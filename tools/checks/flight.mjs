#!/usr/bin/env node
// Free flight (source/host/free-flight.js) in Node, without a browser: one recompiled race per scenario, the flight
// asked for and steered through the host's flightWanted() and flightInput() as the game worker does.
//   node tools/checks/flight.mjs [--etappe 0] [--car 0] [--out evidence/checks/flight.txt]
// What it holds the flight to (the JS reconstruction's behaviour, ../RedCat Superkarts at 5bfe0b62):
//   take-off at the first racing pass; while flying rand (0x502978), the opponents' places, every game timer's elapsed
//   time (table 0x53a274, stride 0x14: +0 start, +8 on, +0xc pause stamp), laps (0x53ba18), GetTickCount and the
//   sound effects (held at their place) stand still, the game plays no sound and reacts to no key but Esc and P (Ctrl,
//   Alt, Space, D, 1-4 held); the whole kart (body, wheels, driver: the draws a racing pass makes around it) is drawn at
//   the flight pose and its shadow is not, every
//   chunk is drawn (the visible-chunk count at all chunks, more draws than a racing pass); the HUD stands still but
//   the minimap's dot and the kart keeps its take-off colour; the game's own P pause and its quit requester work
//   inside a flight pass (N goes back to flying, J ends the race with exit 0 and the take-off restored); landing puts
//   back every byte of the kart's record and render object but the four zeroed speeds, and of the cameras but the
//   active one's eye, which is the JS port's NativePlayerCamera reset and one step; the race then drives on (more
//   than 100 km/h in 120 passes) with the lap count unchanged; Space and C stay hidden from the game until let go.
import { writeFileSync, mkdirSync } from 'node:fs';
import { resolve, dirname } from 'node:path';
import { makeRace, VK, ROOT } from './full-race-gaps-lib.mjs';
import { haveJs, jsModule } from './race-handoff-lib.mjs';
import { recordFrames, karts, nearSets, whole } from './kart-draws-lib.mjs';

const opt = (name, def) => { const k = process.argv.indexOf('--' + name); return k < 0 ? def : process.argv[k + 1]; };
const ETAPPE = Number(opt('etappe', 0)), CAR = Number(opt('car', 0));
const OUT = resolve(ROOT, opt('out', 'evidence/checks/flight.txt'));
const lines = [];
const say = (s) => { lines.push(s); console.log(s); };
const results = [];
function check(name, ok, detail = '') {
  results.push({ name, ok: !!ok });
  say(`${ok ? 'ok  ' : 'FAIL'} ${name}${detail ? '  ' + detail : ''}`);
}

/** A race with the flight's host hooks, run to the first racing pass (phase 0). */
async function racing(opts = {}) {
  const r = await makeRace({ etappe: ETAPPE, car: CAR, ...opts });
  const flight = { want: false, input: {} };
  r.host.flightWanted = () => flight.want;
  r.host.flightInput = () => flight.input;
  r.flightCtl = flight;
  // draws of the last pass (not the HUD's): count, world translations of indexed draws with their vertex counts
  const rr = r.host.render, f32 = r.f32;
  let W = null, hudT = 0;
  r.draws = { n: 0, list: [], hud: [] };
  // the HUD's visible draws as hashes of their vertices and of the world matrix they are drawn with; a draw whose
  // lit vertices (D3DLVERTEX/TLVERTEX, colour at +16) all have alpha 0 shows nothing (overlay.ini's BackArrow at
  // 320;210 appears so while flying the wrong way: its fade-in stands still with the HUD)
  const hash = (p, n) => { let h = 0; for (let k = 0; k < n; k++) h = (h * 31 + (r.m.u32[(p >> 2) + k] | 0)) | 0; return h; };
  const hudDraw = (vt, v, nv) => {
    if (vt !== 1 && Array.from({ length: nv }, (_, k) => r.m.u32[(v + k * 32 + 16) >> 2] >>> 24).every((a) => a === 0)) return;
    r.draws.hud.push(hash(v, nv * 8) + ':' + hudT);
  };
  rr.setTransform = (t, p) => { if (t === 1) W = Array.from({ length: 16 }, (_, k) => f32(p + 4 * k)); if (rr.hud) hudT = hash(p, 16); };
  rr.drawIndexed = (prim, vt, v, nv) => {
    if (rr.hud) { hudDraw(vt, v, nv); return; }
    r.draws.n++;
    let cx = 0, cz = 0;
    if (nv === 4 && prim === 4) { for (let k = 0; k < 4; k++) { cx += f32(v + k * 32) / 4; cz += f32(v + k * 32 + 8) / 4; } }
    r.draws.list.push({ prim, nv, t: W ? W.slice(12, 15) : null, quad: nv === 4 && prim === 4 && W ? [cx * W[0] + cz * W[8] + W[12], cx * W[2] + cz * W[10] + W[14]] : null });
  };
  rr.drawPrimitive = (prim, vt, v, nv) => { if (!rr.hud) r.draws.n++; else hudDraw(vt, v, nv); };
  const tick = r.tick;
  r.tick = () => { r.draws.n = 0; r.draws.list = []; r.draws.hud = []; r.frames.length = 0; return tick(); };
  // every kart's draws per picture (kart-draws-lib.mjs): whole karts in flight and in its pause (render-replay.js)
  recordFrames(r);
  r.race.boot();
  let n = 0;
  while (r.u32(0x53b9c0) !== 0 && n < 1000) { r.tick(); n++; }
  r.greenTick = n;
  return r;
}

