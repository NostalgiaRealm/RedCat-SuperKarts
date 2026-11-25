#!/usr/bin/env node
// The race safeguards (source/host/safeguards.js, stuck.js), in Node on the recompiled race (tools/checks/
// full-race-gaps-lib.mjs: the host of the pages without a browser; host.cheats stands for the game worker's OPT.CHEATS):
//   keys     a handoff that binds W, D, U and F (accelerate, right, left, brake) drives with them and Ctrl without the
//            original's Ctrl+W+D fog, D's overlay cycle or a frozen pass; every debug and cheat key of the original held
//            at once leaves the game's memory byte for byte as without them, the keys the JS port has (P, Esc, J/N,
//            cameras, Space) still answer; with the option the cheats work as in the original (Ctrl+F+I finishes,
//            Ctrl+W+D sets fog, D cycles 0x53ba44 and holds the pass until it is let go).
//   stuck    Nederland, the accelerator held from the green light: the kart runs into the wall after the first bend and
//            is rescued after 8 s of trying within 60 units (the JS port's PLAYER_STUCK_SECONDS/RADIUS), through the
//            original's shrink, DISAPP, rings, REAPP and grow, to a pose it drove through on this lap at least 80 units
//            back, facing on, standing; idle, the handbrake, both pedals and the game's pause do not count.
//   pause    the pause-entry patch (build.py GAME_PATCHES 0x42f6d8) is in the module, and the pass in which P is
//            pressed goes from P's poll (0x42ffda) straight into the pause loop (0x42f226) without the extra object pass
//            (no poll of 0x414160 in between) and flips twice (its render, and the one that draws "pauze"); the race
//            goes on after the pause. The pause picture (source/host/render-replay.js; tools/checks/kart-draws-lib.mjs),
//            on the grid and while racing: every kart whole (four wheels and a driver) and drawn as in the pass's own
//            picture, no scene draw moved, the HUD the pass's with the notice after it; the aging draws (skid marks,
//            smoke, jet streams, colours) got back what the pass's render found and left what it left.
//   npc      an NPC vertical speed that the original's catch-up (0x406100) overflows is set to 0 and counted once; one
//            that was not finite before the dispatch stays as it is.
//   browser  (--browser; the dev server and Playwright as in tools/check-input.mjs) /dev/race.html?nocheats with W, F, U, D
//            bound: they drive and Ctrl+F+I does nothing; the development page as it is: Ctrl+F+I finishes; the
//            accelerator held on Nederland: the worker's input reaches the recovery (gameStats.safe); with pause: the
//            P pause's picture on ?fixed Nederland at pass 401 against the same pass without P, only the notice differs.
// Results in evidence/checks/safeguards/check-safeguards.json (and the browser part's screenshots). Exit code 1 when a
// check fails or a browser page throws or crashes (checks/page-errors.mjs).
//   node tools/check-safeguards.mjs [--only=keys,stuck,pause,npc] [--browser]
import { writeFileSync, mkdirSync, readFileSync } from 'node:fs';
import { join } from 'node:path';
import { makeRace, VK, SpinDetected, ROOT } from './checks/full-race-gaps-lib.mjs';
import { KEY_ALLOW_CALLS } from '../source/host/safeguards.js';
import { recordFrames, karts, nearSets, whole } from './checks/kart-draws-lib.mjs';
import { watchPage } from './checks/page-errors.mjs';

const only = (process.argv.find((a) => a.startsWith('--only=')) || (process.argv.includes('--only') ? '--only=' + process.argv[process.argv.indexOf('--only') + 1] : '')).slice(7).split(',').filter(Boolean);
const want = (k) => !only.length || only.includes(k);
const results = {};
let failed = 0;
const check = (group, name, ok, detail) => {
  (results[group] ||= []).push({ name, ok: !!ok, ...(detail === undefined ? {} : { detail }) });
  if (!ok) failed++;
  console.log(`${ok ? 'ok  ' : 'FAIL'} ${group}: ${name}${detail === undefined ? '' : '  ' + JSON.stringify(detail)}`);
};
const K = { ...VK, W: 0x57, U: 0x55, E: 0x45, G: 0x47, A: 0x41, S: 0x53, Q: 0x51, M: 0x4d, TAB: 0x09, ALT: 0x12, NUM7: 0x67, NUM8: 0x68, NUM9: 0x69, F7: 0x76, F8: 0x77, F12: 0x7b, ADD: 0x6b, SUB: 0x6d, F1: 0x70 };
const GREEN = 2000;
/** A race up to its first racing pass (phase 0). */
async function racing(opts = {}, cheats) {
  const r = await makeRace(opts);
  if (cheats !== undefined) r.host.cheats = cheats;
  r.race.boot();
  let n = 0;
  while (r.state().phase !== 0 && n < GREEN) { r.tick(); n++; }
  return r;
}
const tryTick = (r) => { try { r.tick(); return 'returned'; } catch (e) { if (e instanceof SpinDetected) return 'spin: ' + e.info.reason; throw e; } };
// what the cheats and debug keys change (0x429a90, 0x42f9c0): fog 0x53a264, fill mode 0x53a268, debug page 0x53be2c,
// SndGfx overlay_detail 0x53ba44, phase 0x53b9c0
const marks = (r) => ({ phase: r.u32(0x53b9c0), fog: r.m.u8[0x53a264], fill: r.i32(0x53a268), page: r.i32(0x53be2c), overlay: r.i32(0x53ba44) });

