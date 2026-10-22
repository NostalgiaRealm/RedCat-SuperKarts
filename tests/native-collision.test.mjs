import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {applyNativeRailContact} from '../src/simulation/native-collision.js';
const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/collision-fixtures.json',import.meta.url)));
for(const precision of [24,53]) test(`Native rail contact response ${precision}-bit`,()=>{
 for(const [i,c] of fixtures.cases.entries()){
  if(c.precision!==precision)continue;
  const state={...c.state};const result=applyNativeRailContact(state,c.contact,{precision});
  for(const [k,v]of Object.entries(c.expected)) assert.equal(k==='impulse'?result.impulse:state[k],v,`case${i} ${k}`);
 }
});
import {nativePointRectangleSweep,nativeRectangleSweep} from '../src/simulation/native-collision.js';
const sweeps=JSON.parse(readFileSync(new URL('../evidence/native/sweep-fixtures.json',import.meta.url)));
for(const precision of [24,53]){
 test(`Native point sweep ${precision}-bit`,()=>{
  for(const [i,c]of sweeps.points.entries()){
   if(c.precision!==precision)continue;
   const a=nativePointRectangleSweep(c.start,c.end,c.bounds,{precision});
   assert.equal(a.fraction,c.fraction,`case${i} fraction`);assert.equal(a.edge,c.edge,`case${i} edge`);
  }
 });
 test(`Native rectangle sweep ${precision}-bit`,()=>{
  for(const [i,c]of sweeps.rectangles.entries()){
   if(c.precision!==precision)continue;
   const a=nativeRectangleSweep(c.obstacle,c.moving,c.movement,{precision});
   assert.equal(a.fraction,c.fraction,`case${i} fraction`);assert.equal(a.edge,c.edge,`case${i} edge`);
  }
 });
}
import {NativeRailCollision} from '../src/simulation/native-collision.js';
const rails=JSON.parse(readFileSync(new URL('../evidence/native/rail-fixtures.json',import.meta.url)));
for(const precision of [24,53])test(`Native composed rail sweep ${precision}-bit`,()=>{
 for(const [i,c]of rails.cases.entries()){
  if(c.precision!==precision)continue;
  const collider=new NativeRailCollision({collision:[],route:[{collisionIndices:[0,1]}]},c.bounds,{precision});
  collider.rails=c.rails;
  const a=collider.sample(c.body,c.dt),e=c.expected;
  assert.equal(a.fraction,e.fraction,`case${i} fraction`);assert.equal(a.stopYaw,e.stopYaw,`case${i} stopYaw`);
  assert.deepEqual(a.contact,e.contact,`case${i} contact`);assert.deepEqual(a.velocityOverride??null,e.velocityOverride,`case${i} override`);
 }
});
import {nativeRailRectangle} from '../src/simulation/native-collision.js';
const railLoads=JSON.parse(readFileSync(new URL('../evidence/native/rail-loader-fixtures.json',import.meta.url)));
for(const precision of[24,53])test(`Native CMP rail loader ${precision}-bit`,()=>{
 for(const[i,c]of railLoads.cases.entries()){
  if(c.precision!==precision)continue;
  const a=nativeRailRectangle(c.record,{precision});
  assert.equal(a.angle,c.yaw>0?Math.ceil(c.yaw):Math.floor(c.yaw),`case${i} angle`);
  assert.equal(a.maxZ,Math.fround(c.length+1),`case${i} length`);
 }
});
