#!/usr/bin/env python3
"""Execute isolated shipped x86 gameplay instructions using Unicorn.

This is instruction emulation, NOT a claim of Wine/full game observation.
Only the emulator's memory is changed; original files are read-only.
Run with re-python (pefile and unicorn are in the installed analysis runtime).
"""
import argparse
import hashlib
import json
import random
import struct
from pathlib import Path

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_FPCW

ROOT = Path(__file__).resolve().parents[1]
SOURCE = Path("/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data")
SCRATCH = 0x20000000
OBJECT = 0x21000000
STACK = 0x10000000


class NativeProbe:
    def __init__(self, source):
        self.source = source
        binary = source / "rcskspel.dat"
        self.sha = hashlib.sha256(binary.read_bytes()).hexdigest()
        pe = pefile.PE(str(binary))
        self.uc = Uc(UC_ARCH_X86, UC_MODE_32)
        # Explicit 24-bit precision with masked exceptions. The game's CRT
        # starts in 53-bit mode; device-era runtime precision remains scoped
        # separately. Never silently rely on Unicorn's default control word.
        self.uc.reg_write(UC_X86_REG_FPCW, 0x007f)
        self.uc.mem_map(pe.OPTIONAL_HEADER.ImageBase, (pe.OPTIONAL_HEADER.SizeOfImage + 4095) & ~4095)
        self.uc.mem_write(pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image())
        for address, size in [(STACK, 0x10000), (SCRATCH, 0x10000), (OBJECT, 0x1000)]:
            self.uc.mem_map(address, size)
        self.u32(0x67ee20, OBJECT)
        # Native init_main 0x442fc0 passes 4096 to 0x4ac410 -> 0x4a1510,
        # replacing the PE's initial 1024. Table users must supply 4096 entries.
        self.u32(0x4fc8f0, 4096)
        self.f32(0x4fc8f4, 4096)
        self.u32(0x4fc8f8, 4095)
        self.u32(0x53ba34, 0)
        self.u32(0x53b9b4, 0)
        self.u32(0x53be2c, 0)
        self.u32(OBJECT + 0xc, 0)
        self.u32(0x6a5c38, SCRATCH + 0x4000)
        self.uc.mem_write(0x48f4e0, b"\xd9\x05" + struct.pack("<I", SCRATCH + 0x1000) + b"\xc3")
        self.uc.mem_write(0x42ee60, b"\xa1" + struct.pack("<I", SCRATCH + 0x1010) + b"\xc3")
        # Native FPU return values are captured by a tiny caller continuation.
        self.uc.mem_write(SCRATCH + 0x100, b"\xdd\x1d" + struct.pack("<I", SCRATCH + 0x2000) + b"\x90")

    def u32(self, address, value):
        self.uc.mem_write(address, struct.pack("<I", value))

    def f32(self, address, value):
        self.uc.mem_write(address, struct.pack("<f", value))

    def float(self, address):
        return struct.unpack("<f", self.uc.mem_read(address, 4))[0]

    def integer(self, address):
        return struct.unpack("<I", self.uc.mem_read(address, 4))[0]

    def run(self, address, args=(), float_return=False):
        end = SCRATCH + 0x106 if float_return else SCRATCH
        target = SCRATCH + 0x100 if float_return else end
        sp = STACK + 0xf000
        self.uc.mem_write(sp, struct.pack("<I", target) + b"".join(
            struct.pack("<f", value) if isinstance(value, float) else struct.pack("<I", value)
            for value in args))
        self.uc.reg_write(UC_X86_REG_ESP, sp)
        self.uc.emu_start(address, end, count=100000)
        if float_return:
            return struct.unpack("<d", self.uc.mem_read(SCRATCH + 0x2000, 8))[0]

    def input_step(self, mask, delta, mirrored=False):
        self.u32(SCRATCH + 0x1010, mask)
        self.f32(SCRATCH + 0x1000, delta)
        self.u32(0x53a734, int(mirrored))
        self.run(0x433870, [0])
        return {"throttle": self.float(0x53bd74), "brake": self.integer(0x53be04),
                "steering": self.float(0x53bd70), "handbrake": bool(self.integer(0x53bdf4))}

    def input_reset(self):
        for address in [0x53bd74, 0x53be04, 0x53bd70, 0x53bdf4]:
            self.u32(address, 0)

    def set_physics(self, preset, record):
        data = (self.source / f"Phys{preset}.dat").read_bytes()
        self.uc.mem_write(0x505b60, data)
        self.u32(0x53be2c, record)

    def set_body(self, speed, lateral, yaw, mass):
        self.f32(OBJECT + 0x9c, lateral)
        self.f32(OBJECT + 0xa4, speed)
        self.f32(OBJECT + 0xac, yaw)
        self.f32(OBJECT + 0x90, 1 / mass)


