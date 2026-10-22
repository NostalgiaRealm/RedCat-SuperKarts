#!/usr/bin/env python3
"""Execute original x86 animation instructions with controlled clock/delta inputs.

Run with re-python. Only Unicorn memory is patched; original executable is read-only.
The native functions produce expected data independently of the JavaScript port.
"""
import json
import struct
import random
from pathlib import Path
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_FPCW

ROOT=Path(__file__).resolve().parents[1]
p=NativeProbe(SOURCE)
# Logging and transform rebuild are outside the state update under test.
p.uc.mem_write(0x4afce0,b'\xc3')
p.uc.mem_write(0x4a09e0,b'\xc3')
# Imported GetTickCount returns a controlled uint32 stored in scratch memory.
p.uc.mem_write(SCRATCH+0x300,b'\xa1'+struct.pack('<I',SCRATCH+0x310)+b'\xc3')
p.u32(0x4d215c,SCRATCH+0x300)
state=SCRATCH+0x5000
traces=[]
for count,loops,fps,speed in [(1,-1,15,100),(3,-1,15,100),(10,-2,15,100),
                             (29,-2,15,100),(4,1,8,100),(7,-1,30,50),(3,-1,15,200)]:
    for initial_time in [0,0xfffffff0]:
        p.uc.mem_write(state,bytes(0x60))
        for off,value in [(8,fps),(12,loops&0xffffffff),(24,initial_time),
                          (28,1),(0x54,state+0x100),(0x58,state+0x100+count*4)]:
            p.u32(state+off,value)
        steps=[]
        for elapsed in [0,1,33,66,67,68,99,134]+list(range(201,7500,67)):
            now=(initial_time+elapsed)&0xffffffff
            p.u32(SCRATCH+0x310,now)
            p.uc.reg_write(UC_X86_REG_ECX,state)
            p.run(0x44e850,[speed])
            steps.append({'now':now,'frame':p.integer(state+16),'completedLoops':p.integer(state+20),
                          'lastTime':p.integer(state+24),'forward':bool(p.integer(state+28)&255)})
        traces.append({'count':count,'loops':loops,'fps':fps,'speedPercent':speed,'initialTime':initial_time,'steps':steps})
rotations=[]
for precision, cw in [(24,0x7f),(53,0x27f)]:
    p.uc.reg_write(UC_X86_REG_FPCW,cw)
    rng=random.Random(4390)
    cases=[(delta,initial,increments) for delta in [0,0.001,0.016,0.032,0.1,0.25]
           for initial in [[0,0,0],[4000,4100,-100],[4096,4096,4096]]
           for increments in [[0,0,30],[0,28,0],[15,0,0],[-3,7,31]]]
    cases.extend((rng.uniform(0,.1),[rng.uniform(-5000,5000) for _ in range(3)],
                  [rng.uniform(-30,30) for _ in range(3)]) for _ in range(160))
    for delta,initial,increments in cases:
            render=SCRATCH+0x4000
            for i in range(3):
                p.f32(render+0x68+i*4,increments[i])
                p.f32(render+0x74+i*4,initial[i])
            increments=[p.float(render+0x68+i*4) for i in range(3)]
            initial=[p.float(render+0x74+i*4) for i in range(3)]
            p.f32(SCRATCH+0x1000,delta)
            p.run(0x43f490,[0])
            rotations.append({'precision':precision,'delta':p.float(SCRATCH+0x1000),'initial':initial,'increments':increments,
                              'angles':[p.float(render+0x74+i*4) for i in range(3)]})
target=ROOT/'evidence/native/animation-fixtures.json'
target.write_text(json.dumps({'sourceSHA256':p.sha,'method':'isolated original x86 instructions via Unicorn',
    'addresses':{'meshClock':'0044e850','rotatingObject':'0043f490'},
    'patchedDependencies':['logging no-op','GetTickCount controlled uint32','delta accessor controlled float32','transform rebuild no-op'],
    'meshTraces':traces,'rotations':rotations},indent=2)+'\n')
print(f'{len(traces)} mesh traces; {len(rotations)} rotation cases; {target}')