// --- keys --------------------------------------------------------------------------------------------------------------
if (want('keys')) {
  // W accelerate, F brake, U left, D right, Ctrl bonus (game.ini [INPUT], race-handoff.js INPUT_KEYS)
  const bind = { ini: [['game.ini', 'INPUT', 'KEY_ACCELERATE', K.W], ['game.ini', 'INPUT', 'KEY_BRAKE', K.F],
    ['game.ini', 'INPUT', 'KEY_STEERLEFT', K.U], ['game.ini', 'INPUT', 'KEY_STEERRIGHT', K.D], ['game.ini', 'INPUT', 'KEY_USEBONUS', K.CONTROL]], limit: 20000 };
  {
    const r = await racing(bind, false);
    const m0 = marks(r);
    r.ctl.keys = new Set([K.W, K.D, K.CONTROL]);         // Ctrl+W+D: the original's fog toggle, and D's overlay cycle
    const res = []; let maxPolls = 0;
    for (let k = 0; k < 80; k++) { res.push(tryTick(r)); maxPolls = Math.max(maxPolls, r.per.keys); }
    const p = r.player();
    const drive = { steer: r.f32(0x53bd70), throttle: r.f32(0x53bd74), kmh: r.i32(0x53be34), speed: +p.fwd.toFixed(1) };
    check('keys', 'cheats off: W+D+Ctrl bound to accelerate, right and bonus drive (throttle, steer right, speed)', res.every((x) => x === 'returned') && drive.throttle > 0 && drive.steer > 0 && drive.kmh > 5, { drive, maxPollsPerPass: maxPolls });
    check('keys', 'cheats off: no fog, fill, debug page or overlay change and no frozen pass', JSON.stringify(marks(r)) === JSON.stringify(m0), { before: m0, after: marks(r) });
    r.ctl.keys = new Set([K.F, K.U, K.CONTROL]);         // brake + left + bonus: Ctrl+F (+I), U (+Ctrl+P)
    for (let k = 0; k < 40; k++) res.push(tryTick(r));
    check('keys', 'cheats off: F+U+Ctrl bound to brake, left and bonus brake and steer left', res.every((x) => x === 'returned') && r.f32(0x53bd70) < 0 && r.u32(0x53b9c0) === 0, { steer: r.f32(0x53bd70), kmh: r.i32(0x53be34) });
    check('keys', 'cheats off: polls answered "up" were counted', r.race.safeguards.stats.keys > 0, { filtered: r.race.safeguards.stats.keys });
  }
  {
    // with the option the same binding meets the original's own keys: D (0x42ff6b) cycles 0x53ba44 and waits for it to be
    // let go, so a held D freezes the pass (the risk of binding D with cheats on)
    const r = await racing({ ...bind, limit: 20000 }, true);
    const m0 = marks(r);
    r.ctl.keys = new Set([K.W, K.D]);
    const res = tryTick(r);
    check('keys', 'cheats on: a held D bound to steering freezes the pass in 0x42f9c0 as in the original', res.startsWith('spin') && marks(r).overlay !== m0.overlay, { res, before: m0.overlay, after: marks(r).overlay });
  }
  // every debug and cheat key of the original held at once, against a run with only the keys the JS port knows held
  const debugKeys = [K.F, K.I, K.W, K.D, K.U, K.E, K.N, K.RETURN, K.G, K.A, K.S, K.Q, K.M, K.TAB, K.NUM7, K.NUM8, K.NUM9, K.F7, K.F8, K.F12, K.ADD, K.SUB, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x52, 0x54, 0x4b, 0x4c, 0x5a, 0x35, 0x37, 0x38, 0x39, 0x30, 0x24, 0x23, 0x21, 0x22, 0x2d, 0x2e];
  const base = [K.UP, K.CONTROL, K.SPACE];
  const twin = async (cheats) => {
    const a = await racing({ limit: 20000 }, cheats), b = await racing({ limit: 20000 }, cheats);
    a.ctl.keys = new Set(base); b.ctl.keys = new Set([...base, ...debugKeys]);
    const res = [];
    for (let k = 0; k < 60; k++) { a.tick(); res.push(tryTick(b)); if (res.at(-1) !== 'returned') break; }
    const L = a.m.layout, A = a.m.u8, B = b.m.u8;
    let diff = 0, first = -1;
    // the image's data and the heap (not the stack, whose dead bytes differ with the calls made, nor the host's low area)
    for (const [lo, hi] of [[0x4d0000, L.IMAGE_END], [L.HEAP_BASE, A.length]]) for (let k = lo; k < hi; k++) if (A[k] !== B[k]) { diff++; if (first < 0) first = k; }
    return { res: res.filter((x) => x !== 'returned'), passes: res.length, diff, first: first < 0 ? null : '0x' + first.toString(16), marks: marks(b), filtered: b.race.safeguards.stats.keys };
  };
  const off = await twin(false);
  check('keys', 'cheats off: 44 debug and cheat keys held change no byte of the game against the same race without them', !off.res.length && off.diff === 0, off);
  const on = await twin(true);
  check('keys', 'cheats on: the same keys reach the original (the race changes)', on.res.length > 0 || on.diff > 0, { ...on, res: on.res.slice(0, 1) });
  {
    // the keys the JS port has still answer without the option
    const r = await racing({ limit: 400000 }, false);
    // 0x41d920: 1 -> camera mode 1, 2 -> 3, 4 -> 0 (0x41e280; the mode is i32 0x4e3064, 0x41e270)
    const modes = [];
    for (const key of [0x32, 0x34, 0x31]) { r.ctl.keys = new Set([key]); r.tick(); r.ctl.keys = new Set(); r.tick(); modes.push(r.i32(0x4e3064)); }
    check('keys', 'cheats off: the camera keys 2, 4, 1 switch the camera (0x41d920)', JSON.stringify(modes) === '[3,0,1]', { modes });
    // P pauses (0x42f220): released after 20 polls, Space resumes; then Esc and N (0x42f290, the requester)
    let step = 0, polls = 0, inPause = 0;
    r.ctl.keys = new Set([K.P]);
    r.ctl.onPoll = (vk, ctl) => {
      if (step > 0 || vk === K.P) polls++;
      if (step === 0 && polls > 20) { ctl.keys.delete(K.P); step = 1; polls = 0; }
      else if (step === 1 && polls > 600) { inPause = polls; ctl.keys.add(K.SPACE); step = 2; polls = 0; }
      else if (step === 2 && polls > 600) { ctl.keys.delete(K.SPACE); step = 3; }
    };
    const t0 = r.state().virtualMs;
    const pres = tryTick(r);
    r.ctl.onPoll = null; r.ctl.keys = new Set();
    check('keys', 'cheats off: P pauses and a key resumes (the pause loop ran and came back)', pres === 'returned' && step === 3 && inPause > 0 && r.u32(0x53b9c0) === 0, { pres, step, pauseMs: r.state().virtualMs - t0 });
    step = 0; polls = 0;
    r.ctl.keys = new Set([K.ESCAPE]);
    r.ctl.onPoll = (vk, ctl) => {
      if (step > 0 || vk === K.ESCAPE) polls++;
      if (step === 0 && polls > 20) { ctl.keys.delete(K.ESCAPE); step = 1; polls = 0; }
      else if (step === 1 && polls > 3000) { ctl.keys.add(K.N); step = 2; polls = 0; }
      else if (step === 2 && polls > 600) { ctl.keys.delete(K.N); step = 3; }
    };
    const qres = tryTick(r);
    r.ctl.onPoll = null; r.ctl.keys = new Set();
    for (let k = 0; k < 5; k++) r.tick();
    check('keys', 'cheats off: Esc opens the requester and N goes on', qres === 'returned' && step === 3 && r.u32(0x53b9bc) === 1 && r.u32(0x53b9c0) === 0, { qres, step, running: r.u32(0x53b9bc) });
  }
  {
    const r = await racing({ limit: 400000 }, true);
    r.ctl.keys = new Set([K.CONTROL, K.F, K.I]);
    let c = 0;
    r.ctl.onPoll = (vk, ctl) => { if (vk === K.CONTROL && ++c > 50) ctl.keys.clear(); };
    tryTick(r); r.ctl.onPoll = null;
    for (let k = 0; k < 3; k++) r.tick();
    check('keys', 'cheats on: Ctrl+F+I finishes the race (0x42f740(3))', r.u32(0x53b9c0) === 3, marks(r));
    const r2 = await racing({ limit: 400000 }, false);
    r2.ctl.keys = new Set([K.CONTROL, K.F, K.I]);
    for (let k = 0; k < 10; k++) r2.tick();
    check('keys', 'cheats off: Ctrl+F+I does nothing', r2.u32(0x53b9c0) === 0, marks(r2));
  }
  {
    // cheats on, Ctrl+W+D with release after 50 Ctrl polls: the fog toggles (0x53a264)
    const r = await racing({ limit: 400000 }, true);
    const f0 = r.m.u8[0x53a264];
    r.ctl.keys = new Set([K.CONTROL, K.W, K.D]);
    let c = 0;
    r.ctl.onPoll = (vk, ctl) => { if (vk === K.CONTROL && ++c > 50) ctl.keys.clear(); };
    tryTick(r); r.ctl.onPoll = null;
    check('keys', 'cheats on: Ctrl+W+D toggles the fog', r.m.u8[0x53a264] !== f0, { before: f0, after: r.m.u8[0x53a264] });
  }
  check('keys', 'the allow-list has the 39 calls of the design', KEY_ALLOW_CALLS.length === 39, KEY_ALLOW_CALLS.length);
}

