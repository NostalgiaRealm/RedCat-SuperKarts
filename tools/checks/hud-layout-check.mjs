#!/usr/bin/env node
// Checks source/host/hud-layout.js on the recompiled rcskspel.dat, headless (Nederland, Landenrace, RedCat), for a
// screen shape without insets or touch band (hud-scale-check.mjs takes those too).
//   node tools/checks/hud-layout-check.mjs [--xr 1.3333] [--yr 0.75] [--ticks 1700] [--out evidence/checks/hud-layout.txt]
// Two races with the same keys, clock and HUD events:
//   A plain;
//   B with HudLayout.apply(xr, yr) / restore() around every call of the HUD's draw, m_Manager.Render 0x4614d0
//     (its thunk hook!eh_004614d0, called at 0x467dcb from the HUD pass 0x467d30 after the update 0x468d30).
// It prints (1) the HUD component tree with each component's anchor group, (2) each group's local position
// before apply, after apply and after restore, for 16:9 and for tall shapes, (3) every HUD draw of A and B at
// chosen ticks, named by walking the tree in draw order, with the shift B - A of its projected position against
// the shift the JS port's frame of its group gives it (raceHudLayout itself, hud-lib.mjs jsFrames / expectation), (4) whether restore() left every component field and the bonus globals exactly as
// they were, on every frame of B, and (5) a byte compare of all guest memory of A and B at the same ticks,
// outside the stack, the HUD's cached world transforms (+0x44..+0x73 of composites and strings) and the render
// objects the HUD's elements draw through.
// Exit code 1 (and RESULT: FAIL on the console, not in the --out file) when a draw is marked "<-- differs" or restore()
// left a difference. (5) is only reported: without hud-scale-check.mjs's race C (A's dead stack copied in) leftovers of
// the HUD's draw reach other bytes through the stack (evidence/checks/hud-layout-9x16.txt from tick 1428).
import { writeFileSync, mkdirSync } from 'node:fs';
import { join, dirname, resolve } from 'node:path';
import { makeRace, VK, ROOT } from './full-race-gaps-lib.mjs';
import { HudLayout } from '../../source/host/hud-layout.js';
import { jsFrames, expectation, rendered, drawOrder as drawOrderOf, tree as treeOf } from './hud-lib.mjs';

const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const XR = Number(opt('xr', 4 / 3));
const YR = Number(opt('yr', 0.75));
const TICKS = Number(opt('ticks', 1700));
const OUT = resolve(ROOT, opt('out', 'evidence/checks/hud-layout.txt'));
const lines = [];
const out = (s = '') => { lines.push(s); console.log(s); };

const MANAGER = 0x53a5f8;
const VT = { 0x4d2834: 'composite', 0x4d2890: 'element', 0x4d28c8: 'fixed string', 0x4d2b98: 'prop string' };
const OBJ_TABLE = 0x6a5c38, OBJ_STRIDE = 0xa9;
const WORLD_CACHE = 0x6a61dc;    // the matrix last given to SetTransform(WORLD) (0x4235c0 at 0x423790): the HUD's last draw     // render objects (0x4599c0..0x459c80: element +0x50 indexes it)
// HUD events through the dispatcher 0x430610 (cdecl, event id): 5 "Laatste ronde!" (zoom style), 6 "Snelste
// ronde" (sliding style 0x46d5d0), 1 "PAUZE" text, 2 stop. Called between ticks, the same in A and B.
const EVENTS = { 400: 5, 700: 6, 1000: 1, 1100: 2 };

