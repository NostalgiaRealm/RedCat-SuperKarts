#!/usr/bin/env python3
"""Original race-type3 table modifier on each shipped difficulty table."""
import json,struct
from generate_native_gameplay_fixtures import NativeProbe,SOURCE,ROOT
from unicorn.x86_const import UC_X86_REG_FPCW
def main():
    out={'routine':'4350d0','scope':'Original modifier, called by4319f0 only when race type equals3. All20 records captured to verify the first-ten-only bound.',
         'cases':[]}
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        for difficulty in range(3):
            p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw)
            p.uc.mem_write(0x5068d0,(SOURCE/f'cars{difficulty}.dat').read_bytes())
            p.u32(0x53b9f4,difficulty);p.run(0x4350d0)
            out['sourceSha256']=p.sha
            out['cases'].append({'precision':precision,'difficulty':difficulty,
                'expected':[list(struct.unpack('<31f',p.uc.mem_read(0x5068d0+i*124,124))) for i in range(20)]})
    (ROOT/'evidence/native/ai-difficulty-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
    print('Wrote',len(out['cases']),'complete original modified racer tables')
if __name__=='__main__':main()
