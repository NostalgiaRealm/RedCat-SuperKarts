"""Functions the recompiler does not lift from x86 (Maisy's Playhouse).

Each entry maps an address in the merged image to one of:
- 'inline': emits wasm at each call site (compiler helpers with odd conventions)
- 'hook':   calls a JavaScript implementation through a host thunk; 'pop' is the
            number of argument bytes the callee removes
- 'body':   a hand-written wasm function with the standard signature

Nothing here is game logic. Every module carries its own statically linked C runtime, so the
helpers are found per module by their byte signature (MSVC 5/6 CRT), not by fixed address.
The emitters themselves are the ones written for A2 Racer 4's recompiler.
"""
import os

from recompile import L_ESP, L_EAX, L_ECX, L_EDX, L_EBP, L_T2, G_EDX, G_ST0, G_ST1, TIB_BASE
from wasmgen import *  # noqa: F403


def _chkstk_inline(lift, i, block, index):
    # _chkstk (0x00559400) only probes stack pages and moves esp down by eax.
    # The call's return-address push and pop cancel out.
    c = lift.c
    c.get(L_ESP)
    c.get(L_EAX)
    c.op(I32_SUB)
    c.set(L_ESP)


def _eh_prolog_inline(lift, i, block, index):
    # __EH_prolog (0x0055B39C): builds the caller's frame and C++ exception record.
    # It moves ebp for its caller, which the callee-saved model cannot express:
    #   [esp-4] = ebp, [esp-8] = -1, [esp-12] = eax (handler), [esp-16] = fs:[0]
    #   fs:[0] = esp-16, ebp = esp-4, esp = esp-16
    c = lift.c
    c.get(L_ESP)
    c.i32(4)
    c.op(I32_SUB)
    c.set(L_T2)
    c.get(L_T2)
    c.get(L_EBP)
    c.mem(I32_STORE)
    c.get(L_T2)
    c.set(L_EBP)
    c.get(L_T2)
    c.i32(4)
    c.op(I32_SUB)
    c.i32(-1)
    c.mem(I32_STORE)
    c.get(L_T2)
    c.i32(8)
    c.op(I32_SUB)
    c.get(L_EAX)
    c.mem(I32_STORE)
    c.get(L_T2)
    c.i32(12)
    c.op(I32_SUB)
    c.set(L_ESP)
    c.get(L_ESP)
    c.i32(TIB_BASE)
    c.mem(I32_LOAD)
    c.mem(I32_STORE)
    c.i32(TIB_BASE)
    c.get(L_ESP)
    c.mem(I32_STORE)


def _ftol_inline(lift, i, block, index):
    # __ftol (0x00558524): truncates ST(0) to edx:eax, pops it, restores the control word.
    # The argument was moved to G_ST0 by the x87 call convention.
    c = lift.c
    rt = lift.ctx.rt
    c.gget(G_ST0)
    c.call(rt['ftol'])
    c.set(lift_il(lift))
    c.get(lift_il(lift))
    c.op(I32_WRAP_I64)
    c.set(L_EAX)
    if lift.edx_live(block, index + 1):
        c.get(lift_il(lift))
        c.i64(32)
        c.op(I64_SHR_U, I32_WRAP_I64)
        c.set(L_EDX)


def _unary_math(name):
    """_CI* helpers: argument and result in ST(0), which the call convention passes in G_ST0."""
    def emit(lift, i, block, index):
        c = lift.c
        c.gget(G_ST0)
        c.call(lift.ctx.rt[name])
        c.gset(G_ST0)
    return emit


def _binary_math(name):
    """_CIpow style: x in ST(1), y in ST(0). G_ST0 holds ST(0), G_ST1 holds ST(1)."""
    def emit(lift, i, block, index):
        c = lift.c
        c.gget(G_ST1)
        c.gget(G_ST0)
        c.call(lift.ctx.rt[name])
        c.gset(G_ST0)
    return emit


def lift_il(lift):
    from recompile import L_IA
    return L_IA


