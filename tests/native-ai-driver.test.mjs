import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeAIDriver, NativeWaypointOccupancy } from '../src/simulation/native-ai-driver.js';
import { NativeRandom } from '../src/simulation/native-random.js';
import { NativeGroundClock } from '../src/simulation/native-ground.js';
import { NativeRailCollision } from '../src/simulation/native-collision.js';
import { createNativeTrack } from '../src/simulation/native-track.js';
import { nativePlayerStart } from '../src/simulation/native-start.js';
import { parseRacerTable } from '../src/simulation/native-tables.js';
import { SimulationClock } from '../src/simulation/clock.js';

const read = name => JSON.parse(readFileSync(new URL(`../${name}`, import.meta.url)));
const inventory = read('evidence/gameplay/inventory.json');
const source = inventory.binaryTables.find(table => table.source === 'cars1.dat');
const bytes = new Uint8Array(source.bytes), view = new DataView(bytes.buffer);
source.records.forEach(record => record.uint32.forEach((value, i) => view.setUint32(record.offset + i * 4, value, true)));
const racers = parseRacerTable(bytes);
const geometry = read('public/assets/cars.json').cars[0];
const mesh = read('public/assets/meshes/kart03.json');
const bounds = { minX: Infinity, maxX: -Infinity, minZ: Infinity, maxZ: -Infinity };
for (let i = 0; i < mesh.position.length; i += 3) {
  bounds.minX = Math.min(bounds.minX, mesh.position[i]); bounds.maxX = Math.max(bounds.maxX, mesh.position[i]);
  bounds.minZ = Math.min(bounds.minZ, mesh.position[i + 2]); bounds.maxZ = Math.max(bounds.maxZ, mesh.position[i + 2]);
}

for (let id = 0; id < 6; id++) test(`Connected normal NPC and shared streams on original track ${id}`, () => {
  const track = read(`public/assets/tracks/etappe${id}.json`), world = createNativeTrack(track);
  const replay = times => {
    const random = new NativeRandom(1999), occupancy = new NativeWaypointOccupancy(track), groundClock = new NativeGroundClock();
    const driver = new NativeAIDriver({
      track, world, geometry, start: nativePlayerStart(track, world), id: 1,
      racer: racers[1], playerRacer: racers[0], random, occupancy, groundClock,
      collision: new NativeRailCollision(track, bounds), efficiency: 10,
    });
    const history = [];
    const clock = new SimulationClock({ intervalMs: 25, update(dt) {
      driver.prepare(dt, { difficulty: 1, progressDifference: 0 });
      const state = driver.integrate();
      assert.ok([...state.position, state.yaw, state.forwardSpeed].every(Number.isFinite));
      history.push({ ...state, random: random.state });
    } });
    times.forEach(time => clock.frame(time));
    assert.ok(history.some(state => state.forwardSpeed > 1));
    return history;
  };
  const schedule = fps => [...Array.from({ length: fps * 5 }, (_, n) => n * 1000 / fps), 5000];
  const baseline = replay(schedule(40));
  for (const fps of [31, 60, 144]) assert.deepEqual(replay(schedule(fps)), baseline);
  assert.deepEqual(replay([0, 9, 250, 1500, 4999, 5000]), baseline);
});

test('NPC adapter explicitly rejects unconnected states and missing native dependencies', () => {
  const track = read('public/assets/tracks/etappe0.json'), world = createNativeTrack(track);
  const options = { track, world, geometry, start: nativePlayerStart(track, world), id: 1,
    racer: racers[1], playerRacer: racers[0], random: new NativeRandom(1),
    occupancy: new NativeWaypointOccupancy(track), groundClock: new NativeGroundClock(),
    collision: new NativeRailCollision(track, bounds), efficiency: 10 };
  assert.throws(() => new NativeAIDriver({ ...options, collision: undefined }), /collision sweep/);
  const driver = new NativeAIDriver(options);
  driver.state.mode = 10;
  assert.throws(() => driver.prepare(.025, { difficulty: 1, progressDifference: 0 }), /elapsed time/);
});

