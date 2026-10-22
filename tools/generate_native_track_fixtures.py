#!/usr/bin/env python3
"""Exercise original native sector and triangle selection on all six tracks."""
import json
import math
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EAX, UC_X86_REG_FPCW

AUX = 0x23000000
ROAD = AUX
SECTORS = AUX + 0x10000
VERTICES = AUX + 0x100000
INDICES = AUX + 0x200000


def fp(v):
    return struct.unpack("<f", struct.pack("<f", v))[0]


def plane(vertices):
    a, b, c = vertices
    u, v = [[fp(t[i] - a[i]) for i in range(3)] for t in [b, c]]
    normal = [fp(u[1]*v[2]-u[2]*v[1]), fp(u[2]*v[0]-u[0]*v[2]), fp(u[0]*v[1]-u[1]*v[0])]
    length = math.sqrt(sum(x*x for x in normal))
    if not length: return [0, 0, 0], 0
    normal = [fp(x/length) for x in normal]
    return normal, fp(sum(normal[i]*a[i] for i in range(3)))


def main():
    p = NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f)
    p.uc.mem_map(AUX, 0x300000)
    p.uc.mem_write(0x4afce0, b"\xc3")  # logging only
    p.u32(0x680b70, ROAD)
    p.u32(0x680b28, SECTORS)
    p.u32(ROAD + 4, AUX + 0x8000)
    rng = random.Random(4977)
    output = []
    for track_id in range(6):
        track = json.loads((ROOT / f"public/assets/tracks/etappe{track_id}.json").read_text())
        count = track["sectorCount"]
        p.u32(ROAD + 8, count)
        for i, value in enumerate(track["position"]):
            vertex, axis = divmod(i, 3)
            p.f32(VERTICES + vertex * 32 + axis * 4, value)
        for i, route in enumerate(track["route"]):
            p.u32(AUX + 0x8000 + i*4, i)
            for axis in range(3): p.f32(SECTORS + i*0x984 + 0x24 + axis*4, route["position"][axis])
            for count_offset, list_offset, key in [(0xe4,0x124,"driveLeftIndices"),(0xe8,0x154,"driveIndices")]:
                p.u32(SECTORS+i*0x984+count_offset,len(route[key]))
                for j,index in enumerate(route[key]):p.u32(SECTORS+i*0x984+list_offset+j*4,index)
        native_sectors = []
        for i in range(count):
            current = SECTORS + i*0x984
            previous = SECTORS + ((i+count-1) % count)*0x984 + 0x24
            following = SECTORS + ((i+1) % count)*0x984 + 0x24
            p.uc.reg_write(UC_X86_REG_ECX, current)
            p.run(0x495cb0, [previous, following])
        # Last-sector copied fields in original 0x496b40.
        for offset, length in [(0x30, 36), (0x5c, 64), (0xdc, 4)]:
            p.uc.mem_write(SECTORS + (count-1)*0x984 + offset,
                bytes(p.uc.mem_read(SECTORS + (count-2)*0x984 + offset, length)))
        for i in range(count):
            base = SECTORS + i*0x984
            native_sectors.append({
                "side": [p.float(base+0x30+axis*4) for axis in range(3)],
                "forward": [p.float(base+0x48+axis*4) for axis in range(3)],
                "fallback": {"normal": [p.float(base+0x3c+axis*4) for axis in range(3)], "distance": p.float(base+0xdc)}
            })
        p.u32(0x68021c,AUX+0x8000)
        p.u32(0x680220,count)
        p.u32(0x680b2c,count)
        p.u32(0x680ae0,AUX+0x2a0000)
        for i,node in enumerate(track["drive"]):
            p.u32(AUX+0x2a0000+i*0x50,node["unknown"][0])
            p.u32(AUX+0x2a0000+i*0x50+4,node["unknown"][1])
            for axis in range(3):p.f32(AUX+0x2a0000+i*0x50+8+axis*4,node["position"][axis])
        starts=[]
        for opponents in [0,1,4]:
            p.u32(0x508610,opponents)
            p.u32(0x507f40,0)
            p.uc.mem_write(0x5072c0,bytes(200))
            p.run(0x415dd0)
            if not p.integer(0x5072b8)&255:raise ValueError("Original grid lookup failed")
            sector=p.integer(0x5072c4)
            position=[p.float(0x5072c8+axis*4) for axis in range(3)]
            p.run(0x493540,[0,sector,1])
            starts.append({"opponentCount":opponents,"sector":sector,"position":position,"yaw":p.float(SCRATCH+0x4000+0x78)})
        # Supply original triangles and separately calculated float planes.
        # Plane initialization itself is not the subject of these fixtures.
        for kind, obj_off, range_off, normal_off, distance_off, slot in [
            ("road", 0x6a, 0, 0x184, 0x304, 0),
            ("land", 0x7a, 8, 0x384, 0x5c4, 1),
            ("extra", 0x8a, 24, 0x804, 0x924, 2),
        ]:
            pointer = INDICES + slot*0x20000
            p.u32(ROAD + obj_off, VERTICES)
            p.u32(ROAD + obj_off+4, pointer)
            cursor = 0
            for group in [g for g in track["groups"] if g["kind"] == kind]:
                base = SECTORS + group["sector"]*0x984
                p.u32(base+range_off, cursor)
                for j in range(0, group["count"], 3):
                    indices = track["index"][group["start"]+j:group["start"]+j+3]
                    for index in indices:
                        p.uc.mem_write(pointer+cursor*2, struct.pack("<H", index))
                        cursor += 1
                    vertices = [track["position"][index*3:index*3+3] for index in indices]
                    normal, distance = plane(vertices)
                    for axis in range(3): p.f32(base+normal_off+(j//3)*12+axis*4, normal[axis])
                    p.f32(base+distance_off+(j//3)*4, distance)
                p.u32(base+range_off+4, cursor)
        cases = []
        for j in range(160):
            hint = rng.randrange(count)
            source = track["route"][(hint+rng.randrange(-3,4)) % count]["position"]
            point = [fp(source[0]+rng.uniform(-300,300)), fp(source[1]), fp(source[2]+rng.uniform(-300,300))]
            p.uc.reg_write(UC_X86_REG_ECX, ROAD)
            p.run(0x4977d0, [hint, *[float(v) for v in point]])
            sector = p.uc.reg_read(UC_X86_REG_EAX)
            if sector >= count: raise ValueError(f"Native invalid sector {sector}")
            base = SECTORS+sector*0x984
            p.uc.reg_write(UC_X86_REG_ECX, base)
            p.run(0x495fe0, [*[float(v) for v in point], SCRATCH+0x9000, SCRATCH+0x9004, SCRATCH+0x9008])
            kind, triangle = p.integer(SCRATCH+0x9004), p.integer(SCRATCH+0x9008)
            p.uc.reg_write(UC_X86_REG_ECX, base)
            height = p.run(0x496290, [*[float(v) for v in point], kind, triangle], float_return=True)
            cases.append({"hint": hint, "point": point, "expected": {
                "sector": sector, "kind": {0:"land",1:"road",2:"extra"}.get(kind,"fallback"),
                "triangle": triangle if triangle != 0xffffffff else -1, "height": height}})
        output.append({"id": track_id, "sectors": native_sectors, "cases": cases,"starts":starts})
    path = ROOT / "evidence/gameplay/native-track-fixtures.json"
    path.write_text(json.dumps({"sourceSha256":p.sha,"fpuControlWord":"0x007f","runtimeAngleCount":4096,
        "scope":"Native 495cb0/4977d0/495fe0/496290 on original six tracks. Triangle planes supplied as explicit inputs; initializer and whole collision not claimed.",
        "tracks":output},indent=2)+"\n")
    print(f"Wrote {sum(len(t['cases']) for t in output)} native track selection cases")


if __name__ == "__main__":
    main()
