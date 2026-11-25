// Shared by the HUD scale checks (hud-scale-levers.mjs, hud-scale-check.mjs): the HUD's component tree in draw
// order, a capture of the HUD's draws as projected vertices, and a direct call of its draw.
//
// rcskspel.dat: m_Manager 0x53a5f8, m_Top (the "Screen" composite) at +0x04, root transform at +0x18
// (0x4606c0), the HUD's draw m_Manager.Render 0x4614d0 (thiscall, no arguments: 0x462320 sets the HUD's view and
// projection, 0x458550 draws m_Top with the root transform, 0x462610 puts the render states back).
// Component draw: composite 0x458760 (world transform through vtable +0x30, then each child), element 0x459440
// (obj+0x50.. = local * parent Width/Height + parent position, obj+0x58 = z + 1, obj+0x80.. = this+0x10 * parent
// Scale), strings are composites of glyph elements with the world transform 0x463bb0.
import { join } from 'node:path';
import { pathToFileURL } from 'node:url';
import { makeRace, ROOT } from './full-race-gaps-lib.mjs';
import { SPECIAL_SLIDE } from '../../source/host/hud-layout.js';

// The JS reconstruction's own layout function, imported read-only from its checkout (a module without imports):
// the reference the HUD checks hold source/host/hud-layout.js to.
export const JS_LAYOUT = join(ROOT, '..', 'RedCat Superkarts', 'source', 'race-hud-layout.js');
export const { raceHudLayout } = await import(pathToFileURL(JS_LAYOUT).href);

/**
 * The JS port's frame of every Screen child for a drawing of clip half-extents xr, yr and hud-layout.js's opts
 * ({ insets: fractions, controls: { left: touch band, a fraction of the height } }), from raceHudLayout itself:
 * per group (overlay.ini names, upper case) { k, bx, by, X, Y } (the similarity q = k p + b of the HUD's world, and
 * the frame's top left corner from the screen's top left, world units). Its group() for meshes, text() for the
 * strings: the race times (NUMBERS), the Tijdrace time and the notices. rect: a group's viewport, which cuts its
 * meshes (race-hud-meshes.js:256-257), as fractions of the screen from its top left ({ x, y, w, h }); null for the
 * strings, drawn over the whole canvas (race-hud.js:123).
 */
export function jsFrames(xr, yr, opts = {}) {
  const P = 1000, W = 2 * xr * P, H = 2 * yr * P;
  const ins = opts.insets || {};
  const L = raceHudLayout(W, H, { left: (ins.left || 0) * W, right: (ins.right || 0) * W, top: (ins.top || 0) * H,
    bottom: (ins.bottom || 0) * H, touchHeight: ((opts.controls && opts.controls.left) || 0) * H });
  const sim = ({ x, y, scale = L.scale, width, height }) => {
    const k = (320 * scale) / P;
    return { k, bx: x / P + k - xr, by: yr - y / P - 0.75 * k, X: x / P, Y: y / P, rect: width ? { x: x / W, y: y / H, w: width / W, h: height / H } : null };
  };
  return {
    layout: L,
    PORTRAITS: sim(L.group('portraits')), STARS: sim(L.group('stars')), MAP: sim(L.group('map')), BONUS: sim(L.group('bonus')),
    '321TIMER': sim(L.group('321timer')), BACKARROW: sim(L.group('arrows')), JUNCTIONARROW: sim(L.group('arrows')),
    NUMBERS: sim(L.text('string_lap')), STRING_SPECIAL: sim(L.text('string_special')),
    STRING_COUNTDOWN_VALUE: sim(L.text('string_countdown_value')), STRING_BONUS: sim(L.text('string_bonus')),
  };
}

/**
 * Where source/host/hud-layout.js must draw the vertices of draw d of the 4:3 HUD (a drawOrder entry with its
 * parent, on race A's state mA), for the frames F of jsFrames: { map(x, y, z), ideal(x, y), size, note }. A vertex
 * of a group goes to k v + b (its JS-port frame). The bonus box is drawn into its frame by the renderer (hud-layout.js
 * GROUPS frame), as the JS port draws every group: its projected picture goes to k v + b as it is, also the 3D model
 * (map = ideal); compare it after rendered(). Exception, as hud-layout.js documents it: the sliding notice's path is
 * stretched to (xr + k m) / (1 + m) of its 4:3 length (m = 2.1025 * 0.75 - 1, how far beyond the edge it starts at
 * 4:3).
 */
