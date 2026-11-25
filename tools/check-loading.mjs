#!/usr/bin/env node
// What two races fetch, on the development page (/dev/race.html?idle) in headless Chromium: race 1 Nederland as RedCat
// (a first visit: nothing cached), race 2 Engeland as Brutus on the same page (the game worker keeps what race 1
// fetched). Each race: the files fetched before it starts, then 380 ticks with the throttle held, then the cheat
// Ctrl+F+I and the finish screen to the race's end; every response of game/ and data/ counted with its body bytes as
// sent (Playwright's request sizes: a gzip'd answer counts its packed bytes), split into "before the race ran" and
// "while it ran" (the game thread waiting for a read nobody foresaw: source/web/worker.js). Also the worker's own
// counts (gameStats.load, gameStats.files). Results in evidence/checks/loading.json (--out another file).
//   node tools/check-loading.mjs [--url http://127.0.0.1:4190/dev/race.html] [--out evidence/checks/loading.json]
// Needs the dev server and Playwright (see tools/shot.mjs).
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const opt = (name, def) => { const k = process.argv.indexOf('--' + name); return k < 0 ? def : process.argv[k + 1]; };
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const OUT = join(ROOT, opt('out', 'evidence/checks/loading.json'));
mkdirSync(dirname(OUT), { recursive: true });
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true,
  args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--autoplay-policy=no-user-gesture-required', '--mute-audio'] });
const page = await browser.newPage({ viewport: { width: 854, height: 480 } });
page.on('pageerror', (e) => console.log('[pageerror]', e.message));
const log = [];          // { path, status, bytes, phase }
let phase = 'page';
page.on('requestfinished', async (req) => {
  const u = new URL(req.url());
  const entry = { path: u.pathname, status: 0, bytes: 0, range: req.headers().range || null, phase };
  log.push(entry);
  try { const r = await req.response(); entry.status = r ? r.status() : 0; entry.bytes = (await req.sizes()).responseBodySize; } catch (e) { /* gone */ }
});
await page.goto(opt('url', 'http://127.0.0.1:4190/dev/race.html') + '?idle&fixed&stats');
await page.waitForFunction(() => window.runner && window.race, null, { timeout: 30000 });
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const sum = (list) => list.reduce((s, e) => s + e.bytes, 0);
const game = (e) => /\/(game|data)\//.test(e.path);
const MB = (b) => +(b / 1048576).toFixed(2);

const results = { url: opt('url', 'http://127.0.0.1:4190/dev/race.html'), races: [] };
for (const [n, config] of [[1, { country: 0, character: 0, raceType: 0 }], [2, { country: 2, character: 2, raceType: 0 }]]) {
  phase = `race${n}-load`;
  const t0 = Date.now();
  await page.evaluate((c) => { window.__outcome = null; window.race(c).then((o) => { window.__outcome = o; }); }, config);
  await page.waitForFunction(() => window.gameStats.running || window.gameStats.exit !== null, null, { timeout: 300000 });
  const runningMs = Date.now() - t0;
  phase = `race${n}-run`;
  await page.keyboard.down('ArrowUp');
  await page.waitForFunction(() => window.gameStats.ticks >= 380 || window.gameStats.exit !== null, null, { timeout: 180000 });
  await page.keyboard.up('ArrowUp');
  await page.keyboard.down('Control'); await page.keyboard.down('KeyF'); await page.keyboard.down('KeyI');
  await wait(150);
  await page.keyboard.up('KeyI'); await page.keyboard.up('KeyF'); await page.keyboard.up('Control');
  await page.waitForFunction(() => window.gameStats.exit !== null, null, { timeout: 120000 });
  await wait(500);
  const s = await page.evaluate(() => ({ load: window.gameStats.load, files: window.gameStats.files || null, ticks: window.gameStats.ticks, finished: /^\s*finished\s*=\s*1/mi.test(window.gameStats.raceIni || '') }));
  const load = log.filter((e) => e.phase === `race${n}-load` && game(e)), run = log.filter((e) => e.phase === `race${n}-run` && game(e));
  const r = { race: n, config, runningMs, ticks: s.ticks, finished: s.finished, worker: { load: s.load, files: s.files },
    beforeStart: { requests: load.length, bytes: sum(load), mb: MB(sum(load)) }, whileRunning: { requests: run.length, bytes: sum(run), mb: MB(sum(run)), paths: [...new Set(run.map((e) => e.path))].slice(0, 20) },
    total: { mb: MB(sum(load) + sum(run)) } };
  results.races.push(r);
  console.log(`race ${n}`, JSON.stringify(r));
}
results.page = { requests: log.filter((e) => e.phase === 'page').length, mb: MB(sum(log.filter((e) => e.phase === 'page'))) };
writeFileSync(OUT, JSON.stringify(results, null, 1) + '\n');
console.log(`race 1: ${results.races[0].total.mb} MB (${results.races[0].beforeStart.mb} before it ran), race 2: ${results.races[1].total.mb} MB (${results.races[1].beforeStart.mb} before it ran) -> ${OUT}`);
await browser.close();
