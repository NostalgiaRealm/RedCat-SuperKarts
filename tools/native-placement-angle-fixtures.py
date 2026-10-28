#!/usr/bin/env python3
"""Execute the original OMP loader and placement angle conversion on all six tracks.

rcskspel.dat 0x497070 reads each 68-byte OMP record with fread-shaped
0x4bf930(buf,4,1,file) and copies the raw rotation dwords into 0x43e140
param_4..6. 0x43e140 converts them at 0x43e283..0x43e2ad:
  FLD float [0x4fc8f4]; FMUL float [0x4d2468]      ; 4096 * f32(1/360)
  per axis: FLD ST0; FMUL float [param]; (FCHS on param_5) FSTP float [param]
The 0x497070 loop runs unmodified. Only fopen/fread/fclose/log services are
stubbed, and 0x43e140 is entered at 0x43e283 with its original frame depth
(0x64 below the return address) and left at 0x43e2b4, before world
registration (CALL 0x493210). Both CRT control words are executed.
Instruction emulation, NOT a Wine/full-game observation; original files are
read-only.
"""
import hashlib
import json
import struct

from unicorn import UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_ECX, UC_X86_REG_EIP,
                               UC_X86_REG_ESP, UC_X86_REG_FPCW)
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SCRATCH, SOURCE, STACK

OUTPUT = ROOT / "evidence/native/placement-angle-fixtures.json"
CONTROL_WORDS = [(24, 0x7F), (53, 0x27F)]
THIS = SCRATCH + 0x3000
NAME = SCRATCH + 0x3200
FOPEN, FREAD, FCLOSE = 0x4B96D0, 0x4BF930, 0x4B9840
ENTRY, CONVERT, CONVERTED = 0x43E140, 0x43E283, 0x43E2B4


def omp_file(track):
    name = f"etappe{track}.omp"
    return next(path for path in SOURCE.iterdir() if path.name.lower() == name)


def run_loader(data, control_word):
    probe = NativeProbe(SOURCE)
    uc = probe.uc
    uc.reg_write(UC_X86_REG_FPCW, control_word)
    uc.mem_write(0x4AFCE0, b"\xc3")  # log
    uc.mem_write(0x4AFEE0, b"\xc3")  # fatal error report
    uc.mem_write(NAME, b"etappe.omp\0")
    state = {"cursor": 0, "frame": None, "calls": []}

    def cdecl_return(value):
        sp = uc.reg_read(UC_X86_REG_ESP)
        uc.reg_write(UC_X86_REG_EAX, value)
        uc.reg_write(UC_X86_REG_ESP, sp + 4)
        uc.reg_write(UC_X86_REG_EIP, probe.integer(sp))

    def on_fopen(uc_, address, size, user):
        cdecl_return(1)

    def on_fread(uc_, address, size, user):
        sp = uc.reg_read(UC_X86_REG_ESP)
        buffer, item, count = probe.integer(sp + 4), probe.integer(sp + 8), probe.integer(sp + 12)
        chunk = data[state["cursor"]:state["cursor"] + item * count]
        assert len(chunk) == item * count, "OMP read past end of file"
        uc.mem_write(buffer, chunk)
        state["cursor"] += len(chunk)
        cdecl_return(count)

    def on_fclose(uc_, address, size, user):
        cdecl_return(0)

    def on_entry(uc_, address, size, user):
        frame = uc.reg_read(UC_X86_REG_ESP)
        args = bytes(uc.mem_read(frame + 4, 48))
        state["frame"], state["ebp"] = frame, uc.reg_read(UC_X86_REG_EBP)
        state["calls"].append({"args": args})
        # 0x43e183 loads param_1 into EBP; 0x43e283 is reached at depth 0x64.
        uc.reg_write(UC_X86_REG_EBP, struct.unpack_from("<I", args)[0])
        uc.reg_write(UC_X86_REG_ESP, frame - 0x64)
        uc.reg_write(UC_X86_REG_EIP, CONVERT)

    def on_converted(uc_, address, size, user):
        frame = state["frame"]
        assert uc.reg_read(UC_X86_REG_ESP) == frame - 0x68, "unexpected 0x43e2b4 stack depth"
        # FSTP [ESP+0x78/0x7c/0x80] after PUSH EBP are param_4..6 in place.
        state["calls"][-1]["converted"] = bytes(uc.mem_read(frame + 0x10, 12))
        # 0x43e140 restores its callee-saved EBP before returning (0x43ef74).
        uc.reg_write(UC_X86_REG_EBP, state["ebp"])
        uc.reg_write(UC_X86_REG_ESP, frame + 4)
        uc.reg_write(UC_X86_REG_EIP, probe.integer(frame))

    for address, callback in [(FOPEN, on_fopen), (FREAD, on_fread), (FCLOSE, on_fclose),
                              (ENTRY, on_entry), (CONVERTED, on_converted)]:
        uc.hook_add(UC_HOOK_CODE, callback, begin=address, end=address)
    # Thiscall 0x497070(filename): ECX's [this+0x9a] becomes 0x43e140 param_12.
    sp = STACK + 0xF000
    uc.mem_write(sp, struct.pack("<II", SCRATCH, NAME))
    uc.reg_write(UC_X86_REG_ESP, sp)
    uc.reg_write(UC_X86_REG_ECX, THIS)
    uc.emu_start(0x497070, SCRATCH, count=5_000_000)
    assert state["cursor"] == len(data), "OMP loader left unread bytes"
    return probe.sha, state["calls"]


