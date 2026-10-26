import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nativeRotationMatrix } from '../source/simulation/native-transform.js';
import { NativeRandom } from '../source/simulation/native-random.js';

const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/transform-fixtures.json', import.meta.url)));
for (const precision of [24, 53]) test(`Native render matrices ${precision}-bit`, () => {
  for (const [i, fixture] of fixtures.transforms.entries()) {
    if (fixture.options.precision !== precision) continue;
    assert.deepEqual(nativeRotationMatrix(fixture.angles, fixture.options).map(x => x || 0), fixture.expected.map(x => x || 0), `case ${i}`);
  }
});
test('Original CRT random sequence and shared state', () => {
  for (const fixture of fixtures.random) {
    const random = new NativeRandom(fixture.seed);
    assert.deepEqual(Array.from({ length: fixture.values.length }, () => random.next()), fixture.values);
    assert.equal(random.state, fixture.state);
  }
});
