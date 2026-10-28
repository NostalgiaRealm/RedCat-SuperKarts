#!/usr/bin/env python3
"""Original spin/gum/bubble effect updates, including native spring and CRT RNG."""
import json
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT, PRECISION, precision_path
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EIP, UC_X86_REG_ESP

def word(value): return struct.pack("<I", value & 0xffffffff)
def fp(value): return struct.unpack("<f", struct.pack("<f", value))[0]

def main():
    p = NativeProbe(SOURCE)
    initialize_native_trig(p)
    state, render, height_address = SCRATCH + 0x6000, SCRATCH + 0x4000, SCRATCH + 0x6800
    for address in [0x430dd0, 0x457730, 0x457ab0]:
        p.uc.mem_write(address, b"\xc3")
    p.uc.mem_write(0x4977d0, b"\x31\xc0\xc2\x10\x00")
    p.uc.mem_write(0x457ab0, b"\xc2\x04\x00")
    p.uc.mem_write(0x494b70, b"\xd9\x05" + word(height_address) + b"\xc2\x08\x00")
    p.u32(0x68021c, SCRATCH + 0x6900)
    p.u32(SCRATCH + 0x6900, 0)
    p.uc.mem_write(0x4906b0, b"\xb8\x02\x00\x00\x00\xc2\x04\x00")
    p.u32(0x508610, 4)
    p.u32(0x53be28, 0)
    p.u32(0x5081bc, 0)
    rng = random.Random(0x412390)
    cases = []
    for index in range(600):
        kind = ["spin", "gum", "bubble"][index % 3]
        mode = rng.choice([0, 1]) if kind == "spin" else 4 if kind == "gum" else 6
        type_id = rng.choice([1, 3]) if kind == "spin" else 4 if kind == "gum" else 2
        level = index % 3 + 1
        body = {"position": [fp(rng.uniform(-1000, 1000)) for _ in range(3)],
                "lateralSpeed": fp(rng.uniform(-20, 20)), "verticalSpeed": fp(rng.uniform(-20, 20)),
                "forwardSpeed": fp(rng.uniform(-20, 40)), "pitch": fp(rng.uniform(-100, 100)),
                "roll": fp(rng.uniform(-100, 100)), "yaw": fp(rng.uniform(-9000, 9000)),
                "pitchRate": fp(rng.uniform(-10, 10)), "rollRate": fp(rng.uniform(-10, 10)),
                "yawRate": fp(rng.uniform(-2, 2))}
        effect = {"type": type_id, "level": level, "mode": mode, "remaining": fp(rng.choice([-0.1, 0, 0.025, 0.03, 1, 3])),
                  "originalAngles": [0, fp(body["yaw"] + rng.choice([-5000, -4096, -4095, 0, 4095, 4096, 5000])), 0],
                  "originalVelocity": [0, 0, fp(rng.uniform(-20, 40))],
                  "restoredVelocity": [0, 0, fp(rng.uniform(-10, 20))],
                  "bubbleVisible": bool(index % 2), "active": True}
        params = {"duration": fp(rng.choice([1, 1.5, 2, 3])), "firstSpeedFactor": fp(rng.choice([0, 0.3, 0.5]))}
        dt, height = fp(rng.choice([0.025, 0.03125, 0.1])), fp(rng.uniform(-50, 50))
        seed = rng.randrange(0xffffffff)
        ground_count, rear_y = rng.choice([0, 2, 3, 4]), fp(rng.choice([-5, 0, 5, 100]))
        p.uc.mem_write(state, bytes(0x120))
        p.u32(state, 0)
        for offset, value in [(0xa4, level), (0xa8, type_id), (0xac, mode)]: p.u32(state + offset, value)
        for offset, values in [(0xb0, effect["originalVelocity"]), (0xbc, effect["restoredVelocity"]), (0xc8, effect["originalAngles"])]:
            for axis, value in enumerate(values): p.f32(state + offset + axis * 4, value)
        p.f32(state + 0x98, effect["remaining"])
        p.uc.mem_write(state + 0xfc, bytes([effect["bubbleVisible"]]))
        for offset, key in [(0x9c, "lateralSpeed"), (0xa0, "verticalSpeed"), (0xa4, "forwardSpeed"),
                            (0xa8, "pitchRate"), (0xac, "yawRate"), (0xb0, "rollRate")]: p.f32(OBJECT + offset, body[key])
        for axis, value in enumerate(body["position"]): p.f32(render + 0x50 + axis * 4, value)
        for axis, key in enumerate(["pitch", "yaw", "roll"]): p.f32(render + 0x74 + axis * 4, body[key])
        p.f32(render + 2 * 0xa9 + 0x60, rear_y)
        p.u32(0x50815c + 4 * 4, ground_count)
        p.f32(0x543d40 + type_id * 0x60 + level * 0x20, params["duration"])
        p.f32(0x543d40 + type_id * 0x60 + level * 0x20 + 0x14, params["firstSpeedFactor"])
        p.f32(SCRATCH + 0x1000, dt)
        p.f32(height_address, height)
        p.u32(0x502978, seed)
        entry = {"spin": 0x412390, "gum": 0x412280, "bubble": 0x412560}[kind]
        p.run(entry, [4, state])
        expected_body = {key: p.float(OBJECT + offset) for offset, key in [
            (0x9c, "lateralSpeed"), (0xa0, "verticalSpeed"), (0xa4, "forwardSpeed"),
            (0xa8, "pitchRate"), (0xac, "yawRate"), (0xb0, "rollRate")]}
        expected_body.update({key: p.float(render + 0x74 + axis * 4) for axis, key in enumerate(["pitch", "yaw", "roll"])})
        cases.append({"kind": kind, "body": body, "effect": effect, "parameters": params, "delta": dt,
            "seed": seed, "groundHeight": height, "groundCount": ground_count, "rearWheelVerticalSpeed": rear_y,
            "expected": {"body": expected_body, "remaining": p.float(state + 0x98),
            "bubbleVisible": bool(p.uc.mem_read(state + 0xfc, 1)[0]),
            "active": bool(p.uc.reg_read(UC_X86_REG_EAX) & 0xff), "randomState": p.integer(0x502978)}})
    # Execute the four common initializers. Their text/animation blocks are
    # skipped at explicit boundaries; original gameplay and wheel writes run.
    p.uc.mem_map(0, 0x1000)
    p.uc.mem_write(0x4906b0, b"\x8b\x44\x24\x04\x40\xc2\x04\x00")
    p.uc.ctl_remove_cache(0x4906b0, 0x4906c0)
    p.uc.mem_write(0x481ec0, b"\xc3")
    p.uc.mem_write(0x4afce0, b"\xc3")
    jumps = {0x411958: 0x411a77, 0x411ec8: 0x41207c,
             0x4120c9: 0x412136, 0x4121af: 0x41226c,
             0x411bc8: 0x411d8f}
    def skip_text(uc, address, size, data):
        if address == 0x411852:
            sp = uc.reg_read(UC_X86_REG_ESP)
            uc.reg_write(UC_X86_REG_EBP, p.integer(sp + 0x50))
            uc.reg_write(UC_X86_REG_EIP, 0x4118d6)
        elif address in jumps:
            uc.reg_write(UC_X86_REG_EIP, jumps[address])
    handle = p.uc.hook_add(UC_HOOK_CODE, skip_text)
    initializations = []
    for index in range(120):
        type_id, level, player = index % 4 + 1, index // 4 % 3 + 1, bool(index // 12 % 2)
        seed = rng.randrange(0xffffffff)
        original_speed = fp(rng.uniform(-20, 40))
        params = {"duration": fp(rng.choice([1, 1.5, 2, 3])), "firstSpeedFactor": fp(rng.choice([0, 0.3, 0.5]))}
        p.uc.mem_write(state, bytes(0x120))
        p.u32(state, 0)
        for offset, value in [(0xa0, 0), (0xa4, level), (0xa8, type_id), (0xac, 3)]:
            p.u32(state + offset, value)
        p.f32(state + 0xb8, original_speed)
        p.f32(OBJECT + 0xa4, original_speed)
        for wheel in range(4): p.f32(render + (wheel + 1) * 0xa9 + 0x60, -999)
        p.f32(0x543d40 + type_id * 0x60 + level * 0x20, params["duration"])
        p.f32(0x543d40 + type_id * 0x60 + level * 0x20 + 0x14, params["firstSpeedFactor"])
        p.u32(0x502978, seed)
        p.run({1: 0x411830, 2: 0x411b40, 3: 0x411e50, 4: 0x412090}[type_id], [4 if player else 0, state, level])
        initializations.append({"record": {"shooter": 0, "type": type_id, "level": level, "mode": 3,
            "originalVelocity": [0, 0, original_speed], "restoredVelocity": [0, 0, 0], "originalAngles": [0, 0, 0]},
            "body": {"forwardSpeed": original_speed}, "parameters": params, "seed": seed, "player": player,
            "expected": {"phase": p.integer(state + 0x70), "remaining": p.float(state + 0x98),
                "mode": p.integer(state + 0xac), "bubbleVisible": bool(p.uc.mem_read(state + 0xfc, 1)[0]),
                "forwardSpeed": p.float(OBJECT + 0xa4), "randomState": p.integer(0x502978),
                "launchedWheelSpeeds": [None if p.float(render + (wheel + 1) * 0xa9 + 0x60) == -999
                    else p.float(render + (wheel + 1) * 0xa9 + 0x60) for wheel in range(4)]}})
    p.uc.hook_del(handle)
    output = precision_path(ROOT / "evidence/gameplay/native-effect-fixtures.json")
    output.write_text(json.dumps({"binarySha256": p.sha, "precision": PRECISION, "angleCount": 4096,
        "entries": ["0x412390", "0x412280", "0x412560", "0x413330", "0x4130e0", "0x412fd0"],
        "boundaries": ["ground height/sector", "child lookup", "bubble visual teardown",
            "initializer text/animation blocks skipped; all gameplay writes execute original instructions"],
        "cases": cases, "initializations": initializations}, indent=2) + "\n")
    print(f"Wrote {len(cases)} effect updates and {len(initializations)} original initializations to {output}")

if __name__ == "__main__": main()
