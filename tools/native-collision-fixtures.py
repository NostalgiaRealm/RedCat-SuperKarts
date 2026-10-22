#!/usr/bin/env python3
"""Execute native static rail contact response 0x49c220 at both x87 precisions."""
import json,random
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,OBJECT,SCRATCH
from unicorn.x86_const import UC_X86_REG_FPCW
rng=random.Random(49220);out={'routine':'0x49c220','cases':[]}
for bits,cw in [(24,0x7f),(53,0x27f)]:
 p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);out['sourceSha256']=p.sha
 for i in range(160):
  state={'lateralSpeed':rng.uniform(-15,15),'verticalSpeed':rng.uniform(-2,2),'forwardSpeed':rng.uniform(-15,60),'yawRate':rng.uniform(-3,3),'pitchRate':0,'rollRate':0,'inverseMass':rng.choice([0,1/200,1/500,1/1000]),'inverseInertia':rng.choice([0,1/500,1/1000]),'restitution':rng.choice([0,.2,.5,1])}
  normal=rng.choice([[1,0,0],[-1,0,0],[0,0,1],[0,0,-1],[.6,0,.8],[-.6,.1,-.8]])
  contact={'point':[rng.uniform(-15,15),0,rng.uniform(-30,30)],'normal':normal}
  for k,o in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac),('pitchRate',0xa8),('rollRate',0xb0),('inverseMass',0x90),('inverseInertia',0x94),('restitution',0x98)]:p.f32(OBJECT+o,state[k]);state[k]=p.float(OBJECT+o)
  addr=SCRATCH+0x9000;p.u32(addr+8,0)
  for base,key in [(0x10,'point'),(0x1c,'normal')]:
   for j,v in enumerate(contact[key]):p.f32(addr+base+4*j,v);contact[key][j]=p.float(addr+base+4*j)
  p.f32(0x6a5b80,0);p.run(0x49c220,[addr])
  expected={k:p.float(OBJECT+o) for k,o in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac),('pitchRate',0xa8),('rollRate',0xb0)]};expected['impulse']=p.float(0x6a5b80)
  out['cases'].append({'precision':bits,'state':state,'contact':contact,'expected':expected})
(ROOT/'evidence/native/collision-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'contact fixtures')
