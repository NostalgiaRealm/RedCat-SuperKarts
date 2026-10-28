#!/usr/bin/env python3
"""Original 499c30 sweep and 492470 slide with controlled native bbox inputs."""
import json
import math
import random
import struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_FPCW, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX

rng=random.Random(0x499c30)
out={'routines':['0x499c30','0x492470'],'cases':[],
     'method':'Original x86 code. Candidate discovery and model bbox reads replaced by controlled records; sweep, contact construction and slide execute unchanged. '
              'Appended cases cover zero yaw rate (0x499c93, 0x49a02e) and rails ahead of karts in the 0x499b20 order, with rail records laid out as 0x4997f0 writes them.'}
bounds={'minX':-20.726268768310547,'maxX':20.106887817382812,
        'minZ':-27.615097045898438,'maxZ':36.38368225097656}
f32=lambda value:struct.unpack('<f',struct.pack('<f',value))[0]
extra_cases=[]
for precision,cw in [(24,0x7f),(53,0x27f)]:
    p=NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW,cw)
    initialize_native_trig(p)
    out['sourceSha256']=p.sha
    state={'rails':[]}
    def rectangle(address,body,index):
        b=body.get('bounds',bounds);y=b.get('minY',0)
        values=[b['minX'],y,b['minZ'],b['maxX'],y,b['minZ'],
                b['maxX'],y,b['maxZ'],b['minX'],y,b['maxZ'],
                *body['position']]
        for offset,value in enumerate(values):p.f32(address+offset*4,value)
        p.f32(address+0x3c,42)
        p.u32(address+0x40,index)
        p.u32(address+0x44,(math.ceil(body['yaw']) if body['yaw']>0 else math.floor(body['yaw']))&0xffffffff)
        p.u32(address+0x48,1)
    def rail(address,record):
        # 0x4997f0: corners (-10,0,-1),(0,0,-1),(0,0,len+1),(-10,0,len+1), radius 0,
        # id -1, rounded heading, type 0.
        values=[record['minX'],0,record['minZ'],record['maxX'],0,record['minZ'],
                record['maxX'],0,record['maxZ'],record['minX'],0,record['maxZ'],
                *record['position']]
        for offset,value in enumerate(values):p.f32(address+offset*4,value)
        p.f32(address+0x3c,0)
        p.u32(address+0x40,0xffffffff)
        p.u32(address+0x44,record['angle']&0xffffffff)
        p.u32(address+0x48,0)
    def hook(uc,address,size,data):
        if address not in [0x499b20,0x4999c0]:return
        sp=uc.reg_read(UC_X86_REG_ESP)
        if address==0x499b20:
            # 0x499b20 appends the three sectors' rails before objects.
            for index,record in enumerate(state['rails']):rail(0x680c68+index*0x4c,record)
            base=len(state['rails'])
            for index,body in enumerate(state['others']):rectangle(0x680c68+(base+index)*0x4c,body,index+1)
            p.u32(0x6847c8,base+len(state['others']))
        else:rectangle(p.integer(sp+8),state['body'],0)
        uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
        uc.reg_write(UC_X86_REG_ESP,sp+4)
    p.uc.hook_add(UC_HOOK_CODE,hook)
    def native_float(value):
        p.f32(SCRATCH+0xf000,value);return p.float(SCRATCH+0xf000)
    def execute(body,others,dt,rails=(),identity=False):
        state.update(body=body,others=others,rails=list(rails))
        p.u32(OBJECT+0x44,1);p.u32(OBJECT+4,3)
        for key,offset in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac)]:
            p.f32(OBJECT+offset,body[key])
        fraction=p.run(0x499c30,[0,SCRATCH+0xa000,dt],True)
        assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH+0x106,'0x499c30 did not return'
        contact=None
        if p.integer(0x6a5b58):
            contact={'first':p.integer(0x6a5b60),'second':p.integer(0x6a5b64),
                     'point':[p.float(0x6a5b68+i*4) for i in range(3)],
                     'normal':[p.float(0x6a5b74+i*4) for i in range(3)]}
            # 0x49c540 writes 0x6a5b5c=1 only for two dynamic records.
            if identity:contact['dynamic']=bool(p.integer(0x6a5b5c))
        expected={'fraction':fraction,'stopYaw':bool(p.integer(SCRATCH+0xa000)),'contact':contact}
        # 492470 returns EAX, writes its optional displacement at param3.
        p.run(0x492470,[0,dt,SCRATCH+0xa100,float(fraction),SCRATCH+0xa000])
        assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH,'0x492470 did not return'
        if p.uc.reg_read(UC_X86_REG_EAX):
            expected['velocityOverride']=[p.float(SCRATCH+0xa100+i*4) for i in range(3)]
        expected['stopYaw']=bool(p.integer(SCRATCH+0xa000))
        return expected
    for case in range(180):
        body={'position':[rng.uniform(-50,50),0,rng.uniform(-50,50)],'yaw':rng.uniform(-4096,4096),
              'lateralSpeed':rng.uniform(-10,10),'verticalSpeed':rng.uniform(-1,1),
              'forwardSpeed':rng.uniform(-20,60),'yawRate':rng.uniform(-4,4),'sector':0}
        others=[{'position':[rng.uniform(-50,50),0,rng.uniform(-50,50)],
                 'yaw':rng.uniform(-4096,4096),'sector':0} for _ in range(1+case%2)]
        for item in [body,*others]:
            if case>=120:
                item['bounds']={k:f32(v)for k,v in {
                    'minX':rng.uniform(-100,-5),'maxX':rng.uniform(5,100),
                    'minZ':rng.uniform(-100,-5),'maxZ':rng.uniform(5,100),
                    'minY':rng.uniform(-30,30)}.items()}
            for key in ['yaw','lateralSpeed','verticalSpeed','forwardSpeed','yawRate']:
                if key in item:item[key]=native_float(item[key])
            for axis,value in enumerate(item['position']):item['position'][axis]=native_float(value)
        dt=native_float(rng.choice([.003125,.025,.03125,.1]))
        expected=execute(body,others,dt)
        out['cases'].append({'precision':precision,'bounds':bounds,'body':body,'others':others,'dt':dt,'expected':expected})
    # Appended cases use their own generator, reseeded per precision, so both
    # control words see the same inputs and the 360 cases above stay unchanged.
    extra=random.Random(0x499c31)
    def random_bounds():
        return {k:f32(v)for k,v in {
            'minX':extra.uniform(-60,-5),'maxX':extra.uniform(5,60),
            'minZ':extra.uniform(-60,-5),'maxZ':extra.uniform(5,60),
            'minY':extra.uniform(-30,30)}.items()}
    def rotate(x,z,angle):
        t=2*math.pi*(angle&4095)/4096
        return math.cos(t)*x-math.sin(t)*z,math.sin(t)*x+math.cos(t)*z
    def target(body,dt,clearance,spread):
        # Most candidates are placed along the 0x499f47 world travel
        # direction, so the sweep fraction is often strictly between 0 and 1.
        yaw=body['yaw'];angle=math.ceil(yaw) if yaw>0 else math.floor(yaw)
        dx,dz=rotate(body['lateralSpeed']*dt*10,body['forwardSpeed']*dt*10,angle)
        length=math.hypot(dx,dz);x,_,z=body['position']
        if length==0 or extra.random()<.35:
            heading,distance=extra.uniform(0,2*math.pi),extra.uniform(clearance,clearance+70)
            return x+distance*math.cos(heading),z+distance*math.sin(heading)
        k=(length*extra.uniform(*spread)+clearance)/length
        return x+dx*k,z+dz*k
    def reach(item):
        b=item.get('bounds',bounds)
        return max(math.hypot(x,z) for x in (b['minX'],b['maxX']) for z in (b['minZ'],b['maxZ']))
    def random_rail(body,dt):
        # 0x4997f0 rounds (atan2-pi/2)*4096/2pi away from zero: -3072..1024.
        angle=extra.choice([0,1,-1,1024,-1024,-2048,-3072,extra.randint(-3072,1024),extra.randint(-3072,1024)])
        length=f32(extra.uniform(4,160))
        x,z=target(body,dt,reach(body)*extra.uniform(.5,1.1)+5,(.15,1.3))
        mx,mz=rotate(-5,length/2,angle)
        return {'minX':-10.0,'maxX':0.0,'minZ':-1.0,'maxZ':f32(length+1),
                'position':[f32(x-mx),f32(extra.uniform(-8,8)),f32(z-mz)],'angle':angle,'type':0}
    def random_case(index,yaw_rate,variant=None):
        body={'position':[extra.uniform(-50,50),0,extra.uniform(-50,50)],'yaw':extra.uniform(-4096,4096),
              'lateralSpeed':extra.uniform(-10,10),'verticalSpeed':extra.uniform(-1,1),
              'forwardSpeed':extra.uniform(-20,60),'yawRate':yaw_rate,'sector':0}
        if variant in (0,1):body['lateralSpeed']=0.0
        if variant in (0,2):body['forwardSpeed']=0.0
        if variant==3:body['verticalSpeed']=0.0
        if variant==4:body['lateralSpeed']=-0.0;body['forwardSpeed']=0.0;body['verticalSpeed']=extra.uniform(-5,5)
        for key in ['yaw','lateralSpeed','verticalSpeed','forwardSpeed','yawRate']:body[key]=native_float(body[key])
        dt=native_float(extra.choice([.003125,.025,.03125,.1,.1]))
        others=[{'position':[0,0,0],'yaw':extra.uniform(-4096,4096),'sector':0} for _ in range(1+index%2)]
        if index%3==2:
            for item in [body,*others]:item['bounds']=random_bounds()
        for item in others:
            x,z=target(body,dt,(reach(body)+reach(item))*extra.uniform(.6,1.1),(.05,1))
            item['position']=[x,0,z]
        for item in [body,*others]:
            item['yaw']=native_float(item['yaw'])
            for axis,value in enumerate(item['position']):item['position'][axis]=native_float(value)
        return body,others,dt
    # Zero yaw rate: 0x49a02e skips the overlap stop; 0x499c93 completes the
    # all-zero early return, which ignores vertical speed (variant 4). Signed
    # zero, zero lateral or forward speed and zero vertical speed.
    for index in range(90):
        body,others,dt=random_case(index,-0.0 if index%2 else 0.0,index%9)
        extra_cases.append({'precision':precision,'bounds':bounds,'body':body,'others':others,'dt':dt,
                            'expected':execute(body,others,dt,identity=True)})
    # Rails and karts together, rails first as 0x499b20 lists them.
    for index in range(120):
        body,others,dt=random_case(index,0.0 if index%4==3 else extra.uniform(-4,4))
        rails=[random_rail(body,dt) for _ in range(1+index%3)]
        extra_cases.append({'precision':precision,'bounds':bounds,'body':body,'others':others,'rails':rails,'dt':dt,
                            'expected':execute(body,others,dt,rails,identity=True)})
out['cases'].extend(extra_cases)
(ROOT/'evidence/native/kart-sweep-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'native dynamic sweep and slide cases')
