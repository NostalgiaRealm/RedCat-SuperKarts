import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeDeltaFilter} from '../source/simulation/clock.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/timing-fixtures.json',import.meta.url)));
for(const trace of fixtures.traces){
  test(`original x86 clock: ${trace.clockAPI} ${trace.name}`,()=>{
    const filter=new NativeDeltaFilter();
    for(const [i,sample] of trace.samples.entries()){
      const actual=filter.sample(sample.nativeRawDelta);
      assert.equal(actual,sample.nativeReturnedDelta,`${i}: ${actual} vs original ${sample.nativeReturnedDelta}`);
    }
    assert.equal(trace.reset.deltaField,0);
    // 0x48f590 primes the history with the float 0.1 (0x3dcccccd).
    assert.equal(trace.reset.returnedDelta,Math.fround(.1));
    for(const value of trace.reset.history)assert.equal(value,Math.fround(.1));
  });
}
