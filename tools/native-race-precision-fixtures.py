#!/usr/bin/env python3
"""x87 precision probes for the NPC driver, race grid, kart inertia and pickups.

Isolated Unicorn instruction emulation of shipped rcskspel.dat code, NOT a
Wine/full game observation. Only emulator memory is changed; the installed
game stays read-only. Inputs come from fixed seeds and the 24-bit native sector
fixture (planes and forward axes as plain float inputs), so the default 24-bit
run and the RCSK_FIXTURE_PRECISION=53 run (control word 0x027f) probe identical
inputs.

Routines (full calls unless a range is given):
  0x494b70                 route-plane height returned in ST0
  0x41c70a..0x41c73d       NPC wheel routine: 0x494b70, FSUB body Y, FST float
  0x41c70a..0x41c767       the same plus the suspension clamp: FCOMP ST0 with 0.0
                           (0x41c737), then FLD the stored float and FCOMP -1.11
                           (0x41c752)
  0x40ea50                 one-second hit-flash expiry
  0x40e79d..0x40e7b8       five-second turbo-flag compare inside 0x40e760
  0x48fda0                 mass/inertia setup for car records 0x4e02a0 + car*300
  0x493540 (direction 1)   grid heading, per sector of all six tracks
  0x44fc80 (and 0x497bd0)  bonus/racer overlap
  0x4540f7..0x454117       static pickup yaw rotation inside 0x4540c0
  0x413330                 vertical spring of the 0x412560 bubble (player and
                           NPC); 0x4977d0 returns the sector hint, 0x494b70 real
"""
import json
import math
import random
import struct

from generate_native_gameplay_fixtures import (NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT, STACK,
                                               CONTROL_WORD, PRECISION, precision_path)
from native_probe_math import initialize_native_trig
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDI,
                               UC_X86_REG_EIP, UC_X86_REG_ESI, UC_X86_REG_ESP)

AUX = 0x23000000
SECTORS = AUX + 0x10000          # 0x984-byte native sector records
SECTOR_MAP = AUX + 0x8000        # [0x68021c] sector -> record table
SHAPES = 0x25000000              # [0x6a5ee0] model records, radius at +0x74
RENDER = SCRATCH + 0x4000        # NativeProbe's [0x6a5c38]
RENDER_STRIDE = 0xa9             # 0x490ce0/0x497bd0 index base + ri*169
PICKUP = SCRATCH + 0x5100
YAW = SCRATCH + 0x5200
SECTOR_SIZE = 0x984


def fp(value):
    return struct.unpack("<f", struct.pack("<f", value))[0]


def model(precision):
    return fp if precision == 24 else (lambda value: value)


def write_sector(p, index, sector):
    base = SECTORS + index * SECTOR_SIZE
    for axis in range(3):
        p.f32(base + 0x3c + axis * 4, sector["fallback"]["normal"][axis])
        p.f32(base + 0x48 + axis * 4, sector["forward"][axis])
    p.f32(base + 0xdc, sector["fallback"]["distance"])
    p.u32(SECTOR_MAP + index * 4, index)
    return base


def wheel_suspension(p, base, x, y, z, end):
    """0x41c70a..end with the 0x41c6ee..0x41c704 argument layout; returns the
    float at [ESP+0x18]. end 0x41c73d stops after the FCOMP at 0x41c737 (the
    FST 0x41c733 value); end 0x41c767 is after the clamp. Both keep the x87
    stack balanced. Unicorn keeps translated blocks across emu_start calls, and
    a cached block that runs through a new stop address does not stop there, so
    the routine's blocks are dropped before each run."""
    sp = STACK + 0xf000
    p.uc.mem_write(sp, struct.pack("<ff", x, z))
    p.f32(RENDER + 0x54, y)
    p.u32(OBJECT + 0xc, 0)
    p.uc.reg_write(UC_X86_REG_ESP, sp)
    p.uc.reg_write(UC_X86_REG_ECX, base)
    p.uc.reg_write(UC_X86_REG_ESI, 0)
    p.uc.ctl_remove_cache(0x41c70a, 0x41c770)
    p.uc.emu_start(0x41c70a, end, count=1000)
    if p.uc.reg_read(UC_X86_REG_EIP) != end:
        raise RuntimeError(f"0x41c70a..0x{end:x} stopped at 0x{p.uc.reg_read(UC_X86_REG_EIP):x}")
    return p.float(p.uc.reg_read(UC_X86_REG_ESP) + 0x18)


