#!/usr/bin/env python3
"""Execute complete original player force routine in racing and result phases."""
import json
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, OBJECT, SCRATCH

p=NativeProbe(SOURCE)
base=json.loads((ROOT/'evidence/gameplay/native-fixtures.json').read_text())
out={'sourceSha256':p.sha,'routine':'0x415990','precision':24,'cases':[]}
for case in base['forceCases']:
    for phase in [0,1,3,4,6,8]:
        p.set_physics(case['preset'],case['record'])
        body=case['body']
        p.set_body(body['forwardSpeed'],body['lateralSpeed'],body['yawRate'],body['mass'])
        for address,key in [(0x53bef4,'tireUpgrade'),(0x53bef0,'motorUpgrade'),(0x53bf00,'gearboxUpgrade'),
                            (0x53bdf4,'handbrake'),(0x53bdf8,'turbo'),(0x507298,'gear')]:
            p.u32(address,int(case[key]))
        p.f32(0x507290,case['rpm'])
        p.u32(0x53b9c0,phase);p.u32(0x50728c,7)
        p.f32(SCRATCH+0x1000,.025)
        for offset in [0xb4,0xb8,0xbc,0xc0]:p.f32(OBJECT+offset,0)
        p.run(0x415990,[0,float(case['throttle']),float(case['brake']),float(case['steering'])])
        expected={key:p.float(OBJECT+offset) for key,offset in [
            ('lateralSpeed',0x9c),('forwardSpeed',0xa4),('yawRate',0xac),
            ('lateralForce',0xb4),('longitudinalForce',0xbc),('torque',0xc0)]}
        expected.update(rpm=p.float(0x507290),gear=p.integer(0x507298),
                        slipMagnitude=p.integer(0x50728c),handbrake=bool(p.integer(0x53bdf4)))
        out['cases'].append({**{key:value for key,value in case.items() if key!='expected'},
                             'phase':phase,'slipMagnitude':7,'expected':expected})
(ROOT/'evidence/native/player-phase-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['cases']),'complete player phase/slip cases')
