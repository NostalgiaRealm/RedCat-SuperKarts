import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nativeAIHeadingError, updateNativeAIControls, updateNativeAISpeed, updateNativeAISteering, updateNativeAIRacerMotion } from '../source/simulation/native-ai.js';
import { NativeRandom } from '../source/simulation/native-random.js';
import { parseRacerTable } from '../source/simulation/native-tables.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/ai-fixtures.json', import.meta.url)));
const inventory = JSON.parse(readFileSync(new URL('../evidence/gameplay/inventory.json', import.meta.url)));
const tables = [0, 1, 2].map(i => {
  const table = inventory.binaryTables.find(table => table.source === `cars${i}.dat`);
  const bytes = new Uint8Array(table.bytes), view = new DataView(bytes.buffer);
  for (const record of table.records) record.uint32.forEach((value, j) => view.setUint32(record.offset + j * 4, value, true));
  return parseRacerTable(bytes);
});
for (const precision of [24, 53]) {
  test(`Native NPC steering and throttle controls ${precision}-bit`, () => {
    for (const [i, c] of fixtures.controls.entries()) {
      if (c.precision !== precision) continue;
      assert.equal(nativeAIHeadingError(c.body, c.target, { precision }), c.heading, `heading case ${i}`);
      assert.deepEqual(updateNativeAIControls({ ...c.body }, { ...c.controls }, c.target, c.target, c.dt, { precision }), c.expected, `controls case ${i}`);
    }
  });
  test(`Native NPC longitudinal speed ${precision}-bit`, () => {
    for (const [i, c] of fixtures.speed.entries()) {
      if (c.precision !== precision) continue;
      const body = { ...c.body }, state = { ...c.state };
      updateNativeAISpeed(body, c.controls, state, tables[c.preset][c.record], tables[c.preset][c.playerRecord], c.dt, { precision });
      assert.deepEqual({ body, gear: state.gear, reverseLatch: state.reverseLatch }, c.expected, `speed case ${i}`);
    }
  });
  test(`Native NPC lateral dynamics ${precision}-bit`, () => {
    for (const [i, c] of fixtures.steering.entries()) {
      if (c.options.precision !== precision) continue;
      const body = { ...c.body }, state = { ...c.state };
      updateNativeAISteering(body, c.controls, state, tables[c.preset][c.record], tables[c.preset][c.playerRecord], c.dt, c.options);
      assert.deepEqual({ body, state }, c.expected, `steering case ${i}`);
    }
  });
  test(`Composed native racer preparation ${precision}-bit`, () => {
    for (const [i, c] of fixtures.motion.entries()) {
      if (c.options.precision !== precision) continue;
      const body = { ...c.body }, state = { ...c.state }, controls = { ...c.controls }, random = new NativeRandom(c.seed);
      updateNativeAIRacerMotion(body, controls, state, tables[c.preset][c.record], tables[c.preset][c.playerRecord], c.target, c.dt, random, c.options);
      assert.deepEqual({ body, state, controls }, c.expected, `motion case ${i}`);
      assert.equal(random.state, c.randomState, `random case ${i}`);
    }
  });
}
