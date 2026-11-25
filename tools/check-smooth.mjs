#!/usr/bin/env node
// Smoothing on the worker page in headless Chromium: new pictures per second against the game's frames per second,
// how many draws found a partner in the pass before, with smoothing on and off (?nosmooth); screenshots while
// driving and of the quit requester (2D frames are shown as they are). Needs the dev server and Playwright.
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const out = join(ROOT, 'evidence', 'frames', 'smooth');
mkdirSync(out, { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const results = {};
for (const mode of ['smooth', 'nosmooth']) {
  const page = await browser.newPage({ viewport: { width: 640, height: 480 } });
  page.on('pageerror', (e) => console.log('[pageerror]', e.message));
  await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html') + '?fixed&stats' + (mode === 'nosmooth' ? '&nosmooth' : ''));
  await page.waitForFunction(() => window.gameStats.ticks >= 1, null, { timeout: 180000 });
  await page.keyboard.down('ArrowUp');
  await page.waitForFunction(() => window.gameStats.ticks >= 420, null, { timeout: 180000 });
  const samples = [];
  for (let k = 0; k < 4; k++) { await wait(1050); samples.push(await page.evaluate(() => window.renderStats)); }
  await page.locator('#game').screenshot({ path: join(out, mode + '-driving.png') });
  await page.keyboard.up('ArrowUp');
  await page.keyboard.down('Escape'); await wait(120); await page.keyboard.up('Escape');
  await wait(1500);
  await page.locator('#game').screenshot({ path: join(out, mode + '-requester.png') });
  const avg = (f) => Math.round(samples.reduce((a, s) => a + f(s), 0) / samples.length);
  results[mode] = { shownPerSec: avg((s) => s.shownPerSec), gameFramesPerSec: avg((s) => s.framesPerSec), pairedShare: +(samples.reduce((a, s) => a + s.paired, 0) / Math.max(1, samples.reduce((a, s) => a + s.paired + s.unpaired, 0))).toFixed(3), samples };
  console.log(mode.padEnd(9), JSON.stringify({ ...results[mode], samples: undefined }));
  await page.close();
}
writeFileSync(join(out, 'result.json'), JSON.stringify(results, null, 1));
await browser.close();
