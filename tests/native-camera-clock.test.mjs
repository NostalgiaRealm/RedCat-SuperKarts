import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeDeltaFilter} from '../src/simulation/clock.js';
import {nativePathDurationTicks} from '../src/scenery-paths.js';
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
  for(const c of fixtures.cases){
    if(c.precision!==24)continue;
    const filter=new NativeDeltaFilter({uptimeMs:c.uptimeMs});
    assert.equal(Math.fround(filter.initialDelta),c.initialDelta);
    c.updates.forEach((update,index)=>{
      const raw=update.rawHistory[(index+1)%4];
      assert.ok(Math.abs(filter.sample(raw)-update.delta)<=1e-8);
    });
    if(c.uptimeMs>=1000)assert.deepEqual(c.updates.slice(0,3).map(x=>x.delta),Array(3).fill(Math.fround(.1)));
  }
});
