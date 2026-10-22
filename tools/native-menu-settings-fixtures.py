#!/usr/bin/env python3
"""Execute original options transactions and keyboard capture state.

Delphi UI/string services, INI persistence and sound playback are explicit
boundaries. Native state changes, duplicate detection, key classification,
default bindings and option commits execute original instructions.
"""
import hashlib
import json
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH

p = NativeProbe(SOURCE)
binary = SOURCE / 'rcskmenu.dat'
p.uc.mem_write(0x400000, pefile.PE(str(binary)).get_memory_mapped_image())
p.uc.mem_map(0, 0x1000)
app, form, options, keys, widget, vmt, key_pointer, picture = [SCRATCH + i * 0x1000 for i in range(1, 9)]
enabled_stub, checked_stub = SCRATCH + 0x9000, SCRATCH + 0x9010
p.u32(p.integer(0x47c670), app)
p.u32(app + 0x7c, options)
p.u32(app + 0x88, keys)
p.u32(widget, vmt)
p.u32(vmt + 0x5c, enabled_stub)
p.u32(vmt + 0xb4, checked_stub)
p.u32(widget + 0x12c, picture)
for offset in [0x2dc, 0x358, 0x2f0, 0x2f8]:
    p.u32(form + offset, widget)
saved = [38, 40, 37, 39, 17, 18]
events, image_mode = [], False
checked, enabled = 1, True


def ret(value=None):
    if value is not None:
        p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))


def get_keys():
    return [p.integer(keys + 4 + i * 4) for i in range(6)]


def put_keys(values):
    for i, value in enumerate(values):
        p.u32(keys + 4 + i * 4, value)


def hook(uc, address, size, unused):
    global saved, enabled
    if address == 0x45c720:
        events.append(['sound', uc.reg_read(UC_X86_REG_EAX) & 255])
        ret()
    elif address == enabled_stub:
        enabled = bool(uc.reg_read(UC_X86_REG_EDX) & 255)
        events.append(['enabled', enabled])
        ret()
    elif address == checked_stub:
        ret(checked)
    elif address in [0x403b74, 0x403b50, 0x461d74, 0x43fb28]:
        ret()
    elif address == 0x461b44 and not image_mode:
        events.append(['keyImage', uc.reg_read(UC_X86_REG_EDX) & 255,
                       bool(uc.reg_read(UC_X86_REG_ECX) & 255)])
        ret()
    elif address in [0x45c4c8, 0x45c4f0]:
        ret()
    elif address in [0x460df0, 0x460d08]:
        events.append(['duplicateWarning'])
        ret()
    elif address == 0x458d6c:
        put_keys(saved)
        events.append(['loadSaved'])
        ret()
    elif address == 0x458c44:
        saved = get_keys()
        events.append(['save', saved])
        ret()
    elif address == 0x42eb18:
        events.append(['close', p.uc.mem_read(form + 0x2d4, 1)[0]])
        ret()
    elif image_mode and address == 0x461ea8:
        ret(widget)
    elif image_mode and address == 0x403be8:
        p.u32(uc.reg_read(UC_X86_REG_EAX), uc.reg_read(UC_X86_REG_EDX))
        ret()
    elif image_mode and address == 0x452c0c:
        pointer = uc.reg_read(UC_X86_REG_EDX)
        value = bytes(uc.mem_read(pointer, 80)).split(b'\0', 1)[0].decode('ascii')
        events.append(['image', value])
        ret()
    elif address in [0x4581c8, 0x46fa7c, 0x4786ec, 0x45c7c0]:
        ret(0)
    elif address == 0x46222c:
        events.append(['startInfo'])
        ret()


p.uc.hook_add(UC_HOOK_CODE, hook)


def run(address, edx=0, ecx=0):
    p.uc.reg_write(UC_X86_REG_EAX, form)
    p.uc.reg_write(UC_X86_REG_EDX, edx)
    p.uc.reg_write(UC_X86_REG_ECX, ecx)
    p.run(address)


def capture_state():
    return {'keys': get_keys(), 'capture': bool(p.uc.mem_read(form + 0x34e, 1)[0]),
            'selected': p.uc.mem_read(form + 0x34c, 1)[0], 'enabled': enabled,
            'events': list(events)}


report = {'sourceSha256': hashlib.sha256(binary.read_bytes()).hexdigest(),
          'scope': __doc__, 'capture': [], 'transactions': [], 'images': [], 'options': []}
for action in range(6):
    for key in [13, 16, 17, 18, 27, 32, 37, 38, 39, 40, 48, 65, 81, 90, 112]:
        put_keys([38, 40, 37, 39, 17, 18])
        p.uc.mem_write(form + 0x354, b'\1')
        p.uc.mem_write(form + 0x34e, b'\0')
        enabled = True
        events = []
        run(0x4620ec, action, 0)
        before = capture_state()
        events = []
        p.uc.mem_write(key_pointer, key.to_bytes(2, 'little'))
        run(0x461958, 0, key_pointer)
        report['capture'].append({'action': action, 'key': key, 'before': before,
                                  'after': capture_state()})
for action in range(6):
    for finish, address in [('ok', 0x461904), ('cancel', 0x4618d0)]:
        saved = [38, 40, 37, 39, 17, 18]
        edited = saved.copy()
        edited[action] = 113
        put_keys(edited)
        p.uc.mem_write(form + 0x354, b'\1')
        events = []
        run(address)
        report['transactions'].append({'action': action, 'finish': finish,
                                       'keys': get_keys(), 'saved': saved.copy(), 'events': list(events)})
image_mode = True
for action in range(6):
    for key in [0, 37, 38, 39, 40, 113, 17, 18]:
        put_keys([key] * 6)
        for capture in [False, True]:
            events = []
            run(0x461b44, action, int(capture))
            report['images'].append({'action': action, 'key': key, 'capture': capture,
                                     'image': next(event[1] for event in events if event[0] == 'image')})
image_mode = False
for finish, address in [('ok', 0x46b400), ('back', 0x46b488)]:
    for volume in [0, 25, 100]:
        p.uc.mem_write(options + 4, bytes([0, 3, 1, 0]))
        p.u32(options + 8, 100)
        p.u32(options + 12, 100)
        p.uc.mem_write(options + 0x18, b'\1')
        p.uc.mem_write(form + 0x364, bytes([2, 1, 4]))
        p.u32(form + 0x368, volume)
        p.u32(form + 0x36c, volume)
        checked = 0
        events = []
        run(address)
        report['options'].append({
            'finish': finish, 'volume': volume, 'controlType': p.uc.mem_read(options + 4, 1)[0],
            'resolutionCode': p.uc.mem_read(options + 5, 1)[0],
            'hardware': p.uc.mem_read(options + 6, 1)[0],
            'effects': p.integer(options + 8), 'music': p.integer(options + 12),
            'startInfo': bool(p.uc.mem_read(options + 0x18, 1)[0]), 'events': list(events),
        })
report['startInfo'] = []
for kind, address in [('quickrace', 0x46fdf0), ('adventure', 0x4786a4)]:
    for control in [0, 1, 2]:
        for start_info in [False, True]:
            p.uc.mem_write(options + 4, bytes([control]))
            p.uc.mem_write(options + 0x18, bytes([int(start_info)]))
            events = []
            run(address)
            report['startInfo'].append({'kind': kind, 'controlType': control,
                'startInfo': start_info, 'shown': ['startInfo'] in events})
path = ROOT / 'evidence/native/menu-settings-fixtures.json'
path.write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({key: len(report[key]) for key in ['capture', 'transactions', 'images', 'options', 'startInfo']}))
