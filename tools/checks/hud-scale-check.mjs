#!/usr/bin/env node
// Checks the HUD's layout (source/host/hud-layout.js) on the recompiled rcskspel.dat against the JS reconstruction's
// own raceHudLayout (its source/race-hud-layout.js, imported read-only, tools/checks/hud-lib.mjs jsFrames), headless
// (Nederland, RedCat; Landenrace unless --type).
//   node tools/checks/hud-scale-check.mjs [--aspect 0.462085] [--insets 0.0205,0.0205,0.0557,0.0403] [--band 0]
//        [--type 0] [--ticks 1700] [--out evidence/checks/hud-scale-9x19.5.txt]
// insets: left,right,top,bottom as fractions of the drawing (the page's CTRL.INSET_*, with its 8 CSS px minimum at the
// top and sides of an upright screen); band: the touch controls' band as a fraction of its height (CTRL.CONTROLS_L).
// Two races with the same keys, clock and HUD events:
//   A plain (the 4:3 HUD);
//   B with host.hudLayout = { layout, xr, yr, scale, insets, controls }, which race.js's wrapper of the HUD's draw
//     (hook!eh_004614d0, m_Manager.Render 0x4614d0) hands to HudLayout.apply / restore on every frame.
// It prints (1) the groups' fields before apply, applied and restored on the state after boot, for the shapes
// that must stay as they were and for this one; (2) every HUD draw of chosen passes, A against B: where it moved,
// how much it grew, and the largest distance of a vertex of B from where the JS port's frame of its group puts the
// vertex of A, in canvas pixels (1 world unit = 320 px); (3) the same test on every 5th pass of the whole race, summed
// up per group; (4) whether restore() left every field apply may change exactly as it was on every frame of B, and
// all of guest memory byte for byte after an apply and restore without a draw in between; (5) a byte compare of A and
// B, and every draw outside the HUD (transforms, vertices, indices) of every pass, A against B; and the same for C,
// which is B with A's dead stack (below esp between passes) copied in before every pass: the original reads
// uninitialised stack in places (0x487af0 copies a half-built 0x794-byte record from its stack into a vector), so
// leftovers of the HUD's draw can reach later draws through it; with the dead stack the same, nothing outside the HUD
// may differ. The exception to the JS port's frames (the sliding notice's path) is hud-lib.mjs expectation()'s; the
// bonus box is drawn into its frame by the renderer, which hud-lib.mjs rendered() does to B's draws of it. (6) the
// cut of every draw of B (the rect hud-layout.js hands to its clip sink before the draw's group) against the JS
// port's viewport of the group, and what that cut hides; the start lights hidden above their frame must be wholly
// cut.
import { writeFileSync, mkdirSync } from 'node:fs';
import { dirname, resolve } from 'node:path';
import { VK, ROOT } from './full-race-gaps-lib.mjs';
import { hudRace, drawOrder, tree, compareMemory, compareWorld, fieldSnapshot, EVENT, px, canvasX, canvasY, MANAGER, jsFrames, expectation, rendered, JS_LAYOUT } from './hud-lib.mjs';
import { HudLayout, LIGHTS_HIDDEN } from '../../source/host/hud-layout.js';

const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const ASPECT = Number(opt('aspect', 390 / 844));
const [IL, IR, IT, IB] = String(opt('insets', `${8 / 390},${8 / 390},${47 / 844},${34 / 844}`)).split(',').map(Number);
const BAND = Number(opt('band', 0));
const TYPE = Number(opt('type', 0));
const TICKS = Number(opt('ticks', 1700));
const OUT = resolve(ROOT, opt('out', 'evidence/checks/hud-scale-9x19.5.txt'));
const lines = [];
const out = (s = '') => { lines.push(s); console.log(s); };
const { xr: XR, yr: YR } = HudLayout.clipFor(ASPECT);
const INSETS = { left: IL, right: IR, top: IT, bottom: IB };
const CONTROLS = { left: BAND, right: 0 };
const OPTS = { insets: INSETS, controls: CONTROLS };
const ROOT_T = MANAGER + 0x18;
// HUD events through the dispatcher 0x430610, called between passes, the same in A and B (hud-lib.mjs)
const EVENTS = { 400: 5, 700: 6, 920: 4, 1000: 1, 1100: 2 };
const DETAIL = new Map([[60, 'lights hidden above the top edge'], [200, 'lights sliding in'], [300, 'lights parked, red'], [345, 'lights parked, green'],
  [430, 'Laatste ronde!'], [460, 'lights hidden again'], [705, 'Snelste ronde sliding in'], [790, 'Snelste ronde at the centre'],
  [940, 'Raak!'], [1020, 'PAUZE']]);

