import test from 'node:test';
import assert from 'node:assert/strict';
import {FrameLimiter} from '../source/frame-limit.js';

const drawn=(hz,jitter=0)=>{
  const limiter=new FrameLimiter();let count=0;
  for(let frame=0;frame<hz*10;frame++)if(limiter.due(frame*1000/hz+(frame%2?jitter:-jitter)+1000))count++;
  return count/10;
};
test('phones draw about 60 frames per second on fast displays and every frame up to 60 Hz',()=>{
  for(const hz of [30,50,60])assert.equal(drawn(hz),hz);
  assert.equal(drawn(60,1),60);
  for(const hz of [90,120,144]){const rate=drawn(hz);assert.ok(rate>=55&&rate<=61,`${hz} Hz gives ${rate}`);}
});
