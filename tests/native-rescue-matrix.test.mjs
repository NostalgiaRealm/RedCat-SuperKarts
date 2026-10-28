import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeRescue, updateNativeRescue, NATIVE_RESCUE_SHRINK, NATIVE_RESCUE_GROW } from '../source/simulation/native-rescue.js';
import { updateNativeWheelPose } from '../source/simulation/native-ground.js';
import { resistanceForce } from '../source/simulation/native-forces.js';
import { parsePhysicsTable } from '../source/simulation/native-tables.js';

// tools/native-rescue-matrix-fixtures.py: native 0x4a17c0 scales the body
// render matrix in place (as 0x48ca60 does), then 0x41c0b0 and 0x415520 read
// that scaled matrix on the next tick. Both x87 precisions.
const fixture = JSON.parse(readFileSync(new URL('../evidence/native/rescue-matrix-fixtures.json', import.meta.url)));
const physics = [0, 1, 2].map(i => parsePhysicsTable(readFileSync(new URL(`../public/assets/physics/phys${i}.dat`, import.meta.url))));
// Row-major 3x3 inside the native 4x4 at render +0x10 (row stride 0x10).
const MATRIX3 = [0, 1, 2, 4, 5, 6, 8, 9, 10];
const label = c => `${c.precision}-bit ${c.body} ${c.table}[${c.frame}]`;
const exact = (actual, expected, message) => assert.ok(Object.is(actual, expected), `${message}: ${actual} != ${expected}`);

function portScaledMatrix(c) {
  const body = { id: 0, position: [...c.position], matrix: [...c.matrix], lateralSpeed: 0, verticalSpeed: 0, forwardSpeed: 0 };
  const entry = createNativeRescue(body);
  Object.assign(entry, { frame: c.frame, shrinking: c.table === 'shrink' });
  // Grow frame 0 resolves a destination; null keeps the body in place.
  updateNativeRescue(entry, 0.025, { resolveDestination: () => null, precision: c.precision, effectsEnabled: false });
  assert.equal(entry.scale, c.scale, `${label(c)} scale`);
  return entry.matrix;
}

function wheelPose(c, matrix) {
  const pose = c.wheelPose;
  const body = { position: [...c.position], matrix: [...c.matrix], forwardSpeed: pose.forwardSpeed };
  const state = { wheels: pose.wheels.map(wheel => ({ local: [...wheel.local], radius: wheel.radius, spin: 0, steeringAngle: 0 })) };
  const samples = [];
  updateNativeWheelPose(body, state, pose.deltaSeconds, pose.steering, (...point) => {
    samples.push(point);
    return pose.heights[samples.length - 1];
  }, { precision: c.precision, matrix });
  return { samples, wheels: state.wheels };
}

function resistance(c, item, matrix14, matrix34) {
  const { preset, record, tireUpgrade } = c.resistance;
  return resistanceForce({ forwardSpeed: item.forwardSpeed, mass: item.mass }, physics[preset][record],
    { tireUpgrade, handbrake: item.handbrake, matrix14, matrix34, precision: c.precision });
}

test('fixture covers both precisions, rotated bodies and the 1.4/1.2/0.5/0.1 frames', () => {
  for (const precision of [24, 53]) {
    const cases = fixture.cases.filter(c => c.precision === precision);
    assert.equal(cases.length, 60);
    for (const scale of [1.4, 1.2, 0.5, 0.1].map(Math.fround)) {
      for (const table of ['shrink', 'grow']) assert.ok(cases.some(c => c.table === table && c.scale === scale), `${precision} ${table} ${scale}`);
    }
    assert.ok(cases.filter(c => c.matrix[1] !== 0 && c.matrix[3] !== 0 && c.matrix[5] !== 0).length >= 50, 'pitch/roll bodies');
  }
});

test('native 0x48c520 scale tables are diag(s, s, s, 1) with the port shrink/grow scales', () => {
  for (const { precision, shrink, grow } of fixture.scaleTables) {
    for (const [table, port] of [[shrink, NATIVE_RESCUE_SHRINK], [grow, NATIVE_RESCUE_GROW]]) {
      table.forEach((matrix, frame) => matrix.forEach((value, i) =>
        exact(value, i === 15 ? 1 : [0, 5, 10].includes(i) ? port[frame] : 0, `${precision}-bit frame ${frame} [${i}]`)));
    }
  }
});

