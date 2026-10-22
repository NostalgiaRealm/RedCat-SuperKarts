#!/usr/bin/env python3
"""Original menu adventure progression, qualification, unlock and reset probes.

0x472cfc and 0x472fe0 execute their original decision/store paths. INI result
reads, dialogs, sound and reference-counted strings are explicit boundaries.
"""
import json
import random
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH


def return_from(p, value=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))


def main():
    rng = random.Random(0x472cfc)
    p = NativeProbe(SOURCE)
    p.uc.mem_map(0, 0x1000)
    pe = pefile.PE(str(SOURCE / 'rcskmenu.dat'))
    p.uc.mem_write(0x400000, pe.get_memory_mapped_image())
    app, profile, matrix, sequence, locks, form = [SCRATCH + offset for offset in [0x1000, 0x2000, 0x3000, 0x4000, 0x5000, 0x6000]]
    dialog, vtable, stub = SCRATCH + 0x8000, SCRATCH + 0x9000, SCRATCH + 0xa000
    p.u32(p.integer(0x47c670), app)
    p.u32(app + 0x80, profile); p.u32(app + 0x90, sequence); p.u32(app + 0x94, locks)
    p.u32(profile + 0x18, matrix)
    p.u32(dialog, vtable); p.u32(vtable + 0xd8, stub); p.uc.mem_write(stub, b'\xc3')
    result = {}
    events = []
    gate_mode = None
    movie_key = None
    def hook(uc, address, size, unused):
        nonlocal movie_key
        eax, edx = uc.reg_read(UC_X86_REG_EAX), uc.reg_read(UC_X86_REG_EDX)
        if address == 0x45bba8 and gate_mode is not None:
            return_from(p, gate_mode)
        elif address in [0x471c70, 0x473158, 0x457b34, 0x457918, 0x42eb18] and gate_mode is not None:
            events.append({0x471c70: 'highscore', 0x473158: 'win-movie',
                           0x457b34: 'profile-save', 0x457918: 'quickrace-save',
                           0x42eb18: 'close-debrief'}[address])
            return_from(p)
        elif address == 0x470c4c:
            # The original constructor selects its key from the character table.
            # INI reading and media creation remain explicit API boundaries.
            movie_key = bytes(p.uc.mem_read(edx, 64)).split(b'\0')[0].decode('latin1')
            p.u32(uc.reg_read(UC_X86_REG_ECX), 0)
            return_from(p)
        elif address == 0x407ca8:
            p.u32(edx, 0); return_from(p)
        elif address == 0x4040bc:
            return_from(p, 0)  # Shipped WINMOVIES are MPG, none contains BMP.
        elif address in [0x403ba4, 0x470b50]:
            return_from(p)
        elif address in [0x45c4c8, 0x45c4f0, 0x407f60]:
            p.u32(edx, 0); return_from(p)
        elif address == 0x403e90:
            p.u32(eax, 0)
            sp = uc.reg_read(UC_X86_REG_ESP)
            uc.reg_write(UC_X86_REG_ESP, sp + 4 + edx * 4)
            uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
        elif address == 0x403b50:
            p.u32(eax, 0); return_from(p)
        elif address in [0x403b74, 0x460df0, 0x460d08, 0x402eac,
                          0x460b88, 0x460be8, 0x460cb8, 0x45c5cc]:
            return_from(p)
        elif address in [0x473204, 0x473298, 0x473244]:
            events.append(hex(address)); return_from(p)
        elif address == 0x472c1c:
            return_from(p, int(result['finished']))
        elif address == 0x472f00:
            return_from(p, result['stars'])
        elif address == 0x460a40:
            return_from(p, dialog)
    p.uc.hook_add(UC_HOOK_CODE, hook)
    def put_profile(state):
        p.u32(profile + 0xc, 999); p.u32(profile + 0x14, state['adventure'])
        for offset, key in [(0x10, 'difficulty'), (0x22, 'character'), (0x23, 'carType'),
                            (0x24, 'raceType'), (0x25, 'country'), (0x26, 'completed')]:
            p.uc.mem_write(profile + offset, bytes([state[key]]))
        p.uc.mem_write(matrix + 4, bytes(value for row in state['matrix'] for value in row))
    def get_profile(state):
        updated = {**state, 'adventure': p.integer(profile + 0x14)}
        for offset, key in [(0x10, 'difficulty'), (0x22, 'character'), (0x23, 'carType'),
                            (0x24, 'raceType'), (0x25, 'country'), (0x26, 'completed')]:
            value = p.uc.mem_read(profile + offset, 1)[0]
            updated[key] = bool(value) if key == 'completed' else value
        raw = list(p.uc.mem_read(matrix + 4, 30))
        updated['matrix'] = [raw[i * 5:(i + 1) * 5] for i in range(6)]
        return updated
    out = {'scope': __doc__, 'progression': [], 'resets': [], 'replays': [], 'random': [],
           'nextIndex': [], 'slots': [], 'winMovieGate': [], 'winMovieKeys': []}
    for case in range(960):
        current = rng.randrange(24)
        state = {'name': 'native', 'slot': case % 30, 'difficulty': case % 3, 'adventure': current,
                 'character': case % 4, 'carType': case % 2, 'raceType': case % 5, 'country': case % 6,
                 'completed': bool(case % 2),
                 'matrix': [[rng.choice([0, 1]) if case % 4 else 1 for _ in range(5)] for _ in range(6)]}
        result = {'rank': rng.choice([-1, 0, 1, 2, 3, 4, 5]), 'finished': bool(case % 2),
                  'stars': rng.choice([0, 11, 12, 13])}
        lock_values = [bool(rng.randrange(2)) for _ in range(6)]
        required = [bool(rng.randrange(2)) for _ in range(5)]
        unlocks = [rng.randrange(6) for _ in range(5)]
        put_profile(state)
        p.u32(sequence + 0x40, current); p.u32(sequence + 0x44, 24)
        p.u32(form + 0x330, result['rank'] & 0xffffffff); p.u32(form + 0x33c, 0)
        p.uc.mem_write(locks + 4, bytes(lock_values)); p.uc.mem_write(locks + 10, bytes(unlocks))
        p.uc.mem_write(locks + 15, bytes(required))
        events = []
        p.uc.reg_write(UC_X86_REG_EAX, form); p.run(0x472cfc)
        advanced = p.integer(sequence + 0x40) != current or bool(p.uc.mem_read(form + 0x33c, 1)[0])
        completed = bool(p.uc.mem_read(form + 0x33c, 1)[0])
        p.run(0x472fe0)
        out['progression'].append({'profile': state, 'result': result,
            'options': {'sequence': [None] * 24, 'locks': lock_values,
                        'requiredTypes': required, 'unlockCountries': unlocks},
            'expectedProfile': get_profile(state), 'expectedLocks': [bool(x) for x in p.uc.mem_read(locks + 4, 6)],
            'expectedAdvanced': advanced, 'expectedCompleted': completed, 'events': events})
    for case in range(80):
        state = {'name': 'native', 'slot': case % 30, 'difficulty': case % 3, 'adventure': case % 24,
                 'character': case % 4, 'carType': case % 2, 'raceType': case % 5, 'country': case % 6,
                 'completed': bool(case % 2), 'matrix': [[1] * 5 for _ in range(6)]}
        put_profile(state); p.uc.reg_write(UC_X86_REG_EAX, profile); p.run(0x45aa5c)
        out['resets'].append({'profile': state, 'expected': {**get_profile(state), 'name': ''}})
        put_profile(state); p.uc.reg_write(UC_X86_REG_EAX, profile); p.run(0x45a184)
        out['replays'].append({'profile': state, 'expected': get_profile(state)})
    for seed in [0, 1, 86399999, 0xffffffff]:
        p.u32(0x47d044, seed)
        for index in range(32):
            upper = [2, 3, 0x7fffffff, 0xffffffff][index % 4]
            before = p.integer(0x47d044)
            p.uc.reg_write(UC_X86_REG_EAX, upper); p.run(0x402b74)
            out['random'].append({'seed': before, 'upper': upper,
                                  'expected': p.uc.reg_read(UC_X86_REG_EAX), 'nextSeed': p.integer(0x47d044)})
    for current in [-2, -1, 0, 22, 23, 28, 29, 30, 2147483647]:
        for count in [0, 1, 24, 30, 31]:
            p.u32(sequence + 0x40, current & 0xffffffff); p.u32(sequence + 0x44, count)
            p.uc.reg_write(UC_X86_REG_EAX, sequence); p.run(0x458468)
            value = p.uc.reg_read(UC_X86_REG_EAX)
            if value >= 0x80000000: value -= 0x100000000
            out['nextIndex'].append({'current': current, 'count': count, 'expected': value})
    for case in range(120):
        occupied = [rng.choice([0, 1]) if case % 3 else int(case % 2) for _ in range(30)]
        trailing = case % 3
        current = rng.randrange(30)
        p.uc.mem_write(sequence + 12, bytes(occupied + [trailing]))
        results = {}
        for action, address in [('new', 0x457c50), ('first', 0x457c6c), ('next', 0x457c88), ('previous', 0x457cac)]:
            p.uc.reg_write(UC_X86_REG_EAX, sequence); p.uc.reg_write(UC_X86_REG_EDX, current)
            p.run(address); value = p.uc.reg_read(UC_X86_REG_EAX)
            results[action] = value if value < 0x80000000 else value - 0x100000000
        out['slots'].append({'occupied': occupied, 'trailingByte': trailing, 'current': current, 'expected': results})
    # Execute the full original debrief result gate. Progression/qualification/
    # unlock code remains native; only external dialogs, highscore and media
    # work are stubs. This distinguishes a race/type win from campaign end.
    for mode in [0, 1, 2, 3, 4]:
        for character in range(4):
            for current in [0, 5, 11, 17, 22, 23]:
                for qualifies in [False, True]:
                    gate_mode = mode
                    state = {'name': 'native', 'slot': 0, 'difficulty': 2,
                             'adventure': current, 'character': character, 'carType': 0,
                             'raceType': current // 6, 'country': 0, 'completed': False,
                             'matrix': [[1] * 5 for _ in range(6)]}
                    result = {'rank': 0 if qualifies else 4, 'finished': True, 'stars': 12}
                    put_profile(state)
                    p.u32(sequence + 0x40, current); p.u32(sequence + 0x44, 24)
                    p.u32(form + 0x330, result['rank']); p.u32(form + 0x33c, 0)
                    p.uc.mem_write(locks + 4, bytes([1] * 6))
                    p.uc.mem_write(locks + 10, bytes([4, 3, 2, 5, 0]))
                    p.uc.mem_write(locks + 15, bytes([1, 1, 1, 1, 0]))
                    events = []
                    p.uc.reg_write(UC_X86_REG_EAX, form); p.run(0x471bc0)
                    out['winMovieGate'].append({'mode': mode, 'profile': state,
                        'result': result, 'events': events, 'expectedMovie': 'win-movie' in events,
                        'completed': bool(p.uc.mem_read(form + 0x33c, 1)[0]),
                        'nextPhase': p.uc.mem_read(form + 0x2d4, 1)[0]})
    gate_mode = None
    for character in range(4):
        p.uc.mem_write(profile + 0x22, bytes([character]))
        movie_key = None
        p.uc.reg_write(UC_X86_REG_EAX, form); p.run(0x470a7c)
        out['winMovieKeys'].append({'character': character, 'key': movie_key,
                                   'isMovie': bool(p.uc.mem_read(form + 0x2ec, 1)[0])})
    (ROOT / 'evidence/native/adventure-fixtures.json').write_text(json.dumps(out, indent=2) + '\n')
    print({key: len(out[key]) for key in ['progression', 'resets', 'replays', 'random', 'nextIndex', 'slots', 'winMovieGate', 'winMovieKeys']})


if __name__ == '__main__':
    main()
