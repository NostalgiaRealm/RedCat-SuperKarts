"""Lifts one x86 function to a wasm function body. See recompile.py for the model."""
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_REG_ECX, X86_REG_CX, X86_REG_CL, X86_REG_CH, X86_REG_EDX, X86_REG_DX, X86_REG_DL, X86_REG_DH, X86_REG_FS, X86_REG_ESP, X86_REG_EBP, X86_REG_EAX

from wasmgen import *  # noqa: F403
from recompile import (
    REG, L_ESP, L_EAX, L_ECX, L_EDX, L_EBX, L_EBP, L_ESI, L_EDI, L_TA, L_TB, L_TR, L_TEA, L_FA, L_FB, L_FR,
    L_ZF, L_SF, L_CF, L_OF, L_PF, L_FSW, L_T2, L_T3, L_F0, L_FT, L_FT2, L_IA, L_IB,
    FZ, FS, FC, FO, FP, FALL, CC_NEEDS, JCC, SETCC, flag_effect, x87_form, x87_stack_effect, lazy_supported,
    G_EDX, G_ST0, G_ST1, G_CW, G_A, G_B, G_ZF, G_OF_LOCAL, TIB_BASE, CODE_MAP, MAP_LO, Unsupported,
)

ECX_REGS = {X86_REG_ECX, X86_REG_CX, X86_REG_CL, X86_REG_CH}
EDX_REGS = {X86_REG_EDX, X86_REG_DX, X86_REG_DL, X86_REG_DH}
LOG2 = {1: 0, 2: 1, 4: 2, 8: 3}
LOAD_U = {1: I32_LOAD8_U, 2: I32_LOAD16_U, 4: I32_LOAD}
STORE = {1: I32_STORE8, 2: I32_STORE16, 4: I32_STORE}
INT_MIN = 0x80000000
INT_MAX = 0x7FFFFFFF


