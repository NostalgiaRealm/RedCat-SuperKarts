import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nativeAIRelativeBearing, prepareNativeNormalAI } from '../source/simulation/native-ai.js';
import { NativeRandom } from '../source/simulation/native-random.js';
import { parseRacerTable } from '../source/simulation/native-tables.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-normal-fixtures.json', import.meta.url)));
const inventory = JSON.parse(readFileSync(new URL('../evidence/gameplay/inventory.json', import.meta.url)));
const tracks = Array.from({ length: 6 }, (_, i) => JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${i}.json`, import.meta.url))));
const tables = [0, 1, 2].map(i => {
  const table = inventory.binaryTables.find(table => table.source === `cars${i}.dat`);
  const bytes = new Uint8Array(table.bytes), view = new DataView(bytes.buffer);
  for (const record of table.records) record.uint32.forEach((value, j) => view.setUint32(record.offset + j * 4, value, true));
  return parseRacerTable(bytes);
});
for (const precision of [24, 53]) {
  test(`Native unsigned bearing and yaw repair ${precision}-bit`, () => {
    for (const [i, c] of fixtures.bearing.entries()) {
      if (c.precision !== precision) continue;
      const body = { ...c.body };
      assert.equal(nativeAIRelativeBearing(body, c.target, { precision }), c.expected, `bearing ${i}`);
      assert.equal(body.yaw, c.yaw, `yaw ${i}`);
    }
  });
  test(`Normal NPC handler with original tracks, occupants and shared randomness ${precision}-bit`, () => {
    for (const [i, c] of fixtures.normal.entries()) {
      if (c.precision !== precision) continue;
      const body = { ...c.body }, controls = { ...c.controls }, state = structuredClone(c.state), random = new NativeRandom(c.seed);
      prepareNativeNormalAI(tracks[c.track], body, controls, state, tables[c.preset][c.record], tables[c.preset][c.playerRecord], c.dt, random,
        { precision, efficiency: c.efficiency, occupancy: new Map([[c.nearest, c.occupants]]) });
      const { steeringTarget, speedTarget, ...comparedState } = state;
      assert.deepEqual({ body, controls, state: comparedState }, c.expected, `normal callback ${i}`);
      assert.equal(random.state, c.randomState, `random stream ${i}`);
    }
  });
}
