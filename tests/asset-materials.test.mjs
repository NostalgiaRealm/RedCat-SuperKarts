import assert from 'node:assert/strict';
import fs from 'node:fs';
import test from 'node:test';
import * as THREE from 'three';
import {getNativeMaterialSpec, nativeVertexRGBA, nativeColorAttribute,
  createNativeMeshMaterial, configureNativeTextureColorKey} from '../source/asset-materials.js';

const read = path => JSON.parse(fs.readFileSync(new URL(path, import.meta.url)));
const native = read('../evidence/native/material-fixtures.json');

test('native RGB key replacement is configured before filtering, without changing vertex alpha or blend factors',()=>{
  const map=new THREE.Texture(),unkeyed=new THREE.Texture(),authoredAlpha=new THREE.Texture();
  configureNativeTextureColorKey(map,{nativeRGB:true,pixelsMadeTransparent:2,colorKeyRGB:[255,0,127]});
  configureNativeTextureColorKey(unkeyed,{nativeRGB:true,pixelsMadeTransparent:0});
  configureNativeTextureColorKey(authoredAlpha,{nativeRGB:false,pixelsMadeTransparent:2,colorKeyRGB:[255,0,127]});
  assert.equal(map.premultiplyAlpha,true);
  assert.deepEqual(map.userData.nativeColorKeyRGB,[255,0,127]);
  assert.equal(unkeyed.premultiplyAlpha,false);assert.equal(authoredAlpha.premultiplyAlpha,false);
  const material=createNativeMeshMaterial(map,{blendMode:1});
  const shader={fragmentShader:THREE.ShaderLib.basic.fragmentShader};material.onBeforeCompile(shader);
  assert.doesNotMatch(shader.fragmentShader,/diffuseColor\.a\s*=/);
  assert.equal(material.blendSrc,THREE.SrcAlphaFactor);
  assert.equal(material.blendDst,THREE.OneMinusSrcAlphaFactor);
  material.dispose();for(const texture of [map,unkeyed,authoredAlpha])texture.dispose();
});

test('blend state and depth writes match original Direct3D calls for all four modes', () => {
  for (const row of native.passes) {
    const spec = getNativeMaterialSpec({blendMode: row.mode});
    if (row.mode !== 0) assert.equal(Number(spec.depthWrite), row.calls[0].value);
    assert.equal(spec.sourceBlend, row.calls[1].value);
    assert.equal(spec.destinationBlend, row.calls[2].value);
    assert.deepEqual(row.calls.map(call => call.state), [14, 19, 20, 14]);
  }
  for (const row of native.enables) {
    assert.equal(Number(getNativeMaterialSpec({blendMode: row.mode}).transparent), row.enabled);
    assert.equal(row.calls.length, Number(row.previous !== row.enabled));
    if (row.calls.length) assert.deepEqual(row.calls, [{state: 27, value: row.enabled}]);
  }
  for (const row of native.placements) {
    assert.equal(getNativeMaterialSpec({placementType: row.type}).mode, row.mode);
  }
});

test('all distinct source colors in 13 alpha meshes match original packed ARGB bytes', () => {
  for (const row of native.colors) {
    const data = {position: [0, 0, 0], color: row.rgba.slice(0, 3), alpha: [row.rgba[3]]};
    assert.deepEqual([...nativeVertexRGBA(data)], row.bytes);
    const attribute = nativeColorAttribute(data);
    assert.equal(attribute.itemSize, 4);
    assert.equal(attribute.normalized, true);
  }
  for (const row of native.alphaMeshes) {
    const mesh = read(`../public/assets/meshes/${row.mesh.replace('.d3d', '.json')}`);
    assert.equal(mesh.source.sha256, row.sourceSHA256);
    assert.equal(Math.min(...mesh.alpha), row.alphaMin);
    assert.equal(Math.max(...mesh.alpha), row.alphaMax);
  }
  assert.equal(native.alphaMeshes.length, 13);
  assert.deepEqual([...nativeVertexRGBA({position: [0, 0, 0], sourceVersion: 'legacy'})], [255, 255, 255, 0]);
});

