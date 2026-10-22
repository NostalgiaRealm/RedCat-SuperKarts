#!/usr/bin/env python3
"""Execute original Spawn.cpp timing, transforms and textured effect geometry."""
import json
import struct
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig

SPAWN = 0x23000000
RENDER = SCRATCH + 0x4000


def generate():
    output = {"format": "superkarts-native-rescue-v1", "initial": [], "updates": [], "rings": [],
              "waypoints": [], "nearestSectors": [], "clearance": [], "headings": []}
    for precision in [24, 53]:
        p = NativeProbe(SOURCE)
        output["sourceSha256"] = p.sha
        p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
        p.uc.mem_map(0, 4096)
        p.uc.mem_map(SPAWN, 0x2000)
        initialize_native_trig(p)
        p.run(0x48c370)  # static seven-vertex source definition
        p.uc.mem_write(0x4a6060, b"\x31\xc0\xc2\x04\0")  # texture resolver only
        p.uc.reg_write(UC_X86_REG_ECX, SPAWN)
        p.run(0x48c7e0)
        p.u32(0x53be28, 1)  # no speech actor in isolated update fixtures
        p.u32(0x508610, 0)
        output["baseVertices"] = list(struct.unpack("<21f", p.uc.mem_read(0x67e478, 84)))
        output["shrinkScales"] = [p.float(0x67df70 + i * 64) for i in range(20)]
        output["growScales"] = [p.float(0x67da70 + i * 64) for i in range(20)]
        output["uv"] = [p.float(SPAWN + i * 32 + j) for i in range(7) for j in [24, 28]]
        output["rgba"] = [[(p.integer(SPAWN + i * 32 + 16) >> shift) & 255
                           for shift in [16, 8, 0, 24]] for i in range(140)]
        for position in [[0, 0, 0], [-2346, 22, 7000]]:
            for i, v in enumerate(position):
                p.f32(RENDER + 0x50 + i * 4, v)
                p.f32(OBJECT + 0x9c + i * 4, [4, -8, 12][i])
            p.uc.reg_write(UC_X86_REG_ECX, SPAWN)
            p.run(0x48c9a0, [0, 0])
            output["initial"].append({"precision": precision, "position": position,
                "recordedPosition": [p.float(SPAWN + 0x1184 + i * 4) for i in range(3)],
                "velocity": [p.float(OBJECT + 0x9c + i * 4) for i in range(3)],
                "frame": p.integer(SPAWN + 0x1194), "shrinking": bool(p.integer(SPAWN + 0x1198))})
        # Controlled relocation boundary, retaining original pose write and
        # sample-height result. Geometry selection is validated separately.
        p.u32(0x680ae0, SCRATCH + 0x6000)
        for i, v in enumerate([100, 200, 300]):
            p.f32(SCRATCH + 0x6008 + i * 4, v)
        for address, code in {
            0x493430: b"\x31\xc0\xc3", 0x48d930: b"\xb8\x01\0\0\0\xc2\x04\0",
            0x450690: b"\x31\xc0\xc3", 0x493540: b"\xc3",
            0x430ff0: b"\xd9\x05" + struct.pack("<I", SCRATCH + 0x2200) + b"\xc3",
        }.items(): p.uc.mem_write(address, code)
        p.f32(SCRATCH + 0x2200, 25)
        identity = [1 if i in [0, 5, 10, 15] else 0 for i in range(16)]
        for shrinking in [True, False]:
            for frame in range(20):
                p.uc.mem_write(RENDER + 0x10, struct.pack("<16f", *identity))
                p.u32(SPAWN + 0x1194, frame)
                p.u32(SPAWN + 0x1198, int(shrinking))
                p.u32(SPAWN + 0x11a0, 0)
                for i, v in enumerate([5, 6, 7]): p.f32(RENDER + 0x50 + i * 4, v)
                for i, v in enumerate([4, -8, 12]): p.f32(OBJECT + 0x9c + i * 4, v)
                p.uc.reg_write(UC_X86_REG_ECX, SPAWN)
                p.run(0x48ca60)
                output["updates"].append({"precision": precision, "shrinking": shrinking, "frame": frame,
                    "matrix": list(struct.unpack("<16f", p.uc.mem_read(RENDER + 0x10, 64))),
                    "position": [p.float(RENDER + 0x50 + i * 4) for i in range(3)],
                    "velocity": [p.float(OBJECT + 0x9c + i * 4) for i in range(3)],
                    "frameAfter": p.integer(SPAWN + 0x1194),
                    "shrinkingAfter": bool(p.integer(SPAWN + 0x1198)),
                    "finished": bool(p.integer(SPAWN + 0x11a0))})
        p.u32(0x53ba78, 1)
        p.u32(0x53ba60, 1)
        p.u32(0x53b9b0, 0)
        for dt in [0, .01, .025, .1]:
            for angle in [0, 120, 4090]:
                for scale in [1, .1]:
                    p.uc.mem_write(RENDER + 0x10, struct.pack("<16f", *[
                        scale if i in [0, 5, 10] else 1 if i == 15 else 0 for i in range(16)]))
                    for i, v in enumerate([10, 20, 30]): p.f32(RENDER + 0x40 + i * 4, v)
                    p.f32(SPAWN + 0x11a8, angle)
                    p.f32(SCRATCH + 0x1000, dt)
                    p.uc.reg_write(UC_X86_REG_ECX, SPAWN)
                    p.run(0x48d610)
                    if p.uc.reg_read(UC_X86_REG_EIP) != SCRATCH:
                        p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP), SCRATCH, count=1000000)
                    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH, "Original ring generator did not return"
                    output["rings"].append({"precision": precision, "deltaSeconds": p.float(SCRATCH + 0x1000),
                        "angle": angle, "scale": scale, "position": [10, 20, 30],
                        "angleAfter": p.float(SPAWN + 0x11a8),
                        "positions": [p.float(SPAWN + i * 32 + axis * 4) for i in range(140) for axis in range(3)]})
        q = NativeProbe(SOURCE)
        q.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
        q.uc.mem_map(0, 4096)
        q.uc.mem_map(0x24000000, 0x400000)
        q.uc.mem_map(0x25000000, 0x100000)
        q.uc.mem_map(SPAWN, 0x2000)
        q.u32(0x680b28, 0x24000000)
        q.u32(0x680ae0, 0x25000000)
        q.u32(0x68021c, SCRATCH + 0x8000)
        q.uc.mem_write(0x4afce0, b"\x31\xc0\xc3")
        q.u32(0x508610, 2)
        q.u32(0x53be28, 0)
        q.u32(0x5081bc, 1)
        q.u32(0x50822c, 2)
        for actor in range(3): q.u32(OBJECT + actor * 0xd0 + 0xc, actor)
        for position in [[40, 9999, 20], [40, 0, 21], [0, 10000, 0], [44.72136, 0, 0], [1000, 0, 0]]:
            for actor, values in [(1, position), (2, [1000, 0, 1000])]:
                for i, value in enumerate(values): q.f32(RENDER + actor * 0xa9 + 0x50 + i * 4, value)
            q.run(0x48c170, [0, 0.0, 0.0, 0.0])
            output["clearance"].append({"precision": precision, "other": position,
                "expected": bool(q.uc.reg_read(UC_X86_REG_EAX) & 255)})
        for actor in [1, 2]:
            for i in range(3): q.f32(RENDER + actor * 0xa9 + 0x50 + i * 4, 100000)
        for track_id in range(6):
            track = json.loads((ROOT / f"public/assets/tracks/etappe{track_id}.json").read_text())
            q.u32(0x680b2c, len(track["route"]))
            for i, route in enumerate(track["route"]):
                q.u32(SCRATCH + 0x8000 + i * 4, i)
                for axis, value in enumerate(route["position"]):
                    q.f32(0x24000000 + i * 0x984 + 0x24 + axis * 4, value)
            for i, node in enumerate(track["drive"]):
                base = 0x25000000 + i * 0x50
                q.u32(base, node["unknown"][0])
                q.u32(base + 4, node["unknown"][1])
                for axis, value in enumerate(node["position"]): q.f32(base + 8 + axis * 4, value)
                for offset, value in zip([0x14, 0x1c, 0x18, 0x20], node["links"]):
                    q.u32(base + offset, value & 0xffffffff)
                q.u32(base + 0x24, 0)
            for start in [0, 5, 20, 100, len(track["drive"]) - 1]:
                for occupied in [[], [start], [start, *[x for x in track["drive"][start]["links"] if x >= 0]]]:
                    for node in occupied: q.u32(0x25000000 + node * 0x50 + 0x24, 1)
                    q.f32(SCRATCH + 0x1000, .025)
                    q.u32(SCRATCH + 0x7000, start)
                    q.uc.reg_write(UC_X86_REG_ECX, SPAWN)
                    q.run(0x48d930, [SCRATCH + 0x7000])
                    selected = q.integer(SCRATCH + 0x7000)
                    output["waypoints"].append({"precision": precision, "track": track_id,
                        "start": start, "occupied": occupied, "expected": selected})
                    for node in occupied: q.u32(0x25000000 + node * 0x50 + 0x24, 0)
                    point = track["drive"][selected]["position"]
                    for axis, value in enumerate(point): q.f32(SCRATCH + 0x7100 + axis * 4, value)
                    q.run(0x450500, [SCRATCH + 0x7100])
                    output["nearestSectors"].append({"precision": precision, "track": track_id,
                        "position": point, "expected": q.uc.reg_read(UC_X86_REG_EAX)})
        q.u32(0x680b2c, 1)
        q.u32(SCRATCH + 0x8000, 0)
        for forward in [[1, 0, 0], [0, 0, 1], [0, 0, -1], [-1, 0, 0], [.34101, .3, -.734], [-.291, -.1, .55234]]:
            for i, value in enumerate(forward): q.f32(0x24000000 + 0x48 + i * 4, value)
            q.run(0x493540, [0, 0, 1])
            output["headings"].append({"precision": precision, "forward": [q.float(0x24000000 + 0x48 + i * 4) for i in range(3)],
                                       "expected": q.float(RENDER + 0x78)})
    output["method"] = ("Original x86 initialization, per-tick spawn update and all 140 effect vertices. "
                        "Texture lookup and relocation/height services controlled; no Wine or full-game claim.")
    target = ROOT / "evidence/native/rescue-fixtures.json"
    target.write_text(json.dumps(output, indent=2) + "\n")
    print(f"Wrote {len(output['updates'])} spawn updates and {len(output['rings'])} ring geometry cases")


if __name__ == "__main__":
    generate()
