#!/usr/bin/env node
// Does rcskspel.dat cull anything by the screen's aspect or horizontal field of view? An empirical check for Hor+
// (A2 Racer 4's scheme: the clip volume widened to x in [-xr, xr], xr = 0.75 * aspect, y kept at +-0.75).
//
// Runs races headless (same host as tools/run-headless.mjs, via full-race-gaps-lib.mjs), and on chosen ticks
// records every Direct3D draw of the frame with its world/view/projection and its vertices as they were when it
// was issued. Each draw's triangles are transformed with the game's own matrices, clipped to 0 <= z <= w, and
// tested against three screen rectangles of the game's clip volume: 4:3 (|x| <= 1), 16:9 (|x| <= 4/3) and
// 21:9 (|x| <= 7/4), all |y| <= 0.75. If the game culled per object by its 4:3 frustum, no mesh draw would lie
// wholly outside |x| <= 1.
//
// It also rasterises the frame on a grid of the 21:9 clip rectangle to see what a wider view would show:
//   drawn    nearest depth of the frame's world draws (track window, objects, effects; not sky, flag, HUD)
//   sky      cells the sky draw covers
//   excluded nearest depth of the track triangles of chunks OUTSIDE the drawn chunk window (the same .rmp
//            buffers, the index ranges 0x497270 did not draw), split into chunks within 10 of the camera chunk
//            (near: the window's 2-chunk margin side) and the rest (far: later/earlier parts of the lap): where
//            these are in front of `drawn`, the track is missing at that cell and appears once the window moves
//   objects  tracked objects outside the chunk window whose origin projects on screen (0x4918f0's filter)
// and, with the finish flag forced on (INJECTED u32[0x50bc28] = 1, the flag's own on-switch, 0x423230), the
// flag sheet's coverage and reach.
//
//   node tools/checks/wide-cull.mjs [--etappes 0,1,2,3,4,5] [--ticks 60,140,400,...] [--out evidence/checks/wide-cull]
//
// Guest addresses (rcskspel.dat; Ghidra export ../RedCat Superkarts/original-source/modules/rcskspel.dat):
//   track object 0x680218 (ecx of 0x4971f0 at 0x430120): pass vertex ptr / index ptr / vertex count at
//     road +0x6a/+0x6e/+0x72, land +0x7a/+0x7e/+0x82, extra +0x5a/+0x5e/+0x62, rail +0x8a/+0x8e/+0x92 (0x497270)
//   chunk records u32[0x680b28] stride 0x984: index start/end road +0/+4, land +8/+0xc, extra +0x10/+0x14,
//     rail +0x18/+0x1c (0x497270); chunk count i32[0x680b2c] (0x497ab0); visible chunks N i32[0x53b9d0]
//   window start: 0x4304d0(2) (called at 0x430118 and 0x4301b8), split by 0x497ab0
//   objects u32[0x67ee20] stride 0xd0, count i32[0x67ee24], used bytes u32[0x67ee30]; +0x44 on, +0x3c visible,
//     +0x1c chunk, +0x0c render object (0x4916f0/0x4918f0); render objects u32[0x6a5c38] stride 0xa9, pos +0x50
//   sky: object index u32[0x50914c], scale (10, 4, 10) (0x422d50), drawn by 0x423010 -> 0x4a0d80
//   flag: 10 strips of 34 D3DLVERTEX at 0x5091a0..0x50bc20 (0x4235c0, DrawPrimitive at 0x4237db), on u32[0x50bc28],
//     option u32[0x53ba28]; sine table ptr u32[0x6a5c88] (0x423280)
//   software-transform switch u32[0x6a5f28] (0x4a7e10: 0 -> 0x4a96b0, else 0x4a9900 with screen culling)
//   hardware 3D u32[0x53b9f0] (0x42d1d0), projection 0x6a615c (0x42d7d0 builds it with 0x4a1a40)
import { readFileSync, writeFileSync, mkdirSync } from 'node:fs';
import { join, resolve } from 'node:path';
import { makeRace, VK, ROOT } from './full-race-gaps-lib.mjs';

const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const ETAPPES = String(opt('etappes', '0,1,2,3,4,5')).split(',').map(Number);
const TICKS = opt('ticks', null) ? String(opt('ticks')).split(',').map(Number)
  : [...[40, 80, 120, 160, 200, 300], ...Array.from({ length: 112 }, (_, k) => 400 + k * 50)];
// camera keys (0x41d920, racing only): '1' camera 1, '2' camera 3, '3' toggles camera 5, '4' camera 0
const CAMERA_KEYS = new Map([[2000, 0x31], [3000, 0x32], [4000, 0x33], [4500, 0x33], [5000, 0x34]]);
const OUT = resolve(ROOT, opt('out', 'evidence/checks/wide-cull'));
const FLAG_FRAMES = Number(opt('flag-frames', 40));

