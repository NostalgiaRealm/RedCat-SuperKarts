import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { prepareNativeChaseAI } from '../source/simulation/native-ai.js';
import { NativeRandom } from '../source/simulation/native-random.js';
import { parseRacerTable } from '../source/simulation/native-tables.js';

const json = path => JSON.parse(readFileSync(new URL(`../${path}`, import.meta.url)));
const tracks = Array.from({ length: 6 }, (_, i) => json(`public/assets/tracks/etappe${i}.json`));
const tables = [0, 1, 2].map(i => parseRacerTable(readFileSync(new URL(`../public/assets/racer-tables/cars${i}.dat`, import.meta.url))));

for (const mode of [1, 2]) for (const precision of [24, 53]) {
  test(`Native NPC state${mode} full handler ${precision}-bit`, () => {
    const fixtures = json(`evidence/native/ai-mode${mode}-fixtures.json`);
    let count = 0;
    for (const [i, c] of fixtures.normal.entries()) {
      if (c.precision !== precision) continue;
      count++;
      const body = { ...c.body }, controls = { ...c.controls }, state = structuredClone(c.state), random = new NativeRandom(c.seed);
      prepareNativeChaseAI(tracks[c.track], body, controls, state,
        tables[c.preset][c.record], tables[c.preset][c.playerRecord], c.dt, random,
        { precision, player: c.player, occupancy: new Map([[c.nearest, c.occupants]]) });
      const { steeringTarget, speedTarget, ...comparedState } = state;
      assert.deepEqual({ body, controls, state: comparedState }, c.expected, `mode${mode} callback ${i}`);
      assert.equal(random.state, c.randomState, `random stream ${i}`);
    }
    assert.equal(count, 180);
  });
}
