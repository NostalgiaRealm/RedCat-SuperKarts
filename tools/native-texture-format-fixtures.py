#!/usr/bin/env python3
"""Execute the shipped texture-format enumeration callback with controlled formats.

Only Direct3D enumeration input, array storage and logging are substituted.
The full original callback and selection comparisons execute. This does not
emulate hardware sampling, texture expansion, framebuffer rounding or dithering.
"""
import itertools
import json
import struct

from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT

FORMATS = {
    'RGB565': {'bits': (5, 6, 5), 'shifts': (11, 5, 0), 'masks': (0xf800, 0x7e0, 0x1f)},
    'RGB555': {'bits': (5, 5, 5), 'shifts': (10, 5, 0), 'masks': (0x7c00, 0x3e0, 0x1f)},
    'RGB888': {'bits': (8, 8, 8), 'shifts': (16, 8, 0), 'masks': (0xff0000, 0xff00, 0xff)},
}


def render_state_initialization():
    """Capture original constructor/apply/game-init states at COM boundaries."""
    p = NativeProbe(SOURCE)
    p.uc.mem_map(0, 4096)
    device, vtable, returned_matrix = SCRATCH + 0x3000, SCRATCH + 0x4000, SCRATCH + 0x5000
    set_state, set_transform, set_light = SCRATCH + 0x6000, SCRATCH + 0x6010, SCRATCH + 0x6020
    for target in [0x4a1ad0, 0x4a1a40]:
        p.uc.mem_write(target, b'\xb8' + struct.pack('<I', returned_matrix) + b'\xc3')
    for target in [0x4afce0, 0x4b1d60]:
        p.uc.mem_write(target, b'\xc3')
    p.uc.mem_write(0x4a9680, b'\xc2\x08\x00')
    p.uc.mem_write(0x4b1ed0, b'\xb8\x02\x00\x00\x00\xc3')
    p.u32(device, vtable)
    p.u32(0x6a621c, device)
    p.u32(0x4fdee4, 0xffffffff)
    for offset, target in [(0x5c, set_state), (0x68, set_transform), (0x64, set_light)]:
        p.u32(vtable + offset, target)
        p.uc.mem_write(target, b'\x31\xc0\xc2\x0c\x00')
    calls = []

    def capture(uc, address, size, unused):
        if address in [set_state, set_transform, set_light]:
            sp = uc.reg_read(UC_X86_REG_ESP)
            calls.append({'method': {set_state: 'SetRenderState', set_transform: 'SetTransform',
                                     set_light: 'SetLightState'}[address],
                          'state': p.integer(sp + 8), 'value': p.integer(sp + 12)})

    p.uc.hook_add(UC_HOOK_CODE, capture)
    p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
    p.run(0x4aad10)
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    p.u32(OBJECT + 0x274, 1)
    p.u32(OBJECT + 0x25c, device)
    p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
    p.run(0x4aaef0)
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    initialized = list(calls)
    calls.clear()
    p.u32(0x53b9f0, 1)
    p.run(0x42cff0)
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    all_states = [call for call in initialized + calls if call['method'] == 'SetRenderState']
    assert not any(call['state'] in [15, 24, 25, 26] for call in all_states)
    assert {'method': 'SetRenderState', 'state': 41, 'value': 1} in all_states
    return {'deviceInitialization': initialized, 'gameInitialization': calls,
            'unwrittenStates': {'ALPHATESTENABLE': 15, 'ALPHAREF': 24, 'ALPHAFUNC': 25, 'DITHERENABLE': 26},
            'boundary': 'Matrix constructors, logging/assertions, INI lookup and COM calls are stubbed; original device fields and state-writing instructions execute.'}


def display_modes():
    p = NativeProbe(SOURCE)
    p.uc.mem_write(0x4afce0, b'\xc3')
    p.u32(0x4e7bfc, 0)
    result = []
    for resolution, dimensions in [(3, [640, 480, 16]), (4, [800, 600, 16]), (6, [1024, 768, 16])]:
        p.u32(0x4e7b70, resolution)
        p.run(0x429220)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        actual = [p.integer(address) for address in [0x4fe930, 0x4fe934, 0x4fe938]]
        assert actual == dimensions
        result.append({'resolutionOption': resolution, 'dimensionsAndDepth': actual})
    return result


def main():
    rows = []
    for display_name, order in itertools.product(FORMATS, itertools.permutations(['RGB565', 'RGB555'])):
        p = NativeProbe(SOURCE)
        p.uc.mem_write(0x4afce0, b'\xc3')
        manager, entries, allocated, descriptor = [SCRATCH + n for n in [0x3000, 0x4000, 0x5000, 0x6000]]
        for offset, value in [(0, entries), (4, 8), (8, 0), (12, 1), (16, allocated), (0x52, 0xffffffff)]:
            p.u32(manager + offset, value)
        display = FORMATS[display_name]
        for index in range(3):
            p.u32(0x6ab7ec + index * 4, display['bits'][index])
            p.u32(0x6ab81c + index * 4, display['shifts'][index])
        trace = []
        for name in order:
            pixel_format = FORMATS[name]
            p.uc.mem_write(descriptor, bytes(0x6c))
            p.u32(descriptor, 0x6c)
            p.uc.mem_write(descriptor + 0x48, struct.pack('<8I', 32, 0x40, 0, 16, *pixel_format['masks'], 0))
            p.run(0x4ad8b0, [descriptor, manager])
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            selected = p.integer(manager + 0x52)
            trace.append({'enumerated': name, 'selectedIndex': selected,
                          'selectedFormat': order[selected] if selected != 0xffffffff else None})
        selected_name = trace[-1]['selectedFormat']
        expected = display_name if display_name != 'RGB888' else order[0]
        assert selected_name == expected, (display_name, order, trace)
        rows.append({'display': display_name, 'enumerationOrder': order, 'trace': trace})
    report = {'format': 'superkarts-native-texture-format-v1', 'sourceSha256': p.sha,
              'method': __doc__, 'entry': '004ad8b0', 'cases': rows,
              'renderStateInitialization': render_state_initialization(),
              'acceleratedDisplayModes': display_modes()}
    path = ROOT / 'evidence/native/texture-format-fixtures.json'
    path.write_text(json.dumps(report, indent=2) + '\n')
    print(f'Passed {len(rows)} original enumeration sequences / {sum(len(row["trace"]) for row in rows)} callbacks.')


if __name__ == '__main__':
    main()
