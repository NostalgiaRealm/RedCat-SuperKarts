#!/usr/bin/env python3
"""Builds public/game/rcskspel.wasm, rcskspel.meta.json and rcskspel.codemap.bin from RedCat SuperKarts' rcskspel.dat.

Usage: tools/recomp/build.py [--out public/game] [--no-names] [--fpu-pc 53]
The recompiler is the one of the RedCat Spookkasteel recompiled port (RCSPOOK_MAIN/tools/recomp), which took
its core from Maisy's Playhouse and A2 Racer 4. Inputs come from the SuperKarts reconstruction's export
(original-source/: inputs/rcskspel.dat and modules/rcskspel.dat/*.tsv); SUPERKARTS_ORIGINAL_SOURCE overrides
its location. Needs capstone (the reverse-engineering Python environment has it).
"""
import argparse
import csv
import hashlib
import json
import os
import re
import struct
import sys
import time
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import recompile as R  # noqa: E402
from recompile import (  # noqa: E402
    Image, Recompiler, Unsupported, FUNC_PARAMS, FUNC_RESULTS, LOCALS_DECL,
    G_EDX, G_ST0, G_ST1, G_CW, G_ESP, G_A, G_B, G_ZF,
    POP_TABLE, THUNK_BASE, N_THUNKS, CODE_MAP, MAP_LO, MEM_PAGES, TIB_BASE, STACK_LOW, STACK_TOP, HEAP_BASE,
)
from wasmgen import *  # noqa: E402,F403
import lift as L  # noqa: E402
import replacements as RP  # noqa: E402

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
# The original executable and Ghidra's function lists come from the SuperKarts reconstruction beside this folder.
# In the published repository original-source/ lies in the repository itself; in a checkout where this port is a
# folder of its own it is read from the JavaScript port's checkout beside it
SK = os.environ.get('SUPERKARTS_ORIGINAL_SOURCE') or next((p for p in (os.path.join(ROOT, 'original-source'), os.path.normpath(os.path.join(ROOT, '..', 'RedCat Superkarts', 'original-source'))) if os.path.isdir(os.path.join(p, 'modules'))), os.path.join(ROOT, 'original-source'))
RCSKSPEL_SHA256 = '68e5c9139a9251d36b5cbb526738c5a3ce7d85c17bc95793927da705ad65fd4f'

# Functions that never return although they end in a ret, found by their bytes. Ghidra's own no-return
# flags cannot be used as they are: the recompiler only trusts functions without a ret, and both of
# Ghidra's (0x4BFC77, __exit 0x4C026D) have one. Without this, decoding runs past the call into the jump
# tables behind it (0x437EA0, 0x467E30, 0x46C910).
NORETURN_SIGNATURES = [
    # __CxxThrowException@8 (MSVC6): RaiseException(0xE06D7363, ...), then ret 8 that is never reached.
    ('__CxxThrowException@8', '55 8B EC 83 EC 20 8B 45 08 56 57 6A 08 59 BE ?? ?? ?? ?? 8D 7D E0 F3 A5'),
]


def find_noreturn(img):
    out = {}
    for name, sig in NORETURN_SIGNATURES:
        pat = re.compile(b''.join(b'.' if t == '??' else re.escape(bytes([int(t, 16)])) for t in sig.split()), re.S)
        hits = []
        for lo, hi in img.text_ranges:
            blob = bytes(img.mem[lo - img.base:hi - img.base])
            hits += [lo + mt.start() for mt in pat.finditer(blob)]
        if len(hits) != 1:
            raise SystemExit('no-return signature %s: %d matches' % (name, len(hits)))
        out[hits[0]] = name
    return out

MATH_IMPORTS = [
    ('sin', [F64], [F64]), ('cos', [F64], [F64]), ('tan', [F64], [F64]), ('atan2', [F64, F64], [F64]),
    ('log2', [F64], [F64]), ('pow2m1', [F64], [F64]), ('pow2', [F64], [F64]),
    ('fmod', [F64, F64], [F64]), ('frem', [F64, F64], [F64]),
    ('acos', [F64], [F64]), ('asin', [F64], [F64]), ('pow', [F64, F64], [F64]),
    ('atan', [F64], [F64]), ('exp', [F64], [F64]), ('log', [F64], [F64]), ('log10', [F64], [F64]),
    ('sinh', [F64], [F64]), ('cosh', [F64], [F64]), ('tanh', [F64], [F64]),
]


class ModuleContext:
    def __init__(self, rec):
        self.rec = rec
        self.mod = Module()
        self.type0 = self.mod.add_type(FUNC_PARAMS, FUNC_RESULTS)
        self.rt = {}
        self.func_idx = {}
        self.imp_thunk = {}      # IAT address -> thunk id
        self.thunk_first = None
        self.body_idx = {}

    def func_index_of(self, addr):
        return self.func_idx.get(addr)

    def import_func_index(self, iat_addr):
        return self.thunk_first + self.imp_thunk[iat_addr]


