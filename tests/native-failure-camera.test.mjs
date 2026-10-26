import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeFailureCamera} from '../source/simulation/native-camera.js';
const f=JSON.parse(readFileSync(new URL('../evidence/native/failure-camera-fixtures.json',import.meta.url)));
test('60 original phase6 camera setups and720 post-render orbit transforms match exactly',()=>{
 for(const [i,c] of f.cases.entries()){
  const camera=new NativeFailureCamera(c.body,c.dt,c);
  for(const key of ['orbitFrames','angleIncrement'])assert.equal(camera[key],c[key],`${i}/${key}`);
  for(const key of ['position','target','up'])assert.deepEqual(camera[key],c.initial[key],`${i}/initial/${key}`);
  for(const [step,s] of c.trace.entries()){
   camera.advance();camera.step(c.body);
   assert.equal(camera.angle>>>0,s.angle);
   for(const key of ['position','target','up','localPosition'])assert.deepEqual(camera[key],s[key],`${i}/${step}/${key}`);
  }
 }
});
