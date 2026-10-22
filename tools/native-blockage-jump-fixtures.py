#!/usr/bin/env python3
"""Original registered jump dispatch, direction/waypoint gates and wheel writes.

The executable and asset inputs remain read-only. Calls execute 441970/493290
registration, 4938e0 boundary dispatch, 441c50/441d50, 415be0 and 4906b0.
Only the unrelated 440ef0 scheduler registration is stubbed. The existing
NativeProbe supplies the original capped-delta service's .025 input.
"""
import json
import random
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESI, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH, STACK
from native_ai_fixture_track import install_track

RENDER = SCRATCH + 0x4000
BASE = 0x24000000


def generate():
    config = json.loads((ROOT / 'public/assets/config.json').read_text())
    authored_settings = config['track.ini']['zipper_boost']
    # 4b1ed0 wraps GetPrivateProfileIntA, not a float parser. Its external
    # integer return is the explicit boundary for the original load slice.
    settings = {key: int(float(value)) for key, value in authored_settings.items()}
    route_options = {'british': int(config['race.ini']['etappe'].get('british', 0)),
                     'direction': int(config['race.ini']['etappe'].get('direction', 0))}
    tracks = [json.loads((ROOT / f'public/assets/tracks/etappe{i}.json').read_text()) for i in range(6)]
    output = {'scope': __doc__, 'sourceSha256': None, 'settings': settings,
              'authoredSettings': authored_settings, 'routeOptions': route_options, 'loads': [],
              'registration': {}, 'cases': [], 'crossings': [], 'inventory': []}
    rng = random.Random(44150)
    for precision in [24, 53]:
        p = NativeProbe(SOURCE)
        p.uc.mem_map(0, 4096)
        p.uc.mem_map(BASE, 0x400000)
        p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
        p.f32(SCRATCH + 0x1000, .025)
        p.uc.mem_write(0x440ef0, b'\xc3')
        p.run(0x441970)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        output['sourceSha256'] = p.sha
        output['registration'] = {str(i): hex(p.integer(0x67fe18 + i * 4))
                                  for i in [49, 50, 51, 52, 61, 62, 63]}
        fields = [(0x53d2a8, 'highforward'), (0x53d2ac, 'highup'),
                             (0x53d2a0, 'mediumforward'), (0x53d2a4, 'mediumup'),
                             (0x53d298, 'lowforward'), (0x53d29c, 'lowup')]
        p.uc.mem_write(0x4b1ed0, b'\xc3')
        loaded_keys = []

        def ini_integer(uc, address, size, data):
            sp = uc.reg_read(UC_X86_REG_ESP)
            key_address = p.integer(sp + 8)
            key = bytes(uc.mem_read(key_address, 32)).split(b'\0')[0].decode().lower()
            loaded_keys.append(key)
            uc.reg_write(UC_X86_REG_EAX, settings[key])

        hook = p.uc.hook_add(UC_HOOK_CODE, ini_integer, begin=0x4b1ed0, end=0x4b1ed0)
        p.uc.reg_write(UC_X86_REG_ESI, 0)
        p.uc.reg_write(UC_X86_REG_ESP, STACK + 0x8000)
        p.uc.emu_start(0x42bedf, 0x42bfad, count=10000)
        assert p.uc.reg_read(UC_X86_REG_EIP) == 0x42bfad
        p.uc.hook_del(hook)
        output['loads'].append({'precision': precision, 'keys': loaded_keys,
                               'nativeStored': {key: p.float(address) for address, key in fields}})
        p.u32(OBJECT + 0x8c, 4)
        for i in range(4):
            p.u32(OBJECT + 0x64 + i * 4, i + 1)
        p.u32(0x53ba08, route_options['direction'])

        def run(track_id, sector, previous, waypoint, waypoint_marker, primary,
                secondary, sign, speed, velocities, dispatched):
            track = tracks[track_id]
            route = track['route'][sector]
            left = route_options['british'] == 1 if route_options['direction'] == 0 else route_options['british'] != 1
            side = route['driveLeftIndices'] if left else route['driveIndices']
            origin_id = side[0] if side else 0
            origin = track['drive'][origin_id]
            following = next((link for link in origin['links'][:3] if link != -1), origin_id)
            target = track['drive'][following]
            dx = target['position'][0] - origin['position'][0]
            dz = target['position'][2] - origin['position'][2]
            matrix = [1., 0., 0., 0., 1., 0., sign * dx, 0., sign * dz]
            matrix_offsets = [0x10, 0x14, 0x18, 0x20, 0x24, 0x28, 0x30, 0x34, 0x38]
            for offset, value in zip(matrix_offsets, matrix):
                p.f32(RENDER + offset, value)
            matrix = [p.float(RENDER + offset) for offset in matrix_offsets]
            p.u32(OBJECT + 0x1c, sector)
            p.u32(OBJECT + 0x20, previous)
            p.u32(OBJECT + 0x24, waypoint)
            p.u32(BASE + 0x200000 + waypoint * 0x50 + 4, waypoint_marker)
            p.u32(BASE + sector * 0x984 + 0xec, primary)
            p.u32(BASE + sector * 0x984 + 0xf0, secondary)
            p.f32(OBJECT + 0xa4, speed)
            for i, value in enumerate(velocities):
                p.f32(RENDER + (i + 1) * 0xa9 + 0x60, value)
            row = {'precision': precision, 'track': track_id, 'sector': sector,
                   'previous': previous, 'waypoint': waypoint, 'waypointMarker': waypoint_marker,
                   'marker': primary, 'secondary': secondary, 'matrix': matrix,
                   'speed': p.float(OBJECT + 0xa4),
                   'velocities': [p.float(RENDER + (i + 1) * 0xa9 + 0x60) for i in range(4)]}
            p.run(0x4938e0 if dispatched else (0x441c50 if primary == 49 else 0x441d50), [0])
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            row['expected'] = {'speed': p.float(OBJECT + 0xa4),
                               'velocities': [p.float(RENDER + (i + 1) * 0xa9 + 0x60) for i in range(4)]}
            return row

        for track_id, track in enumerate(tracks):
            install_track(p, track)
            p.u32(0x680b2c, len(track['route']))
            p.u32(0x53ba70, route_options['british'])
            for i, route in enumerate(track['route']):
                p.u32(BASE + i * 0x984 + 0xec, route['trigger'])
                p.u32(BASE + i * 0x984 + 0xf0, route['unknown'])
            authored = [(i, route) for i, route in enumerate(track['route'])
                        if route['trigger'] in [49, 52]]
            if precision == 24:
                output['inventory'].append({'track': track_id, 'boundaries': [
                    {'sector': i, 'marker': r['trigger'], 'secondary': r['unknown'],
                     'waypointMarkers': sorted({track['drive'][wp]['unknown'][1]
                                                for wp in r['driveLeftIndices'] + r['driveIndices']})}
                    for i, r in authored]})
            for sector, route in authored:
                for waypoint in route['driveLeftIndices'] + route['driveIndices']:
                    for sign in [-1, 1]:
                        for previous in [sector - 1, sector]:
                            output['crossings'].append(run(track_id, sector, previous, waypoint,
                                track['drive'][waypoint]['unknown'][1], route['trigger'], route['unknown'],
                                sign, 23.817344, [0., -5.125, 12.768312, 110.12323], True))
            # Controlled handler inputs isolate all three configured boost
            # levels, wrong-node and wrong-heading exits, including reverse.
            if authored:
                sector, route = authored[0]
                waypoint = (route['driveLeftIndices'] + route['driveIndices'])[0]
                for primary in [49, 52]:
                    for secondary in [61, 62, 63]:
                        for marker in [0, 49, 52]:
                            for sign in [-1, 0, 1]:
                                for repeat in range(2):
                                    output['cases'].append(run(track_id, sector, sector - 1, waypoint,
                                        marker, primary, secondary, sign,
                                        rng.uniform(-15, 60), [rng.uniform(-300, 300) for _ in range(4)], False))
    target = ROOT / 'evidence/race-completion/france-native-jump-fixtures.json'
    target.write_text(json.dumps(output, indent=2) + '\n')
    print(json.dumps({'registration': output['registration'], 'cases': len(output['cases']),
                      'crossings': len(output['crossings']), 'inventory': output['inventory']}))


if __name__ == '__main__':
    generate()