const gtc = (r) => { const c = r.race.clock; return Math.floor(((c.frozenUs ?? c.us) - c.offsetUs) / 1000); };
const timers = (r) => {
  const out = [];
  for (let i = 0; i < 28; i++) {
    const a = 0x53a274 + i * 0x14;
    if (r.i32(a + 8) && r.i32(a) !== -1) out.push(`${i}:${gtc(r) - r.i32(a)}`);
  }
  return out.join(' ');
};
// The timers the game's pause 0x42f350 stops (0, 3, 8..0x1b): across a pause their elapsed time may only move by the
// clock's own steps between their stop and the end of the pause (Node's clock moves 0.5 ms per reading inside a long
// pass, race.js VirtualClock.query); the others run on through a pause, as in the original.
const PAUSED = new Set([0, 3, ...Array.from({ length: 20 }, (_, k) => 8 + k)]);
const pauseDrift = (a, b) => {
  const m = (t) => new Map(t.split(' ').filter(Boolean).map((x) => x.split(':').map(Number)));
  const A = m(a), B = m(b);
  let paused = 0, other = 0;
  for (const [i, v] of A) { const d = (B.get(i) ?? NaN) - v; if (PAUSED.has(i)) paused = Math.max(paused, Math.abs(d)); else other = Math.max(other, d); }
  return { paused, other };
};
const opponents = (r) => {
  const out = [];
  for (let k = 0; k < r.i32(0x508610); k++) {
    const idx = r.i32(0x5081bc + k * 0x70), o = r.u32(0x6a5c38) + r.i32(r.u32(0x67ee20) + idx * 0xd0 + 0xc) * 0xa9;
    out.push([r.f32(o + 0x50), r.f32(o + 0x54), r.f32(o + 0x58)].map((q) => q.toFixed(2)).join(','));
  }
  return out.join(' ');
};
const frozen = (r) => ({ rand: r.u32(0x502978), opponents: opponents(r), timers: timers(r), laps: r.i32(0x53ba18), trackTime: r.i32(0x53be58), gtc: gtc(r), plays: r.host.dsound.plays });
const sounds = (r) => [...r.host.dsound.buffers].filter((b) => !b.primary && b.playing).map((b) => `${b.id}@${r.host.dsound.position(b)}`).join(' ');
const diffBytes = (a, b) => { const out = []; for (let k = 0; k < a.length; k++) if (a[k] !== b[k]) out.push('+0x' + k.toString(16)); return out; };
/** The live-input script of full-race-gaps.mjs: steps fire after `after` more polls of `vk` inside the pass. */
function live(r, steps) {
  const counts = new Map();
  let i = 0, base = 0;
  r.ctl.onPoll = (vk, ctl) => {
    counts.set(vk, (counts.get(vk) || 0) + 1);
    while (i < steps.length) {
      const s = steps[i];
      if ((counts.get(s.vk) || 0) - base < s.after) break;
      for (const k of s.release || []) ctl.keys.delete(k);
      for (const k of s.press || []) ctl.keys.add(k);
      i++;
      if (i < steps.length) base = counts.get(steps[i].vk) || 0;
    }
  };
  return () => { r.ctl.onPoll = null; return i; };
}

