#!/usr/bin/env python3
"""Execute complete original HUD enter/leave, retaining cached and actual states."""
import itertools
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT


def constructor_cases():
    """Original manager construction/projection, replacing allocation only."""
    p = NativeProbe(SOURCE)
    p.uc.mem_map(0, 4096)
    p.uc.mem_write(0x4be7ee, b'\xc3')
    cursor = SCRATCH + 0x9000

    def allocate(uc, address, size, unused):
        nonlocal cursor
        if address == 0x4be7ee:
            uc.reg_write(UC_X86_REG_EAX, cursor)
            cursor += 0x100

    p.uc.hook_add(UC_HOOK_CODE, allocate)
    output = []
    for value in [0, 1, 0xa5, 0xff]:
        p.uc.mem_write(OBJECT, bytes([value]) * 0x100)
        p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
        p.run(0x467a60)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        after_constructor = list(p.uc.mem_read(OBJECT + 0x88, 2))
        p.run(0x4604c0)
        p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
        p.run(0x462770)
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        after_projection = list(p.uc.mem_read(OBJECT + 0x88, 2))
        output.append({'before': value, 'afterConstructor': {
            'filter': after_constructor[0], 'hardware': after_constructor[1]},
            'afterProjection': {'filter': after_projection[0], 'hardware': after_projection[1]}})
    return output


def main():
    p = NativeProbe(SOURCE)
    context, device, vtable = SCRATCH + 0x3000, SCRATCH + 0x4000, SCRATCH + 0x5000
    get_state, set_state, set_transform = [SCRATCH + 0x6000 + i * 0x10 for i in range(3)]
    args = [SCRATCH + 0x7000 + i * 0x100 for i in range(4)]
    p.u32(0x6a621c, device)
    p.u32(device, vtable)
    for offset, address in [(0x58, get_state), (0x5c, set_state), (0x68, set_transform)]:
        p.u32(vtable + offset, address)
        p.uc.mem_write(address, b'\x31\xc0\xc2\x0c\x00')
    p.u32(0x6a6290, SCRATCH + 0x8000)
    p.u32(0x4fd9fc, 0)
    p.u32(SCRATCH + 0x8000, SCRATCH + 0x8100)
    p.u32(0x6a5e80, SCRATCH + 0x8200)
    p.u32(0x6a6254, 0)
    states, events = {}, []

    def hook(uc, address, size, unused):
        if address not in [get_state, set_state, set_transform]:
            return
        sp = uc.reg_read(UC_X86_REG_ESP)
        state, value = p.integer(sp + 8), p.integer(sp + 12)
        if address == get_state:
            p.u32(value, states.get(state, 0))
            events.append(['get', state, states.get(state, 0)])
        elif address == set_state:
            states[state] = value
            events.append(['set', state, value])
        else:
            events.append(['transform', state])

    p.uc.hook_add(UC_HOOK_CODE, hook)
    output = {'sourceSha256': p.sha, 'scope': __doc__,
              'constructorCases': constructor_cases(), 'traces': []}
    for cached, minimum, maximum, hud_filter, hardware in itertools.product(
            [0, 1, 2], [1, 2], [1, 2], [0, 1], [0, 1]):
        p.u32(0x6a6274, cached)
        p.u32(0x6a625c, 1)
        p.uc.mem_write(context + 0x88, bytes([hud_filter, hardware]))
        states.clear()
        states.update({17: minimum, 18: maximum, 19: 2, 20: 1})
        trace = {'cached': cached, 'min': minimum, 'mag': maximum,
                 'hudFilterByte': hud_filter, 'hardware': bool(hardware), 'frames': []}
        for frame in range(3):
            events.clear()
            p.uc.reg_write(UC_X86_REG_ECX, context)
            p.run(0x462320, args)
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            draw = {'min': states[17], 'mag': states[18], 'source': states[19],
                    'destination': states[20], 'cached': p.integer(0x6a6274),
                    'events': list(events)}
            events.clear()
            p.uc.reg_write(UC_X86_REG_ECX, context)
            p.run(0x462610, args)
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            trace['frames'].append({'draw': draw, 'after': {'min': states[17], 'mag': states[18],
                'cached': p.integer(0x6a6274), 'source': states[19], 'destination': states[20],
                'events': list(events)}})
        output['traces'].append(trace)
    (ROOT / 'evidence/native/hud-sampler-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    for row in output['traces']:
        if row['hardware'] and row['min'] == row['mag'] and row['cached'] in [0, 2]:
            print({key: row[key] for key in ['cached', 'min', 'hudFilterByte']},
                  'draw', [(f['draw']['min'], f['draw']['mag']) for f in row['frames']])
    print('Executed', len(output['traces']) * 3, 'complete original HUD enter/leave pairs.')


if __name__ == '__main__':
    main()