// --- stuck -------------------------------------------------------------------------------------------------------------
if (want('stuck')) {
  const SHRINK = 20;
  const trace = async (keysOf, passes, { pauseAt = -1 } = {}) => {
    const r = await racing({ etappe: 0 });
    const sg = r.race.safeguards.stuck, det = sg.detector;
    const rows = [];
    let started = -1, moved = -1, finished = -1, origin = null, lastOriginPass = 0, entryFrames = [];
    for (let k = 0; k < passes; k++) {
      r.ctl.keys = new Set(keysOf(k));
      if (k === pauseAt) {
        let step = 0, polls = 0;
        r.ctl.keys = new Set([K.P]);
        r.ctl.onPoll = (vk, ctl) => { if (step > 0 || vk === K.P) polls++; if (step === 0 && polls > 20) { ctl.keys.delete(K.P); step = 1; polls = 0; } else if (step === 1 && polls > 400) { ctl.keys.add(K.SPACE); step = 2; polls = 0; } else if (step === 2 && polls > 400) { ctl.keys.delete(K.SPACE); step = 3; } };
      }
      const before = { att: det.attemptSeconds, origin: det.origin && det.origin.join() };
      r.tick();
      r.ctl.onPoll = null;
      if (det.origin && det.origin.join() !== origin) { origin = det.origin.join(); lastOriginPass = k; }
      const p = r.player(), body = p.racer;
      const mgr = r.u32(0x67e4d0);
      let entry = null;
      if (mgr) { const vec = r.u32(mgr + 4), b = r.u32(vec + 4), e = r.u32(vec + 8); for (let a = b; a && a < e; a += 0x11b0) if (r.i32(a + 0x1180) === p.me) entry = { frame: r.i32(a + 0x1194), shrinking: r.m.u8[a + 0x1198], finished: r.m.u8[a + 0x11a0], flag: r.m.u8[a + 0x11ac] }; }
      if (entry && started < 0) { started = k; rows.push({ k, event: 'queued', entry, attemptBefore: before.att, sinceOrigin: k - lastOriginPass, pose: [p.x, p.y, p.z].map((v) => +v.toFixed(1)), sector: p.sector, laps: r.i32(0x53ba18), armed: r.i32(0x53d1d8), distance: r.i32(0x53be70) }); }
      if (entry) entryFrames.push(entry);
      if (sg.stats.relocated && moved < 0) { moved = k; rows.push({ k, event: 'moved', destination: sg.stats.last.destination, sector: r.i32(body + 0x1c), prev: r.i32(body + 0x20), laps: r.i32(0x53ba18), armed: r.i32(0x53d1d8), distance: r.i32(0x53be70) }); }
      if (started >= 0 && !entry && finished < 0) { finished = k; rows.push({ k, event: 'done', speed: [r.f32(body + 0x9c), r.f32(body + 0xa0), r.f32(body + 0xa4)], rates: [r.f32(body + 0xa8), r.f32(body + 0xac), r.f32(body + 0xb0)] }); }
    }
    return { r, rows, started, moved, finished, stats: sg.stats, entryFrames };
  };
  {
    const t = await trace(() => [K.UP], 760);
    const q = t.rows.find((x) => x.event === 'queued'), mv = t.rows.find((x) => x.event === 'moved'), dn = t.rows.find((x) => x.event === 'done');
    check('stuck', 'NED, accelerator held: the kart is queued for the rescue after 8 s (320 passes) of trying within 60 units', q && q.sinceOrigin >= 319 && q.sinceOrigin <= 321 && q.entry.flag === 0x80, q);
    const shrinkPasses = t.entryFrames.filter((e) => e.shrinking && !e.finished).length;
    check('stuck', 'the original shrink runs 20 passes, then the kart moves at grow frame 0', mv && mv.k - t.started === SHRINK, { queued: t.started, moved: mv && mv.k, shrinkPasses });
    const d = mv && mv.destination, from = q && q.pose;
    const dist = d && from ? Math.hypot(d.position[0] - from[0], d.position[2] - from[2]) : null;
    check('stuck', 'it returns to a pose at least 80 units back, on this lap, sector before the trap, previous sector = sector', mv && dist >= 80 && mv.sector === d.sector && mv.prev === mv.sector && mv.laps === q.laps && mv.distance <= q.distance && d.sector <= q.sector, { dist: dist && +dist.toFixed(1), destination: d, from, queuedSector: q && q.sector });
    check('stuck', 'the finish is not newly armed by the return', mv && (!mv.armed || q.armed), { before: q && q.armed, after: mv && mv.armed });
    // grow frames 0..19 in 20 passes: the move is frame 0's pass, the entry is retired (0x48db30) in frame 19's
    check('stuck', 'it grows for 20 passes and ends standing, no forward 5.0, no rates', dn && dn.k - mv.k === SHRINK - 1 && dn.speed.every((v) => v === 0) && dn.rates.every((v) => v === 0), { ...dn, growPasses: dn && dn.k - mv.k + 1 });
    const after = t.r.player();
    check('stuck', 'it drives on afterwards', Math.hypot(after.x - d.position[0], after.z - d.position[2]) > 30, { at: [after.x, after.z].map((v) => +v.toFixed(1)) });
    results.stuckTrace = t.rows;
  }
  {
    // The JS port's own regression (its tests/helpers/england-tyre-fixture.mjs): WhizzKitty on England, set down on clear
    // road at (-7027, 0, 6317), yaw 512, sector 124, waypoint 589 (setup only), then the analog throttle 1 and steering
    // 0.3 into the stacked tyres near the bridge (banden00.d3d), and straight on once it is back.
    const r = await makeRace({ etappe: 2, car: 1 });
    const joy = { x: 32767, y: 32767, buttons: 0 };
    let analog = false;
    r.host.joystick = (id) => (id === 0 ? joy : null);          // the worker's virtual joystick (winmm.js), centred at boot
    r.host.beforeTick = (race) => { race.m.i32[0x53a5d8 >> 2] = analog ? 3 : 1; };   // the analog handler 0x4341d0
    r.host.driveInput = () => ({ throttle: analog ? 1 : 0, brake: 0, handbrake: false });
    r.race.boot();
    let n = 0; while (r.state().phase !== 0 && n < GREEN) { r.tick(); n++; }
    const { m } = r, v = m.view, me = r.i32(0x53be28), body = r.u32(0x67ee20) + me * 0xd0, ro = r.u32(0x6a5c38) + r.i32(body + 0xc) * 0xa9;
    const pos = [-7027, 0, 6317], yaw = 512, TWO = Math.fround(2 * Math.PI);
    const c = Math.fround(Math.cos(yaw / 4096 * TWO)), sn = Math.fround(Math.sin(yaw / 4096 * TWO));
    [c, 0, sn, 0, 0, 1, 0, 0, -sn, 0, c, 0, ...pos, 1].forEach((x, k) => v.setFloat32(ro + 0x10 + 4 * k, x, true));
    pos.forEach((x, k) => v.setFloat32(ro + 0x50 + 4 * k, x, true));
    v.setFloat32(ro + 0x78, yaw, true); v.setFloat32(ro + 0x74, 0, true); v.setFloat32(ro + 0x7c, 0, true);
    for (const o of [0x9c, 0xa0, 0xa4, 0xa8, 0xac, 0xb0]) v.setFloat32(body + o, 0, true);
    m.i32[(body + 0x1c) >> 2] = 124; m.i32[(body + 0x20) >> 2] = 124; m.i32[(body + 0x24) >> 2] = 589;
    m.call(0x430ff0, [me]);                                       // the ground height and sector, as the rescue sets them
    v.setFloat32(ro + 0x54, Math.fround(m.gSt0.value), true); v.setFloat32(ro + 0x44, Math.fround(m.gSt0.value), true);
    m.i32[(0x507f48 + m.i32[0x508610 >> 2] * 4) >> 2] = 0;        // wheels seated anew (0x416650)
    m.call(0x41e0b0, [me]);
    const det = r.race.safeguards.stuck.detector, st = r.race.safeguards.stuck.stats;
    det.anchors = []; det.reset();                                // no poses from before the setup
    joy.x = 32767 + Math.round(0.3 * 32768); joy.y = 0; analog = true;
    let queued = null, moved = null, trap = null;
    for (let k = 0; k < 900 && !moved; k++) {
      r.tick();
      const p = r.player();
      if (st.started && !queued) { queued = { k, ms: (k + 1) * 25, at: [p.x, p.z].map((x) => +x.toFixed(1)), sector: p.sector }; trap = [p.x, p.z]; }
      if (st.relocated && !moved) moved = { k, destination: st.last.destination };
    }
    joy.x = 32767;
    for (let k = 0; k < 120; k++) r.tick();
    const p = r.player();
    const back = moved && Math.hypot(moved.destination.position[0] - trap[0], moved.destination.position[2] - trap[1]);
    check('stuck', 'ENG tyres (the JS port\'s regression start and input): rescued, at least 80 units from the tyres, and it drives off', queued && moved && back >= 80 && Math.hypot(p.x - moved.destination.position[0], p.z - moved.destination.position[2]) > 100,
      { queued, moved, fromTyres: back && +back.toFixed(1), after: [p.x, p.z].map((x) => +x.toFixed(1)) });
    results.englandTyres = { queued, moved };
  }
  {
    const idle = await trace(() => [], 500);
    check('stuck', 'standing still for 500 passes: no rescue', idle.started < 0, idle.stats);
    const hand = await trace((k) => (k < 200 ? [K.UP] : [K.UP, K.ALT]), 700);
    check('stuck', 'the accelerator with the handbrake (Alt) at the wall: no rescue', hand.started < 0, hand.stats);
    const both = await trace((k) => (k < 200 ? [K.UP] : [K.UP, K.DOWN]), 700);
    check('stuck', 'both pedals at the wall: no rescue', both.started < 0, both.stats);
    // without the pause the rescue comes at pass 578 (above); the pause at 450 starts the 320 passes again
    const paused = await trace(() => [K.UP], 900, { pauseAt: 450 });
    const pq = paused.rows.find((x) => x.event === 'queued');
    check('stuck', 'the game\'s pause starts the 8 s again', pq && pq.k >= 450 + 320 && pq.k <= 450 + 322, pq && { queued: pq.k, sinceOrigin: pq.sinceOrigin });
  }
}

