import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { integrateNativeEuler, nativeTrigTable, nativeIntegrationSchedule } from '../src/simulation/native-integrator.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/integrator-fixtures.json', import.meta.url)));
for (const precision of [24,53]) {
  test(`Native ${precision}-bit trig tables match original x86 generator`, () => {
    const table = nativeTrigTable(precision), expected = fixtures[`trig${precision}`];
    for (const key of ['sin','cos']) for(let i=0;i<4096;i++) assert.equal(table[key][i], expected[key][i],`${key}[${i}]`);
  });
  test(`Original Euler fixtures, ${precision}-bit x87`, () => {
    for(const [index,c] of fixtures.cases.entries()) {
      if(c.options.precision !== precision) continue;
      const actual = integrateNativeEuler({...c.state}, c.force, c.dt, c.options);
      for (const [key,value] of Object.entries(c.expected)) assert.equal(actual[key],value,`case${index} ${key}`);
    }
  });
}
test('Native player integrates in eight subdivisions', () => {
  assert.deepEqual(nativeIntegrationSchedule(0.03125),{count:8,dt:0.00390625,kernel:'euler'});
  assert.equal(nativeIntegrationSchedule(0.03125,{player:false,flags:3}).count,1);
  assert.equal(nativeIntegrationSchedule(0.1,{player:false,flags:4}).count,8);
});
