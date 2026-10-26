import test from 'node:test';
import assert from 'node:assert/strict';
import {NativeEngineTimer} from '../source/simulation/clock.js';
import {createNativeInputState,updateNativeInput} from '../source/simulation/native-input.js';
import {PlayerStuckRecovery} from '../source/simulation/player-stuck-recovery.js';

test('native float cap from the real clock is accepted by digital input at startup and after stalls',()=>{
  const timer=new NativeEngineTimer({absoluteSeconds:60});
  const state=createNativeInputState();
  for(const time of [60.025,60.05,60.075,60.1,60.6]){
    const delta=timer.sampleAbsoluteSeconds(time);
    assert.doesNotThrow(()=>updateNativeInput(state,{accelerate:true,brake:true},delta));
  }
  assert.ok(state.throttle>0);assert.ok(state.brake>0);
  assert.throws(()=>updateNativeInput(state,{},.1001),RangeError);
});

test('native float cap does not silently reset soft-lock detection during slow updates',()=>{
  const detector=new PlayerStuckRecovery(),body={position:[0,0,0]},input={throttle:1};
  for(let i=0;i<79;i++)assert.equal(detector.step(body,input,Math.fround(.1)),false);
  assert.equal(detector.step(body,input,Math.fround(.1)),true);
  assert.equal(detector.step(body,input,.1001),false);
  assert.equal(detector.attemptSeconds,0);
});
