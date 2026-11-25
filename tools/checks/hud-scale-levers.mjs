#!/usr/bin/env node
// Which fields of rcskspel.dat's HUD components scale a group's drawn size, by experiment; the groups' extents on
// the 4:3 screen in the three race types and the special notices' widths; and the room they leave on a portrait
// screen in the JS reconstruction's layout, which source/host/hud-layout.js follows (k 4/3, the stars lower).
//   node tools/checks/hud-scale-levers.mjs [--k 1.25] [--out evidence/checks/hud-scale-levers.txt]
// Every measurement draws the HUD once more on the state after a pass (m_Manager.Render 0x4614d0 called directly,
// tools/checks/hud-lib.mjs), with one set of fields multiplied by k and put back afterwards, and compares each
// draw's projected vertices with the same draw at 4:3.
import { writeFileSync, mkdirSync } from 'node:fs';
import { dirname, resolve } from 'node:path';
import { VK, ROOT } from './full-race-gaps-lib.mjs';
import { hudRace, drawHud, tree, childrenOf, MANAGER, EVENT, canvasX, canvasY, px } from './hud-lib.mjs';
import { STARS_DROP } from '../../source/host/hud-layout.js';

const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const K = Number(opt('k', 1.25));
const OUT = resolve(ROOT, opt('out', 'evidence/checks/hud-scale-levers.txt'));
const lines = [];
const out = (s = '') => { lines.push(s); console.log(s); };
const ROOT_T = MANAGER + 0x18;

async function raceAt(type, ticks) {
  const s = await hudRace({ ini: [['race.ini', 'RACETYPEINFO', 'RaceType', type]] });
  s.r.race.boot();
  for (let n = 0; n < ticks; n++) { s.r.ctl.keys = new Set(n > 330 ? [VK.UP] : []); s.r.tick(); }
  return s;
}

/** Multiplies the fields at the given addresses by k around fn, then puts the exact values back. */
function times(m, addrs, k, fn) {
  const saved = addrs.map((a) => m.f32[a >> 2]);
  for (const a of addrs) m.f32[a >> 2] *= k;
  try { return fn(); } finally { addrs.forEach((a, i) => { m.f32[a >> 2] = saved[i]; }); }
}

const strings = (m, c) => {
  const outl = [];
  const walk = (x, self) => {
    const kind = m.u32[x >> 2];
    if (kind === 0x4d28c8 || kind === 0x4d2b98) { outl.push(x); return; }
    if (kind === 0x4d2834) for (const k of childrenOf(m, x)) walk(k, false);
    void self;
  };
  walk(c, true);
  return outl;
};

out(`# hud-scale-levers: recompiled rcskspel.dat, Nederland, RedCat; k = ${K}`);
out('');
out('## What the code does with each field (Ghidra export of rcskspel.dat, original-source/modules/rcskspel.dat)');
out('- composite world transform 0x4589c0 (vtable 0x4d2834 +0x30), p = the parent\'s 12 floats');
out('    position = local +0x04/+0x08 * p.Width/p.Height + p.position, z = local z + p.z');
out('    ScreenWidth = p.ScreenWidth; Width = +0x7c * p.Width; Height = +0x80 * p.Height');
out('    Scale = p.Scale * GetScale() (vtable +0x20 = 0x4583e0: +0x10..+0x18); Rotation = p.Rotation + +0x1c..');
out('- string world transform 0x463bb0 (vtables 0x4d28c8, 0x4d2b98 +0x30): as the composite, except');
out('    Width = +0x7c * p.ScreenWidth (not p.Width); the string SetScale 0x463c90 stores +0x10.. and, through');
out('    0x458be0, +0x7c = Scale.x, so a string\'s glyph advance follows its own scale and the root\'s ScreenWidth only');
out('- element draw 0x459440 (vtable 0x4d2890 +0): render object (table 0x6a5c38, stride 0xa9)');
out('    +0x50/+0x54 = local * p.Width/p.Height + p.position; +0x58 = local z + p.z + 1;');
out('    +0x80.. = this +0x10.. (0x4583e0, called directly) * p.Scale; +0x74.. = rotation + p.Rotation');
out('    element SetScale 0x459910 keeps the raw value at +0x44 (GetScale 0x459980) and raw * 0x544ab0 at +0x10');
out('- glyphs are elements under their string: glyph position = glyph local * string Width/Height + string position');
out('So a group (direct child of Screen) grows uniformly about its own origin by: its +0x10/+0x14 (sizes of every');
out('mesh and glyph below it), its +0x7c/+0x80 (places of its children), and +0x7c of every string below it (glyph');
out('advance, which does not follow the parent\'s Width). Scale z and every z stay: all HUD vertices are at z 1');
out('(projected z column below), so this is an exact 2D similarity of the drawing.');
out('');

