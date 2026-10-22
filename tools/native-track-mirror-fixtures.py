#!/usr/bin/env python3
"""Execute original 42d8a3..42d905 projection/mirror setup with captured D3D calls.

Only the external D3D device is replaced. The projection input is explicit;
the shipped branch, signs, copy, track lookup and API arguments execute intact.
Existing native analog/button fixtures independently cover mirrored controls.
"""
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, STACK


def generate():
    p = NativeProbe(SOURCE)
    device, vtable = SCRATCH + 0x3000, SCRATCH + 0x3100
    p.u32(0x6a621c, device)
    p.u32(device, vtable)
    p.u32(vtable + 0x5c, SCRATCH + 0x300)
    p.u32(vtable + 0x68, SCRATCH + 0x400)
    for address in [SCRATCH + 0x300, SCRATCH + 0x400]:
        p.uc.mem_write(address, b'\x31\xc0\xc2\x0c\x00')
    calls = []

    def capture(uc, address, size, data):
        sp = uc.reg_read(UC_X86_REG_ESP)
        args = [p.integer(sp + offset) for offset in [4, 8, 12]]
        if address == SCRATCH + 0x300:
            calls.append({'api': 'SetRenderState', 'state': args[1], 'value': args[2]})
        else:
            calls.append({'api': 'SetTransform', 'state': args[1],
                          'matrix': [p.float(args[2] + i * 4) for i in range(16)]})
    p.uc.hook_add(UC_HOOK_CODE, capture, begin=SCRATCH + 0x300, end=SCRATCH + 0x300)
    p.uc.hook_add(UC_HOOK_CODE, capture, begin=SCRATCH + 0x400, end=SCRATCH + 0x400)
    cases = []
    for track in range(6):
        authored = json.loads((ROOT / f'public/assets/tracks/etappe{track}.json').read_text())
        for flag in [int(authored['mirrored']), 2]:
            matrix = [float(i + 1) for i in range(16)]
            sp = STACK + 0x8000
            for i, value in enumerate(matrix):
                p.f32(sp + 0x54 + i * 4, value)
            p.u32(0x53a734 + track * 0x94, flag)
            p.uc.reg_write(UC_X86_REG_EAX, track)
            p.uc.reg_write(UC_X86_REG_ESP, sp)
            calls.clear()
            p.uc.emu_start(0x42d8a3, 0x42d905, count=1000)
            assert p.uc.reg_read(UC_X86_REG_EIP) == 0x42d905
            result = [p.float(0x6a615c + i * 4) for i in range(16)]
            expected = [-value if flag == 1 and i in [0, 4, 8] else value
                        for i, value in enumerate(matrix)]
            assert result == expected
            assert calls[-1] == {'api': 'SetTransform', 'state': 3, 'matrix': expected}
            assert len(calls) == (2 if flag == 1 else 1)
            if flag == 1:
                assert calls[0] == {'api': 'SetRenderState', 'state': 22, 'value': 2}
            cases.append({'track': track, 'authoredFlag': int(authored['mirrored']),
                          'flag': flag, 'input': matrix, 'output': result, 'calls': list(calls)})
    return {'scope': __doc__, 'sourceSha256': p.sha, 'cases': cases}


if __name__ == '__main__':
    path = ROOT / 'evidence/full-race-matrix/native-track-mirror.json'
    path.write_text(json.dumps(generate(), indent=2) + '\n')
    print(path)