// --- what the check expects: the JS port's frames for this shape (not hud-layout.js's arithmetic) -------------
const F = jsFrames(XR, YR, OPTS);
const insetW = { left: IL * 2 * XR, right: IR * 2 * XR, top: IT * 2 * YR, bottom: IB * 2 * YR, band: BAND * 2 * YR };

// --- the races -------------------------------------------------------------------------------------------------
async function newRace(withLayout) {
  const s = await hudRace({ ini: [['race.ini', 'RACETYPEINFO', 'RaceType', TYPE]] });
  s.frames = 0; s.restoreMismatch = 0; s.writes = 0; s.maxWrites = 0;
  if (withLayout) {
    const layout = new HudLayout(s.m);
    s.layout = layout;
    // clip: the worker's sink is the recorder's hudClip; here each captured draw keeps the cut it was asked for
    s.r.host.hudLayout = { layout, xr: XR, yr: YR, scale: 1, insets: INSETS, controls: CONTROLS, clip: (rect) => { s.clip = rect; } };
    const apply = layout.apply.bind(layout);
    layout.apply = (...a) => { apply(...a); s.writes += layout.saved.length / 2; s.maxWrites = Math.max(s.maxWrites, layout.saved.length / 2); };
    // around race.js's own wrapper of the draw: the fields apply may change, before it and after its restore
    const id = s.m.thunkId('hook!eh_004614d0');
    const inner = s.m.thunks[id];
    s.m.thunks[id] = (esp, ecx, edx, eax) => {
      const before = fieldSnapshot(s.m);
      try { return inner(esp, ecx, edx, eax); } finally {
        if (Buffer.compare(before, fieldSnapshot(s.m)) !== 0) s.restoreMismatch++;
        s.frames++;
      }
    };
  }
  s.r.race.boot();
  return s;
}
const A = await newRace(false);
const B = await newRace(true);
const C = await newRace(true);
const m = B.m;
const layout = B.layout;
layout.scan();

out(`# hud-scale-check: recompiled rcskspel.dat, Nederland, RedCat, race type ${TYPE}; screen aspect ${ASPECT.toFixed(4)} (xr ${XR.toFixed(4)}, yr ${YR.toFixed(4)})`);
out(`# apply(xr, yr, ${JSON.stringify(OPTS)}) in race B; insets and band in canvas px of the 4:3 scale: ${Object.entries(insetW).map(([k, v]) => `${k} ${px(v).toFixed(1)}`).join(', ')}`);
out(`# reference: ${JS_LAYOUT} raceHudLayout: ${F.layout.portrait ? 'portrait' : 'landscape'}, scale ${(F.layout.scale * 0.32).toFixed(4)} (k of the HUD), race times ${(F.NUMBERS.k).toFixed(4)}`);
out('# JS-port frames per group, world units: k, b = (bx, by), top left corner (X, Y) from the screen\'s top left');
for (const [g, q] of Object.entries(F)) if (g !== 'layout') out(`#   ${g.padEnd(23)} k ${q.k.toFixed(4)}  b (${q.bx.toFixed(4)}, ${q.by.toFixed(4)})  corner (${q.X.toFixed(4)}, ${q.Y.toFixed(4)})`);
out(`# guest memory ${m.u8.length} bytes; unclassified Screen children: ${layout.unclassified.length ? layout.unclassified.join(', ') : 'none'}`);
out('');

