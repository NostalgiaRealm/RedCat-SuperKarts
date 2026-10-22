#!/usr/bin/env python3
"""Execute both original seed callsites, stubbing only clocks/presentation."""
import json
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, STACK

p=NativeProbe(SOURCE)
# time(time_t* out): provide OS time while retaining original caller and srand.
p.uc.mem_write(0x4bf48c,bytes.fromhex('8b4c2404a1')+struct.pack('<I',SCRATCH+0x1100)+bytes.fromhex('8901c3'))
p.u32(0x4d215c,SCRATCH+0x3000)
p.uc.mem_write(SCRATCH+0x3000,b'\xa1'+struct.pack('<I',SCRATCH+0x1104)+b'\xc3')
dependencies=[0x437d50,0x42f920,0x42f740,0x435210]
for address in dependencies:p.uc.mem_write(address,b'\xc3')
calls=[]
def hook(uc,address,size,data):
    if address in dependencies:
        sp=uc.reg_read(UC_X86_REG_ESP)
        calls.append({'address':f'{address:08x}','randomState':p.integer(0x502978),
            **({'phase':p.integer(sp+4)} if address==0x42f740 else {})})
p.uc.hook_add(UC_HOOK_CODE,hook)
cases=[]
for seconds in [0,1,1700000000,0xffffffff]:
    for tick in [0,25,987654,0xffffffff]:
        for construction_draws in [0,1,7,31]:
            p.f32(SCRATCH+0x1000,.1)
            p.u32(SCRATCH+0x1100,seconds);p.u32(SCRATCH+0x1104,tick)
            p.uc.reg_write(UC_X86_REG_ESP,STACK+0xf000)
            p.uc.emu_start(0x4b14e0,0x4b14fa,count=1000)
            first=p.integer(0x502978)
            before=[]
            for i in range(construction_draws):
                p.run(0x4be6c9);before.append(p.uc.reg_read(UC_X86_REG_EAX))
            calls.clear();p.run(0x42f930)
            reset=p.integer(0x502978);actions=list(calls)
            after=[]
            for i in range(16):
                p.run(0x4be6c9);after.append(p.uc.reg_read(UC_X86_REG_EAX))
            cases.append({'seconds':seconds,'tickMs':tick,'constructionDraws':construction_draws,
                'constructionSeed':first,'constructionValues':before,'raceSeed':reset,
                'actions':actions,'raceValues':after,'finalState':p.integer(0x502978)})
out={'sourceSHA256':p.sha,'functions':['004b14e0 prefix through004b14fa','0042f930','004be6bf','004be6c9'],
    'method':'Original seed callsites and PRNG. OS clocks and four race-initialization callees stubbed. Synthetic construction draw counts demonstrate reseed boundary, not a complete initialization trace.',
    'cases':cases}
(ROOT/'evidence/native/startup-random-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print(f'{len(cases)} original two-seed startup sequences')
