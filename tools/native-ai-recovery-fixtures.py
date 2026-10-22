#!/usr/bin/env python3
"""Original recovery state and spring; explicit terrain and respawn boundaries."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_FPCW

def main():
    rng = random.Random(0x40e4b0)
    output = {'routines': ['0x40e4b0', '0x413330'], 'scope': 'Original recovery handler; route plane height explicit and respawn routines recorded/no-op', 'cases': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        initialize_native_trig(p)
        p.u32(0x503ef0, 0); p.u32(0x5081bc, 0); p.u32(0x508610, 4)
        p.u32(0x68021c, SCRATCH + 0xa000); p.u32(SCRATCH + 0xa000, 0)
        p.u32(0x680b28, SCRATCH + 0xa100)
        p.uc.mem_write(0x417e90, b'\x31\xc0\xc3')
        p.uc.mem_write(0x48da90, b'\xc3'); p.uc.mem_write(0x48dc30, b'\xc2\x04\x00')
        p.uc.mem_write(0x4977d0, b'\x31\xc0\xc2\x10\x00') # thiscall(ret16)
        p.uc.mem_write(0x494b70, b'\xd9\x05' + struct.pack('<I', SCRATCH + 0x9200) + b'\xc2\x08\x00')
        p.uc.mem_write(0x48f4d0, b'\xd9\x05' + struct.pack('<I', SCRATCH + 0x9300) + b'\xc3')
        calls = []
        def hook(uc, address, size, data):
            if address in [0x48da90, 0x48dc30]: calls.append(hex(address))
        p.uc.hook_add(UC_HOOK_CODE, hook)
        addresses = {'x': SCRATCH + 0x4050, 'y': SCRATCH + 0x4054, 'z': SCRATCH + 0x4058,
            'yaw': SCRATCH + 0x4078, 'pitch': SCRATCH + 0x4074, 'roll': SCRATCH + 0x407c,
            'forwardSpeed': OBJECT + 0xa4, 'lateralSpeed': OBJECT + 0x9c, 'verticalSpeed': OBJECT + 0xa0,
            'yawRate': OBJECT + 0xac, 'pitchRate': OBJECT + 0xa8, 'rollRate': OBJECT + 0xb0}
        for i in range(180):
            body = {key: rng.uniform(-5, 5) for key in addresses}
            body.update({'yaw': rng.uniform(-4096, 8192), 'forwardSpeed': rng.uniform(-15, 90), 'x': rng.uniform(-100, 100), 'z': rng.uniform(-100, 100)})
            for key, address in addresses.items(): p.f32(address, body[key]); body[key] = p.float(address)
            state = {'mode': 10, 'sectorTime': rng.choice([0, 1.49, 1.5, 2.1]), 'recoveryTime': rng.choice([0, 1.49, 1.5, 2]),
                'lastRecoveryTime': rng.choice([0, 5, 10]), 'recoveryCounter': rng.randrange(-1, 4), 'priorities': [0, 1, 2], 'reactionMode': 3}
            for key, address in [('sectorTime', 0x503f08), ('recoveryTime', 0x503f0c), ('lastRecoveryTime', 0x503ff4)]:
                p.f32(address, state[key]); state[key] = p.float(address)
            p.u32(0x503ef4, 10); p.u32(0x503fc4, state['recoveryCounter'] & 0xffffffff)
            # 0x40d230 passes the embedded controller at503fcc; +4 is cleared.
            p.u32(0x503fd0, 3); p.u32(0x503f8c, i % 2)
            for j, value in enumerate(state['priorities']): p.u32(0x503f7c + j * 4, value)
            controls = {'steering': rng.choice([-100, 0, 100])}; p.f32(0x503f28, controls['steering'])
            dt, time, height = rng.choice([.001, .025, .03125, .1]), rng.choice([1, 5, 10, 15]), rng.uniform(-10, 10)
            p.f32(SCRATCH + 0x1000, dt); p.f32(SCRATCH + 0x9300, time); p.f32(SCRATCH + 0x9200, height); height = p.float(SCRATCH + 0x9200)
            seed = rng.randrange(2 ** 32); p.u32(0x502978, seed); calls = []
            p.run(0x40e4b0, [0])
            counter = p.integer(0x503fc4); counter = counter if counter < 0x80000000 else counter - 0x100000000
            output['cases'].append({'precision': precision, 'body': body, 'state': state, 'controls': controls, 'dt': dt, 'time': time, 'height': height, 'seed': seed,
                'randomState': p.integer(0x502978), 'respawnCalls': calls, 'expected': {
                    'body': {key: p.float(address) for key, address in addresses.items()}, 'controls': {'steering': p.float(0x503f28)},
                    'state': {'mode': p.integer(0x503ef4), 'sectorTime': p.float(0x503f08), 'recoveryTime': p.float(0x503f0c), 'lastRecoveryTime': p.float(0x503ff4),
                        'recoveryCounter': counter, 'priorities': [p.integer(0x503f7c + j * 4) for j in range(3)],
                        'reactionMode': -1 if p.integer(0x503fd0) == 0xffffffff else p.integer(0x503fd0)}}})
        output['sourceSha256'] = p.sha
    (ROOT / 'evidence/native/ai-recovery-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', len(output['cases']), 'native recovery cases')

if __name__ == '__main__': main()