def build_runtime_helpers(ctx, first_index):
    """Hand-assembled helpers. Returns list of (name, type, locals, code)."""
    m = ctx.mod
    helpers = []

    def add(name, params, results, locals_decl, code):
        ctx.rt[name] = first_index + len(helpers)
        helpers.append((name, m.add_type(params, results), locals_decl, code))

    # movs(dst, src, n): rep movs semantics, forward byte order when overlapping.
    c = Code()
    c.get(0); c.get(1); c.op(I32_SUB); c.get(2); c.op(I32_GE_U)
    c.if_(); c.get(0); c.get(1); c.get(2); c.memory_copy(); c.op(RETURN); c.end()
    c.block(); c.loop()
    c.get(2); c.op(I32_EQZ); c.br_if(1)
    c.get(0); c.get(1); c.mem(I32_LOAD8_U); c.mem(I32_STORE8)
    c.get(0); c.i32(1); c.op(I32_ADD); c.set(0)
    c.get(1); c.i32(1); c.op(I32_ADD); c.set(1)
    c.get(2); c.i32(1); c.op(I32_SUB); c.set(2)
    c.br(0); c.end(); c.end()
    add('movs', [I32, I32, I32], [], [], c)

    # stos1(dst, val, count)
    c = Code()
    c.get(0); c.get(1); c.get(2); c.memory_fill()
    add('stos1', [I32, I32, I32], [], [], c)

    # stos2(dst, val, count)
    c = Code()
    c.block(); c.loop()
    c.get(2); c.op(I32_EQZ); c.br_if(1)
    c.get(0); c.get(1); c.mem(I32_STORE16)
    c.get(0); c.i32(2); c.op(I32_ADD); c.set(0)
    c.get(2); c.i32(1); c.op(I32_SUB); c.set(2)
    c.br(0); c.end(); c.end()
    add('stos2', [I32, I32, I32], [], [], c)

    # stos4(dst, val, count)
    c = Code()
    c.get(1); c.get(1); c.i32(0xFF); c.op(I32_AND); c.i32(0x01010101); c.op(I32_MUL); c.op(I32_EQ)
    c.if_(); c.get(0); c.get(1); c.get(2); c.i32(2); c.op(I32_SHL); c.memory_fill(); c.op(RETURN); c.end()
    c.block(); c.loop()
    c.get(2); c.op(I32_EQZ); c.br_if(1)
    c.get(0); c.get(1); c.mem(I32_STORE)
    c.get(0); c.i32(4); c.op(I32_ADD); c.set(0)
    c.get(2); c.i32(1); c.op(I32_SUB); c.set(2)
    c.br(0); c.end(); c.end()
    add('stos4', [I32, I32, I32], [], [], c)

    # repne_scasb(edi, al, ecx) -> ecx; G_A, G_B hold the last compared pair
    c = Code()
    c.block(); c.loop()
    c.get(2); c.op(I32_EQZ); c.br_if(1)
    c.get(2); c.i32(1); c.op(I32_SUB); c.set(2)
    c.get(0); c.mem(I32_LOAD8_U); c.set(3)
    c.get(0); c.i32(1); c.op(I32_ADD); c.set(0)
    c.get(3); c.get(1); c.op(I32_NE); c.br_if(0)
    c.get(1); c.i32(24); c.op(I32_SHL); c.gset(G_A)
    c.get(3); c.i32(24); c.op(I32_SHL); c.gset(G_B)
    c.get(2); c.op(RETURN)
    c.end(); c.end()
    c.get(1); c.i32(24); c.op(I32_SHL); c.gset(G_A)
    c.get(3); c.i32(24); c.op(I32_SHL); c.gset(G_B)
    c.get(2)
    add('repne_scasb', [I32, I32, I32], [I32], [(1, I32)], c)

    # repe_cmpsb(esi, edi, ecx) -> ecx
    c = Code()
    c.block(); c.loop()
    c.get(2); c.op(I32_EQZ); c.br_if(1)
    c.get(2); c.i32(1); c.op(I32_SUB); c.set(2)
    c.get(0); c.mem(I32_LOAD8_U); c.i32(24); c.op(I32_SHL); c.set(3)
    c.get(1); c.mem(I32_LOAD8_U); c.i32(24); c.op(I32_SHL); c.set(4)
    c.get(0); c.i32(1); c.op(I32_ADD); c.set(0)
    c.get(1); c.i32(1); c.op(I32_ADD); c.set(1)
    c.get(3); c.gset(G_A)
    c.get(4); c.gset(G_B)
    c.get(3); c.get(4); c.op(I32_EQ); c.br_if(0)
    c.end(); c.end()
    c.get(2)
    add('repe_cmpsb', [I32, I32, I32], [I32], [(2, I32)], c)

    # repe_cmpsd(esi, edi, ecx) -> ecx
    c = Code()
    c.block(); c.loop()
    c.get(2); c.op(I32_EQZ); c.br_if(1)
    c.get(2); c.i32(1); c.op(I32_SUB); c.set(2)
    c.get(0); c.mem(I32_LOAD); c.set(3)
    c.get(1); c.mem(I32_LOAD); c.set(4)
    c.get(0); c.i32(4); c.op(I32_ADD); c.set(0)
    c.get(1); c.i32(4); c.op(I32_ADD); c.set(1)
    c.get(3); c.gset(G_A)
    c.get(4); c.gset(G_B)
    c.get(3); c.get(4); c.op(I32_EQ); c.br_if(0)
    c.end(); c.end()
    c.get(2)
    add('repe_cmpsd', [I32, I32, I32], [I32], [(2, I32)], c)

    # fcom(a, b) -> FPU status bits C0/C2/C3
    c = Code()
    c.get(0); c.get(1); c.op(F64_LT); c.if_(); c.i32(0x100); c.op(RETURN); c.end()
    c.get(0); c.get(1); c.op(F64_GT); c.if_(); c.i32(0); c.op(RETURN); c.end()
    c.get(0); c.get(1); c.op(F64_EQ); c.if_(); c.i32(0x4000); c.op(RETURN); c.end()
    c.i32(0x4500)
    add('fcom', [F64, F64], [I32], [], c)

    # fxam(x) -> class bits
    c = Code()
    c.get(0); c.op(I64_REINTERPRET_F64); c.set(1)
    c.get(1); c.i64(63); c.op(I64_SHR_U, I32_WRAP_I64); c.i32(9); c.op(I32_SHL); c.set(2)   # C1 = sign
    c.get(0); c.get(0); c.op(F64_NE); c.if_(); c.get(2); c.i32(0x100); c.op(I32_OR); c.op(RETURN); c.end()
    c.get(0); c.op(F64_ABS); c.f64(float('inf')); c.op(F64_EQ); c.if_(); c.get(2); c.i32(0x500); c.op(I32_OR); c.op(RETURN); c.end()
    c.get(0); c.f64(0.0); c.op(F64_EQ); c.if_(); c.get(2); c.i32(0x4000); c.op(I32_OR); c.op(RETURN); c.end()
    c.get(2); c.i32(0x400); c.op(I32_OR)
    add('fxam', [F64], [I32], [(1, I64), (1, I32)], c)

    # frndint(x) honouring the rounding-control field of the control word
    c = Code()
    c.gget(G_CW); c.i32(10); c.op(I32_SHR_U); c.i32(3); c.op(I32_AND); c.set(1)
    c.get(1); c.op(I32_EQZ); c.if_(); c.get(0); c.op(F64_NEAREST); c.op(RETURN); c.end()
    c.get(1); c.i32(1); c.op(I32_EQ); c.if_(); c.get(0); c.op(F64_FLOOR); c.op(RETURN); c.end()
    c.get(1); c.i32(2); c.op(I32_EQ); c.if_(); c.get(0); c.op(F64_CEIL); c.op(RETURN); c.end()
    c.get(0); c.op(F64_TRUNC)
    add('frndint', [F64], [F64], [(1, I32)], c)

    # fist32(x): rounds per control word, out of range or NaN gives the integer indefinite
    c = Code()
    c.get(0); c.call(ctx.rt['frndint']); c.set(0)
    c.get(0); c.f64(-2147483648.0); c.op(F64_GE); c.get(0); c.f64(2147483647.0); c.op(F64_LE); c.op(I32_AND)
    c.if_(); c.get(0); c.op(I32_TRUNC_F64_S); c.op(RETURN); c.end()
    c.i32(0x80000000)
    add('fist32', [F64], [I32], [], c)

    # fist64(x)
    c = Code()
    c.get(0); c.call(ctx.rt['frndint']); c.set(0)
    c.get(0); c.f64(-9223372036854775808.0); c.op(F64_GE); c.get(0); c.f64(9223372036854774784.0); c.op(F64_LE); c.op(I32_AND)
    c.if_(); c.get(0); c.op(I64_TRUNC_F64_S); c.op(RETURN); c.end()
    c.i64(0x8000000000000000)
    add('fist64', [F64], [I64], [], c)

    # ftol(x) -> i64: truncation, what __ftol computes through fistp with RC=3
    c = Code()
    c.get(0); c.op(F64_TRUNC); c.set(0)
    c.get(0); c.f64(-9223372036854775808.0); c.op(F64_GE); c.get(0); c.f64(9223372036854774784.0); c.op(F64_LE); c.op(I32_AND)
    c.if_(); c.get(0); c.op(I64_TRUNC_F64_S); c.op(RETURN); c.end()
    c.i64(0x8000000000000000)
    add('ftol', [F64], [I64], [], c)

    # fld80(addr) -> f64, rounding the 64-bit mantissa to 53 bits
    c = Code()
    c.get(0); c.mem(I64_LOAD); c.set(1)
    c.get(0); c.mem(I32_LOAD16_U, 8); c.set(2)
    c.get(2); c.i32(0x7FFF); c.op(I32_AND); c.set(3)
    c.get(1); c.op(I64_EQZ)
    c.if_()
    c.get(2); c.i32(15); c.op(I32_SHR_U); c.op(I64_EXTEND_I32_U); c.i64(63); c.op(I64_SHL); c.op(F64_REINTERPRET_I64); c.op(RETURN)
    c.end()
    c.get(3); c.i32(0x7FFF); c.op(I32_EQ)
    c.if_()
    c.get(2); c.i32(15); c.op(I32_SHR_U); c.op(I64_EXTEND_I32_U); c.i64(63); c.op(I64_SHL)
    c.i64(0x7FF0000000000000); c.op(I64_OR)
    c.get(1); c.i64(1); c.op(I64_SHL); c.i64(12); c.op(I64_SHR_U); c.op(I64_OR)
    c.op(F64_REINTERPRET_I64); c.op(RETURN)
    c.end()
    # value = mantissa * 2^(exp - 16383 - 63), computed in two exact steps
    c.get(1); c.op(F64_CONVERT_I64_U)
    c.get(3); c.i32(16383 + 63); c.op(I32_SUB); c.op(F64_CONVERT_I32_S); c.call(ctx_math_pow2(ctx))
    c.op(F64_MUL)
    c.set(4)
    c.get(2); c.i32(0x8000); c.op(I32_AND)
    c.if_(); c.get(4); c.op(F64_NEG); c.op(RETURN); c.end()
    c.get(4)
    add('fld80', [I32], [F64], [(1, I64), (2, I32), (1, F64)], c)

    # fst80(addr, v)
    c = Code()
    c.get(1); c.op(I64_REINTERPRET_F64); c.set(2)
    c.get(2); c.i64(52); c.op(I64_SHR_U, I32_WRAP_I64); c.i32(0x7FF); c.op(I32_AND); c.set(3)
    c.get(2); c.i64(63); c.op(I64_SHR_U, I32_WRAP_I64); c.i32(15); c.op(I32_SHL); c.set(4)
    c.get(3); c.op(I32_EQZ)
    c.if_()
    c.get(0); c.i64(0); c.mem(I64_STORE)
    c.get(0); c.get(4); c.mem(I32_STORE16, 8)
    c.op(RETURN)
    c.end()
    c.get(0)
    c.get(2); c.i64(11); c.op(I64_SHL); c.i64(0x8000000000000000); c.op(I64_OR)
    c.mem(I64_STORE)
    c.get(0)
    c.get(3); c.i32(0x7FF); c.op(I32_EQ)
    c.if_()
    c.get(4); c.i32(0x7FFF); c.op(I32_OR); c.set(3)
    c.else_()
    c.get(4); c.get(3); c.i32(16383 - 1023); c.op(I32_ADD); c.op(I32_OR); c.set(3)
    c.end()
    c.get(3)
    c.mem(I32_STORE16, 8)
    add('fst80', [I32, F64], [], [(1, I64), (2, I32)], c)
    return helpers


