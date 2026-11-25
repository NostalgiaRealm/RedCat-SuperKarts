#!/usr/bin/env node
// What stops a complete race in the recompiled rcskspel.dat beyond the first ticks: pause (P), the quit
// requester (Esc), other keys that busy-wait inside one call, the finish/game-over phases, and race.ini at exit.
//   node tools/checks/full-race-gaps.mjs [--only name,name] [--bot-ticks 60000] [--out evidence/checks/full-race-gaps]
// Each scenario is a new race (boot, then ticks of 25 ms virtual time as source/host/race.js). Keys are given
// two ways:
//   frozen - the key state is fixed for the whole tick, as on the page's main thread, where no key event can
//            arrive while original code runs; a loop that waits for a key change then never ends, and the
//            watchdog of full-race-gaps-lib.mjs reports it (SpinDetected) instead of hanging;
//   live   - onPoll changes the keys after a number of polls inside the same tick, as a worker reading a
//            shared key array would see them.
import { writeFileSync, mkdirSync, readFileSync } from 'node:fs';
import { createHash } from 'node:crypto';
import { join } from 'node:path';
import { makeRace, raceIniSummary, SpinDetected, VK, vkName, ROOT } from './full-race-gaps-lib.mjs';

const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const OUT = join(ROOT, opt('out', 'evidence/checks/full-race-gaps'));
const ONLY = opt('only', '') ? opt('only', '').split(',') : null;
const BOT_TICKS = Number(opt('bot-ticks', 60000));
mkdirSync(OUT, { recursive: true });

/** Boot and run to the green light (phase 0), then `extra` ticks with throttle. */
async function toGreen(extra = 20, opts = {}) {
  const r = await makeRace(opts);
  r.race.boot();
  r.ctl.keys.clear();
  let n = 0;
  while (r.state().phase !== 0 && n < 2000) { r.tick(); n++; }
  r.greenTick = n;
  r.ctl.keys.add(VK.UP);
  for (let k = 0; k < extra; k++) r.tick();
  r.ctl.keys.clear();
  return r;
}

/** Runs one tick and reports what happened inside it. */
function probeTick(r) {
  const before = r.state();
  const t0 = r.race.clock.seconds;
  const flips0 = r.stats.flips, blits0 = r.stats.blits;
  let error = null, spin = null, ok = null;
  try {
    ok = r.tick();
  } catch (e) {
    if (e instanceof SpinDetected) spin = e.info;
    else error = (e.stack || String(e)).split('\n').slice(0, 6).join(' | ');
  }
  const after = spin || error ? null : r.state();
  return {
    before, after, ok, spin, error,
    keyPolls: r.per.keys, clockQueries: r.per.clock, peeks: r.per.peek, waits: r.per.wait,
    virtualMsInsideTick: Math.round((r.race.clock.seconds - t0 - (spin || error ? 0 : 0.025)) * 1000 * 10) / 10,
    flips: r.stats.flips - flips0, blits: r.stats.blits - blits0,
    polledVKs: [...r.per.vk.entries()].sort((a, b) => b[1] - a[1]).slice(0, 10).map(([k, n]) => `${vkName(k)}:${n}`),
  };
}

/**
 * A live-input script: steps run in order; each waits until `vk` has been polled `after` more times since the
 * previous step fired (inside the same tick), then releases/presses keys.
 */
function live(r, steps) {
  const counts = new Map();
  let i = 0;
  let base = 0;
  r.ctl.onPoll = (vk, ctl) => {
    counts.set(vk, (counts.get(vk) || 0) + 1);
    while (i < steps.length) {
      const s = steps[i];
      if ((counts.get(s.vk) || 0) - base < s.after) break;
      for (const k of s.release || []) ctl.keys.delete(k);
      for (const k of s.press || []) ctl.keys.add(k);
      s.at = { polledVk: vkName(vk), pollsOfStepVk: counts.get(s.vk) };
      i++;
      if (i < steps.length) base = counts.get(steps[i].vk) || 0;
    }
  };
  return () => { r.ctl.onPoll = null; return steps.map((s) => ({ ...s, release: (s.release || []).map(vkName), press: (s.press || []).map(vkName), vk: vkName(s.vk) })); };
}

