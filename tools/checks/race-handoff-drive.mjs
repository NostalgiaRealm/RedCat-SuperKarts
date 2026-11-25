#!/usr/bin/env node
// A driven finish through the handoff: writeHandoff for a menu race, a test bot (not original behaviour) drives all the
// laps, the race's own finish screen times out and the race exits; then readResult on race.ini's text against the JS
// port's nativeRaceResultPatch of the race's exit writes, and the patch through the JS port's applyRaceResult into a
// save that the next race's handoff reads (records kept or beaten, grid position).
//   node tools/checks/race-handoff-drive.mjs [--country 0] [--character 0] [--race 0] [--difficulty 1] [--budget 40000]
//     [--record-ms N] (a saved lap record for the etappe) [--name drive-...] [--out evidence/checks/race-handoff]
// Output: <name>.json, <name>.race-exit.ini (tests/race-handoff.test.mjs reads them), a block in drive-summary.txt.
// Runs kept as evidence (2026-11-25): --country 1 (finish, new records), --country 1 --record-ms 60000 (lap record
// kept, race record beaten), --country 1 --race 3 (duel), --country 0 --race 1 (Tijdrace out of time: game over).
// The bot is full-race-gaps.mjs's 'full-race-bot' (throttle to ~140 km/h, steer toward route chunk sector+4) with a
// stronger way out when it is stuck: it reverses longer and aims further to the side each time it is stuck at the
// same place. On the game-over screen (phase 6, a Tijdrace out of time; it waits for a key without a time-out) it
// presses Enter after 2 s, so that path ends with finished=0.
import { writeFileSync, mkdirSync, readFileSync, existsSync } from 'node:fs';
import { join } from 'node:path';
import { makeRace, VK } from './full-race-gaps-lib.mjs';
import { writeHandoff, readResult } from '../../source/host/race-handoff.js';
import { ROOT, expectedPatch, defaultSettings, text, jsModule } from './race-handoff-lib.mjs';

const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const OUT = join(ROOT, opt('out', 'evidence/checks/race-handoff'));
mkdirSync(OUT, { recursive: true });
const config = { country: Number(opt('country', 0)), character: Number(opt('character', 0)), raceType: Number(opt('race', 0)), difficulty: Number(opt('difficulty', 1)) };
const BUDGET = Number(opt('budget', 40000));
const recordMs = opt('record-ms', null);
const NAME = opt('name', `drive-c${config.country}-p${config.character}-r${config.raceType}-d${config.difficulty}${recordMs ? '-record' + recordMs : ''}`);
const settings = await defaultSettings();
const save = { bestTimes: recordMs ? { [`lap_record_e${config.country}`]: Number(recordMs), [`race_record_e${config.country}`]: Number(opt('race-record-ms', 99999999)) } : {} };

const r = await makeRace({ etappe: config.country, car: config.character, limit: 400000 });
const handoff = writeHandoff(r.vfs, config, save, settings);
r.race.boot();
let n = 0;
while (r.state().phase !== 0 && n < 3000) { r.tick(); n++; }
const greenTick = r.ctl.tick;

