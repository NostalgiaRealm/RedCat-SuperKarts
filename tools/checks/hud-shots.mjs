#!/usr/bin/env node
// The in-race HUD of the recomp and of the JS reconstruction ("JS port") in the same screen shapes, side by side:
// 4:3, 16:9 and 21:9 desktop windows, a phone held upright (390x844 CSS px, device pixel ratio 3, notch insets 47
// top and 34 bottom) without and with the touch controls, the same phone in landscape with the touch controls
// (insets 47 left and right, 21 bottom), and the upright phone in Sterrenrace (the stars). Each screenshot is taken
// with the start lights parked (the recomp at pass 345, the JS port in countdown phase 2), Nederland, RedCat.
// The recomp runs from /dev/race.html (tools/serve.mjs, 4190); the JS port from its committed runtime, served
// read-only by tools/checks/menu/serve-js-readonly.mjs (4173): ?drive=0, then a reload of the race with its countdown
// (rcsk.viewer.load(..., { countdown: true }), as its menu's startSelectedRace does), its settings in localStorage.
// Writes evidence/frames/hud/<label>/{recomp,js}-<shape>.png and <label>/measured.json (the recomp's HUD control
// words as the page wrote them, the JS port's raceHudLayout as its RaceHud measured it). In evidence/frames/hud/:
// js/ the JS port's set (taken with --label before, moved there), before/ and after/ the recomp's before and after it
// took over the JS port's layout (2026-11-25), clip/ with each group cut to its frame and the touch controls' rules
// copied (2026-11-25). --moment slide holds both while the start lights slide in, about halfway (the recomp's game
// thread at pass 197, local y 0.84 on the way from 1.25 to 0.4, 0x464e90, headless trace; the JS port 0.58 s into
// countdown phase 0, y 0.84 by its nativeCountdownY), as <label>/{recomp,js}-<shape>-slide.png: the frame's top line
// cuts the lights in both.
//   CHROME_PATH=... node tools/checks/hud-shots.mjs [--label after] [--only 4x3,phone-portrait] [--sites recomp,js] [--moment slide]
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const LABEL = opt('label', 'after');
const ONLY = opt('only', '') ? opt('only').split(',') : null;
const SITES = String(opt('sites', 'recomp,js')).split(',');
const SLIDE = opt('moment', '') === 'slide';
const SUFFIX = SLIDE ? '-slide' : '';
const OUT = join(ROOT, 'evidence', 'frames', 'hud', LABEL);
mkdirSync(OUT, { recursive: true });
const RECOMP = process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html';
const JS = process.env.RCSK_JS_URL || 'http://127.0.0.1:4173/';
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });

const desk = (w, h) => ({ viewport: { width: w, height: h }, deviceScaleFactor: 1 });
const phone = (w, h, touch) => ({ viewport: { width: w, height: h }, deviceScaleFactor: 3, isMobile: true, hasTouch: touch });
const UPRIGHT = { top: 47, right: 0, bottom: 34, left: 0 };
const SIDEWAYS = { top: 0, right: 47, bottom: 21, left: 47 };
const SHAPES = [
  ['4x3', desk(640, 480), null, false, 0], ['16x9', desk(854, 480), null, false, 0], ['21x9', desk(1120, 480), null, false, 0],
  ['phone-portrait', phone(390, 844, false), UPRIGHT, false, 0], ['phone-portrait-touch', phone(390, 844, true), UPRIGHT, true, 0],
  ['phone-landscape-touch', phone(844, 390, true), SIDEWAYS, true, 0], ['phone-portrait-sterrenrace', phone(390, 844, false), UPRIGHT, false, 2],
].filter((s) => !ONLY || ONLY.includes(s[0]));

async function open(ctxOpts, safe, init) {
  const context = await browser.newContext(ctxOpts);
  if (init) await context.addInitScript(init.fn, init.arg);
  const page = await context.newPage();
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  let insets = false;
  if (safe) {
    try {
      const cdp = await context.newCDPSession(page);
      await cdp.send('Emulation.setSafeAreaInsetsOverride', { insets: safe });
      insets = true;
    } catch (e) { console.log('safe-area insets not emulated:', e.message); }
  }
  return { context, page, insets };
}

