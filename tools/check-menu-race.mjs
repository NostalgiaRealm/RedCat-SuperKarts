#!/usr/bin/env node
// The whole game on the menu page with the real race runner, in headless Chromium:
//   1. QuickRace (RedCat, Nederland, Landenrace): the menu's loading screen, the recompiled race, the finish through
//      the race's own cheat Ctrl+F+I (0x429a90), the debrief, the highscore name, the board and the records saved;
//   2. a second QuickRace gets those records and the grid position; a quick Esc tap and J (key presses of a few ms,
//      the minimum hold) quit it, and the menu saves the unfinished result;
//   3. Adventure: a new profile, the briefing, the event's race finished by the cheat, the debrief, the adventure
//      result (the cheat puts the player last: the original "3rd place or better" notice, the highscore name) and
//      the briefing again. (A won event's progress is covered by tools/checks/menu/check-menu.mjs with a recorded
//      patch; the cheat's tracktime 0 also makes a 0:00:00 highscore entry, which a real race never does.)
// Screenshots and results in evidence/frames/menu-race/. Needs the dev server (tools/serve.mjs) and Playwright. Exit
// code 1 when a check fails or the page reported an error (report.errors: thrown, console.error, a response >= 400).
//   node tools/check-menu-race.mjs
import assert from 'node:assert/strict';
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const { chromium } = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
const BASE = process.env.RCSK_MENU_URL || 'http://127.0.0.1:4190/';
const OUT = join(ROOT, 'evidence', 'frames', 'menu-race');
mkdirSync(OUT, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'] });
const page = await browser.newPage({ viewport: { width: 1024, height: 768 } });
const report = { checks: [], forms: {}, errors: [], log: [] };
const t0 = Date.now();
const note = (s) => { const line = ((Date.now() - t0) / 1000).toFixed(1).padStart(6) + 's ' + s; report.log.push(line); console.log(line); };
page.on('pageerror', (e) => report.errors.push('pageerror ' + e.message));
page.on('console', (m) => { if (m.type() === 'error') report.errors.push('console ' + m.text()); });
page.on('response', (r) => { if (r.status() >= 400) report.errors.push(r.status() + ' ' + r.url()); });

const form = (name, timeout = 30000) => page.waitForSelector(`[data-form=${name}]`, { timeout });
const btn = (name) => page.locator(`[data-native=${name}]`);
const shot = (name) => page.screenshot({ path: join(OUT, name + '.png') });
const state = () => page.evaluate(() => window.rcsk.state);
const store = (key) => page.evaluate((k) => JSON.parse(localStorage.getItem(k)), key);
const currentForm = () => page.evaluate(() => document.querySelector('#screen:not([hidden]) [data-form]')?.dataset.form || null);
const game = () => page.evaluate(() => { const r = window.rcsk.runner; return { active: r.active, ticks: Atomics.load(r.ctrl, 3), phase: Atomics.load(r.ctrl, 4), waiting: Atomics.load(r.ctrl, 15) === 1 }; });
const until = (fn, arg, timeout = 120000) => page.waitForFunction(fn, arg, { timeout, polling: 50 });
async function check(name, fn) {
  try { await fn(); report.checks.push({ name, ok: true }); note('ok   ' + name); }
  catch (e) { report.checks.push({ name, ok: false, error: e.message.split('\n')[0] }); note('FAIL ' + name + ': ' + e.message.split('\n')[0]); await shot('fail-' + report.checks.length).catch(() => {}); }
}
// From the start info's OK to the race running on the canvas (the runner's onRunning), then to the racing phase
async function raceRunning(tag) {
  // the menu's loading screen shows until the game's own copy of it is on the canvas (onRunning, about 0.5 s)
  await until(() => window.rcsk.state.page === 'loading');
  const loading = await page.evaluate(() => ({ form: document.querySelector('#screen [data-form]')?.dataset.form || null, screen: !document.getElementById('screen').hidden, canvas: !document.getElementById('game').hidden }));
  await shot(tag + '-loading-menu');
  await page.waitForTimeout(1500);
  await shot(tag + '-loading-game');
  await until(() => window.rcsk.state.page === 'driving', null, 240000);
  const running = await page.evaluate(() => ({ screen: !document.getElementById('screen').hidden, canvas: !document.getElementById('game').hidden }));
  // the start camera and the countdown (phase 1) take about 335 passes; the cheat works in phase 0
  await until(() => { const r = window.rcsk.runner; return Atomics.load(r.ctrl, 4) === 0 && Atomics.load(r.ctrl, 3) >= 340; }, null, 120000);
  note(tag + ': racing ' + JSON.stringify(await game()));
  return { loading, running };
}
async function finishByCheat(tag) {
  await page.keyboard.down('ArrowUp'); await page.waitForTimeout(1500); await page.keyboard.up('ArrowUp');
  await shot(tag + '-race');
  await page.keyboard.down('Control'); await page.keyboard.down('KeyF'); await page.keyboard.down('KeyI');
  await page.waitForTimeout(150);
  await page.keyboard.up('KeyI'); await page.keyboard.up('KeyF'); await page.keyboard.up('Control');
  await until(() => Atomics.load(window.rcsk.runner.ctrl, 4) === 3, null, 20000);
  await page.waitForTimeout(2500);
  await shot(tag + '-finish');
  await form('TFRMDEBRIEF', 60000);
  await page.waitForTimeout(400);
  await shot(tag + '-debrief');
}
// Clicks through the original notices and the highscore name until one of the given forms shows
async function through(stops, tag) {
  const seen = [];
  for (let i = 0; i < 12; i++) {
    await page.waitForTimeout(600);
    const f = await currentForm();
    // (the screen the click before left may still show for a moment over a real network: not counted)
    if (f && f !== 'TFRMDEBRIEF' && seen.at(-1) !== f) seen.push(f);
    if (stops.includes(f)) break;
    if (f === 'TFRMREQUESTER' || f === 'TFRMEDITBOX') {
      await shot(`${tag}-${seen.length}-${f.toLowerCase()}`);
      await btn('btnOk').click().catch(() => {});
      // a press waits for its sound before it acts (up to 1.5 s): wait for the next form, or a second click would
      // land on the next form's OK
      await until((f) => (document.querySelector('#screen:not([hidden]) [data-form]')?.dataset.form || null) !== f, f, 15000).catch(() => {});
    }
  }
  return seen;
}

try {
  // ?cheats: the race's own Ctrl+F+I (0x429a90) answers only with the cheats option (source/host/safeguards.js)
  await page.goto(BASE + '?skipIntro&cheats');
  await form('TFRMMAIN');
  await page.evaluate(() => { for (const k of Object.keys(localStorage)) if (k.startsWith('rcsk.')) localStorage.removeItem(k); });
  await page.reload(); await form('TFRMMAIN');

  await check('QuickRace: the menu starts the recompiled race, the cheat finishes it, debrief and highscore save it', async () => {
    await btn('btnQuickRace').click(); await form('TFRMSELECTCHAR');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');
    await btn('btnOk').click();
    const { loading, running } = await raceRunning('q1');
    report.q1Loading = { loading, running };
    assert.deepEqual(loading, { form: 'RACE_LOADING', screen: true, canvas: true }, JSON.stringify(loading));
    assert.deepEqual(running, { screen: false, canvas: true }, JSON.stringify(running));
    const s = await state();
    assert.equal(s.page, 'driving'); assert.equal(s.racing, true);
    await finishByCheat('q1');
    assert.equal(await page.locator('#game').isHidden(), true);
    const save = await store('rcsk.race-save.v1');
    report.quickSave = { playerPosition: save.playerPosition, bestTimes: save.bestTimes, lastResult: save.lastResult };
    assert.equal(save.lastResult.PLAYER.finished, 1);
    assert.ok(Number.isInteger(save.playerPosition));
    assert.ok(save.bestTimes.race_record_e0 > 0 && save.bestTimes.lap_record_e0 > 0);
    await btn('btnBack').click();
    report.forms.quick = await through(['TFRMMAIN'], 'q1');
    assert.equal(await currentForm(), 'TFRMMAIN');
    const board = (await store('rcsk.race-save.v1')).boards?.[0]?.[0];
    report.quickBoard = board;
    assert.equal(board?.name, 'Speler 1');
    assert.equal(board.totalRaceMs, save.lastResult.PLAYER.tracktime);
  });

  await check('QuickRace again: the saved records reach the race; a quick Esc tap and J quit it', async () => {
    const before = await store('rcsk.race-save.v1');
    await btn('btnQuickRace').click(); await form('TFRMSELECTCHAR');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');
    await btn('btnOk').click();
    await raceRunning('q2');
    const config = (await state()).lastRunnerConfig;
    assert.deepEqual(config.save, { bestTimes: before.bestTimes, playerPosition: before.playerPosition });
    await page.keyboard.press('Escape');                   // down and up at once: the 80 ms minimum hold
    await until(() => Atomics.load(window.rcsk.runner.ctrl, 15) === 1, null, 10000);
    await page.waitForTimeout(1200);                       // the game waits first, then draws its requester
    await shot('q2-requester');
    await page.keyboard.press('KeyJ');
    await form('TFRMMAIN', 60000);
    const save = await store('rcsk.race-save.v1');
    assert.deepEqual(save.lastResult, { PLAYER: { finished: 0 } });
    assert.deepEqual(save.bestTimes, before.bestTimes);
  });

  await check('Adventure: new profile, briefing, the event raced and finished, result processed, next briefing', async () => {
    await btn('btnAdventure').click(); await form('TFRMADVENTUREMAIN');
    await btn('btnNewPlayer').click(); await form('TFRMEDITBOX');
    await page.locator('[data-element=edtName]').fill('Rick');
    await page.keyboard.press('Enter');
    await form('TFRMSELECTCHAR');
    await btn('btnOk').click(); await form('TFRMADVENTBRIEF');
    await page.waitForTimeout(300);
    const slot = (await store('rcsk.race-save.v1')).selectedSlot;
    const profile0 = (await store('rcsk.race-save.v1')).profiles[slot];
    report.adventureBefore = profile0;
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');
    await btn('btnOk').click();
    await raceRunning('a1');
    await finishByCheat('a1');
    await btn('btnOk').click();
    report.forms.adventure = await through(['TFRMADVENTBRIEF', 'TFRMMAIN'], 'a1');
    await page.waitForTimeout(400);
    await shot('a1-next-briefing');
    const profile1 = (await store('rcsk.race-save.v1')).profiles[slot];
    report.adventureAfter = profile1;
    // the cheat finishes the player last (position 4, tracktime 0): the event is not won, so the original notice
    // asks for 3rd place or better, the highscore entry follows, and the briefing shows the same event again
    const last = (await store('rcsk.race-save.v1')).lastResult;
    report.adventureResult = last.PLAYER;
    assert.equal(last.PLAYER.finished, 1);
    assert.deepEqual(report.forms.adventure, ['TFRMREQUESTER', 'TFRMEDITBOX', 'TFRMADVENTBRIEF']);
    assert.equal(await currentForm(), 'TFRMADVENTBRIEF');
    if (last.PLAYER.position > 2) assert.deepEqual(profile1, profile0);
    else assert.notDeepEqual(profile1, profile0);
  });
} finally {
  report.seconds = Math.round((Date.now() - t0) / 1000);
  writeFileSync(join(OUT, 'result.json'), JSON.stringify(report, null, 1) + '\n');
  console.log(JSON.stringify({ failed: report.checks.filter((c) => !c.ok).length, errors: report.errors, forms: report.forms }, null, 1));
  await browser.close();
  // as tools/check-flight.mjs's report.ok (an error thrown out of the try exits 1 by itself)
  if (report.checks.some((c) => !c.ok) || report.errors.length) process.exitCode = 1;
}
