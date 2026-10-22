#!/usr/bin/env python3
"""Original group writes and437e30 gates across all shipped496 sound records."""
import json
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP

p = NativeProbe(SOURCE)
config = json.loads((ROOT / 'public/assets/config.json').read_text())
groups = {name.lower(): 1 << int(index) for index, name in config['sound.ini']['sndgroups'].items()
          if index.isdigit()}
types = []
for index in range(int(config['sound.ini']['sndtypes']['count'])):
    text = config['sound.ini']['sndtypes'][str(index)]
    p.uc.mem_write(SCRATCH + 0x4000, text.encode('cp1252') + b'\0')
    p.run(0x4b1f60, [SCRATCH + 0x4000, 0])
    assert p.integer(0x6ab460) == 7
    types.append([bytes(p.uc.mem_read(0x6a6510 + part * 200, 200)).split(b'\0')[0].decode('cp1252')
                  for part in range(7)])
source_base = 0x22000000
p.uc.mem_map(source_base, 0x10000)
p.u32(0x53bf80, len(types))
cleared = False

def cstring(address):
    return bytes(p.uc.mem_read(address, 64)).split(b'\0')[0].decode('cp1252')
def ret(value=0, pop=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)
def hook(uc, address, size, data):
    global cleared
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x49dd20:
        ret(source_base + p.integer(sp + 4) * 0x60, 4)
    elif address == 0x49e2f0:
        ret(groups[cstring(p.integer(sp + 4)).lower()], 4)
    elif address in [0x49d570, 0x49f250]:
        ret()
    elif address == 0x437be0:
        cleared = True
        ret()
p.uc.hook_add(UC_HOOK_CODE, hook)

def reset():
    for index, fields in enumerate(types):
        mask = sum(groups[name.strip().lower()] for name in fields[6].split('|'))
        p.u32(source_base + index * 0x60 + 8, mask)
        for offset in [0x10, 0x48]:
            p.u32(source_base + index * 0x60 + offset, int(fields[3]))

def group_write(mask, volume):
    p.uc.reg_write(UC_X86_REG_ECX, 0x53bf78)
    p.run(0x49e970, [mask, volume])
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH

def volumes():
    return [p.integer(source_base + index * 0x60 + 0x10) for index in range(len(types))]

rows = []
for enabled in [False, True]:
    for percent in [0, 1, 25, 50, 75, 100]:
        reset()
        settings = config['rcrsound.ini']['volumes']
        for index in range(int(settings['count'])):
            name = settings[str(index)].lower()
            group_write(groups[name], int(settings[name]))
        if enabled:
            p.uc.mem_write(OBJECT, b'\x01')
            p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
            p.run(0x437e30, [percent])
        rows.append({'effectsEnabled': enabled, 'effectsPercent': percent, 'volumes': volumes()})

gates = []
for enabled in [False, True]:
    for percent in [-100, -1, 0, 1, 25, 100, 101, 1000]:
        reset()
        cleared = False
        p.uc.mem_write(OBJECT, bytes([int(enabled)]))
        p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
        p.run(0x437e30, [percent & 0xffffffff])
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        gates.append({'enabled': enabled, 'requestedPercent': percent,
                      'expected': {'enabled': bool(p.uc.mem_read(OBJECT, 1)[0]),
                                   'clearQueues': cleared,
                                   'volumePercent': p.integer(source_base + next(
                                       i for i, t in enumerate(types) if t[6].strip() == 'GENERAL') * 0x60 + 0x10)}})

music = []
for percent in range(101):
    p.run(0x431610, [percent])
    result = p.uc.reg_read(UC_X86_REG_EAX)
    music.append({'percent': percent, 'hundredthDb': result - 0x100000000 if result & 0x80000000 else result})

(ROOT / 'evidence/native/audio-mixing-fixtures.json').write_text(json.dumps({
    'sourceSha256': p.sha, 'sourceNames': [fields[0].strip() for fields in types], 'parsedFields': types,
    'scope': 'Original49e970/49d4d0 source group writes,437e30 enable/clear logic and431610 music conversion. DirectSound update/assertions, group-name lookup and source-address access are boundary stubs.',
    'rows': rows, 'gates': gates, 'music': music,
}, indent=2) + '\n')
print('Wrote', len(rows) * len(types), 'native source-volume checks,', len(gates), 'controller gates and', len(music), 'music conversions')
