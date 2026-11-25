// The JS reconstruction's race safeguards, put around the original code (docs/intentional-differences.md):
//   1. stuck recovery: source/host/stuck.js (its player-stuck-recovery.js and the rescue around it);
//   2. the NPC velocity guard (its npc-velocity-safety.js, race-simulation.js:419, 442-446) around 0x406940;
//   3. the original's debug and cheat keys only with the cheats option (OPT.CHEATS): the JS port has none of them
//      (its research-streams.md:160; input.js:64-72 reacts to the bound keys, Esc, P, Space, 1-4 and the result keys);
//      and P and Esc never drive when bound (with or without the option: it is the JS port's key handling, not a cheat);
//      and the pad's and the touch wheel's actions reach the keyboard device's bindings while a driving key is held (the
//      JS port's per-action merge of its sources: BINDING_SLOTS below).
// The pause entry (no extra object pass and render on the P pass, JS port docs/original-comparison-2026-10-28.md:964-969)
// is a byte patch in the build (tools/recomp/build.py GAME_PATCHES, 0x42f6d8), not here.
//
// Installed by Race.instantiate (race.js); beforePass() runs before every pass of WinMain's loop, after host.beforeTick.
// host.cheats (the game worker sets it from CTRL.OPTIONS before every pass; undefined counts as on, so the Node checks
// keep the race's own keys) is read once per pass and holds for the whole pass: the Ctrl+E+N page waits inside a pass
// for a digit 1..9 (`while (!key('1') ...)` from 0x42a020), and a key that stopped answering half way would hang it.
import { installStuck } from './stuck.js';

// --- 3. keys -------------------------------------------------------------------------------------------------------
// Every GetAsyncKeyState call of the race is in 0x4b3830 (the Shift rule, cdecl, -1 or 0; 245 direct calls plus 18 in
// bytes Ghidra did not disassemble) or in 0x4b3880 (the bound driving keys, 8 calls from 0x42ee60): the only two
// references to its import slot 0x4d21cc (a raw scan of rcskspel.dat; no stored pointers to or jumps into either).
// The recompiler stores every call's return address at [esp] (tools/recomp/lift.py, build.py debug_ret, the default),
// so the import sees which of them calls it: 0x4b3830 returns to 0x4b3848/0x4b3850 (CALL EDI at 0x4b3846/0x4b384e,
// a key with 0x100) or 0x4b3860/0x4b3868 (0x4b385e/0x4b3866), and with push esi, push edi and the argument on its
// stack, 0x4b3830's own caller is at [esp + 0x10]. 0 mismatches against the static call sites over boot, 40 racing
// passes, a pause and a cheat (the safeguards design's keyfilter probe).
export const KEYDOWN_RETURNS = new Set([0x4b3848, 0x4b3850, 0x4b3860, 0x4b3868]);
export const BINDING_RETURNS = new Set([0x4b38d2, 0x4b38da, 0x4b38e8, 0x4b38f0]);   // 0x4b3880: not the cheats filter
// It filters only P and Esc: 0x4b3880's key polls (CALL EDI at 0x4b38d8 and 0x4b38ee, PUSH ESI with the bound key; the
// other two poll Shift, 0x10) answer "up" for them, so a binding on P (or Esc, which the JS reconstruction's settings
// never keep, its settings.js:18) does not drive, as the JS port handles P and Esc before the bindings (its
// input.js:64-65). They still pause and open the requester through 0x42f9c0's own polls (0x42ffda, 0x42ffac).
export const BINDING_KEY_RETURNS = new Set([0x4b38da, 0x4b38f0]);
export const NOT_DRIVING = new Set([0x1b, 0x50]);
// The pad and the touch wheel next to a held driving key. The JS port merges its sources per action (its
// input.js:33-42) and drives digitally while a keyboard source is there (:49-50), every action > 0 then pressed
// (race-simulation.js:390-392): ArrowLeft with the pad's RT steers and accelerates. The game worker chooses the
// keyboard device while a driving key is held (worker.js), and 0x4b3880's polls from 0x42ee60 answer "down" for an
// action the pad or the wheel works (host.joyAction(slot), the worker's virtual joystick), also under Shift, as the JS
// port's Shift rule drops only its keyboard sources (input.js:34-41): for such a slot the Shift poll answers what lets
// the binding through (0x4b38e6, return 0x4b38e8: an unmodified binding is "up" while Shift is down; 0x4b38d0, return
// 0x4b38d2: a binding with 0x100 needs Shift down) and the key poll "down" (0x4b38ee / 0x4b38d8). The slot is 0x4b3880's
// own return address, at [esp + 0x14] in all four polls (push ebx, esi, edi, then the poll's argument and return
// address): 0x42ee60's calls at 0x42eeaa, 0x42eec8, 0x42eee5, 0x42ef01, 0x42ef1d and 0x42ef3a return to these, in its
// table's order 0x53a5b8 + 4k (left, right, accelerate, brake, bonus, handbrake: race-keys.js TABLE_ORDER); its calls for
// the unused slots 6 and 7 (0x42ef5b, 0x42ef77) are left as they are. Only 0x42ee60 calls 0x4b3880 (calls.tsv), and only
// for the keyboard device (from 0x433870; 0x433cf0 is the digital pad's, device 2, which the race never uses).
export const BINDING_SLOTS = new Map([[0x42eeaf, 0], [0x42eecd, 1], [0x42eeea, 2], [0x42ef06, 3], [0x42ef22, 4], [0x42ef3f, 5]]);
const SLOT_ANSWER = new Map([[0x4b38d2, 0x8000], [0x4b38da, 0x8000], [0x4b38e8, 0], [0x4b38f0, 0x8000]]);
// The calls of 0x4b3830 whose keys the JS port also reacts to (call addresses; the stack holds call + 5).
export const KEY_ALLOW_CALLS = Object.freeze([
  0x41d927, 0x41d948, 0x41d969, 0x41d9a7,                          // 0x41d920 cameras 1, 2, 3, 4 (native-camera.js:51)
  0x41fdf2, 0x41fe00, 0x41fe0e, 0x41fe1e, 0x41fe2c, 0x41fe3a,      // 0x41fd90 phase 3: Esc/Enter/Space and their release
  0x420914, 0x420922, 0x420930,                                    // 0x420850 phase 6: Esc/Enter/Space
  0x42f226, 0x42f234, 0x42f243, 0x42f255, 0x42f262,                // 0x42f220 pause: P released, then any key 0..255
  0x42f295, 0x42f2a3, 0x42f2e2, 0x42f2f0, 0x42f30d, 0x42f31b, 0x42f32f, 0x42f33d, // 0x42f290 Esc released, J/Y/N/Esc
  0x42fc66, 0x42ffac, 0x42ffda,                                    // 0x42f9c0 Space (horn), Esc, P
  0x433d71,                                                        // 0x433cf0 Space of the digital pad (device 2, unused)
  0x473956, 0x47396b, 0x47404e, 0x474070, 0x474095, 0x4743b6, 0x4743c8, // the quit requester 0x473820/0x474040/0x4743b0
  0x4b9f01, 0x4b9f15,                                              // 0x4b9ea0 mouse buttons (requester clicks)
]);
const KEY_ALLOW = new Set(KEY_ALLOW_CALLS.map((a) => a + 5));
// The pause loop and the Esc requester (0x42f220, 0x42f290, 0x473820..0x4743b0): a pass that polls here waited in them.
const WAIT_CALLS = [0x42f226, 0x42f234, 0x42f243, 0x42f255, 0x42f262, 0x42f295, 0x42f2a3, 0x42f2e2, 0x42f2f0, 0x42f30d,
  0x42f31b, 0x42f32f, 0x42f33d, 0x473956, 0x47396b, 0x47404e, 0x474070, 0x474095, 0x4743b6, 0x4743c8];
