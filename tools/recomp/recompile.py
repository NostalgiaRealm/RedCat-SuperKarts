#!/usr/bin/env python3
"""Static x86-to-WebAssembly recompiler for A2 Racer 4's spel.dat.

Input: the original PE (read-only) and Ghidra's function list from the decompile.
Output: spel.wasm with the game's logic, physics and data at their original
virtual addresses, plus spel.meta.json describing the host interface.

Model (see docs/recompiler.md):
- Linear memory holds the PE image at its original addresses, so every absolute
  address and every struct offset in the code stays what it was.
- Each x86 function becomes one wasm function (esp eax ecx edx) -> (esp eax).
  edx results go through a global. ebx, ebp, esi and edi are plain locals,
  because the MSVC ABI makes them callee-saved. This holds for every compiled
  function. Hand-written helpers that break it are replaced in replacements.py.
- The x87 stack is modelled with f64 locals at statically known depths.
- Direct conditions are computed from saved operands where one flag setter
  kind reaches each consumer, else flags are materialised into locals.
"""
import argparse
import csv
import hashlib
import json
import os
import struct
import sys
from collections import defaultdict

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import (
    X86_REG_BX as _BX,
    X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_REG_AH, X86_REG_AL, X86_REG_AX, X86_REG_BH, X86_REG_BL,
    X86_REG_BP, X86_REG_BX, X86_REG_CH, X86_REG_CL, X86_REG_CX, X86_REG_DH, X86_REG_DI, X86_REG_DL,
    X86_REG_DX, X86_REG_EAX, X86_REG_EBP, X86_REG_EBX, X86_REG_ECX, X86_REG_EDI, X86_REG_EDX,
    X86_REG_ESI, X86_REG_ESP, X86_REG_FS, X86_REG_SI, X86_REG_SP,
)

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from wasmgen import *  # noqa: E402,F403
import wasmgen as W  # noqa: E402

sys.setrecursionlimit(200000)

# Local indices. Params first: esp, eax, ecx, edx.
L_ESP, L_EAX, L_ECX, L_EDX, L_EBX, L_EBP, L_ESI, L_EDI = range(8)
L_TA, L_TB, L_TR, L_TEA, L_FA, L_FB, L_FR, L_ZF, L_SF, L_CF, L_OF, L_PF, L_FSW, L_T2, L_T3 = range(8, 23)
L_F0 = 23       # f64 x87 stack slots F0..F7
L_FT, L_FT2 = L_F0 + 8, L_F0 + 9
L_IA, L_IB = L_F0 + 10, L_F0 + 11
LOCALS_DECL = [(19, I32), (10, F64), (2, I64)]
FUNC_PARAMS = [I32, I32, I32, I32]
FUNC_RESULTS = [I32, I32]

REG = {
    X86_REG_EAX: (L_EAX, 32, 0), X86_REG_AX: (L_EAX, 16, 0), X86_REG_AL: (L_EAX, 8, 0), X86_REG_AH: (L_EAX, 8, 8),
    X86_REG_ECX: (L_ECX, 32, 0), X86_REG_CX: (L_ECX, 16, 0), X86_REG_CL: (L_ECX, 8, 0), X86_REG_CH: (L_ECX, 8, 8),
    X86_REG_EDX: (L_EDX, 32, 0), X86_REG_DX: (L_EDX, 16, 0), X86_REG_DL: (L_EDX, 8, 0), X86_REG_DH: (L_EDX, 8, 8),
    X86_REG_EBX: (L_EBX, 32, 0), X86_REG_BX: (L_EBX, 16, 0), X86_REG_BL: (L_EBX, 8, 0), X86_REG_BH: (L_EBX, 8, 8),
    X86_REG_ESP: (L_ESP, 32, 0), X86_REG_SP: (L_ESP, 16, 0),
    X86_REG_EBP: (L_EBP, 32, 0), X86_REG_BP: (L_EBP, 16, 0),
    X86_REG_ESI: (L_ESI, 32, 0), X86_REG_SI: (L_ESI, 16, 0),
    X86_REG_EDI: (L_EDI, 32, 0), X86_REG_DI: (L_EDI, 16, 0),
}

# Flag bits
FZ, FS, FC, FO, FP = 1, 2, 4, 8, 16
FALL = FZ | FS | FC | FO | FP
CC_NEEDS = {
    'o': FO, 'no': FO, 'b': FC, 'ae': FC, 'e': FZ, 'ne': FZ, 'be': FC | FZ, 'a': FC | FZ,
    's': FS, 'ns': FS, 'p': FP, 'np': FP, 'l': FS | FO, 'ge': FS | FO, 'le': FZ | FS | FO, 'g': FZ | FS | FO,
}
JCC = {'j' + k: k for k in CC_NEEDS}
SETCC = {'set' + k: k for k in CC_NEEDS}

# Memory layout. The player keeps its virtual addresses (0x400000 up); plug-ins follow it.
POP_TABLE = 0x00010000        # u32 per host thunk: bytes popped besides the return address
STACK_LOW = 0x00100000
STACK_TOP = 0x003E0000
TIB_BASE = 0x003E8000
THUNK_BASE = 0x003F0000       # fake code addresses for host thunks, one per id
N_THUNKS = 4096
MAP_LO = THUNK_BASE
DLL_BASE = 0x00600000         # first relocated plug-in
CODE_MAP = 0x00A00000         # u16 table index per byte of code address, from MAP_LO to the end of the last module
HEAP_BASE = 0x01800000
MEM_PAGES = 3072              # 192 MB

G_EDX, G_ST0, G_ST1, G_CW, G_ESP, G_A, G_B, G_ZF, G_EBX, G_EBP, G_ESI, G_EDI = range(12)
G_OF_LOCAL = {L_EBX: G_EBX, L_EBP: G_EBP, L_ESI: G_ESI, L_EDI: G_EDI}


