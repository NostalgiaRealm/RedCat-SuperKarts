"""Minimal WebAssembly binary encoder used by the recompiler.

Only what the lifter needs: one memory, globals, one funcref table, imports,
exports, a name section and data segments. Instructions are appended to plain
bytearrays by Code.
"""
import struct


def uleb(n):
    out = bytearray()
    while True:
        b = n & 0x7F
        n >>= 7
        if n:
            out.append(b | 0x80)
        else:
            out.append(b)
            return bytes(out)


def sleb(n):
    out = bytearray()
    while True:
        b = n & 0x7F
        n >>= 7
        if (n == 0 and not (b & 0x40)) or (n == -1 and (b & 0x40)):
            out.append(b)
            return bytes(out)
        out.append(b | 0x80)


_ULEB = [uleb(i) for i in range(4096)]

I32, I64, F32, F64 = 0x7F, 0x7E, 0x7D, 0x7C
VOID = 0x40

# Control
UNREACHABLE, NOP, BLOCK, LOOP, IF, ELSE = 0x00, 0x01, 0x02, 0x03, 0x04, 0x05
END, BR, BR_IF, BR_TABLE, RETURN, CALL, CALL_INDIRECT = 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11
DROP, SELECT = 0x1A, 0x1B
LOCAL_GET, LOCAL_SET, LOCAL_TEE, GLOBAL_GET, GLOBAL_SET = 0x20, 0x21, 0x22, 0x23, 0x24
# Memory
I32_LOAD, I64_LOAD, F32_LOAD, F64_LOAD = 0x28, 0x29, 0x2A, 0x2B
I32_LOAD8_S, I32_LOAD8_U, I32_LOAD16_S, I32_LOAD16_U = 0x2C, 0x2D, 0x2E, 0x2F
I64_LOAD8_U, I64_LOAD16_U, I64_LOAD32_U = 0x31, 0x33, 0x35
I32_STORE, I64_STORE, F32_STORE, F64_STORE, I32_STORE8, I32_STORE16 = 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B
I64_STORE16 = 0x3D
I32_CONST, I64_CONST, F32_CONST, F64_CONST = 0x41, 0x42, 0x43, 0x44
# i32 comparisons
I32_EQZ, I32_EQ, I32_NE, I32_LT_S, I32_LT_U, I32_GT_S, I32_GT_U = 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B
I32_LE_S, I32_LE_U, I32_GE_S, I32_GE_U = 0x4C, 0x4D, 0x4E, 0x4F
I64_EQZ, I64_EQ, I64_NE, I64_GE_S, I64_LT_U = 0x50, 0x51, 0x52, 0x59, 0x54
F64_EQ, F64_NE, F64_LT, F64_GT, F64_LE, F64_GE = 0x61, 0x62, 0x63, 0x64, 0x65, 0x66
# i32 arithmetic
I32_CLZ, I32_CTZ, I32_POPCNT = 0x67, 0x68, 0x69
I32_ADD, I32_SUB, I32_MUL, I32_DIV_S, I32_DIV_U, I32_REM_S, I32_REM_U = 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70
I32_AND, I32_OR, I32_XOR, I32_SHL, I32_SHR_S, I32_SHR_U, I32_ROTL, I32_ROTR = 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78
# i64 arithmetic
I64_ADD, I64_SUB, I64_MUL, I64_DIV_S, I64_DIV_U, I64_REM_S, I64_REM_U = 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82
I64_AND, I64_OR, I64_XOR, I64_SHL, I64_SHR_S, I64_SHR_U = 0x83, 0x84, 0x85, 0x86, 0x87, 0x88
# f64
F64_ABS, F64_NEG, F64_CEIL, F64_FLOOR, F64_TRUNC, F64_NEAREST, F64_SQRT = 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F
F64_ADD, F64_SUB, F64_MUL, F64_DIV = 0xA0, 0xA1, 0xA2, 0xA3
# Conversions
I32_WRAP_I64, I32_TRUNC_F64_S, I64_EXTEND_I32_S, I64_EXTEND_I32_U, I64_TRUNC_F64_S = 0xA7, 0xAA, 0xAC, 0xAD, 0xB0
F32_DEMOTE_F64, F64_CONVERT_I32_S, F64_CONVERT_I64_S, F64_PROMOTE_F32 = 0xB6, 0xB7, 0xB9, 0xBB
I32_REINTERPRET_F32, I64_REINTERPRET_F64, F32_REINTERPRET_I32, F64_REINTERPRET_I64 = 0xBC, 0xBD, 0xBE, 0xBF
I32_EXTEND8_S, I32_EXTEND16_S = 0xC0, 0xC1
F64_CONVERT_I64_U = 0xBA


