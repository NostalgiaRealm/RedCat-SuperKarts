import test from 'node:test';
import assert from 'node:assert/strict';
import * as THREE from 'three';
import fs from 'node:fs';
import {KartVisual} from '../source/race-visuals.js';
import {advanceNativeKartColor} from '../source/simulation/native-kart-color.js';
const load=name=>JSON.parse(fs.readFileSync(new URL(`../public/assets/${name}.json`,import.meta.url)));
const config=load('config'),manifest=load('manifest');

test('kart color replaces source vertex colors per actor and preserves frame positions',async()=>{
  const sources=new Map();
  const model=async file=>{
    if(!sources.has(file)){
      const geometry=new THREE.BufferGeometry();
      geometry.setAttribute('position',new THREE.Float32BufferAttribute([0,0,0,1,0,0,0,1,0],3));
      geometry.setAttribute('color',new THREE.Uint8BufferAttribute([255,0,0,255,0,255,0,255,0,0,255,255],4,true));
      sources.set(file,geometry);
    }
    return sources.get(file);
  };
  const actor={body:{position:[1,0,1],sector:0,forwardSpeed:10,matrix:[1,0,0,0,1,0,0,0,1]}};
  const viewer={track:{id:0,placements:[]},group:new THREE.Group(),model,motion:actor,opponents:[],
    mesh:async spec=>new THREE.Mesh(await model(spec.mesh),new THREE.MeshBasicMaterial())};
  const visual=await KartVisual.load(viewer,config,manifest,0,0,actor);
  const other=await KartVisual.load(viewer,config,manifest,0,0,actor);
  const plane={vertices:[[0,0,0],[0,0,10],[10,0,0]],normal:[0,1,0],diffuse:0x123456};
  const world={sectors:[{triangles:{road:[plane],land:[],extra:[]}}]};
  const expected=advanceNativeKartColor(0xffffffff,plane.diffuse,10,.025,[0,0,0]);
  visual.captureColor(world,.025);
  assert.equal(visual.diffuse,expected.diffuse);assert.equal(visual.renderDiffuse,expected.renderDiffuse);
  const rgba=[expected.renderDiffuse>>>16&255,expected.renderDiffuse>>>8&255,expected.renderDiffuse&255,255];
  for(const mesh of [visual.body,...visual.wheels,visual.driver])
    assert.deepEqual(Array.from(mesh.geometry.attributes.color.array),[...rgba,...rgba,...rgba]);
  assert.ok(other.body.geometry.attributes.color.array.every(value=>value===255));
  for(const geometry of sources.values())
    assert.deepEqual(Array.from(geometry.attributes.color.array),[255,0,0,255,0,255,0,255,0,0,255,255]);
  visual.advanceAnimation(60025);
  assert.deepEqual(Array.from(visual.driver.geometry.attributes.position.array),
    Array.from(visual.frames.get(visual.animation.displayedFrame.file).attributes.position.array));
  const count=visual.colorGeometries.size;
  let disposed=0;for(const geometry of visual.colorGeometries)geometry.addEventListener('dispose',()=>disposed++);
  visual.dispose();assert.equal(disposed,count);assert.equal(visual.group.parent,null);
  other.dispose();
});
