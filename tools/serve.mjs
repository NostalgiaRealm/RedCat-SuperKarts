#!/usr/bin/env node
// Development server: the page and its modules from source/, the recompiled race and its file lists from public/game/,
// and the original game files from the installation's data folder (read-only) under /data/, with byte ranges (the
// worker reads rcs.img and rc.img by ranges: source/web/game-files.js). /data/index.json lists them ([{ name, size }];
// the worker uses public/game/files.json, tools/package.mjs writes the same list to data/index.json). /dev/race.html is the
// development page for races without the menu (source/dev/race.html, tools/check-*.mjs use it).
//   node tools/serve.mjs [--data DIR]   (PORT, default 4190; DIR as in tools/run-headless.mjs)
import { createServer } from 'node:http';
import { createReadStream, statSync, existsSync, readdirSync } from 'node:fs';
import { extname, join, normalize, sep, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const opt = (name, def) => { const k = process.argv.indexOf('--' + name); return k < 0 ? def : process.argv[k + 1]; };
const DEFAULT_DATA = join(ROOT, '..', 'RedCat Superkarts', 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c',
  'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
const DATA = opt('data', process.env.SUPERKARTS_DATA || DEFAULT_DATA);
const PORT = Number(process.env.PORT || 4190);
const TYPES = {
  '.wav': 'audio/wav', '.mp3': 'audio/mpeg', '.mp4': 'video/mp4', '.ttf': 'font/ttf', '.ico': 'image/x-icon', '.svg': 'image/svg+xml',
  '.html': 'text/html; charset=utf-8', '.js': 'text/javascript; charset=utf-8', '.mjs': 'text/javascript; charset=utf-8',
  '.css': 'text/css; charset=utf-8', '.svg': 'image/svg+xml', '.json': 'application/json', '.wasm': 'application/wasm', '.png': 'image/png',
};
// The menu's prepared assets (art, forms, fonts, voices, movies, help) are this project's public/assets, the part of the
// JS reconstruction's that the menu uses (tools/build-assets.mjs). Its public/assets (read-only; SUPERKARTS_ASSETS
// overrides) stays behind them as a fallback for a file not copied yet; tools/package.mjs takes only this project's.
const JS_ASSETS = process.env.SUPERKARTS_ASSETS || join(ROOT, '..', 'RedCat Superkarts', 'public', 'assets');
const ROUTES = [['/dev/', join(ROOT, 'source', 'dev')], ['/game/', join(ROOT, 'public', 'game')], ['/assets/', join(ROOT, 'public', 'assets')], ['/assets/', JS_ASSETS], ['/data/', DATA], ['/source/', join(ROOT, 'source')], ['/evidence/', join(ROOT, 'evidence')]];

function resolve(pathname) {
  if (pathname === '/' || pathname === '/index.html') return join(ROOT, 'source', 'index.html');
  if (pathname === '/dev' || pathname === '/dev/') return join(ROOT, 'source', 'dev', 'race.html');
  for (const [prefix, dir] of ROUTES) {
    if (!pathname.startsWith(prefix)) continue;
    const full = normalize(join(dir, pathname.slice(prefix.length)));
    if (!full.startsWith(dir + sep)) return null;
    if (existsSync(full)) return full;          // else the next route with the same prefix
  }
  return null;
}

// Cross-origin isolation: the game worker and the render worker share memory with the page (SharedArrayBuffer).
const ISOLATION = { 'Cross-Origin-Opener-Policy': 'same-origin', 'Cross-Origin-Embedder-Policy': 'require-corp', 'Cross-Origin-Resource-Policy': 'same-origin' };

createServer((req, res) => {
  for (const [k, v] of Object.entries(ISOLATION)) res.setHeader(k, v);
  const url = new URL(req.url, 'http://x');
  const path = decodeURIComponent(url.pathname);
  if (path === '/data/index.json') {
    const files = readdirSync(DATA).filter((n) => statSync(join(DATA, n)).isFile()).map((n) => ({ name: n, size: statSync(join(DATA, n)).size }));
    res.writeHead(200, { 'Content-Type': 'application/json', 'Cache-Control': 'no-cache' });
    res.end(JSON.stringify(files));
    return;
  }
  const file = resolve(path);
  if (!file || !existsSync(file) || statSync(file).isDirectory()) { res.writeHead(404); res.end('not found'); return; }
  const size = statSync(file).size;
  const type = TYPES[extname(file).toLowerCase()] || 'application/octet-stream';
  const range = /bytes=(\d+)-(\d*)/.exec(req.headers.range || '');
  if (range) {
    const start = Number(range[1]);
    const end = range[2] ? Math.min(Number(range[2]), size - 1) : size - 1;
    res.writeHead(206, { 'Content-Type': type, 'Content-Range': `bytes ${start}-${end}/${size}`, 'Content-Length': end - start + 1, 'Accept-Ranges': 'bytes', 'Cache-Control': 'no-cache' });
    createReadStream(file, { start, end }).pipe(res);
    return;
  }
  res.writeHead(200, { 'Content-Type': type, 'Content-Length': size, 'Accept-Ranges': 'bytes', 'Cache-Control': 'no-cache' });
  createReadStream(file).pipe(res);
}).listen(PORT, '127.0.0.1', () => console.log(`http://127.0.0.1:${PORT}/  (data: ${DATA})`));
