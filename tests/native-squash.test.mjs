import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeSquash} from '../source/simulation/native-squash.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/squash-fixtures.json',import.meta.url)));
const config=JSON.parse(readFileSync(new URL('../public/assets/config.json',import.meta.url)));

test('720 original squash activation, timers, aliased shake matrices and rebound frames',()=>{
  for(const trace of fixtures.traces){
    const bodies=Array.from({length:4},()=>({angles:[...fixtures.angles],matrix:[],forwardSpeed:0}));
    const controller=new NativeSquash({config,precision:trace.precision});
    bodies.forEach((body,index)=>controller.register(body,index<3
      ?{timerId:index+19}:{timerId:-1,externalMatrix:false,durationMs:1200}));
    const snapshot=()=>controller.entries.map(entry=>({
      active:entry.active,shake:entry.shake,reboundFrame:entry.reboundFrame,
      shakeFrame:entry.shakeFrame,startedMs:entry.startedMs,
      forwardSpeed:entry.body.forwardSpeed,matrix:[...entry.body.matrix],
    }));
    for(const [tick,frame]of trace.frames.entries()){
      bodies.forEach((body,index)=>Object.assign(body,{
        matrix:[...frame.input[index].matrix],forwardSpeed:frame.input[index].forwardSpeed,
      }));
      for(const id of frame.requests)controller.trigger(bodies[id],frame.nowMs);
      assert.deepEqual(snapshot(),frame.afterTrigger,`trigger precision${trace.precision} dt${trace.delta} tick${tick}`);
      controller.step(trace.delta,frame.nowMs);
      assert.deepEqual(snapshot(),frame.expected,`step precision${trace.precision} dt${trace.delta} tick${tick}`);
    }
  }
});
