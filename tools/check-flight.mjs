#!/usr/bin/env node
// Free flight (Vrij vliegen) on the menu page with the real race runner, in headless Chromium, against the JS
// reconstruction's behaviour (../RedCat Superkarts at 5bfe0b62: main.js:72-81, :871-872, input.js:51-68, :152,
// race-simulation.js:260-275, :599-637, driving-view.js:336-345):
//   settings.freeFlight on (rcsk.settings.v1, touch controls on), ?drive=0: a QuickRace in Nederland;
//   1. the panel #flight-controls shows after green with the JS port's text and buttons, and Omhoog / Omlaag in the
//      touch controls; the game flies (CTRL.FLIGHT_ACTIVE) while its clock stands still;
//   2. Up and Space held for 1 s: the kart goes up and forward while the passes run, the phase stays 0 and the game's
//      time does not move; sound effects held, the music on; a scripted pad's LB and RB and the Omhoog / Omlaag
//      buttons lift and lower it;
//   3. P: the game's own pause shows "pauze" in the middle (the JS port's hud.notify, driving-view.js:395), the panel
//      steps aside, and a key resumes the flight without the notice; the pause picture is the flight's but for the
//      notice, the panel and the lift buttons (every kart whole: source/host/render-replay.js), and at take-off every
//      kart's parts were put back and none drawn off its body (the worker's stats.replay);
//   4. Instellingen: the original settings (TFRMOPTIONS) over the held race (no passes, no panel, no canvas);
//      Terug gives the flight back;
//   5. Stop vliegen: the panel goes, the setting is stored off, the kart stands where it took off with the chase camera
//      reset behind it (race-simulation.js:630), the game's time goes on from where it stood and Up drives it away.
// Screenshots in evidence/frames/flight/ (airborne.png to compare with ../RedCat Superkarts/evidence/free-flight/
// airborne.png), results in evidence/checks/flight-browser.json. Needs the dev server (tools/serve.mjs) and Playwright.
//   node tools/check-flight.mjs
import assert from 'node:assert/strict';
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const { chromium } = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
const BASE = process.env.RCSK_MENU_URL || 'http://127.0.0.1:4190/';
const OUT = join(ROOT, 'evidence', 'frames', 'flight');
mkdirSync(OUT, { recursive: true });
const PANEL_TEXT = 'Vrij vliegen — race gepauzeerd. Rijtoetsen: bewegen en draaien · Spatie: omhoog · C: omlaag.';
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'] });
const page = await browser.newPage({ viewport: { width: 1024, height: 768 } });
const report = { checks: [], errors: [], log: [] };
const t0 = Date.now();
const note = (s) => { const line = ((Date.now() - t0) / 1000).toFixed(1).padStart(6) + 's ' + s; report.log.push(line); console.log(line); };
page.on('pageerror', (e) => report.errors.push('pageerror ' + e.message));
page.on('console', (m) => { if (m.type() === 'error') report.errors.push('console ' + m.text()); });
// a scripted standard pad (as tools/check-touch-pad.mjs): LB (4) and RB (5) lift and lower while flying
await page.addInitScript(() => {
  const pad = { id: 'test pad (STANDARD GAMEPAD)', index: 0, connected: true, mapping: 'standard', timestamp: 0,
    axes: [0, 0, 0, 0], buttons: Array.from({ length: 17 }, () => ({ pressed: false, touched: false, value: 0 })) };
  window.__press = (n, v) => { pad.buttons[n].value = v; pad.buttons[n].pressed = v > 0.5; };
  navigator.getGamepads = () => [pad];
});

const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const shot = (name) => page.screenshot({ path: join(OUT, name + '.png') });
/**
 * The pixels that are orange as the HUD's lettering (as "pauze", the JS port's shots/js-flight-paused.png: about 250,
 * 140, 0) in screenshot b and not in screenshot a, in the middle of the screen (x 25..75%, y 25..65%: below the flight
 * panel, which steps aside in a pause), decoded on the page.
 */
