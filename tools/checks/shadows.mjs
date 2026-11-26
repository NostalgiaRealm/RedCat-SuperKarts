#!/usr/bin/env node
// Kart shadows and engine flares (source/host/shadows.js) in Node, no browser: the real wasm, the real recorder
// through a fake port, a fixed clock, gas held. Per track (default Nederland and Frankrijk) one run with both settings
// on and one with both off, then:
//   a  the shadow callback 0x6802c4 is 0x4260c0, wrapped as 'KartShadow', and the wrapper ran
//   b  every shadow draw's commands: on TRANSFORM(identity) TAG(FOLLOW|DECAL, k+1) DRAWIDX(81 vertices, 384 indices)
//      TRANSFORM(the shadow's world); off TAG(FOLLOW, k+1) and the original 4/6 draw
//   c  the grid's corner points 0, 8, 80, 72 are the drawn body's box corners (bodyMesh, QUAD_BOX) through the quad's
//      world matrix (X/Z, 1e-3)
//   i  the footprints: every grid spans the box of the body the game draws, bit for bit the JS reconstruction's
//      kart03.d3d quad (its getNativeKartShadowSpec, from its manifest, read-only), and the quad the game itself draws,
//      on and off, is 0x4260c0's from 0x490ce0's mesh, redcar.d3d's (the original footprint, untouched)
//   d  Frankrijk's start: the original quad's Y is 0, and every point of the first pass's grids lies on a face the
//      triangle search found (none on the fallback plane), the lowest more than 5 units above the quad
//   e  the game is untouched: game memory from 0x400000 up and race.ini are the same with the settings on and off
//   f  every flare draw is tagged: on FOLLOW owner+1; off HOLD for the racers (slots with a shadow), FOLLOW for others
//   g  the renderer's own drawInfo/pair (gl-renderer.js) on the frames: every follower paired within its owner's, none
//      cut loose while its owner moved 30 units or less; and how far each flare shown at mid-blend is from its place on
//      the kart as the renderer shows the kart (blended, or with its newer rotation when it turned more than 20 degrees
//      a pass, from the kart's own matrices), now and with the old 10-unit vertex rule: now at most 2 units off in 99%
//      (the pool moves flares when a turbo adds one, and which is which is then a guess)
//   h  free flight (host.flightActive): the player's shadow draw is left out, the callback still runs
// Results in evidence/checks/shadows.txt.  node tools/checks/shadows.mjs [--ticks 2000] [--etappes 0,3]
import { readFileSync, readdirSync, statSync, writeFileSync, mkdirSync } from 'node:fs';
import { createHash } from 'node:crypto';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { Vfs } from '../../source/host/vfs.js';
import { Race } from '../../source/host/race.js';
import { writeHandoff } from '../../source/host/race-handoff.js';
import { createRecorder, CMD, CMD_SIZE, TAG } from '../../source/render/recorder.js';
import { GLRenderer } from '../../source/render/gl-renderer.js';
import { ADDR, QUAD_BOX, bodyMesh } from '../../source/host/shadows.js';
import { OPT } from '../../source/web/shared.js';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (n, d) => { const k = process.argv.indexOf('--' + n); return k < 0 ? d : process.argv[k + 1]; };
const TICKS = Number(opt('ticks', 2000));
const ETAPPES = String(opt('etappes', '0,3')).split(',').map(Number);
const dataDir = process.env.SUPERKARTS_DATA || join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c', 'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
const gameDir = join(ROOT, 'public/game');
const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
const wasm = new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm')));
const NAMES = ['Nederland', 'Duitsland', 'Engeland', 'Frankrijk', 'Spanje', 'Italie'];
// the JS reconstruction's shadow quads (kart-shadow.js:7-17 getNativeKartShadowSpec over its manifest's mesh bounds)
const JS_ROOT = process.env.SUPERKARTS_JS || join(ROOT, '..', 'RedCat Superkarts');
const jsManifest = JSON.parse(readFileSync(join(JS_ROOT, 'public', 'assets', 'manifest.json'), 'utf8'));
const jsQuad = (name) => { const b = jsManifest.meshes[name].bounds; return [[b.maxX, b.maxZ], [b.minX, b.maxZ], [b.minX, b.minZ], [b.maxX, b.minZ]].map((c) => c.map(Math.fround)); };
const JS_KART03 = jsQuad('kart03.d3d'), JS_REDCAR = jsQuad('redcar.d3d');
const lines = [];
const say = (s) => { console.log(s); lines.push(s); };
const fails = [];
const check = (ok, what) => { if (!ok) fails.push(what); say((ok ? 'ok   ' : 'FAIL ') + what); };

