import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nativeTrafficRelocationRequests } from '../src/simulation/native-ai-range.js';

const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-range-fixtures.json', import.meta.url)));
test('720 complete native outside-car checks preserve wrap boundaries and registry filtering', () => {
  for (const f of fixtures.cases) {
    assert.deepEqual(nativeTrafficRelocationRequests(f.player, f.registry, f.options), f.expected);
  }
});
test('the original type3 race roster is never relocated by the legacy outside-car controller', () => {
  const cases = fixtures.cases.filter((_, index) => index % 5 === 0);
  assert.equal(cases.length, 144);
  for (const f of cases) {
    assert.deepEqual(f.expected, []);
    assert.deepEqual(nativeTrafficRelocationRequests(f.player, f.registry, f.options), []);
  }
});
