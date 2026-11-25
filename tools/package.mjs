#!/usr/bin/env node
// Builds the folder a web server (or the desktop app's protocol) needs to host this port: dist/site/. Upload its
// contents to the folder that the game's address points at (docs/hosting.md: steps and server settings; the three
// nginx files go next to it in dist/). RedCat Spookkasteel's tools/package.mjs, for this port.
//
//   dist/site/
//     index.html, build.json     the page; always checked with the server
//     app/<revision>/source/     the scripts and styles of the page, the game worker and the render worker (not source/dev/)
//     app/<revision>/game/       rcskspel.wasm, its tables, files.json (the game files) and preload.json (per race)
//     assets/                    the menu's art, voices, movies, help and touch art (public/assets: tools/build-assets.mjs)
//     data/                      the original game files the race reads (files.json; tools/game-data.mjs), and
//                                index.json ([{ name, size }], as tools/serve.mjs answers /data/index.json)
//
// <revision> is made from the content of everything under it: a build with other scripts or another game module gets
// another folder name, so a browser never mixes the files of two builds, and a page that is open during an upload keeps
// finding its own files. Every URL is relative: the site works below any folder (it lives at /redcatsuperkarts/).
// Files get a .gz copy next to them where that is at least a tenth smaller (nginx: gzip_static), except the packed
// archives rcs.img and rc.img: the race reads those by byte ranges, and nginx would answer a Range request with bytes
// of the .gz (source/web/game-files.js).
//
// Read only from: this project and the game files (tools/game-data.mjs: SUPERKARTS_DATA, SUPERKARTS_DISC). Nothing is
// uploaded or published.
//   node tools/package.mjs [--out dist] [--no-gzip]
import fs from 'node:fs';
import path from 'node:path';
import zlib from 'node:zlib';
import { createHash } from 'node:crypto';
import { ROOT, raceFiles, RANGED } from './game-data.mjs';

const args = process.argv.slice(2);
const opt = (n, d) => { const k = args.indexOf('--' + n); return k >= 0 ? args[k + 1] : d; };
const has = (n) => args.includes('--' + n);
const OUT = path.resolve(ROOT, opt('out', 'dist'));
const FINAL = path.join(OUT, 'site');
const SITE = path.join(OUT, 'site.building');          // built here, then moved into place: a build that fails leaves the last good site/
const posix = path.posix;
const fail = (message) => { console.error('package: ' + message); process.exit(1); };
const mb = (n) => (n / 1048576).toFixed(1) + ' MB';

const GAME_FILES = ['rcskspel.wasm', 'rcskspel.meta.json', 'rcskspel.codemap.bin', 'files.json', 'preload.json'];
// not the movies and voices (.mp4, .wav): the browser's media elements ask for them by byte ranges, which gzip_static
// would answer from the .gz
const GZIP = /\.(html|js|css|json|svg|wasm|bin|ini|dat|ind|cmp|dmp|omp|pmp|pth|rmp|ttf|txt|md|ico)$/i;
for (const f of GAME_FILES) if (!fs.existsSync(path.join(ROOT, 'public/game', f))) fail(`public/game/${f} is missing (npm run recompile; node tools/build-manifest.mjs; npm run preload)`);
if (!fs.existsSync(path.join(ROOT, 'public/assets/manifest.json'))) fail('public/assets has not got the menu\'s assets (node tools/build-assets.mjs)');

// Only a folder this tool made is replaced.
if (fs.existsSync(FINAL) && !fs.existsSync(path.join(FINAL, 'build.json')) && fs.readdirSync(FINAL).length) fail(FINAL + ' exists and was not made by this tool; remove it or choose another --out');
fs.rmSync(SITE, { recursive: true, force: true });

const walk = (dir, rel = '') => fs.readdirSync(dir, { withFileTypes: true }).sort((a, b) => (a.name < b.name ? -1 : 1)).flatMap((e) => (e.isDirectory() ? walk(path.join(dir, e.name), rel ? rel + '/' + e.name : e.name) : [rel ? rel + '/' + e.name : e.name]));
const written = [];          // [path below site, bytes]
const put = (rel, data) => { const to = path.join(SITE, rel); fs.mkdirSync(path.dirname(to), { recursive: true }); fs.writeFileSync(to, data); written.push([rel, data.length]); };
// (the CD copy's files are read-only for their owner: every file goes out readable, 644)
const copy = (from, rel) => { const to = path.join(SITE, rel); fs.mkdirSync(path.dirname(to), { recursive: true }); fs.copyFileSync(from, to, fs.constants.COPYFILE_FICLONE); fs.chmodSync(to, 0o644); written.push([rel, fs.statSync(to).size]); };

// --- the game files' list must be the files that go out ----------------------------------------------------------
const { files: dataFiles, disc } = raceFiles();
const manifest = JSON.parse(fs.readFileSync(path.join(ROOT, 'public/game/files.json'), 'utf8'));
{
  const listed = JSON.stringify(manifest.files), now = JSON.stringify(dataFiles.map((f) => [f.name, f.size]));
  if (listed !== now) fail('public/game/files.json does not list the game files as they are now (node tools/build-manifest.mjs, then npm run preload)');
}