// --- pause -------------------------------------------------------------------------------------------------------------
if (want('pause')) {
  const meta = JSON.parse(readFileSync(join(ROOT, 'public/game/rcskspel.meta.json'), 'utf8'));
  const patch = (meta.patches || []).find((p) => p.addr === 0x42f6d8);
  check('pause', 'the module carries the pause-entry patch 0x42f6d8 (jmp 0x42f703)', patch && patch.new === 'e926000000', patch);
  const r = recordFrames(await racing({ limit: 400000 }, true));
  for (let k = 0; k < 40; k++) r.tick();
  const { m } = r;
  // the places of the slots' objects after the pass's render and before the pause entry's: what the pass's own code
  // moves between the two (0x451200 turns the bonus boxes; other scenery moves too), whose draws may move with it
  const places = () => {
    const T = r.u32(0x67ee20), objs = r.u32(0x6a5c38), used = r.u32(0x67ee30), out = new Map();
    for (let i = 0; i < r.i32(0x67ee24); i++) {
      if (m.u8[used + i] !== 1) continue;
      const o = objs + r.i32(T + i * 0xd0 + 0xc) * 0xa9;
      out.set(o, [r.f32(o + 0x40), r.f32(o + 0x44), r.f32(o + 0x48)]);
    }
    return out;
  };
  let afterFirst = null, movedBetween = [];
  m.wrap('Render', (esp, ecx, edx, eax, next) => {
    const ret = m.u32[esp >> 2];
    if (ret === 0x42f708 && afterFirst) {
      movedBetween = [];
      for (const [o, t] of places()) { const t0 = afterFirst.get(o); if (t0 && t0.some((q, j) => q !== t[j])) movedBetween.push([t0, t]); }
    }
    const out = next(esp, ecx, edx, eax);
    if (ret === 0x42f668) afterFirst = places();
    return out;
  });
  const id = m.thunkId('USER32.DLL!GetAsyncKeyState');
  const inner = m.thunks[id];
  const sites = [];
  m.thunks[id] = (esp, ecx, edx, eax) => {
    const ret = m.u32[esp >> 2];
    if (ret === 0x4b3860 || ret === 0x4b3848) sites.push(m.u32[(esp + 0x10) >> 2] - 5);
    return inner(esp, ecx, edx, eax);
  };
  const flips0 = r.stats.flips; r.tick(); const normalFlips = r.stats.flips - flips0;
  sites.length = 0;
  let step = 0, polls = 0;
  r.ctl.keys = new Set([K.P]);
  r.ctl.onPoll = (vk, ctl) => { if (step > 0 || vk === K.P) polls++; if (step === 0 && polls > 20) { ctl.keys.delete(K.P); step = 1; polls = 0; } else if (step === 1 && polls > 600) { ctl.keys.add(K.SPACE); step = 2; polls = 0; } else if (step === 2 && polls > 600) { ctl.keys.delete(K.SPACE); step = 3; } };
  const flips1 = r.stats.flips;
  r.frames.length = 0;
  const res = tryTick(r);
  r.ctl.onPoll = null; r.ctl.keys = new Set();
  const pFlips = r.stats.flips - flips1;
  const pAt = sites.indexOf(0x42ffda), loopAt = sites.indexOf(0x42f226);
  const between = sites.slice(pAt + 1, loopAt);
  const objectPass = between.filter((s) => s >= 0x414160 && s < 0x414400);
  check('pause', 'P pass: from P\'s poll straight into the pause loop, no 0x414160 polls of an extra object pass', res === 'returned' && pAt >= 0 && loopAt > pAt && objectPass.length === 0, { pAt, loopAt, between: between.map((s) => s.toString(16)) });
  check('pause', 'the P pass flips twice: its own render and the one that shows the pauze notice (no extra object pass)', pFlips === normalFlips + 1, { normalFlips, pFlips });
  pausePicture('on the grid (40 passes after green)');
  const t0 = r.state().tick; r.ctl.keys = new Set([K.UP]);
  for (let k = 0; k < 40; k++) r.tick();
  check('pause', 'the race goes on after the pause', r.u32(0x53b9c0) === 0 && r.i32(0x53be34) > 0, { kmh: r.i32(0x53be34), passes: r.state().tick - t0 });
  // a second P pause with skid marks, smoke and jet streams about: driving with the steering swung, the bonus key now and then
  for (let k = 0; k < 400; k++) {
    r.ctl.keys = new Set([K.UP, ...((k >> 6) % 3 === 1 ? [K.LEFT] : (k >> 6) % 3 === 2 ? [K.RIGHT] : []), ...(k % 97 < 3 ? [K.CONTROL] : [])]);
    r.tick();
  }
  step = 0; polls = 0;
  r.ctl.keys = new Set([K.P]);
  r.ctl.onPoll = (vk, ctl) => { if (step > 0 || vk === K.P) polls++; if (step === 0 && polls > 20) { ctl.keys.delete(K.P); step = 1; polls = 0; } else if (step === 1 && polls > 600) { ctl.keys.add(K.SPACE); step = 2; polls = 0; } else if (step === 2 && polls > 600) { ctl.keys.delete(K.SPACE); step = 3; } };
  r.frames.length = 0;
  const res2 = tryTick(r);
  r.ctl.onPoll = null; r.ctl.keys = new Set();
  pausePicture('racing (440 passes later, ' + res2 + ')');
  const st = (r.race.renderReplay && r.race.renderReplay.stats) || {};
  check('pause', 'the pause renders gave every aging draw back what the pass\'s render found, and left what it left (render-replay.js)', st.pauseEntries === 2 && st.effectsSkipped === 0 && st.effectsDiffer === 0 && st.displaced === 0,
    { pauseEntries: st.pauseEntries, kartsRestored: st.kartsRestored, effectsRestored: st.effectsRestored, effectsSkipped: st.effectsSkipped, effectsDiffer: st.effectsDiffer, displaced: st.displaced, maxOff: st.maxOff && +st.maxOff.toFixed(1) });

  /**
   * The P pass's two pictures (its render 0x42f663 and the pause entry's 0x42f703): every kart drawn whole and as in the
   * pass's own picture (the regression before render-replay.js: all wheels and drivers about 7,300 units off), no scene
   * draw moved but with an object the pass's own code moved between the renders (the bonus boxes that 0x451200 turns
   * keep their place), the HUD the pass's with the notice's draws after it.
   */
  function pausePicture(when) {
    const [A, B] = r.frames.slice(-2);
    const ks = karts(r), sa = nearSets(A, ks), sb = nearSets(B, ks);
    const drawnKarts = sa.filter((set) => set.length).length;
    const same = (x, y) => x.every((q, j) => Math.abs(q - y[j]) < 1e-3);
    const movedList = A.scene.map((d, k) => [d, B.scene[k]]).filter(([d, e]) => !e || e.nv !== d.nv || (d.t && e.t && Math.hypot(...d.t.map((q, j) => q - e.t[j])) > 1));
    // a draw that moved with its object, which the pass's code moved between the renders
    const withObject = movedList.filter(([d, e]) => e && d.t && e.t && movedBetween.some(([t0, t]) => same(d.t, t0) && same(e.t, t))).length;
    const moved = movedList.length - withObject;
    const hudSame = B.hud.length > A.hud.length && A.hud.every((h, k) => h === B.hud[k]);
    check('pause', `the pause picture ${when}: every kart whole and as in the pass's picture, no scene draw moved, the HUD with the notice after it`,
      r.frames.length >= 2 && drawnKarts > 0 && sb.every((set, j) => set.join(',') === sa[j].join(',') && (!set.length || whole(set))) && A.scene.length === B.scene.length && moved === 0 && hudSame,
      { karts: sb.map((set) => set.join(',')).join(' | '), drawnKarts, scene: A.scene.length + '/' + B.scene.length, moved, withObject, objectsMovedBetween: movedBetween.length, hud: A.hud.length + '/' + B.hud.length });
  }
}

