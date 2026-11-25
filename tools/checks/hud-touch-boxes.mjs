#!/usr/bin/env node
// The touch controls of the recomp and of the JS reconstruction ("JS port") on the same screens, without a race: on
// each page #touch-controls is shown (hidden = false) and everything else is hidden on a black page, so the two
// screenshots hold the controls only. Pages: the JS port's (its committed runtime, served read-only by
// tools/checks/menu/serve-js-readonly.mjs on 4173), the recomp's menu page (source/index.html + source/style.css,
// tools/serve.mjs on 4190) and its development race page (source/dev/race.html, its race script left out).
// Per screen: the boxes of #touch-controls, the wheel, Rem, Bonus and Stoppen in CSS px, Stoppen's font and
// background, and the pixels of each recomp page that differ from the JS port's (any channel by more than 8 of 255),
// counted with Pillow (python3). Writes evidence/frames/hud/touch/<screen>-{js,recomp,dev}.png and
// evidence/checks/hud-touch-boxes.json. Screens: a phone held upright (390x844, DPR 3) with and without a notch's
// insets (47 top, 34 bottom), the same phone sideways (insets 47 left and right, 21 bottom), small phones sideways
// (568x320 and 667x375, DPR 2), a tablet both ways (1024x768, DPR 2).
// Exit code 1 when anything differs (RESULT: DIFFERENT) or a page throws or crashes (page-errors.mjs; the JS port's
// pages without their console).
//   CHROME_PATH=... node tools/checks/hud-touch-boxes.mjs [--only phone-portrait,...]
import { mkdirSync, writeFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { execFileSync } from 'node:child_process';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { watchPage } from './page-errors.mjs';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const ONLY = opt('only', '') ? opt('only').split(',') : null;
const OUT = join(ROOT, 'evidence', 'frames', 'hud', 'touch');
const JSON_OUT = join(ROOT, 'evidence', 'checks', 'hud-touch-boxes.json');
mkdirSync(OUT, { recursive: true });
mkdirSync(dirname(JSON_OUT), { recursive: true });
const SITES = {
  js: process.env.RCSK_JS_URL || 'http://127.0.0.1:4173/',
  recomp: (process.env.RCSK_BASE || 'http://127.0.0.1:4190/') + '?skipIntro',
  dev: (process.env.RCSK_BASE || 'http://127.0.0.1:4190/') + 'dev/race.html?touch=1',
};
const mod = process.env.PLAYWRIGHT_MODULE || join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs');
const { chromium } = await import(pathToFileURL(mod).href);
const browser = await chromium.launch({ executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader'] });

const phone = (w, h, dpr = 3) => ({ viewport: { width: w, height: h }, deviceScaleFactor: dpr, isMobile: true, hasTouch: true });
const SCREENS = [
  ['phone-portrait-notch', phone(390, 844), { top: 47, right: 0, bottom: 34, left: 0 }],
  ['phone-portrait', phone(390, 844), null],
  ['phone-landscape-notch', phone(844, 390), { top: 0, right: 47, bottom: 21, left: 47 }],
  ['phone-landscape-568', phone(568, 320, 2), null],
  ['phone-landscape-667', phone(667, 375, 2), null],
  ['tablet-landscape', phone(1024, 768, 2), null],
  ['tablet-portrait', phone(768, 1024, 2), null],
].filter((s) => !ONLY || ONLY.includes(s[0]));

// only the controls on a black page; the pointer parked away from them
const ISOLATE = () => {
  const c = document.getElementById('touch-controls');
  c.hidden = false;
  const style = document.createElement('style');
  style.textContent = 'html,body{background:#000!important}body *{visibility:hidden!important}'
    + '#touch-controls,#touch-controls *{visibility:visible!important}#touch-next,#flight-touch,#touch-wheel-help{visibility:hidden!important}';
  document.head.append(style);
  document.activeElement?.blur?.();
};
const MEASURE = () => {
  const box = (id) => { const e = document.getElementById(id); if (!e) return null; const r = e.getBoundingClientRect(); return [r.x, r.y, r.width, r.height].map((v) => +v.toFixed(2)); };
  const stop = document.getElementById('touch-stop');
  const label = stop.querySelector('span') || stop;
  const cs = getComputedStyle(label);
  return {
    controls: box('touch-controls'), wheel: box('touch-wheel'), brake: box('touch-brake'), bonus: box('touch-bonus'), stop: box('touch-stop'),
    stopFont: `${cs.fontWeight} ${cs.fontSize} ${cs.fontFamily}`, stopText: label.textContent.trim(),
    stopBackground: getComputedStyle(stop).backgroundImage.replace(/^.*\/([^/]+)"?\)$/, '$1'),
  };
};

const pageErrors = [];
async function shot(site, name, ctxOpts, safe) {
  const context = await browser.newContext(ctxOpts);
  // the development page without its race (race.js starts one): only its markup and style sheet are compared
  if (site === 'dev') await context.route('**/source/dev/race.js', (route) => route.fulfill({ contentType: 'text/javascript', body: '' }));
  const page = await context.newPage();
  page.on('pageerror', (e) => console.log(`[${site} pageerror]`, e.message));
  watchPage(page, (e) => pageErrors.push(`${name} ${site}: ${e}`), { console: site !== 'js' });
  if (safe) {
    const cdp = await context.newCDPSession(page);
    await cdp.send('Emulation.setSafeAreaInsetsOverride', { insets: safe });
  }
  await page.goto(SITES[site]);
  await page.waitForSelector('#touch-controls', { state: 'attached', timeout: 120000 });
  await page.evaluate(ISOLATE);
  await page.evaluate(() => document.fonts.ready);
  await page.mouse.move(1, 1);
  await page.waitForTimeout(400);
  const file = join(OUT, `${name}-${site}.png`);
  await page.screenshot({ path: file });
  const m = await page.evaluate(MEASURE);
  await context.close();
  return { file, ...m };
}

// pixels of b that differ from a by more than 8 in any channel (Pillow)
function differing(a, b) {
  const py = `import sys
from PIL import Image, ImageChops
a = Image.open(sys.argv[1]).convert('RGB'); b = Image.open(sys.argv[2]).convert('RGB')
if a.size != b.size: print('size', a.size, b.size); sys.exit()
d = ImageChops.difference(a, b).point(lambda v: 255 if v > 8 else 0).convert('L')
print(sum(1 for v in d.getdata() if v), d.getbbox())`;
  return execFileSync('python3', ['-I', '-c', py, a, b], { encoding: 'utf8' }).trim();
}

const results = {};
let same = true;
for (const [name, ctxOpts, safe] of SCREENS) {
  const r = (results[name] = {});
  for (const site of Object.keys(SITES)) r[site] = await shot(site, name, ctxOpts, safe);
  console.log(`## ${name} ${ctxOpts.viewport.width}x${ctxOpts.viewport.height} DPR ${ctxOpts.deviceScaleFactor}${safe ? ' insets ' + JSON.stringify(safe) : ''}`);
  for (const k of ['controls', 'wheel', 'brake', 'bonus', 'stop', 'stopFont', 'stopText', 'stopBackground']) {
    const v = (s) => JSON.stringify(r[s][k]);
    const flag = ['recomp', 'dev'].map((s) => (v(s) === v('js') ? '' : ` <-- ${s} differs`)).join('');
    if (flag && k !== 'stopText') same = false;
    console.log(`  ${k.padEnd(15)} js ${v('js')}  recomp ${v('recomp')}  dev ${v('dev')}${flag}`);
  }
  for (const s of ['recomp', 'dev']) {
    r[s].pixels = differing(r.js.file, r[s].file);
    if (!r[s].pixels.startsWith('0 ')) same = false;
    console.log(`  pixels of ${s} differing from js: ${r[s].pixels}`);
  }
}
writeFileSync(JSON_OUT, JSON.stringify(results, null, 1) + '\n');
console.log(`RESULT: ${same ? 'identical' : 'DIFFERENT'}`);
await browser.close();
for (const e of pageErrors) console.log('FAIL page error', e);
if (!same || pageErrors.length) process.exitCode = 1;