// --- the scripts, styles and game module: app/<revision>/ --------------------------------------------------------
// A style sheet refers to the menu's art relative to its own place (../assets/...). Below app/<revision>/ it is two
// folders deeper, so those references are written anew.
const moveCssUrls = (css, from, to) => css.replace(/url\(\s*(["']?)([^"')]+)\1\s*\)/g, (all, q, ref) => {
  if (/^(data:|https?:|\/|#)/.test(ref)) return all;
  const target = posix.normalize(posix.join(posix.dirname(from), ref));          // below the page's folder
  if (target.startsWith('source/')) return all;                                     // moves along with the sheet
  return `url(${q}${posix.relative(posix.dirname(to), target)}${q})`;
});
const app = new Map();       // path below app/<revision>/ -> bytes
for (const rel of walk(path.join(ROOT, 'source'))) {
  if (rel.startsWith('dev/')) continue;                    // the development page (tools/serve.mjs /dev/)
  let data = fs.readFileSync(path.join(ROOT, 'source', rel));
  if (rel.endsWith('.css')) data = Buffer.from(moveCssUrls(data.toString('utf8'), 'source/' + rel, 'app/R/source/' + rel));
  app.set('source/' + rel, data);
}
for (const f of GAME_FILES) app.set('game/' + f, fs.readFileSync(path.join(ROOT, 'public/game', f)));
const hash = createHash('sha256');
for (const [rel, data] of [...app].sort((a, b) => (a[0] < b[0] ? -1 : 1))) { hash.update(rel + '\0' + data.length + '\0'); hash.update(data); }
const revision = hash.digest('hex').slice(0, 12);
for (const [rel, data] of app) put(`app/${revision}/${rel}`, data);

// --- the page ----------------------------------------------------------------------------------------------------
let html = fs.readFileSync(path.join(ROOT, 'source/index.html'), 'utf8');
let moved = 0;
html = html.replace(/\b(src|href)="source\//g, (all, attr) => { moved++; return `${attr}="app/${revision}/source/`; });
if (!moved) fail('source/index.html refers to no file under source/');
put('index.html', Buffer.from(html));

// --- the menu's assets (public/assets: tools/build-assets.mjs) ---------------------------------------------------
for (const rel of walk(path.join(ROOT, 'public/assets'))) copy(path.join(ROOT, 'public/assets', rel), 'assets/' + rel);

// --- the original game files ---------------------------------------------------------------------------------------
if (manifest.base !== 'data/') fail(`files.json has base "${manifest.base}"; this tool lays the files out under data/`);
for (const f of dataFiles) copy(f.from, 'data/' + f.name);
put('data/index.json', Buffer.from(JSON.stringify(dataFiles.map((f) => ({ name: f.name, size: f.size })))));

// --- smaller copies for the server to send -------------------------------------------------------------------------
let gz = 0, saved = 0;
if (!has('no-gzip')) {
  for (const [rel, size] of [...written]) {
    if (!GZIP.test(rel) || RANGED.test(rel) || size < 1024) continue;
    const packed = zlib.gzipSync(fs.readFileSync(path.join(SITE, rel)), { level: 9 });
    if (packed.length > size * 0.9) continue;
    fs.writeFileSync(path.join(SITE, rel + '.gz'), packed);
    gz++; saved += size - packed.length;
  }
}

// --- what was built ------------------------------------------------------------------------------------------------
const pkg = JSON.parse(fs.readFileSync(path.join(ROOT, 'package.json'), 'utf8'));
const total = written.reduce((s, f) => s + f[1], 0);
const group = (prefix) => { const list = written.filter(([rel]) => rel.startsWith(prefix)); return { files: list.length, bytes: list.reduce((s, f) => s + f[1], 0) }; };
const build = { name: pkg.name, version: pkg.version, revision, built: new Date().toISOString(), files: written.length + 1, bytes: total,
  app: group('app/'), assets: group('assets/'), data: group('data/'), gzip: { files: gz, saved }, gameFilesFrom: disc ? 'cd' : 'installation' };
fs.writeFileSync(path.join(SITE, 'build.json'), JSON.stringify(build, null, 1) + '\n');
fs.rmSync(FINAL, { recursive: true, force: true });
fs.renameSync(SITE, FINAL);
for (const f of ['nginx-redcatsuperkarts.conf', 'nginx-redcatsuperkarts-cache.conf', 'nginx-redcatsuperkarts-test.conf']) fs.copyFileSync(path.join(ROOT, 'docs', f), path.join(OUT, f));

console.log(`${FINAL}
  revision ${revision}
  app/     ${String(build.app.files).padStart(5)} files  ${mb(build.app.bytes)}
  assets/  ${String(build.assets.files).padStart(5)} files  ${mb(build.assets.bytes)}
  data/    ${String(build.data.files).padStart(5)} files  ${mb(build.data.bytes)}
  total    ${String(build.files).padStart(5)} files  ${mb(total)}${gz ? `, plus ${gz} .gz copies that save ${mb(saved)} in transfer` : ''}
Check it: npm run package:check     Host it: docs/hosting.md`);
