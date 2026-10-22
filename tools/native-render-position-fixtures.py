#!/usr/bin/env python3
"""Original draw/color/shadow consumers with deliberately distinct pose fields."""
import json
import random
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT


def main():
    output = {'method': __doc__, 'cases': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        output['sourceSha256'] = p.sha
        render, meshes = SCRATCH + 0x4000, SCRATCH + 0x5000
        p.u32(0x6a5ee0, meshes)
        p.u32(0x6a5f78, SCRATCH + 0x6000)
        p.u32(SCRATCH + 0x6004, SCRATCH + 0x6100)
        p.u32(SCRATCH + 0x6100, 0)
        p.u32(0x6a5f30, SCRATCH + 0x6200)
        p.u32(SCRATCH + 0x6200, 1)
        p.u32(render, 1)
        p.u32(render + 0x99, 0)
        p.u32(render + 0x95, 0)
        p.u32(OBJECT + 0x28, 1)
        p.u32(OBJECT + 0x1c, 0)
        p.u32(meshes + 0xbc + 0x84, 4)
        p.u32(meshes + 0xbc + 0x80, SCRATCH + 0x7000)
        p.u32(0x68021c, SCRATCH + 0x6300)
        p.u32(SCRATCH + 0x6300, 0)
        p.u32(0x680b28, SCRATCH + 0x8000)
        p.u32(0x53ba60, 0)
        p.u32(0x6a6234, 1)
        p.u32(0x6a621c, SCRATCH + 0x9000)
        p.u32(SCRATCH + 0x9000, SCRATCH + 0x9100)
        for offset in [0x5c, 0x68]:
            p.u32(SCRATCH + 0x9100 + offset, SCRATCH + 0x9200)
        p.uc.mem_write(SCRATCH + 0x9200, b'\x31\xc0\xc2\x0c\x00')
        for address in [0x4a09d0, 0x4a7e10]:
            p.uc.mem_write(address, b'\xc3')
        p.uc.mem_write(0x495fe0, b'\xc2\x18\x00')
        p.uc.mem_write(0x496360, b'\xb8\x80\x80\x80\x00\xc2\x08\x00')
        samples, transforms, blend = [], [], {}

        def capture(uc, address, size, _):
            sp = uc.reg_read(UC_X86_REG_ESP)
            if address == 0x495fe0:
                samples.append([p.float(sp + 4 + axis * 4) for axis in range(3)])
            elif address == SCRATCH + 0x9200 and p.integer(sp + 8) == 1:
                matrix = p.integer(sp + 12)
                if matrix == 0x6a61dc:
                    transforms.append([p.float(matrix + index * 4) for index in range(16)])
            elif address == SCRATCH + 0x9200 and p.integer(sp + 8) in [19, 20]:
                blend[p.integer(sp + 8)] = p.integer(sp + 12)

        p.uc.hook_add(UC_HOOK_CODE, capture)
        rng = random.Random(0x48ca60)
        for index in range(100):
            values = [[rng.uniform(-8000, 8000), rng.uniform(-20, 100), rng.uniform(-8000, 8000)]
                      for _ in range(2)]
            logical, translation = [list(struct.unpack('<3f', struct.pack('<3f', *row))) for row in values]
            normal = [0.125, 1, -0.25]
            distance = float(index)
            matrix = [0.1,0,0,0,0.1,0,0,0,0.1]
            for axis in range(3):
                p.f32(render + 0x50 + axis * 4, logical[axis])
                p.f32(render + 0x40 + axis * 4, translation[axis])
                p.f32(SCRATCH + 0x803c + axis * 4, normal[axis])
            for row in range(3):
                for column in range(3):
                    p.f32(render + 0x10 + (row * 4 + column) * 4, matrix[row * 3 + column])
            p.f32(render + 0x4c, 1)
            p.f32(SCRATCH + 0x80dc, distance)
            p.u32(OBJECT + 0x34, 0xffffffff)
            p.f32(SCRATCH + 0x1000, 0.025)
            samples.clear()
            transforms.clear()
            p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
            p.run(0x4903c0)
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            p.uc.reg_write(UC_X86_REG_ECX, render)
            p.run(0x4a0d80)
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            alpha = index % 2
            preset = [[2, 1], [2, 2], [5, 2], [5, 6], [6, 5]][index % 5]
            p.u32(0x53ba60, alpha)
            blend.update({19: preset[0], 20: preset[1]})
            p.run(0x4260c0, [0])
            assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
            shadow = render + 0xa9
            assert samples == [logical]
            assert transforms[0][12:15] == translation
            output['cases'].append({'precision': precision,
                'body': {'position': logical, 'matrixTranslation': translation,
                         'matrix': [p.float(render + 0x10 + (row * 4 + column) * 4)
                                    for row in range(3) for column in range(3)]},
                'plane': {'normal': normal, 'distance': distance},
                'blend': {'alphaBlending': bool(alpha), 'before': preset,
                          'after': [blend[19], blend[20]]},
                'expected': {'colorSample': samples[0], 'drawTranslation': transforms[0][12:15],
                             'shadowLogicalPosition': [p.float(shadow + 0x50 + axis * 4) for axis in range(3)],
                             'shadowDrawPosition': [p.float(shadow + 0x40 + axis * 4) for axis in range(3)]}})
    (ROOT / 'evidence/native/render-position-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
    print('Passed 200 original draw/color/shadow cases with distinct logical and matrix positions.')


if __name__ == '__main__':
    main()
