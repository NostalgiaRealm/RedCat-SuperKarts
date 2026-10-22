#!/usr/bin/env python3
"""Execute shipped x86 clock functions with controlled API clocks in Unicorn.

No Windows process is run, and no source input is changed. Only the two system
clock imports are substituted; timing arithmetic executes original instructions.
"""
from pathlib import Path
import struct,json,hashlib
import pefile
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ECX,UC_X86_REG_EAX,UC_X86_REG_EIP
ROOT=Path(__file__).resolve().parents[1]
SRC=Path('/home/rick/Games/redcat-superkarts/drive_c/Program Files (x86)/Davilex/RedCat Super Karts/data/rcskspel.dat')
CLOCK=0x67ec70;SCRATCH=0x20000000;STACK=0x10000000;API=0x70000000
class Clock:
 def __init__(self,qpc=True):
  p=pefile.PE(str(SRC));self.uc=u=Uc(UC_ARCH_X86,UC_MODE_32)
  u.mem_map(0x400000,(p.OPTIONAL_HEADER.SizeOfImage+4095)&~4095);u.mem_write(0x400000,p.get_memory_mapped_image())
  for a in [SCRATCH,STACK,API]:u.mem_map(a,0x10000)
  self.u32(0x4d204c,API+0x100);self.u32(0x4d2228,API+0x200)
  self.u32(CLOCK,int(qpc));self.f32(CLOCK+4,1000000 if qpc else 1000);self.f32(CLOCK+8,0);self.f32(CLOCK+12,0)
  self.u32(0x67ec28,SCRATCH+0x200);self.u32(0x67ec80,0)
  for i in range(4):self.f32(SCRATCH+0x200+4*i,.1)
  u.mem_write(SCRATCH+0x100,b'\xdd\x1d'+struct.pack('<I',SCRATCH+0x400))
  self.counter=0;self.qpc=qpc
  u.hook_add(UC_HOOK_CODE,self.hook)
 def u32(self,a,v):self.uc.mem_write(a,struct.pack('<I',v))
 def f32(self,a,v):self.uc.mem_write(a,struct.pack('<f',v))
 def read32(self,a):return struct.unpack('<I',self.uc.mem_read(a,4))[0]
 def float(self,a):return struct.unpack('<f',self.uc.mem_read(a,4))[0]
 def hook(self,u,a,size,data):
  if a not in [API+0x100,API+0x200]:return
  sp=u.reg_read(UC_X86_REG_ESP);ret=self.read32(sp)
  if a==API+0x100:
   ptr=self.read32(sp+4);u.mem_write(ptr,struct.pack('<Q',self.counter));u.reg_write(UC_X86_REG_EAX,1);sp+=8
  else:u.reg_write(UC_X86_REG_EAX,self.counter);sp+=4
  u.reg_write(UC_X86_REG_ESP,sp);u.reg_write(UC_X86_REG_EIP,ret)
 def run(self,entry,fp=False):
  sp=STACK+0xf000;self.u32(sp,SCRATCH+0x100 if fp else SCRATCH)
  self.uc.reg_write(UC_X86_REG_ESP,sp);self.uc.reg_write(UC_X86_REG_ECX,CLOCK)
  self.uc.emu_start(entry,SCRATCH+0x106 if fp else SCRATCH,count=10000)
  if fp:return struct.unpack('<d',self.uc.mem_read(SCRATCH+0x400,8))[0]
 def sample(self,ms):
  self.counter+=round(ms*(1000 if self.qpc else 1));ix=self.read32(0x67ec80)
  self.run(0x48f3e0)
  return {'inputMilliseconds':ms,'counter':self.counter,'nativeRawDelta':self.float(SCRATCH+0x200+ix*4),'nativeUnclampedDelta':self.float(CLOCK+12),'nativeReturnedDelta':self.run(0x48f4e0,True),'nativeAbsoluteTime':self.run(0x48f4d0,True)}
traces=[]
for qpc in [True,False]:
 for name,steps in [('31.25FPS',[32]*30),('60FPS',[1000/60]*30),('120FPS',[1000/120]*30),('144FPS',[1000/144]*30),('240FPS',[1000/240]*30),('fluctuating',[4,5,7,16,33,67,100,8]*4),('stalls',[32]*8+[500,2000,0,32,32,32,32]),('zero',[0]*8)]:
  c=Clock(qpc);samples=[c.sample(ms) for ms in steps]
  c.run(0x48f520);reset={'deltaField':c.float(CLOCK+12),'returnedDelta':c.run(0x48f4e0,True),'history':[c.float(SCRATCH+0x200+i*4) for i in range(4)]}
  traces.append({'name':name,'clockAPI':'QueryPerformanceCounter' if qpc else 'timeGetTime','samples':samples,'reset':reset})
out={'sourceSha256':hashlib.sha256(SRC.read_bytes()).hexdigest(),'method':'Unicorn x86 original instructions; mocked clock APIs only; no Windows execution','functions':['0x48f3e0','0x48f4e0','0x48f4d0','0x48f520'],'comparisonToleranceSeconds':1e-8,'toleranceReason':'Approximately one float32 ULP at0.1sec; adopted before comparison','traces':traces}
p=ROOT/'evidence/native/timing-fixtures.json';p.write_text(json.dumps(out,indent=2));print('Wrote',p,len(traces),'traces',sum(len(x['samples']) for x in traces),'samples')
