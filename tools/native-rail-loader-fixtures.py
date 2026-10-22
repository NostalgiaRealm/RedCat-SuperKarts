#!/usr/bin/env python3
"""Execute original CMP loader with in-memory fread and heap services."""
import json,random,struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_FPCW,UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
rng=random.Random(49);out={'routine':'0x49ced0','cases':[]}
for bits,cw in [(24,0x7f),(53,0x27f)]:
 for index in range(60):
  p=NativeProbe(SOURCE);p.u32(0x4fc8f0,4096);p.f32(0x4fc8f4,4096);p.u32(0x4fc8f8,4095);p.uc.reg_write(UC_X86_REG_FPCW,cw);p.uc.mem_write(0x4afce0,b'\xc3')
  vals=[rng.uniform(-5000,5000),0,rng.uniform(-5000,5000),rng.uniform(-100,100),0,rng.uniform(-100,100)]
  binary=struct.pack('<I6f',1,*vals);vals=struct.unpack('<6f',binary[4:]);cursor=0;alloc=SCRATCH+0xa000
  def hook(u,a,size,data):
   global cursor,alloc
   if a not in [0x4b96d0,0x4bf930,0x4b9840,0x4be7ee]:return
   sp=u.reg_read(UC_X86_REG_ESP);ret=p.integer(sp);result=1
   if a==0x4bf930:
    size=p.integer(sp+8)*p.integer(sp+12);p.uc.mem_write(p.integer(sp+4),binary[cursor:cursor+size]);cursor+=size
   if a==0x4be7ee:result=alloc;alloc+=0x1000
   u.reg_write(UC_X86_REG_EAX,result);u.reg_write(UC_X86_REG_ESP,sp+4);u.reg_write(UC_X86_REG_EIP,ret)
  p.uc.hook_add(UC_HOOK_CODE,hook);p.run(0x49ced0,[0]);addr=p.integer(0x6a5be8)
  out['cases'].append({'precision':bits,'record':{'position':list(vals[:3]),'delta':list(vals[3:])},'yaw':p.float(addr+0x18),'length':p.float(addr+0x5c)})
(ROOT/'evidence/native/rail-loader-fixtures.json').write_text(json.dumps(out,indent=2)+'\n');print('Wrote',len(out['cases']),'rail loader cases')