class Op:
    __slots__ = ('type', 'size', 'reg', 'imm', 'base', 'index', 'scale', 'disp', 'seg')

    def __init__(self, o):
        self.type = o.type
        self.size = o.size
        if o.type == X86_OP_REG:
            self.reg = o.reg
        elif o.type == X86_OP_IMM:
            self.imm = o.imm
        elif o.type == X86_OP_MEM:
            m = o.mem
            self.base, self.index, self.scale, self.disp, self.seg = m.base, m.index, m.scale, m.disp, m.segment


class Insn:
    __slots__ = ('addr', 'size', 'mn', 'ops', 'bytes', 'next', 'text', 'rd', 'wr')

    def __init__(self, i):
        self.addr = i.address
        self.size = i.size
        self.mn = i.mnemonic
        if self.mn.startswith('lock '):
            # One game thread: a locked read-modify-write is the plain instruction (the C runtime's
            # lock counters in its string functions).
            self.mn = self.mn[5:]
        self.bytes = bytes(i.bytes)
        self.next = i.address + i.size
        self.ops = [Op(o) for o in i.operands]
        self.text = i.mnemonic + ' ' + i.op_str
        r, w = i.regs_access()
        self.rd, self.wr = tuple(r), tuple(w)


class Image:
    """Several PE modules merged into one address space.

    The player keeps its preferred base. Each plug-in is relocated with its own .reloc
    table to the next free 64 KiB boundary after the previous module, exactly as the
    Windows loader does when a preferred base is taken. Addresses of plug-in code in
    this build are therefore "original VA + delta"; modules[].delta maps them back.
    """

    def __init__(self, specs, first_dll_base=None):
        self.modules = []
        self.sections = []      # (name, va, vsize, rawptr, rawsize); code sections are named '.text'
        self.text_ranges = []
        self.iat = {}
        self.reloc_sites = set()
        self.mem = bytearray()
        self.base = None
        next_base = first_dll_base
        for spec in specs:
            m = self._load(spec, next_base)
            self.modules.append(m)
            if self.base is None:
                self.base = m['base']
            next_base = (m['base'] + m['size'] + 0xFFFF) & ~0xFFFF
            if first_dll_base and len(self.modules) == 1:
                next_base = max(next_base, first_dll_base)
        self.entry = self.modules[0]['entry']
        self.sha256 = self.modules[0]['sha256']
        self.text_ranges.sort()
        self.text_lo = self.text_ranges[0][0]
        self.text_hi = self.text_ranges[-1][1]
        self.end = self.base + len(self.mem)

    def _load(self, spec, want_base):
        d = open(spec['path'], 'rb').read()
        pe = struct.unpack_from('<I', d, 0x3C)[0]
        nsec = struct.unpack_from('<H', d, pe + 6)[0]
        opt = struct.unpack_from('<H', d, pe + 20)[0]
        pref = struct.unpack_from('<I', d, pe + 24 + 28)[0]
        size_image = struct.unpack_from('<I', d, pe + 24 + 56)[0]
        size_headers = struct.unpack_from('<I', d, pe + 24 + 60)[0]
        entry_rva = struct.unpack_from('<I', d, pe + 24 + 16)[0]
        dirs = [struct.unpack_from('<II', d, pe + 24 + 96 + k * 8) for k in range(16)]
        base = pref if (want_base is None or not spec.get('relocate')) else want_base
        delta = base - pref
        if self.base is None:
            self.base = base
        need = base + size_image - self.base
        if len(self.mem) < need:
            self.mem.extend(bytes(need - len(self.mem)))
        o = base - self.base
        self.mem[o:o + size_headers] = d[:size_headers]
        name = spec['name']
        secs = []
        self.sections.append((name + ':headers', base, size_headers, 0, size_headers))
        for k in range(nsec):
            s = pe + 24 + opt + k * 40
            sname = d[s:s + 8].rstrip(b'\0').decode()
            vsize, rva, rawsize, rawptr = struct.unpack_from('<IIII', d, s + 8)
            chars = struct.unpack_from('<I', d, s + 36)[0]
            n = min(rawsize, max(vsize, 0) or rawsize)
            self.mem[o + rva:o + rva + n] = d[rawptr:rawptr + n]
            is_code = bool(chars & 0x20000000)
            if sname == '.reloc':
                continue
            self.sections.append(('.text' if is_code else name + ':' + sname, base + rva, vsize, rawptr, n))
            if is_code:
                self.text_ranges.append((base + rva, base + rva + vsize))
            secs.append((sname, base + rva, vsize))
        # Base relocations.
        rrva, rsize = dirs[5]
        p = rrva
        while rsize and p < rrva + rsize:
            page, blk = struct.unpack_from('<II', self.mem, o + p)
            if blk < 8:
                break
            for q in range(p + 8, p + blk, 2):
                e = struct.unpack_from('<H', self.mem, o + q)[0]
                if e >> 12 == 3:
                    site = o + page + (e & 0xFFF)
                    v = (struct.unpack_from('<I', self.mem, site)[0] + delta) & 0xFFFFFFFF
                    struct.pack_into('<I', self.mem, site, v)
                    self.reloc_sites.add(self.base + site)
                elif e >> 12 != 0:
                    raise SystemExit('%s: unsupported relocation type %d' % (name, e >> 12))
            p += blk
        if delta and not rsize:
            raise SystemExit('%s has no relocations and cannot be moved' % name)
        # Imports.
        imp_rva = dirs[1][0]
        p = imp_rva
        while imp_rva:
            ilt, _, _, name_rva, iat = struct.unpack_from('<IIIII', self.mem, o + p)
            if not name_rva:
                break
            dll = self._cstr(o + name_rva).upper()
            q = 0
            while True:
                hint = struct.unpack_from('<I', self.mem, o + (ilt or iat) + q)[0]
                if not hint:
                    break
                fn = ('#%d' % (hint & 0xFFFF)) if hint & 0x80000000 else self._cstr(o + hint + 2)
                self.iat[base + iat + q] = dll + '!' + fn
                q += 4
            p += 20
        # Exports.
        exports = []
        erva = dirs[0][0]
        if erva:
            ebase, nfun, nnames, afun, anames, aords = struct.unpack_from('<IIIIII', self.mem, o + erva + 16)
            names = {}
            for k in range(nnames):
                nm = self._cstr(o + struct.unpack_from('<I', self.mem, o + anames + k * 4)[0])
                names[struct.unpack_from('<H', self.mem, o + aords + k * 2)[0]] = nm
            for k in range(nfun):
                frva = struct.unpack_from('<I', self.mem, o + afun + k * 4)[0]
                if frva:
                    exports.append((ebase + k, names.get(k, ''), base + frva))
        return {'name': name, 'path': spec['path'], 'sha256': hashlib.sha256(d).hexdigest(), 'preferred': pref, 'base': base,
                'delta': delta, 'size': size_image, 'entry': base + entry_rva if entry_rva else 0, 'exports': exports,
                'sections': secs, 'is_dll': bool(struct.unpack_from('<H', d, pe + 22)[0] & 0x2000), 'id': spec['id']}

    def _cstr(self, off):
        e = self.mem.index(0, off)
        return self.mem[off:e].decode('latin1')

    def is_text(self, v):
        for lo, hi in self.text_ranges:
            if lo <= v < hi:
                return True
        return False

    def same_text(self, a, b):
        for lo, hi in self.text_ranges:
            if lo <= a < hi:
                return lo <= b < hi
        return False

    def u32(self, va):
        return struct.unpack_from('<I', self.mem, va - self.base)[0]

    def u8(self, va):
        return self.mem[va - self.base]


