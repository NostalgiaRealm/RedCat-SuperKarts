#!/usr/bin/env python3
"""Original player request, nearby-racer look and mesh-queue instructions."""
import importlib.util
import json
import random
import struct
from pathlib import Path
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import ROOT, SCRATCH, OBJECT

spec = importlib.util.spec_from_file_location("npc_animation", Path(__file__).with_name("native-npc-animation-fixtures.py"))
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
AnimationProbe = module.AnimationProbe
p = AnimationProbe()
rng = random.Random(0x4325b0)
render = SCRATCH + 0x4000

# GetTickCount, CString and animation admission are explicit boundaries.
p.uc.mem_write(SCRATCH + 0x300, b"\xa1" + struct.pack("<I", SCRATCH + 0x310) + b"\xc3")
p.u32(0x4d215c, SCRATCH + 0x300)
for address in [0x4902a0, 0x4343b0, 0x4320d0, 0x435320, 0x418c80,
                0x406be0, 0x4938e0, 0x41b790, 0x404f00, 0x41c0b0,
                0x435a30, 0x435c30, 0x433870, 0x433cf0, 0x4341d0,
                0x4273f0, 0x414160, 0x495fe0, 0x496290]:
    p.uc.mem_write(address, b"\xc3")
p.uc.mem_write(0x414e60, b"\x31\xc0\xc3")

stop_after_update = False
def hook(uc, address, size, data):
    if address == 0x44a6c0 and stop_after_update:
        uc.emu_stop()
p.uc.hook_add(UC_HOOK_CODE, hook)

out = {"sourceSHA256": p.sha,
       "scope": "Original x86 player request, nearby look, character event and mesh queue instructions. Motion/audio/render boundaries are stubbed; no full Windows runtime claim.",
       "requests": [], "looks": [], "events": [], "queues": []}

def bodies(player, opponents):
    p.u32(0x53be28, 0)
    p.u32(0x508610, len(opponents))
    for index, body in enumerate([player, *opponents]):
        p.u32(OBJECT + index * 0xd0 + 0xc, index)
        p.f32(render + index * 0xa9 + 0x78, body["yaw"])
        for axis, value in enumerate(body["position"]):
            p.f32(render + index * 0xa9 + 0x50 + axis * 4, value)
        if index:
            p.u32(0x503ef0 + (index - 1) * 0x11c, index)

# The nearby controller observes the OTHER racer's orientation, and chooses
# the first nearest racer within strict planar distance100.
for precision in [24, 53]:
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
    for index in range(200):
        player = {"position": [0, 10, 0], "yaw": 0}
        opponents = []
        for other in range(index % 6):
            x = rng.choice([0, .01, -.01, 10, -10, 99.999, 100, 101, rng.uniform(-100, 100)])
            z = rng.choice([0, -20, 20, rng.uniform(-100, 100)])
            opponents.append({"position": [x, rng.uniform(-500, 500), z],
                              "yaw": rng.choice([-4096, -400, 0, 400, 1024, 2048, 3072, 4096])})
        bodies(player, opponents)
        expected = p.call(0x435d50)
        out["looks"].append({"precision": precision, "player": player, "opponents": opponents, "expected": expected})

# Complete4325b0 request branches through their one animation-update point.
# Nearest look remains real and uses an empty opponent list here.
stop_after_update = True
for precision in [24, 53]:
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
    for index in range(240):
        bodies({"position": [0, 0, 0], "yaw": 0}, [])
        lateral = rng.choice([-10, -1.388889, -1.3888888, -1.1, 0, 1.1, 1.3888888, 1.388889, 10])
        speed = rng.choice([-10, -.001, 0, .001, 10])
        brake = rng.choice([-1, 0, 1, 100])
        handbrake = bool(index % 2)
        movement = index % 9 != 0
        recovering = index % 11 == 0
        phase, rank = index % 7, index % 5
        age = rng.choice([0, 1, 4999, 5000, 5001, 0xffffffff])
        p.f32(OBJECT + 0x9c, lateral)
        p.f32(OBJECT + 0xa4, speed)
        for address, value in [(0x508614, 4), (0x53be04, brake), (0x53bdf4, int(handbrake)),
                               (0x53be64, int(recovering)), (0x53be54, int(movement)),
                               (0x53b9e0, 1), (0x53a5d8, 4), (0x53ba34, 0),
                               (0x53b9c0, phase), (0x53be60, rank),
                               (SCRATCH + 0x310, age), (0x53a22c, 0)]:
            p.u32(address, value & 0xffffffff)
        options = {"precision": precision, "lateralSpeed": p.float(OBJECT + 0x9c),
                   "forwardSpeed": p.float(OBJECT + 0xa4), "brake": brake,
                   "handbrake": handbrake, "movementActive": movement,
                   "legacyAutopilotActive": recovering, "phase": phase, "rank": rank,
                   "turboAgeMs": age}
        try:
            expected = p.call(0x4325b0, [0])
        except Exception:
            print("Player failure", options, hex(p.uc.reg_read(UC_X86_REG_EIP)))
            raise
        out["requests"].append({**options, "expected": expected})