class Code:
    """A growing instruction sequence."""
    __slots__ = ('b',)

    def __init__(self):
        self.b = bytearray()

    def op(self, *ops):
        self.b.extend(ops)
        return self

    def get(self, i):
        b = self.b
        b.append(LOCAL_GET)
        b.extend(_ULEB[i])

    def set(self, i):
        b = self.b
        b.append(LOCAL_SET)
        b.extend(_ULEB[i])

    def tee(self, i):
        b = self.b
        b.append(LOCAL_TEE)
        b.extend(_ULEB[i])

    def gget(self, i):
        self.b.append(GLOBAL_GET)
        self.b.extend(_ULEB[i])

    def gset(self, i):
        self.b.append(GLOBAL_SET)
        self.b.extend(_ULEB[i])

    def i32(self, v):
        """i32.const with any 32-bit pattern, signed or unsigned."""
        v &= 0xFFFFFFFF
        if v >= 0x80000000:
            v -= 0x100000000
        self.b.append(I32_CONST)
        self.b.extend(sleb(v))

    def i64(self, v):
        v &= 0xFFFFFFFFFFFFFFFF
        if v >= 0x8000000000000000:
            v -= 0x10000000000000000
        self.b.append(I64_CONST)
        self.b.extend(sleb(v))

    def f64(self, v):
        self.b.append(F64_CONST)
        self.b.extend(struct.pack('<d', v))

    def f64_bits(self, bits):
        self.b.append(F64_CONST)
        self.b.extend(struct.pack('<Q', bits))

    def mem(self, opcode, offset=0, align=0):
        """Load or store. align stays 0: x86 code is free to access unaligned."""
        b = self.b
        b.append(opcode)
        b.append(align)
        if offset < 4096:
            b.extend(_ULEB[offset])
        else:
            b.extend(uleb(offset))

    def call(self, idx):
        self.b.append(CALL)
        self.b.extend(uleb(idx))

    def call_indirect(self, type_idx, table=0):
        self.b.append(CALL_INDIRECT)
        self.b.extend(uleb(type_idx))
        self.b.append(table)

    def block(self):
        self.b.append(BLOCK)
        self.b.append(VOID)

    def loop(self):
        self.b.append(LOOP)
        self.b.append(VOID)

    def if_(self):
        self.b.append(IF)
        self.b.append(VOID)

    def else_(self):
        self.b.append(ELSE)

    def end(self):
        self.b.append(END)

    def br(self, depth):
        self.b.append(BR)
        self.b.extend(uleb(depth))

    def br_if(self, depth):
        self.b.append(BR_IF)
        self.b.extend(uleb(depth))

    def br_table(self, depths, default):
        self.b.append(BR_TABLE)
        self.b.extend(uleb(len(depths)))
        for d in depths:
            self.b.extend(uleb(d))
        self.b.extend(uleb(default))

    def memory_copy(self):
        self.b.extend((0xFC, 0x0A, 0x00, 0x00))

    def memory_fill(self):
        self.b.extend((0xFC, 0x0B, 0x00))

    def extend(self, other):
        self.b.extend(other.b if isinstance(other, Code) else other)


