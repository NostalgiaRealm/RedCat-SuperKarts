#!/usr/bin/env python3
"""Capture original 321 state transitions; renderer and sound calls are observed."""
import json
from pathlib import Path
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,SCRATCH
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_FPCW

ROOT=Path(__file__).resolve().parents[1]
traces=[];slides=[]
for precision,control in [(24,0x7f),(53,0x27f)]:
    probe=NativeProbe(SOURCE);probe.uc.reg_write(UC_X86_REG_FPCW,control)
    state=SCRATCH+0x6000
    for address in [0x464e90,0x464f30,0x43b600]:
        probe.uc.mem_write(address,b'\xc3')
    probe.uc.mem_write(0x464dd0,b'\xc2\x08\x00')
    events=[]
    def observe(uc,address,size,data):
        sp=uc.reg_read(UC_X86_REG_ESP)
        if address in (0x464e90,0x464f30):
            events.append({'type':'slide-in' if address==0x464e90 else 'slide-out','elapsed':probe.float(state+4)})
        elif address==0x464dd0:
            events.append({'type':'frame','element':probe.integer(sp+4),'frame':probe.integer(sp+8)})
        elif address==0x43b600:
            pointer=probe.integer(sp+4)
            name=bytes(uc.mem_read(pointer,32)).split(b'\0')[0].decode('ascii')
            events.append({'type':'sound','name':name})
    probe.uc.hook_add(UC_HOOK_CODE,observe)
    schedules=[('25ms',[.025]*300),('32ms',[.032]*220),
        ('jitter',[.001,.1,.027,.02,.075,.03]*60),('overshoot',[1.5]*10),
        ('boundary',[0,1.0999999,.0000001,.1,.6999999,.0000001,.1]*10)]
    for name,deltas in schedules:
        probe.uc.mem_write(state,bytes(0x30));steps=[]
        for delta in deltas:
            events.clear();probe.f32(SCRATCH+0x1000,delta)
            probe.uc.reg_write(UC_X86_REG_ECX,state);probe.run(0x464a70)
            phase=probe.integer(state+0x18)
            steps.append({'delta':probe.float(SCRATCH+0x1000),'expected':{
                'phase':phase,'elapsed':probe.float(state+4),'soundIndex':probe.integer(state+8),
                'green':phase>3,'done':phase==6,'events':list(events)}})
        traces.append({'precision':precision,'name':name,'steps':steps})
    slide=NativeProbe(SOURCE);slide.uc.reg_write(UC_X86_REG_FPCW,control)
    slide.uc.mem_write(0x464c80,b'\xc2\x04\x00')
    def element(uc,address,size,data):
        if address==0x464c80:
            index=slide.integer(uc.reg_read(UC_X86_REG_ESP)+4)
            uc.reg_write(UC_X86_REG_EAX,SCRATCH+0x7000+index*0x80)
    slide.uc.hook_add(UC_HOOK_CODE,element)
    for exiting in [False,True]:
        for time in [i*.03125 for i in range(45)]+[0.001,.7,.8,1.1,1.2,1.20001]:
            slide.uc.mem_write(state,bytes(0x30));slide.f32(state+4,time)
            slide.uc.reg_write(UC_X86_REG_ECX,state);slide.run(0x464f30 if exiting else 0x464e90)
            slides.append({'precision':precision,'exiting':exiting,'elapsed':slide.float(state+4),
                'expectedY':slide.float(SCRATCH+0x7000+8)})
output=ROOT/'evidence/native/countdown-fixtures.json'
output.write_text(json.dumps({'sourceSHA256':probe.sha,
    'method':'isolated original x86 instructions via Unicorn',
    'addresses':['00464a70','00464ff0','00464fc0'],
    'stubs':['controlled float32 delta','sound/render side effects recorded, not executed'],
    'traces':traces,'slides':slides},indent=2)+'\n')
print(f'{sum(len(trace["steps"]) for trace in traces)} original countdown updates: {output}')
