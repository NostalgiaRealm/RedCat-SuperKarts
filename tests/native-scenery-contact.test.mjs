import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeSceneryPhysics, nativeSceneryRectangle, nativeScenerySlopeMatrix,
  NativeSceneryBodies} from '../source/simulation/native-scenery-contact.js';
import {NativeRailCollision} from '../source/simulation/native-collision.js';
import {createNativeTrack} from '../source/simulation/native-track.js';
import {multiplyNativeMatrices} from '../source/simulation/native-transform.js';
import {integrateNativeEuler,quantizeNativePlanarVelocity} from '../source/simulation/native-integrator.js';
import {nativeObjectCallbackRanges} from '../source/simulation/native-render.js';
import {nativeObjectCallbackCount} from '../source/spatial-audio.js';
const read = path => JSON.parse(fs.readFileSync(new URL('../'+path, import.meta.url)));
const fixtures = read('evidence/native/scenery-contact-fixtures.json');
const config = read('public/assets/config.json'), manifest = read('public/assets/manifest.json');
const exact = (actual, expected, label) => assert.ok(Object.is(actual, expected), `${label}: ${actual} != ${expected}`);

test('scenery initialization and native registration match original instructions', () => {
  for (const [i,c] of fixtures.physics.entries()) {
    const actual = nativeSceneryPhysics(c.type,c.section,{precision:c.precision});
    for (const [key,value] of Object.entries(c.expected)) assert.equal(actual[key],value,`${i} ${key}`);
    assert.equal(c.physical,1);assert.deepEqual(c.registered,[1,0]);
  }
});
test('scenery rectangles use each current mesh bound and native signed yaw conversion', () => {
  for (const c of fixtures.rectangles) {
    const rect=nativeSceneryRectangle(c.body);
    assert.equal(rect.angle,c.angle);assert.deepEqual(rect.position,c.position);
    const b=c.body.bounds;
    assert.deepEqual(c.corners,[b.minX,b.minY,b.minZ,b.maxX,b.minY,b.minZ,
      b.maxX,b.minY,b.maxZ,b.minX,b.minY,b.maxZ]);
    assert.equal(c.count,1);assert.equal(c.radius,127);
  }
});
test('continuous scenery slope orientation matches native chunk initialization', () => {
  for(const [i,c]of fixtures.slopes.entries()){
    const actual=nativeScenerySlopeMatrix(c.forward,{precision:c.precision});
    assert.deepEqual(actual,c.expected,`slope ${i}`);
  }
});
test('scenery ground pose preserves native matrix multiplication order',()=>{
  for(const [i,c] of fixtures.groundPoses.entries()){
    const slope=nativeScenerySlopeMatrix(c.forward,{precision:c.precision});
    assert.deepEqual(multiplyNativeMatrices(c.pose,slope,c.precision),c.expected,`ground pose ${i}`);
  }
});
for(const precision of [24,53])test(`physical scenery receives one Euler step per native visibility range exactly (${precision}-bit)`,()=>{
  assert.ok(fixtures.integration.some(c=>c.precision===precision));
  for(const [i,c]of fixtures.integration.entries()){
    if(c.precision!==precision)continue;
    const body={...c.state};
    quantizeNativePlanarVelocity(body,c.precision);
    const ranges=nativeObjectCallbackRanges(c.playerSector,c.visibleChunks,c.routeCount);
    const count=nativeObjectCallbackCount({alwaysUpdate:c.alwaysUpdate,sector:c.sector,ranges});
    assert.equal(count,c.calls.length,`count ${i}`);
    for(let j=0;j<count;j++)integrateNativeEuler(body,{lateralForce:0,verticalForce:0,longitudinalForce:0,torque:0},
      c.dt,{precision:c.precision});
    for(const[k,v]of Object.entries(c.expected))exact(body[k],v,`integration ${i} ${k}`);
  }
});
test('all six tracks register only authored solid shapes, in OMP order', () => {
  const expected=[[74,0],[24,2],[116,1],[14,3],[8,0],[28,0]];
  for(let id=0;id<6;id++){
    const track=read(`public/assets/tracks/etappe${id}.json`),world=createNativeTrack(track);
    const collision=new NativeRailCollision(track,manifest.meshes['auto0.d3d']?.bounds??{minX:-10,maxX:10,minZ:-20,maxZ:20});
    const scenery=new NativeSceneryBodies({track,config,manifest,world,collision});
    collision.bodies=scenery.bodies;
    assert.equal(scenery.bodies.filter(b=>b.type===5).length,expected[id][0]);
    assert.equal(scenery.bodies.filter(b=>b.type===6).length,expected[id][1]);
    assert.deepEqual(scenery.bodies.map(b=>b.placementIndex),scenery.bodies.map(b=>b.placementIndex).sort((a,b)=>a-b));
    for(const body of scenery.bodies){
      assert.ok(Object.values(body.bounds).every(Number.isFinite));
      assert.equal(body.inverseInertia,0);
      assert.equal(body.inverseMass,body.type===5?0:Math.fround(1/400));
      const candidates=collision.candidates(body.sector,{});
      const candidate=candidates.find(c=>c.body===body);
      assert.equal(candidate.minX,body.bounds.minX);assert.equal(candidate.maxZ,body.bounds.maxZ);
    }
  }
});
test('scenery collision changes both bodies; inactive obstacles are excluded',()=>{
  const track={route:[{collisionIndices:[]}],collision:[]};
  const collision=new NativeRailCollision(track,{minX:-1,maxX:1,minZ:-1,maxZ:1});
  const obstacle={bounds:{minX:-20,maxX:20,minZ:-2,maxZ:2},position:[0,0,10],yaw:0,sector:0,
    lateralSpeed:0,verticalSpeed:0,forwardSpeed:0,yawRate:0,pitchRate:0,rollRate:0,inverseMass:0,inverseInertia:0,restitution:Math.fround(.1)};
  const body={x:0,y:0,z:0,position:[0,0,0],yaw:0,sector:0,lateralSpeed:0,verticalSpeed:0,
    forwardSpeed:10,yawRate:0,pitchRate:0,rollRate:0,inverseMass:Math.fround(1/600),
    inverseInertia:.001,restitution:Math.fround(.2)};
  collision.bodies=[obstacle,body];
  const result=collision.sweep(body,.1);assert.ok(result.fraction<1);assert.ok(result.contact);
  collision.resolve(body,result.contact);assert.ok(body.forwardSpeed<0);assert.equal(obstacle.forwardSpeed,0);
  obstacle.active=false;assert.equal(collision.sweep(body,.1).contact,null);
});
test('held authored paths preserve collision displacement and update sector independently',()=>{
  const track=read('public/assets/tracks/etappe1.json'),world=createNativeTrack(track);
  const scenery=new NativeSceneryBodies({track,config,manifest,world,collision:{}});
  const body=scenery.bodies.find(b=>b.type===6),index=body.placementIndex;
  const state={position:[1,2,3],yaw:100,sector:5,visible:true,poseRevision:1,updateRevision:1};
  const paths={objects:new Map([[index,state]])};
  scenery.syncPaths(paths);assert.deepEqual(body.position,[1,2,3]);
  body.x=50;body.forwardSpeed=12;
  state.updateRevision++;state.sector=6;
  scenery.syncPaths(paths);assert.equal(body.x,50);assert.equal(body.sector,6);assert.equal(body.forwardSpeed,12);
  state.visible=false;scenery.syncPaths(paths);assert.equal(body.active,false);
  state.visible=true;scenery.syncPaths(paths);assert.equal(body.active,true);
  assert.equal(body.x,50);
});
test('headless scenery animation applies current native-frame collision bounds',()=>{
  const track=read('public/assets/tracks/etappe1.json'),world=createNativeTrack(track);
  const scenery=new NativeSceneryBodies({track,config,manifest,world,collision:{}});
  const body=scenery.bodies.find(b=>b.mesh==='dusb0000.d3d');
  scenery.prepare(66,[[0,track.route.length-1]]);
  assert.equal(body.mesh,'dusb0000.d3d');
  scenery.prepare(67,[[0,track.route.length-1]]);
  assert.equal(body.mesh,'dusb0001.d3d');
  assert.deepEqual(body.bounds,manifest.meshes['dusb0001.d3d'].bounds);
  body.active=false;
  scenery.prepare(200,[[0,track.route.length-1]]);
  assert.equal(body.mesh,'dusb0001.d3d');
});
