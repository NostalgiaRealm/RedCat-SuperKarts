#!/usr/bin/env python3
"""Execute original camera mode setters and the complete non-debug key prefix."""
import json, random, struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH, OBJECT

rng=random.Random(0x41e280)
out={'functions':['41e280','41d920','498c00','420f00'],
     'method':'Original mode setters/update and original key prefix through sector lookup; key API and logger supplied.',
     'updates':[],'keys':[],'green':[]}
camera=SCRATCH+0x9000
def f32(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def vec(p,address):return [p.float(address+4*i)for i in range(3)]
for precision,cw in [(24,0x7f),(53,0x27f)]:
 p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw);out['sourceSha256']=p.sha
 p.uc.mem_write(0x4afce0,b'\xc3');p.uc.mem_write(0x4afee0,b'\xc3')
 p.u32(0x680c54,31);p.u32(0x680ba0,camera);p.u32(0x4e3068,0)
 for i in range(10):p.u32(0x508620+4*i,0)
 keyset=set()
 # Run original4b3830 (including modifier rejection), replacing only Win32.
 key_api=SCRATCH+0x300
 p.u32(0x4d21cc,key_api);p.uc.mem_write(key_api,b'\xc2\x04\x00')
 def hook(uc,address,size,data):
  if address==key_api:uc.reg_write(UC_X86_REG_EAX,0x8000 if p.integer(uc.reg_read(UC_X86_REG_ESP)+4)in keyset else 0)
  elif address==0x4977d0:uc.emu_stop()
 p.uc.hook_add(UC_HOOK_CODE,hook)
 def initialize(prior,position,previous,matrix):
  p.uc.mem_write(camera,bytes(0x178))
  p.u32(camera+0x74,1)
  for i,v in enumerate(position):p.f32(SCRATCH+0x4050+4*i,v)
  for row in range(3):
   for col in range(3):p.f32(SCRATCH+0x4010+4*(row*4+col),matrix[row*3+col])
  for i,v in enumerate(previous):p.f32(camera+8+4*i,v);p.f32(camera+0xa0+4*i,v)
  p.run(0x41e280,[1]);p.run(0x41e280,[prior])
 def expected():
  return {'position':vec(p,camera+8),'target':vec(p,camera+0x54),'up':vec(p,camera+0x60),
          'mode':p.integer(0x4e3064),'bodyVisible':bool(p.integer(OBJECT+0x3c)),
          'positionDamping':bool(p.integer(camera+0x6c))}
 for prior in [0,1,3,5]:
  for mode in [0,1,3,5]:
   for i in range(12):
    position=[f32(rng.uniform(-5000,5000))for _ in range(3)]
    previous=[f32(v+rng.uniform(-200,200))for v in position]
    matrix=[f32(rng.uniform(-1,1))for _ in range(9)]
    initialize(prior,position,previous,matrix);p.run(0x41e280,[mode])
    p.uc.reg_write(UC_X86_REG_ECX,camera);p.run(0x498c00)
    out['updates'].append({'precision':precision,'prior':prior,'mode':mode,
      'body':{'position':position,'matrix':matrix},'previous':previous,'expected':expected()})
 for prior in [0,1,3,5]:
  for phase in [0,1,3,6]:
   for mask in range(32):
    initialize(prior,[0,0,0],[0,20,-150],[1,0,0,0,1,0,0,0,1])
    p.u32(0x508670,6);p.u32(0x4e2ac8,3);p.u32(0x53b9c0,phase);p.u32(0x53ba6c,0)
    keyset={49+i for i in range(4)if mask&(1<<i)}
    if mask&16:keyset.add(16)
    p.run(0x41d920)
    out['keys'].append({'precision':precision,'prior':prior,'phase':phase,'keys':sorted(keyset),
      'expected':{'mode':p.integer(0x4e3064),'rememberedMode':p.integer(0x4e2ac8),
                  'selected':p.integer(0x508670)==0,'bodyVisible':bool(p.integer(OBJECT+0x3c)),
                  'positionDamping':bool(p.integer(camera+0x6c))}})
 # The phase setter is unrelated to the camera; use a plain cdecl return.
 p.uc.mem_write(0x42f740,b'\xc3')
 for prior in [0,1,3,5]:
  position=[100.,20.,-50.];previous=[50.,60.,-150.];matrix=[1.,0.,0.,0.,1.,0.,0.,0.,1.]
  initialize(prior,position,previous,matrix);p.run(0x420f00)
  out['green'].append({'precision':precision,'prior':prior,'body':{'position':position,'matrix':matrix},
                     'previous':previous,'expected':expected()})
(ROOT/'evidence/native/camera-control-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print({key:len(out[key])for key in ['updates','keys','green']})
