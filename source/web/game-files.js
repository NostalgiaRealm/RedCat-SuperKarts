// The game's files in the game worker (source/web/worker.js): what a race reads, fetched before it starts and kept for
// the races after it.
//
// Two lists come with the recompiled module (game/, tools/build-manifest.mjs and tools/build-preload.mjs):
//   files.json    { base, page, files: [[name, size], ...], ranged: [names] }: every file the race may read, under data/
//   preload.json  per race (country, race type, character) the files and the pieces of the packed archives it read when
//                 it was run in Node from boot to its exit (common to all, per country, race type, character and race)
// The packed archives (rcs.img, 180 MB, rc.img; their indexes rcs.ind and rc.ind are ordinary files) are never fetched
// whole: they are read by byte ranges (HTTP Range) in pages of `page` bytes (16 KB), and a page once fetched is kept.
// Before a race the worker fetches what its lists name and it does not have yet: the files whole, the archives' pages
// in runs (one request per run, neighbouring runs less than 64 KB apart taken together), six requests at a time, each
// asked again twice when it fails (a refused or broken answer: a network blip, a 503). The INI files (35, 100 KB) come
// along always: an INI read nobody foresaw would make the game wait. Anything else the race reads is fetched when it is
// read, with the game thread waiting (a worker may make synchronous requests): a whole file, or the missing pages from
// the one read on, 128 KB at least (the race reads 512 bytes and 4 KB at a time, onward; most sounds fit), and kept. The number of these
// waits, their bytes and time are in stats() (the worker's 'stats' message: files).
//
// What a server must do for this: answer a Range request with 206 and exactly those bytes. One that answers 200 with the
// whole file still works (the whole archive is then kept, as before 2026-11-25). It must not send a .gz copy for a Range
// request (nginx gzip_static would answer one with bytes of the .gz): tools/package.mjs makes no .gz of the archives.
import { Vfs } from '../host/vfs.js';

const PARALLEL = 6;
const GAP = 4;                 // pages: runs closer than this are fetched in one request (64 KB of 16 KB pages)
const READ_AHEAD = 8;          // pages fetched at least on a read nobody foresaw (128 KB: most sound members whole)
const TRIES = 3;
const INI = /\.ini$/i;

const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

export class GameFiles {
  /** url(name): the address of a game file (data/ + name, relative to the page's folder). */
  constructor(url, manifest, preload) {
    this.url = url;
    this.page = manifest.page || 16384;
    this.list = manifest.files.map(([name, size]) => ({ name, size, key: name.toLowerCase(), ranged: (manifest.ranged || []).some((r) => r.toLowerCase() === name.toLowerCase()) }));
    this.byKey = new Map(this.list.map((f) => [f.key, f]));
    this.preload = preload && preload.version === 1 ? preload : null;
    this.whole = new Map();        // key -> Uint8Array: files kept whole
    this.pages = new Map();        // key -> Map(page -> Uint8Array): the archives' pages kept
    this.demand = { requests: 0, bytes: 0, ms: 0, last: [] };     // reads nobody foresaw (the game thread waited)
    this.fetched = { requests: 0, bytes: 0 };
    this.complete = new Set();     // keys of archives a server sent whole (it ignored Range): every page is kept
  }

  pagesOf(key) {
    let m = this.pages.get(key);
    if (!m) this.pages.set(key, (m = new Map()));
    return m;
  }

  /** What a race reads by the lists: { files: Set(key), runs: Map(key -> [[first page, count]]) }. */
  plan({ country = 0, raceType = 0, character = 0 } = {}) {
    const files = new Set(this.list.filter((f) => INI.test(f.name)).map((f) => f.key));
    const runs = new Map();
    const p = this.preload;
    if (!p) return { files, runs };
    const pick = (g) => [g.common, g.country && g.country[country], g.raceType && g.raceType[raceType], g.character && g.character[character], g.race && g.race[`${country}.${raceType}.${character}`]].filter(Boolean);
    for (const list of pick(p.files || {})) for (const n of list) if (this.byKey.has(n.toLowerCase())) files.add(n.toLowerCase());
    for (const [name, groups] of Object.entries(p.ranges || {})) {
      const key = name.toLowerCase();
      if (!this.byKey.has(key)) continue;
      runs.set(key, pick(groups).flat());
    }
    return { files, runs };
  }

