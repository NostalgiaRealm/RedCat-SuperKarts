import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { prepareNativeAIRecovery } from '../src/simulation/native-ai.js';
import { NativeRandom } from '../src/simulation/native-random.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-recovery-fixtures.json', import.meta.url)));
for (const precision of [24, 53]) test(`Native NPC recovery and spring ${precision}-bit`, () => {
  for (const [i, c] of fixtures.cases.entries()) {
    if (c.precision !== precision) continue;
    const body = { ...c.body }, state = structuredClone(c.state), controls = { ...c.controls }, random = new NativeRandom(c.seed);
    let respawn = 0;
    prepareNativeAIRecovery(body, controls, state, c.dt, random, {
      precision, time: c.time, sampleRouteHeight: () => c.height, respawn: () => { respawn++; },
    });
    assert.deepEqual({ body, state, controls }, c.expected, `recovery ${i}`);
    assert.equal(random.state, c.randomState, `random ${i}`);
    assert.equal(respawn * 2, c.respawnCalls.length, `respawn ${i}`);
  }
});
