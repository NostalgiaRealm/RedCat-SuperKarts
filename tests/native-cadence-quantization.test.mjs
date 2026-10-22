import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {integrateNativeEuler} from '../src/simulation/native-integrator.js';

const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/cadence-quantization.json', import.meta.url)));

test('equal-time Euler cadence probe matches original instructions in both FPU modes', () => {
  for (const entry of fixture.cases) {
    const body = {...entry.state};
    for (let i = 0; i < entry.substeps; i++)
      integrateNativeEuler(body, {lateralForce: 0, verticalForce: 0,
        longitudinalForce: 0, torque: 0}, entry.deltaSeconds, {precision: entry.precision});
    for (const [field, expected] of Object.entries(entry.expected))
      assert.ok(Math.abs(body[field]-expected) < .00002,
        `${entry.precision}bit ${entry.fps}Hz yawRate${entry.state.yawRate} ${field}: ${body[field]} vs ${expected}`);
  }
});

test('the original kernel itself quantizes local velocity rotation differently below the native frame cap', () => {
  for (const precision of [24, 53]) {
    const pair = fixture.cases.filter(entry => entry.precision === precision && entry.state.yawRate === .5);
    const normal = pair.find(entry => entry.fps === 40).expected;
    const diagnostic = pair.find(entry => entry.fps === 120).expected;
    assert.ok(Math.abs(normal.yaw-diagnostic.yaw) < .0001);
    assert.ok(Math.abs(normal.lateralSpeed-diagnostic.lateralSpeed) > 1);
    assert.equal(diagnostic.lateralSpeed, 0);
  }
});
