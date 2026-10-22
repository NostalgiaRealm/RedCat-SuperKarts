#!/usr/bin/env python3
"""Execute original render transform and CRT random routines in isolation."""
import json, random
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EAX, UC_X86_REG_FPCW

def generate():
    trig = json.loads((ROOT / 'evidence/native/integrator-fixtures.json').read_text())
    output = {'routines': ['0x4a09e0', '0x4be6bf', '0x4be6c9'], 'transforms': [], 'random': []}
    rng = random.Random(0x4a09e0)
    for bits, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        output['sourceSha256'] = p.sha
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        initialize_native_trig(p)
        for order in [0, 1, 2]:
            p.u32(0x4fc6e8, order)
            for case in range(80):
                angles = [rng.choice([0, -0.99, 1024, 2048, 4096.9, rng.uniform(-12000, 12000)]) for _ in range(3)]
                scale = [1, 1, 1] if case % 2 == 0 else [rng.uniform(-2, 3) for _ in range(3)]
                for base, values in [(0x74, angles), (0x80, scale)]:
                    for axis, value in enumerate(values):
                        p.f32(SCRATCH + 0x4000 + base + axis * 4, value)
                        values[axis] = p.float(SCRATCH + 0x4000 + base + axis * 4)
                p.uc.reg_write(UC_X86_REG_ECX, SCRATCH + 0x4000)
                p.run(0x4a09e0)
                matrix = [p.float(SCRATCH + 0x4010 + (row * 4 + col) * 4) for row in range(3) for col in range(3)]
                output['transforms'].append({'angles': angles, 'options': {'order': order, 'precision': bits, 'scale': scale}, 'expected': matrix})
    for seed in [0, 1, 1000, 0x7fffffff, 0xffffffff, 1700000000]:
        p.run(0x4be6bf, [seed])
        values = []
        for _ in range(64):
            p.run(0x4be6c9)
            values.append(p.uc.reg_read(UC_X86_REG_EAX))
        output['random'].append({'seed': seed, 'values': values, 'state': p.integer(0x502978)})
    (ROOT / 'evidence/native/transform-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', len(output['transforms']), 'native transforms and', len(output['random']) * 64, 'PRNG draws')

if __name__ == '__main__':
    generate()
