import test from 'node:test';
import assert from 'node:assert/strict';
import * as THREE from 'three';
import fs from 'node:fs';
import {StreamVisuals} from '../source/race-visuals.js';
import {NativeStreams} from '../source/simulation/native-streams.js';
const manifest=JSON.parse(fs.readFileSync(new URL('../public/assets/manifest.json',import.meta.url)));
test('stream renderer copies native strips once with additive depth-writing draw order',async()=>{
  const body={position:[0,20,0],matrix:[1,0,0,0,1,0,0,0,1]};
  const streams=new NativeStreams({playerBody:body});streams.racer(body,0,3);
  for(let tick=0;tick<8;tick++){
    body.position[2]+=5;streams.step(.025,{playerSpeedKmh:100,playerThrottle:100});streams.draw();
  }
  const frames=streams.draw(),viewer={group:new THREE.Group(),texture:async()=>new THREE.Texture()};
  const visual=new StreamVisuals(viewer);await visual.load(manifest);visual.capture(frames);
  assert.ok(frames.jets.length);assert.ok(frames.ribbons.length);
  for(const [meshes,packets]of [[visual.jets,frames.jets],[visual.ribbons,frames.ribbons]])
    packets.forEach((vertices,index)=>{
      const mesh=meshes[index];
      assert.deepEqual(Array.from(mesh.geometry.attributes.position.array.slice(0,vertices.length*3)),
        vertices.flatMap(vertex=>vertex.position));
      assert.deepEqual(Array.from(mesh.geometry.attributes.uv.array.slice(0,vertices.length*2)),
        vertices.flatMap(vertex=>vertex.uv));
      assert.equal(mesh.geometry.drawRange.count,(vertices.length-2)*3);
      assert.equal(mesh.material.blendSrc,THREE.OneFactor);assert.equal(mesh.material.blendDst,THREE.OneFactor);
      assert.equal(mesh.material.depthWrite,true);assert.equal(mesh.material.depthTest,true);
      assert.equal(mesh.material.side,THREE.FrontSide);
    });
  assert.ok(visual.jets.at(-1).renderOrder<visual.ribbons[0].renderOrder);
  visual.capture({jets:[],ribbons:[]});
  assert.ok([...visual.jets,...visual.ribbons].every(mesh=>!mesh.visible));
  visual.dispose();assert.equal(viewer.group.children.length,0);
});
