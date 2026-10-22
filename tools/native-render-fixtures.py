#!/usr/bin/env python3
"""Capture original render settings and visibility selection, without GPU rendering."""
import json
import random
import struct
from pathlib import Path
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH

ROOT=Path(__file__).resolve().parents[1]
p=NativeProbe(SOURCE)
device,vtable,callback=SCRATCH+0x3000,SCRATCH+0x3100,SCRATCH+0x3200
p.u32(0x6a621c,device)
p.u32(device,vtable)
p.u32(vtable+0x5c,callback)
p.uc.mem_write(callback,bytes.fromhex('31c0c20c00'))
p.uc.mem_write(0x4afce0,b'\xc3')
p.uc.mem_write(0x4afee0,b'\xc3')
p.uc.mem_write(0x4b1d60,b'\xc3')
p.uc.mem_write(0x4b1ed0,b'\xa1'+struct.pack('<I',SCRATCH+0x1100)+b'\xc3')
calls=[]
def hook(uc,address,size,data):
    if address==callback:
        sp=uc.reg_read(UC_X86_REG_ESP)
        calls.append({'state':p.integer(sp+8),'value':p.integer(sp+12)})
p.uc.hook_add(UC_HOOK_CODE,hook)
settings=[]
for hardware in [False,True]:
    for filtering in [0,1,2,3]:
        for blend in [2,7,0]:
            for filter_cache in [0,2,1]:
                for shade in [1,2]:
                    p.u32(0x53b9f0,int(hardware));p.u32(SCRATCH+0x1100,filtering)
                    p.u32(0x6a6264,blend);p.u32(0x6a6274,filter_cache);p.u32(0x6a6280,shade)
                    calls.clear();p.run(0x42cff0)
                    settings.append({'input':{'hardware':hardware,'filter':filtering,'blendCache':blend,
                        'filterCache':filter_cache,'shadeCache':shade},'expected':list(calls)})

AUX=0x22000000
p.uc.mem_map(AUX,0x100000)
p.u32(0x680b28,AUX);p.u32(0x680ba0,AUX+0xf0000)
p.u32(0x508620,0);p.u32(0x508670,0)
rng=random.Random(4304)
visibility=[]
for precision in [24,53]:
    p.uc.reg_write(UC_X86_REG_FPCW,0x007f if precision==24 else 0x027f)
    for case in range(600):
        sector=rng.randrange(250);route_count=250;count=rng.randrange(10,51);back=2
        vectors=[[rng.uniform(-1000,1000) for _ in range(3)] for _ in range(3)]
        if case<6:
            vectors[0]=[0,0,1]
            vectors[1]=[0,0,0]
            vectors[2]=[[0,0,1],[0,0,-1],[1,0,0],[0,0,0],[.819152,0,.5736],[.819152,0,-.5736]][case]
        for vec,base in zip(vectors,[AUX+sector*0x984+0x48,AUX+0xf0008,AUX+0xf0054]):
            for k,v in enumerate(vec):p.f32(base+k*4,v)
            vec[:]=[p.float(base+k*4) for k in range(3)]
        p.u32(0x508674,sector);p.u32(0x680220,route_count);p.u32(0x53b9d0,count)
        p.run(0x4304d0,[back])
        expected=struct.unpack('<i',struct.pack('<I',p.uc.reg_read(UC_X86_REG_EAX)))[0]
        visibility.append({'input':{'sector':sector,'routeCount':route_count,'visibleChunks':count,
            'forward':vectors[0],'position':vectors[1],'target':vectors[2],'backOffset':back,
            'precision':precision},'expected':expected})
ranges=[]
for chunks in [1,2,10,250,338]:
    p.u32(0x680b2c,chunks)
    for start in [-2,0,1,chunks-2,chunks-1,chunks]:
        for count in [0,1,10,40]:
            out=SCRATCH+0x6000
            p.run(0x497ab0,[start&0xffffffff,count,out,out+4,out+8,out+12])
            wrapped=bool(p.uc.reg_read(UC_X86_REG_EAX)&255)
            result=struct.unpack('<4i',p.uc.mem_read(out,16))
            ranges.append({'input':[start,count,chunks],'expected':{'wrapped':wrapped,
                'ranges':[list(result[:2]),list(result[2:])] if wrapped else [list(result[:2])]}})
callbacks=[]
for chunks in [104,178,204,250,338]:
    p.u32(0x680220,chunks)
    for sector in [0,1,40,chunks//2,chunks-2,chunks-1]:
        for count in [10,25,40,50]:
            out=SCRATCH+0x6000
            p.run(0x497b30,[sector,count*2,out,out+4,out+8,out+12])
            wrapped=bool(p.uc.reg_read(UC_X86_REG_EAX))
            result=struct.unpack('<4i',p.uc.mem_read(out,16))
            callbacks.append({'input':[sector,count,chunks],
                'expected':[list(result[:2]),list(result[2:])] if wrapped else [list(result[:2])]})
adaptive=[]
for precision in [24,53]:
    p.uc.reg_write(UC_X86_REG_FPCW,0x007f if precision==24 else 0x027f)
    for phase in [0,1,3]:
        for hardware in [False,True]:
            for count in [14,15,16,24,25,26,40]:
                for delta in [.025,.1,.11]:
                    p.u32(0x53b9c0,phase);p.u32(0x53b9f0,int(hardware));p.u32(0x53b9d0,count)
                    p.f32(SCRATCH+0x1000,delta);p.run(0x42f470)
                    adaptive.append({'count':count,'input':{'phase':phase,'hardware':hardware,
                        'delta':delta,'precision':precision},'expected':p.integer(0x53b9d0)})
fog=[]
fog_events=[]
p.uc.mem_write(0x422d50,b'\xc3')
p.uc.mem_write(0x441210,b'\xc3')
def fog_hook(uc,address,size,data):
    if address in [0x4be6c9,0x441210]:fog_events.append(address)
p.uc.hook_add(UC_HOOK_CODE,fog_hook)
for hardware in [False,True]:
    for setting in [0,1,2]:
        for seed in range(12):
            p.u32(0x53b9f0,int(hardware));p.u32(0x53ba00,setting);p.u32(0x502978,seed)
            p.u32(0x6a6264,2);p.u32(0x6a6274,2)
            fog_events.clear();p.run(0x422ed0)
            fog.append({'hardware':hardware,'fog':setting,'seed':seed,
                'expected':{'enabled':0x441210 in fog_events,'draws':fog_events.count(0x4be6c9)},
                'state':p.integer(0x502978)})
out={'sourceSHA256':p.sha,'method':'Original x86 instructions. Device success calls and INI reads stubbed; no GPU rendering.',
     'functions':['0042cff0','004304d0','00497ab0','00497b30','0042f470','00422ed0'],
     'settings':settings,'visibility':visibility,'ranges':ranges,'callbacks':callbacks,'adaptive':adaptive,'fog':fog}
(ROOT/'evidence/native/render-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print({key:len(out[key]) for key in ['settings','visibility','ranges','callbacks','adaptive','fog']})