/** Ticks with fixed keys until the race ends or `max` ticks; records phase changes. */
function runOut(r, max, keysPerTick = () => []) {
  const changes = [];
  let last = r.state();
  let n = 0;
  for (; n < max; n++) {
    r.ctl.keys = new Set(keysPerTick(n, r));
    let ok;
    try {
      ok = r.tick();
    } catch (e) {
      if (e instanceof SpinDetected) return { ticks: n, changes, spin: e.info };
      return { ticks: n, changes, error: String(e) };
    }
    if (!ok) {
      changes.push({ tick: r.ctl.tick, ended: true, exitCode: r.race.exitCode });
      break;
    }
    const s = r.state();
    if (s.phase !== last.phase || s.running !== last.running || s.laps !== last.laps || s.finished !== last.finished) {
      changes.push({ tick: r.ctl.tick, phase: s.phase, running: s.running, laps: s.laps, finished: s.finished, virtualMs: s.virtualMs });
    }
    last = s;
  }
  return { ticks: n, changes, ended: r.race.ended, exitCode: r.race.exitCode, last: r.race.ended ? null : r.state() };
}

const scenarios = {
  // (a) pause with P: 0x42f9c0 sets 0x53b9f8 = 1, 0x42f350 calls 0x42f220 inside handle_game 0x42f4c0
  async 'pause-frozen'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.P]);
    return { greenTick: r.greenTick, tick: probeTick(r) };
  },
  async 'pause-tap-frozen'() {
    // P reads as down for its first poll only (a host that turns a keydown into one "pressed" reading)
    const r = await toGreen();
    let first = true;
    r.ctl.keys = new Set([VK.P]);
    r.ctl.onPoll = (vk, ctl) => { if (vk === VK.P && !first) ctl.keys.delete(VK.P); if (vk === VK.P) first = false; };
    return { greenTick: r.greenTick, tick: probeTick(r) };
  },
  async 'pause-live'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.P]);
    const done = live(r, [
      { vk: VK.P, after: 40, release: [VK.P] },
      { vk: VK.Y, after: 50, press: [VK.SPACE] },        // a key during the 0..255 scan (scan has passed Y fifty times)
      { vk: VK.SPACE, after: 30, release: [VK.SPACE] },
    ]);
    const t = probeTick(r);
    const steps = done();
    const after = runOut(r, 40, () => [VK.UP]);
    return { greenTick: r.greenTick, steps, tick: t, then: after };
  },
  // (a) quit with Esc: 0x42f9c0 sets 0x53b9f8 = 2 (not in phases 1/3/6), 0x42f350 calls 0x42f290
  async 'esc-frozen'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.ESCAPE]);
    return { greenTick: r.greenTick, tick: probeTick(r) };
  },
  async 'esc-tap-frozen'() {
    const r = await toGreen();
    let seen = 0;
    r.ctl.keys = new Set([VK.ESCAPE]);
    r.ctl.onPoll = (vk, ctl) => { if (vk === VK.ESCAPE && ++seen > 1) ctl.keys.delete(VK.ESCAPE); };
    return { greenTick: r.greenTick, tick: probeTick(r) };
  },
  async 'esc-live-no'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.ESCAPE]);
    const done = live(r, [
      { vk: VK.ESCAPE, after: 40, release: [VK.ESCAPE] },
      { vk: VK.J, after: 200, press: [VK.N] },           // requester polling J/N/Esc (0x474040)
      { vk: VK.N, after: 220, release: [VK.N] },         // 0x4743b0 waits for N's release
    ]);
    const t = probeTick(r);
    const steps = done();
    const after = runOut(r, 40, () => [VK.UP]);
    return { greenTick: r.greenTick, steps, tick: t, then: after };
  },
  async 'esc-live-yes'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.ESCAPE]);
    const done = live(r, [
      { vk: VK.ESCAPE, after: 40, release: [VK.ESCAPE] },
      { vk: VK.J, after: 200, press: [VK.J] },
      { vk: VK.J, after: 230, release: [VK.J] },
    ]);
    const w0 = r.iniWrites.length;
    const t = probeTick(r);
    const steps = done();
    const after = runOut(r, 10);
    return { greenTick: r.greenTick, steps, tick: t, then: after, iniWritesAtExit: r.iniWrites.slice(w0), raceIni: raceIniSummary(r.vfs) };
  },
  // (c) D (0x44) in 0x42f9c0: cycles i32[0x53ba44] and waits for D's release, every phase
  async 'd-key-frozen'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.D]);
    return { tick: probeTick(r) };
  },
  async 'd-key-live'() {
    const r = await toGreen();
    const before = r.i32(0x53ba44);
    r.ctl.keys = new Set([VK.D]);
    const done = live(r, [{ vk: VK.D, after: 20, release: [VK.D] }]);
    const t = probeTick(r);
    return { steps: done(), tick: t, ba44: [before, r.i32(0x53ba44)] };
  },
  // (c) the unconditional cheat keys of 0x429a90: Ctrl+F+I enters phase 3 after waiting for all three to be released
  async 'finish-cheat-frozen'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]);
    return { tick: probeTick(r) };
  },
  async 'finish-cheat-live'() {
    const r = await toGreen(200);
    r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]);
    const done = live(r, [{ vk: VK.CONTROL, after: 50, release: [VK.CONTROL, VK.F, VK.I] }]);
    const t = probeTick(r);
    const steps = done();
    const w0 = r.iniWrites.length;
    const out = runOut(r, 2000);
    return { steps, tick: t, then: out, iniWritesAtExit: r.iniWrites.slice(w0), raceIni: raceIniSummary(r.vfs), messages: r.messages.slice(-5) };
  },
  // (b) phase 3 result gate 0x41fd90: after 1500 ms a held Esc/Enter/Space ends it, then it spins until all are up
  async 'finish-enter-frozen'() {
    const r = await toGreen(200);
    r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]);
    const done = live(r, [{ vk: VK.CONTROL, after: 50, release: [VK.CONTROL, VK.F, VK.I] }]);
    probeTick(r);
    done();
    const wait = runOut(r, 70);                           // 70 ticks = 1750 ms of virtual time in phase 3
    r.ctl.keys = new Set([VK.RETURN]);
    return { phase3: wait, tick: probeTick(r) };
  },
  async 'finish-enter-live'() {
    const r = await toGreen(200);
    r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]);
    const d0 = live(r, [{ vk: VK.CONTROL, after: 50, release: [VK.CONTROL, VK.F, VK.I] }]);
    probeTick(r);
    d0();
    const wait = runOut(r, 70);
    r.ctl.keys = new Set([VK.RETURN]);
    const done = live(r, [{ vk: VK.RETURN, after: 25, release: [VK.RETURN] }]);
    const t = probeTick(r);
    const steps = done();
    const out = runOut(r, 10);
    return { phase3: wait, steps, tick: t, then: out, raceIni: raceIniSummary(r.vfs) };
  },
  // (b) phase 6 (game over): INJECTED damage 99 (i32[0x53be30]) so that 0x42f1f0 enters phase 6 with mode 0
  async 'gameover-injected'() {
    const r = await toGreen();
    r.m.view.setInt32(0x53be30, 99, true);
    const idle = runOut(r, 2000);                        // 50 s of virtual time with no key
    r.ctl.keys = new Set([VK.RETURN]);
    const t = probeTick(r);
    const w0 = r.iniWrites.length;
    const out = runOut(r, 10);
    return { injected: 'i32[0x53be30] = 99', idle, enterTick: t, then: out, iniWritesAtExit: r.iniWrites.slice(w0), raceIni: raceIniSummary(r.vfs) };
  },
  // (c) WM_ACTIVATEAPP(0): pump 0x442e80 calls WaitMessage until u32[0x6abae0] is set again
  async 'inactive-pump'() {
    const r = await toGreen();
    r.host.sendToWindow(0x1c, 0, 0);
    r.ctl.keys = new Set([VK.UP]);
    return { tick: probeTick(r), note: 'the host sends WM_ACTIVATEAPP(1) only from ShowWindow (win32.js); this is latent until a blur handler sends 0' };
  },
  // (c) Ctrl+E+N in 0x429a90: waits for the release, then for a digit 1..9 (0x31..0x39)
  async 'ctrl-e-n-frozen'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.CONTROL, 0x45, VK.N]);
    return { tick: probeTick(r) };
  },
  async 'ctrl-e-n-released'() {
    // the combo is released inside the tick (live), then no digit comes: the digit wait itself
    const r = await toGreen();
    r.ctl.keys = new Set([VK.CONTROL, 0x45, VK.N]);
    live(r, [{ vk: VK.CONTROL, after: 50, release: [VK.CONTROL, 0x45, VK.N] }]);
    return { tick: probeTick(r) };
  },
  // (c) numpad 7 (0x67) in 0x489d20 (via 0x48a4f0 in handle_game): toggles and waits in 0x4893d0 for the release
  async 'numpad7-frozen'() {
    const r = await toGreen();
    r.ctl.keys = new Set([0x67]);
    return { tick: probeTick(r) };
  },
  // WinMain's Ctrl+Q (0x4432a0 -> 0x4afee0 "Emergency exit") as race.js tick() runs it
  async 'ctrl-q'() {
    const r = await toGreen();
    r.ctl.keys = new Set([VK.CONTROL, 0x51]);
    const w0 = r.iniWrites.length;
    const t = probeTick(r);
    return { tick: t, ended: r.race.ended, exitCode: r.race.exitCode, messages: r.messages.slice(-3), iniWritesAtExit: r.iniWrites.slice(w0) };
  },
  // WinMain's Backspace screenshot 0x443460 (no release wait: one file per tick while held)
  async 'backspace-screenshot'() {
    const r = await toGreen();
    const files0 = new Set(r.vfs.list());
    r.ctl.keys = new Set([VK.BACK]);
    const t = probeTick(r);
    const t2 = probeTick(r);
    return { tick: t, tick2: t2, newFiles: r.vfs.list().filter((f) => !files0.has(f)) };
  },
  // (b) a whole race: a test bot (not original behaviour) holds throttle up to ~140 km/h and steers toward route
  // chunk sector+4 (route table of 0x493430/0x493540); when the kart has moved < 15 units in 60 ticks it reverses
  // for 45 ticks, then aims 45 units left/right of the route line (alternating) for 160 ticks. Only arrow keys.
  // After the finish it presses nothing: phase 3 ends by its own 8001 ms timeout (0x41fd90).
  async 'full-race-bot'() {
    const r = await toGreen(0);
    const N = r.route.maxChunk();
    const log = [];
    let hist = [], reverse = 0, offset = 0, offTicks = 0, side = 1, stucks = 0, lastLap = 0;
    const laps = [];
    let maxKeyPolls = 0, maxClock = 0, maxClockTick = 0;
    const origTick = r.tick;
    r.tick = () => {
      const ok = origTick();
      if (r.per.keys > maxKeyPolls) maxKeyPolls = r.per.keys;
      if (r.per.clock > maxClock) { maxClock = r.per.clock; maxClockTick = r.ctl.tick; }
      return ok;
    };
    const res = runOut(r, BOT_TICKS, (n, rr) => {
      const s = rr.state();
      if (s.laps !== lastLap) { laps.push({ lap: s.laps, tick: rr.ctl.tick, virtualMs: s.virtualMs, position: s.position, fastestLap: s.fastestLap, stucks }); lastLap = s.laps; }
      if (s.phase !== 0 && s.phase !== 8) return [];
      const p = rr.player();
      const c = ((p.sector + 4) % N + N) % N;
      const t = rr.route.pos(c);
      const w = rr.u32(0x680b28) + rr.route.waypoint(c) * 0x984;
      if (offTicks > 0) { offTicks--; t[0] += -rr.f32(w + 0x50) * offset; t[2] += rr.f32(w + 0x48) * offset; }
      const dx = t[0] - p.x, dz = t[2] - p.z;
      const fx = p.mat[8], fz = p.mat[10];               // forward = matrix row 2 (checked against motion)
      const ang = Math.atan2(fx * dz - fz * dx, fx * dx + fz * dz);   // > 0: target is to the LEFT (checked)
      hist.push([p.x, p.z]);
      if (hist.length > 60) hist.shift();
      const moved = hist.length === 60 ? Math.hypot(hist[59][0] - hist[0][0], hist[59][1] - hist[0][1]) : 999;
      if (reverse === 0 && moved < 15) { reverse = 45; hist = []; stucks++; side = -side; offset = 45 * side; offTicks = 0; }
      if (n % 400 === 0) log.push({ tick: rr.ctl.tick, sector: p.sector, laps: s.laps, kmh: s.kmh, pos: s.position, phase: s.phase, x: s.x, z: s.z, ang: +ang.toFixed(2) });
      if (reverse > 0) {
        reverse--;
        if (reverse === 0) offTicks = 160;
        return [VK.DOWN, ang > 0 ? VK.RIGHT : VK.LEFT];
      }
      const keys = [];
      const want = Math.abs(ang) > 0.5 ? 70 : 140;
      if (s.kmh < want) keys.push(VK.UP);
      else if (s.kmh > want + 40) keys.push(VK.DOWN);
      if (ang > 0.05) keys.push(VK.LEFT);
      else if (ang < -0.05) keys.push(VK.RIGHT);
      return keys;
    });
    return {
      bot: 'test driver, not original behaviour', greenTick: r.greenTick, routeChunks: N, laps, stucks, result: res,
      perTickMax: { keyPolls: maxKeyPolls, clockQueries: maxClock, atTick: maxClockTick, virtualClockBumpAfter: 2000 },
      final: r.race.ended ? null : r.state(), raceIni: raceIniSummary(r.vfs),
      iniWrites: r.iniWrites.filter((x) => x.tick > r.greenTick), sample: log, messages: r.messages.slice(-5),
    };
  },
};