const newOrange = (a, b) => page.evaluate(async ([pa, pb]) => {
  const pixels = async (b64) => {
    const img = await createImageBitmap(await (await fetch('data:image/png;base64,' + b64)).blob());
    const c = new OffscreenCanvas(img.width, img.height), g = c.getContext('2d');
    g.drawImage(img, 0, 0);
    return g.getImageData(Math.round(img.width * 0.25), Math.round(img.height * 0.25), Math.round(img.width * 0.5), Math.round(img.height * 0.4)).data;
  };
  const A = await pixels(pa), B = await pixels(pb);
  const isOrange = (d, k) => d[k] > 200 && d[k + 1] > 90 && d[k + 1] < 190 && d[k + 2] < 70;
  let n = 0;
  for (let k = 0; k < B.length; k += 4) if (isOrange(B, k) && !isOrange(A, k)) n++;
  return n;
}, [a.toString('base64'), b.toString('base64')]);
/**
 * The pixels of screenshot b that differ from a (a channel by 32 or more) with all eight neighbours, outside the boxes
 * ({ x, y, width, height }, page pixels; the flight panel and the lift buttons, which step aside in a pause) and
 * outside the "pauze" notice (the box around b's orange lettering that a lacks in the upper middle, 8 pixels wider each
 * way), decoded on the page; with that box. The neighbours leave out the edges a camera still settling by a fraction
 * of a pixel speckles (1,413 single pixels, 28 with their neighbours, in the pictures of 2026-11-25); a kart part
 * missing is a blob.
 */
const diffOutside = (a, b, boxes) => page.evaluate(async ([pa, pb, boxes]) => {
  const pixels = async (b64) => {
    const img = await createImageBitmap(await (await fetch('data:image/png;base64,' + b64)).blob());
    const c = new OffscreenCanvas(img.width, img.height), g = c.getContext('2d');
    g.drawImage(img, 0, 0);
    return g.getImageData(0, 0, img.width, img.height);
  };
  const A = await pixels(pa), B = await pixels(pb), w = A.width, h = A.height;
  const isOrange = (d, k) => d[k] > 200 && d[k + 1] > 90 && d[k + 1] < 190 && d[k + 2] < 70;
  const n0 = { x0: w, y0: h, x1: -1, y1: -1 };
  const newOrange = (x, y) => { const k = (y * w + x) * 4; return isOrange(B.data, k) && !isOrange(A.data, k); };
  for (let y = Math.round(h * 0.2); y < Math.round(h * 0.5); y++) for (let x = Math.round(w * 0.2); x < Math.round(w * 0.8); x++) {
    // the lettering's strokes: new orange with its four neighbours (no speckle widens the box)
    if (newOrange(x, y) && newOrange(x - 1, y) && newOrange(x + 1, y) && newOrange(x, y - 1) && newOrange(x, y + 1)) {
      n0.x0 = Math.min(n0.x0, x); n0.y0 = Math.min(n0.y0, y); n0.x1 = Math.max(n0.x1, x); n0.y1 = Math.max(n0.y1, y);
    }
  }
  const notice = n0.x1 < 0 ? null : { x: n0.x0 - 8, y: n0.y0 - 8, width: n0.x1 - n0.x0 + 17, height: n0.y1 - n0.y0 + 17 };
  const out = (x, y) => [...boxes, ...(notice ? [notice] : [])].every((r) => x < r.x || y < r.y || x >= r.x + r.width || y >= r.y + r.height);
  const D = new Uint8Array(w * h);
  for (let k = 0; k < w * h; k++) D[k] = [0, 1, 2].some((c) => Math.abs(A.data[k * 4 + c] - B.data[k * 4 + c]) >= 32) ? 1 : 0;
  let n = 0;
  for (let y = 1; y < h - 1; y++) for (let x = 1; x < w - 1; x++) {
    let all = 1;
    for (let j = -1; j <= 1 && all; j++) for (let i = -1; i <= 1 && all; i++) all = D[(y + j) * w + x + i];
    if (all && out(x, y)) n++;
  }
  return { n, notice };
}, [a.toString('base64'), b.toString('base64'), boxes]);
const until = (fn, arg, timeout = 120000) => page.waitForFunction(fn, arg, { timeout, polling: 50 });
// the runner's shared words and its last stats (twice a second; flight: source/host/free-flight.js state())
const game = () => page.evaluate(() => {
  const r = window.rcsk.runner, c = r.ctrl;
  return { active: r.active, ticks: Atomics.load(c, 3), phase: Atomics.load(c, 4), paused: Atomics.load(c, 2), waiting: Atomics.load(c, 15) === 1,
    flightWord: Atomics.load(c, 13), flying: Atomics.load(c, 16) === 1, menu: r.menuHeld, stats: window.__stats || null, audio: r.audioState(),
    panel: !document.getElementById('flight-controls').hidden, lift: !document.getElementById('flight-touch').hidden, canvas: !document.getElementById('game').hidden,
    page: window.rcsk.state.page };
});
/** Fresh stats: waits for one posted after now. */
const fresh = async () => { const n = await page.evaluate(() => (window.__statsN || 0)); await until((k) => (window.__statsN || 0) > k + 1, n, 10000); return game(); };
async function check(name, fn) {
  try { await fn(); report.checks.push({ name, ok: true }); note('ok   ' + name); }
  catch (e) { report.checks.push({ name, ok: false, error: e.message.split('\n')[0] }); note('FAIL ' + name + ': ' + e.message.split('\n')[0]); await shot('fail-' + report.checks.length).catch(() => {}); }
}
const pose = (g) => g.stats.flight;