// --- (1) extents on the 4:3 screen ----------------------------------------------------------------------------
const extents = {};
out('## Group extents on the 4:3 screen (canvas pixels of 640x480, y down): the start lights parked at tick 345, every');
out('other group as far as it reaches on every 10th pass of a race to the finish (ticks 40..1700, throttle held from');
out('331; the portraits change places and the leader\'s grows); without the bonus model, which flies in from the kart');
out('type  group                    x0      x1      y0      y1     z range        draws');
for (const type of [0, 1, 2]) {
  const s = await raceAt(type, 40);
  const g = {};
  for (let n = 40; n <= 1700; n++) {
    s.r.ctl.keys = new Set(n > 330 ? [VK.UP] : []);
    s.r.tick();
    if (n % 10 && n !== 345) continue;
    for (const d of drawHud(s)) {
      if (d.top === 'STRING_SPECIAL' || d.name === 'BonusObject') continue;
      if ((d.top === '321Timer') !== (n === 345)) continue;
      if (Math.max(Math.abs(d.x0), Math.abs(d.x1), Math.abs(d.y0), Math.abs(d.y1)) > 4) continue;
      const b = (g[d.top] ||= { x0: Infinity, x1: -Infinity, y0: Infinity, y1: -Infinity, z0: Infinity, z1: -Infinity, n: 0 });
      b.x0 = Math.min(b.x0, canvasX(d.x0)); b.x1 = Math.max(b.x1, canvasX(d.x1));
      b.y0 = Math.min(b.y0, canvasY(d.y1)); b.y1 = Math.max(b.y1, canvasY(d.y0));
      b.z0 = Math.min(b.z0, d.z0); b.z1 = Math.max(b.z1, d.z1); b.n++;
    }
  }
  for (const [name, b] of Object.entries(g)) {
    const e = extents[name];
    extents[name] = e ? { x0: Math.min(e.x0, b.x0), x1: Math.max(e.x1, b.x1), y0: Math.min(e.y0, b.y0), y1: Math.max(e.y1, b.y1) } : b;
    out(`${String(type).padEnd(5)} ${name.padEnd(24)} ${b.x0.toFixed(1).padStart(6)}  ${b.x1.toFixed(1).padStart(6)}  ${b.y0.toFixed(1).padStart(6)}  ${b.y1.toFixed(1).padStart(6)}   ${b.z0.toFixed(4)}..${b.z1.toFixed(4)}  ${b.n}`);
  }
}
out('(type 0 Landenrace, 1 Tijdrace, 2 Sterrenrace: race.ini [RACETYPEINFO] RaceType)');
out('');

