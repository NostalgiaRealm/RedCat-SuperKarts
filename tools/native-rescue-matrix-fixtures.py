#!/usr/bin/env python3
"""Execute the original rescue matrix scale and its two next-tick readers.

0x48ca60 copies the body render matrix (+0x10, 0x48cc4e..0x48cc57), calls
0x4a17c0(out=copy, scale, in=copy) in place and copies it back. Until 0x491d30
rebuilds the body (0x4a09e0 at 0x49206f), the player callback 0x4325b0 reads
that scaled matrix through 0x41c0b0 (wheel ground samples) and 0x415520
(slope terms +0x14/+0x34). This probe runs those original instructions on
rotated body matrices at both x87 precisions.

Boundaries: the engine route (0x4977d0), triangle (0x495fe0) and height
(0x496290) services are replaced; the height stub logs its (x, y, z) arguments
and returns supplied heights. Body matrices, positions and heights are
synthetic inputs. Instruction emulation only; no Wine or full-game claim.
Run with re-python.
"""
import json
import math
import struct
from unicorn import UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig

AUX = 0x24000000
RENDER = SCRATCH + 0x4000
SHRINK, GROW = 0x67df70, 0x67da70
CURSOR, HEIGHTS, LOG, STUB, BUFFER = AUX + 0xa000, AUX + 0xa100, AUX + 0xb000, AUX + 0xc000, AUX + 0xd000
# Shrink frames 0/1/3/11/19 are 1.2/1.4/1/0.5/0.1; grow frames 0/8/16/17/18
# are 0.1/0.5/1/1.2/1.4 (0x48c520 fills grow as reversed shrink).
FRAMES = [("shrink", f) for f in [0, 1, 3, 11, 19]] + [("grow", f) for f in [0, 8, 16, 17, 18]]
SPEEDS = [-12, 3, 8, 25]


def fp(value):
    return struct.unpack("<f", struct.pack("<f", value))[0]


def rotation(yaw, pitch, roll):
    """Row-major Ry(yaw)*Rx(pitch)*Rz(roll), rounded to float32."""
    cy, sy, cp, sp, cr, sr = (f(math.radians(a)) for a in [yaw, pitch, roll] for f in [math.cos, math.sin])
    ry = [[cy, 0, sy], [0, 1, 0], [-sy, 0, cy]]
    rx = [[1, 0, 0], [0, cp, -sp], [0, sp, cp]]
    rz = [[cr, -sr, 0], [sr, cr, 0], [0, 0, 1]]
    mul = lambda a, b: [[sum(a[i][k] * b[k][j] for k in range(3)) for j in range(3)] for i in range(3)]
    return [fp(v) for row in mul(mul(ry, rx), rz) for v in row]


# (name, row-major 3x3 body matrix, position). The last is a pure yaw with
# explicit -0 entries, to expose the multiply's signed-zero behaviour.
c, s = fp(math.cos(math.radians(40))), fp(math.sin(math.radians(40)))
BODIES = [
    ("yaw30-pitch8-roll-5", rotation(30, 8, -5), [1234.5, 37.25, -4321.75]),
    ("yaw200-pitch-12-roll15", rotation(200, -12, 15), [-2346.0, 22.0, 7000.0]),
    ("yaw-75-pitch25-roll3", rotation(-75, 25, 3), [3001.125, 18.5, -4200.0]),
    ("yaw123-pitch2-roll-20", rotation(123, 2, -20), [-512.0, 64.75, 96.5]),
    ("yaw10-pitch-30-roll-30", rotation(10, -30, -30), [88.0, 5.0, -77.0]),
    ("yaw40-signed-zero", [c, -0.0, s, -0.0, 1.0, -0.0, -s, -0.0, c], [400.0, 12.0, -300.0]),
]
CARS = json.loads((ROOT / "public/assets/cars.json").read_text())["cars"]["0"]
GEOMETRY = [
    {"name": "cars.json car 0", "local": CARS["wheelOffsets"], "radii": [CARS["frontRadius"], CARS["rearRadius"]]},
    {"name": "synthetic", "local": [[-10, 0, 18], [10, 0, 18], [-10, 0, -18], [10, 0, -18]], "radii": [4, 5]},
]


def native4x4(matrix, position):
    # Render +0x40..+0x4c holds the translation row and [15]=1 (0x4a09e0).
    return [*matrix[0:3], 0, *matrix[3:6], 0, *matrix[6:9], 0, *position, 1]


