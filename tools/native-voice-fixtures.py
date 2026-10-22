#!/usr/bin/env python3
"""Original436760 queue selection; only spatial sound and STL storage boundaries stubbed."""
import json
import random
import struct
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe,ROOT,SOURCE,SCRATCH,OBJECT


def main():
    p=NativeProbe(SOURCE)
    p.uc.mem_write(0x4afce0,b'\xc3')
    p.uc.mem_write(0x438c10,b'\xc3')
    p.uc.mem_write(0x49dd20,b'\xb8'+struct.pack('<I',SCRATCH+0x5000)+b'\xc2\x04\x00')
    p.uc.mem_write(0x49d870,b'\xc3')
    p.uc.mem_write(0x436980,b'\xc3')
    p.uc.mem_write(0x49da60,b'\xc2\x1c\x00')
    p.u32(OBJECT,SCRATCH+0x3000)
    p.u32(SCRATCH+0x3000,SCRATCH+0x3100)
    p.u32(SCRATCH+0x300c,SCRATCH+0x3120)
    p.uc.mem_write(SCRATCH+0x3100,b'\x8b\x41\x30\xc3')
    p.uc.mem_write(SCRATCH+0x3120,b'\x8b\x41\x10\xc3')
    p.u32(OBJECT+0x3c,SCRATCH+0x6000);p.u32(SCRATCH+0x6004,SCRATCH+0x7000)
    p.u32(OBJECT+0x40,10);p.u32(0x508610,4)
    for index in range(50):p.u32(SCRATCH+0x7010+index*20,100+index)
    selected=None
    playing=False
    played=[]
    def hook(uc,address,size,data):
        nonlocal selected
        sp=uc.reg_read(UC_X86_REG_ESP)
        if address==0x49dd20:selected=p.integer(sp+4)
        elif address==0x49d870:uc.reg_write(UC_X86_REG_EAX,int(playing))
        elif address==0x436980:
            for output in [p.integer(sp+8),p.integer(sp+12)]:uc.mem_write(output,bytes(12))
        elif address==0x49da60:played.append(selected-100)
    p.uc.hook_add(UC_HOOK_CODE,hook)
    rows=[];rng=random.Random(436760)
    for index in range(600):
        current=rng.randrange(-1,50);queue=[rng.randrange(50) for _ in range(index%6)]
        playing=bool(index%2)
        p.u32(OBJECT+0x34,current&0xffffffff);p.u32(OBJECT+0x30,len(queue))
        p.u32(OBJECT+0x10,SCRATCH+0x8000);p.u32(OBJECT+0xc,SCRATCH+0x9000)
        for slot,value in enumerate(queue):p.u32(SCRATCH+0x8000+slot*4,value)
        played=[]
        p.uc.reg_write(UC_X86_REG_ECX,OBJECT);p.run(0x436760)
        assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
        after=struct.unpack('<i',p.uc.mem_read(OBJECT+0x34,4))[0]
        remaining=p.integer(OBJECT+0x30)
        rows.append({'input':{'current':current,'queue':queue,'playing':playing},
                     'current':after,'queue':queue[len(queue)-remaining:],'spatial':played})
    (ROOT/'evidence/native/voice-queue-fixtures.json').write_text(json.dumps({
      'format':'superkarts-native-voice-queue-v1','sha256':p.sha,'rows':rows},indent=2)+'\n')
    print(f'Wrote{len(rows)} original voice queue updates')


if __name__=='__main__':main()
