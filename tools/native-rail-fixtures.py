#!/usr/bin/env python3
"""Original0x499c30+0x492470 with broadphase/mesh reads supplied synthetic rectangles."""
import json,random,struct,math
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,OBJECT,SCRATCH
from unicorn import UC_HOOK_CODE
from native_probe_math import initialize_native_trig
from unicorn.x86_const import UC_X86_REG_FPCW,UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
rng=random.Random(49930);out={'routines':['0x499c30','0x492470'],'scope':'Unmodified sweep, projection and normals; hooks supply broadphase list and original mesh bounds. Cases after the first 200 vary both rails\' 0x4997f0 pose, length and rounded heading.','cases':[]}
tables=json.loads((ROOT/'evidence/native/integrator-fixtures.json').read_text())
f32=lambda value:struct.unpack('<f',struct.pack('<f',value))[0]
extra_cases=[]
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
 def measure(body,bounds,dt):
  global body_desc
  body_desc={**bounds,'position':[body['x'],body['y'],body['z']],'angle':math.ceil(body['yaw']) if body['yaw']>0 else math.floor(body['yaw'])}
  frac=p.run(0x499c30,[0,SCRATCH+0x8000,float(dt)],True)
  assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH+0x106,'0x499c30 did not return'
  stop=p.integer(SCRATCH+0x8000);contact=None
  if p.integer(0x6a5b58):contact={'point':[p.float(0x6a5b68+4*k) for k in range(3)],'normal':[p.float(0x6a5b74+4*k) for k in range(3)]}
  p.run(0x492470,[0,float(dt),SCRATCH+0x8100,float(frac),SCRATCH+0x8000])
  assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH,'0x492470 did not return'
  override=[p.float(SCRATCH+0x8100+4*k) for k in range(3)] if p.uc.reg_read(UC_X86_REG_EAX) else None
  return {'precision':bits,'body':body,'bounds':bounds,'rails':rails,'dt':dt,'expected':{'fraction':frac,'stopYaw':bool(p.integer(SCRATCH+0x8000)),'contact':contact,'velocityOverride':override}}
 def store_body(body):
  for k,o in [('x',0x50),('y',0x54),('z',0x58),('yaw',0x78)]:p.f32(SCRATCH+0x4000+o,body[k]);body[k]=p.float(SCRATCH+0x4000+o)
  for k,o in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac)]:p.f32(OBJECT+o,body[k]);body[k]=p.float(OBJECT+o)
 for i in range(100):
  bounds={'minX':-6.0,'maxX':6.0,'minZ':-12.0,'maxZ':12.0}
  body={'x':rng.uniform(-20,20),'y':0.0,'z':rng.uniform(-30,30),'yaw':rng.uniform(-4096,4096),'lateralSpeed':rng.uniform(-15,15),'verticalSpeed':0.0,'forwardSpeed':rng.uniform(-15,60),'yawRate':rng.uniform(-3,3),'sector':0}
  store_body(body)
  rails=[{'minX':-10.0,'maxX':0.0,'minZ':-1.0,'maxZ':51.0,'position':[0,0,0],'angle':0,'type':0},{'minX':-10.0,'maxX':0.0,'minZ':-1.0,'maxZ':81.0,'position':[30,0,20],'angle':1024,'type':0}]
  dt=rng.choice([.1/8,.03125/8,.1,.3])
  out['cases'].append(measure(body,bounds,dt))
 # Appended varied poses use their own generator, reseeded per precision, so
 # both control words see the same inputs and the first 200 cases stay unchanged.
 extra=random.Random(49931)
 def rotate(x,z,angle):
  t=2*math.pi*(angle&4095)/4096
  return math.cos(t)*x-math.sin(t)*z,math.sin(t)*x+math.cos(t)*z
 def varied_rail(body=None,dt=0):
  # 0x4997f0: corners from -10/0 and -1/len+1, FADD 1.0 then FST float; the
  # heading is rounded away from zero from (atan2-pi/2)*4096/2pi, -3072..1024.
  length=f32(extra.uniform(4,120))
  angle=extra.choice([0,1,-1,1024,-1024,-2048,-3072,512,-2560,extra.randint(-3072,1024),extra.randint(-3072,1024),extra.randint(-3072,1024)])
  x,z=extra.uniform(-45,45),extra.uniform(-55,55)
  if body:
   # Put the rail's midpoint on the 0x499f47 world travel path.
   yaw=body['yaw'];heading=math.ceil(yaw) if yaw>0 else math.floor(yaw)
   dx,dz=rotate(body['lateralSpeed']*dt*10,body['forwardSpeed']*dt*10,heading)
   travel=math.hypot(dx,dz)
   if travel:
    k=(travel*extra.uniform(.05,1.2)+extra.uniform(8,20))/travel
    mx,mz=rotate(-5,length/2,angle);x,z=body['x']+dx*k-mx,body['z']+dz*k-mz
  return {'minX':-10.0,'maxX':0.0,'minZ':-1.0,'maxZ':f32(length+1),
          'position':[f32(x),f32(extra.uniform(-6,6)),f32(z)],'angle':angle,'type':0}
 for i in range(100):
  bounds={'minX':-6.0,'maxX':6.0,'minZ':-12.0,'maxZ':12.0}
  body={'x':extra.uniform(-20,20),'y':0.0,'z':extra.uniform(-30,30),'yaw':extra.uniform(-4096,4096),'lateralSpeed':extra.uniform(-15,15),'verticalSpeed':0.0,'forwardSpeed':extra.uniform(-15,60),'yawRate':0.0 if i%5==4 else extra.uniform(-3,3),'sector':0}
  store_body(body)
  dt=extra.choice([.1/8,.03125/8,.1,.3])
  rails=[varied_rail(body if i%3 else None,dt),varied_rail()]
  extra_cases.append(measure(body,bounds,dt))
 p.uc.hook_del(h)
out['cases'].extend(extra_cases)
(ROOT/'evidence/native/rail-fixtures.json').write_text(json.dumps(out,indent=2)+'\n');print('Wrote',len(out['cases']),'composed rail cases')