test('port scaled rescue matrix equals native in-place 0x4a17c0 at both precisions', () => {
  let negativeZeroInputs = 0;
  for (const c of fixture.cases) {
    const port = portScaledMatrix(c);
    MATRIX3.forEach((index, k) => {
      // Native sums the zero products of the diagonal scale rows, so s*(-0)
      // + (+0) stores +0; the port matches that bit for bit.
      exact(port[k], c.scaled4x4[index], `${label(c)} [${k}]`);
      if (Object.is(c.matrix[k], -0)) negativeZeroInputs++;
    });
    // Beyond the 3x3: column 3 stays zero and the translation row is copied.
    for (const i of [3, 7, 11]) exact(c.scaled4x4[i], 0, `${label(c)} column 3 [${i}]`);
    for (const i of [12, 13, 14, 15]) exact(c.scaled4x4[i], c.native4x4[i], `${label(c)} row 3 [${i}]`);
  }
  // yaw40-signed-zero has four -0 entries, over ten frames and two precisions.
  assert.equal(negativeZeroInputs, 80);
});

test('0x41c0b0 samples the ground at the scaled-matrix wheel points, with exact wheel outputs', () => {
  assert.deepEqual(fixture.bodyMatrixReads['0x41c0b0'].pcs, ['0x4a2622']);
  for (const c of fixture.cases) {
    const { samples, wheels } = wheelPose(c, portScaledMatrix(c));
    assert.equal(samples.length, 4, label(c));
    samples.forEach((point, i) => point.forEach((value, axis) =>
      exact(value, c.wheelPose.samples[i][axis], `${label(c)} sample ${i}[${axis}]`)));
    wheels.forEach((wheel, i) => {
      const expected = c.wheelPose.expected[i];
      exact(wheel.local[1], expected.localY, `${label(c)} wheel ${i} localY`);
      exact(wheel.spin, expected.spin, `${label(c)} wheel ${i} spin`);
      exact(wheel.steeringAngle, expected.steeringAngle, `${label(c)} wheel ${i} steeringAngle`);
    });
  }
});

test('0x415520 resistance with scaled +0x14/+0x34 matches native', () => {
  assert.deepEqual(fixture.bodyMatrixReads['0x415520'].offsets, ['+0x14', '+0x34']);
  for (const c of fixture.cases) {
    const port = portScaledMatrix(c);
    for (const item of c.resistance.results) {
      const name = `${label(c)} speed ${item.forwardSpeed} handbrake ${item.handbrake}`;
      exact(item.middle, 0, `${name} middle`);
      // Native scaled terms: bit-exact.
      const native = resistance(c, item, c.scaled4x4[1], c.scaled4x4[9]);
      exact(native.lateral, item.lateral, `${name} lateral (native terms)`);
      exact(native.longitudinal, item.longitudinal, `${name} longitudinal (native terms)`);
      // Port scaled terms: bit-exact too, including the sign of a zero lateral.
      const actual = resistance(c, item, port[1], port[7]);
      for (const key of ['lateral', 'longitudinal']) exact(actual[key], item[key], `${name} ${key} (port terms)`);
    }
  }
});

test('control: the unscaled body matrix samples different wheel points', () => {
  let scaled = 0, resistanceChanged = 0;
  for (const c of fixture.cases) {
    const { samples } = wheelPose(c, c.matrix);
    const same = samples.every((point, i) => point.every((value, axis) => value === c.wheelPose.samples[i][axis]));
    if (c.scale === 1) assert.ok(same, `${label(c)} unit scale`);
    else {
      scaled++;
      assert.ok(!same, `${label(c)} unscaled points must differ from native`);
    }
    for (const item of c.resistance.results) {
      const unscaled = resistance(c, item, c.matrix[1], c.matrix[7]);
      if (unscaled.lateral !== item.lateral || unscaled.longitudinal !== item.longitudinal) resistanceChanged++;
    }
  }
  assert.equal(scaled, 96);
  assert.ok(resistanceChanged > 0);
});
