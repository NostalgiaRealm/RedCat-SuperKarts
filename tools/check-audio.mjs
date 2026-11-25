#!/usr/bin/env node
// Sound on the worker page in headless Chromium (source/web/audio.js, source/race-runner.js, source/host/live-volume.js),
// against the JS reconstruction's behaviour. The output's loudness is measured on the master bus (rms) and on the
// music and the effects apart (musicRms, effectsRms; the effects bus holds the engine too). Needs the dev server
// (node tools/serve.mjs) and Playwright (see tools/shot.mjs). Exit code 1 when a check fails or a page throws or
// crashes (checks/page-errors.mjs).
//   start, countdown, driving   effects run, the music track plays, the FPS counter shows (?fps)
//   P pause                     the game's own pause keeps the sound, as the original's 0x42f350 and the JS port's P
//                               (pauseAudio false, main.js:769); the FPS counter hides (JS: shown only in its modes race
//                               and viewer, main.js:865); after Space both are back
//   focus pause                 window blur: "pauze" and silence (the AudioContext suspended), as the JS port's
//                               back('focus') -> DrivingView.suspend() pauses music and effects (main.js:741-747,
//                               driving-view.js:388-402); the FPS counter hides; after Space the sound and the counter
//                               are back
//   hidden page                 the page hidden and shown again: still silent under "pauze" until a key, then sound
//   live effects                in the countdown (?fixed: beeps at passes 225-242, 258-275, 289-305, 320-377) the
//                               effects level set to 0 after the second beep and to 100 after the third: the third beep
//                               is gone from effectsRms (only the engine is left: MOTOR keeps its level, 0x437e30), the
//                               start beep is back (the JS port applies the level at once, driving-view.js:378-383)
//   live music                  music 50: musicRms about 10^(-2450/2000) = 0.06 of before (0x431610: 49 p - 5000);
//                               0: the track paused, musicRms 0; 100: playing again
//   music place                 a 5 s focus pause: the game's music place (dshow.js, worker.js soundUs) keeps its gap
//                               to the page's track, as the JS port's paused <audio> keeps its place (game-audio.js:18)
//   flight focus pause          (?flight) blur while flying: silent; after a key the music plays and the effects stay
//                               held while it flies (the JS port's resume, driving-view.js:404-414)
// Results in evidence/audio/check-audio.json, screenshots next to it.
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { watchPage } from './checks/page-errors.mjs';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const out = join(ROOT, 'evidence', 'audio');
mkdirSync(out, { recursive: true });
const URL0 = process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html';
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'] });
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const log = [];
const failures = [];
const expect = (ok, what, detail) => {
  log.push({ check: what, ok: !!ok, detail });
  console.log((ok ? 'ok   ' : 'FAIL ') + what + (detail !== undefined ? '  ' + JSON.stringify(detail) : ''));
  if (!ok) failures.push(what);
};

async function open(query) {
  const page = await browser.newPage({ viewport: { width: 640, height: 480 } });
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  page.on('console', (m) => { if (m.type() === 'error' || m.type() === 'warning') console.log('[page]', m.type(), m.text()); });
  watchPage(page, (e) => expect(false, 'no page error' + (query ? ` (${query})` : ''), e));
  await page.goto(URL0 + '?fixed&stats&nocheats&fps' + query);
  await page.waitForFunction(() => window.runner && window.gameStats && window.gameStats.ticks >= 1, null, { timeout: 180000 });
  return page;
}
const ticks = (page) => page.evaluate(() => Atomics.load(window.runner.ctrl, 3));
const ticksAtLeast = (page, n) => page.waitForFunction((k) => Atomics.load(window.runner.ctrl, 3) >= k || window.gameStats.crash, n, { timeout: 180000, polling: 20 });
/** The sound now: the loudest of five readings 100 ms apart (rms values), with the runner's state. */
const sample = async (page, what) => {
  let best = null;
  for (let k = 0; k < 5; k++) {
    const s = await page.evaluate(() => {
      const a = window.audioState(), i = window.inputState(), fps = document.getElementById('fps-counter');
      return { ...a, ticks: Atomics.load(window.runner.ctrl, 3), phase: window.gameStats.phase, waiting: i.waiting, flying: i.flying, focusMuted: i.focusMuted, fpsShown: !fps.hidden };
    });
    if (!best) best = s;
    else for (const k2 of ['rms', 'musicRms', 'effectsRms']) best[k2] = Math.max(best[k2], s[k2]);
    await wait(100);
  }
  for (const k2 of ['rms', 'musicRms', 'effectsRms']) best[k2] = +best[k2].toFixed(4);
  console.log('     ' + what.padEnd(24), JSON.stringify(best));
  log.push({ what, ...best });
  return best;
};
const press = async (page, key, ms = 120) => { await page.keyboard.down(key); await wait(ms); await page.keyboard.up(key); };
const setLevels = (page, levels) => page.evaluate((l) => window.runner.applySettings({ ...window.runner.settings, ...l }), levels);

