#!/usr/bin/env node
// Screenshots of the development page (/dev/race.html) in headless Chromium after given ticks.
//   node tools/shot.mjs [--ticks 40,200,400] [--out evidence/frames] [--gas]
// Needs the dev server (node tools/serve.mjs) and Playwright: PLAYWRIGHT_MODULE (default: the SuperKarts
// reconstruction's node_modules), CHROME_PATH optional.
import { mkdirSync } from 'node:fs';
import { join, dirname, resolve } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const opt = (name, def) => { const k = process.argv.indexOf('--' + name); return k < 0 ? def : process.argv[k + 1]; };
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const ticks = opt('ticks', '40,200,400').split(',').map(Number);
const out = resolve(ROOT, opt('out', 'evidence/frames'));
mkdirSync(out, { recursive: true });
const url = (process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html') + '?fixed&capture&stats' + (opt('extra', '') ? '&' + opt('extra') : '') + (opt('etappe', null) ? '&etappe=' + opt('etappe') : '');
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });
const page = await browser.newPage({ viewport: { width: 640, height: 480 }, deviceScaleFactor: 1 });
page.on('console', (m) => { if (m.type() === 'error' || m.type() === 'warning') console.log('[page]', m.type(), m.text()); });
page.on('pageerror', (e) => console.log('[pageerror]', e.message));
await page.goto(url);
await page.waitForFunction(() => window.gameStats && (window.gameStats.ticks >= 1 || window.gameStats.crash), null, { timeout: 180000 });
if (process.argv.includes('--gas')) await page.keyboard.down('ArrowUp');
for (const t of ticks) {
  await page.waitForFunction((n) => window.gameStats.ticks >= n || window.gameStats.exit !== null || window.gameStats.crash, t, { timeout: 180000 });
  const info = await page.evaluate(() => ({ ...window.gameStats, raceIni: undefined }));
  const file = join(out, `nederland-tick${String(t).padStart(4, '0')}.png`);
  await page.locator('#game').screenshot({ path: file });
  console.log(file, JSON.stringify(info));
}
await browser.close();
