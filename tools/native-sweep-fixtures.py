#!/usr/bin/env python3
"""Native point/rectangle collision sweep 0x49a7f0 and0x49a120."""
import json,random,struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_FPCW
rng=random.Random(49750);out={'routines':['0x49a7f0','0x49a120'],'points':[],'rectangles':[]}
tables=json.loads((ROOT/'evidence/native/integrator-fixtures.json').read_text())
for bits,cw in [(24,0x7f),(53,0x27f)]:
 p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);out['sourceSha256']=p.sha
 p.uc.mem_write(0x4afce0,b'\xc3') # diagnostic logger only
 initialize_native_trig(p)
 for i in range(240):
  start=[rng.choice([-10,0,10,rng.uniform(-40,40)]),0,rng.choice([-10,0,10,rng.uniform(-40,40)])]
  end=[rng.uniform(-40,40),0,rng.uniform(-40,40)];bounds=[-10,0,-10,10,0,10]
  vals=[struct.unpack('<f',struct.pack('<f',v))[0] for v in start+end+bounds];p.u32(SCRATCH+0x8000,0xffffffff)
  fraction=p.run(0x49a7f0,vals+[SCRATCH+0x8000],True);edge=p.integer(SCRATCH+0x8000)
  out['points'].append({'precision':bits,'start':vals[:3],'end':vals[3:6],'bounds':vals[6:],'fraction':fraction,'edge':edge if fraction<1 else None})
 for i in range(180):
  def rect():return {'minX':-10.0,'maxX':10.0,'minZ':-15.0,'maxZ':15.0,'position':[rng.uniform(-40,40),0,rng.uniform(-40,40)],'angle':rng.randrange(-4096,4096)}
  a,b=rect(),rect();move=[rng.uniform(-80,80),0,rng.uniform(-80,80)]
  for k,v in enumerate(move):p.f32(SCRATCH+0x9000+4*k,v);move[k]=p.float(SCRATCH+0x9000+4*k)
  for addr,desc in [(SCRATCH+0xa000,a),(SCRATCH+0xa100,b)]:
   vertices=[desc['minX'],0,desc['minZ'],desc['maxX'],0,desc['minZ'],desc['maxX'],0,desc['maxZ'],desc['minX'],0,desc['maxZ']]
   for k,v in enumerate(vertices+desc['position']):p.f32(addr+4*k,v)
   desc['position']=[p.float(addr+0x30+4*k) for k in range(3)]
   p.u32(addr+0x44,desc['angle']&0xffffffff)
  p.u32(0x680b78,0)
  fraction=p.run(0x49a120,[SCRATCH+0xa000,SCRATCH+0xa100,SCRATCH+0x9000],True)
  out['rectangles'].append({'precision':bits,'obstacle':a,'moving':b,'movement':move,'fraction':fraction,'hit':p.integer(0x680b78),'edge':p.integer(0x680b98) if fraction<1 else None})
(ROOT/'evidence/native/sweep-fixtures.json').write_text(json.dumps(out,indent=2)+'\n');print('Wrote',len(out['points']),'point and',len(out['rectangles']),'rectangle cases')
