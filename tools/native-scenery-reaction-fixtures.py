#!/usr/bin/env python3
"""Execute original type2 overlap, launch, flight/bounce and settling kernels."""
import json, random, struct
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig

rng=random.Random(0x43fe80)
out={'functions':['497bd0','43df60','43c5c0','43c870','43cbf0'],
     'method':'Original x86; flight sector and route-plane query stubbed to supplied values.',
     'overlap':[],'launch':[],'flight':[],'settle':[]}
fields={'pitchRate':0xa8,'rollRate':0xb0,'gravity':0x40}
poses={'pitch':0x74,'yaw':0x78,'roll':0x7c}
for precision,cw in [(24,0x7f),(53,0x27f)]:
    p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);out['sourceSha256']=p.sha
    initialize_native_trig(p)
    p.u32(0x4fc6e8,0) # Game42ccf0 selects Z,X,Y, replacing PE default1.
    p.uc.mem_write(0x4afce0,b'\xc3');p.uc.mem_write(0x4afee0,b'\xc3')
    p.uc.mem_write(0x4932e0,b'\xc3')
    p.uc.mem_write(0x494b70,b'\xd9\x05'+struct.pack('<I',SCRATCH+0x1100)+b'\xc2\x08\x00')
    p.u32(0x68021c,SCRATCH+0xb000);p.u32(SCRATCH+0xb000,0)
    p.u32(0x6a5ee0,SCRATCH+0xc000);p.u32(0x53be28,1)
    def put_object(state,index=0):
        base=OBJECT+index*0xd0;render=SCRATCH+0x4000+index*0xa9
        p.uc.mem_write(base,b'\0'*0xd0);p.uc.mem_write(render,b'\0'*0xa9)
        p.u32(base+0xc,index);p.u32(render,1);p.u32(render+0x99,index)
        for offset in [0x80,0x84,0x88]:p.f32(render+offset,1)
        for key,offset in fields.items():
            p.f32(base+offset,state.get(key,0));state[key]=p.float(base+offset)
        for key,offset in poses.items():
            p.f32(render+offset,state.get(key,0));state[key]=p.float(render+offset)
        for i,value in enumerate(state.get('velocity',[0,0,0])):
            p.f32(base+0x9c+4*i,value)
        state['velocity']=[p.float(base+0x9c+4*i)for i in range(3)]
        for i,value in enumerate(state.get('position',[0,0,0])):p.f32(render+0x50+4*i,value)
        state['position']=[p.float(render+0x50+4*i)for i in range(3)]
        p.f32(SCRATCH+0xc074+index*0xbc,state.get('radius',20))
        state['radius']=p.float(SCRATCH+0xc074+index*0xbc)
        p.u32(base+0x14,state.get('mode',0))
    def read_object():
        base=OBJECT;render=SCRATCH+0x4000
        return {**{key:p.float(base+offset)for key,offset in fields.items()},
            **{key:p.float(render+offset)for key,offset in poses.items()},
            'velocity':[p.float(base+0x9c+4*i)for i in range(3)],
            'position':[p.float(render+0x50+4*i)for i in range(3)],
            'mode':p.integer(base+0x14),
            'matrix':[p.float(render+0x10+(row*4+col)*4)for row in range(3)for col in range(3)]}
    for i in range(120):
        first={'position':[rng.uniform(-50,50),rng.uniform(-999,999),rng.uniform(-50,50)],'radius':rng.uniform(1,40)}
        second={'position':[rng.uniform(-50,50),rng.uniform(-999,999),rng.uniform(-50,50)],'radius':rng.uniform(1,40)}
        put_object(first);put_object(second,1);p.run(0x497bd0,[0,1])
        out['overlap'].append({'precision':precision,'object':first,'player':second,'expected':bool(p.uc.reg_read(UC_X86_REG_EAX))})
        object_={'yaw':rng.uniform(-8192,8192)}
        player={'yaw':rng.uniform(-8192,8192),'velocity':[rng.uniform(-12,12),0,rng.uniform(-15,90)]}
        put_object(object_);put_object(player,1)
        seed=rng.randrange(2**32);p.u32(0x502978,seed);p.run(0x43c5c0,[0,4.0,0.0])
        out['launch'].append({'precision':precision,'object':object_,'player':player,'seed':seed,
            'expected':read_object(),'randomState':p.integer(0x502978)})
    for mode,name,fn in [(1,'flight',0x43c870),(3,'settle',0x43cbf0)]:
        for i in range(180):
            state={'position':[rng.uniform(-1000,1000),rng.uniform(-20,100),rng.uniform(-1000,1000)],
                'velocity':[rng.uniform(-15,15),rng.uniform(-20,20),rng.uniform(-50,50)],
                'pitch':rng.uniform(-1400,1400),'yaw':rng.uniform(-8192,8192),'roll':rng.uniform(-1400,1400),
                'pitchRate':rng.uniform(-40,40),'rollRate':rng.uniform(-40,40),'gravity':-45,
                'mode':mode,'radius':rng.uniform(5,40)}
            put_object(state)
            dt=rng.choice([.025,.0625,.1]);ground=rng.uniform(-10,10)
            p.f32(SCRATCH+0x1000,dt);dt=p.float(SCRATCH+0x1000)
            p.f32(SCRATCH+0x1100,ground);ground=p.float(SCRATCH+0x1100)
            p.run(fn,[0,1024,2.0]if mode==1 else[0,1024])
            out[name].append({'precision':precision,'state':state,'dt':dt,'ground':ground,
                'expected':read_object(),'returnValue':bool(p.uc.reg_read(UC_X86_REG_EAX))})
(ROOT/'evidence/native/scenery-reaction-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print({key:len(out[key])for key in ['overlap','launch','flight','settle']})