def ctx_math_pow2(ctx):
    return ctx.rt['pow2']


MODULES = [
    # id in RC_ORIGINAL_DECOMPILED/decompiled, file under originals/, name, relocate?
    # The Genesis3D render driver (D3DDrv.dll) is not recompiled: source/host/gdriver.js implements
    # the driver table that the engine gets from DriverHook.
    ('rcskspel.dat', 'rcskspel.dat', 'GAME', False),
]


# Functions of the game that the host takes over (bound in source/host/); pop is the number of stack bytes the
# function removes. Two kinds (docs/recompiler.md, Hooks):
#  - replace (keep_body): direct calls go to the hook; the code map (calls by address, the host's m.call) still
#    reaches the original body. An unbound one stops the race (machine.js onUnimplemented).
#  - wrap: every call (direct, tail, by address, m.call) goes to the hook, and the original body stays in the table
#    (meta.hooks[name].body), as the guards of eh.js keep theirs. Until the host binds it, the hook runs the body
#    (machine.js), so a wasm with a new wrap runs unchanged with a host that does not know it. The host wraps it with
#    m.wrap(name, fn) and calls the original with m.callOriginal(addr, ...). The build checks that the declared pop is
#    every ret's, that the function has no try block (those are hook!eh_ thunks already) and no callee-saved
#    register inputs. Wraps take thunk ids from the top of the table ('late'), so the ids of the imports, the other
#    hooks and the host's own thunks (COM methods, stored in game memory) do not move.
GAME_HOOKS = {
    # WinMain: the host runs init_main 0x442FC0 and start_game 0x42F930, then one pass of the loop per tick
    # (source/host/race.js) instead of the original's busy-waiting loop. keep_body keeps its callees reachable.
    0x004432A0: {'hook': 'WinMain', 'pop': 16, 'keep_body': True},
    # The NPC driving step 0x406940(ai), cdecl, plain RET at 0x406b37. Called at 0x40b0f2 (NPC callback 0x40b0b0) and
    # 0x4022b4; it holds 0x4062b0 -> 0x406100, which multiplies the velocities +0x9c/+0xa0/+0xa4 once one is >= 30.
    # The JS port's actor.prepare window (race-simulation.js:419, :442-446; npc-velocity-safety.js:82-92): the host
    # resets a velocity that was finite before and is not after (safeguards).
    0x00406940: {'hook': 'NpcPrepare', 'pop': 0, 'wrap': True, 'conv': 'cdecl (ai index)'},
    # The kart shadow 0x4260c0(slot), cdecl, plain RET at 0x4264b1. Only ever called by address: 0x4264c0 registers it
    # (PUSH 0x4260c0, CALL 0x493190 -> [0x6802c4]) and 0x4931a0 calls [0x6802c4] (PUSH ECX, CALL EAX, POP ECX) from
    # 0x4918f0/0x4916f0, right before the kart when racer +0x28 != -1. As a wrap the code map sends that call to the
    # hook, so no pointer swap is needed (visuals: surface grid; free flight hides the player's shadow, JS
    # driving-view.js:228).
    0x004260C0: {'hook': 'KartShadow', 'pop': 0, 'wrap': True, 'conv': 'cdecl (engine slot)'},
    # The render 0x430020 (track, objects, effects, HUD pass; Begin/EndScene), no arguments, plain RET at 0x43046a; its
    # first instruction loads EAX from 0x53ba04, so no register inputs. Called only at 0x42f663 (HANDLE_GAME's render,
    # return 0x42f668) and 0x42f703 (the pause entry's, return 0x42f708, kept by GAME_PATCHES 0x42f6d8), and by free
    # flight's pass (source/host/free-flight.js, m.call). The racer draw 0x490d40 multiplies every kart part's matrix
    # (wheels, driver: racer +0x64.., count +0x8c) by the body's in place (0x4a2560), which only the object pass
    # 0x491530 sets back; the pause entry and free flight render without it, so source/host/render-replay.js puts back the
    # part matrices the render before found.
    0x00430020: {'hook': 'Render', 'pop': 0, 'wrap': True, 'conv': 'cdecl ()'},
    # The camera mode setter 0x41e280(mode), cdecl, plain RETs at 0x41e9dc and 0x41eaff (cases 0-10 of a jump table;
    # the mode goes to 0x4e3064). Key 3 held selects mode 5, the look back (0x41d969..0x41d99d), and its release the
    # mode before (0x4e2ac8). The host sets mode 5's camera offset and aim the way A2 Racer 4's look back has them
    # (source/host/look-back.js; docs/intentional-differences.md).
    0x0041E280: {'hook': 'CameraMode', 'pop': 0, 'wrap': True, 'conv': 'cdecl (mode)'},
    # CBonusController::PickUp 0x4514e0 (JS native-bonus.js:121), thiscall ECX = bonus object with two stack arguments
    # (PUSH EDI, PUSH ESI, MOV ECX,EBP at 0x45418b..0x45418d), RET 8 at 0x451588/0x451634. Called only at 0x45418f
    # (0x4540c0). Safeguards phase 2: the JS port's pickup exclusion after a soft-lock relocation (race-simulation.js:
    # 487, 529-530).
    0x004514E0: {'hook': 'BonusPickUp', 'pop': 8, 'wrap': True, 'conv': 'thiscall (ecx bonus; arg1 = ESI, arg2 = EDI of 0x4540c0)'},
    # The rescue entry's step 0x48ca60, thiscall ECX = entry (0x11b0 bytes), plain RET at 0x48d012/0x48d207/0x48d342.
    # Called only at 0x48db19 (0x48db00, from HANDLE_GAME at 0x42f618). It has an EH frame without a try block, so no
    # guard. The JS port's player stuck recovery replaces its grow-frame-0 destination (native-rescue.js:228-233).
    0x0048CA60: {'hook': 'RescueUpdate', 'pop': 0, 'wrap': True, 'conv': 'thiscall (ecx rescue entry)'},
}