export function expectation(d, mA, F, { xr }) {
  const f = mA.f32;
  const ROOT_T = MANAGER + 0x18;
  const rootW = f[(ROOT_T + 0x10) >> 2];
  const q = F[String(d.top).toUpperCase()];
  const T = q ? (x, y) => [q.k * x + q.bx, q.k * y + q.by] : (x, y) => [x, y];
  // apply works in world units, where a vertex at depth z is drawn at x/z, y/z: the transform of a vertex of A at
  // projected (x, y) and depth z is taken at (x z, y z) and projected back. "ideal" is the same transform on the
  // projected picture, what a flat HUD at z 1 would give, and what the JS port's viewport of a group does.
  const world = (fn) => (x, y, z) => { const p = fn(x * z, y * z); return [p[0] / z, p[1] / z]; };
  if (d.name === 'STRING_SPECIAL') {
    const slide = SPECIAL_SLIDE * rootW;
    const Fx = (xr + q.k * (slide - 1)) / slide;
    const ox = f[(d.c + 4) >> 2] * rootW;
    const fn = (x, y) => [Fx * ox + q.bx + q.k * (x - ox), q.k * y + q.by];
    return { map: world(fn), ideal: fn, size: q.k };
  }
  if (d.top === 'Bonus') return { map: (x, y) => T(x, y), ideal: T, size: q.k };
  return { map: world(T), ideal: T, size: q ? q.k : 1 };
}

/**
 * A captured HUD draw as it reaches the screen: a draw cut in mode 2 (clip.frame, the renderer's frame mode,
 * gl-renderer.js prepare) is drawn with the game's 4:3 clip (x -1..1, y -0.75..0.75) into its rect, the screen being
 * x -xr..xr, y -yr..yr; any other as it is.
 */
export function rendered(d, xr, yr) {
  const c = d.clip;
  if (!c || !c.frame) return d;
  const X = (x) => (c.x + (c.w * (x + 1)) / 2) * 2 * xr - xr;
  const Y = (y) => yr - (c.y + (c.h * (0.75 - y)) / 1.5) * 2 * yr;
  const xs = d.xs.map(X), ys = d.ys.map(Y);
  return { ...d, xs, ys, ...bounds(xs, ys, d.zs) };
}

export const MANAGER = 0x53a5f8;
export const RENDER = 0x4614d0;
export const VT = { 0x4d2834: 'composite', 0x4d2890: 'element', 0x4d28c8: 'fixed string', 0x4d2b98: 'prop string' };
export const BONUS_START = 0x544ae0;
// HUD events through the dispatcher 0x430610 (cdecl, event id), research-hud-notice-audit.md of the JS port:
// 1 PAUZE (style 0), 2 stop, 3 Superbonus! (1), 4 Raak! (1), 5 Laatste ronde! (4, zoom), 6 Snelste ronde (5, slide),
// 10 Alle voorwerpen verzameld! (1), 11 Controlepunt! (1).
export const EVENT = 0x430610;

export const nameAt = (m, c) => {
  const p = m.u32[(c + 0x38) >> 2];
  return p ? m.cstr(p) : '';
};

export function childrenOf(m, c) {
  const v = m.u32[(c + 0x78) >> 2];
  const out = [];
  for (let p = m.u32[(v + 4) >> 2]; p < m.u32[(v + 8) >> 2]; p += 4) out.push(m.u32[p >> 2]);
  return out;
}

/** The component tree under m_Top, depth first in draw order; strings' glyph children are not listed. */
export function tree(m) {
  const outl = [];
  const walk = (c, parent, depth, top) => {
    const kind = VT[m.u32[c >> 2]] || 'vt ' + m.u32[c >> 2].toString(16);
    const name = nameAt(m, c);
    const group = depth === 0 ? 'root' : depth === 1 ? name : top;
    outl.push({ c, kind, name, parent, depth, top: group });
    if (kind === 'composite') for (const k of childrenOf(m, c)) walk(k, c, depth + 1, group);
  };
  walk(m.u32[(MANAGER + 4) >> 2], 0, 0, 'root');
  return outl;
}

/** The draws the HUD will make this frame, by walking the tree as 0x458550 / the composite and string draws do. */
export function drawOrder(m) {
  const list = tree(m);
  const order = [];
  const visible = new Map();
  for (const x of list) {
    const pv = x.parent ? visible.get(x.parent) : true;
    const v = pv && m.u8[x.c + 0x2c] !== 0;
    visible.set(x.c, v);
    if (!v) continue;
    if (x.kind === 'element') {
      if (m.i32[(x.c + 0x50) >> 2] !== -1) order.push({ name: x.name, top: x.top, c: x.c });
    } else if (x.kind.endsWith('string')) {
      for (const g of childrenOf(m, x.c)) {
        if (m.u8[g + 0x2c] && m.i32[(g + 0x50) >> 2] !== -1) order.push({ name: x.name, top: x.top, c: x.c, glyph: g });
      }
    }
  }
  return order;
}

