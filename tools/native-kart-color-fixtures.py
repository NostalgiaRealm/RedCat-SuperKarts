#!/usr/bin/env python3
"""Execute original 4903c0 including parent/child vertex writes."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_FPCW

def fp(x): return struct.unpack('<f', struct.pack('<f', x))[0]

def main():
    rng = random.Random(0x4903c0)
    out = {'scope': 'Original 4903c0 and 4902d0, supplied triangle-color and clock boundaries; original parent/child vertex writes execute. Both x87 precision modes.', 'cases': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        out['sourceSha256'] = p.sha
        render, meshes, vertices = SCRATCH+0x4000, SCRATCH+0x8000, SCRATCH+0x9000
        p.u32(0x6a5ee0, meshes)
        p.u32(OBJECT+0x8c, 3)
        for i in range(4):
            p.u32(render+i*0xa9, 1)
            p.u32(render+i*0xa9+0x99, i)
            p.u32(meshes+i*0xbc+0x80, vertices+i*0x100)
            p.u32(meshes+i*0xbc+0x84, 3)
            if i: p.u32(OBJECT+0x64+(i-1)*4, i)
        # Child modes0/1/2: only mode0 is recolored.
        for i in range(1,4): p.u32(render+i*0xa9+0xa5, i-1)
        p.uc.mem_write(0x495fe0, b'\xc2\x18\x00')
        p.uc.mem_write(0x496360, b'\xa1'+struct.pack('<I',SCRATCH+0x2000)+b'\xc2\x08\x00')
        for case in range(300):
            state = rng.randrange(0x100000000)
            ground = rng.randrange(0x1000000)
            speed = fp(rng.choice([-80, -30, 0, 5, 20, 40, rng.uniform(-100,100)]))
            dt = fp(rng.choice([0, .025, 1/32, .1, .25, 1/144]))
            offsets = rng.choice([[0,0,0],[128,128,128],[-128,64,255],[rng.randrange(-255,256) for _ in range(3)]])
            p.u32(OBJECT+0x34, state)
            p.f32(OBJECT+0xa4, speed)
            p.u32(SCRATCH+0x2000, ground)
            p.f32(SCRATCH+0x1000, dt)
            for address, value in zip([0x6802c0,0x680ac8,0x680acc],offsets): p.f32(address,value)
            for i in range(4):
                for vertex in range(3): p.u32(vertices+i*0x100+vertex*0x20+0x10,0x12345678)
            p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
            p.run(0x4903c0)
            colors = [[p.integer(vertices+i*0x100+v*0x20+0x10) for v in range(3)] for i in range(4)]
            out['cases'].append({'precision':precision,'diffuse':state,'groundDiffuse':ground,'forwardSpeed':speed,
                'deltaSeconds':dt,'brightness':offsets,'expected':{'diffuse':p.integer(OBJECT+0x34),'renderDiffuse':colors[0][0]},
                'meshColors':colors})
    (ROOT/'evidence/native/kart-color-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
    print('Wrote600 original kart-color and child-color updates')

if __name__ == '__main__': main()
