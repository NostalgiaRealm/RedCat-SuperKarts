#!/usr/bin/env node
// The race on screens of other shapes in headless Chromium: 4:3, 16:9, 21:9 and portrait, 16:9 with MSAA 4x, the
// quit requester and the finish flag at 16:9. Screenshots in evidence/frames/shapes/. Needs the dev server and
// Playwright (see tools/shot.mjs). Exit code 1 when the click on "nee" does not let the race go on, or a page throws or
// crashes (checks/page-errors.mjs); the pictures are for the eye.
import { mkdirSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { watchPage } from './checks/page-errors.mjs';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const out = join(ROOT, 'evidence', 'frames', 'shapes');
mkdirSync(out, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const only = process.argv[2] ? process.argv[2].split(',') : null;
const failed = [];
const cases = [
  ['4x3', 640, 480, ''], ['16x9', 854, 480, ''], ['21x9', 1120, 480, ''], ['portrait', 480, 854, ''], ['16x9-msaa4', 854, 480, '&msaa=4'],
  ['16x9-requester', 854, 480, '', 'requester'], ['16x9-finish', 854, 480, '', 'finish'], ['16x9-click-nee', 854, 480, '', 'click'],
].filter((c) => !only || only.includes(c[0]));
for (const [name, w, h, q, what] of cases) {
  const page = await browser.newPage({ viewport: { width: w, height: h }, deviceScaleFactor: 1 });
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  watchPage(page, (e) => failed.push(`${name}: ${e}`));
  await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html') + '?fixed&stats' + q);
  await page.waitForFunction(() => window.gameStats.ticks >= 1, null, { timeout: 180000 });
  await page.keyboard.down('ArrowUp');
  await page.waitForFunction(() => window.gameStats.ticks >= 420, null, { timeout: 180000 });
  await page.keyboard.up('ArrowUp');
  if (what === 'requester') { await page.keyboard.down('Escape'); await wait(120); await page.keyboard.up('Escape'); await wait(1500); }
  if (what === 'click') {
    // the requester's "nee" button at about (485, 370) of the game's 640x480, which sits in the middle 4:3 area
    await page.keyboard.down('Escape'); await wait(120); await page.keyboard.up('Escape'); await wait(1500);
    const before = await page.evaluate(() => window.gameStats.ticks);
    const box = await page.locator('#game').boundingBox();
    const s = Math.min(box.width / 640, box.height / 480);
    const x = box.x + (box.width - 640 * s) / 2 + 485 * s, y = box.y + (box.height - 480 * s) / 2 + 370 * s;
    await page.mouse.move(x - 20, y - 20); await wait(300);
    await page.mouse.move(x, y); await wait(300);
    await page.mouse.down(); await wait(150); await page.mouse.up();
    await wait(1500);
    const after = await page.evaluate(() => window.gameStats.ticks);
    console.log('click on nee: ticks', before, '->', after, after > before ? '(the race goes on)' : '(still waiting)');
    if (!(after > before)) failed.push(`${name}: the click on nee left the race waiting`);
  }
  if (what === 'finish') {
    await page.keyboard.down('Control'); await page.keyboard.down('KeyF'); await page.keyboard.down('KeyI');
    await wait(150);
    await page.keyboard.up('KeyI'); await page.keyboard.up('KeyF'); await page.keyboard.up('Control');
    await wait(2500);
  }
  await page.screenshot({ path: join(out, name + '.png') });
  console.log(name, JSON.stringify(await page.evaluate(() => ({ ticks: window.gameStats.ticks, render: window.renderStats }))));
  await page.close();
}
await browser.close();
for (const f of failed) console.log('FAIL', f);
if (failed.length) process.exitCode = 1;
