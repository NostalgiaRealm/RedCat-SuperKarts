// source/web/game-files.js: the lists a race fetches, byte ranges of the packed archives kept as pages, reads nobody
// foresaw fetched synchronously, and a server that ignores Range. fetch and XMLHttpRequest answered from a made-up file.
import test from 'node:test';
import assert from 'node:assert/strict';
import { GameFiles } from '../source/web/game-files.js';

const PAGE = 16;
const img = Uint8Array.from({ length: 200 }, (_, k) => (k * 7 + 3) & 0xff);       // 12.5 pages
const ini = new TextEncoder().encode('[A]\r\nb=1\r\n');
const dat = Uint8Array.from({ length: 40 }, (_, k) => k);
const manifest = { base: 'data/', page: PAGE, ranged: ['big.img'], files: [['big.img', img.length], ['a.ini', ini.length], ['one.dat', dat.length], ['two.dat', dat.length]] };
const preload = { version: 1, page: PAGE, files: { common: ['one.dat'], country: { 1: ['two.dat'] } }, ranges: { 'big.img': { common: [[0, 2]], country: { 1: [[10, 3]] }, race: { '0.0.0': [[5, 1]] } } } };
const bytesOf = { 'big.img': img, 'a.ini': ini, 'one.dat': dat, 'two.dat': dat };

function server({ ignoreRange = false } = {}) {
  const log = [];
  const answer = (name, range) => {
    const all = bytesOf[name];
    if (range && !ignoreRange) { const [, a, b] = /bytes=(\d+)-(\d+)/.exec(range); log.push(`${name} ${a}-${b}`); return { status: 206, body: all.slice(Number(a), Number(b) + 1) }; }
    log.push(name);
    return { status: 200, body: all.slice() };
  };
  globalThis.fetch = async (url, init) => { const r = answer(url, init && init.headers && init.headers.Range); return { status: r.status, ok: true, statusText: '', arrayBuffer: async () => r.body.buffer }; };
  globalThis.XMLHttpRequest = class { open(m, url) { this.url = url; } setRequestHeader(k, v) { this.range = v; } send() { const r = answer(this.url, this.range); this.status = r.status; this.response = r.body.buffer; } };
  return log;
}

test('a race fetches its lists: the INI files, its files whole, its archive pages in runs (neighbours together)', async () => {
  const log = server();
  const files = new GameFiles((n) => n, manifest, preload);
  const plan = files.plan({ country: 0, raceType: 0, character: 0 });
  assert.deepEqual([...plan.files].sort(), ['a.ini', 'one.dat']);
  assert.deepEqual(plan.runs.get('big.img'), [[0, 2], [5, 1]]);
  const r = await files.prepare({ country: 0, raceType: 0, character: 0 });
  // pages 0-1 and 5 are less than GAP (4) pages apart: one request for pages 0..5
  assert.deepEqual(log.sort(), ['a.ini', 'big.img 0-95', 'one.dat']);
  assert.equal(r.requests, 3);
  assert.equal(r.fetched, ini.length + dat.length + 96);
  const again = await files.prepare({ country: 0, raceType: 0, character: 0 });
  assert.equal(again.fetched, 0);
  assert.equal(again.cached, ini.length + dat.length + 3 * PAGE);
});

test('the Vfs reads the archive across pages; a page nobody listed is fetched while the game waits, 8 pages on', async () => {
  const log = server();
  const files = new GameFiles((n) => n, manifest, preload);
  await files.prepare({ country: 0 });
  log.length = 0;
  const vfs = files.vfs();
  const read = vfs.ranged('big.img');
  assert.equal(typeof read, 'function');
  const out = new Uint8Array(40);
  read(10, 20, out, 0);                                    // pages 0 and 1: kept
  assert.deepEqual([...out.subarray(0, 20)], [...img.subarray(10, 30)]);
  assert.deepEqual(log, []);
  read(150, 30, out, 5);                                   // page 9 on: missing, fetched with the pages after it (to the end)
  assert.deepEqual([...out.subarray(5, 35)], [...img.subarray(150, 180)]);
  assert.deepEqual(log, ['big.img 144-199']);
  assert.equal(files.stats().waits, 1);
  // a whole file not in the lists: fetched on first read
  assert.deepEqual([...vfs.read('two.dat')], [...dat]);
  assert.equal(files.stats().waits, 2);
});

test('a server that ignores Range: the whole archive comes once and is kept, the other runs are not asked for', async () => {
  const log = server({ ignoreRange: true });
  const files = new GameFiles((n) => n, manifest, preload);
  await files.prepare({ country: 1 });
  const vfs = files.vfs();
  const out = new Uint8Array(200);
  vfs.ranged('big.img')(0, 200, out, 0);
  assert.deepEqual([...out], [...img]);
  assert.equal(log.filter((x) => x === 'big.img').length, 1);   // the first run answered whole; the second not asked for
  assert.equal(files.stats().waits, 0);
});

test('without lists every first read is fetched when it is read', async () => {
  const log = server();
  const files = new GameFiles((n) => n, manifest, null);
  const r = await files.prepare({});
  assert.deepEqual(log, ['a.ini']);                        // the INI files always
  assert.equal(r.requests, 1);
  const vfs = files.vfs();
  const out = new Uint8Array(4);
  vfs.ranged('big.img')(0, 4, out, 0);
  assert.deepEqual([...out], [...img.subarray(0, 4)]);
  assert.equal(log.at(-1), 'big.img 0-127');
});
