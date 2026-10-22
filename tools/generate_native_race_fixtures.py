#!/usr/bin/env python3
"""Original x86 race handlers with explicit timer/audio/UI boundary stubs."""
import json
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from unicorn.x86_const import UC_X86_REG_EAX

def word(value):
    return struct.pack("<I", value & 0xffffffff)

class RaceProbe(NativeProbe):
    def __init__(self):
        super().__init__(SOURCE)
        self.timers = SCRATCH + 0x3000
        self.mode = SCRATCH + 0x3100
        self.timer_reset = SCRATCH + 0x3104
        self.expired = SCRATCH + 0x3108
        self.notifications = SCRATCH + 0x310c
        self.sounds = SCRATCH + 0x3110
        self.uc.mem_write(0x42abc0, b"\xa1" + word(self.mode) + b"\xc3")
        self.uc.mem_write(0x42a4d0, b"\x8b\x44\x24\x04\x8b\x04\x85" + word(self.timers) + b"\xc3")
        self.uc.mem_write(0x42a5d0, b"\x8b\x44\x24\x04\x8b\x4c\x24\x08\x89\x0c\x85" + word(self.timers) + b"\xc3")
        self.uc.mem_write(0x42a210, b"\xff\x05" + word(self.timer_reset) + b"\xc3")
        self.uc.mem_write(0x42a280, b"\xc3")
        self.uc.mem_write(0x42a700, b"\xa1" + word(self.expired) + b"\xc3")
        self.uc.mem_write(0x42f740, b"\x8b\x44\x24\x04\xa3" + word(0x53b9c0) + b"\xc3")
        self.uc.mem_write(0x4356a0, b"\xa1" + word(self.timers + 12) + b"\xa3" + word(0x53be58) + b"\xc3")
        self.uc.mem_write(0x430610, b"\xff\x05" + word(self.notifications) + b"\xc3")
        self.uc.mem_write(0x43b600, b"\xff\x05" + word(self.sounds) + b"\xc3")
        self.uc.mem_write(0x4315a0, b"\xc3")
        self.u32(0x53be28, 0)
        self.u32(0x508610, 0)

    def set(self, address, value):
        self.uc.mem_write(address, word(value))

    def initialize(self, state):
        mapping = {
            "phase": 0x53b9c0, "finishArmed": 0x53d1d8, "lapCount": 0x53ba18,
            "lapLimit": 0x53ba1c, "sessionBestLapMs": 0x53be5c, "bestLapMs": 0x53ba0c,
            "bestRaceMs": 0x53ba10, "gateIndex": 0x53d204, "gateDistance": 0x53d208,
            "distance": 0x53be70, "finished": 0x53be50,
        }
        for name, address in mapping.items():
            self.set(address, int(state.get(name, 0)))
        self.set(0x53d32c, 0)  # Legacy split-time storage is outside these fixtures.
        self.set(self.mode, state.get("raceType", 0))
        self.set(OBJECT + 0x20, state.get("previous", 10))
        self.set(OBJECT + 0x1c, state.get("current", 11))
        self.set(OBJECT + 0x3c, 0)
        self.set(0x53be58, 0)
        self.set(0x53ba14, 0)
        self.set(self.timer_reset, 0)
        self.set(self.notifications, 0)
        self.set(self.sounds, 0)
        self.set(self.timers, state.get("lapTimeMs", 0))
        self.set(self.timers + 12, state.get("elapsedMs", 0))
        self.set(self.timers + 18 * 4, state.get("remainingMs", 0))
        self.set(self.expired, int(state.get("remainingMs", 0) == 0))
        self.set(0x53baa8, state.get("lastTickSecond", 0))
        times = state.get("gateTimes", [25000, 23000, 25000, 23000])
        self.set(0x53d338, len(times) - 1)
        for i, time in enumerate(times):
            self.set(0x53d2b0 + i * 4, time)

    def state(self):
        return {
            "phase": self.integer(0x53b9c0), "finishArmed": bool(self.integer(0x53d1d8)),
            "lapCount": self.integer(0x53ba18), "lastLapTimeMs": self.integer(0x53ba14),
            "sessionBestLapMs": self.integer(0x53be5c), "bestLapMs": self.integer(0x53ba0c),
            "bestRaceMs": self.integer(0x53ba10), "finished": bool(self.integer(0x53be50)),
            "raceTimeMs": self.integer(0x53be58), "timerResetCount": self.integer(self.timer_reset),
            "gateIndex": self.integer(0x53d204), "gateDistance": self.integer(0x53d208),
            "remainingMs": self.integer(self.timers + 18 * 4),
            "notifications": self.integer(self.notifications), "sounds": self.integer(self.sounds),
            "lastTickSecond": self.integer(0x53baa8),
        }

