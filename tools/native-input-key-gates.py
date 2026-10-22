#!/usr/bin/env python3
"""Original keyboard/joystick/analog handbrake and mapped-key Shift filtering."""
import json
import struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX
from generate_native_gameplay_fixtures import NativeProbe, SOURCE, ROOT, SCRATCH

p = NativeProbe(SOURCE)
image = pefile.PE(str(SOURCE / "rcskspel.dat"))
imports = {item.name: item.address for lib in image.DIRECTORY_ENTRY_IMPORT for item in lib.imports}
p.u32(imports[b"GetAsyncKeyState"], SCRATCH + 0xb010)
p.uc.mem_write(SCRATCH + 0xb010, b"\x8b\x4c\x24\x04\x0f\xb7\x04\x4d" +
               struct.pack("<I", SCRATCH + 0xc000) + b"\xc2\x04\x00")
mask = 0


def keys(pressed):
    p.uc.mem_write(SCRATCH + 0xc000, bytes(1024))
    for code in pressed:
        p.uc.mem_write(SCRATCH + 0xc000 + code * 2, b"\x00\x80")


def hook(uc, address, _size, _data):
    if address != 0x42ef90:
        return
    sp = uc.reg_read(UC_X86_REG_ESP)
    p.u32(p.integer(sp + 12), 50)
    p.u32(p.integer(sp + 16), 50)
    uc.reg_write(UC_X86_REG_EAX, mask)
    uc.reg_write(UC_X86_REG_EIP, p.integer(sp))
    uc.reg_write(UC_X86_REG_ESP, sp + 4)


p.uc.hook_add(UC_HOOK_CODE, hook)
out = {"sourceSHA256": p.sha, "handbrake": [], "mappedKeys": []}
for device, address in [(1, 0x433870), (2, 0x433cf0), (3, 0x4341d0)]:
    for mask in [0, 32]:
        for space in [False, True]:
            for shift in [False, True]:
                keys(([32] if space else []) + ([16] if shift else []))
                p.input_reset()
                p.u32(SCRATCH + 0x1010, mask)
                p.f32(SCRATCH + 0x1000, .025)
                p.run(address, [0])
                out["handbrake"].append({"device": device, "mapped": bool(mask),
                                        "space": space, "shift": shift,
                                        "expected": bool(p.integer(0x53bdf4))})
for code in [18, 32, 37, 38, 39, 40]:
    for pressed in [[], [code], [16], [16, code]]:
        keys(pressed)
        p.run(0x4b3880, [code, 1])
        out["mappedKeys"].append({"code": code, "pressed": pressed,
                                 "expected": bool(p.uc.reg_read(UC_X86_REG_EAX))})
(ROOT / "evidence/gameplay/native-input-key-gates.json").write_text(json.dumps(out, indent=2) + "\n")
print("Wrote24 original device handbrake and24 original mapped-key Shift cases")