def install_wheel_setup(p):
    """tools/generate_native_ground_fixtures.py lines 23-100 boundary setup."""
    p.uc.mem_map(AUX, 0x10000)
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
    for i in range(4):
        for offset in [0x80, 0x84, 0x88]:
            p.f32(RENDER + (i + 1) * 0xa9 + offset, 1)
    p.uc.mem_write(0x4977d0, b"\x31\xc0\xc2\x10\x00")  # route chunk 0
    p.uc.mem_write(0x495fe0, b"\xc2\x18\x00")  # triangle lookup leaves outputs
    # Height service: log [esp+4..0xc] (x, y, z) to LOG[cursor], return
    # HEIGHTS[cursor] in ST0, advance cursor, RET 0x14 like the original.
    stub = (b"\xa1" + struct.pack("<I", CURSOR) +            # mov eax,[cursor]
            b"\x8d\x14\x40" +                                  # lea edx,[eax+eax*2]
            b"".join(b"\x8b\x4c\x24" + bytes([4 + 4 * k]) +    # mov ecx,[esp+4+4k]
                     b"\x89\x0c\x95" + struct.pack("<I", LOG + 4 * k) for k in range(3)) +
            b"\xd9\x04\x85" + struct.pack("<I", HEIGHTS) +   # fld [heights+eax*4]
            b"\x40\xa3" + struct.pack("<I", CURSOR) +         # inc eax; mov [cursor],eax
            b"\xc2\x14\x00")
    p.uc.mem_write(STUB, stub)
    p.uc.mem_write(0x496290, b"\xe9" + struct.pack("<i", STUB - (0x496290 + 5)))


class MatrixAccess:
    """Record which body-matrix bytes (+0x10..+0x4f) an entrypoint touches."""

    def __init__(self, p):
        self.reads, self.writes, self.active = {}, set(), None
        lo, hi = RENDER + 0x10, RENDER + 0x4f
        p.uc.hook_add(UC_HOOK_MEM_READ, self.read, begin=lo, end=hi)
        p.uc.hook_add(UC_HOOK_MEM_WRITE, self.write, begin=lo, end=hi)

    def read(self, uc, access, address, size, value, data):
        if self.active:
            self.reads.setdefault(self.active, set()).add((uc.reg_read(UC_X86_REG_EIP), address - RENDER))

    def write(self, uc, access, address, size, value, data):
        if self.active:
            self.writes.add((self.active, uc.reg_read(UC_X86_REG_EIP), address - RENDER))


