#!/usr/bin/env python3
"""Execute original player progress and trigger dispatch using engine sector history.

Only the logging and environment-check boundaries are hooked. The progress
instructions 4325b0..432688, 404eb0, 493a40 and 4938e0 run unchanged. Trigger
callbacks record their IDs; their effects are covered by the separate race tests.
"""
import json
import struct
from pathlib import Path
from unicorn import UC_HOOK_CODE
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, OBJECT, SCRATCH
from native_ai_fixture_track import install_track

ROOT = Path(__file__).resolve().parents[1]
p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
p.uc.mem_map(0x24000000, 0x400000)
p.uc.mem_write(0x48c030, b"\xc3")
p.uc.mem_write(0x4afce0, b"\xc3")
callbacks = {}
calls = []
for marker in range(1, 128):
    address = SCRATCH + 0x9000 + marker * 16
    callbacks[address] = marker
    p.uc.mem_write(address, b"\xc3")
    p.u32(0x67fe18 + marker * 4, address)
p.u32(0x67fe18, 0)


def on_instruction(uc, address, _size, _data):
    if address == 0x432688:
        uc.emu_stop()
    elif address in callbacks:
        calls.append(callbacks[address])


p.uc.hook_add(UC_HOOK_CODE, on_instruction)
cases = []
for track_id in range(6):
    track = json.loads((ROOT / f"public/assets/tracks/etappe{track_id}.json").read_text())
    count = len(track["route"])
    install_track(p, track)
    p.u32(0x680b2c, count)
    p.u32(0x680220, count)
    for i, route in enumerate(track["route"]):
        p.u32(0x24000000 + i * 0x984 + 0xec, route["trigger"])
        p.u32(0x24000000 + i * 0x984 + 0xf0, route["unknown"])
    for current in range(count):
        # Include both wrap directions, stationary rescue history, and distances
        # around the original integer half-track direction boundary.
        for offset in (0, 1, -1, 2, count // 2, count // 2 + 1):
            previous = (current - offset) % count
            p.u32(OBJECT + 0x1c, current)
            p.u32(OBJECT + 0x20, previous)
            p.u32(0x53be70, 100)
            p.run(0x4325b0, [0])
            distance = struct.unpack("<i", p.uc.mem_read(0x53be70, 4))[0] - 100
            calls.clear()
            p.run(0x4938e0, [0])
            cases.append({"track": track_id, "current": current, "previous": previous,
                          "cachedPrevious": (previous + count // 3) % count,
                          "distance": distance, "triggers": list(calls)})
output = ROOT / "evidence/gameplay/native-player-sectors.json"
output.write_text(json.dumps({
    "format": "native-player-sector-history-v1",
    "sourceSHA256": p.sha,
    "scope": "Original progress and callback dispatch; environment boundary and callback effects hooked.",
    "cases": cases,
}, separators=(",", ":")) + "\n")
print(f"{len(cases)} original player sector-history cases -> {output}")
