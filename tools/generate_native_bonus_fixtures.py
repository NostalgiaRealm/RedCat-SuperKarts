#!/usr/bin/env python3
"""Original pickup/controller state, respawn, collision and turbo arithmetic."""
import json
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT, STACK
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP
from native_probe_math import initialize_native_trig

def word(value):
    return struct.pack("<I", value & 0xffffffff)

def fp(value):
    return struct.unpack("<f", struct.pack("<f", value))[0]

OWNED, PICKUP, CONTROLLER = SCRATCH + 0x5000, SCRATCH + 0x5100, SCRATCH + 0x5200
ENABLED = SCRATCH + 0x5300

def initialize(probe, address, data):
    probe.uc.mem_write(address, bytes(32))
    for offset, value in [(4, data["type"]), (8, data["state"]), (12, 0), (16, 0), (24, data["level"])]:
        probe.u32(address + offset, value)
    probe.f32(address + 28, data.get("ageSeconds", 0))

def read(probe, address):
    return {"type": probe.integer(address + 4), "state": probe.integer(address + 8),
            "level": probe.integer(address + 24), "ageSeconds": probe.float(address + 28)}

def main():
    probe = NativeProbe(SOURCE)
    probe.uc.mem_map(0, 0x1000)  # Original MSVC exception-chain stack storage.
    for address in [0x4afce0, 0x4106b0, 0x40d610, 0x4362f0, 0x4500e0, 0x4540c0, 0x430dd0]:
        probe.uc.mem_write(address, b"\xc3")
    probe.uc.mem_write(0x452020, b"\xb8" + word(OWNED) + b"\xc2\x04\x00")
    probe.uc.mem_write(0x454560, b"\xa1" + word(ENABLED) + b"\xc3")
    probe.u32(0x508610, 4)
    probe.u32(0x53be28, 0)
    probe.u32(0x543d14, 3)
    probe.u32(0x543d24, CONTROLLER)
    probe.f32(0x543d50, 5)
    rng = random.Random(0x4514e0)
    collections = []
    for index in range(420):
        pickup = {"type": index % 7 + 1, "state": 2, "level": 1, "ageSeconds": fp(rng.uniform(0, 10))}
        owned = {"type": rng.randint(1, 7), "state": rng.choice([1, 2]), "level": rng.randint(1, 3),
                 "ageSeconds": fp(rng.uniform(0, 10))}
        player = index % 3 != 0
        seed = rng.randrange(0xffffffff)
        stars = rng.randrange(20)
        initialize(probe, PICKUP, pickup)
        initialize(probe, OWNED, owned)
        probe.u32(0x543d20, 1 + int(owned["state"] == 2))
        probe.u32(0x502978, seed)
        probe.u32(CONTROLLER + 4, stars)
        probe.uc.reg_write(UC_X86_REG_ECX, CONTROLLER)
        probe.run(0x4514e0, [PICKUP, 4 if player else 0])
        collections.append({"pickup": pickup, "owned": owned, "player": player, "seed": seed, "stars": stars,
                            "expected": {"pickup": read(probe, PICKUP), "owned": read(probe, OWNED),
                                         "stars": probe.integer(CONTROLLER + 4), "randomState": probe.integer(0x502978)}})
    respawns = []
    for index in range(180):
        pickup = {"type": index % 7 + 1, "state": rng.choice([1, 2]), "level": 1,
                  "ageSeconds": fp(rng.choice([0, 4.9, 4.975, 5, 6]))}
        delta = fp(rng.choice([0.025, 0.03125, 0.1]))
        enabled, active = bool(index % 3), rng.choice([0, 20, 39, 40, 45])
        initialize(probe, PICKUP, pickup)
        probe.u32(0x543d20, active)
        probe.u32(ENABLED, int(enabled))
        probe.f32(SCRATCH + 0x1000, delta)
        probe.uc.reg_write(UC_X86_REG_ECX, PICKUP)
        probe.run(0x453fd0)
        respawns.append({"pickup": pickup, "delta": delta, "enabled": enabled, "activeCount": active,
                         "expected": read(probe, PICKUP)})
    turbo = []
    for level, factor in [(1, 150), (2, 160), (3, 170)]:
        probe.u32(0x4f1ca0 + level * 4, factor)
        for speed in [-20, -15, -1, 0, 0.1, 5, 10, 15, 20, 30, 40]:
            initialize(probe, OWNED, {"type": 5, "state": 2, "level": level})
            probe.f32(OBJECT + 0xa4, speed)
            sp = STACK + 0xf000
            probe.uc.mem_write(sp, word(SCRATCH) + word(4))
            probe.uc.reg_write(UC_X86_REG_ESP, sp)
            probe.uc.reg_write(UC_X86_REG_ECX, OWNED)
            # Run original function through the stored velocity, stop before UI.
            probe.uc.emu_start(0x4537f0, 0x453889, count=10000)
            turbo.append({"level": level, "speed": fp(speed), "expected": probe.float(OBJECT + 0xa4)})
    shapes = 0x25000000
    probe.uc.mem_map(shapes, 0x1000)
    probe.u32(0x6a5ee0, shapes)
    for index in [0, 1]:
        probe.u32(OBJECT + index * 0xd0 + 0xc, index)
        probe.u32(SCRATCH + 0x4000 + index * 0xa9, 1)
        probe.u32(SCRATCH + 0x4000 + index * 0xa9 + 0x99, index)
    probe.u32(PICKUP + 0x10, 1)
    overlaps = []
    for index in range(240):
        radius_a, radius_b = rng.choice([5, 10, 35.5]), rng.choice([2, 10, 17.7])
        origin = [fp(rng.uniform(-5000, 5000)) for _ in range(3)]
        distance = rng.choice([0, 0.5, 0.99999, 1, 1.00001, 1.5]) * (radius_a + radius_b)
        other = [fp(origin[0] + distance), fp(origin[1] + rng.choice([0, radius_a + radius_b, 100])), origin[2]]
        for body, position in enumerate([origin, other]):
            for axis, value in enumerate(position):
                probe.f32(SCRATCH + 0x4000 + body * 0xa9 + 0x50 + axis * 4, value)
        probe.f32(shapes + 0x74, radius_a)
        probe.f32(shapes + 0xbc + 0x74, radius_b)
        probe.uc.reg_write(UC_X86_REG_ECX, PICKUP)
        probe.run(0x44fc80, [4])
        overlaps.append({"a": {"position": origin, "radius": fp(radius_a)},
                         "b": {"position": other, "radius": fp(radius_b)},
                         "expected": bool(probe.uc.reg_read(UC_X86_REG_EAX) & 0xff)})
    modes = []
    for mode in range(6):
        probe.run(0x42a8f0 + mode * 0x30)
        address = 0x53a570 - mode * 0x20
        flags = list(probe.uc.mem_read(address + 0x14, 5))
        types = [type_id for type_id, flag in [(7, flags[0]), (1, flags[1]), (2, flags[1]),
                                                (3, flags[2]), (4, flags[2]), (5, flags[3]), (6, flags[4])] if flag]
        modes.append({"mode": mode, "enabledTypes": sorted(types)})
    cooldowns = []
    clock = SCRATCH + 0x6100
    player_data = SCRATCH + 0x6200
    probe.uc.mem_write(0x48f4d0, b"\xd9\x05" + word(clock) + b"\xc3")
    probe.uc.mem_write(0x435a30, b"\xb8" + word(player_data) + b"\xc3")
    for index in range(120):
        deadline = fp(rng.choice([0, 0.25, 1, 10, 1000, 10000]))
        now = fp(deadline + rng.choice([-0.001, 0, 0.001]))
        player = bool(index % 2)
        probe.f32(clock, now)
        probe.f32(player_data + 0x100, deadline)
        probe.f32(0x503ff0, deadline)
        probe.run(0x410650, [4 if player else 0])
        cooldowns.append({"now": now, "deadline": deadline, "player": player,
                          "expected": bool(probe.uc.reg_read(UC_X86_REG_EAX) & 0xff)})
    # Execute the real parameter constructor and loader. Only INI text access is
    # supplied from the extracted original config and all original setters run.
    bonus_config = json.loads((ROOT / "public/assets/config.json").read_text())["game.ini"]["bonus_data"]
    probe.run(0x455190)
    probe.uc.mem_write(0x4b1d60, b"\xc3")
    def ini_hook(uc, address, size, data):
        if address != 0x4b1ed0:
            return
        stack = uc.reg_read(UC_X86_REG_ESP)
        key_address = probe.integer(stack + 8)
        key = bytes(uc.mem_read(key_address, 128)).split(b"\0", 1)[0].decode("ascii").lower()
        uc.reg_write(UC_X86_REG_EAX, int(bonus_config[key]))
        uc.reg_write(UC_X86_REG_ESP, stack + 4)
        uc.reg_write(UC_X86_REG_EIP, probe.integer(stack))
    hook = probe.uc.hook_add(UC_HOOK_CODE, ini_hook)
    probe.uc.reg_write(UC_X86_REG_ECX, CONTROLLER)
    probe.run(0x451810, [0, 0, 0, 0])
    probe.uc.hook_del(hook)
    parameters = {}
    for type_id in range(1, 5):
        parameters[type_id] = []
        for level in range(1, 4):
            values = struct.unpack("<ffIifffi", probe.uc.mem_read(0x543d40 + type_id * 0x60 + level * 0x20, 32))
            parameters[type_id].append(dict(zip(
                ["duration", "lifetime", "homing", "lockRange", "speed", "firstSpeedFactor", "restoredSpeedFactor", "count"],
                [*values[:2], bool(values[2] & 255), *values[3:]])))
    initialize_native_trig(probe)
    owned_visuals = []
    probe.u32(OWNED + 12, 0)
    for index in range(120):
        angles = [fp(rng.uniform(-10000, 10000)) for _ in range(3)]
        delta = fp(rng.choice([0, 0.025, 0.03125, 0.1]))
        rotation = rng.choice([0, 3000, -1000, 125])
        for axis, value in enumerate(angles):
            probe.f32(SCRATCH + 0x4000 + 0x74 + axis * 4, value)
        probe.f32(SCRATCH + 0x1000, delta)
        probe.u32(0x543d18, rotation & 0xffffffff)
        probe.uc.reg_write(UC_X86_REG_ECX, OWNED)
        probe.run(0x453780)
        owned_visuals.append({"angles": angles, "delta": delta, "rotationSpeed": rotation,
                             "expected": [probe.float(SCRATCH + 0x4000 + 0x74 + axis * 4) for axis in range(3)]})
    result = {"sourceSha256": probe.sha, "fpuControlWord": "0x007f",
              "scope": "Original 4514e0, 453fd0, 44fc80/497bd0, 410650, mode constructors, config constructor/loader455190/451810 and 4537f0 through velocity store. HUD/audio/animation and INI reads are explicit boundaries. Shared CRT RNG and geometry getters run unmodified.",
              "collections": collections, "respawns": respawns, "turbo": turbo, "overlaps": overlaps,
              "modes": modes, "cooldowns": cooldowns, "parameters": parameters,
              "ownedVisuals": owned_visuals}
    path = ROOT / "evidence/gameplay/native-bonus-fixtures.json"
    path.write_text(json.dumps(result, indent=2) + "\n")
    print(f"Wrote {len(collections)} collection, {len(respawns)} respawn, {len(turbo)} turbo and {len(overlaps)} overlap cases")

if __name__ == "__main__":
    main()
