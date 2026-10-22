#!/usr/bin/env python3
"""Execute original481ec0 rocket ring construction, update and indexed draws."""
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT


def main():
    traces=[]
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        for delta in [.025,.1,.25]:
            p=NativeProbe(SOURCE);p.uc.mem_map(0,0x1000);p.uc.mem_map(0x22000000,0x100000)
            p.uc.reg_write(UC_X86_REG_FPCW,cw)
            heap=[0x22000000];drawn=[]
            for address in [0x4be7ee,0x4bc150,0x4afcc0,0x4afce0]:p.uc.mem_write(address,b'\xc3')
            p.uc.mem_write(0x4a6060,b'\x31\xc0\xc2\x04\x00')
            p.u32(0x6a6290,SCRATCH+0x8000);p.u32(0x4fd9fc,0)
            p.u32(SCRATCH+0x8000,SCRATCH+0x8100);p.u32(0x6a5e80,SCRATCH+0x8200);p.u32(0x6a6254,0)
            p.u32(0x6a621c,SCRATCH+0x6000);p.u32(SCRATCH+0x6000,SCRATCH+0x5000)
            p.u32(SCRATCH+0x505c,SCRATCH+0x7000);p.u32(SCRATCH+0x5068,SCRATCH+0x7000)
            p.u32(SCRATCH+0x5078,SCRATCH+0x7010)
            p.uc.mem_write(SCRATCH+0x7000,b'\x31\xc0\xc2\x0c\x00')
            p.uc.mem_write(SCRATCH+0x7010,b'\x31\xc0\xc2\x20\x00')
            def hook(uc,address,size,data):
                sp=uc.reg_read(UC_X86_REG_ESP)
                if address==0x4be7ee:
                    n=p.integer(sp+4);base=heap[0];heap[0]+=(n+15)&~15
                    uc.reg_write(UC_X86_REG_EAX,base)
                elif address==SCRATCH+0x7010:
                    base,count=p.integer(sp+16),p.integer(sp+20)
                    indices,length=p.integer(sp+24),p.integer(sp+28)
                    drawn.append({'vertices':[p.float(base+i*32+axis*4)for i in range(count)for axis in range(3)],
                        'uv':[p.float(base+i*32+24+axis*4)for i in range(count)for axis in range(2)],
                        'argb':[p.integer(base+i*32+16)for i in range(count)],
                        'indices':[int.from_bytes(p.uc.mem_read(indices+i*2,2),'little')for i in range(length)]})
            p.uc.hook_add(UC_HOOK_CODE,hook)
            def run(address,args=(),this=None):
                if this is not None:p.uc.reg_write(UC_X86_REG_ECX,this)
                p.run(address,args)
                while p.uc.reg_read(UC_X86_REG_EIP)!=SCRATCH:
                    p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP),SCRATCH,count=2000000)
                return p.uc.reg_read(UC_X86_REG_EAX)&255
            for axis,v in enumerate([100,25,-200]):p.f32(SCRATCH+0x4050+axis*4,v)
            for axis,v in enumerate([3,-1,8]):p.f32(OBJECT+0x9c+axis*4,v)
            run(0x4be6bf,[12345]);run(0x481ec0,[0,0])
            obj=p.integer(0x5450a0)-8;particle=p.integer(obj+0x9c)
            trace={'precision':precision,'delta':delta,'seed':12345,'randomState':p.integer(0x502978),
                'initialPosition':[p.float(particle+0x14+i*4)for i in range(3)],'frames':[]}
            for tick in range(40):
                position=[100+tick*.75,25+tick*.025,-200-tick*.2]
                for axis,value in enumerate(position):p.f32(SCRATCH+0x4050+axis*4,value)
                alive=bool(run(0x483300,[delta],this=obj));drawn.clear()
                if alive:run(0x4842f0,[0],this=obj)
                trace['frames'].append({'position':[p.float(SCRATCH+0x4050+i*4)for i in range(3)],
                    'alive':alive,'age':p.float(particle+4),'drawn':list(drawn)})
                if not alive:break
            traces.append(trace)
    out={'format':'superkarts-native-explosions-v1','sha256':p.sha,'traces':traces}
    (ROOT/'evidence/native/explosion-fixtures.json').write_text(json.dumps(out,separators=(',',':'))+'\n')
    print('Wrote6 original explosion constructors and complete update/indexed geometry traces')


if __name__=='__main__':main()
