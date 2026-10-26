import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import * as THREE from 'three';
import {getNativeKartShadowPose} from '../source/kart-shadow.js';
import {NativeBlendState} from '../source/native-blend-state.js';
import {KartVisual,KartShadowVisual} from '../source/race-visuals.js';
import {advanceNativeKartColor} from '../source/simulation/native-kart-color.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/render-position-fixtures.json',import.meta.url)));

test('200 original rescue draw consumers distinguish logical position from matrix translation',()=>{
  for(const row of fixture.cases){
    assert.deepEqual(row.expected.colorSample,row.body.position);
    assert.deepEqual(row.expected.drawTranslation,row.body.matrixTranslation);
    assert.deepEqual(getNativeKartShadowPose(row.body,row.plane,row).position,row.expected.shadowDrawPosition);
  }
});

test('rescue visual lighting samples the relocated body while shadow keeps old draw XZ',()=>{
  const body={position:[1,0,1],sector:0,forwardSpeed:10,matrix:[1,0,0,0,1,0,0,0,1]};
  const rescue={renderPosition:[100,30,100],matrix:body.matrix.map(x=>x*.1)};
  const plane={vertices:[[0,0,0],[0,0,10],[10,0,0]],normal:[0,1,0],diffuse:0x123456,distance:0};
  const world={sectors:[{triangles:{road:[plane],land:[],extra:[]},fallback:plane}]};
  const visual=Object.assign(new KartVisual(),{actor:{body},diffuse:0xffffffff,brightness:[0,0,0],applyDiffuse(){}});
  visual.captureColor(world,.025,rescue);
  assert.equal(visual.diffuse,advanceNativeKartColor(0xffffffff,plane.diffuse,10,.025,[0,0,0]).diffuse);
  const shadow=Object.assign(new KartShadowVisual(),{actor:{body},mesh:new THREE.Mesh()});
  shadow.capture(world,rescue);
  assert.deepEqual(shadow.current.position,[102,0,102]);
  assert.deepEqual(shadow.current.matrix,rescue.matrix);
});

test('200 native shadow blend states preserve inherited factors with alpha option disabled',()=>{
  const mapping={1:THREE.ZeroFactor,2:THREE.OneFactor,5:THREE.SrcAlphaFactor,6:THREE.OneMinusSrcAlphaFactor};
  for(const {blend} of fixture.cases){
    const state=new NativeBlendState();state.setNative(...blend.before);
    const mesh=new THREE.Mesh();mesh.userData.nativeInheritBlend=!blend.alphaBlending;
    const material=new THREE.MeshBasicMaterial({blending:THREE.CustomBlending,
      blendSrc:THREE.SrcAlphaFactor,blendDst:THREE.OneMinusSrcAlphaFactor});
    state.beforeDraw(mesh,material);
    assert.deepEqual([material.blendSrc,material.blendDst],blend.after.map(x=>mapping[x]));
  }
});

test('scene callbacks track native factors across opaque draws and the separate hardware HUD',()=>{
  const state=new NativeBlendState(),scene=new THREE.Scene(),hud=new THREE.Scene();
  const first=new THREE.Mesh(new THREE.BufferGeometry(),new THREE.MeshBasicMaterial({
    blending:THREE.CustomBlending,blendSrc:THREE.OneFactor,blendDst:THREE.OneFactor}));
  const opaque=new THREE.Mesh(new THREE.BufferGeometry(),new THREE.MeshBasicMaterial({blending:THREE.NoBlending}));
  const shadow=new THREE.Mesh(new THREE.BufferGeometry(),new THREE.MeshBasicMaterial({blending:THREE.CustomBlending}));
  shadow.userData.nativeInheritBlend=true;scene.add(first,opaque,shadow);
  state.bindScene(scene);state.bindScene(hud,{hud:true});scene.onBeforeRender();
  for(const mesh of [first,opaque,shadow])mesh.onBeforeRender(null,scene,null,mesh.geometry,mesh.material);
  assert.deepEqual([shadow.material.blendSrc,shadow.material.blendDst],[THREE.OneFactor,THREE.OneFactor]);
  hud.onBeforeRender();scene.onBeforeRender();
  shadow.onBeforeRender(null,scene,null,shadow.geometry,shadow.material);
  assert.deepEqual([shadow.material.blendSrc,shadow.material.blendDst],[THREE.SrcAlphaFactor,THREE.OneMinusSrcAlphaFactor]);
});
