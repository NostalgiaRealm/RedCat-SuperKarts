import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeStartCountdown,nativeCountdownY} from '../src/simulation/native-countdown.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/countdown-fixtures.json',import.meta.url)));
for(const trace of fixtures.traces)test(`Original countdown ${trace.precision}-bit ${trace.name}`,()=>{
  const countdown=new NativeStartCountdown({precision:trace.precision});
  for(const [index,step]of trace.steps.entries()){
    assert.deepEqual(countdown.step(step.delta),step.expected,`update ${index}`);
  }
});
test('Original countdown slide positions retain native overshoot',()=>{
  for(const entry of fixtures.slides)assert.equal(nativeCountdownY(entry.elapsed,entry),entry.expectedY);
});
