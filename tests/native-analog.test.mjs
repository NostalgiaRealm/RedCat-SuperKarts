import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {updateNativeAnalogInput,nativeAnalogFromNormalized} from '../source/simulation/native-input.js';
const f=JSON.parse(readFileSync(new URL('../evidence/native/analog-fixtures.json',import.meta.url)));
test('1200 original analog-input calls match exactly, including midpoint, clamp and mirrored steering',()=>{
 for(const c of f.cases){
  const state={throttle:37,brake:19,steering:71,handbrake:true};
  updateNativeAnalogInput(state,c,c.mirrored);
  assert.deepEqual(state,c.expected);
 }
});
test('Browser proportional input preserves native two-percent steps and single pedal axis',()=>{
 const state={};
 updateNativeAnalogInput(state,nativeAnalogFromNormalized({steer:.5,throttle:.4}));
 assert.deepEqual(state,{steering:50,throttle:40,brake:0,handbrake:false});
 updateNativeAnalogInput(state,nativeAnalogFromNormalized({steer:-.2,throttle:.1,brake:.7,handbrake:true}));
 assert.deepEqual(state,{steering:-20,throttle:0,brake:60,handbrake:true});
});
