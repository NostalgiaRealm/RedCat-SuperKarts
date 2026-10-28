#!/usr/bin/env python3
"""Exercise original native sector setup, triangle planes (0x494f40) and selection on all six tracks."""
import json
import math
import random
import re
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, CONTROL_WORD, precision_path
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_FPCW

AUX = 0x23000000
ROAD = AUX
SECTORS = AUX + 0x10000
# 0x494d20 reads RMP tiles into the 0x8c-byte array at [0x6a5ba0] and passes
# per-sector tile-id lists to 0x494f40, which appends four vertices per tile
# and three indices per triangle to the road object's per-kind buffers.
TILES = 0x24000000
LISTS = TILES + 0x100000
BUFFERS = 0x25000000
# RMP material order (0x494d20 reads road, land, extra, rail). Road-object
# offsets of each kind's vertex pointer, index pointer, vertex count and index
# count (0x496610-0x4969e0), and the sector-struct plane arrays 0x494f40 fills.
KINDS = [
    ("road", 0x6a, 0x184, 0x304),
    ("land", 0x7a, 0x384, 0x5c4),
    ("extra", 0x8a, 0x804, 0x924),
    ("rail", 0x5a, 0x684, 0x7a4),
]
RANGES = {"road": 0, "land": 8, "rail": 16, "extra": 24}


def fp(v):
    return struct.unpack("<f", struct.pack("<f", v))[0]


def rmp_tiles(track_id, track):
    """Original Etappe RMP tiles as 0x49cc90 stores them, checked against the port's asset."""
    path = next(f for f in SOURCE.iterdir() if f.name.lower() == f"etappe{track_id}.rmp")
    data = path.read_bytes()
    marker, _, sector_count = struct.unpack_from("<iII", data)
    if marker != -1 or sector_count != track["sectorCount"]: raise ValueError(f"{path.name}: unexpected RMP header")
    offset, sectors, tiles = 12, [], []
    for _ in range(sector_count):
        lists = []
        for _ in KINDS:
            count = struct.unpack_from("<I", data, offset)[0]; offset += 4
            ids = []
            for _ in range(count):
                tile = bytearray(0x8c)
                for vertex in range(4):
                    x, y, z, u, v, color = struct.unpack_from("<5fI", data, offset); offset += 24
                    # 0x49cc90: x, y, z at +0/+4/+8, u, v at +0x18/+0x1c, swapped RGB at +0x10.
                    swapped = ((color & 255) << 16) | (color & 0xff00) | ((color >> 16) & 255)
                    struct.pack_into("<3fI", tile, vertex*32, x, y, z, 0)
                    struct.pack_into("<IIff", tile, vertex*32 + 16, swapped, 0, u, v)
                corners = struct.unpack_from("<6I", data, offset); offset += 24
                struct.pack_into("<6h", tile, 0x80, *corners)
                ids.append(len(tiles))
                tiles.append(bytes(tile))
            lists.append(ids)
        sectors.append(lists)
    if offset != len(data): raise ValueError(f"{path.name}: trailing RMP data")
    # The port's vertices are these tile vertices in the same corner order.
    position = [fp(v) for tile in tiles for vertex in range(4) for v in struct.unpack_from("<3f", tile, vertex*32)]
    index = [4*i + corner for i, tile in enumerate(tiles) for corner in struct.unpack_from("<6h", tile, 0x80)]
    if position != track["position"] or index != track["index"]:
        raise ValueError(f"etappe{track_id}.json vertices differ from {path.name}")
    return sectors, tiles


def native_float(p, address):
    """Stored float; null for the x87 default NaN that 0x494f40's 0/0 gives on zero-area triangles."""
    if p.integer(address) == 0xffc00000: return None
    value = p.float(address)
    if not math.isfinite(value): raise ValueError(f"Unexpected non-finite native float at 0x{address:x}")
    return value


def run_checked(p, address, args):
    p.run(address, args)
    if p.uc.reg_read(UC_X86_REG_EIP) != SCRATCH: raise RuntimeError(f"0x{address:x} did not return")


def main():
    p = NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW, CONTROL_WORD)
    p.uc.mem_map(AUX, 0x300000)
    p.uc.mem_map(TILES, 0x200000)
    p.uc.mem_map(BUFFERS, 0x400000)
    p.u32(0x6a5ba0, TILES)
    # 0x4968a0/0x4967f0/0x496940/0x4969e0 adjust only texture UVs (+0x18/+0x1c)
    # when [road+0x9a] is 0; positions are copied unchanged either way.
    p.u32(ROAD + 0x9a, 1)
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
        # Native 0x494f40 per sector, in load order, from the original RMP tiles.
        tile_lists, tiles = rmp_tiles(track_id, track)
        p.uc.mem_write(TILES, b"".join(tiles))
        for slot, (_, obj_off, _, _) in enumerate(KINDS):
            p.u32(ROAD + obj_off, BUFFERS + slot*0x100000)
            p.u32(ROAD + obj_off + 4, BUFFERS + slot*0x100000 + 0xc0000)
            p.u32(ROAD + obj_off + 8, 0)
            p.u32(ROAD + obj_off + 12, 0)
        native_planes = []
        for i, lists in enumerate(tile_lists):
            args = []
            for slot, ids in enumerate(lists):
                for j, tile in enumerate(ids): p.u32(LISTS + slot*0x100 + j*4, tile)
                args += [LISTS + slot*0x100, len(ids)]
            base = SECTORS + i*0x984
            p.uc.reg_write(UC_X86_REG_ECX, base)
            run_checked(p, 0x494f40, args)
            planes = {}
            for kind, _, normal_off, distance_off in KINDS[:3]:
                start, end = p.integer(base + RANGES[kind]), p.integer(base + RANGES[kind] + 4)
                rows = [[native_float(p, base + normal_off + t*12 + axis*4) for axis in range(3)] +
                        [native_float(p, base + distance_off + t*4)] for t in range((end - start) // 3)]
                if len(rows) * 3 != sum(g["count"] for g in track["groups"] if g["sector"] == i and g["kind"] == kind):
                    raise ValueError(f"Native {kind} triangle count differs in sector {i}")
                planes[kind] = [f"@plane:{json.dumps(row)}" for row in rows]
            native_planes.append(planes)
        for sector, planes in zip(native_sectors, native_planes): sector["planes"] = planes
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
    path = precision_path(ROOT / "evidence/gameplay/native-track-fixtures.json")
    text = json.dumps({"sourceSha256":p.sha,"fpuControlWord":f"0x{CONTROL_WORD:04x}","runtimeAngleCount":4096,
        "scope":"Native 495cb0/494f40/4977d0/495fe0/496290 on original six tracks. Triangle planes [nx, ny, nz, distance] per sector come from native 494f40 on the original RMP tiles; whole collision not claimed.",
        "tracks":output},indent=2)+"\n"
    path.write_text(re.sub(r'"@plane:([^"]*)"', r"\1", text))
    print(f"Wrote {sum(len(t['cases']) for t in output)} native track selection cases")


if __name__ == "__main__":
    main()
