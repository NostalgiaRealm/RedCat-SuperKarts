#!/usr/bin/env python3
"""Execute original squash activation, timer, matrix and rebound instructions."""
import json
import struct
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, OBJECT
from native_probe_math import initialize_native_trig


def main():
    config=json.loads((ROOT/'public/assets/config.json').read_text())
    settings=config['sndgfx.ini']['special_effects']
    traces=[]
    for precision,cw in [(24,0x7f),(53,0x27f)]:
        for delta in [.025,.09,.1]:
            for start in [1000,0xfffff800]:
                p=NativeProbe(SOURCE);p.uc.reg_write(UC_X86_REG_FPCW,cw)
                initialize_native_trig(p)
                p.u32(0x4fc6e8,0) # Active 42ccf0 -> 49f540(0), Z-X-Y.
                manager=SCRATCH+0x6000
                for address in [0x4afce0,0x4afcc0]:p.uc.mem_write(address,b'\xc3')
                now=SCRATCH+0x1100;clock=SCRATCH+0x7100
                p.uc.mem_write(clock,b'\xa1'+struct.pack('<I',now)+b'\xc3')
                p.u32(0x4d215c,clock)
                for address,key in [(0x53ba7c,'squash_speed_limit'),(0x53ba80,'squash_shake_strength')]:
                    p.f32(address,int(settings[key]))
                p.f32(0x53ba84,int(settings['squash_ratio'])*.1)
                p.u32(0x53ba88,int(settings['squash_time']))
                p.f32(SCRATCH+0x1000,delta)
                p.u32(0x53be28,0);p.u32(0x508610,2)
                p.u32(0x5081bc,1);p.u32(0x5081bc+0x70,2)
                for body in range(4):
                    p.u32(OBJECT+body*0xd0+0xc,body)
                    render=SCRATCH+0x4000+body*0xa9
                    for offset,value in [(0x74,23.25),(0x78,-527.5),(0x7c,11.75),
                        (0x80,1),(0x84,1),(0x88,1)]:
                        p.f32(render+offset,value)
                def run(address,args=(),this=manager):
                    p.uc.reg_write(UC_X86_REG_ECX,this);p.run(address,args)
                    assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH,hex(p.uc.reg_read(UC_X86_REG_EIP))
                run(0x48e480)
                # A native type44 registration follows the player/NPC records.
                run(0x48e560,[0,3,1200])
                def snapshot():
                    rows=[]
                    for body in range(4):
                        rec=manager+body*0x1c;render=SCRATCH+0x4000+body*0xa9
                        rows.append({'active':bool(p.uc.mem_read(rec+0x11,1)[0]),
                            'shake':bool(p.uc.mem_read(rec+0x10,1)[0]),
                            'reboundFrame':p.integer(rec+8),'shakeFrame':p.integer(rec+12),
                            'startedMs':p.integer(rec+24),'forwardSpeed':p.float(OBJECT+body*0xd0+0xa4),
                            'matrix':[p.float(render+0x10+row*16+col*4)for row in range(3)for col in range(3)]})
                    return rows
                frames=[]
                for tick in range(60):
                    tick_ms=(start+tick*100)&0xffffffff;p.u32(now,tick_ms)
                    inputs=[]
                    for body in range(4):
                        render=SCRATCH+0x4000+body*0xa9
                        run(0x4a09e0,this=render)
                        speed=[25,-30,12,21][body]+tick*.125
                        p.f32(OBJECT+body*0xd0+0xa4,speed)
                        inputs.append({'matrix':snapshot()[body]['matrix'],'forwardSpeed':p.float(OBJECT+body*0xd0+0xa4)})
                    # Repeat requests must neither restart timers nor re-flatten.
                    requests=[0,1,2]if tick==0 else [3]if tick==22 else [0,3]if tick==25 else []
                    for body in requests:run(0x48e780,[body])
                    after_trigger=snapshot()
                    run(0x48e970)
                    frames.append({'nowMs':tick_ms,'input':inputs,'requests':requests,
                        'afterTrigger':after_trigger,'expected':snapshot()})
                traces.append({'precision':precision,'delta':p.float(SCRATCH+0x1000),
                    'startMs':start,'frames':frames})
    output={'format':'superkarts-native-squash-v1','sha256':p.sha,'angles':[23.25,-527.5,11.75],
        'traces':traces}
    (ROOT/'evidence/native/squash-fixtures.json').write_text(json.dumps(output,separators=(',',':'))+'\n')
    print(f'Wrote {sum(len(t["frames"])for t in traces)} original squash timer/matrix/rebound frames')


if __name__=='__main__':main()
