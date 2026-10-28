import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { parsePhysicsTable } from '../source/simulation/native-tables.js';
import { slipAngle, tireLateralForce, enginePower, driveForce, resistanceForce } from '../source/simulation/native-forces.js';
import { calculateNativePlayerForces } from '../source/simulation/native-player.js';
import { NATIVE_PRECISION } from '../source/simulation/native-precision.js';
import { integrateNativeEuler, quantizeNativePlanarVelocity } from '../source/simulation/native-integrator.js';
import { nativeStandardKartInertia } from '../source/simulation/native-motion.js';

const read = name => JSON.parse(readFileSync(new URL(`../${name}`, import.meta.url)));
const forces = read('evidence/gameplay/native-fixtures-53.json');
const phases = read('evidence/native/player-phase-fixtures-53.json');
const recurrence = read('evidence/gameplay/native-player-recurrence-53.json');
const inventory = read('evidence/gameplay/inventory.json');
const tables = [0, 1, 2].map(preset => {
  const table = inventory.binaryTables.find(entry => entry.source === `Phys${preset}.dat`);
  const bytes = new Uint8Array(table.bytes), view = new DataView(bytes.buffer);
  for (const record of table.records) record.uint32.forEach((value, n) => view.setUint32(record.offset + n * 4, value, true));
  return parsePhysicsTable(bytes);
});
const shippedTables = [0, 1, 2].map(i => parsePhysicsTable(readFileSync(
  new URL(`../public/assets/physics/phys${i}.dat`, import.meta.url))));
const precision = 53;
const same = (actual, expected, label) => assert.ok(actual === expected, `${label}: ${actual} != ${expected}`);

test('fixtures were captured under the 53-bit x87 control word', () => {
  assert.equal(forces.fpuControlWord, '0x027f (53-bit precision)');
  assert.equal(phases.precision, 53);
  assert.equal(recurrence.precision, 53);
});

test('recurrence body inverse mass and inertia are native 0x48fda0 at 53-bit and equal the port', () => {
  // 0x48fdf4 stores 1/mass; the inertia stays in ST0 until FSTP +0x94 at 0x48fe1e.
  const kart = nativeStandardKartInertia(0, { precision });
  for (const trace of recurrence.traces) {
    same(trace.body.inverseMass, kart.inverseMass, 'inverseMass');
    same(trace.body.inverseInertia, kart.inverseInertia, 'inverseInertia');
    same(trace.body.mass, kart.mass, 'mass');
  }
  assert.notEqual(kart.inverseInertia, nativeStandardKartInertia(0, { precision: 24 }).inverseInertia);
});

test('120 force kernel cases match original x86 instructions at 53-bit precision', () => {
  for (const [i, fixture] of forces.forceCases.entries()) {
    const physics = tables[fixture.preset][fixture.record];
    for (const axle of ['front', 'rear']) {
      // 0x414ff0 returns FPATAN's extended result (rear: after FCHS; front:
      // after a 53-bit FSUBP), which Math.atan can only reach to one double
      // ULP. Callers store it as a float (0x415388/0x4153b4), so the force
      // kernels below still compare exactly.
      const slip = slipAngle(fixture.body, physics, axle, fixture.steering, { precision });
      const expectedSlip = fixture.expected[`${axle}Slip`];
      assert.ok(Math.abs(slip - expectedSlip) <= 1e-15, `${i}/${axle}Slip: ${slip} != ${expectedSlip}`);
      same(tireLateralForce(fixture.body, physics, axle, fixture.steering, fixture.tireUpgrade, fixture.handbrake, { precision }),
        fixture.expected[`${axle}Force`], `${i}/${axle}Force`);
    }
    same(enginePower(physics, fixture.rpm, fixture.motorUpgrade, { precision }), fixture.expected.power, `${i}/power`);
    same(driveForce(physics, { ...fixture, precision }), fixture.expected.drive, `${i}/drive`);
    const resistance = resistanceForce(fixture.body, physics, { ...fixture, precision });
    same(resistance.lateral, fixture.expected.resistance.lateral, `${i}/resistance.lateral`);
    same(resistance.longitudinal, fixture.expected.resistance.longitudinal, `${i}/resistance.longitudinal`);
  }
});

test('120 complete player force updates match original x86 instructions at 53-bit precision', () => {
  for (const [i, fixture] of forces.forceCases.entries()) {
    const body = { ...fixture.body };
    const force = calculateNativePlayerForces(body, tables[fixture.preset][fixture.record], fixture, 0.025, { ...fixture, precision });
    const actual = { ...force, lateralSpeed: body.lateralSpeed, forwardSpeed: body.forwardSpeed, yawRate: body.yawRate };
    for (const [key, expected] of Object.entries(fixture.expected.playerForces)) same(actual[key], expected, `${i}/${key}`);
  }
});

test('720 complete original player force calls including result phases match at 53-bit precision', () => {
  for (const [i, c] of phases.cases.entries()) {
    const body = { ...c.body }, controls = { throttle: c.throttle, brake: c.brake, steering: c.steering, handbrake: c.handbrake };
    const force = calculateNativePlayerForces(body, tables[c.preset][c.record], controls, .025, { ...c, precision });
    const actual = { ...body, ...force, handbrake: controls.handbrake };
    for (const [key, value] of Object.entries(c.expected)) same(actual[key], value, `${i}/${key}`);
    assert.equal(controls.throttle, c.throttle);
    assert.equal(controls.brake, c.brake);
  }
});

test('2400 recurring original player force/Euler frames match exactly at 53-bit precision', () => {
  for (const [traceIndex, trace] of recurrence.traces.entries()) {
    const body = structuredClone(trace.body);
    let rpm = 800, gear = 0;
    for (const [index, frame] of trace.frames.entries()) {
      const label = `trace${traceIndex} frame${index}`;
      const force = calculateNativePlayerForces(body, shippedTables[trace.preset][trace.record],
        { ...frame.controls }, frame.delta, {
          rpm, gear, motorUpgrade: trace.upgrade, tireUpgrade: trace.upgrade,
          gearboxUpgrade: trace.upgrade, phase: frame.phase, precision,
        });
      for (const [key, value] of Object.entries(frame.force)) same(force[key], value, `${label} ${key}`);
      for (const key of ['rpm', 'gear', 'slipMagnitude']) assert.equal(force[key], frame[key], `${label} ${key}`);
      rpm = force.rpm; gear = force.gear;
      // The fixture emulates the outer planar quantization 0x491e1c..0x491e72.
      quantizeNativePlanarVelocity(body, precision);
      for (let step = 0; step < 8; step++) integrateNativeEuler(body, force, Math.fround(frame.delta * .125), { precision });
      for (const [key, value] of Object.entries(frame.expected)) same(body[key], value, `${label} ${key}`);
    }
  }
});

test('default precision follows NATIVE_PRECISION', () => {
  const fixture = forces.forceCases[0];
  const physics = tables[fixture.preset][fixture.record];
  const explicit = calculateNativePlayerForces({ ...fixture.body }, physics, { ...fixture }, 0.025, { ...fixture, precision: NATIVE_PRECISION });
  assert.deepEqual(calculateNativePlayerForces({ ...fixture.body }, physics, { ...fixture }, 0.025, fixture), explicit);
  assert.equal(enginePower(physics, fixture.rpm, fixture.motorUpgrade),
    enginePower(physics, fixture.rpm, fixture.motorUpgrade, { precision: NATIVE_PRECISION }));
});
