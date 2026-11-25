#!/usr/bin/env node
// Do stationary objects keep their partner when the renderer pairs two passes (gl-renderer.js pair)? A headless race
// (real wasm and recorder, fixed clock, gas held) through the renderer's own drawInfo and pair; per pass, every draw
// of the newer frame that has an exact twin in the older one (same key, same world matrix, same first vertex: it did
// not move) but was paired with another draw, or left without a partner, is counted with how far off it is shown at
// mid-blend; and every draw without a partner must be seen through the blended camera (pair's camFrom), not the newer
// pass's camera.  node tools/checks/pairing-probe.mjs [--ticks 1500] [--etappes 0,3]
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
const TICKS = Number(opt('ticks', 1500));
const ETAPPES = String(opt('etappes', '0,3')).split(',').map(Number);
const dataDir = process.env.SUPERKARTS_DATA || join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c', 'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
const gameDir = join(ROOT, 'public/game');
const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
const wasm = new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm')));
let failed = 0;

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
      const info = GLRenderer.prototype.drawInfo.call(ctx, frame, c[k + 1], c[k + 2], c[k + 4], c[k + 5], ix ? c[k + 6] : c[k + 3], ix ? c[k + 7] : c[k + 4], (ix ? c[k + 8] : c[k + 6]) & 1, (ix ? c[k + 8] : c[k + 6]) & 2, tag === null ? null : c, tag);
      frame.draws.set(k, info); tag = null;
    }
    if (op === CMD.FLIP) tag = null;
    k += CMD_SIZE[op] || 1;
  }
  return frame;
}
const same = (a, b) => { for (let j = 0; j < 16; j++) if (Math.abs(a[j] - b[j]) > 1e-4) return false; return true; };

for (const etappe of ETAPPES) {
  const vfs = new Vfs();
  for (const name of readdirSync(dataDir)) { const p = join(dataDir, name); if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p))); }
  writeHandoff(vfs, { country: etappe, character: 0, raceType: 0 });
  const frames = [];
  const render = createRecorder({ postMessage(d) { if (d.buf) frames.push(d); } }, null, {});
  const keys = new Set();
  const host = { vfs, render, input: { mouseX: 320, mouseY: 240, mouseButtons: 0, keyDown: (vk) => keys.has(vk), takeMouseDelta: () => null, setMouse() {} },
    audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025, clockStart: 1, fixedDate: Date.UTC(2000, 3, 17, 12),
    onFlip() {}, onMessageBox() {}, onStdout() {}, log() {}, options: OPT.SURFACE_SHADOWS | OPT.SMOOTH_ENGINE_LIGHTS };
  const race = new Race(meta, host);
  await race.instantiate(wasm, codeMap);
  render.attach(race.m, host);
  race.boot();
  frames.length = 0;
  keys.add(0x26);
  let unpairedAll = 0, newerCam = 0; const unpairedWhy = {};
  let prev = null, passes = 0, stationary = 0, stolen = 0, mispaired = 0, worst = 0;
  const offs = [], byKey = new Map();
  for (let n = 0; n < TICKS; n++) {
    if (!race.tick()) break;
    const fr = frames.length === 1 ? keptFrame(frames[0]) : null;
    frames.length = 0;
    if (!fr) { prev = null; continue; }
    if (prev) {
      passes++;
      const ctx = Object.assign(Object.create(GLRenderer.prototype), { stats: { paired: 0, unpaired: 0, followed: 0, followSnapped: 0, held: 0 } });
      GLRenderer.prototype.pair.call(ctx, prev, fr);
      const olds = [...prev.draws.values()];
      for (const d of fr.draws.values()) {
        if (d.hud || d.partner) continue;
        unpairedAll++;
        if (!d.camFrom) newerCam++;
        if (d.hold) { unpairedWhy.hold = (unpairedWhy.hold || 0) + 1; continue; }
        // the same object in the pass before under another key (another texture, mesh size: a level of detail)?
        const near = olds.find((e) => same(e.world, d.world) && Math.hypot(e.vx - d.vx, e.vy - d.vy, e.vz - d.vz) < 1);
        const why = d.follow ? 'follow' : near ? 'same place, other key (' + near.key + ' -> ' + d.key + ')' : olds.some((e) => e.key === d.key) ? 'key there, all taken' : 'new key';
        unpairedWhy[why] = (unpairedWhy[why] || 0) + 1;
      }
      for (const d of fr.draws.values()) {
        if (d.hud || d.follow || d.hold) continue;
        const twin = olds.find((e) => e.key === d.key && same(e.world, d.world) && Math.abs(e.vx - d.vx) + Math.abs(e.vy - d.vy) + Math.abs(e.vz - d.vz) < 1e-3);
        if (!twin) continue;
        stationary++;
        if (d.partner === twin) continue;
        const e = d.partner;
        if (!e) { stolen++; continue; }
        if (Math.hypot(e.world[12] - d.world[12], e.world[13] - d.world[13], e.world[14] - d.world[14]) > 30) continue;   // shown at the newer pass
        // the largest gap between the two meshes' vertices (in world units, with their world translations): blended
        // (vertexBlend) the mesh is shown halfway between them
        let gap = 0;
        for (let i = 0; i < d.nverts; i++) {
          const a = (e.base + i) * 8, b = (d.base + i) * 8;
          gap = Math.max(gap, Math.hypot(prev.vx[a] + e.world[12] - fr.vx[b] - d.world[12], prev.vx[a + 1] + e.world[13] - fr.vx[b + 1] - d.world[13], prev.vx[a + 2] + e.world[14] - fr.vx[b + 2] - d.world[14]));
        }
        const off = (d.vertexBlend ? gap : Math.hypot(e.world[12] - d.world[12], e.world[13] - d.world[13], e.world[14] - d.world[14])) / 2;
        if (off < 0.01) continue;
        mispaired++; offs.push(off); worst = Math.max(worst, off); byKey.set(d.key, (byKey.get(d.key) || 0) + 1);
      }
    }
    prev = fr;
  }
  offs.sort((a, b) => a - b);
  console.log(`etappe ${etappe}: ${passes} pairings, ${stationary} stationary draws; paired with another draw and blended (shown off place): ${mispaired} (median ${(offs[offs.length >> 1] || 0).toFixed(2)}, worst ${worst.toFixed(2)} units at mid-blend); left unpaired: ${stolen}`);
  console.log('  keys most affected:', [...byKey].sort((a, b) => b[1] - a[1]).slice(0, 6).map(([k, n]) => k + ' x' + n).join(', '));
  console.log(`  unpaired draws ${unpairedAll}, of which seen through the newer pass's camera instead of the blended one: ${newerCam}; ${unpairedAll}, ${(unpairedAll / passes).toFixed(2)} a pass:`, Object.entries(unpairedWhy).sort((a, b) => b[1] - a[1]).slice(0, 8).map(([k, n]) => k + ' x' + n).join('; '));
  if (mispaired || newerCam) failed++;
}
if (failed) process.exitCode = 1;