// --- (2) the notices ------------------------------------------------------------------------------------------
out('## STRING_SPECIAL notices (dispatcher 0x430610): the width each holds on the 4:3 screen (its most common width');
out('while shown; the zoom style ends by growing past the screen, the slide by leaving it)');
const notices = [[5, 'Laatste ronde! (style 4, zoom)'], [6, 'Snelste ronde (style 5, slide)'], [4, 'Raak! (style 1)'],
  [3, 'Superbonus! (no caller)'], [10, 'Alle voorwerpen verzameld! (no caller)'], [11, 'Controlepunt! (no shipped marker)'],
  [1, 'PAUZE (style 0)']];
{
  const s = await raceAt(0, 360);
  const special = tree(s.m).find((x) => x.name === 'STRING_SPECIAL').c;
  for (const [id, label] of notices) {
    s.m.call(EVENT, [id]);
    let maxW = 0, shown = 0, minX = Infinity, maxX = -Infinity;
    const widths = new Map();
    for (let n = 0; n < 220; n++) {
      s.r.ctl.keys = new Set([VK.UP]);
      s.r.tick();
      const d = drawHud(s).filter((x) => x.top === 'STRING_SPECIAL');
      if (!d.length) continue;
      shown++;
      const x0 = Math.min(...d.map((x) => canvasX(x.x0))), x1 = Math.max(...d.map((x) => canvasX(x.x1)));
      maxW = Math.max(maxW, x1 - x0);
      minX = Math.min(minX, x0); maxX = Math.max(maxX, x1);
      const key = (x1 - x0).toFixed(1);
      widths.set(key, (widths.get(key) || 0) + 1);
    }
    void special;
    if (id === 1) s.m.call(EVENT, [2]);
    for (let n = 0; n < 10; n++) s.r.tick();
    const [restW, passes] = [...widths.entries()].sort((a, b) => b[1] - a[1])[0];
    out(`  ${String(id).padStart(2)} ${label.padEnd(40)} shown ${String(shown).padStart(3)} passes, ${restW.padStart(6)} px wide in ${String(passes).padStart(3)} of them; widest ${maxW.toPrecision(4)} px, x seen ${minX.toPrecision(4)}..${maxX.toPrecision(4)}`);
    extents['notice ' + id] = { w: Number(restW) };
  }
}
out('');

// --- (3) the levers -------------------------------------------------------------------------------------------
out(`## Levers: each group with one set of fields times k = ${K}, against uniform growth about the group's origin`);
out('size: bounding box of each draw, B / A (min..max over the group\'s draws); off: largest distance of a vertex of');
out('B from O + k (vertex of A - O), O the group\'s world origin, in canvas pixels; advance: distance between glyph');
out('neighbours of one string, B / A');
const s = await raceAt(0, 345);
const m = s.m;
s.m.call(EVENT, [5]);
for (let n = 0; n < 50; n++) { s.r.ctl.keys = new Set([VK.UP]); s.r.tick(); }   // Laatste ronde! at rest, scale 2
const base = drawHud(s);
const rootW = m.f32[(ROOT_T + 0x10) >> 2], rootH = m.f32[(ROOT_T + 0x14) >> 2];
const levers = (c, kind) => {
  const isString = kind.endsWith('string');
  const own = isString ? [c + 0x7c] : [];
  return [
    ['+0x10/+0x14 scale', [c + 0x10, c + 0x14]],
    ['+0x7c/+0x80 width/height', kind === 'element' ? [] : [c + 0x7c, c + 0x80]],
    ['+0x7c of the strings below', isString ? own : strings(m, c).map((x) => x + 0x7c)],
    ['all three', [c + 0x10, c + 0x14, ...(kind === 'element' ? [] : [c + 0x7c, c + 0x80]), ...(isString ? [] : strings(m, c).map((x) => x + 0x7c))]],
    ['root ScreenWidth (+0x18+0x0c)', [ROOT_T + 0x0c]],
  ];
};
const groupsShown = [...new Set(base.map((d) => d.top))];
out('group                    lever                           size x          size y          off px   advance');
for (const name of groupsShown) {
  const g = tree(m).find((x) => x.depth === 1 && x.name === name);
  const O = [m.f32[(g.c + 4) >> 2] * rootW + m.f32[(ROOT_T) >> 2], m.f32[(g.c + 8) >> 2] * rootH + m.f32[(ROOT_T + 4) >> 2]];
  for (const [label, addrs] of levers(g.c, g.kind)) {
    if (!addrs.length) { out(`${name.padEnd(24)} ${label.padEnd(31)} (none)`); continue; }
    const after = times(m, addrs, K, () => drawHud(s));
    let sx = [Infinity, -Infinity], sy = [Infinity, -Infinity], off = 0, adv = [Infinity, -Infinity];
    for (let k = 0; k < base.length; k++) {
      const a = base[k], b = after[k];
      if (a.top !== name) continue;
      const wa = a.x1 - a.x0, ha = a.y1 - a.y0;
      if (wa > 1e-4) { const r = (b.x1 - b.x0) / wa; sx = [Math.min(sx[0], r), Math.max(sx[1], r)]; }
      if (ha > 1e-4) { const r = (b.y1 - b.y0) / ha; sy = [Math.min(sy[0], r), Math.max(sy[1], r)]; }
      for (let v = 0; v < a.xs.length; v++) {
        const ex = O[0] + K * (a.xs[v] - O[0]), ey = O[1] + K * (a.ys[v] - O[1]);
        off = Math.max(off, Math.hypot(b.xs[v] - ex, b.ys[v] - ey));
      }
      const pa = base[k - 1], pb = after[k - 1];
      if (a.glyph && pa && pa.c === a.c) {
        const da = Math.hypot(a.cx - pa.cx, a.cy - pa.cy), db = Math.hypot(b.cx - pb.cx, b.cy - pb.cy);
        if (da > 1e-4) adv = [Math.min(adv[0], db / da), Math.max(adv[1], db / da)];
      }
    }
    const f = (r) => (r[0] === Infinity ? '-' : r[0].toFixed(4) === r[1].toFixed(4) ? r[0].toFixed(4) : `${r[0].toFixed(3)}..${r[1].toFixed(3)}`).padEnd(15);
    out(`${name.padEnd(24)} ${label.padEnd(31)} ${f(sx)} ${f(sy)} ${px(off).toFixed(2).padStart(7)}   ${adv[0] === Infinity ? '-' : f(adv).trim()}`);
  }
}
out('');

