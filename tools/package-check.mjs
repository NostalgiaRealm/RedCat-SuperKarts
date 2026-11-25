#!/usr/bin/env node
// Checks a packaged site (dist/site, tools/package.mjs) the way a visitor's browser uses it: served below
// /redcatsuperkarts/ by tools/serve-site.mjs (a stand-in for the web server with the headers of
// docs/nginx-redcatsuperkarts*.conf, Range included), with a delay before every answer for a network's round trip.
// RedCat Spookkasteel's tools/package-check.mjs, for this port.
//   1. the folder: the revision is its content's; every file the page, its scripts and style sheets refer to is there;
//      the game files are files.json's at their sizes; every list entry is a file; no .gz next to a file read by ranges
//      or played by a media element; the .gz copies unpack to their files; nothing that does not belong
//   2. the server's answers: redirect, isolation headers, cache rule per folder, .gz, byte ranges of rcs.img, 404, the
//      old version at classic/ as it is answered today (the JavaScript port's built site, ../RedCat Superkarts/dist)
//   3. headless Chromium (software WebGL): the menu comes up with nothing missing; a QuickRace from the menu
//      (?skipIntro&cheats: RedCat, Nederland, Landenrace) loads, runs and is finished with the race's own cheat Ctrl+F+I,
//      the debrief and highscore follow; a second QuickRace on another track (Groot-Brittannië) in the same page; the
//      bytes each race fetched (as sent, .gz counted packed) and how often the game thread waited; every request stays
//      below the prefix; a second visit takes the scripts and the game module from the browser's cache
//   4. the not-supported notice: the same site without the isolation headers, and with WebGL 2 taken away, says so in
//      Dutch and links to classic/
//   5. --firefox: Playwright's Firefox on the package: isolated? the menu? does a race run? (reported, not a failure)
// What it does not check: nginx with those files, a real network, a real GPU, a whole race (tools/checks/loading-full-race.mjs).
//   node tools/package-check.mjs [--site dist/site] [--latency 25] [--no-browser] [--firefox] [--out evidence/package]
// Playwright: PLAYWRIGHT_MODULE (default the JS reconstruction's node_modules); CHROME_PATH for Chromium.
import fs from 'node:fs';
import path from 'node:path';
import http from 'node:http';
import zlib from 'node:zlib';
import { createHash } from 'node:crypto';
import { pathToFileURL } from 'node:url';
import { serveSite, cachePolicy } from './serve-site.mjs';
import { ROOT, RANGED } from './game-data.mjs';

const args = process.argv.slice(2);
const opt = (n, d) => { const k = args.indexOf('--' + n); return k >= 0 ? args[k + 1] : d; };
const has = (n) => args.includes('--' + n);
const SITE = path.resolve(ROOT, opt('site', 'dist/site'));
const OUT = path.resolve(ROOT, opt('out', 'evidence/package'));
const LATENCY = Number(opt('latency', 25));
const PREFIX = '/redcatsuperkarts/';
const CLASSIC = path.resolve(ROOT, '..', 'RedCat Superkarts', 'dist');
const haveClassic = fs.existsSync(path.join(CLASSIC, 'index.html'));
const posix = path.posix;
fs.mkdirSync(OUT, { recursive: true });

let failed = 0;
const report = { checks: [] };
const check = (ok, what, detail = '') => { if (!ok) failed++; report.checks.push({ ok: !!ok, what, detail }); console.log(`${ok ? 'ok  ' : 'FAIL'} ${what}${detail ? '  [' + detail + ']' : ''}`); return ok; };
const exists = (rel) => { try { return fs.statSync(path.join(SITE, rel)).isFile(); } catch (e) { return false; } };
const walk = (dir, rel = '') => fs.readdirSync(dir, { withFileTypes: true }).flatMap((e) => (e.isDirectory() ? walk(path.join(dir, e.name), rel ? rel + '/' + e.name : e.name) : [rel ? rel + '/' + e.name : e.name]));
const mb = (n) => (n / 1048576).toFixed(1) + ' MB';
const MB = (n) => +(n / 1048576).toFixed(2);

// ================================================================================================================
console.log('the folder ' + SITE);
if (!exists('build.json')) { console.log('FAIL no build.json: not a packaged site (npm run package)'); process.exit(1); }
const build = JSON.parse(fs.readFileSync(path.join(SITE, 'build.json'), 'utf8'));
const APP = `app/${build.revision}/`;
const all = walk(SITE);
const plain = all.filter((f) => !f.endsWith('.gz'));

