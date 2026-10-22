#!/usr/bin/env python3
"""Run original danger-zone, return-marker and occupied-return instructions.

Only isolated emulator memory is changed. Sector selection is controlled in
height-gate cases; actual fallback-plane math, comparison and enqueue arguments
are executed. No claim of a rendered native race.
"""
import json
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_ai_fixture_track import install_track

RENDER = SCRATCH + 0x4000
SPAWN = 0x23000000


def finish(p, limit=10000000):
    if p.uc.reg_read(UC_X86_REG_EIP) != SCRATCH:
        try:
            p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP), SCRATCH, count=limit)
        except Exception as error:
            raise RuntimeError(f"Native instruction {p.uc.reg_read(UC_X86_REG_EIP):x}, "
                               f"stack {p.uc.reg_read(UC_X86_REG_ESP):x}") from error
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH, "Original code did not return"


def generate():
    output = {"format": "superkarts-native-environment-rescue-v1", "gates": [], "markers": [], "relocations": []}
    for precision in [24, 53]:
        p = NativeProbe(SOURCE)
        output["sourceSha256"] = p.sha
        p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
        p.uc.mem_map(0, 4096)
        p.uc.mem_map(SPAWN, 0x2000)
        p.uc.mem_map(0x24000000, 0x400000)
        p.u32(0x680b28, 0x24000000)
        p.u32(0x680ae0, 0x24200000)
        p.uc.mem_write(0x4977d0, b"\x31\xc0\xc2\x10\0")  # selected route0
        p.uc.mem_write(0x48da90, b"\x31\xc0\xc3")  # manager service
        p.uc.mem_write(0x48dce0, b"\xc2\x08\0")  # observe queue arguments
        calls = []

        def observe(uc, address, size, data):
            if address == 0x48dce0:
                sp = uc.reg_read(UC_X86_REG_ESP)
                calls.append([p.integer(sp + 4), p.integer(sp + 8)])

        p.uc.hook_add(UC_HOOK_CODE, observe, begin=0x48dce0, end=0x48dce0)
        planes = [
            {"normal": [0, 1, 0], "distance": 10},
            {"normal": [.25, .75, -.125], "distance": 19.375},
            {"normal": [.341013, .837123, -.291314], "distance": -530.1234},
        ]
        for plane in planes:
            for axis, value in enumerate(plane["normal"]):
                p.f32(0x24000000 + 0x3c + axis * 4, value)
            p.f32(0x24000000 + 0xdc, plane["distance"])
            stored_plane = {"normal": [p.float(0x24000000 + 0x3c + i * 4) for i in range(3)],
                            "distance": p.float(0x24000000 + 0xdc)}
            x, z = (12.0, -17.0) if plane == planes[1] else (-5492.43115234375, 3373.951416015625)
            p.uc.reg_write(UC_X86_REG_ECX, 0x24000000)
            height = p.run(0x494b70, [x, z], float_return=True)
            for offset in [-100, 0, 1.499, 1.5, 1.501, 100]:
                for marker in [0, 50, 51, 68]:
                    p.u32(0x24200004, marker)
                    position = [x, height + offset, z]
                    for axis, value in enumerate(position): p.f32(RENDER + 0x50 + axis * 4, value)
                    calls.clear()
                    p.run(0x48c030, [0])
                    finish(p)
                    output["gates"].append({"precision": precision, "plane": stored_plane, "marker": marker,
                        "position": [p.float(RENDER + 0x50 + i * 4) for i in range(3)], "calls": list(calls)})
        # Real authored DMP slots: both directions, wrap, multiple/no return markers.
        for track_id in range(6):
            track = json.loads((ROOT / f"public/assets/tracks/etappe{track_id}.json").read_text())
            install_track(p, track)
            p.u32(0x680ae4, len(track["drive"]))
            p.u32(0x680af0, SCRATCH + 0x8000)
            p.uc.mem_write(SCRATCH + 0x8000, bytes([1]) * len(track["drive"]))
            starts = {0, len(track["drive"]) - 1}
            starts.update(i for i, node in enumerate(track["drive"]) if node["unknown"][1] in [50, 51])
            for start in sorted(starts):
                for direction in [0, 1]:
                    p.run(0x48bf80, [start, direction])
                    finish(p)
                    result = p.uc.reg_read(UC_X86_REG_EAX)
                    output["markers"].append({"track": track_id, "start": start, "direction": direction,
                        "expected": result if result < 0x80000000 else result - 0x100000000})
        # Original grow-frame0, with controlled marker and clearance services.
        p.run(0x48c370)
        p.uc.mem_write(0x4a6060, b"\x31\xc0\xc2\x04\0")
        p.uc.reg_write(UC_X86_REG_ECX, SPAWN)
        p.run(0x48c7e0)
        p.u32(0x53be28, 1)  # isolated object0 has no speech actor
        p.u32(0x508610, 0)
        p.u32(0x53ba78, 0)
        p.u32(0x53ba60, 0)
        p.u32(0x680ae0, SCRATCH + 0x6000)
        for i, value in enumerate([100, 200, 300]): p.f32(SCRATCH + 0x6008 + i * 4, value)
        for address, code in {
            0x450690: b"\x31\xc0\xc3", 0x493540: b"\xc3",
            0x430ff0: b"\xd9\x05" + struct.pack("<I", SCRATCH + 0x2200) + b"\xc3",
        }.items(): p.uc.mem_write(address, code)
        p.f32(SCRATCH + 0x2200, 25)
        for marker, free in [(0, True), (0, False), (-1, True)]:
            p.uc.mem_write(0x48bf80, b"\xb8" + struct.pack("<I", marker & 0xffffffff) + b"\xc3")
            p.uc.mem_write(0x48c170, b"\xb8" + struct.pack("<I", int(free)) + b"\xc3")
            # The marker scanner was already translated above. Unicorn keeps
            # cached blocks across mem_write, including an earlier stub value.
            p.uc.ctl_remove_cache(0x48bf80, 0x48c370)
            p.uc.reg_write(UC_X86_REG_ECX, SPAWN)
            p.run(0x48c9a0, [0, 1])
            p.u32(SPAWN + 0x1194, 0)
            p.u32(SPAWN + 0x1198, 0)
            p.uc.mem_write(RENDER + 0x10, struct.pack("<16f", *[int(i in [0, 5, 10, 15]) for i in range(16)]))
            for i, value in enumerate([5, 6, 7]): p.f32(RENDER + 0x50 + i * 4, value)
            p.uc.reg_write(UC_X86_REG_ECX, SPAWN)
            p.run(0x48ca60)
            finish(p)
            output["relocations"].append({"precision": precision, "marker": marker, "free": free,
                "environment": bool(p.integer(SPAWN + 0x11ac) & 255),
                "position": [p.float(RENDER + 0x50 + i * 4) for i in range(3)],
                "scale": p.float(RENDER + 0x10), "frame": p.integer(SPAWN + 0x1194),
                "shrinking": bool(p.integer(SPAWN + 0x1198) & 255)})
    output["method"] = __doc__
    (ROOT / "evidence/regressions/environment-rescue-fixtures.json").write_text(json.dumps(output, indent=2) + "\n")
    print({key: len(output[key]) for key in ["gates", "markers", "relocations"]})


if __name__ == "__main__":
    generate()
