#!/usr/bin/env python3
"""Run original Euler instructions at equal elapsed time with different substeps.

120Hz is deliberately outside the native main-loop cap. It diagnoses the
kernel's cadence sensitivity and is not a permitted production race cadence.
"""
import json
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_FPCW

result = {
    'format': 'superkarts-native-cadence-quantization-v1',
    'routine': '0x4911a0',
    'scope': 'Original instructions, synthetic constant yaw rate, zero force and no contacts. Equal0.1s elapsed.120Hz is diagnostic only: native0x4432a0 caps the whole update loop at >=25ms.',
    'cases': [],
}
render_fields = [('x', 0x50), ('y', 0x54), ('z', 0x58), ('yaw', 0x78)]
body_fields = [('lateralSpeed', 0x9c), ('verticalSpeed', 0xa0),
               ('forwardSpeed', 0xa4), ('yawRate', 0xac),
               ('inverseMass', 0x90), ('inverseInertia', 0x94)]
for precision, control_word in [(24, 0x7f), (53, 0x27f)]:
    probe = NativeProbe(SOURCE)
    result['sourceSha256'] = probe.sha
    probe.uc.reg_write(UC_X86_REG_FPCW, control_word)
    initialize_native_trig(probe)
    for yaw_rate in [.25, .5, 1, 2]:
        for fps in [40, 120]:
            state = dict(x=0, y=0, z=0, yaw=0, lateralSpeed=0,
                         verticalSpeed=0, forwardSpeed=60, yawRate=yaw_rate,
                         inverseMass=1/600, inverseInertia=1/1157)
            for key, offset in render_fields:
                probe.f32(SCRATCH+0x4000+offset, state[key])
                state[key] = probe.float(SCRATCH+0x4000+offset)
            for key, offset in body_fields:
                probe.f32(OBJECT+offset, state[key])
                state[key] = probe.float(OBJECT+offset)
            for offset in [0xb4, 0xb8, 0xbc, 0xc0]:
                probe.f32(OBJECT+offset, 0)
            count, delta = int(fps/10)*8, 1/fps/8
            for _ in range(count):
                probe.uc.reg_write(UC_X86_REG_ECX, OBJECT)
                probe.run(0x4911a0, [float(delta), 1.0, 0, 0, SCRATCH+0x8000])
            expected = {key: probe.float(SCRATCH+0x4000+offset)
                        for key, offset in render_fields}
            expected.update({key: probe.float(OBJECT+offset)
                             for key, offset in body_fields[:4]})
            result['cases'].append(dict(precision=precision, fps=fps, state=state,
                                       substeps=count, deltaSeconds=delta,
                                       expected=expected))
path = ROOT/'evidence/native/cadence-quantization.json'
path.write_text(json.dumps(result, indent=2)+'\n')
print(f'Wrote {len(result["cases"])} original-instruction cases to {path}')
