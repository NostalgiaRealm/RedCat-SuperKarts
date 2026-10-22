#!/usr/bin/env python3
"""Original42f9c0 Space branch; controlled keys, CString and sound boundaries."""
import json
import random
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP

p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
commands, allocation, pressed = [], SCRATCH + 0x6000, False
def cstring(address):
    return bytes(p.uc.mem_read(address, 128)).split(b'\0')[0].decode('cp1252')
def ret(value=0, pop=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)
def hook(uc, address, size, data):
    global allocation
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x42fd79:
        uc.emu_stop()
    elif address == 0x4b3830:
        ret(int(pressed and p.integer(sp + 4) == 32))
    elif address == 0x437b40:
        commands.append({'kind': 'voice', 'request': {'voiceId': p.integer(sp + 4),
                         'sample': cstring(p.integer(p.integer(sp + 8) + 4)), 'replace': True}})
        ret(1, 8)
    elif address == 0x4371f0:
        ret(SCRATCH + 0x2000)
    elif address == 0x40b600:
        this, length = uc.reg_read(UC_X86_REG_ECX), p.integer(sp + 4)
        p.uc.mem_write(allocation, b'\x01' + b'\0' * (length + 1))
        p.u32(this + 4, allocation + 1)
        p.u32(this + 8, 0)
        p.u32(this + 12, length)
        allocation += (length + 33) & ~15
        ret(1, 8)
    elif address == 0x4be8cb:
        output, limit, pattern, number = [p.integer(sp + offset) for offset in [4, 8, 12, 16]]
        value = (cstring(pattern) % number).encode()[:limit-1] + b'\0'
        uc.mem_write(output, value)
        ret(len(value) - 1)
    elif address == 0x43b600:
        commands.append({'kind': 'direct', 'event': cstring(p.integer(sp + 4))})
        ret()
    elif address in [0x4bc150, 0x4afce0]:
        ret()
p.uc.hook_add(UC_HOOK_CODE, hook)
p.u32(0x53ba6c, 0)
rng, rows = random.Random(0x42fc63), []
for index in range(240):
    roster = rng.sample(range(4, 10), 4) + [index % 4]
    pressed = index % 3 != 0
    sample_number, repetitions = [1, 4, 12][index % 3], index % 5 + 1
    p.u32(0x508610, 4)
    p.u32(0x53bebc, roster[-1])
    for racer, available in enumerate(roster[:-1]):
        p.u32(0x50820c + racer * 0x70, available)
    p.u32(0x4ead60, sample_number)
    p.u32(0x4ead64, repetitions)
    allocation = SCRATCH + 0x6000
    commands.clear()
    p.run(0x42f9c0)
    assert p.uc.reg_read(UC_X86_REG_EIP) == 0x42fd79
    rows.append({'input': {'racerCharacters': roster, 'sampleNumber': sample_number,
                           'repetitions': repetitions, 'pressed': pressed},
                 'commands': list(commands), 'sampleNumber': p.integer(0x4ead60),
                 'repetitions': p.integer(0x4ead64)})
(ROOT / 'evidence/native/key-audio-fixtures.json').write_text(json.dumps({
    'sourceSha256': p.sha, 'scope': 'Original42f9c0 through42fd79 including voice mapping and counters; keyboard, CString allocation/formatting and sound submission are boundaries.',
    'rows': rows,
}, indent=2) + '\n')
print('Wrote', len(rows), 'original Space audio branches')
