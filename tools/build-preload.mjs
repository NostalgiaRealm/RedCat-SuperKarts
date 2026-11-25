#!/usr/bin/env node
// Measures which game files and which pieces of the packed archives (rcs.img, rc.img) a race reads, for every
// country, race type and character, and writes the lists the browser fetches before a race starts into
// public/game/preload.json (source/web/game-files.js). Without the lists a race still runs: every first read of a file
// or of a piece of an archive is then fetched while the game thread waits.
//
// How (measured, not inferred): each race is run in Node (the host of tools/run-headless.mjs, the files of
// tools/game-data.mjs, the menu's handoff with default settings, difficulty Normaal) from boot through the start
// camera, the countdown and 400 passes with the throttle held, then the cheat Ctrl+F+I and the finish screen until the
// race exits (a game-over screen gets Enter), recording every file opened and every byte range read. 6 countries x 4
// race types (Landenrace, Tijdrace, Sterrenrace, duel) x 4 characters = 96 races, a few seconds each, in parallel.
// What a whole race reads later (voices and sounds the game loads when it first plays them: an overtake, a bump, the
// last lap) is not in a run this short; the browser fetches such a piece when it is read (one request, 128 KB at
// least) and keeps it. --check-difficulty also runs every country at Makkelijk and Moeilijk and reports what they
// read beyond the lists.
//
// preload.json: { version, page (bytes), files: { common, country: {c}, raceType: {r}, character: {p}, race: {"c.r.p"} },
//   ranges: { <archive>: same groups, each a list of [first page, count] } }. A race fetches the union of common, its
// country's, race type's, character's and its own race's entries; each group holds only what every race of it read.
//   node tools/build-preload.mjs [--parallel 8] [--ticks 400] [--check-difficulty] [--only c.r.p,...]
import { Worker, isMainThread, parentPort, workerData } from 'node:worker_threads';
import { readFileSync, writeFileSync, openSync, readSync, mkdirSync } from 'node:fs';
import { join } from 'node:path';
import { cpus } from 'node:os';
import { fileURLToPath } from 'node:url';
import { ROOT, raceFiles, RANGED, PAGE } from './game-data.mjs';

const COUNTRIES = 6, RACE_TYPES = 4, CHARACTERS = 4;

