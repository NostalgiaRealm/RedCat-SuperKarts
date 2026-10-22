#!/usr/bin/env python3
"""Capture NPC animation requests from isolated original x86 instructions.

String allocation, actor lookup and unrelated movement are controlled boundaries.
No original file is modified; this is not whole-game runtime observation.
"""
import json
import struct
from pathlib import Path

from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT

ARENA = 0x22000000
ACTOR, VTABLE = SCRATCH + 0x5000, SCRATCH + 0x5100
TRANSITION, ENQUEUE = SCRATCH + 0x5200, SCRATCH + 0x5300


class AnimationProbe(NativeProbe):
    def __init__(self):
        super().__init__(SOURCE)
        self.uc.mem_map(0, 4096)
        self.uc.mem_map(ARENA, 0x100000)
        self.next_string = ARENA + 16
        self.requests = []
        self.stop_on_enqueue = False
        self.u32(ACTOR, VTABLE)
        self.u32(VTABLE, ENQUEUE)
        self.u32(VTABLE + 12, TRANSITION)
        self.uc.mem_write(TRANSITION, b"\xc2\x0c\x00")
        self.uc.mem_write(ENQUEUE, b"\xc2\x04\x00")
        self.uc.mem_write(0x44a700, b"\xb8" + struct.pack("<I", ACTOR) + b"\xc2\x04\x00")
        # MSVC string helpers: preserve caller-side copies and request branches.
        for address, code in {
            0x40b4f0: b"\xc2\x04\x00",
            0x40b600: b"\xb8\x01\x00\x00\x00\xc2\x08\x00",
            0x40b540: b"\xc2\x08\x00",
            0x40b5e0: b"\xc2\x04\x00",
            0x4bc150: b"\xc3",
        }.items():
            self.uc.mem_write(address, code)
        for address in [0x40f320, 0x40f350, 0x40f380, 0x48c030, 0x4024d0,
                        0x406940, 0x40ea50, 0x41b910, 0x4afce0]:
            self.uc.mem_write(address, b"\xc3")
        self.uc.mem_write(0x44a6c0, b"\xc2\x04\x00")
        for address in [0x4028c0, 0x417e90]:
            self.uc.mem_write(address, b"\x31\xc0\xc3")
        self.uc.mem_write(0x48f4d0, b"\xd9\x05" + struct.pack("<I", SCRATCH + 0x1000) + b"\xc3")
        self.u32(0x680ae0, SCRATCH + 0x6000)
        self.u32(OBJECT + 0x24, 0)
        self.uc.hook_add(UC_HOOK_CODE, self.capture)

    def capture(self, uc, address, size, _):
        if address not in [0x40b4f0, 0x40b600, 0x40b540, 0x40b5e0, TRANSITION, ENQUEUE]:
            return
        obj = uc.reg_read(UC_X86_REG_ECX)
        sp = uc.reg_read(UC_X86_REG_ESP)
        a = self.integer(sp + 4)
        if address == 0x40b4f0:
            for offset in [4, 8, 12]:
                self.u32(obj + offset, 0)
        elif address in [0x40b600, 0x40b540]:
            length = a if address == 0x40b600 else self.integer(sp + 8)
            ptr = self.next_string
            self.next_string += 256
            self.u32(obj + 4, ptr)
            self.u32(obj + 8, length)
            self.u32(obj + 12, length)
            uc.mem_write(ptr - 1, b"\0" * (length + 2))
            if address == 0x40b540:
                uc.mem_write(ptr, bytes(uc.mem_read(a, length)))
        elif address == 0x40b5e0:
            self.u32(obj + 8, a)
            uc.mem_write(self.integer(obj + 4) + a, b"\0")
        else:
            ptr = self.integer(a + 4)
            name = bytes(uc.mem_read(ptr, 64)).split(b"\0", 1)[0].decode("ascii").lower()
            request = {"name": name}
            if address == TRANSITION:
                request.update({"from": self.integer(sp + 8), "to": self.integer(sp + 12)})
            else:
                request["enqueue"] = True
            self.requests.append(request)
            if address == ENQUEUE and self.stop_on_enqueue:
                uc.emu_stop()

    def call(self, address, args=()):
        self.requests = []
        self.next_string = ARENA + 16
        self.run(address, [value & 0xffffffff for value in args])
        return self.requests.copy()