async function run(etappe, on, { flightAt = -1 } = {}) {
  const vfs = new Vfs();
  for (const name of readdirSync(dataDir)) { const p = join(dataDir, name); if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p))); }
  writeHandoff(vfs, { country: etappe, character: 0, raceType: 0 });
  const frames = [];
  const port = { postMessage(d) { if (d.buf) frames.push(d); } };
  const render = createRecorder(port, null, {});
  const keys = new Set();
  const input = { mouseX: 320, mouseY: 240, mouseButtons: 0, keyDown: (vk) => keys.has(vk), takeMouseDelta: () => null, setMouse() {} };
  const host = { vfs, render, input, audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025, clockStart: 1,
    fixedDate: Date.UTC(2000, 3, 17, 12), onFlip() {}, onMessageBox: (c, t) => say('MessageBox: ' + c + ' ' + t), onStdout() {}, log: (s) => say('[log] ' + s),
    options: on ? OPT.SURFACE_SHADOWS | OPT.SMOOTH_ENGINE_LIGHTS | OPT.CHEATS : OPT.CHEATS };
  const race = new Race(meta, host);
  await race.instantiate(wasm, codeMap);
  render.attach(race.m, host);
  const m = race.m;
  // what each recorded draw is (for f and g): a flare's pool address and owner, a shadow's slot; and per shadow draw the
  // original quad's corners and world matrix as the tagger got them (c)
  let seq = [];
  const shadows = [];
  const tagger = render.tagger;
  let lastTag = null, lastArgs = null;
  render.tagger = (prim, vtype, verts, nverts, indices, nindices, world) => {
    const quad = prim === 4 && vtype === 2 && nverts === 4 && nindices === 6 ? { f: m.f32.slice(verts >> 2, (verts >> 2) + 32), W: world.slice() } : null;
    const t = tagger(prim, vtype, verts, nverts, indices, nindices, world);
    if (quad && t && t.id) {
      // the body's box corners in the quad's order, read here as the tagger reads them
      const mesh = bodyMesh(m, m.u32[ADDR.KARTS >> 2] + (t.id - 1) * 0xd0), box = m.u32[ADDR.MESHES >> 2] + mesh * 0xbc;
      quad.mesh = mesh;
      quad.box = QUAD_BOX.map((o) => [m.view.getFloat32(box + o, true), m.view.getFloat32(box + o + 8, true)]);
    }
    lastTag = t ? { ...t } : null; lastArgs = { prim, verts, quad };
    return t;
  };
  for (const name of ['drawPrimitive', 'drawIndexed']) {
    const orig = render[name];
    render[name] = (...a) => {
      lastTag = null; lastArgs = null;
      const before = render.stats.draws, dropped = render.stats.dropped;
      orig(...a);
      if (render.stats.dropped > dropped) seq.dropped = (seq.dropped || 0) + 1;
      if (render.stats.draws === before) return;
      const t = lastTag;
      const id = { tag: t, verts: a[2] };
      if (t && lastArgs.quad) { id.shadow = t.id - 1; if (t.verts) id.grid = { at: t.verts, quad: lastArgs.quad, f: m.f32.slice(t.verts >> 2, (t.verts >> 2) + 81 * 8) }; else id.quad = lastArgs.quad; }
      // a flare, found from the pool here, not from the tagger (f checks that the tagger saw every one)
      if (name === 'drawPrimitive' && a[0] === 5) {
        const mg = m.u32[0x00545100 >> 2], data = mg && m.u32[(m.u32[(mg + 4) >> 2] + 4) >> 2], off = a[2] - data;
        if (mg && off >= 0 && off % 0x17c === 0 && off / 0x17c < 64) {
          const owner = m.i32[(a[2] + 0x138) >> 2];
          const obj = m.u32[ADDR.OBJECTS >> 2] + m.i32[(m.u32[ADDR.KARTS >> 2] + owner * 0xd0 + 0xc) >> 2] * 0xa9;
          id.flare = { owner, verts: a[2], R: [0, 1, 2, 4, 5, 6, 8, 9, 10].map((j) => m.view.getFloat32(obj + 0x10 + j * 4, true)) };
        }
      }
      seq.push(id);
    };
  }
  race.boot();
  const callbackPtr = m.u32[0x006802c4 >> 2];
  frames.length = 0;
  keys.add(0x26);
  const passes = [];
  let flightDrops = 0, flightCalls = 0, firstKinds = null;
  for (let n = 0; n < TICKS; n++) {
    host.flightActive = flightAt >= 0 && n >= flightAt && n < flightAt + 100;
    const calls0 = host.shadowStats.callbacks, grids0 = host.shadowStats.grids, kinds0 = { ...host.shadowStats.kinds };
    seq = [];
    if (!race.tick()) break;
    // the faces the first pass with grids found under their points (d)
    if (!firstKinds && host.shadowStats.grids > grids0) firstKinds = Object.fromEntries(Object.entries(host.shadowStats.kinds).map(([k, v]) => [k, v - (kinds0[k] || 0)]));
    if (host.flightActive) { flightDrops += seq.dropped || 0; flightCalls += host.shadowStats.callbacks - calls0; }
    passes.push({ frames: frames.splice(0), seq });
  }
  const mem = createHash('sha1').update(new Uint8Array(m.mem.buffer, 0x400000)).digest('hex');
  const karts = [];
  for (let s = 0; s < m.i32[ADDR.KART_COUNT >> 2]; s++) {
    const k = m.u32[ADDR.KARTS >> 2] + s * 0xd0;
    if (m.i32[(k + 0x28) >> 2] === -1) continue;
    const o = m.u32[ADDR.OBJECTS >> 2] + m.i32[(k + 0xc) >> 2] * 0xa9;
    karts.push([s, m.view.getFloat32(o + 0x40, true), m.view.getFloat32(o + 0x44, true), m.view.getFloat32(o + 0x48, true)]);
  }
  return { race, m, host, render, passes, callbackPtr, mem, karts, raceIni: new TextDecoder('latin1').decode(vfs.read('race.ini') || new Uint8Array()), flightDrops, flightCalls, firstKinds };
}

