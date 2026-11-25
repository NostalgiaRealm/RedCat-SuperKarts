#!/usr/bin/env node
// Per-tick trace of the race start in the recompiled rcskspel.dat: race phase, the 321 countdown, the start camera
// path, the player's position/speed/lap and the engine timer. Read-only: it only reads guest memory after each tick.
//   node tools/checks/start-trace.mjs [--ticks 400] [--tick-ms 25] [--no-gas] [--data DIR] [--etappe 0] [--car 0]
// Same host set-up as tools/run-headless.mjs (source/host/*.js), without its file-list and draw statistics.
//
// Guest addresses (rcskspel.dat, original-source/modules/rcskspel.dat of the SuperKarts reconstruction):
//   player racer index  i32[0x53be28]   written by 0x4319f0 at 0x431ab5 from 0x415f90 (engine T_ARRAY slot)
//   engine body table   u32[0x67ee20]   stride 0xd0 (0x42f519..0x42f528): +0x0c render object, +0x1c sector,
//                                       +0x20 previous sector, +0x9c lateral, +0xa4 forward speed (0x432696)
//   render objects      u32[0x6a5c38]   stride 0xa9 (0x42f58c..0x42f5a4), 4x4 matrix at +0x10, position +0x50
//   race phase          u32[0x53b9c0]   0x42f740; 1 opening/countdown, 0 racing, 3 finished, 4 exit, 6 failed
//   movement / active   u32[0x53b9e0], u32[0x53be54]   (0x42f930 clears both, 0x42f740(0) sets them)
//   km/h                i32[0x53be34]   trunc(forward*3.6) at 0x4326ab
//   laps / lap limit    i32[0x53ba18] / i32[0x53ba1c]   (0x440c30); finished flag i32[0x53be50] (0x440d70)
//   321 countdown       u32[0x53a5f8+0xa0] (0x469500), +0x04 elapsed f32, +0x08 sound step, +0x18 phase (0x464a70)
//   start camera stage  i32[0x53f4ec]  (0x4441a0: 0 wait 1000 ms, 1 path, 2 approach), its start tick u32[0x53f4f0]
//   CRT rand state      u32[0x502978]  (srand 0x4be6bf, rand 0x4be6c9)
//   engine timer        0x67ec70: +4 freq f32, +8 absolute f32, +0xC filtered dt f32 (0x48f3e0);
//                       history u32[0x67ec28] (4 f32), ring index i32[0x67ec80]; 0x48f4e0 = getter with the .1 cap
import { readFileSync, readdirSync, statSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { Vfs } from '../../source/host/vfs.js';
import { Race } from '../../source/host/race.js';
import { pinRace } from '../../source/host/race-setup.js';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const flag = (name) => process.argv.includes('--' + name);
const DEFAULT_DATA = join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c',
  'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
const dataDir = opt('data', process.env.SUPERKARTS_DATA || DEFAULT_DATA);
const gameDir = opt('game', join(ROOT, 'public/game'));
const ticks = Number(opt('ticks', 400));
const tickMs = Number(opt('tick-ms', 25));
const gas = !flag('no-gas');
const npcEvery = Number(opt('npc-every', 0));   // also print the four opponents' positions/speeds every N ticks
// --rand-callers T1,T2,..: with a build made with --trace 4be6c9 (rand) passed as --game, list rand's return
// addresses in those ticks (0 = boot). The build only adds env.trace calls on rand's entry.
const randTicks = new Set(String(opt('rand-callers', '')).split(',').filter(Boolean).map(Number));

const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
const vfs = new Vfs();
for (const name of readdirSync(dataDir)) {
  const p = join(dataDir, name);
  if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p)));
}
pinRace(vfs, { etappe: Number(opt('etappe', 0)), car: Number(opt('car', 0)) });
const nop = () => {};
const render = {
  freeTexture: nop, fillScreen: nop, blitToScreen: nop, loadTexture: nop, setBackground: nop, clear: nop,
  setViewport: nop, beginScene: nop, endScene: nop, setRenderState: nop, setLightState: nop, setTransform: nop,
  drawPrimitive: nop, drawIndexed: nop,
};
const keys = new Set();
const input = {
  mouseX: 320, mouseY: 240, mouseButtons: 0,
  keyDown: (vk) => keys.has(vk),
  takeMouseDelta: () => null,
  setMouse(x, y) { this.mouseX = x; this.mouseY = y; },
};
const host = {
  vfs, render, input, audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: tickMs / 1000,
  clockStart: 1, fixedDate: Date.UTC(2000, 3, 17, 12),
  onFlip: nop, onMessageBox: (c, t) => console.log('MessageBox:', c, '|', t), onStdout: nop, log: nop,
};
const race = new Race(meta, host);
await race.instantiate(new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm'))), codeMap);
const m = race.m;

// QueryPerformanceCounter / GetTickCount reads, to see exactly what the timer saw.
let qpcReads = 0, tickReads = 0;
const countThunk = (name, counter) => {
  const id = m.thunkId(name), inner = m.thunks[id];
  m.thunks[id] = (...a) => { counter(); return inner(...a); };
};
countThunk('KERNEL32.DLL!QueryPerformanceCounter', () => qpcReads++);
countThunk('KERNEL32.DLL!GetTickCount', () => tickReads++);

let randLog = null;
if (randTicks.size) m.onTrace = (addr, esp) => { if (addr === 0x004be6c9 && randLog) randLog.push(m.u32[esp >> 2]); };
const randReport = (n) => {
  if (!randLog) return;
  const c = new Map();
  for (const a of randLog) c.set(a, (c.get(a) || 0) + 1);
  console.log(`#rand tick ${n}: ${randLog.length} draws: ${[...c].map(([a, k]) => a.toString(16) + 'x' + k).join(' ')}`);
};
const f32 = (a) => m.view.getFloat32(a, true);
const i32 = (a) => m.view.getInt32(a, true);
const u32 = (a) => m.view.getUint32(a, true);
const TIMER = 0x0067ec70;
const fmt = (x, d = 4) => (Number.isFinite(x) ? x.toFixed(d) : String(x));

function timer() {
  const hist = u32(0x0067ec28), idx = i32(0x0067ec80);
  const stored = f32(TIMER + 0xc);
  const getter = stored === 0 || stored > 0.1 ? Math.fround(0.1) : stored;   // 0x48f4e0
  const raw = hist ? f32(hist + (((idx - 1) & 3) * 4)) : NaN;               // newest history entry
  return { abs: f32(TIMER + 8), freq: f32(TIMER + 4), stored, getter, raw, hist: hist ? [0, 1, 2, 3].map((k) => f32(hist + k * 4)) : [], idx };
}

function state() {
  const racers = u32(0x0067ee20), objs = u32(0x006a5c38), me = i32(0x0053be28);
  const s = { me, phase: u32(0x0053b9c0), moving: u32(0x0053b9e0), active: u32(0x0053be54),
    laps: i32(0x0053ba18), lapLimit: i32(0x0053ba1c), finished: i32(0x0053be50), rank: i32(0x0053be60), kmh: i32(0x0053be34),
    throttle: f32(0x0053bd74), camStage: i32(0x0053f4ec), rng: u32(0x00502978) };
  const cd = u32(0x0053a5f8 + 0xa0);
  s.cd = cd ? { phase: i32(cd + 0x18), elapsed: f32(cd + 4), sound: i32(cd + 8) } : null;
  if (racers && objs) {
    const b = racers + me * 0xd0;
    s.obj = i32(b + 0xc);
    s.sector = i32(b + 0x1c);
    s.prevSector = i32(b + 0x20);
    s.lateral = f32(b + 0x9c);
    s.vertical = f32(b + 0xa0);
    s.forward = f32(b + 0xa4);
    const o = objs + s.obj * 0xa9;
    // Position is object +0x50/+0x54/+0x58 (ground placement 0x416650 reads and writes it at 0x41682b/0x416892).
    // The matrix translation +0x40/+0x44/+0x48 is a copy 0x4a09e0 refreshes (0x4a0d2f..0x4a0d41) when it rebuilds
    // the matrix, so after the ground callback it is one update old.
    s.pos = [f32(o + 0x50), f32(o + 0x54), f32(o + 0x58)];
    s.mat = [f32(o + 0x40), f32(o + 0x44), f32(o + 0x48)];
  }
  return s;
}

function racerTable() {
  // Every allocated engine slot that is a kart (its render object exists and sector is a route index).
  const racers = u32(0x0067ee20), cap = i32(0x0067ee24), used = u32(0x0067ee30), objs = u32(0x006a5c38);
  const out = [];
  for (let k = 0; k < cap; k++) {
    if (!m.u8[used + k]) continue;
    const b = racers + k * 0xd0;
    const flags = u32(b + 4);
    if ((flags & 3) !== 3) continue;                       // 0x415f90 ORs 3 into +4 for karts
    const o = objs + i32(b + 0xc) * 0xa9;
    out.push({ k, flags: flags.toString(16), obj: i32(b + 0xc), sector: i32(b + 0x1c), pos: [f32(o + 0x50), f32(o + 0x54), f32(o + 0x58)].map((x) => x.toFixed(1)).join(' ') });
  }
  return { cap, last: i32(0x0067ee28), karts: out };
}

console.log(`# start-trace: rcskspel.wasm, data ${dataDir}`);
console.log(`# etappe ${opt('etappe', 0)} car ${opt('car', 0)}, tick ${tickMs} ms of virtual time, gas ${gas ? 'held from tick 1 (VK_UP)' : 'off'}`);
randLog = randTicks.has(0) ? [] : null;
race.boot();
randReport(0);
const t0 = timer();
console.log(`# after boot: clock ${race.clock.seconds.toFixed(6)} s, QPC reads ${qpcReads}, GetTickCount reads ${tickReads}`);
console.log(`# timer after 0x48f2c0 (constructor + priming update): abs ${t0.abs} freq ${t0.freq} stored dt ${t0.stored} getter ${t0.getter} history [${t0.hist.join(', ')}] idx ${t0.idx}`);
console.log(`# start camera: stage ${i32(0x0053f4ec)}, start tick ${u32(0x0053f4f0)} ms`);
const rt = racerTable();
console.log(`# engine T_ARRAY capacity ${rt.cap}, last allocated ${rt.last}; kart slots (flags&3==3):`);
for (const r of rt.karts) console.log(`#   slot ${r.k} flags ${r.flags} obj ${r.obj} sector ${r.sector} pos ${r.pos}${r.k === i32(0x0053be28) ? '  <- i32[0x53be28] player' : ''}`);
const s0 = state();
console.log(`# player ${s0.me}: obj ${s0.obj} sector ${s0.sector} pos ${s0.pos.map((x) => x.toFixed(3)).join(' ')} (matrix row +0x40: ${s0.mat.map((x) => x.toFixed(3)).join(' ')}) phase ${s0.phase} countdown phase ${s0.cd?.phase} rand state ${s0.rng.toString(16)}`);
console.log('');
console.log('tick  game_s  GTC_ms  phase mv act cam cd_ph cd_el    raw_dt    stored_dt getter_dt  x         y        z         sector fwd       lat      kmh lap/lim fin thr   rng');

if (gas) keys.add(0x26);
const events = [];
let prev = s0, startPos = s0.pos, firstMove = null, green = null, cdStart = null, cdEnd = null;
const speedAt = {};
for (let n = 1; n <= ticks; n++) {
  qpcReads = 0; tickReads = 0;
  randLog = randTicks.has(n) ? [] : null;
  if (!race.tick()) { console.log('race ended at tick', n, 'exit', race.exitCode); break; }
  randReport(n);
  const s = state(), t = timer();
  const gtc = Math.floor(race.clock.seconds * 1000) >>> 0;
  const gameS = n * tickMs / 1000;
  console.log([
    String(n).padStart(4), gameS.toFixed(3).padStart(7), String(gtc).padStart(7), String(s.phase).padStart(5), String(s.moving).padStart(2),
    String(s.active).padStart(3), String(s.camStage).padStart(3), String(s.cd?.phase ?? '-').padStart(5), fmt(s.cd?.elapsed ?? NaN, 3).padStart(6),
    fmt(t.raw, 7).padStart(9), fmt(t.stored, 7).padStart(9), fmt(t.getter, 7).padStart(9),
    fmt(s.pos[0], 3).padStart(9), fmt(s.pos[1], 3).padStart(8), fmt(s.pos[2], 3).padStart(9), String(s.sector).padStart(6),
    fmt(s.forward, 4).padStart(9), fmt(s.lateral, 4).padStart(8), String(s.kmh).padStart(4), `${s.laps}/${s.lapLimit}`.padStart(7),
    String(s.finished).padStart(3), fmt(s.throttle, 1).padStart(5), s.rng.toString(16).padStart(8, '0'),
  ].join(' '));
  if (s.phase !== prev.phase) events.push(`tick ${n} (${gameS.toFixed(3)} s): race phase ${prev.phase} -> ${s.phase}`);
  if (s.moving !== prev.moving) events.push(`tick ${n} (${gameS.toFixed(3)} s): movement flag 0x53b9e0 ${prev.moving} -> ${s.moving}`);
  if (s.camStage !== prev.camStage) events.push(`tick ${n} (${gameS.toFixed(3)} s): start camera stage ${prev.camStage} -> ${s.camStage}`);
  if (s.cd && prev.cd && s.cd.phase !== prev.cd.phase) {
    events.push(`tick ${n} (${gameS.toFixed(3)} s): 321 phase ${prev.cd.phase} -> ${s.cd.phase}`);
    if (prev.cd.phase === 6 && s.cd.phase === 0) cdStart = n;
    if (s.cd.phase === 6 && prev.cd.phase === 5) cdEnd = n;
  }
  if (green === null && prev.phase === 1 && s.phase === 0) green = n;
  const moved = Math.hypot(s.pos[0] - startPos[0], s.pos[2] - startPos[2]);
  if (firstMove === null && (moved > 1e-4 || s.forward !== 0)) {
    firstMove = n;
    events.push(`tick ${n} (${gameS.toFixed(3)} s): first player movement: forward ${s.forward} moved ${moved.toFixed(5)}`);
  }
  if (firstMove !== null) {
    const k = n - firstMove + 1;
    if ([1, 2, 4, 8, 10, 20, 40, 80, 120].includes(k)) speedAt[k] = { n, forward: s.forward, kmh: s.kmh, moved };
  }
  if (npcEvery && n % npcEvery === 0) {
    const racers = u32(0x0067ee20), objs = u32(0x006a5c38);
    const npc = [1, 2, 3, 4].map((d) => {
      const b = racers + (s.me + d) * 0xd0, o = objs + i32(b + 0xc) * 0xa9;
      return `${f32(o + 0x50).toFixed(2)} ${f32(o + 0x54).toFixed(2)} ${f32(o + 0x58).toFixed(2)} f${f32(b + 0xa4).toFixed(3)} s${i32(b + 0x1c)}`;
    });
    console.log(`#npc ${n}: ${npc.join(' | ')}`);
  }
  prev = s;
}
console.log('');
console.log('# events');
for (const e of events) console.log('#   ' + e);
console.log(`# 321 started (6->0) at tick ${cdStart}, green (race phase 1->0) at tick ${green}, 321 back to idle at tick ${cdEnd}, first movement tick ${firstMove}`);
if (cdStart && green) console.log(`# countdown start -> green: ${green - cdStart} ticks = ${((green - cdStart) * tickMs / 1000).toFixed(3)} s game time`);
console.log('# speed after k updates with movement (k = 1 is the first moving update):');
for (const [k, v] of Object.entries(speedAt)) console.log(`#   k ${k} (tick ${v.n}): forward ${v.forward.toFixed(4)} (${(v.forward * 3.6).toFixed(2)} km/h) HUD ${v.kmh} km/h, distance from start ${v.moved.toFixed(3)}`);
