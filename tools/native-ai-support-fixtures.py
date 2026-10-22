#!/usr/bin/env python3
"""Original NPC random lane changes, wobble, catch-up, and wheel presentation."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_FPCW

def generate():
    rng = random.Random(0x405fd0)
    output = {'routines': ['0x40e070', '0x412fd0', '0x4130e0', '0x4062b0', '0x41c4b0'], 'priority': [], 'wobble': [], 'catchup': [], 'wheels': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        output['sourceSha256'] = p.sha
        initialize_native_trig(p)
        p.uc.mem_write(0x410100, b'\xa1' + struct.pack('<I', SCRATCH + 0x9000) + b'\xc3')
        p.uc.mem_write(0x417e90, b'\x31\xc0\xc3')
        p.u32(0x504f98, SCRATCH + 0xa000)
        p.u32(0x5081bc, 0)
        p.u32(0x53be70, 0)
        for i in range(120):
            seed = rng.randrange(2 ** 32)
            priorities = rng.choice([[0, 1, 2], [1, 0, 2], [2, 1, 0]])
            efficiency = rng.choice([0, 1, 10, 20, 40, 70, 100])
            p.u32(0x502978, seed)
            p.u32(SCRATCH + 0x9000, efficiency)
            for j, value in enumerate(priorities): p.u32(0x503f7c + j * 4, value)
            p.run(0x40e070, [0])
            output['priority'].append({'seed': seed, 'efficiency': efficiency, 'priorities': priorities, 'expected': {'priorities': [p.integer(0x503f7c + j * 4) for j in range(3)], 'state': p.integer(0x502978)}})
            body = {key: rng.uniform(-5, 5) for key in ['roll', 'rollRate', 'pitch', 'pitchRate']}
            body['forwardSpeed'] = rng.uniform(-15, 90)
            addresses = {'roll': SCRATCH + 0x407c, 'pitch': SCRATCH + 0x4074, 'rollRate': OBJECT + 0xb0, 'pitchRate': OBJECT + 0xa8, 'forwardSpeed': OBJECT + 0xa4}
            for key, address in addresses.items(): p.f32(address, body[key]); body[key] = p.float(address)
            dt = rng.choice([.001, .025, .03125, .1])
            p.u32(0x502978, seed)
            p.f32(SCRATCH + 0x1000, dt)
            p.run(0x412fd0, [0])
            p.run(0x4130e0, [0])
            output['wobble'].append({'precision': precision, 'seed': seed, 'body': body, 'dt': dt, 'expected': {key: p.float(address) for key, address in addresses.items()}, 'randomState': p.integer(0x502978)})
            body = {key: rng.uniform(-15, 90) for key in ['lateralSpeed', 'verticalSpeed', 'forwardSpeed']}
            for j, key in enumerate(body): p.f32(OBJECT + 0x9c + j * 4, body[key]); body[key] = p.float(OBJECT + 0x9c + j * 4)
            difference = rng.choice([-150, -25, -20, -7, -6, -5, -2, -1, 0, 1, 2, 5, 6, 12, 23, 150])
            difficulty = i % 3
            special_time = rng.uniform(0, 1)
            p.f32(0x503ffc, special_time)
            special_time = p.float(0x503ffc)
            p.u32(0x503ff8, 1)
            p.u32(0x53b9f4, difficulty)
            p.u32(SCRATCH + 0xa060, difference & 0xffffffff)
            p.run(0x4062b0, [0])
            output['catchup'].append({'precision': precision, 'body': body, 'state': {'special': True, 'specialTime': special_time}, 'difficulty': difficulty, 'difference': difference, 'expected': {
                'body': {key: p.float(OBJECT + 0x9c + j * 4) for j, key in enumerate(body)},
                'state': {'special': bool(p.integer(0x503ff8) & 255), 'specialTime': p.float(0x503ffc)}}})
        # Original mesh lookups supplied with two known wheel radii.
        p.uc.mem_map(0x24000000, 0x10000)
        aux = 0x24000000
        p.u32(OBJECT + 0x8c, 4)
        for i in range(4):
            p.u32(OBJECT + 0x64 + 4 * i, i + 1)
            for offset in [0x80, 0x84, 0x88]: p.f32(SCRATCH + 0x4000 + (i + 1) * 0xa9 + offset, 1)
        p.u32(0x6a5f78, aux + 0x8000)
        p.u32(aux + 0x8004, aux + 0x8100)
        p.u32(aux + 0x8104, 0); p.u32(aux + 0x8108, 1)
        p.u32(0x6a5f30, aux + 0x8200)
        p.u32(aux + 0x8200, 0); p.u32(aux + 0x8210, 1)
        p.u32(0x6a5ee0, aux + 0x8300)
        p.u32(0x68021c, aux + 0x9000)
        p.u32(0x680b28, aux + 0xa000)
        p.uc.mem_write(0x494b70, b'\xd9\x05' + struct.pack('<I', aux) + b'\xc2\x08\x00')
        for i in range(120):
            body = {'forwardSpeed': rng.uniform(-15, 90), 'yawRate': rng.uniform(-3, 3), 'y': rng.uniform(-10, 10)}
            for key, address in [('forwardSpeed', OBJECT + 0xa4), ('yawRate', OBJECT + 0xac), ('y', SCRATCH + 0x4054)]:
                p.f32(address, body[key]); body[key] = p.float(address)
            radii = [rng.uniform(2, 6), rng.uniform(2, 6)]
            for j, radius in enumerate(radii):
                p.f32(aux + 0x8314 + j * 0xbc, -radius); radii[j] = -p.float(aux + 0x8314 + j * 0xbc)
            wheels = []
            for j in range(4):
                base = SCRATCH + 0x4000 + (j + 1) * 0xa9
                p.f32(base + 0x74, rng.uniform(-8192, 8192)); p.f32(base + 0x78, 0)
                wheels.append({'spin': p.float(base + 0x74), 'radius': radii[j // 2], 'local': [0, 0, 0], 'steeringAngle': 0})
            height = rng.uniform(-10, 10)
            p.f32(aux, height); height = p.float(aux)
            dt = rng.choice([.001, .025, .03125, .1])
            p.f32(SCRATCH + 0x1000, dt)
            p.run(0x41c4b0, [0])
            output['wheels'].append({'precision': precision, 'body': body, 'wheels': wheels, 'height': height, 'dt': dt, 'expected': [
                {'spin': p.float(SCRATCH + 0x4000 + (j + 1) * 0xa9 + 0x74),
                 'steeringAngle': p.float(SCRATCH + 0x4000 + (j + 1) * 0xa9 + 0x78),
                 'localY': p.float(SCRATCH + 0x4000 + (j + 1) * 0xa9 + 0x54)} for j in range(4)]})
    (ROOT / 'evidence/native/ai-support-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', sum(len(output[k]) for k in ['priority', 'wobble', 'catchup', 'wheels']), 'AI support cases')

if __name__ == '__main__':
    generate()
