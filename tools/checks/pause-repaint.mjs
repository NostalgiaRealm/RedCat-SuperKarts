#!/usr/bin/env node
// The held picture drawn again (source/host/render-replay.js repaint(), notice()), in Node on the recompiled race
// (tools/checks/full-race-gaps-lib.mjs, frames as tools/checks/kart-draws-lib.mjs records them):
//   pause    a P pause while racing, twice: once as the game runs it, once with three repaints from inside the pause loop
//            (from the GetAsyncKeyState import that 0x42f220 polls through 0x4b3830, where the game worker's
//            VirtualClock.idle runs): the first and the third (the HUD as before) draw the pause entry's picture draw
//            for draw, the second (the HUD laid out for a 9:16 drawing, hud-layout.js) the same scene with its HUD moved;
//            the race after the pause is draw for draw the same in both runs, and so is the game's memory outside the
//            stack (the frames' garbage below esp).
//   finish   the finish screen (phase 3, through the race's own cheat Ctrl+F+I), twice: once as it runs, once held for a
//            moment 40 passes into it with the original's "pauze" notice (0x430610(1)), a repaint, a repaint with a 9:16
//            HUD and the notice taken off again (0x430610(2)): the notice shows only while the special text is idle,
//            the repaint has the notice's draws on top of the HUD, and every pass after it until the race ends is draw for
//            draw the same as without it, race.ini too, and so are the game's globals (the heap keeps the notice's own
//            traces: its glyph meshes' last state and the allocator's lists).
//   gameover a Tijdrace without input until its game over (phase 6): "tijd is om!" (0x430610(7), no time limit) runs as
//            the special text the whole screen, so notice(true) leaves it (and shows nothing).
// Results in evidence/checks/pause-repaint.json. Exit code 1 when a check fails.
//   node tools/checks/pause-repaint.mjs [--only=pause,finish,gameover]
import { writeFileSync, mkdirSync } from 'node:fs';
import { join } from 'node:path';
import { createHash } from 'node:crypto';
import { makeRace, VK as K, SpinDetected, ROOT } from './full-race-gaps-lib.mjs';
import { recordFrames } from './kart-draws-lib.mjs';
import { HudLayout } from '../../source/host/hud-layout.js';
import { pinRace } from '../../source/host/race-setup.js';

const only = (process.argv.find((a) => a.startsWith('--only=')) || '').slice(7).split(',').filter(Boolean);
const want = (k) => !only.length || only.includes(k);
const results = {};
let failed = 0;
const check = (group, name, ok, detail) => {
  (results[group] ||= []).push({ name, ok: !!ok, ...(detail === undefined ? {} : { detail }) });
  if (!ok) failed++;
  console.log(`${ok ? 'ok  ' : 'FAIL'} [${group}] ${name}${detail === undefined ? '' : ' ' + JSON.stringify(detail)}`);
};
const GREEN = 600;
const frameKey = (f) => JSON.stringify(f);
const tryTick = (r) => { try { return r.tick() ? 'returned' : 'ended'; } catch (e) { if (e instanceof SpinDetected) return 'spin: ' + e.info.reason; throw e; } };

/** A race to the green light (cheats as the development page has them: the race's own keys answer). */
async function racing(opts = {}) {
  const r = await makeRace(opts);
  if (opts.raceType !== undefined) pinRace(r.vfs, { etappe: opts.etappe ?? 0, car: opts.car ?? 0, raceType: opts.raceType });
  r.race.boot();
  recordFrames(r);
  return r;
}
const toGreen = (r) => { let n = 0; while (r.state().phase !== 0 && n < GREEN) { r.tick(); n++; } };
/**
 * The game's memory outside the stack [STACK_LOW, STACK_TOP) (what lies below esp is the frames' garbage) and the object
 * draw count u32 0x6a5c84 (0x4a0d80 adds 1 per object drawn, INC at 0x4a1086..0x4a1091; the export reads it nowhere else,
 * so every render, the pause entry's too, moves it and nothing follows from it): its hash and that count.
 */
