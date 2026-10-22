#!/usr/bin/env python3
"""Execute original dynamic kart response 0x49b9c0, without modifying originals."""
import json
import random
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_FPCW

rng = random.Random(0x49b9c0)
out = {'routine': '0x49b9c0', 'method': 'Original x86 instruction emulation; no Wine race observation.',
       'cases': [], 'tolerance': {'absolute': 0.0001, 'relative': 0.000003}}
fields = {'lateralSpeed': 0x9c, 'verticalSpeed': 0xa0, 'forwardSpeed': 0xa4,
          'yawRate': 0xac, 'pitchRate': 0xa8, 'rollRate': 0xb0,
          'inverseMass': 0x90, 'inverseInertia': 0x94, 'restitution': 0x98}
for precision, cw in [(24, 0x7f), (53, 0x27f)]:
    probe = NativeProbe(SOURCE)
    probe.uc.reg_write(UC_X86_REG_FPCW, cw)
    initialize_native_trig(probe)
    out['sourceSha256'] = probe.sha
    for case in range(240):
        actors = []
        for index in range(2):
            actor = {
                'position': [rng.uniform(-400, 400), rng.uniform(-5, 5), rng.uniform(-400, 400)],
                'yaw': rng.uniform(-8192, 8192),
                'lateralSpeed': rng.uniform(-20, 20), 'verticalSpeed': rng.uniform(-5, 5),
                'forwardSpeed': rng.uniform(-30, 70), 'yawRate': rng.uniform(-4, 4),
                'pitchRate': rng.uniform(-1, 1), 'rollRate': rng.uniform(-1, 1),
                'inverseMass': rng.choice([0, 1/200, 1/600, 1/1000]),
                'inverseInertia': rng.choice([0, 1/500, 1/1000]),
                'restitution': rng.choice([0, .2, .5, 1]),
            }
            base = OBJECT + index * 0xd0
            render = SCRATCH + 0x4000 + index * 0xa9
            probe.u32(base + 0xc, index)
            for key, offset in fields.items():
                probe.f32(base + offset, actor[key])
                actor[key] = probe.float(base + offset)
            probe.f32(render + 0x78, actor['yaw'])
            actor['yaw'] = probe.float(render + 0x78)
            for axis, value in enumerate(actor['position']):
                probe.f32(render + 0x50 + axis * 4, value)
                actor['position'][axis] = probe.float(render + 0x50 + axis * 4)
            actors.append(actor)
        contact = {'point': [rng.uniform(-20, 20), 0, rng.uniform(-35, 35)],
                   'normal': rng.choice([[1, 0, 0], [-1, 0, 0], [0, 0, 1],
                                         [0, 0, -1], [.6, 0, .8], [-.6, 0, -.8]])}
        address = SCRATCH + 0x9000
        probe.u32(address + 8, 0)
        probe.u32(address + 0xc, 1)
        for key, offset in [('point', 0x10), ('normal', 0x1c)]:
            for axis, value in enumerate(contact[key]):
                probe.f32(address + offset + axis * 4, value)
                contact[key][axis] = probe.float(address + offset + axis * 4)
        probe.run(0x49b9c0, [address])
        expected = [{key: probe.float(OBJECT + index * 0xd0 + offset)
                     for key, offset in fields.items() if key not in ['inverseMass', 'inverseInertia', 'restitution']}
                    for index in range(2)]
        out['cases'].append({'precision': precision, 'actors': actors, 'contact': contact,
                             'expected': expected, 'impulse': probe.float(0x6a5b80)})
path = ROOT / 'evidence/native/kart-contact-fixtures.json'
path.write_text(json.dumps(out, indent=2) + '\n')
print('Wrote', len(out['cases']), 'original kart response cases')
