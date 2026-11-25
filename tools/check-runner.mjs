#!/usr/bin/env node
// Three races in a row on one page through the RaceRunner (source/race-runner.js), on the development page
// (/dev/race.html?idle) in headless Chromium:
//   1. Nederland as RedCat: the FPS counter, the focus-loss pause (window blur presses the game's own P; Space
//      resumes), then the cheat Ctrl+F+I finishes the race (its finish screen ends it by itself).
//   2. Engeland as Brutus: the game files come from the worker's cache (only what its lists add is fetched), the
//      page hidden (runner.suspend: the game thread sleeps, the pause shows when it comes back), then Esc and J quit.
//   3. Nederland again: nothing fetched at all, a driving pad that goes away pauses the race, then Ctrl+F+I.
// After every race: the outcome's patch (finished 1 or 0, race.ini's own sections), the canvas, the touch controls
// and the FPS label hidden, nothing held, every sound buffer and the music freed, the render worker's textures
// deleted, and the page's memory (workers included, performance.measureUserAgentSpecificMemory) not growing by
// a race's worth. Results in evidence/checks/runner.json. Needs the dev server and Playwright (see tools/shot.mjs).
// Exit code 1 when a flag of the summary is false or the page throws or crashes (checks/page-errors.mjs).
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { watchPage } from './checks/page-errors.mjs';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const out = join(ROOT, 'evidence', 'checks');
mkdirSync(out, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required', '--enable-blink-features=ForceEagerMeasureMemory'] });
const page = await browser.newPage({ viewport: { width: 854, height: 480 } });
page.on('pageerror', (e) => console.log('[pageerror]', e.message));
page.on('console', (m) => { if (m.type() === 'error' && !/404/.test(m.text())) console.log('[page]', m.text()); });
const pageErrors = [];
watchPage(page, (e) => pageErrors.push(e));
// a scripted standard gamepad, connected until window.__padGone()
await page.addInitScript(() => {
  const pad = { id: 'test pad (STANDARD GAMEPAD)', index: 0, connected: true, mapping: 'standard', timestamp: 0,
    axes: [0, 0, 0, 0], buttons: Array.from({ length: 17 }, () => ({ pressed: false, touched: false, value: 0 })) };
  let pads = [pad];
  window.__pad = pad;
  window.__padGone = () => { pads = []; };
  navigator.getGamepads = () => pads;
});
await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html') + '?idle&fixed&stats&fps');
await page.waitForFunction(() => window.runner && window.race, null, { timeout: 30000 });

const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const tap = async (key, hold = 120) => { await page.keyboard.down(key); await wait(hold); await page.keyboard.up(key); };
const stats = () => page.evaluate(() => ({ ...window.gameStats, raceIni: undefined, progress: undefined, input: window.inputState() }));
const ticksAtLeast = (n) => page.waitForFunction((k) => window.gameStats.ticks >= k || window.gameStats.exit !== null, n, { timeout: 180000 });
const ended = () => page.waitForFunction(() => window.gameStats.exit !== null, null, { timeout: 60000 });
// the least of three readings a second apart: a race that just ended may not be collected at the first
const memory = async () => {
  let least = null;
  for (let k = 0; k < 3; k++) {
    try {
      const b = await page.evaluate(async () => (performance.measureUserAgentSpecificMemory ? (await performance.measureUserAgentSpecificMemory()).bytes : null));
      if (b !== null && (least === null || b < least)) least = b;
    } catch (e) { /* not available */ }
    if (k < 2) await wait(1000);
  }
  return least;
};
const MB = (b) => (b === null ? null : Math.round(b / 1048576));
const finishByCheat = async () => {
  await page.keyboard.down('Control'); await page.keyboard.down('KeyF'); await page.keyboard.down('KeyI');
  await wait(150);
  await page.keyboard.up('KeyI'); await page.keyboard.up('KeyF'); await page.keyboard.up('Control');
};
const quit = async () => { await tap('Escape'); await wait(1500); await tap('KeyJ'); };

/** What is left between races. */
const between = async () => {
  await wait(1300);           // a render-stats message after the race's end
  return page.evaluate(() => {
    const canvas = document.getElementById('game'), fps = document.getElementById('fps-counter'), touch = document.getElementById('touch-controls');
    const a = window.audioState(), i = window.inputState();
    return {
      canvasHidden: getComputedStyle(canvas).display === 'none', fpsHidden: fps.hidden, touchHidden: touch.hidden,
      active: window.runner.active, held: i.held, joy: i.joy, buttons: i.buttons,
      audio: { buffers: a.buffers, effects: a.effects, musicLoaded: a.music.loaded, musicPlaying: a.music.playing, context: a.context },
      textures: window.renderStats ? window.renderStats.textures : null,
      lastReset: window.renderResets[window.renderResets.length - 1] || null,
    };
  });
};

const results = { races: [] };
const mem0 = await memory();
console.log('memory before the first race', MB(mem0), 'MB');

async function race(n, config, during, end, expectFinished) {
  const t0 = Date.now();
  await page.evaluate((c) => { window.__outcome = null; window.race(c).then((o) => { window.__outcome = o; }); }, config);
  await page.waitForFunction(() => window.gameStats.shown || window.gameStats.exit !== null, null, { timeout: 180000 });
  const shownMs = Date.now() - t0;
  await page.waitForFunction(() => window.gameStats.running || window.gameStats.exit !== null, null, { timeout: 60000 });
  await page.keyboard.down('ArrowUp');
  await ticksAtLeast(380);
  await page.keyboard.up('ArrowUp');
  const r = { race: n, config, shownMs };
  r.load = (await stats()).load;
  const inRace = await page.evaluate(() => ({ textures: window.renderStats ? window.renderStats.textures : null, audio: window.audioState() }));
  r.inRace = { textures: inRace.textures, buffers: inRace.audio.buffers, music: inRace.audio.music.loaded };
  Object.assign(r, await during());
  await end();
  await ended();
  const s = await page.evaluate(() => ({ outcome: window.gameStats.outcome, raceIni: window.gameStats.raceIni }));
  r.outcome = s.outcome;
  r.raceIni = {
    etappe: (s.raceIni.match(/^\s*etappe\s*=\s*(\d+)/mi) || [])[1],
    car: (s.raceIni.match(/^\s*car\s*=\s*(\d+)/mi) || [])[1],
    finished: (s.raceIni.match(/^\s*finished\s*=\s*(\d+)/mi) || [])[1],
  };
  r.after = await between();
  r.memoryMB = MB(await memory());
  const p = r.outcome && r.outcome.patch;
  r.ok = {
    resolved: !!r.outcome && r.outcome.error === null && r.outcome.exitCode === 0,
    patch: !!p && !!p.PLAYER && p.PLAYER.finished === (expectFinished ? 1 : 0) && Number(r.raceIni.finished) === (expectFinished ? 1 : 0)
      && (!expectFinished || Object.keys(p.PLAYER).length === 1 || (Number.isFinite(Number(p.PLAYER.position)) && Number.isFinite(Number(p.PLAYER.tracktime)))),
    etappe: Number(r.raceIni.etappe) === config.country,
    cleanedUp: r.after.canvasHidden && r.after.fpsHidden && r.after.touchHidden && !r.after.active && r.after.held.length === 0 && r.after.buttons === 0
      && r.after.joy[0] === 32767 && r.after.joy[1] === 32767 && r.after.joy[3] === 0,
    audioFreed: r.inRace.buffers > 0 && r.after.audio.buffers === 0 && r.after.audio.effects === 0 && !r.after.audio.musicLoaded && !r.after.audio.musicPlaying,
    texturesFreed: r.inRace.textures > 0 && r.after.textures === 0 && !!r.after.lastReset && r.after.lastReset.textures === 0,
  };
  console.log(`race ${n}`, JSON.stringify({ shownMs, load: r.load, inRace: r.inRace, outcome: r.outcome, raceIni: r.raceIni, memoryMB: r.memoryMB, ok: r.ok }));
  results.races.push(r);
  return r;
}

// 1. Nederland as RedCat: FPS counter, focus-loss pause, finish by cheat
await race(1, { country: 0, character: 0, raceType: 0 }, async () => {
  await wait(3200);           // past the counter's two-second warm-up and one window
  const fps = await page.evaluate(() => ({ text: document.getElementById('fps-counter').textContent, hidden: document.getElementById('fps-counter').hidden, value: window.gameStats.fps }));
  const before = await stats();
  await page.evaluate(() => window.dispatchEvent(new Event('blur')));
  await wait(1000);
  const f1 = await stats();
  await wait(1000);
  const f2 = await stats();
  await tap('Space');
  await wait(800);
  const f3 = await stats();
  console.log('focus pause', JSON.stringify({ before: before.ticks, f1: [f1.ticks, f1.input.waiting, f1.input.p], f2: [f2.ticks, f2.input.waiting], f3: [f3.ticks, f3.input.waiting] }));
  return {
    fps,
    fpsOk: !fps.hidden && /^\d+ FPS$/.test(fps.text) && fps.value > 20,
    focusPause: { phase: before.phase, pausedAt: f1.ticks, stillAt: f2.ticks, resumedAt: f3.ticks,
      ok: before.phase === 0 && f1.input.waiting === true && f1.input.p === 0 && f2.ticks === f1.ticks && f3.ticks > f2.ticks && !f3.input.waiting },
  };
}, finishByCheat, true);

// 2. Engeland as Brutus: cached files, the page hidden and back, quit with Esc and J
await race(2, { country: 2, character: 2, raceType: 0 }, async () => {
  await page.evaluate(() => window.runner.suspend());
  await wait(300);
  const s1 = await stats();
  await wait(1000);
  const s2 = await stats();
  const fpsHidden = await page.evaluate(() => document.getElementById('fps-counter').hidden);
  await page.evaluate(() => window.runner.resume());
  await wait(1200);
  const s3 = await stats();
  await wait(600);
  const s4 = await stats();
  await tap('Space');
  await wait(800);
  const s5 = await stats();
  console.log('suspend', JSON.stringify({ s1: [s1.ticks, s1.input.paused, s1.input.p], s2: s2.ticks, s3: [s3.ticks, s3.input.waiting], s4: s4.ticks, s5: [s5.ticks, s5.input.waiting] }));
  return { suspend: { ok: s1.input.paused === 1 && s2.ticks === s1.ticks && fpsHidden && s3.input.waiting === true && s4.ticks === s3.ticks && s5.ticks > s4.ticks && !s5.input.waiting } };
}, quit, false);

// 3. Nederland again: nothing fetched, the driving pad goes away, finish by cheat
await race(3, { country: 0, character: 0, raceType: 0 }, async () => {
  await page.evaluate(() => { window.__pad.axes[0] = 0.5; window.__pad.buttons[7].value = 1; window.__pad.buttons[7].pressed = true; });
  await wait(600);
  const p0 = await stats();
  await page.evaluate(() => window.__padGone());
  await wait(1200);
  const p1 = await stats();
  await wait(600);
  const p2 = await stats();
  await tap('Space');
  await wait(800);
  const p3 = await stats();
  console.log('pad lost', JSON.stringify({ p0: [p0.ticks, p0.device], p1: [p1.ticks, p1.input.waiting], p2: p2.ticks, p3: [p3.ticks, p3.input.waiting] }));
  return { padLost: { ok: p0.device === 3 && p1.input.waiting === true && p2.ticks === p1.ticks && p3.ticks > p2.ticks && !p3.input.waiting } };
}, finishByCheat, true);

const [r1, r2, r3] = results.races;
results.summary = {
  allResolved: results.races.every((r) => r.ok.resolved && r.ok.patch && r.ok.etappe),
  cleanedUp: results.races.every((r) => r.ok.cleanedUp),
  audioFreed: results.races.every((r) => r.ok.audioFreed),
  texturesFreed: results.races.every((r) => r.ok.texturesFreed),
  fpsCounter: r1.fpsOk,
  focusPause: r1.focusPause.ok, suspend: r2.suspend.ok, padLostPause: r3.padLost.ok,
  // the second race fetches only what its lists name beyond the first's (its etappe's files and archive pages, Brutus's),
  // the third nothing; both load in a fraction of the first's time (since 2026-11-25 a race fetches its lists' files and
  // archive pages, about 30 MB, not the whole 185 MB: source/web/game-files.js)
  cachedLoad: r2.load.cached > 10e6 && r2.load.fetched < r1.load.fetched / 2 && r3.load.fetched === 0 && r3.load.ms < Math.max(200, r1.load.ms / 2),
  loads: results.races.map((r) => r.load),
  memoryMB: [MB(mem0), ...results.races.map((r) => r.memoryMB)],
  // no race's worth of memory kept (a race's wasm memory is about 200 MB): after the second and the third race the
  // page holds what it held after the first, within 64 MB
  memoryFlat: r1.memoryMB === null || (r2.memoryMB - r1.memoryMB < 64 && r3.memoryMB - r1.memoryMB < 64),
};
writeFileSync(join(out, 'runner.json'), JSON.stringify(results, null, 1));
console.log(JSON.stringify(results.summary));
await browser.close();
const failed = Object.entries(results.summary).filter(([, v]) => v === false).map(([k]) => k);
for (const e of pageErrors) console.log('[page error]', e);
if (failed.length || pageErrors.length) {
  console.log('FAIL', [...failed, ...(pageErrors.length ? [pageErrors.length + ' page error(s)'] : [])].join(' '));
  process.exitCode = 1;
} else console.log('all passed');