/**
 * A headless race whose HUD draws are captured while s.draws is an array: per draw, every vertex projected as
 * the HUD's view does (x/z, y/z of the world matrix given to SetTransform(WORLD)), in world units at z = 1.
 */
export async function hudRace(opts = {}) {
  const r = await makeRace(opts);
  const m = r.m;
  // world: while an array, every draw outside the HUD as it reaches Direct3D (transforms, vertex and index words);
  // clip: the cut hud-layout.js asked for (a sink that sets it: { clip: (rect) => { s.clip = rect; } }), kept per draw
  const s = { r, m, draws: null, world: null, clip: null };
  const rr = r.host.render;
  let W = null;
  const copy = (p, n) => m.u32.slice(p >> 2, (p >> 2) + n);
  rr.setTransform = (t, p) => {
    if (!rr.hud && s.world) s.world.push({ what: 'SetTransform ' + t, words: copy(p, 16) });
    if (rr.hud && s.draws && t === 1) W = Array.from({ length: 16 }, (_, k) => m.f32[(p >> 2) + k]);
  };
  rr.drawPrimitive = (pr, vt, v, nv) => {
    if (!rr.hud && s.world) s.world.push({ what: `DrawPrimitive ${pr} vtype ${vt}`, vt, words: copy(v, nv * 8) });
  };
  rr.drawIndexed = (pr, vt, v, nv, ix, ni) => {
    if (!rr.hud && s.world) {
      const idx = new Uint16Array(m.u8.buffer.slice(ix, ix + ni * 2));
      s.world.push({ what: `DrawIndexedPrimitive ${pr} vtype ${vt}`, vt, words: copy(v, nv * 8), idx });
    }
    if (!(rr.hud && s.draws)) return;
    const xs = new Float64Array(nv), ys = new Float64Array(nv), zs = new Float64Array(nv);
    for (let k = 0; k < nv; k++) {
      const q = (v >> 2) + k * 8, a = m.f32[q], b = m.f32[q + 1], c = m.f32[q + 2];
      const z = a * W[2] + b * W[6] + c * W[10] + W[14];
      xs[k] = (a * W[0] + b * W[4] + c * W[8] + W[12]) / z;
      ys[k] = (a * W[1] + b * W[5] + c * W[9] + W[13]) / z;
      zs[k] = z;
    }
    s.draws.push({ xs, ys, zs, clip: s.clip, ...bounds(xs, ys, zs) });
  };
  return s;
}

export function bounds(xs, ys, zs) {
  let x0 = Infinity, x1 = -Infinity, y0 = Infinity, y1 = -Infinity, z0 = Infinity, z1 = -Infinity, cx = 0, cy = 0;
  for (let k = 0; k < xs.length; k++) {
    x0 = Math.min(x0, xs[k]); x1 = Math.max(x1, xs[k]);
    y0 = Math.min(y0, ys[k]); y1 = Math.max(y1, ys[k]);
    z0 = Math.min(z0, zs[k]); z1 = Math.max(z1, zs[k]);
    cx += xs[k] / xs.length; cy += ys[k] / xs.length;
  }
  return { x0, x1, y0, y1, z0, z1, cx, cy };
}

/** One more call of the HUD's draw on the current state (between passes), its draws named from the tree. */
export function drawHud(s, around) {
  const { r, m } = s;
  const order = drawOrder(m);
  s.draws = [];
  const rr = r.host.render;
  rr.hud = true;
  try {
    if (around) around(() => m.call(RENDER, [], MANAGER));
    else m.call(RENDER, [], MANAGER);
  } finally {
    rr.hud = false;
  }
  const draws = s.draws;
  s.draws = null;
  if (draws.length !== order.length) throw new Error(`HUD drew ${draws.length} times, the tree predicts ${order.length}`);
  return draws.map((d, k) => ({ ...d, ...order[k] }));
}

/** World units of the HUD (1 = 320 pixels of the 640x480 view) to canvas pixels of the 4:3 screen. */
export const px = (w) => w * 320;
export const canvasX = (x) => 320 + x * 320;
export const canvasY = (y) => 240 - y * 320;

const OBJ_TABLE = 0x6a5c38, OBJ_STRIDE = 0xa9;
const WORLD_CACHE = 0x6a61dc;    // the matrix last given to SetTransform(WORLD) (0x4235c0 at 0x423790): the HUD's last draw

