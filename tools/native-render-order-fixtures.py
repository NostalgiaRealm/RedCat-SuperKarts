#!/usr/bin/env python3
"""Trace original object and road submissions without executing Direct3D."""
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EAX
from generate_native_gameplay_fixtures import NativeProbe,ROOT,SOURCE,SCRATCH,OBJECT

def main():
    p=NativeProbe(SOURCE);trace=[];ranges=[];cases=[]
    p.u32(0x67ee24,6);p.u32(0x67ee30,SCRATCH+0x3000)
    p.u32(0x6a5e80,SCRATCH+0x2000)
    for address in [0x497ab0,0x490d40,0x4931a0]:p.uc.mem_write(address,b'\xc3')
    def hook(uc,address,size,data):
        sp=uc.reg_read(UC_X86_REG_ESP)
        if address==0x497ab0:
            for index,value in enumerate([*ranges[0],*(ranges[1]if len(ranges)>1 else[0,0])]):
                p.u32(p.integer(sp+12+index*4),value)
            uc.reg_write(UC_X86_REG_EAX,int(len(ranges)>1))
        elif address==0x490d40:trace.append(['object',(uc.reg_read(UC_X86_REG_ECX)-OBJECT)//0xd0])
        elif address==0x4931a0:trace.append(['shadow',p.integer(sp+4)])
    for address in [0x497ab0,0x490d40,0x4931a0]:
        p.uc.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
    for case in range(36):
        ranges[:]=[[0,5]]if case%3==0 else[[4,5],[0,1]]if case%3==1 else[[2,4]]
        objects=[]
        for index in range(6):
            row={'sector':index,'active':not(case%5==0 and index==2),
                 'used':not(case%7==0 and index==3),'renderable':not(case%4==0 and index==1),
                 'shadow':index>=3}
            base=OBJECT+index*0xd0;render=SCRATCH+0x4000+index*0xa9
            for offset,value in [(0xc,index),(0x1c,index),(0x44,int(row['active'])),
                (0x3c,int(row['renderable'])),(0x28,0 if row['shadow'] else 0xffffffff)]:
                p.u32(base+offset,value)
            p.uc.mem_write(SCRATCH+0x3000+index,bytes([int(row['used'])]))
            p.u32(render,1);p.u32(render+0x95,0);objects.append(row)
        trace.clear();p.run(0x4918f0,[0,5])
        cases.append({'objects':objects,'ranges':list(ranges),'expected':list(trace)})
    road=[]
    q=NativeProbe(SOURCE);q.uc.mem_map(0x22000000,0x10000)
    q.u32(0x680b28,0x22000000)
    q.u32(0x6a621c,SCRATCH+0x1000);q.u32(SCRATCH+0x1000,SCRATCH+0x1100)
    for slot in [0x68,0x78]:q.u32(SCRATCH+0x1100+slot,SCRATCH+0x500+slot)
    q.uc.mem_write(SCRATCH+0x568,b'\x31\xc0\xc2\x0c\x00')
    q.uc.mem_write(SCRATCH+0x578,b'\x31\xc0\xc2\x20\x00')
    for kind,(vertices,count,indices)in enumerate([(0x6a,0x72,0x6e),(0x7a,0x82,0x7e),
                                                  (0x5a,0x62,0x5e),(0x8a,0x92,0x8e)]):
        q.u32(OBJECT+vertices,0x23000000+kind*0x1000)
        q.u32(OBJECT+count,1000);q.u32(OBJECT+indices,0x24000000+kind*0x1000)
    for sector in range(6):
        for kind in range(4):
            q.u32(0x22000000+sector*0x984+kind*8,sector*(kind+1)*3)
            q.u32(0x22000000+sector*0x984+kind*8+4,(sector+1)*(kind+1)*3)
    draws=[]
    def draw(uc,address,size,data):
        sp=uc.reg_read(UC_X86_REG_ESP)
        draws.append({'kind':(q.integer(sp+16)-0x23000000)//0x1000,
                      'count':q.integer(sp+28)})
    q.uc.hook_add(UC_HOOK_CODE,draw,begin=SCRATCH+0x578,end=SCRATCH+0x578)
    for first,last in [(0,5),(2,4),(0,1),(4,5)]:
        draws.clear();q.uc.reg_write(UC_X86_REG_ECX,OBJECT);q.run(0x497270,[first,last])
        road.append({'range':[first,last],'expected':list(draws)})
    (ROOT/'evidence/native/render-order-fixtures.json').write_text(json.dumps({
        'format':'superkarts-native-render-order-v1','sha256':p.sha,'objects':cases,'road':road},indent=2)+'\n')
    print(f'Wrote {len(cases)} original object traces and {len(road)} road traces')

if __name__=='__main__':main()
