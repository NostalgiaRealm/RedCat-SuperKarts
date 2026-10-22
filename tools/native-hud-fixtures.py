#!/usr/bin/env python3
"""Execute original fixed/proportional HUD layout instructions with source fonts."""
import json
import struct
from pathlib import Path
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH, OBJECT
from unicorn.x86_const import UC_X86_REG_ECX

ROOT = Path(__file__).resolve().parents[1]
p = NativeProbe(SOURCE)
p.uc.mem_map(0, 4096)
font, vector, glyphs = SCRATCH + 0x5000, SCRATCH + 0x6000, SCRATCH + 0x7000
string, text_buffer = SCRATCH + 0x9000, SCRATCH + 0x9100
# Assertions and temporary diagnostic strings only. Layout arithmetic, loops,
# alignment, fixed-string truncation and padding are original machine code.
patches = {
    0x40b4f0: bytes.fromhex('c7410400000000c7410800000000c7410c00000000c20400'),
    0x40b540: bytes.fromhex('c20800'),
    0x40b600: bytes.fromhex('31c0c20800'),
    0x464530: bytes.fromhex('c3'),
    0x45aab0: bytes.fromhex('b801000000c20400'),
    0x412870: bytes.fromhex('c20c00'),
    # Font lookup wrappers: skip logging/range assertions; retain table reads.
    0x45ac50: bytes.fromhex('0fb64424048b04c1c20400'),
    0x45ad40: bytes.fromhex('0fb6442404d944c104c20400'),
    # Capture original selected glyph IDs without a Direct3D renderer table.
    0x459990: bytes.fromhex('8b442404894150c20400'),
}
for address, code in patches.items():
    p.uc.mem_write(address, code)
p.u32(OBJECT + 0x8c, font)
p.u32(OBJECT + 0x88, vector)
p.u32(vector + 4, vector + 0x100)
for i in range(30):
    p.u32(vector + 0x100 + i * 4, glyphs + 0x80 * i)

count = p.integer(0x4f2cac)
mapping = {}
for i in range(count):
    pointer = p.integer(0x4d2a00 + i * 8)
    name = bytes(p.uc.mem_read(pointer, 32)).split(b'\0')[0].decode('ascii')
    mapping[name.lower()] = p.integer(0x4d2a04 + i * 8)
config = json.loads((ROOT / 'public/assets/config.json').read_text())['overlay.ini']
font_tables, layouts = {}, []
for font_name in ['alpha', 'numeric']:
    section, table = config[font_name], {}
    for name, char in mapping.items():
        if name in section:
            table[char] = list(map(int, section[name].split(';')[1:]))
    for code, value in config.get(font_name + '_ascii', {}).items():
        table[int(code)] = list(map(int, value.split(';')[1:]))
    for code in range(65, 91):
        if code in table:
            table.setdefault(code + 32, table[code])
    font_tables[font_name] = table
    for code in range(256):
        p.u32(font + code * 8, code if code in table else 0xffffffff)
        p.f32(font + code * 8 + 4, table.get(code, [0, 0, 0])[2])
    max_width = max(value[2] for value in table.values())
    p.f32(font + 0x800, float(section['distance']))
    p.f32(font + 0x804, max_width)
    samples = ['Ronde', 'Snelste ronde', 'BONUS', '0', '1', '14', '/5', '01:23:45', '--:--:--', '']
    for string_type in ['fixed', 'proportional']:
        for alignment in range(3):
            for length in [2, 8, 13]:
                for text in samples:
                    if font_name == 'numeric' and any(ord(c) not in table for c in text):
                        continue
                    cell_width = struct.unpack('<f', struct.pack('<f', 2 * max_width / 640))[0]
                    p.u32(OBJECT + 0x98, length)
                    p.u32(OBJECT + 0x90, alignment)
                    p.f32(OBJECT + 0x94, cell_width)
                    p.uc.mem_write(text_buffer, text.encode('latin1') + b'\0')
                    p.u32(string + 4, text_buffer)
                    p.u32(string + 8, len(text))
                    p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
                    if string_type == 'fixed':
                        p.run(0x45a030, [string])
                        p.uc.reg_write(UC_X86_REG_ECX, OBJECT)
                        p.run(0x45a6b0)
                        actual_count = length
                    else:
                        actual_count = min(length, len(text))
                        p.u32(string + 8, actual_count)
                        ratio = struct.unpack('<f', struct.pack('<f', cell_width / max_width))[0]
                        p.run([0x4631d0, 0x4632c0, 0x463400][alignment], [string, ratio])
                    layouts.append({'font': font_name, 'type': string_type,
                                    'alignment': ['left', 'center', 'right'][alignment],
                                    'length': length, 'cellWidth': cell_width, 'text': text,
                                    'glyphs': [{'character': chr(p.integer(glyphs + 0x80 * i + 0x50)),
                                                'center': p.float(glyphs + 0x80 * i + 4)}
                                               for i in range(actual_count)]})

times = []
for value in [-2147483648, -60001, -1000, -10, -1, 0, 1, 9, 10, 99, 999, 1000,
              59999, 60000, 60001, 3599999, 3600000, 59999999, 2147483647]:
    p.run(0x46f700, [value & 0xffffffff, string, string + 4, string + 8])
    parts = [struct.unpack('<i', p.uc.mem_read(string + i * 4, 4))[0] for i in range(3)]
    times.append({'milliseconds': value, 'parts': parts, 'formatted': ('%02d:%02d:%02d' % tuple(parts))[:11]})

output = {
    'sourceSHA256': p.sha, 'method': 'Unchanged original x86 layout and integer time arithmetic in Unicorn',
    'functions': ['0045a030', '0045a6b0', '004631d0', '004632c0', '00463400', '0046f700'],
    'patchedDependencies': ['temporary diagnostic strings and assertions', 'font table lookup wrappers',
                            'glyph assignment captures ID without renderer', 'string changed comparison and final copy'],
    'fontCharacterTableAddress': '004d2a00', 'fontCharacterMap': mapping,
    'formatLiterals': {hex(address): bytes(p.uc.mem_read(address, 32)).split(b'\0')[0].decode()
                      for address in [0x4f6074, 0x4f6084, 0x4f5ec8]},
    'layouts': layouts, 'times': times,
}
(ROOT / 'evidence/native/hud-text-fixtures.json').write_text(json.dumps(output, indent=2) + '\n')
print(f'{len(layouts)} native layouts; {len(times)} native time division cases; {count} original character mappings')
