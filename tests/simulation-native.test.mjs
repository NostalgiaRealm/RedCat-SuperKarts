import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeInputState, updateNativeInput } from '../source/simulation/native-input.js';
import { parsePhysicsTable, parseRacerTable } from '../source/simulation/native-tables.js';
import { slipAngle, tireLateralForce, enginePower, driveForce, resistanceForce, handbrakeForce, nativeReverseClamp } from '../source/simulation/native-forces.js';
import { SimulationClock, NativeDeltaFilter, RaceClock } from '../source/simulation/clock.js';
import { calculateNativePlayerForces } from '../source/simulation/native-player.js';

const inventory = JSON.parse(readFileSync(new URL('../evidence/gameplay/inventory.json', import.meta.url)));
const fixtures = JSON.parse(readFileSync(new URL('../evidence/gameplay/native-fixtures.json', import.meta.url)));
function tableBytes(name) {
  const source = inventory.binaryTables.find(table => table.source === name);
  const bytes = new Uint8Array(source.bytes);
  const view = new DataView(bytes.buffer);
  for (const record of source.records) record.uint32.forEach((value, index) => view.setUint32(record.offset + index * 4, value, true));
  return bytes;
}
const physicsTables = [0, 1, 2].map(preset => parsePhysicsTable(tableBytes(`Phys${preset}.dat`)));
const buttons = mask => ({ left: Boolean(mask & 1), right: Boolean(mask & 2), accelerate: Boolean(mask & 4), brake: Boolean(mask & 8), handbrake: Boolean(mask & 32) });
const close = (actual, expected, absolute, relative = 0) => {
  assert.ok(Math.abs(actual - expected) <= Math.max(absolute, Math.abs(expected) * relative),
    `actual=${actual}; native=${expected}; error=${actual - expected}`);
};

test('native table records: verified strides and data coverage', () => {
  assert.equal(physicsTables[0].length, 20);
  assert.equal(physicsTables[0][0].raw.length, 43);
  for (let preset = 0; preset < 4; preset++) {
    const parsed = parseRacerTable(tableBytes(`cars${preset}.dat`));
    assert.equal(parsed.length, 20);
    assert.equal(parsed[0].raw.length, 31);
  }
  assert.throws(() => parsePhysicsTable(new Uint8Array(3439)), RangeError);
  assert.throws(() => parseRacerTable(new Uint8Array(2481)), RangeError);
});

test('1600 portable input updates match shipped x86 instructions exactly', () => {
  for (const trace of fixtures.inputTraces) {
    const state = createNativeInputState();
    for (const frame of trace.frames) {
      updateNativeInput(state, buttons(frame.mask), frame.delta, trace.mirrored);
      // Per-operation single rounding reproduces the 24-bit emulation exactly.
      assert.equal(state.throttle, frame.expected.throttle);
      assert.equal(state.steering, frame.expected.steering);
      assert.equal(state.brake, frame.expected.brake);
      assert.equal(state.handbrake, frame.expected.handbrake);
    }
  }
});

test('native integer braking loses input if naively called at display rate', () => {
  const slow = createNativeInputState();
  const fast = createNativeInputState();
  for (let i = 0; i < 40; i++) updateNativeInput(slow, { brake: true }, 0.025);
  for (let i = 0; i < 144; i++) updateNativeInput(fast, { brake: true }, 1 / 144);
  assert.equal(slow.brake, 40);
  assert.equal(fast.brake, 0);
});

test('120 portable force cases agree with original x86 instructions, including reverse', () => {
  for (const fixture of fixtures.forceCases) {
    const physics = physicsTables[fixture.preset][fixture.record];
    const cmp = (actual, expected) => assert.ok(actual === expected, `${actual} != ${expected}`);
    for (const axle of ['front', 'rear']) {
      // FPATAN retains extended precision until the caller's float store;
      // one rear-axle double return differs from Math.atan by one double ULP.
      close(slipAngle(fixture.body, physics, axle, fixture.steering), fixture.expected[`${axle}Slip`], 1e-15);
      cmp(tireLateralForce(fixture.body, physics, axle, fixture.steering, fixture.tireUpgrade, fixture.handbrake), fixture.expected[`${axle}Force`]);
    }
    cmp(enginePower(physics, fixture.rpm, fixture.motorUpgrade), fixture.expected.power);
    cmp(driveForce(physics, fixture), fixture.expected.drive);
    const resistance = resistanceForce(fixture.body, physics, fixture);
    cmp(resistance.lateral, fixture.expected.resistance.lateral);
    cmp(resistance.longitudinal, fixture.expected.resistance.longitudinal);
  }
});

