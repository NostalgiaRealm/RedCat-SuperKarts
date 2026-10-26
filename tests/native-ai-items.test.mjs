import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nativeAIPositionBehind, nativeAINearestShooterTarget, nativeAIItemGuard,
  nativeAICatchupGuard, updateNativeAICatchupState, prepareNativeAIFireState } from '../source/simulation/native-ai-items.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/ai-item-fixtures.json',import.meta.url)));
const tracks=Array.from({length:6},(_,i)=>JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${i}.json`,import.meta.url))));

test('720 original NPC graph-facing and weapon-target searches match across all six tracks',()=>{
  for(const f of fixtures.geometry){
    const track=tracks[f.track],body={...f.racers[0]};
    assert.equal(nativeAIPositionBehind(track,body,track.drive[f.racers[4].waypoint].position,f),f.behind);
    const q=nativeAINearestShooterTarget(track,body,f.racers,f);
    assert.equal(q.target?.id??-1,f.nearest);assert.equal(q.distance,f.distance);
  }
});
test('720 complete original NPC weapon decisions retain timers, targets and the shared dropper counter',()=>{
  for(const f of fixtures.decisions){
    const state={...f.state},shared={...f.shared};
    const result=nativeAIItemGuard(tracks[f.track],{...f.racers[0]},state,f.owned,{
      racers:f.racers,player:f.racers[4],rank:f.rank,now:f.now,playerProtected:f.protected,
      reactionMs:f.reactionMs,shared,precision:f.precision,
    });
    assert.equal(result,f.expected);assert.deepEqual(state,f.expectedState);assert.equal(shared.dropperCounter,f.counter);
  }
});
test('720 original NPC catch-up guards retain integer-millisecond truncation and state entry',()=>{
  for(const f of fixtures.catchup){
    const state={...f.state},result=nativeAICatchupGuard(state,f);
    assert.equal(Boolean(result),f.expected);
    assert.equal(Boolean(result?.announce),f.announce);
    assert.deepEqual(state,f.expectedState);
  }
});
test('720 original catch-up duration updates preserve strict reaction deadlines and final frame',()=>{
  for(const f of fixtures.duration){
    const state={...f.state};assert.equal(updateNativeAICatchupState(state,f.dt,f),f.expected);
    assert.deepEqual(state,f.expectedState);
  }
});
test('60 original fire-state handlers fire once, reset, then prepare normal motion in order',()=>{
  for(const f of fixtures.fire){
    const state={mode:26,reactionMode:26,priorities:[2,1,0]},calls=[];
    prepareNativeAIFireState(state,()=>calls.push('fire'),()=>calls.push('normal'));
    assert.deepEqual(calls,f.calls);assert.deepEqual(state,f.state);
  }
});
