#!/usr/bin/env python3
"""Original434f20 instructions, RNG and ftol; sound-card/tick boundaries stubbed."""
import json
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP

p = NativeProbe(SOURCE)
p.u32(0x4d215c, SCRATCH + 0x3000)
p.uc.mem_write(SCRATCH + 0x3000, b'\xa1' + struct.pack('<I', SCRATCH + 0x3010) + b'\xc3')
selected, sounds, enabled = None, [], True
for index in range(7):
    p.u32(0x53bac0 + index * 4, index)

def ret(value=0, pop=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)

def hook(uc, address, size, data):
    global selected
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x4371f0:
        ret(SCRATCH + 0x4000)
    elif address == 0x437550:
        ret(int(enabled))
    elif address == 0x49dd20:
        selected = p.integer(sp + 4)
        ret(SCRATCH + 0x5000, 4)
    elif address == 0x49d780:
        sounds.append({'index': selected, 'loop': bool(p.integer(sp + 4))})
        ret(1, 4)

p.uc.hook_add(UC_HOOK_CODE, hook)
rng, rows = random.Random(0x434f20), []
for index in range(840):
    enabled = index % 3 != 0
    seed = rng.randrange(2**32)
    last_time = [0, 10000, 0xffffff00][index % 3]
    elapsed = [0, 1, 100, 299, 300, 301, 1000][index % 7]
    now = (last_time + elapsed) & 0xffffffff
    impulse = [-100, 0, 17998.9, 17999.9, 18000, 24999.9, 25000, 90000][index % 8]
    contact_type = index % 2
    p.f32(0x6a5b80, impulse)
    p.u32(0x6a5b5c, contact_type)
    p.u32(0x53be20, last_time)
    p.u32(0x502978, seed)
    p.u32(SCRATCH + 0x3010, now)
    sounds.clear()
    p.run(0x434f20)
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    rows.append({'input': {'impulse': p.float(0x6a5b80), 'contactType': contact_type,
                           'lastTimeMs': last_time, 'nowMs': now, 'enabled': enabled, 'seed': seed},
                 'sounds': list(sounds), 'lastTimeMs': p.integer(0x53be20),
                 'nextState': p.integer(0x502978)})

(ROOT / 'evidence/native/crash-audio-fixtures.json').write_text(json.dumps({
    'sourceSha256': p.sha,
    'scope': 'Original434f20 control flow, CRT random and x87 truncation; clock and DirectSound are controlled boundaries.',
    'rows': rows,
}, indent=2) + '\n')
print('Wrote', len(rows), 'original crash sound cases')
