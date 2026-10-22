import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeDeltaFilter} from '../src/simulation/clock.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/timing-fixtures.json',import.meta.url)));
for(const trace of fixtures.traces){
  test(`original x86 clock: ${trace.clockAPI} ${trace.name}`,()=>{
    const filter=new NativeDeltaFilter();
    for(const [i,sample] of trace.samples.entries()){
      const actual=filter.sample(sample.nativeRawDelta);
      assert.ok(Math.abs(actual-sample.nativeReturnedDelta)<=fixtures.comparisonToleranceSeconds,
        `${i}: ${actual} vs original ${sample.nativeReturnedDelta}`);
    }
    assert.equal(trace.reset.deltaField,0);
    assert.ok(Math.abs(trace.reset.returnedDelta-0.1)<=fixtures.comparisonToleranceSeconds);
    for(const value of trace.reset.history)assert.ok(Math.abs(value-.1)<=fixtures.comparisonToleranceSeconds);
  });
}
