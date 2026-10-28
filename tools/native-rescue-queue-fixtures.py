#!/usr/bin/env python3
"""Execute the original rescue queue: enqueue, insert, update and retirement.

Unchanged rcskspel.dat code runs in Unicorn: queue singleton 0x48da90/0x48da40
(vtable 0x4d3000: size 0x48dde0, back 0x48de10), enqueue 0x48dce0 (the
environment caller 0x48c127 passes 1) and 0x48dc30 (AI recovery 0x40e50f) with
their ten-entry cap and duplicate scan, vector insert 0x48de90 at begin()
including reallocation, constructor 0x48c510/0x48c7e0, init 0x48c9a0, update
loop 0x48db00 with every per-entry 0x48ca60 (and its 0x48d610 ring update), and
retirement 0x48db30 with its stuck-flag clears at 0x48dba2.

Replaced leaves: CRT heap (operator new 0x4be7ee as a bump allocator over a
0xCD-filled heap, free 0x4bc150 as a no-op), texture lookup 0x4a6060 and the
Direct3D draw 0x48d460 (entry recorded). The relocation services validated by
rescue-fixtures/environment-rescue-fixtures are controlled: 0x493430, 0x48d930
(AL=1), 0x450690, 0x493540, 0x430ff0, 0x48bf80 (marker 0), and 0x48c170, which
returns the clearance scheduled per tick and player. Voice requests are skipped
by configuration (no human index at 0x53be28, NPC count 0x508610 = 0).
A tick is: scheduled enqueues, optional constructed state ("finish" pokes the
entry to grow frame 19 so 0x48ca60 itself finishes it), 0x48db00, 0x48db30.
Instruction emulation only; no Wine or rendered-race claim.
"""
import json
import multiprocessing
import struct

from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW

from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT, STACK
from native_probe_math import initialize_native_trig

STUBS, HEAP, HEAP_SIZE = 0x2f000000, 0x30000000, 0x1000000
HEAP_POINTER = STUBS + 0x100
CLEARANCE = SCRATCH + 0x7f00
RENDER = SCRATCH + 0x4000          # [0x6a5c38], stride 0xa9 (0x48c9b2..0x48c9f4)
ELEMENT = 0x11b0                   # 0x48de90 copies 0x46c dwords per element
QUEUE_GLOBAL = 0x67e4d0            # 0x48daa6
FLAGS, FLAG_STRIDE = 0x504000, 0x11c  # 0x48dd83 / 0x48dba2
PLAYERS = 12
DC30, DCE0 = "0x48dc30", "0x48dce0"
UNINITIALIZED = 0xcdcdcdcd
IDENTITY = struct.pack("<16f", *[float(i in (0, 5, 10, 15)) for i in range(16)])


def word(value):
    return struct.pack("<I", value & 0xffffffff)


