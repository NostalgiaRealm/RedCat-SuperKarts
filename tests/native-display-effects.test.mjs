import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeSmoke} from '../source/simulation/native-smoke.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {RescueVisuals} from '../source/race-visuals.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/display-effect-fixtures.json',import.meta.url)));
test('accelerated cloud construction matches original alpha option gate and consumes no emission RNG when disabled',()=>{
  for(const row of fixture.smoke.filter(row=>row.sourceCapability&&row.destinationCapability)){
    const random=new NativeRandom(123),smoke=new NativeSmoke({...row,random});
    assert.equal(smoke.enabled,row.after);
    if(!row.after){
      const before=random.state;
      assert.equal(smoke.emit([0,0,0],[1,1,1],.025),0);
      assert.deepEqual(smoke.capture({deltaSeconds:.025,cameraPosition:[0,0,0]}),[]);
      assert.equal(random.state,before);
    }
  }
});
test('rescue strip renderer follows the original jetstream and alpha gates',async()=>{
  const manifest=JSON.parse(fs.readFileSync(new URL('../public/assets/manifest.json',import.meta.url)));
  const THREE=await import('three');
  for(const row of fixture.rescue.filter(row=>!row.paletted)){
    const viewer={runtimeConfig:{'sndgfx.ini':{'gfx options':{
      jetstreams:Number(row.jetstreams),alpha_blending:Number(row.alphaBlending)}}},
      group:new THREE.Group(),texture:async()=>new THREE.Texture()};
    const entry={matrix:[1,0,0,0,1,0,0,0,1],renderPosition:[0,0,0],angle:row.after};
    const visual=new RescueVisuals(viewer,{entries:[entry]});await visual.load(manifest);visual.capture();
    assert.equal(visual.enabled,row.after!==row.before);
    assert.equal(visual.meshes[0].visible,row.after!==row.before);
    for(const mesh of visual.meshes){mesh.geometry.dispose();mesh.material.dispose();}
  }
});
