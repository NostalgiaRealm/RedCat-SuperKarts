#!/usr/bin/env python3
"""Original 0x42ef90/0x4341d0 analog controls with supplied joystick positions."""
import json, random, pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EAX
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH
p=NativeProbe(SOURCE);rng=random.Random(0x4341d0)
out={'sourceSha256':p.sha,'routines':['0x42ef90','0x4341d0'],'cases':[]}
p.u32(0x53a5e8,1);p.u32(0x53a5d8,3);p.u32(0x53ba34,0)
pe=pefile.PE(str(SOURCE/'rcskspel.dat'))
tick=next(x.address for library in pe.DIRECTORY_ENTRY_IMPORT for x in library.imports if x.name==b'GetTickCount')
p.u32(tick,SCRATCH+0xb000);p.uc.mem_write(SCRATCH+0xb000,b'\x31\xc0\xc3')
sample={}
def hook(uc,address,size,_):
 if address!=0x4bac90:return
 sp=uc.reg_read(UC_X86_REG_ESP)
 for arg,key in [(16,'x'),(20,'y'),(24,'buttonMask')]:p.u32(p.integer(sp+arg),sample[key]&0xffffffff)
 uc.reg_write(UC_X86_REG_EAX,1);uc.reg_write(UC_X86_REG_EIP,p.integer(sp));uc.reg_write(UC_X86_REG_ESP,sp+4)
p.uc.hook_add(UC_HOOK_CODE,hook)
for index in range(1200):
 sample={'x':rng.choice([-10,0,1,24,49,50,51,75,99,100,110]),
         'y':rng.randrange(-10,111),'buttonMask':rng.randrange(256)}
 mirrored=bool(index%2);p.u32(0x53a734,int(mirrored))
 p.f32(0x53bd70,rng.uniform(-100,100));p.f32(0x53bd74,rng.uniform(0,100));p.u32(0x53be04,rng.randrange(101))
 p.u32(0x53be1c,0);p.run(0x4341d0)
 out['cases'].append({**sample,'mirrored':mirrored,'expected':{
  'steering':p.float(0x53bd70),'throttle':p.float(0x53bd74),
  'brake':p.integer(0x53be04),'handbrake':bool(p.integer(0x53bdf4))}})
(ROOT/'evidence/native/analog-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote1200 original analog-input cases')