def generate(source, output):
    probe = NativeProbe(source)
    traces = []
    # Button sequences exercise both steering directions, reversal clearing,
    # simultaneous acceleration/brake, handbrake, and the integer brake hazard.
    for interval in [0.025, 0.03125, 1 / 60, 1 / 144, 0.1]:
        for mirrored in [False, True]:
            probe.input_reset()
            frames = []
            for step in range(160):
                mask = (8 if step < 40 else 4 if step < 120 else 0)
                if 10 <= step < 50: mask |= 1
                if 50 <= step < 100: mask |= 2
                if 100 <= step < 110: mask |= 3
                if 130 <= step < 140: mask |= 32
                frames.append({"mask": mask, "delta": interval, "expected": probe.input_step(mask, interval, mirrored)})
            traces.append({"interval": interval, "mirrored": mirrored, "frames": frames})
    rng = random.Random(2000)
    forces = []
    for index in range(120):
        preset, record = index % 3, index % 10
        probe.set_physics(preset, record)
        speed = rng.choice([-15, -10, -0.01, 0, 0.01, 5, 10, 20, 40])
        body = {"forwardSpeed": speed, "lateralSpeed": rng.uniform(-3, 3),
                "yawRate": rng.uniform(-1, 1), "mass": rng.choice([200, 500, 1000])}
        steering = rng.choice([-100.0, -25.0, 0.0, 25.0, 100.0])
        tire_upgrade, motor_upgrade, gearbox_upgrade = index % 2, (index // 2) % 2, (index // 4) % 2
        handbrake, turbo = bool(index % 2), bool(index % 3)
        probe.set_body(speed, body["lateralSpeed"], body["yawRate"], body["mass"])
        # Round values to the native float32 storage before supplying JS too.
        body["lateralSpeed"] = probe.float(OBJECT + 0x9c)
        body["yawRate"] = probe.float(OBJECT + 0xac)
        body["mass"] = 1 / probe.float(OBJECT + 0x90)
        body["forwardSpeed"] = probe.float(OBJECT + 0xa4)
        probe.u32(0x53bef4, tire_upgrade)
        probe.u32(0x53bef0, motor_upgrade)
        probe.u32(0x53bf00, gearbox_upgrade)
        probe.u32(0x53bdf4, int(handbrake))
        probe.u32(0x53bdf8, int(turbo))
        rpm, gear = rng.choice([800.0, 2000.0, 4000.0, 5800.0]), index % 6
        throttle, brake = rng.choice([0.0, 20.0, 100.0]), rng.choice([0.0, 20.0, 100.0])
        probe.f32(0x507290, rpm)
        probe.u32(0x507298, gear)
        expected = {}
        for axle, wheel in [("front", 0), ("rear", 2)]:
            angle = probe.run(0x414ff0, [0, wheel, steering], float_return=True)
            expected[axle + "Slip"] = angle
            probe.run(0x415160, [SCRATCH + 0x3000, 0, float(angle), wheel, steering])
            expected[axle + "Force"] = probe.float(SCRATCH + 0x3000)
        expected["power"] = probe.run(0x415410, float_return=True)
        probe.run(0x415450, [SCRATCH + 0x3000, 0, 0, throttle, brake])
        expected["drive"] = probe.float(SCRATCH + 0x3008)
        probe.run(0x415520, [SCRATCH + 0x3000, 0])
        expected["resistance"] = {"lateral": probe.float(SCRATCH + 0x3000),
                                  "longitudinal": probe.float(SCRATCH + 0x3008)}
        for offset in [0xb4, 0xb8, 0xbc, 0xc0]:
            probe.f32(OBJECT + offset, 0.0)
        probe.u32(0x53b9c0, 0)
        probe.f32(SCRATCH + 0x1000, 0.025)
        probe.run(0x415990, [0, throttle, brake, steering])
        expected["playerForces"] = {
            "lateralSpeed": probe.float(OBJECT + 0x9c),
            "forwardSpeed": probe.float(OBJECT + 0xa4),
            "yawRate": probe.float(OBJECT + 0xac),
            "lateralForce": probe.float(OBJECT + 0xb4),
            "longitudinalForce": probe.float(OBJECT + 0xbc),
            "torque": probe.float(OBJECT + 0xc0),
            "rpm": probe.float(0x507290), "gear": probe.integer(0x507298),
        }
        forces.append({"preset": preset, "record": record, "body": body, "steering": steering,
                       "tireUpgrade": tire_upgrade, "motorUpgrade": motor_upgrade, "gearboxUpgrade": gearbox_upgrade,
                       "handbrake": handbrake, "turbo": turbo, "rpm": rpm, "gear": gear,
                       "throttle": throttle, "brake": brake, "expected": expected})
    output.parent.mkdir(parents=True, exist_ok=True)
    result = {
        "format": "superkarts-native-gameplay-fixtures-v1", "sha256": probe.sha,
        "method": "Unicorn x86 instruction emulation of original PE. Input poll and delta calls stubbed. No Wine/full race observation.",
        "fpuControlWord": "0x007f (24-bit precision)",
        "runtimeAngleCount": 4096,
        "entrypoints": ["0x433870", "0x414ff0", "0x415160", "0x415410", "0x415450", "0x415520", "0x415990"],
        "tolerance": {"inputAbsolute": 0.00003, "forceRelative": 0.000003, "forceAbsolute": 0.002},
        "inputTraces": traces, "forceCases": forces,
    }
    output.write_text(json.dumps(result, indent=2) + "\n")
    print(f"Wrote {sum(len(trace['frames']) for trace in traces)} native input updates and {len(forces)} native force cases to {output}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=SOURCE)
    parser.add_argument("--output", type=Path, default=ROOT / "evidence/gameplay/native-fixtures.json")
    args = parser.parse_args()
    generate(args.source, args.output)