const N = r.route.maxChunk();
let hist = [], reverse = 0, offset = 0, offTicks = 0, side = 1, stucks = 0, lastLap = 0;
let gameOver = 0;
const stuckAt = new Map();                       // route sector -> times stuck there
const laps = [], sample = [], changes = [];
let last = r.state();
const t0 = performance.now();
let ended = false, ticks = 0;
for (; ticks < BUDGET; ticks++) {
  const s = r.state();
  if (s.laps !== lastLap) { laps.push({ lap: s.laps, tick: r.ctl.tick, virtualMs: s.virtualMs, position: s.position, fastestLap: s.fastestLap, stucks }); lastLap = s.laps; }
  let keys = [];
  if (s.phase === 6) { gameOver++; if (gameOver > 80 && gameOver < 90) keys = [VK.RETURN]; }
  if (s.phase === 0 || s.phase === 8) {
    const p = r.player();
    const c = ((p.sector + 4) % N + N) % N;
    const t = r.route.pos(c);
    const w = r.u32(0x680b28) + r.route.waypoint(c) * 0x984;
    if (offTicks > 0) { offTicks--; t[0] += -r.f32(w + 0x50) * offset; t[2] += r.f32(w + 0x48) * offset; }
    const dx = t[0] - p.x, dz = t[2] - p.z;
    const fx = p.mat[8], fz = p.mat[10];
    const ang = Math.atan2(fx * dz - fz * dx, fx * dx + fz * dz);   // > 0: the target is to the left
    hist.push([p.x, p.z]);
    if (hist.length > 60) hist.shift();
    const moved = hist.length === 60 ? Math.hypot(hist[59][0] - hist[0][0], hist[59][1] - hist[0][1]) : 999;
    if (reverse === 0 && moved < 15) {
      const k = (stuckAt.get(p.sector) || 0) + 1;
      stuckAt.set(p.sector, k);
      stucks++; hist = []; side = -side;
      reverse = 45 + 15 * Math.min(k, 8);
      offset = (45 + 20 * Math.min(k, 6)) * side;
      offTicks = 0;
    }
    if (ticks % 400 === 0) sample.push({ tick: r.ctl.tick, sector: p.sector, laps: s.laps, kmh: s.kmh, pos: s.position, x: s.x, z: s.z, ang: +ang.toFixed(2) });
    if (reverse > 0) {
      reverse--;
      if (reverse === 0) offTicks = 160;
      keys = [VK.DOWN, ang > 0 ? VK.RIGHT : VK.LEFT];
    } else {
      const want = Math.abs(ang) > 0.5 ? 70 : 140;
      if (s.kmh < want) keys.push(VK.UP);
      else if (s.kmh > want + 40) keys.push(VK.DOWN);
      if (ang > 0.05) keys.push(VK.LEFT);
      else if (ang < -0.05) keys.push(VK.RIGHT);
    }
  }
  r.ctl.keys = new Set(keys);
  if (!r.tick()) { ended = true; changes.push({ tick: r.ctl.tick, ended: true, exitCode: r.race.exitCode }); break; }
  const s2 = r.state();
  if (s2.phase !== last.phase || s2.laps !== last.laps || s2.finished !== last.finished) changes.push({ tick: r.ctl.tick, phase: s2.phase, laps: s2.laps, finished: s2.finished, virtualMs: s2.virtualMs });
  last = s2;
}
const wallMs = Math.round(performance.now() - t0);
const exitWrites = r.iniWrites.filter((w) => w.tick > greenTick).map(({ tick, file, section, key, value }) => [tick, file.split('\\').pop(), section, key, value]);
const raceIniText = text(r.vfs.read('race.ini'));
const result = readResult(raceIniText);
const expected = await expectedPatch(exitWrites.map(([, ...w]) => w));
// the JS port's menu side: applyRaceResult into a save, and that save into the next race's handoff
const { readRaceSave, applyRaceResult } = await jsModule('race-save.js');
const store = new Map();
const jsSave = readRaceSave({ getItem: (k) => store.get(k) ?? null, setItem: (k, v) => store.set(k, v) });
Object.assign(jsSave.bestTimes, save.bestTimes);
applyRaceResult(jsSave, result.patch);
const next = await makeRace({ etappe: config.country, car: config.character });
const nextHandoff = writeHandoff(next.vfs, config, jsSave, settings);

const out = {
  bot: 'test driver, not original behaviour', config, save, handoff, greenTick, routeChunks: N, laps, stucks,
  stuckSectors: Object.fromEntries([...stuckAt].sort((a, b) => b[1] - a[1]).slice(0, 10)), ended, exitCode: r.race.exitCode,
  ticksAfterGreen: ticks, wallMs, changes, exitWrites, iniWritesAtExit: exitWrites.map(([, ...w]) => w), result, expected,
  resultMatchesJsPatch: JSON.stringify(result.patch) === JSON.stringify(expected),
  jsSaveAfter: { bestTimes: jsSave.bestTimes, playerPosition: jsSave.playerPosition },
  nextHandoff: { position: nextHandoff.position, records: nextHandoff.records },
  sample, messages: r.messages.slice(-5),
};
writeFileSync(join(OUT, NAME + '.json'), JSON.stringify(out, null, 1) + '\n');
writeFileSync(join(OUT, NAME + '.race-exit.ini'), raceIniText);
const line = `${NAME}: ended ${ended} exit ${r.race.exitCode} after ${ticks} ticks (${(wallMs / 1000).toFixed(1)} s), stucks ${stucks}; laps ${JSON.stringify(laps.map((l) => [l.lap, l.virtualMs, l.fastestLap]))}\n` +
  `  exit writes: ${exitWrites.map(([, , s, k, v]) => `${s}.${k}=${v}`).join('; ')}\n` +
  `  readResult ${JSON.stringify(result)} = JS patch: ${out.resultMatchesJsPatch}\n` +
  `  JS save after applyRaceResult: ${JSON.stringify(out.jsSaveAfter)}; next handoff: ${JSON.stringify(out.nextHandoff)}`;
console.log(line);
// drive-summary.txt keeps one block per run name (this run's replaces an older one)
const sumPath = join(OUT, 'drive-summary.txt');
const blocks = (existsSync(sumPath) ? readFileSync(sumPath, 'utf8') : '').split(/\n(?=\S)/).filter((b) => b.trim() && !b.startsWith(NAME + ':'));
writeFileSync(sumPath, [...blocks.map((b) => b.trimEnd()), line].sort().join('\n') + '\n');
process.exitCode = ended && out.resultMatchesJsPatch ? 0 : 1;
