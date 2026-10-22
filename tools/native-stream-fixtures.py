#!/usr/bin/env python3
"""Original ribbon and jet constructors/update/retirement; no gameplay substitutes."""
import json, random, struct
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW

def fp(value): return struct.unpack('<f', struct.pack('<f', value))[0]
class Probe(NativeProbe):
    def __init__(self, precision):
        super().__init__(SOURCE)
        self.uc.mem_map(0,4096)
        self.uc.reg_write(UC_X86_REG_FPCW,0x7f if precision==24 else 0x27f)
        initialize_native_trig(self)
        self.uc.mem_map(0x24000000,0x400000)
        self.heap=0x24000000
        self.manager_mode=False
        self.draw_calls=[]
        self.uc.hook_add(UC_HOOK_CODE,self.hook)
    def ret(self,value=0,pop=0):
        sp=self.uc.reg_read(UC_X86_REG_ESP)
        self.uc.reg_write(UC_X86_REG_EAX,value)
        self.uc.reg_write(UC_X86_REG_EIP,self.integer(sp))
        self.uc.reg_write(UC_X86_REG_ESP,sp+4+pop)
    def hook(self,uc,address,size,data):
        if address==0x4be7ee:
            length=self.integer(uc.reg_read(UC_X86_REG_ESP)+4)
            pointer=self.heap;self.heap+=(length+15)&~15
            if self.heap>=0x24400000:raise RuntimeError('fixture heap exhausted')
            self.ret(pointer)
        elif address==0x4bc150:self.ret()
        elif address==0x4a6060:self.ret(0,4)
        elif address==0x4b3830:self.ret(0)
        # Ribbon init's associated flare creation is verified separately.
        elif address==0x488a90:self.ret(SCRATCH+0xb000)
        elif address==0x488b80 and not self.manager_mode:self.ret(0,28)
        elif address==SCRATCH+0xe900:
            sp=uc.reg_read(UC_X86_REG_ESP)
            self.draw_calls.append({'state':self.integer(sp+8),'value':self.integer(sp+12)})
            self.ret(0,12)
        elif address==SCRATCH+0xe910:self.ret(0,12)
        elif address==SCRATCH+0xe920:
            sp=uc.reg_read(UC_X86_REG_ESP)
            self.draw_calls.append({'primitive':self.integer(sp+8),'vertexType':self.integer(sp+12),
                'flags':self.integer(sp+24),'vertices':self.vertices(self.integer(sp+16),self.integer(sp+20))})
            self.ret(0,24)
    def call(self,address,record,args=()):
        self.uc.reg_write(UC_X86_REG_ECX,record);self.run(address,args)
    def vertices(self,address,count):
        return [{'position':[self.float(address+i*32+j*4) for j in range(3)],
                 'color':self.integer(address+i*32+16),'specular':self.integer(address+i*32+20),
                 'uv':[self.float(address+i*32+24+j*4) for j in range(2)]} for i in range(count)]
    def ribbon(self,record):
        vector=self.integer(record+4);start=self.integer(vector+4)
        return {'angle':self.float(record+0x10c),
                'colors':[self.integer(record+0x110+i*4) for i in range(3)],
                'vertices':self.vertices(start,(self.integer(vector+8)-start)//32) if start else []}
    def jet(self,record):
        return {'angle':self.integer(record+0x164),'vertices':self.vertices(record,self.integer(record+0x154))}
    def matrix(self,angles,position):
        matrices=[SCRATCH+0xc000+i*64 for i in range(3)]
        for address,angle in zip(matrices,angles):
            self.run(0x4a22e0,[address,angle&4095])
        self.run(0x4a2560,[SCRATCH+0xc100,matrices[0],matrices[1]])
        self.run(0x4a2560,[SCRATCH+0xc200,SCRATCH+0xc100,matrices[2]])
        matrix=[self.float(SCRATCH+0xc200+i*4) for i in range(16)]
        matrix[12:15]=position
        for i,value in enumerate(matrix):self.f32(SCRATCH+0x4010+i*4,value)
        return matrix
    def managers(self,manager,jet_manager):
        result={'ribbons':[],'jets':[],'pairCount':self.integer(manager+12)}
        for label,record,stride in [('ribbons',manager,0x120),('jets',jet_manager,0x17c)]:
            vector=self.integer(record+4);start=self.integer(vector+4)
            count=(self.integer(vector+8)-start)//stride if start else 0
            for i in range(count):
                entry=start+i*stride
                if label=='ribbons':
                    result[label].append({'body':self.integer(entry+0xe8),
                        'offset':[self.float(entry+0xf0+j*4) for j in range(3)],
                        'rotate':bool(self.uc.mem_read(entry+0x100,1)[0]),
                        'colorIndex':self.integer(entry+0xfc),'rainbow':bool(self.uc.mem_read(entry+0x101,1)[0]),
                        'doubleSided':bool(self.uc.mem_read(entry+0x102,1)[0]),'size':self.float(entry+0x104),
                        'flare':bool(self.uc.mem_read(entry+0x108,1)[0]),
                        'fastShrink':bool(self.uc.mem_read(entry+0x11c,1)[0])})
                else:
                    result[label].append({'body':self.integer(entry+0x138),
                        'offset':[self.float(entry+0x140+j*4) for j in range(3)],
                        'clockwise':bool(self.uc.mem_read(entry+0x151,1)[0]),
                        'colorIndex':self.integer(entry+0x14c),'rainbow':bool(self.uc.mem_read(entry+0x150,1)[0]),
                        'crossed':bool(self.uc.mem_read(entry+0x134,1)[0]),'size':self.float(entry+0x168)})
        return result

def main():
    rng=random.Random(0x489400)
    output={'scope':'Original488100/488210/488850 jet and489400/4894c0/489d20/489f50 ribbon instructions, including original heap vector operations and transform math. Only allocation, resource lookup, debug keyboard, clock and secondary manager creation are bounded adapters. Zero memory policy for native untouched fields.','traces':[],'managers':[],'draws':[]}
    for precision in [24,53]:
        p=Probe(precision);output['sourceSha256']=p.sha
        for case in range(24):
            ribbon,jet,offset=SCRATCH+0x7000,SCRATCH+0x8000,SCRATCH+0x9000
            p.uc.mem_write(ribbon,bytes(0x120));p.uc.mem_write(jet,bytes(0x17c))
            options={'offset':[fp(rng.uniform(-30,30)) for _ in range(3)],
                     'rotate':bool(case%2),'colorIndex':case%6,'rainbow':bool(case%3==0),
                     'doubleSided':bool(case%2),'size':fp(rng.choice([8,10,20,50])),
                     'flare':False,'fastShrink':bool(case%4)}
            jet_options={'offset':options['offset'],'clockwise':bool(case%2),'colorIndex':case%6,
                         'rainbow':options['rainbow'],'crossed':bool(case%3),'size':options['size']}
            for i,value in enumerate(options['offset']):p.f32(offset+i*4,value)
            p.call(0x489400,ribbon)
            p.call(0x4894c0,ribbon,[0,offset,int(options['rotate']),options['colorIndex'],
                int(options['rainbow']),int(options['doubleSided']),float(options['size']),0,int(options['fastShrink'])])
            p.call(0x488100,jet)
            p.call(0x488210,jet,[0,offset,int(jet_options['clockwise']),jet_options['colorIndex'],
                int(jet_options['rainbow']),int(jet_options['crossed']),float(jet_options['size'])])
            trace={'precision':precision,'options':options,'jetOptions':jet_options,'frames':[]}
            for frame in range(20):
                player=bool(case%2)
                p.u32(0x53be28,0 if player else 1)
                speed=rng.choice([-5,0,1,40,90]);throttle=fp(rng.choice([0,20,100]))
                dt=fp(rng.choice([.025,1/32,.1,1/144]))
                p.u32(0x53be34,speed&0xffffffff);p.f32(0x53bd74,throttle);p.f32(SCRATCH+0x1000,dt)
                matrix=p.matrix([rng.randrange(4096) for _ in range(3)],[fp(rng.uniform(-1000,1000)) for _ in range(3)])
                p.call(0x489d20,ribbon)
                updated=p.ribbon(ribbon)
                p.call(0x489f50,ribbon)
                drawn=p.ribbon(ribbon)
                p.call(0x488850,jet)
                trace['frames'].append({'player':player,'speedKmh':speed,'throttle':throttle,'dt':dt,
                    'body':{'matrix':matrix,'position':matrix[12:15]},'updated':updated,'drawn':drawn,'jet':p.jet(jet)})
            if case in [0,1,2,3]:
                p.u32(0x53b9b0,0);p.u32(0x6a621c,SCRATCH+0xe000);p.u32(SCRATCH+0xe000,SCRATCH+0xe100)
                for method,address in [(0x5c,0xe900),(0x68,0xe910),(0x74,0xe920)]:
                    p.u32(SCRATCH+0xe100+method,SCRATCH+address)
                p.u32(0x6a6290,SCRATCH+0xe300);p.u32(0x4fd9fc,0);p.u32(SCRATCH+0xe300,SCRATCH+0xe400)
                p.u32(0x6a5e80,SCRATCH+0xe500);p.u32(0x6a6254,0)
                p.draw_calls=[];before=p.ribbon(ribbon)
                p.call(0x48a170,ribbon)
                output['draws'].append({'precision':precision,'doubleSided':options['rotate'] or options['doubleSided'],
                    'fastShrink':options['fastShrink'],'before':before,'after':p.ribbon(ribbon),'calls':p.draw_calls})
                p.draw_calls=[];p.call(0x4888b0,jet)
                output['draws'].append({'precision':precision,'jet':p.jet(jet),'calls':p.draw_calls})
            output['traces'].append(trace)
        p.manager_mode=True
        for case in range(8):
            manager,jet_manager=SCRATCH+0xa000,SCRATCH+0xb000
            p.uc.mem_write(manager,bytes(0x10));p.uc.mem_write(jet_manager,bytes(0xc))
            p.call(0x48a430,manager);p.call(0x488a40,jet_manager)
            p.u32(0x53be28,4)
            flags={'jetstreams':case!=5,'alphaBlending':case!=6,'paletted':case==7}
            p.u32(0x53ba78,int(flags['jetstreams']));p.u32(0x53ba60,int(flags['alphaBlending']))
            p.u32(0x53b9b0,int(flags['paletted']))
            trace={'precision':precision,'flags':flags,'operations':[]}
            for operation in range(45):
                body=rng.randrange(10) if case<4 else operation
                if operation%4==3:
                    p.call(0x48a890,manager,[body])
                    command={'op':'remove','body':body}
                elif operation%5==4:
                    for j,value in enumerate([-18,12,-12,18,12,-12]):p.f32(SCRATCH+0x9000+j*4,value)
                    rotate=int(operation%2);size=fp(10)
                    p.call(0x48a6d0,manager,[body,SCRATCH+0x9000,SCRATCH+0x900c,float(size),rotate])
                    command={'op':'pair','body':body,'rotate':bool(rotate),'size':size}
                else:
                    options={'offset':[0,10,-28],'rotate':bool(operation%2),'colorIndex':operation%10,
                             'rainbow':bool(operation%3==0),'doubleSided':bool(operation%3==1),
                             'size':fp(rng.choice([8,10,20])),'flare':True,'fastShrink':bool(operation%2)}
                    for j,value in enumerate(options['offset']):p.f32(SCRATCH+0x9000+j*4,value)
                    p.call(0x48a570,manager,[body,SCRATCH+0x9000,int(options['rotate']),options['colorIndex'],
                        int(options['rainbow']),int(options['doubleSided']),float(options['size']),1,int(options['fastShrink'])])
                    command={'op':'add','body':body,'options':options}
                trace['operations'].append({**command,'expected':p.managers(manager,jet_manager)})
            output['managers'].append(trace)
    (ROOT/'evidence/native/stream-fixtures.json').write_text(json.dumps(output,indent=2)+'\n')
    print('Wrote960 original ribbon update/shrink,960 jet frames and720 manager operations')

if __name__=='__main__':main()
