#!/usr/bin/env python3
"""Execute original rain/snow construction, particle updates and draw vertices.

Only allocator/texture/Direct3D boundaries are replaced. The allocator explicitly
returns fresh zero-filled memory; native unwritten UV bytes have no stable value.
"""
import json
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT


def fixture(kind, count, precision, enabled):
    p = NativeProbe(SOURCE)
    p.uc.mem_map(0, 0x1000)
    p.uc.mem_map(0x22000000, 0x100000)
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
    heap = [0x22000000]
    for address in [0x4be7ee, 0x4bc150, 0x4afcc0, 0x4afce0]:
        p.uc.mem_write(address, b'\xc3')
    p.uc.mem_write(0x4a6060, b'\x31\xc0\xc2\x04\x00')
    p.u32(0x6a6290, SCRATCH+0x8000)
    p.u32(0x4fd9fc, 0)
    p.u32(SCRATCH+0x8000, SCRATCH+0x8100)
    p.u32(0x6a5e80, SCRATCH+0x8200)
    p.u32(0x6a6254, 0)
    p.u32(0x6a621c, SCRATCH+0x6000)
    p.u32(SCRATCH+0x6000, SCRATCH+0x5000)
    p.u32(SCRATCH+0x505c, SCRATCH+0x7000)
    p.u32(SCRATCH+0x5068, SCRATCH+0x7000)
    p.u32(SCRATCH+0x5074, SCRATCH+0x7010)
    p.uc.mem_write(SCRATCH+0x7000, b'\x31\xc0\xc2\x0c\x00')
    p.uc.mem_write(SCRATCH+0x7010, b'\x31\xc0\xc2\x18\x00')
    drawn = []
    states = []

    def hook(uc, address, size, data):
        sp = uc.reg_read(UC_X86_REG_ESP)
        if address == 0x4be7ee:
            n = p.integer(sp+4)
            base = heap[0]
            heap[0] += (n+15) & ~15
            uc.reg_write(UC_X86_REG_EAX, base)
        elif address == SCRATCH+0x7000:
            states.append([p.integer(sp+8), p.integer(sp+12)])
        elif address == SCRATCH+0x7010:
            vertices, length = p.integer(sp+16), p.integer(sp+20)
            for index in range(length//6):
                base = vertices+index*192
                drawn.append({
                    'vertices': [p.float(base+i*32+axis*4) for i in range(6) for axis in range(3)],
                    'uv': [p.float(base+i*32+24+axis*4) for i in range(6) for axis in range(2)],
                    'argb': [p.integer(base+i*32+16) for i in range(6)],
                })
    p.uc.hook_add(UC_HOOK_CODE, hook)

    def run(address, args=(), this=None):
        if this is not None:
            p.uc.reg_write(UC_X86_REG_ECX, this)
        p.run(address, args)
        while p.uc.reg_read(UC_X86_REG_EIP) != SCRATCH:
            p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP), SCRATCH, count=2000000)

    run(0x4be6bf, [12345])
    run(0x481be0 if kind == 'rain' else 0x481a80, [0, 0, count, int(enabled)])
    obj = p.integer(0x5450a8 if kind == 'rain' else 0x5450a4)

    def snapshot():
        pointer = p.integer(obj+0x9c)
        return {
            'paused': bool(p.integer(obj+0xa8) & 255),
            'activeCount': p.integer(obj+0xa0),
            'acceleration': [p.float(obj+0xbc+i*4) for i in range(3)],
            'randomState': p.integer(0x502978),
            'particles': [{
                'active': bool(p.integer(pointer+i*92+8) & 255),
                'age': p.float(pointer+i*92+4),
                'lifetime': p.float(pointer+i*92+12),
                'mass': p.float(pointer+i*92+16),
                'position': [p.float(pointer+i*92+20+j*4) for j in range(3)],
                'previousPosition': [p.float(pointer+i*92+32+j*4) for j in range(3)],
                'acceleration': [p.float(pointer+i*92+44+j*4) for j in range(3)],
                'velocity': [p.float(pointer+i*92+56+j*4) for j in range(3)],
                'width': p.float(pointer+i*92+68),
                'argb': p.integer(pointer+i*92+72),
            } for i in range(count)],
        }
    output = {'kind': kind, 'count': count, 'precision': precision, 'enabled': enabled,
              'seed': 12345, 'initial': snapshot(), 'frames': []}
    for tick in range(32):
        delta = [.025, .1, .25, .5][tick//8]
        velocity = [tick*.125-2, tick%4-1.5, tick*2.25]
        for axis, value in enumerate(velocity):
            p.f32(OBJECT+0x9c+axis*4, value)
        if tick == 3:
            p.uc.mem_write(obj+0xa8, b'\0')
        if tick == 5:
            p.uc.mem_write(obj+0xa8, b'\1')
        if tick == 7:
            p.uc.mem_write(obj+0xa8, b'\0')
        fraction = None
        if kind == 'rain' and tick in [10, 12, 14, 16]:
            fraction = {10: .25, 12: 0., 14: .75, 16: 1.}[tick]
            run(0x481e10, [fraction])
        run(0x483300, [delta], this=obj)
        drawn.clear()
        states.clear()
        run(0x483350, [0], this=obj)
        output['frames'].append({
            'input': {'deltaSeconds': delta, 'velocity': velocity,
                      'paused': bool(p.integer(obj+0xa8)&255), 'fraction': fraction},
            'expected': snapshot(),
            # Keep all draw attributes on representative full frames; state/RNG
            # is compared for every particle on every frame.
            'drawn': list(drawn) if tick in [0, 7, 12, 16, 31] else None,
        })
    return p.sha, output


def main():
    traces = []
    for precision in [24, 53]:
        for kind in ['rain', 'snow']:
            for count in [17, 400]:
                sha, trace = fixture(kind, count, precision, count == 400)
                traces.append(trace)
    p = NativeProbe(SOURCE)
    p.u32(0x5450a8, SCRATCH+0x3000)
    p.u32(0x5450a4, SCRATCH+0x3200)
    p.u32(0x5450b4, SCRATCH+0x3400)
    p.u32(0x5450ac, SCRATCH+0x3400)
    p.u32(0x5450b8, 4)
    p.u32(0x5450b0, 4)
    p.u32(0x680ae0, SCRATCH+0x3600)
    p.u32(0x53be28, 0)
    p.u32(OBJECT+0x24, 0)
    p.u32(OBJECT+0xd0+0x24, 0)
    p.uc.mem_write(0x415be0,b'\xa1'+struct.pack('<I',SCRATCH+0x3800)+b'\xc3')
    for i, percent in enumerate([25,50,75,100]): p.u32(SCRATCH+0x3400+i*4, percent)
    triggers = []
    for kind in ['rain','snow']:
        for precision,cw in [(24,0x7f),(53,0x27f)]:
            p.uc.reg_write(UC_X86_REG_FPCW,cw)
            for marker in range(79,89):
                for player in [True,False]:
                    for forward in [True,False]:
                        for match in [True,False]:
                            for base in [SCRATCH+0x3000,SCRATCH+0x3200]:
                                p.u32(base+0xa8,1);p.u32(base+0xa0,400);p.u32(base+0xa4,400)
                            p.u32(0x53d20c,0);p.u32(0x53d210,0)
                            p.u32(SCRATCH+0x3604,marker if match else 0)
                            p.u32(SCRATCH+0x3800,int(forward))
                            p.run(p.integer(0x4ecd80+marker*4),[0 if player else 1])
                            base=SCRATCH+(0x3000 if kind=='rain' else 0x3200)
                            triggers.append({'kind':kind,'precision':precision,'marker':marker,
                                'player':player,'forward':forward,'waypointMarker':marker if match else 0,
                                'expected':{'paused':bool(p.integer(base+0xa8)&255),
                                    'activeCount':p.integer(base+0xa0),
                                    'percentageIndex':p.integer(0x53d20c if kind=='rain' else 0x53d210)}})
    output = {'format': 'superkarts-native-weather-v1', 'sha256': sha,
              'allocation': 'fresh-zero-filled; original unwritten UV bytes are unspecified',
              'traces': traces, 'triggers':triggers}
    (ROOT/'evidence/native/weather-fixtures.json').write_text(json.dumps(output, separators=(',', ':'))+'\n')
    print('Wrote 8 original weather constructors,256 complete particle frames,320 marker callbacks')


if __name__ == '__main__':
    main()
