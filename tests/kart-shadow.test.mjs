import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import * as THREE from 'three';
import {KartShadowVisual} from '../source/race-visuals.js';
import {getNativeKartShadowSpec} from '../source/kart-shadow.js';
const read=name=>JSON.parse(fs.readFileSync(new URL(name,import.meta.url)));
const fixture=read('../evidence/shadow-audit/native.json');
const manifest=read('../public/assets/manifest.json');
const source=read('../public/assets/meshes/s_shadow.json');

test('original416270 shadow initialization has black alpha128 and two-pixel UV insets',()=>{
  for(const row of fixture.initializers){
    const m={...manifest,images:{...manifest.images,'s_shadow.tga':{...manifest.images['s_shadow.tga'],width:row.width}}};
    const spec=getNativeKartShadowSpec(m,manifest.meshes['kart03.d3d'].bounds);
    assert.deepEqual(spec.uv,row.uv);
    assert.deepEqual(row.diffuse,[0x80000000,0x80000000,0x80000000,0x80000000]);
    assert.deepEqual(row.specular,[0,0,0,0]);
    assert.deepEqual(spec.rgba,[0,0,0,128,0,0,0,128,0,0,0,128,0,0,0,128]);
  }
});

test('shadow owns current kart bounds and keeps native sector visibility without a second sphere rejection',async()=>{
  const original=new THREE.BufferGeometry();
  original.setAttribute('position',new THREE.Float32BufferAttribute(source.position,3));
  original.setIndex(source.index);original.computeBoundingSphere();
  const sourceRadius=original.boundingSphere.radius;
  for(const name of ['kart03.d3d','ufotje.d3d']){
    const actor={body:{}};
    const viewer={motion:actor,opponents:[],track:{placements:[]},group:new THREE.Group(),
      model:async()=>original,texture:async()=>new THREE.Texture()};
    const bounds=manifest.meshes[name].bounds;
    const visual=await KartShadowVisual.load(viewer,manifest,{bounds},actor);
    const g=visual.mesh.geometry;
    assert.equal(g.boundingBox.min.x,bounds.minX);assert.equal(g.boundingBox.max.z,bounds.maxZ);
    for(let i=0;i<4;i++)assert.ok(g.boundingSphere.center.distanceTo(
      new THREE.Vector3().fromBufferAttribute(g.attributes.position,i))<=g.boundingSphere.radius+1e-12);
    assert.ok(g.boundingSphere.radius>sourceRadius);
    assert.equal(visual.mesh.frustumCulled,false);
    assert.equal(visual.mesh.material.transparent,false);
    assert.equal(visual.mesh.material.depthWrite,true);
    assert.equal(visual.mesh.material.blendSrc,THREE.SrcAlphaFactor);
    assert.equal(visual.mesh.material.blendDst,THREE.OneMinusSrcAlphaFactor);
    assert.equal(visual.mesh.material.side,THREE.FrontSide);
    assert.deepEqual([...original.attributes.position.array],source.position);
    assert.equal(original.boundingSphere.radius,sourceRadius);
  }
});
