#!/usr/bin/env python3
"""Original PTH sampling, activation and motion, with OS/renderer boundaries."""
import json
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT


class PathProbe(NativeProbe):
    def __init__(self):
        super().__init__(SOURCE)
        self.uc.mem_write(0x4a09e0, b'\xc3')  # Matrix output tested independently.
        self.uc.mem_write(SCRATCH + 0x7100, b'\x31\xc0\xc3')
        self.u32(0x4d215c, SCRATCH + 0x7100)  # GetTickCount: diagnostic-only here.
        self.uc.mem_write(0x446b80, b'\xb8\x01\x00\x00\x00\xc3')
        self.uc.mem_write(0x446c00, b'\xb8\x01\x00\x00\x00\xc3')
        self.activations = []
        self.uc.hook_add(UC_HOOK_CODE, self.hook)

    def hook(self, uc, address, size, _):
        if address == 0x446c00:
            self.activations.append(self.integer(uc.reg_read(UC_X86_REG_ESP) + 4))

    def load(self, paths):
        self.u32(0x543760, len(paths))
        self.uc.mem_write(0x53f660, bytes(0x340 * len(paths)))
        self.uc.mem_write(0x53f4f8, bytes(0x24 * 10))
        for index, path in enumerate(paths):
            base = 0x53f660 + index * 0x340
            self.uc.mem_write(base, struct.pack('<6i', path['startSector'], path['endSector'],
                path['type'], path['unknown'], path['durationMs'], len(path['points'])))
            for i, point in enumerate(path['points']):
                self.uc.mem_write(base + 24 + i * 16, struct.pack('<i3f', point['flag'], *point['position']))

    def call(self, address, args=()):
        self.run(address, args)
        assert self.uc.reg_read(UC_X86_REG_EIP) == SCRATCH

    def sample(self, index, ticks, tick, closed):
        self.call(0x445120, [SCRATCH + 0x8000, index, ticks, tick, .5, int(closed)])
        return list(struct.unpack('<3f', self.uc.mem_read(SCRATCH + 0x8000, 12)))

    def init(self, index, closed, repeat, delta):
        self.uc.mem_write(0x53f4f8, bytes(0x24 * 10))
        self.uc.mem_write(SCRATCH + 0x8100, struct.pack('<iii f iii BBxx',
            1, 0, 0, .5, 0, -1, index, int(repeat), int(closed)))
        self.f32(SCRATCH + 0x1000, delta)
        self.call(0x445740, [SCRATCH + 0x8100])
        return self.integer(0x53f500)


def main():
    p = PathProbe()
    samples, durations, updates, activations = [], [], [], []
    for track_id in range(6):
        track = json.loads((ROOT / f'public/assets/tracks/etappe{track_id}.json').read_text())
        paths = track['paths']
        p.load(paths)
        dynamic = {}
        for index, path in enumerate(paths):
            row = track['pathObjects'].get(track['pathTypes'][str(path['type'])].lower())
            if row:
                fields = row.split(',')
                dynamic[index] = int(fields[1]) if len(fields) > 1 else 0
        for precision in [24, 53]:
            p.uc.reg_write(UC_X86_REG_FPCW, 0x007f if precision == 24 else 0x027f)
            for index, flags in dynamic.items():
                path, closed, repeat = paths[index], bool(flags & 1), bool(flags & 2)
                for delta in [.025, .03125, .1]:
                    ticks = p.init(index, closed, repeat, delta)
                    durations.append({'track': track_id, 'path': index, 'precision': precision, 'delta': delta, 'ticks': ticks})
                ticks = p.init(index, closed, repeat, .025)
                times = sorted(set([0, 1, ticks - 3, ticks - 2, ticks - 1, ticks, ticks + 3]
                    + [int(ticks * i / 19) for i in range(20)]))
                for tick in times:
                    samples.append({'track': track_id, 'path': index, 'precision': precision,
                        'ticks': ticks, 'tick': tick, 'position': p.sample(index, ticks, tick, closed)})
                for initial in [0, ticks - 3, ticks - 2, ticks, ticks + 1]:
                    p.init(index, closed, repeat, .025)
                    p.u32(0x53f504, initial)
                    p.u32(OBJECT + 0x44, 1)
                    p.uc.mem_write(SCRATCH + 0x4050, struct.pack('<3f', 101, 202, 303))
                    p.f32(SCRATCH + 0x4078, 77)
                    for end in [False, False, True]:
                        sector = path['endSector'] if end else path['startSector'] + 1
                        p.u32(0x53be40, sector)
                        before_tick = p.integer(0x53f504)
                        before_position = list(struct.unpack('<3f', p.uc.mem_read(SCRATCH + 0x4050, 12)))
                        before_yaw = p.float(SCRATCH + 0x4078)
                        p.call(0x446dd0, [0x53f4fc])
                        updates.append({'track': track_id, 'path': index, 'precision': precision,
                            'ticks': ticks, 'tick': before_tick, 'sector': sector,
                            'beforePosition': before_position, 'beforeYaw': before_yaw,
                            'afterTick': p.integer(0x53f504),
                            'position': list(struct.unpack('<3f', p.uc.mem_read(SCRATCH + 0x4050, 12))),
                            'yaw': p.float(SCRATCH + 0x4078), 'done': bool(p.uc.reg_read(UC_X86_REG_EAX) & 255)})
        # Keep original 445900 loop/filters. Dynamic lookup and successful
        # start are service stubs so camera paths are marked already started.
        p.load(paths)
        for index in range(len(paths)):
            if index not in dynamic:
                p.u32(0x53f998 + index * 0x340, 1)
        p.u32(0x4ef160, 0xffffffff)
        p.u32(0x543764, 0)
        for lap in [0, 0, 1, 2]:
            for sector in range(track['sectorCount']):
                p.u32(0x53be40, sector)
                p.u32(0x53ba18, lap)
                # Camera controller selection is out of this fixture's scope.
                for index in range(len(paths)):
                    if index not in dynamic:
                        p.u32(0x53f660 + index * 0x340, 0)
                p.activations = []
                p.call(0x445900)
                activations.append({'track': track_id, 'lap': lap, 'sector': sector, 'started': p.activations.copy()})
    target = ROOT / 'evidence/native/scenery-path-fixtures.json'
    target.write_text(json.dumps({'format': 'superkarts-native-scenery-path-v1', 'sha256': p.sha,
        'method': 'Original 445740/4450c0 duration quantization, 445120/445530/445620 spline, 446dd0 dynamic movement and 445900 activation instructions. Renderer, OS timer and activation services are boundary stubs.',
        'durations': durations, 'samples': samples, 'updates': updates, 'activations': activations}, separators=(',', ':')) + '\n')
    print({name: len(rows) for name, rows in [('durations', durations), ('samples', samples), ('updates', updates), ('activations', activations)]})


if __name__ == '__main__':
    main()
