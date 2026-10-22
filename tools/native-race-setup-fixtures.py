#!/usr/bin/env python3
"""Original grid marker scan, racer ranks and heading across all shipped tracks."""
import json
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH
from native_ai_fixture_track import install_track
from unicorn.x86_const import UC_X86_REG_FPCW

def main():
    p = NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f)
    p.uc.mem_map(0x24000000, 0x400000)
    p.uc.mem_write(0x4afce0, b'\xc3')
    p.uc.mem_write(0x4afee0, b'\xc3')
    p.uc.mem_write(0x417e90, b'\x31\xc0\xc3') # all entries are NPCs
    sectors = json.loads((ROOT / 'evidence/gameplay/native-track-fixtures.json').read_text())['tracks']
    output = {'sourceSha256': p.sha, 'routines': ['0x415dd0', '0x493540', '0x417ae0'], 'scope': 'Grid marker scan, heading and rank allocation; model creation is separate', 'cases': []}
    for track_id in range(6):
        track = json.loads((ROOT / f'public/assets/tracks/etappe{track_id}.json').read_text())
        install_track(p, track)
        p.u32(0x680b2c, len(track['route']))
        for i, sector in enumerate(sectors[track_id]['sectors']):
            for j, value in enumerate(sector['forward']): p.f32(0x24000000 + i * 0x984 + 0x48 + j * 4, value)
        for count in range(5):
            p.u32(0x508610, count); p.u32(0x507f40, 0)
            p.uc.mem_write(0x5072c0, bytes(200))
            p.run(0x415dd0)
            if not p.integer(0x5072b8) & 255: raise ValueError('Original markers incomplete')
            grid = []
            for i in range(count + 1):
                base = 0x5072c0 + i * 20
                sector = p.integer(base + 4)
                p.run(0x493540, [0, sector, 1])
                grid.append({'sector': sector, 'position': [p.float(base + 8 + j * 4) for j in range(3)], 'yaw': p.float(SCRATCH + 0x4078)})
            for player_rank in range(count + 1):
                p.u32(0x53be60, player_rank)
                p.run(0x417ae0)
                output['cases'].append({'track': track_id, 'opponentCount': count, 'previousFinishPosition': player_rank,
                    'grid': grid, 'ranks': [p.integer(0x5081b8 + j * 0x70) for j in range(count)]})
    (ROOT / 'evidence/native/race-setup-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', len(output['cases']), 'native grid/rank cases')

if __name__ == '__main__': main()