const WAIT_RETURNS = new Set(WAIT_CALLS.map((a) => a + 5));
// Without the option the other 224 calls answer "up" for both their Shift poll and their key: F, Tab and Ctrl+Space+R
// (0x414160), the tweak menus 0x419230..0x41b350 and their keys in 0x41d920, 0x41ecd0, 0x42f9c0 (F7, F8, Q, W, E, A, S,
// M, numpad +/-), 0x4303ff (F12) and 0x466ca0, D in 0x42f9c0 (0x42ff6b: cycles SndGfx overlay_detail 0x53ba44, which
// nothing else reads, and waits for its release), the cheats of 0x429a90 (Ctrl+W+D and Ctrl+U+P fog, Ctrl+Enter+Space a
// random bonus, Ctrl+F+I the finish 0x42f740(3), Ctrl+W+F the fill mode, Ctrl+E+N the debug pages), G held at load
// (0x431bfb), numpad 7/8/9 (0x489d20: stream flags), F1-F6 (0x4524c0, its gate 0x543d28 is never written), WinMain's
// own (never called here) and code nothing reaches (GUI pages, 0x442b00, 0x46e5b0, 0x46f980, 0x470360/0x470390,
// 0x47c1b0, 0x4bbe70). The full table: evidence/checks/safeguards/key-sites.txt.