try {
  // --- a race on Nederland: the countdown with live effects, then driving, pauses and live music ---------------
  const page = await open('');
  await page.mouse.click(320, 240);           // a gesture, as a player gives one
  const start = await sample(page, 'start camera');
  expect(start.context === 'running', 'start: the sound runs', { context: start.context });
  // the countdown: effects 0 after beep 2, 100 after beep 3 (passes from CTRL.TICKS, read in the page every 15 ms)
  await ticksAtLeast(page, 240);
  const timeline = await page.evaluate(() => new Promise((done) => {
    const r = window.runner, out = [];
    let off = false, on = false;
    const step = () => {
      const t = Atomics.load(r.ctrl, 3);
      if (!off && t >= 278) { off = true; r.applySettings({ ...r.settings, effects: 0 }); }
      if (!on && t >= 310) { on = true; r.applySettings({ ...r.settings, effects: 1 }); }
      out.push([t, window.audioState().effectsRms]);
      if (t < 378 && !window.gameStats.crash) setTimeout(step, 15); else done(out);
    };
    step();
  }));
  const peak = (a, b) => Math.max(0, ...timeline.filter(([t]) => t >= a && t < b).map(([, r]) => r));
  const beep2 = peak(255, 278), beep3 = peak(286, 308), go = peak(318, 378), floor = peak(279, 286);
  log.push({ what: 'countdown effectsRms peaks', beep2, beep3, go, floor });
  expect(beep2 > 0.15, 'countdown: beep 2 at effects 100 is loud', { beep2 });
  expect(beep3 < beep2 * 0.4, 'live effects 0: beep 3 is gone, the engine is left (MOTOR keeps its level)', { beep3, beep2 });
  expect(go > beep2 * 0.6, 'live effects 100: the start beep is back', { go, beep2 });
  const countdown = await sample(page, 'after the countdown');
  expect(countdown.fpsShown, 'FPS counter shows while racing');

  await page.keyboard.down('ArrowUp');
  await ticksAtLeast(page, 500);
  const driving = await sample(page, 'driving');
  expect(driving.context === 'running' && driving.music.playing && driving.effects > 0 && driving.rms > 0.02, 'driving: effects and music play', driving);
  await page.keyboard.up('ArrowUp');

  // P: the game's pause keeps the sound, hides the FPS counter
  await press(page, 'KeyP');
  await wait(1500);
  const paused = await sample(page, 'P pause');
  await page.screenshot({ path: join(out, 'p-pause.png') });
  expect(paused.waiting && paused.context === 'running' && paused.music.playing && paused.rms > 0.01, 'P pause: the sound plays on', paused);
  expect(!paused.fpsShown, 'P pause: FPS counter hidden');
  await press(page, 'Space');
  await wait(1500);
  const afterP = await sample(page, 'after the P pause');
  expect(!afterP.waiting && afterP.context === 'running' && afterP.fpsShown, 'after the P pause: racing, sound, FPS counter', afterP);

  // focus: blur -> "pauze", silent, no FPS counter; Space -> sound and counter back
  await page.evaluate(() => window.dispatchEvent(new Event('blur')));
  await wait(1500);
  const focus = await sample(page, 'focus pause');
  await page.screenshot({ path: join(out, 'focus-pause.png') });
  // silence = the AudioContext suspended (its analysers keep their last 2048 samples, so rms is not 0 then)
  expect(focus.waiting && focus.focusMuted && focus.context === 'suspended', 'focus pause: "pauze" and silence (AudioContext suspended)', focus);
  expect(!focus.fpsShown, 'focus pause: FPS counter hidden');
  // a press beside the picture (the runner's unlock on window) does not bring the sound back; one on the picture
  // would end the pause, as the JS port's main.js:851 does
  await page.evaluate(() => window.dispatchEvent(new PointerEvent('pointerdown', { bubbles: true })));
  await wait(300);
  const clicked = await sample(page, 'focus pause, clicked');
  expect(clicked.focusMuted && clicked.context === 'suspended', 'focus pause: a pointer press on the page leaves it silent', clicked);
  await press(page, 'Space');
  await wait(1500);
  const afterFocus = await sample(page, 'after the focus pause');
  expect(!afterFocus.waiting && !afterFocus.focusMuted && afterFocus.context === 'running' && afterFocus.music.playing && afterFocus.rms > 0.01, 'after the focus pause: the sound is back', afterFocus);
  expect(afterFocus.fpsShown, 'after the focus pause: FPS counter shows');

  // the page hidden and shown again: still "pauze" and silent until a key
  await page.evaluate(() => {
    window.__hidden = true;
    Object.defineProperty(document, 'hidden', { configurable: true, get: () => window.__hidden });
    document.dispatchEvent(new Event('visibilitychange'));
  });
  await wait(500);
  await page.evaluate(() => { window.__hidden = false; document.dispatchEvent(new Event('visibilitychange')); });
  await page.waitForFunction(() => window.inputState().waiting, null, { timeout: 10000 }).catch(() => {});
  await wait(800);
  const back = await sample(page, 'hidden page shown again');
  await page.screenshot({ path: join(out, 'hidden-back.png') });
  expect(back.waiting && back.focusMuted && back.context === 'suspended', 'hidden page shown again: "pauze" and still silent', back);
  await press(page, 'Space');
  await wait(1500);
  const afterHidden = await sample(page, 'after the hidden page');
  expect(!afterHidden.waiting && afterHidden.context === 'running' && afterHidden.rms > 0.01, 'after a key: the sound is back', afterHidden);

  // live music: 50, 0, 100
  const m100 = await sample(page, 'music 100');
  await setLevels(page, { music: 0.5 });
  await wait(800);
  const m50 = await sample(page, 'music 50');
  expect(m50.music.volume === -2550 && m50.musicRms < m100.musicRms * 0.25 && m50.musicRms > 0, 'live music 50: -2550 hundredths, quieter', { before: m100.musicRms, after: m50.musicRms });
  await setLevels(page, { music: 0 });
  await wait(800);
  const m0 = await sample(page, 'music 0');
  expect(!m0.music.playing && m0.musicRms === 0, 'live music 0: the track paused, silent', m0.music);
  await setLevels(page, { music: 1 });
  await wait(800);
  const mBack = await sample(page, 'music 100 again');
  expect(mBack.music.playing && mBack.music.volume === -100 && mBack.musicRms > m50.musicRms * 3, 'live music 100: playing again', { musicRms: mBack.musicRms });

  // the music's place over a 5 s focus pause: the game's (dshow.js on the sound's clock, posted with the worker's stats
  // and carried to now) against the page's track (audio.js, its context's time); their gap stays as it was, as the JS
  // port's paused <audio> keeps its place (game-audio.js:18). Before the sound's clock (worker.js soundUs) the game's
  // place ran on through the pause loop and the gap grew by the pause.
  const place = async () => {
    await page.waitForFunction(() => { const s = window.gameStats.sound; return s && s.music !== null && performance.timeOrigin + performance.now() - s.at < 40; }, null, { timeout: 10000, polling: 5 }).catch(() => {});
    return page.evaluate(() => {
      const s = window.gameStats.sound, a = window.audioState(), now = performance.timeOrigin + performance.now();
      const game = s.music + (now - s.at) / 1000;
      return { game: +game.toFixed(3), page: a.music.position, gap: +(game - a.music.position).toFixed(3), held: s.heldSeconds };
    });
  };
  await wait(1500);
  const p0 = await place();
  await page.evaluate(() => window.dispatchEvent(new Event('blur')));
  await wait(5000);
  await press(page, 'Space');
  await page.waitForFunction(() => !window.inputState().waiting && !window.inputState().focusMuted, null, { timeout: 10000 }).catch(() => {});
  await wait(1000);
  const p1 = await place();
  log.push({ what: 'music place over a 5 s focus pause', before: p0, after: p1 });
  console.log('     music place'.padEnd(29), JSON.stringify({ before: p0, after: p1 }));
  expect(p1.held - p0.held > 4.5 && Math.abs(p1.gap - p0.gap) < 1, 'a 5 s focus pause: the game\'s music place keeps its gap to the page\'s track (the held time left out of the sound\'s clock)',
    { gapBefore: p0.gap, gapAfter: p1.gap, held: +(p1.held - p0.held).toFixed(3) });
  await page.close();

  // --- free flight: a focus pause is silent; after it the music plays, the effects stay held ------------------
  const fly = await open('&flight');
  await fly.mouse.click(320, 240);
  await fly.waitForFunction(() => window.inputState().flying, null, { timeout: 180000 });
  await wait(1500);
  const flying = await sample(fly, 'flying');
  expect(flying.music.playing && flying.effectsRms < 0.01, 'flying: the music plays, the effects are held', flying);
  await fly.evaluate(() => window.dispatchEvent(new Event('blur')));
  await wait(1500);
  const flyFocus = await sample(fly, 'flight focus pause');
  await fly.screenshot({ path: join(out, 'flight-focus-pause.png') });
  expect(flyFocus.waiting && flyFocus.focusMuted && flyFocus.context === 'suspended' && !flyFocus.fpsShown, 'flight focus pause: "pauze", silent, no FPS counter', flyFocus);
  await press(fly, 'KeyX');
  await wait(1500);
  const flyBack = await sample(fly, 'flight after the pause');
  expect(!flyBack.waiting && flyBack.flying && flyBack.context === 'running' && flyBack.music.playing && flyBack.musicRms > 0.01 && flyBack.effectsRms < 0.01,
    'flight after the pause: music back, effects still held', flyBack);
  await fly.close();
} catch (e) {
  expect(false, 'the check ran', e.message.split('\n')[0]);
}
writeFileSync(join(out, 'check-audio.json'), JSON.stringify(log, null, 1));
await browser.close();
console.log(failures.length ? `${failures.length} failed` : 'all passed');
process.exitCode = failures.length ? 1 : 0;
