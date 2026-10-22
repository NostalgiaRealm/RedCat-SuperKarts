#!/usr/bin/env python3
"""Execute original main FormShow and FIRSTTIME state handling.

INI access, Delphi string/path housekeeping, allocation and focus are explicit
boundaries. Original 474b00/45d4a0 instructions select the sample, read the
default, store the flag and write its next value. Original inputs stay read-only.
"""
import hashlib
import json
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH

probe = NativeProbe(SOURCE)
binary = SOURCE / 'rcskmenu.dat'
probe.uc.mem_write(0x400000, pefile.PE(str(binary)).get_memory_mapped_image())
probe.uc.mem_map(0, 0x1000)
form, ini, focus, focus_vmt, phase = [SCRATCH + x for x in [0x1000, 0x2000, 0x3000, 0x4000, 0x5000]]
probe.u32(form + 0x2d0, phase)
probe.u32(form + 0x2e0, focus)
probe.u32(focus, focus_vmt)
probe.u32(focus_vmt + 0xb0, SCRATCH + 0x6000)
probe.u32(ini, 0x44f450)
stored = None
events = []


def ret(value=None, stack_bytes=0):
    if value is not None:
        probe.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    sp = probe.uc.reg_read(UC_X86_REG_ESP)
    probe.uc.reg_write(UC_X86_REG_ESP, sp + 4 + stack_bytes)
    probe.uc.reg_write(UC_X86_REG_EIP, probe.integer(sp))


def string(address):
    return bytes(probe.uc.mem_read(address, 80)).split(b'\0', 1)[0].decode('ascii')


def hook(uc, address, size, unused):
    global stored
    if address in [0x403f84, 0x43285c, 0x4081c4, 0x402eac, 0x403b74, 0x403b50, SCRATCH + 0x6000]:
        ret()
    elif address == 0x403e90:
        ret(stack_bytes=12)
    elif address == 0x44f4ac:
        ret(ini)
    elif address == 0x44f4e8:
        default = probe.integer(uc.reg_read(UC_X86_REG_ESP) + 4)
        value = default if stored is None else stored
        events.append({'operation': 'read', 'section': string(uc.reg_read(UC_X86_REG_EDX)),
                       'key': string(uc.reg_read(UC_X86_REG_ECX)), 'default': default, 'value': value})
        ret(value, 4)
    elif address == 0x44f5ac:
        stored = probe.integer(uc.reg_read(UC_X86_REG_ESP) + 4)
        events.append({'operation': 'write', 'section': string(uc.reg_read(UC_X86_REG_EDX)),
                       'key': string(uc.reg_read(UC_X86_REG_ECX)), 'value': stored})
        ret(stack_bytes=4)
    elif address == 0x45c720:
        events.append({'operation': 'genericSound', 'sample': uc.reg_read(UC_X86_REG_EAX) & 255})
        ret()


probe.uc.hook_add(UC_HOOK_CODE, hook)
report = {'sourceSha256': hashlib.sha256(binary.read_bytes()).hexdigest(),
          'scope': __doc__, 'main': [], 'firstTime': [], 'settings': []}
for seed in [0, 1, 86399999, 0xffffffff]:
    for initial in [None, 0, 1, -1, 256]:
        stored = initial
        probe.uc.mem_write(phase, b'PHASE_MAIN\0')
        probe.u32(0x47d044, seed)
        for visit in range(3):
            events = []
            probe.uc.reg_write(UC_X86_REG_EAX, form)
            probe.run(0x474b00)
            report['main'].append({'seed': seed, 'initial': initial, 'visit': visit,
                                   'events': events, 'stored': stored,
                                   'firstTimeByte': probe.uc.mem_read(form + 0x2d5, 1)[0],
                                   'nextSeed': probe.integer(0x47d044)})
for name in ['PHASE_SELECTCHAR', 'PHASE_SELECTCOUNTRY', 'PHASE_ADVENT_MAIN']:
    for initial in [None, 0, 1]:
        stored = initial
        probe.uc.mem_write(phase, name.encode() + b'\0')
        for visit in range(2):
            events = []
            probe.uc.reg_write(UC_X86_REG_EAX, form)
            probe.uc.reg_write(UC_X86_REG_EDX, phase)
            probe.run(0x45d4a0)
            report['firstTime'].append({'phase': name, 'initial': initial, 'visit': visit,
                                        'events': events, 'stored': stored,
                                        'result': probe.uc.reg_read(UC_X86_REG_EAX) & 255})
for file in [SOURCE / 'ini/settings.ini',
             ROOT / 'public/assets/config.json',
             __import__('pathlib').Path('/home/rick/Games/UnpackedISO/RedCat Superkarts/RedCat Superkarts/data/ini/settings.ini')]:
    report['settings'].append({'file': str(file), 'sha256': hashlib.sha256(file.read_bytes()).hexdigest()})
(ROOT / 'evidence/native/menu-greeting-fixtures.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'main': len(report['main']), 'firstTime': len(report['firstTime']),
                  'allRngUnchanged': all(row['seed'] == row['nextSeed'] for row in report['main'])}))
