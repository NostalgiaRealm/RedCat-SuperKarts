#!/usr/bin/env python3
"""Execute original normal racer callback with real track graph and table data."""
import argparse, json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_ai_fixture_track import install_track
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_FPCW

def signed(value):
    return value - 0x100000000 if value > 0x7fffffff else value

def main(mode=0):
    rng = random.Random(0x40e180)
    output = {'routines': ['0x401320', '0x409b30', '0x40e180'], 'bearing': [], 'normal': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        output['sourceSha256'] = p.sha
        p.uc.mem_map(0x24000000, 0x400000)
        p.uc.mem_write(0x4afce0, b'\xc3')
        p.uc.mem_write(0x4afee0, b'\xc3')
        p.uc.mem_write(0x410100, b'\xa1' + struct.pack('<I', SCRATCH + 0x9000) + b'\xc3')
        p.u32(0x503ef0, 0)
        p.u32(0x503ef4, mode)
        p.u32(0x508610, 4)
        for i in range(240):
            body = {'x': rng.uniform(-500, 500), 'z': rng.uniform(-500, 500), 'yaw': rng.uniform(-4096, 8192)}
            target = [rng.uniform(-500, 500), 0, rng.uniform(-500, 500)]
            if i % 5 == 0: target[0] = body['x']
            for key, offset in [('x', 0x50), ('z', 0x58), ('yaw', 0x78)]:
                p.f32(SCRATCH + 0x4000 + offset, body[key]); body[key] = p.float(SCRATCH + 0x4000 + offset)
            for j, value in enumerate(target):
                p.f32(SCRATCH + 0x8000 + j * 4, value); target[j] = p.float(SCRATCH + 0x8000 + j * 4)
            p.run(0x401320, [0, SCRATCH + 0x8000])
            output['bearing'].append({'precision': precision, 'body': body, 'target': target,
                'expected': signed(p.uc.reg_read(UC_X86_REG_EAX)), 'yaw': p.float(SCRATCH + 0x4078)})
        for track_id in range(6):
            track = json.loads((ROOT / f'public/assets/tracks/etappe{track_id}.json').read_text())
            if mode == 27:
                # No supplied map contains marker66. Exercise the dormant
                # original handler on real geometry with explicit synthetic tags.
                for node in track['drive']: node['unknown'][1] = 66
                output['markerOverride'] = 66
            install_track(p, track)
            forced_sectors = [i for i in range(len(track['route'])) if any(
                track['drive'][node]['unknown'][1] == 66 for node in track['route'][(i + 1) % len(track['route'])]['driveIndices'])]
            for i in range(30):
                if mode == 27 and not forced_sectors: continue
                sector = rng.choice(forced_sectors) if mode == 27 else rng.randrange(len(track['route']))
                if not track['route'][sector]['driveIndices']: continue
                node = track['drive'][track['route'][sector]['driveIndices'][0]]
                body = {'x': node['position'][0] + rng.uniform(-30, 30), 'y': node['position'][1], 'z': node['position'][2] + rng.uniform(-30, 30),
                    'yaw': rng.uniform(-4096, 8192), 'pitch': rng.uniform(-2, 2), 'roll': rng.uniform(-2, 2),
                    'forwardSpeed': rng.uniform(-13, 85), 'lateralSpeed': rng.uniform(-5, 5),
                    'yawRate': rng.uniform(-2, 2), 'pitchRate': rng.uniform(-2, 2), 'rollRate': rng.uniform(-2, 2)}
                addresses = {'x': SCRATCH + 0x4050, 'y': SCRATCH + 0x4054, 'z': SCRATCH + 0x4058,
                    'yaw': SCRATCH + 0x4078, 'pitch': SCRATCH + 0x4074, 'roll': SCRATCH + 0x407c,
                    'forwardSpeed': OBJECT + 0xa4, 'lateralSpeed': OBJECT + 0x9c, 'yawRate': OBJECT + 0xac,
                    'pitchRate': OBJECT + 0xa8, 'rollRate': OBJECT + 0xb0}
                for key, address in addresses.items(): p.f32(address, body[key]); body[key] = p.float(address)
                body.update({'sector': sector, 'id': 0})
                p.u32(OBJECT + 0x1c, sector)
                player_sector = (sector + 1) % len(track['route'])
                player_node = track['drive'][track['route'][player_sector]['driveIndices'][0]]
                player = {'id': 3, 'sector': player_sector, **dict(zip(['x', 'y', 'z'], player_node['position']))}
                p.u32(0x503ef8, 3)
                p.u32(OBJECT + 3 * 0xd0 + 0xc, 3)
                p.u32(OBJECT + 3 * 0xd0 + 0x1c, player_sector)
                for j, value in enumerate(player_node['position']): p.f32(SCRATCH + 0x4000 + 3 * 0xa9 + 0x50 + j * 4, value)
                p.run(0x494000, [0, 1])
                nearest = p.uc.reg_read(UC_X86_REG_EAX)
                occupancy = []
                for waypoint in range(len(track['drive'])): p.u32(0x24200000 + waypoint * 0x50 + 0x24, 0)
                for j in range(1, 3):
                    other = {'id': j, 'x': body['x'] + rng.uniform(-60, 60), 'y': body['y'], 'z': body['z'] + rng.uniform(-60, 60), 'forwardSpeed': rng.uniform(0, 90)}
                    p.u32(OBJECT + j * 0xd0 + 0xc, j)
                    for key, offset in [('x', 0x50), ('y', 0x54), ('z', 0x58)]:
                        address = SCRATCH + 0x4000 + j * 0xa9 + offset
                        p.f32(address, other[key]); other[key] = p.float(address)
                    p.f32(OBJECT + j * 0xd0 + 0xa4, other['forwardSpeed']); other['forwardSpeed'] = p.float(OBJECT + j * 0xd0 + 0xa4)
                    occupancy.append(other)
                p.u32(0x24200000 + nearest * 0x50 + 0x24, 2)
                p.u32(0x24200000 + nearest * 0x50 + 0x28, 1)
                p.u32(0x24200000 + nearest * 0x50 + 0x2c, 2)
                for j in range(8):
                    p.u32(0x505a30 + j * 24, 0xffffffff)
                    p.u32(0x505a40 + j * 24, 0)
                preset, record, player_record = i % 3, i % 9, (i // 9) % 9
                p.uc.mem_write(0x5068d0, (SOURCE / f'cars{preset}.dat').read_bytes())
                p.u32(0x503f24, record); p.u32(0x53be2c, player_record)
                state = {'gear': i % 6, 'reverseLatch': False, 'disabled': False, 'turnTime': 0,
                    'turnIntegral': 0, 'turnStartHeading': 0, 'special': False, 'specialTime': 0,
                    'waypoint': nearest, 'priorities': [0, 1, 2]}
                if mode: state.update({'mode': mode, 'chaseTime': .5})
                p.f32(0x503f04, .5)
                p.u32(0x503ef4, mode)
                for key, address in [('gear', 0x503f38), ('reverseLatch', 0x503f4c), ('disabled', 0x503f34), ('waypoint', 0x503f10)]:
                    p.u32(address, int(state[key]))
                for address in [0x503f3c, 0x503f40, 0x503f44, 0x503ffc, 0x503ff8, 0x53bef4, 0x50728c, 0x507294]: p.u32(address, 0)
                for j in range(3): p.u32(0x503f7c + j * 4, j)
                controls = {'throttle': rng.choice([0, 50, 100]), 'brake': rng.choice([0, 50, 100]), 'steering': 0}
                for key, address in [('throttle', 0x503f2c), ('brake', 0x503f30), ('steering', 0x503f28)]: p.f32(address, controls[key])
                dt = rng.choice([.025, .03125, .1])
                seed = rng.randrange(2 ** 32); efficiency = rng.choice([10, 20, 40, 70, 100])
                p.f32(SCRATCH + 0x1000, dt); p.u32(0x502978, seed); p.u32(SCRATCH + 0x9000, efficiency)
                p.run({0: 0x40e180, 1: 0x409cc0, 2: 0x409dc0, 27: 0x40e270}[mode], [0])
                expected_state = {**state, **{key: p.float(address) for key, address in [('turnTime', 0x503f3c), ('turnIntegral', 0x503f40), ('turnStartHeading', 0x503f44)]},
                    'gear': p.integer(0x503f38), 'reverseLatch': bool(p.integer(0x503f4c)), 'disabled': bool(p.integer(0x503f34)),
                    'waypoint': p.integer(0x503f10), 'priorities': [p.integer(0x503f7c + j * 4) for j in range(3)]}
                if mode: expected_state['chaseTime'] = p.float(0x503f04)
                output['normal'].append({'track': track_id, 'precision': precision, 'preset': preset, 'record': record, 'playerRecord': player_record,
                    'body': body, 'state': state, 'controls': controls, 'nearest': nearest, 'occupants': occupancy, 'player': player,
                    'dt': dt, 'seed': seed, 'efficiency': efficiency, 'randomState': p.integer(0x502978),
                    'expected': {'body': {**body, **{key: p.float(address) for key, address in addresses.items()}},
                        'state': expected_state, 'controls': {key: p.float(address) for key, address in [('throttle', 0x503f2c), ('brake', 0x503f30), ('steering', 0x503f28)]}}})
    name = 'normal' if mode == 0 else f'mode{mode}'
    if mode: output.pop('bearing')
    output['routines'] = ['0x401320', '0x409b30', {0: '0x40e180', 1: '0x409cc0', 2: '0x409dc0', 27: '0x40e270'}[mode]]
    (ROOT / f'evidence/native/ai-{name}-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', len(output.get('bearing', [])), 'bearing and', len(output['normal']), f'state{mode} callback cases')

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--mode', type=int, choices=[0, 1, 2, 27], default=0)
    main(parser.parse_args().mode)