/** Render-object indices the HUD's elements and glyphs draw through (+0x50 of each element), and the fonts' glyphs. */
export function hudObjects(m) {
  const set = new Set();
  for (const x of tree(m)) {
    if (x.kind === 'element') set.add(m.i32[(x.c + 0x50) >> 2]);
    if (x.kind.endsWith('string')) for (const g of childrenOf(m, x.c)) set.add(m.i32[(g + 0x50) >> 2]);
  }
  // Font glyph objects (font: {int object; float width}[256], fonts vector at m_Manager +0x0c): shared by every
  // string, they keep the place of the last glyph drawn with them, also when no string uses them any more.
  const fv = m.u32[(MANAGER + 0x0c) >> 2];
  for (let p = m.u32[(fv + 4) >> 2]; p < m.u32[(fv + 8) >> 2]; p += 4) {
    const f = m.u32[p >> 2];
    for (let ch = 0; ch < 256; ch++) set.add(m.i32[(f + ch * 8) >> 2]);
  }
  set.delete(-1);
  return set;
}

/**
 * Byte compare of two races' guest memory; differences are sorted into the places the HUD's draw writes (its
 * world transform caches +0x44..+0x73 of composites and strings, its render objects, the last world matrix) and
 * everything else.
 */
export function compareMemory(ma, mb) {
  const a = ma.u8, b = mb.u8;
  const L = ma.layout;
  const caches = [];
  for (const x of tree(ma)) if (x.kind !== 'element') caches.push([x.c + 0x44, x.c + 0x74]);
  const objs = hudObjects(ma);
  const table = ma.u32[OBJ_TABLE >> 2];
  const where = (p) => {
    if (p >= L.STACK_LOW && p < L.TIB_BASE) return 'stack';
    if (p >= WORLD_CACHE && p < WORLD_CACHE + 64) return 'last world matrix 0x6a61dc';
    for (const [lo, hi] of caches) if (p >= lo && p < hi) return 'HUD world transform cache';
    if (p >= table && objs.has(Math.floor((p - table) / OBJ_STRIDE))) return 'HUD render object';
    return 'other';
  };
  const counts = {};
  const other = [];
  const n = Math.min(a.length, b.length);
  const CH = 1 << 16;
  for (let o = 0; o < n; o += CH) {
    const e = Math.min(n, o + CH);
    if (Buffer.compare(a.subarray(o, e), b.subarray(o, e)) === 0) continue;
    for (let p = o; p < e; p++) {
      if (a[p] === b[p]) continue;
      const w = where(p);
      counts[w] = (counts[w] || 0) + 1;
      if (w === 'other' && other.length < 12) other.push('0x' + p.toString(16));
    }
  }
  return { counts, other };
}

/**
 * Every field apply() may change, for a restore check: +0x04..+0x33 of every component (position, scale,
 * rotation, visible, the draw callback +0x30 that cuts a group to its frame), +0x7c..+0x83 of composites and strings
 * (width, height), and the bonus fly-in start 0x544ae0..0x544aeb.
 */
export function fieldSnapshot(m) {
  const comps = tree(m);
  const buf = Buffer.alloc(comps.length * 0x38 + 12);
  let o = 0;
  for (const x of comps) {
    buf.set(m.u8.subarray(x.c + 4, x.c + 0x34), o); o += 0x30;
    if (x.kind !== 'element') buf.set(m.u8.subarray(x.c + 0x7c, x.c + 0x84), o);
    o += 8;
  }
  buf.set(m.u8.subarray(BONUS_START, BONUS_START + 12), o);
  return buf;
}

/**
 * Compares two passes' draws outside the HUD (hudRace's s.world): the differing words, at most `max`, as
 * { draw, what, vertex, field, a, b } (vertex/field for vertex words, field 0..15 of a matrix), or a count mismatch.
 */
export function compareWorld(wa, wb, max = 8) {
  const out = [];
  if (wa.length !== wb.length) return [{ draw: -1, what: `${wa.length} draws and transforms in A, ${wb.length} in B` }];
  const f = new DataView(new ArrayBuffer(4));
  const asFloat = (w) => { f.setUint32(0, w, true); return f.getFloat32(0, true); };
  for (let k = 0; k < wa.length && out.length < max; k++) {
    const a = wa[k], b = wb[k];
    if (a.what !== b.what || a.words.length !== b.words.length) { out.push({ draw: k, what: `${a.what} against ${b.what}` }); continue; }
    for (let j = 0; j < a.words.length && out.length < max; j++) {
      if (a.words[j] === b.words[j]) continue;
      const vertex = a.what.startsWith('Set') ? null : Math.floor(j / 8);
      out.push({ draw: k, what: a.what, vertex, field: vertex === null ? j : j % 8, a: asFloat(a.words[j]), b: asFloat(b.words[j]) });
    }
    if (a.idx && (a.idx.length !== b.idx.length || a.idx.some((v, j) => v !== b.idx[j]))) out.push({ draw: k, what: a.what + ' indices' });
  }
  return out;
}
