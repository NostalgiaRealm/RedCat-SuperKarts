#!/usr/bin/env python3
"""Run the original player's audio/trigger/wheel/input dispatch order.

The original caller and keyboard/analog input routines execute in Unicorn.
Audio, ranks, track queries, wheel work, forces and shooting are explicit
boundaries; a supplied speed change at the trigger/fire boundary reveals which
later callbacks see it. This is not a complete native race execution.
"""
import json
import struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX,
                              UC_X86_REG_EBP, UC_X86_REG_EDI, UC_X86_REG_EIP, UC_X86_REG_ESP)
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH, STACK


def main():
    p = NativeProbe(SOURCE)
    pe = pefile.PE(str(SOURCE / 'rcskspel.dat'))
    tick = next(item.address for group in pe.DIRECTORY_ENTRY_IMPORT
                for item in group.imports if item.name == b'GetTickCount')
    p.u32(tick, SCRATCH + 0xb000)
    p.uc.mem_write(SCRATCH + 0xb000, b'\xb8\x60\xea\x00\x00\xc3')  # 60000ms
    names = {0x418c80: 'engine', 0x406be0: 'rank', 0x4938e0: 'triggers',
             0x41b790: 'first-wheels', 0x4517f0: 'fire', 0x414160: 'forces',
             0x41c0b0: 'second-wheels'}
    for address in [*names, 0x4513c0, 0x4273f0, 0x42ef90, 0x4b3830]:
        p.uc.mem_write(address, b'\xc3')
    p.uc.mem_write(0x418c80, b'\xc2\x0c\x00')
    p.uc.mem_write(0x495fe0, b'\xc2\x18\x00')
    p.uc.mem_write(0x496290, b'\xd9\xee\xc2\x14\x00')
    p.u32(0x6a5cd0, SCRATCH + 0x6000)
    p.u32(0x680b28, SCRATCH + 0x8000)
    p.u32(0x53be28, 0)
    p.f32(SCRATCH + 0x1000, .025)
    trace = []
    case = {}

    def hook(uc, address, size, data):
        if address == 0x432b85:  # Inactive branch: stop before string work.
            uc.emu_stop()
        if address == 0x42ef90:
            sp = uc.reg_read(UC_X86_REG_ESP)
            p.u32(p.integer(sp + 12), 75)
            p.u32(p.integer(sp + 16), 100)
            uc.reg_write(UC_X86_REG_EAX, case['buttons'])
        if address == 0x4b3830:
            uc.reg_write(UC_X86_REG_EAX, 0)
        if address not in names:
            return
        trace.append({'stage': names[address], 'forwardSpeed': p.float(OBJECT + 0xa4),
                      'throttle': p.float(0x53bd74), 'brake': p.integer(0x53be04),
                      'steering': p.float(0x53bd70), 'handbrake': bool(p.integer(0x53bdf4))})
        if address == 0x4938e0:
            p.f32(OBJECT + 0xa4, p.float(OBJECT + 0xa4) + case['triggerBoost'])
        if address == 0x4517f0:
            p.f32(OBJECT + 0xa4, p.float(OBJECT + 0xa4) * 1.5)

    p.uc.hook_add(UC_HOOK_CODE, hook)
    output = {'sourceSha256': p.sha, 'callerRange': '0x432ab5..0x432f2b',
              'scope': __doc__.strip(), 'cases': []}
    for input_mode in [1, 2, 3]:
        for active in [False, True]:
            for buttons in [0, 0x34]:  # accelerate, bonus, handbrake
                for trigger_boost in [0, 5]:
                    case = {'inputMode': input_mode, 'active': active,
                            'buttons': buttons, 'triggerBoost': trigger_boost}
                    trace.clear()
                    for address, value in [(0x53be64, 0), (0x53be54, int(active)),
                                           (0x53b9e0, 1), (0x53a5d8, input_mode),
                                           (0x53be1c, 0), (0x53bdf4, 0),
                                           (0x53be04, 0), (SCRATCH + 0x1010, buttons)]:
                        p.u32(address, value)
                    p.f32(OBJECT + 0xa4, 20)
                    p.f32(0x53bd74, 20)
                    p.f32(0x53bd70, 30)
                    for register in [UC_X86_REG_EBX, UC_X86_REG_EBP, UC_X86_REG_EDI]:
                        p.uc.reg_write(register, 0)
                    p.uc.reg_write(UC_X86_REG_ESP, STACK + 0x8000)
                    p.uc.emu_start(0x432ab5, 0x432f2b, count=5000)
                    assert p.uc.reg_read(UC_X86_REG_EIP) == (0x432f2b if active else 0x432b85)
                    output['cases'].append({**case, 'trace': list(trace)})
    path = ROOT / 'evidence/native/player-frame-order-fixtures.json'
    path.write_text(json.dumps(output, indent=2) + '\n')
    print(f'Wrote {len(output["cases"])} original player caller/input traces')


if __name__ == '__main__':
    main()
