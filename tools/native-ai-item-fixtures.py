#!/usr/bin/env python3
"""Execute original NPC weapon decisions, reaction clocks and catch-up states."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_ai_fixture_track import install_track
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW

def word(x): return struct.pack('<I', x & 0xffffffff)
def fp(x): return struct.unpack('<f', struct.pack('<f', x))[0]
def signed(x): return x if x < 0x80000000 else x - 0x100000000

def main():
    rng = random.Random(0x40cde0)
    config = json.loads((ROOT / 'public/assets/config.json').read_text())['npc_ai.ini']['rcr_global']
    out = {'routines': ['406320', '410420', '40cde0', '40d070', '40c010', '40eb20', '40eba0', '40e690'],
           'boundaries': ['absolute and delta clocks', 'owned-item container lookup',
                          'player protected flag', 'catch-up announcement audio after original state mutation',
                          'fire handler callback and subsequent normal movement'],
           'geometry': [], 'decisions': [], 'catchup': [], 'duration': [], 'fire': []}
    for precision, cw in [(24, 0x7f), (53, 0x27f)]:
        p = NativeProbe(SOURCE)
        p.uc.reg_write(UC_X86_REG_FPCW, cw)
        p.uc.mem_map(0, 0x1000)
        p.uc.mem_map(0x24000000, 0x400000)
        p.uc.mem_write(0x4afce0, b'\xc3')
        p.uc.mem_write(0x451450, b'\xb8' + word(SCRATCH+0x7000) + b'\xc3')
        p.uc.mem_write(0x4513c0, b'\xb8' + word(SCRATCH+0x7000) + b'\xc3')
        p.uc.mem_write(0x452120, b'\xb8' + word(SCRATCH+0x6004) + b'\xc2\x04\x00')
        p.uc.mem_write(0x48f4d0, b'\xd9\x05' + word(SCRATCH+0x7100) + b'\xc3')
        p.uc.mem_write(0x435a30, b'\xb8' + word(SCRATCH+0x7200) + b'\xc3')
        p.u32(0x505a20, SCRATCH+0x8000)
        for level in range(1, 6):
            for offset, key in [(0x1a0, 'reaction'), (0x1f0, 'catchup'), (0x204, 'catchup_dur')]:
                p.u32(SCRATCH+0x8000+offset+4*level, int(config[f'{key}{level}']))
        p.u32(0x503ef0, 0); p.u32(0x503f5c, 0); p.u32(0x503fcc, 0)
        p.u32(0x508610, 4); p.u32(0x53be28, 4)
        out['sourceSha256'] = p.sha
        announce, calls = False, []
        def hook(uc, address, size, data):
            nonlocal announce
            sp = uc.reg_read(UC_X86_REG_ESP)
            if address == 0x40d9c0:
                announce = bool(p.integer(sp+8) & 255)
            if address == 0x40da0e:
                # Original guards and state mutation have completed. Skip speech.
                uc.reg_write(UC_X86_REG_EIP, 0x40dbbb)
            if address in [0x451640, 0x40e180]:
                calls.append('fire' if address == 0x451640 else 'normal')
                uc.reg_write(UC_X86_REG_EAX, 1)
                uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
                uc.reg_write(UC_X86_REG_ESP, sp + (8 if address == 0x451640 else 4))
        p.uc.hook_add(UC_HOOK_CODE, hook)
        for track_id in range(6):
            track = json.loads((ROOT / f'public/assets/tracks/etappe{track_id}.json').read_text())
            install_track(p, track)
            p.u32(0x680b2c, len(track['route']))
            for case in range(60):
                racers = []
                for i in range(5):
                    sector = rng.randrange(len(track['route']))
                    nodes = track['route'][sector]['driveIndices']
                    waypoint = rng.choice(nodes) if nodes else rng.randrange(len(track['drive']))
                    pos = track['drive'][waypoint]['position']
                    body = {'id': i, 'sector': sector, 'waypoint': waypoint,
                            'x': fp(pos[0]+rng.uniform(-25,25)), 'z': fp(pos[2]+rng.uniform(-25,25)), 'yaw': fp(rng.uniform(0,4096))}
                    racers.append(body)
                    p.u32(OBJECT+i*0xd0+0xc, i)
                    p.u32(OBJECT+i*0xd0+0x1c, sector)
                    p.u32(OBJECT+i*0xd0+0x24, waypoint)
                    p.u32(0x5081bc+i*0x70, i)
                    for offset,key in [(0x50,'x'),(0x58,'z'),(0x78,'yaw')]:
                        p.f32(SCRATCH+0x4000+i*0xa9+offset, body[key])
                target = track['drive'][racers[4]['waypoint']]['position']
                for axis,value in enumerate(target): p.f32(SCRATCH+0x7400+axis*4,value)
                p.run(0x406320,[0,SCRATCH+0x7400])
                behind = bool(p.uc.reg_read(UC_X86_REG_EAX))
                p.u32(SCRATCH+0x7410,0)
                p.run(0x410420,[0,2,SCRATCH+0x7410])
                nearest = signed(p.uc.reg_read(UC_X86_REG_EAX))
                out['geometry'].append({'precision':precision,'track':track_id,'racers':racers,
                    'behind':behind,'nearest':nearest,'distance':p.integer(SCRATCH+0x7410)})
                owned = {'type':case%7+1,'state':2 if case%8 else 1,'level':case%3+1}
                now = fp(rng.choice([0,5,10,50,1000])+rng.uniform(0,.1))
                state = {'mode':rng.choice([0,1,9,10,23,26,28]),'lastBonusTime':fp(now-rng.choice([0,5,5.001,10,10.001])),
                         'reactionMode':-1,'reactionDeadline':0}
                shared = {'dropperCounter':rng.choice([0,456788,456789])}
                rank, reaction_level = case%5, case%5+1
                protected = bool(case%2)
                p.u32(SCRATCH+0x6004,owned['type']); p.u32(SCRATCH+0x6008,owned['state'])
                p.u32(0x503ef4,state['mode']); p.f32(0x504004,state['lastBonusTime'])
                p.u32(0x503fd0,0xffffffff);p.f32(0x503fd4,0)
                p.f32(SCRATCH+0x7100,now);p.u32(0x5081b8,rank);p.u32(0x505940,reaction_level)
                p.uc.mem_write(SCRATCH+0x7200+0x11c,bytes([protected]))
                p.u32(0x50592c,shared['dropperCounter'])
                p.run(0x40cde0,[0])
                out['decisions'].append({'precision':precision,'track':track_id,'racers':racers,'owned':owned,
                    'state':state,'shared':shared,'now':now,'rank':rank,'protected':protected,
                    'reactionMs':int(config[f'reaction{reaction_level}']),
                    'expected':bool(p.uc.reg_read(UC_X86_REG_EAX)),
                    'expectedState':{'mode':p.integer(0x503ef4),'lastBonusTime':p.float(0x504004),
                                     'reactionMode':signed(p.integer(0x503fd0)),'reactionDeadline':p.float(0x503fd4)},
                    'counter':signed(p.integer(0x50592c))})
        for case in range(360):
            now = fp(rng.uniform(0, 1000)); dt=fp(rng.choice([.025,.03125,.1]))
            rank, player_rank, level = case%5, rng.randrange(5), case%5+1
            state={'mode':rng.choice([0,9,10,26,28]), 'lastRank':rng.choice([rank,rank-1]),
                   'rankTime':fp(rng.choice([0,.5,1,1.5,2,2.5,3,10])), 'chaseTime':fp(rng.choice([0,.5,1,2,3])),
                   'reactionMode':-1,'reactionDeadline':0}
            for address,value in [(0x503ef4,state['mode']),(0x503fd8,state['lastRank']),(0x5081b8,rank),
                                  (0x53be60,player_rank),(0x505934,level),(0x505940,level),(0x503fd0,-1)]:
                p.u32(address,value&0xffffffff)
            p.f32(0x503fdc,state['rankTime']);p.f32(0x503f04,state['chaseTime'])
            p.f32(0x503fd4,0);p.f32(SCRATCH+0x7100,now);p.f32(SCRATCH+0x1000,dt)
            announce=False;p.run(0x40d070,[0])
            out['catchup'].append({'precision':precision,'state':state,'now':now,'rank':rank,'playerRank':player_rank,
                'catchupMs':int(config[f'catchup{level}']),'reactionMs':int(config[f'reaction{level}']),
                'expected':bool(p.uc.reg_read(UC_X86_REG_EAX)),'announce':announce,
                'expectedState':{**state,'mode':p.integer(0x503ef4),'chaseTime':p.float(0x503f04),
                    'reactionMode':signed(p.integer(0x503fd0)),'reactionDeadline':p.float(0x503fd4)}})
            state={'mode':28,'reactionMode':rng.choice([-1,28]),'reactionDeadline':fp(now+rng.choice([-.01,0,.01])),
                   'chaseTime':fp(rng.choice([0,.5,1,1.5,2,2.5,3,10]))}
            p.u32(0x503ef4,state['mode']);p.u32(0x503fd0,state['reactionMode']&0xffffffff)
            p.f32(0x503fd4,state['reactionDeadline']);p.f32(0x503f04,state['chaseTime'])
            p.run(0x40c010,[0])
            out['duration'].append({'precision':precision,'state':state,'now':now,'dt':dt,
                'durationMs':int(config[f'catchup_dur{level}']),
                'expected':bool(p.uc.reg_read(UC_X86_REG_EAX)&255),
                'expectedState':{**state,'reactionMode':signed(p.integer(0x503fd0)),'chaseTime':p.float(0x503f04)}})
        for case in range(30):
            p.u32(0x503ef4,26);p.u32(0x503fd0,26)
            for i,value in enumerate([2,1,0]):p.u32(0x503f7c+i*4,value)
            calls=[];p.run(0x40e690,[0])
            out['fire'].append({'precision':precision,'calls':calls,
                'state':{'mode':p.integer(0x503ef4),'reactionMode':signed(p.integer(0x503fd0)),
                         'priorities':[p.integer(0x503f7c+i*4) for i in range(3)]}})
    (ROOT/'evidence/native/ai-item-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
    print({key:len(out[key]) for key in ['geometry','decisions','catchup','duration','fire']})

if __name__=='__main__':main()
