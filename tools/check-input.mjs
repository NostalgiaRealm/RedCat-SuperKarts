#!/usr/bin/env node
// The race's own waits on the worker page, driven with real key presses in headless Chromium: pause (P, then a
// key), the quit requester (Esc, then N to go on), and leaving the race (Esc, then J). Screenshots go to
// evidence/frames/input/. Needs the dev server (node tools/serve.mjs) and Playwright (see tools/shot.mjs). Exit code 1
// when a wait does not hold or end, J does not end the race with exit 0, the cheat does not reach the finish screen
// (phase 3) or its screen does not end the race with exit 0, or the page throws or crashes (checks/page-errors.mjs).
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
const page = await browser.newPage({ viewport: { width: 640, height: 480 }, deviceScaleFactor: 1 });
page.on('pageerror', (e) => console.log('[pageerror]', e.message));
page.on('console', (m) => { if (m.type() === 'error') console.log('[page]', m.text()); });
const pageErrors = [];
watchPage(page, (e) => pageErrors.push(e));
await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html') + '?fixed&stats');
const stats = () => page.evaluate(() => ({ ticks: window.gameStats.ticks, phase: window.gameStats.phase, exit: window.gameStats.exit, crash: window.gameStats.crash }));
const ticksAtLeast = (n) => page.waitForFunction((k) => window.gameStats.ticks >= k || window.gameStats.crash, n, { timeout: 180000 });
const shot = async (name) => { const f = join(out, name + '.png'); await page.locator('#game').screenshot({ path: f }); return f; };
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
const tap = async (key, hold = 120) => { await page.keyboard.down(key); await wait(hold); await page.keyboard.up(key); };
const log = [];
const note = async (what) => { const s = await stats(); log.push({ what, ...s }); console.log(what.padEnd(34), JSON.stringify(s)); return s; };

await ticksAtLeast(1);
await page.keyboard.down('ArrowUp');
await ticksAtLeast(420);
await page.keyboard.up('ArrowUp');
await note('driving');
// pause: P, then any key resumes (0x42f220)
await tap('KeyP');
await wait(1500);
const p1 = await note('paused (1.5 s after P)');
await shot('paused');
await wait(1000);
const p2 = await note('still paused (2.5 s)');
await tap('Space');
await wait(800);
const p3 = await note('after Space');
// quit requester: Esc (0x42f290 -> requester 0x473780), N goes on
await tap('Escape');
await wait(1500);
const q1 = await note('requester (1.5 s after Esc)');
await shot('requester');
await tap('KeyN');
await wait(1000);
const q2 = await note('after N');
await shot('after-n');
// leave: Esc, then J
await tap('Escape');
await wait(1500);
await tap('KeyJ');
await page.waitForFunction(() => window.gameStats.exit !== null || window.gameStats.crash, null, { timeout: 30000 }).catch(() => {});
const e = await note('after Esc, J');
const raceIni = await page.evaluate(() => window.gameStats.raceIni || '');
// the finish, through the race's own cheat Ctrl+F+I (0x429a90): phase 3, its screen (0x41fd90) ends the race by
// itself after 8 s
await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4190/dev/race.html') + '?fixed&stats');
await ticksAtLeast(1);
await page.keyboard.down('ArrowUp');
await ticksAtLeast(420);
await page.keyboard.up('ArrowUp');
await page.keyboard.down('Control'); await page.keyboard.down('KeyF'); await page.keyboard.down('KeyI');
await wait(150);
await page.keyboard.up('KeyI'); await page.keyboard.up('KeyF'); await page.keyboard.up('Control');
await page.waitForFunction(() => window.gameStats.phase === 3 || window.gameStats.exit !== null, null, { timeout: 20000 }).catch(() => {});
const f1 = await note('finish (Ctrl+F+I)');
await wait(2500);
await shot('finish');
await page.waitForFunction(() => window.gameStats.exit !== null || window.gameStats.crash, null, { timeout: 30000 }).catch(() => {});
const f2 = await note('after the finish screen');
const finishIni = await page.evaluate(() => window.gameStats.raceIni || '');
const result = {
  pauseHolds: p2.ticks === p1.ticks, pauseResumes: p3.ticks > p2.ticks,
  requesterHolds: q1.ticks <= p3.ticks + 80, requesterResumes: q2.ticks > q1.ticks,
  exitCode: e.exit, finishedLine: (raceIni.match(/^finished=.*$/mi) || [''])[0],
  finishPhase: f1.phase, finishExit: f2.exit, finishIni: (finishIni.match(/^(finished|tracktime|position)=.*$/gmi) || []).join(' '), log,
};
writeFileSync(join(out, 'result.json'), JSON.stringify(result, null, 1));
console.log(JSON.stringify({ ...result, log: undefined }));
await browser.close();
// what PLAN.md (Worker page) records for this check: J ends the race with exit 0, the cheat reaches the finish screen
// and that screen ends the race by itself (exit 0, as check-runner.mjs's ok.resolved holds for both ends)
const failed = Object.entries({ pauseHolds: result.pauseHolds, pauseResumes: result.pauseResumes, requesterHolds: result.requesterHolds,
  requesterResumes: result.requesterResumes, quitExit: result.exitCode === 0, finishPhase: result.finishPhase === 3, finishExit: result.finishExit === 0,
  noCrash: log.every((l) => !l.crash) }).filter(([, ok]) => !ok).map(([k]) => k);
for (const e of pageErrors) console.log('[page error]', e);
if (failed.length || pageErrors.length) {
  console.log('FAIL', [...failed, ...(pageErrors.length ? [pageErrors.length + ' page error(s)'] : [])].join(' '));
  process.exitCode = 1;
} else console.log('all passed');