def route_plane(p, tracks, sector_fixture, rng):
    cases = []
    for data in sector_fixture["tracks"]:
        track = tracks[data["id"]]
        for index, sector in enumerate(data["sectors"]):
            write_sector(p, index, sector)
        for _ in range(40):
            index = rng.randrange(len(data["sectors"]))
            plane = data["sectors"][index]["fallback"]
            center = track["route"][index]["position"]
            x, z = fp(center[0] + rng.uniform(-60, 60)), fp(center[2] + rng.uniform(-60, 60))
            normal, distance = plane["normal"], plane["distance"]
            estimate = (distance - x * normal[0] - z * normal[2]) / normal[1]
            y = fp(estimate + rng.uniform(-1.6, 0.4))
            base = SECTORS + index * SECTOR_SIZE
            p.uc.reg_write(UC_X86_REG_ECX, base)
            height = p.run(0x494b70, [x, z], float_return=True)
            suspension = wheel_suspension(p, base, x, y, z, 0x41c73d)
            cases.append({"track": data["id"], "sector": index, "point": [x, y, z],
                          "height": height, "suspension": suspension})
    return cases


def plane_height(precision, plane, x, z):
    """Input selection only: 0x494b70 operation order at either width."""
    r, n = model(precision), plane["normal"]
    return r(r(r(plane["distance"] - r(x * n[0])) - r(z * n[2])) / n[1])


def float_step(value, steps):
    """The float `steps` representable values away from float `value`."""
    bits = struct.unpack("<I", struct.pack("<f", value))[0]
    key = bits if bits < 0x80000000 else -(bits & 0x7fffffff)
    key += steps
    bits = key if key >= 0 else (-key) | 0x80000000
    return struct.unpack("<f", struct.pack("<I", bits))[0]


def suspension_clamp(p, tracks, sector_fixture):
    """0x41c4b0 clamp on the real 0x494b70 register height. 0x41c737 FCOMPs
    the unstored ST0 difference with 0.0 (0x4d2258) and stores 0 only when it
    is above; otherwise 0x41c752 compares the FST float with -1.11 (0x4d2560)
    and stores 0xbf8e147b when it is below. Body Y is chosen at and a few float
    steps around both limits, for the 24- and 53-bit heights, so both runs
    probe the same inputs."""
    rng = random.Random(0x41c737)
    limit = fp(-1.11)
    cases = []
    for data in sector_fixture["tracks"]:
        track, sectors = tracks[data["id"]], data["sectors"]
        for index, sector in enumerate(sectors):
            write_sector(p, index, sector)
        tilted = [i for i, s in enumerate(sectors) if s["fallback"]["normal"][0] or s["fallback"]["normal"][2]]
        flat = [i for i in range(len(sectors)) if i not in tilted]
        for index in rng.sample(tilted, min(3, len(tilted))) + rng.sample(flat, 1):
            plane = sectors[index]["fallback"]
            center = track["route"][index]["position"]
            x, z = fp(center[0] + rng.uniform(-60, 60)), fp(center[2] + rng.uniform(-60, 60))
            ys = set()
            for height in {plane_height(24, plane, x, z), plane_height(53, plane, x, z)}:
                for target in (0.0, limit):
                    base_y = fp(height - target)
                    ys.update(float_step(base_y, step) for step in range(-2, 3))
                    ys.update(fp(height - target + offset) for offset in (-2 ** -12, 2 ** -12))
            base = SECTORS + index * SECTOR_SIZE
            for y in sorted(ys):
                p.uc.reg_write(UC_X86_REG_ECX, base)
                height = p.run(0x494b70, [x, z], float_return=True)
                cases.append({"track": data["id"], "sector": index, "point": [x, y, z], "height": height,
                              "suspension": wheel_suspension(p, base, x, y, z, 0x41c73d),
                              "clamped": wheel_suspension(p, base, x, y, z, 0x41c767)})
    return cases


