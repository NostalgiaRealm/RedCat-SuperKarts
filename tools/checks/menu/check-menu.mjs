// Menu checks of the recomp page against the skeleton runner (or any runner): intro, main menu, QuickRace to
// runner.start and back, a finished result through debrief and highscore, Adventure profile and briefing,
// highscores, settings (Geavanceerd, Instellen, Meer instellingen) saved with the JS port's schema, Help, quit prompt,
// keyboard and pad navigation, input ignored during a race.
//   node tools/checks/menu/check-menu.mjs [baseURL] [outDir]   (REAL_RUNNER=1: the real runner, not the skeleton)
// Exit code 1 when a check fails or the page reported an error (report.errors: thrown, console.error, a response >= 400).
import assert from 'node:assert/strict';
import { mkdirSync, writeFileSync } from 'node:fs';
import { join } from 'node:path';
import { dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..', '..');
const { chromium } = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
const BASE = process.argv[2] || 'http://127.0.0.1:4190/';
const OUT = process.argv[3] || join(ROOT, 'evidence', 'frames', 'menu');
mkdirSync(OUT, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required'] });
const context = await browser.newContext({ viewport: { width: 1024, height: 768 } });
// a fake standard gamepad the test can press (navigator.getGamepads)
await context.addInitScript(() => {
  const pad = { id: 'test pad', connected: true, mapping: 'standard', index: 0, axes: [0, 0, 0, 0], buttons: Array.from({ length: 17 }, () => ({ value: 0, pressed: false })) };
  window.__pad = pad;
  window.__press = (n, down) => { pad.buttons[n] = { value: down ? 1 : 0, pressed: down }; };
  navigator.getGamepads = () => [pad];
});
// the skeleton runner, whatever source/race-runner.js holds now (its builder works on it at the same time)
if (!process.env.REAL_RUNNER) await context.route('**/source/race-runner.js', (route) => route.fulfill({ contentType: 'text/javascript', path: fileURLToPath(new URL('./skeleton-race-runner.js', import.meta.url)) }));
const page = await context.newPage();
const report = { base: BASE, checks: [], errors: [] };
page.on('pageerror', (e) => report.errors.push('pageerror ' + e.message));
page.on('console', (m) => { if (m.type() === 'error') report.errors.push('console ' + m.text()); });
page.on('response', (r) => { if (r.status() >= 400) report.errors.push(r.status() + ' ' + r.url()); });
const form = (name) => page.waitForSelector(`[data-form=${name}]`, { timeout: 20000 });
const btn = (name) => page.locator(`[data-native=${name}]`);
const shot = (name) => page.screenshot({ path: join(OUT, name + '.png') });
const state = () => page.evaluate(() => window.rcsk.state);
const store = (key) => page.evaluate((k) => JSON.parse(localStorage.getItem(k)), key);
const settle = () => page.waitForTimeout(250);
async function check(name, fn) {
  try { await fn(); report.checks.push({ name, ok: true }); console.log('ok  ', name); }
  catch (e) { report.checks.push({ name, ok: false, error: e.message, stack: e.stack?.split('\n').slice(1, 3).join(' ') }); console.log('FAIL', name, e.message, e.stack?.split('\n')[1]); await shot('fail-' + report.checks.length);
    await page.evaluate(() => { window.__releaseLoading?.(); }).catch(() => {}); await page.waitForTimeout(2500); await page.keyboard.press('Escape').catch(() => {}); }
}
// Wrap the runner: record start() configs and applySettings() calls; optionally hold a race open or return a patch.
// REAL_RUNNER: a start without a plan stands in for the skeleton's (300 ms, unfinished) instead of a real race, which
// would never end by itself; a planned race shows and hides the canvas as the real start() does (race-runner.js
// showCanvas/hideCanvas, which also set style.display: main.js's $('game').hidden=false alone leaves it invisible).
async function instrument() {
  await page.evaluate((real) => {
    const r = window.rcsk.runner;
    if (r.__wrapped) return;
    r.__wrapped = true; window.__calls = []; window.__applied = []; window.__race = null;
    const start = r.start.bind(r), apply = r.applySettings.bind(r);
    r.applySettings = (s) => { window.__applied.push(JSON.parse(JSON.stringify(s))); return apply(s); };
    r.start = async (config) => {
      const call = { config: JSON.parse(JSON.stringify({ ...config, onProgress: undefined, onRunning: undefined })),
        canvasShown: !document.getElementById('game').hidden, loadingForm: document.querySelector('#screen [data-form]')?.dataset.form || null };
      window.__calls.push(call);
      const plan = window.__race || (real ? { progress: 100, runMs: 300 } : null); window.__race = null;
      if (!plan) return start(config);
      r.active = true; r.showCanvas?.();
      config.onProgress?.(plan.progress ?? 50);
      window.__racePhase = 'loading';
      await new Promise((res) => { window.__releaseLoading = res; setTimeout(res, plan.loadingMs ?? 0); });
      config.onRunning?.(); window.__racePhase = 'running';
      // the real runner reports the race's effects level once it has booted (race-runner.js 'running', onEffects);
      // main.js adopts it there and no longer from the outcome's effectsPercent (main.js:480, :489)
      if (typeof plan.effectsPercent === 'number') config.onEffects?.(plan.effectsPercent);
      call.screenHiddenWhileRunning = document.getElementById('screen').hidden;
      await new Promise((res) => setTimeout(res, plan.runMs ?? 300));
      r.active = false; r.hideCanvas?.(); window.__racePhase = 'done';
      return { patch: plan.patch ?? { PLAYER: { finished: 0 } }, effectsPercent: plan.effectsPercent ?? null, exitCode: 0, error: null };
    };
  }, !!process.env.REAL_RUNNER);
}
const lastCall = () => page.evaluate(() => window.__calls.at(-1));

try {
  await page.goto(BASE);
  await check('intro plays the original intro movie and a key skips it to the main menu', async () => {
    await page.waitForFunction(() => !document.getElementById('intro').hidden && document.getElementById('movie').src.endsWith('assets/media/intro.mp4'));
    const codec = await page.evaluate(() => document.getElementById('movie').canPlayType('video/mp4; codecs="avc1.42E01E, mp4a.40.2"'));
    report.introCodec = codec;
    if (codec) await page.waitForFunction(() => document.getElementById('movie').currentTime > 0.5, null, { timeout: 15000 });
    await shot('01-intro');
    assert.equal((await state()).mode, 'intro');
    await page.keyboard.press('ArrowLeft');            // types nothing: no skip (rcskmenu 0x479cd4)
    await settle();
    assert.equal((await state()).mode, 'intro');
    await page.keyboard.press('x');
    await form('TFRMMAIN');
    assert.equal(await page.locator('#intro').isHidden(), true);
  });
  await instrument();
  await check('main menu shows with its greeting, Avontuur focused', async () => {
    await settle();
    const s = await state();
    assert.equal(s.page, 'main');
    report.mainGreeting = s.menuAudio;
    assert.equal(await page.evaluate(() => document.activeElement?.dataset.native), 'btnAdventure');
    assert.equal(await page.locator('#game').isHidden(), true);
    await shot('02-main');
  });
  await check('keyboard: Right then Enter opens QuickRace character selection; Escape returns', async () => {
    await page.keyboard.press('ArrowRight'); await page.keyboard.press('Enter');
    await form('TFRMSELECTCHAR');
    await page.keyboard.press('Escape');
    await form('TFRMMAIN');
  });
  await check('pad: D-pad right and A open QuickRace; B returns', async () => {
    await btn('btnAdventure').focus();
    const tap = async (n) => { await page.evaluate((n) => window.__press(n, true), n); await page.waitForTimeout(80); await page.evaluate((n) => window.__press(n, false), n); await page.waitForTimeout(80); };
    await tap(15); await tap(0);
    await form('TFRMSELECTCHAR');
    await tap(1);
    await form('TFRMMAIN');
  });
  await check('QuickRace: character, difficulty, country, race type, start info, runner.start with the selection', async () => {
    await btn('btnQuickRace').click(); await form('TFRMSELECTCHAR');
    await btn('btnNext').click(); await page.waitForFunction(() => window.rcsk.state.selection.character === 1);
    await btn('rdoHard').click(); await page.waitForFunction(() => window.rcsk.state.selection.difficulty === 2);
    await shot('03-quickrace-characters');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    await btn('rdoTime').click(); await page.waitForFunction(() => window.rcsk.state.selection.race === 1);
    await shot('04-quickrace-countries');
    await btn('btnRight').click(); await page.waitForFunction(() => window.rcsk.state.selection.country === 1); await page.waitForTimeout(300);
    await btn('btnRight').click(); await page.waitForFunction(() => window.rcsk.state.selection.country === 2); await page.waitForTimeout(300);
    await btn('btnOk').click(); await form('TFRMREQUESTER');              // Groot-Brittannië is locked: the original notice
    await shot('04b-locked-country');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    await btn('btnLeft').click(); await page.waitForFunction(() => window.rcsk.state.selection.country === 1); await page.waitForTimeout(300);
    await btn('btnLeft').click(); await page.waitForFunction(() => window.rcsk.state.selection.country === 0); await page.waitForTimeout(300);
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');         // start info (keyboard, startInfo on)
    assert.equal((await state()).page, 'start-info');
    await shot('05-start-info');
    await page.evaluate(() => { window.__race = { progress: 45, loadingMs: 60000, runMs: 1500 }; });
    await btn('btnOk').click();
    await page.waitForFunction(() => window.__racePhase === 'loading');
    await page.waitForTimeout(400);
    await shot('06-loading');
    const call = await lastCall();
    assert.deepEqual({ country: call.config.country, character: call.config.character, difficulty: call.config.difficulty, raceType: call.config.raceType },
      { country: 0, character: 1, difficulty: 2, raceType: 1 });
    assert.deepEqual(call.config.save, { bestTimes: {} });
    assert.equal(call.config.settings.startInfo, true);
    assert.equal(call.canvasShown, true);
    assert.equal(call.loadingForm, 'RACE_LOADING');
    assert.deepEqual(await store('rcsk.selection.v1'), { character: 1, difficulty: 2, country: 0, race: 1 });
    await page.evaluate(() => window.__releaseLoading());
    await page.waitForFunction(() => window.__racePhase === 'running');
    // during the race the menu ignores keys and the pad
    await page.keyboard.press('Escape'); await page.keyboard.press('Enter');
    await page.evaluate(() => window.__press(1, true)); await page.waitForTimeout(100); await page.evaluate(() => window.__press(1, false));
    const during = await state();
    assert.equal(during.page, 'driving'); assert.equal(during.mode, 'race');
    assert.equal(await page.locator('#screen').isHidden(), true);
    assert.equal(await page.locator('#game').isVisible(), true);
    await shot('07-race-canvas');
    await page.waitForFunction(() => window.__racePhase === 'done');
    await form('TFRMMAIN');                                               // unfinished: back to the main menu
    assert.equal(await page.locator('#game').isHidden(), true);
    const save = await store('rcsk.race-save.v1');
    assert.deepEqual(save.lastResult, { PLAYER: { finished: 0 } });
  });
  await check('skeleton runner itself: start resolves unfinished and the menu returns to the main menu', async () => {
    await btn('btnQuickRace').click(); await form('TFRMSELECTCHAR');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');
    const before = await page.evaluate(() => window.__calls.length);
    await btn('btnOk').click();
    await page.waitForFunction((n) => window.__calls.length === n + 1, before);
    await form('TFRMMAIN');
    assert.equal((await state()).racing, false);
  });
  const finishedPatch = { PLAYER: { finished: 1, damage: 0, tracktime: 183456, position: 0, EUROSTARS: 0, FASTEST_LAP: 35210 },
    RACERS: { 0: '0,1,184000', 1: '2,2,185000', 2: '3,3,186000', 3: '4,4,187000', 4: '1,0,183456' },
    'BEST TIMES': { LAP_RECORD_E0: 35210, RACE_RECORD_E0: 183456 } };
  await check('a finished QuickRace: debrief, highscore name "Speler 1", effects read back, highscore board', async () => {
    await btn('btnQuickRace').click(); await form('TFRMSELECTCHAR');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');
    await page.evaluate((patch) => { window.__race = { patch, effectsPercent: 75, runMs: 100 }; }, finishedPatch);
    await btn('btnOk').click();
    await form('TFRMDEBRIEF');
    await shot('08-debrief');
    const save = await store('rcsk.race-save.v1');
    assert.equal(save.playerPosition, 0);
    assert.equal(save.bestTimes.lap_record_e0, 35210);
    assert.equal((await store('rcsk.settings.v1')).effects, 0.75);
    await btn('btnBack').click();
    await form('TFRMEDITBOX');
    assert.equal(await page.locator('[data-element=edtName]').inputValue(), 'Speler 1');
    await shot('09-highscore-name');
    await btn('btnOk').click();
    await form('TFRMMAIN');
    const board = (await store('rcsk.race-save.v1')).boards[0][0];
    assert.deepEqual(board, { name: 'Speler 1', character: 1, totalRaceMs: 183456, bestLapMs: 35210, difficulty: 2 });
    // the next race gets the saved records and position
    await btn('btnQuickRace').click(); await form('TFRMSELECTCHAR');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');
    await btn('btnOk').click();
    await form('TFRMMAIN');
    const call = await lastCall();
    assert.deepEqual(call.config.save, { bestTimes: { lap_record_e0: 35210, race_record_e0: 183456 }, playerPosition: 0 });
    assert.equal(call.config.settings.effects, 0.75);
  });
  await check('highscores show the entry per country', async () => {
    await btn('btnHighscore').click(); await form('TFRMHIGHSCORE');
    await page.waitForTimeout(300);
    assert.equal(await page.locator('[data-element=lblName1]').innerText(), 'Speler 1');
    await shot('10-highscores');
    // a press waits for its sound and acts only if its button is still on screen (the JS port's button()), so wait
    // for each redraw before the next press
    await btn('btnRight').click(); await page.waitForFunction(() => document.querySelector('[data-element=lblCountryName]')?.textContent === 'DUITSLAND');
    await page.waitForTimeout(300);
    await btn('btnOk').click(); await form('TFRMMAIN');
  });
  await check('Adventure: new profile, character, briefing, Landinfo, start with the event selection', async () => {
    await btn('btnAdventure').click(); await form('TFRMADVENTUREMAIN');
    await shot('11-adventure-empty');
    await btn('btnNewPlayer').click(); await form('TFRMEDITBOX');
    await page.locator('[data-element=edtName]').fill('Rick');
    await shot('12-adventure-name');
    await page.keyboard.press('Enter');
    await form('TFRMSELECTCHAR');
    assert.equal(await btn('btnBack').isDisabled(), true);
    await btn('btnNext').click(); await page.waitForFunction(() => window.rcsk.state.selection.character === 1); await page.waitForTimeout(300);
    await btn('btnNext').click(); await page.waitForFunction(() => window.rcsk.state.selection.character === 2); await page.waitForTimeout(300);
    await shot('13-adventure-characters');
    await btn('btnOk').click(); await form('TFRMADVENTBRIEF');
    await page.waitForTimeout(300);
    await shot('14-briefing');
    const profile = (await store('rcsk.race-save.v1')).profiles.find(Boolean);
    assert.equal(profile.name, 'Rick'); assert.equal(profile.character, 2);
    await btn('btnOverview').click(); await form('TFRMLANDINFO');
    await page.waitForTimeout(300);
    await shot('15-landinfo');
    await btn('btnOk').click(); await form('TFRMADVENTBRIEF');
    const sel = (await state()).selection;
    await btn('btnOk').click(); await form('TFRMCONTROLSETTINGS');
    await btn('btnOk').click();
    await form('TFRMMAIN');
    const call = await lastCall();
    assert.deepEqual({ country: call.config.country, character: call.config.character, difficulty: call.config.difficulty, raceType: call.config.raceType },
      { country: sel.country, character: 2, difficulty: sel.difficulty, raceType: sel.race });
    report.adventureFirstEvent = { country: sel.country, raceType: sel.race, difficulty: sel.difficulty };
  });
  await check('Adventure: an unfinished race keeps the profile; Continue leads back to the briefing', async () => {
    await btn('btnAdventure').click(); await form('TFRMADVENTUREMAIN');
    assert.equal(await page.locator('[data-element=lblPlayerName]').innerText(), 'Rick');
    await btn('btnOk').click(); await form('TFRMADVENTBRIEF');
    await btn('btnBack').click(); await form('TFRMMAIN');
  });
  await check('settings: Instellingen, Instellen (key capture), Geavanceerd, Meer instellingen, saved with the JS schema', async () => {
    await btn('btnMainOptions').click(); await form('TFRMOPTIONS');
    await page.waitForTimeout(300);
    await shot('16-settings');
    // Instellen: capture B for Bonus
    await btn('btnControlsAdvanced').click(); await form('TFRMCONTROLSETTINGS');
    await page.locator('[data-native=lblKEY_USEBONUS], [data-element=lblKEY_USEBONUS]').first().click();
    await page.waitForTimeout(150);
    await page.keyboard.press('KeyB');
    await page.waitForTimeout(150);
    await shot('18-instellen');
    await btn('btnOk').click(); await form('TFRMOPTIONS');
    assert.equal((await store('rcsk.settings.v1')).bindings.bonus, 'KeyB');
    // Geavanceerd: the original display dialog
    await btn('btnAdvanced').click();
    await page.waitForTimeout(300);
    await shot('17-geavanceerd');
    await page.waitForSelector('[data-form=TFRMDISPLAYSETTINGS]');
    await page.locator('[data-form=TFRMDISPLAYSETTINGS] [data-native=btnOk]').click();
    await form('TFRMOPTIONS');
    // radio buttons and start info in the draft
    await btn('rdoGamepad').click(); await page.waitForTimeout(100);
    await btn('chkStartInfo').click(); await page.waitForTimeout(100);
    // Meer instellingen
    await page.locator('[data-native=btnMoreSettings]').click();
    await page.waitForSelector('.settings-form');
    await page.selectOption('#resolution', '1280x720');
    await page.locator('#scale').fill('150'); await page.locator('#scale').dispatchEvent('input');
    await page.locator('#show-fps').check(); await page.locator('#msaa-enabled').check();
    await page.selectOption('#msaa-samples', '8');
    await page.locator('#surface-shadows').uncheck();
    await page.locator('#free-flight').click();
    await page.locator('#deadzone').fill('25'); await page.locator('#deadzone').dispatchEvent('input');
    await page.selectOption('#touch', 'on');
    assert.match(await page.locator('#game-version').innerText(), /^Versie \d+\.\d+\.\d+$/);
    report.version = await page.locator('#game-version').innerText();
    await shot('19-meer-instellingen');
    await page.locator('#unlock-all').click();
    await page.waitForFunction(() => /ontgrendeld en opgeslagen/.test(document.getElementById('unlock-status').textContent));
    assert.deepEqual((await store('rcsk.race-save.v1')).locks, [false, false, false, false, false, false]);
    await page.locator('.more-settings-accept').click();
    await form('TFRMOPTIONS');
    const appliedBefore = await page.evaluate(() => window.__applied.length);
    await btn('btnOk').click(); await form('TFRMMAIN');
    const saved = await store('rcsk.settings.v1');
    assert.deepEqual(Object.keys(saved).sort(), ['bindings', 'controlType', 'deadzone', 'display', 'effects', 'freeFlight', 'fullscreen', 'msaaEnabled', 'msaaSamples', 'music', 'renderScale', 'resolution', 'showFps', 'smoothEngineLights', 'startInfo', 'surfaceShadows', 'touch'].sort());
    assert.deepEqual({ resolution: saved.resolution, renderScale: saved.renderScale, showFps: saved.showFps, msaaEnabled: saved.msaaEnabled, msaaSamples: saved.msaaSamples,
      surfaceShadows: saved.surfaceShadows, freeFlight: saved.freeFlight, deadzone: saved.deadzone, touch: saved.touch, controlType: saved.controlType, startInfo: saved.startInfo },
      { resolution: '1280x720', renderScale: 150, showFps: true, msaaEnabled: true, msaaSamples: 8, surfaceShadows: false, freeFlight: true, deadzone: 0.25, touch: 'on', controlType: 1, startInfo: false });
    const applied = await page.evaluate(() => window.__applied.at(-1));
    assert.ok((await page.evaluate(() => window.__applied.length)) > appliedBefore);
    assert.equal(applied.resolution, '1280x720'); assert.equal(applied.touch, 'on');
    report.savedSettings = saved;
  });
  await check('with a gamepad control type the start info is skipped and settings reach runner.start', async () => {
    await btn('btnQuickRace').click(); await form('TFRMSELECTCHAR');
    await btn('btnOk').click(); await form('TFRMSELECTCOUNTRY');
    for (let c = 1; c <= 3; c++) { await btn('btnRight').click(); await page.waitForFunction((c) => window.rcsk.state.selection.country === c, c); await page.waitForTimeout(300); }
    await btn('btnOk').click();                                            // Frankrijk: unlocked by Alles ontgrendelen
    await form('TFRMMAIN');
    const call = await lastCall();
    assert.equal(call.config.country, 3);
    assert.equal(call.config.settings.msaaSamples, 8); assert.equal(call.config.settings.bindings.bonus, 'KeyB');
  });
  await check('Help opens on the main menu topic and closes back to the menu', async () => {
    await btn('btnMainHelp').click();
    await page.waitForSelector('.help-window, .original-help', { timeout: 15000 });
    await page.waitForTimeout(400);
    await shot('20-help');
    await page.keyboard.press('Escape');
    await form('TFRMMAIN');
  });
  await check('Stoppen asks with the original requester; Nee returns', async () => {
    await btn('btnMainStop').click(); await form('TFRMREQUESTER');
    await shot('21-quit-prompt');
    await btn('btnCancel').click(); await form('TFRMMAIN');
  });
  await check('portrait phone layout of the main menu and settings', async () => {
    await page.setViewportSize({ width: 390, height: 844 });
    await page.waitForTimeout(400);
    await shot('22-main-portrait');
    await btn('btnMainOptions').click(); await form('TFRMOPTIONS'); await page.waitForTimeout(300);
    await shot('23-settings-portrait');
    await btn('btnBack').click(); await form('TFRMMAIN');
    await page.setViewportSize({ width: 1024, height: 768 });
  });
} finally {
  report.firsttime = await page.evaluate(() => Object.keys(localStorage).filter((k) => k.startsWith('rcsk.')).sort()).catch(() => null);
  writeFileSync(join(OUT, 'result.json'), JSON.stringify(report, null, 2) + '\n');
  console.log(JSON.stringify({ failed: report.checks.filter((c) => !c.ok).length, errors: report.errors, introCodec: report.introCodec, version: report.version, keys: report.firsttime }, null, 1));
  await browser.close();
  // as tools/check-flight.mjs's report.ok (an error thrown out of the try exits 1 by itself)
  if (report.checks.some((c) => !c.ok) || report.errors.length) process.exitCode = 1;
}
