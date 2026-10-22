#!/usr/bin/env python3
"""Original race timer operations and inactive-player stores, instruction probes."""
import json, random, struct
import pefile
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH, STACK
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ESP, UC_X86_REG_FPCW

def main():
    p = NativeProbe(SOURCE)
    image = pefile.PE(str(SOURCE / 'rcskspel.dat'))
    tick_import = next(item.address for group in image.DIRECTORY_ENTRY_IMPORT for item in group.imports if item.name == b'GetTickCount')
    p.u32(tick_import, SCRATCH + 0xb000)
    p.uc.mem_write(SCRATCH + 0xb000, b'\xa1' + struct.pack('<I', SCRATCH + 0xb100) + b'\xc3')
    p.u32(0x53be28, 0)
    rng = random.Random(0x42a4d0)
    output = {'sourceSha256': p.sha, 'routines': ['0x42a210', '0x42a280', '0x42a2f0',
        '0x42a420', '0x42a4d0', '0x42a5d0', '0x42a670', '0x42a700', '0x432b85..0x432c09'],
        'timers': [], 'inactive': [], 'setup': []}
    addresses = {'start': 0x42a210, 'pause': 0x42a280, 'resume': 0x42a420, 'setLimit': 0x42a5d0}
    for case in range(240):
        index, limit, countdown = case % 28, rng.choice([0, 500, 5000, 0xfffffff]), bool(case % 2)
        p.run(0x42a670, [index, limit, int(countdown)])
        now = rng.choice([0, 1, 100000, 0xfffff000, 0xfffffffe])
        trace = []
        for step in range(12):
            now = (now + rng.choice([0, 1, 20, 500, 5001])) & 0xffffffff
            p.u32(SCRATCH + 0xb100, now)
            operation = 'read' if step == 0 else rng.choice(['start', 'pause', 'resume', 'setLimit', 'read'])
            args = [index]
            value = rng.choice([0, 100, 9000, 0xfffffff])
            if operation == 'setLimit': args.append(value)
            if operation != 'read': p.run(addresses[operation], args)
            p.run(0x42a4d0, [index])
            read = p.uc.reg_read(UC_X86_REG_EAX)
            if read > 0x7fffffff: read -= 0x100000000
            p.run(0x42a700, [index])
            base = 0x53a270 + index * 20
            trace.append({'operation': operation, 'nowMs': now, 'value': value, 'read': read,
                'expired': bool(p.uc.reg_read(UC_X86_REG_EAX) & 0xff),
                'state': {'limitMs': p.integer(base), 'startMs': p.integer(base + 4),
                    'countdown': bool(p.integer(base + 8)), 'pausedAtMs': p.integer(base + 16)}})
        output['timers'].append({'index': index, 'limitMs': limit, 'countdown': countdown, 'trace': trace})
    body_offsets = {'lateralSpeed': 0x9c, 'verticalSpeed': 0xa0, 'forwardSpeed': 0xa4,
        'pitchRate': 0xa8, 'yawRate': 0xac, 'rollRate': 0xb0}
    for case in range(80):
        body = {}
        for key, offset in body_offsets.items():
            p.f32(OBJECT + offset, rng.uniform(-30, 60)); body[key] = p.float(OBJECT + offset)
        p.f32(0x507290, rng.uniform(0, 6000))
        p.u32(0x50728c, case % 2)
        rpm = p.float(0x507290)
        # Execute exactly the original reset block; stop before animation string work.
        p.uc.reg_write(UC_X86_REG_EBX, 0)
        p.uc.reg_write(UC_X86_REG_ESP, STACK + 0xe000)
        p.uc.emu_start(0x432b85, 0x432c0a, count=100)
        output['inactive'].append({'body': body, 'rpm': rpm, 'lowSpeedTurn': bool(case % 2),
            'expected': {'body': {key: p.float(OBJECT + offset) for key, offset in body_offsets.items()},
                'rpm': p.float(0x507290), 'lowSpeedTurn': bool(p.integer(0x50728c))}})
    config = json.loads((ROOT / 'public/assets/config.json').read_text())
    def timers():
        result = []
        for index in range(28):
            base = 0x53a270 + index * 20
            result.append(None if not p.integer(base + 12) else {
                'limitMs': p.integer(base), 'startMs': p.integer(base + 4),
                'countdown': bool(p.integer(base + 8)), 'pausedAtMs': p.integer(base + 16)})
        return result
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        for track in range(6):
            for difficulty in range(3):
                p.uc.mem_write(0x5068d0, (SOURCE / f'cars{difficulty}.dat').read_bytes())
                for character in range(4):
                    for upgrades in range(4):
                        p.uc.mem_write(0x53a270, bytes(28 * 20))
                        race_type = (track + character) % 2
                        gate = int(config['track.ini']['time_gates'][str(track * 3 + difficulty)].split(',')[1])
                        lap = int(config['track.ini']['maps'][str(track)].split(',')[10])
                        for address, value in [(0x53b9b4, track), (0x53b9f4, difficulty), (0x53be2c, character),
                            (0x53a4b0, race_type), (0x53bef0, upgrades & 1), (0x53bf00, upgrades >> 1),
                            (0x53d2b0, gate), (0x53a730 + track * 0x94, lap), (0x508610, 4)]:
                            p.u32(address, value)
                        p.run(0x42d360); p.run(0x435670); p.run(0x417dd0)
                        initialized = timers()
                        p.u32(SCRATCH + 0xb100, 12345); p.run(0x42f980)
                        output['setup'].append({'precision': precision, 'trackIndex': track, 'difficulty': difficulty,
                            'character': character, 'raceType': race_type, 'motorUpgrade': bool(upgrades & 1),
                            'gearboxUpgrade': bool(upgrades >> 1), 'opponentCount': 4,
                            'initialized': initialized, 'started': timers()})
    (ROOT / 'evidence/native/game-timer-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Wrote 2880 original timer operations, 80 inactive-player resets and', len(output['setup']), 'race initializations')

if __name__ == '__main__': main()
