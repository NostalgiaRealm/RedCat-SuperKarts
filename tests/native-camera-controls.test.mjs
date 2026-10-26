import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativePlayerCamera} from '../source/simulation/native-camera.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/camera-control-fixtures.json',import.meta.url)));
function snapshot(camera){return Object.fromEntries(['position','target','up','mode','bodyVisible','positionDamping'].map(key=>[key,camera[key]]));}

test('reachable player-camera mode transitions match original positions, damping, targets and up vectors',()=>{
 for(const [i,c]of fixtures.updates.entries()){
  const camera=new NativePlayerCamera({precision:c.precision});camera.position=c.previous;
  camera.setMode(c.prior).setMode(c.mode).step(c.body);
  assert.deepEqual(snapshot(camera),c.expected,`native update ${i}`);
 }
});
test('original camera keys preserve ordering, rear-view restoration and phase gates',()=>{
 for(const [i,c]of fixtures.keys.entries()){
  const camera=new NativePlayerCamera({precision:c.precision});camera.setMode(c.prior);camera.rememberedMode=3;
  const selected=camera.handleKeys(new Set(c.keys),c.phase);
  assert.deepEqual({mode:camera.mode,rememberedMode:camera.rememberedMode,selected,
   bodyVisible:camera.bodyVisible,positionDamping:camera.positionDamping},c.expected,`native keys ${i}`);
 }
});
test('green updates the preceding camera mode once before restoring normal chase',()=>{
 for(const [i,c]of fixtures.green.entries()){
  const camera=new NativePlayerCamera({precision:c.precision});camera.position=c.previous;
  camera.setMode(c.prior).startRace(c.body);
  assert.deepEqual(snapshot(camera),c.expected,`native green ${i}`);
 }
});