// (1) fields before / applied / restored
const fieldTable = (label, xr, yr, opts) => {
  const f = m.f32;
  const snap = fieldSnapshot(m);
  const before = layout.entries.map((e) => [f[(e.c + 4) >> 2], f[(e.c + 8) >> 2], f[(e.c + 0x10) >> 2], f[(e.c + 0x7c) >> 2]]);
  layout.apply(xr, yr, opts);
  const writes = layout.saved.length / 2;
  const during = layout.entries.map((e) => [f[(e.c + 4) >> 2], f[(e.c + 8) >> 2], f[(e.c + 0x10) >> 2], f[(e.c + 0x7c) >> 2]]);
  layout.restore();
  const same = Buffer.compare(snap, fieldSnapshot(m)) === 0;
  out(`## ${label}: apply(${xr.toFixed(4)}, ${yr.toFixed(4)}${opts ? ', ' + JSON.stringify(opts) : ''}), HUD k ${layout.frames ? (layout.frames.f * 320).toFixed(4) : '-'}, race times k ${layout.frames ? (layout.frames.fT * 320).toFixed(4) : '-'}`);
  out('name                    group         position before      applied              scale +0x10       width +0x7c');
  layout.entries.forEach((e, k) => {
    const [b, d] = [before[k], during[k]];
    const p = (v) => `(${v[0].toFixed(4)}, ${v[1].toFixed(4)})`.padEnd(21);
    out(`${e.name.padEnd(23)} ${e.group.padEnd(13)} ${p(b)}${p(d)}${`${+b[2].toPrecision(4)} -> ${+d[2].toPrecision(4)}`.padEnd(18)}${e.kind === 'element' ? '-' : `${+b[3].toPrecision(4)} -> ${+d[3].toPrecision(4)}`}`);
  });
  out(`${writes} floats written; every field apply may change identical after restore: ${same}`);
  out('');
};
fieldTable('4:3, scale 1, no insets (must write nothing)', 1, 0.75);
fieldTable('4:3, scale 1, no insets, as an options object', 1, 0.75, { scale: 1, insets: { left: 0, right: 0, top: 0, bottom: 0 } });
fieldTable('16:9, no options (as before: 6 floats)', ...Object.values(HudLayout.clipFor(16 / 9)));
fieldTable('9:16, no options (as before: 8 floats)', ...Object.values(HudLayout.clipFor(9 / 16)));
fieldTable('this shape', XR, YR, OPTS);
fieldTable('this shape, with a clip sink (the callbacks +0x30 set and put back)', XR, YR, { ...OPTS, clip: () => {} });

