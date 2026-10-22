import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { prepareNativeForcedRouteAI } from '../src/simulation/native-ai.js';
import { NativeRandom } from '../src/simulation/native-random.js';
import { parseRacerTable } from '../src/simulation/native-tables.js';
const json = path => JSON.parse(readFileSync(new URL(`../${path}`, import.meta.url)));
const fixtures = json('evidence/native/ai-mode27-fixtures.json');
const tracks = Array.from({ length: 6 }, (_, i) => {
  const track = json(`public/assets/tracks/etappe${i}.json`);
  for (const node of track.drive) node.unknown[1] = fixtures.markerOverride;
  return track;
});
const tables = [0, 1, 2].map(i => parseRacerTable(readFileSync(new URL(`../public/assets/racer-tables/cars${i}.dat`, import.meta.url))));

for (const precision of [24, 53]) test(`Native dormant route state27 with explicit synthetic marker66, ${precision}-bit`, () => {
  let count = 0;
  for (const [i, c] of fixtures.normal.entries()) {
    if (c.precision !== precision) continue;
    count++;
    const body = { ...c.body }, controls = { ...c.controls }, state = structuredClone(c.state), random = new NativeRandom(c.seed);
    prepareNativeForcedRouteAI(tracks[c.track], body, controls, state,
      tables[c.preset][c.record], tables[c.preset][c.playerRecord], c.dt, random,
      { precision, efficiency: c.efficiency });
    assert.deepEqual({ body, controls, state }, c.expected, `forced route ${i}`);
    assert.equal(random.state, c.randomState);
  }
  assert.equal(count, 180);
});
