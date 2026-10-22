#!/usr/bin/env python3
"""Original notification state, queue and animation instructions in Unicorn."""
import importlib.util, json, struct
from pathlib import Path
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import ROOT, SCRATCH, OBJECT

module = importlib.util.spec_from_file_location('animation_probe', ROOT/'tools/native-npc-animation-fixtures.py')
animation = importlib.util.module_from_spec(module);module.loader.exec_module(animation)
TEXT, VTABLE, SETTEXT, MESSAGE = SCRATCH+0x7000, SCRATCH+0x7200, SCRATCH+0x7300, SCRATCH+0x7400
class Probe(animation.AnimationProbe):
    def __init__(self,precision):
        super().__init__()
        self.uc.reg_write(UC_X86_REG_FPCW,0x007f if precision==24 else 0x027f)
        self.alloc=animation.ARENA+0x80000
        self.clock_stack=[]
        self.uc.mem_write(0x4be7ee,b'\xc3')
        self.uc.mem_write(0x431640,b'\xc3');self.uc.mem_write(0x431680,b'\xc3')
        self.uc.mem_write(SETTEXT,b'\xc2\x04\x00')
        self.uc.mem_write(SCRATCH+0x7310,b'\xc3')
        for offset,target in [(0x20,0x4583e0),(0x24,0x463c90),(0x28,0x458570),
                              (0x34,0x463b40),(0x3c,0x463b90),(0x44,SCRATCH+0x7310),(0x50,SETTEXT)]:
            self.u32(VTABLE+offset,target)
        self.u32(TEXT,VTABLE);self.u32(TEXT+0x98,30)
        self.uc.mem_write(TEXT+0x10,struct.pack('<3f',2,2,2))
        self.f32(TEXT+0x7c,2);self.f32(TEXT+0x80,1)
        self.u32(TEXT+0x28,0xffffffff)
        self.u32(OBJECT+0x30,TEXT)
        self.uc.mem_write(0x544b40,struct.pack('<3f',2,2,2))
        self.u32(0x544b4c,0xffffffff)
        self.u32(0x544aa8,1)
        self.uc.hook_add(UC_HOOK_CODE,self.boundary)
    def boundary(self,uc,address,size,_):
        sp=uc.reg_read(UC_X86_REG_ESP);obj=uc.reg_read(UC_X86_REG_ECX)
        if address==0x4be7ee:
            size=self.integer(sp+4);ptr=self.alloc;self.alloc+=(size+15)&~15
            uc.mem_write(ptr,b'\0'*size);uc.reg_write(UC_X86_REG_EAX,ptr)
        elif address==SETTEXT:
            msg=self.integer(sp+4)
            uc.mem_write(TEXT+0x9c,bytes(uc.mem_read(msg,16)))
        elif address==0x431640:
            self.clock_stack.append(self.float(SCRATCH+0x1000));self.f32(SCRATCH+0x1000,0)
        elif address==0x431680:
            self.f32(SCRATCH+0x1000,self.clock_stack.pop())
    def invoke(self,address,args=()):
        self.uc.reg_write(UC_X86_REG_ECX,OBJECT);self.run(address,args)
        assert self.uc.reg_read(UC_X86_REG_EIP)==SCRATCH,hex(self.uc.reg_read(UC_X86_REG_EIP))
    def message(self,text,mode,duration,interrupt=False):
        ptr=self.next_string;self.next_string+=256
        data=text.encode('latin1');self.uc.mem_write(ptr-1,b'\0'+data+b'\0')
        self.uc.mem_write(MESSAGE,struct.pack('<7I',0,ptr,len(data),len(data),mode,duration,0))
        self.invoke(0x46c180 if interrupt else 0x46c1e0,[MESSAGE])
    def snapshot(self):
        ptr=self.integer(TEXT+0xa0);length=self.integer(TEXT+0xa4)
        return {'state':self.integer(OBJECT+8),'elapsedMove':self.float(OBJECT+0x24),
                'loopDuration':self.float(OBJECT+0x28),'duration':self.float(OBJECT+0x64),
                'elapsedTotal':self.float(OBJECT+0x68),'mode':self.integer(OBJECT+0x6c),
                'queueLength':self.integer(OBJECT+0x60),'visible':bool(self.uc.mem_read(TEXT+0x2c,1)[0]),
                'text':bytes(self.uc.mem_read(ptr,length)).decode('latin1') if ptr else '',
                'position':list(struct.unpack('<3f',self.uc.mem_read(TEXT+4,12))),
                'scale':list(struct.unpack('<3f',self.uc.mem_read(TEXT+0x10,12))),
                'cellWidth':self.float(TEXT+0x94),'rgbaPacked':self.integer(TEXT+0x28)}

rows=[]
for precision in [24,53]:
    for mode in range(6):
        p=Probe(precision);actions=[]
        p.message('ORIGINAL',mode,[3000,4000,4000,8000,5000,3000][mode])
        actions.append({'op':'message','text':'ORIGINAL','mode':mode,'duration':[3000,4000,4000,8000,5000,3000][mode],
                        'expected':p.snapshot()})
        for dt in [.016,.1,.134,.249999,.000001,.25,.25,.016,.5,1,1,2,4]:
            p.f32(SCRATCH+0x1000,dt)
            if p.integer(OBJECT+8)==1:p.invoke(0x46c910)
            actions.append({'op':'step','delta':p.float(SCRATCH+0x1000),'expected':p.snapshot()})
        rows.append({'precision':precision,'actions':actions})
    for initial_mode in [0,1,4,5]:
        p=Probe(precision);actions=[]
        def add(text,mode,duration,interrupt=False):
            p.message(text,mode,duration,interrupt)
            actions.append({'op':'message','text':text,'mode':mode,'duration':duration,'interrupt':interrupt,'expected':p.snapshot()})
        def step(dt):
            p.f32(SCRATCH+0x1000,dt)
            if p.integer(OBJECT+8)==1:p.invoke(0x46c910)
            actions.append({'op':'step','delta':p.float(SCRATCH+0x1000),'expected':p.snapshot()})
        add('FIRST',initial_mode,0 if initial_mode==0 else 5000);step(.25)
        add('SECOND',5,3000);add('THIRD',1,4000);step(.001);step(.1)
        add('PAUZE',0,0,True);step(.5)
        p.invoke(0x46cc70);actions.append({'op':'stop','expected':p.snapshot()})
        for dt in [.1,1,2,3,4,5,10]:step(dt)
        rows.append({'precision':precision,'actions':actions})
(ROOT/'evidence/native/hud-notification-fixtures.json').write_text(json.dumps({
    'sourceSHA256':p.sha,'functions':['46c180','46c1e0','46c670','46c890','46c910','46cc70','46cfb0','46d210','46d290','46d320','46d3c0','46d5d0','463c90','463b90'],
    'scope':'All notification queue/state/animation instructions unchanged. String storage, allocation, clock freeze and text assignment are controlled boundaries; text re-layout is independently fixture-tested.',
    'rows':rows},indent=2)+'\n')
print('Captured',sum(len(row['actions']) for row in rows),'original notification state/queue updates.')
