#!/usr/bin/env python3
"""Original scenery physics, current-frame rectangle and slope-frame routines."""
import json, random, struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_ECX, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig

rng=random.Random(0x43f1b0)
out={'method':'Original x86 instructions; logger and INI value retrieval stubbed.',
     'functions':['0043f1b0','0043f200','0043f2c0','0043f360','0043f3b0','0043d130',
                  '0048fda0','004939d0','00499630','00494b90'],
     'physics':[],'rectangles':[],'slopes':[],'groundPoses':[],'integration':[]}
fields={'inverseMass':0x90,'inverseInertia':0x94,'restitution':0x98,
        'lateralSpeed':0x9c,'verticalSpeed':0xa0,'forwardSpeed':0xa4,'yawRate':0xac}
for precision,cw in [(24,0x7f),(53,0x27f)]:
    p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);out['sourceSha256']=p.sha
    p.uc.mem_write(0x4afce0,b'\xc3');p.uc.mem_write(0x4afee0,b'\xc3')
    p.uc.mem_write(0x43d300,b'\xc3')
    current={}
    def hook(uc,address,size,data):
        if address==0x43d300:
            dest=p.integer(uc.reg_read(UC_X86_REG_ESP)+8)
            for i,value in enumerate([current['mass'],current['speed'],0,current['inertia']]):
                p.f32(dest+i*4,value)
    p.uc.hook_add(UC_HOOK_CODE,hook)
    for typ,fn in [(5,0x43f1b0),(8,0x43f200),(25,0x43f2c0),(24,0x43f360),(23,0x43f3b0),(6,0x43d130)]:
        for i in range(16):
            p.uc.mem_write(OBJECT,b'\0'*0xd0)
            p.uc.mem_write(0x67ee78,b'\0'*(0x67fe18-0x67ee78))
            current={'mass':rng.choice([0,.05,.1,300,400,13000]),'speed':rng.uniform(-10,20),'inertia':rng.choice([0,.001,1])}
            section={'massa':current['mass'],'snelheid':current['speed'],'inertia':current['inertia']}
            for k in current:current[k]=struct.unpack('<f',struct.pack('<f',current[k]))[0]
            p.run(fn,[0,0,0,0])
            out['physics'].append({'precision':precision,'type':typ,'section':section,
                'expected':{key:p.float(OBJECT+offset)for key,offset in fields.items()},
                'physical':p.integer(OBJECT),'registered':[p.integer(0x67ee78),p.integer(0x67ee7c)]})
    AUX=0x23000000;p.uc.mem_map(AUX,0x10000);p.u32(0x6a5ee0,AUX)
    p.uc.mem_write(0x490ce0,b'\x31\xc0\xc3')
    for case in range(120):
        bounds={'minX':rng.uniform(-300,-1),'maxX':rng.uniform(1,300),
                'minY':rng.uniform(-30,0),'maxY':rng.uniform(1,80),
                'minZ':rng.uniform(-300,-1),'maxZ':rng.uniform(1,300)}
        bounds={k:struct.unpack('<f',struct.pack('<f',v))[0]for k,v in bounds.items()}
        corners=[[bounds['minX'],bounds['minY'],bounds['minZ']],
                 [bounds['maxX'],bounds['minY'],bounds['minZ']],
                 [bounds['maxX'],bounds['minY'],bounds['maxZ']],
                 [bounds['minX'],bounds['minY'],bounds['maxZ']]]
        for offset,corner in zip([0x10,0x1c,0x4c,0x40],corners):
            for k,v in enumerate(corner):p.f32(AUX+offset+4*k,v)
        position=[rng.uniform(-5000,5000)for _ in range(3)]
        for k,v in enumerate(position):
            p.f32(SCRATCH+0x4050+k*4,v);position[k]=p.float(SCRATCH+0x4050+k*4)
        yaw=rng.uniform(-8192,8192);p.f32(SCRATCH+0x4078,yaw);yaw=p.float(SCRATCH+0x4078)
        p.f32(AUX+0x74,123);p.u32(OBJECT+0xc,0);p.u32(OBJECT+0x44,1);p.u32(0x6847c8,0)
        p.run(0x499630,[0])
        out['rectangles'].append({'precision':precision,'body':{'bounds':bounds,'position':position,'yaw':yaw},
            'corners':list(struct.unpack('<12f',p.uc.mem_read(0x680c68,48))),
            'position':list(struct.unpack('<3f',p.uc.mem_read(0x680c98,12))),
            'angle':struct.unpack('<i',p.uc.mem_read(0x680cac,4))[0],
            'radius':p.float(0x680ca4),'count':p.integer(0x6847c8)})
    for k in range(16):p.f32(0x6a5c90+k*4,int(k in [0,5,10,15]));p.f32(0x6a5cd8+k*4,0)
    for case in range(180):
        forward=[rng.uniform(-1,1),rng.uniform(-.5,.5),rng.uniform(-1,1)]
        for k,v in enumerate(forward):
            p.f32(AUX+0x48+4*k,v);forward[k]=p.float(AUX+0x48+4*k)
        p.uc.reg_write(UC_X86_REG_ECX,AUX);p.run(0x494b90)
        matrix=[p.float(AUX+0x9c+(row*4+col)*4)for row in range(3)for col in range(3)]
        out['slopes'].append({'precision':precision,'forward':forward,'expected':matrix})
        p.u32(0x680b28,AUX);p.u32(0x68021c,AUX+0xf000);p.u32(AUX+0xf000,0)
        p.u32(OBJECT+0x58,0);p.u32(OBJECT+0x1c,0)
        pose=[rng.uniform(-1,1)for _ in range(9)]
        for row in range(3):
            for col in range(3):
                addr=SCRATCH+0x4010+(row*4+col)*4
                p.f32(addr,pose[row*3+col]);pose[row*3+col]=p.float(addr)
        for k in [3,7,11,12,13,14,15]:p.f32(SCRATCH+0x4010+k*4,0)
        p.run(0x4936a0,[0])
        expected=[p.float(SCRATCH+0x4010+(row*4+col)*4)for row in range(3)for col in range(3)]
        out['groundPoses'].append({'precision':precision,'forward':forward,'pose':pose,'expected':expected})
    initialize_native_trig(p)
    for address in [0x493860,0x4932e0,0x4936a0,0x4a09e0]:p.uc.mem_write(address,b'\xc3')
    p.uc.mem_write(0x49c6e0,b'\x31\xc0\xc3')
    p.u32(0x680ad0,0);p.u32(0x680ad8,0xffffffff);p.u32(0x67ee24,1)
    p.u32(0x67ee30,SCRATCH+0xa000);p.uc.mem_write(SCRATCH+0xa000,b'\x01')
    calls=[]
    def integration_hook(uc,address,size,data):
        if address==0x4911a0:
            sp=uc.reg_read(UC_X86_REG_ESP)
            calls.append({'dt':p.float(sp+4),'fraction':p.float(sp+8)})
    p.uc.hook_add(UC_HOOK_CODE,integration_hook)
    for case in range(120):
        p.uc.mem_write(OBJECT,b'\0'*0xd0);p.u32(OBJECT,1);p.u32(OBJECT+0x44,1)
        p.uc.mem_write(0x67ee78,b'\0'*(0x67fe18-0x67ee78));p.u32(0x67ee78,1);p.u32(0x67ee7c,0)
        route_count=rng.choice([104,250]);player_sector=rng.randrange(route_count);sector=rng.randrange(route_count)
        visible=rng.choice([15,25,40]);always=bool(case%3==0);dt=rng.choice([.025,.0625,.1])
        p.u32(0x680220,route_count);p.u32(OBJECT+0x1c,sector);p.u32(OBJECT+0x50,int(always))
        p.f32(SCRATCH+0x1000,dt)
        state={'x':rng.uniform(-1000,1000),'y':rng.uniform(-50,50),'z':rng.uniform(-1000,1000),'yaw':rng.uniform(-5000,5000),
            'lateralSpeed':rng.uniform(-10,10),'verticalSpeed':0,'forwardSpeed':rng.uniform(-10,10),
            'yawRate':rng.uniform(-1,1),'inverseMass':.0025,'inverseInertia':0}
        for key,offset in [('x',0x50),('y',0x54),('z',0x58),('yaw',0x78)]:
            p.f32(SCRATCH+0x4000+offset,state[key]);state[key]=p.float(SCRATCH+0x4000+offset)
        for key,offset in fields.items():
            p.f32(OBJECT+offset,state.get(key,0))
            if key in state:state[key]=p.float(OBJECT+offset)
        calls.clear();p.run(0x491d30,[player_sector,visible*2,0xffffffff])
        expected={key:p.float(SCRATCH+0x4000+offset)for key,offset in [('x',0x50),('y',0x54),('z',0x58),('yaw',0x78)]}
        expected.update({key:p.float(OBJECT+offset)for key,offset in fields.items()if key in state})
        out['integration'].append({'precision':precision,'state':state,'dt':dt,'alwaysUpdate':always,
            'sector':sector,'playerSector':player_sector,'visibleChunks':visible,'routeCount':route_count,
            'expected':expected,'calls':list(calls)})
(ROOT/'evidence/native/scenery-contact-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print({key:len(out[key])for key in ['physics','rectangles','slopes','groundPoses','integration']})
