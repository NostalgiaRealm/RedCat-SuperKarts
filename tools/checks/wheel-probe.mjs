#!/usr/bin/env node
// The karts' wheels and drivers in the renderer's pairing at speed (turbo, Normaal/Moeilijk): a headless race with the
// random-bonus cheat (Ctrl+Enter+Space) and the bonus key fired until turbos come, through the renderer's own drawInfo
// and pair. Each draw of a kart part (render-replay.js: slot +0x64.. parts) is told by its world matrix; per pairing
// it reports parts paired with another kart's or another wheel, and parts cut loose (shown at the newer pass) while
// their body is blended, or the other way round.  node tools/checks/wheel-probe.mjs [--ticks 3000] [--etappe 0] [--difficulty 2]
import { readFileSync, readdirSync, statSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { Vfs } from '../../source/host/vfs.js';
import { Race } from '../../source/host/race.js';
import { writeHandoff } from '../../source/host/race-handoff.js';
import { createRecorder, CMD, CMD_SIZE } from '../../source/render/recorder.js';
import { GLRenderer } from '../../source/render/gl-renderer.js';
import { OPT } from '../../source/web/shared.js';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (n, d) => { const k = process.argv.indexOf('--' + n); return k < 0 ? d : process.argv[k + 1]; };
const TICKS = Number(opt('ticks', 3000)), ETAPPE = Number(opt('etappe', 0)), DIFF = Number(opt('difficulty', 2));
const dataDir = process.env.SUPERKARTS_DATA || join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c', 'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
const gameDir = join(ROOT, 'public/game');
const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
const wasm = new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm')));
const SLOTS = 0x0067ee20, OBJECTS = 0x006a5c38, COUNT = 0x0067ee24;
const TELEPORT = 30, FOLLOW_JUMP = 150;   // gl-renderer.js

function keptFrame(d) {
  const c = new Float64Array(d.buf, 0, d.nc);
  let flat = false, flips = 0;
  for (let k = 0; k < d.nc; k += CMD_SIZE[c[k]] || 1) { if (c[k] === CMD.IMAGE || c[k] === CMD.FILL || c[k] === CMD.PRESENT) flat = true; if (c[k] === CMD.FLIP) flips++; }
  if (flat || flips !== 1) return null;
  const ctx = Object.assign(Object.create(GLRenderer.prototype), { world: new Float32Array(16), view: new Float32Array(16), proj: new Float32Array(16), stats: {} });
  const frame = { c, draws: new Map(), vx: new Float32Array(d.buf, d.nc * 8, d.nv * 8) };
  let tag = null;
  for (let k = 0; k < d.nc;) {
    const op = c[k];
    if (op === CMD.TRANSFORM) { const dst = c[k + 1] === 1 ? ctx.world : c[k + 1] === 2 ? ctx.view : ctx.proj; for (let j = 0; j < 16; j++) dst[j] = c[k + 2 + j]; }
    if (op === CMD.TAG) tag = k;
    if (op === CMD.DRAW || op === CMD.DRAWIDX) {
      const ix = op === CMD.DRAWIDX;
      frame.draws.set(k, GLRenderer.prototype.drawInfo.call(ctx, frame, c[k + 1], c[k + 2], c[k + 4], c[k + 5], ix ? c[k + 6] : c[k + 3], ix ? c[k + 7] : c[k + 4], (ix ? c[k + 8] : c[k + 6]) & 1, (ix ? c[k + 8] : c[k + 6]) & 2, tag === null ? null : c, tag));
      tag = null;
    }
    if (op === CMD.FLIP) tag = null;
    k += CMD_SIZE[op] || 1;
  }
  return frame;
}

const vfs = new Vfs();
for (const name of readdirSync(dataDir)) { const p = join(dataDir, name); if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p))); }
writeHandoff(vfs, { country: ETAPPE, character: 0, raceType: 0, difficulty: DIFF });
const frames = [];
const render = createRecorder({ postMessage(d) { if (d.buf) frames.push(d); } }, null, {});
// held keys; the cheat keys are let go after some polls (the cheat waits inside its pass for their release)
const keys = new Set(); let cheatPolls = 0;
const keyDown = (vk) => {
  if (cheatPolls > 0 && (vk === 0x0D || vk === 0x20 || vk === 0x11)) { if (--cheatPolls === 0) { keys.delete(0x0D); keys.delete(0x20); keys.delete(0x11); } return true; }
  return keys.has(vk);
};
const host = { vfs, render, input: { mouseX: 320, mouseY: 240, mouseButtons: 0, keyDown, takeMouseDelta: () => null, setMouse() {} },
  audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025, clockStart: 1, fixedDate: Date.UTC(2000, 3, 17, 12),
  onFlip() {}, onMessageBox() {}, onStdout() {}, log() {}, options: OPT.SURFACE_SHADOWS | OPT.SMOOTH_ENGINE_LIGHTS | OPT.CHEATS };
