#!/usr/bin/env python3
"""Check the captured Italy return-point occupancy using original x86 code."""
import hashlib
import json
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT


def main():
    trace_path = ROOT / "evidence/race-completion/italy-all-rescue-trace.json"
    trace_bytes = trace_path.read_bytes()
    sample = json.loads(trace_bytes)["runs"][0]["samples"][-1]
    track = json.loads((ROOT / "public/assets/tracks/etappe5.json").read_text())
    target = track["drive"][514]["position"]
    report = {
        "format": "superkarts-captured-italy-rescue-v1",
        "scope": "Original 0x48c170 and 0x417e90 execute on captured actor positions. "
                 "Only the logging boundary is stubbed. Synthetic occupancy variations "
                 "are isolated probes, not altered race runs. This does not validate "
                 "the complete native trajectory or the cause of NPC recovery states.",
        "trace": str(trace_path.relative_to(ROOT)),
        "traceSha256": hashlib.sha256(trace_bytes).hexdigest(),
        "capturedTimeMs": sample["timeMs"],
        "waypoint": 514,
        "target": target,
        "cases": [],
    }
    for precision in [24, 53]:
        probe = NativeProbe(SOURCE)
        report["sourceSha256"] = probe.sha
        probe.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
        probe.uc.mem_map(0, 4096)
        probe.uc.mem_write(0x4afce0, b"\x31\xc0\xc3")  # logging only
        probe.u32(0x508610, 4)
        probe.u32(0x53be28, 4)
        for actor in range(5):
            probe.u32(OBJECT + actor * 0xd0 + 0xc, actor)
            if actor < 4:
                probe.u32(0x5081bc + actor * 0x70, actor)
        for variation in ["captured", "blocker-moved-away", "blocker-height-only"]:
            bodies = [{"id": body["id"], "position": list(body["position"])}
                      for body in sample["allBodies"]]
            if variation == "blocker-moved-away":
                bodies[0]["position"][0] += 10000
            if variation == "blocker-height-only":
                bodies[0]["position"][1] += 10000
            for body in bodies:
                for axis, value in enumerate(body["position"]):
                    probe.f32(SCRATCH + 0x4000 + body["id"] * 0xa9 + 0x50 + axis * 4, value)
            probe.run(0x48c170, [4, *target])
            free = bool(probe.uc.reg_read(UC_X86_REG_EAX) & 255)
            assert free == (variation == "blocker-moved-away"), (precision, variation, free)
            report["cases"].append({"precision": precision, "variation": variation,
                                    "bodies": bodies, "expectedFree": free})
    path = ROOT / "evidence/race-completion/italy-native-rescue.json"
    path.write_text(json.dumps(report, indent=2) + "\n")
    print(f"Verified {len(report['cases'])} original rescue-clearance cases: {path}")


if __name__ == "__main__":
    main()
