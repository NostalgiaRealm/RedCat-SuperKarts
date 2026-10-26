#!/usr/bin/env python3
"""Trace original pause/quit flow, bounding timer, input and UI services.

The original 42f350 wrapper and 42f220/42f290 branches execute unchanged.
The DirectShow completion poll is recorded at its entry, not represented as
sound pause. No game process is run and no original file is modified.
"""
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH

p = NativeProbe(SOURCE)
events = []
counts = {}
selection = 0

def ret(uc, value=0):
    sp = uc.reg_read(UC_X86_REG_ESP)
    uc.reg_write(UC_X86_REG_EAX, value)
    uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    uc.reg_write(UC_X86_REG_ESP, sp + 4)

def hook(uc, address, size, unused):
    sp = uc.reg_read(UC_X86_REG_ESP)
    if address == 0x4b3830:
        key = p.integer(sp + 4)
        counts[key] = counts.get(key, 0) + 1
        # Release opening P/Escape; an X press/release resumes the P pause.
        pressed = key in [0x50, 0x1b] and counts[key] == 1
        if key == 0x58:
            pressed = counts[key] == 1
        return ret(uc, int(pressed))
    services = {0x42a2f0:'timer.pause', 0x42a420:'timer.resume',
                0x48ef80:'music.poll-completion', 0x48f520:'frame-clock.reset',
                0x430610:'hud.notify', 0x4707f0:'requester.create',
                0x471740:'requester.available', 0x473780:'requester.run',
                0x42f740:'race.phase'}
    if address in services:
        event = {'call':services[address], 'address':f'{address:08x}'}
        if address in [0x42a2f0, 0x42a420, 0x430610, 0x42f740]:
            event['argument'] = p.integer(sp + 4)
        events.append(event)
        return ret(uc, 1 if address == 0x471740 else selection if address == 0x473780 else 0)

p.uc.hook_add(UC_HOOK_CODE, hook)
traces = []
for name, request, selection in [('pause-resume',1,0),('quit-cancel',2,0),('quit-confirm',2,1)]:
    events.clear();counts.clear()
    p.u32(0x53b9f8, request)
    p.run(0x42f350)
    assert p.uc.reg_read(UC_X86_REG_EIP) == SCRATCH
    assert [event['argument'] for event in events if event['call']=='timer.pause'] == [0,3,8,*range(9,28)]
    assert [event['argument'] for event in events if event['call']=='timer.resume'] == [0,3,8,*range(9,28)]
    traces.append({'name':name,'request':request,'events':list(events)})

result = {'format':'superkarts-native-pause-audio-v1','sourceSHA256':p.sha,
          'functions':['0042f350','0042f220','0042f290'],
          'scope':'Original pause wrapper and P/quit branches; timer APIs, key polling, HUD, requester, phase assignment and one music completion poll are recorded services. This traces dispatch, not sound-card output or Windows playback.',
          'traces':traces}
target = ROOT/'evidence/native/pause-audio-fixtures.json'
target.write_text(json.dumps(result,indent=2)+'\n')
print(f'Captured {len(traces)} original pause/quit call traces: {target}')
