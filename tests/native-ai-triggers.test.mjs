import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { applyNativeAITrigger, nativeAITrackMarkers, nativeAIBonusCollected, markNativeNPCWeaponHit } from '../source/simulation/native-ai-items.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/ai-trigger-fixtures.json',import.meta.url)));
const tracks=Array.from({length:6},(_,i)=>JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${i}.json`,import.meta.url))));
test('1120 original NPC marker updates retain laps, turbo, speed zones and forced-route flags',()=>{
  for(const f of fixtures.triggers){
    const state={...f.state},body={...f.body};applyNativeAITrigger(body,state,f.marker,f.options);
    assert.deepEqual(state,f.expectedState);assert.deepEqual(body,f.expectedBody);
  }
});
test('1200 original NPC marker dispatches retain sector and waypoint order across all six tracks',()=>{
  for(const f of fixtures.dispatch)assert.deepEqual(nativeAITrackMarkers(tracks[f.track],f.body),f.expected);
});
test('120 native NPC pickup callbacks store seconds even after a racer has finished',()=>{
  for(const f of fixtures.pickups){
    const state={...f.state};nativeAIBonusCollected(state,f.now);assert.deepEqual(state,f.expectedState);
  }
});
test('120 original NPC hit markers preserve the first timestamp and ignore finished racers',()=>{
  for(const f of fixtures.hitMarkers){
    const state={...f.state};markNativeNPCWeaponHit(state,f.now);assert.deepEqual(state,f.expectedState);
  }
});
