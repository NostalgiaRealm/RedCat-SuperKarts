#!/usr/bin/env python3
"""Capture CarSound original instructions at their sound-service boundary."""
import json
import random
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT


class EngineProbe(NativeProbe):
    def __init__(self):
        super().__init__(SOURCE)
        self.commands = []
        self.selected = None
        self.start_playing = False
        self.config = json.loads((ROOT / 'public/assets/config.json').read_text())['car_snd.ini']['car0']
        self.events = dict(enumerate([self.config[key] for key in ['start', 'switchgear', 'geara', 'gearb', 'stat']]))
        self.uc.mem_write(0x492fe0, b'\xc3')  # assertions
        self.uc.mem_write(0x49dd20, b'\xb8' + struct.pack('<I', SCRATCH + 0x5000) + b'\xc2\x04\x00')
        for address in [0x49d780, 0x49d5e0, 0x49d4d0]:
            self.uc.mem_write(address, b'\xc2\x04\x00')
        self.uc.mem_write(0x49d7a0, b'\xc3')
        self.uc.mem_write(0x49d870, b'\xc3')
        self.uc.mem_write(SCRATCH + 0x6000, b'\x31\xc0\xc3')
        self.u32(OBJECT, 6)
        self.u32(OBJECT + 8, 0)
        self.u32(OBJECT + 12, 1)
        self.u32(OBJECT + 0x14, SCRATCH + 0x2000)
        self.u32(OBJECT + 0x18, int(self.config['maxrpm']))
        self.u32(OBJECT + 0x48, SCRATCH + 0x6100)
        self.u32(SCRATCH + 0x6100, SCRATCH + 0x6000)
        for i, key in enumerate(['geara', 'gearb', 'stat']):
            self.u32(OBJECT + 0x24 + i * 12, 2 + i)
            self.u32(OBJECT + 0x2c + i * 12, SCRATCH + 0x3000 + i * 16)
            self.u32(SCRATCH + 0x3004 + i * 16, SCRATCH + 0x4000 + i * 0x100)
            for gear in range(6):
                values = list(map(int, self.config[f'{key}{gear}'].split(',')))
                self.uc.mem_write(SCRATCH + 0x4000 + i * 0x100 + gear * 16, struct.pack('<4i', *values))
        self.uc.hook_add(UC_HOOK_CODE, self.capture)

    def capture(self, uc, address, size, _):
        if address not in [0x49dd20, 0x49d870, 0x49d780, 0x49d7a0, 0x49d5e0, 0x49d4d0]:
            return
        sp = uc.reg_read(UC_X86_REG_ESP)
        value = self.integer(sp + 4)
        if address == 0x49dd20:
            self.selected = value
        elif address == 0x49d870:
            uc.reg_write(UC_X86_REG_EAX, int(self.selected == 0 and self.start_playing))
        else:
            command = {'event': self.events[self.selected]}
            if address == 0x49d780:
                command.update(op='play', loop=bool(value))
            elif address == 0x49d7a0:
                command['op'] = 'stop'
            elif address == 0x49d5e0:
                command.update(op='pitch', percent=struct.unpack('<i', struct.pack('<I', value))[0])
            elif address == 0x49d4d0:
                command.update(op='volume', percent=value)
            self.commands.append(command)

    def reset(self):
        self.u32(OBJECT + 4, 0)
        self.u32(OBJECT + 0x10, 0xffffffff)
        self.uc.mem_write(SCRATCH + 0x2000, struct.pack('<6i', 800, -1, -1, -1, -1, -1))

    def call(self, address, args=()):
        self.commands = []
        self.uc.reg_write(UC_X86_REG_ECX, OBJECT)
        self.run(address, args)
        assert self.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        return self.commands.copy()

    def state(self):
        return {'active': bool(self.integer(OBJECT + 4)),
                'gear': struct.unpack('<i', self.uc.mem_read(OBJECT + 0x10, 4))[0],
                'minimumRpm': list(struct.unpack('<6i', self.uc.mem_read(SCRATCH + 0x2000, 24)))}


def main():
    p = EngineProbe()
    traces = []
    for precision in [24, 53]:
        p.uc.reg_write(UC_X86_REG_FPCW, 0x007f if precision == 24 else 0x027f)
        p.reset()
        start = p.call(0x418950)
        frames = []
        rng = random.Random(2000)
        for tick in range(180):
            gear = min(5, tick // 16) if tick < 96 else rng.randrange(6)
            rpm = [0, 799, 800, 801, 1600, 2400, 4000, 7999, 8000, 9000][tick % 10]
            p.start_playing = tick < 4
            inputs = {'gear': gear, 'rpm': rpm, 'startPlaying': p.start_playing}
            commands = p.call(0x418c80, [gear, rpm])
            frames.append({'input': inputs, 'commands': commands, 'state': p.state()})
        stop = p.call(0x418980)
        traces.append({'precision': precision, 'start': start, 'frames': frames, 'stop': stop, 'stateAfterStop': p.state()})
    volumes = []
    p.uc.mem_write(0x49f250, b'\xc3')
    for volume in range(101):
        p.run(0x49d520, [volume])
        value = p.uc.reg_read(UC_X86_REG_EAX)
        volumes.append({'percent': volume, 'hundredthDb': struct.unpack('<i', struct.pack('<I', value))[0]})
    target = ROOT / 'evidence/native/engine-audio-fixtures.json'
    target.write_text(json.dumps({'format': 'superkarts-native-engine-audio-v1', 'sha256': p.sha,
        'method': 'Original 418950/418c80/418980 and interpolation instructions; sound output/status are captured services and shipped Car_Snd.ini rows are loaded verbatim.',
        'traces': traces, 'volumes': volumes}, indent=2) + '\n')
    print(f'Wrote {sum(len(trace["frames"]) for trace in traces)} engine frames and {len(volumes)} volume conversions')


if __name__ == '__main__':
    main()
