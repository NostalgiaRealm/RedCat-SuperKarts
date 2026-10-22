#!/usr/bin/env python3
"""Execute native pickup names and firing preambles; CString/queue boundaries stubbed."""
import json
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP

p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
strings, commands, allocation = {}, [], SCRATCH + 0x6000
player, bonus_type, level = True, 1, 1

def cstring(address):
    return bytes(p.uc.mem_read(address, 128)).split(b'\0')[0].decode('cp1252')

def string(address):
    pointer = p.integer(address + 4)
    return cstring(pointer) if pointer else strings.get(address, '')

def output_string(address, value):
    p.uc.mem_write(address, b'\0' * 16)
    strings[address] = value

def ret(value=0, pop=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)

def hook(uc, address, size, data):
    global allocation
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x4314a0:
        output = p.integer(sp + 4)
        output_string(output, str(p.integer(sp + 8)))
        ret(output)
    elif address == 0x412710:
        output = p.integer(sp + 4)
        output_string(output, cstring(p.integer(sp + 8)) + string(p.integer(sp + 12)))
        ret(output)
    elif address == 0x412870:
        output = uc.reg_read(UC_X86_REG_ECX)
        output_string(output, string(p.integer(sp + 4)))
        ret(output, 12)
    elif address == 0x437b10:
        commands.append({'voiceId': p.integer(sp + 4),
                         'sample': string(p.integer(sp + 8)), 'replace': False})
        ret(1, 8)
    elif address == 0x4371f0:
        ret(SCRATCH + 0x2000)
    elif address == 0x40b600:
        this, length = uc.reg_read(UC_X86_REG_ECX), p.integer(sp + 4)
        p.uc.mem_write(allocation, b'\x01' + b'\0' * (length + 1))
        p.u32(this + 4, allocation + 1)
        p.u32(this + 8, 0)
        p.u32(this + 12, length)
        strings.pop(this, None)
        allocation += (length + 33) & ~15
        ret(1, 8)
    elif address in [0x4bc150, 0x4afce0]:
        ret()
    elif address == 0x417e90:
        ret(int(player))
    elif address == 0x44fb50:
        ret(bonus_type)
    elif address == 0x44fbc0:
        ret(level)
    elif address == 0x44fb40:
        ret(0)
    elif address in [0x430dd0, 0x4537f0, 0x452020]:
        ret()
    elif address == 0x44fa70:
        ret(0, 4)
    elif address == 0x456d10:
        # End after the complete455490 sound preamble, before projectile setup.
        uc.emu_stop()

p.uc.hook_add(UC_HOOK_CODE, hook)
rows = []
for bonus_type in [-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 100]:
    allocation = SCRATCH + 0x6000
    strings.clear()
    p.run(0x4542c0, [SCRATCH + 0x4000, bonus_type & 0xffffffff])
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    rows.append({'kind': 'pickup', 'type': bonus_type, 'sample': string(SCRATCH + 0x4000)})

for player in [False, True]:
    for bonus_type in range(1, 6):
        for level in range(1, 4):
            allocation = SCRATCH + 0x6000
            strings.clear()
            commands.clear()
            p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
            p.u32(OBJECT + 0x20, 0)
            p.run(0x451640 if bonus_type == 5 else 0x455490, [0])
            assert p.uc.reg_read(UC_X86_REG_EIP) == (SCRATCH if bonus_type == 5 else 0x456d10)
            rows.append({'kind': 'fire', 'type': bonus_type, 'level': level,
                         'player': player, 'commands': list(commands)})

(ROOT / 'evidence/native/bonus-audio-fixtures.json').write_text(json.dumps({
    'sourceSha256': p.sha,
    'scope': 'Original4542c0 mapping and455490/451640 firing sound branches. CString and queue boundaries stubbed; projectile setup excluded.',
    'rows': rows,
}, indent=2) + '\n')
print('Wrote', len(rows), 'original bonus sound cases')