try {
  await page.goto(BASE + '?skipIntro');
  await page.waitForSelector('[data-form=TFRMMAIN]', { timeout: 60000 });
  await page.evaluate(() => {
    for (const k of Object.keys(localStorage)) if (k.startsWith('rcsk.')) localStorage.removeItem(k);
    localStorage.setItem('rcsk.settings.v1', JSON.stringify({ freeFlight: true, touch: 'on' }));
  });
  await page.goto(BASE + '?drive=0&skipIntro');
  await until(() => window.rcsk?.runner?.active);
  await page.evaluate(() => { window.rcsk.runner.on('stats', (d) => { window.__stats = d; window.__statsN = (window.__statsN || 0) + 1; }); });

  let takeoff = null;
  await check('the panel and Omhoog/Omlaag show after green, with the JS port\'s text and buttons', async () => {
    await until(() => !document.getElementById('flight-controls').hidden, null, 240000);
    const g = await fresh();
    const panel = await page.evaluate(() => ({ text: document.querySelector('#flight-controls p').textContent,
      buttons: [...document.querySelectorAll('#flight-controls button')].map((b) => b.textContent),
      lift: [...document.querySelectorAll('#touch-controls #flight-touch button')].map((b) => b.textContent) }));
    note('take-off ' + JSON.stringify({ ticks: g.ticks, phase: g.phase, flight: pose(g), replay: g.stats.replay }));
    await shot('flight-start');
    // every kart's wheels and driver put back before each flight render (source/host/render-replay.js), none drawn off
    // its body (before it the opponents were drawn without them, evidence/frames/flight/flight-start.png of 2026-11-25)
    assert.ok(g.stats.replay && g.stats.replay.kartsRestored > 0 && g.stats.replay.displaced === 0, 'replay ' + JSON.stringify(g.stats.replay));
    assert.equal(panel.text, PANEL_TEXT);
    assert.deepEqual(panel.buttons, ['Instellingen', 'Stop vliegen']);
    assert.deepEqual(panel.lift, ['Omhoog', 'Omlaag']);
    assert.ok(g.flying && g.flightWord === 1 && g.phase === 0 && g.lift && pose(g).active, JSON.stringify(g));
    takeoff = pose(g).takeoff;
  });

  await check('Up and Space for 1 s: up and forward, passes run, phase 0, the game\'s time stands still', async () => {
    const a = await fresh();
    await page.keyboard.down('ArrowUp'); await page.keyboard.down('Space');
    await wait(1000);
    await shot('airborne');
    await page.keyboard.up('Space'); await page.keyboard.up('ArrowUp');
    const b = await fresh();
    const pa = pose(a), pb = pose(b);
    note(`moved ${JSON.stringify({ from: [pa.x, pa.y, pa.z], to: [pb.x, pb.y, pb.z], ticks: b.ticks - a.ticks, gameMs: [pa.gameMs, pb.gameMs] })}`);
    assert.ok(pb.y - pa.y > 150, 'rose ' + (pb.y - pa.y));
    assert.ok(Math.hypot(pb.x - pa.x, pb.z - pa.z) > 300, 'forward ' + Math.hypot(pb.x - pa.x, pb.z - pa.z));
    assert.ok(b.ticks - a.ticks >= 30 && b.phase === 0 && b.flying);
    assert.equal(pb.gameMs, pa.gameMs);
    assert.deepEqual(pb.kart, [pb.x, pb.y, pb.z]);
  });

  await check('sound effects held, the music plays on', async () => {
    const g = await game();
    note('audio ' + JSON.stringify(g.audio));
    assert.equal(g.audio.effects, 0);
    assert.ok(g.audio.music.playing || !g.audio.music.loaded, JSON.stringify(g.audio.music));
  });

  await check('the pad\'s LB lifts and RB lowers; Omhoog and Omlaag do too', async () => {
    const y = async () => pose(await fresh()).y;
    const y0 = await y();
    await page.evaluate(() => window.__press(4, 1)); await wait(600); await page.evaluate(() => window.__press(4, 0));
    const y1 = await y();
    await page.evaluate(() => window.__press(5, 1)); await wait(600); await page.evaluate(() => window.__press(5, 0));
    const y2 = await y();
    const up = await page.locator('#flight-touch button').nth(0).boundingBox(), down = await page.locator('#flight-touch button').nth(1).boundingBox();
    await page.mouse.move(up.x + up.width / 2, up.y + up.height / 2); await page.mouse.down(); await wait(600); await page.mouse.up();
    const y3 = await y();
    await page.mouse.move(down.x + down.width / 2, down.y + down.height / 2); await page.mouse.down(); await wait(600); await page.mouse.up();
    const y4 = await y();
    note(`lift ${[y0, y1, y2, y3, y4].join(' -> ')}`);
    assert.ok(y1 - y0 > 100 && y2 - y1 < -100 && y3 - y2 > 100 && y4 - y3 < -100);
    const held = (await page.evaluate(() => window.rcsk.runner.inputState().held));
    assert.ok(!held.includes(0x20) && !held.includes(0x43), 'held ' + held);
  });

  await check('P: the game\'s own pause shows "pauze", the panel steps aside; a key resumes the flight without it', async () => {
    const lap0 = pose(await fresh()).lapMs;
    const before = await page.screenshot({ path: join(OUT, 'flight-before-pause.png') });
    const aside = [await page.locator('#flight-controls').boundingBox(), await page.locator('#flight-touch').boundingBox()].filter(Boolean);
    await page.keyboard.press('KeyP');
    await until(() => Atomics.load(window.rcsk.runner.ctrl, 15) === 1, null, 10000);
    await wait(300);
    const p = await game();
    const pausedShot = await page.screenshot({ path: join(OUT, 'flight-pause.png') });
    const paused = await newOrange(before, pausedShot);
    // the flight pause's picture is the flight's with the notice (its render runs as a pause render, render-replay.js
    // again()): nothing else may change, the flying kart's wheels and driver included (before it they went missing)
    const outside = await diffOutside(before, pausedShot, aside);
    note(`flight pause against the picture before P: ${outside.n} pixels differ (with their neighbours) outside the panel, the lift buttons and the notice ${JSON.stringify(outside.notice)}`);
    assert.ok(p.waiting && !p.panel && p.flying, JSON.stringify(p));
    await page.keyboard.press('KeyN');
    await until(() => Atomics.load(window.rcsk.runner.ctrl, 15) === 0, null, 10000);
    await wait(500);
    const q = await fresh();
    const after = await newOrange(before, await page.screenshot({ path: join(OUT, 'flight-resumed.png') }));
    note(`orange lettering in the middle that was not there before P: paused ${paused}, after ${after} pixels; lap timer ${lap0} -> ${pose(q).lapMs} ms`);
    assert.ok(!q.waiting && q.panel && q.flying && q.phase === 0, JSON.stringify(q));
    // the notice is drawn before the pause (free-flight.js, HANDLE_GAME's pause tail) and gone after it (0x430610(2))
    assert.ok(paused > 1000, `new orange pixels: paused ${paused}`);
    // the lap time stands still over the pause too (the JS port's flightPausedAt, race-simulation.js:650, :664-667;
    // here the game's own pause takes it out, free-flight.js); the kart and camera may have settled a little, so the
    // picture after it is only held to have far fewer new orange pixels than the notice
    assert.ok(after < paused / 2 && Math.abs(pose(q).lapMs - lap0) <= 1, `after ${after} new orange pixels, lap ${lap0} -> ${pose(q).lapMs}`);
    assert.ok(outside.notice && outside.n <= 100, `the pause picture differs from the flight's in ${outside.n} pixels besides the notice`);
    const rp = q.stats.replay;
    assert.ok(rp && rp.pauseEntries >= 1 && rp.effectsDiffer === 0 && rp.displaced === 0, 'replay ' + JSON.stringify(rp));
  });

  await check('Instellingen: the original settings over the held race; Terug flies on', async () => {
    await page.locator('#flight-controls button', { hasText: 'Instellingen' }).click();
    await page.waitForSelector('[data-form=TFRMOPTIONS]', { timeout: 20000 });
    const a = await game();
    await wait(1000);
    const b = await game();
    await shot('flight-settings');
    note('settings ' + JSON.stringify({ menu: b.menu, paused: b.paused, ticks: [a.ticks, b.ticks], panel: b.panel, canvas: b.canvas, page: b.page }));
    assert.ok(b.menu && b.paused === 1 && b.ticks === a.ticks && !b.panel && !b.canvas && b.page === 'settings');
    await page.locator('[data-native=btnBack]').click();
    await until(() => window.rcsk.state.page === 'driving', null, 20000);
    await wait(600);
    const c = await fresh();
    assert.ok(!c.menu && c.paused === 0 && c.ticks > b.ticks && c.flying && c.panel && c.canvas, JSON.stringify(c));
  });

  await check('Stop vliegen: the panel goes, stored off, the kart where it took off; the race drives on', async () => {
    const a = await fresh();
    await page.locator('#flight-controls button', { hasText: 'Stop vliegen' }).click();
    await until(() => Atomics.load(window.rcsk.runner.ctrl, 16) === 0, null, 20000);
    await wait(100);
    const b = await fresh();
    const stored = await page.evaluate(() => JSON.parse(localStorage.getItem('rcsk.settings.v1')).freeFlight);
    await shot('landed');
    note('landed ' + JSON.stringify({ kart: pose(b).kart, takeoff, eye: pose(b).eye, gameMs: [pose(a).gameMs, pose(b).gameMs], panel: b.panel }));
    assert.ok(!b.flying && !b.panel && !b.lift && b.flightWord === 0 && stored === false);
    assert.ok(Math.hypot(pose(b).kart[0] - takeoff[0], pose(b).kart[2] - takeoff[2]) < 30, 'kart ' + pose(b).kart + ' take-off ' + takeoff);
    // the chase camera reset behind the kart (race-simulation.js:630): 150 back, 20 up, then easing up towards 50 (the
    // stats come some passes later; tools/checks/flight.mjs holds the reset itself to the JS port's)
    const [ex, ey, ez] = pose(b).eye, [kx, ky, kz] = pose(b).kart, back = Math.hypot(ex - kx, ez - kz);
    assert.ok(back > 140 && back < 160 && ey - ky > 15 && ey - ky < 60, `eye ${back.toFixed(1)} back, ${(ey - ky).toFixed(1)} up`);
    assert.ok(pose(b).gameMs > pose(a).gameMs && pose(b).gameMs - pose(a).gameMs < 2000, 'game time ' + pose(a).gameMs + ' -> ' + pose(b).gameMs);
    await page.keyboard.down('ArrowUp'); await wait(1500);
    const c = await fresh();
    await page.keyboard.up('ArrowUp');
    await shot('driving-after');
    note('after ' + JSON.stringify({ kmh: c.stats.kmh, phase: c.phase, kart: pose(c).kart }));
    assert.ok(c.stats.kmh > 30 && c.phase === 0 && !c.flying, JSON.stringify(c.stats));
  });
} catch (e) {
  report.checks.push({ name: 'run', ok: false, error: e.message.split('\n')[0] });
  note('FAIL run: ' + e.message.split('\n')[0]);
  await shot('fail-run').catch(() => {});
}
report.ok = report.checks.every((c) => c.ok) && !report.errors.length;
note(`${report.checks.filter((c) => c.ok).length} of ${report.checks.length} checks passed, ${report.errors.length} page errors`);
for (const e of report.errors) note('  ' + e);
writeFileSync(join(ROOT, 'evidence', 'checks', 'flight-browser.json'), JSON.stringify(report, null, 1));
await browser.close();
process.exit(report.ok ? 0 : 1);