// (2), (3): the races
const bonusObj = tree(m).find((x) => x.name === 'BonusObject')?.c;
let bonusSeen = null;
const captures = new Set();
for (let t = 40; t < TICKS + 80; t += 5) captures.add(t);
const perGroup = new Map();          // group -> { draws, maxErr, sizes:[min,max], moved:[min,max] }
const failures = [];
const detail = [];
const memChecks = [];
const fullRestore = [];
const finishKeys = (s) => {
  // Ctrl+F+I (0x429a90): phase 3 once all three are released; released after 50 polls of Ctrl in the tick
  s.r.ctl.keys = new Set([VK.CONTROL, VK.F, VK.I]);
  let polls = 0;
  s.r.ctl.onPoll = (vk, ctl) => { if (vk === VK.CONTROL && ++polls > 50) ctl.keys.clear(); };
};
const treeIndex = (mm) => new Map(tree(mm).map((x) => [x.c, x]));
const overlaps = new Set();
const cuts = new Map();              // group -> cut counts (see the loop)
const beyond0 = (f, D, span) => f * span > D;   // a box reaches more than D world units past a rect's edge
const hiddenShown = [];
let hiddenChecked = 0;
const rowGaps = [];
const worldDiff = { B: [], C: [] };
const stackLow = A.m.layout.STACK_LOW;
for (let n = 0; n < TICKS + 80; n++) {
  C.m.u8.set(A.m.u8.subarray(stackLow, A.m.esp), stackLow);       // C: the same dead stack as A
  for (const s of [A, B, C]) {
    if (EVENTS[n] !== undefined) s.m.call(EVENT, [EVENTS[n]]);
    s.r.ctl.onPoll = null;
    if (n === TICKS) finishKeys(s);
    else s.r.ctl.keys = new Set(n > 330 && n < TICKS ? [VK.UP] : []);
  }
  if (n === TICKS + 40) DETAIL.set(n, 'finish phase');
  const cap = captures.has(n) || DETAIL.has(n);
  A.draws = cap ? [] : null;
  B.draws = cap ? [] : null;
  for (const s of [A, B, C]) s.world = [];
  A.r.tick();
  B.r.tick();
  C.r.tick();
  for (const [k, s] of [['B', B], ['C', C]]) {
    const d = compareWorld(A.world, s.world, 4);
    if (d.length) worldDiff[k].push({ tick: n, d });
  }
  if (bonusObj && bonusSeen === null && A.m.u8[bonusObj + 0x2c]) {
    bonusSeen = n;
    DETAIL.set(n + 4, 'bonus model in flight'); DETAIL.set(n + 12, 'bonus model landing'); DETAIL.set(n + 50, 'bonus model at rest');
  }
  if (!cap) continue;
  const order = drawOrder(A.m);
  const idx = treeIndex(A.m);
  if (A.draws.length !== order.length || B.draws.length !== order.length) {
    failures.push(`tick ${n}: ${A.draws.length} draws in A, ${B.draws.length} in B, ${order.length} in the tree`);
    continue;
  }
  const rows = [];
  for (let k = 0; k < order.length; k++) {
    const o = { ...order[k], parent: idx.get(order[k].c)?.parent };
    // B's draw as it reaches the screen (a group drawn into its frame, the bonus box, mapped as the renderer maps it)
    const a = A.draws[k], b = rendered(B.draws[k], XR, YR);
    const e = expectation(o, A.m, F, { xr: XR });
    let err = 0, err2d = 0;
    for (let v = 0; v < a.xs.length; v++) {
      const [ex, ey] = e.map(a.xs[v], a.ys[v], a.zs[v]);
      err = Math.max(err, Math.hypot(b.xs[v] - ex, b.ys[v] - ey));
      const [ix, iy] = e.ideal(a.xs[v], a.ys[v]);
      err2d = Math.max(err2d, Math.hypot(b.xs[v] - ix, b.ys[v] - iy));
    }
    const wa = Math.max(a.x1 - a.x0, a.y1 - a.y0), wb = Math.max(b.x1 - b.x0, b.y1 - b.y0);
    const size = wa > 1e-6 ? wb / wa : NaN;
    const move = [b.cx - a.cx, b.cy - a.cy];
    let ecx = 0, ecy = 0;
    for (let v = 0; v < a.xs.length; v++) { const q = e.map(a.xs[v], a.ys[v], a.zs[v]); ecx += q[0] / a.xs.length; ecy += q[1] / a.xs.length; }
    // float32 keeps about 7 digits: a notice zooming past the screen is drawn far outside it
    const mag = Math.max(Math.abs(a.x0), Math.abs(a.x1), Math.abs(a.y0), Math.abs(a.y1), 1);
    const ok = err <= 0.01 / 320 + 2e-6 * mag;
    const g = perGroup.get(o.top) || { draws: 0, maxErr: 0, maxNear: 0, max2d: 0, size: [Infinity, -Infinity], z: [Infinity, -Infinity] };
    g.draws++; g.maxErr = Math.max(g.maxErr, err);
    if (mag <= 4) { g.maxNear = Math.max(g.maxNear, err); g.max2d = Math.max(g.max2d, err2d); }   // within 4 world units of the centre
    g.z = [Math.min(g.z[0], a.z0), Math.max(g.z[1], a.z1)];
    if (!Number.isNaN(size)) g.size = [Math.min(g.size[0], size), Math.max(g.size[1], size)];
    perGroup.set(o.top, g);
    // The cut: B's draw must be cut to the rect the JS port's viewport gives its group's meshes (race-hud-meshes.js:256),
    // and to none for a string (race-hud.js:123); the one exception is the BONUS label, a string drawn with the bonus
    // box into its frame (hud-layout.js GROUPS frame), measured as the meshes. Measured: how much of the draw's box the
    // rect leaves out (on the screen's 4:3 scale, canvas px), what the cut hides of the picture.
    {
      const qj = F[String(o.top).toUpperCase()];
      const jsCut = o.glyph || !qj ? null : qj.rect;
      const same = (p, q) => (p === null && q === null) || (p !== null && q !== null && ['x', 'y', 'w', 'h'].every((k) => Math.abs(p[k] - q[k]) < 1e-9));
      const c = cuts.get(o.top) || { draws: 0, same: 0, framedText: 0, trimmed: 0, hidden: 0, worst: 0, textTrimmed: 0 };
      c.draws++;
      const framedText = o.glyph && b.clip && b.clip.frame && qj && same(b.clip, qj.rect);
      if (same(b.clip, jsCut)) c.same++;
      else if (framedText) c.framedText++;
      else failures.push(`tick ${n}: ${o.name} (${o.top}) cut to ${JSON.stringify(b.clip)}, the JS port's ${JSON.stringify(jsCut)}`);
      const want = framedText ? qj.rect : jsCut;
      if (want) {
        // the box in fractions of the screen from its top left
        const fx0 = (b.x0 + XR) / (2 * XR), fx1 = (b.x1 + XR) / (2 * XR), fy0 = (YR - b.y1) / (2 * YR), fy1 = (YR - b.y0) / (2 * YR);
        const out = Math.max(want.x - fx0, fx1 - (want.x + want.w), 0) * 2 * XR, outY = Math.max(want.y - fy0, fy1 - (want.y + want.h), 0) * 2 * YR;
        const beyond = px(Math.max(out, outY));
        const gone = fx1 <= want.x || fx0 >= want.x + want.w || fy1 <= want.y || fy0 >= want.y + want.h;
        const D = 0.5 / 320;
        if (beyond0(want.x - fx0, D, 2 * XR)) (c.edges ||= new Set()).add('left');
        if (beyond0(fx1 - want.x - want.w, D, 2 * XR)) (c.edges ||= new Set()).add('right');
        if (beyond0(want.y - fy0, D, 2 * YR)) (c.edges ||= new Set()).add('top');
        if (beyond0(fy1 - want.y - want.h, D, 2 * YR)) (c.edges ||= new Set()).add('bottom');
        if (beyond > 0.5) {
          c.trimmed++; if (gone) c.hidden++; c.worst = Math.max(c.worst, beyond);
          if (framedText) { c.textTrimmed++; failures.push(`tick ${n}: ${o.name} (${o.top}) cut by its frame, ${beyond.toFixed(1)} px, where the JS port draws it whole`); }
        }
        // a hidden start light (local y 1.25) must be wholly above its frame, which hides it
        if (o.top === '321Timer' && A.m.f32[(o.c + 8) >> 2] >= LIGHTS_HIDDEN) {
          hiddenChecked++;
          if (!(b.clip && fy1 <= want.y + 1e-9)) hiddenShown.push(`tick ${n}: ${o.name} reaches ${px((fy1 - want.y) * 2 * YR).toFixed(1)} px into its frame`);
        }
      }
      cuts.set(o.top, c);
    }
    if (!ok) failures.push(`tick ${n}: ${o.name} (${o.top}) off by ${px(err).toFixed(3)} px`);
    const last = rows[rows.length - 1];
    if (last && last.name === o.name && o.glyph) { last.n++; last.err = Math.max(last.err, err); continue; }
    rows.push({ name: o.name, top: o.top, n: 1, err, size, esize: e.size, move, emove: [ecx - a.cx, ecy - a.cy], a, note: e.note, ok });
  }
  // Do groups overlap on this screen that did not at 4:3? Bounding boxes of each group's draws in A and in B.
  {
    const boxes = (draws) => {
      const g = new Map();
      draws.forEach((d, k) => {
        if (Math.max(Math.abs(d.x0), Math.abs(d.x1), Math.abs(d.y0), Math.abs(d.y1)) > 4) return;   // off screen
        const b = g.get(order[k].top) || [Infinity, Infinity, -Infinity, -Infinity];
        g.set(order[k].top, [Math.min(b[0], d.x0), Math.min(b[1], d.y0), Math.max(b[2], d.x1), Math.max(b[3], d.y1)]);
      });
      return g;
    };
    // overlap deeper than 2 canvas px either way (the lights sliding in pass over the Stars' place in the original
    // too, and with a top inset they come down up to the inset later than the groups beside them)
    const D = 2 / 320;
    const hit = (p, q) => p && q && p[0] + D < q[2] && q[0] + D < p[2] && p[1] + D < q[3] && q[1] + D < p[3];
    const ba = boxes(A.draws), bb = boxes(B.draws);
    const names = [...bb.keys()];
    for (let i = 0; i < names.length; i++) {
      for (let j = i + 1; j < names.length; j++) {
        if (hit(bb.get(names[i]), bb.get(names[j])) && !hit(ba.get(names[i]), ba.get(names[j]))) {
          overlaps.add(`${names[i]} and ${names[j]} (first at tick ${n})`);
        }
      }
    }
    if (DETAIL.has(n)) {
      const gap = (l, r) => (bb.has(l) && bb.has(r) ? px(bb.get(r)[0] - bb.get(l)[2]).toFixed(1) : '-');
      rowGaps.push(`tick ${n}: Portraits..Stars ${gap('Portraits', 'Stars')} px, Stars..NUMBERS ${gap('Stars', 'NUMBERS')} px, Portraits..321Timer ${gap('Portraits', '321Timer')} px, Portraits..NUMBERS ${gap('Portraits', 'NUMBERS')} px, Bonus..Map ${gap('Bonus', 'Map')} px`);
    }
  }
  if (DETAIL.has(n)) {
    detail.push(`### tick ${n} (${DETAIL.get(n)}), race phase ${A.m.u32[0x53b9c0 >> 2]}: ${order.length} draws`);
    for (const r of rows) {
      detail.push(`  ${r.name.padEnd(22)} x${String(r.n).padEnd(3)} ${String(r.top).padEnd(22)} A at (${canvasX(r.a.cx).toFixed(1).padStart(6)}, ${canvasY(r.a.cy).toFixed(1).padStart(6)}) px  moved (${px(r.move[0]).toFixed(1).padStart(6)}, ${px(-r.move[1]).toFixed(1).padStart(6)}) expected (${px(r.emove[0]).toFixed(1).padStart(6)}, ${px(-r.emove[1]).toFixed(1).padStart(6)})  grew ${Number.isNaN(r.size) ? '  -   ' : r.size.toFixed(4)} expected ${r.esize.toFixed(4)}  off ${px(r.err).toFixed(4)} px${r.note ? '  ' + r.note : ''}${r.ok ? '' : '  <-- differs'}`);
    }
    memChecks.push({ tick: n, ...compareMemory(A.m, B.m), c: compareMemory(A.m, C.m) });
    // apply and restore with no draw between: all of guest memory as it was
    const copy = m.u8.slice();
    layout.apply(XR, YR, { ...OPTS, clip: () => {} });
    const w = layout.saved.length / 2 + layout.savedWords.length / 2;
    layout.restore();
    fullRestore.push({ tick: n, writes: w, same: Buffer.compare(copy, m.u8) === 0 });
  }
}
memChecks.push({ tick: 'end', ...compareMemory(A.m, B.m), c: compareMemory(A.m, C.m) });

