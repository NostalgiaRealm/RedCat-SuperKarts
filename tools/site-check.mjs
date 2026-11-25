#!/usr/bin/env node
// Checks a web server that hosts the packaged site against the package on this computer (dist/site): is every file
// there, whole, and sent the way the port needs it? Run it against the real server before and after the switch
// (docs/hosting.md). It only asks (GET and HEAD); it changes nothing, on the server or here. RedCat Spookkasteel's
// tools/site-check.mjs, for this port.
//   - the build on the server is the build in dist/site
//   - the page: isolation headers, checked with the server every time, the same bytes
//   - every file of the package: answered 200 with its size (uploaded, readable, no rule of the server in its way,
//     whatever its extension), with the cache rule of its folder and the isolation headers
//   - scripts and the game module and its lists: the same bytes as here
//   - byte ranges of rcs.img: 206 with exactly those bytes, not packed (the race reads it so), from a client that
//     accepts gzip as a browser does; a range beyond the end: 416
//   - the .gz copies are used (a note when they are not: the site works without)
//   - a file that is not there: 404, not to be kept
//   - with --classic: the JavaScript port at classic/ as it was (its page, bundle and runtime manifest are the ones in
//     ../RedCat Superkarts/dist, no isolation headers, no-cache)
//   - with --burst: what a visitor's browser asks for before race 1 (Nederland, RedCat, Landenrace: its files and its
//     archive pages by the lists, six at a time), twice, to see whether the server refuses any of it
//   node tools/site-check.mjs --url https://games.nostalgiarealm.com/redcatsuperkarts/ [--site dist/site] [--parallel 8]
//        [--classic] [--burst]
import fs from 'node:fs';
import path from 'node:path';
import http from 'node:http';
import https from 'node:https';
import zlib from 'node:zlib';
import { createHash } from 'node:crypto';
import { ROOT } from './game-data.mjs';

const args = process.argv.slice(2);
const opt = (n, d) => { const k = args.indexOf('--' + n); return k >= 0 ? args[k + 1] : d; };
const has = (n) => args.includes('--' + n);
const SITE = path.resolve(ROOT, opt('site', 'dist/site'));
const PARALLEL = Number(opt('parallel', 8));
let base = opt('url', null);
if (!base) { console.error('usage: node tools/site-check.mjs --url https://host/path/ [--classic] [--burst]'); process.exit(2); }
if (!base.endsWith('/')) base += '/';
const BASE = new URL(base);
const mod = BASE.protocol === 'https:' ? https : http;
const agent = new mod.Agent({ keepAlive: true, maxSockets: Math.max(PARALLEL, 16) });

let failed = 0, notes = 0;
const check = (ok, what, detail = '') => { if (!ok) failed++; console.log(`${ok ? 'ok  ' : 'FAIL'} ${what}${detail ? '  [' + detail + ']' : ''}`); return ok; };
const note = (what) => { notes++; console.log('note ' + what); };
const sha = (b) => createHash('sha256').update(b).digest('hex');
const mb = (n) => (n / 1048576).toFixed(1) + ' MB';
const enc = (rel) => rel.split('/').map(encodeURIComponent).join('/');

/** One request. encoding: what the client says it accepts. body: keep the answer's bytes (unpacked when sent as gzip). */
const ask = (method, target, { encoding = 'identity', body = false, range = null } = {}) => new Promise((resolve) => {
  const headers = { 'Accept-Encoding': encoding, 'User-Agent': 'site-check' };
  if (range) headers.Range = range;
  const req = mod.request(target, { method, agent, timeout: 60000, headers }, (res) => {
    const chunks = [];
    res.on('data', (c) => { if (body) chunks.push(c); });
    res.on('end', () => {
      let bytes = Buffer.concat(chunks);
      const packed = bytes.length;
      if (body && res.headers['content-encoding'] === 'gzip') { try { bytes = zlib.gunzipSync(bytes); } catch (e) { bytes = Buffer.alloc(0); } }
      resolve({ status: res.statusCode, headers: res.headers, body: bytes, packed });
    });
    res.on('error', (e) => resolve({ status: 0, headers: {}, error: e.message, body: Buffer.alloc(0) }));
  });
  req.on('timeout', () => req.destroy(new Error('no answer in 60 s')));
  req.on('error', (e) => resolve({ status: 0, headers: {}, error: e.message, body: Buffer.alloc(0) }));
  req.end();
});
const at = (rel) => new URL(enc(rel), BASE);
const pool = async (items, n, fn) => { let k = 0; const out = new Array(items.length); await Promise.all(Array.from({ length: n }, async () => { while (k < items.length) { const i = k++; out[i] = await fn(items[i], i); } })); return out; };