test('NPC hit mode replaces normal driving and resets native lane order on completion', () => {
  const track = read('public/assets/tracks/etappe0.json'), world = createNativeTrack(track);
  const random = new NativeRandom(99);
  const driver = new NativeAIDriver({ track, world, geometry, start: nativePlayerStart(track, world), id: 1,
    racer: racers[1], playerRacer: racers[0], random,
    occupancy: new NativeWaypointOccupancy(track), groundClock: new NativeGroundClock(),
    collision: new NativeRailCollision(track, bounds), efficiency: 10 });
  driver.phase = 25;
  driver.prepare(.025, { difficulty: 1, progressDifference: 0, effect: () => {
    driver.body.forwardSpeed = 0;
    driver.body.yawRate = 2;
    return true;
  } });
  assert.equal(driver.controls.throttle, 0);
  assert.equal(driver.body.yawRate, 2);
  assert.equal(random.state, 99, 'normal driving did not consume lane or wobble randomness');
  driver.integrate();
  driver.prepare(.025, { difficulty: 1, progressDifference: 0, effect: () => false });
  assert.equal(driver.phase, 0);
  assert.deepEqual(driver.state.priorities, [1, 0, 2]);
  assert.equal(driver.controls.throttle, 0, 'normal driving resumes on next tick');
});

function connectedDriver() {
  const track = read('public/assets/tracks/etappe0.json'), world = createNativeTrack(track);
  return new NativeAIDriver({ track, world, geometry, start: nativePlayerStart(track, world), id: 1,
    racer: racers[1], playerRacer: racers[0], random: new NativeRandom(1999),
    occupancy: new NativeWaypointOccupancy(track), groundClock: new NativeGroundClock(),
    collision: new NativeRailCollision(track, bounds), efficiency: 10 });
}
function decisionFor(driver, extra = {}) {
  const player = { ...driver.body, position: [...driver.body.position], id: 4 };
  return { player, racers: [driver.body, player], rank: 1, playerRank: 0, itemRank: 0,
    time: 1, owned: { state: 1, type: 0, level: 0 }, shared: { dropperCounter: 0 },
    reactionMs: 60, catchupMs: 1500, catchupDurationMs: 2000, playerProtected: false,
    ...extra };
}

test('Connected selector fires an owned turbo then resumes original normal movement', () => {
  const driver = connectedDriver(), calls = [];
  driver.state.priorities = [2, 1, 0];
  const event = { type: 'turbo', shooter: 1, level: 2 };
  driver.prepare(.025, { difficulty: 2, progressDifference: 0, decision: decisionFor(driver, {
    owned: { state: 2, type: 5, level: 2 },
    fire() { calls.push(driver.phase); return event; },
  }) });
  assert.deepEqual(calls, [26]);
  assert.equal(driver.phase, 0);
  assert.equal(driver.state.reactionMode, -1);
  assert.deepEqual(driver.events, [event]);
  assert.ok(driver.controls.throttle > 0);
  assert.deepEqual(driver.animationEvents, [], 'owned turbo does not call track-turbo animation');
});

test('Countdown selects the native item state but waits for movement activation to execute it', () => {
  const driver = connectedDriver(), fired = [];
  const decision = decisionFor(driver, {
    owned: { state: 2, type: 5, level: 1 },
    fire() { fired.push(1); return { type: 'turbo' }; },
  });
  driver.prepare(.025, { active: false, decision });
  assert.equal(driver.phase, 26);
  assert.equal(driver.controls.throttle, 0);
  assert.deepEqual(fired, []);
  driver.integrate();
  driver.prepare(.025, { active: true, difficulty: 1, progressDifference: 0, decision });
  assert.deepEqual(fired, [1]);
  assert.equal(driver.phase, 0);
});

test('Connected stuck selector enters recovery and invokes its original respawn branch', () => {
  const driver = connectedDriver(), calls = [];
  driver.state.sectorTime = Math.fround(2.1);
  driver.prepare(.025, { difficulty: 0, progressDifference: 0, decision: decisionFor(driver, {
    rescue(body) { calls.push(body); driver.state.blockRecovery = true; },
  }) });
  assert.deepEqual(calls, [driver.body]);
  assert.equal(driver.phase, 0);
  assert.equal(driver.state.blockRecovery, true);
  assert.deepEqual(driver.state.priorities, [1, 0, 2]);
  assert.equal(driver.controls.steering, 0);
});

test('NPC animation callback queue survives preparation and preserves expiry-frame input', () => {
  const driver = connectedDriver();
  const callback = { callback: 0x40d610, fsmState: 0 };
  driver.animationEvents.push(callback);
  driver.state.turboVisible = true;
  driver.state.turboTime = 1;
  driver.prepare(.025, { active: false, decision: { time: 6 } });
  assert.deepEqual(driver.animationEvents, [callback]);
  assert.deepEqual(driver.animationTurbo, { turboActive: true, turboStartedSeconds: 1, nowSeconds: 6 });
  assert.equal(driver.state.turboVisible, false);
  driver.animationEvents.length = 0;
  driver.integrate();
  driver.prepare(.025, { active: false, decision: { time: 6.025 } });
  assert.equal(driver.animationTurbo.turboActive, false);
  assert.deepEqual(driver.animationEvents, []);
});
