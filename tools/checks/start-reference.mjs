#!/usr/bin/env node
// The same race start (Nederland, RedCat, Normaal, Landenrace, full throttle, no steering) in the SuperKarts
// JavaScript reimplementation, whose start sequence is backed by original-instruction fixtures
// (docs/research-countdown.md, research-startup.md, research-variable-update-timing.md there). Read-only: it imports
// that project's modules and assets and writes nothing.
//   node tools/checks/start-reference.mjs [--ticks 400] [--tick-ms 25] [--clock ideal|recomp] [--port DIR]
// --clock ideal : integer wall milliseconds n*tickMs and exact absolute seconds (the port's own NativeUpdateClock
//                 at a fixed 25 ms admission; NativeEngineTimer at the port's declared 60 s epoch).
// --clock recomp: the recomp's VirtualClock (source/host/win32.js): seconds = 1, seconds += dt in double per tick,
//                 GetTickCount = floor(seconds*1000), QPC = floor(seconds*1193182) at frequency 1193182.
import { readFileSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
const opt = (name, def) => {
  const k = process.argv.indexOf('--' + name);
  return k < 0 ? def : process.argv[k + 1];
};
const PORT = opt('port', join(ROOT, '..', 'RedCat Superkarts'));
const ticks = Number(opt('ticks', 400));
const tickMs = Number(opt('tick-ms', 25));
const clockMode = opt('clock', 'ideal');
const npcEvery = Number(opt('npc-every', 0));
const imp = (p) => import(pathToFileURL(join(PORT, p)).href);
const { RaceSimulation } = await imp('source/race-simulation.js');
const { NativeRandom } = await imp('source/simulation/native-random.js');
const { NativeEngineTimer, NATIVE_REFERENCE_UPTIME_MS } = await imp('source/simulation/clock.js');
const { NATIVE_PRECISION } = await imp('source/simulation/native-precision.js');
const read = (f) => readFileSync(join(PORT, 'public', 'assets', f));
const json = (f) => JSON.parse(read(f));

const track = 0, difficulty = 1, raceMode = 0, character = 0;
const random = new NativeRandom(956577600);       // CRT time() of the recomp's fixedDate 2000-04-17 12:00 UTC
const sim = new RaceSimulation({ config: json('config.json'), manifest: json('manifest.json'), cars: json('cars.json'),
  track: json(`tracks/etappe${track}.json`), physicsBytes: read(`physics/phys${difficulty}.dat`),
  racerBytes: read(`racer-tables/cars${difficulty}.dat`), random, character, difficulty, raceMode, countdown: true });

// Clocks. The recomp boots with VirtualClock at 1.000 s; 0x48f2c0 primes the engine timer there and 0x42f930 reseeds
// rand with GetTickCount (1000). The port's DrivingView uses a 60 s epoch and performance.now(); both are host choices.
let seconds = 1, timerEpoch;
const recomp = clockMode === 'recomp';
const QPC = 1193182;
let engine;
if (recomp) {
  engine = new NativeEngineTimer({ counter: Math.floor(seconds * QPC), frequency: QPC, precision: NATIVE_PRECISION });
  random.seed(1000);
} else {
  timerEpoch = NATIVE_REFERENCE_UPTIME_MS;
  engine = new NativeEngineTimer({ absoluteSeconds: timerEpoch / 1000, precision: NATIVE_PRECISION });
  random.seed(1000);
}
const input = { throttle: 1, brake: 0, steer: 0, handbrake: 0, bonus: 0 };
const fmt = (x, d = 4) => (Number.isFinite(x) ? x.toFixed(d) : String(x));
console.log(`# start-reference: SuperKarts JS port at ${PORT}`);
console.log(`# Nederland, RedCat, Normaal, Landenrace, countdown on, throttle held, steer 0; ${tickMs} ms updates, clock ${clockMode}, x87 precision ${NATIVE_PRECISION}`);
console.log(`# engine timer initial delta ${engine.initialDelta} (history [${engine.history.join(', ')}])`);
const b0 = sim.motion.body;
console.log(`# player start: pos ${b0.position.map((x) => fmt(x, 3)).join(' ')} sector ${b0.sector} yaw ${b0.yaw}`);
console.log(`# opponents: ${sim.opponents.map((a) => `${a.body.position.map((x) => x.toFixed(1)).join(' ')} s${a.body.sector}`).join(' | ')}`);
console.log(`# rand state after construction and the 1000 reseed: ${random.state.toString(16)}`);
console.log(`# start camera: durationTicks ${sim.startCamera?.durationTicks} (path ${sim.startCamera?.path.durationMs} ms incl. +1000)`);
console.log('');
console.log('tick  game_s  wall_ms phase mv cam cd_ph cd_el  dt        x         y        z         sector fwd       lat      kmh lap/lim rng');
const events = [];
let prev = { phase: sim.race.phase, moving: sim.movementActive, cam: sim.startCamera?.stage, cd: sim.countdownStarted ? sim.countdown.phase : 6 };
const start = [...b0.position];
let firstMove = null;
const speedAt = {};
for (let n = 1; n <= ticks; n++) {
  let wallMs, dt;
  if (recomp) {
    seconds += tickMs / 1000;
    wallMs = (Math.floor(seconds * 1000) >>> 0) - 1000;
    dt = engine.sampleCounter(Math.floor(seconds * QPC), QPC);
  } else {
    wallMs = n * tickMs;
    dt = engine.sampleAbsoluteSeconds((timerEpoch + wallMs) / 1000);
  }
  sim.step(input, dt, wallMs, { wallMs, engineMs: (recomp ? 1000 : timerEpoch) + wallMs, keys: {} });
  const b = sim.motion.body;
  const cd = sim.countdownStarted ? sim.countdown.phase : 6, cdEl = sim.countdownStarted ? sim.countdown.elapsed : NaN;
  const cam = sim.startCamera ? (sim.startCamera.done ? 3 : sim.startCamera.stage) : '-';
  const gameS = n * tickMs / 1000;
  console.log([String(n).padStart(4), gameS.toFixed(3).padStart(7), String(wallMs).padStart(7), String(sim.race.phase).padStart(5),
    String(+sim.movementActive).padStart(2), String(cam).padStart(3), String(cd).padStart(5), fmt(cdEl, 3).padStart(6), fmt(dt, 7),
    fmt(b.position[0], 3).padStart(9), fmt(b.position[1], 3).padStart(8), fmt(b.position[2], 3).padStart(9), String(b.sector).padStart(6),
    fmt(b.forwardSpeed, 4).padStart(9), fmt(b.lateralSpeed, 4).padStart(8), String(sim.playerSpeedKmh).padStart(4),
    `${sim.race.lapCount}/${sim.race.lapLimit}`.padStart(7), random.state.toString(16).padStart(8, '0')].join(' '));
  if (sim.race.phase !== prev.phase) events.push(`tick ${n} (${gameS.toFixed(3)} s): race phase ${prev.phase} -> ${sim.race.phase}`);
  if (cam !== prev.cam) events.push(`tick ${n} (${gameS.toFixed(3)} s): start camera stage ${prev.cam} -> ${cam} (3 = done)`);
  if (cd !== prev.cd) events.push(`tick ${n} (${gameS.toFixed(3)} s): 321 phase ${prev.cd} -> ${cd}`);
  const moved = Math.hypot(b.position[0] - start[0], b.position[2] - start[2]);
  if (firstMove === null && (moved > 1e-4 || b.forwardSpeed !== 0)) {
    firstMove = n;
    events.push(`tick ${n} (${gameS.toFixed(3)} s): first player movement: forward ${b.forwardSpeed} moved ${moved.toFixed(5)}`);
  }
  if (firstMove !== null) {
    const k = n - firstMove + 1;
    if ([1, 2, 4, 8, 10, 20, 40, 80, 120].includes(k)) speedAt[k] = { n, forward: b.forwardSpeed, kmh: sim.playerSpeedKmh, moved };
  }
  if (npcEvery && n % npcEvery === 0) console.log(`#npc ${n}: ${sim.opponents.map((a) =>
    `${a.body.position.map((x) => x.toFixed(2)).join(' ')} f${a.body.forwardSpeed.toFixed(3)} s${a.body.sector}`).join(' | ')}`);
  prev = { phase: sim.race.phase, moving: sim.movementActive, cam, cd };
}
console.log('');
console.log('# events');
for (const e of events) console.log('#   ' + e);
console.log('# speed after k updates with movement (k = 1 is the first moving update):');
for (const [k, v] of Object.entries(speedAt)) console.log(`#   k ${k} (tick ${v.n}): forward ${v.forward.toFixed(4)} (${(v.forward * 3.6).toFixed(2)} km/h) HUD ${v.kmh} km/h, distance from start ${v.moved.toFixed(3)}`);