def memcpy_body(ctx, c):
    """memmove semantics for memcpy(dst, src, n) and memmove: cdecl, returns dst."""
    # Stack on entry: [esp] return, [esp+4] dst, [esp+8] src, [esp+12] n
    c.get(0)
    c.mem(I32_LOAD, 4)
    c.get(0)
    c.mem(I32_LOAD, 8)
    c.get(0)
    c.mem(I32_LOAD, 12)
    c.memory_copy()
    c.get(0)
    c.i32(4)
    c.op(I32_ADD)
    c.get(0)
    c.mem(I32_LOAD, 4)


def memset_body(ctx, c):
    c.get(0)
    c.mem(I32_LOAD, 4)
    c.get(0)
    c.mem(I32_LOAD8_U, 8)
    c.get(0)
    c.mem(I32_LOAD, 12)
    c.memory_fill()
    c.get(0)
    c.i32(4)
    c.op(I32_ADD)
    c.get(0)
    c.mem(I32_LOAD, 4)


def strrchr_body(ctx, c):
    """strrchr(s, ch): the original scans backwards with the direction flag set."""
    # locals: 4 = cursor, 5 = result, 6 = current byte
    c.get(0)
    c.mem(I32_LOAD, 4)
    c.set(4)
    c.i32(0)
    c.set(5)
    c.loop()
    c.get(4)
    c.mem(I32_LOAD8_U)
    c.set(6)
    c.get(6)
    c.get(0)
    c.mem(I32_LOAD8_U, 8)
    c.op(I32_EQ)
    c.if_()
    c.get(4)
    c.set(5)
    c.end()
    c.get(4)
    c.i32(1)
    c.op(I32_ADD)
    c.set(4)
    c.get(6)
    c.br_if(0)
    c.end()
    c.get(0)
    c.i32(4)
    c.op(I32_ADD)
    c.get(5)




# name -> (signature bytes at the function start, replacement template)
SIGNATURES = {
    # _chkstk / __alloca_probe: push ecx; cmp eax,1000h; lea ecx,[esp+8]; jb ...
    '_chkstk': (bytes.fromhex('513D001000008D4C24087214'), {'inline': _chkstk_inline}),
    # __EH_prolog: push -1; push eax; mov eax,fs:[0]; push eax; mov eax,[esp+0Ch]; mov fs:[0],esp; ...
    '__EH_prolog': (bytes.fromhex('6AFF5064A100000000508B44240C64892500000000896C240C8D6C240C50C3'), {'inline': _eh_prolog_inline}),
    # __ftol: push ebp; mov ebp,esp; add esp,-0Ch; wait; fnstcw [ebp-2]; ...
    '__ftol': (bytes.fromhex('558BEC83C4F49BD97DFE9B668B45FE80CC0C'), {'inline': _ftol_inline, 'fpu': (1, 0)}),
    # memcpy/memmove (asm, computed jumps, std for overlapping copies)
    '_memcpy': (bytes.fromhex('558BEC57568B750C8B4D108B7D088BC18BD103C63BFE76083BF80F82'), {'body': memcpy_body}),
    '_memcpy_b': (bytes.fromhex('558BEC57568B750C8B7D088B4D103BFE760C8BC603C13BF80F82'), {'body': memcpy_body}),
    # memset (asm)
    '_memset': (bytes.fromhex('8B54240C8B4C240485D2'), {'body': memset_body}),
    # strrchr: scans backwards with the direction flag set
    '_strrchr': (bytes.fromhex('558BEC578B7D0833C083C9FFF2AE41F7D94F8A450CFDF2AE'), {'body': strrchr_body, 'locals': [(3, I32)]}),
}


def _cdecl_math(name, nargs):
    """C math function with double arguments on the stack, result in ST(0) (G_ST0)."""
    def body(ctx, c):
        c.get(0)
        c.mem(F64_LOAD, 4)
        if nargs == 2:
            c.get(0)
            c.mem(F64_LOAD, 12)
        c.call(ctx.rt[name])
        c.gset(G_ST0)
        c.get(0)
        c.i32(4)
        c.op(I32_ADD)
        c.get(1)
    return body


