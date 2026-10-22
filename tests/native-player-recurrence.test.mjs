import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {calculateNativePlayerForces} from '../src/simulation/native-player.js';
import {integrateNativeEuler, quantizeNativePlanarVelocity} from '../src/simulation/native-integrator.js';
import {parsePhysicsTable} from '../src/simulation/native-tables.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/gameplay/native-player-recurrence.json', import.meta.url)));
const tables = [0, 1, 2].map(i => parsePhysicsTable(fs.readFileSync(
  new URL(`../public/assets/physics/phys${i}.dat`, import.meta.url))));

test('2400 recurring original player force/Euler frames match exactly at explicit24-bit precision', () => {
  for (const [traceIndex, trace] of fixture.traces.entries()) {
    const body = structuredClone(trace.body);
    let rpm = 800, gear = 0;
    for (const [index, frame] of trace.frames.entries()) {
      const force = calculateNativePlayerForces(body, tables[trace.preset][trace.record],
        {...frame.controls}, frame.delta, {
          rpm, gear, motorUpgrade: trace.upgrade, tireUpgrade: trace.upgrade,
          gearboxUpgrade: trace.upgrade, phase: frame.phase,
        });
      const label = `trace${traceIndex} frame${index}`;
      for (const [key, value] of Object.entries(frame.force))
        assert.ok(force[key] === value, `${label} ${key}: ${force[key]} != ${value}`);
      for (const key of ['rpm', 'gear', 'slipMagnitude']) assert.equal(force[key], frame[key], `${label} ${key}`);
      rpm = force.rpm; gear = force.gear;
      quantizeNativePlanarVelocity(body);
      for (let step = 0; step < 8; step++) integrateNativeEuler(body, force, Math.fround(frame.delta * .125));
      for (const [key, value] of Object.entries(frame.expected))
        assert.ok(body[key] === value, `${label} ${key}: ${body[key]} != ${value}`);
    }
  }
});
