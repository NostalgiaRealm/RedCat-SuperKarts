import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeRandom } from '../source/simulation/native-random.js';
import { updateNativeAIPriorities, updateNativeAIWobble, applyNativeAICatchup, updateNativeAIWheels } from '../source/simulation/native-ai.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-support-fixtures.json', import.meta.url)));
test('Native NPC random lane preferences use shared CRT stream', () => {
  for (const [i, c] of fixtures.priority.entries()) {
    const random = new NativeRandom(c.seed), state = { priorities: c.priorities };
    updateNativeAIPriorities(state, c.efficiency, random);
    assert.deepEqual({ priorities: state.priorities, state: random.state }, c.expected, `case ${i}`);
  }
});
for (const precision of [24, 53]) {
  test(`Native NPC body wobble ${precision}-bit`, () => {
    for (const [i, c] of fixtures.wobble.entries()) {
      if (c.precision !== precision) continue;
      const random = new NativeRandom(c.seed), body = { ...c.body };
      updateNativeAIWobble(body, c.dt, random, { precision });
      assert.deepEqual(body, c.expected, `body case ${i}`);
      assert.equal(random.state, c.randomState, `random case ${i}`);
    }
  });
  test(`Native NPC catch-up and slowdown ${precision}-bit`, () => {
    for (const [i, c] of fixtures.catchup.entries()) {
      if (c.precision !== precision) continue;
      const body = { ...c.body }, state = { ...c.state };
      applyNativeAICatchup(body, state, c.difficulty, c.difference, { precision });
      assert.deepEqual({ body, state }, c.expected, `case ${i}`);
    }
  });
  test(`Native NPC wheel presentation ${precision}-bit`, () => {
    for (const [i, c] of fixtures.wheels.entries()) {
      if (c.precision !== precision) continue;
      const state = { wheels: structuredClone(c.wheels) };
      updateNativeAIWheels(c.body, state, c.dt, c.height, { precision });
      assert.deepEqual(state.wheels.map(wheel => ({ spin: wheel.spin, steeringAngle: wheel.steeringAngle, localY: wheel.local[1] })), c.expected, `case ${i}`);
    }
  });
}