def generate():
    probe = RaceProbe()
    rng = random.Random(0x440dd0)
    finish_cases = []
    for i in range(240):
        state = {
            "phase": [0, 0, 0, 7, 8, 3, 6, 4][i % 8],
            "finishArmed": bool(i % 5), "lapCount": i % 5, "lapLimit": 5,
            "sessionBestLapMs": rng.choice([0, 20000, 30000]),
            "bestLapMs": rng.choice([0xfffffff, 20000, 30000]),
            "bestRaceMs": rng.choice([0xfffffff, 100000]),
            "lapTimeMs": rng.choice([0, 10000, 20000, 30000, 40000]),
            "elapsedMs": rng.randrange(100000, 200000),
            "previous": 11 if i % 3 == 0 else 10, "current": 10 if i % 3 == 0 else 11,
        }
        probe.initialize(state)
        probe.run(0x440dd0, [0])
        finish_cases.append({"input": state, "expected": probe.state()})
    gate_cases = []
    for i in range(240):
        state = {
            "raceType": 0 if i % 7 == 0 else 1, "phase": [0, 3, 6, 7, 8][i % 5],
            "gateIndex": i % 4, "gateDistance": rng.choice([0, 10, 20, 40]),
            "distance": rng.choice([0, 10, 20, 40]), "remainingMs": rng.choice([0, 1000, 13000, 25000]),
            "gateTimes": [16000, 13000, 15000, 13000], "player": bool(i % 6),
        }
        probe.initialize(state)
        probe.run(0x441e70, [0 if state["player"] else 1])
        gate_cases.append({"input": state, "expected": probe.state()})
    expiry_cases = []
    for i in range(120):
        state = {"raceType": 0 if i % 7 == 0 else 1, "phase": [0, 0, 3, 6][i % 4],
                 "remainingMs": rng.choice([0, 1, 999, 1000, 1999, 4999, 5000, 5999, 6000, 13000]),
                 "lastTickSecond": i % 7}
        probe.initialize(state)
        probe.run(0x42f170)
        expiry_cases.append({"input": state, "expected": probe.state()})
    # Record dispatcher calls for actual source sector triggers, preserving both slots.
    track_memory = 0x22000000
    probe.uc.mem_map(track_memory, 0x200000)
    probe.set(0x680b28, track_memory)
    probe.set(0x68021c, SCRATCH + 0x4000)
    callback_count, callback_ids = SCRATCH + 0x5000, SCRATCH + 0x5010
    for trigger in range(100):
        callback = SCRATCH + 0x8000 + trigger * 32
        probe.set(0x67fe18 + trigger * 4, callback if trigger else 0)
        probe.uc.mem_write(callback, b"\x8b\x0d" + word(callback_count)
                           + b"\xc7\x04\x8d" + word(callback_ids) + word(trigger)
                           + b"\xff\x05" + word(callback_count) + b"\xc3")
    crossings = []
    for track_id in range(6):
        track = json.loads((ROOT / f"public/assets/tracks/etappe{track_id}.json").read_text())
        count = len(track["route"])
        probe.set(0x680b2c, count)
        probe.set(0x680220, count)
        for sector, route in enumerate(track["route"]):
            probe.set(SCRATCH + 0x4000 + sector * 4, sector)
            probe.set(track_memory + sector * 0x984 + 0xec, route["trigger"])
            probe.set(track_memory + sector * 0x984 + 0xf0, route["unknown"])
        pairs = [(0, count - 1), (count - 1, 0), (0, 0), (0, count // 2), (count // 2, 0)]
        pairs += [(i - 1, i) for i in range(1, count)]
        pairs += [(rng.randrange(count), rng.randrange(count)) for _ in range(30)]
        for previous, current in pairs:
            probe.set(OBJECT + 0x20, previous)
            probe.set(OBJECT + 0x1c, current)
            probe.set(callback_count, 0)
            probe.run(0x4938e0, [0])
            triggers = [probe.integer(callback_ids + i * 4) for i in range(probe.integer(callback_count))]
            probe.run(0x404eb0, [current, previous])
            forward = probe.uc.reg_read(UC_X86_REG_EAX)
            probe.run(0x493a40, [current, previous])
            distance = probe.uc.reg_read(UC_X86_REG_EAX) * (1 if forward else -1)
            crossings.append({"track": track_id, "previous": previous, "current": current,
                              "triggers": triggers, "distance": distance})
    result = {
        "format": "superkarts-native-race-fixtures-v1", "sha256": probe.sha,
        "method": "Original x86 handlers in Unicorn. Timers, sound, logging, notifications, and phase UI are boundary stubs. Dispatcher callback table records both source trigger slots.",
        "entrypoints": ["0x440dd0", "0x440c30", "0x440d70", "0x441e70", "0x42f170", "0x4938e0", "0x404eb0", "0x493a40"],
        "finishCases": finish_cases, "gateCases": gate_cases, "expiryCases": expiry_cases, "crossings": crossings,
    }
    output = ROOT / "evidence/gameplay/native-race-fixtures.json"
    output.write_text(json.dumps(result, indent=2) + "\n")
    print(f"Wrote {len(finish_cases)} finish, {len(gate_cases)} gate, {len(expiry_cases)} expiry, and {len(crossings)} crossing cases")

if __name__ == "__main__":
    generate()
