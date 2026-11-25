#!/usr/bin/env node
// Schaduwen op het wegdek and Motorlicht volgt de kart (source/host/shadows.js) on the worker page in headless Chromium
// at 16:9 (960x540). Pictures and results in evidence/frames/visuals/.
//
// A picture pair compares two runs of the same race (?fixed: a fixed clock, the same input from before the first
// pass), one with a setting and one without, each frozen at the same pass (CTRL.PAUSED set as the pass count reaches
// it; the render worker keeps showing it, ?blendat=0: the older pass of the last two). The game is the same in both
// (tools/checks/shadows.mjs: game memory identical on and off), so every pixel that differs is the setting's.
//   standstill  Frankrijk's start, where the original quad lies under the road (the JS reconstruction's France start:
//               3143 darker pixels with the setting, none without, its docs/research-kart-shadows.md), and Nederland's,
//               where the original's quad partly shows: no gas, frozen at pass 80 (Frankrijk: the start camera beside the
//               player, the shadow in full) and at pass 260 (behind the player, the lights at red: the grid spans the
//               drawn kart03 body's box, so it shows around the karts; the original's redcar-sized quad lies under them)
//   driving     Nederland, gas held from before the start, frozen at pass 400 (at speed, before the dolmen): the shadows and the engine lights on, the
//               shadows off (?noshadows), the engine lights off (?nolights; the JS reconstruction's
//               evidence/engine-lights/alpha-0-*.png show the same moment of its own); render stats of each run
//   live        Nederland driving: render stats with both on, both switched off live (runner.applySettings, as the menu's
//               OK does), on again
//   turbo       the same race: the random-bonus cheat (Ctrl+Enter+Space) and the bonus key until the player is faster
//               than without a turbo, then pictures with the engine light on and off and the render stats; every
//               follower the renderer cuts loose meanwhile is logged from the render worker (owner, how far it moved),
//               and none may come from an owner that moved 30 units or less
//   js          (only when asked for, and with the JS reconstruction's read-only server on 4173:
//               tools/checks/menu/serve-js-readonly.mjs) its own France race (?drive=3, RedCat) with the player waiting
//               at the line under the chase camera, Schaduwen op het wegdek on and off, beside the recomp's the same
//               (frozen at pass RCSK_JS_PASS, default 700): js-fra-start-*.png, fra-chase-*.png and js-vs-recomp-fra.png
//               (JS on, JS off, recomp on, recomp off; the player cut out). The darkened pixels around the player are
//               counted in both and their overlap measured (the same footprint: kart03.d3d's box)
// Needs the dev server (tools/serve.mjs, 4190) and Playwright (see tools/shot.mjs).
//   node tools/check-visuals.mjs [standstill,driving,live,turbo,js]
import { mkdirSync, writeFileSync, readFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const out = join(ROOT, 'evidence', 'frames', 'visuals');
mkdirSync(out, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
const URL_ = process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html';
const only = process.argv[2] ? process.argv[2].split(',') : null;
const want = (name) => !only || only.includes(name);
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const VIEW = { width: 960, height: 540 };
const results = {};
const fails = [];
const check = (ok, what) => { if (!ok) fails.push(what); console.log((ok ? 'ok   ' : 'FAIL ') + what); return ok; };

/** A page of the dev race; page errors and console errors are collected (a missing resource's 404 is only noted). */
async function open(query, { gas = false } = {}) {
  const page = await browser.newPage({ viewport: VIEW, deviceScaleFactor: 1 });
  page.errors = []; page.notes = [];
  page.on('pageerror', (e) => page.errors.push(e.message));
  page.on('console', (m) => { if (m.type() === 'error') (/Failed to load resource.*404/.test(m.text()) ? page.notes : page.errors).push(m.text()); });
  await page.goto(URL_ + '?fixed&stats&blendat=0' + query);
  if (gas) await page.keyboard.down('ArrowUp');         // before the first pass, so both runs drive the same
  await page.waitForFunction(() => window.gameStats.ticks >= 1, null, { timeout: 240000 });
  return page;
}
const untilTick = (page, n) => page.waitForFunction((n) => window.gameStats.ticks >= n, n, { timeout: 240000 });
/**
 * Every follower the renderer cuts loose, logged in the render worker: its pairFollowers (gl-renderer.js) wrapped
 * through the worker's own module (a dynamic import of the URL it imported, so the same class). Per snap: the owner's
 * tag id (engine slot + 1), whether the owner has a kart shadow in that pass (a racer), how far the owner moved since the
 * pass before, the vertex counts, and the worker's time. A follower's group key holds its vertex count
 * (gl-renderer.js drawInfo), so a pair always has the same count and a snap means the owner moved more than TELEPORT.
 */
async function logSnaps(page) {
  const w = page.workers().find((x) => /render-worker\.js/.test(x.url()));
  if (!w) return false;
  return w.evaluate(async () => {
    const { GLRenderer } = await import(new URL('../render/gl-renderer.js', self.location.href).href);
    if (GLRenderer.prototype.__snapLog) return true;
    const pair = GLRenderer.prototype.pairFollowers;
    self.__snaps = [];
    GLRenderer.prototype.pairFollowers = function (groups, followers) {
      pair.call(this, groups, followers);
      const racers = new Set(followers.filter((d) => d.decal).map((d) => d.key.split(':').pop()));
      for (const d of followers) {
        if (!d.partner || d.vertexBlend) continue;
        const e = d.partner, id = d.key.split(':').pop();
        self.__snaps.push({ t: performance.now(), id: +id, racer: racers.has(id), decal: d.decal, moved: +Math.hypot(d.ox - e.ox, d.oy - e.oy, d.oz - e.oz).toFixed(1), nverts: [e.nverts, d.nverts] });
      }
    };
    GLRenderer.prototype.__snapLog = true;
    return true;
  });
}
/** The render worker's clock (a mark), and the snaps since a mark with their time after it in ms. */
const workerNow = async (page) => { const w = page.workers().find((x) => /render-worker\.js/.test(x.url())); return w ? w.evaluate(() => performance.now()) : null; };
const snapsSince = async (page, mark) => {
  const w = page.workers().find((x) => /render-worker\.js/.test(x.url()));
  return w && mark !== null ? w.evaluate((mark) => (self.__snaps || []).filter((s) => s.t >= mark).map(({ t, ...s }) => ({ ms: Math.round(t - mark), ...s })), mark) : null;
};
/** Stops the game thread after pass n (CTRL.PAUSED = 2, CTRL.TICKS = 3, source/web/shared.js): the page waits for the
 * pass count in a loop of its own, so the worker, which sleeps about 25 ms before its next pass, never starts it. */
async function freezeAt(page, n) {
  await page.waitForFunction((n) => window.gameStats.ticks >= n - 20, n, { timeout: 240000 });
  const at = await page.evaluate((n) => {
    const ctrl = window.runner.ctrl, t0 = performance.now();
    while (Atomics.load(ctrl, 3) < n && performance.now() - t0 < 5000) { /* the pass count, from the game thread */ }
    Atomics.store(ctrl, 2, 1);
    return Atomics.load(ctrl, 3);
  }, n);
  await wait(700);            // the render worker shows the frozen passes
  return at;
}
const shot = (page, name) => page.locator('#game').screenshot({ path: join(out, name + '.png') });
/** Both settings for the running race, as the menu's OK hands them over (main.js storeSettings -> applySettings). */
const setVisuals = (page, surfaceShadows, smoothEngineLights) => page.evaluate(([a, b]) => { window.runner.applySettings({ ...window.runner.settings, surfaceShadows: a, smoothEngineLights: b }); }, [surfaceShadows, smoothEngineLights]);
/** Render stats summed over n whole seconds (render-worker.js rstats, posted once a second). */
async function rstats(page, n = 3) {
  const sum = { decals: 0, followed: 0, followSnapped: 0, held: 0, paired: 0, unpaired: 0, framesPerSec: 0 };
  await page.evaluate(() => new Promise((r) => { const t = window.renderStats; const f = () => (window.renderStats !== t ? r() : setTimeout(f, 20)); f(); }));
  for (let k = 0; k < n; k++) {
    const r = await page.evaluate(() => new Promise((res) => { const t = window.renderStats; const f = () => (window.renderStats !== t ? res(window.renderStats) : setTimeout(f, 20)); f(); }));
    for (const key of Object.keys(sum)) sum[key] += r[key] || 0;
  }
  return sum;
}
/** Pixels darker (all three channels at least 16 lower) and lighter in a than in b, inside box (default: all). */
async function compare(a, b, box = { x: 0, y: 0, w: VIEW.width, h: VIEW.height }) {
  const page = await browser.newPage();
  const r = await page.evaluate(async ([a, b, box]) => {
    const load = async (s) => { const bm = await createImageBitmap(await (await fetch('data:image/png;base64,' + s)).blob()); const c = new OffscreenCanvas(bm.width, bm.height); const g = c.getContext('2d'); g.drawImage(bm, 0, 0); return g.getImageData(0, 0, bm.width, bm.height); };
    const A = await load(a), B = await load(b);
    let dark = 0, light = 0, other = 0, ratio = 0;
    for (let y = box.y; y < box.y + box.h; y++) for (let x = box.x; x < box.x + box.w; x++) {
      const p = (y * A.width + x) * 4;
      const d = [0, 1, 2].map((c) => A.data[p + c] - B.data[p + c]);
      if (d.every((v) => v <= -16)) { dark++; ratio += (A.data[p] + A.data[p + 1] + A.data[p + 2]) / Math.max(1, B.data[p] + B.data[p + 1] + B.data[p + 2]); }
      else if (d.every((v) => v >= 16)) light++;
      else if (d.some((v) => Math.abs(v) >= 16)) other++;
    }
    return { dark, light, other, darkRatio: dark ? +(ratio / dark).toFixed(3) : null };
  }, [a.toString('base64'), b.toString('base64'), box]);
  await page.close();
  return r;
}
const noErrors = (page, what) => check(page.errors.length === 0, `${what}: no page errors${page.errors.length ? ' (' + page.errors.join(' | ') + ')' : ''}${page.notes.length ? ` (${page.notes.length} missing resources)` : ''}`);

/** One run frozen at pass n: its picture and the render stats of the seconds before. */
async function frozen(query, n, name, opts = {}) {
  const page = await open(query, opts);
  let stats = null;
  if (n > 200) { await untilTick(page, n - 140); stats = await rstats(page, 2); }
  const at = await freezeAt(page, n);
  // (the development page's status line shows the pass count of the moment, which differs between the runs)
  await page.addStyleTag({ content: '#status { visibility: hidden !important; }' });
  const png = await shot(page, name);
  noErrors(page, name);
  await page.close();
  return { png, stats, at };
}

// --- standstill: the start of Frankrijk and Nederland ---------------------------------------------------------------
if (want('standstill')) {
  for (const [etappe, track, n] of [[3, 'fra', 80], [3, 'fra', 260], [0, 'ned', 260]]) {
    const on = await frozen(`&etappe=${etappe}`, n, `${track}-standstill-${n}-on`);
    const off = await frozen(`&etappe=${etappe}&noshadows`, n, `${track}-standstill-${n}-off`);
    const d = await compare(on.png, off.png);
    results[`${track}Standstill${n}`] = { frozenAt: [on.at, off.at], onVsOff: d, statsOn: on.stats, statsOff: off.stats };
    console.log(track, 'standstill', n, JSON.stringify(results[`${track}Standstill${n}`]));
    check(on.at === n && off.at === n, `${track} standstill ${n}: both runs frozen at pass ${n} (${on.at}, ${off.at})`);
    if (on.stats) check(on.stats.decals > 0 && off.stats.decals === 0, `${track} standstill: ${on.stats.decals} surface shadows in 2 s with the setting, ${off.stats.decals} without`);
    if (track === 'fra') check(d.dark > 50 && d.light === 0, `fra standstill ${n}: the surface shadows darken ${d.dark} pixels (to ${d.darkRatio} of their brightness), ${d.light} lighter, ${d.other} otherwise changed; the original quads lie under the road`);
    else check(d.dark > 50, `ned standstill ${n}: the surface shadows darken ${d.dark} pixels (to ${d.darkRatio}), ${d.light} are lighter where the original quads lay elsewhere, ${d.other} otherwise changed`);
  }
}

// --- driving: Nederland with gas from the start, frozen at the same pass ---------------------------------------------
if (want('driving')) {
  const n = 400;
  const runs = {};
  for (const [q, name] of [['', 'on'], ['&noshadows', 'noshadows'], ['&nolights', 'nolights']]) runs[name] = await frozen('&etappe=0' + q, n, 'ned-driving-' + name, { gas: true });
  const shadows = await compare(runs.on.png, runs.noshadows.png), lights = await compare(runs.on.png, runs.nolights.png);
  results.driving = { frozenAt: Object.fromEntries(Object.entries(runs).map(([k, v]) => [k, v.at])), stats: Object.fromEntries(Object.entries(runs).map(([k, v]) => [k, v.stats])), shadowsVsNoshadows: shadows, onVsNolights: lights };
  console.log('driving', JSON.stringify(results.driving));
  const { on, noshadows, nolights } = runs;
  check(on.stats.decals > 0 && on.stats.followed > 0 && on.stats.held === 0 && on.stats.followSnapped === 0, `driving on: ${on.stats.decals} surface shadows, ${on.stats.followed} draws paired with their kart's, ${on.stats.followSnapped} cut loose, ${on.stats.held} held (2 s)`);
  check(noshadows.stats.decals === 0 && noshadows.stats.held === 0, `driving ?noshadows: ${noshadows.stats.decals} surface shadows, ${noshadows.stats.held} held`);
  check(nolights.stats.decals > 0 && nolights.stats.held > 0, `driving ?nolights: ${nolights.stats.decals} surface shadows, ${nolights.stats.held} flares held at the newer pass`);
  check(shadows.dark > 0, `driving: the surface shadows against the original quads: ${shadows.dark} darker, ${shadows.light} lighter, ${shadows.other} otherwise changed`);
  check(lights.dark + lights.light + lights.other > 0 && lights.dark + lights.light + lights.other < 20000, `driving: the engine lights following against held: ${lights.dark + lights.light + lights.other} pixels differ (the flares only)`);
}

// --- live: both settings switched during a race, and back -------------------------------------------------------------
if (want('live') || want('turbo')) {
  const page = await open('&etappe=0', { gas: true });
  const snapLog = await logSnaps(page);
  await untilTick(page, 420);
  const on = await rstats(page, 2);
  await setVisuals(page, false, false);
  const off = await rstats(page, 2);
  await shot(page, 'ned-live-off');
  await setVisuals(page, true, true);
  const again = await rstats(page, 2);
  await shot(page, 'ned-live-on-again');
  results.live = { on, off, again };
  console.log('live', JSON.stringify(results.live));
  // (a window of the render stats can straddle the switch: the first after it may still count the passes before)
  check(on.decals > 0 && on.held === 0, `live, on: ${on.decals} surface shadows, ${on.held} held`);
  check(off.decals < on.decals / 4 && off.held > 0, `live, both switched off: ${off.decals} surface shadows, ${off.held} flares held, ${off.followed} paired with their kart's (the original quads)`);
  check(again.decals > on.decals / 2 && again.held < off.held / 2, `live, switched on again: ${again.decals} surface shadows, ${again.held} held`);
  if (want('turbo')) {
    // a turbo: random bonuses (Ctrl+Enter+Space, the cheat of 0x429a90; the development page keeps the cheat keys) fired
    // with the bonus key until the speed is up
    const kmh = () => page.evaluate(() => window.gameStats.kmh);
    const base = await kmh();
    const mark = snapLog ? await workerNow(page) : null;
    let best = base, tries = 0;
    // (rand() % 7 picks the bonus, 0x40c790; a turbo is type 5, native-bonus.js:14: 15 tries found none in about one run
    // in ten, 30 in about one in a hundred)
    for (; tries < 30 && best <= base + 15; tries++) {
      await page.keyboard.down('ControlLeft'); await page.keyboard.down('Enter'); await page.keyboard.down('Space');
      await wait(150);
      await page.keyboard.up('Space'); await page.keyboard.up('Enter'); await page.keyboard.up('ControlLeft');
      await wait(300);
      await page.keyboard.down('ControlLeft'); await wait(150); await page.keyboard.up('ControlLeft');
      for (let k = 0; k < 8 && best <= base + 15; k++) { await wait(150); best = Math.max(best, await kmh()); }
    }
    const turbo = best > base + 15;
    const r = { tries, kmhBefore: base, best };
    if (turbo) {
      await shot(page, 'ned-turbo-on');
      r.on = { kmh: await kmh(), stats: await page.evaluate(() => window.renderStats), snaps: await snapsSince(page, mark) };
      await setVisuals(page, true, false);
      await wait(200);
      await shot(page, 'ned-turbo-lights-off');
      r.lightsOff = { kmh: await kmh(), stats: await rstats(page, 1) };
      await setVisuals(page, true, true);
    }
    results.turbo = r;
    console.log('turbo', JSON.stringify(r));
    check(turbo, `turbo: ${best} km/h after ${tries} random bonuses (${base} without)`);
    // A follower is cut loose only when its owner moved more than TELEPORT (30 units) in a pass (its group key holds the
    // vertex count): the renderer's rule for the kart itself too (blendMatrix), which tools/checks/shadows.mjs g allows.
    // Measured with the log (2026-11-25, two runs, 4 and 20 snaps): all are karts' shadows and flares (slots 346, 347
    // and 349), 22 of them in the two passes after a random-bonus cheat (156 ms after each try's start, the tries 1.81 s
    // apart). The cheat waits inside its pass until Ctrl, Enter and Space are let go (0x429a90 at 0x42f668,
    // functions/00429a90 lines 148-155); held 150 ms here, that live pass's frame time comes out at 0.1 s (0x48f4e0's
    // cap), so the karts move up to four passes' way (49.6 units, then 30.7). The other two, one kart's shadow and flare,
    // moved 598 units (inferred: a rescue). Inferred, not logged then: the regression suite's failures (4 and 2 cut
    // loose) were such passes inside the stats' second before the turbo.
    // Each snap is logged; the check holds that none came from an owner that moved 30 units or less, from the first
    // bonus to the stats (with the log; without it, from the count alone, as before).
    if (turbo) {
      const snaps = r.on.snaps;
      if (snaps) for (const sn of snaps) console.log('  snap', JSON.stringify(sn));
      const near = snaps ? snaps.filter((sn) => sn.moved <= 30).length : r.on.stats.followSnapped;
      check(near === 0, `turbo: ${r.on.stats.followed} draws paired with their owner's in the last second, ${r.on.stats.followSnapped} cut loose; since the first bonus ${snaps ? snaps.length : '?'} cut loose, ${near} of them while the owner moved <= 30`
        + (snaps ? ` (${snaps.filter((sn) => sn.racer).length} of a racer, owners ${[...new Set(snaps.map((sn) => sn.id))].join(',') || '-'}, moved ${snaps.map((sn) => sn.moved).join(',') || '-'})` : ', no snap log'));
    }
  }
  noErrors(page, 'live');
  await page.keyboard.up('ArrowUp');
  await page.close();
}

// --- js: the JS reconstruction's France start beside the recomp's, from the chase camera ---------------------------
if (only && only.includes('js')) {
  const JS = process.env.RCSK_JS_URL || 'http://127.0.0.1:4173/';
  const P = Number(process.env.RCSK_JS_PASS || 700);
  const shots = { js: {}, recomp: {} };
  for (const on of [true, false]) {
    const page = await browser.newPage({ viewport: VIEW, deviceScaleFactor: 1 });
    await page.goto(JS + '?skipIntro');
    await page.evaluate((on) => localStorage.setItem('rcsk.settings.v1', JSON.stringify({ surfaceShadows: on, smoothEngineLights: true })), on);
    await page.goto(JS + '?drive=3');
    // its race starts at once and runs in real time: the others are gone and the player (RedCat, its default
    // character) waits at the line
    await wait(Number(process.env.RCSK_JS_WAIT || 12000));
    shots.js[on] = await page.screenshot({ path: join(out, `js-fra-start-${on ? 'on' : 'off'}.png`) });
    await page.close();
    // the recomp's France race with RedCat (car=0), no gas, frozen at pass P: the lights are done, the others gone and
    // the player waits at the line under the chase camera
    shots.recomp[on] = (await frozen(`&etappe=3&car=0${on ? '' : '&noshadows'}`, P, `fra-chase-${P}-${on ? 'on' : 'off'}`)).png;
  }
  const box = { x: 330, y: 280, w: 300, h: 190 };
  const jsD = await compare(shots.js[true], shots.js[false], box), recompD = await compare(shots.recomp[true], shots.recomp[false], box);
  // where the two ports darken. The karts differ a little (the JS reconstruction's rear wheels are the narrow
  // wielv.d3d, the original's the wide wiela.d3d), so the footprints are compared where both pictures without the
  // setting show the same thing (every channel within 24: the road); the other pixels the JS reconstruction darkens
  // and the recomp leaves as they are are counted as covered by the recomp's kart
  const page = await browser.newPage();
  const both = await page.evaluate(async ([list, box]) => {
    const load = async (s) => { const bm = await createImageBitmap(await (await fetch('data:image/png;base64,' + s)).blob()); const c = new OffscreenCanvas(bm.width, bm.height); const g = c.getContext('2d'); g.drawImage(bm, 0, 0); return g.getImageData(0, 0, bm.width, bm.height); };
    const [jOn, jOff, rOn, rOff] = await Promise.all(list.map(load));
    const dark = (A, B, p) => [0, 1, 2].every((c) => A.data[p + c] - B.data[p + c] <= -16);
    const near = (A, B, p, d) => [0, 1, 2].every((c) => Math.abs(A.data[p + c] - B.data[p + c]) < d);
    const r = { inBoth: 0, inEither: 0, sameBackground: 0, js: 0, recomp: 0, both: 0, either: 0, coveredInRecomp: 0 };
    for (let y = box.y; y < box.y + box.h; y++) for (let x = box.x; x < box.x + box.w; x++) {
      const p = (y * jOn.width + x) * 4, a = dark(jOn, jOff, p), b = dark(rOn, rOff, p);
      if (a && b) r.inBoth++;
      if (a || b) r.inEither++;
      if (near(jOff, rOff, p, 24)) {
        r.sameBackground++;
        if (a) r.js++;
        if (b) r.recomp++;
        if (a && b) r.both++;
        if (a || b) r.either++;
      } else if (a && !b && near(rOn, rOff, p, 16)) r.coveredInRecomp++;
    }
    r.iou = r.either ? +(r.both / r.either).toFixed(3) : null;
    return r;
  }, [[shots.js[true], shots.js[false], shots.recomp[true], shots.recomp[false]].map((b) => b.toString('base64')), box]);
  // the four side by side: the JS reconstruction on and off, the recomp on and off (the kart cut out)
  const png = await page.evaluate(async ([list, box]) => {
    const c = new OffscreenCanvas(box.w * list.length + 10 * (list.length - 1), box.h), g = c.getContext('2d');
    g.fillStyle = '#fff'; g.fillRect(0, 0, c.width, c.height);
    for (let i = 0; i < list.length; i++) { const bm = await createImageBitmap(await (await fetch('data:image/png;base64,' + list[i])).blob()); g.drawImage(bm, box.x, box.y, box.w, box.h, i * (box.w + 10), 0, box.w, box.h); }
    const b = new Uint8Array(await (await c.convertToBlob({ type: 'image/png' })).arrayBuffer());
    let s = ''; for (let i = 0; i < b.length; i += 0x8000) s += String.fromCharCode(...b.subarray(i, i + 0x8000));
    return btoa(s);
  }, [[shots.js[true], shots.js[false], shots.recomp[true], shots.recomp[false]].map((b) => b.toString('base64')), box]);
  writeFileSync(join(out, 'js-vs-recomp-fra.png'), Buffer.from(png, 'base64'));
  await page.close();
  results.js = { pass: P, box, jsOnVsOff: jsD, recompOnVsOff: recompD, darkened: both };
  console.log('js', JSON.stringify(results.js));
  // the same footprint from the same camera: where both show the road, about as many pixels darkened, the same ones
  console.log(`js: around the player the surface shadow darkens ${recompD.dark} pixels in the recomp, ${jsD.dark} in the JS reconstruction (${both.inBoth} in both); ${both.coveredInRecomp} of the JS reconstruction's lie where the recomp's kart is drawn`);
  check(both.recomp >= both.js * 0.8 && both.recomp <= both.js * 1.25 && recompD.light === 0, `js: where both show the road (${both.sameBackground} of ${box.w * box.h} pixels) the shadow darkens ${both.recomp} in the recomp, ${both.js} in the JS reconstruction (${recompD.light} lighter in the recomp)`);
  check(both.iou >= 0.85, `js: there ${both.both} darkened in both, ${both.either} in either (overlap ${both.iou})`);
}

// result.json keeps the cases of earlier runs that this one did not make
const resultFile = join(out, 'result.json');
let earlier = {};
try { earlier = JSON.parse(readFileSync(resultFile, 'utf8')); } catch (e) { /* none yet */ }
writeFileSync(resultFile, JSON.stringify({ ...earlier, ...results, fails, at: new Date().toISOString(), cases: only || 'all' }, null, 1));
await browser.close();
console.log(fails.length ? `${fails.length} FAILED` : 'all passed');
process.exit(fails.length ? 1 : 0);