test('complete active player force update agrees with x86 native velocity, forces, gearing and RPM', () => {
  for (const fixture of fixtures.forceCases) {
    const physics = physicsTables[fixture.preset][fixture.record];
    const body = { ...fixture.body };
    const actual = {
      ...calculateNativePlayerForces(body, physics, fixture, 0.025, fixture),
      lateralSpeed: body.lateralSpeed, forwardSpeed: body.forwardSpeed, yawRate: body.yawRate,
    };
    for (const [key, expected] of Object.entries(fixture.expected.playerForces)) {
      assert.ok(actual[key] === expected, `${key}: ${actual[key]} != ${expected}`);
    }
  }
});

function renderSchedule(fps, duration = 5000) {
  const result = [0];
  for (let index = 1; index < duration * fps / 1000; index++) result.push(index * 1000 / fps);
  result.push(duration);
  return result;
}

function replay(schedule) {
  const state = createNativeInputState();
  const output = [];
  // 25ms is the native minimum pacing gate; this isolated test does NOT claim
  // it was the measured original update interval on the user's Wine setup.
  const clock = new SimulationClock({ intervalMs: 25, update(delta, time) {
    updateNativeInput(state, { brake: time <= 1000, accelerate: time > 1000 && time <= 4000,
      left: time >= 500 && time < 1500, right: time >= 1500 && time < 2500 }, delta);
    output.push({ ...state });
  } });
  for (const timestamp of schedule) clock.frame(timestamp);
  return { output, clock: clock.snapshot() };
}

test('reference updates stay identical across 31/32/60/120/144/240 render FPS, jitter and stalls', () => {
  const baseline = replay(renderSchedule(40));
  for (const fps of [31, 32, 60, 120, 144, 240]) {
    assert.deepEqual(replay(renderSchedule(fps)).output, baseline.output);
  }
  const jitter = [0];
  for (let time = 0, index = 0; time < 5000; index++) {
    time = Math.min(5000, time + [3, 40, 7, 16, 92, 4][index % 6]);
    jitter.push(time);
  }
  assert.deepEqual(replay(jitter).output, baseline.output);
  assert.deepEqual(replay([0, 15, 600, 1000, 2500, 2501, 5000]).output, baseline.output);
  assert.equal(baseline.clock.simulationMs, 5000);
});

test('focus pause prevents a catch-up jump and race clock excludes paused wall time', () => {
  let updates = 0;
  const clock = new SimulationClock({ intervalMs: 25, update() { updates++; } });
  clock.frame(0); clock.frame(100);
  clock.pause(); clock.frame(100000);
  clock.resume(); clock.frame(200000); clock.frame(200025);
  assert.equal(updates, 5);
  const race = new RaceClock();
  race.start(50); race.pause(1050); race.resume(50000); race.advance(51000);
  assert.equal(race.elapsedMs, 2000);
});

test('native delta history weights and 100ms cap remain explicit', () => {
  const filter = new NativeDeltaFilter();
  close(filter.sample(0.025), 0.0625, 1e-8);
  close(filter.sample(0.025), 0.04375, 1e-8);
  close(filter.sample(0.025), 0.034375, 1e-8);
  close(filter.sample(0.025), 0.025, 1e-8);
  assert.equal(filter.sample(2), 0.1);
  const zero = new NativeDeltaFilter();
  zero.sample(0); zero.sample(0); zero.sample(0);
  assert.equal(zero.sample(0), 0.1);
});

test('recovered reverse constants and force direction are retained', () => {
  assert.equal(nativeReverseClamp(-20), -15);
  assert.equal(nativeReverseClamp(20), 20);
  assert.equal(handbrakeForce(-12), 30000);
  assert.equal(handbrakeForce(12), -30000);
  assert.equal(handbrakeForce(-2), 2000);
  // A force test is not a claim of verified driving or reverse transitions.
  const physics = physicsTables[1][0];
  assert.ok(driveForce(physics, { rpm: 4000, gear: 0, throttle: 0, brake: 100 }) < 0);
});
