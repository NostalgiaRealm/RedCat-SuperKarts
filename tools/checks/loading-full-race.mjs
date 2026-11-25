#!/usr/bin/env node
// What a whole race reads that its preload lists (public/game/preload.json) do not name: the reads the browser's game
// thread would wait for. The lists are measured on short races (tools/build-preload.mjs: boot, countdown, 400 passes,
// the finish cheat); this drives whole races in Node with the test bot of race-handoff-drive.mjs (not original
// behaviour: throttle to ~140 km/h, steer toward route chunk sector+4, reverse out when stuck) and runs the browser's
// file code itself (source/web/game-files.js: prepare() for the race's lists, then its Vfs), with its requests answered
// from the files on disk and counted. A wait is one synchronous request (a missing file, or the missing archive pages
// from the read on, 128 KB at least).
//   node tools/checks/loading-full-race.mjs [--races 0.0.0,1.0.0,...] [--budget 30000] [--out evidence/loading/full-races.json]
import { readFileSync, writeFileSync, openSync, readSync, mkdirSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { makeRace, VK } from './full-race-gaps-lib.mjs';
import { GameFiles } from '../../source/web/game-files.js';
import { ROOT, raceFiles } from '../game-data.mjs';

const opt = (name, def) => { const k = process.argv.indexOf('--' + name); return k < 0 ? def : process.argv[k + 1]; };
const RACES = opt('races', '0.0.0,1.0.1,2.0.2,3.0.3,4.0.0,5.0.1,2.2.0,4.3.2').split(',');
const BUDGET = Number(opt('budget', 30000));
const OUT = join(ROOT, opt('out', 'evidence/loading/full-races.json'));
const manifest = JSON.parse(readFileSync(join(ROOT, 'public/game/files.json'), 'utf8'));
const preload = JSON.parse(readFileSync(join(ROOT, 'public/game/preload.json'), 'utf8'));
const from = new Map(raceFiles().files.map((f) => [f.name, f.from]));
const readDisk = (f, range) => {
  if (!range) return new Uint8Array(readFileSync(from.get(f.name)));
  const b = new Uint8Array(range[1] - range[0]);
  const fd = openSync(from.get(f.name), 'r');
  readSync(fd, b, 0, b.length, range[0]);
  return b;
};

const results = [];
for (const name of RACES) {
  const [country, raceType, character] = name.split('.').map(Number);
  const config = { country, raceType, character, difficulty: 1 };
  const files = new GameFiles((n) => n, manifest, preload);
  const waits = [];
  let tick = -1;
  files.get = async (f, range) => readDisk(f, range);
  files.getSync = (f, range) => { waits.push({ tick, file: f.name, at: range ? range[0] : null, bytes: range ? range[1] - range[0] : f.size }); return { bytes: readDisk(f, range), whole: !range }; };
  const before = await files.prepare(config);
  const r = await makeRace({ etappe: country, car: character, limit: 400000, ini: [] });
  // the race's own handoff (makeRace: pinRace) stays in the INI files; every other file is the browser's
  const vfs = files.vfs();
  for (const [k, v] of vfs.files) if (!/\.ini$/.test(k)) r.vfs.files.set(k, v);
  const { writeHandoff } = await import('../../source/host/race-handoff.js');
  writeHandoff(r.vfs, config, null, null);
  r.race.boot();
  tick = 0;
  let n = 0;
  r.ctl.keys = new Set([VK.UP]);
  while (r.state().phase !== 0 && n < 3000) { r.tick(); tick++; n++; }
  const N = r.route.maxChunk();
  let hist = [], reverse = 0, offset = 0, offTicks = 0, side = 1, gameOver = 0, ended = false, laps = 0;
  const stuckAt = new Map();
  const t0 = performance.now();
  for (let ticks = 0; ticks < BUDGET; ticks++) {
    const s = r.state();
    laps = Math.max(laps, s.laps);
    let keys = [];
    if (s.phase === 6) { gameOver++; if (gameOver > 80 && gameOver < 90) keys = [VK.RETURN]; }
    if (s.phase === 0 || s.phase === 8) {
      const p = r.player();
      const c = ((p.sector + 4) % N + N) % N;
      const t = r.route.pos(c);
      const w = r.u32(0x680b28) + r.route.waypoint(c) * 0x984;
      if (offTicks > 0) { offTicks--; t[0] += -r.f32(w + 0x50) * offset; t[2] += r.f32(w + 0x48) * offset; }
      const dx = t[0] - p.x, dz = t[2] - p.z;
      const ang = Math.atan2(p.mat[8] * dz - p.mat[10] * dx, p.mat[8] * dx + p.mat[10] * dz);
      hist.push([p.x, p.z]);
      if (hist.length > 60) hist.shift();
      const moved = hist.length === 60 ? Math.hypot(hist[59][0] - hist[0][0], hist[59][1] - hist[0][1]) : 999;
      if (reverse === 0 && moved < 15) {
        const k = (stuckAt.get(p.sector) || 0) + 1;
        stuckAt.set(p.sector, k);
        hist = []; side = -side;
        reverse = 45 + 15 * Math.min(k, 8);
        offset = (45 + 20 * Math.min(k, 6)) * side;
        offTicks = 0;
      }
      if (reverse > 0) { reverse--; if (reverse === 0) offTicks = 160; keys = [VK.DOWN, ang > 0 ? VK.RIGHT : VK.LEFT]; }
      else {
        const want = Math.abs(ang) > 0.5 ? 70 : 140;
        if (s.kmh < want) keys.push(VK.UP); else if (s.kmh > want + 40) keys.push(VK.DOWN);
        if (ang > 0.05) keys.push(VK.LEFT); else if (ang < -0.05) keys.push(VK.RIGHT);
      }
    }
    r.ctl.keys = new Set(keys);
    tick++;
    if (!r.tick()) { ended = true; break; }
  }
  const out = { race: name, config, preload: before, passes: tick, ended, exitCode: r.race.exitCode, laps, finished: r.state().finished, wallMs: Math.round(performance.now() - t0),
    waits: waits.length, waitKb: Math.round(waits.reduce((s, w) => s + w.bytes, 0) / 1024), list: waits };
  results.push(out);
  console.log(`${name}: ${out.passes} passes, laps ${laps}, ${ended ? 'exit ' + out.exitCode : 'did not end'}; fetched before the start ${(before.fetched / 1048576).toFixed(1)} MB in ${before.requests} requests; the game would wait ${out.waits} times (${out.waitKb} KB): ${waits.slice(0, 6).map((w) => `${w.tick}:${w.file}${w.at !== null ? '@' + w.at : ''}`).join(' ')}`);
}
mkdirSync(dirname(OUT), { recursive: true });
writeFileSync(OUT, JSON.stringify({ built: new Date().toISOString(), bot: 'test driver, not original behaviour', budget: BUDGET, results }, null, 1) + '\n');
console.log('-> ' + OUT);
