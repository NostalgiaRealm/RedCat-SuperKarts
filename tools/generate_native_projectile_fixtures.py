#!/usr/bin/env python3
"""Execute original 455ce0 projectile flight with explicit renderer/ground boundaries."""
import json
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT, PRECISION, precision_path
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import STACK
from native_ai_fixture_track import install_track

def word(value): return struct.pack("<I", value & 0xffffffff)
def fp(value): return struct.unpack("<f", struct.pack("<f", value))[0]

def main():
    p = NativeProbe(SOURCE)
    initialize_native_trig(p)
    shot, render, ground = SCRATCH + 0x6000, SCRATCH + 0x4000, SCRATCH + 0x6800
    p.uc.mem_write(0x430dd0, b"\xc3")
    p.uc.mem_write(0x450440, b"\xc3")
    p.uc.mem_write(0x481ec0, b"\xc3")
    p.uc.mem_write(0x430ff0, b"\xd9\x05" + word(ground) + b"\xc3")
    # SetState rendering/audio/container bookkeeping is outside this kernel.
    # Preserve its gameplay writes: state=1, age=0, height-initialized=false.
    p.uc.mem_write(0x456440, b"\xc7\x41\x08\x01\x00\x00\x00\xc7\x41\x1c\x00\x00\x00\x00\xc6\x41\x2c\x00\xc2\x04\x00")
    p.u32(0x508610, 4)
    p.u32(0x5081bc, 1)
    p.u32(OBJECT + 0xd0 + 0xc, 1)
    p.u32(0x543d18, 3000)
    rng = random.Random(0x455ce0)
    cases = []
    for index in range(480):
        type_id, level = index % 2 + 1, index // 2 % 3 + 1
        params = {"lifetime": rng.choice([3, 4, 5, 15]), "speed": rng.choice([750, 1000]),
                  "lockRange": rng.choice([0, 10])}
        data = {
            "type": type_id, "level": level, "state": 2, "ageSeconds": fp(rng.choice([0.025, 1, 3, 4, 5, 16])),
            "position": [fp(rng.uniform(-5000, 5000)) for _ in range(3)],
            "angles": [fp(rng.uniform(-100, 100)), fp(rng.uniform(-8192, 8192)), fp(rng.uniform(0, 4096))],
            "matrix": [1, 0, 0, 0, 1, 0, fp(rng.uniform(-1, 1)), fp(rng.uniform(-1, 1)), fp(rng.uniform(-1, 1))],
            "inheritedForward": fp(rng.uniform(-15, 30)), "target": rng.choice([-2, 0]),
            "clearance": fp(rng.choice([5.5, 10, 12.25])), "previousHeight": rng.randint(-100, 100),
            "heightInitialized": bool(index % 2),
        }
        target = [fp(rng.uniform(-5000, 5000)) for _ in range(3)]
        height, dt = fp(rng.uniform(-50, 50)), fp(rng.choice([0.025, 0.03125, 0.1, 1/144]))
        p.uc.mem_write(shot, bytes(64))
        for offset, value in [(4, type_id), (8, 2), (12, 0), (16, 0), (24, level),
                              (0x24, data["target"]), (0x28, data["previousHeight"])]:
            p.uc.mem_write(shot + offset, word(value))
        for offset, value in [(0x1c, data["ageSeconds"]), (0x38, data["inheritedForward"]), (0x3c, data["clearance"])]:
            p.f32(shot + offset, value)
        p.uc.mem_write(shot + 0x2c, bytes([data["heightInitialized"]]))
        for offset, values in [(0x50, data["position"]), (0x74, data["angles"])]:
            for axis, value in enumerate(values): p.f32(render + offset + axis * 4, value)
        for row in range(3):
            for col in range(3): p.f32(render + 0x10 + row * 16 + col * 4, data["matrix"][row * 3 + col])
        for axis, value in enumerate(target): p.f32(render + 0xa9 + 0x50 + axis * 4, value)
        parameter_address = 0x543d40 + type_id * 0x60 + level * 0x20
        p.f32(parameter_address + 4, params["lifetime"])
        p.u32(parameter_address + 12, params["lockRange"])
        p.f32(parameter_address + 16, params["speed"])
        p.f32(ground, height)
        p.f32(SCRATCH + 0x1000, dt)
        p.uc.reg_write(UC_X86_REG_ECX, shot)
        p.run(0x455ce0)
        expected = {
            "position": [p.float(render + 0x50 + axis * 4) for axis in range(3)],
            "angles": [p.float(render + 0x74 + axis * 4) for axis in range(3)],
            "matrix": [p.float(render + 0x10 + row * 16 + col * 4) for row in range(3) for col in range(3)],
            "state": p.integer(shot + 8), "ageSeconds": p.float(shot + 0x1c),
            "previousHeight": struct.unpack("<i", p.uc.mem_read(shot + 0x28, 4))[0],
            "heightInitialized": bool(p.uc.mem_read(shot + 0x2c, 1)[0]),
        }
        cases.append({"shot": data, "parameters": params, "targetPosition": target,
                      "groundHeight": height, "delta": dt, "expected": expected})
    # Original fire gate through 4338f1, with a synthetic GetTickCount return.
    ticks, calls, clock_fn = SCRATCH + 0x6900, SCRATCH + 0x6904, SCRATCH + 0x7000
    p.uc.mem_write(clock_fn, b"\xa1" + word(ticks) + b"\xc3")
    p.u32(0x4d215c, clock_fn)
    p.uc.mem_write(0x4513c0, b"\xc3")
    p.uc.mem_write(0x4517f0, b"\xff\x05" + word(calls) + b"\xc3")
    gates = []
    for index in range(120):
        previous = rng.choice([0, 500, 10000, 0xfffffe00, 0xffffffff])
        now = (previous + rng.choice([0, 1, 499, 500, 501, 1000])) & 0xffffffff
        held = bool(index % 3)
        p.u32(0x53be1c, previous)
        p.u32(ticks, now)
        p.u32(calls, 0)
        p.u32(SCRATCH + 0x1010, 16 if held else 0)
        p.uc.reg_write(UC_X86_REG_ESP, STACK + 0xf000)
        p.uc.mem_write(STACK + 0xf000, word(SCRATCH) + word(0))
        p.uc.emu_start(0x433870, 0x4338f1, count=10000)
        gates.append({"previous": previous, "now": now, "held": held,
                      "fired": bool(p.integer(calls)), "lastFireMs": p.integer(0x53be1c)})
    # Full target selection with the facing result as an explicit boundary.
    targets = []
    p.u32(0x680b70, SCRATCH + 0x7400)
    facing = SCRATCH + 0x740c
    p.uc.mem_write(0x415be0, b"\xa1" + word(facing) + b"\xc3")
    for index in range(240):
        count, shooter, lock_range, forward = rng.choice([178, 181, 187]), rng.randrange(5), rng.choice([0, 1, 2, 10, 100]), bool(index % 2)
        sectors = [rng.randrange(count) for _ in range(5)]
        p.u32(0x53be28, 4)
        for racer, sector in enumerate(sectors):
            p.u32(0x5081bc + racer * 0x70, racer)
            p.u32(OBJECT + racer * 0xd0 + 0x1c, sector)
        p.u32(SCRATCH + 0x7408, count)
        p.u32(facing, forward)
        p.u32(shot + 4, 1)
        p.u32(shot + 24, 2)
        p.u32(0x543d40 + 0x60 + 0x40 + 12, lock_range)
        p.uc.reg_write(UC_X86_REG_ECX, shot)
        p.run(0x4561e0, [shooter])
        expected = struct.unpack("<i", word(p.uc.reg_read(UC_X86_REG_EAX)))[0]
        targets.append({"shooter": shooter, "racers": [{"sector": sector} for sector in sectors],
                        "sectorCount": count, "lockRange": lock_range, "forward": forward, "expected": expected})
    # Full launch function excluding UI/container registration, target choice,
    # render matrix rebuild, and fan creation (verified separately).
    p.uc.mem_map(0, 0x1000)
    p.u32(0x53be28, 0)
    p.u32(0x5081bc, 0)
    p.u32(OBJECT + 0xc, 0)
    p.u32(OBJECT + 0xd0 + 0xc, 1)
    p.u32(0x6a5ee0, SCRATCH + 0x8000)
    p.uc.mem_write(0x490ce0, b"\x31\xc0\xc3")
    p.uc.mem_write(0x450500, b"\x31\xc0\xc3")
    p.uc.mem_write(0x4a09e0, b"\xc3")
    p.uc.mem_write(0x456440, b"\x8b\x44\x24\x04\x89\x41\x08\xc7\x41\x1c\x00\x00\x00\x00\xc2\x04\x00")
    p.uc.ctl_remove_cache(0x456440, 0x456460)
    def skip_launch_ui(uc, address, size, data):
        if address == 0x4554af: uc.reg_write(UC_X86_REG_EIP, 0x4556f2)
    hook = p.uc.hook_add(UC_HOOK_CODE, skip_launch_ui)
    launches = []
    for index in range(180):
        body = {"position": [fp(rng.uniform(-5000, 5000)) for _ in range(3)], "yaw": fp(rng.uniform(-8192, 8192)),
                "pitch": fp(rng.uniform(-100, 100)), "roll": fp(rng.uniform(-100, 100)),
                "lateralSpeed": fp(rng.uniform(-10, 10)), "verticalSpeed": fp(rng.uniform(-10, 10)),
                "forwardSpeed": fp(rng.uniform(-15, 30))}
        height, radius = fp(rng.uniform(-50, 50)), fp(rng.uniform(5, 25))
        p.uc.mem_write(shot, bytes(64))
        for offset, value in [(0, 0x4d27f8), (4, 1), (8, 1), (12, 1), (16, 1), (24, 1), (32, 0)]:
            p.u32(shot + offset, value)
        p.f32(shot + 0x3c, 17.25)  # Sentinel verifies launch does not initialize it.
        for axis, value in enumerate(body["position"]): p.f32(render + 0x50 + axis * 4, value)
        for axis, key in enumerate(["pitch", "yaw", "roll"]): p.f32(render + 0x74 + axis * 4, body[key])
        for axis, key in enumerate(["lateralSpeed", "verticalSpeed", "forwardSpeed"]): p.f32(OBJECT + 0x9c + axis * 4, body[key])
        p.f32(SCRATCH + 0x8000 + 0x74, radius)
        p.f32(ground, height)
        p.u32(0x543d40 + 0x60 + 0x20 + 8, 0)
        p.u32(0x543d40 + 0x60 + 0x20 + 28, 1)
        p.uc.reg_write(UC_X86_REG_ECX, shot)
        p.run(0x455490)
        shot_render = render + 0xa9
        launches.append({"body": body, "groundHeight": height, "radius": radius, "expected": {
            "position": [p.float(shot_render + 0x50 + axis * 4) for axis in range(3)],
            "angles": [p.float(shot_render + 0x74 + axis * 4) for axis in range(3)],
            "inheritedLateral": p.float(shot + 0x30), "inheritedVertical": p.float(shot + 0x34),
            "inheritedForward": p.float(shot + 0x38)}, "untouchedClearance": p.float(shot + 0x3c)})
    p.uc.hook_del(hook)
    # Original fan creation, including original state/age setters and slot scan.
    # Only mesh/texture replacement is omitted; no position/yaw write is hooked.
    fan_probe = NativeProbe(SOURCE)
    fan_probe.uc.mem_map(0, 0x1000)
    fan_probe.uc.mem_write(0x4afce0, b"\xc3")
    fan_probe.uc.mem_write(0x4500e0, b"\xc3")
    fan_probe.u32(0x543d20, 0)
    fans = []
    def write_fan_slot(address, renderer, data):
        fan_probe.uc.mem_write(address, bytes(64))
        for offset, value in [(0, 0x4d27f8), (4, data["type"]), (8, data["state"]),
                              (12, renderer), (16, -1), (20, 4), (24, data["level"]),
                              (32, data["shooter"]), (36, data["target"])]:
            fan_probe.uc.mem_write(address + offset, word(value))
        for offset, key in [(28,"ageSeconds"), (48,"inheritedLateral"),
                            (52,"inheritedVertical"), (56,"inheritedForward"), (60,"clearance")]:
            fan_probe.f32(address + offset, data[key])
        for offset, key in [(0x50,"position"), (0x74,"angles")]:
            for axis, value in enumerate(data[key]):
                fan_probe.f32(render + renderer * 0xa9 + offset + axis * 4, value)
    def read_fan_slot(address, renderer):
        return {
            **{key: fan_probe.integer(address+offset) for key,offset in
               [("type",4),("state",8),("level",24),("shooter",32)]},
            "target": struct.unpack("<i",fan_probe.uc.mem_read(address+36,4))[0],
            **{key: fan_probe.float(address+offset) for key,offset in
               [("ageSeconds",28),("inheritedLateral",48),("inheritedVertical",52),
                ("inheritedForward",56),("clearance",60)]},
            **{key:[fan_probe.float(render+renderer*0xa9+offset+axis*4) for axis in range(3)]
               for key,offset in [("position",0x50),("angles",0x74)]},
        }
    for index in range(120):
        extra = [0, 2, 4][index % 3]
        def slot(active):
            return {"type": 2, "state": 2 if active else 1, "level": rng.randrange(1,4),
                    "shooter": rng.randrange(5), "target": rng.choice([-2,0,1]),
                    "ageSeconds": fp(rng.uniform(0,20)),
                    "inheritedLateral": fp(rng.uniform(-10,10)), "inheritedVertical": fp(rng.uniform(-10,10)),
                    "inheritedForward": fp(rng.uniform(-15,50)), "clearance": 0,
                    "position": [fp(rng.uniform(-5000,5000)) for _ in range(3)],
                    "angles": [fp(rng.uniform(-5000,5000)) for _ in range(3)]}
        main_shot, pool = slot(True), [slot(i % 3 == index % 3) for i in range(40)]
        write_fan_slot(shot, 0, main_shot)
        for child, data in enumerate(pool): write_fan_slot(0x544080+child*64, child+1, data)
        fan_probe.uc.reg_write(UC_X86_REG_ECX, shot)
        fan_probe.run(0x4560c0, [extra])
        fans.append({"shot": main_shot, "pool": pool, "extra": extra,
                     "expectedShot": read_fan_slot(shot,0),
                     "expectedPool": [read_fan_slot(0x544080+child*64,child+1) for child in range(40)]})
    facing_cases = []
    facing_probe = NativeProbe(SOURCE)
    facing_probe.uc.mem_map(0x24000000, 0x400000)
    for track_id in range(6):
        track = json.loads((ROOT / f"public/assets/tracks/etappe{track_id}.json").read_text())
        install_track(facing_probe, track)
        facing_probe.u32(0x680b2c, len(track["route"]))
        for index in range(60):
            sector, british, direction = rng.randrange(len(track["route"])), index % 2, index // 2 % 2
            matrix = [1, 0, 0, 0, 1, 0, fp(rng.uniform(-1, 1)), 0, fp(rng.uniform(-1, 1))]
            facing_probe.u32(OBJECT + 0x1c, sector)
            facing_probe.u32(0x53ba08, direction)
            facing_probe.u32(0x53ba70, british)
            for row in range(3):
                for col in range(3):
                    facing_probe.f32(render + 0x10 + row * 16 + col * 4, matrix[row * 3 + col])
            facing_probe.run(0x415be0, [0])
            facing_cases.append({"track": track_id, "body": {"sector": sector, "matrix": matrix},
                "options": {"british": british, "direction": direction},
                "expected": bool(facing_probe.uc.reg_read(UC_X86_REG_EAX) & 0xff)})
    output = precision_path(ROOT / "evidence/gameplay/native-projectile-fixtures.json")
    output.write_text(json.dumps({"binarySha256": p.sha, "entry": "0x455ce0", "precision": PRECISION,
        "angleCount": 4096, "boundaries": ["ground height 430ff0", "renderer validity 450440",
        "visual impact 481ec0", "flight/launch SetState gameplay writes with visual/audio/container operations excluded",
        "launch UI block, target selection, matrix rebuild and fan call excluded from launch probe",
        "fan probe executes original4560c0 and state setters; mesh/texture replacement4500e0 omitted",
        "target probe supplied facing result; facing probe separately executes original415be0 on all six source graphs"],
        "cases": cases, "gates": gates, "targets": targets, "launches": launches, "facing": facing_cases,
        "fans": fans}, indent=2) + "\n")
    print(f"Wrote {len(cases)} flights, {len(gates)} gates, {len(targets)} target queries, {len(launches)} launches, {len(facing_cases)} facing cases to {output}")

if __name__ == "__main__": main()
