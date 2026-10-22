#!/usr/bin/env python3
"""Execute original outside-car selection and record traffic callback requests."""
import json, random
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP

def main():
    rng = random.Random(0x4107e0)
    p = NativeProbe(SOURCE)
    p.uc.mem_map(OBJECT + 0x1000, 0x10000)
    calls = []
    def hook(uc, address, size, data):
        if address == 0x4108f0:
            sp = uc.reg_read(UC_X86_REG_ESP)
            calls.append({'id': p.integer(sp + 4), 'sector': p.integer(sp + 8),
                          'forced': bool(p.integer(sp + 12))})
            uc.reg_write(UC_X86_REG_ESP, sp + 4)
            uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.hook_add(UC_HOOK_CODE, hook)
    out = {'sourceSha256': p.sha,
           'scope': 'Complete original4107e0 and497b30. Only selected legacy traffic relocation4108f0 is recorded as a boundary.',
           'cases': []}
    for case in range(720):
        count = [178, 187, 178, 187, 181, 181][case % 6]
        player = {'id': 0, 'sector': rng.randrange(count)}
        distance = rng.choice([1, 2, 10, 32, 50, count // 2, count])
        p.u32(0x680220, count); p.u32(0x53b9d0, distance)
        registry = []
        for index in range(250):
            car = {'id': index, 'sector': player['sector'] if index == 0 else rng.randrange(count),
                   'type': rng.choice([0, 1, 2, 3, 4, 5]), 'active': rng.choice([False, True])}
            if case % 5 == 0:
                car['type'] = 1 if index == 0 else 3
            p.u32(0x507388 + index * 12, int(car['active']))
            p.u32(0x50738c + index * 12, car['id'])
            p.u32(0x507390 + index * 12, car['type'])
            p.u32(OBJECT + index * 0xd0 + 0x1c, car['sector'])
            registry.append(car)
        calls = []; p.run(0x4107e0, [player['id']])
        out['cases'].append({'player': player, 'registry': registry,
                             'options': {'sectorCount': count, 'viewDistance': distance},
                             'expected': calls})
    (ROOT / 'evidence/native/ai-range-fixtures.json').write_text(json.dumps(out, separators=(',', ':')) + '\n')
    print('Wrote720 complete native outside-car checks, including144 race-only registries')

if __name__ == '__main__': main()
