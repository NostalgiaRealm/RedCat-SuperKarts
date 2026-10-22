#!/usr/bin/env python3
"""Capture the shipped overlay's controller registration dispatch unchanged.

Only controller construction services are bounded. The original main switch
and race-type getter execute; no original file is modified.
"""
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH

p=NativeProbe(SOURCE)
p.uc.mem_map(0,4096)
names={0x4680a0:'portraits',0x468220:'statistics',0x468560:'minimap',
       0x4683c0:'arrows',0x4686e0:'bonus',0x468860:'special-string',
       0x468b80:'countdown',0x468a00:'stars'}
calls=[]
for address in names:p.uc.mem_write(address,b'\xc3')
def observe(uc,address,size,data):
    if address in names:calls.append({'address':f'{address:08x}','controller':names[address]})
p.uc.hook_add(UC_HOOK_CODE,observe)
modes=[]
for mode in range(6):
    calls=[]
    p.u32(0x53a4b0,mode)
    p.run(0x467e30)
    assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
    modes.append({'raceType':mode,'controllers':calls})
path=ROOT/'evidence/native/hud-controller-dispatch.json'
path.write_text(json.dumps({'format':'superkarts-native-hud-controller-dispatch-v1',
 'sourceSHA256':p.sha,'function':'00467e30','modes':modes,
 'scope':'Original registration order and mode switch; constructor services replaced at their boundaries, no renderer claim.'},indent=2)+'\n')
print(f'Captured {len(modes)} complete original HUD registration paths.')