class Block:
    __slots__ = ('start', 'insns', 'kind', 'succs', 'target', 'table', 'tail_insn', 'cc', 'preds', 'rpo',
                 'fpu_in', 'code', 'flag_in', 'live_in', 'live_out')

    def __init__(self, start):
        self.start = start
        self.insns = []
        self.kind = 'fall'
        self.succs = []
        self.preds = []
        self.target = None
        self.table = None
        self.tail_insn = None
        self.cc = None
        self.rpo = -1
        self.fpu_in = None
        self.code = None
        self.flag_in = None
        self.live_in = 0
        self.live_out = 0


class Func:
    __slots__ = ('addr', 'name', 'blocks', 'order', 'entry_block', 'fpu_in', 'fpu_out', 'fpu_ok', 'icall_ret',
                 'mode_b', 'idx', 'uses', 'insn_count', 'has_std', 'notes', 'force_float_ret')

    def __init__(self, addr, name):
        self.addr = addr
        self.name = name
        self.blocks = {}
        self.order = []
        self.fpu_in = 0
        self.fpu_out = 0
        self.fpu_ok = True
        self.icall_ret = set()
        self.mode_b = False
        self.idx = None
        self.insn_count = 0
        self.has_std = False
        self.notes = []
        self.force_float_ret = False


# ---------------------------------------------------------------------------
# x87 classification, from raw bytes because register forms are ambiguous in
# disassembler text.
# ---------------------------------------------------------------------------

def x87_form(i):
    """Returns (name, arg) for register and no-operand forms, else None for memory forms."""
    b = i.bytes
    k = 0
    while b[k] in (0x66, 0x9B):
        k += 1
    op = b[k]
    if op < 0xD8 or op > 0xDF:
        return None
    m = b[k + 1]
    if m < 0xC0:
        return None
    r, s = (m >> 3) & 7, m & 7
    if op == 0xD8:
        return (('fadd0', 'fmul0', 'fcom', 'fcomp', 'fsub0', 'fsubr0', 'fdiv0', 'fdivr0')[r], s)
    if op == 0xDC:
        return (('faddi', 'fmuli', 'fcom', 'fcomp', 'fsubri', 'fsubi', 'fdivri', 'fdivi')[r], s)
    if op == 0xDE:
        if r == 3 and s == 1:
            return ('fcompp', 1)
        return (('faddp', 'fmulp', None, None, 'fsubrp', 'fsubp', 'fdivrp', 'fdivp')[r], s)
    if op == 0xD9:
        if r == 0:
            return ('fld', s)
        if r == 1:
            return ('fxch', s)
        return ({0xD0: 'fnop', 0xE0: 'fchs', 0xE1: 'fabs', 0xE4: 'ftst', 0xE5: 'fxam', 0xE8: 'fld1', 0xE9: 'fldl2t',
                 0xEA: 'fldl2e', 0xEB: 'fldpi', 0xEC: 'fldlg2', 0xED: 'fldln2', 0xEE: 'fldz', 0xF0: 'f2xm1',
                 0xF1: 'fyl2x', 0xF2: 'fptan', 0xF3: 'fpatan', 0xF5: 'fprem1', 0xF8: 'fprem', 0xFA: 'fsqrt',
                 0xFB: 'fsincos', 0xFC: 'frndint', 0xFD: 'fscale', 0xFE: 'fsin', 0xFF: 'fcos'}.get(m), 0)
    if op == 0xDD:
        return (('ffree', None, 'fst', 'fstp', 'fcom', 'fcomp', None, None)[r], s)
    if op == 0xDA and m == 0xE9:
        return ('fcompp', 1)
    if op == 0xDB:
        return ({0xE2: 'fnclex', 0xE3: 'fninit'}.get(m), 0)
    if op == 0xDF and m == 0xE0:
        return ('fnstsw_ax', 0)
    return (None, 0)