stop_after_update = False

# Player pickup CHEER has its own completed-flag guard.
for completed in [False, True]:
    p.u32(0x53be50, int(completed))
    out["events"].append({"callback": "004362f0", "completed": completed, "expected": p.call(0x4362f0)})

# The same four initializers submit HIT for NPC and player animator indices.
p.uc.mem_write(0x456aa0, b"\xd9\xee\xc3")
p.uc.mem_write(0x40c960, b"\xc3")
p.uc.mem_write(0x40c9b0, b"\x31\xc0\xc3")
p.uc.mem_write(0x4be6c9, b"\x31\xc0\xc3")
p.stop_on_enqueue = True
for racer in [0, 4]:
    for callback in [0x411830, 0x411b40, 0x411e50, 0x412090]:
        out["events"].append({"callback": f"{callback:08x}", "racer": racer,
                              "expected": p.call(callback, [racer, OBJECT, 1])})
p.stop_on_enqueue = False

# Real44f110 advances/pops/resets;44cac0's graphics boundary is intentionally
# not needed: displayed sequence is whatever head remains after44f110.
p.uc.mem_write(0x4bc150, b"\xc3")
actor, block, sequences = module.ACTOR, SCRATCH + 0x8000, SCRATCH + 0x9000
for queue in [[], [1], [0, 1], [2, 1], [0, 0], [1, 2, 0]]:
    for now in [0, 66, 67, 134, 1000]:
        p.uc.mem_write(actor, bytes(0x78))
        for offset, value in [(0x28, sequences), (0x38, block), (0x3c, block + 0x1000),
                              (0x40, block), (0x44, SCRATCH + 0x7000), (0x60, len(queue))]:
            p.u32(actor + offset, value)
        p.u32(SCRATCH + 0x7000, block)
        for i, value in enumerate(queue): p.u32(block + 4 * i, value)
        initial = []
        for i in range(3):
            seq = sequences + i * 0x60
            p.uc.mem_write(seq, bytes(0x60))
            frame, loops_done, last_time = (2, 0, 0) if i != 1 else (1, 2, 65)
            for offset, value in [(8, 15), (12, 1 if i != 1 else 5),
                                  (16, frame), (20, loops_done), (24, last_time), (28, 1),
                                  (0x54, seq + 0x200), (0x58, seq + 0x200 + 12)]:
                p.u32(seq + offset, value)
            initial.append({"frame": frame, "completedLoops": loops_done, "lastTime": last_time,
                            "forward": True, "loops": 1 if i != 1 else 5, "fps": 15, "count": 3})
        p.u32(SCRATCH + 0x310, now)
        p.uc.reg_write(UC_X86_REG_ECX, actor)
        p.run(0x44f110)
        count, head = p.integer(actor + 0x60), p.integer(actor + 0x40)
        out["queues"].append({"queue": queue, "now": now, "initial": initial,
            "expectedQueue": [p.integer(head + 4 * i) for i in range(count)],
            "expected": [{"frame": p.integer(sequences + i * 0x60 + 16),
                           "completedLoops": p.integer(sequences + i * 0x60 + 20),
                           "lastTime": p.integer(sequences + i * 0x60 + 24)}
                          for i in range(3)]})

target = ROOT / "evidence/native/player-animation-fixtures.json"
target.write_text(json.dumps(out, indent=2) + "\n")
print("Wrote", {name: len(out[name]) for name in ["requests", "looks", "events", "queues"]})