def _vec(items):
    out = bytearray(uleb(len(items)))
    for it in items:
        out.extend(it)
    return bytes(out)


def _name(s):
    e = s.encode('utf-8')
    return uleb(len(e)) + e


def _section(sid, payload):
    return bytes((sid,)) + uleb(len(payload)) + payload


class Module:
    def __init__(self):
        self.types = []       # (params, results)
        self.imports = []     # (module, name, type_idx)
        self.funcs = []       # dict(type, locals, code, name)
        self.globals = []     # (valtype, mutable, init_bytes)
        self.exports = []     # (name, kind, index)
        self.elems = []       # (table_offset, [func_idx])
        self.data = []        # (address, bytes)
        self.table_size = 0
        self.mem_pages = 0
        self.names = {}       # func index -> debug name

    def add_type(self, params, results):
        key = (tuple(params), tuple(results))
        if key in self.types:
            return self.types.index(key)
        self.types.append(key)
        return len(self.types) - 1

    def add_import(self, module, name, params, results):
        if self.funcs:
            raise RuntimeError('imports must precede functions')
        self.imports.append((module, name, self.add_type(params, results)))
        return len(self.imports) - 1

    def add_global(self, valtype, init=0):
        body = bytearray()
        if valtype == I32:
            body.append(I32_CONST)
            body.extend(sleb(init))
        elif valtype == F64:
            body.append(F64_CONST)
            body.extend(struct.pack('<d', init))
        elif valtype == I64:
            body.append(I64_CONST)
            body.extend(sleb(init))
        body.append(END)
        self.globals.append((valtype, 1, bytes(body)))
        return len(self.globals) - 1

    def add_func(self, type_idx, locals_decl, code, name=None):
        """locals_decl: list of (count, valtype). Returns the function index."""
        self.funcs.append({'type': type_idx, 'locals': locals_decl, 'code': code})
        idx = len(self.imports) + len(self.funcs) - 1
        if name:
            self.names[idx] = name
        return idx

    def encode(self, with_names=True):
        out = bytearray(b'\0asm\x01\0\0\0')
        out += _section(1, _vec([
            b'\x60' + uleb(len(p)) + bytes(p) + uleb(len(r)) + bytes(r) for p, r in self.types
        ]))
        out += _section(2, _vec([
            _name(m) + _name(n) + b'\x00' + uleb(t) for m, n, t in self.imports
        ]))
        out += _section(3, _vec([uleb(f['type']) for f in self.funcs]))
        out += _section(4, _vec([b'\x70\x00' + uleb(self.table_size)]))
        out += _section(5, _vec([b'\x01' + uleb(self.mem_pages) + uleb(self.mem_pages)]))
        out += _section(6, _vec([bytes((t, m)) + init for t, m, init in self.globals]))
        out += _section(7, _vec([_name(n) + bytes((k,)) + uleb(i) for n, k, i in self.exports]))
        elems = []
        for off, idxs in self.elems:
            elems.append(b'\x00\x41' + sleb(off) + b'\x0B' + _vec([uleb(i) for i in idxs]))
        out += _section(9, _vec(elems))
        out += _section(12, uleb(len(self.data)))  # DataCount, required by memory.copy/fill validation
        bodies = []
        for f in self.funcs:
            loc = bytearray(uleb(len(f['locals'])))
            for count, vt in f['locals']:
                loc += uleb(count) + bytes((vt,))
            body = bytes(loc) + bytes(f['code']) + bytes((END,))
            bodies.append(uleb(len(body)) + body)
        out += _section(10, _vec(bodies))
        segs = []
        for addr, data in self.data:
            segs.append(b'\x00\x41' + sleb(addr) + b'\x0B' + uleb(len(data)) + data)
        out += _section(11, _vec(segs))
        if with_names:
            sub = _vec([uleb(i) + _name(n) for i, n in sorted(self.names.items())])
            payload = _name('name') + bytes((1,)) + uleb(len(sub)) + sub
            out += _section(0, payload)
        return bytes(out)