# depth delta and required depth for x87 forms
def x87_stack_effect(i):
    """(required depth, delta) of an instruction on the x87 stack, or None if it is not x87."""
    mn = i.mn
    if mn[0] != 'f' and mn != 'wait':
        return None
    if mn == 'wait':
        return (0, 0)
    f = x87_form(i)
    if f is not None:
        name, s = f
        if name is None:
            return (0, 0)
        if name in ('fadd0', 'fmul0', 'fsub0', 'fsubr0', 'fdiv0', 'fdivr0', 'faddi', 'fmuli', 'fsubi', 'fsubri',
                    'fdivi', 'fdivri', 'fcom', 'fxch', 'fst'):
            return (max(s + 1, 1), 0)
        if name in ('fcomp', 'fstp'):
            return (max(s + 1, 1), -1)
        if name in ('faddp', 'fmulp', 'fsubp', 'fsubrp', 'fdivp', 'fdivrp'):
            return (max(s + 1, 1), -1)
        if name == 'fcompp':
            return (2, -2)
        if name == 'fld':
            return (s + 1, 1)
        if name in ('fld1', 'fldl2t', 'fldl2e', 'fldpi', 'fldlg2', 'fldln2', 'fldz'):
            return (0, 1)
        if name in ('fchs', 'fabs', 'ftst', 'fxam', 'f2xm1', 'fsqrt', 'frndint', 'fsin', 'fcos'):
            return (1, 0)
        if name == 'fptan':
            return (1, 1)
        if name == 'fsincos':
            return (1, 1)
        if name in ('fyl2x', 'fpatan'):
            return (2, -1)
        if name in ('fprem', 'fprem1', 'fscale'):
            return (2, 0)
        return (0, 0)
    # Memory forms and no-stack instructions
    if mn in ('fnstcw', 'fldcw', 'fnstsw', 'fnclex', 'fninit', 'fnstenv', 'fldenv', 'fnsave', 'frstor', 'fstcw', 'fstsw'):
        return (0, 0)
    if mn in ('fld', 'fild'):
        return (0, 1)
    if mn in ('fst', 'fist'):
        return (1, 0)
    if mn in ('fstp', 'fistp'):
        return (1, -1)
    if mn in ('fadd', 'fmul', 'fsub', 'fsubr', 'fdiv', 'fdivr', 'fiadd', 'fimul', 'fisub', 'fisubr', 'fidiv', 'fidivr', 'fcom', 'ficom'):
        return (1, 0)
    if mn in ('fcomp', 'ficomp'):
        return (1, -1)
    return None


# Instructions whose flag effects matter. Returns (reads, writes, kind).
# kind is a lazy-capable representation name or None.
LOGIC = {'and', 'or', 'xor', 'test'}
PARTIAL_MN = {'rol', 'ror', 'rcl', 'rcr', 'bt', 'bts', 'btr', 'btc', 'stc', 'clc', 'cmc'}


def flag_effect(i):
    mn = i.mn
    if mn in JCC:
        return (CC_NEEDS[JCC[mn]], 0, None)
    if mn in SETCC:
        return (CC_NEEDS[SETCC[mn]], 0, None)
    if mn in ('cmp', 'sub'):
        return (0, FALL, 'sub')
    if mn in LOGIC:
        return (0, FALL, 'logic')
    if mn == 'add':
        return (0, FALL, 'add')
    if mn == 'inc':
        return (0, FZ | FS | FO | FP, 'inc' if i.ops[0].size == 4 else None)
    if mn == 'dec':
        return (0, FZ | FS | FO | FP, 'dec' if i.ops[0].size == 4 else None)
    if mn == 'neg':
        return (0, FALL, 'neg')
    if mn in ('adc', 'sbb'):
        return (FC, FALL, None)
    if mn in ('shl', 'sal', 'shr', 'sar'):
        o = i.ops[1] if len(i.ops) > 1 else None
        if o is not None and o.type == X86_OP_IMM:
            if o.imm & 31:
                return (0, FALL, 'shift')
            return (0, 0, None)
        return (0, 0, 'varshift')  # may leave flags alone: partial
    if mn in ('shld', 'shrd'):
        return (0, 0, 'varshift')
    if mn in ('imul', 'mul', 'div', 'idiv'):
        return (0, FALL, None)
    if mn == 'sahf':
        return (0, FZ | FS | FC | FP, None)
    if mn in ('bt', 'bts', 'btr', 'btc'):
        return (0, FC, None)
    if mn in ('rol', 'ror'):
        return (0, FC | FO, None)
    if mn in ('rcl', 'rcr'):
        return (FC, FC | FO, None)
    if mn in ('stc', 'clc'):
        return (0, FC, None)
    if mn == 'cmc':
        return (FC, FC, None)
    if mn in ('repe cmpsb', 'repe cmpsd', 'repne cmpsb', 'repe cmpsw', 'repne scasb', 'repe scasb', 'repne scasd', 'repne scasw'):
        return (0, 0, 'repcmp')   # flags change only when the count is non-zero
    if mn in ('cmpsb', 'cmpsw', 'cmpsd', 'scasb', 'scasw', 'scasd'):
        return (0, FALL, None)
    return (0, 0, None)


class Unsupported(Exception):
    pass


