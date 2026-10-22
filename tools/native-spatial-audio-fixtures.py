#!/usr/bin/env python3
"""Original spatial mixer instructions; only the DirectSound boundary is stubbed."""
import json
import random
import struct
import itertools
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig


class SpatialProbe(NativeProbe):
    def __init__(self):
        super().__init__(SOURCE)
        self.commands = []
        self.playing = False
        self.uc.mem_write(0x49f2a0, b'\xc3')
        for address in [0x49d780, 0x49d650, 0x49d5e0]:
            self.uc.mem_write(address, b'\xc2\x04\x00')
        for address in [0x49d7a0, 0x49d570, 0x49d870]:
            self.uc.mem_write(address, b'\xc3')
        self.uc.hook_add(UC_HOOK_CODE, self.capture)
        self.u32(OBJECT + 0x54, 0x53bf78)

    def capture(self, uc, address, size, _):
        if address == 0x49d870:
            uc.reg_write(UC_X86_REG_EAX, int(self.playing))
        elif address in [0x49d780, 0x49d650, 0x49d5e0, 0x49d7a0, 0x49d570]:
            value = struct.unpack('<i', uc.mem_read(uc.reg_read(UC_X86_REG_ESP) + 4, 4))[0]
            if address == 0x49d780:
                self.commands.append({'op': 'play', 'loop': bool(value)})
            elif address == 0x49d7a0:
                self.commands.append({'op': 'stop'})
            elif address == 0x49d570:
                self.commands.append({'op': 'volume', 'percent': self.integer(OBJECT + 0x48)})
            elif address == 0x49d650:
                self.commands.append({'op': 'pan', 'hundredthDb': value})
            elif address == 0x49d5e0:
                self.commands.append({'op': 'pitch', 'percent': value})

    def call(self, inputs):
        self.commands = []
        self.playing = inputs['playing']
        for offset, value in [(0xc, inputs['range']), (0x10, inputs['baseVolume']), (0x14, inputs['doppler'])]:
            self.u32(OBJECT + offset, value)
        for offset, name in [(0x254, 'listenerPosition'), (0x244, 'listenerForward'), (0x264, 'listenerVelocity')]:
            self.uc.mem_write(0x53bf78 + offset, struct.pack('<3f', *inputs[name]))
        args = [struct.unpack('<I', struct.pack('<f', x))[0] for x in inputs['position'] + inputs['velocity']]
        self.uc.reg_write(UC_X86_REG_ECX, OBJECT)
        self.run(0x49da60, [*args, int(inputs['loop'])])
        assert self.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        return self.commands.copy()