say(`free flight, etappe ${ETAPPE}, car ${CAR}, ${new Date().toISOString()}`);

// --- 1. take-off, flight, pause, requester, landing --------------------------------------------------------------
{
  const r = await racing();
  const F = r.race.flight;
  const normalDraws = r.draws.n;
  const near = (p, d = 40) => r.draws.list.filter((x) => x.t && Math.hypot(x.t[0] - p[0], x.t[1] - p[1], x.t[2] - p[2]) < d).map((x) => x.nv).sort((a, b) => a - b);
  const at0 = r.player();
  const karts0 = karts(r), sets0 = nearSets(r.frames.at(-1), karts0);
  const kartRacing = near([at0.x, at0.y, at0.z]);
  say(`green after ${r.greenTick} passes; a racing pass draws ${normalDraws}`);
  r.flightCtl.want = true;
  r.tick();                                           // take-off and the first flight pass
  check('takes off at the first pass in phase 0', F.active && F.flights === 1, `pose ${[F.x, F.y, F.z].map((q) => q.toFixed(1))}`);
  const S = F.saved, { rec, R } = S.at;
  const start = { x: F.x, y: F.y, z: F.z };
  const before = frozen(r);
  const soundsBefore = sounds(r);
  check('camera mode 1 (the JS chase camera), shadow slot -1, every chunk visible', r.i32(0x4e3064) === 1 && r.i32(rec + 0x28) === -1 && r.i32(0x53b9d0) === r.i32(0x680b2c) - 1,
    `mode ${r.i32(0x4e3064)} vchunks ${r.i32(0x53b9d0)} of ${r.i32(0x680b2c)} (was ${S.vchunks})`);
  // up and forward, then a right turn, with Ctrl, Alt, Space, D and the camera keys held: the game must not see them
  r.ctl.keys = new Set([VK.UP, VK.CONTROL, 0x12, VK.SPACE, VK.D, 0x31, 0x33]);
  // the HUD draws that change from one flight pass to the next, and how far the kart's lit colour (+0x34) strays
  const hudChanges = new Set();
  let hudPrev = r.draws.hud, hudCounts = new Set([hudPrev.length]), colourOff = 0;
  const channels = (c) => [16, 8, 0].map((sh) => (c >>> sh) & 0xff);
  const flightTick = () => {
    r.tick();
    r.draws.hud.forEach((h, i) => { if (h !== hudPrev[i]) hudChanges.add(i); });
    hudCounts.add(r.draws.hud.length);
    hudPrev = r.draws.hud;
    const c = channels(r.u32(rec + 0x34)), c0 = channels(S.colour);
    colourOff = Math.max(colourOff, ...c.map((q, k) => Math.abs(q - c0[k])));
  };
  r.flightCtl.input = { throttle: 1, lift: 1 };
  for (let k = 0; k < 40; k++) flightTick();
  r.flightCtl.input = { throttle: 1, steer: 1 };
  for (let k = 0; k < 40; k++) flightTick();
  r.ctl.keys = new Set();
  const after = frozen(r);
  const pose = [F.x, F.y, F.z];
  const moved = Math.hypot(F.x - start.x, F.z - start.z);
  check('moves: 40 passes up and forward, 40 turning (650 u/s, 400 u/s up)', Math.abs(F.y - start.y - 400) < 1e-6 && moved > 1000,
    `rose ${(F.y - start.y).toFixed(1)}, ${moved.toFixed(0)} units over the ground, yaw ${F.yaw.toFixed(3)}`);
  for (const k of Object.keys(before)) check(`stands still while flying: ${k}`, before[k] === after[k], before[k] === after[k] ? '' : `${before[k]} -> ${after[k]}`);
  check('sound effects held where they were', soundsBefore === sounds(r) && r.host.dsound.holding, soundsBefore.split(' ').length + ' playing');
  check('the game saw no key but Esc and P: camera mode, D counter unchanged', r.i32(0x4e3064) === 1 && r.i32(0x53ba44) === 0, `mode ${r.i32(0x4e3064)} D ${r.i32(0x53ba44)}`);
  const kart = near(pose);
  // every kart, the opponents too: the draws nearest its body as at take-off (the player's but its shadow), four wheels
  // and a driver each; before render-replay.js the opponents' wheels and drivers were drawn on their body twice, about
  // 7,000 units off (evidence/frames/flight/flight-start.png of 2026-11-25)
  const me = karts0.findIndex((k) => k.i === r.i32(0x53be28));
  const setsF = nearSets(r.frames.at(-1), karts(r));
  const kartsOk = setsF.every((set, j) => whole(set) && set.join(',') === sets0[j].filter((nv) => j !== me || nv !== 4).join(','));
  check('every kart drawn whole in flight (wheels, driver), the opponents as at take-off', kartsOk && setsF.length === 5,
    setsF.map((set, j) => (j === me ? 'player ' : '') + set.join(',')).join(' | ') + (kartsOk ? '' : '; take-off ' + sets0.map((set) => set.join(',')).join(' | ')));
  check('the whole kart is drawn at the flight pose: a racing pass\'s kart draws but the shadow', kart.join(',') === kartRacing.filter((nv) => nv !== 4).join(',') && kart.length >= 3,
    `flying ${kart.join(',')} vertices; racing ${kartRacing.join(',')}`);
  const quads = r.draws.list.filter((d) => d.quad && Math.hypot(d.quad[0] - start.x, d.quad[1] - start.z) < 25);
  check('no shadow quad left at the take-off point', quads.length === 0, quads.length + ' quads');
  // (every chunk once with the visible count at chunks - 1: 0x4304d0, 0x497ab0; checked above. The draw count grows by
  // 1.8x on Spanje to 3.6x on Nederland, so only a rise is held here)
  check('the whole track is drawn (more than 1.5x the draws of a racing pass)', r.draws.n >= 1.5 * normalDraws, `${r.draws.n} draws against ${normalDraws}`);
  const cam = F.camera(), eye = [r.f32(cam + 8), r.f32(cam + 12), r.f32(cam + 16)];
  const dist = Math.hypot(eye[0] - pose[0], eye[1] - pose[1], eye[2] - pose[2]);
  check('the chase camera follows (eye within 100..300 units)', dist > 100 && dist < 300, dist.toFixed(1) + ' units');
  // driving-view.js:231-234 (hud.update skipped, HUD meshes with dt 0): only the minimap's dot may move
  check('the HUD stands still while flying: one visible HUD draw changes (the minimap\'s dot)', hudChanges.size <= 1 && hudCounts.size === 1,
    `${hudChanges.size} of ${hudPrev.length} HUD draws changed (draw ${[...hudChanges].join(',')}), counts ${[...hudCounts].join(',')}`);
  // driving-view.js:264 (no captureColor for the flying kart): one 0x4903c0 step (2.5%) at most from the take-off colour
  check('the kart keeps its take-off colour while flying', colourOff <= 8, `take-off ${S.colour.toString(16)}, at most ${colourOff} levels off`);

  // the game's own pause (P) inside a flight pass: P let go, a key pressed and let go in its key scan (0x42f220)
  const t0 = timers(r);
  r.ctl.keys = new Set([VK.P]);
  const done = live(r, [{ vk: VK.P, after: 40, release: [VK.P] }, { vk: VK.Y, after: 50, press: [VK.N] }, { vk: VK.N, after: 30, release: [VK.N] }]);
  const ok = r.tick();
  const steps = done();
  // the flight pause's picture (its second render, free-flight.js through render-replay.js again()): the flight
  // render's scene draw for draw, every kart whole, and its HUD with the "pauze" notice's draws after it
  {
    const [A, B] = r.frames.slice(-2);
    const ks = karts(r), sa = nearSets(A, ks), sb = nearSets(B, ks);
    const key = (d) => d.nv + '@' + (d.t ? d.t.map((q) => q.toFixed(2)).join(',') : '-');
    const sceneSame = A.scene.length === B.scene.length && A.scene.every((d, k) => key(d) === key(B.scene[k]));
    const hudSame = B.hud.length > A.hud.length && A.hud.every((h, k) => h === B.hud[k]);
    check('the flight pause shows the flight picture: every kart whole, the scene draw for draw, the HUD with the notice after it',
      r.frames.length === 2 && sb.every(whole) && sb.every((set, j) => set.join(',') === sa[j].join(',')) && sceneSame && hudSame,
      `${r.frames.length} pictures; scene ${A.scene.length}/${B.scene.length} ${sceneSame ? 'same' : 'differ'}; HUD ${A.hud.length}/${B.hud.length}; karts ${sb.map((set) => set.join(',')).join(' | ')}`);
  }
  check('P pauses inside a flight pass and any key resumes it', ok && steps === 3 && F.active && r.u32(0x53b9f8) === 0 && r.u32(0x53b9c0) === 0,
    `steps ${steps} active ${F.active} kind ${r.u32(0x53b9f8)}`);
  const dP = pauseDrift(t0, timers(r));
  check('after the pause: the paused timers as before, clock frozen again, frame dt 0.025', dP.paused <= 10 && r.race.clock.frozenUs !== null && Math.abs(r.f32(0x67ec7c) - 0.025) < 1e-6,
    `paused timers moved ${dP.paused} ms, the others ${dP.other} ms, dt ${r.f32(0x67ec7c)}`);
  // Esc and N: the quit requester (0x42f290) and back to flying
  r.ctl.keys = new Set([VK.ESCAPE]);
  const doneN = live(r, [{ vk: VK.ESCAPE, after: 40, release: [VK.ESCAPE] }, { vk: VK.J, after: 200, press: [VK.N] }, { vk: VK.N, after: 220, release: [VK.N] }]);
  const okN = r.tick();
  const stepsN = doneN(), dN = pauseDrift(t0, timers(r));
  check('Esc opens the quit requester in flight, N flies on', okN && stepsN === 3 && F.active && r.u32(0x53b9bc) === 1 && dN.paused <= 10,
    `steps ${stepsN} running ${r.u32(0x53b9bc)}, paused timers moved ${dN.paused} ms, the others ${dN.other} ms`);
  for (let k = 0; k < 5; k++) r.tick();

  // landing (the page's Stop vliegen): straight through step(), so the restored state is seen before a racing pass
  const recNow = () => r.m.u8.slice(rec, rec + 0xd0), objNow = () => r.m.u8.slice(R, R + 0xa9);
  r.ctl.keys = new Set([VK.SPACE]);
  r.flightCtl.want = false;
  const tLand = timers(r);
  r.race.flight.step(0.025);
  const recDiff = diffBytes(S.rec, recNow()), objDiff = diffBytes(S.obj, objNow());
  const zeroed = new Set(['+0x9c', '+0x9d', '+0x9e', '+0x9f', '+0xa0', '+0xa1', '+0xa2', '+0xa3', '+0xa4', '+0xa5', '+0xa6', '+0xa7', '+0xac', '+0xad', '+0xae', '+0xaf']);
  const partDiff = F.parts.filter((p) => diffBytes(p.bytes, r.m.u8.slice(p.P, p.P + 0xa9)).length).length;
  check('landing: the render object and its parts (wheels, driver) as at take-off', objDiff.length === 0 && partDiff === 0, `${objDiff.join(' ')} ${F.parts.length} parts, ${partDiff} differ`);
  check('landing: the racer record as at take-off but the zeroed speeds', recDiff.every((k) => zeroed.has(k)), recDiff.join(' ') || 'no difference');
  // the cameras as before the flight but the active one's eye, view (+0x08..+0x6b: eye, matrix, target, up) and
  // damped eye (+0xa0..+0xab), which landing resets and steps once (race-simulation.js:630-633)
  const camBase = r.u32(0x680ba0), active = F.camera() - camBase;
  const reset = (k) => k >= active + 0x08 && k < active + 0x6c || k >= active + 0xa0 && k < active + 0xac;
  const camDiff = [...r.m.u8.slice(camBase, camBase + 10 * 0x178)].map((b, k) => (b !== S.cameras[k] && !reset(k) ? k : -1)).filter((k) => k >= 0);
  check('landing: cameras, mode, visible chunks, dot back; clock and sounds go on', r.i32(0x4e3064) === S.mode && r.i32(0x53b9d0) === S.vchunks && r.race.clock.frozenUs === null && !r.host.dsound.holding
    && camDiff.length === 0, `mode ${r.i32(0x4e3064)} vchunks ${r.i32(0x53b9d0)}, camera bytes off ${camDiff.length}`);
  // The JS reconstruction's landing camera: NativePlayerCamera setMode(mode).reset(body) and one step(body), the body
  // level at the take-off pose (restoreFlightPose); free-flight.js levels the kart's matrix for its 0x498c00 step too.
  if (haveJs()) {
    const { NativePlayerCamera } = await jsModule('simulation/native-camera.js');
    const p = r.player(), unit = 4096 / (2 * Math.PI);
    const { nativeRotationMatrix } = await jsModule('simulation/native-transform.js');
    const body = { position: [p.x, p.y, p.z], matrix: nativeRotationMatrix([0, S.yaw * unit, 0]) };
    const js = new NativePlayerCamera().setMode(S.mode).reset(body).step(body).position;
    const ours = [8, 12, 16].map((o) => r.f32(F.camera() + o));
    const off = Math.hypot(...ours.map((q, k) => q - js[k]));
    check('landing: the chase camera reset behind the kart and stepped once, as the JS port (within 0.05 units)', off < 0.05,
      `eye ${ours.map((q) => q.toFixed(2))}, JS ${js.map((q) => q.toFixed(2))}, ${off.toFixed(2)} apart; before the flight ${[8, 12, 16].map((o) => new DataView(S.cameras.buffer).getFloat32(active + o, true).toFixed(2))}`);
    check('landing: the camera\'s last chunk is the kart\'s (cameraSectors.set)', r.i32(0x508648 + 4 * r.i32(0x508670)) === r.i32(rec + 0x1c), `chunk ${r.i32(0x508648 + 4 * r.i32(0x508670))}`);
  }
  check('landing: the game\'s time goes on from where it stood (elapsed times as in flight)', timers(r) === tLand, `take-off ${before.timers}; landing ${timers(r)}`);
  check('Space stays hidden after landing until let go', F.hidden.has(VK.SPACE) && r.m.call(0x4b3830, [VK.SPACE]) === 0);
  r.ctl.keys = new Set([VK.UP]);
  r.tick();
  check('…and is seen again once let go', !F.hidden.has(VK.SPACE));
  let crash = null, maxKmh = 0;
  try { for (let k = 0; k < 120; k++) { r.tick(); maxKmh = Math.max(maxKmh, r.i32(0x53be34)); } } catch (e) { crash = e.message; }
  check('the race drives on after landing', !crash && maxKmh > 100 && r.u32(0x53b9c0) === 0 && r.i32(0x53ba18) === before.laps && soundsBefore !== sounds(r),
    `${crash || ''} max ${maxKmh} km/h, laps ${r.i32(0x53ba18)}, rpm ${r.f32(0x507290).toFixed(0)} gear ${r.i32(0x507298)}`);
  check('one flight in this race', F.flights === 1, `${F.passes} flight passes`);
}