/** One frame through the renderer's replay bookkeeping (gl-renderer.js replay + drawInfo), without GL. */
function keptFrame(d, seq) {
  const c = new Float64Array(d.buf, 0, d.nc);
  let flat = false, flips = 0;
  for (let k = 0; k < d.nc; k += CMD_SIZE[c[k]] || 1) {
    if (c[k] === CMD.IMAGE || c[k] === CMD.FILL || c[k] === CMD.PRESENT) flat = true;
    if (c[k] === CMD.FLIP) flips++;
  }
  if (flat || flips !== 1) return null;
  const ctx = Object.assign(Object.create(GLRenderer.prototype), { world: new Float32Array(16), view: new Float32Array(16), proj: new Float32Array(16), stats: {} });
  const frame = { c, draws: new Map(), vx: new Float32Array(d.buf, d.nc * 8, d.nv * 8), cmds: [] };
  let tag = null, n = 0;
  for (let k = 0; k < d.nc;) {
    const op = c[k];
    frame.cmds.push(k);
    if (op === CMD.TRANSFORM) { const dst = c[k + 1] === 1 ? ctx.world : c[k + 1] === 2 ? ctx.view : ctx.proj; for (let j = 0; j < 16; j++) dst[j] = c[k + 2 + j]; }
    if (op === CMD.TAG) tag = k;
    if (op === CMD.DRAW || op === CMD.DRAWIDX) {
      const ix = op === CMD.DRAWIDX;
      const info = GLRenderer.prototype.drawInfo.call(ctx, frame, c[k + 1], c[k + 2], c[k + 4], c[k + 5], ix ? c[k + 6] : c[k + 3], ix ? c[k + 7] : c[k + 4], (ix ? c[k + 8] : c[k + 6]) & 1, (ix ? c[k + 8] : c[k + 6]) & 2, tag === null ? null : c, tag);
      info.id = seq[n++];
      info.k = k;
      frame.draws.set(k, info);
      tag = null;
    }
    if (op === CMD.FLIP) tag = null;
    k += CMD_SIZE[op] || 1;
  }
  frame.count = n;
  return frame;
}