def bubble_spring(p, tracks, sector_fixture):
    """0x413330 for object 0, as 0x412560 calls it at 0x412610 (floating:
    0x4125f1/0x412602 first zero lateral/forward speed) and 0x412630. Only
    0x4977d0 is replaced, by "return the [obj+0x1c] hint" (MOV EAX,[ESP+4];
    RET 0x10), so callers compare cases whose port selection keeps the hint.
    The real 0x494b70 height is stored over the argument slot (FSTP float
    0x41346e). 0x4134a7..0x4134c4 clears [0x50728c] when height+2 < Y and
    the object is [0x53be28]; each case runs as player and as NPC."""
    initialize_native_trig(p)
    rng = random.Random(0x413330)
    selector = bytes(p.uc.mem_read(0x4977d0, 7))
    p.uc.mem_write(0x4977d0, b"\x8b\x44\x24\x04\xc2\x10\x00")
    sp = STACK + 0xf000                 # NativeProbe.run entry ESP
    cases = []
    for data in sector_fixture["tracks"]:
        track, sectors = tracks[data["id"]], data["sectors"]
        for index, sector in enumerate(sectors):
            write_sector(p, index, sector)
        tilted = [i for i, s in enumerate(sectors) if s["fallback"]["normal"][0] or s["fallback"]["normal"][2]]
        for _ in range(24):
            index = rng.choice(tilted or range(len(sectors)))
            plane = sectors[index]["fallback"]
            center = track["route"][index]["position"]
            x, z = fp(center[0] + rng.uniform(-8, 8)), fp(center[2] + rng.uniform(-8, 8))
            floating = rng.random() < 0.5
            height = fp(plane_height(24, plane, x, z))
            y = (float_step(fp(height + 2), rng.randrange(-2, 3)) if floating and rng.random() < 0.5
                 else fp(height + rng.uniform(-1, 4)))
            body = {"position": [x, y, z], "yaw": fp(rng.uniform(0, 4096)),
                    "lateralSpeed": fp(rng.uniform(-4, 4)), "verticalSpeed": fp(rng.uniform(-5, 5)),
                    "forwardSpeed": fp(rng.uniform(-10, 30))}
            dt = fp(rng.choice([1 / 60, 0.025, 1 / 31, 0.1]))
            case = {"track": data["id"], "sector": index, "floating": floating, "dt": dt, "body": body}
            results = {}
            for role, player in [("player", 0), ("npc", 1)]:
                speeds = [0.0 if floating else body["lateralSpeed"], body["verticalSpeed"],
                          0.0 if floating else body["forwardSpeed"]]
                for offset, value in zip((0x9c, 0xa0, 0xa4), speeds):
                    p.f32(OBJECT + offset, value)
                for axis, value in enumerate(body["position"]):
                    p.f32(RENDER + 0x50 + axis * 4, value)
                p.f32(RENDER + 0x78, body["yaw"])
                p.u32(OBJECT + 0xc, 0)
                p.u32(OBJECT + 0x1c, index)
                p.f32(SCRATCH + 0x1000, dt)
                p.u32(0x53be28, player)
                p.u32(0x50728c, 7)
                p.run(0x413330, [0])
                # Predicted X/Z are the 0x4133fb/0x413430 float locals.
                results[role] = {"sample": [p.float(sp - 0x24), p.float(sp - 0x1c)], "height": p.float(sp + 4),
                                 "verticalSpeed": p.float(OBJECT + 0xa0)}
                case[f"{role}SlipCleared"] = p.integer(0x50728c) == 0
            if results["player"] != results["npc"]:
                raise ValueError("0x413330 differs between player and NPC beyond 0x50728c")
            cases.append({**case, **results["player"]})
    p.uc.mem_write(0x4977d0, selector)
    return cases


def timers(p, rng):
    p.u32(0x508610, 4)
    pairs = [
        # Divergent by construction: the difference needs more than 24 bits.
        (1.125, 0.125 + 2 ** -26), (1.125, 0.125 + 2 ** -25), (1.125, 0.125),
        (5.25, 0.25 + 2 ** -25), (5.5, 0.5 + 2 ** -24), (5.25, 0.25),
        (37.25, 36.25), (37.25, 32.25), (0.0, 0.0), (12.0, 7.0), (12.0, 11.0),
    ]
    divergent = 0
    while divergent < 40:
        limit = rng.choice([1, 5])
        start = fp(rng.uniform(0, 1) * 2 ** -rng.randrange(0, 12))
        now = fp(limit + start + rng.uniform(-2 ** -20, 2 ** -20))
        if (fp(now - start) >= limit) != ((now - start) >= limit):
            pairs.append((now, start))
            divergent += 1
    for _ in range(40):
        now = fp(rng.uniform(0, 600))
        pairs.append((now, fp(now - rng.uniform(0, 10))))
    cases = []
    for now, start in pairs:
        now, start = fp(now), fp(start)
        p.f32(0x67ec78, now)            # 0x48f4d0: FLD [0x67ec70+8]
        p.f32(0x503fe8, start)          # hit time, racer 0
        p.uc.mem_write(0x508215, b"\x01")
        p.run(0x40ea50, [0])
        hit_visible = bool(p.uc.reg_read(UC_X86_REG_EAX) & 0xff)
        if hit_visible != bool(p.uc.mem_read(0x508215, 1)[0]):
            raise ValueError("0x40ea50 return and flag disagree")
        p.f32(0x503fe4, start)          # turbo time, racer 0
        p.uc.reg_write(UC_X86_REG_ESI, 0)
        p.uc.reg_write(UC_X86_REG_ESP, STACK + 0xf000)
        p.uc.emu_start(0x40e79d, 0x40e7b8, count=100)
        below = (p.uc.reg_read(UC_X86_REG_EAX) >> 8) & 1   # C0 after FCOMP 5.0
        cases.append({"now": now, "start": start, "hitExpired": not hit_visible,
                      "turboExpired": not below})
    return cases


