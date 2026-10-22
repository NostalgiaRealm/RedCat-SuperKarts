#!/usr/bin/env python3
"""Original0x499c30+0x492470 with broadphase/mesh reads supplied synthetic rectangles."""
import json,random,struct,math
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,OBJECT,SCRATCH
from unicorn import UC_HOOK_CODE
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_FPCW,UC_X86_REG_ESP,UC_X86_REG_EIP
rng=random.Random(49930);out={'routines':['0x499c30','0x492470'],'scope':'Unmodified sweep, projection and normals; hooks supply broadphase list and original mesh bounds','cases':[]}
tables=json.loads((ROOT/'evidence/native/integrator-fixtures.json').read_text())
for bits,cw in [(24,0x7f),(53,0x27f)]:
 p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);out['sourceSha256']=p.sha
 p.uc.mem_write(0x4afce0,b'\xc3');initialize_native_trig(p)
 p.u32(OBJECT+4,3);p.u32(OBJECT+0x44,1)
 def desc(addr,v):
  points=[v['minX'],0,v['minZ'],v['maxX'],0,v['minZ'],v['maxX'],0,v['maxZ'],v['minX'],0,v['maxZ']]
  for k,val in enumerate(points+v['position']):p.f32(addr+4*k,val)
  p.u32(addr+0x40,0 if v.get('type',1) else 0xffffffff);p.u32(addr+0x44,v['angle']&0xffffffff);p.u32(addr+0x48,v.get('type',1))
 def hook(u,a,size,data):
  if a not in [0x499b20,0x4999c0]:return
  sp=u.reg_read(UC_X86_REG_ESP);ret=p.integer(sp)
  if a==0x499b20:
   p.u32(0x6847c8,len(rails))
   for k,v in enumerate(rails):desc(0x680c68+0x4c*k,v)
  else:desc(p.integer(sp+8),body_desc)
  u.reg_write(UC_X86_REG_ESP,sp+4);u.reg_write(UC_X86_REG_EIP,ret)
 h=p.uc.hook_add(UC_HOOK_CODE,hook)
 for i in range(100):
  bounds={'minX':-6.0,'maxX':6.0,'minZ':-12.0,'maxZ':12.0}
  body={'x':rng.uniform(-20,20),'y':0.0,'z':rng.uniform(-30,30),'yaw':rng.uniform(-4096,4096),'lateralSpeed':rng.uniform(-15,15),'verticalSpeed':0.0,'forwardSpeed':rng.uniform(-15,60),'yawRate':rng.uniform(-3,3),'sector':0}
  for k,o in [('x',0x50),('y',0x54),('z',0x58),('yaw',0x78)]:p.f32(SCRATCH+0x4000+o,body[k]);body[k]=p.float(SCRATCH+0x4000+o)
  for k,o in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac)]:p.f32(OBJECT+o,body[k]);body[k]=p.float(OBJECT+o)
  body_desc={**bounds,'position':[body['x'],body['y'],body['z']],'angle':math.ceil(body['yaw']) if body['yaw']>0 else math.floor(body['yaw'])}
  rails=[{'minX':-10.0,'maxX':0.0,'minZ':-1.0,'maxZ':51.0,'position':[0,0,0],'angle':0,'type':0},{'minX':-10.0,'maxX':0.0,'minZ':-1.0,'maxZ':81.0,'position':[30,0,20],'angle':1024,'type':0}]
  dt=rng.choice([.1/8,.03125/8,.1,.3]);frac=p.run(0x499c30,[0,SCRATCH+0x8000,float(dt)],True)
  stop=p.integer(SCRATCH+0x8000);contact=None
  if p.integer(0x6a5b58):contact={'point':[p.float(0x6a5b68+4*k) for k in range(3)],'normal':[p.float(0x6a5b74+4*k) for k in range(3)]}
  from unicorn.x86_const import UC_X86_REG_EAX
  p.run(0x492470,[0,float(dt),SCRATCH+0x8100,float(frac),SCRATCH+0x8000])
  override=[p.float(SCRATCH+0x8100+4*k) for k in range(3)] if p.uc.reg_read(UC_X86_REG_EAX) else None
  out['cases'].append({'precision':bits,'body':body,'bounds':bounds,'rails':rails,'dt':dt,'expected':{'fraction':frac,'stopYaw':bool(p.integer(SCRATCH+0x8000)),'contact':contact,'velocityOverride':override}})
 p.uc.hook_del(h)
(ROOT/'evidence/native/rail-fixtures.json').write_text(json.dumps(out,indent=2)+'\n');print('Wrote',len(out['cases']),'composed rail cases')