const race = new Race(meta, host);
await race.instantiate(wasm, codeMap);
render.attach(race.m, host);
race.boot();
const m = race.m, v = m.view;
frames.length = 0;
keys.add(0x26);
const parts = () => {
  const out = [], table = m.u32[SLOTS >> 2], objs = m.u32[OBJECTS >> 2];
  for (let i = 0; i < m.i32[COUNT >> 2]; i++) {
    const slot = table + i * 0xd0, n = v.getInt32(slot + 0x8c, true);
    if (n <= 0 || n > 10) continue;
    const body = objs + v.getInt32(slot + 0xc, true) * 0xa9 + 0x10;
    const mat = (a) => Array.from({ length: 16 }, (_, k) => v.getFloat32(a + 4 * k, true));
    out.push({ i, part: -1, M: mat(body) });
    for (let k = 0; k < n; k++) out.push({ i, part: k, M: mat(objs + v.getInt32(slot + 0x64 + 4 * k, true) * 0xa9 + 0x10) });
  }
  return out;
};
let untagged = 0;
let prev = null, prevWho = null, pairings = 0, maxMove = 0;
const bad = { foreign: 0, otherPart: 0, partLoose: 0, bodyLoose: 0, mixed: 0 };
const examples = [];
for (let n = 0; n < TICKS; n++) {
  if (n > 400 && n % 120 === 0) { keys.add(0x11); keys.add(0x0D); keys.add(0x20); cheatPolls = 40; }
  if (n > 400 && n % 120 === 60) keys.add(0x11);
  if (n > 400 && n % 120 === 64) keys.delete(0x11);
  if (!race.tick()) break;
  const fr = frames.length === 1 ? keptFrame(frames[0]) : null;
  frames.length = 0;
  if (!fr) { prev = null; continue; }
  // which draw is which part: its world translation is the part's (body's) drawn matrix row 3
  const P = parts(), who = new Map();
  for (const d of fr.draws.values()) {
    if (d.hud || d.hold) continue;
    // the whole matrix (world-space draws have the identity, and so may a part at the origin)
    const identity = d.world.every((x, k) => x === (k % 5 === 0 ? 1 : 0));
    const p = !identity && P.find((q) => q.M.every((x, k) => x === d.world[k]));
    if (p) who.set(d, p);
  }
  if (prev) {
    pairings++;
    const ctx = Object.assign(Object.create(GLRenderer.prototype), { stats: { paired: 0, unpaired: 0, followed: 0, followSnapped: 0, held: 0 } });
    GLRenderer.prototype.pair.call(ctx, prev, fr);
    const loose = new Map();          // kart -> { body: cut loose?, parts: [cut loose?] }
    for (const [d, p] of who) {
      const e = d.partner, q = e && prevWho.get(e);
      const move = e ? Math.hypot(d.world[12] - e.world[12], d.world[13] - e.world[13], d.world[14] - e.world[14]) : 0;
      if (p.part === -1) maxMove = Math.max(maxMove, move);
      if (!d.follow) untagged++;
      // a tagged part is cut loose by its kart's move (FOLLOW_JUMP), anything else by its own (TELEPORT)
      const cut = !e || (d.follow ? Math.hypot(e.ox - d.ox, e.oy - d.oy, e.oz - d.oz) > FOLLOW_JUMP : move > TELEPORT);
      const k = loose.get(p.i) || { body: null, parts: [] };
      if (p.part === -1) k.body = cut; else k.parts.push(cut);
      loose.set(p.i, k);
      if (e && q && q.i !== p.i) { bad.foreign++; if (examples.length < 8) examples.push(`pass ${n}: kart ${p.i} part ${p.part} paired with kart ${q.i} part ${q.part} (${move.toFixed(1)} units)`); }
      else if (e && q && q.part !== p.part) { bad.otherPart++; if (examples.length < 8) examples.push(`pass ${n}: kart ${p.i} part ${p.part} paired with its part ${q.part} (${move.toFixed(1)} units)`); }
    }
    for (const [i, k] of loose) {
      if (k.body === null) continue;
      if (k.parts.some((c) => c !== k.body)) { bad.mixed++; if (examples.length < 12) examples.push(`pass ${n}: kart ${i} body ${k.body ? 'cut loose' : 'blended'}, parts ${k.parts.map((c) => (c ? 'loose' : 'blend')).join(',')}`); }
    }
  }
  prev = fr; prevWho = who;
}
console.log(`etappe ${ETAPPE}, difficulty ${DIFF}: ${pairings} pairings, the fastest body moved ${maxMove.toFixed(1)} units in a pass`);
console.log('  kart part draws not tagged with their kart:', untagged);
console.log('  part paired with another kart\'s:', bad.foreign, '| with another part of its kart:', bad.otherPart, '| karts whose parts and body were treated differently:', bad.mixed);
for (const e of examples) console.log('  ' + e);
if (untagged || bad.foreign || bad.otherPart || bad.mixed) process.exitCode = 1;