def main():
    out = {
        "routines": ["0x497070", "0x43e140:0x43e283..0x43e2ad"],
        "method": ("Original x86 OMP loader loop and placement angle conversion; fopen/fread/fclose/log "
                   "stubbed, 0x43e140 entered at 0x43e283 with its original frame and left at 0x43e2b4."),
        "constants": {"0x4fc8f4": "runtime 4096.0 from 0x4a1510(4096)", "0x4d2468": "0x3b360b61 f32(1/360)"},
        "rowFields": ["index", "sector", "type", "degreesRaw", "degrees", "angles24", "angles53"],
        "tracks": [],
    }
    for track in range(6):
        path = omp_file(track)
        data = path.read_bytes()
        count = struct.unpack_from("<I", data)[0]
        assert len(data) == 4 + count * 68, f"{path.name}: OMP size mismatch"
        records = list(struct.iter_unpack("<II6f32sI", data[4:]))
        results = {}
        for precision, control_word in CONTROL_WORDS:
            sha, calls = run_loader(data, control_word)
            out["sourceSha256"] = sha
            assert len(calls) == count, f"{path.name}: {len(calls)} conversions for {count} records"
            results[precision] = calls
        rows = []
        for index in range(count):
            record = data[4 + index * 68:4 + (index + 1) * 68]
            args = results[24][index]["args"]
            assert results[53][index]["args"] == args
            # 0x497070: param_1 type, param_4..6 raw rotation dwords at OMP +20..+31.
            assert args[0:4] == record[4:8] and args[12:24] == record[20:32], f"{path.name}:{index}"
            rows.append([index, records[index][0], records[index][1], record[20:32].hex(),
                         list(struct.unpack("<3f", record[20:32]))]
                        + [list(struct.unpack("<3f", results[precision][index]["converted"]))
                           for precision, _ in CONTROL_WORDS])
        out["tracks"].append({"track": track, "file": path.name,
                              "sha256": hashlib.sha256(data).hexdigest(), "rows": rows})
    body = ",\n".join(
        json.dumps({key: value for key, value in track.items() if key != "rows"})[:-1]
        + ',"rows":[\n' + ",\n".join(json.dumps(row, separators=(",", ":")) for row in track["rows"]) + "]}"
        for track in out["tracks"])
    header = json.dumps({key: value for key, value in out.items() if key != "tracks"}, indent=2)[:-2]
    OUTPUT.write_text(header + ',\n  "tracks": [\n' + body + "\n]\n}\n")
    total = sum(len(track["rows"]) for track in out["tracks"])
    print(f"Wrote {total} placements ({total * 3} angles) x {len(CONTROL_WORDS)} control words to {OUTPUT}")


if __name__ == "__main__":
    main()
