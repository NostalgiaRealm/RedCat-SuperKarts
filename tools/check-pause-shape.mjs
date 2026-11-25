#!/usr/bin/env node
// The held picture at a new shape, on the worker page in headless Chromium, against the JS reconstruction (read-only
// server, tools/checks/menu/serve-js-readonly.mjs on 4173): the game worker draws the held picture again with the HUD
// laid out for the new shape (source/web/worker.js repaint, source/host/render-replay.js), as the JS port lays its HUD
// out for every picture.
//   rotate    a phone (844x390, touch) racing on Nederland: a focus pause (blur), the phone turned upright (390x844):
//             the game still waits in its pause and the render worker got a new frame (CTRL.FRAMES) with the HUD laid
//             out upright; a key resumes; P in portrait, turned back to landscape: the same
//   requester the quit requester (Esc), turned upright: still the requester (pause kind 2), its 640x480 form sent again
//             (the render worker keeps no 2D frame to draw again: before, the canvas stayed black)
//   flight    (?flight) free flight's P pause turned upright: the same
//   finish    (cheats: Ctrl+F+I) the finish screen held by a blur: "pauze" over it (a new frame), turned upright with it,
//             a key ends the hold and the next passes run without the notice
//   gameover  a Tijdrace (race=1) without input until the time runs out (phase 6), held by a blur: "tijd is om!" stays and
//             no "pauze" (render-replay.js notice: the original's notice would drop it for good), turned upright
//   js-*      the JS port: rotate (focus pause upright, P pause back to landscape) and gameover (held, turned, resumed)
// Screenshots, side-by-sides (cmp-*.png, recomp left) and results in evidence/frames/pause-shape/. Needs the dev server
// (node tools/serve.mjs), Playwright (see tools/shot.mjs) and, for js-*, the JS port's read-only server. Exit code 1 when
// a check fails or a page throws or crashes (checks/page-errors.mjs; on the JS port's pages without their console).
//   node tools/check-pause-shape.mjs [--only=rotate,requester,flight,finish,gameover,js]
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { execFileSync } from 'node:child_process';
import { watchPage } from './checks/page-errors.mjs';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const out = join(ROOT, 'evidence', 'frames', 'pause-shape');
mkdirSync(out, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'] });
const DEV = process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html';
const JS = process.env.RCSK_JS_URL || 'http://127.0.0.1:4173/';
const only = (process.argv.find((a) => a.startsWith('--only=')) || '').slice(7).split(',').filter(Boolean);
const want = (k) => !only.length || only.includes(k);
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const results = {};
let failed = 0;
const check = (group, name, ok, detail) => {
  (results[group] ||= []).push({ name, ok: !!ok, ...(detail === undefined ? {} : { detail }) });
  if (!ok) failed++;
  console.log(`${ok ? 'ok  ' : 'FAIL'} [${group}] ${name}${detail === undefined ? '' : ' ' + JSON.stringify(detail)}`);
};
const PHONE = { viewport: { width: 844, height: 390 }, deviceScaleFactor: 2, isMobile: true, hasTouch: true };
const shot = (page, name) => page.screenshot({ path: join(out, name + '.png') });
const tap = async (page, key, ms = 150) => { await page.keyboard.down(key); await wait(ms); await page.keyboard.up(key); };
const blur = (page) => page.evaluate(() => window.dispatchEvent(new Event('blur')));
// the recomp: the race, the runner's holds and the frames the render worker has drawn (CTRL.FRAMES, word 0)
const rc = (page) => page.evaluate(() => { const g = window.gameStats, i = window.inputState();
  return { ticks: g.ticks, phase: g.phase, exit: g.exit, waiting: i.waiting, kind: i.pauseKind, focusHeld: i.focusHeld, focusMuted: i.focusMuted, paused: i.paused, frames: Atomics.load(window.runner.ctrl, 0),
    hold: Atomics.load(window.runner.ctrl, 27), notices: g.replay ? g.replay.notices : null, repaints: g.replay ? g.replay.repaints : null, clockMs: g.clockMs }; });
async function dev(query, ctx) {
  const context = await browser.newContext(ctx);
  const page = await context.newPage();
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  watchPage(page, (e) => check('page', `no page error (${query || 'dev'})`, false, e));
  await page.goto(DEV + '?stats' + query);
  await page.waitForFunction(() => window.runner && window.gameStats && window.gameStats.ticks >= 1, null, { timeout: 180000 });
  return page;
}
const ticksAtLeast = (page, n) => page.waitForFunction((k) => window.gameStats.ticks >= k || window.gameStats.crash, n, { timeout: 300000, polling: 100 });
/** The JS port on its read-only server, racing (?drive=0) with these settings and selection. */
async function jsPage(settings, selection, ctx) {
  const context = await browser.newContext(ctx);
  const page = await context.newPage();
  page.on('pageerror', (e) => console.log('[pageerror js]', e.message));
  watchPage(page, (e) => check('page', 'no page error (JS port)', false, e), { console: false });
  await page.goto(JS);
  await page.evaluate(([s, sel]) => { localStorage.setItem('rcsk.settings.v1', JSON.stringify(s)); localStorage.setItem('rcsk.selection.v1', JSON.stringify(sel)); }, [settings, selection]);
  await page.goto(JS + '?drive=0');
  await page.waitForFunction(() => window.rcsk && window.rcsk.state.mode === 'race' && window.rcsk.viewer?.race, null, { timeout: 300000, polling: 200 });
  return page;
}
const js = (page) => page.evaluate(() => ({ mode: window.rcsk.state.mode, phase: window.rcsk.viewer?.race?.phase }));
const montage = (name, files, width = 420) => {
  try { execFileSync('python3', ['-c', MONTAGE, join(out, name + '.png'), String(width), String(files.length), ...files.map((f) => join(out, f + '.png'))]); } catch (e) { console.log('montage', name, e.message.split('\n')[0]); }
};
// side by side: each picture scaled to one width, its file name above it
const MONTAGE = `
import sys
from PIL import Image, ImageDraw
out, W, cols = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
ims = []
for f in sys.argv[4:]:
    im = Image.open(f).convert('RGB'); h = int(im.height * W / im.width); ims.append((f.split('/')[-1], im.resize((W, h))))
H = max(i.height for _, i in ims) + 14
M = Image.new('RGB', (W * cols, H), (40, 40, 40)); d = ImageDraw.Draw(M)
for k, (n, i) in enumerate(ims):
    d.text((k * W + 2, 0), n, fill=(255, 255, 0)); M.paste(i, (k * W, 14))
M.save(out)
`;

try {
  if (want('rotate') || want('requester')) {
    const page = await dev('&touch=1&nocheats&fixed', PHONE);
    await ticksAtLeast(page, 420);
    await page.keyboard.down('ArrowUp'); await wait(2000); await page.keyboard.up('ArrowUp');
    if (want('rotate')) {
      await blur(page);
      await page.waitForFunction(() => window.inputState().waiting, null, { timeout: 20000 }).catch(() => {});
      await wait(1000);
      const s0 = await rc(page);
      await shot(page, 'rc-focus-landscape');
      await page.setViewportSize({ width: 390, height: 844 });
      await wait(2500);
      const s1 = await rc(page);
      await shot(page, 'rc-focus-portrait');
      check('rotate', 'focus pause turned upright: still the pause, and a new frame with the HUD laid out upright', s0.waiting && s0.kind === 1 && s1.waiting && s1.kind === 1 && s1.ticks === s0.ticks && s1.frames > s0.frames,
        { before: s0, after: s1 });
      await tap(page, 'ArrowLeft');
      await wait(1500);
      const s2 = await rc(page);
      await shot(page, 'rc-resumed-portrait');
      await tap(page, 'KeyP');
      await page.waitForFunction(() => window.inputState().waiting, null, { timeout: 20000 }).catch(() => {});
      await wait(1000);
      const s3 = await rc(page);
      await shot(page, 'rc-ppause-portrait');
      await page.setViewportSize(PHONE.viewport);
      await wait(2500);
      const s4 = await rc(page);
      await shot(page, 'rc-ppause-landscape');
      check('rotate', 'P pause turned back to landscape: still the pause, a new frame', !s2.waiting && s2.ticks > s1.ticks && s3.waiting && s3.kind === 1 && s4.waiting && s4.kind === 1 && s4.ticks === s3.ticks && s4.frames > s3.frames,
        { resumed: s2, paused: s3, turned: s4 });
      await tap(page, 'Space');
      await wait(1500);
      const s5 = await rc(page);
      check('rotate', 'the race goes on after it', !s5.waiting && s5.ticks > s4.ticks, s5);
      await shot(page, 'rc-ppause-resumed');
    }
    if (want('requester')) {
      await tap(page, 'Escape');
      await page.waitForFunction(() => window.inputState().waiting && window.inputState().pauseKind === 2, null, { timeout: 20000 }).catch(() => {});
      await wait(1000);
      const r0 = await rc(page);
      await shot(page, 'rc-requester-landscape');
      await page.setViewportSize({ width: 390, height: 844 });
      await wait(2500);
      const r1 = await rc(page);
      await shot(page, 'rc-requester-portrait');
      check('requester', 'the quit requester turned upright: still the requester, its form sent again (a new frame: worker.js resend2d)', r0.kind === 2 && r1.waiting && r1.kind === 2 && r1.frames > r0.frames, { before: r0, after: r1 });
      await tap(page, 'KeyN');
      await wait(1500);
      const r2 = await rc(page);
      check('requester', 'N goes on racing', !r2.waiting && r2.exit === null, r2);
    }
    await page.context().close();
  }

  if (want('flight')) {
    // free flight's pause (its pass calls the pause 0x42f350 after its own pause render, free-flight.js): the same loop
    const page = await dev('&touch=1&nocheats&fixed&flight', PHONE);
    await page.waitForFunction(() => window.inputState().flying, null, { timeout: 300000 });
    await page.keyboard.down('ArrowUp'); await wait(1200); await page.keyboard.up('ArrowUp');
    await tap(page, 'KeyP');
    await page.waitForFunction(() => window.inputState().waiting, null, { timeout: 20000 }).catch(() => {});
    await wait(1000);
    const l0 = await rc(page);
    await shot(page, 'rc-flight-pause-landscape');
    await page.setViewportSize({ width: 390, height: 844 });
    await wait(2500);
    const l1 = await rc(page);
    await shot(page, 'rc-flight-pause-portrait');
    check('flight', 'free flight\'s P pause turned upright: still the pause, a new frame', l0.waiting && l0.kind === 1 && l1.waiting && l1.kind === 1 && l1.ticks === l0.ticks && l1.frames > l0.frames, { before: l0, after: l1 });
    await tap(page, 'Space');
    await wait(1500);
    const l2 = await rc(page);
    check('flight', 'it flies on after the pause', !l2.waiting && l2.ticks > l1.ticks, l2);
    await page.context().close();
  }

  if (want('finish')) {
    const page = await dev('&fixed', { viewport: { width: 960, height: 540 } });   // cheats on: Ctrl+F+I finishes
    await ticksAtLeast(page, 420);
    for (const k of ['ControlLeft', 'KeyF', 'KeyI']) await page.keyboard.down(k);
    await wait(600);
    for (const k of ['ControlLeft', 'KeyF', 'KeyI']) await page.keyboard.up(k);
    await page.waitForFunction(() => window.gameStats.phase === 3, null, { timeout: 30000 }).catch(() => {});
    await wait(800);
    const f0 = await rc(page);
    await shot(page, 'rc-finish');
    await blur(page);
    await wait(1200);
    const f1 = await rc(page);
    await shot(page, 'rc-finish-held');
    await wait(800);
    const f1b = await rc(page);
    check('finish', 'a blur on the finish screen holds it (no passes, HOLD.RESULTS)', f0.phase === 3 && f1.focusHeld && f1.paused === 1 && (f1.hold & 2) !== 0 && f1b.ticks === f1.ticks && f1b.frames === f1.frames,
      { before: f0, held: f1, later: f1b });
    await page.setViewportSize({ width: 540, height: 960 });
    await wait(2500);
    const f2 = await rc(page);
    await shot(page, 'rc-finish-held-portrait');
    check('finish', 'turned upright while held: still held, a new frame', f2.focusHeld && f2.ticks === f1.ticks && f2.frames > f1.frames, f2);
    await page.setViewportSize({ width: 960, height: 540 });
    await wait(1500);
    await tap(page, 'Enter');
    await wait(700);
    const f3 = await rc(page);
    await shot(page, 'rc-finish-after');
    check('finish', 'a key ends the hold: the passes go on on the finish screen, the notice shown once and taken off', !f3.focusHeld && f3.ticks > f2.ticks && f3.phase === 3 && f3.notices === 1, f3);
    // the hold (about 6 s) is not game time: the clock moved by the passes after it (25 ms each, more for a slow pass),
    // not by the hold (worker.js still: before it, the held picture's render caught the clock up with real time)
    const heldMs = f3.clockMs - f1b.clockMs, passMs = (f3.ticks - f1b.ticks) * 25;
    check('finish', 'the hold is not game time: the clock moved by about the passes after it', heldMs < passMs + 1500, { clockMs: heldMs, passesMs: passMs });
    await page.context().close();
  }

  if (want('gameover')) {
    const page = await dev('&touch=1&race=1&nocheats', PHONE);
    await page.waitForFunction(() => window.gameStats.phase === 6 || window.gameStats.exit !== null, null, { timeout: 300000, polling: 100 });
    await wait(600);
    const g0 = await rc(page);
    await shot(page, 'rc-gameover');
    await blur(page);
    await wait(1200);
    const g1 = await rc(page);
    await shot(page, 'rc-gameover-held');
    await page.setViewportSize({ width: 390, height: 844 });
    await wait(2500);
    const g2 = await rc(page);
    await shot(page, 'rc-gameover-held-portrait');
    check('gameover', 'game over held: no "pauze" (the special text runs "tijd is om!"), turned upright: a new frame', g0.phase === 6 && g1.focusHeld && g2.focusHeld && g2.ticks === g1.ticks && g2.frames > g1.frames,
      { before: g0, held: g1, turned: g2 });
    await page.touchscreen.tap(200, 300);
    await wait(800);
    const g3 = await rc(page);
    await shot(page, 'rc-gameover-after');
    check('gameover', 'a tap ends the hold, no notice was shown', !g3.focusHeld && (g3.notices || 0) === 0, g3);
    await page.context().close();
  }

  if (want('js')) {
    // the JS port: the same rotations in its focus and P pause
    const page = await jsPage({ touch: 'on' }, { race: 0, character: 0, difficulty: 1, country: 0 }, PHONE);
    await page.keyboard.down('ArrowUp'); await wait(2000); await page.keyboard.up('ArrowUp');
    await blur(page);
    await wait(1200);
    await shot(page, 'js-focus-landscape');
    await page.setViewportSize({ width: 390, height: 844 });
    await wait(2500);
    await shot(page, 'js-focus-portrait');
    await tap(page, 'ArrowLeft');
    await wait(1500);
    await tap(page, 'KeyP');
    await wait(1000);
    await shot(page, 'js-ppause-portrait');
    await page.setViewportSize(PHONE.viewport);
    await wait(2500);
    await shot(page, 'js-ppause-landscape');
    results.js = { rotate: await js(page) };
    await page.context().close();
    // a Tijdrace's game over held and turned, then resumed: "tijd is om!" against "pauze"
    const go = await jsPage({ touch: 'on' }, { race: 1, character: 0, difficulty: 1, country: 0 }, PHONE);
    await go.waitForFunction(() => window.rcsk.viewer?.race?.phase === 6 || window.rcsk.state.mode !== 'race', null, { timeout: 300000, polling: 100 });
    await wait(600);
    await shot(go, 'js-gameover');
    await blur(go);
    await wait(1200);
    await shot(go, 'js-gameover-held');
    await go.setViewportSize({ width: 390, height: 844 });
    await wait(2500);
    await shot(go, 'js-gameover-held-portrait');
    await go.touchscreen.tap(200, 300);
    await wait(800);
    await shot(go, 'js-gameover-after');
    results.js.gameover = await js(go);
    await go.context().close();
  }
} catch (e) {
  check('run', 'the check ran', false, e.message.split('\n')[0]);
}
await browser.close();
// side by side, the recomp left
const have = (n) => { try { return execFileSync('test', ['-f', join(out, n + '.png')]) || true; } catch { return false; } };
for (const [name, files] of [['cmp-focus-portrait', ['rc-focus-portrait', 'js-focus-portrait']], ['cmp-ppause-landscape', ['rc-ppause-landscape', 'js-ppause-landscape']],
  ['cmp-gameover-held', ['rc-gameover-held', 'js-gameover-held']], ['cmp-gameover-held-portrait', ['rc-gameover-held-portrait', 'js-gameover-held-portrait']],
  ['cmp-gameover-after', ['rc-gameover-after', 'js-gameover-after']], ['rc-finish-sequence', ['rc-finish', 'rc-finish-held', 'rc-finish-after']],
  ['rc-requester-turned', ['rc-requester-landscape', 'rc-requester-portrait']], ['rc-flight-pause-turned', ['rc-flight-pause-landscape', 'rc-flight-pause-portrait']]]) {
  if (files.every(have)) montage(name, files, name.includes('portrait') || name.startsWith('cmp-focus') ? 300 : 420);
}
writeFileSync(join(out, 'check-pause-shape.json'), JSON.stringify({ date: new Date().toISOString(), failed, results }, null, 1));
console.log(failed ? `${failed} check(s) failed` : 'all checks passed');
process.exit(failed ? 1 : 0);
