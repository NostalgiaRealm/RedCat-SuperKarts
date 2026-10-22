#!/usr/bin/env python3
"""Original NPC proximity/chase guards and ordered transition table."""
import json, random
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW

def main():
    rng = random.Random(0x4024d0)
    output = {'routines': ['0x401570', '0x4016e0', '0x402040', '0x407150', '0x4024d0'], 'behind': [], 'chase': [], 'transition': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        p.uc.mem_write(0x4afce0, b'\xc3')
        p.uc.mem_write(0x417e90, b'\x31\xc0\xc3')
        p.u32(0x503ef0, 0); p.u32(0x508610, 4); p.u32(0x53be28, 1); p.u32(OBJECT + 0xd0 + 0xc, 1)
        output['sourceSha256'] = p.sha
        for i in range(240):
            body = {'x': rng.uniform(-50, 50), 'z': rng.uniform(-50, 50), 'yaw': rng.uniform(-4096, 8192)}
            player = {'id': 1, 'x': rng.uniform(-50, 50), 'z': rng.uniform(-50, 50)}
            for obj, base in [(body, SCRATCH + 0x4000), (player, SCRATCH + 0x4000 + 0xa9)]:
                for key, offset in [('x', 0x50), ('z', 0x58)]:
                    p.f32(base + offset, obj[key]); obj[key] = p.float(base + offset)
            p.f32(SCRATCH + 0x4078, body['yaw']); body['yaw'] = p.float(SCRATCH + 0x4078)
            state = {'chaseTime': rng.choice([0, 1, 1.001, rng.uniform(0, 2)]), 'targetId': -1}
            p.f32(0x503f04, state['chaseTime']); state['chaseTime'] = p.float(0x503f04)
            p.u32(0x503ef8, 0xffffffff)
            rank = i % 3; p.u32(0x5081b8, rank)
            p.run(0x401570, [0])
            output['behind'].append({'precision': precision, 'body': body, 'player': player, 'state': state, 'rank': rank,
                'expected': bool(p.uc.reg_read(UC_X86_REG_EAX)), 'yaw': p.float(SCRATCH + 0x4078),
                'expectedState': {'chaseTime': p.float(0x503f04), 'targetId': 1 if p.integer(0x503ef8) == 1 else -1}})
            speed = rng.choice([0, 29, 30, 70]); p.f32(OBJECT + 0xa4, speed)
            dt = rng.choice([.001, .025, .03125, .1])
            p.f32(SCRATCH + 0x1000, dt); p.f32(0x503f04, state['chaseTime'])
            seed = rng.randrange(2 ** 32); p.u32(0x502978, seed)
            p.run(0x4016e0, [0])
            output['chase'].append({'precision': precision, 'body': {'forwardSpeed': speed}, 'state': state, 'rank': rank, 'dt': dt, 'seed': seed,
                'expected': bool(p.uc.reg_read(UC_X86_REG_EAX)), 'chaseTime': p.float(0x503f04), 'randomState': p.integer(0x502978)})
    p = NativeProbe(SOURCE)
    p.uc.mem_write(0x43b790, b'\xc3')
    p.u32(0x503ef0, 0); p.u32(0x508610, 4)
    for i in range(35):
        p.u32(0x503cc0 + i * 16, 0xffffffff); p.u32(0x503cc4 + i * 16, 0xffffffff)
    p.run(0x407150)
    table = []
    for i in range(35):
        values = [p.integer(0x503cc0 + i * 16 + j * 4) for j in range(4)]
        if values[0] != 0xffffffff: table.append([i, *values[:3], f'{values[3]:x}'])
    output['table'] = table
    guards = {int(row[4], 16) for row in table}
    results, calls = {}, []
    def hook(uc, address, size, data):
        if address not in guards: return
        calls.append(f'{address:x}')
        stack = uc.reg_read(UC_X86_REG_ESP)
        uc.reg_write(UC_X86_REG_EAX, results[address])
        uc.reg_write(UC_X86_REG_EIP, p.integer(stack))
        uc.reg_write(UC_X86_REG_ESP, stack + 4)
    p.uc.hook_add(UC_HOOK_CODE, hook)
    for i in range(400):
        mode = rng.choice([0, 1, 2, 10, 22, 23, 24, 25, 26, 27, 28])
        results = {guard: rng.randrange(2) for guard in guards}; calls = []
        p.u32(0x503ef4, mode)
        p.run(0x4024d0, [0])
        output['transition'].append({'mode': mode, 'guards': {f'{key:x}': value for key, value in results.items()},
            'expected': p.integer(0x503ef4), 'calls': calls})
    (ROOT / 'evidence/native/ai-state-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote', len(output['behind']), 'proximity,', len(output['chase']), 'chase and', len(output['transition']), 'transition cases')

if __name__ == '__main__': main()
