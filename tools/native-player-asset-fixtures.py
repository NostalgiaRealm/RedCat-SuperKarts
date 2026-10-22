#!/usr/bin/env python3
"""Run original x86 bounding-box and character-animation admission instructions."""
import json
import struct
from pathlib import Path
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH
from unicorn.x86_const import UC_X86_REG_ECX

ROOT = Path(__file__).resolve().parents[1]
p = NativeProbe(SOURCE)
record, vertices = SCRATCH + 0x5000, SCRATCH + 0x6000
bounds = {}
for name in ['kart03', 'wiela', 'wielv', 'redcar', 'buggy', 'ufotje',
             'pootje1', 'pootje2', 'pootje3', 'pootje4', 'pootje5', 'ster', 'flle0008']:
    data = json.loads((ROOT / f'public/assets/meshes/{name}.json').read_text())
    coords = data['position']
    packed = b''.join(struct.pack('<8f', *coords[i:i + 3], 0, 0, 0, 0, 0)
                      for i in range(0, len(coords), 3))
    p.uc.mem_write(vertices, packed)
    p.uc.mem_write(record, bytes(0xbc))
    p.u32(record, 2)
    p.u32(record + 0x80, vertices)
    p.u32(record + 0x84, len(coords) // 3)
    p.uc.reg_write(UC_X86_REG_ECX, record)
    p.run(0x4aa040)
    bounds[name + '.d3d'] = {
        'sourceSHA256': data['source']['sha256'],
        'horizontalRadius': p.float(record + 0x74),
        'bounds': {name: p.float(record + offset) for name, offset in
                   [('minX', 0x10), ('minY', 0x14), ('minZ', 0x18),
                    ('maxX', 0x1c), ('maxY', 0x2c), ('maxZ', 0x48)]},
        'corners': [[p.float(record + 0x10 + corner * 12 + axis * 4)
                     for axis in range(3)] for corner in range(8)],
    }

# 0044ce90's unchanged state/queue checks and state assignment. The virtual
# enqueue callee is a controlled stub; it increments the real queue-length field.
# Logging is a no-op. The original branch instructions are not patched.
p.uc.mem_write(0x4afce0, b'\xc3')
vtable, callback, argument = SCRATCH + 0x3000, SCRATCH + 0x3100, SCRATCH + 0x3200
p.uc.mem_write(callback, b'\xff\x41\x60\xc2\x04\x00')
p.u32(vtable, callback)
p.u32(argument + 4, 0x4eb578)  # original literal "IDLE"
admission = []
for current in range(7):
    for queued in [0, 1, 3]:
        for expected in range(7):
            target = (expected + 1) % 7
            p.uc.mem_write(record, bytes(0x78))
            for offset, value in [(0, vtable), (0x60, queued), (0x6c, current)]:
                p.u32(record + offset, value)
            p.uc.reg_write(UC_X86_REG_ECX, record)
            p.run(0x44ce90, [argument, expected, target])
            admission.append({'currentState': current, 'queueLength': queued, 'from': expected,
                              'to': target, 'resultState': p.integer(record + 0x6c),
                              'resultQueueLength': p.integer(record + 0x60)})

target = ROOT / 'evidence/native/player-asset-fixtures.json'
target.write_text(json.dumps({
    'sourceSHA256': p.sha,
    'method': 'Original x86 instructions in Unicorn; bounds use extracted source XYZ',
    'functions': ['004aa040', '004aa0c0', '0044ce90'],
    'patchedDependencies': ['logging no-op', 'virtual enqueue increments queue length'],
    'bounds': bounds, 'admission': admission,
}, indent=2) + '\n')
print(f'{len(bounds)} native mesh bounding boxes; {len(admission)} native animation admission cases')
