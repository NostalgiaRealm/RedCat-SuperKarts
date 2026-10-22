#!/usr/bin/env python3
"""Native timer initialization followed by startup-path duration allocation."""
import json, struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH

out={'functions':['48f2c0','48f3e0','48f4e0','443d20','445740','4450c0'],
     'method':'Original x86 timer init and path allocation; clock APIs, heap allocation and logger supplied.',
     'cases':[]}
image=pefile.PE(str(SOURCE/'rcskspel.dat'))
for precision,cw in [(24,0x7f),(53,0x27f)]:
 for qpc in [True,False]:
  for uptime_ms in [0,50,1000,60000,3600000,86400000]:
   for track_id in range(6):
    p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);out['sourceSha256']=p.sha
    p.uc.mem_write(0x48f4e0,image.get_data(0x8f4e0,0x32))
    for address in [0x4afce0,0x4afee0,0x4bc150,0x4be7ee]:p.uc.mem_write(address,b'\xc3')
    for address in [SCRATCH+0x9000,SCRATCH+0x9010]:p.uc.mem_write(address,b'\xc2\x04\x00')
    p.uc.mem_write(SCRATCH+0x9020,b'\xc3')
    p.u32(0x4d2058,SCRATCH+0x9000);p.u32(0x4d204c,SCRATCH+0x9010);p.u32(0x4d2228,SCRATCH+0x9020)
    counter=[uptime_ms];heap=[SCRATCH+0xa000]
    def hook(uc,address,size,data):
     sp=uc.reg_read(UC_X86_REG_ESP)
     if address==0x4be7ee:
      count=p.integer(sp+4);uc.reg_write(UC_X86_REG_EAX,heap[0]);heap[0]+=(count+15)&~15
     elif address==SCRATCH+0x9000:
      uc.mem_write(p.integer(sp+4),struct.pack('<Q',1000000));uc.reg_write(UC_X86_REG_EAX,int(qpc))
     elif address==SCRATCH+0x9010:
      uc.mem_write(p.integer(sp+4),struct.pack('<Q',counter[0]*1000));uc.reg_write(UC_X86_REG_EAX,1)
     elif address==SCRATCH+0x9020:uc.reg_write(UC_X86_REG_EAX,counter[0])
    p.uc.hook_add(UC_HOOK_CODE,hook)
    p.uc.reg_write(UC_X86_REG_ECX,0x67ec70);p.run(0x48f2c0)
    p.uc.reg_write(UC_X86_REG_ECX,0x67ec70);initial_delta=p.run(0x48f4e0,float_return=True)
    track=json.loads((ROOT/f'public/assets/tracks/etappe{track_id}.json').read_text())
    index=next(i for i,path in enumerate(track['paths'])if path['type']==1)
    path=track['paths'][index];address=0x53f660+index*0x340
    p.uc.mem_write(address,struct.pack('<6i',path['startSector'],path['endSector'],1,path['unknown'],path['durationMs'],len(path['points'])))
    for i,point in enumerate(path['points']):p.uc.mem_write(address+24+16*i,struct.pack('<i3f',point['flag'],*point['position']))
    p.u32(0x508638,1);p.u32(0x53be28,0)
    p.run(0x443d20,[SCRATCH+0xb000,index])
    case={'precision':precision,'qpc':qpc,'uptimeMs':uptime_ms,'track':track_id,
       'initialDelta':initial_delta,'durationTicks':p.integer(0x53f500),'updates':[]}
    for i in range(6):
     counter[0]+=25;p.uc.reg_write(UC_X86_REG_ECX,0x67ec70);p.run(0x48f3e0)
     p.uc.reg_write(UC_X86_REG_ECX,0x67ec70);delta=p.run(0x48f4e0,float_return=True)
     case['updates'].append({'delta':delta,'rawHistory':[p.float(p.integer(0x67ec28)+4*i)for i in range(4)]})
    out['cases'].append(case)
(ROOT/'evidence/native/camera-clock-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'timer/start-path initializations')
