#!/usr/bin/env python3
"""Capture original CRcoStars arithmetic, tint updates and race-mode gate.

This executes isolated x86 instructions, not the Windows renderer. Original
files remain read-only; assertions and unrelated HUD constructors are stubbed.
"""
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDI, UC_X86_REG_ESI, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig

slots, updates, modes = [], [], []
for precision, control in [(24, 0x007f), (53, 0x027f)]:
    p = NativeProbe(SOURCE)
    p.uc.mem_map(0, 4096)
    p.uc.reg_write(UC_X86_REG_FPCW, control)
    initialize_native_trig(p)
    p.run(0x46dc90)  # Original static scale initializer.
    p.uc.mem_write(0x544aa8, b'\x01')  # Normal per-element color writes enabled.
    stop = p.uc.hook_add(UC_HOOK_CODE, lambda uc, address, size, data:
                        uc.emu_stop() if address == 0x46e20a else None)
    for index in range(12):
        element = SCRATCH + 0x6000 + index * 0x100
        p.u32(element, 0x4d2890)
        p.uc.reg_write(UC_X86_REG_EBX, index)
        p.uc.reg_write(UC_X86_REG_ESI, element)
        p.uc.reg_write(UC_X86_REG_EDI, 0)
        p.run(0x46e184)  # After dynamic element/string allocation.
        assert p.uc.reg_read(UC_X86_REG_EIP) == 0x46e20a
        slots.append({'precision': precision, 'index': index,
                      'position': [p.float(element + 4 + i * 4) for i in range(3)],
                      'scale': [p.float(element + 0x44 + i * 4) for i in range(3)],
                      'argb': p.integer(element + 0x28),
                      'visible': bool(p.uc.mem_read(element + 0x2c, 1)[0])})
        p.u32(OBJECT + 12 + index * 4, element)
    p.uc.hook_del(stop)
    p.uc.mem_write(0x46e330, b'\xc3')  # Pointer assertions only.
    p.u32(0x543d24, SCRATCH + 0x5000)  # Existing bonus singleton, original getter.
    p.u32(OBJECT + 0x3c, 0xffffffff)
    for count in list(range(15)) + [12, 5, 5, 0, 1, 12]:
        p.u32(SCRATCH + 0x5004, count)
        p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
        p.run(0x46e260)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        updates.append({'precision': precision, 'count': count,
                        'storedCount': p.integer(OBJECT + 0x3c),
                        'argb': [p.integer(SCRATCH + 0x6028 + i * 0x100) for i in range(12)]})

# Preserve the original mode switch, replacing unrelated constructor services.
for address in [0x4680a0, 0x468220, 0x468560, 0x4683c0, 0x4686e0, 0x468860, 0x468b80]:
    p.uc.mem_write(address, b'\xc3')
p.uc.mem_write(0x468a00, b'\xff\x05\x00\x40\x00\x20\xc3')
for mode in range(6):
    p.u32(SCRATCH + 0x4000, 0)
    p.u32(0x53a4b0, mode)  # Original 42abc0 getter reads this race-type field.
    p.run(0x467e30)
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    modes.append({'raceType': mode, 'createsStars': bool(p.integer(SCRATCH + 0x4000))})

target = ROOT / 'evidence/native/star-hud-fixtures.json'
target.write_text(json.dumps({'format': 'superkarts-native-star-hud-v1', 'sourceSHA256': p.sha,
    'functions': ['0046dc90', '0046e184..0046e205', '0046e260', '00467e30'],
    'scope': 'Original star position/scale/color arithmetic and mode dispatch with bounded allocation/assertion/HUD-service boundaries; no whole-game or GPU claim.',
    'slots': slots, 'updates': updates, 'modes': modes}, indent=2) + '\n')
print(f'Captured {len(slots)} slots, {len(updates)} updates and {len(modes)} mode branches.')
