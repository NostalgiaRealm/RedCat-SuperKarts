#!/usr/bin/env python3
"""Original INI upgrade stores, later player-construction reset, and timer setup.

Only emulator memory is changed. Filesystem/INI access is a named boundary;
the six loader stores, both Phys-load exits, reset stores, and timer routines
are original shipped instructions. This is not a full Windows startup run.
"""
import hashlib
import json
import struct
from pathlib import Path

import capstone
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_ESI
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, STACK

KEYS = ['motor', 'banden', 'turbo', 'abs', 'versnellingsbak', 'injectie']
GLOBALS = dict(zip(KEYS, range(0x53bef0, 0x53bf08, 4)))


def main():
    p = NativeProbe(SOURCE)
    pe = pefile.PE(str(SOURCE / 'rcskspel.dat'))
    cs = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    cs.detail = True
    cs.skipdata = True
    image = pe.get_memory_mapped_image()
    config = json.loads((ROOT / 'public/assets/config.json').read_text())
    reads, calls = [], []
    values = {}
    fopen_success = True

    def cstring(address):
        return bytes(p.uc.mem_read(address, 128)).split(b'\0')[0].decode('ascii')

    def boundary(uc, address, size, user):
        if address not in [0x4b1d60, 0x4b1ed0, 0x4bf445, 0x4bf930, 0x4bf2c5, 0x4afee0]:
            return
        sp = uc.reg_read(UC_X86_REG_ESP)
        destination = p.integer(sp)
        if address == 0x4b1ed0:
            section, key = cstring(p.integer(sp + 4)), cstring(p.integer(sp + 8))
            assert section == 'PLAYER', section
            result = values.get(key, 0)
            reads.append({'section': section, 'key': key, 'value': result})
        elif address == 0x4bf445:
            result = 1 if fopen_success else 0
        elif address == 0x4bf930:
            assert [p.integer(sp + n) for n in [4, 8, 12]] == [0x505b60, 0xac, 20]
            result = 20
        else:
            result = 0
        calls.append(f'{address:08x}')
        uc.reg_write(UC_X86_REG_EAX, result & 0xffffffff)
        uc.reg_write(UC_X86_REG_ESP, sp + 4)
        uc.reg_write(UC_X86_REG_EIP, destination)

    p.uc.hook_add(UC_HOOK_CODE, boundary)
    output = {
        'sourceSha256': p.sha,
        'scope': 'Instruction boundaries, not a full startup. INI/file/log services are mocked; loader/reset/timer arithmetic are original.',
        'globals': {key: f'{address:08x}' for key, address in GLOBALS.items()},
        'resetBytes': image[0x31ecd:0x31ef1].hex(),
        'boundaries': ['4b1d60 INI filename', '4b1ed0 INI integer', '4bf445 fopen',
                       '4bf930 fread', '4bf2c5 fclose', '4afee0 log'],
        'directCallOrder': {}, 'directWrites': [], 'cases': [], 'timerCases': [],
    }
    for name, begin, end in [
        ('startup', 0x42d7d0, 0x42df90),
        ('config', 0x42ad70, 0x42af0d),
        ('cars', 0x415d70, 0x415dc4),
    ]:
        output['directCallOrder'][name] = [
            {'address': f'{i.address:08x}', 'target': f'{i.operands[0].imm:08x}'}
            for i in cs.disasm(image[begin - 0x400000:end - 0x400000], begin)
            if i.id and i.mnemonic == 'call' and i.operands[0].type == capstone.x86.X86_OP_IMM
        ]
    for section in pe.sections:
        if not section.Characteristics & 0x20000000:
            continue
        for instruction in cs.disasm(section.get_data(), 0x400000 + section.VirtualAddress):
            if not instruction.id:
                continue
            for operand in instruction.operands:
                if (operand.type == capstone.x86.X86_OP_MEM
                        and operand.mem.base == 0 and operand.mem.index == 0
                        and operand.mem.disp in GLOBALS.values()
                        and operand.access & capstone.CS_AC_WRITE):
                    output['directWrites'].append({
                        'address': f'{instruction.address:08x}',
                        'instruction': f'{instruction.mnemonic} {instruction.op_str}',
                        'destination': f'{operand.mem.disp:08x}',
                    })

    # All 64 switch combinations and both successful/missing Phys file exits.
    # Missing input file is only a branch coverage fixture, not a supported run.
    for bits in range(64):
        values = {key: (bits >> index) & 1 for index, key in enumerate(KEYS)}
        for fopen_success in [True, False]:
            reads.clear()
            calls.clear()
            p.run(0x42b870)
            loaded = {key: p.integer(address) for key, address in GLOBALS.items()}
            assert loaded == values
            # Original prolog initializes ESI at431a0f. All intervening calls
            # follow the callee-saved ESI convention. Execute it independently.
            p.uc.reg_write(UC_X86_REG_ESI, 0xdeadbeef)
            p.uc.emu_start(0x431a0f, 0x431a11, count=1)
            assert p.uc.reg_read(UC_X86_REG_ESI) == 0
            # File service path beginning before fopen; both branches converge
            # on the six unconditional stores and stop before sound services.
            p.uc.reg_write(UC_X86_REG_EAX, SCRATCH)
            p.uc.reg_write(UC_X86_REG_ESP, STACK + 0xe000)
            p.uc.emu_start(0x431e85, 0x431ef1, count=100)
            cleared = {key: p.integer(address) for key, address in GLOBALS.items()}
            assert not any(cleared.values())
            output['cases'].append({'loaded': loaded, 'fileExists': fopen_success,
                                    'reads': reads.copy(), 'calls': calls.copy(), 'expected': cleared})

    # Race timer setup happens after the reset. Capture all shipped character,
    # difficulty and country combinations, and compare the old loaded1 premise.
    for track in range(6):
        for difficulty in range(3):
            p.uc.mem_write(0x5068d0, (SOURCE / f'cars{difficulty}.dat').read_bytes())
            for character in range(4):
                gate = int(config['track.ini']['time_gates'][str(track * 3 + difficulty)].split(',')[1])
                lap = int(config['track.ini']['maps'][str(track)].split(',')[10])
                for address, value in [(0x53b9b4, track), (0x53b9f4, difficulty), (0x53be2c, character),
                                       (0x53a4b0, 1), (0x53d2b0, gate), (0x53a730 + track * 0x94, lap)]:
                    p.u32(address, value)
                limits = {}
                for label, enabled in [('loaded', 1), ('afterConstruction', 0)]:
                    for address in GLOBALS.values():
                        p.u32(address, enabled)
                    p.run(0x42d360)
                    limits[label] = {str(timer): p.integer(0x53a270 + timer * 20)
                                     for timer in [0, 8, 18]}
                output['timerCases'].append({
                    'trackIndex': track, 'difficulty': difficulty, 'character': character,
                    'limits': limits,
                })
    for label, path in [
        ('installed', SOURCE / 'race.ini'),
        ('CD', Path('/home/rick/Games/UnpackedISO/RedCat Superkarts/RedCat Superkarts/data/Game/race.ini')),
    ]:
        if path.exists():
            output.setdefault('raceIniInputs', []).append({
                'label': label, 'path': str(path), 'sha256': hashlib.sha256(path.read_bytes()).hexdigest(),
            })
    target = ROOT / 'evidence/native/startup-upgrades.json'
    target.write_text(json.dumps(output, indent=2) + '\n')
    print(f'{len(output["cases"])} original loader/reset paths; {len(output["timerCases"])} timer comparisons; {len(output["directWrites"])} direct stores')


if __name__ == '__main__':
    main()
