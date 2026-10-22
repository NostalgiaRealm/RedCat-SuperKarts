#!/usr/bin/env python3
"""Original instruction probes for the captured NPC vertical-speed overflow.

Never modifies the input PE. Terrain queries in the ground callback are
explicit flat-height boundaries; this is not a full native race replay.
"""
import hashlib
import json
import math
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig

AUX = 0x24000000
RENDER = SCRATCH + 0x4000
CAPTURE = ROOT / "evidence/full-race-matrix/timed-england-nonfinite-deep.json"
OUTPUT = ROOT / "evidence/native/ai-vertical-overflow.json"


def bits(value):
    return struct.pack("<f", value).hex()


def value(value):
    return value if math.isfinite(value) else str(value)


def read(p, address):
    x = p.float(address)
    return {"value": value(x), "bitsLE": bits(x)}


def setup(precision):
    p = NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
    initialize_native_trig(p)
    p.u32(0x508610, 3)
    p.u32(0x503ef0, 0)
    p.u32(0x5081bc, 0)
    p.u32(0x53be28, 9)
    p.u32(0x53b9f4, 2)
    p.f32(SCRATCH + 0x1000, .025)
    return p


def catchup(precision, history):
    p = setup(precision)
    cases = []
    for frame in history:
        body = frame["actors"][0]["body"]
        for name, offset in [("lateralSpeed", 0x9c), ("verticalSpeed", 0xa0), ("forwardSpeed", 0xa4)]:
            p.f32(OBJECT + offset, body[name])
        before = {name: read(p, OBJECT + offset) for name, offset in
                  [("lateralSpeed", 0x9c), ("verticalSpeed", 0xa0), ("forwardSpeed", 0xa4)]}
        # The captured state has specialTime1: the full catch-up region.
        p.run(0x406100, [0, (-30) & 0xffffffff])
        after = {name: read(p, OBJECT + offset) for name, offset in
                 [("lateralSpeed", 0x9c), ("verticalSpeed", 0xa0), ("forwardSpeed", 0xa4)]}
        cases.append({"now": frame["now"], "before": before, "after": after})
    p.f32(OBJECT + 0x9c, 0)
    p.f32(OBJECT + 0xa0, 1)
    p.f32(OBJECT + 0xa4, 40)
    recurrence = []
    for frame in range(1500):
        p.run(0x406100, [0, (-30) & 0xffffffff])
        recurrence.append(read(p, OBJECT + 0xa0))
        if not math.isfinite(p.float(OBJECT + 0xa0)):
            break
    return {"precision": precision, "cases": cases, "recurrence": recurrence,
            "overflowCall": len(recurrence), "sourceSha256": p.sha}


def normal(precision, body):
    p = setup(precision)
    p.uc.mem_write(0x5068d0, (SOURCE / "cars2.dat").read_bytes())
    p.u32(0x503f24, 1)
    p.u32(0x53be2c, 1)
    p.u32(0x503f38, 2)
    p.f32(0x503f2c, 100)
    p.f32(0x503f30, 0)
    p.u32(0x53bef4, 1)
    p.u32(0x50728c, 1)
    p.u32(0x507294, 1)
    p.u32(0x502978, 0)
    for name, offset in [("lateralSpeed", 0x9c), ("verticalSpeed", 0xa0), ("forwardSpeed", 0xa4),
                         ("pitchRate", 0xa8), ("yawRate", 0xac), ("rollRate", 0xb0)]:
        p.f32(OBJECT + offset, body[name])
    for axis, x in enumerate(body["position"]):
        p.f32(RENDER + 0x50 + axis * 4, x)
        p.f32(SCRATCH + 0x8000 + axis * 4, x + (100 if axis == 2 else 0))
    for name, offset in [("pitch", 0x74), ("yaw", 0x78), ("roll", 0x7c)]:
        p.f32(RENDER + offset, body[name])
    calls = []
    p.uc.hook_add(UC_HOOK_CODE, lambda uc, address, size, data: calls.append(hex(address)),
                  begin=0x413330, end=0x413330)
    before = read(p, OBJECT + 0xa0)
    p.run(0x401200, [0, SCRATCH + 0x8000])
    return {"precision": precision, "before": before, "after": read(p, OBJECT + 0xa0),
            "springCalls": calls}


