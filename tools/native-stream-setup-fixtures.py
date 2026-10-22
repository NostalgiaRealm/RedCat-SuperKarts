#!/usr/bin/env python3
"""Capture original racer/turbo/projectile stream setup arguments."""
import json
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_ESI,UC_X86_REG_EDI

p=NativeProbe(SOURCE);p.uc.mem_map(0,4096)
commands=[];level=0;bonus_type=0;body=0;stops=set()
def ret(value=0,pop=0):
    sp=p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_EAX,value);p.uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
    p.uc.reg_write(UC_X86_REG_ESP,sp+4+pop)
def hook(uc,address,size,data):
    sp=uc.reg_read(UC_X86_REG_ESP)
    if address in stops:uc.reg_write(UC_X86_REG_EIP,SCRATCH)
    elif address==0x48a480:ret(SCRATCH+0x8000)
    elif address==0x48a890:
        commands.append({'op':'remove','body':p.integer(sp+4)});ret(0,4)
    elif address==0x48a570:
        args=[p.integer(sp+4+i*4) for i in range(9)]
        commands.append({'op':'add','body':args[0],'options':[{
            'offset':[p.float(args[1]+i*4) for i in range(3)],'rotate':bool(args[2]&255),
            'colorIndex':args[3],'rainbow':bool(args[4]&255),'doubleSided':bool(args[5]&255),
            'size':p.float(sp+28),'flare':bool(args[7]&255),'fastShrink':bool(args[8]&255)}]})
        ret(0,36)
    elif address==0x48a6d0:
        args=[p.integer(sp+4+i*4) for i in range(5)]
        commands.append({'op':'add','body':args[0],'options':[{
            'offset':[p.float(ptr+i*4) for i in range(3)],'rotate':bool(args[4]&255),
            'colorIndex':2,'rainbow':bool(args[4]&255),'doubleSided':bool(args[4]&255),
            'size':p.float(sp+16),'flare':True,'fastShrink':False} for ptr in args[1:3]]})
        ret(0,20)
    elif address in [0x44fbc0,0x4503c0]:ret(level)
    elif address==0x4500b0:ret(bonus_type)
    elif address==0x4500d0:ret(body)
    elif address==0x4afce0:ret()
p.uc.hook_add(UC_HOOK_CODE,hook)
p.run(0x489300);p.run(0x489350)
out={'sourceSha256':p.sha,'scope':'Original42d7d0 setup block,4537f0 stream-replacement block and456440 projectile state2 branch, with manager entry arguments captured.','initial':[],'turbo':[],'projectiles':[]}
for count in [0,1,4]:
    p.u32(0x508610,count);p.u32(0x53be28,10)
    for i in range(count):p.u32(0x5081bc+i*0x70,i+20)
    commands=[];stops={0x42dcdb}
    p.run(0x42dbbb)
    out['initial'].append({'opponents':count,'playerBody':10,'npcBodies':[20+i for i in range(count)],'commands':commands})
for racer in range(5):
    for level in range(1,4):
        commands=[];stops={0x453ab1,0x453a36}
        p.uc.reg_write(UC_X86_REG_ESI,10+racer);p.uc.reg_write(UC_X86_REG_EDI,racer)
        p.run(0x453951)
        out['turbo'].append({'racer':racer,'level':level,'body':10+racer,'commands':commands})
for bonus_type in range(1,5):
    for level in range(1,4):
        body=70+bonus_type;commands=[];stops={0x45654c,0x4566f3}
        p.uc.reg_write(UC_X86_REG_ECX,SCRATCH+0x7000)
        p.run(0x456440,[2])
        out['projectiles'].append({'type':bonus_type,'level':level,'body':body,'commands':commands})
(ROOT/'evidence/native/stream-setup-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote30 original stream setup branches')
