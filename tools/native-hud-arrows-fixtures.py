#!/usr/bin/env python3
"""Execute original HUD arrow state machines with bounded clock/facing services.

No original files are changed. Element visibility/color setters and all arrow
branches remain original; the probe supplies the two already-created elements.
"""
import json
import struct
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT

traces=[]
for precision, control in [(24,0x007f),(53,0x027f)]:
    p=NativeProbe(SOURCE)
    p.uc.mem_map(0,4096)
    p.uc.reg_write(UC_X86_REG_FPCW,control)
    p.uc.mem_write(0x48f4d0,b'\xd9\x05'+struct.pack('<I',SCRATCH+0x1018)+b'\xc3')
    p.uc.mem_write(0x415be0,b'\xa1'+struct.pack('<I',SCRATCH+0x1020)+b'\xc3')
    p.uc.mem_write(0x544aa8,b'\x01')
    definitions=[
      ('wrong-way-full-cycle',[(False,'update',i*.025,.025) for i in range(180)]
       +[(True,'update',4.5,.025)]),
      ('junction-expiry',[(True,'requestJunction',7.1,.025)]
       +[(True,'update',7.1+i*.025,.025) for i in range(1,50)]),
      ('junction-interrupt',[(True,'requestJunction',15,.1),(True,'requestJunction',15.05,.1),
        (False,'update',15.1,.1),(False,'requestJunction',15.2,.1),
        (False,'update',15.3,.1),(True,'update',15.4,.1),(True,'requestJunction',15.5,.1)]),
      ('long-stalls',[(False,'update',1000,0)]+
       [(False,'update',1000+i*4,.1) for i in range(1,40)]),
      ('clock-boundaries',[(False,'update',0,.025)]+
       [(False,'update',t,.025) for t in [0.07142856,0.0714285746216774,0.07142858,
        0.14285713,0.1428571492433548,0.14285717,0.2142857,0.21428572]]),
      ('zero-dt-junction',[(True,'requestJunction',0,0)]+
       [(True,'update',i*.1,0) for i in range(1,31)]),
    ]
    for name,steps in definitions:
        p.uc.mem_write(OBJECT,b'\0'*0x100)
        for index in range(2):
            element=SCRATCH+0x6000+index*0x100
            p.uc.mem_write(element,b'\0'*0x100)
            p.u32(element,0x4d2890)
            p.u32(element+0x28,0xffffffff)
            p.u32(OBJECT+8+index*4,element)
        frames=[]
        for forward,method,now,dt in steps:
            p.f32(SCRATCH+0x1018,now);p.f32(SCRATCH+0x1000,dt)
            p.u32(SCRATCH+0x1020,int(forward))
            p.uc.reg_write(UC_X86_REG_ECX,OBJECT)
            p.run(0x4653c0 if method=='update' else 0x465840)
            assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
            state=dict(zip(['phase','type','alphaStep'],[p.integer(OBJECT+x) for x in [0x10,0x14,0x18]]))
            state.update(timestampSeconds=p.float(OBJECT+0x1c),remainingSeconds=p.float(OBJECT+0x20))
            frames.append({'input':{'forward':forward,'nowSeconds':p.float(SCRATCH+0x1018),
                'deltaSeconds':p.float(SCRATCH+0x1000)},'method':method,'state':state,
                'elements':[{'visible':bool(p.uc.mem_read(SCRATCH+0x602c+i*0x100,1)[0]),
                  'argb':p.integer(SCRATCH+0x6028+i*0x100)} for i in range(2)]})
        traces.append({'precision':precision,'name':name,'frames':frames})

# The player-only junction marker callback is original 4420f0, table slot54.
assert p.integer(0x4ecd80+54*4)==0x4420f0
p.uc.mem_write(0x430610,b'\x8b\x44\x24\x04\xa3'+struct.pack('<I',SCRATCH+0x3000)+b'\xc3')
p.u32(0x53be28,7)
triggers=[]
for actor in [0,7,8]:
    p.u32(SCRATCH+0x3000,0xffffffff)
    p.run(0x4420f0,[actor])
    triggers.append({'actor':actor,'player':7,'event':p.integer(SCRATCH+0x3000)})

out=ROOT/'evidence/native/hud-arrows-fixtures.json'
out.write_text(json.dumps({'format':'superkarts-native-hud-arrows-v1','sourceSHA256':p.sha,
 'functions':['004653c0','004654b0','00465570','00465820','00465840','00465880','004420f0'],
 'scope':'Original arrow instructions and element setters; clock/facing queries supplied. No GPU or full-process parity claim.',
 'traces':traces,'junctionTriggers':triggers},indent=2)+'\n')
print(f'Captured {sum(len(t["frames"]) for t in traces)} native arrow updates, {len(triggers)} trigger cases.')
