#!/usr/bin/env python3
"""Original hazard callbacks; isolate already-verified animation and manager calls."""
import json,random,struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe,ROOT,SOURCE,SCRATCH,OBJECT

def main():
    rows=[];rng=random.Random(0x43bc70)
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw)
        for address in [0x43f490,0x43ff30,0x4a09e0]:p.uc.mem_write(address,b'\xc3')
        for address in [0x44d730,0x44d4b0]:p.uc.mem_write(address,b'\x31\xc0\xc2\x04\x00')
        p.uc.mem_write(0x44f500,b'\x31\xc0\xc3')
        p.uc.mem_write(0x44f0f0,b'\xa1'+struct.pack('<I',SCRATCH+0x3000)+b'\xc2\x04\x00')
        p.uc.mem_write(0x48e210,b'\xb8'+struct.pack('<I',SCRATCH+0x3500)+b'\xc3')
        #48e210 leaves the body argument on the stack;48e780 thiscall consumes it.
        p.uc.mem_write(0x48e780,b'\xc2\x04\x00')
        calls=[]
        from unicorn.x86_const import UC_X86_REG_ESP
        def hook(uc,address,size,data):
            if address==0x48e780:
                calls.append(p.integer(uc.reg_read(UC_X86_REG_ESP)+4))
        p.uc.hook_add(UC_HOOK_CODE,hook,begin=0x48e780,end=0x48e780)
        p.u32(0x53be28,1)
        for index in range(9):
            p.u32(OBJECT+index*0xd0+0xc,index)
        for kind,address in [(43,0x43f740),(44,0x440290),(46,0x43bc70),(47,0x43fab0)]:
            for case in range(240):
                count=[0,1,4,6][case%4];p.u32(0x508610,count)
                origin=[rng.uniform(-8000,8000),0,rng.uniform(-8000,8000)]
                distances=[0,31.99,32,43.99,44,69.99,70,94.99,95,-31.99,-70]
                positions=[origin]
                for index in range(count+1):
                    d=distances[(case+index)%len(distances)]
                    positions.append([origin[0]+d,0,origin[2]+[0,.99,1.01][(case+index)%3]])
                for index,position in enumerate(positions):
                    for axis,value in enumerate(position):p.f32(SCRATCH+0x4000+index*0xa9+0x50+axis*4,value)
                for index in range(count):p.u32(0x5081bc+index*0x70,index+2)
                cached=[positions[1][0]+(100 if case%7==0 else 0),0,positions[1][2]]
                for axis,value in enumerate(cached):p.f32(0x53be44+axis*4,value)
                angle=[-100,0,99.99,100.99,101,500,923.99,924,1023.99,1124.99,2048][case%11]
                frame=[0,2,3,16,17,38,39,48,49,63][case%10]
                p.f32(SCRATCH+0x4000+0x7c,angle);p.f32(0x53ba8c,100)
                p.u32(SCRATCH+0x3000,frame);calls.clear()
                p.run(address,[0])
                assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH,hex(p.uc.reg_read(UC_X86_REG_EIP))
                stored=lambda index:[p.float(SCRATCH+0x4000+index*0xa9+0x50+axis*4)for axis in range(3)]
                rows.append({'precision':precision,'type':kind,'position':stored(0),
                    'angle':p.float(SCRATCH+0x4000+0x7c),'frame':frame,
                    'player':stored(1),'opponents':[stored(i+2)for i in range(count)],
                    'cachedPlayer':[p.float(0x53be44+i*4)for i in range(3)],'expected':list(calls)})
    (ROOT/'evidence/native/squash-activation-fixtures.json').write_text(json.dumps({
        'format':'superkarts-native-squash-activation-v1','sha256':p.sha,'cases':rows},separators=(',',':'))+'\n')
    print(f'Wrote {len(rows)} original hazard activation cases')

if __name__=='__main__':main()