def main():
    p = AnimationProbe()
    steering, turbo, normal, events = [], [], [], []
    for callback in [0x40c0c0, 0x40c370]:
        for argument in [-2147483648, -1000, -999, -1, 0, 1, 999, 1000, 2147483647]:
            expected = p.call(callback, [0, argument])
            steering.append({"callback": f"{callback:08x}", "argument": argument, "expected": expected})
    for precision in [24, 53]:
        p.uc.reg_write(UC_X86_REG_FPCW, 0x007f if precision == 24 else 0x027f)
        for active in [False, True]:
            for start, now in [(0, 0), (0, 4.9999995), (0, 5), (0, 5.0000005),
                               (1000, 1004.9999), (1000, 1005), (1, 0)]:
                p.u32(0x503fe0, int(active))
                p.f32(0x503fe4, start)
                p.f32(SCRATCH + 0x1000, now)
                options = {"precision": precision, "turboActive": active,
                           "turboStartedSeconds": p.float(0x503fe4),
                           "nowSeconds": p.float(SCRATCH + 0x1000)}
                expected = p.call(0x40e760, [0])
                turbo.append({**options, "expected": expected, "activeAfter": bool(p.integer(0x503fe0))})
        for phase in [0, 1, 2, 3]:
            for rank in [0, 1, 4]:
                p.u32(0x503fe0, 0)
                p.u32(0x53b9c0, phase)
                p.u32(0x5081b8, rank)
                normal.append({"precision": precision, "racePhase": phase, "rank": rank,
                               "expected": p.call(0x40b0b0, [0])})
    for state in [0, 3, 9]:
        p.u32(0x503ef4, state)
        events.append({"callback": "0040dc10", "fsmState": state,
                       "expected": p.call(0x40dc10, [0])})
        p.stop_on_enqueue = True
        for callback in [0x40de60, 0x40d610]:
            events.append({"callback": f"{callback:08x}", "fsmState": state,
                           "expected": p.call(callback, [0])})
        p.stop_on_enqueue = False
    # Damage effects share unconditional animator-slot-zero HIT, irrespective
    # of the NPC state. Stop after submission, before unrelated effect physics.
    p.uc.mem_write(0x456aa0, b"\xd9\xee\xc3")  # controlled duration 0.0
    p.uc.mem_write(0x40c960, b"\xc3")
    p.uc.mem_write(0x40c9b0, b"\x31\xc0\xc3")
    p.uc.mem_write(0x4be6c9, b"\x31\xc0\xc3")
    p.stop_on_enqueue = True
    for callback in [0x411830, 0x411b40, 0x411e50, 0x412090]:
        events.append({"callback": f"{callback:08x}", "expected": p.call(callback, [0, OBJECT, 1])})
    p.stop_on_enqueue = False
    # Exercise the actual deque append and reset code with a preallocated
    # block. Allocation is the only substituted container boundary.
    p.uc.mem_write(0x4398f0, b"\xc3")
    queue_cases = []
    for existing in [[], [0], [0, 1], [1, 0]]:
        for added in [0, 1, 2]:
            block, sequences = SCRATCH + 0x8000, SCRATCH + 0x9000
            p.u32(ACTOR + 0x28, sequences)
            p.u32(ACTOR + 0x40, block)
            p.u32(ACTOR + 0x4c, block + 0x100)
            p.u32(ACTOR + 0x50, block + len(existing) * 4)
            p.u32(ACTOR + 0x60, len(existing))
            p.u32(ACTOR + 0x64, 1)
            for i, value in enumerate(existing):
                p.u32(block + i * 4, value)
            for i in range(3):
                p.u32(sequences + i * 0x60 + 0x10, 2 + i)
                p.u32(sequences + i * 0x60 + 0x14, 7 + i)
                p.u32(sequences + i * 0x60 + 0x18, 12345 + i)
            p.uc.reg_write(UC_X86_REG_ECX, ACTOR)
            p.run(0x44f390, [added])
            queue_cases.append({"existing": existing, "added": added,
                                "queue": [p.integer(block + i * 4) for i in range(len(existing) + 1)],
                                "sequences": [{"loops": p.integer(sequences + i * 0x60 + 0x10),
                                               "frame": p.integer(sequences + i * 0x60 + 0x14),
                                               "retained": p.integer(sequences + i * 0x60 + 0x18)}
                                              for i in range(3)]})
    output = {"format": "superkarts-native-npc-animation-v1", "sha256": p.sha,
              "method": "Unicorn executes original NPC request instructions. Actor/string allocation and unrelated motion are controlled; no full-race or Wine claim.",
              "steering": steering, "turbo": turbo, "normal": normal, "events": events,
              "queueAppend": queue_cases}
    target = ROOT / "evidence/native/npc-animation-fixtures.json"
    target.write_text(json.dumps(output, indent=2) + "\n")
    print(f"Wrote {sum(map(len, [steering, turbo, normal, events]))} NPC request and {len(queue_cases)} queue cases to {target}")


if __name__ == "__main__":
    main()