out('## HUD draws, A (4:3 HUD) and B (this shape), mean projected vertex in canvas pixels (y down)');
out('moved: B - A; grew: largest side of the bounding box, B / A; off: largest distance of a vertex of B from where');
out('the JS port\'s frame of its group (or an exception, hud-lib.mjs expectation()) puts the same vertex of A (canvas pixels)');
for (const l of detail) out(l);
out('');
out(`## Every 5th pass from 40 to ${TICKS + 75} and the passes above: per group`);
out('group                    draws  depth z          grew (min..max)    largest vertex error: near the screen, anywhere;');
out('                                                                       and near the screen from the flat 2D transform');
for (const [g, v] of perGroup) out(`${String(g).padEnd(24)} ${String(v.draws).padStart(5)}  ${`${v.z[0].toFixed(4)}..${v.z[1].toFixed(4)}`.padEnd(16)} ${v.size[0] === Infinity ? '-'.padEnd(18) : `${v.size[0].toFixed(4)}..${v.size[1].toFixed(4)}`.padEnd(18)} ${px(v.maxNear).toFixed(4)} px, ${px(v.maxErr).toPrecision(4)} px; 2D ${px(v.max2d).toFixed(3)} px`);
out('("near": within 4 world units of the centre: Laatste ronde! leaves by zooming to 10^10 px wide, where float32 keeps');
out('about 7 digits. "2D": against the flat transform of the picture, what the JS port\'s viewport of a group does: parts');
out('off z 1 that are moved in game memory (the stars at 1.001, the arrows at 1.0005) are drawn in perspective, so moving');
out('them is not exactly a move of their picture; the bonus box, with its 3D model at 1.07..1.13 and z up to 3 in');
out('flight, is drawn into its frame by the renderer as the JS port draws it, so its picture is the flat transform)');
out(`draws off by more than 0.01 px (plus 2e-6 of the draw's distance from the centre, for float32): ${failures.length ? failures.length : 'none'}`);
for (const f of failures.slice(0, 40)) out('  ' + f);
out('');
out('## Room: horizontal gaps between neighbouring groups in B (canvas px, - when one is not drawn), and groups whose');
out('boxes overlap by more than 2 px in B but not in A, on any checked pass (B follows the JS port\'s frames, so these');
out('are the JS port\'s own overlaps; the lights pass over the stars\' place while sliding in, also at 4:3)');
for (const l of rowGaps) out(l);
out(`overlapping only in B: ${overlaps.size ? [...overlaps].join('; ') : 'none'}`);
out('');
out('## Cuts: each draw of B against the JS port\'s viewport of its group (meshes) or none (strings)');
out('same: cut to the JS port\'s rect, or both uncut; label in frame: the BONUS label\'s glyphs, drawn into the bonus');
out('box\'s frame (uncut in the JS port: any of them the frame cuts is a failure); trimmed: draws the rect cuts by more');
out('than 0.5 px (wholly hidden of them), largest part cut off (canvas px of the 4:3 scale), the edges where it cuts');
out('group                    draws   same  label in frame  trimmed (hidden)  largest  edges');
for (const [g, c] of cuts) {
  out(`${String(g).padEnd(24)} ${String(c.draws).padStart(5)} ${String(c.same).padStart(6)} ${String(c.framedText).padStart(15)} ${String(c.trimmed).padStart(8)} (${String(c.hidden).padStart(5)})  ${c.worst.toFixed(1).padStart(7)}  ${[...(c.edges || [])].join(' ') || '-'}`);
}
out(`hidden start lights (local y 1.25) reaching into their frame: ${hiddenShown.length ? hiddenShown.slice(0, 8).join('; ') : 'none'} (${hiddenChecked} draws checked)`);
out('');
out('## restore()');
out(`B drew the HUD ${B.frames} times with the layout; ${B.writes} float writes by apply in all, at most ${B.maxWrites} in one frame; frames where a field apply may change differed after restore: ${B.restoreMismatch}`);
out(`apply + restore without a draw between, all ${m.u8.length} bytes of guest memory compared: ${fullRestore.filter((x) => x.same).length} of ${fullRestore.length} identical (${fullRestore.map((x) => `${x.tick}: ${x.writes} writes${x.same ? '' : ' DIFFERS'}`).join(', ')})`);
out('');
out('## Guest memory of A against B and C (same keys, clock, events)');
for (const c of memChecks) {
  out(`tick ${c.tick}: B differing bytes ${JSON.stringify(c.counts)}${c.other.length ? ' other at ' + c.other.join(' ') : ''}`);
  out(`${' '.repeat(String(c.tick).length + 6)}C differing bytes ${JSON.stringify(c.c.counts)}${c.c.other.length ? ' other at ' + c.c.other.join(' ') : ''}`);
}
out('');
out('## Draws outside the HUD, every pass: transforms, vertex words and indices as handed to Direct3D, A against B and C');
for (const k of ['B', 'C']) {
  out(`${k}: ${worldDiff[k].length} of ${TICKS + 80} passes differ${worldDiff[k].length ? ':' : ''}`);
  for (const w of worldDiff[k].slice(0, 12)) {
    out(`  tick ${w.tick}: ` + w.d.map((d) => d.vertex === undefined ? `draw ${d.draw} ${d.what}` : `draw ${d.draw} ${d.what}${d.vertex === null ? ` matrix word ${d.field}` : ` vertex ${d.vertex} word ${d.field}`} A ${d.a.toPrecision(6)} B ${d.b.toPrecision(6)}`).join('; '));
  }
}
out('(DrawPrimitive vtype 2 is D3DLVERTEX: words x, y, z, reserved, color, specular, tu, tv)');
out(`race phase at the end: A ${A.m.u32[0x53b9c0 >> 2]}, B ${B.m.u32[0x53b9c0 >> 2]}, C ${C.m.u32[0x53b9c0 >> 2]}; bonus model first shown at tick ${bonusSeen}`);
const pass = failures.length === 0 && hiddenShown.length === 0 && B.restoreMismatch === 0 && C.restoreMismatch === 0 && fullRestore.every((x) => x.same)
  && memChecks.every((c) => !c.c.counts.other) && worldDiff.C.length === 0;
out(`RESULT: ${pass ? 'pass' : 'FAIL'}`);
mkdirSync(dirname(OUT), { recursive: true });
writeFileSync(OUT, lines.join('\n') + '\n');
if (!pass) process.exitCode = 1;