if (!fs.existsSync(path.join(SITE, 'build.json'))) { console.error(SITE + ' is not a packaged site (npm run package)'); process.exit(2); }
const build = JSON.parse(fs.readFileSync(path.join(SITE, 'build.json'), 'utf8'));
const APP = `app/${build.revision}/`;
const walk = (dir, rel = '') => fs.readdirSync(dir, { withFileTypes: true }).flatMap((e) => (e.isDirectory() ? walk(path.join(dir, e.name), rel ? rel + '/' + e.name : e.name) : [rel ? rel + '/' + e.name : e.name]));
const files = walk(SITE).filter((f) => !f.endsWith('.gz'));
const local = (rel) => fs.readFileSync(path.join(SITE, rel));
const size = (rel) => fs.statSync(path.join(SITE, rel)).size;
const policy = (rel) => (/^(app|data)\//.test(rel) ? 'public, max-age=31536000, immutable' : /^assets\//.test(rel) ? 'public, max-age=86400' : 'no-cache');
const isolated = (r) => r.headers['cross-origin-opener-policy'] === 'same-origin' && r.headers['cross-origin-embedder-policy'] === 'require-corp';
const why = (r) => (r.status ? `${r.status}` : r.error || 'no answer');

console.log(`${base}  against ${SITE} (revision ${build.revision}, ${files.length} files)`);
const t0 = Date.now();

// --- the server and the build -----------------------------------------------------------------------------------
let r = await ask('GET', at('build.json'), { body: true });
if (!check(r.status === 200, 'the address answers: build.json is there', why(r))) { console.log('\nnothing else can be checked'); process.exit(1); }
let remote = null;
try { remote = JSON.parse(r.body.toString('utf8')); } catch (e) { remote = null; }
check(remote && remote.revision === build.revision, `the server has the build of dist/site (revision ${build.revision})`, remote ? 'the server has ' + remote.revision : 'build.json is not what tools/package.mjs wrote');
console.log(`     server: ${r.headers.server || 'not named'}`);

// --- the page ---------------------------------------------------------------------------------------------------
r = await ask('GET', BASE, { encoding: 'gzip', body: true });
check(r.status === 200 && /text\/html/.test(r.headers['content-type'] || ''), 'the page: 200, text/html', `${why(r)} ${r.headers['content-type'] || ''}`);
check(isolated(r), 'the page: the two isolation headers (without them no race starts)', `COOP ${r.headers['cross-origin-opener-policy'] || 'none'}, COEP ${r.headers['cross-origin-embedder-policy'] || 'none'}`);
check(/no-cache/.test(r.headers['cache-control'] || '') && !/max-age=[1-9]|immutable/.test(r.headers['cache-control'] || ''), 'the page: checked with the server at every visit (no-cache)', r.headers['cache-control'] || 'no Cache-Control');
check(sha(r.body) === sha(local('index.html')), 'the page: the bytes of dist/site/index.html');
if (!r.headers['strict-transport-security'] && BASE.protocol === 'https:') note('the page has no Strict-Transport-Security header: the server\'s security headers (snippets/security-headers.conf) are not included in this location');
{ const bare = new URL(BASE); bare.pathname = bare.pathname.replace(/\/$/, ''); r = await ask('GET', bare);
  check((r.status === 301 || r.status === 302 || r.status === 308) && /\/$/.test(String(r.headers.location || '').split('?')[0]), 'the address without its slash is sent on to the one with it', `${why(r)} ${r.headers.location || ''}`); }

// --- every file -------------------------------------------------------------------------------------------------
const heads = await pool(files, PARALLEL, async (rel) => ({ rel, r: await ask('HEAD', at(rel)) }));
const report = (list, what) => { for (const x of list.slice(0, 8)) console.log(`       ${x.rel}: ${what(x)}`); if (list.length > 8) console.log(`       … and ${list.length - 8} more`); };
{
  const refused = heads.filter((x) => x.r.status === 429 || x.r.status >= 500 || x.r.status === 0);
  const missing = heads.filter((x) => x.r.status !== 200 && !refused.includes(x));
  check(missing.length === 0, `all ${files.length} files are answered with 200 (${mb(files.reduce((s, f) => s + size(f), 0))})`, missing.length ? `${missing.length} are not` : '');
  report(missing, (x) => why(x.r));
  const byExt = {}; for (const x of missing) { const e = path.extname(x.rel).toLowerCase() || '(none)'; byExt[e] = (byExt[e] || 0) + 1; }
  if (missing.length) console.log('       by extension: ' + Object.entries(byExt).map(([e, n]) => `${e} ${n}`).join(', '));
  check(refused.length === 0, 'the server refused none of these requests (429, 5xx or no answer)', refused.length ? `${refused.length} refused, e.g. ${refused[0].rel}: ${why(refused[0].r)}` : '');
  const ok = heads.filter((x) => x.r.status === 200);
  const wrongSize = ok.filter((x) => Number(x.r.headers['content-length']) !== size(x.rel) || x.r.headers['content-encoding']);
  check(wrongSize.length === 0, 'each has the size it has here, when asked for as it is', wrongSize.length ? `${wrongSize.length} differ` : '');
  report(wrongSize, (x) => `${x.r.headers['content-length']} bytes${x.r.headers['content-encoding'] ? ' as ' + x.r.headers['content-encoding'] : ''}, here ${size(x.rel)}`);
  const noIso = ok.filter((x) => !isolated(x.r));
  check(noIso.length === 0, 'each carries the two isolation headers (the workers and every file they fetch need them too)', noIso.length ? `${noIso.length} do not, e.g. ${noIso[0].rel}` : '');
  const wrongCache = ok.filter((x) => (x.r.headers['cache-control'] || '') !== policy(x.rel));
  const strict = wrongCache.filter((x) => policy(x.rel) === 'no-cache');
  check(strict.length === 0, 'index.html and build.json are not to be kept without asking', strict.map((x) => `${x.rel}: ${x.r.headers['cache-control'] || 'no Cache-Control'}`).join('; '));
  const loose = wrongCache.filter((x) => !strict.includes(x));
  if (loose.length) note(`${loose.length} files under app/, data/ or assets/ do not have their folder's cache rule (e.g. ${loose[0].rel}: "${loose[0].r.headers['cache-control'] || 'none'}", expected "${policy(loose[0].rel)}"). The site works; browsers then ask the server about these files more often than needed.`);
  else check(true, 'app/ and data/ may be kept for good, assets/ for a day');
  const jsType = ok.filter((x) => x.rel.endsWith('.js') && !/javascript/.test(x.r.headers['content-type'] || ''));
  check(jsType.length === 0, 'scripts are sent as JavaScript (a browser refuses a module of another type)', jsType.length ? `${jsType[0].rel}: ${jsType[0].r.headers['content-type']}` : '');
  const wasm = ok.find((x) => x.rel.endsWith('rcskspel.wasm'));
  if (wasm && !/application\/wasm/.test(wasm.r.headers['content-type'] || '')) note(`the game module is sent as "${wasm.r.headers['content-type']}", not application/wasm: it is compiled from its bytes, so this works`);
}

// --- the same bytes: scripts, the game module and its lists, some of the game's files -----------------------------
{
  const code = files.filter((f) => f.startsWith(APP));
  const sample = files.filter((f) => f.startsWith('data/') && !/\.img$/i.test(f)).filter((f, i, a) => i % Math.ceil(a.length / 30) === 0);
  const got = await pool([...code, ...sample], PARALLEL, async (rel) => ({ rel, r: await ask('GET', at(rel), { encoding: 'gzip', body: true }) }));
  const differ = got.filter((x) => x.r.status !== 200 || sha(x.r.body) !== sha(local(x.rel)));
  check(differ.length === 0, `the ${code.length} files under ${APP} and ${sample.length} of the game's files hold the same bytes as here`, differ.slice(0, 4).map((x) => x.rel).join(' '));
  const withCopy = got.filter((x) => fs.existsSync(path.join(SITE, x.rel + '.gz')));
  const packed = withCopy.filter((x) => x.r.headers['content-encoding'] === 'gzip');
  const wasm = got.find((x) => x.rel.endsWith('rcskspel.wasm'));
  if (packed.length === withCopy.length) check(true, `the .gz copies are used (${packed.length} of ${withCopy.length} asked for; the game module travels as ${mb(wasm.r.packed)})`);
  else note(`the .gz copies are not used for ${withCopy.length - packed.length} of ${withCopy.length} files asked for (gzip_static is off or its module is missing). The site works; the game module then travels as ${mb(size(wasm.rel))} instead of ${mb(size(wasm.rel + '.gz'))}.`);
}

// --- the packed archive by byte ranges, as the game worker asks for it ---------------------------------------------
{
  const img = 'data/rcs.img', total = size(img);
  const fd = fs.openSync(path.join(SITE, img), 'r');
  const want = (a, b) => { const out = Buffer.alloc(b - a + 1); fs.readSync(fd, out, 0, out.length, a); return out; };
  const probes = [[0, 16383], [150798336, 150863871], [total - 16384, total - 1]];
  const got = await pool(probes, 3, async ([a, b]) => ({ a, b, r: await ask('GET', at(img), { encoding: 'gzip, deflate, br', body: true, range: `bytes=${a}-${b}` }) }));
  const bad = got.filter((x) => x.r.status !== 206 || x.r.headers['content-encoding'] || !x.r.body.equals(want(x.a, x.b)) || x.r.headers['content-range'] !== `bytes ${x.a}-${x.b}/${total}`);
  check(bad.length === 0, `${img} by byte ranges (three, from a client that takes gzip): 206 with exactly those bytes, not packed`, bad.map((x) => `${x.a}-${x.b}: ${why(x.r)} ${x.r.headers['content-range'] || ''} ${x.r.headers['content-encoding'] || ''}`).join('; '));
  fs.closeSync(fd);
  check(got.every((x) => isolated(x.r) && /immutable/.test(x.r.headers['cache-control'] || '')), 'those answers carry the isolation headers and may be kept for good');
  r = await ask('GET', at(img), { range: `bytes=${total}-` });
  check(r.status === 416, 'a range beyond the end: 416', why(r));
}

// --- what is not there ------------------------------------------------------------------------------------------
r = await ask('GET', at(APP + 'source/web/nothing-here.js'));
check(r.status === 404 && !/max-age=[1-9]|immutable/.test(r.headers['cache-control'] || ''), 'a script that is not there: 404, and not to be kept', `${why(r)} ${r.headers['cache-control'] || ''}`);
r = await ask('GET', at('.git/config'));
check(r.status === 404, 'a dotfile path: 404', why(r));

// --- the JavaScript port at classic/ ----------------------------------------------------------------------------
r = await ask('GET', at('classic/index.html'), { encoding: 'gzip', body: true });
if (has('classic') || r.status === 200) {
  const OLD = path.resolve(ROOT, '..', 'RedCat Superkarts', 'dist');
  check(r.status === 200, 'classic/: the JavaScript port answers (the not-supported notice offers it)', why(r));
  check(/no-cache/.test(r.headers['cache-control'] || '') && !isolated(r), 'classic/: checked with the server at every visit, no isolation headers, as before', `${r.headers['cache-control'] || 'no Cache-Control'}, COOP ${r.headers['cross-origin-opener-policy'] || 'none'}`);
  if (fs.existsSync(path.join(OLD, 'index.html'))) {
    check(sha(r.body) === sha(fs.readFileSync(path.join(OLD, 'index.html'))), 'classic/: its page is the one in ../RedCat Superkarts/dist');
    const olds = ['src/main.js', 'runtime-manifest.json', 'assets/manifest.json', 'assets/media/intro.mp4'].filter((f) => fs.existsSync(path.join(OLD, f)));
    const got = await pool(olds, 4, async (rel) => ({ rel, r: await ask('HEAD', at('classic/' + rel)) }));
    const bad = got.filter((x) => x.r.status !== 200 || Number(x.r.headers['content-length']) !== fs.statSync(path.join(OLD, x.rel)).size);
    check(bad.length === 0, `classic/: its bundle, runtime manifest, asset list and intro movie are there at their sizes (${olds.length} files)`, bad.map((x) => `${x.rel}: ${why(x.r)}`).join('; '));
  }
} else note('no classic/ at this address (expected at the temporary address; after the switch, run with --classic)');

// --- race 1's start, as a browser asks for it -------------------------------------------------------------------
if (has('burst')) {
  const lists = JSON.parse(local(APP + 'game/preload.json').toString('utf8'));
  const manifest = JSON.parse(local(APP + 'game/files.json').toString('utf8'));
  const pick = (g) => [g.common, g.country && g.country[0], g.raceType && g.raceType[0], g.character && g.character[0], g.race && g.race['0.0.0']].filter(Boolean).flat();
  const jobs = [...new Set([...pick(lists.files), ...manifest.files.map(([n]) => n).filter((n) => /\.ini$/i.test(n))])].map((n) => ({ rel: 'data/' + n }));
  for (const [name, groups] of Object.entries(lists.ranges)) for (const [first, count] of pick(groups)) jobs.push({ rel: 'data/' + name, range: `bytes=${first * lists.page}-${Math.min(size('data/' + name), (first + count) * lists.page) - 1}` });
  for (const round of [1, 2]) {
    const t = Date.now();
    const got = await pool(jobs, 6, async (j) => ({ ...j, r: await ask('GET', at(j.rel), { encoding: 'gzip', body: true, range: j.range }) }));
    const refused = got.filter((x) => x.r.status !== (x.range ? 206 : 200));
    const bytes = got.reduce((s, x) => s + (x.r.packed || 0), 0);
    check(refused.length === 0, `race 1's start, round ${round}: ${jobs.length} requests, six at a time, all answered (${mb(bytes)} in ${((Date.now() - t) / 1000).toFixed(1)} s)`, refused.length ? `${refused.length} not answered, e.g. ${refused[0].rel}: ${why(refused[0].r)}` : '');
  }
}

agent.destroy();
console.log(`\n${failed ? failed + ' check(s) FAILED' : 'all checks passed'}${notes ? `, ${notes} note(s)` : ''}  (${((Date.now() - t0) / 1000).toFixed(0)} s)`);
process.exit(failed ? 1 : 0);