// --- function ranges, to name a draw by its call site -------------------------------------------------------
const EXPORT = join(ROOT, '..', 'RedCat Superkarts', 'original-source', 'modules', 'rcskspel.dat');
const fnRanges = [];
for (const line of readFileSync(join(EXPORT, 'functions.tsv'), 'utf8').split('\n').slice(1)) {
  const p = line.split('\t');
  if (p.length < 5) continue;
  for (const r of p[4].split(/[;,]/)) {
    const [a, b] = r.split('-').map((h) => parseInt(h, 16));
    if (a && b) fnRanges.push([a, b, parseInt(p[0], 16)]);
  }
}
fnRanges.sort((x, y) => x[0] - y[0]);
const fnOf = (addr) => {
  let lo = 0, hi = fnRanges.length - 1, best = null;
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    if (fnRanges[mid][0] <= addr) { best = fnRanges[mid]; lo = mid + 1; } else hi = mid - 1;
  }
  return best && addr <= best[1] ? best[2] : 0;
};
const hex = (v) => '0x' + (v >>> 0).toString(16);

// --- geometry -----------------------------------------------------------------------------------------------
const RECTS = { '4:3': 1, '16:9': 4 / 3, '21:9': 7 / 4 };   // xr; yr stays 0.75 (Hor+)
const YR = 0.75;
const mul = (a, b) => {                       // row-major 4x4, row vectors: (v*a)*b = v*(a*b)
  const o = new Float64Array(16);
  for (let r = 0; r < 4; r++) for (let c = 0; c < 4; c++) {
    let s = 0;
    for (let k = 0; k < 4; k++) s += a[r * 4 + k] * b[k * 4 + c];
    o[r * 4 + c] = s;
  }
  return o;
};
const xform = (M, x, y, z) => [
  x * M[0] + y * M[4] + z * M[8] + M[12], x * M[1] + y * M[5] + z * M[9] + M[13],
  x * M[2] + y * M[6] + z * M[10] + M[14], x * M[3] + y * M[7] + z * M[11] + M[15],
];
// clip a polygon of homogeneous points to z >= 0 and z <= w (Direct3D's depth range), then project
function clipNearFar(poly) {
  for (const f of [(p) => p[2], (p) => p[3] - p[2]]) {
    const out = [];
    for (let i = 0; i < poly.length; i++) {
      const a = poly[i], b = poly[(i + 1) % poly.length], da = f(a), db = f(b);
      if (da >= 0) out.push(a);
      if ((da >= 0) !== (db >= 0)) {
        const t = da / (da - db);
        out.push([a[0] + t * (b[0] - a[0]), a[1] + t * (b[1] - a[1]), a[2] + t * (b[2] - a[2]), a[3] + t * (b[3] - a[3])]);
      }
    }
    poly = out;
    if (poly.length < 3) return null;
  }
  return poly.map((p) => [p[0] / p[3], p[1] / p[3], p[3]]);     // NDC x, y and w (view depth times a constant)
}
// does a projected polygon overlap the rectangle |x| <= xr, |y| <= YR? (2D clip, non-empty)
function overlaps(poly, xr) {
  let p = poly;
  for (const [ax, s, lim] of [[0, 1, xr], [0, -1, xr], [1, 1, YR], [1, -1, YR]]) {
    const out = [];
    for (let i = 0; i < p.length; i++) {
      const a = p[i], b = p[(i + 1) % p.length], da = lim - s * a[ax], db = lim - s * b[ax];
      if (da >= 0) out.push(a);
      if ((da >= 0) !== (db >= 0)) {
        const t = da / (da - db);
        out.push([a[0] + t * (b[0] - a[0]), a[1] + t * (b[1] - a[1]), a[2] + t * (b[2] - a[2])]);
      }
    }
    p = out;
    if (p.length < 3) return false;
  }
  let area = 0;
  for (let i = 0; i < p.length; i++) { const a = p[i], b = p[(i + 1) % p.length]; area += a[0] * b[1] - b[0] * a[1]; }
  return Math.abs(area) > 1e-9;
}
// the grid over the 21:9 rectangle; region of a cell by |x|
const CELL = 1 / 48;
const GW = Math.round((2 * RECTS['21:9']) / CELL), GH = Math.round((2 * YR) / CELL);
const cellX = (i) => -RECTS['21:9'] + (i + 0.5) * CELL, cellY = (j) => -YR + (j + 0.5) * CELL;
const regionOf = (x) => (Math.abs(x) <= 1 ? 0 : Math.abs(x) <= RECTS['16:9'] ? 1 : 2);
const REGION = ['4:3', '16:9 band', '21:9 band'];
function raster(layer, poly) {                  // nearest w per cell, fan triangles, perspective-correct 1/w
  for (let k = 1; k + 1 < poly.length; k++) {
    const a = poly[0], b = poly[k], c = poly[k + 1];
    const minx = Math.min(a[0], b[0], c[0]), maxx = Math.max(a[0], b[0], c[0]);
    const miny = Math.min(a[1], b[1], c[1]), maxy = Math.max(a[1], b[1], c[1]);
    const i0 = Math.max(0, Math.floor((minx + RECTS['21:9']) / CELL - 0.5)), i1 = Math.min(GW - 1, Math.ceil((maxx + RECTS['21:9']) / CELL - 0.5));
    const j0 = Math.max(0, Math.floor((miny + YR) / CELL - 0.5)), j1 = Math.min(GH - 1, Math.ceil((maxy + YR) / CELL - 0.5));
    if (i0 > i1 || j0 > j1) continue;
    const det = (b[1] - c[1]) * (a[0] - c[0]) + (c[0] - b[0]) * (a[1] - c[1]);
    if (Math.abs(det) < 1e-14) continue;
    for (let j = j0; j <= j1; j++) {
      const y = cellY(j);
      for (let i = i0; i <= i1; i++) {
        const x = cellX(i);
        const l1 = ((b[1] - c[1]) * (x - c[0]) + (c[0] - b[0]) * (y - c[1])) / det;
        const l2 = ((c[1] - a[1]) * (x - c[0]) + (a[0] - c[0]) * (y - c[1])) / det;
        const l3 = 1 - l1 - l2;
        if (l1 < 0 || l2 < 0 || l3 < 0) continue;
        const w = 1 / (l1 / a[2] + l2 / b[2] + l3 / c[2]);
        const q = j * GW + i;
        if (w < layer[q]) layer[q] = w;
      }
    }
  }
}

