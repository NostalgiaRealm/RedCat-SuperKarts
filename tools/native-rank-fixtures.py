#!/usr/bin/env python3
"""Execute original complete 0x406be0 rank updater and capture overtake calls."""
import json
import random
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP

p=NativeProbe(SOURCE)
rng=random.Random(0x406be0)
out={'routine':'0x406be0','sourceSha256':p.sha,'cases':[]}
events=[]
def capture(uc,address,size,data):
    if address!=0x4387e0:return
    sp=uc.reg_read(UC_X86_REG_ESP)
    events.append({'type':'overtake','behind':p.integer(sp+4),'ahead':p.integer(sp+8)})
    uc.reg_write(UC_X86_REG_EIP,p.integer(sp));uc.reg_write(UC_X86_REG_ESP,sp+4)
p.uc.hook_add(UC_HOOK_CODE,capture)
p.u32(0x504f98,SCRATCH+0xa000)
for case in range(600):
    count=case%10
    ranks=list(range(count+1));rng.shuffle(ranks)
    actors=[{'rank':ranks[index],'distance':rng.choice([-2,-1,0,0,1,2,20,100]),
             'finished':rng.choice([False,False,True]),'finishTimeMs':rng.choice([0,1234,1234,2345,4567])}
            for index in range(count+1)]
    p.u32(0x508610,count)
    for index,actor in enumerate(actors):
        if index==count:
            p.u32(0x53be28,index)
            for address,key in [(0x53be60,'rank'),(0x53be70,'distance'),(0x53be50,'finished'),(0x53be58,'finishTimeMs')]:
                p.u32(address,int(actor[key])&0xffffffff)
        else:
            base=0x5081b4+index*0x70
            p.u32(base,actor['finishTimeMs']);p.u32(base+4,actor['rank'])
            p.u32(base+8,index);p.u32(base+12,int(actor['finished']))
            p.u32(OBJECT+index*0xd0+0x10,index)
            p.u32(SCRATCH+0xa000+index*0x6c+0x60,actor['distance']&0xffffffff)
    events.clear()
    p.run(0x406be0)
    expected=[p.integer(0x5081b8+i*0x70) for i in range(count)]+[p.integer(0x53be60)]
    out['cases'].append({'actors':actors,'ranks':expected,'events':list(events)})
(ROOT/'evidence/native/rank-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'original rank/overtake cases')
