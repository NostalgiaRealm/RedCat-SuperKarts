import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeGroundState, NativeGroundClock, updateNativeGround, updateNativeWheelPose } from '../source/simulation/native-ground.js';
import { NATIVE_PRECISION } from '../source/simulation/native-precision.js';

// Same inputs as native-ground-fixtures.json, probed with x87 control word 0x027f.
const fixtures = JSON.parse(readFileSync(new URL('../evidence/gameplay/native-ground-fixtures-53.json', import.meta.url)));
const precision = 53;
const exact = (a, b, label) => assert.ok(Object.is(a, b), `${label}: ${a} != ${b}`);

test('53-bit fixture was probed under PC=53', () => {
  assert.match(fixtures.fpuControlWord, /^0x027f /);
});

test('160 original x86 wheel callbacks agree exactly at 53-bit x87 precision', () => {
  for (const [index, fixture] of fixtures.cases.entries()) {
    const body = structuredClone(fixture.body);
    const state = { wheels: structuredClone(fixture.wheels) };
    const clock = new NativeGroundClock(fixture.oldDelta);
    let sample = 0;
    updateNativeGround(body, state, fixture.delta, () => fixture.heights[sample++], { clock, precision });
    assert.equal(sample, 8);
    assert.equal(state.groundCount, fixture.expected.groundCount, `case ${index} contact count`);
    assert.equal(state.playerContact, fixture.expected.playerContact, `case ${index} player flag`);
    exact(clock.delta, fixture.expected.delta, `case ${index} delta`);
    for (const key of ['position', 'matrix']) body[key].forEach((value, axis) => exact(value, fixture.expected[key][axis], `case ${index} ${key}[${axis}]`));
    state.wheels.forEach((wheel, i) => {
      exact(wheel.verticalSpeed, fixture.expected.wheels[i].verticalSpeed, `case ${index} wheel ${i} vertical`);
      wheel.position.forEach((value, axis) => exact(value, fixture.expected.wheels[i].position[axis], `case ${index} wheel ${i} position[${axis}]`));
    });
  }
});

test('160 native wheel poses agree exactly at 53-bit x87 precision', () => {
  for (const [index, fixture] of fixtures.wheelPoseCases.entries()) {
    const state = { wheels: structuredClone(fixture.wheels) };
    let sample = 0;
    updateNativeWheelPose(fixture.body, state, fixture.delta, fixture.steering, () => fixture.heights[sample++], { precision });
    assert.equal(sample, 4);
    state.wheels.forEach((wheel, i) => {
      exact(wheel.local[1], fixture.expected[i].localY, `pose ${index} wheel ${i} localY`);
      exact(wheel.spin, fixture.expected[i].spin, `pose ${index} wheel ${i} spin`);
      exact(wheel.steeringAngle, fixture.expected[i].steeringAngle, `pose ${index} wheel ${i} steeringAngle`);
    });
  }
});

test('320 recurring native frames agree exactly at 53-bit x87 precision', () => {
  for (const [traceIndex, trace] of fixtures.traces.entries()) {
    const body = structuredClone(trace.body), state = { wheels: structuredClone(trace.wheels) };
    const clock = new NativeGroundClock(trace.oldDelta);
    for (const [frameIndex, frame] of trace.frames.entries()) {
      body.forwardSpeed = frame.forwardSpeed;
      body.lateralSpeed = frame.lateralSpeed;
      // Player callback invokes 41c0b0 twice, then the engine invokes 416650.
      for (let call = 0; call < 2; call++) {
        let sample = 0;
        updateNativeWheelPose(body, state, frame.delta, frame.steering, () => frame.heights[sample++], { precision });
      }
      if (frameIndex === 0) {
        const initial = createNativeGroundState(body, state.wheels, { precision });
        state.wheels.forEach((wheel, i) => { wheel.position = initial.wheels[i].position; });
      }
      let sample = 0;
      updateNativeGround(body, state, frame.delta, () => frame.heights[sample++], { clock, precision });
      const label = `trace${traceIndex} frame${frameIndex}`;
      exact(clock.delta, frame.expected.delta, `${label} delta`);
      assert.equal(state.groundCount, frame.expected.groundCount, `${label} contact`);
      assert.equal(state.playerContact, frame.expected.playerContact, `${label} player flag`);
      for (const key of ['position', 'matrix']) body[key].forEach((value, axis) =>
        exact(value, frame.expected[key][axis], `${label} ${key}[${axis}]`));
      state.wheels.forEach((wheel, i) => {
        const expected = frame.expected.wheels[i];
        for (const key of ['verticalSpeed', 'spin', 'steeringAngle']) exact(wheel[key], expected[key], `${label} wheel${i} ${key}`);
        exact(wheel.local[1], expected.localY, `${label} wheel${i} localY`);
        wheel.position.forEach((value, axis) => exact(value, expected.position[axis], `${label} wheel${i} position[${axis}]`));
      });
    }
  }
});

test('default precision follows NATIVE_PRECISION', () => {
  const base = fixtures.cases[0];
  const run = options => {
    const body = structuredClone(base.body), state = { wheels: structuredClone(base.wheels) };
    let sample = 0;
    updateNativeGround(body, state, base.delta, () => base.heights[sample++], { clock: new NativeGroundClock(base.oldDelta), ...options });
    return { body, state };
  };
  assert.deepEqual(run({}), run({ precision: NATIVE_PRECISION }));
});
