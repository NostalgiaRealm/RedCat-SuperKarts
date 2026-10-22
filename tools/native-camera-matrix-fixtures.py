#!/usr/bin/env python3
"""Execute the unmodified original camera orientation update with fixed locks."""
import json
import random
import struct
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH


def main():
    rows=[]
    rng=random.Random(49800)
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW,cw)
        p.uc.mem_write(0x4afce0,b'\xc3')
        p.u32(0x680c54,0x1f)
        camera=SCRATCH+0x9000
        for index in range(240):
            position=[rng.uniform(-20000,20000) for _ in range(3)]
            target=[position[axis]+rng.uniform(-500,500) for axis in range(3)]
            up=[rng.uniform(-1,1) for _ in range(3)] if index%2 else [0,1,0]
            if index<6:
                position=[0,0,0]
                target=[[0,0,1],[1,0,0],[-1,0,0],[0,0,-1],[1,1,1],[1,-1,1]][index]
                up=[0,1,0]
            inputs={key:list(struct.unpack('<3f',struct.pack('<3f',*value))) for key,value in
                    [('position',position),('target',target),('up',up)]}
            p.uc.mem_write(camera,bytes(0x178))
            for i in range(4):p.f32(camera+0x14+i*20,1)
            p.u32(camera+0x78,1);p.u32(camera+0xc8,0xffffffff);p.u32(camera+0x80,1)
            for base,key in [(8,'position'),(0xcc,'target'),(0x24,'up')]:
                for axis,value in enumerate(inputs[key]):p.f32(camera+base+axis*4,value)
            p.uc.reg_write(UC_X86_REG_ECX,camera)
            p.run(0x498c00)
            assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
            matrix=[p.float(camera+0x14+row*16+col*4) for row in range(3) for col in range(3)]
            rows.append({'precision':precision,'input':inputs,'matrix':matrix})
    output={'format':'superkarts-native-camera-matrix-v1','sha256':p.sha,'rows':rows}
    (ROOT/'evidence/native/camera-matrix-fixtures.json').write_text(json.dumps(output,indent=2)+'\n')
    print(f'Wrote {len(rows)} native camera matrices')


if __name__=='__main__':main()
