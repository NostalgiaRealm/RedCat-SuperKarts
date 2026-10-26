import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {createHash} from 'node:crypto';
import {nativeRescuePositionFree} from '../source/simulation/native-rescue.js';

const fixture = JSON.parse(readFileSync(new URL(
  '../evidence/race-completion/italy-native-rescue.json', import.meta.url)));

test('Italy occupancy fixture retains the captured race trace', () => {
  const trace = readFileSync(new URL(`../${fixture.trace}`, import.meta.url));
  assert.equal(createHash('sha256').update(trace).digest('hex'), fixture.traceSha256);
  assert.equal(fixture.cases.length, 6);
});

for (const item of fixture.cases) {
  test(`Italy return clearance matches original 0x48c170: ${item.variation}, ${item.precision}-bit`, () => {
    const player = item.bodies.find(body => body.id === 4);
    assert.ok(player);
    assert.equal(nativeRescuePositionFree(player, fixture.target, item.bodies, {
      precision: item.precision,
    }), item.expectedFree);
  });
}