// --- npc ---------------------------------------------------------------------------------------------------------------
if (want('npc')) {
  const r = await racing({ etappe: 0 });
  const { m } = r;
  for (let k = 0; k < 200; k++) { r.ctl.keys = new Set([K.UP]); r.tick(); }
  const npcBody = (ai) => m.u32[0x67ee20 >> 2] + m.i32[(0x5081bc + ai * 0x70) >> 2] * 0xd0;
  const sg = r.race.safeguards.stats;
  // a test wrapper outside the guard: before NPC 0's dispatch, a vertical speed at the float limit and the player far ahead,
  // so that 0x4062b0 calls the catch-up 0x406100, whose (1 + f) overflows it inside the guarded call
  let mode = 'overflow', seen = null;
  m.wrap('NpcPrepare', (esp, ecx, edx, eax, next) => {
    const ai = m.i32[(esp + 4) >> 2];
    if (ai !== 0 || !mode) return next(esp, ecx, edx, eax);
    const b = npcBody(0);
    if (mode === 'overflow') { m.f32[(b + 0xa0) >> 2] = 3.4e38; m.i32[0x53be70 >> 2] += 10000; }
    if (mode === 'inf') m.f32[(b + 0xa0) >> 2] = Infinity;
    const out = next(esp, ecx, edx, eax);
    if (mode === 'overflow') m.i32[0x53be70 >> 2] -= 10000;
    seen = m.f32[(b + 0xa0) >> 2];
    mode = null;
    return out;
  });
  const n0 = sg.npc;
  for (let k = 0; k < 4 && mode; k++) r.tick();
  check('npc', 'a speed the catch-up overflows is set to 0 and counted once', seen === 0 && sg.npc === n0 + 1, { seen, corrections: sg.npc - n0, event: sg.npcEvents.at(-1) });
  mode = 'inf';
  const n1 = sg.npc;
  for (let k = 0; k < 4 && mode; k++) r.tick();
  check('npc', 'a speed that was not finite before the dispatch is not hidden', !Number.isFinite(seen) && sg.npc === n1, { seen: String(seen), corrections: sg.npc - n1 });
}