const DRAW_COUNT = 0x6a5c84;
const memoryHash = (r) => {
  const { STACK_LOW, STACK_TOP } = r.m.layout;
  const h = createHash('sha1');
  // the stack lies below the image (machine layout: stack 0x100000..0x3e0000, image from 0x400000, heap 0x1800000)
  h.update(r.m.u8.subarray(0, STACK_LOW));
  h.update(r.m.u8.subarray(STACK_TOP, DRAW_COUNT));
  h.update(r.m.u8.subarray(DRAW_COUNT + 4));
  return { hash: h.digest('hex').slice(0, 16), drawCount: r.u32(DRAW_COUNT) };
};
/** A HUD layout for a drawing of aspect a (the game worker's host.hudLayout, without the recorder's clip). */
const layoutFor = (r, a) => { const c = HudLayout.clipFor(a); return { layout: new HudLayout(r.m), xr: c.xr, yr: c.yr, aspect: a, scale: 1, insets: { left: 0, right: 0, top: 0, bottom: 0 }, controls: { left: 0, right: 0 }, clip: () => {} }; };
/** The special text's state (overlay 0x53a5f8 +0x94 -> +8; 1 while a text shows). */
const textState = (r) => { const t = r.u32(0x53a5f8 + 0x94); return t ? r.i32(t + 8) : null; };

// --- pause ---------------------------------------------------------------------------------------------------------------
if (want('pause')) {
  const run = async (repaint) => {
    const r = await racing();
    toGreen(r);
    // driving with the steering swung and the bonus now and then: skid marks, smoke and jet streams about
    for (let k = 0; k < 240; k++) { r.ctl.keys = new Set([K.UP, ...((k >> 6) % 2 ? [K.LEFT] : []), ...(k % 97 < 3 ? [K.CONTROL] : [])]); r.tick(); }
    let step = 0, polls = 0, done = false;
    const marks = {};
    r.frames.length = 0;
    r.ctl.keys = new Set([K.P]);
    r.ctl.onPoll = (vk, ctl) => {
      if (step > 0 || vk === K.P) polls++;
      if (step === 0 && polls > 20) { ctl.keys.delete(K.P); step = 1; polls = 0; }
      else if (step === 1 && polls === 300 && repaint && !done) {
        // inside 0x42f220: the import's esp is m.esp (machine.js host), as in the worker's idle()
        done = true;
        const replay = r.race.renderReplay;
        marks.held = replay.held();
        marks.esp = r.m.esp;
        marks.inLoop = r.u32(0x53b9f8);
        marks.before = r.frames.length;
        replay.repaint();
        r.host.hudLayout = layoutFor(r, 9 / 16);
        replay.repaint();
        r.host.hudLayout = undefined;
        replay.repaint();
        marks.after = r.frames.length;
      } else if (step === 1 && polls > 600) { ctl.keys.add(K.SPACE); step = 2; polls = 0; }
      else if (step === 2 && polls > 600) { ctl.keys.delete(K.SPACE); step = 3; }
    };
    const res = tryTick(r);
    r.ctl.onPoll = null;
    const pauseFrames = r.frames.slice();
    r.frames.length = 0;
    for (let k = 0; k < 160; k++) { r.ctl.keys = new Set([K.UP, ...(k % 50 < 10 ? [K.RIGHT] : [])]); r.tick(); }
    return { r, res, marks, pauseFrames, after: r.frames.slice(), mem: memoryHash(r), state: r.state(), stats: { ...r.race.renderReplay.stats } };
  };
  const A = await run(false), B = await run(true);
  // A: the pass's own picture, the pause entry's; B: those two, then the three repaints
  const [, entryA] = A.pauseFrames, [, entryB, p1, p2, p3] = B.pauseFrames;
  check('pause', 'the repaints ran inside the pause loop (pause kind 1, after the pause entry\'s render)', B.res === 'returned' && B.marks.held === true && B.marks.inLoop === 1 && B.marks.after - B.marks.before === 3,
    { res: B.res, marks: B.marks, framesA: A.pauseFrames.length, framesB: B.pauseFrames.length });
  check('pause', 'the pause entry\'s picture is the same with and without the repaints', entryA && entryB && frameKey(entryA) === frameKey(entryB));
  check('pause', 'a repaint draws the pause entry\'s picture draw for draw (scene and HUD)', p1 && frameKey(p1) === frameKey(entryB),
    p1 && { scene: p1.scene.length + '/' + entryB.scene.length, hud: p1.hud.length + '/' + entryB.hud.length });
  const sceneSame = p2 && JSON.stringify(p2.scene) === JSON.stringify(entryB.scene);
  const hudMoved = p2 && p2.hud.length === entryB.hud.length && p2.hud.some((h, k) => h !== entryB.hud[k]);
  check('pause', 'a repaint with a 9:16 HUD layout: the same scene, the HUD moved', sceneSame && hudMoved,
    p2 && { hudDraws: p2.hud.length, hudChanged: p2.hud.filter((h, k) => h !== entryB.hud[k]).length });
  check('pause', 'a repaint with the HUD as before draws the pause entry\'s picture again', p3 && frameKey(p3) === frameKey(entryB));
  const sameAfter = A.after.length === B.after.length && A.after.every((f, k) => frameKey(f) === frameKey(B.after[k]));
  const firstDiff = A.after.findIndex((f, k) => !B.after[k] || frameKey(f) !== frameKey(B.after[k]));
  check('pause', '160 passes after the pause: every picture draw for draw the same with and without the repaints', sameAfter, { passes: A.after.length + '/' + B.after.length, firstDiff });
  check('pause', 'the game\'s memory outside the stack is the same after them (but the object draw count 0x6a5c84)', A.mem.hash === B.mem.hash && JSON.stringify(A.state) === JSON.stringify(B.state),
    { A: A.mem, B: B.mem, state: B.state });
  check('pause', 'the repaints restored every aging draw and drew no kart part off its body (render-replay.js stats)',
    B.stats.repaints === 3 && B.stats.effectsSkipped === 0 && B.stats.effectsDiffer === 0 && B.stats.displaced === 0,
    { repaints: B.stats.repaints, pauseEntries: B.stats.pauseEntries, effectsRestored: B.stats.effectsRestored, effectsSkipped: B.stats.effectsSkipped, effectsDiffer: B.stats.effectsDiffer, displaced: B.stats.displaced });
}

