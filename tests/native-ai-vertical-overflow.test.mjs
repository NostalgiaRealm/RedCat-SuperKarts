import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { applyNativeAICatchup } from '../source/simulation/native-ai.js';

const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-vertical-overflow.json', import.meta.url)));
const bits = value => {
  const bytes = Buffer.alloc(4);
  bytes.writeFloatLE(value);
  return bytes.toString('hex');
};

for (const { precision, cases, recurrence, overflowCall } of fixtures.catchup) {
  test(`Captured NPC catch-up preserves original ${precision}-bit overflow behavior`, () => {
    for (const c of cases) {
      const body = Object.fromEntries(Object.entries(c.before).map(([key, { value }]) => [key, value]));
      applyNativeAICatchup(body, {}, 2, -30, { precision });
      for (const key of Object.keys(body)) {
        assert.equal(bits(body[key]), c.after[key].bitsLE, `${c.now} ${key}`);
      }
    }
    const body = { lateralSpeed: 0, verticalSpeed: 1, forwardSpeed: 40 };
    recurrence.forEach((expected, i) => {
      applyNativeAICatchup(body, {}, 2, -30, { precision });
      assert.equal(bits(body.verticalSpeed), expected.bitsLE, `recurrence ${i + 1}`);
    });
    assert.equal(overflowCall, 1153);
    assert.equal(body.verticalSpeed, Infinity);
    assert.equal(body.forwardSpeed, 80);
  });
}

test('Native captured transition and ground-boundary evidence remains explicit', () => {
  assert.equal(fixtures.summary.activeCapturedTransitions, 119);
  assert.equal(fixtures.summary.activeTransitionMismatches, 0);
  assert.equal(fixtures.summary.finalOriginalResult.bitsLE, '0000807f');
  for (const c of fixtures.normal) {
    assert.equal(c.before.bitsLE, c.after.bitsLE);
    assert.deepEqual(c.springCalls, []);
  }
  for (const c of fixtures.ground) {
    assert.equal(c.before.bitsLE, c.after.bitsLE);
    assert.equal(c.renderYBefore, 500);
    assert.equal(c.renderYAfter, 0);
    assert.equal(c.groundCount, 4);
  }
});