  /**
   * Fetches what the race's lists name and is not kept yet. onProgress(percent). Returns { fetched, cached, requests }
   * (bytes of this race's lists that were fetched now and that were kept from an earlier race).
   */
  async prepare(config, onProgress = () => {}) {
    const { files, runs } = this.plan(config);
    const jobs = [];               // { bytes, go() }
    let cached = 0;
    for (const key of files) {
      const f = this.byKey.get(key);
      if (!f || f.ranged) continue;
      if (this.whole.has(key)) { cached += f.size; continue; }
      jobs.push({ bytes: f.size, go: async () => { const b = await this.get(f, null); this.whole.set(key, b); return b.length; } });
    }
    for (const [key, list] of runs) {
      const f = this.byKey.get(key), kept = this.pagesOf(key);
      const last = Math.ceil(f.size / this.page) - 1;
      const want = [];
      for (const [first, count] of list) for (let p = first; p < first + count && p <= last; p++) { if (kept.has(p)) cached += this.pageBytes(f, p); else want.push(p); }
      want.sort((a, b) => a - b);
      // missing pages in runs, neighbours closer than GAP pages in one request (the pages between come along)
      let k = 0;
      while (k < want.length) {
        let end = want[k];
        let j = k + 1;
        while (j < want.length && want[j] - end <= GAP) end = want[j++];
        const a = want[k], b = end;
        jobs.push({ bytes: (b - a + 1) * this.page, key, go: () => (this.complete.has(key) ? 0 : this.fillPages(f, a, b)) });
        k = j;
      }
    }
    const total = jobs.reduce((s, j) => s + j.bytes, 0);
    let done = 0, fetched = 0, lastPct = -1;
    onProgress(jobs.length ? 0 : 100);
    // each archive's first request alone before the rest: a server that ignores Range answers it with the whole file
    // (then kept, and the archive's other requests are skipped) instead of answering six of them with 180 MB each
    const first = new Set(), order = [];
    for (const j of jobs) if (j.key && !first.has(j.key)) { first.add(j.key); order.push(j); }
    const rest = jobs.filter((j) => !order.includes(j));
    let next = 0;
    const run = async (list) => {
      while (next < list.length) {
        const job = list[next++];
        const n = await job.go();          // (not `fetched += await …`: that adds to the value read before the await)
        fetched += n;
        done += job.bytes;
        const pct = Math.floor(done * 100 / Math.max(1, total));
        if (pct !== lastPct) { lastPct = pct; onProgress(pct); }
      }
    };
    for (const list of [order.concat(jobs.filter((j) => !j.key)), rest.filter((j) => j.key)]) {
      next = 0;
      await Promise.all(Array.from({ length: Math.min(PARALLEL, list.length) }, () => run(list)));
    }
    return { fetched, cached, requests: jobs.length };
  }

  pageBytes(f, p) { return Math.min(this.page, f.size - p * this.page); }

  /** Fetches pages a..b of an archive (async) and keeps them; returns the bytes that came. */
  async fillPages(f, a, b) {
    const start = a * this.page, end = Math.min(f.size, (b + 1) * this.page);
    const bytes = await this.get(f, [start, end]);
    const whole = bytes.length === f.size && end - start !== f.size;
    if (whole) this.complete.add(f.key);
    this.keep(f, bytes, whole ? 0 : start);
    return bytes.length;
  }

  /** Puts fetched bytes that start at `start` into the archive's pages (a whole file when a server ignored the range). */
  keep(f, bytes, start) {
    const kept = this.pagesOf(f.key);
    for (let at = 0; at < bytes.length; at += this.page) {
      const p = (start + at) / this.page;
      if (!kept.has(p)) kept.set(p, bytes.subarray(at, Math.min(bytes.length, at + this.page)));
    }
  }