class FnLifter:
    def __init__(self, ctx, fn):
        self.ctx = ctx          # ModuleContext from build.py
        self.rec = ctx.rec
        self.fn = fn
        self.c = None
        self.d = 0
        self.kind = 'none'
        self.ecx_known = None
        self.writes_edx = any(
            any(r in EDX_REGS for r in i.wr) for b in fn.blocks.values() for i in b.insns if i.mn != 'call'
        )

    # --- operands ------------------------------------------------------------
    def ea(self, o):
        """Pushes the base of an effective address and returns a static load offset."""
        c = self.c
        have = False
        if o.base:
            c.get(REG[o.base][0])
            have = True
        if o.index:
            c.get(REG[o.index][0])
            if o.scale > 1:
                c.i32(LOG2[o.scale])
                c.op(I32_SHL)
            if have:
                c.op(I32_ADD)
            have = True
        d = o.disp
        if o.seg == X86_REG_FS:
            d += TIB_BASE
        d &= 0xFFFFFFFF
        if not have:
            c.i32(d)
            return 0
        if d >= 0x80000000:
            d -= 0x100000000
        if 0 <= d < 0x8000:
            return d
        c.i32(d)
        c.op(I32_ADD)
        return 0

    def ea_full(self, o):
        off = self.ea(o)
        if off:
            self.c.i32(off)
            self.c.op(I32_ADD)

    def ea_tea(self, o):
        self.ea_full(o)
        self.c.set(L_TEA)

    def rd_reg(self, reg):
        c = self.c
        li, bits, sh = REG[reg]
        c.get(li)
        if sh:
            c.i32(sh)
            c.op(I32_SHR_U)
        if bits == 8:
            c.i32(0xFF)
            c.op(I32_AND)
        elif bits == 16:
            c.i32(0xFFFF)
            c.op(I32_AND)

    def wr_reg(self, reg):
        """Takes the value from the wasm stack."""
        c = self.c
        li, bits, sh = REG[reg]
        if bits == 32:
            c.set(li)
            return
        mask = (1 << bits) - 1
        c.set(L_T3)
        c.get(li)
        c.i32(~(mask << sh) & 0xFFFFFFFF)
        c.op(I32_AND)
        c.get(L_T3)
        c.i32(mask)
        c.op(I32_AND)
        if sh:
            c.i32(sh)
            c.op(I32_SHL)
        c.op(I32_OR)
        c.set(li)

    def rd(self, o, size=None):
        """Pushes an integer operand, zero-extended."""
        c = self.c
        if o.type == X86_OP_REG:
            self.rd_reg(o.reg)
        elif o.type == X86_OP_IMM:
            sz = size or o.size or 4
            c.i32(o.imm & ((1 << (sz * 8)) - 1))
        else:
            off = self.ea(o)
            c.mem(LOAD_U[o.size], off)

    def rd_tea(self, o):
        """Pushes a memory or register destination, using L_TEA for memory."""
        c = self.c
        if o.type == X86_OP_REG:
            self.rd_reg(o.reg)
        else:
            c.get(L_TEA)
            c.mem(LOAD_U[o.size])

    def wr_tea(self, o, local):
        """Writes local to a destination prepared with ea_tea."""
        c = self.c
        if o.type == X86_OP_REG:
            c.get(local)
            self.wr_reg(o.reg)
        else:
            c.get(L_TEA)
            c.get(local)
            c.mem(STORE[o.size])

    def wr_op(self, o, local):
        """Writes local to any destination, computing the address."""
        c = self.c
        if o.type == X86_OP_REG:
            c.get(local)
            self.wr_reg(o.reg)
        else:
            off = self.ea(o)
            c.get(local)
            c.mem(STORE[o.size], off)

    # --- flags ---------------------------------------------------------------
    def norm(self, local, sh):
        self.c.get(local)
        if sh:
            self.c.i32(sh)
            self.c.op(I32_SHL)

    def set_flags(self, kind, bits, live, cin_local=None):
        """Records flags of an ALU result held in TA, TB, TR."""
        if not live:
            return
        c = self.c
        sh = 32 - bits
        if not self.fn.mode_b:
            if kind in ('sub', 'add'):
                self.norm(L_TA, sh)
                c.set(L_FA)
                self.norm(L_TB, sh)
                c.set(L_FB)
            elif kind in ('logic', 'inc', 'dec', 'neg', 'shift'):
                self.norm(L_TR, sh)
                c.set(L_FR)
            return
        if live & FZ:
            self.norm(L_TR, sh)
            c.op(I32_EQZ)
            c.set(L_ZF)
        if live & FS:
            self.norm(L_TR, sh)
            c.i32(0)
            c.op(I32_LT_S)
            c.set(L_SF)
        if live & FP:
            c.get(L_TR)
            c.i32(0xFF)
            c.op(I32_AND, I32_POPCNT)
            c.i32(1)
            c.op(I32_AND, I32_EQZ)
            c.set(L_PF)
        if live & FC:
            if kind in ('sub', 'sbb'):
                self.norm(L_TA, sh)
                self.norm(L_TB, sh)
                c.op(I32_LT_U)
                if kind == 'sbb':
                    self.norm(L_TA, sh)
                    self.norm(L_TB, sh)
                    c.op(I32_EQ)
                    c.get(cin_local)
                    c.op(I32_AND, I32_OR)
                c.set(L_CF)
            elif kind in ('add', 'adc'):
                self.norm(L_TR, sh)
                self.norm(L_TA, sh)
                c.op(I32_LT_U)
                if kind == 'adc':
                    self.norm(L_TR, sh)
                    self.norm(L_TA, sh)
                    c.op(I32_EQ)
                    c.get(cin_local)
                    c.op(I32_AND, I32_OR)
                c.set(L_CF)
            elif kind == 'logic':
                c.i32(0)
                c.set(L_CF)
            elif kind == 'neg':
                self.norm(L_TR, sh)
                c.i32(0)
                c.op(I32_NE)
                c.set(L_CF)
        if live & FO:
            if kind in ('sub', 'sbb'):
                c.get(L_TA)
                c.get(L_TB)
                c.op(I32_XOR)
                c.get(L_TA)
                c.get(L_TR)
                c.op(I32_XOR, I32_AND)
                c.i32(sh)
                c.op(I32_SHL)
                c.i32(0)
                c.op(I32_LT_S)
                c.set(L_OF)
            elif kind in ('add', 'adc'):
                c.get(L_TA)
                c.get(L_TR)
                c.op(I32_XOR)
                c.get(L_TB)
                c.get(L_TR)
                c.op(I32_XOR, I32_AND)
                c.i32(sh)
                c.op(I32_SHL)
                c.i32(0)
                c.op(I32_LT_S)
                c.set(L_OF)
            elif kind == 'logic':
                c.i32(0)
                c.set(L_OF)
            elif kind in ('inc', 'neg'):
                self.norm(L_TR, sh)
                c.i32(INT_MIN)
                c.op(I32_EQ)
                c.set(L_OF)
            elif kind == 'dec':
                self.norm(L_TR, sh)
                c.i32(((1 << (bits - 1)) - 1) << sh)
                c.op(I32_EQ)
                c.set(L_OF)

    def cond(self, cc):
        """Pushes the boolean value of a condition code."""
        if self.fn.mode_b:
            self.cond_b(cc)
        else:
            self.cond_a(cc, self.kind)

    def cond_b(self, cc):
        c = self.c
        if cc == 'o':
            c.get(L_OF)
        elif cc == 'no':
            c.get(L_OF)
            c.op(I32_EQZ)
        elif cc == 'b':
            c.get(L_CF)
        elif cc == 'ae':
            c.get(L_CF)
            c.op(I32_EQZ)
        elif cc == 'e':
            c.get(L_ZF)
        elif cc == 'ne':
            c.get(L_ZF)
            c.op(I32_EQZ)
        elif cc == 'be':
            c.get(L_CF)
            c.get(L_ZF)
            c.op(I32_OR)
        elif cc == 'a':
            c.get(L_CF)
            c.get(L_ZF)
            c.op(I32_OR, I32_EQZ)
        elif cc == 's':
            c.get(L_SF)
        elif cc == 'ns':
            c.get(L_SF)
            c.op(I32_EQZ)
        elif cc == 'p':
            c.get(L_PF)
        elif cc == 'np':
            c.get(L_PF)
            c.op(I32_EQZ)
        elif cc == 'l':
            c.get(L_SF)
            c.get(L_OF)
            c.op(I32_NE)
        elif cc == 'ge':
            c.get(L_SF)
            c.get(L_OF)
            c.op(I32_EQ)
        elif cc == 'le':
            c.get(L_ZF)
            c.get(L_SF)
            c.get(L_OF)
            c.op(I32_NE, I32_OR)
        elif cc == 'g':
            c.get(L_ZF)
            c.get(L_SF)
            c.get(L_OF)
            c.op(I32_NE, I32_OR, I32_EQZ)
        else:
            raise Unsupported('cond ' + cc)

    def cond_a(self, cc, k):
        c = self.c
        if k == 'sub':
            t = {'e': I32_EQ, 'ne': I32_NE, 'l': I32_LT_S, 'ge': I32_GE_S, 'le': I32_LE_S, 'g': I32_GT_S,
                 'b': I32_LT_U, 'ae': I32_GE_U, 'be': I32_LE_U, 'a': I32_GT_U}.get(cc)
            if t:
                c.get(L_FA)
                c.get(L_FB)
                c.op(t)
            elif cc in ('s', 'ns'):
                c.get(L_FA)
                c.get(L_FB)
                c.op(I32_SUB)
                c.i32(0)
                c.op(I32_LT_S if cc == 's' else I32_GE_S)
            elif cc in ('o', 'no'):
                c.get(L_FA)
                c.get(L_FB)
                c.op(I32_XOR)
                c.get(L_FA)
                c.get(L_FA)
                c.get(L_FB)
                c.op(I32_SUB, I32_XOR, I32_AND)
                c.i32(0)
                c.op(I32_LT_S if cc == 'o' else I32_GE_S)
            else:
                raise Unsupported('sub cond ' + cc)
        elif k == 'logic':
            if cc in ('e', 'be'):
                c.get(L_FR)
                c.op(I32_EQZ)
            elif cc in ('ne', 'a'):
                c.get(L_FR)
                c.i32(0)
                c.op(I32_NE)
            elif cc in ('s', 'l'):
                c.get(L_FR)
                c.i32(0)
                c.op(I32_LT_S)
            elif cc in ('ns', 'ge'):
                c.get(L_FR)
                c.i32(0)
                c.op(I32_GE_S)
            elif cc == 'le':
                c.get(L_FR)
                c.i32(0)
                c.op(I32_LE_S)
            elif cc == 'g':
                c.get(L_FR)
                c.i32(0)
                c.op(I32_GT_S)
            elif cc in ('b', 'o'):
                c.i32(0)
            elif cc in ('ae', 'no'):
                c.i32(1)
            else:
                raise Unsupported('logic cond ' + cc)
        elif k == 'add':
            if cc in ('e', 'ne', 's', 'ns'):
                c.get(L_FA)
                c.get(L_FB)
                c.op(I32_ADD)
                c.i32(0)
                c.op({'e': I32_EQ, 'ne': I32_NE, 's': I32_LT_S, 'ns': I32_GE_S}[cc])
            elif cc in ('b', 'ae'):
                c.get(L_FA)
                c.get(L_FB)
                c.op(I32_ADD)
                c.get(L_FA)
                c.op(I32_LT_U if cc == 'b' else I32_GE_U)
            elif cc in ('be', 'a'):
                c.get(L_FA)
                c.get(L_FB)
                c.op(I32_ADD, I32_EQZ)
                c.get(L_FA)
                c.get(L_FB)
                c.op(I32_ADD)
                c.get(L_FA)
                c.op(I32_LT_U, I32_OR)
                if cc == 'a':
                    c.op(I32_EQZ)
            else:
                raise Unsupported('add cond ' + cc)
        elif k in ('inc', 'dec'):
            ov = INT_MIN if k == 'inc' else INT_MAX
            if cc in ('e', 'ne', 's', 'ns'):
                c.get(L_FR)
                c.i32(0)
                c.op({'e': I32_EQ, 'ne': I32_NE, 's': I32_LT_S, 'ns': I32_GE_S}[cc])
            else:
                c.get(L_FR)
                c.i32(0)
                c.op(I32_LT_S)
                c.get(L_FR)
                c.i32(ov)
                c.op(I32_EQ, I32_NE)
                if cc == 'ge':
                    c.op(I32_EQZ)
                elif cc in ('le', 'g'):
                    c.get(L_FR)
                    c.op(I32_EQZ, I32_OR)
                    if cc == 'g':
                        c.op(I32_EQZ)
        elif k == 'neg':
            if cc in ('e', 'ae'):
                c.get(L_FR)
                c.op(I32_EQZ)
            elif cc in ('ne', 'b'):
                c.get(L_FR)
                c.i32(0)
                c.op(I32_NE)
            elif cc == 's':
                c.get(L_FR)
                c.i32(0)
                c.op(I32_LT_S)
            elif cc == 'ns':
                c.get(L_FR)
                c.i32(0)
                c.op(I32_GE_S)
            else:
                raise Unsupported('neg cond ' + cc)
        elif k == 'shift':
            c.get(L_FR)
            c.i32(0)
            c.op({'e': I32_EQ, 'ne': I32_NE, 's': I32_LT_S, 'ns': I32_GE_S}[cc])
        else:
            raise Unsupported('cond %s on kind %s at %08x' % (cc, k, self.fn.addr))

    # --- calls ---------------------------------------------------------------
    def push_ret(self, i, target=None):
        c = self.c
        c.get(L_ESP)
        c.i32(4)
        c.op(I32_SUB)
        c.set(L_ESP)
        if self.rec.debug_ret or target in self.rec.ret_store_targets or self.rec.ret_store_from(i.addr):
            c.get(L_ESP)
            c.i32(i.next)
            c.mem(I32_STORE)

    def call_args(self):
        c = self.c
        c.get(L_ESP)
        c.get(L_EAX)
        c.get(L_ECX)
        c.get(L_EDX)

    def icall_target(self, local):
        """Pushes the table index for a code address held in local."""
        c = self.c
        if self.rec.debug_ret:
            c.get(local)
            c.gset(G_A)
        c.get(local)
        c.i32(MAP_LO)
        c.op(I32_SUB)
        c.i32(1)
        c.op(I32_SHL)
        c.i32(CODE_MAP)
        c.op(I32_ADD)
        c.mem(I32_LOAD16_U)

    def edx_live(self, block, index):
        """Is edx read before it is written, on any path after instruction index of block?"""
        work = [(block, index)]
        seen = set()
        while work:
            b, k = work.pop()
            stop = False
            for i in b.insns[k:]:
                if i.mn == 'call':
                    stop = True
                    break
                if any(r in EDX_REGS for r in i.rd):
                    return True
                if X86_REG_EDX in i.wr:
                    stop = True
                    break
            if stop:
                continue
            if b.kind == 'ret':
                if self.writes_edx:
                    return True
                continue
            for s in b.succs:
                if s not in seen:
                    seen.add(s)
                    work.append((self.fn.blocks[s], 0))
        return False

    def after_call(self, block, index, fpu):
        c = self.c
        c.set(L_EAX)
        c.set(L_ESP)
        if self.edx_live(block, index + 1):
            c.gget(G_EDX)
            c.set(L_EDX)
        cin, cout = fpu
        if cout:
            if self.d > 7 or self.d < 0:
                raise Unsupported('x87 depth %d after call in %s' % (self.d, self.fn.name))
            c.gget(G_ST0)
            c.set(L_F0 + self.d)
            self.d += 1

    def fpu_call_in(self, fpu):
        """Passes x87 stack arguments of a call."""
        cin, cout = fpu
        c = self.c
        if cin >= 1:
            c.get(L_F0 + self.d - 1)
            c.gset(G_ST0)
        if cin >= 2:
            c.get(L_F0 + self.d - 2)
            c.gset(G_ST1)
        if cin > 2:
            raise Unsupported('call with %d x87 args at %08x' % (cin, self.fn.addr))
        self.d -= cin

    def pass_saved(self, target):
        """Passes callee-saved registers to a callee that reads them as inputs."""
        f = self.rec.funcs.get(target)
        if f is not None and f.uses:
            for li in sorted(f.uses):
                self.c.get(li)
                self.c.gset(G_OF_LOCAL[li])

    def x_call(self, i, block, index):
        c = self.c
        o = i.ops[0]
        fpu = self.rec.call_fpu(self.fn, i)
        if o.type == X86_OP_IMM:
            t = o.imm & 0xFFFFFFFF
            r = self.rec.replacements.get(t)
            if r is not None and r.get('inline'):
                self.fpu_call_in(fpu)
                r['inline'](self, i, block, index)
                cin, cout = fpu
                if cout:
                    c.gget(G_ST0)
                    c.set(L_F0 + self.d)
                    self.d += 1
                return
            idx = self.ctx.func_index_of(t)
            if idx is None:
                raise Unsupported('call to unknown %08x from %08x' % (t, self.fn.addr))
            self.fpu_call_in(fpu)
            self.push_ret(i, t)
            self.pass_saved(t)
            self.call_args()
            c.call(idx)
            self.after_call(block, index, fpu)
            return
        if o.type == X86_OP_MEM and o.base == 0 and o.index == 0 and (o.disp & 0xFFFFFFFF) in self.rec.img.iat:
            idx = self.ctx.import_func_index((o.disp & 0xFFFFFFFF))
            self.push_ret(i)
            self.call_args()
            c.call(idx)
            self.after_call(block, index, fpu)
            return
        self.rd(o, 4)
        c.set(L_T2)
        self.fpu_call_in(fpu)
        self.push_ret(i)
        self.call_args()
        self.icall_target(L_T2)
        c.call_indirect(self.ctx.type0)
        self.after_call(block, index, fpu)

    def x_tail(self, block):
        """Terminates a block with a tail call and returns the callee's results."""
        c = self.c
        i = block.tail_insn
        if block.kind == 'tail' and (self.rec.replacements.get(block.target) or {}).get('inline'):
            r = self.rec.replacements[block.target]
            self.fpu_call_in(r.get('fpu', (0, 0)))
            r['inline'](self, i, block, len(block.insns) - 1)
            if r.get('fpu', (0, 0))[1]:
                raise Unsupported('tail to a float-returning inline helper in %s' % self.fn.name)
            if self.writes_edx:
                c.get(L_EDX)
                c.gset(G_EDX)
            c.get(L_ESP)
            c.i32(4)
            c.op(I32_ADD)
            c.get(L_EAX)
            c.op(RETURN)
            return
        if block.kind == 'tail':
            t = block.target
            r = self.rec.replacements.get(t)
            if r is not None and not r.get('wrap'):
                fpu = r.get('fpu', (0, 0))
            else:
                f = self.rec.funcs.get(t)
                fpu = (f.fpu_in, f.fpu_out) if f else (0, 0)
            self.fpu_call_in(fpu)
            if self.fn.fpu_out and not fpu[1]:
                c.get(L_F0 + self.d - 1)
                c.gset(G_ST0)
            idx = self.ctx.func_index_of(t)
            if idx is None:
                raise Unsupported('tail to unknown %08x from %08x' % (t, self.fn.addr))
            self.pass_saved(t)
            self.call_args()
            c.call(idx)
        elif block.kind == 'tailmem':
            addr = block.target
            if addr in self.rec.img.iat:
                self.call_args()
                c.call(self.ctx.import_func_index(addr))
            else:
                c.i32(addr)
                c.mem(I32_LOAD)
                c.set(L_T2)
                self.call_args()
                self.icall_target(L_T2)
                c.call_indirect(self.ctx.type0)
        else:
            self.rd(i.ops[0], 4)
            c.set(L_T2)
            self.call_args()
            self.icall_target(L_T2)
            c.call_indirect(self.ctx.type0)
        c.op(RETURN)

    def x_ret(self, block):
        c = self.c
        i = block.tail_insn
        if self.writes_edx:
            c.get(L_EDX)
            c.gset(G_EDX)
        if self.fn.fpu_out >= 1:
            c.get(L_F0 + self.d - 1)
            c.gset(G_ST0)
        pop = 4
        if i.ops:
            pop += i.ops[0].imm & 0xFFFF
        c.get(L_ESP)
        c.i32(pop)
        c.op(I32_ADD)
        c.get(L_EAX)
        c.op(RETURN)

    # --- integer instructions --------------------------------------------------
    def alu(self, i, opcode, kind, write, live):
        c = self.c
        d, s = i.ops
        bits = d.size * 8
        if d.type == X86_OP_REG and bits == 32 and not live:
            if not write:
                return
            if opcode == I32_XOR and s.type == X86_OP_REG and s.reg == d.reg:
                c.i32(0)
                c.set(REG[d.reg][0])
                return
            c.get(REG[d.reg][0])
            self.rd(s, d.size)
            c.op(opcode)
            c.set(REG[d.reg][0])
            return
        if d.type == X86_OP_MEM:
            self.ea_tea(d)
        self.rd_tea(d)
        c.set(L_TA)
        self.rd(s, d.size)
        c.set(L_TB)
        c.get(L_TA)
        c.get(L_TB)
        c.op(opcode)
        c.set(L_TR)
        if write:
            self.wr_tea(d, L_TR)
        self.set_flags(kind, bits, live)

    def adc_sbb(self, i, is_sbb, live):
        c = self.c
        d, s = i.ops
        bits = d.size * 8
        if d.type == X86_OP_MEM:
            self.ea_tea(d)
        self.cond('b')
        c.set(L_T2)
        self.rd_tea(d)
        c.set(L_TA)
        self.rd(s, d.size)
        c.set(L_TB)
        c.get(L_TA)
        c.get(L_TB)
        c.op(I32_SUB if is_sbb else I32_ADD)
        c.get(L_T2)
        c.op(I32_SUB if is_sbb else I32_ADD)
        c.set(L_TR)
        self.wr_tea(d, L_TR)
        self.set_flags('sbb' if is_sbb else 'adc', bits, live, L_T2)

    def incdec(self, i, is_inc, live):
        c = self.c
        d = i.ops[0]
        bits = d.size * 8
        if d.type == X86_OP_REG and bits == 32 and not live:
            li = REG[d.reg][0]
            c.get(li)
            c.i32(1)
            c.op(I32_ADD if is_inc else I32_SUB)
            c.set(li)
            return
        if d.type == X86_OP_MEM:
            self.ea_tea(d)
        self.rd_tea(d)
        c.i32(1)
        c.op(I32_ADD if is_inc else I32_SUB)
        c.set(L_TR)
        self.wr_tea(d, L_TR)
        self.set_flags('inc' if is_inc else 'dec', bits, live)

    def shift(self, i, mn, live):
        c = self.c
        d = i.ops[0]
        bits = d.size * 8
        cnt = i.ops[1] if len(i.ops) > 1 else None
        var = cnt is not None and cnt.type != X86_OP_IMM
        n = 1
        if cnt is not None and cnt.type == X86_OP_IMM:
            n = cnt.imm & 31
            if n == 0:
                return
        if d.type == X86_OP_MEM:
            self.ea_tea(d)
        self.rd_tea(d)
        if mn == 'sar' and bits < 32:
            c.op(I32_EXTEND8_S if bits == 8 else I32_EXTEND16_S)
        c.set(L_TA)
        if var:
            self.rd_reg(X86_REG_CL)
            c.i32(31)
            c.op(I32_AND)
            c.set(L_T2)
        c.get(L_TA)
        if var:
            c.get(L_T2)
        else:
            c.i32(n)
        c.op({'shl': I32_SHL, 'sal': I32_SHL, 'shr': I32_SHR_U, 'sar': I32_SHR_S}[mn])
        c.set(L_TR)
        self.wr_tea(d, L_TR)
        if not live:
            return
        if not self.fn.mode_b:
            if var:
                raise Unsupported('variable shift flags in mode A')
            self.set_flags('shift', bits, live)
            return
        if var:
            c.get(L_T2)
            c.if_()
        sh = 32 - bits
        if live & FZ:
            self.norm(L_TR, sh)
            c.op(I32_EQZ)
            c.set(L_ZF)
        if live & FS:
            self.norm(L_TR, sh)
            c.i32(0)
            c.op(I32_LT_S)
            c.set(L_SF)
        if live & FP:
            c.get(L_TR)
            c.i32(0xFF)
            c.op(I32_AND, I32_POPCNT)
            c.i32(1)
            c.op(I32_AND, I32_EQZ)
            c.set(L_PF)
        if live & FC:
            c.get(L_TA)
            if mn in ('shl', 'sal'):
                c.i32(bits)
                if var:
                    c.get(L_T2)
                else:
                    c.i32(n)
                c.op(I32_SUB)
            else:
                if var:
                    c.get(L_T2)
                else:
                    c.i32(n)
                c.i32(1)
                c.op(I32_SUB)
            c.op(I32_SHR_U)
            c.i32(1)
            c.op(I32_AND)
            c.set(L_CF)
        if live & FO:
            if mn in ('shl', 'sal'):
                self.norm(L_TR, sh)
                self.norm(L_TA, sh)
                c.op(I32_XOR)
                c.i32(31)
                c.op(I32_SHR_U)
            elif mn == 'shr':
                self.norm(L_TA, sh)
                c.i32(31)
                c.op(I32_SHR_U)
            else:
                c.i32(0)
            c.set(L_OF)
        if var:
            c.end()

    def rot(self, i, mn, live):
        c = self.c
        d = i.ops[0]
        bits = d.size * 8
        cnt = i.ops[1] if len(i.ops) > 1 else None
        if d.type == X86_OP_MEM:
            self.ea_tea(d)
        if mn in ('rcl', 'rcr'):
            if not (cnt is None or (cnt.type == X86_OP_IMM and cnt.imm == 1)):
                raise Unsupported('rcl/rcr count at %08x' % i.addr)
            if bits != 32:
                raise Unsupported('rcl/rcr size at %08x' % i.addr)
            self.rd_tea(d)
            c.set(L_TA)
            if mn == 'rcr':
                c.get(L_TA)
                c.i32(1)
                c.op(I32_SHR_U)
                c.get(L_CF)
                c.i32(31)
                c.op(I32_SHL, I32_OR)
                c.set(L_TR)
                c.get(L_TA)
                c.i32(1)
                c.op(I32_AND)
                c.set(L_CF)
            else:
                c.get(L_TA)
                c.i32(1)
                c.op(I32_SHL)
                c.get(L_CF)
                c.op(I32_OR)
                c.set(L_TR)
                c.get(L_TA)
                c.i32(31)
                c.op(I32_SHR_U)
                c.set(L_CF)
            self.wr_tea(d, L_TR)
            return
        self.rd_tea(d)
        c.set(L_TA)
        if bits == 32:
            c.get(L_TA)
            self.rd(cnt, 1)
            c.op(I32_ROTL if mn == 'rol' else I32_ROTR)
            c.set(L_TR)
        else:
            # Narrow rotates: rotate a value repeated across 32 bits.
            c.get(L_TA)
            if bits == 8:
                c.i32(0x01010101)
            else:
                c.i32(0x00010001)
            c.op(I32_MUL)
            self.rd(cnt, 1)
            c.i32(bits - 1)
            c.op(I32_AND)
            c.op(I32_ROTL if mn == 'rol' else I32_ROTR)
            c.set(L_TR)
        self.wr_tea(d, L_TR)
        if live & FC and self.fn.mode_b:
            if mn == 'rol':
                c.get(L_TR)
                c.i32(1)
                c.op(I32_AND)
            else:
                c.get(L_TR)
                c.i32(bits - 1)
                c.op(I32_SHR_U)
                c.i32(1)
                c.op(I32_AND)
            c.set(L_CF)

    def mul_div(self, i, mn, live):
        c = self.c
        ops = i.ops
        if mn == 'imul' and len(ops) >= 2:
            d = ops[0]
            s = ops[1]
            bits = d.size * 8
            if len(ops) == 3:
                self.rd(s, d.size)
                if bits == 16:
                    c.op(I32_EXTEND16_S)
                c.i32(ops[2].imm)
            else:
                self.rd_reg(d.reg)
                if bits == 16:
                    c.op(I32_EXTEND16_S)
                self.rd(s, d.size)
                if bits == 16:
                    c.op(I32_EXTEND16_S)
            if live and (live & (FC | FO)):
                c.set(L_TB)
                c.set(L_TA)
                c.get(L_TA)
                c.op(I64_EXTEND_I32_S)
                c.get(L_TB)
                c.op(I64_EXTEND_I32_S, I64_MUL)
                c.set(L_IA)
                c.get(L_IA)
                c.op(I32_WRAP_I64)
                c.set(L_TR)
                c.get(L_IA)
                c.get(L_TR)
                c.op(I64_EXTEND_I32_S, I64_NE)
                c.set(L_CF)
                c.get(L_CF)
                c.set(L_OF)
                c.get(L_TR)
            else:
                c.op(I32_MUL)
            self.wr_reg(d.reg)
            return
        o = ops[0]
        bits = o.size * 8
        if bits == 32:
            self.rd(o, 4)
            if mn in ('imul', 'idiv'):
                c.op(I64_EXTEND_I32_S)
            else:
                c.op(I64_EXTEND_I32_U)
            c.set(L_IB)
            if mn in ('mul', 'imul'):
                c.get(L_EAX)
                c.op(I64_EXTEND_I32_S if mn == 'imul' else I64_EXTEND_I32_U)
                c.get(L_IB)
                c.op(I64_MUL)
                c.set(L_IA)
                c.get(L_IA)
                c.op(I32_WRAP_I64)
                c.set(L_EAX)
                c.get(L_IA)
                c.i64(32)
                c.op(I64_SHR_U, I32_WRAP_I64)
                c.set(L_EDX)
                if live & (FC | FO) and self.fn.mode_b:
                    if mn == 'mul':
                        c.get(L_EDX)
                        c.i32(0)
                        c.op(I32_NE)
                    else:
                        c.get(L_IA)
                        c.get(L_EAX)
                        c.op(I64_EXTEND_I32_S, I64_NE)
                    c.set(L_CF)
                    c.get(L_CF)
                    c.set(L_OF)
                return
            # edx:eax / operand
            c.get(L_EDX)
            c.op(I64_EXTEND_I32_U)
            c.i64(32)
            c.op(I64_SHL)
            c.get(L_EAX)
            c.op(I64_EXTEND_I32_U, I64_OR)
            c.set(L_IA)
            c.get(L_IA)
            c.get(L_IB)
            c.op(I64_DIV_S if mn == 'idiv' else I64_DIV_U, I32_WRAP_I64)
            c.get(L_IA)
            c.get(L_IB)
            c.op(I64_REM_S if mn == 'idiv' else I64_REM_U, I32_WRAP_I64)
            c.set(L_EDX)
            c.set(L_EAX)
            return
        if bits == 16 and mn in ('div', 'idiv', 'mul', 'imul'):
            self.rd(o, 2)
            if mn in ('idiv', 'imul'):
                c.op(I32_EXTEND16_S)
            c.set(L_TB)
            if mn in ('mul', 'imul'):
                self.rd_reg(REG_AX)
                if mn == 'imul':
                    c.op(I32_EXTEND16_S)
                c.get(L_TB)
                c.op(I32_MUL)
                c.set(L_TR)
                c.get(L_TR)
                self.wr_reg(REG_AX)
                c.get(L_TR)
                c.i32(16)
                c.op(I32_SHR_U)
                self.wr_reg(REG_DX)
                return
            self.rd_reg(REG_DX)
            c.i32(16)
            c.op(I32_SHL)
            self.rd_reg(REG_AX)
            c.op(I32_OR)
            c.set(L_TA)
            c.get(L_TA)
            c.get(L_TB)
            c.op(I32_DIV_S if mn == 'idiv' else I32_DIV_U)
            self.wr_reg(REG_AX)
            c.get(L_TA)
            c.get(L_TB)
            c.op(I32_REM_S if mn == 'idiv' else I32_REM_U)
            self.wr_reg(REG_DX)
            return
        if bits == 8 and mn in ('mul', 'imul'):
            self.rd(o, 1)
            if mn == 'imul':
                c.op(I32_EXTEND8_S)
            self.rd_reg(REG_AL)
            if mn == 'imul':
                c.op(I32_EXTEND8_S)
            c.op(I32_MUL)
            self.wr_reg(REG_AX)
            return
        if bits == 8:
            self.rd(o, 1)
            if mn == 'idiv':
                c.op(I32_EXTEND8_S)
            c.set(L_TB)
            self.rd_reg(REG_AX)
            if mn == 'idiv':
                c.op(I32_EXTEND16_S)
            c.set(L_TA)
            c.get(L_TA)
            c.get(L_TB)
            c.op(I32_DIV_S if mn == 'idiv' else I32_DIV_U)
            c.i32(0xFF)
            c.op(I32_AND)
            c.get(L_TA)
            c.get(L_TB)
            c.op(I32_REM_S if mn == 'idiv' else I32_REM_U)
            c.i32(0xFF)
            c.op(I32_AND)
            c.i32(8)
            c.op(I32_SHL, I32_OR)
            self.wr_reg(REG_AX)
            return
        raise Unsupported('%s size %d at %08x' % (mn, bits, i.addr))

    # --- string instructions ---------------------------------------------------
    def bump(self, li, n):
        c = self.c
        c.get(li)
        c.i32(n)
        c.op(I32_ADD)
        c.set(li)

    def x_string(self, i, mn, live):
        c = self.c
        base = mn.split()[-1]
        rep = mn.split()[0] if ' ' in mn else None
        width = {'b': 1, 'w': 2, 'd': 4}[base[-1]]
        kind = base[:-1]
        store = STORE[width]
        load = LOAD_U[width]
        if kind == 'movs':
            if rep is None:
                c.get(L_EDI)
                c.get(L_ESI)
                c.mem(load)
                c.mem(store)
                self.bump(L_ESI, width)
                self.bump(L_EDI, width)
                return
            if self.ecx_known is not None and self.ecx_known * width <= 128:
                n = self.ecx_known * width
                off = 0
                while n - off >= 8:
                    c.get(L_EDI)
                    c.get(L_ESI)
                    c.mem(I64_LOAD, off)
                    c.mem(I64_STORE, off)
                    off += 8
                while n - off >= 4:
                    c.get(L_EDI)
                    c.get(L_ESI)
                    c.mem(I32_LOAD, off)
                    c.mem(I32_STORE, off)
                    off += 4
                while n - off >= 1:
                    c.get(L_EDI)
                    c.get(L_ESI)
                    c.mem(I32_LOAD8_U, off)
                    c.mem(I32_STORE8, off)
                    off += 1
                self.bump(L_ESI, n)
                self.bump(L_EDI, n)
                c.i32(0)
                c.set(L_ECX)
                return
            c.get(L_ECX)
            c.i32(LOG2[width])
            c.op(I32_SHL)
            c.set(L_T2)
            c.get(L_EDI)
            c.get(L_ESI)
            c.get(L_T2)
            c.call(self.ctx.rt['movs'])
            c.get(L_ESI)
            c.get(L_T2)
            c.op(I32_ADD)
            c.set(L_ESI)
            c.get(L_EDI)
            c.get(L_T2)
            c.op(I32_ADD)
            c.set(L_EDI)
            c.i32(0)
            c.set(L_ECX)
            return
        if kind == 'stos':
            if rep is None:
                c.get(L_EDI)
                c.get(L_EAX)
                c.mem(store)
                self.bump(L_EDI, width)
                return
            if self.ecx_known is not None and self.ecx_known * width <= 64 and width == 4:
                n = self.ecx_known
                for k in range(n):
                    c.get(L_EDI)
                    c.get(L_EAX)
                    c.mem(I32_STORE, k * 4)
                self.bump(L_EDI, n * 4)
                c.i32(0)
                c.set(L_ECX)
                return
            c.get(L_EDI)
            c.get(L_EAX)
            c.get(L_ECX)
            c.call(self.ctx.rt['stos' + str(width)])
            c.get(L_EDI)
            c.get(L_ECX)
            c.i32(LOG2[width])
            c.op(I32_SHL, I32_ADD)
            c.set(L_EDI)
            c.i32(0)
            c.set(L_ECX)
            return
        if kind == 'scas':
            if rep == 'repne' and width == 1:
                c.get(L_ECX)
                c.set(L_T2)
                c.get(L_EDI)
                c.get(L_EAX)
                c.i32(0xFF)
                c.op(I32_AND)
                c.get(L_ECX)
                c.call(self.ctx.rt['repne_scasb'])
                c.set(L_ECX)
                c.get(L_EDI)
                c.get(L_T2)
                c.get(L_ECX)
                c.op(I32_SUB, I32_ADD)
                c.set(L_EDI)
                if live and self.fn.mode_b:
                    c.get(L_T2)
                    c.if_()
                    self.flags_from_ab(live)
                    c.end()
                return
            if rep is None and width == 1:
                c.get(L_EAX)
                c.i32(24)
                c.op(I32_SHL)
                c.gset(G_A)
                c.get(L_EDI)
                c.mem(I32_LOAD8_U)
                c.i32(24)
                c.op(I32_SHL)
                c.gset(G_B)
                self.bump(L_EDI, 1)
                if live and self.fn.mode_b:
                    self.flags_from_ab(live)
                return
            raise Unsupported('%s at %08x' % (mn, i.addr))
        if kind == 'cmps':
            if rep == 'repe' and width in (1, 4):
                c.get(L_ECX)
                c.set(L_T2)
                c.get(L_ESI)
                c.get(L_EDI)
                c.get(L_ECX)
                c.call(self.ctx.rt['repe_cmpsb' if width == 1 else 'repe_cmpsd'])
                c.set(L_ECX)
                c.get(L_ESI)
                c.get(L_T2)
                c.get(L_ECX)
                c.op(I32_SUB)
                c.i32(LOG2[width])
                c.op(I32_SHL, I32_ADD)
                c.set(L_ESI)
                c.get(L_EDI)
                c.get(L_T2)
                c.get(L_ECX)
                c.op(I32_SUB)
                c.i32(LOG2[width])
                c.op(I32_SHL, I32_ADD)
                c.set(L_EDI)
                if live and self.fn.mode_b:
                    c.get(L_T2)
                    c.if_()
                    self.flags_from_ab(live)
                    c.end()
                return
            if rep is None:
                c.get(L_ESI)
                c.mem(load)
                c.i32(32 - width * 8)
                c.op(I32_SHL)
                c.gset(G_A)
                c.get(L_EDI)
                c.mem(load)
                c.i32(32 - width * 8)
                c.op(I32_SHL)
                c.gset(G_B)
                self.bump(L_ESI, width)
                self.bump(L_EDI, width)
                if live and self.fn.mode_b:
                    self.flags_from_ab(live)
                return
        raise Unsupported('%s at %08x' % (mn, i.addr))

    def flags_from_ab(self, live):
        c = self.c
        if live & FZ:
            c.gget(G_A)
            c.gget(G_B)
            c.op(I32_EQ)
            c.set(L_ZF)
        if live & FC:
            c.gget(G_A)
            c.gget(G_B)
            c.op(I32_LT_U)
            c.set(L_CF)
        if live & FS:
            c.gget(G_A)
            c.gget(G_B)
            c.op(I32_SUB)
            c.i32(0)
            c.op(I32_LT_S)
            c.set(L_SF)
        if live & FO:
            c.gget(G_A)
            c.gget(G_B)
            c.op(I32_XOR)
            c.gget(G_A)
            c.gget(G_A)
            c.gget(G_B)
            c.op(I32_SUB, I32_XOR, I32_AND)
            c.i32(0)
            c.op(I32_LT_S)
            c.set(L_OF)
        if live & FP:
            c.i32(0)
            c.set(L_PF)

    # --- x87 -------------------------------------------------------------------
    def st(self, k):
        v = self.d - 1 - k
        if v < 0 or v > 7:
            raise Unsupported('x87 slot %d (depth %d, st%d) in %s' % (v, self.d, k, self.fn.name))
        return L_F0 + v

    def rnd(self):
        """Rounds the f64 on the stack to the precision-control setting in use."""
        if self.rec.fpu_pc == 24:
            self.c.op(F32_DEMOTE_F64, F64_PROMOTE_F32)

    def fmem(self, o):
        """Pushes a float operand from memory as f64."""
        c = self.c
        off = self.ea(o)
        if o.size == 4:
            c.mem(F32_LOAD, off)
            c.op(F64_PROMOTE_F32)
        elif o.size == 8:
            c.mem(F64_LOAD, off)
        else:
            raise Unsupported('float size %d at %08x' % (o.size, self.fn.addr))

    def imem(self, o):
        c = self.c
        off = self.ea(o)
        if o.size == 2:
            c.mem(I32_LOAD16_S, off)
            c.op(F64_CONVERT_I32_S)
        elif o.size == 4:
            c.mem(I32_LOAD, off)
            c.op(F64_CONVERT_I32_S)
        elif o.size == 8:
            c.mem(I64_LOAD, off)
            c.op(F64_CONVERT_I64_S)
        else:
            raise Unsupported('int size %d at %08x' % (o.size, self.fn.addr))

    def x87(self, i, live):
        c = self.c
        f = x87_form(i)
        mn = i.mn
        rt = self.ctx.rt
        if f is not None:
            name, s = f
            if name is None:
                raise Unsupported('x87 %s at %08x' % (i.text, i.addr))
            arith = {'add': F64_ADD, 'mul': F64_MUL, 'sub': F64_SUB, 'div': F64_DIV}
            if name in ('fadd0', 'fmul0', 'fsub0', 'fdiv0'):
                c.get(self.st(0))
                c.get(self.st(s))
                c.op(arith[name[1:4]])
                self.rnd()
                c.set(self.st(0))
            elif name in ('fsubr0', 'fdivr0'):
                c.get(self.st(s))
                c.get(self.st(0))
                c.op(arith[name[1:4]])
                self.rnd()
                c.set(self.st(0))
            elif name in ('faddi', 'fmuli', 'fsubi', 'fdivi', 'faddp', 'fmulp', 'fsubp', 'fdivp'):
                c.get(self.st(s))
                c.get(self.st(0))
                c.op(arith[name[1:4]])
                self.rnd()
                c.set(self.st(s))
                if name.endswith('p'):
                    self.d -= 1
            elif name in ('fsubri', 'fdivri', 'fsubrp', 'fdivrp'):
                c.get(self.st(0))
                c.get(self.st(s))
                c.op(arith[name[1:4]])
                self.rnd()
                c.set(self.st(s))
                if name.endswith('p'):
                    self.d -= 1
            elif name in ('fcom', 'fcomp'):
                c.get(self.st(0))
                c.get(self.st(s))
                c.call(rt['fcom'])
                c.set(L_FSW)
                if name == 'fcomp':
                    self.d -= 1
            elif name == 'fcompp':
                c.get(self.st(0))
                c.get(self.st(1))
                c.call(rt['fcom'])
                c.set(L_FSW)
                self.d -= 2
            elif name == 'ftst':
                c.get(self.st(0))
                c.f64(0.0)
                c.call(rt['fcom'])
                c.set(L_FSW)
            elif name == 'fxam':
                c.get(self.st(0))
                c.call(rt['fxam'])
                c.set(L_FSW)
            elif name == 'fld':
                c.get(self.st(s))
                self.d += 1
                c.set(self.st(0))
            elif name == 'fxch':
                c.get(self.st(0))
                c.get(self.st(s))
                c.set(self.st(0))
                c.set(self.st(s))
            elif name == 'fst':
                c.get(self.st(0))
                c.set(self.st(s))
            elif name == 'fstp':
                c.get(self.st(0))
                c.set(self.st(s))
                self.d -= 1
            elif name in ('fld1', 'fldz', 'fldpi', 'fldln2', 'fldlg2', 'fldl2e', 'fldl2t'):
                v = {'fld1': 1.0, 'fldz': 0.0, 'fldpi': 3.141592653589793, 'fldln2': 0.6931471805599453,
                     'fldlg2': 0.3010299956639812, 'fldl2e': 1.4426950408889634, 'fldl2t': 3.3219280948873626}[name]
                c.f64(v)
                self.d += 1
                c.set(self.st(0))
            elif name == 'fchs':
                c.get(self.st(0))
                c.op(F64_NEG)
                c.set(self.st(0))
            elif name == 'fabs':
                c.get(self.st(0))
                c.op(F64_ABS)
                c.set(self.st(0))
            elif name == 'fsqrt':
                c.get(self.st(0))
                c.op(F64_SQRT)
                self.rnd()
                c.set(self.st(0))
            elif name == 'fsin':
                c.get(self.st(0))
                c.call(rt['sin'])
                c.set(self.st(0))
                c.i32(0)
                c.set(L_FSW)
            elif name == 'fcos':
                c.get(self.st(0))
                c.call(rt['cos'])
                c.set(self.st(0))
                c.i32(0)
                c.set(L_FSW)
            elif name == 'fptan':
                c.get(self.st(0))
                c.call(rt['tan'])
                c.set(self.st(0))
                c.f64(1.0)
                self.d += 1
                c.set(self.st(0))
                c.i32(0)
                c.set(L_FSW)
            elif name == 'fsincos':
                c.get(self.st(0))
                c.call(rt['sin'])
                c.get(self.st(0))
                c.call(rt['cos'])
                self.d += 1
                c.set(self.st(0))
                c.set(self.st(1))
                c.i32(0)
                c.set(L_FSW)
            elif name == 'fpatan':
                c.get(self.st(1))
                c.get(self.st(0))
                c.call(rt['atan2'])
                c.set(self.st(1))
                self.d -= 1
            elif name == 'fyl2x':
                c.get(self.st(1))
                c.get(self.st(0))
                c.call(rt['log2'])
                c.op(F64_MUL)
                c.set(self.st(1))
                self.d -= 1
            elif name == 'f2xm1':
                c.get(self.st(0))
                c.call(rt['pow2m1'])
                c.set(self.st(0))
            elif name == 'fscale':
                c.get(self.st(0))
                c.get(self.st(1))
                c.op(F64_TRUNC)
                c.call(rt['pow2'])
                c.op(F64_MUL)
                c.set(self.st(0))
            elif name == 'frndint':
                c.get(self.st(0))
                c.call(rt['frndint'])
                c.set(self.st(0))
            elif name in ('fprem', 'fprem1'):
                c.get(self.st(0))
                c.get(self.st(1))
                c.call(rt['fmod' if name == 'fprem' else 'frem'])
                c.set(self.st(0))
                c.i32(0)
                c.set(L_FSW)
            elif name == 'fnstsw_ax':
                c.get(L_EAX)
                c.i32(0xFFFF0000)
                c.op(I32_AND)
                c.get(L_FSW)
                c.op(I32_OR)
                c.set(L_EAX)
            elif name == 'fninit':
                c.i32(0x37F)
                c.gset(G_CW)
            elif name in ('fnclex', 'fnop', 'ffree'):
                pass
            else:
                raise Unsupported('x87 %s at %08x' % (name, i.addr))
            return
        o = i.ops[0] if i.ops else None
        if mn == 'fld':
            if o.size == 10:
                self.ea_full(o)
                c.call(rt['fld80'])
            else:
                self.fmem(o)
            self.d += 1
            c.set(self.st(0))
        elif mn == 'fild':
            self.imem(o)
            self.d += 1
            c.set(self.st(0))
        elif mn in ('fst', 'fstp'):
            if o.size == 10:
                self.ea_full(o)
                c.get(self.st(0))
                c.call(rt['fst80'])
            else:
                off = self.ea(o)
                c.get(self.st(0))
                if o.size == 4:
                    c.op(F32_DEMOTE_F64)
                    c.mem(F32_STORE, off)
                else:
                    c.mem(F64_STORE, off)
            if mn == 'fstp':
                self.d -= 1
        elif mn in ('fist', 'fistp'):
            off = self.ea(o)
            c.get(self.st(0))
            if o.size == 2:
                c.call(rt['fist32'])
                c.mem(I32_STORE16, off)
            elif o.size == 4:
                c.call(rt['fist32'])
                c.mem(I32_STORE, off)
            else:
                c.call(rt['fist64'])
                c.mem(I64_STORE, off)
            if mn == 'fistp':
                self.d -= 1
        elif mn in ('fadd', 'fmul', 'fsub', 'fdiv'):
            c.get(self.st(0))
            self.fmem(o)
            c.op({'fadd': F64_ADD, 'fmul': F64_MUL, 'fsub': F64_SUB, 'fdiv': F64_DIV}[mn])
            self.rnd()
            c.set(self.st(0))
        elif mn in ('fsubr', 'fdivr'):
            self.fmem(o)
            c.get(self.st(0))
            c.op(F64_SUB if mn == 'fsubr' else F64_DIV)
            self.rnd()
            c.set(self.st(0))
        elif mn in ('fiadd', 'fimul', 'fisub', 'fidiv'):
            c.get(self.st(0))
            self.imem(o)
            c.op({'fiadd': F64_ADD, 'fimul': F64_MUL, 'fisub': F64_SUB, 'fidiv': F64_DIV}[mn])
            self.rnd()
            c.set(self.st(0))
        elif mn in ('fisubr', 'fidivr'):
            self.imem(o)
            c.get(self.st(0))
            c.op(F64_SUB if mn == 'fisubr' else F64_DIV)
            self.rnd()
            c.set(self.st(0))
        elif mn in ('fcom', 'fcomp'):
            c.get(self.st(0))
            self.fmem(o)
            c.call(rt['fcom'])
            c.set(L_FSW)
            if mn == 'fcomp':
                self.d -= 1
        elif mn == 'fnstcw':
            off = self.ea(o)
            c.gget(G_CW)
            c.mem(I32_STORE16, off)
        elif mn == 'fldcw':
            off = self.ea(o)
            c.mem(I32_LOAD16_U, off)
            c.gset(G_CW)
        elif mn == 'fnstsw':
            off = self.ea(o)
            c.get(L_FSW)
            c.mem(I32_STORE16, off)
        elif mn in ('fnclex', 'wait'):
            pass
        elif mn in ('fnstenv', 'fnsave', 'fldenv', 'frstor'):
            self.rec.problems['x87_env'].append('%s at %08x' % (mn, i.addr))
            if mn in ('fnstenv', 'fnsave'):
                # Zeroed environment with the current control word.
                self.ea_full(o)
                c.set(L_T2)
                c.get(L_T2)
                c.i32(0)
                c.i32(28)
                c.memory_fill()
                c.get(L_T2)
                c.gget(G_CW)
                c.mem(I32_STORE16)
        else:
            raise Unsupported('x87 %s at %08x' % (i.text, i.addr))

    # --- dispatcher ------------------------------------------------------------
    def insn(self, i, live, block, index):
        c = self.c
        mn = i.mn
        ops = i.ops
        if mn == 'mov':
            d, s = ops
            if d.type == X86_OP_REG:
                self.rd(s, d.size)
                self.wr_reg(d.reg)
            elif s.type == X86_OP_IMM:
                off = self.ea(d)
                c.i32(s.imm)
                c.mem(STORE[d.size], off)
            else:
                off = self.ea(d)
                self.rd(s, d.size)
                c.mem(STORE[d.size], off)
        elif mn in ('push', 'pop') and ops[0].type == X86_OP_REG and ops[0].reg not in REG:
            # push/pop of a segment register (an interrupt-style timer callback in EXTRAS.R32 saves
            # fs and gs): flat model, the selector value is never used. Push a zero, pop and discard.
            c.get(L_ESP)
            c.i32(4)
            c.op(I32_SUB if mn == 'push' else I32_ADD)
            c.set(L_ESP)
            if mn == 'push':
                c.get(L_ESP)
                c.i32(0)
                c.mem(I32_STORE)
        elif mn == 'push':
            o = ops[0]
            sz = o.size
            if o.type == X86_OP_IMM:
                sz = 4
            if o.type == X86_OP_MEM or (o.type == X86_OP_REG and REG[o.reg][0] == L_ESP):
                self.rd(o, sz)
                c.set(L_T2)
                c.get(L_ESP)
                c.i32(sz)
                c.op(I32_SUB)
                c.set(L_ESP)
                c.get(L_ESP)
                c.get(L_T2)
                c.mem(STORE[sz])
            else:
                c.get(L_ESP)
                c.i32(sz)
                c.op(I32_SUB)
                c.set(L_ESP)
                c.get(L_ESP)
                if o.type == X86_OP_IMM:
                    c.i32(o.imm)
                else:
                    self.rd(o, sz)
                c.mem(STORE[sz])
        elif mn == 'pop':
            o = ops[0]
            if o.type == X86_OP_REG:
                c.get(L_ESP)
                c.mem(LOAD_U[o.size])
                c.set(L_T2)
                c.get(L_ESP)
                c.i32(o.size)
                c.op(I32_ADD)
                c.set(L_ESP)
                c.get(L_T2)
                self.wr_reg(o.reg)
            else:
                c.get(L_ESP)
                c.mem(LOAD_U[o.size])
                c.set(L_T2)
                c.get(L_ESP)
                c.i32(o.size)
                c.op(I32_ADD)
                c.set(L_ESP)
                self.wr_op(o, L_T2)
        elif mn == 'lea':
            self.ea_full(ops[1])
            self.wr_reg(ops[0].reg)
        elif mn in ('add', 'sub', 'cmp'):
            opc = I32_ADD if mn == 'add' else I32_SUB
            kind = 'add' if mn == 'add' else 'sub'
            self.alu(i, opc, kind, mn != 'cmp', live)
        elif mn in ('and', 'or', 'xor', 'test'):
            opc = {'and': I32_AND, 'or': I32_OR, 'xor': I32_XOR, 'test': I32_AND}[mn]
            self.alu(i, opc, 'logic', mn != 'test', live)
        elif mn in ('adc', 'sbb'):
            self.adc_sbb(i, mn == 'sbb', live)
        elif mn in ('inc', 'dec'):
            self.incdec(i, mn == 'inc', live)
        elif mn == 'neg':
            d = ops[0]
            if d.type == X86_OP_MEM:
                self.ea_tea(d)
            c.i32(0)
            c.set(L_TA)
            self.rd_tea(d)
            c.set(L_TB)
            c.i32(0)
            c.get(L_TB)
            c.op(I32_SUB)
            c.set(L_TR)
            self.wr_tea(d, L_TR)
            self.set_flags('neg', d.size * 8, live)
        elif mn == 'not':
            d = ops[0]
            if d.type == X86_OP_MEM:
                self.ea_tea(d)
            self.rd_tea(d)
            c.i32(-1)
            c.op(I32_XOR)
            c.set(L_TR)
            self.wr_tea(d, L_TR)
        elif mn in ('shl', 'sal', 'shr', 'sar'):
            self.shift(i, mn, live)
        elif mn in ('rol', 'ror', 'rcl', 'rcr'):
            self.rot(i, mn, live)
        elif mn in ('shld', 'shrd'):
            self.shxd(i, mn, live)
        elif mn in ('imul', 'mul', 'div', 'idiv'):
            self.mul_div(i, mn, live)
        elif mn == 'cdq':
            c.get(L_EAX)
            c.i32(31)
            c.op(I32_SHR_S)
            c.set(L_EDX)
        elif mn == 'cwde':
            c.get(L_EAX)
            c.op(I32_EXTEND16_S)
            c.set(L_EAX)
        elif mn == 'cbw':
            c.get(L_EAX)
            c.op(I32_EXTEND8_S)
            self.wr_reg(REG_AX)
        elif mn == 'cwd':
            c.get(L_EAX)
            c.op(I32_EXTEND16_S)
            c.i32(31)
            c.op(I32_SHR_S)
            self.wr_reg(REG_DX)
        elif mn in ('movzx', 'movsx'):
            d, s = ops
            if s.type == X86_OP_MEM:
                off = self.ea(s)
                if s.size == 1:
                    c.mem(I32_LOAD8_U if mn == 'movzx' else I32_LOAD8_S, off)
                else:
                    c.mem(I32_LOAD16_U if mn == 'movzx' else I32_LOAD16_S, off)
            else:
                self.rd_reg(s.reg)
                if mn == 'movsx':
                    c.op(I32_EXTEND8_S if s.size == 1 else I32_EXTEND16_S)
            self.wr_reg(d.reg)
        elif mn == 'xchg':
            a, b = ops
            if b.type == X86_OP_MEM:
                a, b = b, a
            if a.type == X86_OP_MEM:
                self.ea_tea(a)
                c.get(L_TEA)
                c.mem(LOAD_U[a.size])
                c.set(L_TR)
                c.get(L_TEA)
                self.rd(b)
                c.mem(STORE[a.size])
                c.get(L_TR)
                self.wr_reg(b.reg)
            else:
                self.rd(a)
                c.set(L_TR)
                self.rd(b)
                self.wr_reg(a.reg)
                c.get(L_TR)
                self.wr_reg(b.reg)
        elif mn == 'leave':
            c.get(L_EBP)
            c.mem(I32_LOAD)
            c.get(L_EBP)
            c.i32(4)
            c.op(I32_ADD)
            c.set(L_ESP)
            c.set(L_EBP)
        elif mn in SETCC:
            self.cond(SETCC[mn])
            c.set(L_T2)
            self.wr_op(ops[0], L_T2)
        elif mn == 'sahf':
            self.rd_reg(REG_AH)
            c.set(L_TA)
            if live & FC:
                c.get(L_TA)
                c.i32(1)
                c.op(I32_AND)
                c.set(L_CF)
            if live & FP:
                c.get(L_TA)
                c.i32(2)
                c.op(I32_SHR_U)
                c.i32(1)
                c.op(I32_AND)
                c.set(L_PF)
            if live & FZ:
                c.get(L_TA)
                c.i32(6)
                c.op(I32_SHR_U)
                c.i32(1)
                c.op(I32_AND)
                c.set(L_ZF)
            if live & FS:
                c.get(L_TA)
                c.i32(7)
                c.op(I32_SHR_U)
                c.i32(1)
                c.op(I32_AND)
                c.set(L_SF)
        elif mn in ('bt', 'bts', 'btr', 'btc'):
            self.bit_test(i, mn, live)
        elif mn == 'xlatb':
            c.get(L_EBX)
            self.rd_reg(REG_AL)
            c.op(I32_ADD)
            c.mem(I32_LOAD8_U)
            self.wr_reg(REG_AL)
        elif mn in ('nop', 'cld', 'wait', 'pause'):
            pass
        elif mn == 'pushal':
            # eax, ecx, edx, ebx, the esp before, ebp, esi, edi, from high to low.
            c.get(L_ESP)
            c.set(L_T2)
            for k, li in enumerate((L_EAX, L_ECX, L_EDX, L_EBX, L_T2, L_EBP, L_ESI, L_EDI)):
                c.get(L_T2)
                c.i32(4 * (k + 1))
                c.op(I32_SUB)
                c.get(li)
                c.mem(I32_STORE)
            c.get(L_T2)
            c.i32(32)
            c.op(I32_SUB)
            c.set(L_ESP)
        elif mn == 'popal':
            for k, li in enumerate((L_EDI, L_ESI, L_EBP, None, L_EBX, L_EDX, L_ECX, L_EAX)):
                if li is None:
                    continue
                c.get(L_ESP)
                c.mem(I32_LOAD, 4 * k)
                c.set(li)
            c.get(L_ESP)
            c.i32(32)
            c.op(I32_ADD)
            c.set(L_ESP)
        elif mn == 'std':
            self.rec.problems['std'].append('%08x in %s' % (i.addr, self.fn.name))
        elif mn == 'clc':
            c.i32(0)
            c.set(L_CF)
        elif mn == 'stc':
            c.i32(1)
            c.set(L_CF)
        elif mn == 'cmc':
            c.get(L_CF)
            c.op(I32_EQZ)
            c.set(L_CF)
        elif mn == 'call':
            self.x_call(i, block, index)
        elif mn.split()[-1] in ('movsb', 'movsw', 'movsd', 'stosb', 'stosw', 'stosd', 'scasb', 'scasw', 'scasd',
                                'cmpsb', 'cmpsw', 'cmpsd'):
            self.x_string(i, mn, live)
        elif mn[0] == 'f':
            self.x87(i, live)
        elif mn in JCC or mn in ('jmp', 'ret', 'jecxz', 'int3', 'hlt', 'int'):
            pass    # handled as the block terminator
        else:
            raise Unsupported('instruction %s at %08x in %s' % (i.text, i.addr, self.fn.name))

    def shxd(self, i, mn, live):
        c = self.c
        d, s, n = i.ops
        if d.size != 4:
            raise Unsupported('shld size at %08x' % i.addr)
        if d.type == X86_OP_MEM:
            self.ea_tea(d)
        if n.type == X86_OP_IMM:
            c.i32(n.imm & 31)
        else:
            self.rd_reg(X86_REG_CL)
            c.i32(31)
            c.op(I32_AND)
        c.set(L_T2)
        c.get(L_T2)
        c.if_()
        self.rd_tea(d)
        c.set(L_TA)
        self.rd(s)
        c.set(L_TB)
        c.get(L_TA)
        c.get(L_T2)
        c.op(I32_SHL if mn == 'shld' else I32_SHR_U)
        c.get(L_TB)
        c.i32(32)
        c.get(L_T2)
        c.op(I32_SUB)
        c.op(I32_SHR_U if mn == 'shld' else I32_SHL)
        c.op(I32_OR)
        c.set(L_TR)
        self.wr_tea(d, L_TR)
        c.end()

    def bit_test(self, i, mn, live):
        c = self.c
        d, s = i.ops
        if d.type == X86_OP_MEM:
            self.ea_full(d)
            if s.type == X86_OP_REG:
                self.rd(s)
                c.i32(5)
                c.op(I32_SHR_S)
                c.i32(2)
                c.op(I32_SHL, I32_ADD)
            else:
                c.i32((s.imm >> 5) * 4)
                c.op(I32_ADD)
            c.set(L_TEA)
        self.rd_tea(d)
        c.set(L_TA)
        self.rd(s, 1)
        c.i32(31)
        c.op(I32_AND)
        c.set(L_T2)
        c.get(L_TA)
        c.get(L_T2)
        c.op(I32_SHR_U)
        c.i32(1)
        c.op(I32_AND)
        c.set(L_CF)
        if mn != 'bt':
            c.i32(1)
            c.get(L_T2)
            c.op(I32_SHL)
            c.set(L_TB)
            c.get(L_TA)
            c.get(L_TB)
            if mn == 'bts':
                c.op(I32_OR)
            elif mn == 'btc':
                c.op(I32_XOR)
            else:
                c.i32(-1)
                c.op(I32_XOR, I32_AND)
            c.set(L_TR)
            self.wr_tea(d, L_TR)

    # --- blocks and structure ----------------------------------------------------
    def lift_block(self, b):
        c = Code()
        self.c = c
        self.d = b.fpu_in if b.fpu_in is not None else 0
        self.kind = b.flag_in
        self.ecx_known = None
        # Flag liveness after each instruction.
        lives = [0] * len(b.insns)
        live = b.live_out
        for k in range(len(b.insns) - 1, -1, -1):
            i = b.insns[k]
            lives[k] = live
            if i.mn == 'call':
                live = 0
            else:
                r, w, _ = flag_effect(i)
                live = (live & ~w) | r
        for k, i in enumerate(b.insns):
            if b.kind == 'jmp' and i is b.tail_insn and i.mn in ('call', 'ret'):
                # Spliced code (recompile.py, splices): the call pushes its return address and
                # jumps in, the ret pops it, and its arguments, and jumps back.
                if i.mn == 'call':
                    self.push_ret(i, i.ops[0].imm & 0xFFFFFFFF)
                else:
                    c.get(L_ESP)
                    c.i32(4 + ((i.ops[0].imm & 0xFFFF) if i.ops else 0))
                    c.op(I32_ADD)
                    c.set(L_ESP)
                continue
            self.insn(i, lives[k], b, k)
            # Track the flag representation in mode A.
            if i.mn == 'call':
                self.kind = 'none'
            else:
                r, w, kind = flag_effect(i)
                if kind in ('varshift', 'repcmp'):
                    self.kind = 'mixed'
                elif w:
                    self.kind = kind if kind else 'other'
            # Track a constant ecx for rep prefixes.
            if i.mn == 'mov' and i.ops[0].type == X86_OP_REG and i.ops[0].reg == X86_REG_ECX and i.ops[1].type == X86_OP_IMM:
                self.ecx_known = i.ops[1].imm & 0xFFFFFFFF
            elif i.mn == 'call' or any(r in ECX_REGS for r in i.wr):
                self.ecx_known = None
        # Terminator.
        term = Code()
        k = b.kind
        if k == 'ret':
            self.x_ret(b)
        elif k in ('tail', 'tailmem', 'tailind'):
            self.x_tail(b)
        elif k == 'noreturn' or k == 'trap':
            c.op(UNREACHABLE)
        elif k == 'cond':
            if b.cc == 'ecxz':
                c.get(L_ECX)
                c.op(I32_EQZ)
            else:
                # The condition reads the state after the last instruction.
                self.cond(b.cc)
        elif k == 'switch':
            o = b.tail_insn.ops[0]
            c.get(REG[o.index][0])
            c.set(L_T2)
        b.code = c
        return term

    def compute_doms(self):
        fn = self.fn
        order = fn.order
        idx = {a: k for k, a in enumerate(order)}
        idom = {order[0]: order[0]}
        changed = True

        def isect(a, b):
            while a != b:
                while idx[a] > idx[b]:
                    a = idom[a]
                while idx[b] > idx[a]:
                    b = idom[b]
            return a
        while changed:
            changed = False
            for a in order[1:]:
                new = None
                for p in fn.blocks[a].preds:
                    if p in idom:
                        new = p if new is None else isect(p, new)
                if idom.get(a) != new:
                    idom[a] = new
                    changed = True
        return idom, idx

    def structure(self, out):
        fn = self.fn
        idom, idx = self.compute_doms()

        def dominates(a, b):
            while True:
                if a == b:
                    return True
                if b == idom[b]:
                    return False
                b = idom[b]
        back = set()
        loop_headers = set()
        forward_preds = {a: 0 for a in fn.order}
        switch_targets = set()
        irreducible = False
        for a in fn.order:
            b = fn.blocks[a]
            if b.kind == 'switch':
                switch_targets.update(b.succs)
            for s in b.succs:
                if idx[s] <= idx[a]:
                    if dominates(s, a):
                        back.add((a, s))
                        loop_headers.add(s)
                    else:
                        irreducible = True
                else:
                    forward_preds[s] += 1
        if irreducible:
            self.rec.problems['irreducible'].append(fn.name)
            self.emit_dispatch(out, idx)
            return
        merges = {a for a, n in forward_preds.items() if n >= 2} | switch_targets
        children = {a: [] for a in fn.order}
        for a in fn.order[1:]:
            children[idom[a]].append(a)
        for a in children:
            children[a].sort(key=lambda x: -idx[x])
        ctx = []

        def label_depth(t):
            for k in range(len(ctx) - 1, -1, -1):
                if ctx[k] == t:
                    return len(ctx) - 1 - k
            raise Unsupported('no label for %08x in %s' % (t, fn.name))

        def branch(src, t):
            if (src, t) in back or t in merges:
                out.br(label_depth(t))
            else:
                do_tree(t)

        def do_tree(x):
            mc = [c for c in children[x] if c in merges]
            if x in loop_headers:
                out.loop()
                ctx.append(x)
                node_within(x, mc)
                ctx.pop()
                out.end()
                # Anything after a loop that fell through its end is unreachable by construction.
                out.op(UNREACHABLE)
            else:
                node_within(x, mc)

        def node_within(x, ys):
            if ys:
                y = ys[0]
                out.block()
                ctx.append(y)
                node_within(x, ys[1:])
                ctx.pop()
                out.end()
                do_tree(y)
                return
            b = fn.blocks[x]
            out.extend(b.code)
            k = b.kind
            if k == 'fall' or k == 'jmp':
                branch(x, b.succs[0])
            elif k == 'cond':
                out.if_()
                ctx.append(None)
                branch(x, b.succs[0])
                out.else_()
                branch(x, b.succs[1])
                ctx.pop()
                out.end()
                out.op(UNREACHABLE)
            elif k == 'switch':
                out.block()
                ctx.append(None)
                out.get(L_T2)
                out.br_table([label_depth(t) if t is not None else 0 for t in b.table], 0)
                ctx.pop()
                out.end()
                out.op(UNREACHABLE)
            else:
                # ret, tail, noreturn, trap: the block's code already ended control flow.
                pass
        do_tree(fn.addr)
        out.op(UNREACHABLE)

    def emit_dispatch(self, out, idx):
        """Fallback for irreducible graphs: a state machine over basic blocks."""
        fn = self.fn
        order = fn.order
        pc = L_T3 + 0  # distinct use below: terminators run after instruction temps are dead
        out.i32(0)
        out.set(pc)
        out.loop()
        for _ in order:
            out.block()
        out.block()
        out.get(pc)
        out.br_table(list(range(len(order))), len(order) - 1)
        out.end()
        n = len(order)

        def go(t, depth):
            out.i32(idx[t])
            out.set(pc)
            out.br(depth)
        for k, a in enumerate(order):
            depth = n - k            # enclosing blocks of this entry, then the loop
            b = fn.blocks[a]
            out.extend(b.code)
            kd = b.kind
            if kd in ('fall', 'jmp'):
                go(b.succs[0], depth)
            elif kd == 'cond':
                out.if_()
                go(b.succs[0], depth + 1)
                out.else_()
                go(b.succs[1], depth + 1)
                out.end()
                out.op(UNREACHABLE)
            elif kd == 'switch':
                # Sequential compare: irreducible functions with switches are rare.
                for v, t in enumerate(b.table):
                    if t is None:
                        continue
                    out.get(L_T2)
                    out.i32(v)
                    out.op(I32_EQ)
                    out.if_()
                    go(t, depth + 1)
                    out.end()
                out.op(UNREACHABLE)
            out.end()
        out.op(UNREACHABLE)
        out.end()
        out.op(UNREACHABLE)

    def run(self):
        fn = self.fn
        for a in fn.order:
            self.lift_block(fn.blocks[a])
        out = Code()
        # x87 inputs arrive through globals.
        if fn.fpu_in >= 1:
            out.gget(G_ST0)
            out.set(L_F0 + fn.fpu_in - 1)
        if fn.fpu_in >= 2:
            out.gget(G_ST1)
            out.set(L_F0 + fn.fpu_in - 2)
        for li in sorted(fn.uses or ()):
            out.gget(G_OF_LOCAL[li])
            out.set(li)
        if fn.addr in self.rec.trace_set:
            out.i32(fn.addr)
            out.get(L_ESP)
            out.get(L_EAX)
            out.get(L_ECX)
            out.get(L_EDX)
            out.call(self.ctx.trace_imp)
        self.structure(out)
        return bytes(out.b)


from capstone.x86 import X86_REG_AX as REG_AX, X86_REG_DX as REG_DX, X86_REG_AL as REG_AL, X86_REG_AH as REG_AH  # noqa: E402
