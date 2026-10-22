#!/usr/bin/env python3
"""Run original statistics constructor/init/hold/update instructions.

Only generic CString, element lookup/set-text, timer0 and assertion services
are bounded. Native hold arithmetic and branching execute unchanged, including
the original absolute-clock getter and truncating x87 conversion. No original
artifact is modified. Existing hud-text fixtures independently cover formatting.
"""
import json
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT

def formatted(ms):
    return f'{ms//60000:02d}:{(ms//1000)%60:02d}:{(ms//10)%100:02d}'[:11]

traces=[];pause_resets=[]
for precision, control in [(24,0x007f),(53,0x027f)]:
    p=NativeProbe(SOURCE)
    p.uc.mem_map(0,4096)
    p.uc.reg_write(UC_X86_REG_FPCW,control)
    strings={};displays={};writes=[];lookups=[]
    element_ids=['STRING_LAP_VALUE','STRING_LAPOF_VALUE','STRING_LAPTIME_VALUE','STRING_BESTLAP_VALUE']
    elements={name:SCRATCH+0x6000+i*0x100 for i,name in enumerate(element_ids)}
    vtable=SCRATCH+0x7000;setter=SCRATCH+0x7100
    p.u32(vtable+0x50,setter);p.uc.mem_write(setter,b'\xc2\x04\x00')
    for element in elements.values():p.u32(element,vtable)
    p.uc.mem_write(0x46f250,b'\xc3') # Pointer validation only.
    p.uc.mem_write(0x46eac0,b'\xc3') # Independent timed-countdown initializer.
    p.uc.mem_write(0x46f0b0,b'\xc3') # Independent timed-countdown update.
    for address,cleanup in [(0x40b4f0,4),(0x40b540,8),(0x4621a0,4),(0x412870,12),
                            (0x463d20,0),(0x412710,0),(0x46f5f0,0),(0x42a4d0,0)]:
        p.uc.mem_write(address,b'\xc2'+struct.pack('<H',cleanup) if cleanup else b'\xc3')
    def word(offset):return p.integer(p.uc.reg_read(UC_X86_REG_ESP)+offset)
    def cstring(address):
        result=bytearray()
        while p.uc.mem_read(address,1)!=b'\0':
            result.extend(p.uc.mem_read(address,1));address+=1
        return result.decode('latin1')
    def observe(uc,address,size,data):
        this=uc.reg_read(UC_X86_REG_ECX)
        if address==0x40b4f0:
            strings[this]='';p.uc.mem_write(this+4,b'\0'*12)
        elif address==0x40b540:strings[this]=bytes(p.uc.mem_read(word(4),word(8))).decode('latin1')
        elif address==0x4621a0:
            name=strings[word(4)];lookups.append(name);uc.reg_write(UC_X86_REG_EAX,elements[name])
        elif address==0x463d20:
            strings[word(4)]=str(word(8));uc.reg_write(UC_X86_REG_EAX,word(4))
        elif address==0x412710:
            strings[word(4)]=cstring(word(8))+strings.get(word(12),'');uc.reg_write(UC_X86_REG_EAX,word(4))
        elif address==0x412870:strings[this]=strings.get(word(4),'')
        elif address==0x46f5f0:
            strings[word(4)]=formatted(word(8));uc.reg_write(UC_X86_REG_EAX,word(4))
        elif address==0x42a4d0:
            assert word(4)==0;uc.reg_write(UC_X86_REG_EAX,p.integer(SCRATCH+0x3000))
        elif address==setter:
            name=next(name for name,element in elements.items() if element==this)
            displays[name]=strings.get(word(4),'');writes.append(name)
    p.uc.hook_add(UC_HOOK_CODE,observe)
    definitions=[
      ('first-display', [('update',0,0,0),('notify',0,.99,0),('update',0,1,1000)]),
      ('fractional-hold', [('update',0,99.95,39950),('notify',1,100.975,0),
        ('update',1,100.975,25),('update',1,102.99999,2025),('update',1,103,2050),
        ('update',1,103.025,2075)]),
      ('repeated-notice', [('update',0,10.1,10100),('notify',1,10.9,0),
        ('update',1,11.1,200),('notify',1,12.75,0),('update',1,13,2100),
        ('update',1,15,4100),('update',1,15.025,4125)]),
      ('pause-absolute-clock', [('update',0,50.7,15700),('notify',1,50.725,0),
        ('update',1,50.75,25),('update',1,150.75,25),('update',1,150.775,50)]),
      ('pre-first-display-notice', [('notify',1,20.9,0),('update',1,20.925,25),
        ('update',1,23,2100),('update',1,23.025,2125)]),
      ('zero-and-negative-laps', [('update',0,1,1000),('notify',0,1.1,0),
        ('update',0,1.2,1200),('notify',-1,1.3,0),('update',0,1.4,1400)]),
    ]
    for stamp in [0,1,123,65536,1048576]:
        definitions.append((f'float-boundary-{stamp}',[
          ('update',0,stamp+.25,10000),('notify',1,stamp+.99999999,0),
          ('update',1,stamp+3.999999,2999),('update',1,stamp+4,3000),
          ('update',1,stamp+4.025,3025)]))
    for race_type in [0,1,2,3]:
      for name,operations in definitions:
        strings={};displays={name:'' for name in element_ids};writes=[];lookups=[]
        p.uc.mem_write(OBJECT,b'\0'*0x100)
        p.u32(0x53a4b0,race_type);p.u32(0x53ba1c,5);p.u32(0x53ba0c,0x0fffffff)
        p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x46e680,[OBJECT+0x200])
        assert p.integer(OBJECT+12)==0xffffffff
        p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x46e6a0)
        assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
        initial={'holdStampSeconds':-1,'text':displays['STRING_LAPTIME_VALUE'],
                 'writtenElements':list(writes),'lookups':list(lookups)}
        frames=[]
        for method,lap,now,timer in operations:
            writes=[];p.u32(0x53ba18,lap&0xffffffff);p.f32(0x67ec78,now)
            p.u32(SCRATCH+0x3000,timer);p.uc.reg_write(UC_X86_REG_ECX,OBJECT)
            p.run(0x46f230 if method=='notify' else 0x46ecc0)
            assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
            stamp=p.integer(OBJECT+12);stamp=stamp-2**32 if stamp>=2**31 else stamp
            frames.append({'method':method,'lapCount':lap,'nowSeconds':p.float(0x67ec78),
              'timerMs':timer,'lapText':formatted(timer),'state':{'holdStampSeconds':stamp,
              'text':displays['STRING_LAPTIME_VALUE']},'writesLapText':'STRING_LAPTIME_VALUE' in writes})
        traces.append({'precision':precision,'raceType':race_type,'name':name,'initial':initial,'frames':frames})
    # 42f350 invokes this original reset after the blocking pause/requester.
    # Its wall-clock value advances even though race timer0 remained paused.
    p.u32(0x4d2228,SCRATCH+0x7200)
    p.uc.mem_write(SCRATCH+0x7200,b'\xa1'+struct.pack('<I',SCRATCH+0x3020)+b'\xc3')
    p.u32(0x67ec70,0);p.f32(0x67ec74,1000);p.u32(0x67ec28,SCRATCH+0x4000)
    for before,after_ms in [(50.75,150750),(100.975,102999),(100.975,103000)]:
        p.f32(0x67ec78,before);p.u32(SCRATCH+0x3020,after_ms)
        p.uc.reg_write(UC_X86_REG_ECX,0x67ec70);p.run(0x48f520)
        assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
        pause_resets.append({'precision':precision,'beforeSeconds':before,'wallMilliseconds':after_ms,
          'afterSeconds':p.float(0x67ec78),'deltaSeconds':p.float(0x67ec7c),
          'history':[p.float(SCRATCH+0x4000+i*4) for i in range(4)]})
target=ROOT/'evidence/native/lap-display-fixtures.json'
target.write_text(json.dumps({'format':'superkarts-native-lap-display-v1','sourceSHA256':p.sha,
 'functions':['0046e680','0046e6a0','0046f230','0046ecc0','0048f4d0','004be698','0048f520'],
 'scope':'Original constructor, initialization lookup/write targets and complete statistics update/hold control flow; CString/format/set-text and timer services bounded; no Windows renderer observation.',
 'traces':traces,'pauseResets':pause_resets},indent=2)+'\n')
print(f'Captured {len(traces)} initialized original traces and {sum(len(t["frames"]) for t in traces)} callbacks.')