class Recompiler:
    def __init__(self, img, ghidra, noreturn, skip_names, replacements, debug_ret=True, fpu_pc=24):
        self.img = img
        self.md = Cs(CS_ARCH_X86, CS_MODE_32)
        self.md.detail = True
        self.decoded = {}
        self.ghidra = ghidra               # address in this build -> row with name and body_ranges (already shifted)
        self.eh_prolog = set()
        self.noreturn = set(noreturn)
        self.skip_names = skip_names
        self.replacements = replacements   # addr -> callable(rec, Code) or ('hook', name, pop)
        self.debug_ret = debug_ret
        self.ret_store_targets = set()
        # call site -> (start, end) of added code spliced into its caller instead of called.
        self.splices = {}
        self.ret_store_range = (0, 0)
        self.fpu_pc = fpu_pc
        self.funcs = {}
        self.real_entries = set()
        self.problems = defaultdict(list)
        self.hooks = {}                    # addr -> thunk id
        self.thunk_names = {}              # id -> name
        self.extra_entries = []
        self.extra_roots = []
        self.force_uses = set()
        self.table_starts = set()
        self.body_index = None
        self.thunk_pops = {}

    # --- decoding -----------------------------------------------------------
    def decode(self, a):
        i = self.decoded.get(a)
        if i is None:
            off = a - self.img.base
            for x in self.md.disasm(bytes(self.img.mem[off:off + 16]), a, 1):
                i = Insn(x)
                break
            if i is None:
                raise Unsupported('undecodable at %08x' % a)
            self.decoded[a] = i
        return i

    def splice_return(self, ret_addr, fn_addr):
        """Where a ret in spliced code continues in its caller, or None for an ordinary ret."""
        for site, (lo, hi) in self.splices.items():
            if lo <= ret_addr < hi and fn_addr != lo:
                return self.decode(site).next
        return None

    def ret_store_from(self, addr):
        lo, hi = self.ret_store_range
        return lo <= addr < hi

    def is_excluded(self, addr):
        row = self.ghidra.get(addr)
        if not row:
            return False
        n = row['name']
        return any(n.startswith(p) for p in self.skip_names)

    def in_ghidra_body(self, v):
        if self.body_index is None:
            import bisect
            ranges = []
            for row in self.ghidra.values():
                ranges.extend(row['ranges'])
            ranges.sort()
            self.body_index = ([r[0] for r in ranges], [r[1] for r in ranges], bisect)
        los, his, bisect = self.body_index
        k = bisect.bisect_right(los, v) - 1
        return k >= 0 and v <= his[k]

    def scan_entries(self):
        """Collect call targets and address-taken functions over the whole Ghidra function set."""
        img = self.img
        taken = set()
        calls = set()
        for addr, row in self.ghidra.items():
            if self.is_excluded(addr):
                continue
            for lo, hi in row['ranges']:
                a = lo
                while a <= hi:
                    try:
                        i = self.decode(a)
                    except Unsupported:
                        break
                    if i.mn == 'jmp' and i.ops[0].type == X86_OP_MEM and i.ops[0].index and i.ops[0].scale == 4 and not i.ops[0].base:
                        self.table_starts.add(i.ops[0].disp & 0xFFFFFFFF)
                    if i.mn == 'call' and i.ops[0].type == X86_OP_IMM:
                        calls.add(i.ops[0].imm & 0xFFFFFFFF)
                    else:
                        for o in i.ops:
                            if o.type != X86_OP_IMM or o.size != 4:
                                continue
                            v = o.imm & 0xFFFFFFFF
                            if v in self.ghidra and i.mn in ('push', 'mov'):
                                taken.add(v)
                            elif i.mn == 'push' and img.is_text(v):
                                # A callback passed to a helper, at an address Ghidra did not list.
                                self.extra_entries.append((v, i.addr))
                            elif i.mn == 'mov' and img.is_text(v) and not self.in_ghidra_body(v):
                                # A function pointer loaded or stored with mov, outside Ghidra's functions
                                # (RcHcGame.dat: the window procedure 0x5A8180, the callback 0x600F3C).
                                self.extra_entries.append((v, i.addr))
                    a = i.next
        # Data references to code: vtables, callback tables, initialiser lists. Every absolute
        # address stored in the image has a base relocation, so only relocated words are pointers.
        for site in sorted(img.reloc_sites):
            if img.is_text(site):
                continue
            v = img.u32(site)
            if v in self.ghidra:
                taken.add(v)
            elif img.is_text(v) and not self.in_ghidra_body(v):
                self.extra_entries.append((v, site))
        # Feasibility test addition, taken from A2 Racer 4's recompiler: a module without base
        # relocations (RcHcGame.dat, like A2's spel.dat) gets its data sections scanned word by word.
        for m in img.modules:
            lo, hi = m['base'], m['base'] + m['size']
            if any(lo <= s_ < hi for s_ in img.reloc_sites):
                continue
            for name, va, vsize, rawptr, rawsize in img.sections:
                if name == '.text' or not (lo <= va < hi):
                    continue
                sz = min(vsize, rawsize) if rawsize else 0
                for off in range(0, max(0, sz - 3), 4):
                    v = img.u32(va + off)
                    if v in self.ghidra:
                        taken.add(v)
                    elif img.is_text(v) and (not self.in_ghidra_body(v) or (v & 15) == 0):
                        self.extra_entries.append((v, va + off))
        self.address_taken = {a for a in taken if not self.is_excluded(a)}
        self.problems['data_refs_outside_functions'] = sorted('%08x<-%08x' % x for x in self.extra_entries)
        for v, src in self.extra_entries:
            self.address_taken.add(v)
        self.call_targets = calls
        self.real_entries = {a for a in (calls | self.address_taken) if not self.is_excluded(a)} | set(self.extra_roots)
        self.real_entries.add(img.entry)

    def jump_table(self, i, fn_addr):
        """Targets of 'jmp [reg*4 + table]': consecutive pointers into nearby code.

        What follows a table never reads as such a pointer: it is a byte index table,
        padding or the next function's first instructions.
        """
        table = i.ops[0].disp & 0xFFFFFFFF
        out = []
        a = table

        def valid(v):
            return self.img.same_text(i.addr, v) and abs(v - i.addr) <= 0x20000
        if not valid(self.img.u32(a)) and self.img.u32(a) != 0:
            # The compiler folds a constant index bias into the displacement, so the
            # displacement may point before the table: skip to the first real entry.
            k = 0
            while k < 512 and not valid(self.img.u32(a + k * 4)):
                k += 1
            if k == 512:
                return []
            out = [None] * k
            a += k * 4
        while len(out) < 4096:
            if out and a in self.table_starts:
                break               # the next switch's table
            v = self.img.u32(a)
            if v == 0:
                out.append(None)    # a hole for a case value the code never expects
                a += 4
                continue
            if not valid(v):
                break
            out.append(v)
            a += 4
        while out and out[-1] is None:
            out.pop()
        return out

    # --- control-flow graph -------------------------------------------------
    def build(self, addr):
        fn = Func(addr, (self.ghidra.get(addr) or {}).get('name', 'sub_%08x' % addr))
        insns = {}
        leaders = {addr}
        work = [addr]
        ends = {}
        while work:
            a = work.pop()
            while a not in insns:
                i = self.decode(a)
                insns[a] = i
                fn.insn_count += 1
                mn = i.mn
                if mn == 'ret' or mn == 'retf':
                    back = self.splice_return(a, addr)
                    if back is not None:
                        ends[a] = ('jmp', back)
                        leaders.add(back)
                        work.append(back)
                    else:
                        ends[a] = ('ret', None)
                    break
                if mn == 'jmp':
                    o = i.ops[0]
                    if o.type == X86_OP_IMM:
                        t = o.imm & 0xFFFFFFFF
                        if t in self.real_entries and t != addr:
                            ends[a] = ('tail', t)
                        elif t in self.replacements:
                            ends[a] = ('tail', t)
                        else:
                            ends[a] = ('jmp', t)
                            leaders.add(t)
                            work.append(t)
                    elif o.type == X86_OP_MEM and o.index != 0 and o.scale == 4 and o.base == 0 and o.disp:
                        tgts = self.jump_table(i, addr)
                        if not tgts:
                            self.problems['empty_jump_table'].append(hex(i.addr))
                        ends[a] = ('switch', tgts)
                        for t in tgts:
                            if t is not None:
                                leaders.add(t)
                                work.append(t)
                    elif o.type == X86_OP_MEM and o.index == 0 and o.base == 0:
                        ends[a] = ('tailmem', o.disp & 0xFFFFFFFF)
                    else:
                        ends[a] = ('tailind', None)
                    break
                if mn in JCC or mn == 'jecxz':
                    t = i.ops[0].imm & 0xFFFFFFFF
                    ends[a] = ('cond', t)
                    leaders.add(t)
                    leaders.add(i.next)
                    work.append(t)
                    a = i.next
                    continue
                if mn == 'call':
                    o = i.ops[0]
                    if a in self.splices:
                        t = self.splices[a][0]
                        if o.type != X86_OP_IMM or (o.imm & 0xFFFFFFFF) != t:
                            raise Unsupported('splice at %08x does not call %08x' % (a, t))
                        ends[a] = ('jmp', t)
                        leaders.add(t)
                        work.append(t)
                        break
                    if o.type == X86_OP_IMM and (o.imm & 0xFFFFFFFF) in self.noreturn:
                        ends[a] = ('noreturn', None)
                        break
                    a = i.next
                    continue
                if mn in ('int3', 'hlt', 'int', 'ud2'):
                    ends[a] = ('trap', None)
                    break
                a = i.next
        # Partition into blocks.
        addrs = sorted(insns)
        cur = None
        for a in addrs:
            i = insns[a]
            if cur is not None and cur.insns[-1].next != a:
                raise Unsupported('overlapping decode at %08x in %08x' % (a, addr))
            if cur is None or a in leaders:
                nb = Block(a)
                if cur is not None and cur.kind == 'fall' and cur.insns[-1].next == a:
                    cur.succs = [a]
                fn.blocks[a] = nb
                cur = nb
            cur.insns.append(i)
            e = ends.get(a)
            if e:
                kind, arg = e
                cur.kind = kind
                cur.tail_insn = i
                if kind == 'cond':
                    cur.target = arg
                    cur.cc = JCC.get(i.mn, 'ecxz')
                    cur.succs = [arg, i.next]
                elif kind == 'jmp':
                    cur.succs = [arg]
                elif kind == 'switch':
                    cur.table = arg
                    cur.succs = sorted(set(t for t in arg if t is not None))
                elif kind in ('tail', 'tailmem'):
                    cur.target = arg
                cur = None
                continue
            nx = i.next
            if nx not in insns:
                # Falls into code we have not seen: cannot happen with a complete walk.
                raise Unsupported('fallthrough gap at %08x in %08x' % (a, addr))
        for b in fn.blocks.values():
            for s in b.succs:
                if s not in fn.blocks:
                    raise Unsupported('successor %08x of %08x missing in %08x' % (s, b.start, addr))
                fn.blocks[s].preds.append(b.start)
        fn.has_std = any(i.mn == 'std' for i in insns.values())
        # Reverse postorder.
        order = []
        seen = set()
        stack = [(addr, iter(fn.blocks[addr].succs))]
        seen.add(addr)
        while stack:
            n, it = stack[-1]
            for s in it:
                if s not in seen:
                    seen.add(s)
                    stack.append((s, iter(fn.blocks[s].succs)))
                    break
            else:
                order.append(n)
                stack.pop()
        order.reverse()
        fn.order = order
        for k, a in enumerate(order):
            fn.blocks[a].rpo = k
        return fn

    def discover(self):
        """Reachable functions from the entry point and every address-taken function."""
        roots = [self.img.entry] + sorted(self.address_taken) + list(self.extra_roots)
        work = list(roots)
        while work:
            a = work.pop()
            if a in self.funcs or (a in self.replacements and not self.replacements[a].get('keep_body')):
                continue
            try:
                fn = self.build(a)
            except Unsupported as e:
                self.problems['build'].append(str(e))
                continue
            self.funcs[a] = fn
            for b in fn.blocks.values():
                for i in b.insns:
                    if i.mn == 'call' and i.ops[0].type == X86_OP_IMM:
                        t = i.ops[0].imm & 0xFFFFFFFF
                        if t not in self.funcs:
                            work.append(t)
                if b.kind == 'tail' and b.target not in self.funcs:
                    work.append(b.target)

    # --- x87 depth analysis -------------------------------------------------
    def call_fpu(self, fn, i):
        """(in, out) x87 effect of a call instruction."""
        o = i.ops[0]
        if o.type == X86_OP_IMM:
            t = o.imm & 0xFFFFFFFF
            r = self.replacements.get(t)
            if r is not None and not r.get('wrap'):
                return r.get('fpu', (0, 0))
            f = self.funcs.get(t)      # a wrap (build.py GAME_HOOKS) runs its body: the body's own summary
            if f is not None:
                return (f.fpu_in, f.fpu_out)
            return (0, 0)
        if o.type == X86_OP_MEM and o.base == 0 and o.index == 0 and (o.disp & 0xFFFFFFFF) in self.img.iat:
            return (0, 0)
        return (0, 1 if i.addr in fn.icall_ret else 0)

    def fpu_pass(self, fn, final=False):
        """Propagates x87 depth through fn. Returns True when its summary changed.

        Compiled functions take no x87 arguments and return at most ST(0), so inputs
        are only ever declared for replacements. An underflow means a call returned a
        float that was not known about (attributed to the block's last indirect call)
        or the function is a hand-written helper that needs a replacement.
        """
        changed = False
        for b in fn.blocks.values():
            b.fpu_in = None
        fn.blocks[fn.addr].fpu_in = fn.fpu_in
        work = [fn.addr]
        out_depth = None
        underflow = None
        conflict = False
        end_icall = {}
        while work:
            ba = work.pop()
            b = fn.blocks[ba]
            d = b.fpu_in
            last_icall = None
            last_direct = None
            for i in b.insns:
                if i.mn == 'call' and b.kind == 'jmp' and i is b.tail_insn:
                    continue    # a splice: its code follows in this function
                if i.mn == 'call':
                    ci, co = self.call_fpu(fn, i)
                    if d < ci:
                        underflow = i.addr
                        d = ci
                    d = d - ci + co
                    o = i.ops[0]
                    last_direct = None
                    last_icall = None
                    if o.type == X86_OP_IMM:
                        if co == 0:
                            last_direct = o.imm & 0xFFFFFFFF
                    elif not (o.type == X86_OP_MEM and o.base == 0 and o.index == 0 and (o.disp & 0xFFFFFFFF) in self.img.iat) and co == 0:
                        last_icall = i
                    continue
                e = x87_stack_effect(i)
                if e is None:
                    continue
                req, delta = e
                if d < req:
                    # A value appeared out of nowhere: the last call must have returned it.
                    if last_icall is not None and last_icall.addr not in fn.icall_ret:
                        fn.icall_ret.add(last_icall.addr)
                        changed = True
                    elif last_direct is not None and last_direct in self.funcs and not self.funcs[last_direct].force_float_ret:
                        self.funcs[last_direct].force_float_ret = True
                        changed = True
                    else:
                        underflow = i.addr
                    d = req
                d += delta
                if d > 8:
                    d = 8
            if b.kind == 'ret':
                if fn.force_float_ret and d == 0:
                    if last_icall is not None and last_icall.addr not in fn.icall_ret:
                        fn.icall_ret.add(last_icall.addr)
                        changed = True
                    elif last_direct is not None and last_direct in self.funcs and not self.funcs[last_direct].force_float_ret:
                        self.funcs[last_direct].force_float_ret = True
                        changed = True
                out_depth = d if out_depth is None else max(out_depth, d)
            elif b.kind == 'tail':
                t = self.funcs.get(b.target)
                r = self.replacements.get(b.target)
                if r is not None and not r.get('wrap'):
                    ci, co = r.get('fpu', (0, 0))
                elif t is not None:
                    ci, co = t.fpu_in, t.fpu_out
                else:
                    ci, co = 0, 0
                if fn.force_float_ret and co == 0 and t is not None and not t.force_float_ret:
                    t.force_float_ret = True
                    changed = True
                dd = max(d, ci) - ci + co
                out_depth = dd if out_depth is None else max(out_depth, dd)
            for s in b.succs:
                sb = fn.blocks[s]
                if sb.fpu_in is None:
                    sb.fpu_in = d
                    end_icall[s] = last_icall
                    work.append(s)
                elif sb.fpu_in != d:
                    # A float-returning indirect call that reaches a merge one slot short.
                    if sb.fpu_in == d + 1 and last_icall is not None and last_icall.addr not in fn.icall_ret:
                        fn.icall_ret.add(last_icall.addr)
                        changed = True
                    elif sb.fpu_in == d - 1 and end_icall.get(s) is not None and end_icall[s].addr not in fn.icall_ret:
                        fn.icall_ret.add(end_icall[s].addr)
                        changed = True
                    conflict = True
        out = min(out_depth or 0, 1)
        if out != fn.fpu_out:
            fn.fpu_out = out
            changed = True
        if final:
            fn.notes = []
            if underflow is not None:
                fn.notes.append('x87 underflow at %08x' % underflow)
                fn.fpu_ok = False
            if conflict:
                fn.notes.append('x87 depth conflict')
                fn.fpu_ok = False
            if out_depth and out_depth > 1:
                fn.notes.append('x87 depth %d at return' % out_depth)
                fn.fpu_ok = False
        return changed

    def analyse_fpu(self):
        for round_no in range(40):
            changed = False
            for fn in self.funcs.values():
                if self.fpu_pass(fn):
                    changed = True
            if not changed:
                break
        else:
            self.problems['fpu'].append('summaries did not converge')
        for fn in self.funcs.values():
            self.fpu_pass(fn, final=True)

    # --- callee-saved registers used as inputs ---------------------------------
    def analyse_inputs(self):
        """Finds functions that read ebx, ebp, esi or edi before writing them.

        __finally blocks are called with the parent's ebp live, so they break the
        rule that callee-saved registers carry no input. Such functions receive
        those registers through globals.
        """
        saved = {X86_REG_EBX, X86_REG_EBP, X86_REG_ESI, X86_REG_EDI}
        names = {X86_REG_EBX: L_EBX, X86_REG_EBP: L_EBP, X86_REG_ESI: L_ESI, X86_REG_EDI: L_EDI}
        low = {X86_REG_BX: X86_REG_EBX, X86_REG_BL: X86_REG_EBX, X86_REG_BH: X86_REG_EBX, X86_REG_BP: X86_REG_EBP,
               X86_REG_SI: X86_REG_ESI, X86_REG_DI: X86_REG_EDI}
        for fn in self.funcs.values():
            fn.uses = set()
            if fn.addr in self.force_uses:
                fn.uses = {L_EBX, L_EBP, L_ESI, L_EDI}
                continue
            state = {fn.addr: frozenset()}
            work = [fn.addr]
            while work:
                a = work.pop()
                b = fn.blocks[a]
                w = set(state[a])
                for i in b.insns:
                    if i.mn == 'call':
                        if i.ops[0].type == X86_OP_IMM and (i.ops[0].imm & 0xFFFFFFFF) in self.eh_prolog:
                            w.add(X86_REG_EBP)    # __EH_prolog sets the caller's ebp
                        continue
                    is_push = i.mn == 'push' and i.ops[0].type == X86_OP_REG
                    is_clear = i.mn == 'xor' and i.ops[0].type == X86_OP_REG and i.ops[1].type == X86_OP_REG and i.ops[0].reg == i.ops[1].reg
                    if not is_push and not is_clear:
                        for r in i.rd:
                            r = low.get(r, r)
                            if r in saved and r not in w:
                                fn.uses.add(names[r])
                    for r in i.wr:
                        r = low.get(r, r)
                        if r in saved:
                            w.add(r)
                    if is_clear and i.ops[0].reg in saved:
                        w.add(i.ops[0].reg)
                    if i.mn == 'pop' and i.ops[0].type == X86_OP_REG and i.ops[0].reg in saved:
                        w.add(i.ops[0].reg)
                fz = frozenset(w)
                for s in b.succs:
                    if s not in state:
                        state[s] = fz
                        work.append(s)
                    else:
                        merged = state[s] & fz
                        if merged != state[s]:
                            state[s] = merged
                            work.append(s)

    # --- flags analysis -----------------------------------------------------
    def analyse_flags(self, fn):
        """Per-flag liveness, then decide lazy (mode A) or materialised (mode B) flags."""
        blocks = fn.blocks
        # Backward liveness per block.
        changed = True
        while changed:
            changed = False
            for a in reversed(fn.order):
                b = blocks[a]
                live = 0
                for s in b.succs:
                    live |= blocks[s].live_in
                b.live_out = live
                for i in reversed(b.insns):
                    if i.mn == 'call':
                        live = 0
                        continue
                    r, w, _ = flag_effect(i)
                    live = (live & ~w) | r
                if live != b.live_in:
                    b.live_in = live
                    changed = True
        # Forward kind propagation: each block entry state is a kind, 'none' or 'mixed'.
        for b in blocks.values():
            b.flag_in = None
        blocks[fn.addr].flag_in = 'none'
        work = [fn.addr]
        lazy_ok = True
        while work:
            a = work.pop()
            b = blocks[a]
            k = b.flag_in
            for i in b.insns:
                if i.mn == 'call':
                    k = 'none'
                    continue
                r, w, kind = flag_effect(i)
                if kind in ('varshift', 'repcmp'):
                    k = 'mixed'
                elif w:
                    k = kind if kind else 'other'
            for s in b.succs:
                sb = blocks[s]
                if sb.flag_in is None:
                    sb.flag_in = k
                    work.append(s)
                elif sb.flag_in != k and sb.flag_in != 'mixed':
                    sb.flag_in = 'mixed'
                    work.append(s)
        # Check every consumer can be served lazily.
        for a in fn.order:
            b = blocks[a]
            k = b.flag_in
            for i in b.insns:
                if i.mn == 'call':
                    k = 'none'
                    continue
                r, w, kind = flag_effect(i)
                if r:
                    cc = JCC.get(i.mn) or SETCC.get(i.mn) or 'b'
                    if i.mn in ('rcl', 'rcr', 'cmc') or not lazy_supported(k, cc):
                        lazy_ok = False
                if kind in ('varshift', 'repcmp'):
                    k = 'mixed'
                elif w:
                    k = kind if kind else 'other'
        fn.mode_b = not lazy_ok


def lazy_supported(kind, cc):
    if kind == 'sub':
        return cc not in ('p', 'np')
    if kind == 'logic':
        return cc not in ('p', 'np')
    if kind == 'add':
        return cc in ('e', 'ne', 's', 'ns', 'b', 'ae', 'be', 'a')
    if kind in ('inc', 'dec'):
        return cc in ('e', 'ne', 's', 'ns', 'l', 'ge', 'le', 'g')
    if kind == 'neg':
        return cc in ('e', 'ne', 's', 'ns', 'b', 'ae')
    if kind == 'shift':
        return cc in ('e', 'ne', 's', 'ns')
    return False


def main():
    raise SystemExit('use build.py')


if __name__ == '__main__':
    main()
