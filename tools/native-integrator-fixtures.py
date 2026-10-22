#!/usr/bin/env python3
"""Isolated original x86 Euler instruction fixtures with explicit FPU modes."""
import json, math, random, struct
from pathlib import Path
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,OBJECT,SCRATCH
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_FPCW

def generate():
 out={'angleCount':4096,'sourceSha256':None,'routine':'0x4911a0','scope':'Euler only; original instructions, synthetic body/force inputs, no collision callbacks', 'cases':[]}
 rng=random.Random(4911)
 for bits,cw in [(24,0x7f),(53,0x27f)]:
  p=NativeProbe(SOURCE);out['sourceSha256']=p.sha;p.uc.reg_write(UC_X86_REG_FPCW,cw)
  from native_probe_math import initialize_native_trig
  sine,cosine=initialize_native_trig(p)
  for j in range(180):
   state={'x':rng.uniform(-5000,5000),'y':rng.uniform(0,100),'z':rng.uniform(-5000,5000),'yaw':rng.choice([-.5,-1.1,0,4095.99,4096.5,rng.uniform(-8192,8192)]),'lateralSpeed':rng.uniform(-10,10),'verticalSpeed':rng.uniform(-2,2),'forwardSpeed':rng.uniform(-15,60),'yawRate':rng.uniform(-3,3),'inverseMass':1/rng.choice([200,500,1000]),'inverseInertia':1/rng.choice([250,600,1200])}
   force={'lateralForce':rng.uniform(-4000,4000),'verticalForce':rng.uniform(-1000,1000),'longitudinalForce':rng.uniform(-5000,5000),'torque':rng.uniform(-10000,10000)}
   opt={'fraction':rng.choice([0,0.25,0.7,1]),'stopYaw':bool(j%7==0),'precision':bits}
   if j%3==0:opt['velocityOverride']=[rng.uniform(-5,5),0,rng.uniform(-10,30)]
   dt=rng.choice([0,0.025/8,.03125/8,1/60/8,.1/8,.1])
   for k,o in [('x',0x50),('y',0x54),('z',0x58),('yaw',0x78)]:p.f32(SCRATCH+0x4000+o,state[k]);state[k]=p.float(SCRATCH+0x4000+o)
   for k,o in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac),('inverseMass',0x90),('inverseInertia',0x94)]:p.f32(OBJECT+o,state[k]);state[k]=p.float(OBJECT+o)
   for k,o in [('lateralForce',0xb4),('verticalForce',0xb8),('longitudinalForce',0xbc),('torque',0xc0)]:p.f32(OBJECT+o,force[k]);force[k]=p.float(OBJECT+o)
   for k,v in enumerate(opt.get('velocityOverride',[0,0,0])):p.f32(SCRATCH+0x8000+k*4,v)
   p.uc.reg_write(UC_X86_REG_ECX,OBJECT)
   p.run(0x4911a0,[float(dt),float(opt['fraction']),int(opt['stopYaw']),int('velocityOverride' in opt),SCRATCH+0x8000])
   expected={k:p.float(SCRATCH+0x4000+o) for k,o in [('x',0x50),('y',0x54),('z',0x58),('yaw',0x78)]}
   expected.update({k:p.float(OBJECT+o) for k,o in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac)]})
   out['cases'].append({'state':state,'force':force,'dt':dt,'options':opt,'expected':expected})
  out[f'trig{bits}']={'sin':[p.float(sine+4*i) for i in range(4096)],'cos':[p.float(cosine+4*i) for i in range(4096)]}
 (ROOT/'evidence/native/integrator-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
 print(f"Wrote {len(out['cases'])} native Euler fixtures, CW 0x007f and0x027f")
if __name__=='__main__':generate()