if (!isMainThread) {
  const { Vfs } = await import('../source/host/vfs.js');
  const { Race } = await import('../source/host/race.js');
  const { writeHandoff } = await import('../source/host/race-handoff.js');
  const { config, files, ticks } = workerData;
  const gameDir = join(ROOT, 'public/game');
  const meta = JSON.parse(readFileSync(join(gameDir, 'rcskspel.meta.json'), 'utf8'));
  const codeMap = new Uint8Array(readFileSync(join(gameDir, 'rcskspel.codemap.bin')));
  const vfs = new Vfs();
  const whole = new Set(), pages = {};
  let tick = -1;
  const firstTick = {};
  for (const f of files) {
    if (RANGED.test(f.name)) {
      const fd = openSync(f.from, 'r');
      const set = pages[f.name] = new Set();
      vfs.addRanged(f.name, f.size, (pos, n, u8, dst) => {
        for (let p = Math.floor(pos / PAGE); p <= Math.floor((pos + n - 1) / PAGE); p++) if (!set.has(p)) { set.add(p); firstTick[f.name + ':' + p] = tick; }
        readSync(fd, u8, dst, n, pos);
      });
    } else vfs.addLazy(f.name, f.size, () => new Uint8Array(readFileSync(f.from)));
  }
  vfs.onRead = (p) => whole.add(p);
  writeHandoff(vfs, config, null, null);
  const keys = new Set();
  // Ctrl+F+I is let go from inside the pass that took it: 0x429a90 waits there for all three to be released
  // (tools/checks/full-race-gaps.mjs finish-cheat-live); a pass that polls keys without end is reported, not waited for
  let cheatPolls = -1, polls = 0;
  const keyDown = (vk) => {
    if (++polls > 2e6) throw new Error('a pass polled the keyboard 2,000,000 times (a wait for a key that never comes)');
    if (cheatPolls >= 0 && vk === 0x11 && ++cheatPolls > 50) { keys.clear(); cheatPolls = -1; }
    return keys.has(vk);
  };
  const nop = () => {};
  const render = { freeTexture: nop, fillScreen: nop, blitToScreen: nop, loadTexture: nop, setBackground: nop, clear: nop, setViewport: nop,
    beginScene: nop, endScene: nop, setRenderState: nop, setLightState: nop, setTransform: nop, drawPrimitive: nop, drawIndexed: nop };
  const host = {
    vfs, render, audio: null, music: null, screen: { width: 640, height: 480, bits: 16 }, tickSeconds: 0.025, clockStart: 1, fixedDate: Date.UTC(2000, 3, 17, 12),
    input: { mouseX: 320, mouseY: 240, mouseButtons: 0, keyDown, takeMouseDelta: () => null, setMouse() {} },
    onFlip: nop, onMessageBox: nop, onStdout: nop, log: nop,
    driveInput: () => ({ throttle: keys.has(0x26) ? 1 : 0, brake: 0, handbrake: false }),
  };
  const race = new Race(meta, host);
  await race.instantiate(new WebAssembly.Module(readFileSync(join(gameDir, 'rcskspel.wasm'))), codeMap);
  const phase = () => race.m.u32[0x0053b9c0 >> 2];
  race.boot();
  tick = 0;
  keys.add(0x26);
  let n = 0, green = null, cheat = null, ended = false;
  const step = () => { polls = 0; const going = race.tick(); tick++; n++; return going; };
  try {
    while (n < 3000 && phase() !== 0) if (!step()) break;
    green = n;
    for (let k = 0; k < ticks && !race.ended; k++) if (!step()) break;
    keys.delete(0x26);
    // Ctrl+F+I (0x429a90's finish cheat; safeguards.js lets it through while host.cheats is not false)
    cheat = n;
    for (const vk of [0x11, 0x46, 0x49]) keys.add(vk);
    cheatPolls = 0;
    for (let k = 0; k < 6 && cheatPolls >= 0; k++) step();
    keys.clear(); cheatPolls = -1;
    for (let k = 0; k < 8000; k++) {
      // the game-over screen (phase 6) waits for Esc, Enter or Space
      if (phase() === 6 && k % 40 === 20) keys.add(0x0d); else keys.delete(0x0d);
      if (!step()) { ended = true; break; }
    }
  } catch (e) {
    parentPort.postMessage({ config, error: String(e && e.stack || e) });
    process.exit(0);
  }
  const later = {};
  for (const [k, t] of Object.entries(firstTick)) if (t > 0) { const [name, p] = k.split(':'); (later[name] ||= []).push([Number(p), t]); }
  parentPort.postMessage({ config, whole: [...whole].sort(), pages: Object.fromEntries(Object.entries(pages).map(([k, s]) => [k, [...s].sort((a, b) => a - b)])),
    later, ticks: n, green, cheat, ended, exitCode: race.exitCode, finished: /finished\s*=\s*1/i.test(new TextDecoder('latin1').decode(vfs.read('race.ini') || new Uint8Array())) });
  process.exit(0);
}

// --- main thread ---------------------------------------------------------------------------------------------------
const args = process.argv.slice(2);
const opt = (n, d) => { const k = args.indexOf('--' + n); return k >= 0 ? args[k + 1] : d; };
const has = (n) => args.includes('--' + n);
const PARALLEL = Number(opt('parallel', Math.max(1, Math.min(8, cpus().length >> 1))));
const TICKS = Number(opt('ticks', 400));
const { files } = raceFiles();
const size = new Map(files.map((f) => [f.name.toLowerCase(), f.size]));
const nameOf = new Map(files.map((f) => [f.name.toLowerCase(), f.name]));
const key = (c) => `${c.country}.${c.raceType}.${c.character}`;
let configs = [];
for (let country = 0; country < COUNTRIES; country++) for (let raceType = 0; raceType < RACE_TYPES; raceType++) for (let character = 0; character < CHARACTERS; character++) configs.push({ country, raceType, character, difficulty: 1 });
if (opt('only', null)) { const want = new Set(opt('only', '').split(',')); configs = configs.filter((c) => want.has(key(c))); }