class QueueProbe:
    def __init__(self, precision):
        p = self.p = NativeProbe(SOURCE)
        self.sha = p.sha
        uc = p.uc
        uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
        uc.mem_map(0, 0x1000)  # FS:[0] SEH chain used by 0x48da90/0x48ca60
        uc.mem_map(STUBS, 0x1000)
        uc.mem_map(HEAP, HEAP_SIZE)
        initialize_native_trig(p)
        p.run(0x48c370)  # static seven-vertex source read by 0x48c7e0
        # Bump allocator for operator new (cdecl size): eax=heap; heap=align16(heap+size).
        uc.mem_write(STUBS, b"\xa1" + word(HEAP_POINTER) + b"\x8b\x4c\x24\x04\x8d\x4c\x08\x0f"
                     b"\x83\xe1\xf0\x89\x0d" + word(HEAP_POINTER) + b"\xc3")
        uc.mem_write(0x4be7ee, b"\xe9" + struct.pack("<i", STUBS - (0x4be7ee + 5)))
        for address, code in {
            0x4bc150: b"\xc3",                       # free
            0x4a6060: b"\x31\xc0\xc2\x04\x00",       # texture lookup
            0x48d460: b"\xc3",                       # Direct3D draw
            0x493430: b"\x31\xc0\xc3", 0x48d930: b"\xb8\x01\0\0\0\xc2\x04\0",
            0x450690: b"\x31\xc0\xc3", 0x493540: b"\xc3",
            0x430ff0: b"\xd9\x05" + word(SCRATCH + 0x2200) + b"\xc3",
            0x48bf80: b"\x31\xc0\xc3",
            0x48c170: b"\xa1" + word(CLEARANCE) + b"\xc3",
        }.items():
            uc.mem_write(address, code)
        p.u32(0x53be28, 0xffffffff)
        p.u32(0x508610, 0)
        for address, value in [(0x53ba78, 1), (0x53ba60, 1), (0x53b9b0, 0)]:
            p.u32(address, value)  # effects on: 0x48d610 runs; 0x48d460 is the stubbed draw
        p.u32(0x680ae0, SCRATCH + 0x6000)
        for axis, value in enumerate([100, 200, 300]):
            p.f32(SCRATCH + 0x6008 + axis * 4, value)
        p.f32(SCRATCH + 0x2200, 25)
        p.f32(SCRATCH + 0x1000, .025)
        for player in range(PLAYERS):
            base = OBJECT + 0xd0 * player
            for offset, value in [(0xc, player), (0x10, player), (0x1c, 0), (0x24, 0)]:
                p.u32(base + offset, value)
        self.blocked, self.path, self.updates, self.clearance = set(), [], [], []
        self.renders, self.visits, self.inserts = [], [], []
        hooks = {
            0x48dcfe: lambda: self.path.append("belowCap"), 0x48dc4e: lambda: self.path.append("belowCap"),
            0x48dd3a: lambda: self.path.append("insert"), 0x48dc8a: lambda: self.path.append("insert"),
            0x48de90: self.on_insert, 0x48ca60: lambda: self.updates.append(self.player_at(self.ecx())),
            0x48c170: self.on_clearance, 0x48d460: lambda: self.renders.append(self.player_at(self.ecx())),
            0x48db82: self.on_visit, 0x48dbb2: self.on_back,
        }
        for address, callback in hooks.items():
            uc.hook_add(UC_HOOK_CODE, lambda _uc, _a, _s, _d, f=callback: f(), begin=address, end=address)

    # Native state helpers -------------------------------------------------
    def ecx(self):
        return self.p.uc.reg_read(UC_X86_REG_ECX)

    def eax(self):
        return self.p.uc.reg_read(UC_X86_REG_EAX)

    def arg(self, index):
        return self.p.integer(self.p.uc.reg_read(UC_X86_REG_ESP) + 4 + index * 4)

    def header(self):
        vector = self.p.integer(self.queue + 4)
        return [self.p.integer(vector + offset) for offset in (4, 8, 0xc)]

    def size(self):
        begin, end, _ = self.header()
        assert (end - begin) % ELEMENT == 0
        return (end - begin) // ELEMENT if begin else 0

    def player_at(self, address):
        player = self.p.integer(address + 0x1180)
        assert player != UNINITIALIZED and player < PLAYERS, f"uninitialized slot read at {address:#x}"
        return player

    def slot_of(self, address):
        begin = self.header()[0]
        assert (address - begin) % ELEMENT == 0
        return (address - begin) // ELEMENT

    def players(self, start=0, stop=None):
        begin = self.header()[0]
        stop = self.size() if stop is None else stop
        return [self.player_at(begin + i * ELEMENT) for i in range(start, stop)]

    def byte(self, address):
        return self.p.uc.mem_read(address, 1)[0]

    def flags(self):
        return [q for q in range(PLAYERS) if self.byte(FLAGS + FLAG_STRIDE * q)]

    # Hooks -----------------------------------------------------------------
    def on_insert(self):
        # thiscall vector(this=[queue+4]), args (position, count, value*).
        self.inserts.append({"position": self.arg(0), "count": self.arg(1), "begin": self.header()[0]})

    def on_clearance(self):
        player = self.arg(0)
        free = player not in self.blocked
        self.p.u32(CLEARANCE, int(free))
        self.clearance.append([player, free])

    def on_visit(self):
        element = self.eax()
        slot = self.slot_of(element)
        self.visits.append({"slot": slot, "player": self.player_at(element), "stale": slot >= self.size()})

    def on_back(self):
        back = self.eax()
        self.visits[-1].update(backSlot=self.slot_of(back), back=self.player_at(back))

    # Execution -------------------------------------------------------------
    def call(self, address, args=(), ecx=None, pops=0):
        uc = self.p.uc
        if ecx is not None:
            uc.reg_write(UC_X86_REG_ECX, ecx)
        sp = STACK + 0xf000
        uc.mem_write(sp, word(SCRATCH) + b"".join(word(value) for value in args))
        uc.reg_write(UC_X86_REG_ESP, sp)
        uc.emu_start(address, SCRATCH, count=50_000_000)
        assert uc.reg_read(UC_X86_REG_EIP) == SCRATCH, f"{address:#x} did not return"
        assert uc.reg_read(UC_X86_REG_ESP) == sp + 4 + pops, f"{address:#x} stack imbalance"
        return uc.reg_read(UC_X86_REG_EAX)

    def reset(self):
        used = self.p.integer(HEAP_POINTER) - HEAP if hasattr(self, "queue") else HEAP_SIZE
        self.p.uc.mem_write(HEAP, b"\xcd" * used)
        self.p.u32(HEAP_POINTER, HEAP)
        self.p.u32(QUEUE_GLOBAL, 0)
        self.queue = self.call(0x48da90)
        assert self.queue == self.p.integer(QUEUE_GLOBAL) and self.size() == 0
        for player in range(PLAYERS):
            self.p.uc.mem_write(FLAGS + FLAG_STRIDE * player, b"\0")
            for axis, value in enumerate([player * 100.0, 0.0, 0.0]):
                self.p.f32(RENDER + 0xa9 * player + 0x50 + axis * 4, value)

    def tick(self, index, spec):
        trace = {"tick": index, "enqueue": []}
        for player, entry in spec.get("enqueue", []):
            before = self.players()
            self.path, self.inserts = [], []
            if entry == DCE0:
                self.call(0x48dce0, [player, 1], ecx=self.queue, pops=8)
            else:
                self.call(0x48dc30, [player], ecx=self.queue, pops=4)
            result = "inserted" if "insert" in self.path else "duplicate" if "belowCap" in self.path else "full"
            if result == "inserted":
                # 0x48dd51/0x48dca1 pass begin() and count 1 to 0x48de90.
                assert len(self.inserts) == 1 and self.inserts[0]["count"] == 1
                assert self.inserts[0]["position"] == self.inserts[0]["begin"]
                assert self.players() == [player, *before]
            else:
                assert not self.inserts and self.players() == before
            trace["enqueue"].append({"player": player, "entry": entry,
                                     "environment": int(entry == DCE0), "result": result})
        begin = self.header()[0]
        slots = {player: i for i, player in enumerate(self.players())}
        for player in spec.get("finish", []):
            element = begin + slots[player] * ELEMENT
            self.p.u32(element + 0x1194, 19)
            self.p.uc.mem_write(element + 0x1198, b"\0")
        trace["queue"] = self.players()
        trace["capacity"] = (self.header()[2] - begin) // ELEMENT if begin else 0
        for player in range(PLAYERS):
            self.p.uc.mem_write(RENDER + 0xa9 * player + 0x10, IDENTITY)
        self.blocked = set(spec.get("blocked", []))
        self.updates, self.clearance = [], []
        self.call(0x48db00, ecx=self.queue)
        trace["updates"], trace["clearance"] = self.updates, self.clearance
        trace["state"] = []
        for i in range(self.size()):
            element = begin + i * ELEMENT
            trace["state"].append([self.player_at(element), self.p.integer(element + 0x1194),
                                   self.byte(element + 0x1198), self.byte(element + 0x11a0)])
        count = self.size()
        self.renders, self.visits = [], []
        self.call(0x48db30, ecx=self.queue)
        assert self.header()[0] == begin, "retirement must not reallocate"
        trace["renders"] = self.renders
        trace["visits"] = [[v["slot"], v["player"], v["stale"], v["back"]] for v in self.visits]
        trace["retired"] = [v["player"] for v in self.visits]
        trace["dropped"] = [v["back"] for v in self.visits if v["stale"] and v["back"] != v["player"]]
        trace["after"] = self.players()
        trace["stale"] = self.players(self.size(), count)
        trace["flags"] = self.flags()
        return trace

    def run(self, sequence):
        self.reset()
        return [self.tick(i, spec) for i, spec in enumerate(sequence["ticks"])]