async function newRace(withLayout) {
  const r = await makeRace({});
  const m = r.m;
  const s = { r, m, layout: null, draws: null, frames: 0, restoreMismatch: 0, restoreChecked: 0, writes: 0, clip: null };
  // HUD draws, captured when s.draws is an array
  const rr = r.host.render;
  let W = null;
  rr.setTransform = (t, p) => { if (rr.hud && s.draws && t === 1) W = Array.from({ length: 16 }, (_, k) => m.f32[(p >> 2) + k]); };
  rr.drawIndexed = (pr, vt, v, nv) => {
    if (!(rr.hud && s.draws)) return;
    let cx = 0, cy = 0, cz = 0;
    const xs = [], ys = [], zs = [];
    for (let k = 0; k < nv; k++) {
      const q = (v >> 2) + k * 8, a = m.f32[q], b = m.f32[q + 1], c = m.f32[q + 2];
      const z = a * W[2] + b * W[6] + c * W[10] + W[14];
      xs.push((a * W[0] + b * W[4] + c * W[8] + W[12]) / z);
      ys.push((a * W[1] + b * W[5] + c * W[9] + W[13]) / z);
      zs.push(z);
      cx += xs[k] / nv; cy += ys[k] / nv; cz += z / nv;
    }
    // mean projected vertex: world units at z = 1 (x/z, y/z); clip: the cut hud-layout.js asked for (its clip sink)
    s.draws.push({ x: cx, y: cy, z: cz, xs, ys, zs, clip: s.clip });
  };
  if (withLayout) {
    const layout = new HudLayout(m);
    s.layout = layout;
    const id = m.thunkId('hook!eh_004614d0');
    const render = m.thunks[id];
    m.thunks[id] = (esp, ecx, edx, eax) => {
      const before = fieldSnapshot(s);
      // the clip sink as the worker's (the recorder's hudClip): the bonus box is then drawn into its frame (rendered)
      layout.apply(XR, YR, { clip: (rect) => { s.clip = rect; } });
      s.writes += layout.saved.length / 2;
      try {
        return render(esp, ecx, edx, eax);
      } finally {
        layout.restore();
        const after = fieldSnapshot(s);
        s.restoreChecked++;
        if (Buffer.compare(before, after) !== 0) s.restoreMismatch++;
        s.frames++;
      }
    };
  }
  r.race.boot();
  return s;
}

/** Every component's local fields +0x04..+0x33 (with the draw callback +0x30), and the bonus fly-in globals 0x544ae0..0x544aeb. */
function fieldSnapshot(s) {
  const m = s.m;
  const comps = tree(m).map((x) => x.c);
  const buf = Buffer.alloc(comps.length * 0x30 + 12);
  let o = 0;
  for (const c of comps) { buf.set(m.u8.subarray(c + 4, c + 0x34), o); o += 0x30; }
  buf.set(m.u8.subarray(0x544ae0, 0x544aec), o);
  return buf;
}

const nameAt = (m, c) => {
  const p = m.u32[(c + 0x38) >> 2];
  return p ? m.cstr(p) : '';
};

/** The component tree under m_Top, depth first in draw order; strings' glyph children are not listed. */
function tree(m) {
  const outl = [];
  const walk = (c, parent, depth, top) => {
    const kind = VT[m.u32[c >> 2]] || 'vt ' + m.u32[c >> 2].toString(16);
    const name = nameAt(m, c);
    const group = depth === 0 ? 'root' : depth === 1 ? name : top;
    outl.push({ c, kind, name, parent, depth, top: group });
    if (kind === 'composite') {
      const v = m.u32[(c + 0x78) >> 2];
      for (let p = m.u32[(v + 4) >> 2]; p < m.u32[(v + 8) >> 2]; p += 4) walk(m.u32[p >> 2], c, depth + 1, group);
    }
  };
  walk(m.u32[(MANAGER + 4) >> 2], 0, 0, 'root');
  return outl;
}

/** The draws the HUD will make this frame, by walking the tree as 0x458550 / the composite and string draws do. */
function drawOrder(m) {
  const list = tree(m);
  const order = [];
  const visible = new Map();
  for (const x of list) {
    const pv = x.parent ? visible.get(x.parent) : true;
    const v = pv && m.u8[x.c + 0x2c] !== 0;
    visible.set(x.c, v);
    if (!v) continue;
    if (x.kind === 'element') {
      if (m.i32[(x.c + 0x50) >> 2] !== -1) order.push({ name: x.name, top: x.top });
    } else if (x.kind.endsWith('string')) {
      const vv = m.u32[(x.c + 0x78) >> 2];
      for (let p = m.u32[(vv + 4) >> 2]; p < m.u32[(vv + 8) >> 2]; p += 4) {
        const g = m.u32[p >> 2];
        if (m.u8[g + 0x2c] && m.i32[(g + 0x50) >> 2] !== -1) order.push({ name: x.name, top: x.top, glyph: true });
      }
    }
  }
  return order;
}

