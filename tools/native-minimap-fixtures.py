#!/usr/bin/env python3
"""Original complete minimap position callback; only overlay validity skipped."""
import json,random,struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT,OBJECT,SCRATCH
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_FPCW
def main():
    rng=random.Random(0x466830)
    out={'routines':['466830','4669d0'],'scope':'Complete original coordinate callback and overlay position setter458400. Overlay validity and optional interactive calibration UI are excluded. All original PE transform values retained.',
         'cases':[],'orientations':[]}
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        p=NativeProbe(SOURCE);p.uc.mem_map(0,0x1000);p.uc.reg_write(UC_X86_REG_FPCW,cw)
        p.uc.mem_write(0x466a20,b'\xc3');p.uc.mem_write(0x544af4,b'\0')
        record=SCRATCH+0x8000
        table=[list(struct.unpack('<4fI',p.uc.mem_read(0x4f4620+i*20,20))) for i in range(6)]
        out['transforms']=table;out['sourceSha256']=p.sha
        for case in range(360):
            track=case%6;opponent_count=case%5
            p.uc.mem_write(record+0x30,bytes(p.uc.mem_read(0x4f4620+track*20,20)))
            p.u32(0x508610,opponent_count);p.u32(0x53be28,opponent_count)
            p.u32(record+0x2c,SCRATCH+0x9000)
            player=[rng.uniform(-10000,10000) for _ in range(3)]
            for axis,value in enumerate(player):p.f32(0x53be44+axis*4,value);player[axis]=p.float(0x53be44+axis*4)
            opponents=[]
            for i in range(opponent_count):
                position=[rng.uniform(-10000,10000) for _ in range(3)]
                p.u32(record+8+i*4,SCRATCH+0x9020+i*32)
                p.u32(0x5081bc+i*0x70,i);p.u32(OBJECT+i*0xd0+12,i)
                for axis,value in enumerate(position):
                    p.f32(SCRATCH+0x4000+i*0xa9+0x50+axis*4,value)
                    position[axis]=p.float(SCRATCH+0x4000+i*0xa9+0x50+axis*4)
                opponents.append(position)
            p.uc.reg_write(UC_X86_REG_ECX,record);p.run(0x466830)
            expected=[{'player':True,'index':opponent_count,'position':[p.float(SCRATCH+0x9004+axis*4) for axis in range(3)]}]
            for i in range(opponent_count):
                expected.append({'player':False,'index':i,'position':[p.float(SCRATCH+0x9024+i*32+axis*4) for axis in range(3)]})
            out['cases'].append({'precision':precision,'track':track,'player':player,'opponents':opponents,'expected':expected})
        for orientation in range(4):
            for case in range(20):
                position=[rng.uniform(-1,1) for _ in range(3)]
                for axis,value in enumerate(position):p.f32(SCRATCH+0xa000+axis*4,value);position[axis]=p.float(SCRATCH+0xa000+axis*4)
                p.u32(record+0x40,orientation);p.uc.reg_write(UC_X86_REG_ECX,record);p.run(0x4669d0,[SCRATCH+0xa000])
                out['orientations'].append({'orientation':orientation,'position':position,
                    'expected':[p.float(SCRATCH+0xa000+axis*4) for axis in range(3)]})
    (ROOT/'evidence/native/minimap-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
    print('Wrote',len(out['cases']),'original minimap updates and',len(out['orientations']),'orientation cases')
if __name__=='__main__':main()
