import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {SCENARIOS,trace,firstDifference} from '../tools/race-trace.mjs';

// Reference generated before the performance work: a race must keep every bit
// of its karts, camera, scenery, combat, effects, sounds and random stream.
const reference=JSON.parse(fs.readFileSync(new URL('./fixtures/race-trace.json',import.meta.url)));
SCENARIOS.forEach((scenario,index)=>{
  test(`race stays bit-exact: ${scenario.name}`,()=>{
    const result=trace(scenario,{ticks:reference.ticks,every:reference.every});
    assert.deepEqual(firstDifference(reference.results[index],result),null);
    assert.deepEqual(result.final,reference.results[index].final);
  });
});
