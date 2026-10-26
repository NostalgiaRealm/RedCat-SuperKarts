#!/usr/bin/env python3
"""Execute original menu entry focus and name-entry key-release handlers.

Only unchanged original menu instruction bytes run. Win32 widget operations,
FIRSTTIME/phase reads, speech and Delphi string services are explicit stubs.
This checks native dispatch, not an original Windows interaction session.
"""
import hashlib
import json
import struct
from pathlib import Path

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_EIP, UC_X86_REG_ESP

ROOT = Path(__file__).resolve().parents[1]
BINARY = Path('/home/rick/Games/UnpackedISO/RedCat Superkarts/RedCat Superkarts/data/Game/rcskmenu.dat')
pe = pefile.PE(str(BINARY))
uc = Uc(UC_ARCH_X86, UC_MODE_32)
uc.mem_map(0x400000, (pe.OPTIONAL_HEADER.SizeOfImage + 4095) & ~4095)
uc.mem_write(0x400000, pe.get_memory_mapped_image())
uc.mem_map(0, 0x1000)
uc.mem_map(0x20000000, 0x10000)
uc.mem_map(0x10000000, 0x10000)
STOP, FORM, APP, OPTIONS, VMT, KEY = [0x20000000 + v for v in [0, 0x1000, 0x2000, 0x2100, 0x2200, 0x2300]]
FOCUS, ENABLED, SET_ENABLED = [0x20008000 + v for v in [0, 0x10, 0x20]]
def put(address, value):
    uc.mem_write(address, struct.pack('<I', value & 0xffffffff))
def read(address):
    return struct.unpack('<I', uc.mem_read(address, 4))[0]
def ret(value=None):
    if value is not None:
        uc.reg_write(UC_X86_REG_EAX, value)
    sp = uc.reg_read(UC_X86_REG_ESP)
    uc.reg_write(UC_X86_REG_EIP, read(sp))
    uc.reg_write(UC_X86_REG_ESP, sp + 4)
put(read(0x47c670), APP)
put(APP + 0x7c, OPTIONS)
put(VMT + 0xb0, FOCUS)
put(VMT + 0x4c, ENABLED)
put(VMT + 0x5c, SET_ENABLED)
methods = json.loads((ROOT / 'evidence/native/metadata/menu-form-methods.json').read_text())
events, widgets = [], {}
first, phase, enabled, length = 0, 2, True, 0
def hook(machine, address, size, data):
    if address == 0x45d4a0:
        ret(first)
    elif address == 0x45bba8:
        ret(phase)
    elif address in [0x45c720, 0x4731c8, 0x403b50]:
        ret()
    elif address == FOCUS:
        events.append({'focus': widgets[uc.reg_read(UC_X86_REG_EAX)]})
        ret()
    elif address == ENABLED:
        ret(int(enabled))
    elif address == SET_ENABLED:
        events.append({'enabled': bool(uc.reg_read(UC_X86_REG_EDX) & 255)})
        ret()
    elif address == 0x43f64c:
        put(uc.reg_read(UC_X86_REG_EDX), 0)
        ret()
    elif address == 0x403dd0:
        ret(length)
    elif address == 0x42eb18:
        events.append({'close': uc.mem_read(FORM + 0x2d4, 1)[0]})
        ret()
uc.hook_add(UC_HOOK_CODE, hook)
def form_widgets(name):
    widgets.clear()
    uc.mem_write(FORM, bytes(0x800))
    for index, (field, offset) in enumerate(methods[name]['fields'].items()):
        address = 0x20003000 + index * 16
        widgets[address] = field
        put(FORM + int(offset, 16), address)
        put(address, VMT)
def run(address):
    put(0x1000f000, STOP)
    uc.reg_write(UC_X86_REG_ESP, 0x1000f000)
    uc.reg_write(UC_X86_REG_EAX, FORM)
    uc.reg_write(UC_X86_REG_EDX, 0)
    uc.reg_write(UC_X86_REG_ECX, KEY)
    uc.emu_start(address, STOP, count=10000)
    assert uc.reg_read(UC_X86_REG_EIP) == STOP, 'Native handler did not return'
report = {'source': str(BINARY), 'sourceSha256': hashlib.sha256(BINARY.read_bytes()).hexdigest(),
          'scope': __doc__, 'focus': [], 'nameEntry': []}
for name in ['TfrmMain', 'TfrmSelectChar', 'TfrmSelectCountry', 'TfrmAdventureMain',
             'TfrmAdventBrief', 'TfrmControlSettings', 'TfrmDebrief']:
    address = int(methods[name]['methods']['FormShow'], 16)
    for first in [0, 1]:
        for phase in [2, 3]:
            for enabled in [False, True]:
                form_widgets(name)
                events = []
                run(address)
                report['focus'].append({'form': name.upper(), 'address': hex(address),
                    'firstTime': first, 'phase': phase, 'okEnabled': enabled, 'events': events})
for length in [0, 1, 20]:
    for key in [13, 27, 32, 65, 112]:
        form_widgets('TfrmEditBox')
        uc.mem_write(KEY, struct.pack('<H', key))
        events = []
        run(0x470600)
        report['nameEntry'].append({'length': length, 'keyCode': key, 'events': events})
output = ROOT / 'evidence/full-source-audit/menu-entry-native.json'
output.parent.mkdir(parents=True, exist_ok=True)
output.write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'focus': len(report['focus']), 'nameEntry': len(report['nameEntry'])}))
