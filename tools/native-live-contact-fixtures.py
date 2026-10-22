#!/usr/bin/env python3
"""Original sweep at a captured port stall pose; not a full-process replay."""
import json
import math
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH
from native_probe_math import initialize_native_trig
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_FPCW, UC_X86_REG_ESP, UC_X86_REG_EIP

out={'routines':['0x499c30','0x492470'],'cases':[],
     'method':'Original sweep at the captured France stall pose, plus signed velocity variants. One observed opponent candidate is retained. VerticalSpeed is controlled0; this is not a full trajectory comparison.'}
radius=json.loads((ROOT/'public/assets/manifest.json').read_text())['meshes']['kart03.d3d']['horizontalRadius']
for precision,cw in [(24,0x7f),(53,0x27f)]:
    p=NativeProbe(SOURCE)
    p.uc.reg_write(UC_X86_REG_FPCW,cw)
    initialize_native_trig(p)
    out['sourceSha256']=p.sha
    state={}
    def rectangle(address,body,index):
        b=body.get('bounds',bounds);y=b.get('minY',0)
        values=[b['minX'],y,b['minZ'],b['maxX'],y,b['minZ'],
                b['maxX'],y,b['maxZ'],b['minX'],y,b['maxZ'],
                *body['position']]
        for offset,value in enumerate(values):p.f32(address+offset*4,value)
        p.f32(address+0x3c,radius)
        p.u32(address+0x40,index)
        p.u32(address+0x44,(math.ceil(body['yaw']) if body['yaw']>0 else math.floor(body['yaw']))&0xffffffff)
        p.u32(address+0x48,1)
    def hook(uc,address,size,data):
        if address not in [0x499b20,0x4999c0]:return
        sp=uc.reg_read(UC_X86_REG_ESP)
        if address==0x499b20:
            for index,body in enumerate(state['others']):rectangle(0x680c68+index*0x4c,body,index+1)
            p.u32(0x6847c8,len(state['others']))
        else:rectangle(p.integer(sp+8),state['body'],0)
        uc.reg_write(UC_X86_REG_EIP,p.integer(sp))
        uc.reg_write(UC_X86_REG_ESP,sp+4)
    p.uc.hook_add(UC_HOOK_CODE,hook)
    live=json.loads((ROOT/'evidence/gameplay/force-audit-live-contact.json').read_text())
    for case in range(8):
        body={**live['body'],'verticalSpeed':0.0}
        others=[{**live['contacts'][0]['candidate']['body']}]
        bounds={k:live['contacts'][0]['candidate'][k] for k in ['minX','maxX','minY','maxY','minZ','maxZ']}
        body['bounds']=bounds
        others[0]['bounds']=bounds
        if case&1:body['forwardSpeed']=-body['forwardSpeed']
        if case&2:body['lateralSpeed']=-body['lateralSpeed']
        if case&4:body['yawRate']=-body['yawRate']
        for item in [body,*others]:
            for key in ['yaw','lateralSpeed','verticalSpeed','forwardSpeed','yawRate']:
                if key in item:
                    p.f32(SCRATCH+0xf000,item[key]);item[key]=p.float(SCRATCH+0xf000)
            for axis,value in enumerate(item['position']):
                p.f32(SCRATCH+0xf000,value);item['position'][axis]=p.float(SCRATCH+0xf000)
        state.update(body=body,others=others)
        p.u32(OBJECT+0x44,1);p.u32(OBJECT+4,3)
        for key,offset in [('lateralSpeed',0x9c),('verticalSpeed',0xa0),('forwardSpeed',0xa4),('yawRate',0xac)]:
            p.f32(OBJECT+offset,body[key])
        dt=.003125
        p.f32(SCRATCH+0xf000,dt);dt=p.float(SCRATCH+0xf000)
        fraction=p.run(0x499c30,[0,SCRATCH+0xa000,dt],True)
        contact=None
        if p.integer(0x6a5b58):
            contact={'first':p.integer(0x6a5b60),'second':p.integer(0x6a5b64),
                     'point':[p.float(0x6a5b68+i*4) for i in range(3)],
                     'normal':[p.float(0x6a5b74+i*4) for i in range(3)]}
        expected={'fraction':fraction,'stopYaw':bool(p.integer(SCRATCH+0xa000)),'contact':contact}
        # 492470 returns EAX, writes its optional displacement at param3.
        from unicorn.x86_const import UC_X86_REG_EAX
        p.run(0x492470,[0,dt,SCRATCH+0xa100,float(fraction),SCRATCH+0xa000])
        if p.uc.reg_read(UC_X86_REG_EAX):
            expected['velocityOverride']=[p.float(SCRATCH+0xa100+i*4) for i in range(3)]
        expected['stopYaw']=bool(p.integer(SCRATCH+0xa000))
        out['cases'].append({'precision':precision,'bounds':bounds,'body':body,'others':others,'dt':dt,'expected':expected})
(ROOT/'evidence/gameplay/native-live-contact-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'native dynamic sweep and slide cases')