// --- one race -------------------------------------------------------------------------------------------------
async function runTrack(etappe) {
  const r = await makeRace({ etappe });
  const { m } = r;
  const dv = m.view;
  const u32 = (a) => dv.getUint32(a, true), i32 = (a) => dv.getInt32(a, true), f32 = (a) => dv.getFloat32(a, true);
  const mat = (p) => { const o = new Float64Array(16); for (let k = 0; k < 16; k++) o[k] = f32(p + k * 4); return o; };
  const xf = { 1: null, 2: null, 3: null };
  let viewport = null;
  let frame = null;                               // draws of the tick being captured
  const flagsBySite = new Map();                  // call-site function -> Set of DrawPrimitive flags
  const wrapThunk = (name, fn) => {
    const id = m.thunkNames.indexOf(name);
    if (id < 0) throw new Error('no thunk ' + name);
    const inner = m.thunks[id];
    m.thunks[id] = (esp, ecx, edx, eax) => { fn(esp); return inner(esp, ecx, edx, eax); };
  };
  const arg = (esp, k) => u32(esp + 4 + k * 4);   // k = 0 is `this`
  wrapThunk('IDirect3DDevice2::SetTransform', (esp) => { const t = arg(esp, 1); if (t >= 1 && t <= 3) xf[t] = mat(arg(esp, 2)); });
  wrapThunk('IDirect3DViewport2::SetViewport2', (esp) => {
    const p = arg(esp, 1);
    viewport = { x: u32(p + 4), y: u32(p + 8), w: u32(p + 12), h: u32(p + 16), clipX: f32(p + 20), clipY: f32(p + 24), clipW: f32(p + 28), clipH: f32(p + 32), minZ: f32(p + 36), maxZ: f32(p + 40) };
  });
  const note = (site, prim, vtype, flags) => {
    const fn = fnOf(site);
    const key = `${hex(fn)} prim ${prim} vtype ${vtype}`;
    if (!flagsBySite.has(key)) flagsBySite.set(key, new Set());
    flagsBySite.get(key).add(flags);
    return fn;
  };
  const readPos = (verts, count) => {
    const p = new Float64Array(count * 3);
    for (let k = 0; k < count; k++) { p[k * 3] = f32(verts + k * 32); p[k * 3 + 1] = f32(verts + k * 32 + 4); p[k * 3 + 2] = f32(verts + k * 32 + 8); }
    return p;
  };
  wrapThunk('IDirect3DDevice2::DrawPrimitive', (esp) => {
    const [prim, vtype, verts, count, flags] = [arg(esp, 1), arg(esp, 2), arg(esp, 3), arg(esp, 4), arg(esp, 5)];
    const fn = note(u32(esp), prim, vtype, flags);
    if (!frame || r.host.render.hud || vtype === 3 || prim < 4) return;
    const tris = [];
    for (let k = 0; k + 2 < count; k += prim === 4 ? 3 : 1) {
      if (prim === 4) tris.push(k, k + 1, k + 2);
      else if (prim === 5) tris.push(k, k + 1, k + 2);
      else tris.push(0, k + 1, k + 2);
    }
    frame.draws.push({ fn, prim, verts, pos: readPos(verts, count), tris, M: mul(mul(xf[1], xf[2]), xf[3]), world: xf[1] });
  });
  wrapThunk('IDirect3DDevice2::DrawIndexedPrimitive', (esp) => {
    const [prim, vtype, verts, nverts, indices, nidx, flags] = [1, 2, 3, 4, 5, 6, 7].map((k) => arg(esp, k));
    const fn = note(u32(esp), prim, vtype, flags);
    if (!frame || r.host.render.hud || vtype === 3) return;
    const idx = [];
    for (let k = 0; k < nidx; k++) idx.push(dv.getUint16(indices + k * 2, true));
    const tris = [];
    for (let k = 0; k + 2 < nidx; k += prim === 4 ? 3 : 1) {
      if (prim === 4 || prim === 5) tris.push(idx[k], idx[k + 1], idx[k + 2]);
      else tris.push(idx[0], idx[k + 1], idx[k + 2]);
    }
    // only the referenced vertices are read
    const used = [...new Set(tris)];
    const pos = new Float64Array(nverts * 3);
    for (const v of used) { pos[v * 3] = f32(verts + v * 32); pos[v * 3 + 1] = f32(verts + v * 32 + 4); pos[v * 3 + 2] = f32(verts + v * 32 + 8); }
    frame.draws.push({ fn, prim, verts, nverts, indices, nidx, pos, tris, M: mul(mul(xf[1], xf[2]), xf[3]), world: xf[1] });
  });

  r.race.boot();
  const boot = {
    hardware3d: u32(0x53b9f0), softwareTransform: u32(0x6a5f28), objectDrawVariant: u32(0x6802b2),
    visibleChunks: i32(0x53b9d0), chunkCount: i32(0x680b2c), finishFlagOption: u32(0x53ba28),
    projection: Array.from(mat(0x6a615c)).map((v) => +v.toFixed(5)), viewport,
    mirrored: i32(0x53a734 + i32(0x53b9b4) * 0x25 * 4),
  };
  const sine = u32(0x6a5c88);
  boot.flagTableMask = u32(0x4fc8f8);
  if (sine) { let lo = Infinity, hi = -Infinity; for (let k = 0; k <= boot.flagTableMask; k++) { const v = f32(sine + k * 4); lo = Math.min(lo, v); hi = Math.max(hi, v); } boot.flagSineTable = { ptr: hex(sine), min: lo, max: hi }; }

  // --- the window and the per-frame analysis -----------------------------------------------------------------
  const TRACK = 0x680218;
  const PASSES = [['road', 0x6a, 0x6e, 0x72, 0], ['land', 0x7a, 0x7e, 0x82, 8], ['extra', 0x5a, 0x5e, 0x62, 0x10], ['rail', 0x8a, 0x8e, 0x92, 0x18]];
  const window = () => {
    const start = m.call(0x4304d0, [2]) | 0;              // pure: reads camera, chunk and N
    const C = i32(0x680b2c), N = i32(0x53b9d0);
    let first = Math.min(Math.max(start, 0), C - 1), end = start + N, wrap = null;
    if (end >= C) { wrap = [0, end - C]; end = C - 1; }
    return { start, N, ranges: wrap ? [[first, end], wrap] : [[first, end]] };
  };
  const inWindow = (c, w) => w.ranges.some(([a, b]) => c >= a && c <= b);

  const results = [];
  // weather triangles by |x| of their centre in the clip volume, bins of 0.125 (|y| <= 0.75), and the extent of
  // their vertices as submitted (world and view are the identity there: camera space)
  const weather = { frames: 0, bins: new Array(16).fill(0), view: [[Infinity, -Infinity], [Infinity, -Infinity], [Infinity, -Infinity]], worldIdentity: true };
  const analyse = (tick, label) => {
    const win = window();
    const chunkRec = u32(0x680b28), C = i32(0x680b2c);
    const drawn = new Float64Array(GW * GH).fill(Infinity);
    const excl = new Float64Array(GW * GH).fill(Infinity);
    const exclNear = new Float64Array(GW * GH).fill(Infinity);   // out-of-window chunks within 10 of the camera's
    const cc = i32(0x508674);                                       // chunk c (0x4304d0), by ring distance
    const sky = new Uint8Array(GW * GH);
    const skyL = new Float64Array(GW * GH).fill(Infinity);
    const bySite = new Map();
    const trackRanges = new Map();               // pass -> drawn index ranges
    let skyDraws = 0;
    for (const d of frame.draws) {
      if (d.fn === 0x483350) {
        weather.frames += 1 / Math.max(1, frame.draws.filter((x) => x.fn === 0x483350).length);
        for (let v = 0; v < d.pos.length / 3; v++) for (let a = 0; a < 3; a++) {
          weather.view[a][0] = Math.min(weather.view[a][0], d.pos[v * 3 + a]); weather.view[a][1] = Math.max(weather.view[a][1], d.pos[v * 3 + a]);
        }
        weather.worldIdentity &&= Array.from(d.world).every((x, k) => x === (k % 5 === 0 ? 1 : 0));
      }
      const W = d.world;
      const isSky = Math.abs(W[0] - 10) < 1e-4 && Math.abs(W[5] - 4) < 1e-4 && Math.abs(W[10] - 10) < 1e-4 && W[1] === 0 && W[2] === 0 && W[4] === 0;
      const isFlag = d.verts >= 0x5091a0 && d.verts < 0x50bc20;
      const isTrack = d.fn === 0x497270;
      if (isTrack) {
        const pass = PASSES.find((p) => u32(TRACK + p[1]) === d.verts);
        const base = u32(TRACK + pass[2]);
        const s = (d.indices - base) / 2;
        if (!trackRanges.has(pass[0])) trackRanges.set(pass[0], []);
        trackRanges.get(pass[0]).push([s, s + d.nidx]);
      }
      if (isSky) skyDraws++;
      const kind = isSky ? 'sky' : isFlag ? 'flag' : isTrack ? 'track 0x497270' : hex(d.fn);
      if (!bySite.has(kind)) bySite.set(kind, { draws: 0, tris: 0, drawIn: { '4:3': 0, '16:9 only': 0, '21:9 only': 0, offscreen: 0 }, triIn: { '4:3': 0, '16:9 only': 0, '21:9 only': 0, offscreen: 0 } });
      const st = bySite.get(kind);
      st.draws++;
      let v43 = false, v169 = false, v219 = false;
      const cache = new Map();
      const P = (v) => { let h = cache.get(v); if (!h) { h = xform(d.M, d.pos[v * 3], d.pos[v * 3 + 1], d.pos[v * 3 + 2]); cache.set(v, h); } return h; };
      for (let t = 0; t < d.tris.length; t += 3) {
        st.tris++;
        const poly = clipNearFar([P(d.tris[t]), P(d.tris[t + 1]), P(d.tris[t + 2])]);
        if (!poly) { st.triIn.offscreen++; continue; }
        const a = overlaps(poly, 1), b = a || overlaps(poly, RECTS['16:9']), c = b || overlaps(poly, RECTS['21:9']);
        st.triIn[a ? '4:3' : b ? '16:9 only' : c ? '21:9 only' : 'offscreen']++;
        v43 ||= a; v169 ||= b; v219 ||= c;
        if (isSky) { raster(skyL, poly); } else if (!isFlag) raster(drawn, poly);
        if (d.fn === 0x483350) {                  // weather (rain/snow, 0x482190 -> 0x483350): camera-relative
          let cx = 0, cy = 0;
          for (const q of poly) { cx += q[0] / poly.length; cy += q[1] / poly.length; }
          if (Math.abs(cy) <= YR && Math.abs(cx) < 2) weather.bins[Math.floor(Math.abs(cx) / 0.125)]++;
        }
      }
      st.drawIn[v43 ? '4:3' : v169 ? '16:9 only' : v219 ? '21:9 only' : 'offscreen']++;
    }
    for (let q = 0; q < sky.length; q++) sky[q] = skyL[q] < Infinity ? 1 : 0;
    // the track triangles the window left out
    const W0 = Float64Array.from([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
    const MV = mul(mul(W0, xf[2]), xf[3]);         // track world is the identity 0x6a5c90 (checked below)
    let exclTris = 0;
    for (const [name, vo, io, no, co] of PASSES) {
      const verts = u32(TRACK + vo), base = u32(TRACK + io);
      if (!verts || !base) continue;
      const drawnR = trackRanges.get(name) || [];
      const isDrawn = (k) => drawnR.some(([a, b]) => k >= a && k < b);
      for (let c = 0; c < C; c++) {
        if (inWindow(c, win)) continue;
        const rec = chunkRec + c * 0x984, s = i32(rec + co), e = i32(rec + co + 4);
        for (let k = s; k + 2 < e; k += 3) {
          if (isDrawn(k)) continue;
          exclTris++;
          const tri = [0, 1, 2].map((j) => { const v = dv.getUint16(base + (k + j) * 2, true); return xform(MV, f32(verts + v * 32), f32(verts + v * 32 + 4), f32(verts + v * 32 + 8)); });
          const poly = clipNearFar(tri);
          if (poly) raster(Math.min(((c - cc) % C + C) % C, ((cc - c) % C + C) % C) <= 10 ? exclNear : excl, poly);
        }
      }
    }
    const cells = [0, 0, 0], popin = [0, 0, 0], popinNear = [0, 0, 0], hole = [0, 0, 0], noSky = [0, 0, 0];
    for (let j = 0; j < GH; j++) for (let i = 0; i < GW; i++) {
      const q = j * GW + i, g = regionOf(cellX(i));
      cells[g]++;
      if (excl[q] < drawn[q]) popin[g]++;
      if (exclNear[q] < drawn[q]) popinNear[g]++;
      if (drawn[q] === Infinity && !sky[q]) hole[g]++;
      if (!sky[q]) noSky[g]++;
    }
    const pct = (a) => a.map((v, g) => +(100 * v / cells[g]).toFixed(2));
    // objects left out by the window whose origin is on screen
    const objs = u32(0x67ee20), nObj = i32(0x67ee24), used = u32(0x67ee30), ro = u32(0x6a5c38);
    const VP = mul(xf[2], xf[3]);
    const objOut = { '4:3': 0, '16:9 band': 0, '21:9 band': 0 }, objOutFront = { '4:3': 0, '16:9 band': 0, '21:9 band': 0 }, objIn = { '4:3': 0, '16:9 band': 0, '21:9 band': 0, offscreen: 0 };
    for (let k = 0; k < nObj; k++) {
      if (!dv.getUint8(used + k)) continue;
      const b = objs + k * 0xd0;
      if (!i32(b + 0x44) || !i32(b + 0x3c)) continue;
      const o = ro + i32(b + 0xc) * 0xa9;
      const h = xform(VP, f32(o + 0x50), f32(o + 0x54), f32(o + 0x58));
      const onScreen = h[2] >= 0 && h[2] <= h[3] && h[3] > 0 && Math.abs(h[1] / h[3]) <= YR;
      const x = Math.abs(h[0] / h[3]);
      const reg = !onScreen || x > RECTS['21:9'] ? null : x <= 1 ? '4:3' : x <= RECTS['16:9'] ? '16:9 band' : '21:9 band';
      if (inWindow(i32(b + 0x1c), win)) objIn[reg || 'offscreen']++;
      else if (reg) {
        objOut[reg]++;
        // origin nearer than what the frame drew at that cell: the object would be in view, not behind terrain
        const i = Math.min(GW - 1, Math.max(0, Math.floor((h[0] / h[3] + RECTS['21:9']) / CELL)));
        const j = Math.min(GH - 1, Math.max(0, Math.floor((h[1] / h[3] + YR) / CELL)));
        if (h[3] < drawn[j * GW + i]) objOutFront[reg]++;
      }
    }
    results.push({
      etappe, tick, label, phase: u32(0x53b9c0), window: { start: win.start, N: win.N, ranges: win.ranges, roadDrawnIndexRanges: trackRanges.get('road') },
      trackWorldIdentity: Array.from(mat(0x6a5c90)).every((v, k) => v === (k % 5 === 0 ? 1 : 0)),
      skyDraws, excludedTrackTris: exclTris,
      draws: Object.fromEntries(bySite),
      grid: { cells, popinPct: pct(popin), popinNearPct: pct(popinNear), holePct: pct(hole), noSkyPct: pct(noSky) },
      objectsInWindowOrigin: objIn, objectsOutsideWindowOriginOnScreen: objOut, objectsOutsideWindowOriginInFront: objOutFront,
      camera: i32(0x4e3064),               // camera mode (0x41e280 writes it, 0x41e270 reads it)
      cameraChunk: i32(0x508674),          // c of 0x4304d0 (written in 0x41d920 from 0x4977d0)
    });
  };

  // --- drive: the start camera, then a test bot (not original behaviour) like full-race-gaps.mjs ---------------
  const N = r.route.maxChunk();
  let hist = [], reverse = 0;
  const botKeys = () => {
    const s = r.state();
    if (s.phase !== 0) return [];
    const p = r.player();
    const c = ((p.sector + 4) % N + N) % N, t = r.route.pos(c);
    const dx = t[0] - p.x, dz = t[2] - p.z, fx = p.mat[8], fz = p.mat[10];
    const ang = Math.atan2(fx * dz - fz * dx, fx * dx + fz * dz);
    hist.push([p.x, p.z]); if (hist.length > 60) hist.shift();
    const moved = hist.length === 60 ? Math.hypot(hist[59][0] - hist[0][0], hist[59][1] - hist[0][1]) : 999;
    if (reverse === 0 && moved < 15) { reverse = 45; hist = []; }
    if (reverse > 0) { reverse--; return [VK.DOWN, ang > 0 ? VK.RIGHT : VK.LEFT]; }
    const keys = [];
    if (s.kmh < (Math.abs(ang) > 0.5 ? 70 : 140)) keys.push(VK.UP);
    if (ang > 0.05) keys.push(VK.LEFT); else if (ang < -0.05) keys.push(VK.RIGHT);
    return keys;
  };
  const last = Math.max(...TICKS);
  const want = new Set(TICKS);
  for (let n = 1; n <= last; n++) {
    r.ctl.keys = new Set(botKeys());
    if (CAMERA_KEYS.has(n)) r.ctl.keys.add(CAMERA_KEYS.get(n));
    if (want.has(n)) frame = { draws: [] };
    if (!r.tick()) break;
    if (frame) { analyse(n, u32(0x53b9c0) === 1 ? 'start' : 'race'); frame = null; }
  }

  // --- the finish flag, forced on ------------------------------------------------------------------------------
  const flag = { option: u32(0x53ba28), injected: 'u32[0x50bc28] = 1 (the on-switch 0x423230 writes)', frames: 0, strips: new Map(), reach: null };
  dv.setUint32(0x50bc28, 1, true);
  let minReachX = Infinity, minReachY = Infinity, maxReachX = 0, maxReachY = 0, zLo = Infinity, zHi = -Infinity;
  const cover = [0, 0, 0], cells = [0, 0, 0];
  for (let n = 0; n < FLAG_FRAMES; n++) {
    frame = { draws: [] };
    r.ctl.keys = new Set(botKeys());
    if (!r.tick()) break;
    const fl = frame.draws.filter((d) => d.verts >= 0x5091a0 && d.verts < 0x50bc20);
    frame = null;
    if (!fl.length) continue;
    flag.frames++;
    const layer = new Float64Array(GW * GH).fill(Infinity);
    for (const d of fl) {
      flag.strips.set(d.verts, (flag.strips.get(d.verts) || 0) + 1);
      for (let v = 0; v < d.pos.length / 3; v++) { zLo = Math.min(zLo, d.pos[v * 3 + 2]); zHi = Math.max(zHi, d.pos[v * 3 + 2]); }
      for (let t = 0; t < d.tris.length; t += 3) {
        const poly = clipNearFar(d.tris.slice(t, t + 3).map((v) => xform(d.M, d.pos[v * 3], d.pos[v * 3 + 1], d.pos[v * 3 + 2])));
        if (poly) raster(layer, poly);
      }
      // reach of the sheet's outer columns/rows in NDC (|x| of the left/right edge vertices, |y| of the top/bottom)
      for (let v = 0; v < d.pos.length / 3; v++) {
        const h = xform(d.M, d.pos[v * 3], d.pos[v * 3 + 1], d.pos[v * 3 + 2]);
        const x = Math.abs(h[0] / h[3]), y = Math.abs(h[1] / h[3]);
        if (Math.abs(Math.abs(d.pos[v * 3]) - 100) < 1e-3) { minReachX = Math.min(minReachX, x); maxReachX = Math.max(maxReachX, x); }
        if (Math.abs(Math.abs(d.pos[v * 3 + 1]) - 75) < 1e-3) { minReachY = Math.min(minReachY, y); maxReachY = Math.max(maxReachY, y); }
      }
    }
    for (let j = 0; j < GH; j++) for (let i = 0; i < GW; i++) { const g = regionOf(cellX(i)); cells[g]++; if (layer[j * GW + i] < Infinity) cover[g]++; }
  }
  flag.strips = { count: flag.strips.size, first: hex(Math.min(...flag.strips.keys())), last: hex(Math.max(...flag.strips.keys())),
    inRecorderFlagRange: [...flag.strips.keys()].filter((v) => v >= 0x5091a0 && v < 0x5091a0 + 34 * 32).length };
  flag.sheetZ = { min: +zLo.toFixed(3), max: +zHi.toFixed(3) };
  flag.reach = { minEdgeX: +minReachX.toFixed(4), maxEdgeX: +maxReachX.toFixed(4), minEdgeY: +minReachY.toFixed(4), maxEdgeY: +maxReachY.toFixed(4) };
  flag.coverPct = cover.map((v, g) => +(100 * v / Math.max(1, cells[g])).toFixed(2));

  const sites = Object.fromEntries([...flagsBySite].map(([k, s]) => [k, [...s].map(hex)]));
  weather.frames = Math.round(weather.frames);
  return { etappe, boot, sites, frames: results, flag, weather };
}

// --- all tracks -----------------------------------------------------------------------------------------------
mkdirSync(OUT, { recursive: true });
const all = [];
const lines = [];
const say = (t) => { console.log(t); lines.push(t); };
const mean = (xs) => (xs.length ? xs.reduce((a, b) => a + b, 0) / xs.length : 0);
const total = { mesh: { '4:3': 0, '16:9 only': 0, '21:9 only': 0, offscreen: 0 }, track: { '4:3': 0, '16:9 only': 0, '21:9 only': 0, offscreen: 0 } };
for (const e of ETAPPES) {
  const t0 = Date.now();
  const res = await runTrack(e);
  all.push(res);
  const F = res.frames;
  say(`etappe ${e}: ${F.length} frames (${F.filter((f) => f.label === 'start').length} start camera, cameras ${[...new Set(F.map((f) => f.camera))].join('/')}) in ${((Date.now() - t0) / 1000).toFixed(1)} s`);
  say(`  boot ${JSON.stringify({ ...res.boot, projection: undefined, viewport: undefined })}`);
  say(`  viewport ${JSON.stringify(res.boot.viewport)}  projection ${JSON.stringify(res.boot.projection)}`);
  say(`  draw sites (function prim vtype: DrawPrimitive flags) ${JSON.stringify(res.sites)}`);
  const meshIn = { '4:3': 0, '16:9 only': 0, '21:9 only': 0, offscreen: 0 }, trackTri = { '4:3': 0, '16:9 only': 0, '21:9 only': 0, offscreen: 0 };
  for (const f of F) {
    const mm = f.draws['0x4a96b0'];
    if (mm) for (const k in meshIn) { meshIn[k] += mm.drawIn[k]; total.mesh[k] += mm.drawIn[k]; }
    const tt = f.draws['track 0x497270'];
    if (tt) for (const k in trackTri) { trackTri[k] += tt.triIn[k]; total.track[k] += tt.triIn[k]; }
  }
  say(`  mesh draws (0x4a96b0) by where they are visible: ${JSON.stringify(meshIn)}`);
  say(`  track triangles drawn (0x497270) by where they are visible: ${JSON.stringify(trackTri)}`);
  const col = (key) => [0, 1, 2].map((g) => mean(F.map((f) => f.grid[key][g])).toFixed(3));
  const mx = (key) => [0, 1, 2].map((g) => Math.max(...F.map((f) => f.grid[key][g])).toFixed(2));
  say(`  track pop-in cells %, out-of-window chunks more than 10 from the camera chunk (4:3, 16:9 band, 21:9 band): mean ${col('popinPct').join(', ')}  max ${mx('popinPct').join(', ')}`);
  say(`  track pop-in cells %, out-of-window chunks within 10 of the camera chunk: mean ${col('popinNearPct').join(', ')}  max ${mx('popinNearPct').join(', ')}`);
  say(`  cells with neither world nor sky %: mean ${col('holePct').join(', ')}; not covered by sky %: mean ${col('noSkyPct').join(', ')}`);
  const objF = ['4:3', '16:9 band', '21:9 band'].map((k) => F.reduce((a, f) => a + f.objectsOutsideWindowOriginInFront[k], 0));
  const objO = ['4:3', '16:9 band', '21:9 band'].map((k) => F.reduce((a, f) => a + f.objectsOutsideWindowOriginOnScreen[k], 0));
  say(`  objects outside the window, origin on screen (summed over frames) 4:3/16:9 band/21:9 band: ${objO.join(' / ')}; of these nearer than the drawn scene: ${objF.join(' / ')}`);
  const worst = [...F].sort((a, b) => (b.grid.popinPct[1] + b.grid.popinPct[2]) - (a.grid.popinPct[1] + a.grid.popinPct[2]))[0];
  if (worst) say(`  worst band frame: tick ${worst.tick} (${worst.label}, camera ${worst.camera}) window ${JSON.stringify(worst.window.ranges)} camera chunk ${worst.cameraChunk}, far pop-in % ${worst.grid.popinPct.join(', ')}, near % ${worst.grid.popinNearPct.join(', ')}`);
  if (res.weather.frames) say(`  weather (0x483350, ${res.weather.frames} frames): triangles by |x| bin of 0.125 ${JSON.stringify(res.weather.bins)}; camera-space extent x/y/z ${JSON.stringify(res.weather.view.map((r) => r.map((v) => +v.toFixed(1))))}; world identity ${res.weather.worldIdentity}`);
  say(`  flag (forced on ${res.flag.frames} frames): ${JSON.stringify({ strips: res.flag.strips, sheetZ: res.flag.sheetZ, reach: res.flag.reach, coverPct: res.flag.coverPct })}`);
}
say(`all tracks: mesh draws ${JSON.stringify(total.mesh)}; track triangles ${JSON.stringify(total.track)}`);
writeFileSync(join(OUT, 'result.json'), JSON.stringify({ grid: { cell: CELL, w: GW, h: GH, rects: RECTS, yr: YR, regions: REGION }, tracks: all }));
writeFileSync(join(OUT, 'summary.txt'), lines.join('\n') + '\n');
console.log('wrote', join(OUT, 'result.json'), 'and summary.txt');
