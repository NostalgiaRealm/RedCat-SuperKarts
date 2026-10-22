import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { prepareNativeAIFinished } from '../src/simulation/native-ai.js';
import { recordNativeNPCFinish } from '../src/simulation/native-ai-items.js';
import { NativeRandom } from '../src/simulation/native-random.js';
import { parseRacerTable } from '../src/simulation/native-tables.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/ai-finish-fixtures.json',import.meta.url)));
const tables=Array.from({length:3},(_,i)=>parseRacerTable(new Uint8Array(readFileSync(new URL(`../public/assets/racer-tables/cars${i}.dat`,import.meta.url)))));
test('360 original finished-NPC movement updates match with all three racer tables at both precisions',()=>{
  for(const [i,f] of fixtures.movement.entries()){
    const body={...f.body},state={...f.state},controls={...f.controls},random=new NativeRandom(f.seed);
    prepareNativeAIFinished(body,controls,state,tables[f.preset][f.record],tables[f.preset][f.playerRecord],f.dt,random,{
      precision:f.precision,sampleRouteHeight:()=>f.height,lowSpeedTurn:true,reverseTurn:true,
    });
    assert.deepEqual({body,state,controls},f.expected,`finished movement${i}`);assert.equal(random.state,f.randomState);
  }
});
test('120 original NPC finish records read and pause the correct timers and preserve object-index matching',()=>{
  for(const f of fixtures.timers){
    const actors=structuredClone(f.opponents),calls=[];
    recordNativeNPCFinish(f.objectId,actors,i=>{calls.push(['read',i]);return f.timerValues[i-9];},
      i=>calls.push(['pause',i]));
    assert.deepEqual(actors,f.expected);assert.deepEqual(calls,f.calls);
  }
});
