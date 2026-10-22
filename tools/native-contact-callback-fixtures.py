#!/usr/bin/env python3
"""Execute original 491d30 contact callback dispatch, with motion/response stubbed."""
import itertools, json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH

p = NativeProbe(SOURCE)
for address in [0x4afce0, 0x493860, 0x4911a0, 0x4a09e0, 0x49c4f0,
                0x4932e0, 0x4936a0]:
    p.uc.mem_write(address, b'\xc3')
callbacks = [SCRATCH+0xb000, SCRATCH+0xb010]
for address in callbacks: p.uc.mem_write(address, b'\xc3')
calls = []
def hook(uc, address, size, data):
    if address in callbacks:
        calls.append(p.integer(uc.reg_read(UC_X86_REG_ESP)+4))
p.uc.hook_add(UC_HOOK_CODE, hook)
p.u32(0x680ad0, 0); p.u32(0x680ad8, 0xffffffff); p.u32(0x67ee24, 2)
p.u32(0x67ee30, SCRATCH+0xa000); p.uc.mem_write(SCRATCH+0xa000, b'\1\1')
p.u32(0x680220, 104); p.f32(SCRATCH+0x1000, .025)
out = {'sourceSha256':p.sha,
       'method':'Original491d30 with Euler/response/sector callees stubbed; original latch dispatch executes.',
       'cases':[], 'retainedImpulse':[]}
for mover, kind, reverse, mask, latchMask in itertools.product(
        range(2), [-1,0,1], [False,True], range(4), range(4)):
    p.uc.mem_write(OBJECT, b'\0'*(0xd0*2))
    p.uc.mem_write(0x67ee78, b'\0'*(0x67fe18-0x67ee78))
    p.u32(0x67ee78,1); p.u32(0x67ee7c,mover)
    for i in range(2):
        address=OBJECT+i*0xd0
        p.u32(address,1);p.u32(address+0x44,1);p.u32(address+0x50,1)
        p.u32(address+0x4c,int(bool(latchMask&(1<<i))))
        p.u32(address+0x5c,callbacks[i] if mask&(1<<i) else 0)
    first=(1-mover) if reverse and kind==1 else mover
    second=1-first
    p.u32(0x6a5b58,int(kind!=-1));p.u32(0x6a5b5c,max(0,kind))
    p.u32(0x6a5b60,first);p.u32(0x6a5b64,second)
    calls.clear();p.run(0x491d30,[0,80,0xffffffff])
    out['cases'].append({'mover':mover,'kind':kind,'first':first,'second':second,
        'callbackMask':mask,'latchMask':latchMask,'calls':list(calls),
        'latches':[bool(p.integer(OBJECT+i*0xd0+0x4c))for i in range(2)]})
for speed, inverse_mass, previous in itertools.product([-10,0,10],[0,.0025],[0,22000]):
    p.uc.mem_write(OBJECT,b'\0'*0xd0)
    p.f32(OBJECT+0x9c,speed);p.f32(OBJECT+0x90,inverse_mass);p.f32(OBJECT+0x98,.2)
    contact=SCRATCH+0x9000;p.uc.mem_write(contact,b'\0'*48);p.f32(contact+0x1c,1)
    p.f32(0x6a5b80,previous);p.run(0x49c220,[contact])
    out['retainedImpulse'].append({'speed':speed,'inverseMass':p.float(OBJECT+0x90),
        'restitution':p.float(OBJECT+0x98),'previous':previous,'expected':p.float(0x6a5b80)})
(ROOT/'evidence/native/contact-callback-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print(len(out['cases']))
