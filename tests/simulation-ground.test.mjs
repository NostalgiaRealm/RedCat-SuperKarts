import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeGroundState, NativeGroundClock, updateNativeGround, updateNativeWheelPose } from '../source/simulation/native-ground.js';

const fixtures = JSON.parse(readFileSync(new URL('../evidence/gameplay/native-ground-fixtures.json', import.meta.url)));
const exact = (a, b, label) => assert.ok(a === b, `${label}: ${a} != ${b}`);

test('160 original x86 wheel callbacks agree for contact, airborne wheels, slopes and reverse', () => {
  for (const [index, fixture] of fixtures.cases.entries()) {
    const body = structuredClone(fixture.body);
    const state = { wheels: structuredClone(fixture.wheels) };
    const clock = new NativeGroundClock(fixture.oldDelta);
    let sample = 0;
    updateNativeGround(body, state, fixture.delta, () => fixture.heights[sample++], { clock });
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

test('160 native wheel poses preserve original suspension limits and steering/spin', () => {
  for (const fixture of fixtures.wheelPoseCases) {
    const state = { wheels: structuredClone(fixture.wheels) };
    let sample = 0;
    updateNativeWheelPose(fixture.body, state, fixture.delta, fixture.steering, () => fixture.heights[sample++]);
    assert.equal(sample, 4);
    state.wheels.forEach((wheel, i) => {
      exact(wheel.local[1], fixture.expected[i].localY, 'localY');
      exact(wheel.spin, fixture.expected[i].spin, 'spin');
      exact(wheel.steeringAngle, fixture.expected[i].steeringAngle, 'steeringAngle');
    });
  }
});

test('320 recurring native frames preserve exact suspension and tilt with shipped wheel geometry', () => {
  for (const [traceIndex, trace] of fixtures.traces.entries()) {
    const body = structuredClone(trace.body), state = {wheels: structuredClone(trace.wheels)};
    const clock = new NativeGroundClock(trace.oldDelta);
    for (const [frameIndex, frame] of trace.frames.entries()) {
      body.forwardSpeed = frame.forwardSpeed;
      body.lateralSpeed = frame.lateralSpeed;
      // Player callback invokes 41c0b0 twice, then the engine invokes416650.
      for (let call = 0; call < 2; call++) {
        let sample = 0;
        updateNativeWheelPose(body, state, frame.delta, frame.steering, () => frame.heights[sample++]);
      }
      if (frameIndex === 0) {
        const initial = createNativeGroundState(body, state.wheels);
        state.wheels.forEach((wheel, i) => {wheel.position = initial.wheels[i].position;});
      }
      let sample = 0;
      updateNativeGround(body, state, frame.delta, () => frame.heights[sample++], {clock});
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