# Byte patches applied to the image before anything is decoded: address -> (original bytes, new bytes, what), hex.
# The build checks the original bytes and stops on a mismatch, so a patch only lands on the code it was written for.
# Lifting decodes the patched image (recursive descent from the entries, Recompiler.decode) and .text is not emitted
# as data, so a patch changes code only. meta.patches records them. docs/recompiler.md, Byte patches.
GAME_PATCHES = {
    # Pause entry, the JS port's intentional departure (Rick, 2026-10-28; its docs/original-comparison-2026-10-28.md:
    # 964-969): on the pass where P or Esc set 0x53b9f8 (0x42f9c0), HANDLE_GAME 0x42f4c0 runs one more object pass
    # 0x491530 (three pushes at 0x42f6e3/0x42f6ea/0x42f6fa, ADD ESP,0xC at 0x42f700) before render 0x430020, present
    # 0x430470 and the pause 0x42f350. Only the object pass is left out: MOV ECX,[0x53b9d0] at 0x42f6d8 becomes
    # JMP 0x42f703 (rel32 0x26). The render and present stay, because 0x42f9c0's P branch sets the "pauze" notice
    # (0x430610(1)) after the pass's own render and that second render is the only one that draws it before the
    # pause loop 0x42f220 removes it again (0x430610(2) at 0x42f27d); the JS port shows the notice with its own HUD
    # (driving-view.js:394). The skipped code is stack-neutral, no reference targets 0x42f6d9..0x42f702
    # (references.tsv), and the 00 left at 0x42f6dd is dead (a linear decode resyncs at 0x42f6e3).
    0x0042F6D8: ('8b0dd0b953', 'e926000000', 'pause entry: no extra object pass 0x491530 (render and present stay: the pauze notice)'),
}


def apply_patches(img, md):
    out = []
    for a, (old, new, what) in sorted(GAME_PATCHES.items()):
        old_b, new_b = bytes.fromhex(old), bytes.fromhex(new)
        if len(old_b) != len(new_b):
            raise SystemExit('patch %08x: %d original bytes, %d new' % (a, len(old_b), len(new_b)))
        o = a - img.base
        have = bytes(img.mem[o:o + len(old_b)])
        if not img.is_text(a) or have != old_b:
            raise SystemExit('patch %08x: expected %s, found %s' % (a, old, have.hex()))
        img.mem[o:o + len(new_b)] = new_b
        asm = '; '.join('%s %s' % (x.mnemonic, x.op_str) for x in md.disasm(new_b, a))
        out.append({'addr': a, 'old': old, 'new': new, 'asm': asm, 'what': what})
        print('  patch %08x %s -> %s (%s): %s' % (a, old, new, asm, what))
    return out


