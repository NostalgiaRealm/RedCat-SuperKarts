#!/usr/bin/env python3
"""Original race phase/gate code; replace OS time/key inputs and presentation calls."""
import json, random, struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH, STACK

p = NativeProbe(SOURCE)
image = pefile.PE(str(SOURCE / 'rcskspel.dat'))
imports = {item.name: item.address for group in image.DIRECTORY_ENTRY_IMPORT for item in group.imports}
p.u32(imports[b'GetTickCount'], SCRATCH + 0xb000)
p.uc.mem_write(SCRATCH + 0xb000, b'\xa1' + struct.pack('<I', SCRATCH + 0xb100) + b'\xc3')
# Preserve original 0x4b3830, including its Shift filtering.
p.u32(imports[b'GetAsyncKeyState'], SCRATCH + 0xb010)
p.uc.mem_write(SCRATCH + 0xb010, b'\x8b\x4c\x24\x04\x0f\xb7\x04\x4d' + struct.pack('<I', SCRATCH + 0xc000) + b'\xc2\x04\x00')
for address in [0x498ad0, 0x420490, 0x423230, 0x430610, 0x473d40]:
    p.uc.mem_write(address, b'\xc3')
p.uc.mem_write(0x498ad0, b'\xc2\x0c\x00') # thiscall Vec3 by value
p.u32(0x6a5cd0, SCRATCH + 0xd000)
p.u32(0x6a5c88, SCRATCH + 0xd000)
p.u32(0x53be30, 0)
p.u32(0x53b9f0, 0)
p.u32(0x508af0, 0)
p.u32(0x508aec, 0)
captured = []
def hook(uc, address, size, _):
    if address not in [0x420ba0, 0x42f980]: return
    sp = uc.reg_read(UC_X86_REG_ESP)
    captured.append([address] + ([p.integer(sp + n) for n in [4,8,12,16]] if address == 0x420ba0 else []))
    uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    uc.reg_write(UC_X86_REG_ESP, sp + 4)
p.uc.hook_add(UC_HOOK_CODE, hook)
out = {'sourceSha256': p.sha, 'resultTraces': [], 'phaseTransitions': [], 'quitKeys': []}
def keys(values):
    p.uc.mem_write(SCRATCH + 0xc000, bytes(512))
    for code in values: p.uc.mem_write(SCRATCH + 0xc000 + code * 2, b'\x00\x80')
def start(address):
    p.u32(STACK + 0xf000, SCRATCH)
    p.uc.reg_write(UC_X86_REG_ESP, STACK + 0xf000)
    p.uc.reg_write(UC_X86_REG_EIP, address)
def advance():
    p.uc.emu_start(p.uc.reg_read(UC_X86_REG_EIP), SCRATCH, count=1000)
    returned = p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    return {'returned': returned, 'done': returned and bool(p.uc.reg_read(UC_X86_REG_EAX))}
for phase in [3,6]:
    epoch_address = 0x4e3a80 if phase == 3 else 0x4e3b14
    entry = 0x41fd90 if phase == 3 else 0x420850
    sequences = [
        [(0,[]),(999,[]),(1000,[]),(1499,[]),(1500,[]),(8000,[]),(8001,[])],
        [(0,[]),(999,[13]),(1000,[13]),(1499,[13]),(1500,[13]),(9000,[13]),(9001,[])],
        [(0,[]),(1500,[27]),(1600,[32]),(1700,[])],
        [(0,[]),(1500,[16,13]),(1600,[]),(2000,[32]),(2001,[])],
    ]
    for hardware,initial in [(h,t) for h in [False,True] for t in [0,12345,0xfffffc00]]:
        for sequence in sequences:
            p.u32(epoch_address, 0xffffffff)
            p.u32(0x53b9f0,int(hardware));p.u32(0x5086a4,0)
            trace = []; blocked = False
            for offset, pressed in sequence:
                now = (initial + offset) & 0xffffffff
                keys(pressed);p.u32(SCRATCH + 0xb100, now)
                if not blocked: start(entry)
                result = advance();blocked = not result['returned']
                trace.append({'nowMs':now,'keys':pressed,'epoch':p.integer(epoch_address),
                    'finishFlagRequested':bool(p.integer(0x5086a4)),**result})
                if result['done']: break
            out['resultTraces'].append({'phase':phase,'hardware':hardware,'trace':trace})
rng = random.Random(0x42f740)
flags = {'phase':0x53b9c0, 'movementActive':0x53b9e0, 'playerActive':0x53be54,
    'running':0x53b9bc,'presentation':0x53b9e4,'raceCompleted':0x53be50}
for index in range(240):
    before = {key:rng.randrange(2) for key in flags}
    before['phase'] = rng.choice([0,1,2,3,4,6,8])
    for key,address in flags.items():p.u32(address,before[key])
    target = rng.choice([0,1,2,3,4,6,8]);captured.clear()
    finish = rng.choice([None,None,0x41fe50,0x420950])
    if finish is not None: p.run(finish);target=4
    else: p.run(0x42f740,[target])
    out['phaseTransitions'].append({'before':before,'target':target,'finish':finish,
        'expected':{key:p.integer(address) for key,address in flags.items()},'calls':list(captured)})
# 0x474040 keyboard branches return before mouse polling. Emulate the native
# key-release loop, then continue after releasing every held key.
for pressed in [[74],[78],[27],[74,78],[74,27],[78,27]]:
    keys(pressed);start(0x474040);first=advance()
    keys([]);last=advance()
    out['quitKeys'].append({'keys':pressed,'blocked':not first['returned'],
        'code':p.uc.reg_read(UC_X86_REG_EAX),'returned':last['returned']})
(ROOT/'evidence/native/race-lifecycle-fixtures.json').write_text(json.dumps(out,indent=2)+'\n')
print('Wrote',len(out['resultTraces']),'native result traces,',len(out['phaseTransitions']),'phase transitions and',len(out['quitKeys']),'requester key loops')
