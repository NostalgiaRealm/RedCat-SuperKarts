// Read-only static server for the JS port's committed runtime (index.html, src/, public/assets as /assets/), for
// side-by-side screenshots. Unlike its tools/serve.mjs it does not rebuild src/ into the checkout.
import { createServer } from 'node:http';
import { createReadStream, statSync, existsSync } from 'node:fs';
import { dirname, extname, join, normalize, resolve, sep } from 'node:path';
import { fileURLToPath } from 'node:url';
const ROOT = resolve(process.env.SUPERKARTS_JS || join(dirname(fileURLToPath(import.meta.url)), '..', '..', '..', '..', 'RedCat Superkarts'));
const TYPES = { '.html': 'text/html; charset=utf-8', '.js': 'text/javascript', '.css': 'text/css', '.json': 'application/json', '.png': 'image/png', '.svg': 'image/svg+xml',
  '.wav': 'audio/wav', '.mp3': 'audio/mpeg', '.mp4': 'video/mp4', '.ttf': 'font/ttf', '.ico': 'image/x-icon', '.bin': 'application/octet-stream', '.gif': 'image/gif', '.bmp': 'image/bmp' };
const map = (p) => p === '/' ? join(ROOT, 'index.html') : p.startsWith('/src/') ? join(ROOT, p) : p.startsWith('/assets/') ? join(ROOT, 'public', p) : null;
createServer((req, res) => {
  const file = map(decodeURIComponent(new URL(req.url, 'http://x').pathname));
  if (!file || !normalize(file).startsWith(ROOT + sep) || !existsSync(file) || statSync(file).isDirectory()) { res.writeHead(404); res.end(); return; }
  const size = statSync(file).size, type = TYPES[extname(file).toLowerCase()] || 'application/octet-stream';
  const range = /bytes=(\d+)-(\d*)/.exec(req.headers.range || '');
  if (range) { const s = +range[1], e = range[2] ? Math.min(+range[2], size - 1) : size - 1;
    res.writeHead(206, { 'Content-Type': type, 'Content-Range': `bytes ${s}-${e}/${size}`, 'Content-Length': e - s + 1, 'Accept-Ranges': 'bytes' }); createReadStream(file, { start: s, end: e }).pipe(res); return; }
  res.writeHead(200, { 'Content-Type': type, 'Content-Length': size, 'Accept-Ranges': 'bytes' }); createReadStream(file).pipe(res);
}).listen(4173, '127.0.0.1', () => console.log('http://127.0.0.1:4173/'));
