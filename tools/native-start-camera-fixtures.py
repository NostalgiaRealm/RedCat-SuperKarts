#!/usr/bin/env python3
"""Original startup camera initialization, wall-clock spline and convergence."""
import json
import random
import struct
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, STACK


def main():
    rng = random.Random(0x443e80)
    out = {'routines': ['0x443e80', '0x443d20', '0x443db0', '0x4441a0',
                        '0x443f10', '0x443ff0', '0x498c00'], 'cases': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        out['sourceSha256'] = p.sha
        p.uc.mem_write(0x4afce0, b'\xc3')
        p.uc.mem_write(SCRATCH + 0xb000, b'\xa1' + struct.pack('<I', SCRATCH + 0xb100) + b'\xc3')
        p.u32(0x4d215c, SCRATCH + 0xb000)
        base, camera = SCRATCH + 0x8000, SCRATCH + 0x8178
        p.u32(0x680ba0, base)
        p.u32(0x508620, 0)
        p.u32(0x508638, 1)
        p.u32(0x53be28, 0)
        p.u32(0x4e3068, 0)
        p.u32(0x680c54, 31)
        for track_id in range(6):
            track = json.loads((ROOT / f'public/assets/tracks/etappe{track_id}.json').read_text())
            index = next(i for i, path in enumerate(track['paths']) if path['type'] == 1)
            for delta in [.025, .03125, .05, .1]:
                p.uc.mem_write(0x53f4f8, bytes(0x24 * 10))
                p.u32(0x543760, len(track['paths']))
                for i, path in enumerate(track['paths']):
                    address = 0x53f660 + i * 0x340
                    p.uc.mem_write(address, struct.pack('<6i', path['startSector'], path['endSector'],
                        path['type'], path['unknown'], path['durationMs'], len(path['points'])))
                    for j, point in enumerate(path['points']):
                        p.uc.mem_write(address + 24 + j * 16, struct.pack('<i3f', point['flag'], *point['position']))
                p.uc.mem_write(base, bytes(0x178 * 2))
                for cam in [base, camera]:
                    for j in range(4):
                        p.f32(cam + 0x14 + j * 20, 1)
                    p.u32(cam + 0x80, 1)
                p.u32(base + 0x74, 1)
                p.u32(base + 0x78, 1)
                for j, v in enumerate([0, 50, -150]):
                    p.f32(base + 0xbc + 4 * j, v)
                for j, v in enumerate([0, 50, 0]):
                    p.f32(base + 0xcc + 4 * j, v)
                body = {'position': track['paths'][index]['points'][-1]['position'].copy(),
                        'matrix': [rng.uniform(-1, 1) for _ in range(9)]}
                body['position'][1] = 10
                for j, v in enumerate(body['position']):
                    p.f32(SCRATCH + 0x4050 + j * 4, v)
                for row in range(3):
                    for col in range(3):
                        p.f32(SCRATCH + 0x4010 + (row * 4 + col) * 4, body['matrix'][row * 3 + col])
                        body['matrix'][row * 3 + col] = p.float(SCRATCH + 0x4010 + (row * 4 + col) * 4)
                p.u32(0x53b9c0, 1)
                p.f32(SCRATCH + 0x1000, delta)
                now = 10000
                p.u32(SCRATCH + 0xb100, now)
                # 443d20 leaves the temporary duration uninitialized. 443db0
                # uses it only for tick0, which equals the first point for any
                # valid nonzero segment duration. Seed the probe stack with a
                # valid value; the actual allocated state's duration is native.
                p.uc.mem_write(STACK, struct.pack('<I', 4096) * (0x10000 // 4))
                p.run(0x443e80, [index])

                def snapshot():
                    return {'position': [p.float(camera + 8 + j * 4) for j in range(3)],
                            'target': [p.float(camera + 0x54 + j * 4) for j in range(3)],
                            'up': [p.float(camera + 0x60 + j * 4) for j in range(3)]}

                p.uc.reg_write(UC_X86_REG_ECX, camera)
                p.run(0x498c00)
                case = {'track': track_id, 'precision': precision, 'delta': delta,
                        'body': body, 'startedMs': now, 'ticks': p.integer(0x53f500),
                        'initial': snapshot(), 'updates': []}
                for frame in range(2000):
                    now += [16, 17, 25, 50][frame % 4]
                    p.u32(SCRATCH + 0xb100, now)
                    p.run(0x4441a0, [0x53f4fc])
                    done = bool(p.uc.reg_read(UC_X86_REG_EAX) & 255)
                    p.uc.reg_write(UC_X86_REG_ECX, camera)
                    p.run(0x498c00)
                    case['updates'].append({'nowMs': now, 'stage': p.integer(0x53f4ec),
                        'tick': p.integer(0x53f504), 'lastPathMs': p.integer(0x53f4f4),
                        'done': done, **snapshot()})
                    if done:
                        break
                assert done, (track_id, precision, delta)
                out['cases'].append(case)
    out['method'] = ('Original instructions with controlled engine delta/GetTickCount; log boundary stub. '
        'The temporary uninitialized tick-zero duration is seeded4096; allocated path duration is unmodified original output.')
    (ROOT / 'evidence/native/start-camera-fixtures.json').write_text(json.dumps(out, separators=(',', ':')) + '\n')
    print('Wrote', len(out['cases']), 'startups and', sum(len(c['updates']) for c in out['cases']), 'updates')


if __name__ == '__main__':
    main()
