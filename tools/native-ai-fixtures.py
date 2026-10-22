#!/usr/bin/env python3
"""Native NPC control and longitudinal speed probes; original instructions."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_FPCW

def generate():
    rng = random.Random(414470)
    result = {'routines': ['0x414360', '0x401030', '0x4010e0', '0x414470', '0x414750', '0x401200'], 'controls': [], 'speed': [], 'steering': [], 'motion': []}
    for bits, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        result['sourceSha256'] = p.sha
        p.u32(0x503ef0, 0)
        p.u32(0x508610, 4)
        for i in range(180):
            body = {'x': rng.uniform(-500, 500), 'z': rng.uniform(-500, 500), 'yaw': rng.uniform(-4096, 8192), 'forwardSpeed': rng.uniform(-10, 100)}
            target = [rng.uniform(-500, 500), 0, rng.uniform(-500, 500)]
            if i % 9 == 0: target[0] = body['x']
            controls = {'throttle': rng.uniform(0, 100), 'brake': rng.uniform(0, 100)}
            dt = rng.choice([.025, .03125, .1, .001])
            for key, offset in [('x', 0x50), ('z', 0x58), ('yaw', 0x78)]:
                p.f32(SCRATCH + 0x4000 + offset, body[key])
                body[key] = p.float(SCRATCH + 0x4000 + offset)
            if i % 30 == 0:
                # Real spawn/path edge: coincident XZ makes 0/0 before __ftol.
                target[0], target[2] = body['x'], body['z']
            p.f32(OBJECT + 0xa4, body['forwardSpeed'])
            body['forwardSpeed'] = p.float(OBJECT + 0xa4)
            for j, value in enumerate(target):
                p.f32(SCRATCH + 0x8000 + 4 * j, value)
                target[j] = p.float(SCRATCH + 0x8000 + 4 * j)
            for key, address in [('throttle', 0x503f2c), ('brake', 0x503f30)]:
                p.f32(address, controls[key])
                controls[key] = p.float(address)
            p.f32(SCRATCH + 0x1000, dt)
            p.run(0x414360, [0] + [float(v) for v in target])
            heading = p.uc.reg_read(UC_X86_REG_EAX)
            if heading > 0x7fffffff: heading -= 0x100000000
            p.run(0x401030, [0, SCRATCH + 0x8000])
            p.run(0x4010e0, [0, SCRATCH + 0x8000])
            result['controls'].append({'precision': bits, 'body': body, 'target': target, 'controls': controls, 'dt': dt, 'heading': heading,
                'expected': {'steering': p.float(0x503f28), 'throttle': p.float(0x503f2c), 'brake': p.float(0x503f30)}})
        for i in range(240):
            preset, record, player_record = i % 3, i % 9, (i // 9) % 9
            p.uc.mem_write(0x5068d0, (SOURCE / f'cars{preset}.dat').read_bytes())
            p.u32(0x503f24, record)
            p.u32(0x53be2c, player_record)
            state = {'gear': i % 7, 'reverseLatch': bool(i % 3), 'disabled': bool(i % 13 == 0)}
            body = {'forwardSpeed': rng.choice([-.01, .01, 0, rng.uniform(-16, 100)]), 'pitchRate': rng.uniform(-3, 3)}
            controls = {'throttle': rng.choice([0, 100, rng.uniform(0, 100)]), 'brake': rng.choice([0, 100, rng.uniform(0, 100)])}
            dt = rng.choice([.025, .03125, .1, .001])
            for key, address in [('gear', 0x503f38), ('reverseLatch', 0x503f4c), ('disabled', 0x503f34)]:
                p.u32(address, int(state[key]))
            for key, address in [('forwardSpeed', OBJECT + 0xa4), ('pitchRate', OBJECT + 0xa8)]:
                p.f32(address, body[key])
                body[key] = p.float(address)
            for key, address in [('throttle', 0x503f2c), ('brake', 0x503f30)]:
                p.f32(address, controls[key])
                controls[key] = p.float(address)
            p.f32(SCRATCH + 0x1000, dt)
            p.run(0x414470, [0])
            result['speed'].append({'precision': bits, 'preset': preset, 'record': record, 'playerRecord': player_record, 'body': body, 'controls': controls, 'state': state, 'dt': dt,
                'expected': {'body': {'forwardSpeed': p.float(OBJECT + 0xa4), 'pitchRate': p.float(OBJECT + 0xa8)}, 'gear': p.integer(0x503f38), 'reverseLatch': bool(p.integer(0x503f4c))}})
        for i in range(240):
            preset, record, player_record = i % 3, i % 9, (i // 9) % 9
            p.uc.mem_write(0x5068d0, (SOURCE / f'cars{preset}.dat').read_bytes())
            p.u32(0x503f24, record)
            p.u32(0x53be2c, player_record)
            options = {'precision': bits, 'tireUpgrade': bool(i % 2), 'lowSpeedTurn': bool(i % 3), 'reverseTurn': bool(i % 3), 'traffic': bool(i % 5 == 0)}
            p.u32(0x53bef4, int(options['tireUpgrade']))
            p.u32(0x50728c, int(options['lowSpeedTurn']))
            p.u32(0x507294, int(options['reverseTurn']))
            p.u32(0x508610, 0 if options['traffic'] else 4)
            state = {'disabled': bool(i % 7 == 0), 'turnTime': rng.uniform(0, 1), 'turnIntegral': rng.uniform(-2, 2), 'turnStartHeading': rng.choice([0, rng.uniform(-2, 2)]), 'special': bool(i % 3 == 0), 'specialTime': rng.choice([.01, .1])}
            body = {'yaw': rng.uniform(-4096, 8192), 'roll': rng.uniform(-1, 1), 'forwardSpeed': rng.choice([0, -.01, .01, -1, 1, rng.uniform(-16, 90)]), 'lateralSpeed': rng.uniform(-5, 5), 'yawRate': rng.uniform(-2, 2)}
            controls = {'steering': rng.choice([0, -100, 100, rng.uniform(-100, 100)])}
            for key, address in [('yaw', SCRATCH + 0x4078), ('roll', SCRATCH + 0x407c), ('forwardSpeed', OBJECT + 0xa4), ('lateralSpeed', OBJECT + 0x9c), ('yawRate', OBJECT + 0xac)]:
                p.f32(address, body[key]); body[key] = p.float(address)
            for key, address in [('turnTime', 0x503f3c), ('turnIntegral', 0x503f40), ('turnStartHeading', 0x503f44), ('specialTime', 0x503ffc)]:
                p.f32(address, state[key]); state[key] = p.float(address)
            p.u32(0x503f34, int(state['disabled']))
            p.u32(0x503ff8, int(state['special']))
            p.f32(0x503f28, controls['steering']); controls['steering'] = p.float(0x503f28)
            dt = rng.choice([.001, .025, .03125, .1])
            p.f32(SCRATCH + 0x1000, dt)
            p.run(0x414750, [0])
            result['steering'].append({'preset': preset, 'record': record, 'playerRecord': player_record, 'body': dict(body), 'state': dict(state), 'controls': dict(controls), 'dt': dt, 'options': dict(options), 'expected': {
                'body': {key: p.float(address) for key, address in [('yaw', SCRATCH + 0x4078), ('roll', SCRATCH + 0x407c), ('forwardSpeed', OBJECT + 0xa4), ('lateralSpeed', OBJECT + 0x9c), ('yawRate', OBJECT + 0xac)]},
                'state': {**state, **{key: p.float(address) for key, address in [('turnTime', 0x503f3c), ('turnIntegral', 0x503f40), ('turnStartHeading', 0x503f44)]}}}})
            if i < 120:
                p.u32(0x508610, 4)
                options['traffic'] = False
                body.update({'x': rng.uniform(-500, 500), 'y': 0, 'z': rng.uniform(-500, 500),
                    'pitch': rng.uniform(-2, 2), 'rollRate': rng.uniform(-2, 2), 'pitchRate': rng.uniform(-2, 2)})
                addresses = {'x': SCRATCH + 0x4050, 'y': SCRATCH + 0x4054, 'z': SCRATCH + 0x4058,
                    'pitch': SCRATCH + 0x4074, 'yaw': SCRATCH + 0x4078, 'roll': SCRATCH + 0x407c,
                    'forwardSpeed': OBJECT + 0xa4, 'lateralSpeed': OBJECT + 0x9c, 'yawRate': OBJECT + 0xac,
                    'rollRate': OBJECT + 0xb0, 'pitchRate': OBJECT + 0xa8}
                for key, address in addresses.items(): p.f32(address, body[key]); body[key] = p.float(address)
                controls.update({'throttle': rng.choice([0, 50, 100]), 'brake': rng.choice([0, 50, 100])})
                for key, address in [('throttle', 0x503f2c), ('brake', 0x503f30)]: p.f32(address, controls[key])
                state.update({'gear': i % 6, 'reverseLatch': bool(i % 3)})
                for key, address in [('turnTime', 0x503f3c), ('turnIntegral', 0x503f40), ('turnStartHeading', 0x503f44)]: p.f32(address, state[key])
                p.u32(0x503f38, state['gear']); p.u32(0x503f4c, int(state['reverseLatch']))
                target = [rng.uniform(-500, 500), 0, rng.uniform(-500, 500)]
                for j, value in enumerate(target): p.f32(SCRATCH + 0x8000 + j * 4, value); target[j] = p.float(SCRATCH + 0x8000 + j * 4)
                seed = rng.randrange(2 ** 32); p.u32(0x502978, seed)
                p.run(0x401200, [0, SCRATCH + 0x8000])
                result['motion'].append({'preset': preset, 'record': record, 'playerRecord': player_record,
                    'body': dict(body), 'controls': dict(controls), 'state': dict(state), 'options': dict(options),
                    'dt': dt, 'target': target, 'seed': seed, 'randomState': p.integer(0x502978),
                    'expected': {'body': {key: p.float(address) for key, address in addresses.items()},
                        'controls': {**controls, 'steering': p.float(0x503f28)},
                        'state': {**state, **{key: p.float(address) for key, address in [('turnTime', 0x503f3c), ('turnIntegral', 0x503f40), ('turnStartHeading', 0x503f44)]},
                            'gear': p.integer(0x503f38), 'reverseLatch': bool(p.integer(0x503f4c))}}})
    (ROOT / 'evidence/native/ai-fixtures.json').write_text(json.dumps(result, indent=2) + '\n')
    print('Wrote', len(result['controls']), 'AI control,', len(result['speed']), 'AI longitudinal and', len(result['steering']), 'lateral cases')

if __name__ == '__main__':
    generate()
