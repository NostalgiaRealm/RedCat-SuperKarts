import { chromium } from 'playwright';
import assert from 'node:assert/strict';
import { mkdir, readFile, writeFile } from 'node:fs/promises';
import { createNativeAdventureProfile } from '../src/simulation/native-adventure.js';

const origin = process.env.RCSK_URL || 'http://127.0.0.1:4173';
const config = JSON.parse(await readFile(new URL('../public/assets/config.json', import.meta.url)));
const browser = await chromium.launch({
  executablePath: process.env.CHROME_PATH || '/usr/bin/google-chrome',
  headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'],
});
const report = { browser: browser.version(),
  scope: 'Browser profile-bank interactions only; no race simulation or injected race result.',
  checks: [], errors: [] };
const form = (page, name) => page.waitForSelector(`[data-form=${name}]`);
const control = (page, name) => page.locator(`[data-native=${name}]`);
const saved = page => page.evaluate(() => JSON.parse(localStorage.getItem('rcsk.race-save.v1')));
const profile = slot => createNativeAdventureProfile(`Speler ${slot}`, { slot });
async function open(slots, selectedSlot) {
  const context = await browser.newContext({ viewport: { width: 1024, height: 768 } });
  const page = await context.newPage();
  page.on('pageerror', error => report.errors.push(error.message));
  page.on('response', response => {
    if (response.status() >= 400) report.errors.push(`${response.status()} ${response.url()}`);
  });
  await page.addInitScript(value => {
    if (!localStorage.getItem('rcsk.race-save.v1'))
      localStorage.setItem('rcsk.race-save.v1', JSON.stringify(value));
  }, { profiles: Array.from({ length: 30 }, (_, i) => slots.includes(i) ? profile(i) : null), selectedSlot });
  await page.goto(origin + '/?skipIntro');
  await control(page, 'btnAdventure').click();
  await form(page, 'TFRMADVENTUREMAIN');
  return { page, context };
}
async function deleteSelected(page) {
  await control(page, 'btnDeletePlayer').click();
  await form(page, 'TFRMREQUESTER');
  await control(page, 'btnOk').click();
  await form(page, 'TFRMADVENTUREMAIN');
}
async function expectName(page, name) {
  await page.waitForFunction(value =>
    document.querySelector('[data-element=lblPlayerName]')?.textContent === value, name);
}
try {
  const full = await open(Array.from({ length: 30 }, (_, i) => i), 29);
  const page = full.page;
  await expectName(page, 'Speler 29');
  assert.equal(await control(page, 'btnRight').isDisabled(), true);
  const before = await saved(page);
  await control(page, 'btnNewPlayer').click();
  await form(page, 'TFRMREQUESTER');
  assert.equal(await page.locator('[data-element=lblQuit]').innerText(),
    config['ini/shellang.ini'].dutch[52]);
  await control(page, 'btnOk').click();
  await form(page, 'TFRMADVENTUREMAIN');
  assert.deepEqual(await saved(page), before);
  await deleteSelected(page);
  assert.equal((await saved(page)).selectedSlot, 28);
  await expectName(page, 'Speler 28');
  await control(page, 'btnNewPlayer').click();
  await form(page, 'TFRMEDITBOX');
  await page.locator('[data-element=edtName]').fill('Herstelde laatste');
  await control(page, 'btnOk').click();
  await form(page, 'TFRMSELECTCHAR');
  assert.equal((await saved(page)).profiles[29].name, 'Herstelde laatste');
  await control(page, 'btnBack').click();
  await form(page, 'TFRMADVENTUREMAIN');
  await page.reload();
  await control(page, 'btnAdventure').click();
  await expectName(page, 'Herstelde laatste');
  report.checks.push('Full30 bank shows original no-room requester without changing saves; deleting last occupied slot selects previous; slot29 is reusable and persists after Back/reload');
  await full.context.close();

  const sparse = await open([0, 7, 29], 7);
  await expectName(sparse.page, 'Speler 7');
  await control(sparse.page, 'btnLeft').click();
  await expectName(sparse.page, 'Speler 0');
  assert.equal(await control(sparse.page, 'btnLeft').isDisabled(), true);
  await control(sparse.page, 'btnRight').click();
  await expectName(sparse.page, 'Speler 7');
  await deleteSelected(sparse.page);
  await expectName(sparse.page, 'Speler 29');
  assert.equal((await saved(sparse.page)).selectedSlot, 29);
  await control(sparse.page, 'btnNewPlayer').click();
  await form(sparse.page, 'TFRMEDITBOX');
  await sparse.page.locator('[data-element=edtName]').fill('Eerste vrije');
  await control(sparse.page, 'btnOk').click();
  await form(sparse.page, 'TFRMSELECTCHAR');
  const reused = await saved(sparse.page);
  assert.equal(reused.selectedSlot, 1);
  assert.equal(reused.profiles[1].name, 'Eerste vrije');
  assert.equal(reused.profiles[7], null);
  report.checks.push('Sparse bank skips gaps without wrapping; deleting middle selects next; new profile uses lowest free slot1 rather than deleted slot7');
  await sparse.context.close();

  const single = await open([14], 14);
  assert.equal(await control(single.page, 'btnLeft').isDisabled(), true);
  assert.equal(await control(single.page, 'btnRight').isDisabled(), true);
  await deleteSelected(single.page);
  const empty = await saved(single.page);
  assert.equal(empty.selectedSlot, -1);
  assert.ok(empty.profiles.every(p => p === null));
  for (const name of ['btnLeft', 'btnRight', 'btnOk', 'btnDeletePlayer'])
    assert.equal(await control(single.page, name).isDisabled(), true);
  assert.equal(await control(single.page, 'btnNewPlayer').isDisabled(), false);
  await single.page.screenshot({ path: 'evidence/adventure/profile-bank-empty.png' });
  report.checks.push('Deleting sole occupied slot empties bank, selects -1 and disables only navigation/accept/delete while New remains usable');
  await single.context.close();
  assert.deepEqual(report.errors, []);
  report.status = 'passed';
} catch (error) {
  report.status = 'failed';
  report.failure = String(error.stack || error);
  throw error;
} finally {
  await mkdir('evidence/adventure', { recursive: true });
  await writeFile('evidence/adventure/profile-bank-report.json', JSON.stringify(report, null, 2) + '\n');
  await browser.close();
  console.log(JSON.stringify(report, null, 2));
}
