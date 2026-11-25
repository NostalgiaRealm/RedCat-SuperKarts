#!/usr/bin/env node
// Runs the recompiled race without a browser, against the original installation's data folder.
// For boot checks, listing the files a race reads, and counting what it draws.
//   node tools/run-headless.mjs [--data DIR] [--ticks 200] [--etappe 0] [--car 0] [--race 0] [--difficulty 1] [--gas] [--trace-api]
// DIR defaults to SUPERKARTS_DATA, else the installation copy inside the SuperKarts reconstruction. --etappe (country,
// track.ini order NED DUI ENG FRA SPA ITA), --car (character: RedCat, WhizzKitty, Brutus, Max), --race (Landenrace,
// Tijdrace, Sterrenrace, duel) and --difficulty go through the menu's handoff (source/host/race-handoff.js).
import { readFileSync, readdirSync, statSync, writeFileSync, mkdirSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { Vfs } from '../source/host/vfs.js';
import { Race } from '../source/host/race.js';
import { writeHandoff } from '../source/host/race-handoff.js';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const flag = (name) => process.argv.includes('--' + name);
const DEFAULT_DATA = join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c',
  'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
const dataDir = opt('data', process.env.SUPERKARTS_DATA || DEFAULT_DATA);
const gameDir = opt('game', join(ROOT, 'public/game'));
const ticks = Number(opt('ticks', 200));

const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
const vfs = new Vfs();
for (const name of readdirSync(dataDir)) {
  const p = join(dataDir, name);
  if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p)));
}
const handoff = writeHandoff(vfs, { country: Number(opt('etappe', 0)), character: Number(opt('car', 0)), raceType: Number(opt('race', 0)),
  difficulty: opt('difficulty', null) === null ? undefined : Number(opt('difficulty', 1)) });
console.log('handoff:', JSON.stringify({ country: handoff.country, raceType: handoff.raceType, difficulty: handoff.difficulty, car: handoff.car, roster: handoff.roster }));
const stats = { draws: 0, indexed: 0, verts: 0, tris: 0, states: 0, flips: 0, textures: 0, clears: 0, blits: 0, transforms: 0 };
const primCount = {};
const render = {
  freeTexture() {}, fillScreen() {}, blitToScreen() { stats.blits++; }, loadTexture() { stats.textures++; },
  setBackground() {}, clear() { stats.clears++; }, setViewport(v) { if (flag('verbose')) console.log('viewport', JSON.stringify(v)); },
  beginScene() {}, endScene() {}, setRenderState() { stats.states++; }, setLightState() {}, setTransform() { stats.transforms++; },
  drawPrimitive(p, t, v, n) { stats.draws++; stats.verts += n; const k = 'dp' + p + '/' + t; primCount[k] = (primCount[k] || 0) + 1; },
  drawIndexed(p, t, v, nv, i, ni) { stats.indexed++; stats.verts += nv; stats.tris += ni / 3; const k = 'dip' + p + '/' + t; primCount[k] = (primCount[k] || 0) + 1; },
};
const keys = new Set();
const input = {
  mouseX: 320, mouseY: 240, mouseButtons: 0,
  keyDown: (vk) => keys.has(vk),
  takeMouseDelta: () => null,
  setMouse(x, y) { this.mouseX = x; this.mouseY = y; },
};
const filesRead = new Set();
vfs.onRead = (p) => filesRead.add(p);
const host = {
  vfs, render, input, audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025, clockStart: 1,
  fixedDate: Date.UTC(2000, 3, 17, 12),
  onFlip() { stats.flips++; },
  onMessageBox: (c, t) => console.log('MessageBox:', c, '|', t),
  onStdout: (t) => process.stdout.write('[stdout] ' + t),
  log: (s) => console.log('[host] ' + s),
};
const race = new Race(meta, host);
await race.instantiate(new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm'))), codeMap);
console.log('unbound imports:', race.unbound.filter((n) => !n.startsWith('hook!')).join(', ') || 'none');
const m = race.m;
if (flag('trace-api')) {
  const names = m.thunkNames;
  m.traceApi = (id) => { if (names[id] && !names[id].startsWith('hook!')) process.stdout.write(names[id] + '\n'); };
}
let t0 = performance.now();
try {
  race.boot();
} catch (e) {
  console.log('BOOT FAILED:', e.message);
  console.log((e.stack || '').split('\n').slice(0, 8).join('\n'));
  process.exitCode = 1;
}
console.log('boot ms', (performance.now() - t0).toFixed(0), 'heap', (host.heap.bytesInUse / 1048576).toFixed(1), 'MB', JSON.stringify(stats));
mkdirSync(join(ROOT, 'evidence', 'headless'), { recursive: true });
writeFileSync(join(ROOT, 'evidence', 'headless', 'files-read.txt'), [...filesRead].sort().join('\n') + '\n');
if (!process.exitCode) {
  Object.keys(stats).forEach((k) => { stats[k] = 0; });
  t0 = performance.now();
  if (flag('gas')) keys.add(0x26);
  let n = 0;
  try {
    const every = Number(opt('pos-every', 0));
    const pose = () => {
      const racers = m.u32[0x0067ee20 >> 2], objs = m.u32[0x006a5c38 >> 2], me = m.i32[0x0053be28 >> 2];
      if (!racers || !objs) return 'no racer table';
      // me is the player's engine slot (0x415f90, stored at 0x431ab5): scenery fills the slots before the karts
      // the engine body (stride 0xd0) holds the speeds and its render object; the render object (stride 0xa9) the
      // position at +0x50 (tools/checks/start-trace.mjs has the field list)
      const body = racers + me * 0xd0;
      const obj = objs + m.view.getInt32(body + 0xc, true) * 0xa9;
      const f = (p) => m.view.getFloat32(p, true).toFixed(1);
      return `player ${me} at ${f(obj + 0x50)} ${f(obj + 0x54)} ${f(obj + 0x58)} speed ${f(body + 0xa4)} km/h ${m.i32[0x0053be34 >> 2]} lap ${m.i32[0x0053ba18 >> 2]} phase ${m.u32[0x0053b9c0 >> 2]}`;
    };
    for (; n < ticks && race.tick(); n++) if (every && n % every === 0) console.log('tick', n, pose());
    if (every) console.log('tick', n, pose());
  } catch (e) {
    console.log('TICK', n, 'FAILED:', e.message);
    console.log((e.stack || '').split('\n').slice(0, 8).join('\n'));
    process.exitCode = 1;
  }
  console.log('ticks', n, 'ms', (performance.now() - t0).toFixed(0), 'ended', race.ended, 'exit', race.exitCode, JSON.stringify(stats), JSON.stringify(primCount));
  const ds = host.dsound, playing = [...ds.buffers].filter((b) => !b.primary && (ds.position(b), b.playing));
  console.log('sound: buffers', ds.buffers.size, 'plays', ds.plays, 'playing now', playing.length, 'looping', playing.filter((b) => b.loop).length,
    'music', JSON.stringify((host.musicGraphs || []).map((g) => ({ file: g.file, state: g.state, duration: +g.duration.toFixed(1), volume: g.volume }))));
}
