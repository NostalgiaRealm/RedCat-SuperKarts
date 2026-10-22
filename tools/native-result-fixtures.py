#!/usr/bin/env python3
"""Instruction-level original result records and Delphi high-score operations.

The filesystem, timer service and Delphi reference-counted string assignment are
explicit boundaries. Ranking, shifts, estimates and save decisions run original
x86 instructions. Original files are read only.
"""
import hashlib
import json
import random
import struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH


def signed(x):
    return x if x < 0x80000000 else x - 0x100000000


def cstring(p, address):
    result = bytearray()
    while True:
        value = p.uc.mem_read(address + len(result), 1)[0]
        if not value:
            return result.decode('cp1252')
        result.append(value)


def return_from(p, value=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))


def main():
    rng = random.Random(0x417d00)
    p = NativeProbe(SOURCE)
    out = {'scope': __doc__, 'gameSha256': p.sha, 'finalization': [], 'patches': [], 'highscoreIndex': [], 'highscoreInsert': [], 'timeParts': []}
    p.u32(0x504f98, SCRATCH + 0x3000)
    timer_values, paused, writes = {}, [], {}
    mode = 'finalize'
    image = pefile.PE(str(SOURCE / 'rcskspel.dat'))
    printf_import = next(item.address for group in image.DIRECTORY_ENTRY_IMPORT for item in group.imports if item.name == b'wsprintfA')
    p.u32(printf_import, SCRATCH + 0xb010)

    def hook(uc, address, size, unused):
        sp = uc.reg_read(UC_X86_REG_ESP)
        if address == 0x42a4d0:
            return_from(p, timer_values[p.integer(sp + 4)])
        elif address == 0x42a280:
            paused.append(p.integer(sp + 4)); return_from(p)
        elif mode == 'save':
            if address in [0x4afce0, 0x4b1d60, 0x4513c0, 0x417d00]:
                return_from(p)
            elif address == 0x4521b0:
                return_from(p, p.integer(SCRATCH + 0x7100))
            elif address in [0x4b1e70, 0x4b1e30]:
                section = cstring(p, p.integer(sp + 4)); key = cstring(p, p.integer(sp + 8))
                value = p.integer(sp + 12)
                writes.setdefault(section, {})[key] = signed(value) if address == 0x4b1e70 else cstring(p, value)
                return_from(p)
            elif address in [0x4bea92, SCRATCH + 0xb010]:
                target = p.integer(sp + 4); fmt = cstring(p, p.integer(sp + 8))
                values = tuple(signed(p.integer(sp + 12 + i * 4)) for i in range(fmt.count('%d')))
                result = fmt % values
                p.uc.mem_write(target, result.encode('ascii') + b'\0'); return_from(p, len(result))
    p.uc.hook_add(UC_HOOK_CODE, hook)
    for case in range(360):
        count = case % 5
        sector_count, laps = rng.choice([178, 181, 187]), rng.choice([1, 3, 5])
        player_distance = sector_count * laps + rng.randrange(5)
        opponents = []
        timer_values, paused = {}, []
        trailing = rng.choice([0, 12345, 54321])
        for i in range(count):
            obj = i * 2 + 1
            record = {'objectId': obj, 'finished': bool(rng.randrange(2)),
                      'finishTimeMs': rng.choice([12345, 12346, 54321, rng.randrange(1000, 200000)]),
                      'distance': rng.randrange(1, sector_count * laps + 20), 'carIndex': i, 'rank': i}
            opponents.append(record)
            p.u32(0x503ef0 + i * 0x11c, obj)
            p.u32(OBJECT + obj * 0xd0 + 0x10, i)
            p.u32(SCRATCH + 0x3000 + i * 0x6c + 0x60, record['distance'])
            for offset, value in [(0, record['finishTimeMs']), (8, obj), (12, int(record['finished']))]:
                p.u32(0x5081b4 + i * 0x70 + offset, value)
            timer_values[i + 9] = rng.randrange(1000, 200000)
        p.u32(0x5081b4 + count * 0x70, trailing)
        p.u32(0x508610, count); p.u32(0x53be70, player_distance)
        p.u32(0x680b2c, sector_count); p.u32(0x53ba1c, laps)
        p.run(0x417d00)
        expected = [{**record, 'finishTimeMs': p.integer(0x5081b4 + i * 0x70),
                     'finished': bool(p.integer(0x5081c0 + i * 0x70))} for i, record in enumerate(opponents)]
        out['finalization'].append({'opponents': opponents, 'options': {'playerDistance': player_distance,
            'sectorCount': sector_count, 'lapCount': laps, 'trailingRecordTimeMs': trailing},
            'timerValues': timer_values, 'expected': expected, 'paused': paused})
    mode = 'save'
    for case in range(120):
        count = case % 5
        player = {'carIndex': case % 10, 'rank': case % (count + 1), 'finishTimeMs': rng.randrange(1000, 200000),
                  'bestLapMs': rng.randrange(100, 30000), 'damage': rng.randrange(101), 'stars': rng.randrange(13)}
        opponents = [{'carIndex': i + 1, 'rank': i, 'finishTimeMs': rng.randrange(1000, 200000)} for i in range(count)]
        values = {'finished': bool(case % 3), 'player': player, 'opponents': opponents, 'trackIndex': case % 6,
                  'bestLapRecordMs': rng.randrange(1000, 100000), 'raceRecordMs': rng.randrange(1000, 200000),
                  'timeCheckCount': rng.choice([-1, 0, 1, 5, 9, 10]), 'timeChecks': [rng.randrange(1000, 100000) for _ in range(9)]}
        for address, value in [(0x53be50, int(values['finished'])), (0x53be2c, player['carIndex']), (0x53be60, player['rank']),
            (0x53be58, player['finishTimeMs']), (0x53be5c, player['bestLapMs']), (0x53be30, player['damage']),
            (SCRATCH + 0x7100, player['stars']), (0x508610, count), (0x53b9b4, values['trackIndex']),
            (0x53ba0c, values['bestLapRecordMs']), (0x53ba10, values['raceRecordMs']),
            (0x4ed1c0, values['timeCheckCount'])]:
            p.u32(address, value & 0xffffffff)
        for i, value in enumerate(values['timeChecks']): p.u32(0x53d300 + i * 4, value)
        for i, record in enumerate(opponents):
            for offset, key in [(-4, 'carIndex'), (0, 'finishTimeMs'), (4, 'rank')]:
                p.u32(0x5081b4 + i * 0x70 + offset, record[key])
        writes = {}
        p.run(0x42c4c0)
        out['patches'].append({'input': values, 'expected': writes})

    # Separate Delphi image; register arguments and string-assignment boundary.
    menu = NativeProbe(SOURCE)
    binary = SOURCE / 'rcskmenu.dat'
    pe = pefile.PE(str(binary))
    menu.uc.mem_write(pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image())
    out['menuSha256'] = hashlib.sha256(binary.read_bytes()).hexdigest()
    table, new = SCRATCH + 0x1000, SCRATCH + 0x2000
    def string_hook(uc, address, size, unused):
        if address == 0x403ba4:
            menu.u32(uc.reg_read(UC_X86_REG_EAX), uc.reg_read(UC_X86_REG_EDX))
            return_from(menu)
    menu.uc.hook_add(UC_HOOK_CODE, string_hook)
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        menu.uc.reg_write(UC_X86_REG_FPCW, cw)
        for value in [1, 5, 10, 15, 995, 999, 1000, 1005, 59995, 59999, 60000, 60001, 60005, 120000] + [rng.randrange(1, 10000000) for _ in range(250)]:
            args = struct.unpack('<II', struct.pack('<d', value))
            minutes = menu.run(0x45cae8, args, float_return=True)
            seconds = menu.run(0x45ca84, args, float_return=True)
            menu.run(0x45cb3c, args)
            centiseconds = signed(menu.uc.reg_read(UC_X86_REG_EAX))
            out['timeParts'].append({'milliseconds': value, 'precision': precision,
                'expected': {'minutes': minutes, 'seconds': seconds, 'centiseconds': centiseconds}})
    def write_row(address, row):
        menu.u32(address, row['name'])
        menu.u32(address + 4, row['character'] & 255)
        menu.u32(address + 8, row['totalRaceMs'] & 0xffffffff)
        menu.u32(address + 12, row['bestLapMs'] & 0xffffffff)
        menu.u32(address + 16, row['difficulty'] & 255)
    def read_row(address):
        return {'name': menu.integer(address), 'character': menu.integer(address + 4) & 255,
                'totalRaceMs': signed(menu.integer(address + 8)), 'bestLapMs': signed(menu.integer(address + 12)),
                'difficulty': menu.integer(address + 16) & 255}
    for case in range(500):
        times = sorted(rng.choices([1000, 1000, 2000, 3000, 4000, 10000, 100000], k=5))
        if case % 3 == 0:
            first_empty = rng.randrange(5)
            times[first_empty:] = [0] * (5 - first_empty)
        if case % 40 == 0: times = [-2147483648, -10, 10, 2147483647, 0]
        entries = [{'name': i + 1, 'character': rng.randrange(13), 'totalRaceMs': rng.randrange(1000, 300000),
                    'bestLapMs': times[i], 'difficulty': rng.randrange(3)} for i in range(5)]
        value = rng.choice([0, 999, 1000, 2000, 3000, 9999, 200000, -2147483648, 2147483647])
        for i, row in enumerate(entries): write_row(table + 8 + i * 24, row)
        menu.uc.reg_write(UC_X86_REG_EAX, table); menu.uc.reg_write(UC_X86_REG_EDX, value & 0xffffffff)
        menu.run(0x458a00); expected_index = signed(menu.uc.reg_read(UC_X86_REG_EAX))
        out['highscoreIndex'].append({'entries': entries, 'bestLapMs': value, 'expected': expected_index})
        record = {'name': 100 + case, 'character': case % 13, 'totalRaceMs': rng.randrange(1000, 200000),
                  'bestLapMs': value, 'difficulty': case % 3}
        write_row(new + 4, record)
        index = -1 if case % 2 else case % 5
        menu.uc.reg_write(UC_X86_REG_EAX, table); menu.uc.reg_write(UC_X86_REG_EDX, index & 0xffffffff)
        menu.uc.reg_write(UC_X86_REG_ECX, new); menu.run(0x458a40)
        out['highscoreInsert'].append({'entries': entries, 'record': record, 'index': index,
            'expected': [read_row(table + 8 + i * 24) for i in range(5)]})
    (ROOT / 'evidence/native/result-fixtures.json').write_text(json.dumps(out, indent=2) + '\n')
    print({key: len(out[key]) for key in ['finalization', 'patches', 'highscoreIndex', 'highscoreInsert', 'timeParts']})


if __name__ == '__main__':
    main()
