import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativePlayerMotion } from '../src/simulation/native-motion.js';
import { SimulationClock } from '../src/simulation/clock.js';
import { parsePhysicsTable } from '../src/simulation/native-tables.js';
import { createNativeTrack } from '../src/simulation/native-track.js';
import { nativePlayerStart } from '../src/simulation/native-start.js';
import { NativeRailCollision } from '../src/simulation/native-collision.js';

const data = JSON.parse(readFileSync(new URL('../evidence/gameplay/inventory.json', import.meta.url)));
const source = data.binaryTables.find(table => table.source === 'Phys1.dat');
const bytes = new Uint8Array(source.bytes), view = new DataView(bytes.buffer);
source.records.forEach(record => record.uint32.forEach((value, i) => view.setUint32(record.offset + i * 4, value, true)));
const physics = parsePhysicsTable(bytes)[0];
const geometry = JSON.parse(readFileSync(new URL('../public/assets/cars.json', import.meta.url))).cars[0];
const track = JSON.parse(readFileSync(new URL('../public/assets/tracks/etappe0.json', import.meta.url)));
const world = createNativeTrack(track);
const start = { position: track.drive[0].position, yaw: 0, sector: 0 };

function replay(schedule) {
  // Explicit collision-free test: verifies composition and timing, not barriers.
  const motion = new NativePlayerMotion({ physics, geometry, world, start, collision: { sample: () => null } });
  const history = [];
  const clock = new SimulationClock({ intervalMs: 25, update(dt, time) {
    history.push(motion.step({ accelerate: time < 3000, brake: time >= 3000 && time < 11000 }, dt));
  } });
  schedule.forEach(time => clock.frame(time));
  return history;
}

test('connected native player movement and reverse stay identical across render rates and stalls', () => {
  const duration = 12000;
  const schedule = fps => {
    const values = [0];
    for (let frame = 1; frame < duration * fps / 1000; frame++) values.push(frame * 1000 / fps);
    return [...values, duration];
  };
  const baseline = replay(schedule(40));
  assert.ok(baseline.some(state => state.forwardSpeed > 0), 'accelerates forwards');
  assert.ok(baseline.some(state => state.forwardSpeed < -1), 'brakes through zero into reverse');
  assert.ok(baseline.every(state => state.position.every(Number.isFinite)), 'finite original-track trajectory');
  for (const fps of [31, 32, 60, 120, 144, 240]) assert.deepEqual(replay(schedule(fps)), baseline);
  assert.deepEqual(replay([0, 5, 650, 651, 1700, 5999, 6000, 12000]), baseline);
});

test('unimplemented collision is never silently substituted', () => {
  assert.throws(() => new NativePlayerMotion({ physics, geometry, world, start }), /collision adapter/);
});

test('all six native starts support rail contact, reverse steering and returning forwards at every display rate', () => {
  const mesh = JSON.parse(readFileSync(new URL('../public/assets/meshes/kart03.json', import.meta.url)));
  const bounds = { minX: Infinity, maxX: -Infinity, minZ: Infinity, maxZ: -Infinity };
  for (let i = 0; i < mesh.position.length; i += 3) {
    bounds.minX = Math.min(bounds.minX, mesh.position[i]);
    bounds.maxX = Math.max(bounds.maxX, mesh.position[i]);
    bounds.minZ = Math.min(bounds.minZ, mesh.position[i + 2]);
    bounds.maxZ = Math.max(bounds.maxZ, mesh.position[i + 2]);
  }
  const duration = 20000;
  const schedule = fps => {
    const times = [0];
    for (let n = 1; n < duration * fps / 1000; n++) times.push(n * 1000 / fps);
    return [...times, duration];
  };
  for (let id = 0; id < 6; id++) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${id}.json`, import.meta.url)));
    const world = createNativeTrack(track);
    const run = times => {
      const collision = new NativeRailCollision(track, bounds);
      const sample = collision.sample.bind(collision);
      let contacts = 0;
      collision.sample = (...args) => {
        const result = sample(...args);
        if (result.contact) contacts++;
        return result;
      };
      const motion = new NativePlayerMotion({ physics, geometry, world,
        start: nativePlayerStart(track, world), collision });
      const history = [];
      let reversed = false, returnedForwards = false;
      const clock = new SimulationClock({ intervalMs: 25, update(dt, time) {
        const state = motion.step({
          accelerate: time < 3000 || time >= 12000,
          brake: time >= 3000 && time < 12000,
          left: time >= 6000 && time < 8000,
          right: time >= 8000 && time < 10000,
        }, dt);
        if (state.forwardSpeed < -1) reversed = true;
        if (reversed && time >= 12000 && state.forwardSpeed > 1) returnedForwards = true;
        const record = [...state.position, state.yaw, state.forwardSpeed, state.lateralSpeed, state.yawRate, state.gear, state.rpm];
        assert.ok(record.every(Number.isFinite), `track ${id}: finite motion`);
        history.push(record);
      } });
      times.forEach(time => clock.frame(time));
      return { history, contacts, reversed, returnedForwards };
    };
    const baseline = run(schedule(40));
    assert.ok(baseline.contacts > 0, `track ${id}: original rails were contacted`);
    assert.ok(baseline.reversed, `track ${id}: braking crosses zero into reverse`);
    assert.ok(baseline.returnedForwards, `track ${id}: acceleration returns forwards`);
    for (const fps of [31, 32, 60, 120, 144, 240]) assert.deepEqual(run(schedule(fps)), baseline, `track ${id}, ${fps} FPS`);
    assert.deepEqual(run([0, 9, 200, 503, 4000, 8999, 9000, 14000, 20000]), baseline, `track ${id}, stalls`);
  }
});
