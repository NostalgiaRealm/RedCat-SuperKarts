#!/usr/bin/env python3
"""Original closest-waypoint and racer graph search on all six shipped tracks."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

AUX = 0x24000000
SECTORS = AUX
WAYPOINTS = AUX + 0x200000
MAP = AUX + 0x300000

def main():
    rng = random.Random(40940)
    p = NativeProbe(SOURCE)
    p.uc.mem_map(AUX, 0x400000)
    p.uc.mem_write(0x4afce0, b'\xc3')
    p.uc.mem_write(0x4afee0, b'\xc3')
    p.u32(0x680b28, SECTORS)
    p.u32(0x680ae0, WAYPOINTS)
    p.u32(0x68021c, MAP)
    p.u32(0x503ef0, 0)
    p.u32(0x503ef4, 0)
    priorities = [1, 2, 0]
    def hook(uc, address, size, data):
        if address != 0x40f0b0:
            return
        stack = uc.reg_read(UC_X86_REG_ESP)
        for i, value in enumerate(priorities):
            p.u32(p.integer(stack + 12 + i * 4), value)
        uc.reg_write(UC_X86_REG_EIP, p.integer(stack))
        uc.reg_write(UC_X86_REG_ESP, stack + 4)
    p.uc.hook_add(UC_HOOK_CODE, hook)
    output = {'sourceSha256': p.sha, 'routines': ['0x494000', '0x40ed40'], 'scope': 'Original graph search and nearest waypoint; priority helper supplied explicitly, no AI personality/FSM claim', 'tracks': []}
    for track_id in range(6):
        track = json.loads((ROOT / f'public/assets/tracks/etappe{track_id}.json').read_text())
        for i, route in enumerate(track['route']):
            p.u32(MAP + i * 4, i)
            for count_offset, list_offset, key in [(0xe4, 0x124, 'driveLeftIndices'), (0xe8, 0x154, 'driveIndices')]:
                p.u32(SECTORS + i * 0x984 + count_offset, len(route[key]))
                for j, value in enumerate(route[key]):
                    p.u32(SECTORS + i * 0x984 + list_offset + j * 4, value)
        for i, node in enumerate(track['drive']):
            base = WAYPOINTS + i * 0x50
            for j, value in enumerate(node['unknown']): p.u32(base + j * 4, value)
            for j, value in enumerate(node['position']): p.f32(base + 8 + j * 4, value)
            for j, value in enumerate([node['links'][0], node['links'][2], node['links'][1], node['links'][3]]):
                p.u32(base + 0x14 + j * 4, value & 0xffffffff)
        cases = []
        for i in range(120):
            sector = rng.randrange(len(track['route']))
            p.u32(OBJECT + 0x1c, sector)
            position = [track['route'][sector]['position'][j] + rng.uniform(-200, 200) for j in range(3)]
            for j, value in enumerate(position):
                p.f32(SCRATCH + 0x4050 + j * 4, value)
                position[j] = p.float(SCRATCH + 0x4050 + j * 4)
            p.run(0x494000, [0, 1])
            nearest = p.uc.reg_read(UC_X86_REG_EAX)
            if nearest > 0x7fffffff: nearest -= 0x100000000
            if nearest < 0: continue
            priorities = rng.choice([[0, 1, 2], [1, 0, 2], [1, 2, 0], [2, 1, 0]])
            occupied = list(range(len(track['drive']))) if i % 10 == 0 else rng.sample(range(len(track['drive'])), i % 30)
            for j in range(len(track['drive'])): p.u32(WAYPOINTS + j * 0x50 + 0x24, int(j in occupied))
            initial = {'steering': [123, 234, 345], 'speed': [456, 567, 678]}
            for base, values in [(SCRATCH + 0x8000, initial['steering']), (SCRATCH + 0x8100, initial['speed'])]:
                for j, value in enumerate(values): p.f32(base + j * 4, value)
            p.run(0x40ed40, [0, 0, 5, nearest, SCRATCH + 0x8000, SCRATCH + 0x8100])
            result = p.uc.reg_read(UC_X86_REG_EAX)
            if result > 0x7fffffff: result -= 0x100000000
            cases.append({'sector': sector, 'position': position, 'nearest': nearest, 'priorities': priorities, 'occupied': occupied, 'initial': initial,
                'expected': {'waypoint': result, 'steering': [p.float(SCRATCH + 0x8000 + j * 4) for j in range(3)], 'speed': [p.float(SCRATCH + 0x8100 + j * 4) for j in range(3)]}})
        output['tracks'].append({'id': track_id, 'cases': cases})
    (ROOT / 'evidence/native/ai-path-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', sum(len(t['cases']) for t in output['tracks']), 'native AI nearest/path cases')

if __name__ == '__main__':
    main()
