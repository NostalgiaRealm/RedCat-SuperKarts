#!/usr/bin/env python3
"""Execute phase6 camera setup, post-render orbit, and original camera transform."""
import json, random, struct, pefile
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_FPCW
rng=random.Random(0x420730);out={'routines':['0x420730','0x420850','0x498c00'],'cases':[]}
for precision,cw in [(24,0x7f),(53,0x27f)]:
 p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);initialize_native_trig(p)
 out['sourceSha256']=p.sha
 base=SCRATCH+0x8000;camera=base+0x178
 for address in [0x4afce0,0x430610]:p.uc.mem_write(address,b'\xc3')
 pe=pefile.PE(str(SOURCE/'rcskspel.dat'))
 tick=next(x.address for library in pe.DIRECTORY_ENTRY_IMPORT for x in library.imports if x.name==b'GetTickCount')
 p.u32(tick,SCRATCH+0xb000);p.uc.mem_write(SCRATCH+0xb000,b'\x31\xc0\xc3')
 p.u32(0x680ba0,base);p.u32(0x508620,0);p.u32(0x508638,1)
 p.u32(0x4e3068,0);p.u32(0x53be28,0);p.u32(0x680c54,31)
 p.u32(0x4e3b10,1);p.u32(0x53be30,0)
 for case in range(30):
  p.uc.mem_write(base,bytes(0x178*2))
  for cam in [base,camera]:
   p.u32(cam+0x80,1)
   for j in range(4):p.f32(cam+0x14+j*20,1)
  body={'position':[rng.uniform(-5000,5000) for _ in range(3)],
        'matrix':[rng.uniform(-1,1) for _ in range(9)]}
  for j,v in enumerate(body['position']):
   p.f32(SCRATCH+0x4050+j*4,v);body['position'][j]=p.float(SCRATCH+0x4050+j*4)
  for row in range(3):
   for col in range(3):
    address=SCRATCH+0x4010+(row*4+col)*4
    p.f32(address,body['matrix'][row*3+col]);body['matrix'][row*3+col]=p.float(address)
  dt=[.025,.05,.1,1/60,1/144][case%5];p.f32(SCRATCH+0x1000,dt);dt=p.float(SCRATCH+0x1000)
  p.run(0x420730)
  def snapshot():
   return {'position':[p.float(camera+8+j*4) for j in range(3)],
           'target':[p.float(camera+0x54+j*4) for j in range(3)],
           'up':[p.float(camera+0x60+j*4) for j in range(3)]}
  record={'precision':precision,'body':body,'dt':dt,'orbitFrames':p.integer(0x508ae0),
          'angleIncrement':p.integer(0x508af0),'initial':snapshot(),'trace':[]}
  p.u32(0x4e3b14,0xffffffff)
  for step in range(12):
   p.run(0x420850)
   local=[p.float(camera+0xbc+j*4) for j in range(3)]
   p.uc.reg_write(UC_X86_REG_ECX,camera);p.run(0x498c00)
   record['trace'].append({'localPosition':local,'angle':p.integer(0x508aec),**snapshot()})
  out['cases'].append(record)
(ROOT/'evidence/native/failure-camera-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'original phase6 camera setups and720 orbit updates')
