#!/usr/bin/env python3
"""Execute original page-presentation dispatch against recording COM stubs.
Only API arguments are measured: no display, GPU completion or vsync timings.
"""
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH
p=NativeProbe(SOURCE)
initial_buffers=p.integer(0x4fe940)
front,back,vt,flip,blt=[SCRATCH+x for x in [0x3000,0x3100,0x4000,0x5000,0x5100]]
p.u32(0x6a64bc,front);p.u32(0x6a64c0,back);p.u32(front,vt);p.u32(back,vt)
p.u32(vt+0x2c,flip);p.u32(vt+0x14,blt)
p.uc.mem_write(flip,b'\x31\xc0\xc2\x0c\x00');p.uc.mem_write(blt,b'\x31\xc0\xc2\x18\x00')
# Surface restore/check has no role in deciding the presentation API flags.
p.uc.mem_write(0x4b08e0,b'\xc3')
p.u32(0x6a64f4,0);p.u32(0x4fe930,640);p.u32(0x4fe934,480)
# This software-copy stub preserves the original caller's cdecl argument cleanup.
p.uc.mem_write(0x4b6120,b'\xc3')
events=[]
def hook(uc,address,size,user):
    if address not in [flip,blt]:return
    sp=uc.reg_read(UC_X86_REG_ESP)
    if address==flip:events.append({'api':'Flip','target':p.integer(sp+8),'flags':p.integer(sp+12)})
    else:events.append({'api':'Blt','flags':p.integer(sp+20),'effects':p.integer(sp+24)})
p.uc.hook_add(UC_HOOK_CODE,hook)
cases=[]
for renderer in [1,2]:
    for buffers in [0,1,2]:
        p.u32(0x4e7bec,renderer);p.u32(0x4fe940,buffers);events.clear()
        p.run(0x430470)
        assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
        expected=[{'api':'Flip','target':0,'flags':1}] if buffers else [{'api':'Blt','flags':0x1000000,'effects':0}]
        assert events==expected,(renderer,buffers,events)
        cases.append({'renderer':renderer,'backbufferCount':buffers,'events':list(events)})
result={'format':'superkarts-native-presentation-flags-v1','sourceSha256':p.sha,'scope':__doc__,'entry':'0x430470','present':'0x4aff70','initialPEBackbufferCount':initial_buffers,'cases':cases,'limitations':['COM calls are stubs. No refresh rate, waiting duration, GPU completion, driver behavior or native runtime cadence was measured.','Native main loop0x4432a0 enforces25ms minimum before full0x42f4c0 update; presentation can add host-dependent latency.']}
path=ROOT/'evidence/native/presentation-flags.json';path.write_text(json.dumps(result,indent=2)+'\n');print('PASS',len(cases),'original dispatch cases; initial backbuffer count',initial_buffers)