def load_inventory(img):
    """Ghidra's function lists (functions.tsv of the decompilation package), shifted to this build's addresses."""
    ghidra, noreturn = {}, set()
    for m in img.modules:
        d = os.path.join(SK, 'modules', m['id'])
        with open(os.path.join(d, 'functions.tsv'), newline='') as f:
            for row in csv.DictReader(f, delimiter='\t'):
                a = int(row['address'], 16) + m['delta']
                ranges = []
                for rng in row['body_ranges'].replace(',', ';').replace(' ', '').split(';'):
                    lo, hi = [int(x, 16) + m['delta'] for x in rng.split('-')]
                    ranges.append((lo, hi))
                name = row['name']
                # keep the original address in the name so a trap maps straight back to the decompilation
                name = name if name.startswith(('Unwind@', 'Catch@', '__break')) else '%s_%s_%s' % (m['name'], name, row['address'])
                ghidra[a] = {'name': name, 'ranges': ranges, 'module': m['name'], 'orig': int(row['address'], 16)}
    return ghidra, noreturn


def load_unowned_starts(img):
    """Code that Ghidra decoded but did not make a function of (instructions_outside_functions.tsv).

    In RcHcGame.dat (Spookkasteel) these were mostly callbacks that are only ever reached through a stored pointer:
    the window procedure (0x5A8180, stored into the WNDCLASS with a mov), atexit destructors, and
    the like. Every such range becomes an entry point, so a call through a stored pointer finds
    its code. Not only the 16-byte aligned ones: part of the image is built with tighter packing
    (0x600F3C, a callback stored with 'mov edx, offset', sits on a 4-byte boundary).
    """
    out = []
    for m in img.modules:
        f = os.path.join(SK, 'modules', m['id'], 'instructions_outside_functions.tsv')
        if not os.path.exists(f):
            continue
        with open(f, newline='') as fh:
            for row in csv.DictReader(fh, delimiter='\t'):
                out.append(int(row['start'], 16) + m['delta'])
    return out