// --- 2. the quit requester's J while flying ends the race, landed first -----------------------------------------
{
  const r = await racing();
  const F = r.race.flight;
  r.flightCtl.want = true;
  r.flightCtl.input = { throttle: 1, lift: 1 };
  for (let k = 0; k < 20; k++) r.tick();
  const S = F.saved;
  r.ctl.keys = new Set([VK.ESCAPE]);
  const done = live(r, [{ vk: VK.ESCAPE, after: 40, release: [VK.ESCAPE] }, { vk: VK.J, after: 200, press: [VK.J] }, { vk: VK.J, after: 230, release: [VK.J] }]);
  r.tick();
  done();
  r.ctl.keys = new Set();
  let ended = false;
  for (let k = 0; k < 5 && !ended; k++) ended = !r.tick();
  const R = S.at.R;
  const objDiff = diffBytes(S.obj, r.m.u8.slice(R, R + 0xa9));
  check('Esc and J while flying end the race with exit 0, landed (no neutralizing)', ended && r.race.exitCode === 0 && !F.active && r.i32(0x53b9d0) === S.vchunks && objDiff.length === 0,
    `exit ${r.race.exitCode} vchunks ${r.i32(0x53b9d0)} object diff ${objDiff.join(' ') || 'none'}`);
}

// --- 3. a take-off at speed (the setting switched on during a race: development page, checks) -------------------
{
  const r = await racing();
  const F = r.race.flight;
  r.ctl.keys = new Set([VK.UP]);
  for (let k = 0; k < 60; k++) r.tick();
  const kmh0 = r.i32(0x53be34), rpm0 = r.f32(0x507290), gear0 = r.i32(0x507298);
  r.flightCtl.want = true;
  r.flightCtl.input = { throttle: 1 };
  for (let k = 0; k < 10; k++) r.tick();
  const S = F.saved, { rec } = S.at;
  r.ctl.keys = new Set();
  r.flightCtl.want = false;
  F.step(0.025);
  const recDiff = diffBytes(S.rec, r.m.u8.slice(rec, rec + 0xd0));
  const speeds = [0x9c, 0xa0, 0xa4, 0xac].map((o) => r.f32(rec + o));
  check('landing at speed: only the speeds differ from the take-off, and they are 0', recDiff.length > 0 && recDiff.every((k) => ['9c', '9d', '9e', '9f', 'a0', 'a1', 'a2', 'a3', 'a4', 'a5', 'a6', 'a7', 'ac', 'ad', 'ae', 'af'].includes(k.slice(3))) && speeds.every((v) => v === 0),
    `took off at ${kmh0} km/h, rpm ${rpm0.toFixed(0)}, gear ${gear0}; changed ${recDiff.join(' ')}`);
  r.tick();
  const idle = { kmh: r.i32(0x53be34), rpm: r.f32(0x507290), gear: r.i32(0x507298) };
  check('rpm 0 and gear 0 (the engine before the start) give a standstill and idle', Math.abs(idle.kmh) <= 1 && idle.gear === 0 && idle.rpm > 0 && idle.rpm <= 1000, JSON.stringify(idle));
  r.ctl.keys = new Set([VK.UP]);
  let maxKmh = 0;
  for (let k = 0; k < 120; k++) { r.tick(); maxKmh = Math.max(maxKmh, r.i32(0x53be34)); }
  check('…and the kart pulls away again', maxKmh > 100, `max ${maxKmh} km/h`);
}

// --- 4. setting off: nothing changes ------------------------------------------------------------------------------
{
  const a = await racing(), b = await racing();
  b.host.flightWanted = undefined;
  a.ctl.keys = new Set([VK.UP]); b.ctl.keys = new Set([VK.UP]);
  for (let k = 0; k < 200; k++) { a.tick(); b.tick(); }
  const same = a.m.u8.length === b.m.u8.length && Buffer.compare(Buffer.from(a.m.u8.buffer, 0, 0x800000), Buffer.from(b.m.u8.buffer, 0, 0x800000)) === 0;
  check('with the setting off the race is the same as without the flight host (first 8 MB of memory after 200 passes)', same && !a.race.flight.flights);
}

const failed = results.filter((x) => !x.ok).length;
say(`${results.length - failed} of ${results.length} checks passed`);
mkdirSync(dirname(OUT), { recursive: true });
writeFileSync(OUT, lines.join('\n') + '\n');
process.exit(failed ? 1 : 0);