def generate():
    output = {"format": "superkarts-native-rescue-matrix-v1", "scaleTables": [], "cases": []}
    access_summary = {}
    for precision in [24, 53]:
        p = NativeProbe(SOURCE)
        output["sourceSha256"] = p.sha
        control = 0x7f if precision == 24 else 0x27f
        p.uc.reg_write(UC_X86_REG_FPCW, control)
        initialize_native_trig(p)  # also writes the 0x6a5c90 identity
        assert p.uc.reg_read(UC_X86_REG_FPCW) & 0xffff == control
        # 0x48c7e0 calls 0x48c520 (0x48c98d): identity copies, diagonal
        # scale stores, then grow[19-k] = shrink[k]; guarded by 0x67e4cc.
        p.uc.mem_write(0x67e4cc, b"\0")
        p.run(0x48c520)
        tables = {name: [list(struct.unpack("<16f", p.uc.mem_read(base + i * 64, 64))) for i in range(20)]
                  for name, base in [("shrink", SHRINK), ("grow", GROW)]}
        output["scaleTables"].append({"precision": precision, **tables})
        install_wheel_setup(p)
        access = MatrixAccess(p)
        for index, ((body_name, matrix, position), (table, frame)) in enumerate(
                (body, frame) for body in BODIES for frame in FRAMES):
            geometry = GEOMETRY[index % 2]
            native = native4x4(matrix, [fp(v) for v in position])
            p.uc.mem_write(RENDER + 0x10, struct.pack("<16f", *native))
            for axis in range(3):
                p.f32(RENDER + 0x50 + axis * 4, position[axis])
            # 0x48cc4e..0x48cc7f: copy, in-place 4x4 multiply, copy back.
            p.uc.mem_write(BUFFER, bytes(p.uc.mem_read(RENDER + 0x10, 64)))
            scale_address = (SHRINK if table == "shrink" else GROW) + frame * 64
            p.run(0x4a17c0, [BUFFER, scale_address, BUFFER])
            p.uc.mem_write(RENDER + 0x10, bytes(p.uc.mem_read(BUFFER, 64)))
            scaled = list(struct.unpack("<16f", p.uc.mem_read(RENDER + 0x10, 64)))
            scaled_bits = [struct.unpack("<I", struct.pack("<f", v))[0] for v in scaled]

            # Wheel pose 0x41c0b0 with the scaled body matrix.
            delta = fp([0.025, 0.03125, 1 / 60][index % 3])
            steering = fp([37.5, -80.0, 0.0, 100.0][index % 4])
            speed = fp([12.0, -7.5, 20.0][index % 3])
            radii = [fp(v) for v in geometry["radii"]]
            p.f32(AUX + 0x8300 + 0x14, -radii[0])
            p.f32(AUX + 0x8300 + 0xbc + 0x14, -radii[1])
            heights = []
            for i, local in enumerate(geometry["local"]):
                for axis in range(3):
                    p.f32(RENDER + (i + 1) * 0xa9 + 0x50 + axis * 4, local[axis])
                for offset in [0x60, 0x74, 0x78, 0x7c]:
                    p.f32(RENDER + (i + 1) * 0xa9 + offset, 0)
                # Approximate scaled sample height plus an offset, so the
                # suspension difference covers both clamps and the open range.
                y = position[1] + local[0] * scaled[1] + local[2] * scaled[9]
                heights.append(fp(y + [-2.0, -0.4, 0.3, 1.5][(i + index) % 4]))
            p.f32(OBJECT + 0xa4, speed)
            p.f32(OBJECT + 0x9c, 0)
            p.f32(SCRATCH + 0x1000, delta)
            p.f32(0x53bd70, steering)
            p.u32(CURSOR, 0)
            for i, height in enumerate(heights):
                p.f32(HEIGHTS + 4 * i, height)
            access.active = "0x41c0b0"
            p.run(0x41c0b0, [0])
            access.active = None
            calls = p.integer(CURSOR)
            assert calls == 4, f"0x41c0b0 sampled {calls} heights"
            samples = [[p.float(LOG + call * 12 + axis * 4) for axis in range(3)] for call in range(calls)]
            wheels = [{"localY": p.float(RENDER + (i + 1) * 0xa9 + 0x54),
                       "spin": p.float(RENDER + (i + 1) * 0xa9 + 0x74),
                       "steeringAngle": p.float(RENDER + (i + 1) * 0xa9 + 0x78)} for i in range(4)]
            assert list(struct.unpack("<16f", p.uc.mem_read(RENDER + 0x10, 64))) == scaled

            # Resistance 0x415520 with the scaled +0x14/+0x34 slope terms.
            preset, record, tire_upgrade = index % 3, index % 10, (index // 3) % 2
            mass = [200, 500, 1000][index % 3]
            p.set_physics(preset, record)
            p.u32(0x53bef4, tire_upgrade)
            resistance = []
            for forward in SPEEDS:
                for handbrake in [False, True]:
                    p.set_body(forward, 0.0, 0.0, mass)
                    p.u32(0x53bdf4, int(handbrake))
                    for k in range(3):
                        p.f32(SCRATCH + 0x3000 + 4 * k, 12345.0)
                    access.active = "0x415520"
                    p.run(0x415520, [SCRATCH + 0x3000, 0])
                    access.active = None
                    resistance.append({"forwardSpeed": p.float(OBJECT + 0xa4), "handbrake": handbrake,
                                       "mass": 1 / p.float(OBJECT + 0x90),
                                       "lateral": p.float(SCRATCH + 0x3000),
                                       "middle": p.float(SCRATCH + 0x3004),
                                       "longitudinal": p.float(SCRATCH + 0x3008)})
            p.u32(0x53bdf4, 0)
            output["cases"].append({
                "precision": precision, "body": body_name, "table": table, "frame": frame,
                "scale": tables[table][frame][0],
                "matrix": matrix, "position": [fp(v) for v in position],
                "native4x4": native, "scaled4x4": scaled, "scaledBits": scaled_bits,
                "wheelPose": {"geometry": geometry["name"],
                              "wheels": [{"local": [fp(v) for v in local], "radius": radii[i // 2]}
                                         for i, local in enumerate(geometry["local"])],
                              "deltaSeconds": delta, "steering": steering, "forwardSpeed": speed,
                              "heights": heights, "samples": samples, "expected": wheels},
                "resistance": {"preset": preset, "record": record, "tireUpgrade": tire_upgrade,
                               "results": resistance},
            })
        for entry, reads in access.reads.items():
            summary = access_summary.setdefault(entry, {"pcs": set(), "offsets": set()})
            summary["pcs"].update(pc for pc, _ in reads)
            summary["offsets"].update(offset & ~3 for _, offset in reads)
        assert not access.writes, f"body matrix written by a reader: {sorted(access.writes)[:4]}"
    output["bodyMatrixReads"] = {entry: {
        "pcs": [f"0x{pc:x}" for pc in sorted(summary["pcs"])],
        "offsets": [f"+0x{offset:02x}" for offset in sorted(summary["offsets"])]}
        for entry, summary in sorted(access_summary.items())}
    output["method"] = (
        "Original x86 0x48c520 scale tables, 0x4a17c0 in place as at 0x48cc4e..0x48cc7f/0x48d283..0x48d2b4, "
        "then 0x41c0b0 and 0x415520 on that scaled render matrix. Route/triangle/height services replaced; "
        "the height stub logs its (x, y, z) arguments. Synthetic body matrices, positions and heights; "
        "shipped Phys*.dat and cars.json wheel geometry. No Wine or full-game claim.")
    target = ROOT / "evidence/native/rescue-matrix-fixtures.json"
    target.write_text(json.dumps(output, indent=1) + "\n")
    print(f"Wrote {len(output['cases'])} scaled-matrix cases "
          f"({sum(len(c['resistance']['results']) for c in output['cases'])} resistance results) to {target}")
    print(json.dumps(output["bodyMatrixReads"]))


if __name__ == "__main__":
    generate()
