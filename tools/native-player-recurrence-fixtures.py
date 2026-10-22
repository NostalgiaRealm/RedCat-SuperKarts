#!/usr/bin/env python3
"""Original force/RPM + eight Euler calls, preserving storage between frames.

Collision and ground are intentionally outside this recurrence probe. The
already-verified outer-loop planar quantization is reproduced at its boundary.
Only emulator memory is modified; installed game inputs remain read-only.
"""
import json
import struct
from unicorn.x86_const import UC_X86_REG_ECX
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig

def fp(value):
    return struct.unpack("<f", struct.pack("<f", value))[0]

p = NativeProbe(SOURCE)
initialize_native_trig(p)
render = SCRATCH + 0x4000
out = {"sourceSha256": p.sha, "precision": 24, "routines": ["0x415990", "0x4911a0"],
       "scope": "Recurring original force/RPM and eight Euler calls. No world/contact callbacks. "
                "Caller supplies controls and reproduces verified outer planar quantization.",
       "traces": []}
for preset in range(3):
    for upgrade in range(2):
        p.set_physics(preset, 0)
        inverse_mass = fp(1 / 600)
        inverse_inertia = fp(1 / fp(fp(600 * fp(.083333336)) *
                                  fp(fp(fp(4.5) * fp(4.5)) + fp(fp(1.7) * fp(1.7)))))
        body = {"x": fp(100), "y": fp(0), "z": fp(-200), "yaw": fp(-71.75),
                "lateralSpeed": fp(.75), "verticalSpeed": 0, "forwardSpeed": fp(10),
                "yawRate": fp(.04), "inverseMass": inverse_mass, "inverseInertia": inverse_inertia,
                "mass": 1 / inverse_mass}
        for key, offset in [("x", 0x50), ("y", 0x54), ("z", 0x58), ("yaw", 0x78)]:
            p.f32(render + offset, body[key])
        for key, offset in [("lateralSpeed", 0x9c), ("verticalSpeed", 0xa0),
                            ("forwardSpeed", 0xa4), ("yawRate", 0xac),
                            ("inverseMass", 0x90), ("inverseInertia", 0x94)]:
            p.f32(OBJECT + offset, body[key])
        p.f32(render + 0x14, 0)
        p.f32(render + 0x34, 0)
        p.f32(0x507290, 800)
        p.u32(0x507298, 0)
        for address in [0x53bef0, 0x53bef4, 0x53bf00]:
            p.u32(address, upgrade)
        trace = {"preset": preset, "record": 0, "upgrade": upgrade, "body": body, "frames": []}
        for frame in range(400):
            dt = fp([.025, .03125, .1, 1 / 60][frame % 4])
            phase = 0 if frame < 380 else 3
            controls = {"throttle": fp(100 if frame < 120 or 260 <= frame < 320 else 0),
                        "brake": fp(100 if 120 <= frame < 260 else 0),
                        "steering": fp(45 if frame % 80 < 40 else -35),
                        "handbrake": frame >= 320}
            p.f32(SCRATCH + 0x1000, dt)
            p.u32(0x53b9c0, phase)
            p.u32(0x53bdf4, int(controls["handbrake"]))
            p.u32(0x53bdf8, 0)
            for offset in [0xb4, 0xb8, 0xbc, 0xc0]:
                p.f32(OBJECT + offset, 0)
            p.run(0x415990, [0, controls["throttle"], controls["brake"], controls["steering"]])
            force = {key: p.float(OBJECT + offset) for key, offset in [
                ("lateralForce", 0xb4), ("longitudinalForce", 0xbc), ("torque", 0xc0)]}
            for offset in [0x9c, 0xa4]:
                p.f32(OBJECT + offset, fp(int(fp(p.float(OBJECT + offset) * 10000)) * fp(.0001)))
            for _ in range(8):
                p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
                p.run(0x4911a0, [fp(dt * .125), 1.0, 0, 0, SCRATCH + 0x8000])
            expected = {key: p.float(render + offset) for key, offset in [
                ("x", 0x50), ("y", 0x54), ("z", 0x58), ("yaw", 0x78)]}
            expected.update({key: p.float(OBJECT + offset) for key, offset in [
                ("lateralSpeed", 0x9c), ("verticalSpeed", 0xa0), ("forwardSpeed", 0xa4), ("yawRate", 0xac)]})
            trace["frames"].append({"delta": dt, "phase": phase, "controls": controls,
                "force": force, "rpm": p.float(0x507290), "gear": p.integer(0x507298),
                "slipMagnitude": p.integer(0x50728c), "expected": expected})
        out["traces"].append(trace)
(ROOT / "evidence/gameplay/native-player-recurrence.json").write_text(json.dumps(out, indent=2) + "\n")
print("Wrote", sum(len(trace["frames"]) for trace in out["traces"]), "native recurring player frames")