def inertia(p):
    cases = []
    for car in range(9):
        base = 0x4e02a0 + car * 300
        mass, length, width = p.float(base), p.float(base + 4), p.float(base + 8)
        p.uc.mem_write(OBJECT, bytes(0xd0))
        p.run(0x48fda0, [0, 0.0, 0.0, 0.0, 0.0, mass, fp(0.2), length, width])
        cases.append({"car": car, "mass": mass, "length": length, "width": width,
                      "inverseMass": p.float(OBJECT + 0x90), "inverseInertia": p.float(OBJECT + 0x94)})
    return cases


def headings(p, sector_fixture):
    p.u32(0x680b28, SECTORS)
    p.u32(0x68021c, SECTOR_MAP)
    output = []
    for data in sector_fixture["tracks"]:
        count = len(data["sectors"])
        p.u32(0x680b2c, count)
        for index, sector in enumerate(data["sectors"]):
            write_sector(p, index, sector)
        yaws = []
        for index in range(count):
            p.u32(OBJECT + 0xc, 0)
            p.run(0x493540, [0, index, 1])
            yaws.append(p.float(RENDER + 0x78))
        output.append({"track": data["id"], "yaws": yaws})
    return output


def overlap_model(precision, a, b):
    r = model(precision)
    dx, dz = r(a["position"][0] - b["position"][0]), r(a["position"][2] - b["position"][2])
    radius = r(a["radius"] + b["radius"])
    planar = r(r(dz * dz) + r(dx * dx)) < r(radius * radius)
    return planar, planar and abs(r(a["position"][1] - b["position"][1])) < radius


def overlaps(p, rng):
    p.uc.mem_map(SHAPES, 0x1000)
    p.u32(0x6a5ee0, SHAPES)
    p.u32(0x508610, 4)
    p.u32(0x53be28, 0)
    for index in [0, 1]:
        p.u32(OBJECT + index * 0xd0 + 0xc, index)
        p.u32(RENDER + index * RENDER_STRIDE, 1)
        p.u32(RENDER + index * RENDER_STRIDE + 0x99, index)
    p.uc.mem_write(PICKUP, bytes(32))
    p.u32(PICKUP + 0x10, 1)
    chosen, divergent = [], 0
    while divergent < 60 or len(chosen) < 120:
        radius_a, radius_b = fp(rng.uniform(1, 40)), fp(rng.uniform(1, 40))
        total = radius_a + radius_b
        origin = [fp(rng.uniform(-5000, 5000)) for _ in range(3)]
        angle = rng.uniform(0, 2 * math.pi)
        distance = total * (1 + rng.uniform(-1e-6, 1e-6))
        dy = rng.choice([0, total * (1 + rng.uniform(-1e-6, 1e-6))]) * rng.choice([-1, 1])
        a = {"position": origin, "radius": radius_a}
        b = {"position": [fp(origin[0] + distance * math.cos(angle)), fp(origin[1] + dy),
                          fp(origin[2] + distance * math.sin(angle))], "radius": radius_b}
        differs = overlap_model(24, a, b) != overlap_model(53, a, b)
        if differs and divergent < 60:
            divergent += 1
            chosen.append((a, b))
        elif not differs and len(chosen) - divergent < 60:
            chosen.append((a, b))
    cases = []
    for a, b in chosen:
        for render, body in enumerate([a, b]):
            for axis, value in enumerate(body["position"]):
                p.f32(RENDER + render * RENDER_STRIDE + 0x50 + axis * 4, value)
            p.f32(SHAPES + render * 0xbc + 0x74, body["radius"])
        p.run(0x497bd0, [0, 1])
        planar = bool(p.uc.reg_read(UC_X86_REG_EAX))
        p.uc.reg_write(UC_X86_REG_ECX, PICKUP)
        p.run(0x44fc80, [4])
        cases.append({"a": a, "b": b, "planar": planar,
                      "expected": bool(p.uc.reg_read(UC_X86_REG_EAX) & 0xff)})
    return cases


