# The recompiler for rcskspel.dat

`tools/recomp/` is a copy of RedCat Spookkasteel's recompiler (`RCSPOOK_MAIN/tools/recomp`, 4,745 lines:
`build.py`, `lift.py`, `recompile.py`, `replacements.py`, `wasmgen.py`). `build.py` differs, and three lines of
`recompile.py` and `lift.py` for the wrap hooks (below).

## Changes to build.py

| Change | Why |
|---|---|
| Module list: `('rcskspel.dat', 'rcskspel.dat', 'GAME', False)` | The race executable. No relocations (Characteristics 0x10F), so it stays at 0x400000 and its data sections get the recompiler's word-by-word code-pointer scan, as A2's `spel.dat` did |
| Inputs from `../RedCat Superkarts/original-source/` (`inputs/rcskspel.dat`, `modules/rcskspel.dat/functions.tsv` and `instructions_outside_functions.tsv`), `SUPERKARTS_ORIGINAL_SOURCE` overrides; SHA-256 checked (`68e5c913…`) | The SuperKarts export has the same TSV format as Spookkasteel's |
| `NORETURN_SIGNATURES`: `__CxxThrowException@8` found by its bytes (0x4BFC77 here; the same signature finds A2's 0x5593C0) | It ends in `ret 8` after `RaiseException`, so the recompiler's rule (trust only functions without a ret) cannot see it. Without it, decoding runs on after three calls into jump tables (0x437EA0, 0x467E30, 0x46C910) and 13 more functions fail |
| `GAME_HOOKS = {0x4432A0: WinMain, pop 16, keep_body}` | WinMain's loop busy-waits on GetTickCount for 25 ms per pass. The host runs init_main and start_game itself and then one pass per tick (`source/host/race.js`). keep_body keeps its callees reachable. This also replaces WinMain's own `eh_` guard: its three catch blocks all end in the fatal path 0x4afee0 |
| `GAME_HOOKS` wraps (below) | Places where the JS reconstruction's improvements sit around original code (kart shadow, rescue, NPC step, bonus pickup, the render: kart parts and the pause picture) |
| `GAME_PATCHES` (below) | The pause entry the JS reconstruction has (docs/intentional-differences.md) |
| Output names `rcskspel.wasm`, `rcskspel.meta.json`, `rcskspel.codemap.bin`; `source: rcskspel.dat` | |

Outside build.py, `recompile.py` (`call_fpu`, the tail case of `fpu_pass`) and `lift.py` (`x_tail`) take a wrap's x87
summary from its body, as they did before it was a hook; for every other replacement they still use its `fpu` entry.

Kept from Spookkasteel: the memory layout (thunk base 0x3F0000, 4,096 thunks, heap from 0x1800000, 192 MB),
`--fpu-pc 53` (the 53-bit x87 precision the SuperKarts research established for the original), the
return-address store (no `--no-ret-store` until it is shown safe here), and the C++ exception scheme:
every function that owns a try block runs behind a guard thunk and `source/host/eh.js` runs the original
unwind and catch funclets.

## Result (2026-11-25)

| | |
|---|---:|
| Functions discovered | 5,620 |
| Instructions | 238,224 (238,238 before the pause patch skipped 15 and added one) |
| Lifted | 5,604 |
| Failed | 16 |
| Wasm | 4,020,768 bytes |
| Build time | 6.2 s |

- CRT replacements matched by signature: `__ftol`, `_CIasin`, `_CIpow`, `_fmod`, `_CIfmod`, `_CIacos`,
  `_memcpy` (2), `_memset`, `_strrchr`, `_chkstk`, `__EH_prolog`.
- C++ exceptions: 411 handler stubs, 24 with try blocks, 21 guarded functions (WinMain is a hook now),
  1,543 unwind funclets, 53 catch funclets, 23 continuations.
- **The 16 failures:** 15 x87 special-value handlers of the C runtime (0x4BFD64, 0x4C1EC4–0x4C1F66,
  0x4C4D71–0x4C5F3C), reached only through the CRT's dispatch tables at 0x5029E0–0x503070 from the
  replaced `_CIfmod`/`_CIasin` family (static references; none was hit in the runs so far), and data
  decoded as code at 0x4C4F52.
- Six functions have irreducible control flow and use the recompiler's fallback mode.

## Hooks

Two kinds, both in `GAME_HOOKS` (`pop` is what the function's ret removes):

- **replace** (`keep_body`): direct calls go to the host thunk `hook!Name`; the code map (calls by address, the host's
  `m.call`) still reaches the original body. Unbound, the thunk stops the race (`onUnimplemented`). WinMain.
- **wrap** (`'wrap': True`): every call, direct, tail, by address or `m.call`, goes to `hook!Name`, and the body keeps a
  table slot of its own (`meta.hooks.Name = {id, addr, pop, kind: 'wrap', conv, body}`), as the C++ guards keep theirs
  (`meta.eh.guardBodies`). `source/host/machine.js` binds every wrap to its body when the instance is made, so until host
  code wraps it the game runs exactly as the original, with any host. The build stops when the declared pop is not
  every ret's (the thunk returns esp + pop + 4 whatever the body did), when the function leaves through a tail jump,
  owns a try block (it is a `hook!eh_` guard already: wrap that) or reads ebx/ebp/esi/edi as inputs (those travel in
  globals that host calls before the body could change). Wraps take thunk ids from the top of the table (4095 down),
  so the import, guard and WinMain ids and `firstFreeThunk` (156: the COM methods' thunk addresses the game stores in
  its memory) stay as they were.

| Address | Thunk | Kind | Pop | Convention | Callers (export) | For |
|---|---|---|---:|---|---|---|
| 0x4432a0 | `hook!WinMain` | replace | 16 | stdcall (hInstance, hPrev, cmdLine, nCmdShow) | CRT start-up | the host's loop (`race.js`) |
| 0x406940 | `hook!NpcPrepare` | wrap | 0 | cdecl (ai index), RET at 0x406b37 | 0x40b0f2 (NPC callback 0x40b0b0), 0x4022b4 | NPC velocity guard: holds 0x4062b0 → 0x406100, which scales +0x9c/+0xa0/+0xa4 (JS race-simulation.js:419, :442-446) |
| 0x4260c0 | `hook!KartShadow` | wrap | 0 | cdecl (engine slot), RET at 0x4264b1 | only by address: [0x6802c4] (set by 0x4264c0 through 0x493190), called by 0x4931a0 from 0x4918f0/0x4916f0 right before the kart | surface shadow grid; no shadow in free flight (JS driving-view.js:228). No pointer swap needed: the code map sends the call to the hook |
| 0x430020 | `hook!Render` | wrap | 0 | no arguments, RET at 0x43046a; first instruction MOV EAX,[0x53ba04] (no register inputs) | 0x42f663 (HANDLE_GAME's render, return 0x42f668), 0x42f703 (the pause entry's, return 0x42f708); free flight's `m.call` (return 0) | `source/host/render-replay.js`: the kart parts and aging draws put back before the renders that no object pass precedes |
| 0x4514e0 | `hook!BonusPickUp` | wrap | 8 | thiscall (ecx = bonus object; ESI, EDI of the caller), RET 8 at 0x451588/0x451634 | 0x45418f (0x4540c0) | pickup exclusion after a soft-lock relocation (JS race-simulation.js:487, 529-530) |
| 0x48ca60 | `hook!RescueUpdate` | wrap | 0 | thiscall (ecx = rescue entry, 0x11b0 bytes), RET at 0x48d012/0x48d207/0x48d342 | 0x48db19 (0x48db00, from HANDLE_GAME at 0x42f618) | player stuck recovery: its grow-frame-0 destination (JS native-rescue.js:228-233) |
| 21 functions | `hook!eh_XXXXXXXX` | guard (`eh.js`) | own ret | as the function | all | C++ exceptions; also wrappable, e.g. the HUD pass 0x467d30 and draw 0x4614d0 in `race.js` |

**Binding a wrap (host code).** `m.wrap(name, fn)` puts `fn(esp, ecx, edx, eax, next)` in front of what was bound before
(at first the body; wrappers chain, the last bound runs first). esp points at the return address, so the first stack
argument is `m.u32[(esp + 4) >> 2]`; `fn` returns eax; `next(esp, ecx, edx, eax)` runs the rest of the chain and the body
and returns its eax. The pop stays the function's, also when `fn` skips `next`. ST0 (`m.gSt0`) and edx (`m.gEdx`) are left
as the body left them. Outside a hook `m.callOriginal(addr, args, ecx, edx)` runs a wrap's body past every wrapper (for
other addresses it is `m.call`); `m.call(addr)` and the code map (`u16[CODE_MAP + (addr - MAP_LO) * 2]`) reach the hook.

```js
// count the kart shadows of one pass, and skip the player's (as free flight does)
m.wrap('KartShadow', (esp, ecx, edx, eax, next) => {
  const slot = m.u32[(esp + 4) >> 2];
  if (flying && slot === m.i32[0x53be28 >> 2]) return 0;
  shadows++;
  return next(esp, ecx, edx, eax);
});
// a thiscall: the entry is ecx
m.wrap('RescueUpdate', (esp, entry, edx, eax, next) => { const r = next(esp, entry, edx, eax); /* after the body */ return r; });
```

## Byte patches

`GAME_PATCHES` (address → original bytes, new bytes, what) is applied to the image right after the SHA-256 check, before
anything is decoded. The build checks the original bytes (and that they are in .text) and stops on a mismatch, and prints
and records each patch with its disassembly in `meta.patches`. Lifting decodes the patched image (recursive descent from
the entries); .text is not emitted as data, so a patch changes code only.

| Address | Original | New | What |
|---|---|---|---|
| 0x42f6d8 | `8B 0D D0 B9 53` (first 5 bytes of MOV ECX,[0x53b9d0]) | `E9 26 00 00 00` (JMP 0x42f703) | **Pause entry.** On the pass where P or Esc set 0x53b9f8 (0x42f9c0), HANDLE_GAME 0x42f4c0 runs one more object pass 0x491530 (pushes at 0x42f6e3/0x42f6ea/0x42f6fa, ADD ESP,0xC at 0x42f700) before render 0x430020, present 0x430470 and the pause 0x42f350. The jump skips only the object pass, as the JS reconstruction pauses without it (docs/intentional-differences.md). The render and present stay: 0x42f9c0's P branch sets the "pauze" notice (0x430610(1)) after the pass's own render, and this render is the only one that draws it before the pause loop removes it (0x430610(2) at 0x42f27d). The skipped code is stack-neutral, no reference targets 0x42f6d9..0x42f702, and the 00 left at 0x42f6dd is dead (a linear decode resyncs at 0x42f6e3) |

## Checks of the 2026-11-25 hook build

Results and scripts in `evidence/checks/recomp-hooks/` (README.txt there).

- The wasm against the build before it, function by function: only the bodies of HANDLE_GAME 0x42f4c0 (the patch) and of
  the four direct callers of wraps (0x402260, 0x40b0b0, 0x4540c0, 0x48db00: one call index each) differ; the element
  section differs in order.
- The two builds in lockstep in Node (same host, Up held, some steering), with counting `m.wrap` wrappers on all four
  wraps: game memory identical apart from the pop table and the code map after 3,000 passes on Nederland, 2,000 on
  France and 1,500 on Germany (there with KartShadow calling `m.callOriginal` instead of `next`, the stack left out); the
  wraps ran (Nederland: NpcPrepare 12,000, KartShadow 8,263, BonusPickUp 4, RescueUpdate 120 calls).
- The pause entry: on the P pass the old build polled 0x414160's keys again between P's poll (CALL at 0x42ffda) and the pause's (0x42f226),
  the new one does not (`pause-cmp.json`); that pass draws 217 instead of 439 and flips once instead of twice; the pause, the quit
  requester (N goes on, J ends with exit code 0) and the race after them run as before
  (`evidence/checks/recomp-hooks/full-race-gaps/`).
- `node tools/run-headless.mjs --ticks 400 --gas` prints the same pose, draw, vertex and sound counts on both builds;
  `node --test tests/*.test.mjs` 14/14; `tools/check-input.mjs` (pause, requester, exit, finish) and
  `tools/check-runner.mjs` (three races, focus pause, suspend, pad lost) pass in Chromium.
- `m.call` of 0x430ff0 and of 0x4977d0 → 0x495fe0 → 0x496290 hands the height back in `m.gSt0` (Nederland, pass 400:
  -26.19 under the player, whose kart is at -26.67).
