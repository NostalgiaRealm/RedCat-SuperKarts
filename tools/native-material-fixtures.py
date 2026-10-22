#!/usr/bin/env python3
"""Capture original Direct3D state calls and original diffuse-color packing."""
import json
import struct
from pathlib import Path
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_EBP, UC_X86_REG_EBX, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH, OBJECT, STACK

ROOT = Path(__file__).resolve().parents[1]
p = NativeProbe(SOURCE)
device, vtable, callback = SCRATCH + 0x3000, SCRATCH + 0x3100, SCRATCH + 0x3200
render, output, stack = SCRATCH + 0x4000, SCRATCH + 0x6000, STACK + 0xe000
p.u32(0x6a621c, device)
p.u32(device, vtable)
p.u32(vtable + 0x5c, callback)
p.uc.mem_write(callback, bytes.fromhex('31c0c20c00'))
calls = []

def capture(uc, address, size, data):
    if address == callback:
        sp = uc.reg_read(UC_X86_REG_ESP)
        calls.append({'state': p.integer(sp + 8), 'value': p.integer(sp + 12)})

p.uc.hook_add(UC_HOOK_CODE, capture)
passes, enables = [], []
for mode in range(4):
    calls.clear()
    p.u32(OBJECT, 0)
    p.u32(OBJECT + 400, 1)
    p.u32(render + 0xa5, mode)
    p.uc.mem_write(render + 0x90, b'\0')  # omit geometry submission
    p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
    p.run(0x48f600)
    passes.append({'mode': mode, 'calls': list(calls)})
    for previous in [0, 1]:
        calls.clear()
        p.u32(0x6a6288, previous)
        p.uc.reg_write(UC_X86_REG_EDX, render)
        p.uc.reg_write(UC_X86_REG_ESP, stack)
        p.uc.emu_start(0x4a1097, 0x4a10e2, count=1000)
        enables.append({'mode': mode, 'previous': previous, 'enabled': p.integer(0x6a6288),
                        'calls': list(calls)})

placements = []
for placement_type in [9, 10]:
    p.u32(OBJECT + 0xc, 0)
    p.u32(render + 0xa5, 0)
    p.u32(stack + 0x68, placement_type)
    p.uc.reg_write(UC_X86_REG_EBP, 0)
    p.uc.reg_write(UC_X86_REG_ESP, stack)
    p.uc.emu_start(0x43ea26, 0x43ecc3, count=1000)
    placements.append({'type': placement_type, 'mode': p.integer(render + 0xa5)})

colors, alpha_meshes, seen = [], [], set()
for path in sorted((ROOT / 'public/assets/meshes').glob('*.json')):
    mesh = json.loads(path.read_text())
    if not any(value != 1 for value in mesh['alpha']):
        continue
    alpha_meshes.append({'mesh': path.stem + '.d3d', 'sourceSHA256': mesh['source']['sha256'],
                        'alphaMin': min(mesh['alpha']), 'alphaMax': max(mesh['alpha'])})
    for i, alpha in enumerate(mesh['alpha']):
        rgba = (*mesh['color'][i * 3:i * 3 + 3], alpha)
        if rgba in seen:
            continue
        seen.add(rgba)
        for j, value in enumerate(rgba):
            p.f32(stack + 0x70 + j * 4, value)
        p.u32(OBJECT + 0x80, output)
        p.uc.reg_write(UC_X86_REG_EBP, OBJECT)
        p.uc.reg_write(UC_X86_REG_EBX, 0)
        p.uc.reg_write(UC_X86_REG_ESP, stack)
        p.uc.emu_start(0x4a9e47, 0x4a9e9e, count=10000)
        argb = p.integer(output + 0x10)
        colors.append({'rgba': rgba, 'argb': argb,
                       'bytes': [(argb >> 16) & 255, (argb >> 8) & 255, argb & 255, argb >> 24]})

result = {'sourceSHA256': p.sha, 'method': 'Original x86 instructions; Direct3D SetRenderState captured',
          'functions': ['0043e140', '0048f600', '004a0d80', '004a9ad0'],
          'patchedDependencies': ['Direct3D SetRenderState returns success'],
          'blendTableAddress': '004fa400', 'passes': passes, 'enables': enables,
          'placements': placements, 'colors': colors, 'alphaMeshes': alpha_meshes}
(ROOT / 'evidence/native/material-fixtures.json').write_text(json.dumps(result, indent=2) + '\n')
print(f'{len(passes)} blend modes, {len(enables)} alpha-enable transitions, '
      f'{len(colors)} original color conversions, {len(alpha_meshes)} alpha-bearing meshes')