def schedule(length, events):
    ticks = [{} for _ in range(length)]
    for index, spec in events.items():
        ticks[index] = spec
    return ticks


def sequences():
    d30, de0 = DC30, DCE0
    natural = [
        {"name": "cap-and-duplicates-same-tick", "ticks": schedule(82, {
            0: {"enqueue": [[0, d30], [1, d30], [2, d30], [3, d30], [4, d30], [0, d30], [5, de0], [6, de0],
                            [5, d30], [7, d30], [8, d30], [2, de0], [9, d30], [10, d30], [3, d30], [11, de0]]},
            40: {"enqueue": [[10, de0], [11, d30], [0, d30], [11, d30]]}})},
        {"name": "staggered-cap-and-reenqueue", "ticks": schedule(84, {
            **{k: {"enqueue": [[k, d30 if k % 2 == 0 else de0]]} for k in range(12)},
            6: {"enqueue": [[6, d30], [4, de0]]},
            40: {"enqueue": [[10, d30]]}, 41: {"enqueue": [[11, de0], [0, d30]]}, 42: {"enqueue": [[0, d30]]}})},
        {"name": "same-tick-groups-at-end", "ticks": schedule(46, {
            0: {"enqueue": [[0, d30], [1, d30]]}, 1: {"enqueue": [[2, de0]]},
            2: {"enqueue": [[3, d30], [4, de0], [5, d30]]}, 3: {"enqueue": [[6, d30]]},
            5: {"enqueue": [[7, de0], [8, d30]]}})},
        # Blocked environment returns (0x48cf58: shrink frame 19, two ticks per retry)
        # move finished entries off the end.
        {"name": "blocked-finished-front", "ticks": schedule(45, {
            0: {"enqueue": [[2, de0]]}, 1: {"enqueue": [[1, de0]]}, 2: {"enqueue": [[0, d30]]},
            20: {"blocked": [2]}, 21: {"blocked": [1]}, 22: {"blocked": [2]}})},
        {"name": "blocked-finished-middle", "ticks": schedule(43, {
            0: {"enqueue": [[2, de0]]}, 1: {"enqueue": [[1, d30]]}, 2: {"enqueue": [[0, d30]]},
            20: {"blocked": [2]}})},
        {"name": "blocked-front-and-end-drop-live", "ticks": schedule(45, {
            0: {"enqueue": [[2, de0]]}, 1: {"enqueue": [[1, de0]]}, 2: {"enqueue": [[0, d30]]},
            20: {"blocked": [2]}, 21: {"blocked": [1]}, 23: {"blocked": [1]}})},
        {"name": "blocked-repeated-mixed", "ticks": schedule(60, {
            0: {"enqueue": [[0, de0], [1, de0], [2, de0], [3, de0]]}, 1: {"enqueue": [[4, d30], [5, d30]]},
            3: {"enqueue": [[6, d30], [7, de0], [6, de0]]},
            20: {"blocked": [0, 2]}, 22: {"blocked": [2, 3]}, 23: {"blocked": [7]}, 24: {"blocked": [2]},
            25: {"blocked": [7]}, 26: {"blocked": [2]}})},
    ]
    matrix = []
    for count in range(1, 11):
        for mask in range(1, 1 << count):
            # Players 0..count-1 enqueued on one tick sit newest first: slot i holds count-1-i.
            finished = [count - 1 - slot for slot in range(count) if mask >> slot & 1]
            matrix.append({"name": f"retire-{count}-{mask:0{count}b}", "count": count,
                           "finishedSlots": [slot for slot in range(count) if mask >> slot & 1],
                           "ticks": [{"enqueue": [[player, DC30] for player in range(count)]}, {"finish": finished}]})
    return natural, matrix


