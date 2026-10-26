import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import * as THREE from 'three';
import {presentNativeRaceCamera} from '../source/render-transforms.js';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {nativeAnalogFromNormalized} from '../source/simulation/native-input.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));
const tracks=Array.from({length:6},(_,i)=>JSON.parse(read(`tracks/etappe${i}.json`)));
function create(track){
  const random=new NativeRandom(0);
  const sim=new RaceSimulation({config,manifest,cars,track,random,character:0,difficulty:1,
    physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat')});
  random.seed(0);return sim;
}

test('shipped MAPS flags and executed native projection calls identify the same mirrored countries',()=>{
  const evidence=JSON.parse(fs.readFileSync(new URL('../evidence/full-race-matrix/native-track-mirror.json',import.meta.url)));
  assert.equal(evidence.cases.length,12);
  assert.deepEqual(tracks.map(track=>track.mirrored),[false,false,true,true,false,true]);
  for(const item of evidence.cases){
    assert.equal(Number(config['track.ini'].maps[item.track].split(',')[14]),item.authoredFlag);
    assert.equal(Number(tracks[item.track].mirrored),item.authoredFlag);
    assert.deepEqual(item.output,item.input.map((value,index)=>item.flag===1&&[0,4,8].includes(index)?-value:value));
    assert.equal(item.calls[0].api,item.flag===1?'SetRenderState':'SetTransform');
    if(item.flag===1)assert.deepEqual(item.calls[0],{api:'SetRenderState',state:22,value:2});
  }
});

test('world and camera reflection match a horizontal projection flip at arbitrary camera roll and interpolation',()=>{
  const ordinaryScene=new THREE.Group(),mirroredScene=new THREE.Group();
  const ordinaryRoot=new THREE.Scene(),mirroredRoot=new THREE.Scene();
  const ordinaryCamera=new THREE.PerspectiveCamera(60,4/3,1.5,12500);
  const mirroredCamera=ordinaryCamera.clone();
  ordinaryRoot.add(ordinaryScene,ordinaryCamera);mirroredRoot.add(mirroredScene,mirroredCamera);
  const ordinaryWeather=new THREE.Object3D(),mirroredWeather=new THREE.Object3D();
  ordinaryWeather.scale.z=mirroredWeather.scale.z=-1;
  ordinaryCamera.add(ordinaryWeather);mirroredCamera.add(mirroredWeather);
  for(let i=0;i<12;i++){
    const angle=i*.37;
    const previous={position:new THREE.Vector3(50+i*7,80,130),
      target:new THREE.Vector3(20,15+i,0),up:new THREE.Vector3(Math.sin(angle),Math.cos(angle),.15)};
    const current={position:previous.position.clone().add(new THREE.Vector3(20,-10,15)),
      target:previous.target.clone().add(new THREE.Vector3(15,20,-40)),up:previous.up.clone()};
    const saved=JSON.stringify([previous,current]);
    for(const alpha of [0,.25,.75,1]){
      presentNativeRaceCamera(ordinaryScene,ordinaryCamera,previous,current,alpha,false);
      presentNativeRaceCamera(mirroredScene,mirroredCamera,previous,current,alpha,true);
      ordinaryRoot.updateMatrixWorld();mirroredRoot.updateMatrixWorld();
      for(const position of [[0,0,0],[50,30,10],[-100,75,-15]]){
        const a=new THREE.Vector3(...position).applyMatrix4(ordinaryScene.matrixWorld).project(ordinaryCamera);
        const b=new THREE.Vector3(...position).applyMatrix4(mirroredScene.matrixWorld).project(mirroredCamera);
        assert.ok(Math.abs(a.x+b.x)<1e-11);
        assert.ok(Math.abs(a.y-b.y)<1e-11);
        assert.ok(Math.abs(a.z-b.z)<1e-11);
      }
      const weatherA=new THREE.Vector3(10,20,100).applyMatrix4(ordinaryWeather.matrixWorld).project(ordinaryCamera);
      const weatherB=new THREE.Vector3(10,20,100).applyMatrix4(mirroredWeather.matrixWorld).project(mirroredCamera);
      assert.ok(Math.abs(weatherA.x+weatherB.x)<1e-11);
      assert.ok(Math.abs(weatherA.y-weatherB.y)<1e-11);
      assert.ok(Math.abs(weatherA.z-weatherB.z)<1e-11);
      assert.equal(mirroredRoot.scale.x,1);
      assert.equal(mirroredScene.matrixWorld.determinant(),-1);
      assert.equal(JSON.stringify([previous,current]),saved,'presentation must not mutate the simulation camera');
    }
  }
  presentNativeRaceCamera(mirroredScene,mirroredCamera,
    {position:new THREE.Vector3(0,20,100),target:new THREE.Vector3(),up:new THREE.Vector3(0,1,0)},
    {position:new THREE.Vector3(0,20,100),target:new THREE.Vector3(),up:new THREE.Vector3(0,1,0)},0,false);
  assert.equal(mirroredScene.scale.x,1,'loading an ordinary track removes the reflection');
});

test('browser camera parent stays unmirrored while world and camera-attached effects reflect',()=>{
  const scene=new THREE.Scene(),world=new THREE.Group();
  const camera=new THREE.PerspectiveCamera(60,4/3,1.5,12500);
  const effect=new THREE.Group();effect.scale.z=-1;
  scene.add(world,camera);camera.add(effect);
  const pose={position:new THREE.Vector3(50,80,130),target:new THREE.Vector3(20,15,0),
    up:new THREE.Vector3(.25,1,.15)};
  function capture(mirrored){
    presentNativeRaceCamera(world,camera,pose,pose,0,mirrored);
    scene.updateMatrixWorld(true);
    return {
      world:new THREE.Vector3(10,30,0).applyMatrix4(world.matrixWorld).project(camera),
      effect:new THREE.Vector3(.3,.4,2).applyMatrix4(effect.matrixWorld).project(camera),
    };
  }
  const ordinary=capture(false),mirrored=capture(true);
  for(const key of ['world','effect']){
    assert.ok(Math.abs(ordinary[key].x+mirrored[key].x)<1e-11,key);
    assert.ok(Math.abs(ordinary[key].y-mirrored[key].y)<1e-11,key);
    assert.ok(Math.abs(ordinary[key].z-mirrored[key].z)<1e-11,key);
  }
  assert.equal(scene.scale.x,1);
  assert.equal(world.scale.x,-1);
  assert.deepEqual(effect.scale.toArray(),[-1,1,-1]);
  capture(false);
  assert.deepEqual(effect.scale.toArray(),[1,1,-1]);
});

test('assembled native mirroring reverses input without changing road selection or physical trajectories',()=>{
  for(const track of tracks){
    const actual=create(track),reference=create({...track,mirrored:false});
    assert.equal(actual.motion.mirrored,track.mirrored);
    assert.deepEqual(actual.routeOptions,reference.routeOptions);
    assert.deepEqual(actual.setup,reference.setup);
    for(let now=25;now<=3000;now+=25){
      const steer=now<1250?.01:now<1500?-.15:now<1750?.3:0;
      const analog={throttle:1,brake:0,steer};
      const x=nativeAnalogFromNormalized(analog).x;
      const reflected={...analog,steer:(100-x)/50-1};
      reference.step({...analog,analog},.025,now);
      const controls=track.mirrored?reflected:analog;
      actual.step({...controls,analog:controls},.025,now);
      assert.deepEqual(actual.motion.controls,reference.motion.controls);
      assert.deepEqual(actual.actors.map(actor=>actor.body.position),reference.actors.map(actor=>actor.body.position));
      assert.deepEqual(actual.race.snapshot(),reference.race.snapshot());
    }
    const buttons=create(track);
    buttons.step({throttle:0,brake:0,steer:-1,handbrake:0},.025,25);
    buttons.step({throttle:0,brake:0,steer:-1,handbrake:0},.025,50);
    assert.equal(Math.sign(buttons.motion.controls.steering),track.mirrored?1:-1);
  }
});
