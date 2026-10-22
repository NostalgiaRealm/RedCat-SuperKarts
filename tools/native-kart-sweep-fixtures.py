#!/usr/bin/env python3
"""Original 499c30 sweep and 492470 slide with controlled native bbox inputs."""
import json
import random
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_FPCW, UC_X86_REG_ESP, UC_X86_REG_EIP

rng=random.Random(0x499c30)
out={'routines':['0x499c30','0x492470'],'cases':[],
     'method':'Original x86 code. Candidate discovery and model bbox reads replaced by controlled records; sweep, contact construction and slide execute unchanged.',
     'tolerance':{'absolute':0.00003,'relative':0.000003}}
bounds={'minX':-20.726268768310547,'maxX':20.106887817382812,
        'minZ':-27.615097045898438,'maxZ':36.38368225097656}
for precision,cw in [(24,0x7f),(53,0x27f)]:
    p=NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW,cw)
    initialize_native_trig(p)
    out['sourceSha256']=p.sha
    state={}
    def rectangle(address,body,index):
        b=body.get('bounds',bounds);y=b.get('minY',0)
        values=[b['minX'],y,b['minZ'],b['maxX'],y,b['minZ'],
                b['maxX'],y,b['maxZ'],b['minX'],y,b['maxZ'],
                *body['position']]
        for offset,value in enumerate(values):p.f32(address+offset*4,value)
        p.f32(address+0x3c,42)
        p.u32(address+0x40,index)
        import math
        p.u32(address+0x44,(math.ceil(body['yaw']) if body['yaw']>0 else math.floor(body['yaw']))&0xffffffff)
        p.u32(address+0x48,1)
    def hook(uc,address,size,data):
        if address not in [0x499b20,0x4999c0]:return
        sp=uc.reg_read(UC_X86_REG_ESP)
        if address==0x499b20:
            for index,body in enumerate(state['others']):rectangle(0x680c68+index*0x4c,body,index+1)
            p.u32(0x6847c8,len(state['others']))
        else:rectangle(p.integer(sp+8),state['body'],0)
        uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
        uc.reg_write(UC_X86_REG_ESP,sp+4)
    p.uc.hook_add(UC_HOOK_CODE,hook)
    for case in range(180):
        body={'position':[rng.uniform(-50,50),0,rng.uniform(-50,50)],'yaw':rng.uniform(-4096,4096),
              'lateralSpeed':rng.uniform(-10,10),'verticalSpeed':rng.uniform(-1,1),
              'forwardSpeed':rng.uniform(-20,60),'yawRate':rng.uniform(-4,4),'sector':0}
        others=[{'position':[rng.uniform(-50,50),0,rng.uniform(-50,50)],
                 'yaw':rng.uniform(-4096,4096),'sector':0} for _ in range(1+case%2)]
        for item in [body,*others]:
            if case>=120:
                import struct
                item['bounds']={k:struct.unpack('<f',struct.pack('<f',v))[0]for k,v in {
                    'minX':rng.uniform(-100,-5),'maxX':rng.uniform(5,100),
                    'minZ':rng.uniform(-100,-5),'maxZ':rng.uniform(5,100),
                    'minY':rng.uniform(-30,30)}.items()}
            for key in ['yaw','lateralSpeed','verticalSpeed','forwardSpeed','yawRate']:
                if key in item:
                    p.f32(SCRATCH+0xf000,item[key]);item[key]=p.float(SCRATCH+0xf000)
            for axis,value in enumerate(item['position']):
                p.f32(SCRATCH+0xf000,value);item['position'][axis]=p.float(SCRATCH+0xf000)
        state.update(body=body,others=others)
        p.u32(OBJECT+0x44,1);p.u32(OBJECT+4,3)
        for key,offset in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac)]:
            p.f32(OBJECT+offset,body[key])
        dt=rng.choice([.003125,.025,.03125,.1])
        p.f32(SCRATCH+0xf000,dt);dt=p.float(SCRATCH+0xf000)
        fraction=p.run(0x499c30,[0,SCRATCH+0xa000,dt],True)
        contact=None
        if p.integer(0x6a5b58):
            contact={'first':p.integer(0x6a5b60),'second':p.integer(0x6a5b64),
                     'point':[p.float(0x6a5b68+i*4) for i in range(3)],
                     'normal':[p.float(0x6a5b74+i*4) for i in range(3)]}
        expected={'fraction':fraction,'stopYaw':bool(p.integer(SCRATCH+0xa000)),'contact':contact}
        # 492470 returns EAX, writes its optional displacement at param3.
        from unicorn.x86_const import UC_X86_REG_EAX
        p.run(0x492470,[0,dt,SCRATCH+0xa100,float(fraction),SCRATCH+0xa000])
        if p.uc.reg_read(UC_X86_REG_EAX):
            expected['velocityOverride']=[p.float(SCRATCH+0xa100+i*4) for i in range(3)]
        expected['stopYaw']=bool(p.integer(SCRATCH+0xa000))
        out['cases'].append({'precision':precision,'bounds':bounds,'body':body,'others':others,'dt':dt,'expected':expected})
(ROOT/'evidence/native/kart-sweep-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'native dynamic sweep and slide cases')
