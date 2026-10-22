#!/usr/bin/env python3
"""Original486ea0 beep admission/timer branch; stop at selected literal."""
import json
import math
import struct
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, OBJECT, SCRATCH, STACK
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_FPCW

p = NativeProbe(SOURCE)
sample = None

def hook(uc, address, size, data):
    global sample
    if address in [0x487464, 0x48751d, 0x4875fe, 0x4876fb]:
        sample = {0x487464: 'ARMBEEP3', 0x48751d: 'ARMBEEP2', 0x4875fe: 'ARMBEEP1'}.get(address)
        uc.emu_stop()
    elif address in [0x4371f0, 0x437ea0]:
        sp = uc.reg_read(UC_X86_REG_ESP)
        uc.reg_write(UC_X86_REG_EAX, 0)
        uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
        uc.reg_write(UC_X86_REG_ESP, sp + 4)

p.uc.hook_add(UC_HOOK_CODE, hook)
p.u32(0x53be28, 0)
rows = []
for precision in [24, 53]:
    p.uc.reg_write(UC_X86_REG_FPCW, 0x7f if precision == 24 else 0x27f)
    for player in [False, True]:
        for timer in [0, .025, .075, .1, .10000001, .35]:
            for delta in [.001, .025, .033333333, .1, .25]:
                for ratio in [0, .39999999, .4, .40000004, .6999999, .7, .7000001, 1.1, float('nan'), float('inf')]:
                    p.f32(OBJECT + 0x780, timer)
                    p.f32(SCRATCH + 0x1000, delta)
                    p.uc.reg_write(UC_X86_REG_EBP, OBJECT)
                    p.uc.reg_write(UC_X86_REG_EAX, 0 if player else 1)
                    p.f32(STACK + 0xf014, ratio)
                    p.run(0x4873f8)
                    rows.append({'input': {'timer': struct.unpack('<f', struct.pack('<f', timer))[0],
                                           'deltaSeconds': p.float(SCRATCH + 0x1000),
                                           'ratio': 'NaN' if math.isnan(ratio) else 'Infinity' if math.isinf(ratio) else p.float(STACK + 0xf014),
                                           'player': player, 'precision': precision},
                                 'expected': {'timer': p.float(OBJECT + 0x780), 'sample': sample}})

(ROOT / 'evidence/native/arm-audio-fixtures.json').write_text(json.dumps({
    'sourceSha256': p.sha,
    'scope': 'Original4873f8 admission, floating-point timer and threshold instructions. Stops at selected ARMBEEP literal before CString allocation.',
    'rows': rows,
}, indent=2) + '\n')
print('Wrote', len(rows), 'original rubber-arm beep cases')
