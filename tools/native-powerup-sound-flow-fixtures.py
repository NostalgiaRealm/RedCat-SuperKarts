#!/usr/bin/env python3
"""Replay complete native turbo Shoot audio dispatch, with visual/device stubs.

Original 451640 and 4537f0 execute, including the real character selectors,
chance gate, CRT RNG, speed multiplication and final inventory transition.
String storage, graphics, clock and sound-device submissions are boundaries.
"""
import json
import random
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP

p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
strings, commands = {}, []
allocation, level, owned_state = SCRATCH + 0x6000, 1, 2


def text(address):
    return bytes(p.uc.mem_read(address, 128)).split(b'\0')[0].decode('cp1252')


def string(address):
    pointer = p.integer(address + 4)
    return text(pointer) if pointer else strings.get(address, '')


def assign(address, value):
    p.uc.mem_write(address, b'\0' * 16)
    strings[address] = value


def ret(value=0, pop=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)


def hook(uc, address, size, data):
    global allocation, owned_state
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x4314a0:
        output = p.integer(sp + 4)
        assign(output, str(p.integer(sp + 8)))
        ret(output)
    elif address == 0x412710:
        output = p.integer(sp + 4)
        assign(output, text(p.integer(sp + 8)) + string(p.integer(sp + 12)))
        ret(output)
    elif address in [0x437b10, 0x437b40]:
        commands.append({'voiceId': p.integer(sp + 4), 'sample': string(p.integer(sp + 8)),
                         'replace': address == 0x437b40})
        ret(1, 8)
    elif address == 0x4371f0:
        ret(SCRATCH + 0x2000)
    elif address == 0x40b600:
        output, length = uc.reg_read(UC_X86_REG_ECX), p.integer(sp + 4)
        p.uc.mem_write(allocation, b'\x01' + b'\0' * (length + 1))
        p.u32(output + 4, allocation + 1)
        p.u32(output + 8, 0)
        p.u32(output + 12, length)
        strings.pop(output, None)
        allocation += (length + 33) & ~15
        ret(1, 8)
    elif address == 0x40b4f0:
        assign(uc.reg_read(UC_X86_REG_ECX), '')
        ret(0, 4)
    elif address in [0x4bc150, 0x4afce0, 0x430dd0]:
        ret()
    elif address == 0x452020:
        ret(OBJECT + 0x500, 4)
    elif address == 0x44fb40:
        ret(owned_state)
    elif address == 0x44fb50:
        ret(5)
    elif address == 0x44fbc0:
        ret(level)
    elif address == 0x453d70:
        ret([150, 200, 250][level - 1])
    elif address == 0x44fa70:
        owned_state = p.integer(sp + 4)
        ret(0, 4)
    elif address == SCRATCH + 0x3300:
        ret(12345)
    elif address == 0x48a480:
        ret(SCRATCH + 0x3400, 4)
    elif address == 0x48a890:
        ret()
    elif address == 0x48a570:
        ret(0, 32)
    elif address == 0x48a6d0:
        ret(0, 16)


p.uc.hook_add(UC_HOOK_CODE, hook)
p.uc.mem_write(SCRATCH + 0x3300, b'\xc3')
p.u32(0x4d215c, SCRATCH + 0x3300)
p.u32(0x508610, 1)
p.u32(0x53be28, 1)
p.u32(0x5081bc, 0)
p.u32(0x50820c, 1)
rng = random.Random(0x451640)
rows = []
for player in [False, True]:
    for level in range(1, 4):
        for case in range(30):
            seed, available = rng.randrange(2**32), case % 10
            p.u32(0x53bebc, available)
            p.u32(0x502978, seed)
            for body in range(2):
                p.f32(OBJECT + body * 0xd0 + 0xa4, 100)
            allocation, owned_state = SCRATCH + 0x6000, 2
            strings.clear()
            commands.clear()
            shooter = int(player)
            p.uc.reg_write(UC_X86_REG_ECX, OBJECT + 0x600)
            p.run(0x451640, [shooter])
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            rows.append({'player': player, 'level': level, 'seed': seed,
                         'roster': [1, available], 'shooter': shooter,
                         'expected': {'commands': list(commands),
                                      'randomState': p.integer(0x502978),
                                      'speed': p.float(OBJECT + shooter * 0xd0 + 0xa4),
                                      'ownedState': owned_state}})

result = {'sourceSha256': p.sha, 'scope': __doc__.strip(), 'rows': rows}
(ROOT / 'evidence/native/powerup-sound-flow-fixtures.json').write_text(json.dumps(result, indent=2) + '\n')
print('Wrote', len(rows), 'complete original turbo sound-flow cases')
