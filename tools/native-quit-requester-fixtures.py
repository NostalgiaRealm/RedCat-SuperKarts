#!/usr/bin/env python3
"""Execute original requester dispatch/pressed loop; replace only OS/presentation services.

Input selection for 0x473f20 is stubbed to each original return code. Existing
race-lifecycle-fixtures.json separately executes the real 0x474040 keyboard
release loop. No original files are modified; no game process is launched.
"""
import json
import struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, STACK

p = NativeProbe(SOURCE)
pe = pefile.PE(str(SOURCE / 'rcskspel.dat'))
imports = {item.name:item.address for group in pe.DIRECTORY_ENTRY_IMPORT for item in group.imports}
clock = SCRATCH + 0xb000
p.u32(imports[b'GetTickCount'], clock)
p.uc.mem_write(clock, b'\xa1' + struct.pack('<I', SCRATCH + 0xb100) + b'\xc3')
events = []
now = 0
choice = -1

def ret(uc, value=0, pop=0):
    sp = uc.reg_read(UC_X86_REG_ESP)
    uc.reg_write(UC_X86_REG_EAX, value)
    uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    uc.reg_write(UC_X86_REG_ESP, sp + 4 + pop)

def cstring(address):
    out = bytearray()
    while (value := p.uc.mem_read(address, 1)[0]):
        out.append(value);address += 1
    return out.decode('ascii')

def hook(uc, address, size, unused):
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x474040: return ret(uc, choice)
    if address == 0x4b4d70:
        events.append({'type':'sound','name':cstring(p.integer(sp+4)), 'nowMs':now})
        return ret(uc)
    if address == 0x4715e0:
        events.append({'type':'draw','args':[p.integer(sp+n) for n in [4,8,12]], 'nowMs':now})
        return ret(uc, pop=12) # Original 0x4715e0 thiscall RET 0xc.
    if address in [0x4707f0,0x4739c0,0x471d10,0x4aff70,0x473d40,0x471b80]:
        return ret(uc)

p.uc.hook_add(UC_HOOK_CODE, hook)
out={'sourceSha256':p.sha, 'scope':'Original 0x473f20 and 0x473fb0; OS clock and presentation calls stubbed. Real key-release loop is in race-lifecycle-fixtures.json.', 'traces':[]}
for choice in [0,1,2,3,10000]:
    for epoch in [0,60000,0xfffffff0]:
        events.clear()
        pointer=SCRATCH+0xd000
        p.uc.mem_write(pointer,b'\x7f')
        sp=STACK+0xf000
        p.u32(sp,SCRATCH);p.u32(sp+4,pointer)
        p.uc.reg_write(UC_X86_REG_ESP,sp);p.uc.reg_write(UC_X86_REG_EIP,0x473f20)
        trace=[]
        for offset in [0,1,50,99,100]:
            now=(epoch+offset)&0xffffffff
            p.u32(SCRATCH+0xb100,now)
            p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP),SCRATCH,count=2000)
            trace.append({'nowMs':now,'returned':p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH,
                'result':p.uc.mem_read(pointer,1)[0], 'events':list(events)})
        out['traces'].append({'choice':choice,'epoch':epoch,'trace':trace})
path=ROOT/'evidence/native/quit-requester-fixtures.json'
path.write_text(json.dumps(out,indent=2)+'\n')
assert len(out['traces'])==15
for item in out['traces']:
    assert [v['returned'] for v in item['trace']]==[False]*4+[True]
    assert item['trace'][-1]['result']==(1 if item['choice'] in [0,2] else 0)
    assert item['trace'][-1]['events']==[
        {'type':'sound','name':'click4.wav','nowMs':item['epoch']},
        {'type':'draw','args':[1,7 if item['choice'] in [0,2] else 10,9],'nowMs':item['epoch']}]
print('Wrote 15 original requester traces / 75 timed observations:',path)
