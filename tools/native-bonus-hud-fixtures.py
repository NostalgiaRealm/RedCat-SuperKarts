#!/usr/bin/env python3
"""Execute the complete original bonus HUD dispatch and moving-element math."""
import json,random,struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_FPCW
def fp(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def main():
    rng=random.Random(0x465c90)
    out={'scope':'Original465c90 with its unchanged PE vtable,465f50,465fa0,467000,4671f0,4676d0 and overlay setters. Initial owned/render/overlay objects explicitly supplied; only dt clock is replaced.',
         'cases':[]}
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE);p.uc.mem_map(0,0x1000);p.uc.reg_write(UC_X86_REG_FPCW,cw)
        p.run(0x465900)
        out['origin']=[p.float(0x544ae0+i*4) for i in range(3)];out['sourceSha256']=p.sha
        record=SCRATCH+0x8000;overlay=SCRATCH+0x9000;owned_ptr=SCRATCH+0xa000;render=SCRATCH+0x4000
        p.u32(record,0x4d2c58);p.u32(record+0x30,overlay);p.u32(record+0x34,owned_ptr);p.u32(overlay+0x50,0)
        p.u32(record+0x2c,0);p.f32(record+0x28,1000)
        for case in range(480):
            cached={'state':rng.choice([1,2]),'type':rng.randrange(1,6),'level':rng.randrange(1,4)}
            owned={**cached,'angles':[fp(rng.uniform(-5000,5000)) for _ in range(3)],'visible':bool(case%2)}
            if case%4==1:owned['state']=3-owned['state']
            if case%4==2:owned['type']=owned['type']%5+1
            if case%4==3:owned['level']=owned['level']%3+1
            state={'phase':case%3,'cached':cached,'origin':out['origin'],
                   'destination':[fp(rng.uniform(-2,2)) for _ in range(3)],
                   'position':[fp(rng.uniform(-2,2)) for _ in range(3)],
                   'elapsedMs':fp(rng.choice([0,900,975,999.99994,rng.uniform(0,1100)])),
                   'visible':bool((case//2)%2),'angles':[fp(rng.random()) for _ in range(3)]}
            dt=fp(rng.choice([0,.025,.1,.00000004,.3333333]))
            p.u32(record+8,state['phase']);p.f32(record+0x24,state['elapsedMs']);p.f32(SCRATCH+0x1000,dt)
            for offset,key in [(0,'type'),(4,'state'),(0x14,'level')]:p.u32(owned_ptr+offset,owned[key])
            for offset,key in [(0x3c,'state'),(0x40,'type'),(0x48,'level')]:p.u32(record+offset,cached[key])
            for i in range(3):
                p.f32(record+0xc+i*4,state['origin'][i]);p.f32(record+0x18+i*4,state['destination'][i])
                p.f32(overlay+4+i*4,state['position'][i]);p.f32(overlay+0x1c+i*4,state['angles'][i])
                p.f32(render+0x74+i*4,owned['angles'][i])
            p.uc.mem_write(render+0x90,bytes([owned['visible']]));p.uc.mem_write(overlay+0x2c,bytes([state['visible']]))
            p.uc.reg_write(UC_X86_REG_ECX,record);p.run(0x465c90)
            expected={**state,'phase':p.integer(record+8),'elapsedMs':p.float(record+0x24),
                      'origin':[p.float(record+0xc+i*4) for i in range(3)],
                      'position':[p.float(overlay+4+i*4) for i in range(3)],
                      'angles':[p.float(overlay+0x1c+i*4) for i in range(3)],
                      'visible':bool(p.uc.mem_read(overlay+0x2c,1)[0]),
                      'cached':{key:p.integer(record+offset) for offset,key in [(0x3c,'state'),(0x40,'type'),(0x48,'level')]}}
            out['cases'].append({'precision':precision,'state':state,'owned':owned,'dt':dt,'expected':expected})
    (ROOT/'evidence/native/bonus-hud-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
    print('Wrote960 complete original bonus HUD updates')
if __name__=='__main__':main()
