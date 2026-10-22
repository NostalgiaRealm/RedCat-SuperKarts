#!/usr/bin/env python3
"""Original shadow geometry/pose and animated finish-flag instructions."""
import json
import random
import struct
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig


def main():
    result = {'format': 'superkarts-native-race-effects-v1', 'shadows': [], 'flags': []}
    model = json.loads((ROOT / 'public/assets/meshes/kart03.json').read_text())
    bounds = json.loads((ROOT / 'public/assets/manifest.json').read_text())['meshes']['kart03.d3d']['bounds']
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        result['sha256'] = p.sha
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        initialize_native_trig(p)
        p.u32(0x6a5ee0, SCRATCH + 0x5000)
        p.u32(0x6a5f78, SCRATCH + 0x6000)
        p.u32(SCRATCH + 0x6004, SCRATCH + 0x6100)
        p.u32(SCRATCH + 0x6100, 0)
        p.u32(0x6a5f30, SCRATCH + 0x6200)
        p.u32(SCRATCH + 0x6200, 1)
        p.u32(SCRATCH + 0x4000, 1)
        p.u32(SCRATCH + 0x4099, 0)
        p.u32(OBJECT + 0x28, 1)
        p.u32(OBJECT + 0x1c, 0)
        p.u32(SCRATCH + 0x5000 + 0xbc + 0x84, 4)
        p.u32(SCRATCH + 0x5000 + 0xbc + 0x80, SCRATCH + 0x7000)
        for index in range(len(model['position']) // 3):
            p.uc.mem_write(SCRATCH + 0xa000 + index*32, struct.pack('<3f', *model['position'][index*3:index*3+3]))
        p.uc.reg_write(UC_X86_REG_ECX, SCRATCH + 0x500c)
        p.run(0x4aa0c0, [SCRATCH + 0xa000, len(model['position']) // 3])
        p.u32(0x68021c, SCRATCH + 0x6300)
        p.u32(SCRATCH + 0x6300, 0)
        p.u32(0x680b28, SCRATCH + 0x8000)
        p.u32(0x53ba60, 0)
        p.uc.mem_write(0x4a0d80, b'\xc3')
        rng = random.Random(4260)
        for index in range(100):
            position = [rng.uniform(-8000, 8000), rng.uniform(-20, 100), rng.uniform(-8000, 8000)]
            normal = [rng.uniform(-.2, .2), rng.uniform(.5, 1), rng.uniform(-.2, .2)]
            distance = rng.uniform(-100, 100)
            matrix = [rng.uniform(-1, 1) for _ in range(9)]
            position, normal, matrix = [list(struct.unpack('<'+'f'*len(a), struct.pack('<'+'f'*len(a), *a)))
                                       for a in [position, normal, matrix]]
            distance = struct.unpack('<f', struct.pack('<f', distance))[0]
            for j, value in enumerate(position):
                p.f32(SCRATCH + 0x4050 + j*4, value)
                p.f32(SCRATCH + 0x4040 + j*4, value)
            for row in range(3):
                for column in range(3):
                    p.f32(SCRATCH + 0x4010 + (row*4+column)*4, matrix[row*3+column])
            p.f32(SCRATCH + 0x404c, 1)
            for j, value in enumerate(normal):
                p.f32(SCRATCH + 0x803c + j*4, value)
            p.f32(SCRATCH + 0x80dc, distance)
            p.run(0x4260c0, [0])
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            shadow = SCRATCH + 0x4000 + 0xa9
            result['shadows'].append({'precision': precision, 'body': {'position': position, 'matrix': matrix},
                'plane': {'normal': normal, 'distance': distance}, 'bounds': bounds,
                'expected': {'position': [p.float(shadow + 0x50 + j*4) for j in range(3)],
                    'matrix': [p.float(shadow + 0x10 + (row*4+column)*4) for row in range(3) for column in range(3)],
                    'vertices': [p.float(SCRATCH + 0x7000 + vertex*32 + axis*4) for vertex in range(4) for axis in range(3)]}})
        p.run(0x423450)
        geometry = {'position': [], 'uv': []}
        for vertex in range(340):
            base = 0x5091a0 + vertex*32
            geometry['position'].extend(p.float(base + axis*4) for axis in range(3))
            geometry['uv'].extend(p.float(base + 24 + axis*4) for axis in range(2))
        result.setdefault('flagGeometry', []).append({'precision': precision, **geometry})
        for delta in [.1, .025, 1/60, .017, .0025]:
            p.f32(SCRATCH + 0x1000, delta)
            p.run(0x423560)
            p.run(0x423230, [1])
            period = p.integer(0x50bc20)
            for tick in [0, 1, period//4, period-1]:
                p.u32(0x50bc24, tick)
                p.run(0x423280)
                result['flags'].append({'precision': precision, 'deltaSeconds': p.float(SCRATCH + 0x1000),
                    'tick': tick, 'period': period,
                    'z': [p.float(0x5091a8 + vertex*32) for vertex in range(340)],
                    'argb': [p.integer(0x5091b0 + vertex*32) for vertex in range(340)]})
    target = ROOT / 'evidence/native/race-effect-fixtures.json'
    target.write_text(json.dumps(result, indent=2) + '\n')
    print('Wrote', len(result['shadows']), 'shadow poses and', len(result['flags']), 'finish-flag frames')


if __name__ == '__main__':
    main()
