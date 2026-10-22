#!/usr/bin/env python3
"""Original shell sound selection before sndPlaySound.

Runs the original handlers up to their sound wrapper. No sound-device call,
window callback or original file is changed.
"""
import hashlib
import json
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH

p = NativeProbe(SOURCE)
binary = SOURCE / 'rcskmenu.dat'
pe = pefile.PE(str(binary))
p.uc.mem_write(0x400000, pe.get_memory_mapped_image())
p.uc.mem_map(0, 0x1000)
app, profile, form = SCRATCH + 0x1000, SCRATCH + 0x2000, SCRATCH + 0x3000
p.u32(p.integer(0x47c670), app)
p.u32(app + 0x80, profile)
captured = None
binding = None

def return_from(value=None):
    if value is not None:
        p.uc.reg_write(UC_X86_REG_EAX, value)
    sp = p.uc.reg_read(UC_X86_REG_ESP)
    p.uc.reg_write(UC_X86_REG_ESP, sp + 4)
    p.uc.reg_write(UC_X86_REG_EIP, p.integer(sp))

def hook(uc, address, size, unused):
    global captured
    if binding is not None:
        if address == 0x45c720:
            binding['samples'].append(uc.reg_read(UC_X86_REG_EAX) & 255)
            return_from()
        elif address == 0x458eb4:
            return_from(0)  # Isolated key classification, no duplicate binding.
        elif address == 0x458ea4:
            binding['accepted'] = True
            return_from()
        elif address in [0x461b44, 0x461d74, 0x4620ec, 0x403b74]:
            return_from()
        return
    if address in [0x45c720, 0x45c668, 0x45c5cc]:
        eax, edx = uc.reg_read(UC_X86_REG_EAX) & 255, uc.reg_read(UC_X86_REG_EDX) & 255
        captured = ({'bank': 'character', 'character': eax, 'sample': edx, 'wait': False}
                    if address == 0x45c5cc else
                    {'bank': 'generic', 'sample': eax, 'wait': address == 0x45c668 and bool(edx)})
        uc.emu_stop()
p.uc.hook_add(UC_HOOK_CODE, hook)

def probe(address):
    global captured
    captured = None
    p.uc.reg_write(UC_X86_REG_EAX, form)
    p.uc.reg_write(UC_X86_REG_EDX, 0)
    p.uc.reg_write(UC_X86_REG_ECX, 0)
    p.run(address)
    return captured

out = {'sourceSha256': hashlib.sha256(binary.read_bytes()).hexdigest(),
       'scope': __doc__, 'navigation': [], 'modes': [], 'countryInfo': [], 'bindingKeys': []}
for screen, offset, maximum, forward, back in [
        ('characters', 0x338, 3, 0x474234, 0x474268),
        ('countries', 0x338, 5, 0x46fd98, 0x46fdc4),
        ('highscores', 0x384, 5, 0x477284, 0x4772b0)]:
    for index in range(maximum + 1):
        for direction, address in [(1, forward), (-1, back)]:
            p.uc.mem_write(form + offset, bytes([index]))
            out['navigation'].append({'screen': screen, 'index': index, 'maximum': maximum,
                                      'direction': direction, 'expected': probe(address)})
for character in range(4):
    p.uc.mem_write(profile + 0x22, bytes([character]))
    for mode, address in enumerate([0x46fefc, 0x46ff20, 0x46ff44]):
        out['modes'].append({'character': character, 'mode': mode, 'expected': probe(address)})
for country in range(6):
    p.uc.mem_write(form + 0x32c, bytes([country]))
    for photo, address in [(None, 0x477d80), (0, 0x477d30), (1, 0x477d44),
                           (2, 0x477d58), (3, 0x477d6c)]:
        out['countryInfo'].append({'country': country, 'photo': photo, 'expected': probe(address)})
for key in range(256):
    binding = {'samples': [], 'accepted': False}
    p.uc.mem_write(form + 0x354, b'\1')
    p.uc.mem_write(form + 0x34e, b'\1')
    p.uc.mem_write(SCRATCH + 0x4000, key.to_bytes(2, 'little'))
    p.uc.reg_write(UC_X86_REG_EAX, form)
    p.uc.reg_write(UC_X86_REG_ECX, SCRATCH + 0x4000)
    p.run(0x461958)
    decision = 'accept' if binding['accepted'] else 'reject' if 110 in binding['samples'] else 'cancel'
    out['bindingKeys'].append({'keyCode': key, 'expected': decision, 'samples': binding['samples']})
binding = None
path = ROOT / 'evidence/native/menu-audio-fixtures.json'
path.write_text(json.dumps(out, indent=2) + '\n')
print(json.dumps({key: len(out[key]) for key in ['navigation', 'modes', 'countryInfo', 'bindingKeys']}))
