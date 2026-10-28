#!/usr/bin/env python3
"""Execute shipped HUD INI filler, String scale setter and hierarchy transform.

Original instructions from rcskspel.dat build every recorded value:
  HUD root   4606c0 up to 46081c: root context at HUD+0x18 and the "Screen"
             element (4585e0); traversal 4614d0 -> 458550 passes HUD+0x18.
  Composite  4585e0 constructor, 45c4d0 position/alignment (45cd10 size),
             45cc00 Scale -> vtable+0x24 (458420), vtable+0x30 (4589c0).
  String     4585e0 + concrete vtable (45a000 FIXED / 462b40 PROPORTIONAL),
             45caa0 position, 45cc00 Scale -> vtable+0x24 (463c90),
             optional runtime SetScale (vtable+0x24), vtable+0x30 (463bb0).
INI XYZ values are parsed by the original 45d470 -> 45d560 (4b1f60 tokens,
463f20 sscanf "%f"). Only the OS/CRT boundary is replaced:
GetPrivateProfileStringA (wrapper 4b1f10, IAT 4d2160) reads the shipped
overlay.ini, operator new (4be7ee) is a bump allocator and the free wrapper
(4bc150) is a no-op.
"""
import json, struct
from pathlib import Path
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, SCRATCH, STACK

ROOT = Path(__file__).resolve().parents[1]
HEAP, HEAP_SIZE = 0x22000000, 0x100000
# 461b50 type 0 -> 45a000 stores 4d28c8 (45a01e; slot 0x44 fixed layout 45a6b0),
# type 1 -> 462b40 stores 4d2b98 (462b5e; slot 0x44 proportional 462d20).
STRING_VTABLES = {'fixed': 0x4d28c8, 'proportional': 0x4d2b98}


def private_profile(path):
    """GetPrivateProfileStringA view: case-insensitive names, first section/key, trimmed."""
    sections, current = {}, None
    for raw in path.read_bytes().decode('latin-1').splitlines():
        line = raw.strip()
        if line.startswith('[') and ']' in line:
            name = line[1:line.index(']')].strip().lower()
            current = sections.setdefault(name, {}) if name not in sections else {}
        elif current is not None and '=' in line and not line.startswith(';'):
            key, value = line.split('=', 1)
            current.setdefault(key.strip().lower(), value.strip())
    return sections