def main():
    p = SpatialProbe()
    rows = []
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        rng = random.Random(4960)
        for index in range(350):
            inputs = {'precision': precision, 'playing': bool(index % 2), 'loop': bool(index % 3),
                      'range': [500, 1500, 1, 750][index % 4], 'baseVolume': [0, 50, 80, 100][index % 4],
                      'doppler': [0, 5, 20, 40][index % 4],
                      'listenerPosition': [0, 0, 0], 'listenerForward': [0, 0, 1],
                      'listenerVelocity': [rng.uniform(-300, 300), 0, rng.uniform(-300, 300)],
                      'velocity': [rng.uniform(-300, 300), 0, rng.uniform(-300, 300)]}
            if index < 20:
                inputs['position'] = [[0, 0, 0], [500, 0, 0], [499.999, 0, 0],
                                      [-1, 0, 0], [1, 0, 0], [0, 0, 1],
                                      [0, 1, 0], [50, 0, 80], [-50, 0, 80],
                                      [1, 1, 1]][index % 10]
            else:
                inputs['position'] = [rng.uniform(-600, 600) for _ in range(3)]
                inputs['listenerPosition'] = [rng.uniform(-100, 100) for _ in range(3)]
                direction = [rng.uniform(-1, 1) for _ in range(3)]
                length = sum(x*x for x in direction) ** .5
                inputs['listenerForward'] = [x / length for x in direction]
            for key in ['position', 'velocity', 'listenerPosition', 'listenerForward', 'listenerVelocity']:
                inputs[key] = list(struct.unpack('<3f', struct.pack('<3f', *inputs[key])))
            rows.append({'input': inputs, 'commands': p.call(inputs)})
    # A real camera orientation update, listener copy, and source listener read.
    listeners = []
    p.uc.mem_write(0x4afce0, b'\xc3')
    p.u32(0x680c54, 0x1f)
    camera = SCRATCH + 0x9000
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = SpatialProbe()
        p.uc.mem_write(0x4afce0, b'\xc3')
        p.u32(0x680c54, 0x1f)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        initialize_native_trig(p)
        for translation in [[0, 0, 0], [123, 456, 789]]:
            p.uc.mem_write(camera, bytes(0x178))
            for index in range(4):
                p.f32(camera + 0x14 + index * 20, 1)
            for j, value in enumerate(translation):
                p.f32(camera + 0x44 + j*4, value)
            position, target = [-2500, 80, 7600], [-2490, 50, 7750]
            p.u32(camera + 0x78, 1)
            p.u32(camera + 0xc8, 0xffffffff)
            for base, values in [(8, position), (0xcc, target)]:
                for j, value in enumerate(values):
                    p.f32(camera + base + j*4, value)
            p.uc.reg_write(UC_X86_REG_ECX, camera)
            p.run(0x498c00)
            p.u32(0x680ba0, camera)
            p.u32(0x508670, 0)
            p.u32(0x508620, 0)
            p.u32(0x53be28, 0)
            p.u32(OBJECT + 0xc, 0)
            p.f32(OBJECT + 0x9c, 12)
            p.f32(OBJECT + 0xa4, 100)
            p.f32(SCRATCH + 0x4078, 160)
            p.run(0x43b660)
            p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
            outputs = [SCRATCH + 0x7000, SCRATCH + 0x7010, SCRATCH + 0x7020]
            p.run(0x49d9e0, outputs)
            listeners.append({'precision': precision, 'matrixTranslation': translation,
                              'cameraPosition': position, 'cameraTarget': target,
                              'localVelocity': [12, 0, 100], 'yaw': 160,
                              'expected': {key: list(struct.unpack('<3f', p.uc.mem_read(ptr, 12)))
                                           for key, ptr in zip(['position', 'forward', 'velocity'], outputs)}})
        # POSITION_LOCK copies body render matrix INCLUDING its translation.
        p.uc.mem_write(camera, bytes(0x178))
        body_position = [-2500, 21, 7600]
        for index in range(4):
            p.f32(SCRATCH + 0x4010 + index * 20, 1)
        for j, value in enumerate(body_position):
            p.f32(SCRATCH + 0x4050 + j*4, value)
            p.f32(SCRATCH + 0x4040 + j*4, value)
        p.u32(camera + 0x74, 1)
        p.u32(camera + 0x78, 1)
        for base, values in [(0xbc, [0, 50, -150]), (0xcc, [0, 50, 0])]:
            for j, value in enumerate(values):
                p.f32(camera + base + j*4, value)
        p.uc.reg_write(UC_X86_REG_ECX, camera)
        p.run(0x498c00)
        p.run(0x43b660)
        p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
        p.run(0x49d9e0, outputs)
        listeners.append({'precision': precision, 'positionLock': True, 'matrixTranslation': body_position,
                          'cameraPosition': [p.float(camera + 8 + j*4) for j in range(3)],
                          'cameraTarget': [p.float(camera + 0x54 + j*4) for j in range(3)],
                          'localVelocity': [12, 0, 100], 'yaw': 160,
                          'expected': {key: list(struct.unpack('<3f', p.uc.mem_read(ptr, 12)))
                                       for key, ptr in zip(['position', 'forward', 'velocity'], outputs)}})
    gates = []
    p = NativeProbe(SOURCE)
    p.u32(0x67ee24, 1)
    p.u32(0x67ee30, SCRATCH + 0x2000)
    p.uc.mem_write(SCRATCH + 0x2000, b'\x01')
    p.uc.mem_write(0x497b30, b'\xc3')
    p.uc.mem_write(0x491d30, b'\xc3')
    p.uc.mem_write(SCRATCH + 0x8000, b'\xc3')
    p.u32(OBJECT + 0x54, SCRATCH + 0x8000)
    current = {}
    def gate_hook(uc, address, size, data):
        if address == 0x497b30:
            sp = uc.reg_read(UC_X86_REG_ESP)
            for index, value in enumerate(current['bounds']):
                p.u32(p.integer(sp + 12 + index*4), value)
            uc.reg_write(UC_X86_REG_EAX, int(current['wrapped']))
        elif address == SCRATCH + 0x8000:
            current['calls'] += 1
    handle = p.uc.hook_add(UC_HOOK_CODE, gate_hook)
    for visible, always, wrapped, sector in itertools.product([False, True], [False, True], [False, True], [0, 4, 5, 7, 10, 11, 20, 90, 99]):
        current = {'bounds': [5, 10, 90, 99], 'wrapped': wrapped, 'calls': 0}
        p.u32(OBJECT + 0x44, int(visible))
        p.u32(OBJECT + 0x50, int(always))
        p.u32(OBJECT + 0x1c, sector)
        p.run(0x491530, [0, 20, 0])
        assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        gates.append({'visible': visible, 'alwaysUpdate': always, 'sector': sector,
                      'ranges': [[5, 10], [90, 99]] if wrapped else [[5, 10]], 'calls': current['calls']})
    p.uc.hook_del(handle)
    target = ROOT / 'evidence/native/spatial-audio-fixtures.json'
    target.write_text(json.dumps({'format': 'superkarts-native-spatial-audio-v1', 'sha256': p.sha,
        'method': 'Unchanged 49da60/49d980/49d900/49d8a0 and 49d9e0/49e9f0; sound service calls captured. Listener cases execute 498c00→43b660→49ea30→49d9e0.',
        'rows': rows, 'listeners': listeners, 'callbackGates': gates}, indent=2) + '\n')
    print(f'Wrote {len(rows)} spatial mixer, {len(listeners)} listener and {len(gates)} callback-gate cases')


if __name__ == '__main__':
    main()
