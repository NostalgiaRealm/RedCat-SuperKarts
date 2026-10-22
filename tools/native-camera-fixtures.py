#!/usr/bin/env python3
"""Execute native active-player camera0x498c00 against controlled body matrices."""
import json,random,struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH
from unicorn.x86_const import UC_X86_REG_FPCW,UC_X86_REG_ECX
rng=random.Random(49800);out={'routine':'0x498c00','cases':[]}
for bits,cw in[(24,0x7f),(53,0x27f)]:
 p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);p.uc.mem_write(0x4afce0,b'\xc3');p.u32(0x680c54,0x1f);camera=SCRATCH+0x9000
 for i in range(100):
  p.uc.mem_write(camera,bytes(0x178))
  for o in[0x6c,0x74,0x78]:p.u32(camera+o,1)
  for base,vals in[(0x88,[.1,.1,.5]),(0xbc,[0,50,-150]),(0xcc,[0,50,0])]:
   for j,v in enumerate(vals):p.f32(camera+base+4*j,v)
  position=[rng.uniform(-5000,5000) for _ in range(3)];previous=[v+rng.uniform(-200,200) for v in position];matrix=[rng.uniform(-1,1) for _ in range(9)]
  position=[struct.unpack('<f',struct.pack('<f',v))[0] for v in position];previous=[struct.unpack('<f',struct.pack('<f',v))[0] for v in previous];matrix=[struct.unpack('<f',struct.pack('<f',v))[0] for v in matrix]
  for j,v in enumerate(position):p.f32(SCRATCH+0x4000+0x50+4*j,v)
  for j,v in enumerate(previous):p.f32(camera+0xa0+4*j,v)
  for row in range(3):
   for col in range(3):p.f32(SCRATCH+0x4010+4*(row*4+col),matrix[row*3+col])
  p.uc.reg_write(UC_X86_REG_ECX,camera);p.run(0x498c00)
  out['cases'].append({'precision':bits,'transform':{'position':position,'matrix':matrix},'previous':previous,'expected':{'position':[p.float(camera+8+4*j) for j in range(3)],'target':[p.float(camera+0x54+4*j) for j in range(3)]}})
(ROOT/'evidence/native/camera-fixtures.json').write_text(json.dumps(out,indent=2)+'\n');print('Wrote',len(out['cases']),'camera cases')
