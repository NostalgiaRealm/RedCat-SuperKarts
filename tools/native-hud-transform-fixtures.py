#!/usr/bin/env python3
"""Capture original HUD scale, hierarchy, and final render-object transforms."""
import json, struct
from pathlib import Path
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH, OBJECT
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_FPCW

ROOT=Path(__file__).resolve().parents[1]
rows=[]
for precision,control in [(24,0x007f),(53,0x027f)]:
    p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,control)
    p.uc.mem_map(0,4096)  # native SEH linked-list storage
    # Only renderer submission/matrix rebuilding are bypassed. All recovered
    # HUD arithmetic and model color writes execute original instructions.
    p.uc.mem_write(0x4a09d0,b'\xc3');p.uc.mem_write(0x4a0d80,b'\xc3')
    p.run(0x4604c0)  # native HUD FOV static initializer: float(pi)*.5
    p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x462770)
    pixel_scale=[p.float(0x544ab0+i*4) for i in range(3)]
    fov=p.float(0x544ad0)
    parent_addr=SCRATCH+0x7000
    table=SCRATCH+0x7200
    p.u32(table+0x20,0x4583e0)
    p.u32(0x6a5ee0,SCRATCH+0x6000)
    render=SCRATCH+0x4000
    p.u32(render,1);p.u32(render+0x99,0)
    p.u32(SCRATCH+0x6000,2)
    p.u32(SCRATCH+0x6080,SCRATCH+0x6500)
    p.u32(SCRATCH+0x6084,1)
    for parent in [
        [0,0,0,1,.75,.75,1,1,1,0,0,0],
        [.3,-.2,.01,1,.75,844/390,.9,.85,1,0,0,0],
        [-.78125,-.5,0,1,.75,.75,1,1,1,0,0,0],
    ]:
        for position in [[0,0,0],[-.328125,1.25,0],[.328125,.4,0],[-.1,-.1,.1]]:
            for scale in [[1,1,1],[.9,.9,1],[.4,.4,1]]:
                rotation=[0,0,0]
                p.uc.mem_write(parent_addr,struct.pack('<12f',*parent))
                p.u32(OBJECT,table)
                for i,x in enumerate(position):p.f32(OBJECT+4+i*4,x)
                for i,x in enumerate(scale):p.f32(OBJECT+0x10+i*4,x)
                for i,x in enumerate(rotation):p.f32(OBJECT+0x1c+i*4,x)
                p.f32(OBJECT+0x7c,100/640);p.f32(OBJECT+0x80,320/480)
                p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x4589c0,[parent_addr])
                composite=list(struct.unpack('<12f',p.uc.mem_read(OBJECT+0x44,48)))
                for i,x in enumerate(scale):p.f32(SCRATCH+0x7400+i*4,x)
                p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x459910,[SCRATCH+0x7400])
                p.u32(OBJECT+0x50,0);p.uc.mem_write(OBJECT+0x2c,b'\x01')
                p.u32(OBJECT+0x28,0x7fff8040)
                p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x459440,[parent_addr])
                rows.append({'precision':precision,'fov':fov,'pixelScale':pixel_scale,
                    'parent':list(struct.unpack('<12f',struct.pack('<12f',*parent))),
                    'position':position,'scale':scale,'rotation':rotation,
                    'width':100/640,'height':320/480,'composite':composite,
                    'element':{'position':[p.float(render+0x50+i*4) for i in range(3)],
                        'scale':[p.float(render+0x80+i*4) for i in range(3)],
                        'rotation':[p.float(render+0x74+i*4) for i in range(3)]},
                    'packedColor':p.integer(SCRATCH+0x6510)})
out=ROOT/'evidence/native/hud-transform-fixtures.json'
out.write_text(json.dumps({'sourceSHA256':p.sha,
    'functions':['4604c0','462770','459ce0','459910','4589c0','459440'],
    'scope':'Original arithmetic at explicit24/53-bit x87 precision; renderer calls4a09d0/4a0d80 stubbed.',
    'rows':rows},indent=2)+'\n')
print(f'Captured {len(rows)} original HUD transform cases.')