INI = private_profile(SOURCE/'overlay.ini')
rows = []
for precision in [24, 53]:
    p = NativeProbe(SOURCE)
    uc = p.uc
    uc.mem_map(0, 4096)  # FS:[0] SEH chain used by the original prologues.
    uc.mem_map(HEAP, HEAP_SIZE)
    uc.reg_write(UC_X86_REG_FPCW, 0x007f if precision == 24 else 0x027f)
    heap = [HEAP]

    def alloc(size):
        address = heap[0]
        heap[0] = (address + max(size, 1) + 15) & ~15
        assert heap[0] <= HEAP + HEAP_SIZE
        return address

    def arg(index):
        return p.integer(uc.reg_read(UC_X86_REG_ESP) + 4*index)

    def cstring(address):
        data = bytes(uc.mem_read(address, 256))
        return data[:data.index(0)].decode('latin-1')

    def get_private_profile_string(uc, address, size, _):
        # 4b1f10(section, key, buffer, size): lpDefault 5437b0 is the empty string.
        value = INI.get(cstring(arg(1)).lower(), {}).get(cstring(arg(2)).lower(), '')
        value = value.encode('latin-1')[:arg(4) - 1]
        uc.mem_write(arg(3), value + b'\0')
        uc.reg_write(UC_X86_REG_EAX, len(value))

    for address in [0x4b1f10, 0x4be7ee, 0x4bc150]:
        uc.mem_write(address, b'\xc3')
    uc.hook_add(UC_HOOK_CODE, get_private_profile_string, begin=0x4b1f10, end=0x4b1f10)
    uc.hook_add(UC_HOOK_CODE, lambda uc, *_: uc.reg_write(UC_X86_REG_EAX, alloc(arg(1))),
                begin=0x4be7ee, end=0x4be7ee)

    def run(address, this, args=()):
        uc.reg_write(UC_X86_REG_ECX, this)
        p.run(address, args)
        assert uc.reg_read(UC_X86_REG_EIP) == SCRATCH, hex(address)

    def floats(address, count):
        return list(struct.unpack(f'<{count}f', uc.mem_read(address, 4*count)))

    def virtual(obj, slot):
        return p.integer(p.integer(obj) + slot)

    def element(name, size, vtable=None):
        text = alloc(len(name) + 1)
        uc.mem_write(text, name.encode('latin-1') + b'\0')
        string, obj = alloc(16), alloc(size)
        run(0x40b540, string, [text, len(name)])  # std::string assign
        run(0x4585e0, obj, [string])              # HUD element constructor
        if vtable:
            p.u32(obj, vtable)
        return obj

    # CRT startup _cinit 4c022f -> _fpmath 4be597 first runs _cfltcvt_init 4be5af,
    # which installs the sscanf "%f" converters (otherwise _fptrap 4c9597).
    # 4be597's later _setdefaultprecision 4c17bc is not run: FPCW is explicit.
    run(0x4be5af, 0)
    # 45b2e0 (45b41c..45b42a) fixes the IniFiller authored extent at 640x480x1000.
    parser = alloc(0x30)
    for offset, value in [(0x18, 640), (0x1c, 480), (0x20, 1000)]:
        p.f32(parser + offset, value)
    # HUD init: root context from 4f3924/4f3920 and the shipped 640x480 display
    # integers 4fe930/4fe934, then the root "Screen" element stored at HUD+4.
    hud = alloc(0x100)
    uc.reg_write(UC_X86_REG_ECX, hud)
    uc.reg_write(UC_X86_REG_ESP, STACK + 0xf000)
    uc.emu_start(0x4606c0, 0x46081c, count=100000)
    assert uc.reg_read(UC_X86_REG_EIP) == 0x46081c
    screen = p.integer(hud + 4)
    run(virtual(screen, 0x30), screen, [hud + 0x18])
    contexts = {'screen': screen + 0x44}

    def parent_context(name):
        if name.lower() not in contexts:
            # 45b520 -> 460ba0 (new 0x84, 4585e0), 45c4d0, 45bf10 -> 45cc00.
            composite = element(name, 0x84)
            run(0x45c4d0, parser, [composite])
            run(0x45cc00, parser, [composite])
            parent = parent_context(INI[name.lower()]['parent'])
            run(virtual(composite, 0x30), composite, [parent])
            contexts[name.lower()] = composite + 0x44
        return contexts[name.lower()]

    for index in range(int(INI['strings']['count'])):
        name = INI['strings'][str(index)]
        section = INI[name.lower()]
        for override in [None, [.8, 1.2, 1]]:
            parent = parent_context(section['parent'])
            # 45e7a0: 461b50 (new 0xac, 463750 -> 4585e0), 45caa0, 45bf10 -> 45cc00.
            string = element(name, 0xac, STRING_VTABLES[section['type'].lower()])
            run(0x45caa0, parser, [string])
            run(0x45cc00, parser, [string])
            if override:
                scale = alloc(12)
                uc.mem_write(scale, struct.pack('<3f', *override))
                run(virtual(string, 0x24), string, [scale])
            run(virtual(string, 0x30), string, [parent])
            rows.append({'precision': precision, 'id': name.lower(), 'override': override,
                         'position': floats(string + 4, 3), 'parent': floats(parent, 12),
                         'scale': floats(string + 0x10, 3), 'context': floats(string + 0x44, 12)})

(ROOT/'evidence/native/hud-string-transform-fixtures.json').write_text(json.dumps({
    'sourceSHA256': p.sha,
    'functions': ['4be5af', '4606c0', '4585e0', '45c4d0', '45cd10', '45caa0', '45cc00', '45d470', '45d560',
                  '464150', '463c90', '458420', '4589c0', '463bb0'],
    'scope': 'Original HUD root init, element constructor, INI position/alignment/size/scale '
             'readers, String SetScale and hierarchy transforms. GetPrivateProfileStringA reads '
             'the shipped overlay.ini; operator new/free use a bump allocator; String-specific '
             'constructor fields (463750) are not built, only its concrete vtable is installed. '
             'Rotation is not authored and keeps the 458230 constructor zero.',
    'rows': rows}, indent=2) + '\n')
print(f'Captured {len(rows)} original string hierarchy transforms.')