/** Render-object indices the HUD's elements and glyphs draw through (+0x50 of each element). */
function hudObjects(m) {
  const set = new Set();
  for (const x of tree(m)) {
    if (x.kind === 'element') set.add(m.i32[(x.c + 0x50) >> 2]);
    if (x.kind.endsWith('string')) {
      const vv = m.u32[(x.c + 0x78) >> 2];
      for (let p = m.u32[(vv + 4) >> 2]; p < m.u32[(vv + 8) >> 2]; p += 4) set.add(m.i32[(m.u32[p >> 2] + 0x50) >> 2]);
    }
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

/** Byte compare of A and B; differences are sorted into the places the HUD draw writes and everything else. */
function compareMemory(a, b) {
  const ma = a.m.u8, mb = b.m.u8;
  const L = a.m.layout;
  const caches = [];
  for (const x of tree(a.m)) if (x.kind !== 'element') caches.push([x.c + 0x44, x.c + 0x74]);
  const objs = hudObjects(a.m);
  const table = a.m.u32[OBJ_TABLE >> 2];
  const where = (p) => {
    if (p >= L.STACK_LOW && p < L.TIB_BASE) return 'stack';
    if (p >= WORLD_CACHE && p < WORLD_CACHE + 64) return 'last world matrix 0x6a61dc';
    for (const [lo, hi] of caches) if (p >= lo && p < hi) return 'HUD world transform cache';
    if (p >= table) {
      const k = Math.floor((p - table) / OBJ_STRIDE);
      if (objs.has(k)) return 'HUD render object';
    }
    return 'other';
  };
  const counts = {};
  const other = [];
  const n = Math.min(ma.length, mb.length);
  const CH = 1 << 16;
  for (let o = 0; o < n; o += CH) {
    const e = Math.min(n, o + CH);
    if (Buffer.compare(ma.subarray(o, e), mb.subarray(o, e)) === 0) continue;
    for (let p = o; p < e; p++) {
      if (ma[p] === mb[p]) continue;
      const w = where(p);
      counts[w] = (counts[w] || 0) + 1;
      if (w === 'other' && other.length < 12) other.push('0x' + p.toString(16));
    }
  }
  return { counts, other };
}

const A = await newRace(false);
const B = await newRace(true);
const m = B.m;

out(`# hud-layout-check: recompiled rcskspel.dat, Nederland Landenrace, RedCat; layout apply(${XR.toFixed(4)}, ${YR.toFixed(4)}) in race B`);
out(`# m_Manager 0x53a5f8: m_Top 0x${m.u32[(MANAGER + 4) >> 2].toString(16)}, root transform (+0x18): ${Array.from({ length: 12 }, (_, k) => +m.f32[(MANAGER + 0x18 + k * 4) >> 2].toFixed(4)).join(' ')}`);
out(`# HUD projection (+0x48): m00 ${m.f32[(MANAGER + 0x48) >> 2].toFixed(5)} m11 ${m.f32[(MANAGER + 0x5c) >> 2].toFixed(5)} m22 ${m.f32[(MANAGER + 0x70) >> 2].toFixed(5)} m23 ${m.f32[(MANAGER + 0x74) >> 2].toFixed(5)} m32 ${m.f32[(MANAGER + 0x7c) >> 2].toFixed(5)}`);
out(`# bonus fly-in start 0x544ae0: ${[0, 4, 8].map((o) => m.f32[(0x544ae0 + o) >> 2].toFixed(3)).join(' ')}`);
out('');

// (1) the tree and its groups, after boot
const layout = B.layout;
layout.scan();
out('## Components after boot (depth, kind, name, local position, visible) and the group of their top-level parent');
const groupOf = (top) => {
  const e = layout.entries.find((x) => x.name === top);
  return e ? e.group : top === 'root' ? '-' : 'unclassified';
};
for (const x of tree(m)) {
  const p = [4, 8, 12].map((o) => m.f32[(x.c + o) >> 2].toFixed(4)).join(', ');
  out(`${'  '.repeat(x.depth)}${x.name.padEnd(24 - 2 * x.depth)} ${x.kind.padEnd(12)} (${p}) vis ${m.u8[x.c + 0x2c]}  ${x.depth ? groupOf(x.top) : ''}`);
}
out(`unclassified Screen children: ${layout.unclassified.length ? layout.unclassified.join(', ') : 'none'}`);
out('');

// (2) positions before apply / after apply / after restore
const shapeTable = (label, xr, yr) => {
  out(`## ${label}: apply(${xr.toFixed(4)}, ${yr.toFixed(4)}) on the state after boot`);
  const before = layout.describe();
  const snap0 = fieldSnapshot(B);
  layout.apply(xr, yr, { clip: () => {} });
  const during = layout.describe();
  const writes = layout.saved.length / 2;
  layout.restore();
  const after = layout.describe();
  const same = Buffer.compare(snap0, fieldSnapshot(B)) === 0;
  out('name                    group         before (x, y)        applied (x, y)       restored (x, y)');
  for (let k = 0; k < before.length; k++) {
    const f = (d) => `(${d.x.toFixed(4)}, ${d.y.toFixed(4)})`.padEnd(21);
    out(`${before[k].name.padEnd(23)} ${before[k].group.padEnd(13)} ${f(before[k])}${f(during[k])}${f(after[k])}`);
  }
  out(`${writes} floats written, component fields identical after restore: ${same}`);
  out('');
};
shapeTable('4:3', 1, 0.75);
shapeTable('16:9', ...Object.values(HudLayout.clipFor(16 / 9)));
shapeTable('21:9 (2.37)', ...Object.values(HudLayout.clipFor(2.37)));
shapeTable('1:1', ...Object.values(HudLayout.clipFor(1)));
shapeTable('9:16', ...Object.values(HudLayout.clipFor(9 / 16)));

// (3)-(5): the races
const bonusObj = tree(m).find((x) => x.name === 'BonusObject')?.c;
const captures = new Map();          // tick -> label
for (const t of [60, 300, 420, 760, 1020]) captures.set(t, '');
let bonusSeen = null;
const memChecks = [];
const drawReport = [];
let shiftFails = 0;
const F = jsFrames(XR, YR);
// the expected shift of a draw's mean vertex: the mean of A's vertices, each mapped where the JS port's frame of its
// group (or one of hud-layout.js's exceptions, hud-lib.mjs expectation) puts it, less A's mean
const expectShift = (o, a, mA) => {
  const e = expectation(o, mA, F, { xr: XR });
  let x = 0, y = 0;
  for (let k = 0; k < a.xs.length; k++) { const q = e.map(a.xs[k], a.ys[k], a.zs[k]); x += q[0] / a.xs.length; y += q[1] / a.xs.length; }
  return [x - a.x, y - a.y];
};
// B's draw as it reaches the screen: the bonus box, drawn into its frame by the renderer (hud-lib.mjs rendered)
const onScreen = (d) => {
  const r = rendered(d, XR, YR);
  if (r === d) return d;
  return { ...r, x: r.xs.reduce((a, v) => a + v, 0) / r.xs.length, y: r.ys.reduce((a, v) => a + v, 0) / r.ys.length };
};
const finishKeys = (s) => {
  // Ctrl+F+I (0x429a90): phase 3 once all three are released; released after 50 polls of Ctrl in the tick
  s.r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]);
  let polls = 0;
  s.r.ctl.onPoll = (vk, ctl) => { if (vk === VK.CONTROL && ++polls > 50) ctl.keys.clear(); };
};
for (let n = 0; n < TICKS + 80; n++) {
  for (const s of [A, B]) {
    if (EVENTS[n] !== undefined) s.m.call(0x430610, [EVENTS[n]]);
    s.r.ctl.onPoll = null;
    if (n === TICKS) finishKeys(s);
    else s.r.ctl.keys = new Set(n > 330 && n < TICKS ? [VK.UP] : []);
  }
  if (n === TICKS + 40) captures.set(n, 'finish phase');
  const cap = captures.has(n);
  const order = cap ? drawOrderOf(A.m) : null;
  const parents = cap ? new Map(treeOf(A.m).map((x) => [x.c, x.parent])) : null;
  A.draws = cap ? [] : null;
  B.draws = cap ? [] : null;
  A.r.tick();
  B.r.tick();
  if (bonusObj && bonusSeen === null && A.m.u8[bonusObj + 0x2c]) {
    bonusSeen = n;
    captures.set(n + 4, 'bonus model in flight');
    captures.set(n + 50, 'bonus model at rest');
  }
  if (cap) {
    const label = captures.get(n);
    drawReport.push(`### tick ${n}${label ? ' (' + label + ')' : ''}, race phase ${A.m.u32[0x53b9c0 >> 2]}: ${A.draws.length} draws in A, ${B.draws.length} in B, ${order.length} predicted from the tree`);
    // group consecutive draws of one component
    const rows = [];
    for (let k = 0; k < Math.min(A.draws.length, B.draws.length, order.length); k++) {
      const o = order[k];
      const b = onScreen(B.draws[k]);
      const d = [b.x - A.draws[k].x, b.y - A.draws[k].y];
      const e = expectShift({ ...o, parent: parents.get(o.c) }, A.draws[k], A.m);
      const err = Math.hypot(d[0] - e[0], d[1] - e[1]);        // every glyph against its own expected shift
      const last = rows[rows.length - 1];
      if (last && last.name === o.name && o.glyph) { last.n++; last.err = Math.max(last.err, err); continue; }
      const z = A.draws[k].z;
      rows.push({ name: o.name, top: o.top, n: 1, d, err, z, ax: A.draws[k].x, ay: A.draws[k].y, e });
    }
    for (const row of rows) {
      const e = row.e;
      // every draw of the row within 0.01 canvas px of its expected shift (plus float32's 7 digits far off screen)
      const ok = row.err < 0.01 / 320 + 2e-6 * Math.max(1, Math.abs(row.ax), Math.abs(row.ay));
      if (!ok) shiftFails++;
      drawReport.push(`  ${row.name.padEnd(22)} x${String(row.n).padEnd(3)} ${groupOf(row.top).padEnd(13)} A at (${row.ax.toFixed(3)}, ${row.ay.toFixed(3)}) z ${row.z.toFixed(3)}  B-A (${row.d[0].toFixed(4)}, ${row.d[1].toFixed(4)})  expected (${e[0].toFixed(4)}, ${e[1].toFixed(4)})${ok ? '' : `  <-- differs by ${(row.err * 320).toFixed(3)} px`}`);
    }
    memChecks.push({ tick: n, ...compareMemory(A, B) });
  }
}
memChecks.push({ tick: 'end', ...compareMemory(A, B) });