def ground(precision, vertical):
    p = setup(precision)
    p.uc.mem_map(AUX, 0x10000)
    p.u32(0x508158, 3)
    p.u32(0x508184, 1)
    p.f32(0x53a4a8, 400)
    p.f32(0x53a4ac, 100)
    p.u32(0x507f48, 1)
    p.u32(OBJECT + 0x8c, 4)
    for i in range(4):
        p.u32(OBJECT + 0x64 + 4 * i, i + 1)
    p.u32(0x6a5f78, AUX + 0x8000)
    p.u32(AUX + 0x8004, AUX + 0x8100)
    p.u32(AUX + 0x8104, 0)
    p.u32(AUX + 0x8108, 1)
    p.u32(0x6a5f30, AUX + 0x8200)
    p.u32(AUX + 0x8200, 0)
    p.u32(AUX + 0x8210, 1)
    p.u32(0x6a5ee0, AUX + 0x8300)
    p.u32(0x680b28, AUX + 0x9000)
    for i in range(16):
        p.f32(0x6a5c90 + i * 4, int(i in [0, 5, 10, 15]))
    p.uc.mem_write(0x4977d0, b"\x31\xc0\xc2\x10\x00")
    p.uc.mem_write(0x495fe0, b"\xc2\x18\x00")
    p.uc.mem_write(0x496290, b"\xd9\x05" + struct.pack("<I", AUX + 0xa000) + b"\xc2\x14\x00")
    p.f32(AUX + 0xa000, 0)
    p.f32(AUX + 0x8300 + 0x14, -4)
    p.f32(AUX + 0x8300 + 0xbc + 0x14, -4)
    p.f32(0x507f70, .025)
    p.f32(OBJECT + 0xa0, vertical)
    p.f32(OBJECT + 0xa4, 40)
    # Body starts displaced above flat ground, cached wheels stay grounded.
    for axis, x in enumerate([100, 500, 200]):
        p.f32(RENDER + 0x50 + axis * 4, x)
    for row in range(3):
        for axis in range(3):
            p.f32(RENDER + 0x10 + row * 0x10 + axis * 4, int(row == axis))
    for i, local in enumerate([[-10, 4, 18], [10, 4, 18], [-10, 4, -18], [10, 4, -18]]):
        for axis in range(3):
            p.f32(RENDER + (i + 1) * 0xa9 + 0x50 + axis * 4, local[axis])
            p.f32(0x507f78 + i * 12 + axis * 4, local[axis] + [100, 0, 200][axis])
        for offset in [0x80, 0x84, 0x88]:
            p.f32(RENDER + (i + 1) * 0xa9 + offset, 1)
    before = read(p, OBJECT + 0xa0)
    p.run(0x416650, [0])
    return {"precision": precision, "before": before, "after": read(p, OBJECT + 0xa0),
            "renderYBefore": 500, "renderYAfter": p.float(RENDER + 0x54),
            "groundCount": p.integer(0x50815c),
            "wheelVerticalSpeeds": [p.float(RENDER + (i + 1) * 0xa9 + 0x60) for i in range(4)]}


def main():
    capture = json.loads(CAPTURE.read_text())
    history = capture["failure"]["history"]
    report = {"format": "rcsk-native-ai-vertical-overflow-v1",
              "capture": str(CAPTURE.relative_to(ROOT)),
              "captureSha256": hashlib.sha256(CAPTURE.read_bytes()).hexdigest(),
              "method": "Original PE instructions in Unicorn; explicit terrain boundary in416650; not a full native race replay.",
              "catchup": [catchup(p, history) for p in [24, 53]],
              "normal": [normal(p, history[-1]["actors"][0]["body"]) for p in [24, 53]],
              "ground": [ground(p, v) for p in [24, 53]
                         for v in [0, 1, 100, history[0]["actors"][0]["body"]["verticalSpeed"],
                                   history[-1]["actors"][0]["body"]["verticalSpeed"], float("inf")]]}
    active = report["catchup"][0]
    transitions = [{"from": a["now"], "to": b["now"],
                    "match": a["after"]["verticalSpeed"]["bitsLE"] == b["before"]["verticalSpeed"]["bitsLE"]}
                   for a, b in zip(active["cases"], active["cases"][1:])]
    report["capturedTransitionChecks"] = transitions
    report["summary"] = {"activeCapturedTransitions": len(transitions),
                         "activeTransitionMismatches": sum(not c["match"] for c in transitions),
                         "finalOriginalResult": active["cases"][-1]["after"]["verticalSpeed"],
                         "normalSpringCalls": sum(len(c["springCalls"]) for c in report["normal"]),
                         "groundPreservationFailures": sum(c["before"] != c["after"] for c in report["ground"])}
    OUTPUT.write_text(json.dumps(report, indent=2, allow_nan=False) + "\n")
    print(json.dumps(report["summary"], indent=2))
    if report["summary"]["activeTransitionMismatches"] or report["summary"]["normalSpringCalls"] or report["summary"]["groundPreservationFailures"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