def build(args):
    t0 = time.time()
    specs = [{'id': i, 'path': os.path.join(SK, 'inputs', p), 'name': n, 'relocate': r} for i, p, n, r in MODULES]
    img = Image(specs, first_dll_base=R.DLL_BASE)
    if img.sha256 != RCSKSPEL_SHA256:
        raise SystemExit('rcskspel.dat: unexpected SHA-256 %s' % img.sha256)
    for m in img.modules:
        print('%-9s base %08x (preferred %08x) size %06x entry %08x exports %d sha256 %s' % (m['name'], m['base'], m['preferred'], m['size'], m['entry'], len(m['exports']), m['sha256'][:16]))
    if img.end > CODE_MAP or CODE_MAP + (img.end - MAP_LO) * 2 > HEAP_BASE:
        raise SystemExit('layout: image end %08x does not fit' % img.end)
    patches = apply_patches(img, R.Cs(R.CS_ARCH_X86, R.CS_MODE_32))
    ghidra, noreturn = load_inventory(img)
    repl, eh_prolog, rep_report = RP.find_replacements(img, ghidra)
    for a, r in GAME_HOOKS.items():
        repl[a] = dict(r)
        if r.get('wrap'):
            repl[a].update(keep_body=True, late=True)
        rep_report.append((a, 'hook!' + r['hook'] + (' (wrap)' if r.get('wrap') else '')))
    for a, n in sorted(rep_report):
        print('  replacement %08x %s' % (a, n))
    # Ghidra's no-return analysis is used only to end basic blocks after a call; here it comes from
    # NORETURN_SIGNATURES (see there).
    noret = find_noreturn(img)
    for a, n in sorted(noret.items()):
        print('  no-return %08x %s' % (a, n))
    rec = Recompiler(img, ghidra, set(noret), ('Unwind@', 'Catch@', '__break'), repl, debug_ret=not args.no_ret_store,
                     fpu_pc=args.fpu_pc)
    rec.eh_prolog = eh_prolog
    roots = []
    for m in img.modules:
        if m['entry']:
            roots.append(m['entry'])
        roots.extend(e[2] for e in m['exports'])
    # C++ exception handling: cleanup and catch funclets are entered by the host's unwinder with the
    # frame's ebp; the code after a catch is entered again at its continuation address.
    eh_stubs, eh_unwind, eh_catch, eh_with_try = RP.find_eh(img)
    eh_conts = set()
    for a in sorted(eh_catch):
        try:
            f = rec.build(a)
        except Unsupported as e:
            rec.problems['eh'].append('catch funclet %08x: %s' % (a, e))
            continue
        for b in f.blocks.values():
            if b.kind == 'ret' and len(b.insns) >= 2:
                i = b.insns[-2]
                if i.mn == 'mov' and i.ops[0].type == R.X86_OP_REG and i.ops[0].reg == R.X86_REG_EAX and i.ops[1].type == R.X86_OP_IMM and img.is_text(i.ops[1].imm & 0xFFFFFFFF):
                    eh_conts.add(i.ops[1].imm & 0xFFFFFFFF)
    print('eh: %d handler stubs, %d with try blocks, %d unwind funclets, %d catch funclets, %d continuations' % (len(eh_stubs), len(eh_with_try), len(eh_unwind), len(eh_catch), len(eh_conts)))
    roots.extend(sorted(eh_unwind | eh_catch | eh_conts))
    unowned = [a for a in load_unowned_starts(img) if a not in ghidra and a not in repl]
    print('unowned code ranges added as entries:', len(unowned))
    roots.extend(unowned)
    rec.force_uses = set(eh_unwind | eh_catch | eh_conts)
    rec.extra_roots = roots
    rec.scan_entries()
    print('entries', len(rec.real_entries), 'address-taken', len(rec.address_taken), '%.1fs' % (time.time() - t0))
    rec.discover()
    print('functions', len(rec.funcs), 'instructions', sum(f.insn_count for f in rec.funcs.values()), '%.1fs' % (time.time() - t0))
    # Functions that own a try block run under a host guard (source/host/eh.js): a C++ throw is a
    # JavaScript exception that unwinds the wasm frames up to the guard of the catching function.
    eh_guarded = {}
    for a, fn in rec.funcs.items():
        if a in rec.force_uses:
            continue
        for b in fn.blocks.values():
            if not a <= b.start < a + 64:
                continue
            for i in b.insns:
                if i.addr >= a + 64:
                    break
                for o in i.ops:
                    if o.type == R.X86_OP_IMM and (o.imm & 0xFFFFFFFF) in eh_with_try:
                        eh_guarded[a] = o.imm & 0xFFFFFFFF
    owned = set(eh_guarded.values())
    if eh_with_try - owned:
        # the frame set-up can sit further into a long prologue: take the function whose body holds the push
        for a, fn in rec.funcs.items():
            if a in rec.force_uses or a in eh_guarded:
                continue
            for b in fn.blocks.values():
                for i in b.insns:
                    for o in i.ops:
                        if o.type == R.X86_OP_IMM and (o.imm & 0xFFFFFFFF) in eh_with_try and (o.imm & 0xFFFFFFFF) not in owned and i.addr - a < 0x200:
                            eh_guarded[a] = o.imm & 0xFFFFFFFF
        owned = set(eh_guarded.values())
    for sref in sorted(eh_with_try - owned):
        rec.problems['eh'].append('try-block handler stub %08x: its function is not reachable (not discovered), no guard needed' % sref)
    wraps = sorted(a for a, r in GAME_HOOKS.items() if r.get('wrap'))
    for a in wraps:
        # A function with a try block is already behind a guard (hook!eh_...): wrap that thunk in the host instead.
        if a in eh_guarded:
            raise SystemExit('wrap %08x %s: the function owns a try block; wrap hook!eh_%08x in the host' % (a, GAME_HOOKS[a]['hook'], a))
        fn = rec.funcs.get(a)
        if fn is None:
            raise SystemExit('wrap %08x %s: not a discovered function' % (a, GAME_HOOKS[a]['hook']))
        # The hook's thunk returns esp + pop + 4 whatever the body did, so the declared pop must be every exit's.
        pops = set()
        for b in fn.blocks.values():
            if b.kind == 'ret':
                pops.add((b.tail_insn.ops[0].imm & 0xFFFF) if b.tail_insn.ops else 0)
            elif b.kind in ('tail', 'tailmem', 'tailind'):
                raise SystemExit('wrap %08x %s: leaves through a tail jump at %08x, pop cannot be checked' % (a, GAME_HOOKS[a]['hook'], b.tail_insn.addr))
        if pops != {GAME_HOOKS[a]['pop']}:
            raise SystemExit('wrap %08x %s: declared pop %d, rets pop %s' % (a, GAME_HOOKS[a]['hook'], GAME_HOOKS[a]['pop'], sorted(pops)))
    for a in eh_guarded:
        if a in rec.replacements:
            rec.problems['eh'].append('guarded function %08x is already replaced' % a)
            continue
        rec.replacements[a] = {'hook': 'eh_%08x' % a, 'pop': None, 'keep_body': True, 'guarded': True}
    print('eh: %d guarded functions' % len(eh_guarded))
    rec.analyse_fpu()
    rec.analyse_inputs()
    uses = sorted('%08x %s %s' % (a, f.name, sorted(f.uses)) for a, f in rec.funcs.items() if f.uses)
    print('functions with register inputs:', len(uses))
    rec.problems['register_input_functions'] = uses
    for a in wraps:
        # inputs in ebx/ebp/esi/edi travel in globals that host code calling the game before the body could change
        if rec.funcs[a].uses:
            raise SystemExit('wrap %08x %s: reads callee-saved registers as inputs %s' % (a, GAME_HOOKS[a]['hook'], sorted(rec.funcs[a].uses)))
        f = rec.funcs[a]
        print('  wrap %08x hook!%s pop %d %s, x87 in %d out %d' % (a, GAME_HOOKS[a]['hook'], GAME_HOOKS[a]['pop'], GAME_HOOKS[a]['conv'], f.fpu_in, f.fpu_out))
    for fn in rec.funcs.values():
        rec.analyse_flags(fn)
    print('analysis done %.1fs' % (time.time() - t0))

    ctx = ModuleContext(rec)
    mod = ctx.mod
    host_imp = mod.add_import('env', 'host', [I32, I32, I32, I32, I32], [I32])
    ctx.trace_imp = mod.add_import('env', 'trace', [I32, I32, I32, I32, I32], [])
    rec.trace_set = set(int(x, 16) for x in args.trace.split(',')) if args.trace else set()
    for name, p, r in MATH_IMPORTS:
        ctx.rt[name] = mod.add_import('env', name, p, r)
    n_imports = len(mod.imports)

    # Globals in the order of the G_* constants.
    mod.add_global(I32, 0)    # G_EDX
    mod.add_global(F64, 0.0)  # G_ST0
    mod.add_global(F64, 0.0)  # G_ST1
    mod.add_global(I32, 0x27F)  # G_CW
    mod.add_global(I32, 0)    # G_ESP
    mod.add_global(I32, 0)    # G_A
    mod.add_global(I32, 0)    # G_B
    mod.add_global(I32, 0)    # G_ZF
    for _ in range(4):
        mod.add_global(I32, 0)  # G_EBX, G_EBP, G_ESI, G_EDI: inputs of frame-sharing functions

    helpers = build_runtime_helpers(ctx, n_imports)
    next_idx = n_imports + len(helpers)
    badcall_idx = next_idx
    next_idx += 1
    ctx.thunk_first = next_idx
    next_idx += N_THUNKS
    call_idx = next_idx
    next_idx += 1

    # Thunk ids: imports first, then hooks.
    names = {}
    thunk_id = 0
    by_name = {}
    for iat_addr, name in sorted(img.iat.items()):
        # One thunk per imported function, shared by every module that imports it.
        if name not in by_name:
            by_name[name] = thunk_id
            names[thunk_id] = name
            thunk_id += 1
        ctx.imp_thunk[iat_addr] = by_name[name]
        # The IAT holds the thunk's fake code address, for code that loads it into a register.
        struct.pack_into('<I', img.mem, iat_addr - img.base, THUNK_BASE + by_name[name])
    hooks = {}
    late_id = N_THUNKS - 1      # 'late' hooks count down from the top of the table (see GAME_HOOKS)
    for addr, r in sorted(rec.replacements.items()):
        if r.get('hook'):
            pop = r.get('pop', 0)
            if pop is None:
                # A guarded function pops what it popped: read it from its own ret.
                fn = rec.funcs[addr]
                rets = [b.tail_insn for b in fn.blocks.values() if b.kind == 'ret']
                pop = (rets[0].ops[0].imm & 0xFFFF) if rets and rets[0].ops else 0
            if r.get('late'):
                tid = late_id
                late_id -= 1
            else:
                tid = thunk_id
                thunk_id += 1
            hooks[r['hook']] = {'id': tid, 'addr': addr, 'pop': pop}
            if r.get('wrap'):
                hooks[r['hook']].update(kind='wrap', conv=r['conv'])     # + body, the table index, below
            ctx.func_idx[addr] = ctx.thunk_first + tid
            names[tid] = 'hook!' + r['hook']
    first_free_thunk = thunk_id

    # Replacement bodies.
    body_list = []
    for addr, r in sorted(rec.replacements.items()):
        if r.get('body'):
            ctx.func_idx[addr] = next_idx
            next_idx += 1
            body_list.append((addr, r))
    # Lifted functions.
    order = sorted(rec.funcs)
    kept_bodies = {}
    for a in order:
        if a in rec.replacements:
            kept_bodies[a] = next_idx   # direct calls go to the hook, the code map to the body
        else:
            ctx.func_idx[a] = next_idx
        next_idx += 1

    # Emit in index order.
    for name, tidx, loc, code in helpers:
        mod.add_func(tidx, loc, code.b, 'rt_' + name)
    c = Code()
    c.op(UNREACHABLE)
    mod.add_func(ctx.type0, [], c.b, 'BAD_INDIRECT_CALL')
    for tid in range(N_THUNKS):
        c = Code()
        c.i32(tid)
        c.get(0)
        c.get(1)
        c.get(2)
        c.get(3)
        c.call(host_imp)
        c.set(1)
        c.get(0)
        c.i32(POP_TABLE + tid * 4)
        c.mem(I32_LOAD)
        c.op(I32_ADD)
        c.i32(4)
        c.op(I32_ADD)
        c.get(1)
        mod.add_func(ctx.type0, [], c.b, names.get(tid, 'thunk_%d' % tid).replace('!', '_'))
    # __call(addr, esp, eax, ecx, edx) -> eax, with the new esp in G_ESP
    t = mod.add_type([I32, I32, I32, I32, I32], [I32])
    c = Code()
    c.get(1); c.get(2); c.get(3); c.get(4)
    c.get(0); c.i32(MAP_LO); c.op(I32_SUB); c.i32(1); c.op(I32_SHL); c.i32(CODE_MAP); c.op(I32_ADD); c.mem(I32_LOAD16_U)
    c.call_indirect(ctx.type0)
    c.set(2)
    c.gset(G_ESP)
    c.get(2)
    mod.add_func(t, [], c.b, '__call')
    for addr, r in body_list:
        c = Code()
        r['body'](ctx, c)
        mod.add_func(ctx.type0, r.get('locals', []), c.b, r['name'])

    stats = Counter()
    failed = []
    lifted = 0
    for a in order:
        fn = rec.funcs[a]
        try:
            if not fn.fpu_ok:
                raise Unsupported('x87 analysis: ' + '; '.join(fn.notes))
            body = L.FnLifter(ctx, fn).run()
        except (Unsupported, IndexError, KeyError, TypeError, ValueError, AttributeError) as e:
            e = '%s: %s (fpu in=%d out=%d)' % (type(e).__name__, e, fn.fpu_in, fn.fpu_out)
            failed.append((fn.name, str(e)))
            c = Code()
            c.op(UNREACHABLE)
            body = bytes(c.b)
            rec.problems['unsupported'].append(fn.name + ': ' + str(e))
        else:
            lifted += 1
        if fn.mode_b:
            stats['mode_b'] += 1
        mod.add_func(ctx.type0, LOCALS_DECL, body, '%s_%08x' % (fn.name.replace('@', '_').replace('~', '_').replace('<', '').replace('>', ''), a) if not fn.name.startswith('FUN_') else fn.name)
    print('lifted', lifted, 'failed', len(failed), '%.1fs' % (time.time() - t0))
    rec.problems['failed'] = ['%s: %s' % x for x in failed]
    for name, why in failed[:40]:
        print('  FAIL', name, why)

    # Table: 0 = bad call, then thunks, replacement bodies and lifted functions.
    table = [badcall_idx] + [ctx.thunk_first + k for k in range(N_THUNKS)]
    code_map = [[THUNK_BASE + k, 1 + k] for k in range(N_THUNKS)]
    for addr, idx in sorted(ctx.func_idx.items()):
        if addr in kept_bodies:
            continue
        if idx < ctx.thunk_first + N_THUNKS:
            code_map.append([addr, 1 + idx - ctx.thunk_first])
            continue
        code_map.append([addr, len(table)])
        table.append(idx)
    guard_bodies = {}
    for addr, idx in sorted(kept_bodies.items()):
        if rec.replacements[addr].get('guarded'):
            # by address (calls through pointers, window procedures) the guard runs too; the host
            # reaches the body through its table slot
            code_map.append([addr, 1 + ctx.func_idx[addr] - ctx.thunk_first])
            guard_bodies[addr] = len(table)
        elif rec.replacements[addr].get('wrap'):
            # the same for a wrap: the hook gets every call, the body is its table slot (meta.hooks[name].body)
            code_map.append([addr, 1 + ctx.func_idx[addr] - ctx.thunk_first])
            hooks[rec.replacements[addr]['hook']]['body'] = len(table)
        else:
            code_map.append([addr, len(table)])
        table.append(idx)
    mod.table_size = len(table)
    if len(table) > 65535:
        raise SystemExit('table too large for 16-bit code map')
    mod.elems.append((0, table))
    mod.mem_pages = MEM_PAGES

    # Data: every non-code section as non-zero runs.
    for name, va, vsize, rawptr, rawsize in img.sections:
        if name == '.text':
            continue
        data = bytes(img.mem[va - img.base:va - img.base + min(max(vsize, rawsize), len(img.mem) - (va - img.base))])
        i = 0
        n = len(data)
        while i < n:
            while i < n and data[i] == 0:
                i += 1
            if i >= n:
                break
            j = i
            zeros = 0
            k = i
            while k < n:
                if data[k] == 0:
                    zeros += 1
                    if zeros >= 64:
                        break
                else:
                    zeros = 0
                    j = k + 1
                k += 1
            mod.data.append((va + i, data[i:j]))
            i = k
    # Absolute references into .text that read data there.
    text_refs = set()
    for fn in rec.funcs.values():
        for b in fn.blocks.values():
            for i in b.insns:
                if i.mn in ('jmp', 'call'):
                    continue
                for o in i.ops:
                    if o.type == R.X86_OP_MEM and (o.disp & 0xFFFFFFFF) and img.is_text(o.disp & 0xFFFFFFFF):
                        text_refs.add((i.addr, o.disp & 0xFFFFFFFF))
    if text_refs:
        # Index tables of sparse switches sit in .text after the function: copy them to the same address.
        ranges = []
        for ia, ta in sorted(text_refs, key=lambda x: x[1]):
            lo, hi = ta, min(ta + 2048, next(h for l, h in img.text_ranges if l <= ta < h))
            if ranges and lo <= ranges[-1][1]:
                ranges[-1][1] = max(ranges[-1][1], hi)
            else:
                ranges.append([lo, hi])
        for lo, hi in ranges:
            mod.data.append((lo, bytes(img.mem[lo - img.base:hi - img.base])))
        print('copied', len(ranges), 'data tables from .text,', sum(h - l for l, h in ranges), 'bytes')
    # Expose globals and memory.
    mod.exports.append(('memory', 2, 0))
    mod.exports.append(('table', 1, 0))
    for nm, g in (('g_edx', G_EDX), ('g_st0', G_ST0), ('g_st1', G_ST1), ('g_cw', G_CW), ('g_esp', G_ESP), ('g_a', G_A),
                  ('g_ebx', R.G_EBX), ('g_ebp', R.G_EBP), ('g_esi', R.G_ESI), ('g_edi', R.G_EDI)):
        mod.exports.append((nm, 3, g))
    mod.exports.append(('__call', 0, call_idx))
    wasm = mod.encode(with_names=not args.no_names)
    os.makedirs(args.out, exist_ok=True)
    with open(os.path.join(args.out, 'rcskspel.wasm'), 'wb') as f:
        f.write(wasm)

    meta = {
        'source': 'rcskspel.dat',
        'modules': [{'name': m['name'], 'file': os.path.basename(m['path']), 'sha256': m['sha256'], 'base': m['base'],
                     'preferredBase': m['preferred'], 'size': m['size'], 'entry': m['entry'], 'isDll': m['is_dll'],
                     'exports': m['exports']} for m in img.modules],
        'entry': img.entry,
        'imageBase': img.base,
        'layout': {
            'POP_TABLE': POP_TABLE, 'STACK_LOW': STACK_LOW, 'STACK_TOP': STACK_TOP, 'TIB_BASE': TIB_BASE,
            'THUNK_BASE': THUNK_BASE, 'N_THUNKS': N_THUNKS, 'CODE_MAP': CODE_MAP, 'MAP_LO': MAP_LO,
            'HEAP_BASE': HEAP_BASE, 'MEM_PAGES': MEM_PAGES, 'IMAGE_END': img.end,
        },
        'thunks': {str(k): v for k, v in names.items()},
        'hooks': hooks,
        'firstFreeThunk': first_free_thunk,
        # the translated module itself: part of a save state's build identity (source/host/snapshot.js),
        # since the same RcHcGame.dat with other hooks or another code generator is another build
        'wasmSha256': hashlib.sha256(wasm).hexdigest(),
        'wasmSize': len(wasm),
        'fpuPrecisionBits': args.fpu_pc,
        'eh': {'stubs': {str(k): v for k, v in eh_stubs.items()}, 'guardBodies': {str(k): v for k, v in guard_bodies.items()}},
        'patches': patches,
    }
    # The code map is large: it goes to its own binary file (u32 address, u32 table index pairs).
    with open(os.path.join(args.out, 'rcskspel.codemap.bin'), 'wb') as f:
        f.write(b''.join(struct.pack('<II', a, i) for a, i in code_map))
    with open(os.path.join(args.out, 'rcskspel.meta.json'), 'w') as f:
        json.dump(meta, f)

    # Compile report for debugging. Not used at run time.
    report = {
        'functions': len(rec.funcs),
        'instructions': sum(f.insn_count for f in rec.funcs.values()),
        'mode_b': stats['mode_b'],
        'wasm_bytes': len(wasm),
        'problems': {k: v for k, v in rec.problems.items()},
        'fpu_input_functions': sorted('%08x %s in=%d out=%d' % (a, f.name, f.fpu_in, f.fpu_out) for a, f in rec.funcs.items() if f.fpu_in),
        'fpu_return_functions': sum(1 for f in rec.funcs.values() if f.fpu_out),
        'fpu_notes': sorted('%08x %s: %s' % (a, f.name, n) for a, f in rec.funcs.items() for n in f.notes),
        'indirect_float_calls': sum(len(f.icall_ret) for f in rec.funcs.values()),
    }
    rep_dir = os.path.join(ROOT, 'tools', 'recomp', 'out')
    os.makedirs(rep_dir, exist_ok=True)
    with open(os.path.join(rep_dir, 'report.json'), 'w') as f:
        json.dump(report, f, indent=1)
    print('wasm %.1f MB, %.1fs' % (len(wasm) / 1e6, time.time() - t0))
    for k, v in rec.problems.items():
        print('problem', k, len(v), v[:12])
    print('fpu return functions', report['fpu_return_functions'], 'indirect float calls', report['indirect_float_calls'])
    # Callers of functions that failed analysis, so hand-written helpers can be found.
    callers = Counter()
    for fn in rec.funcs.values():
        for b in fn.blocks.values():
            for i in b.insns:
                if i.mn == 'call' and i.ops[0].type == R.X86_OP_IMM:
                    callers[i.ops[0].imm & 0xFFFFFFFF] += 1
    bad = sorted((a for a, f in rec.funcs.items() if not f.fpu_ok), key=lambda a: -callers[a])
    print('x87-bad functions:', len(bad))
    for a in bad[:80]:
        print('  %08x callers=%d %s %s' % (a, callers[a], rec.funcs[a].name, '; '.join(rec.funcs[a].notes)))


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', default=os.path.join(ROOT, 'public', 'game'))
    ap.add_argument('--no-names', action='store_true')
    ap.add_argument('--no-ret-store', action='store_true')
    ap.add_argument('--fpu-pc', type=int, default=53, choices=(24, 53))
    ap.add_argument('--trace', default='', help='comma-separated function addresses that call env.trace on entry')
    build(ap.parse_args())
