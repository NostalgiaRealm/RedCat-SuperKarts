#!/usr/bin/env python3
"""Run native bonus mesh/texture selection and repeated projectile updates."""
import json
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH


def main():
    p=NativeProbe(SOURCE);p.uc.mem_map(0x22000000,0x10000)
    config=json.loads((ROOT/'public/assets/config.json').read_text())
    names=['kogel0','kogel0','kogel1','dropper0','dropper1','turbo0','star','bonus0']
    p.u32(0x543d1c,1);p.u32(0x6a5f78,0x22000000);p.u32(0x6a5f30,0x22001000)
    lookups={}
    for type_id in range(1,8):
        p.u32(0x4f0fb8+type_id*4,type_id)
        p.u32(0x22000000+type_id*9+4,0x22000100+type_id*0x40)
        sequence=config['gen_anim.ini'][names[type_id]]
        for frame in range(int(sequence['count'])):
            pair=type_id*10+frame
            mesh,texture=[v.strip().lower()for v in sequence[str(frame)].split(',')]
            p.u32(0x22000100+type_id*0x40+frame*4,pair)
            p.u32(0x22001000+pair*16,pair+1000)
            p.u32(0x22001000+pair*16+4,pair+2000)
            lookups[pair]={'frame':frame,'mesh':mesh,'texture':texture}
    # Projection/ground/movement are explicit boundaries; bonus selectors and
    # complete CShotBonus::Handle age/state path execute original instructions.
    p.uc.mem_write(0x430ff0,b'\xd9\xee\xc3')
    p.uc.mem_write(0x455ce0,b'\xc3')
    p.uc.mem_write(0x4a09e0,b'\xc3')
    p.u32(0x508610,0xffffffff)
    point=SCRATCH+0x6000;render=SCRATCH+0x4000
    cases=[]
    for kind,offset,types,levels in [('pickup',0,range(1,8),[1]),('owned',1,range(1,6),[1,2,3]),
                                   ('shot',4,range(1,5),[1,2,3])]:
        for type_id in types:
            for level in levels:
                p.uc.mem_write(point,bytes(64))
                for off,value in [(4,type_id),(8,2),(12,0),(16,0),(20,offset),(24,level)]:
                    p.u32(point+off,value)
                p.uc.reg_write(UC_X86_REG_ECX,point+4);p.run(0x4500e0)
                pair=p.integer(render+0x99)-1000
                assert p.integer(render+0x95)==pair+2000
                result={'kind':kind,'type':type_id,'level':level,**lookups[pair]}
                if kind=='shot':
                    samples=[]
                    for tick in range(80):
                        p.f32(SCRATCH+0x1000,.025)
                        p.uc.reg_write(UC_X86_REG_ECX,point);p.run(0x455a10)
                        assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
                        samples.append({'meshId':p.integer(render+0x99),
                            'textureId':p.integer(render+0x95),'age':p.float(point+0x1c)})
                    assert all(row['meshId']==pair+1000 and row['textureId']==pair+2000 for row in samples)
                    result['updates']=samples
                cases.append(result)
    (ROOT/'evidence/native/bonus-visual-fixtures.json').write_text(json.dumps({
        'format':'superkarts-native-bonus-visual-v1','sha256':p.sha,'cases':cases},indent=2)+'\n')
    print(f'Wrote {len(cases)} native frame selections and960 fixed-frame projectile updates')


if __name__=='__main__':main()