{ // the revision is the content's
  const hash = createHash('sha256');
  const files = plain.filter((f) => f.startsWith(APP)).map((f) => [f.slice(APP.length), fs.readFileSync(path.join(SITE, f))]).sort((a, b) => (a[0] < b[0] ? -1 : 1));
  for (const [rel, data] of files) { hash.update(rel + '\0' + data.length + '\0'); hash.update(data); }
  const rev = hash.digest('hex').slice(0, 12);
  check(rev === build.revision, `app/${build.revision}/ holds what its name was made from (${files.length} files)`, rev === build.revision ? '' : 'content gives ' + rev);
  const others = fs.readdirSync(path.join(SITE, 'app')).filter((n) => n !== build.revision);
  check(others.length === 0, 'one revision under app/', others.join(' '));
}

const html = fs.readFileSync(path.join(SITE, 'index.html'), 'utf8');
{ // the page's own references
  const refs = [...html.matchAll(/\b(?:src|href)="([^"#]+)"/g)].map((m) => m[1]).filter((r) => !/^(https?:|data:|mailto:)/.test(r));
  const missing = refs.filter((r) => !exists(r.split('?')[0]));
  check(refs.length >= 6 && missing.length === 0, `index.html: its ${refs.length} references to files are in the folder`, missing.slice(0, 5).join(' '));
  check(!/\b(src|href)="source\//.test(html) && html.includes(APP + 'source/') && !/\b(src|href)="\//.test(html), 'index.html loads its scripts and styles from the revision folder, every URL relative');
}

const reached = new Set();
{ // every script reachable from the page and from the workers
  const entries = [...html.matchAll(/<script[^>]+src="([^"]+)"/g)].map((m) => m[1]);
  const queue = [...entries];
  const missing = [], outside = [];
  while (queue.length) {
    const file = queue.pop();
    if (reached.has(file)) continue;
    if (!exists(file)) { missing.push(file); continue; }
    reached.add(file);
    const text = fs.readFileSync(path.join(SITE, file), 'utf8').replace(/^\s*\/\/.*$/gm, '').replace(/\/\*[\s\S]*?\*\//g, '');          // line comments first: they write paths like source/input/*
    const refs = [...text.matchAll(/\bimport\s+(?:[^'"()]*?\s*from\s*)?['"]([^'"]+)['"]/g), ...text.matchAll(/\bexport\s+[^'"]*?\sfrom\s+['"]([^'"]+)['"]/g), ...text.matchAll(/new URL\(\s*['"]([^'"]+\.js)['"]\s*,\s*import\.meta\.url\s*\)/g), ...text.matchAll(/\bimport\(\s*['"]([^'"]+)['"]\s*\)/g)].map((m) => m[1]);
    for (const ref of refs) {
      const to = posix.normalize(posix.join(posix.dirname(file), ref));
      if (!to.startsWith(APP)) outside.push(`${file} -> ${ref}`);
      queue.push(to);
    }
  }
  check(entries.length >= 1 && missing.length === 0, `scripts: ${reached.size} reached from the page, all in the folder`, missing.slice(0, 5).join(' '));
  check(outside.length === 0, 'no script refers to a script outside its revision folder', outside.slice(0, 3).join('; '));
  check(['source/web/worker.js', 'source/web/render-worker.js', 'source/web/game-files.js', 'source/web/support.js', 'source/host/race.js'].every((f) => reached.has(APP + f)), 'the game worker, the render worker, the file loader, the support check and the host are among them');
  const unused = plain.filter((f) => f.startsWith(APP + 'source/') && f.endsWith('.js') && !reached.has(f));
  if (unused.length) console.log('     note: scripts in the folder that nothing reaches: ' + unused.map((f) => f.slice(APP.length)).join(' '));
  check(!plain.some((f) => f.startsWith(APP + 'source/dev/')), 'the development page (source/dev/) is not in it');
}

{ // style sheets: every url() points at a file
  const sheets = plain.filter((f) => f.startsWith(APP) && f.endsWith('.css'));
  const missing = []; let n = 0;
  for (const sheet of sheets) for (const m of fs.readFileSync(path.join(SITE, sheet), 'utf8').matchAll(/url\(\s*["']?([^"')]+)["']?\s*\)/g)) {
    if (/^(data:|https?:|#)/.test(m[1])) continue;
    n++;
    const to = posix.normalize(posix.join(posix.dirname(sheet), m[1]));
    if (!exists(to)) missing.push(`${sheet.slice(APP.length)}: ${m[1]}`);
  }
  check(sheets.length >= 1 && n > 10 && missing.length === 0, `style sheets: ${n} url() references point at files in the folder`, missing.slice(0, 4).join('; '));
}

{ // asset paths written out in the scripts and the page; what the menu names through manifest.json
  const texts = [html, ...[...reached].map((f) => fs.readFileSync(path.join(SITE, f), 'utf8'))].join('\n');
  const literal = [...new Set([...texts.matchAll(/assets\/[A-Za-z0-9_.\/-]+\.(?:png|wav|json|svg|ico|mp4|ttf)/g)].map((m) => m[0]))];
  const missing = literal.filter((p) => !exists(p));
  check(literal.length > 10 && missing.length === 0, `scripts and page: the ${literal.length} asset paths written out in them are in the folder`, missing.slice(0, 5).join(' '));
  const manifest = JSON.parse(fs.readFileSync(path.join(SITE, 'assets/manifest.json'), 'utf8'));
  const config = JSON.parse(fs.readFileSync(path.join(SITE, 'assets/config.json'), 'utf8'));
  const named = [];
  for (let c = 0; c < 6; c++) for (const ch of 'abcd') named.push(manifest.images[`e0${c}_${ch}_hi.tga`]);
  for (let k = 1; k <= 7; k++) named.push(manifest.images[`image_0${k}.tga`]);
  const samples = new Set(Object.values(config['ini/soundset.dat'].generic_samples));
  for (const f of ['rc_snd.dat', 'wk_snd.dat', 'br_snd.dat', 'mx_snd.dat']) for (const s of Object.values(config['ini/' + f].sample_set)) samples.add(s);
  for (const s of samples) if (s && manifest.audio[s.toLowerCase()]) named.push(manifest.audio[s.toLowerCase()]);
  const absent = named.filter((e) => !e || !exists('assets/' + e.file));
  check(named.length > 100 && absent.length === 0, `the menu's loading screens and voices named through manifest.json are in assets/ (${named.length})`, absent.slice(0, 4).map((e) => e && e.file).join(' '));
  const movies = Object.values(manifest.movies || {}).map((m) => 'assets/' + m.file).filter((f) => !exists(f));
  check(movies.length === 0, 'the intro and the reward movies are in assets/media/', movies.join(' '));
}

const files = JSON.parse(fs.readFileSync(path.join(SITE, APP, 'game/files.json'), 'utf8'));
const lists = JSON.parse(fs.readFileSync(path.join(SITE, APP, 'game/preload.json'), 'utf8'));
{ // the game's files and lists
  const bad = files.files.filter(([rel, size]) => { try { return fs.statSync(path.join(SITE, files.base, rel)).size !== size; } catch (e) { return true; } });
  check(files.files.length > 80 && bad.length === 0, `the ${files.files.length} original game files of files.json are under ${files.base} at their sizes (${mb(files.files.reduce((s, f) => s + f[1], 0))})`, bad.slice(0, 3).map((f) => f[0]).join(' '));
  const extra = plain.filter((f) => f.startsWith('data/') && f !== 'data/index.json' && !files.files.some(([n]) => 'data/' + n === f));
  check(extra.length === 0, 'data/ holds nothing else (index.json aside)', extra.join(' '));
  check(!exists('data/debug.txt') && !plain.some((f) => /^data\/.*\.(exe|dll|hlp|cnt)$/i.test(f) || /^data\/(rcskspel|rcskmenu|rcmovie)\.dat$/i.test(f)), 'no debug.txt, program or help file in data/');
  const known = new Set(files.files.map((f) => f[0]));
  const named = [...Object.values(lists.files).flatMap((g) => (Array.isArray(g) ? g : Object.values(g).flat()))];
  const unknown = named.filter((n) => !known.has(n));
  const ranged = Object.keys(lists.ranges);
  check(unknown.length === 0 && ranged.every((n) => files.ranged.includes(n)) && files.ranged.includes('rcs.img'), `preload.json names only files of files.json (${new Set(named).size} files) and pieces of its ranged archives (${ranged.join(', ')})`, unknown.slice(0, 3).join(' '));
  check(lists.page === files.page, `the lists and the file list count in the same page (${files.page} bytes)`);
}

{ // .gz copies, and nothing that does not belong
  let n = 0; const wrong = [];
  for (const f of all.filter((x) => x.endsWith('.gz'))) {
    const orig = f.slice(0, -3);
    if (!exists(orig)) { wrong.push(f + ' (no file)'); continue; }
    if (!zlib.gunzipSync(fs.readFileSync(path.join(SITE, f))).equals(fs.readFileSync(path.join(SITE, orig)))) wrong.push(f);
    n++;
  }
  check(wrong.length === 0, `the ${n} .gz copies unpack to exactly their files`, wrong.slice(0, 3).join(' '));
  const ranged = all.filter((f) => f.endsWith('.gz') && (RANGED.test(f.slice(0, -3)) || /\.(wav|mp4)$/i.test(f.slice(0, -3))));
  check(ranged.length === 0, 'no .gz next to a file read by byte ranges (rcs.img, rc.img) or played by a media element (.wav, .mp4)', ranged.join(' '));
  const top = fs.readdirSync(SITE).sort();
  const extra = top.filter((x) => !['app', 'assets', 'data', 'index.html', 'index.html.gz', 'build.json'].includes(x));
  check(extra.length === 0, 'top level: app/ assets/ data/ index.html build.json and nothing else', extra.join(' '));
  const unwanted = all.filter((f) => /\.(exe|dll|map|mjs|log|py|sh)$/i.test(f) || /(^|\/)\./.test(f) || /node_modules/.test(f));
  check(unwanted.length === 0, 'no programs, tools, logs or hidden files in the folder', unwanted.slice(0, 4).join(' '));
  const names = all.filter((f) => !/^[A-Za-z0-9 _.\/-]+$/.test(f));
  check(names.length === 0, 'file names: letters, digits, space, _ - . only', names.slice(0, 3).join(' '));
  const lower = new Map(); const clash = [];
  for (const f of all) { const k = f.toLowerCase(); if (lower.has(k)) clash.push(f); lower.set(k, f); }
  check(clash.length === 0, 'no two file names differ only in case', clash.slice(0, 3).join(' '));
}

// ================================================================================================================
console.log('\nthe server\'s answers (tools/serve-site.mjs, as docs/nginx-redcatsuperkarts*.conf describe them)');
const get = (port, p, headers = {}, method = 'GET') => new Promise((resolve, reject) => {
  const req = http.request({ host: '127.0.0.1', port, path: p, method, headers }, (res) => { const chunks = []; res.on('data', (c) => chunks.push(c)); res.on('end', () => resolve({ status: res.statusCode, headers: res.headers, body: Buffer.concat(chunks) })); });
  req.on('error', reject); req.end();
});
const isolated = (r) => r.headers['cross-origin-opener-policy'] === 'same-origin' && r.headers['cross-origin-embedder-policy'] === 'require-corp';
{
  const s = await serveSite({ root: SITE, port: 0, prefix: PREFIX, classic: haveClassic ? CLASSIC : null });
  let r = await get(s.port, '/redcatsuperkarts?skipIntro');
  check(r.status === 301 && r.headers.location === '/redcatsuperkarts/?skipIntro', 'the address without its slash is sent on, with its query', `${r.status} ${r.headers.location}`);
  r = await get(s.port, PREFIX, { 'accept-encoding': 'gzip' });
  check(r.status === 200 && /text\/html/.test(r.headers['content-type']) && r.headers['cache-control'] === 'no-cache' && isolated(r), 'the page: isolation headers, always checked with the server (no-cache)', r.headers['cache-control']);
  r = await get(s.port, PREFIX + 'build.json');
  check(r.status === 200 && r.headers['cache-control'] === 'no-cache', 'build.json: no-cache');
  const wasm = PREFIX + APP + 'game/rcskspel.wasm';
  r = await get(s.port, wasm, { 'accept-encoding': 'gzip, deflate, br' });
  const rawSize = fs.statSync(path.join(SITE, APP, 'game/rcskspel.wasm')).size;
  check(r.status === 200 && r.headers['content-encoding'] === 'gzip' && zlib.gunzipSync(r.body).length === rawSize && /immutable/.test(r.headers['cache-control']) && isolated(r), `the game module to a browser: its .gz copy (${mb(r.body.length)} for ${mb(rawSize)}), kept for good, isolation headers`, r.headers['cache-control']);
  const etag = r.headers.etag;
  r = await get(s.port, wasm, { 'if-none-match': etag, 'accept-encoding': 'gzip' });
  check(r.status === 304, 'a copy that is still good: 304', String(r.status));
  r = await get(s.port, PREFIX + 'data/rcs.img', { range: 'bytes=1048576-1064959', 'accept-encoding': 'gzip, deflate, br' });
  const want = Buffer.alloc(16384); { const fd = fs.openSync(path.join(SITE, 'data/rcs.img'), 'r'); fs.readSync(fd, want, 0, 16384, 1048576); fs.closeSync(fd); }
  check(r.status === 206 && !r.headers['content-encoding'] && r.body.equals(want) && r.headers['content-range'] === `bytes 1048576-1064959/${fs.statSync(path.join(SITE, 'data/rcs.img')).size}` && /immutable/.test(r.headers['cache-control']) && isolated(r), 'rcs.img by a byte range from a browser that takes gzip: 206, exactly those 16 KB, not packed, kept for good', `${r.status} ${r.headers['content-range']} ${r.headers['content-encoding'] || ''}`);
  r = await get(s.port, PREFIX + 'data/rcs.img', { range: 'bytes=999999999-' });
  check(r.status === 416, 'a range beyond the end: 416', String(r.status));
  r = await get(s.port, PREFIX + 'data/Etappe0.rmp', { 'accept-encoding': 'gzip' });
  check(r.status === 200 && r.headers['content-encoding'] === 'gzip' && /immutable/.test(r.headers['cache-control']) && isolated(r), `an original track file: its .gz copy (${mb(r.body.length)}), kept for good`);
  r = await get(s.port, PREFIX + 'assets/menu/mn_0000a.png');
  check(r.status === 200 && r.headers['cache-control'] === 'public, max-age=86400' && isolated(r), 'a menu picture: kept for a day', r.headers['cache-control']);
  r = await get(s.port, PREFIX + 'assets/media/intro.mp4', { range: 'bytes=0-1023', 'accept-encoding': 'gzip' });
  check(r.status === 206 && r.body.length === 1024 && !r.headers['content-encoding'], 'the intro movie: byte ranges, not packed', String(r.status));
  r = await get(s.port, PREFIX + APP + 'source/web/nothing.js');
  check(r.status === 404 && !/max-age|immutable/.test(r.headers['cache-control'] || '') && isolated(r), 'a script that is not there: 404, not to be kept', `${r.status} ${r.headers['cache-control'] || 'no Cache-Control'}`);
  if (haveClassic) {
    r = await get(s.port, PREFIX + 'classic/index.html', {}, 'HEAD');
    check(r.status === 200 && r.headers['cache-control'] === 'no-cache' && !r.headers['cross-origin-opener-policy'] && !r.headers['cross-origin-embedder-policy'], 'the old version at classic/: answered as the site answers it now (no-cache, no isolation headers)', `${r.status} ${r.headers['cache-control']}`);
  } else console.log('     note: ../RedCat Superkarts/dist not found, classic/ not checked');
  r = await get(s.port, '/index.html');
  check(r.status === 404, 'nothing is served outside the prefix');
  r = await get(s.port, PREFIX + '.hidden');
  check(r.status === 404, 'a dotfile: 404');
  await s.close();
}

// ================================================================================================================
if (has('no-browser')) { console.log(failed ? `\n${failed} check(s) FAILED` : '\nall checks passed (browser part skipped)'); process.exit(failed ? 1 : 0); }
console.log(`\nheadless Chromium, ${LATENCY} ms before every answer`);
const pw = await import(pathToFileURL(process.env.PLAYWRIGHT_MODULE || path.join(ROOT, '..', 'RedCat Superkarts', 'node_modules', 'playwright', 'index.mjs')).href);
const LAUNCH = { executablePath: process.env.CHROME_PATH || undefined, headless: true, args: ['--mute-audio', '--autoplay-policy=no-user-gesture-required', '--ignore-gpu-blocklist', '--use-angle=swiftshader', '--enable-unsafe-swiftshader'] };
const profiles = [];
const newProfile = () => { const dir = fs.mkdtempSync(path.join(OUT, 'profile-')); profiles.push(dir); return dir; };
const open = async (profile, browserType = pw.chromium, launch = LAUNCH) => {
  const context = await browserType.launchPersistentContext(profile, { ...launch, viewport: { width: 1024, height: 768 } });
  const page = context.pages()[0] || await context.newPage();
  const seen = { bad: [], outside: [], errors: [] };
  page.on('response', (r) => { const u = new URL(r.url()); if (!u.pathname.startsWith(PREFIX)) seen.outside.push(r.url()); else if (r.status() >= 400) seen.bad.push(`${r.status()} ${u.pathname.slice(PREFIX.length)}`); });
  page.on('requestfailed', (r) => { if (!/ERR_ABORTED|NS_BINDING_ABORTED/.test(r.failure()?.errorText || '')) seen.bad.push(`failed ${r.url()} ${r.failure()?.errorText}`); });
  page.on('pageerror', (e) => seen.errors.push(e.message));
  page.on('console', (m) => { if (m.type() === 'error') seen.errors.push('console: ' + m.text()); });
  return { context, page, seen };
};
const shot = (t, name) => t.page.screenshot({ path: path.join(OUT, name + '.png') }).catch(() => {});
const form = (t, name, timeout = 60000) => t.page.waitForSelector(`[data-form=${name}]`, { timeout });
const btn = (t, name) => t.page.locator(`[data-native=${name}]`);
const currentForm = (t) => t.page.evaluate(() => document.querySelector('#screen:not([hidden]) [data-form]')?.dataset.form || null);
const until = (t, fn, arg, timeout = 120000) => t.page.waitForFunction(fn, arg, { timeout, polling: 100 });
/** Bytes the stand-in server sent from log index `from` on, by folder. */
const sent = (log, from, to = log.length) => {
  const list = log.slice(from, to), by = {};
  for (const e of list) { const k = e.path.split('/')[0] + '/'; by[k] = (by[k] || 0) + e.bytes; }
  const data = list.filter((e) => e.path.startsWith('data/'));
  return { requests: list.length, bytes: list.reduce((s, e) => s + e.bytes, 0), mb: MB(list.reduce((s, e) => s + e.bytes, 0)), byFolder: Object.fromEntries(Object.entries(by).map(([k, v]) => [k, MB(v)])),
    ranges: data.filter((e) => e.range).length, whole: data.filter((e) => !e.range && e.status === 200).length, gz: list.filter((e) => e.encoding === 'gzip').length };
};
/** QuickRace from the main menu: character, country (shift: btnRight presses), Landenrace; runs, then the cheat finishes it. */
async function quickRace(t, site, tag, shift = 0) {
  await btn(t, 'btnQuickRace').click(); await form(t, 'TFRMSELECTCHAR');
  await btn(t, 'btnOk').click(); await form(t, 'TFRMSELECTCOUNTRY');
  for (let k = 0; k < shift; k++) {
    const was = (await t.page.evaluate(() => window.rcsk.state.selection.country));
    await btn(t, 'btnRight').click();
    await until(t, (c) => window.rcsk.state.selection.country !== c && document.querySelector('[data-form=TFRMSELECTCOUNTRY]'), was, 15000);
    await t.page.waitForTimeout(300);
  }
  const country = await t.page.evaluate(() => window.rcsk.state.selection.country);
  await btn(t, 'btnOk').click(); await form(t, 'TFRMCONTROLSETTINGS');
  const mark = site.log.length, t0 = Date.now();
  await btn(t, 'btnOk').click();
  // the button waits for its sound before it acts: the race's loading screen first, then the race on the canvas
  await until(t, () => window.rcsk.state.racing && window.rcsk.state.page === 'loading', null, 30000);
  const loadingMs = Date.now() - t0;
  await until(t, () => window.rcsk.state.page === 'driving' || !window.rcsk.state.racing, null, 240000);
  const runningMs = Date.now() - t0 - loadingMs;
  const atRun = site.log.length;
  await until(t, () => { const r = window.rcsk.runner; return Atomics.load(r.ctrl, 4) === 0 && Atomics.load(r.ctrl, 3) >= 340; }, null, 120000);
  await t.page.keyboard.down('ArrowUp'); await t.page.waitForTimeout(1500); await t.page.keyboard.up('ArrowUp');
  await shot(t, tag + '-race');
  await t.page.keyboard.down('Control'); await t.page.keyboard.down('KeyF'); await t.page.keyboard.down('KeyI');
  await t.page.waitForTimeout(150);
  await t.page.keyboard.up('KeyI'); await t.page.keyboard.up('KeyF'); await t.page.keyboard.up('Control');
  await until(t, () => Atomics.load(window.rcsk.runner.ctrl, 4) === 3, null, 20000);
  await form(t, 'TFRMDEBRIEF', 60000);
  await shot(t, tag + '-debrief');
  const info = await t.page.evaluate(() => ({ load: window.rcsk.runner.lastLoad, files: window.rcsk.runner.lastFiles, last: JSON.parse(localStorage.getItem('rcsk.race-save.v1') || '{}').lastResult }));
  // back to the main menu through the notices and the highscore name
  await btn(t, 'btnBack').click();
  for (let i = 0; i < 12 && (await currentForm(t)) !== 'TFRMMAIN'; i++) {
    await t.page.waitForTimeout(600);
    const f = await currentForm(t);
    if (f === 'TFRMREQUESTER' || f === 'TFRMEDITBOX') { await btn(t, 'btnOk').click().catch(() => {}); await until(t, (x) => (document.querySelector('#screen:not([hidden]) [data-form]')?.dataset.form || null) !== x, f, 15000).catch(() => {}); }
  }
  return { country, runningMs, beforeRunning: sent(site.log, mark, atRun), wholeRace: sent(site.log, mark), worker: info, finished: info.last?.PLAYER?.finished === 1, menu: await currentForm(t) };
}

const site = await serveSite({ root: SITE, port: 0, prefix: PREFIX, latency: LATENCY, classic: haveClassic ? CLASSIC : null });
report.races = {};
const profile = newProfile();
{
  let t = await open(profile);
  const t0 = Date.now();
  await t.page.goto(site.url + '?skipIntro&cheats');
  await form(t, 'TFRMMAIN');
  await t.page.waitForTimeout(1500);
  const menuMs = Date.now() - t0;
  // QuickRace on another track needs it unlocked: Meer instellingen' Alles ontgrendelen, through the menu's own save code
  await t.page.evaluate(async (app) => { const m = await import(`./${app}source/menu/race-save.js`); const s = m.readRaceSave(); m.unlockAllCountries(s); m.writeRaceSave(s); }, APP);
  await t.page.reload(); await form(t, 'TFRMMAIN'); await t.page.waitForTimeout(800);
  const info = await t.page.evaluate(() => ({ isolated: self.crossOriginIsolated, notice: !document.getElementById('unsupported').hidden, images: [...document.images].filter((i) => i.complete && i.naturalWidth === 0 && i.getAttribute('src')).map((i) => i.getAttribute('src')) }));
  await shot(t, 'menu');
  const menuLoad = sent(site.log, 0);
  report.menu = { ms: menuMs, ...menuLoad };
  check(info.isolated && !info.notice, 'the page is isolated and shows no not-supported notice');
  check(t.seen.bad.length === 0 && t.seen.outside.length === 0 && t.seen.errors.length === 0, `the menu comes up (${(menuMs / 1000).toFixed(1)} s, ${menuLoad.mb} MB): nothing missing, nothing outside the prefix, no script error`, [...t.seen.bad, ...t.seen.outside, ...t.seen.errors].slice(0, 4).join(' | '));
  check(info.images.length === 0, 'no picture of the page failed to load', info.images.join(' '));
  const scripts = site.log.filter((r) => /\.js$/.test(r.path));
  check(scripts.length > 20 && scripts.every((r) => r.path.startsWith(APP)), `the page's ${scripts.length} script requests go to the revision folder`);

  const r1 = await quickRace(t, site, 'race1', 0);
  report.races.first = r1;
  check(r1.finished && r1.menu === 'TFRMMAIN', `race 1, Nederland from the menu: ran (${(r1.runningMs / 1000).toFixed(1)} s from its loading screen to the race on screen), finished with the cheat, debrief and highscore, back in the main menu`, JSON.stringify({ finished: r1.finished, menu: r1.menu }));
  check(r1.wholeRace.ranges > 0 && r1.worker.files && r1.worker.files.waits <= 2, `race 1 fetched ${r1.wholeRace.mb} MB in ${r1.wholeRace.requests} requests (${r1.beforeRunning.mb} MB before it ran; ${r1.wholeRace.ranges} byte ranges, ${r1.wholeRace.whole} whole files, ${r1.wholeRace.gz} as .gz); the game thread waited ${r1.worker.files ? r1.worker.files.waits : '?'} time(s)${r1.worker.files && r1.worker.files.waits ? ' for ' + r1.worker.files.lastWaits.join(' ') : ''}`, JSON.stringify(r1.wholeRace.byFolder));
  const r2 = await quickRace(t, site, 'race2', 2);
  report.races.second = r2;
  check(r2.finished && r2.country === 2, `race 2, Groot-Brittannië in the same page: ran and finished (${(r2.runningMs / 1000).toFixed(1)} s from its loading screen to the race on screen)`, JSON.stringify({ finished: r2.finished, country: r2.country }));
  check(r2.wholeRace.bytes < r1.wholeRace.bytes / 2 && !r2.wholeRace.byFolder['app/'] && r2.worker.files.waits <= 2, `race 2 fetched ${r2.wholeRace.mb} MB in ${r2.wholeRace.requests} requests (its own track; the karts, the module and the common files kept); the game thread waited ${r2.worker.files.waits - (r1.worker.files ? r1.worker.files.waits : 0)} time(s)${r2.worker.files.waits > (r1.worker.files ? r1.worker.files.waits : 0) ? ` (${r2.worker.files.lastWaits.slice(-(r2.worker.files.waits - (r1.worker.files ? r1.worker.files.waits : 0))).join(' ')}, ${r2.worker.files.waitMs} ms in all: a sound the measured race did not play)` : ''}`, JSON.stringify(r2.wholeRace.byFolder));
  check(t.seen.bad.length === 0 && t.seen.outside.length === 0 && t.seen.errors.length === 0, 'both races: nothing missing, nothing asked for outside /redcatsuperkarts/, no script error', [...t.seen.bad, ...t.seen.outside, ...t.seen.errors].slice(0, 4).join(' | '));
  await t.context.close();

  // a second visit with the same browser profile: the scripts and the game module from the browser's cache
  t = await open(profile);
  const mark = site.log.length;
  await t.page.goto(site.url + '?skipIntro&cheats');
  await form(t, 'TFRMMAIN');
  const r3 = await quickRace(t, site, 'visit2', 0);
  const again = site.log.slice(mark);
  const appFetched = again.filter((e) => e.path.startsWith('app/') && e.status === 200);
  report.races.secondVisit = { ...r3, appFetched: appFetched.length };
  check(r3.finished && appFetched.length === 0, `second visit, race 1 again: no script or game-module file fetched again; ${MB(again.reduce((s, e) => s + e.bytes, 0))} MB sent in all (${again.length} answers; data/ ${r3.wholeRace.byFolder['data/'] || 0} MB: the browser's cache keeps whole files, its use for byte ranges is the browser's)`, appFetched.slice(0, 4).map((e) => e.path).join(' '));
  await t.context.close();
}
await site.close();

// ================================================================================================================
console.log('\nthe not-supported notice');
{
  const bare = await serveSite({ root: SITE, port: 0, prefix: PREFIX, isolation: false, classic: haveClassic ? CLASSIC : null });
  let t = await open(newProfile());
  await t.page.goto(bare.url + '?skipIntro');
  await form(t, 'TFRMMAIN');
  await t.page.waitForFunction(() => !document.getElementById('unsupported').hidden && (document.getElementById('unsupported-classic') || performance.now() > 8000), null, { timeout: 15000 }).catch(() => {});
  let n = await t.page.evaluate(() => ({ isolated: self.crossOriginIsolated, shown: !document.getElementById('unsupported').hidden, text: document.getElementById('unsupported').textContent, link: document.getElementById('unsupported-classic')?.getAttribute('href') || null }));
  await shot(t, 'unsupported-isolation');
  report.unsupported = { isolation: n };
  check(!n.isolated && n.shown && /niet starten/.test(n.text) && /cross-origin isolated/.test(n.text), 'without the isolation headers: the menu says in Dutch that the races cannot start, and why', n.text.slice(0, 160));
  if (haveClassic) check(n.link && new URL(n.link).pathname === PREFIX + 'classic/', 'and offers the old version at classic/', String(n.link));
  await t.context.close();
  await bare.close();
  const full = await serveSite({ root: SITE, port: 0, prefix: PREFIX, classic: haveClassic ? CLASSIC : null });
  t = await open(newProfile());
  await t.page.addInitScript(() => { const get = OffscreenCanvas.prototype.getContext; OffscreenCanvas.prototype.getContext = function (kind, ...rest) { return kind === 'webgl2' ? null : get.call(this, kind, ...rest); }; });
  await t.page.goto(full.url + '?skipIntro');
  await form(t, 'TFRMMAIN');
  await t.page.waitForFunction(() => !document.getElementById('unsupported').hidden, null, { timeout: 15000 }).catch(() => {});
  n = await t.page.evaluate(() => ({ shown: !document.getElementById('unsupported').hidden, text: document.getElementById('unsupported').textContent }));
  report.unsupported.webgl2 = n;
  await shot(t, 'unsupported-webgl2');
  check(n.shown && /WebGL 2/.test(n.text), 'without WebGL 2 on an OffscreenCanvas: the same notice, naming WebGL 2', n.text.slice(0, 160));
  await t.context.close();
  await full.close();
}

// ================================================================================================================
if (has('firefox')) {
  console.log('\nPlaywright\'s Firefox (reported, not a failure)');
  const ff = await serveSite({ root: SITE, port: 0, prefix: PREFIX, latency: LATENCY, classic: haveClassic ? CLASSIC : null });
  const result = {};
  let t = null;
  try {
    t = await open(newProfile(), pw.firefox, { headless: true, firefoxUserPrefs: { 'media.autoplay.default': 0, 'webgl.force-enabled': true } });
    await t.page.goto(ff.url + '?skipIntro&cheats');
    await form(t, 'TFRMMAIN');
    Object.assign(result, await t.page.evaluate(() => ({ isolated: self.crossOriginIsolated, notice: !document.getElementById('unsupported').hidden ? document.getElementById('unsupported').textContent : null, ua: navigator.userAgent })));
    await shot(t, 'firefox-menu');
    if (!result.notice) {
      await t.page.goto(ff.url + '?skipIntro&cheats&drive=0');
      await until(t, () => window.rcsk && (window.rcsk.state.page === 'driving' || (!window.rcsk.state.racing && window.rcsk.state.page !== 'loading')), null, 240000).catch((e) => { result.wait = e.message.split('\n')[0]; });
      await t.page.waitForTimeout(3000);
      const a = await t.page.evaluate(() => { const r = window.rcsk.runner; return r && r.ctrl ? { page: window.rcsk.state.page, ticks: Atomics.load(r.ctrl, 3), phase: Atomics.load(r.ctrl, 4) } : { page: window.rcsk.state.page }; });
      await t.page.waitForTimeout(3000);
      const b = await t.page.evaluate(() => { const r = window.rcsk.runner; return r && r.ctrl ? { ticks: Atomics.load(r.ctrl, 3), files: r.lastLoad, message: document.getElementById('message').hidden ? null : document.getElementById('message').textContent } : {}; });
      await shot(t, 'firefox-race');
      result.race = { ...a, ticksLater: b.ticks, load: b.files, message: b.message, runs: a.page === 'driving' && b.ticks > a.ticks };
    }
    result.errors = [...t.seen.bad, ...t.seen.errors].slice(0, 8);
  } catch (e) { result.error = e.message.split('\n')[0]; }
  if (t) await t.context.close().catch(() => {});
  await ff.close();
  report.firefox = result;
  console.log(`     Firefox: ${result.error ? 'could not be run: ' + result.error : `isolated ${result.isolated}, ${result.notice ? 'notice: ' + result.notice.slice(0, 100) : 'no notice'}${result.race ? `, race: ${result.race.runs ? `runs (${result.race.ticks} -> ${result.race.ticksLater} passes)` : 'does not run ' + JSON.stringify(result.race)}` : ''}`}${result.errors && result.errors.length ? ' | ' + result.errors.join(' | ') : ''}`);
}

for (const dir of profiles) fs.rmSync(dir, { recursive: true, force: true });
report.failed = failed;
report.revision = build.revision;
report.latency = LATENCY;
fs.writeFileSync(path.join(OUT, 'result.json'), JSON.stringify(report, null, 1) + '\n');
console.log(failed ? `\n${failed} check(s) FAILED` : '\nall checks passed');
process.exit(failed ? 1 : 0);
