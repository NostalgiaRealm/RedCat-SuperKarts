import test from'node:test';import assert from'node:assert/strict';import{readFileSync}from'node:fs';import{NativePlayerCamera}from'../src/simulation/native-camera.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/camera-fixtures.json',import.meta.url)));
for(const precision of[24,53])test(`Native player camera ${precision}-bit`,()=>{
 for(const[i,c]of fixtures.cases.entries()){
  if(c.precision!==precision)continue;
  const camera=new NativePlayerCamera({precision});camera.position=c.previous;camera.step(c.transform);
  assert.deepEqual(camera.position,c.expected.position,`case${i} position`);assert.deepEqual(camera.target,c.expected.target,`case${i} target`);
 }
});
