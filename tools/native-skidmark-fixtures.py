#!/usr/bin/env python3
"""Original skid strip emission, pool reuse, fading and render data."""
import json
import math
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_FPCW, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH


def main():
    traces=[]
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW,cw)
        p.uc.mem_write(0x415b90,b'\xc3')
        wheels=[[9,-2,14],[-9,-2,14],[9,-2,-11],[-9,-2,-11]]
        def wheel(uc,address,size,data):
            if address != 0x415b90:return
            sp=uc.reg_read(UC_X86_REG_ESP)
            out,index=p.integer(sp+4),p.integer(sp+12)
            for axis,value in enumerate(wheels[index]):p.f32(out+axis*4,value)
            uc.reg_write(UC_X86_REG_EAX,out)
        p.uc.hook_add(UC_HOOK_CODE,wheel)
        p.run(0x426c00)
        frames=[]
        for tick in range(260):
            dt=.125 if tick<180 else .5
            slip=(10 if tick else 3) if tick<60 else ((10 if tick%4 else 3) if tick<150 else (7 if tick<240 else 0))
            enabled=tick not in [20,21,22]
            fade=tick not in range(42,48)
            contact=tick not in [31,32,33]
            angle=tick*.021
            matrix=[math.cos(angle),0,math.sin(angle), .01,1,.015, -math.sin(angle),0,math.cos(angle)]
            position=[tick*1.1,20+tick*.025,-120+tick*.8]
            for row in range(3):
                for col in range(3):p.f32(SCRATCH+0x4010+row*16+col*4,matrix[row*3+col])
            for axis,value in enumerate(position):p.f32(SCRATCH+0x4040+axis*4,value)
            matrix=[p.float(SCRATCH+0x4010+row*16+col*4) for row in range(3) for col in range(3)]
            position=[p.float(SCRATCH+0x4040+axis*4) for axis in range(3)]
            p.f32(SCRATCH+0x1000,dt)
            p.u32(0x53ba2c,int(enabled));p.u32(0x53ba30,int(fade));p.u32(0x4e0d14,int(contact))
            p.run(0x426aa0,[0,slip])
            #426e50 calls ageing only while enabled; draw itself does not mutate.
            if enabled:p.run(0x426db0)
            assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
            strips=[]
            for index in range(20):
                base=0x50dfb0+index*0x1910
                if not p.integer(base+0x1904):continue
                count=p.integer(base)
                sides=[]
                for offset in [4,0xc84]:
                    sides.append([{
                        'position':[p.float(base+offset+i*32+axis*4) for axis in range(3)],
                        'argb':p.integer(base+offset+i*32+16),
                        'uv':[p.float(base+offset+i*32+24),p.float(base+offset+i*32+28)],
                    } for i in range(count)])
                strips.append({'id':index,'active':True,'period':p.integer(base+0x1908),
                    'tick':p.integer(base+0x190c),'sides':sides})
            frames.append({'input':{'deltaSeconds':dt,'slipMagnitude':slip,'enabled':enabled,'fade':fade,
                'playerContact':contact,'matrix':matrix,'position':position,'wheelOffsets':wheels},
                'lastSlip':p.integer(0x52d4f0),'currentIndex':p.integer(0x4e763c),
                'strips':strips})
        traces.append({'precision':precision,'frames':frames})
    output={'format':'superkarts-native-skidmarks-v1','sha256':p.sha,'traces':traces}
    (ROOT/'evidence/native/skidmark-fixtures.json').write_text(json.dumps(output,separators=(',',':'))+'\n')
    print('Wrote520 complete native skidmark pool/emission/fade frames')


if __name__=='__main__':main()
