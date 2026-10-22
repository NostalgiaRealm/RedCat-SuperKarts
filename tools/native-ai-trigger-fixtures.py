#!/usr/bin/env python3
"""Original NPC track-marker state writes and pickup timestamp callback."""
import json,random,struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,OBJECT,SCRATCH
from native_ai_fixture_track import install_track
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import *

def fp(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def word(x):return struct.pack('<I',x&0xffffffff)

def main():
    rng=random.Random(0x406470)
    out={'scope':'Original406470 and nested trigger writes; finish timer and visual/string allocation after native turbo state stores are boundaries. Original4067e0 dispatch order executes separately.',
         'triggers':[],'dispatch':[],'pickups':[],'hitMarkers':[]}
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE);p.uc.mem_map(0,0x1000);p.uc.mem_map(0x24000000,0x400000)
        p.uc.reg_write(UC_X86_REG_FPCW,cw)
        p.uc.mem_write(0x48f4d0,b'\xd9\x05'+word(SCRATCH+0x7100)+b'\xc3')
        p.uc.mem_write(0x417e30,b'\xc3')
        p.u32(0x53be28,4);p.u32(0x508610,4);p.u32(0x503ef0,0)
        p.u32(0x5081bc,0);p.u32(0x503f5c,0);p.u32(0x53b9b4,0)
        saved={};dispatch=False;calls=[]
        def hook(uc,address,size,data):
            nonlocal saved
            if address in [0x40dc10,0x40d610]:
                saved={reg:uc.reg_read(reg) for reg in [UC_X86_REG_ESP,UC_X86_REG_EBX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EBP]}
            if address in [0x40dc80,0x40d649]:
                sp=saved[UC_X86_REG_ESP]
                for reg,value in saved.items():uc.reg_write(reg,value)
                uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
            if dispatch and address==0x406470:
                sp=uc.reg_read(UC_X86_REG_ESP);calls.append(p.integer(sp+8))
                uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
        p.uc.hook_add(UC_HOOK_CODE,hook)
        out['sourceSha256']=p.sha
        for case in range(560):
            marker=[4,5,6,8,14,14,14,15,53,64,65,67,68,0][case%14]
            now=fp(rng.uniform(0,1000))
            body={'sector':rng.randrange(20),'lateralSpeed':fp(rng.uniform(-20,40)),
                  'verticalSpeed':fp(rng.uniform(-20,40)),'forwardSpeed':fp(rng.uniform(-20,40))}
            state={'mode':rng.choice([0,9,27,28]),'laps':rng.randrange(6),'finishMarker':rng.choice([0,14,15]),
                   'lastFinishTime':fp(now-rng.choice([0,10,10.001,11])),'speedLimit':fp(7),
                   'finished':False,'forcedRoute':bool(case%2),'recoveryCounter':3,
                   'slippery':bool(case%2),'turboVisible':False,'turboTime':fp(0)}
            options={'now':now,'circuit':bool(case%3),'lapCount':5,'playerForwardSpeed':fp(rng.uniform(-20,35)),
                     'drivingStyle':case%5+1,'previousEngineSector':body['sector'] if case%2 else body['sector']-1,
                     'speedLimits':{'4':12.5,'5':17.5,'6':25,'8':30},'precision':precision}
            for address,value in [(0x503ef4,state['mode']),(0x503efc,state['laps']),(0x503f1c,state['finishMarker']),
                 (0x503fc4,state['recoveryCounter']),(0x5081c0,0),(0x505938,options['drivingStyle']),
                 (0x53a6a4,int(options['circuit'])),(0x53ba1c,5),
                 (OBJECT+0x1c,body['sector']),(OBJECT+0x20,options['previousEngineSector'])]:
                p.u32(address,value&0xffffffff)
            for address,value in [(0x503f8c,state['forcedRoute']),(0x508214,state['slippery']),(0x503fe0,0)]:
                p.uc.mem_write(address,bytes([value]))
            for address,value in [(0x504008,state['lastFinishTime']),(0x503f20,state['speedLimit']),(0x503fe4,0),
                 (OBJECT+0x9c,body['lateralSpeed']),(OBJECT+0xa0,body['verticalSpeed']),(OBJECT+0xa4,body['forwardSpeed']),
                 (OBJECT+4*0xd0+0xa4,options['playerForwardSpeed']),(SCRATCH+0x7100,now)]:
                p.f32(address,value)
            for index,limit in enumerate(options['speedLimits'].values()):p.f32(0x50504c+index*4,limit)
            p.run(0x406470,[0,marker])
            expected={**state,'mode':p.integer(0x503ef4),'laps':p.integer(0x503efc),'finishMarker':p.integer(0x503f1c),
                      'lastFinishTime':p.float(0x504008),'speedLimit':p.float(0x503f20),'finished':bool(p.integer(0x5081c0)),
                      'forcedRoute':bool(p.uc.mem_read(0x503f8c,1)[0]),'recoveryCounter':p.integer(0x503fc4),
                      'slippery':bool(p.uc.mem_read(0x508214,1)[0]),'turboVisible':bool(p.uc.mem_read(0x503fe0,1)[0]),
                      'turboTime':p.float(0x503fe4)}
            out['triggers'].append({'body':body,'state':state,'marker':marker,'options':options,'expectedState':expected,
                                    'expectedBody':{**body,'forwardSpeed':p.float(OBJECT+0xa4)}})
        for track_id in range(6):
            track=json.loads((ROOT/f'public/assets/tracks/etappe{track_id}.json').read_text());install_track(p,track)
            for index,route in enumerate(track['route']):
                p.u32(0x24000000+index*0x984+0xec,route['trigger'])
                p.u32(0x24000000+index*0x984+0xf0,route['unknown'])
            for case in range(100):
                sector=rng.randrange(len(track['route']));nodes=track['route'][sector]['driveIndices']
                waypoint=rng.choice(nodes) if nodes else rng.randrange(len(track['drive']))
                p.u32(OBJECT+0x1c,sector);p.u32(OBJECT+0x24,waypoint)
                calls=[];dispatch=True;p.run(0x4067e0,[0]);dispatch=False
                out['dispatch'].append({'track':track_id,'body':{'sector':sector,'waypoint':waypoint},'expected':calls})
        for case in range(60):
            state={'mode':rng.choice([0,9,25,26]),'lastBonusTime':fp(rng.uniform(0,100))}
            now=fp(rng.uniform(0,10000));p.u32(0x503ef4,state['mode']);p.f32(SCRATCH+0x7100,now)
            p.f32(0x504004,state['lastBonusTime']);p.run(0x40d610,[0])
            out['pickups'].append({'state':state,'now':now,'expectedState':{**state,'lastBonusTime':p.float(0x504004)}})
        for case in range(60):
            state={'mode':rng.choice([0,9,25,26]),'hitVisible':bool(case%2),'hitTime':fp(rng.uniform(0,100))}
            now=fp(rng.uniform(0,10000));p.u32(0x503ef4,state['mode']);p.f32(SCRATCH+0x7100,now)
            p.f32(0x503fe8,state['hitTime']);p.uc.mem_write(0x508215,bytes([state['hitVisible']]))
            p.run(0x40ddd0,[0])
            out['hitMarkers'].append({'state':state,'now':now,'expectedState':{**state,
                'hitVisible':bool(p.uc.mem_read(0x508215,1)[0]),'hitTime':p.float(0x503fe8)}})
    (ROOT/'evidence/native/ai-trigger-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
    print({key:len(out[key]) for key in ['triggers','dispatch','pickups','hitMarkers']})
if __name__=='__main__':main()
