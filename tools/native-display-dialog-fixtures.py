#!/usr/bin/env python3
"""Original46a350/46a5a0 advanced display init/commit, with UI-only boundaries.

Get/SetChecked, enabled state, empty host driver enumeration, string disposal,
and dialog close are boundary hooks. All option arithmetic and field writes run
original x86 instructions; no original INI or game inputs are written.
"""
import hashlib,json,pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ESP,UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH
p=NativeProbe(SOURCE);binary=SOURCE/'rcskmenu.dat'
p.uc.mem_write(0x400000,pefile.PE(str(binary)).get_memory_mapped_image());p.uc.mem_map(0,0x1000)
form,options,vmt=SCRATCH+0x1000,SCRATCH+0x2000,SCRATCH+0x3000
p.u32(form+0x338,options)
fields={'rdoBrightnessLight':0x2e8,'rdoBrightnessDark':0x2ec,'cboDriver':0x2f8,
 'cboResolution':0x304,'chkBilinearFiltering':0x314,'chkAlphaBlending':0x31c,
 'chkRenderToSystemMemory':0x324,'chkWaitVbl':0x328,'chkParticles':0x334}
widgets={name:SCRATCH+0x4000+i*0x300 for i,name in enumerate(fields)}
by_address={value:key for key,value in widgets.items()}
get_checked,set_checked,enabled,count=[SCRATCH+0x7000+i*0x10 for i in range(4)]
for name,address in widgets.items():
 p.u32(form+fields[name],address);p.u32(address,vmt);p.u32(address+0x1f0,address)
for offset,address in [(0xb4,get_checked),(0xb8,set_checked),(0x5c,enabled),(0x14,count)]:p.u32(vmt+offset,address)
checks={};events=[]
def ret(value=None):
 if value is not None:p.uc.reg_write(UC_X86_REG_EAX,value&0xffffffff)
 sp=p.uc.reg_read(UC_X86_REG_ESP);p.uc.reg_write(UC_X86_REG_ESP,sp+4);p.uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
def hook(uc,address,size,unused):
 if address in [get_checked,set_checked,enabled]:
  name=by_address[uc.reg_read(UC_X86_REG_EAX)]
  if address==get_checked:ret(int(checks.get(name,False)))
  else:
   state=bool(uc.reg_read(UC_X86_REG_EDX)&255)
   if address==set_checked:checks[name]=state;p.uc.mem_write(widgets[name]+0x210,bytes([int(state)]))
   else:events.append(['enabled',name,state])
   ret()
 elif address==count:ret(0)
 elif address==0x46a878:ret(1)
 elif address==0x424728:ret(-1)
 elif address in [0x402c94,0x424744,0x46a198,0x403b50,0x403b74]:ret()
 elif address==0x42eb18:events.append(['close']);ret()
p.uc.hook_add(UC_HOOK_CODE,hook)
def run(address):p.uc.reg_write(UC_X86_REG_EAX,form);p.run(address)
def state():return {'gamma':p.integer(options+0x30),'filter':p.uc.mem_read(options+0x34,1)[0]*2,'alpha':p.integer(options+0x38),'reducedEffects':p.uc.mem_read(options+0x41,1)[0]}
report={'sourceSha256':hashlib.sha256(binary.read_bytes()).hexdigest(),'scope':__doc__,'cases':[]}
for mask in range(16):
 values={name:bool(mask>>i&1) for i,name in enumerate(['brightnessLight','bilinearFiltering','alphaBlending','particles'])}
 p.u32(options+0x30,int(not values['brightnessLight']));p.uc.mem_write(options+0x34,bytes([int(values['bilinearFiltering'])]));p.u32(options+0x38,2*int(values['alphaBlending']));p.uc.mem_write(options+0x41,bytes([int(not values['particles'])]));p.u32(options+0x3c,0);p.uc.mem_write(options+0x40,b'\0');p.u32(options+0x1c,0xffffffff)
 checks={};events=[];run(0x46a350);initialized=dict(checks);before=state();run(0x46a87c);cancel=state()
 # Set all four active inputs to the opposite checkbox/radio state.
 for name in ['rdoBrightnessLight','rdoBrightnessDark','chkBilinearFiltering','chkAlphaBlending','chkParticles']:checks[name]=not checks[name];p.uc.mem_write(widgets[name]+0x210,bytes([int(checks[name])]))
 run(0x46a8a0)
 report['cases'].append({'values':values,'initialControls':initialized,'before':before,'cancel':cancel,'committed':state(),'events':events})
(ROOT/'evidence/native/display-dialog-fixtures.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({'init':16,'cancel':16,'commit':16}))
