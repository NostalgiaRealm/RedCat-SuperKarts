#!/usr/bin/env python3
"""Original main-loop admission and absolute engine-clock arithmetic.

Read-only original input. The gate range executes 44331b..44333a; clock calls
execute 48f2c0/48f3e0/48f4d0/48f4e0/48f520. OS clocks, heap and logging are
explicit stubs, and the game-update body is an observation boundary.
"""
import hashlib,json,struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDI,UC_X86_REG_ESI,UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,SCRATCH,STACK

pe=pefile.PE(str(SOURCE/'rcskspel.dat'))
imports={x.name:x.address for group in pe.DIRECTORY_ENTRY_IMPORT for x in group.imports}
out={'format':'superkarts-variable-timing-v1','sourceSha256':hashlib.sha256((SOURCE/'rcskspel.dat').read_bytes()).hexdigest(),
     'scope':__doc__.strip(),'gateTraces':[],'clockTraces':[]}

for name,epoch,offered in [
 ('boundary',0,[(0,0),(8,8),(24,24),(25,25),(25,25),(49,49),(50,50),(75,75)]),
 ('late-no-catchup',1000,[(24,24),(25,25),(325,325),(325,325),(326,326),(349,349),(350,350)]),
 ('distinct-poll-and-start',0,[(25,26),(50,50),(51,52),(76,76),(77,77)]),
 ('integer-display-opportunities',0,[(16,16),(33,33),(50,50),(66,66),(83,83),(100,100)]),
 ('unsigned-wrap',0xfffffff0,[(24,24),(25,25),(49,49),(50,50),(100,100)]),
 ('pause-does-not-reset-gate',60000,[(25,25),(1037,1037),(1038,1038),(1061,1061),(1062,1062)]),
]:
 p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_EDI,SCRATCH+0x9000)
 p.uc.reg_write(UC_X86_REG_ESI,epoch);p.uc.reg_write(UC_X86_REG_ESP,STACK+0xf000)
 current={};calls=[]
 def gate_hook(uc,address,size,unused):
  if address not in [SCRATCH+0x9000,0x4afce0,0x42f4c0]:return
  sp=uc.reg_read(UC_X86_REG_ESP);ret=p.integer(sp)
  if address==SCRATCH+0x9000:
   value=current['start'] if ret==0x443326 else current['poll']
   uc.reg_write(UC_X86_REG_EAX,value)
  elif address==0x42f4c0:calls.append(uc.reg_read(UC_X86_REG_ESI))
  uc.reg_write(UC_X86_REG_EIP,ret);uc.reg_write(UC_X86_REG_ESP,sp+4)
 p.uc.hook_add(UC_HOOK_CODE,gate_hook)
 frames=[]
 for poll,start in offered:
  current={'poll':(epoch+poll)&0xffffffff,'start':(epoch+start)&0xffffffff};before=len(calls)
  p.uc.emu_start(0x44331b,0x44333a,count=200)
  frames.append({**current,'admitted':len(calls)>before,'previousStart':p.uc.reg_read(UC_X86_REG_ESI)})
 out['gateTraces'].append({'name':name,'initialStart':epoch,'frames':frames,'starts':calls})

for precision,cw in [(24,0x7f),(53,0x27f)]:
 for qpc,frequency in [(False,1000),(True,1000000),(True,3579545)]:
  for epoch in [0,60000,86400000]:
   p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw)
   p.uc.mem_write(0x48f4e0,pe.get_data(0x8f4e0,0x32))
   heap=[SCRATCH+0xa000];counter=[round(epoch*frequency/1000)]
   for address in [0x4afce0,0x4bc150,0x4be7ee]:p.uc.mem_write(address,b'\xc3')
   for address in [SCRATCH+0x9000,SCRATCH+0x9010]:p.uc.mem_write(address,b'\xc2\x04\x00')
   p.uc.mem_write(SCRATCH+0x9020,b'\xc3')
   p.u32(imports[b'QueryPerformanceFrequency'],SCRATCH+0x9000)
   p.u32(imports[b'QueryPerformanceCounter'],SCRATCH+0x9010)
   p.u32(imports[b'timeGetTime'],SCRATCH+0x9020)
   def clock_hook(uc,address,size,unused):
    sp=uc.reg_read(UC_X86_REG_ESP)
    if address==0x4be7ee:
     count=p.integer(sp+4);uc.reg_write(UC_X86_REG_EAX,heap[0]);heap[0]+=(count+15)&~15
    elif address==SCRATCH+0x9000:
     uc.mem_write(p.integer(sp+4),struct.pack('<Q',frequency));uc.reg_write(UC_X86_REG_EAX,int(qpc))
    elif address==SCRATCH+0x9010:
     uc.mem_write(p.integer(sp+4),struct.pack('<Q',counter[0]));uc.reg_write(UC_X86_REG_EAX,1)
    elif address==SCRATCH+0x9020:uc.reg_write(UC_X86_REG_EAX,counter[0]&0xffffffff)
   p.uc.hook_add(UC_HOOK_CODE,clock_hook)
   frames=[]
   operations=[('initialize',0),('update',25),('update',58),('update',83),('update',125),
     ('update',425),('update',450),('update',475),('update',500),('update',525),
     ('reset',1537),('update',1537),('update',1538),('update',1563),('update',1596),('update',1621)]
   for operation,offset in operations:
    counter[0]=round((epoch+offset)*frequency/1000)
    before_index=p.integer(0x67ec80)
    p.uc.reg_write(UC_X86_REG_ECX,0x67ec70)
    p.run({'initialize':0x48f2c0,'reset':0x48f520,'update':0x48f3e0}[operation])
    history=[p.float(p.integer(0x67ec28)+i*4) for i in range(4)]
    p.uc.reg_write(UC_X86_REG_ECX,0x67ec70);value=p.run(0x48f4e0,float_return=True)
    frames.append({'operation':operation,'counter':counter[0],'absoluteMs':epoch+offset,
      'absoluteSeconds':p.float(0x67ec78),'rawDelta':None if operation=='reset' else history[before_index],
      'deltaField':p.float(0x67ec7c),'returnedDelta':value,'history':history,'historyIndex':p.integer(0x67ec80)})
   out['clockTraces'].append({'precision':precision,'api':'QPC' if qpc else 'timeGetTime',
     'frequency':frequency,'storedFrequency':p.float(0x67ec74),'epochMs':epoch,'frames':frames})

path=ROOT/'evidence/native/variable-timing-fixtures.json'
path.write_text(json.dumps(out,indent=2)+'\n')
assert out['gateTraces'][1]['starts']==[1025,1325,1350]
assert out['gateTraces'][2]['starts']==[26,52,77]
for trace in out['clockTraces']:
 reset=trace['frames'][10]
 assert reset['historyIndex']==trace['frames'][9]['historyIndex']
 assert reset['deltaField']==0 and len(set(reset['history']))==1
 assert reset['returnedDelta']==struct.unpack('<f',struct.pack('<f',.1))[0]
print('Wrote',len(out['gateTraces']),'gate traces and',len(out['clockTraces']),'absolute-clock traces:',path)
