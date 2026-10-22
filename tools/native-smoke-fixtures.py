#!/usr/bin/env python3
"""Execute complete native tyre/damage cloud emission and render updates."""
import json
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig


def main():
    output={'format':'superkarts-native-smoke-v1','traces':[]}
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE)
        output['sha256']=p.sha
        p.uc.reg_write(UC_X86_REG_FPCW,cw)
        initialize_native_trig(p)
        p.uc.mem_write(0x432190,b'\xc3')
        p.uc.mem_write(SCRATCH+0x300,b'\xa1'+struct.pack('<I',SCRATCH+0x310)+b'\xc3')
        p.u32(0x4d215c,SCRATCH+0x300)
        p.u32(0x53b9f0,1);p.u32(0x53ba24,1);p.u32(0x53be28,0)
        p.u32(0x53be10,0);p.u32(0x508b00,0)
        p.u32(0x680ba0,SCRATCH+0x9000);p.u32(0x508670,0);p.u32(0x508620,0)
        for index in range(4):p.f32(SCRATCH+0x9014+index*20,1)
        p.u32(0x6a6290,SCRATCH+0x8000);p.u32(0x4fd9fc,0);p.u32(SCRATCH+0x8000,SCRATCH+0x8100)
        p.u32(0x6a5e80,SCRATCH+0x8200);p.u32(0x53a228,0);p.u32(0x6a6254,0)
        p.u32(0x6a621c,SCRATCH+0x6000);p.u32(SCRATCH+0x6000,SCRATCH+0x5000)
        p.u32(SCRATCH+0x505c,SCRATCH+0x7000);p.u32(SCRATCH+0x5068,SCRATCH+0x7000)
        p.u32(SCRATCH+0x5074,SCRATCH+0x7010)
        p.uc.mem_write(SCRATCH+0x7000,b'\x31\xc0\xc2\x0c\x00')
        p.uc.mem_write(SCRATCH+0x7010,b'\x31\xc0\xc2\x18\x00')
        p.run(0x427720) if False else None
        p.run(0x428720);p.run(0x428800);p.run(0x4be6bf,[12345])
        for index in range(70):p.u32(0x535020+index*300+0x10c,index)
        drawn=[]
        def hook(uc,address,size,data):
            if address!=SCRATCH+0x7010:return
            sp=uc.reg_read(UC_X86_REG_ESP)
            vertices=p.integer(sp+16)
            drawn.append({'id':p.integer(vertices-64+0x10c),
                'vertices':[p.float(vertices+i*32+axis*4) for i in range(6) for axis in range(3)],
                'uv':[p.float(vertices+i*32+24+axis*4) for i in range(6) for axis in range(2)],
                'argb':[p.integer(vertices+i*32+16) for i in range(6)]})
        p.uc.hook_add(UC_HOOK_CODE,hook)
        frames=[]
        for tick in range(90):
            delta=[.025,.03125,.05,.1,.08][min(4,tick//18)]
            now=tick*101+100
            position=[100+tick*.75,20,-200+tick*.25]
            yaw=-234.6+tick*33.3
            lateral=-15+tick*.1;forward=25-tick*.2
            for axis,value in enumerate(position):p.f32(0x53be44+axis*4,value)
            p.f32(SCRATCH+0x4078,yaw);p.f32(OBJECT+0x9c,lateral);p.f32(OBJECT+0xa4,forward)
            p.f32(SCRATCH+0x1000,delta);p.u32(SCRATCH+0x310,now)
            p.u32(0x50728c,10 if tick%11 else 3)
            hardware=tick!=15;enabled=tick!=25
            p.u32(0x53ba24,int(enabled));p.u32(0x53b9f0,int(hardware))
            kind='damage' if tick%7==0 else 'skid'
            p.run(0x420490 if kind=='damage' else 0x432240)
            camera=[500-tick*4,60,200+tick*2]
            for axis,value in enumerate(camera):p.f32(SCRATCH+0x9008+axis*4,value)
            drawn=[]
            p.run(0x428a00)
            if p.uc.reg_read(UC_X86_REG_EIP)!=SCRATCH:
                p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP),SCRATCH,count=2000000)
            assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
            clouds=[]
            for index in range(70):
                base=0x535020+index*300
                if p.integer(base+0x128):
                    clouds.append({'id':p.integer(base+0x10c),
                        'position':[p.float(base+0x30+axis*4) for axis in range(3)],
                        'velocity':[p.float(base+0x100+axis*4) for axis in range(3)],
                        'period':p.integer(base+0x118),'tick':p.integer(base+0x11c),
                        'width':p.float(base+0x120),'height':p.float(base+0x124),
                        'alpha':p.integer(base+0x50)>>24})
            frames.append({'input':{'kind':kind,'nowMs':now,'deltaSeconds':p.float(SCRATCH+0x1000),
                'position':[p.float(0x53be44+axis*4) for axis in range(3)],
                'body':{'yaw':p.float(SCRATCH+0x4078),'lateralSpeed':p.float(OBJECT+0x9c),'forwardSpeed':p.float(OBJECT+0xa4)},
                'slipMagnitude':p.integer(0x50728c),'cameraPosition':camera,'hardware':hardware,'enabled':enabled},
                'randomState':p.integer(0x502978),'clouds':clouds,
                'order':[p.integer(0x535020+index*300+0x10c) for index in range(70)],
                'drawn':drawn})
        output['traces'].append({'precision':precision,'seed':12345,'frames':frames})
    (ROOT/'evidence/native/smoke-fixtures.json').write_text(json.dumps(output,separators=(',',':'))+'\n')
    print('Wrote180 complete native smoke emission/render/sort frames')


if __name__=='__main__':main()
