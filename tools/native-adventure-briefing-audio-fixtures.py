#!/usr/bin/env python3
"""Execute the original Adventure briefing sample lookup and accept ordering.

The selection probe enters the intact suffix 4784b5 of phase initializer
4783b8 and stops at generic sample wrapper45c720. Its input bytes are the
selected country, race type and difficulty in the native form. The complete
initializer has no FIRSTTIME or difficulty branch around this suffix.

The accept probe runs4786a4 through the actual sound-stop wrapper45c7c0 and
the settings predicate45bb50. Only sndPlaySoundA, race setup, optional start
information and form close are explicit boundaries. No original GUI, sound
device, race, settings file or executable is run or modified.
"""
import configparser
import hashlib
import json

import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX,
                               UC_X86_REG_ESP, UC_X86_REG_EIP)
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH


p = NativeProbe(SOURCE)
binary = SOURCE / 'rcskmenu.dat'
pe = pefile.PE(str(binary))
p.uc.mem_write(0x400000, pe.get_memory_mapped_image())
p.uc.mem_map(0, 0x1000)
app, form, settings = [SCRATCH + x for x in [0x1000, 0x3000, 0x6000]]
p.u32(p.integer(0x47c670), app)
p.u32(app + 0x7c, settings)
events = []


def ret(stack_bytes=0):
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4 + stack_bytes)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))


def hook(uc, address, size, unused):
    if address == 0x45c720:
        events.append({'operation': 'genericSound',
                       'sample': uc.reg_read(UC_X86_REG_EAX) & 255,
                       'wait': False})
        uc.emu_stop()
    elif address == 0x455920:
        sp = uc.reg_read(UC_X86_REG_ESP)
        events.append({'operation': 'sndPlaySoundA',
                       'soundPointer': p.integer(sp + 4),
                       'flags': p.integer(sp + 8)})
        ret(8)
    elif address in [0x4786ec, 0x46222c, 0x42eb18]:
        events.append({'operation': {0x4786ec: 'raceSetup',
                                     0x46222c: 'startInfo',
                                     0x42eb18: 'closeForm'}[address]})
        ret()


p.uc.hook_add(UC_HOOK_CODE, hook)
soundset = configparser.ConfigParser(interpolation=None, comment_prefixes=(';', '#', '//'))
soundset.read(SOURCE / 'ini/soundset.dat')
report = {
    'sourceSha256': hashlib.sha256(binary.read_bytes()).hexdigest(),
    'scope': __doc__,
    'selectionEntry': '0x4784b5',
    'selectionEnd': '0x45c720',
    'initializer': '0x4783b8',
    'byteTableAddress': '0x47c5a4',
    'byteTable': list(p.uc.mem_read(0x47c5a4, 30)),
    'selection': [],
    'accept': [],
    'limits': [
        'Instruction emulation with explicit boundaries, not live Windows listening.',
        'The shipped fifth type aliases normalrace; public Adventure uses types0..3.',
        'Repeated entry follows the same unconditional suffix; no first-visit flag is read there.',
        'Difficulty modifies text via brief.dat but not the sample lookup.'
    ]
}
for country in range(6):
    for race_type in range(4):
        for difficulty in range(3):
            events = []
            p.uc.mem_write(form + 0x390, bytes([country, race_type, difficulty]))
            p.uc.reg_write(UC_X86_REG_EBX, form)
            p.run(0x4784b5)
            assert len(events) == 1
            event = events[0]
            assert event['sample'] == 56 + country * 4 + race_type
            report['selection'].append({
                'country': country, 'raceType': race_type, 'difficulty': difficulty,
                'sampleFile': soundset['GENERIC_SAMPLES'][str(event['sample'])],
                'expected': event
            })
for show_start_info in [False, True]:
    for settings_mode in [False, True]:
        events = []
        p.uc.mem_write(settings + 0x18, bytes([show_start_info]))
        p.uc.mem_write(settings + 4, bytes([settings_mode]))
        p.uc.reg_write(UC_X86_REG_EAX, form)
        p.run(0x4786a4)
        assert events[0] == {'operation': 'sndPlaySoundA', 'soundPointer': 0, 'flags': 0}
        expected = ['sndPlaySoundA', 'raceSetup']
        if show_start_info and not settings_mode:
            expected.append('startInfo')
        expected.append('closeForm')
        assert [event['operation'] for event in events] == expected
        report['accept'].append({'showStartInfo': show_start_info,
                                 'settingsModeByte': settings_mode,
                                 'events': events,
                                 'closeResult': p.uc.mem_read(form + 0x2d4, 1)[0]})
        assert report['accept'][-1]['closeResult'] == 4

destination = ROOT / 'evidence/native/adventure-briefing-audio-fixtures.json'
destination.write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps({'selection': len(report['selection']),
                  'accept': len(report['accept']),
                  'sourceSha256': report['sourceSha256']}))
