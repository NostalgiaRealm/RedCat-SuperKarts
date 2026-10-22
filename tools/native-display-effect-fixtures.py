#!/usr/bin/env python3
"""Original display-option initialization and rescue-ring update gates."""
import itertools
import json
import struct
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig


def main():
    p = NativeProbe(SOURCE)
    result = {'sourceSha256': p.sha, 'smoke': [], 'rescue': []}
    for address in [0x4afce0, 0x428720, 0x428800]:
        p.uc.mem_write(address, b'\xc3')
    p.uc.mem_write(0x4a6060, b'\x31\xc0\xc2\x04\x00')
    for hardware, enabled, alpha, source, destination in itertools.product([0, 1], repeat=5):
        p.u32(0x53b9f0, hardware)
        p.u32(0x53ba24, enabled)
        p.u32(0x53ba60, alpha)
        p.u32(0x53ba48, 0x10 if source else 0)
        p.u32(0x53ba4c, 2 if destination else 0)
        p.run(0x4288b0)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        result['smoke'].append({'hardware': bool(hardware), 'enabled': bool(enabled),
            'alphaBlending': bool(alpha), 'sourceCapability': bool(source),
            'destinationCapability': bool(destination), 'after': bool(p.integer(0x53ba24))})

    initialize_native_trig(p)
    spawn = 0x23000000
    p.uc.mem_map(spawn, 0x2000)
    p.run(0x48c370)
    p.uc.reg_write(UC_X86_REG_ECX, spawn)
    p.run(0x48c7e0)
    p.u32(spawn + 0x1180, 0)
    render = SCRATCH + 0x4000
    identity = [1 if i in [0, 5, 10, 15] else 0 for i in range(16)]
    p.uc.mem_write(render + 0x10, struct.pack('<16f', *identity))
    p.f32(SCRATCH + 0x1000, 0.025)
    for jetstreams, alpha, paletted in itertools.product([0, 1], repeat=3):
        p.u32(0x53ba78, jetstreams)
        p.u32(0x53ba60, alpha)
        p.u32(0x53b9b0, paletted)
        p.f32(spawn + 0x11a8, 120)
        p.uc.reg_write(UC_X86_REG_ECX, spawn)
        p.run(0x48d610)
        if p.uc.reg_read(UC_X86_REG_EIP) != SCRATCH:
            p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP), SCRATCH, count=1000000)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        result['rescue'].append({'jetstreams': bool(jetstreams), 'alphaBlending': bool(alpha),
            'paletted': bool(paletted), 'before': 120, 'after': p.float(spawn + 0x11a8)})
    (ROOT / 'evidence/native/display-effect-fixtures.json').write_text(json.dumps(result, indent=2) + '\n')
    print('Passed 32 original smoke initialization and8 rescue effect gate combinations.')


if __name__ == '__main__':
    main()