def trace_all(precision):
    natural, matrix = sequences()
    probe = QueueProbe(precision)
    return probe.sha, [probe.run(sequence) for sequence in natural + matrix]


def generate():
    natural, matrix = sequences()
    # One emulator per x87 precision, created after the fork.
    with multiprocessing.get_context("fork").Pool(2) as pool:
        (sha, traces), (sha53, traces53) = pool.map(trace_all, [24, 53])
    assert sha == sha53 and traces == traces53, "queue traces differ between x87 precisions"
    for sequence, trace in zip(natural + matrix, traces):
        sequence["trace"] = trace
    drops = [s["name"] for s in natural + matrix if any(t["dropped"] for t in s["trace"])]
    output = {
        "format": "superkarts-native-rescue-queue-v1", "sourceSha256": sha,
        "precisions": [24, 53], "identicalAcrossPrecisions": True,
        "entrypoints": ["0x48da90", "0x48dce0", "0x48dc30", "0x48de90", "0x48db00", "0x48ca60", "0x48db30"],
        "method": __doc__.strip(), "deltaSeconds": .025,
        "summary": {"natural": len(natural), "retirementMatrix": len(matrix),
                    "ticks": sum(len(s["ticks"]) for s in natural + matrix),
                    "updates": sum(len(t["updates"]) for s in natural + matrix for t in s["trace"]),
                    "retirements": sum(len(t["retired"]) for s in natural + matrix for t in s["trace"]),
                    "staleVisits": sum(v[2] for s in natural + matrix for t in s["trace"] for v in t["visits"]),
                    "sequencesWithDrops": len(drops), "naturalDrops": [n for n in drops if not n.startswith("retire-")]},
        "natural": natural, "retirementMatrix": matrix,
    }
    target = ROOT / "evidence/native/rescue-queue-fixtures.json"
    lines = [json.dumps({k: v for k, v in output.items() if k not in ("natural", "retirementMatrix")}, indent=2)[:-2] + ","]
    for key in ("natural", "retirementMatrix"):
        lines.append(f'  "{key}": [')
        lines.append(",\n".join("    " + json.dumps(item, separators=(",", ":")) for item in output[key]))
        lines.append("  ]" + ("," if key == "natural" else ""))
    target.write_text("\n".join(lines) + "\n}\n")
    json.loads(target.read_text())
    print(json.dumps(output["summary"]))


if __name__ == "__main__":
    generate()