// --- (4) room on a portrait screen ----------------------------------------------------------------------------
// The JS reconstruction's layout of an upright screen without insets (race-hud-layout.js:9, 22-24): the HUD at k =
// 4/3 (480 of its 640 pixels across the width), Portraits and Stars from the left edge, NUMBERS from the right, the
// Stars 110 pixels lower, the lights and the arrows in the middle of the height. Canvas px of a 640 px wide screen.
const E = extents;
const W = 640;
const KP = 4 / 3;
const room = [];
const limit = (label, s) => room.push([label, s]);
limit('Portraits (right edge) and NUMBERS (left edge) side by side', W / (E.Portraits.x1 + (W - E.NUMBERS.x0)));
limit('Tijdrace time (top centre) right of Portraits', 320 / (E.Portraits.x1 + (320 - E.STRING_COUNTDOWN_VALUE.x0)));
limit('Portraits and Stars side by side (both from the left edge)', E.Stars.x0 > E.Portraits.x1 ? Infinity : 0);
limit('Bonus (bottom left) and Map (bottom right)', W / (E.Bonus.x1 + (W - E.Map.x0)));
limit('Laatste ronde! (widest reachable notice) inside the width', W / E['notice 5'].w);
out('## Room on a portrait screen (no side insets): the largest k at which each pair just touches; the layout uses 4/3');
for (const [label, v] of room) out(`  ${label.padEnd(62)} k <= ${v === Infinity ? 'any' : v.toFixed(3)}${v >= KP ? '' : '  <-- short'}`);
// Stars and NUMBERS share the top rows at 4:3; in portrait they overlap sideways (Stars to x Stars.x1 k from the left,
// NUMBERS from 640 - (640 - NUMBERS.x0) k), so the 110 pixels down must clear the race times
const side = E.Stars.x1 * KP - (W - (W - E.NUMBERS.x0) * KP);
const below = (E.Stars.y0 + STARS_DROP - E.NUMBERS.y1) * KP;
out(`  Sterrenrace at k 4/3: Stars and NUMBERS overlap sideways by ${side.toFixed(1)} px; Stars, ${STARS_DROP} px lower, start ${below.toFixed(1)} px below NUMBERS' last row`);
mkdirSync(dirname(OUT), { recursive: true });
writeFileSync(OUT, lines.join('\n') + '\n');
