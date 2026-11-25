#!/usr/bin/env node
// The race on a phone held upright in headless Chromium: 390x844 CSS pixels, device pixel ratio 3, touch, with the
// safe-area insets of a notched phone (47 top, 34 bottom) where Chromium can emulate them. Screenshot at the start
// lights (tick 345) of the development race page (/dev/race.html) in evidence/frames/shapes/phone-portrait.png, and
// what the page measured in evidence/checks/hud-phone-shot.json: the canvas, the safe area, the HUD's control words
// as race-runner.js wrote them (CTRL.INSET_*, CTRL.CONTROLS_L the touch band), and the HUD's k that hud-layout.js
// derives from them next to the k of the JS reconstruction's raceHudLayout (imported read-only) for the same
// numbers. Without --query, a touch device shows the touch controls (source/input/touch.js) over the bottom of the
// picture. Needs the dev server (node tools/serve.mjs) and Playwright (see tools/shot.mjs).
//   CHROME_PATH=... node tools/checks/hud-phone-shot.mjs [--ticks 345] [--out evidence/frames/shapes/phone-portrait.png]
//        [--size 390x844] [--safe 47,0,34,0 (top,right,bottom,left CSS px)] [--query &touch=0] [--json path]
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname, resolve } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { HudLayout, hudFrames } from '../../source/host/hud-layout.js';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const TICKS = Number(opt('ticks', 345));
const OUT = resolve(ROOT, opt('out', 'evidence/frames/shapes/phone-portrait.png'));
const [VW, VH] = String(opt('size', '390x844')).split('x').map(Number);
const [st, sr, sb, sl] = String(opt('safe', '47,0,34,0')).split(',').map(Number);
const SAFE = { top: st, right: sr, bottom: sb, left: sl };
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
const context = await browser.newContext({ viewport: { width: VW, height: VH }, deviceScaleFactor: 3, isMobile: true, hasTouch: true });
const page = await context.newPage();
page.on('pageerror', (e) => console.log('[pageerror]', e.message));
let insetsEmulated = false;
try {
  const cdp = await context.newCDPSession(page);
  await cdp.send('Emulation.setSafeAreaInsetsOverride', { insets: SAFE });
  insetsEmulated = true;
} catch (e) {
  console.log('safe-area insets not emulated:', e.message);
}
await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html') + '?fixed' + opt('query', ''));
await page.waitForFunction(() => window.gameStats.ticks >= 1, null, { timeout: 180000 });
await page.keyboard.down('ArrowUp');
await page.waitForFunction((t) => window.gameStats.ticks >= t, TICKS, { timeout: 180000 });
await page.screenshot({ path: OUT });
await page.keyboard.up('ArrowUp');
// what the page measured (race-runner.js hudShape)
const measured = await page.evaluate(() => {
  const probe = document.createElement('div');
  probe.style.cssText = 'position:fixed;left:0;top:0;width:0;height:0;visibility:hidden;'
    + 'padding:env(safe-area-inset-top,0px) env(safe-area-inset-right,0px) env(safe-area-inset-bottom,0px) env(safe-area-inset-left,0px)';
  document.body.append(probe);
  const cs = getComputedStyle(probe);
  const r = document.getElementById('game').getBoundingClientRect();
  const c = window.runner.ctrl;
  return {
    canvas: { w: r.width, h: r.height }, dpr: devicePixelRatio,
    safeArea: { top: cs.paddingTop, right: cs.paddingRight, bottom: cs.paddingBottom, left: cs.paddingLeft },
    // CTRL words 5..12 (source/web/shared.js): ASPECT, HUD_SCALE, INSET_L/R/T/B, CONTROLS_L/R
    words: { aspect: c[5] / 1e6, hudScale: c[6] / 1000, insets: { left: c[7] / 1e4, right: c[8] / 1e4, top: c[9] / 1e4, bottom: c[10] / 1e4 }, band: c[11] / 1e4 },
    touchShown: !document.getElementById('touch-controls').hidden,
    ticks: window.gameStats.ticks, phase: window.gameStats.phase,
  };
});
{
  const w = measured.words, { xr, yr } = HudLayout.clipFor(w.aspect);
  const F = hudFrames(xr, yr, { insets: w.insets, controls: { left: w.band } });
  const jsMod = join(ROOT, '..', 'RedCat Superkarts', 'source', 'race-hud-layout.js');
  const { raceHudLayout } = await import(pathToFileURL(jsMod).href);
  const W = 1000 * w.aspect, H = 1000;
  const L = raceHudLayout(W, H, { left: w.insets.left * W, right: w.insets.right * W, top: w.insets.top * H, bottom: w.insets.bottom * H, touchHeight: w.band * H });
  // k: the HUD's size against the 4:3 HUD drawn across the canvas's width (world units: 320 canvas px of 4:3 each)
  measured.k = { recomp: +(F.f * 320).toFixed(4), recompTimes: +(F.fT * 320).toFixed(4),
    js: +((320 * L.scale * 2 * xr) / W).toFixed(4), jsTimes: +((320 * L.text('string_lap').scale * 2 * xr) / W).toFixed(4) };
  measured.cssPxPerHudPx = +((F.f * 320 * measured.canvas.w) / (640 * xr)).toFixed(4);
}
const result = { url: page.url(), insetsEmulated, emulatedInsets: SAFE, ...measured, screenshot: OUT };
console.log(JSON.stringify(result, null, 1));
mkdirSync(dirname(OUT), { recursive: true });
const JSON_OUT = resolve(ROOT, opt('json', 'evidence/checks/hud-phone-shot.json'));
mkdirSync(dirname(JSON_OUT), { recursive: true });
writeFileSync(JSON_OUT, JSON.stringify(result, null, 1) + '\n');
await browser.close();
