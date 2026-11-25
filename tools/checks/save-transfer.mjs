#!/usr/bin/env node
// Do the JS reconstruction's saves carry over to the recomp? Both keep them in localStorage under the same keys
// (rcsk.race-save.v1, rcsk.settings.v1, rcsk.selection.v1, rcsk.firsttime.*), with the same code (source/menu/
// race-save.js and settings.js are copies of the JS port's), so on one site (one origin) the recomp reads what the
// JS port wrote. This check makes the saves with the JS port's own menu, served read-only on :4173
// (tools/checks/menu/serve-js-readonly.mjs), adds a finished race and a highscore with the same save code, carries
// every rcsk.* key to the recomp's origin (:4190) as a shared origin would, and checks the recomp's menu shows and
// uses them: the Adventure profile, the highscore, the unlocked countries, the settings, the selection, and the
// records and grid position a race gets. Also a settings object from before showFps (JS port 1.0.2). Then the
// way between two sites (another host or port): the JS port's saves written to a file by the console line
// (source/save-transfer.js EXPORT_SNIPPET), imported on an empty recomp with Meer instellingen → Opslag importeren,
// and the recomp's own Opslag exporteren read back.
//   node tools/checks/menu/serve-js-readonly.mjs &   then   node tools/checks/save-transfer.mjs
import assert from 'node:assert/strict';
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { readRaceSave, writeRaceSave, applyRaceResult, saveHighscore } from '../../source/menu/race-save.js';
import { EXPORT_SNIPPET } from '../../source/save-transfer.js';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const { chromium } = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
const JS = process.env.RCSK_JS_URL || 'http://127.0.0.1:4173/';
const RECOMP = process.env.RCSK_MENU_URL || 'http://127.0.0.1:4190/';
const OUT = join(ROOT, 'evidence', 'checks', 'save-transfer');
mkdirSync(OUT, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'] });
const report = { checks: [], errors: [] };
const check = async (name, fn) => {
  try { await fn(); report.checks.push({ name, ok: true }); console.log('ok  ', name); }
  catch (e) { report.checks.push({ name, ok: false, error: e.message.split('\n')[0] }); console.log('FAIL', name, e.message.split('\n')[0]); }
};
const dump = (page) => page.evaluate(() => Object.fromEntries(Object.keys(localStorage).filter((k) => k.startsWith('rcsk.')).map((k) => [k, localStorage.getItem(k)])));
const open = async (base, init) => {
  const context = await browser.newContext({ viewport: { width: 1024, height: 768 } });
  // the recomp's stand-in race (tools/checks/menu/skeleton-race-runner.js): start() records its config, no race runs
  if (base === RECOMP) await context.route('**/source/race-runner.js', (route) => route.fulfill({ contentType: 'text/javascript', path: join(ROOT, 'tools', 'checks', 'menu', 'skeleton-race-runner.js') }));
  const page = await context.newPage();
  page.on('pageerror', (e) => report.errors.push(base + ' pageerror ' + e.message));
  await page.goto(base + '?skipIntro');
  await page.waitForSelector('[data-form=TFRMMAIN]');
  await page.evaluate((init) => { for (const k of Object.keys(localStorage)) if (k.startsWith('rcsk.')) localStorage.removeItem(k); for (const [k, v] of Object.entries(init || {})) localStorage.setItem(k, v); }, init);
  await page.reload(); await page.waitForSelector('[data-form=TFRMMAIN]');
  return page;
};
// a press waits for its sound (up to 1.5 s) before it acts: wait for the next form before the next press
const btn = (page, n) => page.locator(`[data-native=${n}]`);
const form = (page, n) => page.waitForSelector(`[data-form=${n}]`, { timeout: 20000 });

try {
  // 1. The JS port's own menu writes its saves: an Adventure profile with WhizzKitty, a QuickRace selection,
  //    Meer instellingen (resolution, render scale, shadows off, FPS on, touch on) and Alles ontgrendelen.
  const js = await open(JS);
  await btn(js, 'btnAdventure').click(); await form(js, 'TFRMADVENTUREMAIN');
  await btn(js, 'btnNewPlayer').click(); await form(js, 'TFRMEDITBOX');
  await js.locator('[data-element=edtName]').fill('Rick'); await js.keyboard.press('Enter');
  await form(js, 'TFRMSELECTCHAR');
  await btn(js, 'btnNext').click(); await js.waitForTimeout(1600);
  await btn(js, 'btnOk').click(); await form(js, 'TFRMADVENTBRIEF');
  await btn(js, 'btnBack').click(); await form(js, 'TFRMMAIN');
  await btn(js, 'btnMainOptions').click(); await form(js, 'TFRMOPTIONS');
  await js.locator('[data-native=btnMoreSettings]').click(); await js.waitForSelector('.settings-form');
  await js.selectOption('#resolution', '1280x720');
  await js.locator('#scale').fill('150'); await js.locator('#scale').dispatchEvent('input');
  await js.locator('#surface-shadows').uncheck(); await js.locator('#show-fps').check();
  await js.selectOption('#touch', 'on');
  await js.locator('#unlock-all').click();
  await js.waitForFunction(() => /ontgrendeld en opgeslagen/.test(document.getElementById('unlock-status').textContent));
  await js.locator('.more-settings-accept').click(); await form(js, 'TFRMOPTIONS');
  await btn(js, 'btnOk').click(); await form(js, 'TFRMMAIN');
  await btn(js, 'btnQuickRace').click(); await form(js, 'TFRMSELECTCHAR');
  await btn(js, 'btnNext').click(); await js.waitForTimeout(1600);
  await btn(js, 'btnOk').click(); await form(js, 'TFRMSELECTCOUNTRY');
  await btn(js, 'btnRight').click(); await js.waitForTimeout(1600);
  await btn(js, 'btnBack').click(); await form(js, 'TFRMSELECTCHAR');
  await btn(js, 'btnBack').click(); await form(js, 'TFRMMAIN');
  await js.screenshot({ path: join(OUT, 'js-port-main.png') });
  const written = await dump(js);
  await js.context().close();

  // 2. A finished QuickRace in Nederland and its highscore, through the same save code (the JS port's race-save.js;
  //    a finished race in the JS port needs five driven laps)
  const store = { getItem: (k) => written[k] ?? null, setItem: (k, v) => { written[k] = v; } };
  const save = readRaceSave(store);
  const patch = { PLAYER: { finished: 1, damage: 0, tracktime: 371250, position: 1, EUROSTARS: 0, FASTEST_LAP: 70110 },
    RACERS: { 0: '1,0,369000', 1: '2,2,372000', 2: '3,3,380000', 3: '4,4,390000', 4: '0,1,371250' },
    'BEST TIMES': { LAP_RECORD_E0: 70110, RACE_RECORD_E0: 371250, TIME_CHECK_COUNT_E0: 0 } };
  applyRaceResult(save, patch);
  saveHighscore(save, 0, { name: 'Rick', character: 1, totalRaceMs: 371250, bestLapMs: 70110, difficulty: 1 });
  writeRaceSave(save, store);
  report.jsKeys = Object.keys(written).sort();
  writeFileSync(join(OUT, 'js-port-localStorage.json'), JSON.stringify(written, null, 1) + '\n');

  // 3. The recomp on a page that holds those keys (as on one shared site)
  const rc = await open(RECOMP, written);
  const st = (k) => rc.evaluate((k) => JSON.parse(localStorage.getItem(k)), k);
  await check('every key the JS port wrote is there, unchanged by loading the recomp, and its QuickRace selection is used', async () => {
    const now = await dump(rc);
    for (const k of Object.keys(written)) assert.equal(now[k], written[k], k);
    // the QuickRace selection, before anything here changes it (the Adventure briefing selects the profile's event)
    const sel = (await rc.evaluate(() => window.rcsk.state)).selection, jsSel = JSON.parse(written['rcsk.selection.v1']);
    report.selection = { recomp: sel, js: jsSel };
    assert.deepEqual(sel, jsSel, JSON.stringify(report.selection));
  });
  await check('Adventure shows the JS port\'s profile (Rick, WhizzKitty)', async () => {
    await btn(rc, 'btnAdventure').click(); await form(rc, 'TFRMADVENTUREMAIN'); await rc.waitForTimeout(300);
    assert.equal(await rc.locator('[data-element=lblPlayerName]').innerText(), 'Rick');
    await rc.screenshot({ path: join(OUT, 'recomp-adventure.png') });
    await btn(rc, 'btnOk').click(); await form(rc, 'TFRMADVENTBRIEF');
    const p = (await st('rcsk.race-save.v1')).profiles.find(Boolean);
    assert.equal(p.character, 1);
    await btn(rc, 'btnBack').click(); await form(rc, 'TFRMMAIN');
  });
  await check('the highscore board shows the entry', async () => {
    await btn(rc, 'btnHighscore').click(); await form(rc, 'TFRMHIGHSCORE'); await rc.waitForTimeout(300);
    assert.equal(await rc.locator('[data-element=lblName1]').innerText(), 'Rick');
    await rc.screenshot({ path: join(OUT, 'recomp-highscores.png') });
    await btn(rc, 'btnOk').click(); await form(rc, 'TFRMMAIN');
  });
  await check('settings: Meer instellingen shows the JS port\'s values', async () => {
    const s = (await rc.evaluate(() => window.rcsk.state)).settings;
    assert.deepEqual({ resolution: s.resolution, renderScale: s.renderScale, surfaceShadows: s.surfaceShadows, showFps: s.showFps, touch: s.touch },
      { resolution: '1280x720', renderScale: 150, surfaceShadows: false, showFps: true, touch: 'on' });
    await btn(rc, 'btnMainOptions').click(); await form(rc, 'TFRMOPTIONS');
    await rc.locator('[data-native=btnMoreSettings]').click(); await rc.waitForSelector('.settings-form');
    assert.equal(await rc.locator('#resolution').inputValue(), '1280x720');
    assert.equal(await rc.locator('#surface-shadows').isChecked(), false);
    await rc.screenshot({ path: join(OUT, 'recomp-meer-instellingen.png') });
    await rc.locator('.more-settings-accept').click(); await form(rc, 'TFRMOPTIONS');
    await btn(rc, 'btnBack').click(); await form(rc, 'TFRMMAIN');
  });
  await check('QuickRace: unlocked Frankrijk, and the records and grid position reach the race', async () => {
    await btn(rc, 'btnQuickRace').click(); await form(rc, 'TFRMSELECTCHAR');
    await btn(rc, 'btnOk').click(); await form(rc, 'TFRMSELECTCOUNTRY');
    // to Frankrijk (3), locked in a new save: without the JS port's Alles ontgrendelen the original notice would show
    while (true) {
      const c = await rc.evaluate(() => window.rcsk.state.selection.country);
      if (c === 3) break;
      await btn(rc, c < 3 ? 'btnRight' : 'btnLeft').click();
      await rc.waitForFunction((c) => window.rcsk.state.selection.country !== c, c); await rc.waitForTimeout(300);
    }
    await btn(rc, 'btnOk').click(); await form(rc, 'TFRMCONTROLSETTINGS');
    await btn(rc, 'btnOk').click(); await form(rc, 'TFRMMAIN');
    const cfg = (await rc.evaluate(() => window.rcsk.state)).lastRunnerConfig;
    report.raceConfig = cfg.save;
    assert.equal(cfg.country, 3);
    assert.deepEqual(cfg.save, { bestTimes: { lap_record_e0: 70110, race_record_e0: 371250, time_check_count_e0: 0 }, playerPosition: 1 });
    assert.equal(cfg.settings.resolution, '1280x720');
    assert.deepEqual((await st('rcsk.race-save.v1')).locks, [false, false, false, false, false, false]);
  });
  await rc.context().close();

  // 4. Settings from before the FPS counter (JS port 1.0.2: no showFps key)
  const old = JSON.parse(written['rcsk.settings.v1']); delete old.showFps;
  const rc2 = await open(RECOMP, { ...written, 'rcsk.settings.v1': JSON.stringify(old) });
  await check('settings without showFps (JS port 1.0.2) load with the counter off and the rest kept', async () => {
    const s = (await rc2.evaluate(() => window.rcsk.state)).settings;
    assert.equal(s.showFps, false); assert.equal(s.resolution, '1280x720'); assert.equal(s.surfaceShadows, false);
  });
  await rc2.context().close();

  // 5. Between two sites: a file from the JS port's site, imported on an empty recomp, and exported again
  const js2 = await open(JS, written);
  const [download] = await Promise.all([js2.waitForEvent('download'), js2.evaluate(EXPORT_SNIPPET)]);
  const file = join(OUT, 'js-port-export.json');
  await download.saveAs(file);
  await js2.context().close();
  const rc3 = await open(RECOMP, {});
  await check('import: the JS port\'s file on an empty recomp brings back every key and the menu shows them', async () => {
    await btn(rc3, 'btnMainOptions').click(); await form(rc3, 'TFRMOPTIONS');
    await rc3.locator('[data-native=btnMoreSettings]').click(); await rc3.waitForSelector('.settings-form');
    let asked = '';
    rc3.once('dialog', (d) => { asked = d.message(); d.accept(); });
    await rc3.screenshot({ path: join(OUT, 'recomp-opslag.png'), fullPage: true });
    await Promise.all([rc3.waitForEvent('load'), rc3.locator('#save-file').setInputFiles(file)]);
    await rc3.waitForSelector('[data-form=TFRMMAIN]');
    report.importQuestion = asked;
    assert.match(asked, /avonturen: Rick/);
    const now = await dump(rc3);
    for (const k of Object.keys(written)) assert.deepEqual(JSON.parse(now[k] === '1' ? '1' : now[k]), JSON.parse(written[k] === '1' ? '1' : written[k]), k);
    await btn(rc3, 'btnAdventure').click(); await form(rc3, 'TFRMADVENTUREMAIN'); await rc3.waitForTimeout(300);
    assert.equal(await rc3.locator('[data-element=lblPlayerName]').innerText(), 'Rick');
  });
  await check('export: the recomp\'s file holds the same saves, and a file that is not a save is refused', async () => {
    await rc3.goto(RECOMP + '?skipIntro'); await rc3.waitForSelector('[data-form=TFRMMAIN]');
    await btn(rc3, 'btnMainOptions').click(); await form(rc3, 'TFRMOPTIONS');
    await rc3.locator('[data-native=btnMoreSettings]').click(); await rc3.waitForSelector('.settings-form');
    const [d] = await Promise.all([rc3.waitForEvent('download'), rc3.locator('#save-export').click()]);
    const back = join(OUT, 'recomp-export.json'); await d.saveAs(back);
    const { readFileSync } = await import('node:fs');
    const data = JSON.parse(readFileSync(back, 'utf8'));
    assert.equal(data.format, 'rcsk-saves');
    for (const k of ['rcsk.race-save.v1', 'rcsk.settings.v1', 'rcsk.selection.v1']) assert.deepEqual(JSON.parse(data.keys[k]), JSON.parse(written[k]), k);
    const bad = join(OUT, 'not-a-save.json'); writeFileSync(bad, '{"hello":1}');
    let asked = false; rc3.once('dialog', (dl) => { asked = true; dl.dismiss(); });
    await rc3.locator('#save-file').setInputFiles(bad);
    await rc3.waitForFunction(() => /geen opslag/i.test(document.getElementById('save-status').textContent));
    assert.equal(asked, false);
  });
  await rc3.context().close();
} catch (e) {
  report.checks.push({ name: 'run', ok: false, error: e.message.split('\n')[0] }); console.log('FAIL run', e.message.split('\n')[0]);
} finally {
  writeFileSync(join(OUT, 'result.json'), JSON.stringify(report, null, 1) + '\n');
  const failed = report.checks.filter((c) => !c.ok).length;
  console.log(JSON.stringify({ failed, errors: report.errors, jsKeys: report.jsKeys }));
  if (failed || report.errors.length) process.exitCode = 1;
  await browser.close();
}
