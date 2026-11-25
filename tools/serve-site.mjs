#!/usr/bin/env node
// Serves a packaged site (dist/site, tools/package.mjs) the way the web server is meant to (docs/nginx-redcatsuperkarts*.conf):
// only below a path prefix, with the isolation headers, the cache rule of each folder, the .gz copy next to a file for a
// client that accepts gzip (also for a Range request, as nginx's gzip_static does: the range is then of the .gz bytes,
// which is why the package has no .gz of a file read by ranges), byte ranges (206, 416), 304 for a copy that is still
// good, and a plain 404 for anything else. The JavaScript port can be served at <prefix>classic/ as the site serves it
// today (no-cache, no isolation headers). For tools/package-check.mjs and for trying a package by hand. RedCat
// Spookkasteel's tools/serve-site.mjs, for this port. A stand-in for the web server, not the web server: it says nothing
// about the nginx files being right for nginx.
//   node tools/serve-site.mjs [--root dist/site] [--port 4196] [--prefix /redcatsuperkarts/] [--latency 0]
//        [--classic ../RedCat Superkarts/dist]   the JavaScript port's built site, at <prefix>classic/
//        [--no-isolation]                         without the two isolation headers (the page must say it cannot run)
import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const ROOT = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const TYPES = { '.html': 'text/html', '.js': 'application/javascript', '.css': 'text/css', '.json': 'application/json', '.wasm': 'application/wasm', '.png': 'image/png', '.svg': 'image/svg+xml', '.wav': 'audio/wav', '.ttf': 'font/ttf', '.jpg': 'image/jpeg', '.ico': 'image/x-icon', '.mp4': 'video/mp4', '.txt': 'text/plain', '.md': 'text/plain', '.ini': 'application/octet-stream' };
const ISOLATION = { 'Cross-Origin-Opener-Policy': 'same-origin', 'Cross-Origin-Embedder-Policy': 'require-corp' };
/** Cache-Control for a path below the prefix, as the map in docs/nginx-redcatsuperkarts-cache.conf; like nginx's add_header without "always" it goes on 2xx and 3xx answers only. */
export const cachePolicy = (rel) => (/^(app|data)\//.test(rel) ? 'public, max-age=31536000, immutable' : /^assets\//.test(rel) ? 'public, max-age=86400' : 'no-cache');

/**
 * Starts the server. Returns { url, port, log, close() }; log is every request as
 * { method, path (below the prefix), status, encoding, range, bytes (body bytes sent), at (ms since start) }.
 */
export function serveSite({ root = path.join(ROOT, 'dist/site'), port = 4196, prefix = '/redcatsuperkarts/', latency = 0, classic = null, isolation = true } = {}) {
  const log = [];
  const t0 = Date.now();
  const server = http.createServer((req, res) => {
    const answer = () => {
      const url = new URL(req.url, 'http://x');
      let p;
      try { p = decodeURIComponent(url.pathname); } catch (e) { p = url.pathname; }
      const entry = { method: req.method, path: p.startsWith(prefix) ? p.slice(prefix.length) : p, status: 0, bytes: 0, at: Date.now() - t0 };
      log.push(entry);
      const send = (status, headers, body) => { entry.status = status; res.writeHead(status, headers); if (body && req.method !== 'HEAD') { entry.bytes = body.length; res.end(body); } else res.end(); };
      if (p === prefix.slice(0, -1)) { send(301, { Location: prefix + url.search }); return; }
      if (!p.startsWith(prefix)) { send(404, { 'Content-Type': 'text/html' }, Buffer.from('404')); return; }
      let rel = p.slice(prefix.length);
      if (rel === '' || rel.endsWith('/')) rel += 'index.html';
      // classic/: the JavaScript port's own location, answered as today (the server's no-cache, no isolation headers)
      const old = classic && rel.startsWith('classic/');
      const base = old ? { 'Cache-Control': 'no-cache' } : { ...(isolation ? ISOLATION : {}) };
      const miss = () => send(404, { ...base, 'Content-Type': 'text/html' }, Buffer.from('404'));
      if (/(^|\/)\./.test(rel)) { miss(); return; }                  // location ~ ^/redcatsuperkarts/(?:\.|.*/\.)
      const dir = old ? classic : root;
      let file = path.join(dir, old ? rel.slice('classic/'.length) : rel);
      if (!file.startsWith(dir + path.sep)) { miss(); return; }
      let st;
      try { st = fs.statSync(file); } catch (e) { miss(); return; }
      if (st.isDirectory()) { send(301, { ...base, Location: p + '/' }); return; }
      const headers = { ...base, 'Content-Type': TYPES[path.extname(file).toLowerCase()] || 'application/octet-stream', 'Cache-Control': old ? 'no-cache' : cachePolicy(rel) };
      // gzip_static (not for classic/, which has nginx's dynamic gzip: left out here)
      if (!old && /\bgzip\b/.test(req.headers['accept-encoding'] || '')) {
        try { const gz = fs.statSync(file + '.gz'); file += '.gz'; st = gz; entry.encoding = 'gzip'; headers['Content-Encoding'] = 'gzip'; headers.Vary = 'Accept-Encoding'; } catch (e) { /* none */ }
      }
      const etag = `"${Math.floor(st.mtimeMs / 1000).toString(16)}-${st.size.toString(16)}"`;
      headers.ETag = etag; headers['Last-Modified'] = st.mtime.toUTCString(); headers['Accept-Ranges'] = 'bytes';
      if (req.headers['if-none-match'] === etag) { send(304, headers); return; }
      const range = req.headers.range;
      if (range) {
        entry.range = range;
        const m = /^bytes=(\d*)-(\d*)$/.exec(range);
        let start = m && m[1] ? Number(m[1]) : m && m[2] ? st.size - Number(m[2]) : NaN;
        let end = m && m[1] && m[2] ? Math.min(Number(m[2]), st.size - 1) : st.size - 1;
        if (!m || !(start >= 0) || start > end || start >= st.size) { send(416, { ...base, 'Content-Range': `bytes */${st.size}` }); return; }
        const fd = fs.openSync(file, 'r');
        const body = Buffer.alloc(end - start + 1);
        fs.readSync(fd, body, 0, body.length, start);
        fs.closeSync(fd);
        send(206, { ...headers, 'Content-Range': `bytes ${start}-${end}/${st.size}`, 'Content-Length': body.length }, body);
        return;
      }
      const body = req.method === 'HEAD' ? null : fs.readFileSync(file);
      send(200, { ...headers, 'Content-Length': st.size }, body);
    };
    if (latency > 0) setTimeout(answer, latency); else answer();
  });
  return new Promise((resolve, reject) => {
    server.on('error', reject);
    server.listen(port, '127.0.0.1', () => resolve({ url: `http://127.0.0.1:${server.address().port}${prefix}`, port: server.address().port, log,
      close: () => new Promise((done) => { server.closeAllConnections(); server.close(done); }) }));
  });
}

if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  const args = process.argv.slice(2);
  const opt = (n, d) => { const k = args.indexOf('--' + n); return k >= 0 ? args[k + 1] : d; };
  const classic = opt('classic', null);
  const s = await serveSite({ root: path.resolve(opt('root', path.join(ROOT, 'dist/site'))), port: Number(opt('port', 4196)), prefix: opt('prefix', '/redcatsuperkarts/'),
    latency: Number(opt('latency', 0)), classic: classic ? path.resolve(classic) : null, isolation: !args.includes('--no-isolation') });
  console.log(s.url);
}