def pickup_yaw(p, rng, config_speed):
    def yaw_model(precision, yaw, dt, speed):
        r = model(precision)
        return fp(r(r(speed * dt) + yaw))
    chosen, divergent = [], 0
    while divergent < 40 or len(chosen) < 80:
        speed = rng.choice([config_speed, 360, 1000, 2048, 4096])
        dt = fp(rng.choice([1 / 60, 1 / 144, 0.025, 1 / 31, rng.uniform(0.001, 0.1)]))
        yaw = fp(rng.uniform(0, 2e5))
        differs = yaw_model(24, yaw, dt, speed) != yaw_model(53, yaw, dt, speed)
        if differs and divergent < 40:
            divergent += 1
            chosen.append((yaw, dt, speed))
        elif not differs and len(chosen) - divergent < 40:
            chosen.append((yaw, dt, speed))
    cases = []
    for yaw, dt, speed in chosen:
        p.f32(YAW, yaw)
        p.f32(SCRATCH + 0x1000, dt)     # NativeProbe's 0x48f4e0 replacement
        p.u32(0x543d18, speed)          # 0x4504f0: MOV EAX,[0x543d18]
        p.uc.reg_write(UC_X86_REG_EBX, YAW)
        p.uc.reg_write(UC_X86_REG_ECX, 0x67ec70)
        p.uc.reg_write(UC_X86_REG_EDI, 0)
        p.uc.reg_write(UC_X86_REG_ESP, STACK + 0xf000)
        p.uc.emu_start(0x4540f7, 0x454117, count=100)
        cases.append({"yaw": yaw, "dt": dt, "speed": speed, "expected": p.float(YAW)})
    return cases


def main():
    p = NativeProbe(SOURCE)
    p.uc.mem_map(AUX, 0x300000)
    p.uc.mem_write(0x4afce0, b"\xc3")  # logging only
    p.u32(0x680b28, SECTORS)
    p.u32(0x68021c, SECTOR_MAP)
    sector_path = ROOT / "evidence/gameplay/native-track-fixtures.json"
    sector_fixture = json.loads(sector_path.read_text())
    if sector_fixture["sourceSha256"] != p.sha:
        raise ValueError("Sector fixture comes from a different rcskspel.dat")
    tracks = {i: json.loads((ROOT / f"public/assets/tracks/etappe{i}.json").read_text()) for i in range(6)}
    config = json.loads((ROOT / "public/assets/config.json").read_text())
    config_speed = int(config["game.ini"]["bonus_data"]["weapon_rotation_speed"])
    rng = random.Random(0x494b70)
    output = {
        "sourceSha256": p.sha, "fpuControlWord": f"0x{CONTROL_WORD:04x}", "precision": PRECISION,
        "sectorSource": sector_path.relative_to(ROOT).as_posix(),
        "scope": "Unicorn emulation of 494b70, 41c70a..41c73d, 41c70a..41c767, 40ea50, 40e79d..40e7b8, 48fda0, "
                 "493540 (direction 1), 497bd0/44fc80, 4540f7..454117 and 413330 (4977d0 returns its hint). Sector planes and "
                 "forward axes are float inputs from the 24-bit native sector fixture at both "
                 "precisions. Logging (4afce0) is stubbed and 48f4e0 is replaced by a plain dt load.",
        "routePlane": route_plane(p, tracks, sector_fixture, rng),
        "timers": timers(p, rng),
        "inertia": inertia(p),
        "headings": headings(p, sector_fixture),
        "overlaps": overlaps(p, rng),
        "pickupYaw": pickup_yaw(p, rng, config_speed),
        "suspensionClamp": suspension_clamp(p, tracks, sector_fixture),
        "bubbleSpring": bubble_spring(p, tracks, sector_fixture),
    }
    path = precision_path(ROOT / "evidence/gameplay/native-race-precision-fixtures.json")
    path.write_text(json.dumps(output, indent=2) + "\n")
    print(f"Wrote {path.name}: {len(output['routePlane'])} route-plane, {len(output['timers'])} timer, "
          f"{sum(len(t['yaws']) for t in output['headings'])} heading, {len(output['overlaps'])} overlap "
          f"{len(output['pickupYaw'])} pickup-yaw, {len(output['suspensionClamp'])} suspension-clamp and "
          f"{len(output['bubbleSpring'])} bubble-spring cases")


if __name__ == "__main__":
    main()