const results = {};
const summary = [];
for (const [name, fn] of Object.entries(scenarios)) {
  if (ONLY && !ONLY.includes(name)) continue;
  const t0 = performance.now();
  try {
    results[name] = await fn();
  } catch (e) {
    results[name] = { error: (e.stack || String(e)).split('\n').slice(0, 8).join(' | ') };
  }
  results[name].wallMs = Math.round(performance.now() - t0);
  const x = results[name];
  const t = x.tick || x.enterTick;
  const line = x.error ? 'ERROR ' + x.error
    : t && t.spin ? `HANG (${t.spin.reason}; polled ${t.spin.topPolledVKs.join(' ')}; phase ${t.spin.phase}, pause ${t.spin.pauseKind})`
    : t && t.error ? 'ERROR ' + t.error
    : t ? `returned: keyPolls ${t.keyPolls}, clockQueries ${t.clockQueries}, +${t.virtualMsInsideTick} ms inside the tick, phase ${t.after && t.after.phase}`
    : '';
  const full = `${name.padEnd(22)} ${line} ${x.then ? '| then ' + JSON.stringify(x.then.changes.slice(-3)) : ''} ${x.laps ? '| laps ' + JSON.stringify(x.laps) : ''}`.trimEnd();
  console.log(full);
  summary.push(full);
  writeFileSync(join(OUT, name + '.json'), JSON.stringify(results[name], null, 1) + '\n');
}
if (!ONLY) {
  const sha = (p) => createHash('sha256').update(readFileSync(join(ROOT, p))).digest('hex');
  writeFileSync(join(OUT, 'summary.json'), JSON.stringify({
    command: 'node tools/checks/full-race-gaps.mjs', node: process.version, date: new Date().toISOString(),
    wasmSha256: sha('public/game/rcskspel.wasm'), metaSha256: sha('public/game/rcskspel.meta.json'),
    spinLimitPerTick: 400000, lines: summary,
  }, null, 1) + '\n');
}
