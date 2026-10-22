#!/usr/bin/env python3
"""Execute shipped String normalization, scale setter and hierarchy transform."""
import json, struct
from pathlib import Path
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH, OBJECT

ROOT = Path(__file__).resolve().parents[1]
config = json.loads((ROOT/'public/assets/config.json').read_text())['overlay.ini']
f = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
rows = []
for precision in [24, 53]:
    p = NativeProbe(SOURCE)
    p.uc.mem_map(0, 4096)
    p.uc.reg_write(UC_X86_REG_FPCW, 0x007f if precision == 24 else 0x027f)
    r = f if precision == 24 else lambda x:x
    for addr, code in {
        0x40b600:b'\x31\xc0\xc2\x08\x00', 0x45cd10:b'\xc2\x04\x00',
        0x45d470:b'\xb8\x01\x00\x00\x00\xc2\x0c\x00',
        0x4a09d0:b'\xc3', 0x4a0d80:b'\xc3',
    }.items(): p.uc.mem_write(addr,code)
    desired = [0, 0, 0]
    def input_position(uc,address,size,_):
        if address == 0x45d470:
            sp = uc.reg_read(UC_X86_REG_ESP)
            p.uc.mem_write(p.integer(sp+12), struct.pack('<3f', *desired))
    p.uc.hook_add(UC_HOOK_CODE,input_position)
    p.run(0x4604c0)
    p.uc.reg_write(UC_X86_REG_ECX,OBJECT); p.run(0x462770)
    parser, parent_addr, scale_addr = SCRATCH+0x5000, SCRATCH+0x5200, SCRATCH+0x5300
    for offset,value in [(0x18,640),(0x1c,480),(0x20,1000)]:p.f32(parser+offset,value)
    def fields(obj,node):
        for offset,values in [(4,node['position']),(0x10,node['scale']),(0x1c,[0,0,0])]:
            p.uc.mem_write(obj+offset,struct.pack('<3f',*values))
        p.f32(obj+0x7c,node.get('width',1));p.f32(obj+0x80,node.get('height',1))
        p.u32(obj,0x4d292c)
    def composite(section,parent):
        xyz=list(map(float,section.get('position','0;0;0').split(';')));xyz += [0]*(3-len(xyz))
        x,y,z=xyz;nx=f(x/480);ny=f(y/480)
        width=f(float(section.get('width',640))/640);height=f(float(section.get('height',480))/480)
        pos=[f(r(r(nx+nx)-r(640/480))),f(r(1-r(ny+ny))),f(z/1000)]
        h,v=(section.get('alignment','LEFT&TOP').lower().split('&')+['top'])[:2]
        if h=='left':pos[0]=f(r(pos[0]+r(r(640/480)*width)))
        if h=='right':pos[0]=f(r(pos[0]-r(r(640/480)*width)))
        if v=='top':pos[1]=f(r(pos[1]-height))
        if v=='bottom':pos[1]=f(r(pos[1]+height))
        scale=list(map(float,section.get('scale','1;1;1').split(';')));scale += [1]*(3-len(scale))
        fields(OBJECT,{'position':pos,'scale':scale,'width':width,'height':height})
        p.uc.mem_write(parent_addr,struct.pack('<12f',*parent))
        p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x4589c0,[parent_addr])
        return list(struct.unpack('<12f',p.uc.mem_read(OBJECT+0x44,48)))
    def parent_context(name):
        if name.lower()=='screen':return [0,0,0,1,.75,.75,1,1,1,0,0,0]
        node=config[name.lower()]
        return composite(node,parent_context(node['parent']))
    for id in [config['strings'][str(i)].lower() for i in range(10)]:
        section=config[id]
        for override in [None, [.8,1.2,1]]:
            parent=parent_context(section['parent'])
            desired=list(map(float,section['position'].split(';')));desired += [0]*(3-len(desired))
            scale=override or list(map(float,section.get('scale','1;1;1').split(';')))
            scale=scale+[1]*(3-len(scale))
            fields(OBJECT,{'position':[0,0,0],'scale':[1,1,1]})
            p.uc.reg_write(UC_X86_REG_ECX,parser);p.run(0x45caa0,[OBJECT])
            assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
            position=list(struct.unpack('<3f',p.uc.mem_read(OBJECT+4,12)))
            p.uc.mem_write(scale_addr,struct.pack('<3f',*scale))
            p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x463c90,[scale_addr])
            p.uc.mem_write(parent_addr,struct.pack('<12f',*parent))
            p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x463bb0,[parent_addr])
            context=list(struct.unpack('<12f',p.uc.mem_read(OBJECT+0x44,48)))
            rows.append({'precision':precision,'id':id,'override':override,'position':position,
                         'parent':parent,'scale':scale,'context':context})
(ROOT/'evidence/native/hud-string-transform-fixtures.json').write_text(json.dumps({
    'sourceSHA256':p.sha,'functions':['45caa0','463c90','463bb0','4589c0'],
    'scope':'Original string position conversion, scale setter and hierarchy. INI lookup supplies authored XYZ; parser setup/logging stubbed. Parent INI conversion is independently source-transcribed; parent and string transforms execute original instructions.',
    'rows':rows},indent=2)+'\n')
print(f'Captured {len(rows)} original string hierarchy transforms.')