MATH_NAMES = {'asin': 1, 'acos': 1, 'atan': 1, 'atan2': 2, 'sinh': 1, 'cosh': 1, 'tanh': 1, 'pow': 2, 'log': 1,
              'log10': 1, 'exp': 1, 'fmod': 2}


def find_math_stubs(img, ghidra):
    """MSVC CRT transcendental entry points: 'mov edx, offset <table>; jmp dispatcher'.

    The table starts with the function's name as a counted string. The dispatcher decides the
    convention: __ctrandisp1/2 take doubles from the stack (asin(x)), __cintrindisp1/2 take them
    from the x87 stack (_CIasin). Both families run hand-written x87 code with values live across
    jumps between labels, which the static x87 model cannot follow, so they map to the host's Math.
    """
    out, report = {}, []
    disp = {}
    for a, row in ghidra.items():
        for key in ('__cintrindisp1', '__cintrindisp2', '__ctrandisp1', '__ctrandisp2'):
            if key in row['name']:
                disp[a] = key
    for lo, hi in img.text_ranges:
        blob = bytes(img.mem[lo - img.base:hi - img.base])
        p = blob.find(b'\xBA')
        while p != -1 and p + 10 <= len(blob):
            a = lo + p
            tbl = int.from_bytes(blob[p + 1:p + 5], 'little')
            op = blob[p + 5]
            tgt = None
            if op == 0xE9:
                tgt = a + 10 + int.from_bytes(blob[p + 6:p + 10], 'little', signed=True)
            elif op == 0xEB:
                tgt = a + 7 + int.from_bytes(blob[p + 6:p + 7], 'little', signed=True)
                # the short jump lands on a sibling's 'jmp dispatcher'
                q = tgt - lo
                if 0 <= q < len(blob) - 5 and blob[q] == 0xE9:
                    tgt = tgt + 5 + int.from_bytes(blob[q + 1:q + 5], 'little', signed=True)
                else:
                    tgt = None
            if tgt in disp and img.base <= tbl < img.end - 16:
                o = tbl - img.base
                n = img.mem[o]
                name = bytes(img.mem[o + 1:o + 1 + n]).decode('latin1') if 0 < n < 8 else ''
                if name in MATH_NAMES:
                    nargs = MATH_NAMES[name]
                    if 'cintrin' in disp[tgt]:
                        r = {'inline': _unary_math(name) if nargs == 1 else _binary_math(name), 'fpu': (nargs, 1), 'name': '_CI%s_%08x' % (name, a)}
                    else:
                        r = {'body': _cdecl_math(name, nargs), 'fpu': (0, 1), 'name': '_%s_%08x' % (name, a)}
                    out[a] = r
                    report.append((a, r['name']))
            p = blob.find(b'\xBA', p + 1)
    return out, report


def find_ci_direct(img):
    """Later MSVC 6 CRT builds: _CIasin, _CIacos and _CIpow that do not go through __cintrindisp.

    One argument:  sub esp,8; fst qword [esp]; call __fload_withFB; call impl; add esp,8; ret
    The implementation loads its name ('asin', 'acos') with 'lea ecx,[table]' before __math_exit.
    _CIpow:        sub esp,10h; fxch; fstp qword [esp]; fst qword [esp+8]; mov eax,[esp+0Ch]; call impl; ...
    Their bodies jump between labels with values live on the x87 stack, like the dispatcher family,
    so they map to the host's Math the same way (RedCat Spookkasteel: 0x60B110, 0x60DCD0, 0x60B760).
    """
    out, report = {}, []
    one = bytes.fromhex('83EC08DD1424E8')
    for lo, hi in img.text_ranges:
        blob = bytes(img.mem[lo - img.base:hi - img.base])
        p = blob.find(one)
        while p != -1 and p + 20 <= len(blob):
            if blob[p + 11] == 0xE8 and blob[p + 16:p + 20] == bytes.fromhex('83C408C3'):
                impl = lo + p + 16 + int.from_bytes(blob[p + 12:p + 16], 'little', signed=True)
                q = impl - lo
                name = ''
                k = blob.find(b'\x8D\x0D', q, q + 0x120) if 0 <= q < len(blob) else -1
                if k != -1:
                    tbl = int.from_bytes(blob[k + 2:k + 6], 'little')
                    if img.base <= tbl < img.end - 8:
                        raw = bytes(img.mem[tbl - img.base:tbl - img.base + 8]).split(b'\0')[0]
                        name = raw.decode('latin1')
                if name in MATH_NAMES and MATH_NAMES[name] == 1:
                    a = lo + p
                    out[a] = {'inline': _unary_math(name), 'fpu': (1, 1), 'name': '_CI%s_%08x' % (name, a)}
                    report.append((a, out[a]['name']))
            p = blob.find(one, p + 1)
        sig = bytes.fromhex('83EC10D9C9DD1C24DD5424088B44240CE8')
        p = blob.find(sig)
        while p != -1 and p + 26 <= len(blob):
            if blob[p + 21:p + 25] == bytes.fromhex('83C410C3'):
                a = lo + p
                out[a] = {'inline': _binary_math('pow'), 'fpu': (2, 1), 'name': '_CIpow_%08x' % a}
                report.append((a, out[a]['name']))
            p = blob.find(sig, p + 1)
    return out, report