// --- browser (--browser): the option and the input through the pages and the game worker ------------------------------
if (process.argv.includes('--browser')) {
  const { pathToFileURL } = await import('node:url');
  const { chromium } = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
  const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
  const URL_ = process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html';
  const wait = (ms) => new Promise((res) => setTimeout(res, ms));
  const shots = join(ROOT, 'evidence', 'checks', 'safeguards');
  mkdirSync(shots, { recursive: true });
  const stats = (page) => page.evaluate(() => { const g = window.gameStats; return { ticks: g.ticks, phase: g.phase, steer: g.steer, throttle: g.throttle, kmh: g.kmh, safe: g.safe, exit: g.exit, crash: g.crash }; });
  const WFUD = { accelerate: 'KeyW', brake: 'KeyF', left: 'KeyU', right: 'KeyD', bonus: 'ControlLeft', handbrake: 'AltLeft' };
  const open = async (query, bindings) => {
    const page = await browser.newPage({ viewport: { width: 640, height: 480 } });
    page.on('pageerror', (e) => console.log('[pageerror]', e.message));
    watchPage(page, (e) => check('browser', 'no page error' + (query ? ` (${query})` : ''), false, e));
    await page.goto(URL_ + '?fixed&stats&idle' + query);
    await page.waitForFunction(() => window.runner, null, { timeout: 60000 });
    await page.evaluate((b) => { window.race(b ? { settings: { ...window.runner.settings, bindings: b } } : {}); }, bindings || null);
    await page.waitForFunction(() => window.gameStats.ticks >= 345 || window.gameStats.crash, null, { timeout: 240000 });
    return page;
  };
  const hold = async (page, keys, ms) => { for (const k of keys) await page.keyboard.down(k); await wait(ms); for (const k of keys) await page.keyboard.up(k); };
  {
    const page = await open('&nocheats', WFUD);
    const s0 = await stats(page);
    for (const k of ['KeyW', 'KeyD', 'ControlLeft']) await page.keyboard.down(k);
    await wait(2500);
    const s1 = await stats(page);
    await page.locator('#game').screenshot({ path: join(shots, 'browser-wd-nocheats.png') });
    for (const k of ['KeyW', 'KeyD', 'ControlLeft']) await page.keyboard.up(k);
    check('browser', '?nocheats: W, D and Ctrl bound to accelerate, right and bonus drive, the passes go on', s1.phase === 0 && s1.throttle > 0 && s1.steer > 0 && s1.kmh > 0 && s1.ticks - s0.ticks > 60 && s1.safe && s1.safe.cheats === false && s1.safe.keys > 0, { s0, s1 });
    await hold(page, ['ControlLeft', 'KeyF', 'KeyI'], 800);
    await wait(1500);
    const s2 = await stats(page);
    check('browser', '?nocheats: Ctrl+F+I does not finish the race', s2.phase === 0, s2);
    await page.close();
  }
  {
    const page = await open('', WFUD);
    await hold(page, ['ControlLeft', 'KeyF', 'KeyI'], 800);
    await page.waitForFunction(() => window.gameStats.phase === 3 || window.gameStats.exit !== null, null, { timeout: 20000 }).catch(() => {});
    const s = await stats(page);
    check('browser', 'development page (cheats by default): Ctrl+F+I finishes the race', s.phase === 3 || s.exit === 0, s);
    await page.close();
  }
  {
    // the accelerator held from the green light on Nederland: the game worker's input reaches the stuck recovery
    const page = await open('&nocheats');
    await page.keyboard.down('ArrowUp');
    await page.waitForFunction(() => window.gameStats.safe && window.gameStats.safe.relocated >= 1, null, { timeout: 60000 }).catch(() => {});
    const s = await stats(page);
    await wait(600);
    await page.locator('#game').screenshot({ path: join(shots, 'browser-stuck-returned.png') });
    await page.keyboard.up('ArrowUp');
    check('browser', 'NED, ArrowUp held from the green light: the stuck recovery moves the kart back (worker input, CTRL.SAFE_STUCK)', s.safe && s.safe.stuck >= 1 && s.safe.relocated >= 1, s);
    await page.close();
  }
  if (want('pause')) {
    // The P pause's picture (the pause entry's render 0x42f703) against the same pass without P: ?fixed runs the same
    // race twice, the accelerator held from the first pass, frozen after pass N (CTRL.PAUSED, as tools/check-visuals.mjs
    // freezeAt); one run then goes on to N + 1 and stops, the other has P down for N + 1, which pauses in it. Its picture
    // may differ only by the notice (source/host/render-replay.js): before it every kart lost its wheels and driver
    // (evidence/frames/input/paused.png of 2026-11-25). Counted as in tools/check-flight.mjs: pixels that differ with
    // all eight neighbours, outside the box of the notice's orange strokes.
    const N = 400;
    const run = async (withP) => {
      const page = await browser.newPage({ viewport: { width: 960, height: 540 }, deviceScaleFactor: 1 });
      page.on('pageerror', (e) => console.log('[pageerror]', e.message));
      watchPage(page, (e) => check('browser', `no page error (pause picture, ${withP ? 'with' : 'without'} P)`, false, e));
      await page.goto(URL_ + '?fixed&etappe=0');
      await page.keyboard.down('ArrowUp');           // before the first pass, so both runs drive the same
      await page.waitForFunction((n) => window.gameStats.ticks >= n - 20, N, { timeout: 240000 });
      const freezeAt = (n) => page.evaluate((n) => {
        const ctrl = window.runner.ctrl, t0 = performance.now();
        while (Atomics.load(ctrl, 3) < n && performance.now() - t0 < 5000) { /* the pass count, from the game thread */ }
        Atomics.store(ctrl, 2, 1);
        return Atomics.load(ctrl, 3);
      }, n);
      const go = () => page.evaluate(() => { Atomics.store(window.runner.ctrl, 2, 0); Atomics.notify(window.runner.ctrl, 2); });
      const at = [await freezeAt(N)];
      if (withP) {
        await page.keyboard.down('KeyP');
        await go();
        await page.waitForFunction(() => Atomics.load(window.runner.ctrl, 15) === 1, null, { timeout: 20000 });
        await page.keyboard.up('KeyP');
        at.push(await page.evaluate(() => Atomics.load(window.runner.ctrl, 3)));
      } else {
        await page.waitForTimeout(300);
        await go();
        at.push(await freezeAt(N + 1));
      }
      await wait(800);                                  // the render worker shows the pass (smoothing ends at it)
      await page.addStyleTag({ content: '#status { visibility: hidden !important; }' });
      const png = await page.locator('#game').screenshot({ path: join(shots, withP ? 'browser-p-paused.png' : 'browser-p-same-pass.png') });
      const replay = await page.evaluate(() => window.gameStats.replay || null);
      return { page, png, at, replay };
    };
    const A = await run(false), B = await run(true);
    const d = await B.page.evaluate(async ([pa, pb]) => {
      const pixels = async (b64) => {
        const img = await createImageBitmap(await (await fetch('data:image/png;base64,' + b64)).blob());
        const c = new OffscreenCanvas(img.width, img.height), g = c.getContext('2d');
        g.drawImage(img, 0, 0);
        return g.getImageData(0, 0, img.width, img.height);
      };
      const P = await pixels(pa), Q = await pixels(pb), w = P.width, h = P.height;
      const isOrange = (dt, k) => dt[k] > 200 && dt[k + 1] > 90 && dt[k + 1] < 190 && dt[k + 2] < 70;
      const newOrange = (x, y) => { const k = (y * w + x) * 4; return isOrange(Q.data, k) && !isOrange(P.data, k); };
      const b = { x0: w, y0: h, x1: -1, y1: -1 };
      for (let y = Math.round(h * 0.2); y < Math.round(h * 0.6); y++) for (let x = Math.round(w * 0.2); x < Math.round(w * 0.8); x++) {
        if (newOrange(x, y) && newOrange(x - 1, y) && newOrange(x + 1, y) && newOrange(x, y - 1) && newOrange(x, y + 1)) {
          b.x0 = Math.min(b.x0, x); b.y0 = Math.min(b.y0, y); b.x1 = Math.max(b.x1, x); b.y1 = Math.max(b.y1, y);
        }
      }
      const notice = b.x1 < 0 ? null : { x: b.x0 - 8, y: b.y0 - 8, width: b.x1 - b.x0 + 17, height: b.y1 - b.y0 + 17 };
      const D = new Uint8Array(w * h);
      for (let k = 0; k < w * h; k++) D[k] = [0, 1, 2].some((c) => Math.abs(P.data[k * 4 + c] - Q.data[k * 4 + c]) >= 32) ? 1 : 0;
      let n = 0, raw = 0;
      for (let y = 1; y < h - 1; y++) for (let x = 1; x < w - 1; x++) {
        if (notice && x >= notice.x && y >= notice.y && x < notice.x + notice.width && y < notice.y + notice.height) continue;
        raw += D[y * w + x];
        let all = 1;
        for (let j = -1; j <= 1 && all; j++) for (let i = -1; i <= 1 && all; i++) all = D[(y + j) * w + x + i];
        n += all;
      }
      return { n, raw, notice };
    }, [A.png.toString('base64'), B.png.toString('base64')]);
    await A.page.close(); await B.page.close();
    check('browser', '?fixed, Nederland, pass 401 with P: the pause picture is the pass\'s picture without P but for the notice (every kart whole)',
      A.at[1] === N + 1 && B.at[0] === N && d.notice && d.n <= 100, { frozen: [A.at, B.at], ...d, replay: B.replay });
  }
  await browser.close();
}

mkdirSync(join(ROOT, 'evidence', 'checks', 'safeguards'), { recursive: true });
writeFileSync(join(ROOT, 'evidence', 'checks', 'safeguards', 'check-safeguards.json'), JSON.stringify({ date: new Date().toISOString(), node: process.version, failed, results }, null, 1));
console.log(failed ? `${failed} check(s) failed` : 'all checks passed');
process.exit(failed ? 1 : 0);