  /**
   * One request, asked again when it fails: a file whole (range null) or bytes [start, end). A server that ignores the
   * range answers 200 with the whole file: that is returned (the caller keeps all of it).
   */
  async get(f, range) {
    let error = null;
    for (let t = 0; t < TRIES; t++) {
      if (t) await sleep(t * 500);
      try {
        const r = await fetch(this.url(f.name), range ? { headers: { Range: `bytes=${range[0]}-${range[1] - 1}` } } : undefined);
        if (range && r.status === 206) {
          const b = new Uint8Array(await r.arrayBuffer());
          if (b.length !== range[1] - range[0]) throw new Error(`${f.name}: ${b.length} bytes for a range of ${range[1] - range[0]}`);
          this.fetched.requests++; this.fetched.bytes += b.length;
          return b;
        }
        if (r.status === 200) { const b = new Uint8Array(await r.arrayBuffer()); this.fetched.requests++; this.fetched.bytes += b.length; return b; }
        error = new Error(`${f.name}: ${r.status} ${r.statusText}`);
        if (r.status === 404) break;
      } catch (e) { error = e; }
    }
    throw error;
  }

  /** The same synchronously, for a read during the race (the game thread waits; a worker may do this). */
  getSync(f, range) {
    const t0 = performance.now();
    for (let t = 0; t < TRIES; t++) {
      try {
        const x = new XMLHttpRequest();
        x.open('GET', this.url(f.name), false);
        x.responseType = 'arraybuffer';
        if (range) x.setRequestHeader('Range', `bytes=${range[0]}-${range[1] - 1}`);
        x.send();
        if (x.status === 206 || x.status === 200) {
          const b = new Uint8Array(x.response);
          this.demand.requests++; this.demand.bytes += b.length; this.demand.ms += performance.now() - t0;
          this.demand.last = [...this.demand.last.slice(-7), range ? `${f.name}@${range[0]}+${range[1] - range[0]}` : f.name];
          return { bytes: b, whole: x.status === 200 };
        }
        if (x.status === 404) return null;
      } catch (e) { /* asked again */ }
    }
    return null;
  }

  /** A fresh Vfs over what is kept; what is not is fetched when the race reads it. */
  vfs() {
    const vfs = new Vfs();
    for (const f of this.list) {
      if (f.ranged) {
        const kept = this.pagesOf(f.key), page = this.page, last = Math.ceil(f.size / page) - 1;
        // the missing page p and the missing ones after it, READ_AHEAD at least (fewer where a kept page comes first)
        const fill = (p) => {
          let b = p;
          while (b < last && b - p + 1 < READ_AHEAD && !kept.has(b + 1)) b++;
          const r = this.getSync(f, [p * page, Math.min(f.size, (b + 1) * page)]);
          if (!r) throw new Error(`${f.name}: bytes ${p * page}.. could not be fetched`);
          if (r.whole) this.complete.add(f.key);
          this.keep(f, r.bytes, r.whole ? 0 : p * page);
        };
        vfs.addRanged(f.name, f.size, (pos, n, u8, dst) => {
          while (n > 0) {
            const p = Math.floor(pos / page), off = pos - p * page;
            if (!kept.has(p)) fill(p);
            const src = kept.get(p);
            const k = Math.min(n, src.length - off);
            u8.set(src.subarray(off, off + k), dst);
            pos += k; dst += k; n -= k;
          }
        });
      } else if (this.whole.has(f.key)) {
        // the race never writes into these: WriteFile works on a copy and INI changes make new bytes (win32.js, vfs.js)
        vfs.add(f.name, this.whole.get(f.key));
      } else {
        vfs.addLazy(f.name, f.size, () => {
          const r = this.getSync(f, null);
          if (r) this.whole.set(f.key, r.bytes);
          return r ? r.bytes : null;
        });
      }
    }
    return vfs;
  }

  /** For the worker's stats: the reads the game thread waited for, and everything fetched so far. */
  stats() {
    let pages = 0;
    for (const m of this.pages.values()) pages += m.size;
    let whole = 0;
    for (const b of this.whole.values()) whole += b.length;
    return { waits: this.demand.requests, waitBytes: this.demand.bytes, waitMs: Math.round(this.demand.ms), lastWaits: this.demand.last,
      requests: this.fetched.requests + this.demand.requests, bytes: this.fetched.bytes + this.demand.bytes, keptMb: +((whole + pages * this.page) / 1048576).toFixed(1) };
  }
}