const kartPlace = (m, slot) => { const k = m.u32[ADDR.KARTS >> 2] + slot * 0xd0; const o = m.u32[ADDR.OBJECTS >> 2] + m.i32[(k + 0xc) >> 2] * 0xa9; return [m.view.getFloat32(o + 0x40, true), m.view.getFloat32(o + 0x44, true), m.view.getFloat32(o + 0x48, true)]; };

for (const etappe of ETAPPES) {
  say(`\n== ${NAMES[etappe]} (etappe ${etappe}), ${TICKS} passes, gas held, fixed clock`);
  const t0 = Date.now();
  const on = await run(etappe, true, { flightAt: 600 });
  const off = await run(etappe, false);
  say(`runs: ${((Date.now() - t0) / 1000).toFixed(1)} s`);
  // a
  check(on.callbackPtr === ADDR.KART_SHADOW && meta.hooks.KartShadow.kind === 'wrap', `a  0x6802c4 = 0x${on.callbackPtr.toString(16)}, KartShadow is a wrap hook`);
  check(on.host.shadowStats.callbacks > 0 && off.host.shadowStats.callbacks === on.host.shadowStats.callbacks, `a  the wrapper ran ${on.host.shadowStats.callbacks} times on, ${off.host.shadowStats.callbacks} off (${(on.host.shadowStats.callbacks / on.passes.length).toFixed(2)} a pass)`);
  // b, c, d
  let seqOk = 0, seqBad = 0, offOk = 0, offBad = 0, cornerMax = 0, grids = 0;
  let boxJs = 0, boxOther = 0, quadOrig = 0, quadOther = 0;
  const meshes = new Set(), same = (q, ref) => ref.every((c, k) => c[0] === q[k][0] && c[1] === q[k][1]);
  const firstGridY = [];
  for (const [run_, isOn] of [[on, true], [off, false]]) {
    for (const P of run_.passes) {
      for (const d of P.frames) {
        const c = new Float64Array(d.buf, 0, d.nc);
        const ks = [];
        for (let k = 0; k < d.nc; k += CMD_SIZE[c[k]] || 1) ks.push(k);
        for (let q = 0; q < ks.length; q++) {
          const k = ks[q];
          if (c[k] !== CMD.TAG || c[k + 1] < 1) continue;
          const flags = c[k + 2], draw = ks[q + 1];
          if (c[draw] !== CMD.DRAWIDX) continue;            // (a flare's: DRAW)
          // a kart's body, wheels and driver are tagged FOLLOW too (the parts, shadows.js part()): neither the grid
          // (DECAL) nor the original 4/6 quad
          if (!(flags & TAG.DECAL) && !(c[draw + 7] === 4 && c[draw + 4] === 6)) continue;
          if (isOn) {
            const pre = ks[q - 1], post = ks[q + 2];
            const ident = c[pre] === CMD.TRANSFORM && c[pre + 1] === 1 && [...Array(16)].every((_, j) => c[pre + 2 + j] === (j % 5 === 0 ? 1 : 0));
            const good = ident && flags === (TAG.FOLLOW | TAG.DECAL) && c[draw + 7] === 81 && c[draw + 4] === 384 && c[post] === CMD.TRANSFORM && c[post + 1] === 1;
            if (good) seqOk++; else seqBad++;
          } else {
            if (flags === TAG.FOLLOW && c[draw + 7] === 4 && c[draw + 4] === 6) offOk++; else offBad++;
          }
        }
      }
      for (const id of P.seq) {
        const q = id.grid ? id.grid.quad : id.quad;
        if (!q) continue;
        if (same([0, 1, 2, 3].map((c) => [q.f[c * 8], q.f[c * 8 + 2]]), JS_REDCAR)) quadOrig++; else quadOther++;
      }
      if (!isOn) continue;
      for (const id of P.seq) {
        if (!id.grid) continue;
        grids++;
        const { quad, f } = id.grid, W = quad.W;
        meshes.add(quad.mesh);
        if (same(quad.box, JS_KART03)) boxJs++; else boxOther++;
        for (const [corner, pt] of [[0, 0], [1, 8], [2, 80], [3, 72]]) {
          const lx = quad.box[corner][0], ly = quad.f[corner * 8 + 1], lz = quad.box[corner][1];
          const x = lx * W[0] + ly * W[4] + lz * W[8] + W[12], z = lx * W[2] + ly * W[6] + lz * W[10] + W[14];
          cornerMax = Math.max(cornerMax, Math.abs(x - f[pt * 8]), Math.abs(z - f[pt * 8 + 2]));
        }
        if (firstGridY.length < 5) {
          let lo = Infinity, hi = -Infinity;
          for (let p = 0; p < 81; p++) { lo = Math.min(lo, f[p * 8 + 1]); hi = Math.max(hi, f[p * 8 + 1]); }
          firstGridY.push({ slot: id.shadow, quadY: W[13], lo, hi });
        }
      }
    }
  }
  check(seqBad === 0 && seqOk > 0, `b  on: ${seqOk} shadow draws as TRANSFORM(identity) TAG(FOLLOW|DECAL) DRAWIDX(81, 384) TRANSFORM(world), ${seqBad} otherwise`);
  check(offBad === 0 && offOk > 0, `b  off: ${offOk} shadow draws as TAG(FOLLOW) and the original 4/6 draw, ${offBad} otherwise`);
  check(cornerMax < 1e-3, `c  grid corners 0, 8, 80, 72 against the body box's corners through the quad's world matrix: largest X/Z difference ${cornerMax.toExponential(2)} over ${grids} grids`);
  const span = (q) => `${(q[0][0] - q[1][0]).toFixed(1)} x ${(q[0][1] - q[2][1]).toFixed(1)}`;
  check(boxJs === grids && grids > 0 && boxOther === 0, `i  ${boxJs} of ${grids} grids span the drawn body's box, the JS reconstruction's kart03.d3d quad bit for bit (${span(JS_KART03)}; body meshes ${[...meshes].join(', ')})`);
  check(quadOrig > 0 && quadOther === 0, `i  ${quadOrig} quads the game drew (on and off) are 0x4260c0's from 0x490ce0's redcar.d3d (${span(JS_REDCAR)}), ${quadOther} otherwise`);
  say('   first grids (slot, original quad Y, grid Y min..max): ' + firstGridY.map((g) => `${g.slot} ${g.quadY.toFixed(2)} ${g.lo.toFixed(2)}..${g.hi.toFixed(2)}`).join(' | '));
  if (etappe === 3) check(firstGridY.every((g) => g.quadY === 0 && g.lo > 5) && on.firstKinds && !on.firstKinds['-1'], `d  Frankrijk start: the original quads lie at Y 0, the first pass's grid points on faces the search found (${JSON.stringify(on.firstKinds)}; -1 the fallback plane), the lowest at Y ${Math.min(...firstGridY.map((g) => g.lo)).toFixed(2)}`);
  const ss = on.host.shadowStats;
  say(`   grid: ${ss.grids} grids, ${(ss.ms / ss.grids).toFixed(3)} ms each, ${(ss.ms / on.passes.length).toFixed(3)} ms a pass (Node); faces found ${JSON.stringify(ss.kinds)}`);
  // e
  check(on.mem === off.mem, `e  game memory from 0x400000 up after ${on.passes.length} passes: ${on.mem.slice(0, 12)} on, ${off.mem.slice(0, 12)} off`);
  check(on.raceIni === off.raceIni && JSON.stringify(on.karts) === JSON.stringify(off.karts), `e  race.ini and the racers' places the same on and off: ${on.karts.map((k) => k[0] + ' ' + k.slice(1).map((v) => v.toFixed(1)).join(',')).join(' | ')}`);
  // f
  let flaresOn = 0, flareTagOn = 0, flaresOff = 0, holdOff = 0, followOff = 0, badOff = 0;
  const owners = new Set();
  for (const [run_, isOn] of [[on, true], [off, false]]) {
    for (const P of run_.passes) {
      for (const id of P.seq) {
        if (!id.flare) continue;
        const racer = run_.m.i32[(run_.m.u32[ADDR.KARTS >> 2] + id.flare.owner * 0xd0 + 0x28) >> 2] !== -1;
        const flags = id.tag ? id.tag.flags : 0, tagId = id.tag ? id.tag.id : 0;
        if (isOn) { flaresOn++; owners.add(id.flare.owner); if (flags === TAG.FOLLOW && tagId === id.flare.owner + 1) flareTagOn++; }
        else { flaresOff++; if (racer && flags === TAG.HOLD) holdOff++; else if (!racer && flags === TAG.FOLLOW) followOff++; else badOff++; }
      }
    }
  }
  check(flaresOn > 0 && flareTagOn === flaresOn, `f  on: ${flareTagOn} of ${flaresOn} flare draws tagged FOLLOW with their owner (owners ${[...owners].join(', ')})`);
  check(flaresOff > 0 && badOff === 0, `f  off: ${holdOff} racer flares HOLD, ${followOff} other flares FOLLOW, ${badOff} otherwise`);
  // g
  for (const [run_, label] of [[on, 'on'], [off, 'off']]) {
    let prev = null, foreign = 0, moved = 0, flarePairs = 0, followed = 0, snapped = 0, snappedNear = 0, held = 0, shadowPairs = 0, spins = 0;
    const errNow = [], errOld = [];
    const SPIN_COS = Math.cos(20 * Math.PI / 180);
    const turnCos = (a, b) => { let tr = 0; for (let r = 0; r < 9; r += 3) { const la = Math.hypot(a[r], a[r + 1], a[r + 2]), lb = Math.hypot(b[r], b[r + 1], b[r + 2]); if (!la || !lb) return 1; tr += (a[r] * b[r] + a[r + 1] * b[r + 1] + a[r + 2] * b[r + 2]) / (la * lb); } return (tr - 1) / 2; };
    for (const P of run_.passes) {
      const fr = P.frames.length === 1 ? keptFrame(P.frames[0], P.seq) : null;
      if (!fr || fr.count !== P.seq.length) { prev = null; continue; }
      if (prev) {
        const ctx = Object.assign(Object.create(GLRenderer.prototype), { stats: { paired: 0, unpaired: 0, followed: 0, followSnapped: 0, held: 0 } });
        GLRenderer.prototype.pair.call(ctx, prev, fr);
        held += ctx.stats.held;
        for (const d of fr.draws.values()) {
          if (!d.partner) continue;
          const e = d.partner;
          if (d.follow) { followed++; if (!d.vertexBlend) { snapped++; if (Math.hypot(d.ox - e.ox, d.oy - e.oy, d.oz - e.oz) <= 30) snappedNear++; } }
          if (d.id && d.id.shadow !== undefined) { shadowPairs++; if (!e.id || e.id.shadow !== d.id.shadow) foreign++; }
          if (!d.id || !d.id.flare) continue;
          flarePairs++;
          if (!e.id || !e.id.flare || e.id.flare.owner !== d.id.flare.owner) { foreign++; continue; }
          if (e.id.flare.verts !== d.id.flare.verts) moved++;
          if (!d.follow || Math.hypot(d.ox - e.ox, d.oy - e.oy, d.oz - e.oz) > 30) continue;
          // at mid-blend: the kart as blendMatrix shows it, and the flare's place on it
          const t = 0.5, lerp = (a, b) => a + (b - a) * t;
          const vOld = [e.vx, e.vy, e.vz], vNew = [d.vx, d.vy, d.vz], oOld = [e.ox, e.oy, e.oz], oNew = [d.ox, d.oy, d.oz];
          const kartMid = oNew.map((v, j) => lerp(oOld[j], v));
          const spun = turnCos(e.id.flare.R, d.id.flare.R) < SPIN_COS;
          if (spun) spins++;
          const want = spun ? vNew.map((v, j) => v + kartMid[j] - oNew[j]) : vNew.map((v, j) => lerp(vOld[j], v));
          const shown = d.vertexBlend ? vNew.map((v, j) => lerp(vOld[j], v)) : vNew;
          const old = Math.hypot(e.vx - d.vx, e.vy - d.vy, e.vz - d.vz) < 10 ? vNew.map((v, j) => lerp(vOld[j], v)) : vNew;
          errNow.push(Math.hypot(...shown.map((v, j) => v - want[j]))); errOld.push(Math.hypot(...old.map((v, j) => v - want[j])));
        }
      }
      prev = fr;
    }
    const mean = (a) => a.length ? (a.reduce((s, v) => s + v, 0) / a.length).toFixed(2) : '-';
    const max = (a) => a.length ? Math.max(...a).toFixed(2) : '-';
    const over = (a, x) => a.filter((v) => v > x).length;
    if (label === 'on') {
      check(foreign === 0 && flarePairs > 0, `g  on: ${flarePairs} flare and ${shadowPairs} shadow pairings, ${foreign} with another owner's (${moved} flares moved in the pool between the two passes)`);
      check(snappedNear === 0, `g  on: ${followed} tagged draws paired with their owner's, ${snapped} cut loose, ${snappedNear} of them while the owner moved <= 30`);
      check(errNow.length > 0 && over(errNow, 2) <= errNow.length * 0.01, `g  on: flare off its place on the kart shown at mid-blend: ${mean(errNow)} mean, ${max(errNow)} max, ${over(errNow, 2)} of ${errNow.length} over 2 units; kart turns over 20 degrees ${spins} (the old 10-unit vertex rule: ${mean(errOld)} mean, ${max(errOld)} max, ${over(errOld, 2)} over 2)`);
    } else {
      check(held > 0, `g  off: ${held} racer flares held at the newer pass, ${flarePairs} other flares paired`);
    }
  }
  // h
  check(on.flightDrops > 0 && on.flightDrops <= on.flightCalls, `h  free flight (passes 600..699): ${on.flightDrops} player shadow draws left out, ${on.flightCalls} callbacks ran`);
}
say(fails.length ? `\n${fails.length} FAILED: ${fails.join('; ')}` : '\nall passed');
mkdirSync(join(ROOT, 'evidence', 'checks'), { recursive: true });
writeFileSync(join(ROOT, 'evidence', 'checks', 'shadows.txt'), `# node tools/checks/shadows.mjs --ticks ${TICKS} --etappes ${ETAPPES.join(',')}  (${new Date().toISOString()})\n` + lines.join('\n') + '\n');
process.exit(fails.length ? 1 : 0);