// --- finish --------------------------------------------------------------------------------------------------------------
if (want('finish')) {
  const run = async (hold) => {
    const r = await racing();
    toGreen(r);
    for (let k = 0; k < 120; k++) { r.ctl.keys = new Set([K.UP]); r.tick(); }
    // the cheat waits in the pass for Ctrl's release (as tools/check-safeguards.mjs keys lets go after 50 Ctrl polls)
    r.ctl.keys = new Set([K.CONTROL, K.F, K.I]);
    let c = 0;
    r.ctl.onPoll = (vk, ctl) => { if (vk === K.CONTROL && ++c > 50) ctl.keys.clear(); };
    r.tick();
    r.ctl.onPoll = null;
    r.ctl.keys = new Set();
    let n = 0;
    while (r.state().phase !== 3 && n < 40) { r.tick(); n++; }
    const states = [];
    for (let k = 0; k < 40; k++) { r.tick(); states.push(textState(r)); }
    const marks = { phase: r.state().phase, textState: textState(r) };
    r.frames.length = 0;
    if (hold) {
      // the worker's result-screen hold (worker.js): the notice, the picture again, a turned phone, the notice off
      const replay = r.race.renderReplay;
      marks.shown = replay.notice(true);
      marks.textWhileShown = textState(r);
      replay.repaint();
      r.host.hudLayout = layoutFor(r, 9 / 16);
      replay.repaint();
      r.host.hudLayout = undefined;
      replay.notice(false);
      marks.textAfter = textState(r);
    }
    const held = r.frames.slice();
    r.frames.length = 0;
    let res = 'returned', passes = 0;
    while (res === 'returned' && passes < 2000) { res = tryTick(r); passes++; }
    const ini = r.vfs.read('race.ini');
    return { r, marks, states, held, after: r.frames.slice(), passes, res, ini: ini ? new TextDecoder('latin1').decode(ini) : '' };
  };
  const A = await run(false), B = await run(true);
  check('finish', 'the finish screen (Ctrl+F+I): phase 3, the special text idle 40 passes into it', A.marks.phase === 3 && A.marks.textState !== 1,
    { phase: A.marks.phase, textState: A.marks.textState, statesSeen: [...new Set(A.states)] });
  check('finish', 'notice(true) shows "pauze" (the special text runs), notice(false) takes it off (idle again)', B.marks.shown === true && B.marks.textWhileShown === 1 && B.marks.textAfter !== 1, B.marks);
  const [h1, h2] = B.held;
  const last = A.after[0];   // the next pass's picture without the hold (its HUD as the held one's, the notice aside)
  check('finish', 'the held picture: the notice\'s draws on top of the HUD, then the same scene with a 9:16 HUD', h1 && h2 && h1.hud.length > 0 && JSON.stringify(h1.scene) === JSON.stringify(h2.scene) && h2.hud.some((h, k) => h !== h1.hud[k]),
    h1 && { hud: h1.hud.length + '/' + h2.hud.length + ' (next pass ' + (last ? last.hud.length : '-') + ')', scene: h1.scene.length });
  const sameAfter = A.after.length === B.after.length && A.after.every((f, k) => frameKey(f) === frameKey(B.after[k]));
  const firstDiff = A.after.findIndex((f, k) => !B.after[k] || frameKey(f) !== frameKey(B.after[k]));
  check('finish', 'every pass after the hold until the race ends: draw for draw the same with and without it', sameAfter && A.res === B.res,
    { passes: A.passes + '/' + B.passes, frames: A.after.length + '/' + B.after.length, firstDiff, end: A.res + '/' + B.res });
  check('finish', 'race.ini at the end the same', A.ini === B.ini && A.ini.length > 0, { bytes: A.ini.length });
  // The notice leaves its own traces in the heap: the special text's glyph meshes keep "pauze"'s last state (hidden;
  // the next text sets them anew, 0x46c1e0 -> vtable +0x50) and the C runtime's lists hold its strings' blocks in
  // another order. The game's globals (the image's data) are the same.
  const L = A.r.m.layout, a = A.r.m.u8, b = B.r.m.u8;
  const differ = { low: 0, globals: 0, heap: 0 };
  for (let k = 0; k < a.length; k++) {
    if (a[k] === b[k] || (k >= L.STACK_LOW && k < L.STACK_TOP) || (k >= DRAW_COUNT && k < DRAW_COUNT + 4)) continue;
    differ[k < L.STACK_LOW ? 'low' : k < L.HEAP_BASE ? 'globals' : 'heap']++;
  }
  check('finish', 'the game\'s globals at the end the same (but the object draw count 0x6a5c84); bytes differ only in the heap', differ.low === 0 && differ.globals === 0, differ);
}

// --- gameover ------------------------------------------------------------------------------------------------------------
if (want('gameover')) {
  const r = await racing({ raceType: 1 });
  let n = 0;
  while (r.state().phase !== 6 && n < 4000) { r.tick(); n++; }
  for (let k = 0; k < 20; k++) r.tick();
  const s = textState(r);
  const shown = r.race.renderReplay.notice(true);
  check('gameover', 'Tijdrace game over (phase 6): "tijd is om!" runs as the special text, so no "pauze" over it', r.state().phase === 6 && s === 1 && shown === false && textState(r) === 1,
    { passes: n, phase: r.state().phase, textState: s, shown });
}

const out = join(ROOT, 'evidence', 'checks');
mkdirSync(out, { recursive: true });
writeFileSync(join(out, 'pause-repaint.json'), JSON.stringify({ date: new Date().toISOString(), failed, results }, null, 1));
console.log(failed ? `${failed} check(s) failed` : 'all checks passed');
process.exit(failed ? 1 : 0);