// --- 2. NPC velocity guard ---------------------------------------------------------------------------------------------
// 0x406940(ai) (cdecl, RET 0x406b37; called from the NPC callback 0x40b0b0 at 0x40b0f2 and from 0x4022b4) runs 0x4062b0
// -> 0x406100, which multiplies all three linear speeds of the racer's body by (1 + f) whenever one of them is >= 30
// and caps only the forward one at 80: the vertical one can grow until its float store overflows. The JS port's guard
// (npc-velocity-safety.js:82-92) sets to 0 only a speed that was finite before the dispatch and is not after, so a value
// that was already not finite is not hidden. In the recomp an overflow does not trap (wasm floats; fist/ftol saturate),
// so this is parity, not stability: after an overflow the original's `30 <= vy` stays true and 0x406100 then scales the
// other two on every call (safeguards design, NPC probes on NED and ENG).
const LINEAR = [0x9c, 0xa0, 0xa4];

/** Installs the safeguards on a Race's machine; returns { beforePass(), stats, stuck }. */
export function installSafeguards(m, host) {
  const { u32, i32, f32 } = m;
  const stats = { keys: 0, bindingPolls: 0, joyPolls: 0, npc: 0, npcEvents: [], unknownCallers: 0 };
  let cheats = host.cheats !== false;
  let waited = false;

  const id = m.thunkId('USER32.DLL!GetAsyncKeyState');
  const keyState = m.thunks[id];
  m.thunks[id] = (esp, ecx, edx, eax) => {
    const ret = u32[esp >> 2];
    if (KEYDOWN_RETURNS.has(ret)) {
      const site = u32[(esp + 0x10) >> 2];
      if (WAIT_RETURNS.has(site)) waited = true;
      // site 0: host code called 0x4b3830 itself (m.call's return address)
      if (!cheats && site !== 0 && !KEY_ALLOW.has(site)) {
        stats.keys++;
        if (host.clock) host.clock.poll();   // still a poll for the clock's naps (win32.js VirtualClock.poll)
        return 0;
      }
    } else if (BINDING_RETURNS.has(ret)) {
      // the pad's or the wheel's action for this binding (BINDING_SLOTS; host.joyAction from the game worker)
      const slot = host.joyAction ? BINDING_SLOTS.get(u32[(esp + 0x14) >> 2]) : undefined;
      if (slot !== undefined && host.joyAction(slot)) {
        stats.joyPolls++;
        if (host.clock) host.clock.poll();
        return SLOT_ANSWER.get(ret);
      }
      if (BINDING_KEY_RETURNS.has(ret) && NOT_DRIVING.has(u32[(esp + 4) >> 2] & 0xFF)) {
        stats.bindingPolls++;
        if (host.clock) host.clock.poll();
        return 0;
      }
    } else {
      // a build without return addresses (--no-ret-store) or a new caller: no filter, said once
      if (!stats.unknownCallers++) host.log('safeguards: GetAsyncKeyState from 0x' + ret.toString(16) + ', keys not filtered');
    }
    return keyState(esp, ecx, edx, eax);
  };

  const hooked = (name) => { try { m.thunkId('hook!' + name); return true; } catch { return false; } };
  if (hooked('NpcPrepare')) m.wrap('NpcPrepare', (esp, ecx, edx, eax, next) => {
    const ai = i32[(esp + 4) >> 2];
    // 0x417e90: an index outside 0..[0x508610]-1 is the player; else the racer table 0x5081bc (stride 0x70)
    const who = ai < 0 || ai >= i32[0x508610 >> 2] ? i32[0x53be28 >> 2] : i32[(0x5081bc + ai * 0x70) >> 2];
    const body = u32[0x67ee20 >> 2] + who * 0xd0;
    const v0 = f32[(body + 0x9c) >> 2], v1 = f32[(body + 0xa0) >> 2], v2 = f32[(body + 0xa4) >> 2];
    const r = next(esp, ecx, edx, eax);
    const before = [v0, v1, v2];
    for (let k = 0; k < 3; k++) {
      const at = (body + LINEAR[k]) >> 2;
      if (!Number.isFinite(before[k]) || Number.isFinite(f32[at])) continue;
      stats.npc++;
      if (stats.npcEvents.length < 32) stats.npcEvents.push({ racer: ai, body: who, offset: LINEAR[k], previous: before[k], rejected: String(f32[at]) });
      host.log(`safeguards: NPC ${ai} speed +0x${LINEAR[k].toString(16)} ${f32[at]} after 0x406940, set to 0`);
      f32[at] = 0;
    }
    return r;
  });

  // a module built before hook!RescueUpdate (tools/recomp/build.py GAME_HOOKS) has no recovery
  const stuck = hooked('RescueUpdate') ? installStuck(m, host, { dt: host.tickSeconds || 0.025 }) : { stats: null, beforePass() {} };

  return {
    stats, stuck,
    /** Before a pass: the cheats option for this pass, then the stuck detector (with whether the last pass waited). */
    beforePass() {
      cheats = host.cheats !== false;
      const paused = waited;
      waited = false;
      stuck.beforePass(paused);
    },
  };
}
