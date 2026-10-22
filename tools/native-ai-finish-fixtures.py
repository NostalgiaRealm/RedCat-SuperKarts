#!/usr/bin/env python3
"""Original finished-racer movement and separate NPC finish-timer writes."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,OBJECT,SCRATCH
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import *
def word(x):return struct.pack('<I',x&0xffffffff)
def main():
    rng=random.Random(0x409ea0)
    output={'routines':['409ea0','417e30'],'scope':'Original finished movement including steering/spring/wobble; explicit route height. Original finish recorder with supplied timer reads and captured pause calls.',
            'movement':[],'timers':[]}
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);initialize_native_trig(p)
        p.u32(0x503ef0,0);p.u32(0x5081bc,0);p.u32(0x508610,4)
        p.u32(0x68021c,SCRATCH+0xa000);p.u32(SCRATCH+0xa000,0);p.u32(0x680b28,SCRATCH+0xa100)
        p.uc.mem_write(0x4977d0,b'\x31\xc0\xc2\x10\x00')
        p.uc.mem_write(0x494b70,b'\xd9\x05'+word(SCRATCH+0x9200)+b'\xc2\x08\x00')
        p.u32(0x53bef4,0);p.u32(0x50728c,1);p.u32(0x507294,1)
        addresses={'x':SCRATCH+0x4050,'y':SCRATCH+0x4054,'z':SCRATCH+0x4058,'yaw':SCRATCH+0x4078,
                   'pitch':SCRATCH+0x4074,'roll':SCRATCH+0x407c,'forwardSpeed':OBJECT+0xa4,
                   'lateralSpeed':OBJECT+0x9c,'verticalSpeed':OBJECT+0xa0,'yawRate':OBJECT+0xac,
                   'pitchRate':OBJECT+0xa8,'rollRate':OBJECT+0xb0}
        states={'turnTime':0x503f3c,'turnIntegral':0x503f40,'turnStartHeading':0x503f44,'specialTime':0x503ffc}
        controls={'steering':0x503f28,'throttle':0x503f2c,'brake':0x503f30}
        for case in range(180):
            preset,record,player_record=case%3,case%9,(case//9)%9
            p.uc.mem_write(0x5068d0,(SOURCE/f'cars{preset}.dat').read_bytes());p.u32(0x503f24,record);p.u32(0x53be2c,player_record)
            body={key:rng.uniform(-10,10) for key in addresses}
            body.update(yaw=rng.uniform(-4096,8192),forwardSpeed=rng.uniform(-20,90))
            for key,address in addresses.items():p.f32(address,body[key]);body[key]=p.float(address)
            state={key:rng.uniform(-1,1) for key in states};state.update(disabled=False,special=bool(case%2))
            for key,address in states.items():p.f32(address,state[key]);state[key]=p.float(address)
            p.u32(0x503f34,0);p.u32(0x503ff8,int(state['special']))
            control={'steering':rng.choice([-100,0,99,100]),'throttle':50,'brake':25}
            for key,address in controls.items():p.f32(address,control[key])
            dt=rng.choice([.001,.025,.03125,.1]);p.f32(SCRATCH+0x1000,dt)
            p.f32(SCRATCH+0x9200,rng.uniform(-5,5));height=p.float(SCRATCH+0x9200)
            seed=rng.randrange(2**32);p.u32(0x502978,seed)
            p.run(0x409ea0,[0])
            output['movement'].append({'precision':precision,'preset':preset,'record':record,'playerRecord':player_record,
                'body':body,'state':state,'controls':control,'dt':dt,'height':height,'seed':seed,'randomState':p.integer(0x502978),
                'expected':{'body':{key:p.float(address) for key,address in addresses.items()},
                            'state':{**state,**{key:p.float(address) for key,address in states.items()},'disabled':bool(p.integer(0x503f34))},
                            'controls':{key:p.float(address) for key,address in controls.items()}}})
        output['sourceSha256']=p.sha
    p=NativeProbe(SOURCE);p.u32(0x508610,4)
    timer_values=[];calls=[]
    def hook(uc,address,size,data):
        if address not in [0x42a4d0,0x42a280]:return
        sp=uc.reg_read(UC_X86_REG_ESP);timer=p.integer(sp+4)
        calls.append([address==0x42a4d0 and 'read' or 'pause',timer])
        if address==0x42a4d0:uc.reg_write(UC_X86_REG_EAX,timer_values[timer-9])
        uc.reg_write(UC_X86_REG_EIP,p.integer(sp));uc.reg_write(UC_X86_REG_ESP,sp+4)
    p.uc.hook_add(UC_HOOK_CODE,hook)
    for case in range(120):
        opponents=[{'objectId':rng.randrange(8),'finished':bool(case%2),'finishTimeMs':rng.randrange(1000000)} for i in range(4)]
        target=rng.randrange(8);timer_values=[rng.randrange(2**32) for _ in range(4)]
        for i,actor in enumerate(opponents):
            p.u32(0x5081bc+i*0x70,actor['objectId']);p.u32(0x5081c0+i*0x70,int(actor['finished']))
            p.u32(0x5081b4+i*0x70,actor['finishTimeMs'])
        calls=[];p.run(0x417e30,[target])
        output['timers'].append({'objectId':target,'opponents':opponents,'timerValues':timer_values,'calls':calls,
            'expected':[{'objectId':a['objectId'],'finished':bool(p.integer(0x5081c0+i*0x70)),
                         'finishTimeMs':p.integer(0x5081b4+i*0x70)} for i,a in enumerate(opponents)]})
    (ROOT/'evidence/native/ai-finish-fixtures.json').write_text(json.dumps(output,indent=2)+'\n')
    print('Wrote',len(output['movement']),'finished movement and',len(output['timers']),'timer cases')
if __name__=='__main__':main()