const runOnce = (config, ticks) => new Promise((resolve) => {
  const w = new Worker(fileURLToPath(import.meta.url), { workerData: { config, files, ticks } });
  w.once('message', resolve);
  w.once('error', (e) => resolve({ config, error: String(e && e.stack || e) }));
  w.once('exit', (code) => resolve({ config, error: 'worker ended with code ' + code }));
});
// A race that fails is run again with the cheat 100 passes sooner. Seen once (2026-11-25): 0.3.3 (Nederland, duel, Max)
// with the cheat after 400 passes stops in 0x41fc60 (the route's waypoint position, from 0x420a70) with a memory access
// out of bounds; after 200, 300 or 600 passes it finishes. A test-bot position with the finish cheat, not a player's
// path (the cheat answers only with ?cheats); recorded in the summary (retried).
const retried = [];
const run = async (config) => {
  const r = await runOnce(config, TICKS);
  if (!r.error) return r;
  retried.push({ race: key(config), error: r.error.split('\n')[0] });
  return runOnce(config, Math.max(0, TICKS - 100));
};
const pool = async (items, n, fn) => { let k = 0; const out = []; await Promise.all(Array.from({ length: n }, async () => { while (k < items.length) { const i = k++; out[i] = await fn(items[i], i); } })); return out; };

const t0 = Date.now();
const results = await pool(configs, PARALLEL, async (c) => {
  const r = await run(c);
  if (r.error) console.log(`${key(c)}: FAILED ${r.error.split('\n').slice(0, 3).join(' | ')}`);
  else console.log(`${key(c)}: ${r.ticks} passes (green ${r.green}, cheat ${r.cheat}), ${r.ended ? 'exit ' + r.exitCode : 'did not end'}, finished=${r.finished ? 1 : 0}, ${r.whole.length} files, ${Object.entries(r.pages).map(([k, p]) => `${k} ${(p.length * PAGE / 1048576).toFixed(1)} MB`).join(', ')}`);
  return r;
});
const failed = results.filter((r) => r.error || !r.ended);
if (failed.length) { console.error(`${failed.length} race(s) failed or did not end: ${failed.map((r) => key(r.config)).join(' ')}`); process.exit(1); }

// --- factor the sets: what every race reads, then per country, race type and character, then per race --------------
const items = (r) => {
  const s = new Set();
  for (const n of r.whole) if (size.has(n) && !RANGED.test(n)) s.add('f:' + n);
  for (const [f, list] of Object.entries(r.pages)) for (const p of list) s.add('p:' + f.toLowerCase() + ':' + p);
  return s;
};
const sets = new Map(results.map((r) => [key(r.config), items(r)]));
const meet = (keys) => { let out = null; for (const k of keys) { const s = sets.get(k); out = out ? new Set([...out].filter((x) => s.has(x))) : new Set(s); } return out || new Set(); };
const all = [...sets.keys()];
const common = meet(all);
const groups = { common };
const dims = [['country', 0, COUNTRIES], ['raceType', 1, RACE_TYPES], ['character', 2, CHARACTERS]];
for (const [dim, at, count] of dims) {
  groups[dim] = {};
  for (let v = 0; v < count; v++) {
    const keys = all.filter((k) => Number(k.split('.')[at]) === v);
    if (keys.length) groups[dim][v] = new Set([...meet(keys)].filter((x) => !common.has(x)));
  }
}
groups.race = {};
for (const k of all) {
  const [c, r, p] = k.split('.').map(Number);
  const covered = new Set([...common, ...(groups.country[c] || []), ...(groups.raceType[r] || []), ...(groups.character[p] || [])]);
  groups.race[k] = new Set([...sets.get(k)].filter((x) => !covered.has(x)));
}
// one group as written: files (names as in files.json) and per archive [first page, count] runs
const runsOf = (list) => { const out = []; for (const p of list.sort((a, b) => a - b)) { const last = out[out.length - 1]; if (last && last[0] + last[1] === p) last[1]++; else out.push([p, 1]); } return out; };
const split = (set) => {
  const f = [], pages = {};
  for (const x of set) {
    if (x.startsWith('f:')) f.push(nameOf.get(x.slice(2)));
    else { const [, file, p] = x.split(':'); (pages[nameOf.get(file)] ||= []).push(Number(p)); }
  }
  return { files: f.sort(), ranges: Object.fromEntries(Object.entries(pages).map(([k, v]) => [k, runsOf(v)])) };
};
const out = { version: 1, page: PAGE, measured: { races: results.length, ticks: TICKS, difficulty: 1 }, files: {}, ranges: {} };
const put = (path, set) => {
  const { files: f, ranges } = split(set);
  const at = (obj) => { let o = obj; for (const k of path.slice(0, -1)) o = o[k] ||= {}; return o; };
  if (f.length) at(out.files)[path[path.length - 1]] = f;
  for (const [file, runs] of Object.entries(ranges)) { out.ranges[file] ||= {}; let o = out.ranges[file]; for (const k of path.slice(0, -1)) o = o[k] ||= {}; o[path[path.length - 1]] = runs; }
};
put(['common'], common);
for (const [dim] of dims) for (const [v, set] of Object.entries(groups[dim])) if (set.size) put([dim, v], set);
for (const [k, set] of Object.entries(groups.race)) if (set.size) put(['race', k], set);
writeFileSync(join(ROOT, 'public/game/preload.json'), JSON.stringify(out));

