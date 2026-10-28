#!/usr/bin/env python3
"""Probe original 0x416650; replace only engine ground lookup with explicit heights.

Synthetic wheel geometry/heights are boundary inputs to this callback test,
not claims about actual assets or complete world collision parity.
"""
import json
import math
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT, PRECISION, CONTROL_WORD, precision_path
from native_probe_math import initialize_native_trig

AUX = 0x24000000
RENDER = SCRATCH + 0x4000


def fp(value):
    return struct.unpack("<f", struct.pack("<f", value))[0]


def main():
    p = NativeProbe(SOURCE)
    initialize_native_trig(p)
    p.uc.mem_map(AUX, 0x10000)
    # Skip atexit registration and shared first-time initialization.
    p.u32(0x508158, 3)
    p.u32(0x508184, 1)
    p.u32(0x53be28, 0)
    p.f32(0x53a4a8, 400)
    p.f32(0x53a4ac, 100)
    p.u32(0x508610, 0)
    p.u32(0x507f48, 1)
    p.u32(OBJECT + 0x8c, 4)
    for i in range(4):
        p.u32(OBJECT + 0x64 + 4 * i, i + 1)
    p.u32(0x6a5f78, AUX + 0x8000)
    p.u32(AUX + 0x8004, AUX + 0x8100)
    p.u32(AUX + 0x8104, 0)
    p.u32(AUX + 0x8108, 1)
    p.u32(0x6a5f30, AUX + 0x8200)
    p.u32(AUX + 0x8200, 0)
    p.u32(AUX + 0x8210, 1)
    p.u32(0x6a5ee0, AUX + 0x8300)
    p.u32(0x680b28, AUX + 0x9000)
    for i in range(16): p.f32(0x6a5c90+i*4, 1 if i in [0,5,10,15] else 0)
    for i in range(4):
        for offset in [0x80,0x84,0x88]: p.f32(RENDER+(i+1)*0xa9+offset, 1)
    # Mocked engine boundary: route chunk0; triangle lookup leaves outputs0;
    # height uses eight supplied float32 answers, incrementing its own cursor.
    p.uc.mem_write(0x4977d0, b"\x31\xc0\xc2\x10\x00")
    p.uc.mem_write(0x495fe0, b"\xc2\x18\x00")
    p.uc.mem_write(0x496290,
        b"\xa1" + struct.pack("<I", AUX + 0xa000) +
        b"\xd9\x04\x85" + struct.pack("<I", AUX + 0xa100) +
        b"\x40\xa3" + struct.pack("<I", AUX + 0xa000) + b"\xc2\x14\x00")
    rng = random.Random(416650)
    cases = []
    wheel_pose_cases = []
    for index in range(160):
        delta = fp(rng.choice([0.025, 0.03125, 0.1, 1/60]))
        old_delta = fp(rng.choice([0.025, 0.03125, 0.1]))
        yaw = fp(rng.uniform(-4096, 8192))
        angle = fp((int(yaw) & 4095) / 4096 * fp(math.pi * 2))
        s, c = fp(math.sin(angle)), fp(math.cos(angle))
        body = {"position": [fp(rng.uniform(-5000, 5000)), fp(rng.uniform(0, 20)), fp(rng.uniform(-5000, 5000))],
                "matrix": [c, 0, s, 0, 1, 0, -s, 0, c], "yaw": yaw,
                "forwardSpeed": fp(rng.choice([-15, -5, 0, 5, 20, 40])),
                "lateralSpeed": fp(rng.uniform(-4, 4))}
        radii = [fp(4), fp(5)]
        wheel_state = []
        heights = []
        for i, local in enumerate([[-10, 0, 18], [10, 0, 18], [-10, 0, -18], [10, 0, -18]]):
            point = [fp(fp(sum(local[j] * body["matrix"][j * 3 + axis] for j in range(3))) + body["position"][axis]) for axis in range(3)]
            wheel_state.append({"local": local, "radius": radii[i // 2], "position": point, "verticalSpeed": fp(rng.uniform(-20, 20))})
            old_height = fp(point[1] - radii[i // 2] + rng.choice([-2, 0, 2]))
            heights += [old_height, fp(old_height + rng.choice([-5, -1, 0, 0.5, 1.8, 5]))]
            for axis in range(3):
                p.f32(RENDER + (i + 1) * 0xa9 + 0x50 + axis * 4, local[axis])
                p.f32(0x507f78 + i * 12 + axis * 4, point[axis])
            p.f32(RENDER + (i + 1) * 0xa9 + 0x60, wheel_state[-1]["verticalSpeed"])
        for axis in range(3): p.f32(RENDER + 0x50 + axis * 4, body["position"][axis])
        for row in range(3):
            for axis in range(3): p.f32(RENDER + 0x10 + row * 0x10 + axis * 4, body["matrix"][row * 3 + axis])
        p.f32(RENDER + 0x78, yaw)
        p.f32(OBJECT + 0x9c, body["lateralSpeed"])
        p.f32(OBJECT + 0xa4, body["forwardSpeed"])
        p.f32(AUX + 0x8300 + 0x14, -radii[0])
        p.f32(AUX + 0x8300 + 0xbc + 0x14, -radii[1])
        p.f32(0x507f70, old_delta)
        p.f32(SCRATCH + 0x1000, delta)
        p.u32(AUX + 0xa000, 0)
        for i, height in enumerate(heights): p.f32(AUX + 0xa100 + 4 * i, height)
        steering = fp(rng.uniform(-100,100))
        p.f32(0x53bd70, steering)
        for i in range(4):
            p.f32(RENDER+(i+1)*0xa9+0x74, 0)
            p.f32(RENDER+(i+1)*0xa9+0x78, 0)
            p.f32(RENDER+(i+1)*0xa9+0x7c, 0)
        p.run(0x41c0b0, [0])
        wheel_pose_cases.append({"body":body,"wheels":wheel_state,"delta":delta,"steering":steering,
            "heights":heights[:4], "expected":[
                {"localY":p.float(RENDER+(i+1)*0xa9+0x54),
                 "spin":p.float(RENDER+(i+1)*0xa9+0x74),
                 "steeringAngle":p.float(RENDER+(i+1)*0xa9+0x78)} for i in range(4)]})
        for i in range(4): p.f32(RENDER+(i+1)*0xa9+0x54, wheel_state[i]["local"][1])
        p.u32(AUX + 0xa000, 0)
        p.run(0x416650, [0])
        expected = {
            "delta": p.float(0x507f70), "groundCount": p.integer(0x50815c),
            "playerContact": bool(p.integer(0x4e0d14)),
            "position": [p.float(RENDER + 0x50 + i * 4) for i in range(3)],
            "matrix": [p.float(RENDER + 0x10 + row * 0x10 + axis * 4) for row in range(3) for axis in range(3)],
            "wheels": [{"position": [p.float(0x507f78 + i * 12 + axis * 4) for axis in range(3)],
                        "verticalSpeed": p.float(RENDER + (i + 1) * 0xa9 + 0x60)} for i in range(4)]
        }
        cases.append({"body": body, "wheels": wheel_state, "delta": delta, "oldDelta": old_delta,
                      "heights": heights, "expected": expected})
    # Recurrence probes preserve native matrix/wheel storage across updates.
    # The shipped wheel geometry is used; explicit terrain heights remain the
    # boundary of this instruction-level probe, not a whole-track simulation.
    geometry = json.loads((ROOT / "public/assets/cars.json").read_text())["cars"]["0"]
    traces = []
    for trace_index in range(4):
        body = {"position": [fp(3000 + trace_index * 17), fp(20), fp(-4200)],
                "matrix": [1, 0, 0, 0, 1, 0, 0, 0, 1], "yaw": 0,
                "forwardSpeed": 0, "lateralSpeed": 0}
        wheels = [{"local": local, "radius": geometry["frontRadius"] if i < 2 else geometry["rearRadius"],
                   "verticalSpeed": 0, "spin": 0, "steeringAngle": 0}
                  for i, local in enumerate(geometry["wheelOffsets"])]
        for axis in range(3):
            p.f32(RENDER + 0x50 + axis * 4, body["position"][axis])
        for row in range(3):
            for axis in range(3):
                p.f32(RENDER + 0x10 + row * 0x10 + axis * 4, body["matrix"][row * 3 + axis])
        for i, wheel in enumerate(wheels):
            for axis in range(3):
                p.f32(RENDER + (i + 1) * 0xa9 + 0x50 + axis * 4, wheel["local"][axis])
            for offset in [0x60, 0x74, 0x78, 0x7c]:
                p.f32(RENDER + (i + 1) * 0xa9 + offset, 0)
        for i, radius in enumerate([geometry["frontRadius"], geometry["rearRadius"]]):
            p.f32(AUX + 0x8300 + i * 0xbc + 0x14, -radius)
        p.u32(0x507f48, 0)
        old_delta = fp(.03125)
        p.f32(0x507f70, old_delta)
        frames = []
        for frame in range(80):
            delta = fp([.025, .03125, .1, 1 / 60][(frame + trace_index) % 4])
            speed = fp(20 if frame < 25 else -12 if frame < 50 else 4)
            lateral = fp((frame % 7 - 3) * .7)
            steering = fp(70 if frame % 20 < 10 else -50)
            # Step, slope, airborne drop, then a flat section.
            heights = [fp((3 if frame < 20 else 8 if frame < 40 else -2 if frame < 60 else 0)
                          + (i % 2) * .7 + (i // 2) * .3) for i in range(8)]
            p.f32(SCRATCH + 0x1000, delta)
            p.f32(OBJECT + 0x9c, lateral)
            p.f32(OBJECT + 0xa4, speed)
            p.f32(RENDER + 0x78, 0)
            p.f32(0x53bd70, steering)
            for i, height in enumerate(heights):
                p.f32(AUX + 0xa100 + i * 4, height)
            for _ in range(2):
                p.u32(AUX + 0xa000, 0)
                p.run(0x41c0b0, [0])
            p.u32(AUX + 0xa000, 0)
            p.run(0x416650, [0])
            frames.append({"delta": delta, "forwardSpeed": speed, "lateralSpeed": lateral,
                "steering": steering, "heights": heights,
                "expected": {"delta": p.float(0x507f70),
                    "groundCount": p.integer(0x50815c), "playerContact": bool(p.integer(0x4e0d14)),
                    "position": [p.float(RENDER + 0x50 + i * 4) for i in range(3)],
                    "matrix": [p.float(RENDER + 0x10 + row * 0x10 + axis * 4) for row in range(3) for axis in range(3)],
                    "wheels": [{"position": [p.float(0x507f78 + i * 12 + axis * 4) for axis in range(3)],
                        "verticalSpeed": p.float(RENDER + (i + 1) * 0xa9 + 0x60),
                        "localY": p.float(RENDER + (i + 1) * 0xa9 + 0x54),
                        "spin": p.float(RENDER + (i + 1) * 0xa9 + 0x74),
                        "steeringAngle": p.float(RENDER + (i + 1) * 0xa9 + 0x78)} for i in range(4)]}})
        traces.append({"body": body, "wheels": wheels, "oldDelta": old_delta, "frames": frames})
    output = precision_path(ROOT / "evidence/gameplay/native-ground-fixtures.json")
    output.write_text(json.dumps({"format": "superkarts-native-ground-v1", "sha256": p.sha,
        "method": "Original x86 0x416650 instructions; route and triangle-height selection replaced by explicit boundary inputs. Synthetic wheel offsets. No full-world claim.",
        "fpuControlWord":f"0x{CONTROL_WORD:04x} ({PRECISION}-bit precision)", "runtimeAngleCount":4096, "cases": cases,
        "wheelPoseCases":wheel_pose_cases, "traces": traces}, indent=2) + "\n")
    print(f"Wrote {len(cases)} native wheel-contact cases, {len(wheel_pose_cases)} poses and "
          f"{sum(len(trace['frames']) for trace in traces)} recurring frames to {output}")


if __name__ == "__main__":
    main()
