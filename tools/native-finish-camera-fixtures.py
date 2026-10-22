#!/usr/bin/env python3
"""Execute original 0x41fc60 finish-camera setup and 0x498c00 tracking."""
import json, random
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_FPCW

def main():
    rng = random.Random(0x41fc60)
    output = {'routines': ['0x41fc60', '0x498c00'], 'cases': []}
    tracks = [json.loads((ROOT / f'public/assets/tracks/etappe{i}.json').read_text()) for i in range(6)]
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE); p.uc.reg_write(UC_X86_REG_FPCW, cw)
        output['sourceSha256'] = p.sha
        camera, lookup, chunk = SCRATCH + 0x9000, SCRATCH + 0xc000, SCRATCH + 0xd000
        p.u32(0x680ba0, camera); p.u32(0x508634, 0); p.u32(0x53be28, 0)
        p.u32(0x4e3068, 0); p.u32(0x53be60, 5)
        p.u32(0x68021c, lookup); p.u32(0x680b28, chunk); p.u32(0x680c54, 0x1f)
        p.uc.mem_write(0x4afce0, b'\xc3'); p.uc.mem_write(0x49e9b0, b'\xc2\x04\x00')
        for index in range(60):
            track_id = index % 6; track = tracks[track_id]
            sector = rng.randrange(len(track['route']) - 3)
            p.u32(OBJECT + 0x1c, sector)
            p.u32(lookup + (sector + 3) * 4, 0)
            point = track['route'][sector + 3]['position']
            for j, value in enumerate(point): p.f32(chunk + 0x24 + j * 4, value)
            p.uc.mem_write(camera, bytes(0x178))
            p.u32(camera + 0x80, 1)
            for j in range(4): p.f32(camera + 0x14 + j * 20, 1)
            position = track['route'][sector]['position']
            matrix = [rng.uniform(-1, 1) for _ in range(9)]
            for j, value in enumerate(position): p.f32(SCRATCH + 0x4050 + j * 4, value)
            for row in range(3):
                for col in range(3):
                    p.f32(SCRATCH + 0x4010 + (row * 4 + col) * 4, matrix[row * 3 + col])
                    matrix[row * 3 + col] = p.float(SCRATCH + 0x4010 + (row * 4 + col) * 4)
            body = {'position': list(position), 'sector': sector, 'matrix': matrix}
            p.run(0x41fc60)
            initial = {'position': [p.float(camera + 8 + j * 4) for j in range(3)],
                'target': [p.float(camera + 0x54 + j * 4) for j in range(3)]}
            moved = [value + rng.uniform(-50, 50) for value in position]
            for j, value in enumerate(moved):
                p.f32(SCRATCH + 0x4050 + j * 4, value); moved[j] = p.float(SCRATCH + 0x4050 + j * 4)
            p.uc.reg_write(UC_X86_REG_ECX, camera); p.run(0x498c00)
            output['cases'].append({'precision': precision, 'track': track_id, 'body': body,
                'moved': moved, 'initial': initial, 'updated': {
                    'position': [p.float(camera + 8 + j * 4) for j in range(3)],
                    'target': [p.float(camera + 0x54 + j * 4) for j in range(3)]},
                'activeCamera': p.integer(0x508670)})
    (ROOT / 'evidence/native/finish-camera-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', len(output['cases']), 'original finish-camera setup and tracking cases')

if __name__ == '__main__': main()