async function recomp(name, ctxOpts, safe, touch, race) {
  const { context, page, insets } = await open(ctxOpts, safe);
  await page.goto(`${RECOMP}?fixed&touch=${touch ? 1 : 0}&race=${race}`);
  await page.waitForFunction(() => window.gameStats.ticks >= 1, null, { timeout: 300000 });
  let held = null;
  if (SLIDE) {
    // window.gameStats comes every 500 ms: the game thread's own count (CTRL.TICKS, word 3) is watched, and the game
    // thread held (CTRL.PAUSED, word 2) at pass 197, so the picture stays there for the screenshot
    await page.waitForFunction(() => window.gameStats.ticks >= 150, null, { timeout: 300000 });
    held = await page.evaluate((T) => { const c = window.runner.ctrl; while (Atomics.load(c, 3) < T); Atomics.store(c, 2, 1); return Atomics.load(c, 3); }, 197);
    await page.waitForTimeout(600);
  } else await page.waitForFunction(() => window.gameStats.ticks >= 345, null, { timeout: 300000 });
  await page.screenshot({ path: join(OUT, `recomp-${name}${SUFFIX}.png`) });
  const words = await page.evaluate(() => {
    const c = window.runner.ctrl, r = document.getElementById('game').getBoundingClientRect();
    // CTRL words 5..12 (source/web/shared.js): ASPECT, HUD_SCALE, INSET_L/R/T/B, CONTROLS_L/R
    return { canvas: [r.width, r.height], aspect: c[5] / 1e6, hudScale: c[6] / 1000, insets: [c[7], c[8], c[9], c[10]].map((v) => v / 1e4),
      controls: [c[11], c[12]].map((v) => v / 1e4), ticks: c[3], touchShown: !document.getElementById('touch-controls').hidden };
  });
  await context.close();
  return { insets, held, ...words };
}

async function js(name, ctxOpts, safe, touch, race) {
  const init = { fn: ([t, r]) => {
    localStorage.setItem('rcsk.selection.v1', JSON.stringify({ character: 0, difficulty: 1, country: 0, race: r }));
    localStorage.setItem('rcsk.settings.v1', JSON.stringify({ touch: t ? 'on' : 'off' }));
  }, arg: [touch, race] };
  const { context, page, insets } = await open(ctxOpts, safe, init);
  await page.goto(JS + '?drive=0');
  await page.waitForFunction(() => window.rcsk?.state?.page === 'driving', null, { timeout: 300000 });
  await page.evaluate(async (r) => { const v = rcsk.viewer; await v.load(0, { character: 0, difficulty: 1, raceMode: r, countdown: true }); v.resume(); }, race);
  let held = null;
  if (SLIDE) {
    // checked after each of its frames (requestAnimationFrame, after the viewer's own), and the viewer held there
    // without its pause notice (driving-view.js:388 suspend)
    held = await page.evaluate(() => new Promise((done) => {
      const f = () => {
        const s = rcsk.viewer.simulation;
        if (s.countdownStarted && (s.countdown.phase > 0 || s.countdown.elapsed >= 0.58)) {
          rcsk.viewer.suspend({ notifyPause: false, pauseAudio: false });
          done({ phase: s.countdown.phase, elapsed: s.countdown.elapsed, y: s.countdown.phase === 0 ? 1.25 + (0.4 - 1.25) * s.countdown.elapsed / 1.2 : 0.4 });
        } else requestAnimationFrame(f);
      };
      f();
    }));
    await page.waitForTimeout(300);
  } else await page.waitForFunction(() => { const s = rcsk.viewer.simulation; return s.countdownStarted && s.countdown.phase >= 2; }, null, { timeout: 300000, polling: 50 });
  await page.screenshot({ path: join(OUT, `js-${name}${SUFFIX}.png`) });
  const layout = await page.evaluate(() => {
    const L = rcsk.viewer.hud.layout;
    if (!L) return null;
    const g = (n) => { const v = L.group(n); return [v.x, v.y].map(Math.round); };
    const t = (n) => { const v = L.text(n); return { x: Math.round(v.x), y: Math.round(v.y), scale: v.scale && +v.scale.toFixed(4) }; };
    return { portrait: L.portrait, scale: +L.scale.toFixed(4), frame: [L.width, L.height].map(Math.round), canvas: [rcsk.viewer.hud.canvas.width, rcsk.viewer.hud.canvas.height],
      groups: Object.fromEntries(['portraits', 'stars', 'map', 'bonus', '321timer', 'arrows'].map((n) => [n, g(n)])),
      texts: Object.fromEntries(['string_lap', 'string_bonus', 'string_special', 'string_countdown_value'].map((n) => [n, t(n)])),
      touchShown: !document.getElementById('touch-controls').hidden };
  });
  await context.close();
  return { insets, held, layout };
}

const measured = {};
for (const [name, ctxOpts, safe, touch, race] of SHAPES) {
  measured[name] = {};
  for (const site of SITES) {
    try {
      measured[name][site] = await (site === 'js' ? js : recomp)(name, ctxOpts, safe, touch, race);
      console.log(name, site, JSON.stringify(measured[name][site]));
    } catch (e) {
      measured[name][site] = { error: e.message };
      console.log(name, site, 'FAILED', e.message);
    }
  }
}
writeFileSync(join(OUT, `measured${SUFFIX}.json`), JSON.stringify(measured, null, 1) + '\n');
await browser.close();
