#!/usr/bin/env python3
"""Execute original bubble attach/find/detach/pre-object update operations.

Only logging, engine allocation/free, route selection, mesh lookup and the
separately verified zero-angle matrix builder are stubbed service boundaries.
The manager's slot search, racer mapping, visibility, pose and asset writes run.
"""
import json
import random
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT

MANAGER = SCRATCH + 0x2000
RENDER = SCRATCH + 0x4000


class BubbleProbe(NativeProbe):
    def __init__(self, opponents):
        super().__init__(SOURCE)
        self.opponents = opponents
        self.allocated = set()
        self.cursor = 9
        self.uc.mem_map(OBJECT + 0x1000, 0x3000)
        self.u32(0x508610, opponents)
        self.u32(0x53be28, 0)
        for index in range(opponents):
            self.u32(0x5081bc + index * 0x70, index + 1)
        self.u32(0x6a5c38, RENDER)
        for index in range(64):
            self.u32(OBJECT + index * 0xd0 + 0xc, index)
        for address in [0x4afce0, 0x48fc70, 0x4932e0, 0x48fea0, 0x4a6200, 0x4a09e0]:
            self.uc.mem_write(address, b'\xc3')
        self.uc.mem_write(0x4a6200, b'\xc2\x04\x00')
        self.u32(0x6a5f78, SCRATCH + 0x3000)
        self.u32(SCRATCH + 0x3004, SCRATCH + 0x3020)
        self.u32(SCRATCH + 0x3020, 0)
        self.u32(0x6a5f30, SCRATCH + 0x3040)
        self.u32(SCRATCH + 0x3040, 123)
        self.u32(SCRATCH + 0x3044, 456)
        self.uc.hook_add(UC_HOOK_CODE, self.services)
        self.call(0x457630)

    def services(self, uc, address, size, _):
        if address == 0x48fc70:
            while self.cursor in self.allocated:
                self.cursor += 1
            self.allocated.add(self.cursor)
            uc.reg_write(UC_X86_REG_EAX, self.cursor)
        elif address == 0x48fea0:
            index = self.integer(uc.reg_read(UC_X86_REG_ESP) + 4)
            self.allocated.remove(index)
        elif address == 0x4a6200:
            uc.reg_write(UC_X86_REG_EAX, 0)

    def call(self, address, args=()):
        self.uc.reg_write(UC_X86_REG_ECX, MANAGER)
        self.run(address, args)
        assert self.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
        return self.uc.reg_read(UC_X86_REG_EAX) & 0xff

    def bodies(self, bodies):
        for racer, body in enumerate(bodies):
            index = 0 if racer == self.opponents else racer + 1
            engine, render = OBJECT + index * 0xd0, RENDER + index * 0xa9
            self.u32(engine + 0x1c, body['sector'])
            self.u32(engine + 0x24, body['waypoint'])
            for axis, value in enumerate(body['position']):
                self.f32(render + 0x50 + axis * 4, value)

    def snapshot(self):
        result = []
        for slot in range(self.opponents + 1):
            entry = MANAGER + slot * 0x10
            if not self.uc.mem_read(entry + 0xc, 1)[0]:
                result.append(None)
                continue
            attached, object_index, render_index = [self.integer(entry + i * 4) for i in range(3)]
            engine, render = OBJECT + object_index * 0xd0, RENDER + render_index * 0xa9
            result.append({'racer': self.opponents if attached == 0 else attached - 1,
                'objectOrder': object_index - 9,
                'position': [self.float(render + 0x50 + axis * 4) for axis in range(3)],
                'sector': self.integer(engine + 0x1c), 'waypoint': self.integer(engine + 0x24),
                'angles': [self.float(render + 0x74 + axis * 4) for axis in range(3)],
                'visible': bool(self.integer(engine + 0x44)),
                'meshId': self.integer(render + 0x99), 'textureId': self.integer(render + 0x95),
                'blendMode': self.integer(render + 0xa5)})
        return result


def main():
    rng = random.Random(0x457780)
    report = {'sourceSha256': None, 'method': __doc__, 'traces': []}
    for opponents in [1, 3, 4]:
        probe = BubbleProbe(opponents)
        report['sourceSha256'] = probe.sha
        trace = {'opponentCount': opponents, 'steps': []}
        for tick in range(160):
            bodies = [{'position': [float(rng.randrange(-10000, 10000)) / 8 for _ in range(3)],
                       'sector': rng.randrange(200), 'waypoint': rng.randrange(1000)}
                      for _ in range(opponents + 1)]
            probe.bodies(bodies)
            action = ['attach', 'step', 'detach', 'attach'][tick % 4]
            racer = rng.randrange(-1, opponents + 2)
            result = probe.call({'attach': 0x457780, 'step': 0x457b60, 'detach': 0x457ab0}[action],
                                [] if action == 'step' else [racer & 0xffffffff])
            snapshot = probe.snapshot()
            for entry in snapshot:
                if entry:
                    assert entry['meshId'] == 123 and entry['textureId'] == 456
                    assert entry['blendMode'] == 2 and entry['visible']
                    assert entry['angles'] == [0, 0, 0]
            trace['steps'].append({'action': action, 'racer': racer, 'bodies': bodies,
                                   'result': result if action != 'step' else None, 'expected': snapshot})
        report['traces'].append(trace)
    target = ROOT / 'evidence/native/bubble-attachment-fixtures.json'
    target.write_text(json.dumps(report, separators=(',', ':')) + '\n')
    print('Passed 480 original bubble-manager operations, including attach, duplicate, detach and pre-object pose copy.')


if __name__ == '__main__':
    main()
