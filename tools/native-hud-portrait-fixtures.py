#!/usr/bin/env python3
"""Probe original Moving/Portrait controllers, retaining their arithmetic/state."""
import importlib.util
import json
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import ROOT, SCRATCH, OBJECT
import native_probe_math

spec = importlib.util.spec_from_file_location("npc_animation", ROOT / "tools/native-npc-animation-fixtures.py")
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
native_probe_math.TRIG = 0x23000000


def main():
    p = module.AnimationProbe()
    native_probe_math.initialize_native_trig(p)
    # Assertions only; actual position writes, movement and state remain native.
    p.uc.mem_write(0x469eb0, b"\xc3")
    p.uc.mem_write(0x464530, b"\xc3")
    for address, value in [(0x544b24, .4), (0x544b28, .32)]:
        p.f32(address, value)
    curves, moving, managers = [], [], []

    def vector(address, value=None):
        if value is not None:
            for i, component in enumerate(value):
                p.f32(address + i * 4, component)
        return [p.float(address + i * 4) for i in range(3)]

    def call(address, obj, args=()):
        p.next_string = module.ARENA + 16
        p.uc.reg_write(UC_X86_REG_ECX, obj)
        p.run(address, args)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH, hex(p.uc.reg_read(UC_X86_REG_EIP))

    def init_portrait(address, start, target, elapsed=0, duration=400, curved=1):
        p.uc.mem_write(address, b"\0" * 0x80)
        p.u32(address, 0x4d2d0c)
        p.u32(address + 8, 1)
        vector(address + 12, start)
        vector(address + 24, target)
        p.f32(address + 36, elapsed)
        p.f32(address + 40, duration)
        p.u32(address + 44, curved)
        p.u32(address + 60, 0xffffffff)
        for j in range(3):
            element = SCRATCH + 0xa000 + ((address - SCRATCH - 0x7000) // 0x100 * 3 + j) * 0x80
            p.u32(address + 48 + j * 4, element)
            vector(element + 4, start)

    def snapshot(address):
        return {"state": p.integer(address + 8), "start": vector(address + 12),
                "target": vector(address + 24), "elapsedMs": p.float(address + 36),
                "durationMs": p.float(address + 40), "curved": bool(p.integer(address + 44)),
                "rank": p.integer(address + 60) if p.integer(address + 60) != 0xffffffff else -1,
                "position": vector(p.integer(address + 48) + 4)}

    for precision in [24, 53]:
        p.uc.reg_write(UC_X86_REG_FPCW, 0x007f if precision == 24 else 0x027f)
        for curved in [False, True]:
            for start, target in [([0, 1, 0], [0, -.48, 0]), ([0, -.48, 0], [0, .84, 0]),
                                  ([.1, -.2, .3], [-.2, .7, -.4]), ([0, .8, 0], [0, .8, 0])]:
                for fraction in [0., .001, .125, .5, .875, .999, 1.]:
                    vector(SCRATCH + 0x1100, start)
                    vector(SCRATCH + 0x1120, target)
                    call(0x4676d0, 0, [SCRATCH + 0x1140, int(curved), SCRATCH + 0x1100, SCRATCH + 0x1120, fraction])
                    curves.append({"precision": precision, "curved": curved, "start": vector(SCRATCH + 0x1100),
                                   "target": vector(SCRATCH + 0x1120), "fraction": fraction,
                                   "expected": vector(SCRATCH + 0x1140)})
            for elapsed in [0, 25, 99, 100, 399, 400]:
                for delta in [0., .001, .025, .5]:
                    obj = SCRATCH + 0x7000
                    init_portrait(obj, [0, 1, 0], [0, -.48, 0], elapsed, 400 if curved else 100, int(curved))
                    p.f32(SCRATCH + 0x1000, delta)
                    before = snapshot(obj)
                    call(0x467000, obj)
                    moving.append({"precision": precision, "delta": p.float(SCRATCH + 0x1000),
                                   "before": before, "expected": snapshot(obj)})
        # Every possible player rank, with rank changes during movement and
        # just after a transition, exercises 400ms arcs/100ms corrections.
        for player in range(5):
            p.u32(0x508610, 4)
            p.u32(OBJECT + 0x84, player)
            for i in range(5):
                obj = SCRATCH + 0x7000 + i * 0x100
                init_portrait(obj, [0, 1, 0], [0, 1, 0])
                p.u32(obj + 8, 2)
                p.u32(OBJECT + 8 + i * 4, obj)
                p.u32(OBJECT + 0x1c + i * 4, SCRATCH + 0xb000 + i * 0x80)
                vector(SCRATCH + 0xb004 + i * 0x80, [-.890625, 0, 0])
            frames = []
            for tick in range(60):
                ranks = [0, 1, 2, 3, 4] if tick < 8 else [4, 2, 0, 1, 3] if tick < 24 else [1, 3, 2, 4, 0]
                for i, rank in enumerate(ranks):
                    p.u32(0x5081b8 + i * 0x70, rank)
                p.f32(SCRATCH + 0x1000, .025)
                call(0x46b5e0, OBJECT)
                frames.append({"ranks": ranks, "portraits": [snapshot(SCRATCH + 0x7000 + i * 0x100) for i in range(5)],
                               "labels": [vector(SCRATCH + 0xb004 + i * 0x80) for i in range(5)]})
            managers.append({"precision": precision, "playerIndex": player, "delta": p.float(SCRATCH + 0x1000), "frames": frames})
    target = ROOT / "evidence/native/hud-portrait-fixtures.json"
    target.write_text(json.dumps({"format": "superkarts-native-hud-portrait-v1", "sha256": p.sha,
                                 "method": "Original x86 4676d0,467000,46b5e0 with controlled clock and racer tables. Assertions/string allocation are bounded services; this is not full-game execution.",
                                 "curves": curves, "moving": moving, "managers": managers}, indent=2) + "\n")
    print(f"Wrote {len(curves)} curves, {len(moving)} updates, {sum(len(x['frames']) for x in managers)} manager frames")


if __name__ == "__main__":
    main()
