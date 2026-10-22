import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nativeAIPlayerBehind, nativeAIStartChase, updateNativeAITransition, NATIVE_AI_TRANSITIONS } from '../src/simulation/native-ai.js';
import { NativeRandom } from '../src/simulation/native-random.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-state-fixtures.json', import.meta.url)));
for (const precision of [24, 53]) {
  test(`Original AI player-behind guard ${precision}-bit`, () => {
    for (const [i, c] of fixtures.behind.entries()) {
      if (c.precision !== precision) continue;
      const body = { ...c.body }, state = { ...c.state };
      assert.equal(nativeAIPlayerBehind(body, state, c.player, c.rank, { precision }), c.expected, `guard ${i}`);
      assert.equal(body.yaw, c.yaw, `yaw ${i}`);
      assert.deepEqual(state, c.expectedState, `state ${i}`);
    }
  });
  test(`Original AI random chase guard ${precision}-bit`, () => {
    for (const [i, c] of fixtures.chase.entries()) {
      if (c.precision !== precision) continue;
      const state = { ...c.state }, random = new NativeRandom(c.seed);
      assert.equal(nativeAIStartChase(c.body, state, c.rank, c.dt, random, { precision }), c.expected, `chase ${i}`);
      assert.equal(state.chaseTime, c.chaseTime, `timer ${i}`);
      assert.equal(random.state, c.randomState, `random ${i}`);
    }
  });
}
test('Original populated transition table and first-match call order', () => {
  assert.deepEqual(NATIVE_AI_TRANSITIONS, fixtures.table);
  for (const [i, c] of fixtures.transition.entries()) {
    const state = { mode: c.mode }, calls = [];
    const guards = Object.fromEntries(Object.entries(c.guards).map(([address, result]) => [address, () => { calls.push(address); return result; }]));
    assert.equal(updateNativeAITransition(state, guards), c.expected, `transition ${i}`);
    assert.deepEqual(calls, c.calls, `guard order ${i}`);
  }
});
