import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nearestNativeAIWaypoint, searchNativeAIPath } from '../src/simulation/native-ai.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-path-fixtures.json', import.meta.url)));
for (const item of fixtures.tracks) test(`Native AI waypoint search track ${item.id}`, () => {
  const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${item.id}.json`, import.meta.url)));
  for (const [i, fixture] of item.cases.entries()) {
    assert.equal(nearestNativeAIWaypoint(track, fixture), fixture.nearest, `nearest ${i}`);
    const actual = searchNativeAIPath(track, fixture.nearest, { ...fixture, occupied: new Set(fixture.occupied) });
    assert.deepEqual(actual, fixture.expected, `search ${i}`);
  }
});
