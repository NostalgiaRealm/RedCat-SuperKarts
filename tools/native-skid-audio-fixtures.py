#!/usr/bin/env python3
"""Execute original tyre-loop controller with captured sound service calls."""
import importlib.util
import itertools
import json
import struct
from unicorn.x86_const import UC_X86_REG_EAX
from generate_native_gameplay_fixtures import ROOT, SCRATCH

module = importlib.util.spec_from_file_location('engine_probe', ROOT / 'tools/native-engine-audio-fixtures.py')
engine = importlib.util.module_from_spec(module)
module.loader.exec_module(engine)


class SkidProbe(engine.EngineProbe):
    def __init__(self):
        super().__init__()
        self.events = {0: 'SLIP'}
        self.u32(0x53badc, 0)
        self.uc.mem_write(0x4371f0, b'\xb8' + struct.pack('<I', SCRATCH + 0x7000) + b'\xc3')

    def capture(self, uc, address, size, data):
        if address == 0x49d870:
            uc.reg_write(UC_X86_REG_EAX, int(self.playing))
        else:
            super().capture(uc, address, size, data)


def main():
    p = SkidProbe()
    rows = []
    for enabled, contact, slip, playing, controller in itertools.product([False, True], [False, True], range(11), [False, True], [False, True]):
        p.u32(0x4e7bf4, int(enabled))
        p.uc.mem_write(0x4e0d14, bytes([int(contact)]))
        p.u32(0x50728c, slip)
        p.uc.mem_write(SCRATCH + 0x7000, bytes([int(controller)]))
        p.playing = playing
        rows.append({'input': {'soundEnabled': enabled, 'playerContact': contact, 'slipMagnitude': slip,
                              'playing': playing, 'controllerEnabled': controller},
                     'commands': p.call(0x432190)})
    target = ROOT / 'evidence/native/skid-audio-fixtures.json'
    target.write_text(json.dumps({'format': 'superkarts-native-skid-audio-v1', 'sha256': p.sha,
        'method': 'Original 00432190 instructions with unchanged global gate 00429050 and controller flag getter 00437550. Only singleton lookup and DirectSound services are stubbed.',
        'rows': rows}, indent=2) + '\n')
    print(f'Wrote {len(rows)} original tyre-loop decisions')


if __name__ == '__main__':
    main()