test('low vertex alpha is independent of texture cutout and does not select blend mode', () => {
  const map = new THREE.Texture();
  const opaque = createNativeMeshMaterial(map);
  const lamp = createNativeMeshMaterial(map, {placementType: 9});
  const effect = createNativeMeshMaterial(map, {placementType: 10});
  assert.equal(opaque.transparent, false);
  assert.equal(lamp.transparent, true);
  assert.equal(lamp.depthWrite, false);
  assert.equal(lamp.alphaTest, 0);
  assert.equal(map.colorSpace, THREE.NoColorSpace);
  assert.equal(lamp.toneMapped, false);
  assert.equal(lamp.forceSinglePass, true);
  assert.equal(lamp.blendSrc, THREE.SrcAlphaFactor);
  assert.equal(lamp.blendDst, THREE.OneMinusSrcAlphaFactor);
  assert.equal(effect.blendSrc, THREE.OneFactor);
  assert.equal(effect.blendDst, THREE.OneMinusSrcColorFactor);
  // The original texture is RGB; generated alpha encodes its key and must not
  // multiply the interpolated source vertex alpha on filtered edge pixels.
  const shader = {fragmentShader: THREE.ShaderLib.basic.fragmentShader};
  lamp.onBeforeCompile(shader);
  assert.match(shader.fragmentShader, /if \(sampledDiffuseColor\.a <= 0\.0\) discard/);
  assert.match(shader.fragmentShader, /diffuseColor\.rgb \*= sampledDiffuseColor\.rgb/);
  assert.doesNotMatch(shader.fragmentShader, /diffuseColor \*= sampledDiffuseColor/);
  assert.doesNotMatch(shader.fragmentShader, /#include <colorspace_fragment>/);
  for (const material of [opaque, lamp, effect]) material.dispose();
  map.dispose();
});

test('native packed texture sampling decodes channel counts without replacing vertex alpha',()=>{
  const map=new THREE.DataTexture(new Uint8Array([1,0,0,255]),1,1);
  map.userData.nativeTextureFormat='RGB565';
  configureNativeTextureColorKey(map,{nativeRGB:true,pixelsMadeTransparent:1,colorKeyRGB:[255,0,127]});
  assert.equal(map.premultiplyAlpha,false,'key RGB is already zero in the packed upload');
  const material=createNativeMeshMaterial(map,{blendMode:1});
  const shader={fragmentShader:THREE.ShaderLib.basic.fragmentShader};material.onBeforeCompile(shader);
  assert.match(shader.fragmentShader,/sampledDiffuseColor.rgb \*= vec3\(8\.22580645161, 4\.04761904762, 8\.22580645161\)/);
  assert.doesNotMatch(shader.fragmentShader,/diffuseColor\.a\s*=/);
  assert.match(material.customProgramCacheKey(),/RGB565$/);
  map.userData.nativeTextureFormat='RGB555';
  assert.match(material.customProgramCacheKey(),/RGB555$/,'changed texture encoding selects a different program');
  material.dispose();map.dispose();
});

test('all alpha-mode track placements resolve their original source resources', () => {
  const manifest = read('../public/assets/manifest.json');
  let normal = 0, screen = 0;
  for (let id = 0; id < 6; id++) {
    const track = read(`../public/assets/tracks/etappe${id}.json`);
    for (const placement of track.placements) {
      if (![9, 10].includes(placement.type)) continue;
      const definition = track.objectDefinitions[placement.animation.toLowerCase()];
      assert.ok(manifest.meshes[definition.mesh]);
      assert.ok(manifest.images[definition.texture]);
      const spec = getNativeMaterialSpec({placementType: placement.type});
      assert.equal(spec.depthWrite, false);
      if (placement.type === 9) normal++;
      else screen++;
    }
  }
  assert.equal(normal, 58);
  assert.equal(screen, 41);
});
