#!/usr/bin/env node
// Touch and gamepad on the worker page in headless Chromium.
//   touch: a phone in landscape (844x390, touch): the wheel dragged up and left drives through the game's analog
//          handler (device 3: steer left, throttle), Stoppen opens the requester (the controls step aside: pause kind
//          2), a tap on its "nee" goes on. P pauses (kind 1): the controls stay shown but inert, as the JS port's (its
//          main.js:763 input.setMode('menu'), :882 hides them only for the requester): a tap on Bonus holds nothing and
//          the pause goes on, a tap on the picture ends it, and the wheel drives again after it.
//   finish: the same phone, Ctrl+F+I (the development page's cheats) to the finish screen (phase 3): a blur holds it
//          with the controls inert, a tap on Rem does not end the hold, a tap on the picture does; then, past its 1.5 s,
//          a tap on Stoppen does nothing (the JS port's Stoppen only asks its quit gate, which has no quit in phases 1, 3
//          and 6: main.js:835-839, native-race-lifecycle.js:107-111), and a tap on the picture holds Space and ends the
//          screen long before its 8 s timeout (the JS port's main.js:850-854; native-race-lifecycle.js:33-38).
//   gameover: the same phone in a Tijdrace (race=1) until the time runs out (phase 6): a tap on Stoppen 1.8 s in does
//          nothing, a tap on the picture leaves.
//   pad:   a scripted standard gamepad (navigator.getGamepads): stick right and RT drive through the analog handler;
//          Start pauses, where X, the D-pad and B do nothing (the JS port's P pause takes only its Enter and P keys) and
//          A resumes; Back does nothing (the JS port maps none); a focus pause (blur), where X does nothing and the
//          stick resumes (the JS port's menu arrows); the requester (Esc): the pointer parked on "nee" by the game, A
//          presses it and the race goes on; the keyboard takes over again; Esc, D-pad left (the pointer on "ja"), A quits.
// Screenshots and results in evidence/frames/input/. Needs the dev server and Playwright (see tools/shot.mjs). Exit code 1
// when a result is false or a page throws or crashes (checks/page-errors.mjs).
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { watchPage } from './checks/page-errors.mjs';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const out = join(ROOT, 'evidence', 'frames', 'input');
mkdirSync(out, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
const URL_ = process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html';
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const results = {};
const pageErrors = [];
const stats = (page) => page.evaluate(() => ({ ...window.gameStats, raceIni: undefined, input: window.inputState() }));
const note = async (page, what) => { const s = await stats(page); console.log(what.padEnd(30), JSON.stringify({ ticks: s.ticks, phase: s.phase, exit: s.exit, device: s.device, steer: s.steer, throttle: s.throttle, kmh: s.kmh, waiting: s.input.waiting, kind: s.input.pauseKind, touch: s.input.touch, inert: s.input.touchInert, held: s.input.held, joy: s.input.joy })); return s; };

// --- touch -------------------------------------------------------------------------------------------------
{
  const page = await browser.newPage({ viewport: { width: 844, height: 390 }, deviceScaleFactor: 2, hasTouch: true, isMobile: true });
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  watchPage(page, (e) => pageErrors.push(e));
  await page.goto(URL_ + '?fixed&stats&touch=1');
  await page.waitForFunction(() => window.gameStats.ticks >= 335, null, { timeout: 180000 });
  const wheel = await page.locator('#touch-wheel').boundingBox();
  await page.mouse.move(wheel.x + wheel.width * 0.2, wheel.y + wheel.height * 0.15);
  await page.mouse.down();
  await wait(1500);
  const t1 = await note(page, 'touch wheel up-left');
  await page.screenshot({ path: join(out, 'touch-driving.png') });
  await page.mouse.up();
  await wait(700);
  const t2 = await note(page, 'touch wheel let go');
  await page.locator('#touch-stop').tap();
  await wait(1500);
  const t3 = await note(page, 'Stoppen');
  await page.screenshot({ path: join(out, 'touch-requester.png') });
  const box = await page.locator('#game').boundingBox();
  const s = Math.min(box.width / 640, box.height / 480);
  await page.touchscreen.tap(box.x + (box.width - 640 * s) / 2 + 485 * s, box.y + (box.height - 480 * s) / 2 + 370 * s);
  await wait(1500);
  const t4 = await note(page, 'tap on nee');
  results.touch = {
    wheelDrivesAnalog: t1.device === 3 && t1.steer < -30 && t1.throttle > 30,
    letGoBackToKeyboard: t2.device === 1,
    stopOpensRequester: t3.input.waiting === true && t3.input.pauseKind === 2 && t3.input.touch === false,
    tapNeeGoesOn: t4.ticks > t3.ticks && t4.input.touch === true && t4.input.touchInert === false,
  };
  // the game's pause on P: the controls stay drawn and inert
  await page.keyboard.down('KeyP'); await wait(300); await page.keyboard.up('KeyP');
  await wait(1200);
  const t5 = await note(page, 'P (pause)');
  await page.screenshot({ path: join(out, 'touch-pause.png') });
  const bonus = await page.locator('#touch-bonus').boundingBox();
  await page.touchscreen.tap(bonus.x + bonus.width / 2, bonus.y + bonus.height / 2);
  await wait(800);
  const t6 = await note(page, 'tap on Bonus in the pause');
  const wheelVisible = await page.locator('#touch-wheel').isVisible();
  // a tap on the picture, above the controls' band
  await page.touchscreen.tap(box.x + box.width / 2, box.y + box.height * 0.3);
  await wait(1000);
  const t7 = await note(page, 'tap on the picture');
  await page.mouse.move(wheel.x + wheel.width * 0.8, wheel.y + wheel.height * 0.15);
  await page.mouse.down();
  await wait(1200);
  const t8 = await note(page, 'touch wheel up-right after');
  await page.mouse.up();
  await wait(300);
  Object.assign(results.touch, {
    pauseKeepsControlsInert: t5.input.waiting === true && t5.input.pauseKind === 1 && t5.input.touch === true && t5.input.touchInert === true && wheelVisible,
    bonusTapInPauseHoldsNothing: t6.input.waiting === true && t6.ticks === t5.ticks && !t6.input.held.includes(0x11) && t6.input.joy[2] === 0,
    tapOnPictureEndsPause: t7.input.waiting === false && t7.ticks > t6.ticks && t7.input.touchInert === false,
    wheelDrivesAfterPause: t8.device === 3 && t8.steer > 30,
  });
  await page.close();
}

// --- finish screen by touch ------------------------------------------------------------------------------------
{
  const page = await browser.newPage({ viewport: { width: 844, height: 390 }, deviceScaleFactor: 2, hasTouch: true, isMobile: true });
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  watchPage(page, (e) => pageErrors.push(e));
  await page.goto(URL_ + '?fixed&stats&touch=1');
  await page.waitForFunction(() => window.gameStats.ticks >= 400, null, { timeout: 180000 });
  for (const k of ['ControlLeft', 'KeyF', 'KeyI']) await page.keyboard.down(k);
  await wait(600);
  for (const k of ['ControlLeft', 'KeyF', 'KeyI']) await page.keyboard.up(k);
  await page.waitForFunction(() => window.gameStats.phase === 3, null, { timeout: 30000 }).catch(() => {});
  const f0 = await note(page, 'finish screen');
  const box = await page.locator('#game').boundingBox();
  const picture = [box.x + box.width / 2, box.y + box.height * 0.3];
  await page.evaluate(() => window.dispatchEvent(new Event('blur')));
  await wait(600);
  const f1 = await note(page, 'blur (focus hold)');
  const rem = await page.locator('#touch-brake').boundingBox();
  await page.touchscreen.tap(rem.x + rem.width / 2, rem.y + rem.height / 2);
  await wait(600);
  const f2 = await note(page, 'tap on Rem in the hold');
  await page.touchscreen.tap(...picture);
  await wait(600);
  const f3 = await note(page, 'tap on the picture');
  await wait(2000);
  const f4 = await note(page, 'past 1.5 s');
  const stop = await page.locator('#touch-stop').boundingBox();
  await page.touchscreen.tap(stop.x + stop.width / 2, stop.y + stop.height / 2);
  await wait(800);
  const f4s = await note(page, 'tap on Stoppen');
  const t0 = Date.now();
  await page.touchscreen.tap(...picture);
  await page.waitForFunction(() => window.gameStats.phase !== 3 || window.gameStats.exit !== null, null, { timeout: 15000, polling: 50 }).catch(() => {});
  const ms = Date.now() - t0;
  const f5 = await note(page, 'tap on the picture');
  results.finish = {
    reachedFinish: f0.phase === 3,
    holdKeepsControlsInert: f1.input.focusHeld === true && f1.input.touch === true && f1.input.touchInert === true,
    remTapKeepsHold: f2.input.focusHeld === true && !f2.input.held.includes(0x12),
    pictureTapEndsHold: f3.input.focusHeld === false && f3.input.touchInert === false && f3.phase === 3,
    stopTapDoesNothing: f4s.phase === 3 && f4s.exit === null && f4s.ticks > f4.ticks && !f4s.input.held.includes(0x1B),
    tapContinuesFinish: f4s.phase === 3 && (f5.phase !== 3 || f5.exit !== null) && ms < 3000,
    msToLeave: ms,
  };
  await page.close();
}

// --- game over by touch ---------------------------------------------------------------------------------------------
{
  const page = await browser.newPage({ viewport: { width: 844, height: 390 }, deviceScaleFactor: 2, hasTouch: true, isMobile: true });
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  watchPage(page, (e) => pageErrors.push(e));
  await page.goto(URL_ + '?fixed&stats&touch=1&race=1&nocheats');
  await page.waitForFunction(() => window.gameStats.phase === 6 || window.gameStats.exit !== null, null, { timeout: 300000, polling: 100 });
  const g0 = await note(page, 'game over (time out)');
  await wait(1800);
  const stop = await page.locator('#touch-stop').boundingBox();
  await page.touchscreen.tap(stop.x + stop.width / 2, stop.y + stop.height / 2);
  await wait(1200);
  const g1 = await note(page, 'tap on Stoppen 1.8 s in');
  await page.screenshot({ path: join(out, 'touch-gameover-stoppen.png') });
  const box = await page.locator('#game').boundingBox();
  await page.touchscreen.tap(box.x + box.width / 2, box.y + box.height * 0.3);
  await page.waitForFunction(() => window.gameStats.exit !== null, null, { timeout: 15000, polling: 50 }).catch(() => {});
  const g2 = await note(page, 'tap on the picture');
  results.gameover = {
    reachedGameOver: g0.phase === 6,
    stopTapDoesNothing: g1.phase === 6 && g1.exit === null && g1.ticks > g0.ticks,
    pictureTapLeaves: g2.exit === 0,
  };
  await page.close();
}

// --- gamepad -----------------------------------------------------------------------------------------------
{
  const page = await browser.newPage({ viewport: { width: 854, height: 480 } });
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  watchPage(page, (e) => pageErrors.push(e));
  await page.addInitScript(() => {
    const pad = { id: 'test pad (STANDARD GAMEPAD)', index: 0, connected: true, mapping: 'standard', timestamp: 0,
      axes: [0, 0, 0, 0], buttons: Array.from({ length: 17 }, () => ({ pressed: false, touched: false, value: 0 })) };
    window.__pad = pad;
    window.__press = (n, v) => { pad.buttons[n].value = v; pad.buttons[n].pressed = v > 0.5; };
    navigator.getGamepads = () => [pad];
  });
  await page.goto(URL_ + '?fixed&stats');
  await page.waitForFunction(() => window.gameStats.ticks >= 335, null, { timeout: 180000 });
  await page.evaluate(() => { window.__pad.axes[0] = 0.6; window.__press(7, 1); });
  await wait(1500);
  const p1 = await note(page, 'pad stick right + RT');
  await page.screenshot({ path: join(out, 'pad-driving.png') });
  await page.evaluate(() => { window.__pad.axes[0] = 0; window.__press(7, 0); });
  await wait(700);
  const p2 = await note(page, 'pad let go');
  const btn = async (n, ms = 150) => { await page.evaluate((k) => window.__press(k, 1), n); await wait(ms); await page.evaluate((k) => window.__press(k, 0), n); };
  await btn(9);
  await wait(1500);
  const p3 = await note(page, 'Start (pause)');
  await btn(2); await wait(500);
  await btn(14); await wait(500);
  await btn(1); await wait(800);
  const p3b = await note(page, 'X, D-pad left, B in the pause');
  await btn(0);
  await wait(1000);
  const p4 = await note(page, 'A (resume)');
  await btn(8);
  await wait(1500);
  const p5 = await note(page, 'Back');
  await page.evaluate(() => window.dispatchEvent(new Event('blur')));
  await wait(1500);
  const f1 = await note(page, 'blur (focus pause)');
  await btn(2); await wait(800);
  const f2 = await note(page, 'X in the focus pause');
  await page.evaluate(() => { window.__pad.axes[0] = 0.9; });
  await wait(1000);
  const f3 = await note(page, 'stick right');
  await page.evaluate(() => { window.__pad.axes[0] = 0; });
  await page.keyboard.down('Escape'); await wait(150); await page.keyboard.up('Escape');
  await wait(1500);
  const r1 = await note(page, 'Esc (requester)');
  await page.screenshot({ path: join(out, 'pad-requester-nee.png') });
  await btn(0);
  await wait(1200);
  const r2 = await note(page, 'A on nee');
  await page.keyboard.down('ArrowUp');
  await wait(1000);
  const p7 = await note(page, 'keyboard ArrowUp');
  await page.keyboard.up('ArrowUp');
  await page.keyboard.down('Escape'); await wait(150); await page.keyboard.up('Escape');
  await wait(1500);
  await btn(14);
  await wait(600);
  const r3 = await note(page, 'requester, D-pad left');
  await page.screenshot({ path: join(out, 'pad-requester-ja.png') });
  await btn(0);
  await page.waitForFunction(() => window.gameStats.exit !== null, null, { timeout: 15000, polling: 50 }).catch(() => {});
  const r4 = await note(page, 'A on ja');
  results.pad = {
    stickAndTriggerDriveAnalog: p1.device === 3 && p1.steer > 30 && p1.throttle > 50,
    letGoBackToKeyboard: p2.device === 1,
    startPauses: p3.input.waiting === true && p3.input.pauseKind === 1,
    xDpadBDoNotResumePPause: p3b.input.waiting === true && p3b.ticks === p3.ticks,
    aResumes: p4.ticks > p3.ticks && !p4.input.waiting,
    backDoesNothing: p5.input.waiting === false && p5.ticks > p4.ticks && !p5.input.held.includes(0x1B),
    focusPauses: f1.input.waiting === true && f1.input.pauseKind === 1 && f1.input.focusMuted === true,
    xDoesNotResumeFocusPause: f2.input.waiting === true && f2.ticks === f1.ticks,
    stickResumesFocusPause: f3.input.waiting === false && f3.ticks > f2.ticks,
    requesterFocusOnNee: r1.input.waiting === true && r1.input.pauseKind === 2 && r1.input.requesterFocus === 'no' && r1.input.mouse[0] === 482 && r1.input.mouse[1] === 369,
    aOnNeeGoesOn: r2.input.waiting === false && r2.ticks > r1.ticks && r2.exit === null,
    keyboardTakesOver: p7.device === 1 && p7.throttle > 0,
    dpadMovesToJa: r3.input.pauseKind === 2 && r3.input.requesterFocus === 'yes' && r3.input.mouse[0] === 207 && r3.input.mouse[1] === 369,
    aOnJaQuits: r4.exit === 0,
  };
  await page.close();
}
writeFileSync(join(out, 'touch-pad.json'), JSON.stringify(results, null, 1));
console.log(JSON.stringify(results));
await browser.close();
const failed = Object.entries(results).flatMap(([g, r]) => Object.entries(r).filter(([, v]) => v === false).map(([k]) => g + '.' + k));
for (const e of pageErrors) console.log('[page error]', e);
if (pageErrors.length) failed.push(pageErrors.length + ' page error(s)');
if (failed.length) { console.log('FAIL', failed.join(' ')); process.exit(1); }