out('## HUD draws, A (4:3) and B (layout), mean projected vertex in world units (x/z, y/z)');
for (const l of drawReport) out(l);
out('');
out('## restore()');
out(`B drew the HUD ${B.frames} times with the layout; ${B.writes} float writes by apply in all; component fields or bonus globals differing after restore: ${B.restoreMismatch} of ${B.restoreChecked} frames`);
out('');
out('## Guest memory of A against B (same keys, clock, events)');
for (const c of memChecks) out(`tick ${c.tick}: differing bytes ${JSON.stringify(c.counts)}${c.other.length ? ' other at ' + c.other.join(' ') : ''}`);
out(`race phase at the end: A ${A.m.u32[0x53b9c0 >> 2]}, B ${B.m.u32[0x53b9c0 >> 2]}; laps A ${A.m.i32[0x53ba18 >> 2]}, B ${B.m.i32[0x53ba18 >> 2]}; bonus model first shown at tick ${bonusSeen}`);
mkdirSync(dirname(OUT), { recursive: true });
writeFileSync(OUT, lines.join('\n') + '\n');
const pass = shiftFails === 0 && B.restoreMismatch === 0;
console.log(`RESULT: ${pass ? 'pass' : 'FAIL'} (draws off their expected shift ${shiftFails}, frames differing after restore ${B.restoreMismatch})`);
if (!pass) process.exitCode = 1;
