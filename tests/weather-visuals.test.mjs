import test from 'node:test';
import assert from 'node:assert/strict';
import * as THREE from 'three';
import {WeatherVisuals,SkidmarkVisuals,ExplosionVisuals} from '../source/race-visuals.js';
import {NativeWeather} from '../source/simulation/native-weather.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {NativeSkidmarks} from '../source/simulation/native-skidmarks.js';
import {NativeExplosions} from '../source/simulation/native-explosions.js';
import fs from 'node:fs';
const manifest=JSON.parse(fs.readFileSync(new URL('../public/assets/manifest.json',import.meta.url)));
const viewer=()=>({camera:new THREE.PerspectiveCamera(),scene:new THREE.Scene(),group:new THREE.Group(),
  texture:async()=>new THREE.Texture()});

test('native weather vertices remain camera-relative with the original depth and blend state',async()=>{
  const view=viewer(),weather=new NativeWeather({kind:'rain',count:12,random:new NativeRandom(3)});
  weather.step(.025,[0,0,30]);
  const visual=new WeatherVisuals(view,weather);
  await visual.load(manifest);visual.capture(weather.capture());
  const mesh=visual.mesh,frame=weather.capture()[0];
  assert.deepEqual(Array.from(mesh.geometry.attributes.position.array.slice(0,18)),frame.vertices);
  assert.deepEqual(Array.from(mesh.geometry.attributes.uv.array.slice(0,12)),frame.uv);
  assert.equal(mesh.geometry.drawRange.count,72);
  assert.equal(mesh.material.depthTest,true);assert.equal(mesh.material.depthWrite,false);
  assert.equal(mesh.material.blendSrc,THREE.SrcAlphaFactor);assert.equal(mesh.material.blendDst,THREE.OneFactor);
  assert.equal(mesh.material.side,THREE.FrontSide);
  assert.equal(mesh.parent,view.camera);
  view.camera.position.set(100,200,300);view.camera.rotation.set(.1,.3,.2);
  view.scene.updateMatrixWorld(true);
  const local=new THREE.Vector3(...frame.vertices.slice(0,3));
  const transformed=local.clone().applyMatrix4(mesh.matrixWorld).applyMatrix4(view.camera.matrixWorldInverse);
  assert.ok(transformed.distanceTo(new THREE.Vector3(local.x,local.y,-local.z))<1e-10);
  visual.capture([]);assert.equal(mesh.visible,false);
  visual.dispose();assert.equal(mesh.parent,null);
});

test('skidmark triangle lists preserve original strip winding, colors and inverse-alpha fading',async()=>{
  const view=viewer(),controller=new NativeSkidmarks(),visual=new SkidmarkVisuals(view);
  await visual.load(manifest);
  const input={deltaSeconds:.025,slipMagnitude:8,playerContact:true,
    matrix:[1,0,0,0,1,0,0,0,1],position:[0,0,0],wheelOffsets:[[1,0,1],[-1,0,1],[1,0,-1],[-1,0,-1]]};
  controller.emit(input);controller.emit({...input,position:[0,0,1]});
  const frames=controller.capture();visual.capture(frames);
  const mesh=visual.meshes[0];
  assert.equal(mesh.geometry.drawRange.count,6);
  assert.deepEqual(Array.from(mesh.geometry.index.array.slice(0,6)),[0,1,2,2,1,3]);
  assert.deepEqual(Array.from(mesh.geometry.attributes.position.array.slice(0,12)),frames[0].sides[0].flatMap(vertex=>vertex.position));
  assert.equal(mesh.material.blendSrc,THREE.OneMinusSrcAlphaFactor);
  assert.equal(mesh.material.blendDst,THREE.SrcAlphaFactor);
  assert.equal(mesh.material.depthWrite,true);
  assert.equal(mesh.geometry.attributes.color.array[3],frames[0].sides[0][0].argb>>>24);
  visual.capture([]);assert.ok(visual.meshes.every(mesh=>!mesh.visible));
});

test('rocket rings preserve native list/strip order and retire their owned geometry',async()=>{
  const view=viewer(),controller=new NativeExplosions({random:new NativeRandom(4)});
  controller.add({position:[10,20,30]});controller.add({position:[40,50,60]});
  controller.step(.025);
  const visual=new ExplosionVisuals(view);await visual.load(manifest);
  const frames=controller.capture();visual.capture(frames);
  assert.equal(frames[0].id,1);
  const mesh=visual.meshes.get(1);
  assert.deepEqual(Array.from(mesh.geometry.attributes.position.array),frames[0].vertices);
  assert.deepEqual(Array.from(mesh.geometry.index.array.slice(0,6)),[0,1,3,3,1,4]);
  assert.equal(mesh.material.depthWrite,true);assert.equal(mesh.material.depthTest,true);
  assert.equal(mesh.material.blendDst,THREE.OneFactor);
  assert.ok(mesh.renderOrder<visual.meshes.get(0).renderOrder);
  let disposed=false;mesh.geometry.addEventListener('dispose',()=>disposed=true);
  visual.capture([]);assert.equal(disposed,true);assert.equal(visual.meshes.size,0);
  visual.dispose();
});
