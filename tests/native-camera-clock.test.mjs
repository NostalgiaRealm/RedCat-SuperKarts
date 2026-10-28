import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeDeltaFilter} from '../source/simulation/clock.js';
import {nativePathDurationTicks} from '../source/scenery-paths.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/camera-clock-fixtures.json',import.meta.url)));

test('original timer initialization fixes all six startup path durations before the first race update',()=>{
  const tracks=Array.from({length:6},(_,id)=>JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${id}.json`,import.meta.url))));
  for(const c of fixtures.cases){
    const original=tracks[c.track].paths.find(path=>path.type===1);
    const path={...original,durationMs:original.durationMs+1000,closed:false};
    assert.equal(nativePathDurationTicks(path,c.initialDelta,c.precision),c.durationTicks);
    if(c.uptimeMs>=1000)assert.equal(c.initialDelta,Math.fround(.1));
  }
  assert.equal(fixtures.cases.length,144);
});

test('native initialization primes history with absolute uptime, retaining three capped startup updates',()=>{
  // 0x48f3e0 stores every partial sum, so both control words give one result.
  for(const c of fixtures.cases){
    const filter=new NativeDeltaFilter({uptimeMs:c.uptimeMs});
    assert.equal(filter.initialDelta,c.initialDelta);
    c.updates.forEach((update,index)=>{
      const raw=update.rawHistory[(index+1)%4];
      assert.equal(filter.sample(raw),update.delta,`${c.precision}/${c.uptimeMs}/${index}`);
    });
    if(c.uptimeMs>=1000)assert.deepEqual(c.updates.slice(0,3).map(x=>x.delta),Array(3).fill(Math.fround(.1)));
  }
});