// --- what it means per race ----------------------------------------------------------------------------------------
const bytesOf = (set) => { let b = 0; for (const x of set) b += x.startsWith('f:') ? size.get(x.slice(2)) : PAGE; return b; };
const mb = (b) => (b / 1048576).toFixed(1);
const per = all.map((k) => bytesOf(sets.get(k)));
const second = [];          // a second race on another track after a first, any character and race type: what is new
for (const a of all) for (const b of all) if (a.split('.')[0] !== b.split('.')[0]) { const sa = sets.get(a); let n = 0; for (const x of sets.get(b)) if (!sa.has(x)) n += x.startsWith('f:') ? size.get(x.slice(2)) : PAGE; second.push(n); }
const laterPieces = results.reduce((s, r) => s + Object.values(r.later).reduce((t, l) => t + l.length, 0), 0) / results.length;
const summary = {
  built: new Date().toISOString(), races: results.length, seconds: Math.round((Date.now() - t0) / 1000),
  common: { files: split(common).files.length, archivePages: [...common].filter((x) => x.startsWith('p:')).length, mb: +mb(bytesOf(common)) },
  perRace: { minMb: +mb(Math.min(...per)), maxMb: +mb(Math.max(...per)), meanMb: +mb(per.reduce((s, b) => s + b, 0) / per.length) },
  secondRaceOtherTrack: { minMb: +mb(Math.min(...second)), maxMb: +mb(Math.max(...second)), meanMb: +mb(second.reduce((s, b) => s + b, 0) / second.length) },
  readAfterBoot: { meanPages: +laterPieces.toFixed(1), note: 'pieces first read after boot (countdown, race, finish): in the lists too' },
  json: { bytes: JSON.stringify(out).length },
  retried,
  races: Object.fromEntries(results.map((r) => [key(r.config), { mb: +mb(bytesOf(sets.get(key(r.config)))), passes: r.ticks, exit: r.exitCode, finished: r.finished }])),
};

if (has('check-difficulty')) {
  const extra = await pool([0, 2].flatMap((d) => Array.from({ length: COUNTRIES }, (_, c) => ({ country: c, raceType: 0, character: 0, difficulty: d }))), PARALLEL, run);
  summary.difficulty = extra.map((r) => {
    const base = sets.get(key(r.config)), got = r.error ? new Set() : items(r);
    const beyond = [...got].filter((x) => !base.has(x));
    return { country: r.config.country, difficulty: r.config.difficulty, error: r.error || null, beyondLists: beyond.length, beyondKb: Math.round(bytesOf(new Set(beyond)) / 1024) };
  });
  for (const d of summary.difficulty) console.log(`difficulty ${d.difficulty}, country ${d.country}: ${d.error ? 'FAILED' : `${d.beyondLists} pieces/files (${d.beyondKb} KB) beyond the lists of its Normaal race`}`);
}
mkdirSync(join(ROOT, 'evidence', 'loading'), { recursive: true });
writeFileSync(join(ROOT, 'evidence', 'loading', 'preload-summary.json'), JSON.stringify(summary, null, 1) + '\n');
console.log(`${retried.length ? `retried with the cheat sooner: ${retried.map((x) => x.race).join(' ')}\n` : ''}common: ${summary.common.files} files and ${summary.common.archivePages} archive pages, ${summary.common.mb} MB; a race: ${summary.perRace.minMb}-${summary.perRace.maxMb} MB (mean ${summary.perRace.meanMb}); a second race on another track adds ${summary.secondRaceOtherTrack.minMb}-${summary.secondRaceOtherTrack.maxMb} MB`);
console.log(`public/game/preload.json: ${(summary.json.bytes / 1024).toFixed(0)} KB, ${summary.seconds} s; evidence/loading/preload-summary.json`);