def find_replacements(img, ghidra):
    """Scans every code section for the CRT helper signatures. Returns (replacements, eh_prolog addresses, report)."""
    out, eh, report = {}, set(), []
    for lo, hi in img.text_ranges:
        blob = bytes(img.mem[lo - img.base:hi - img.base])
        for name, (sig, tmpl) in SIGNATURES.items():
            p = blob.find(sig)
            while p != -1:
                a = lo + p
                r = dict(tmpl)
                r['name'] = '%s_%08x' % (name, a)
                out[a] = r
                report.append((a, name))
                if name == '__EH_prolog':
                    eh.add(a)
                p = blob.find(sig, p + 1)
    m, mr = find_math_stubs(img, ghidra)
    out.update(m)
    report.extend(mr)
    m, mr = find_ci_direct(img)
    out.update(m)
    report.extend(mr)
    return out, eh, report


def find_eh(img):
    """MSVC C++ exception tables. Returns (stubs, unwind funclets, catch funclets, try owners).

    A function with destructible locals or a try block registers a handler stub
    'mov eax, offset FuncInfo; jmp __CxxFrameHandler'. FuncInfo (magic 0x19930520) lists the unwind
    map (state -> previous state, cleanup funclet) and the try blocks with their catch funclets.
    stubs: stub address -> FuncInfo address; both funclet sets hold code addresses that are only
    ever reached from these tables.
    """
    import struct
    stubs, unwind, catches = {}, set(), set()
    base, mem = img.base, img.mem

    def u32(a):
        return struct.unpack_from('<I', mem, a - base)[0]
    for lo, hi in img.text_ranges:
        blob = bytes(mem[lo - base:hi - base])
        p = blob.find(b'\xB8')
        while p != -1 and p + 10 <= len(blob):
            if blob[p + 5] == 0xE9:
                fi = int.from_bytes(blob[p + 1:p + 5], 'little')
                if base <= fi < img.end - 20 and not img.is_text(fi) and u32(fi) == 0x19930520:
                    max_state, p_unwind, n_try, p_try = u32(fi + 4), u32(fi + 8), u32(fi + 12), u32(fi + 16)
                    if max_state < 4096 and n_try < 256:
                        stubs[lo + p] = fi
                        for k in range(max_state):
                            a = u32(p_unwind + k * 8 + 4)
                            if a and img.is_text(a):
                                unwind.add(a)
                        for k in range(n_try):
                            n_catch, p_h = u32(p_try + k * 20 + 12), u32(p_try + k * 20 + 16)
                            for j in range(n_catch):
                                a = u32(p_h + j * 16 + 12)
                                if a and img.is_text(a):
                                    catches.add(a)
            p = blob.find(b'\xB8', p + 1)
    with_try = {s for s, fi in stubs.items() if u32(fi + 12)}
    return stubs, unwind, catches, with_try
