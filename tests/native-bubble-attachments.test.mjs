import {test} from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {NativeBubbleAttachments} from '../src/simulation/native-bubble-attachments.js';
import {getNativeBubbleShellSpec,BubbleShellVisuals} from '../src/bubble-visuals.js';
import * as THREE from 'three';
import {NATIVE_RENDER_ORDER} from '../src/render-order.js';

const fixtures=JSON.parse(await readFile(new URL('../evidence/native/bubble-attachment-fixtures.json',import.meta.url)));

test('bubble shells match 480 original attach/detach/pre-object update operations',()=>{
  for(const trace of fixtures.traces){
    const bodies=Array.from({length:trace.opponentCount+1},()=>({}));
    const controller=new NativeBubbleAttachments(bodies);
    for(const [tick,step]of trace.steps.entries()){
      bodies.forEach((body,index)=>Object.assign(body,structuredClone(step.bodies[index])));
      const actual=step.action==='step'?controller.step():controller[step.action](step.racer);
      if(step.result!==null)assert.equal(actual,Boolean(step.result),`return ${trace.opponentCount}:${tick}`);
      const snapshot=controller.entries.map(entry=>entry&&({
        racer:entry.racer,objectOrder:entry.objectOrder,position:entry.position,
        sector:entry.sector,waypoint:entry.waypoint,angles:entry.angles,visible:entry.visible,
        meshId:123,textureId:456,blendMode:entry.blendMode,
      }));
      assert.deepEqual(snapshot,step.expected,`snapshot ${trace.opponentCount}:${tick}`);
    }
  }
});

test('shell pose retains the pre-movement copy, separate from kart rotation and visibility',()=>{
  const body={position:[10,20,30],sector:7,waypoint:15,matrix:[0,0,1,0,1,0,-1,0,0]};
  const controller=new NativeBubbleAttachments([body]);
  controller.attach(0);controller.step();
  body.position[0]=100;body.sector=8;
  assert.deepEqual(controller.entries[0].position,[10,20,30]);
  assert.equal(controller.entries[0].sector,7);
  assert.deepEqual(controller.entries[0].matrix,[1,0,0,0,1,0,0,0,1]);
  controller.step();
  assert.deepEqual(controller.entries[0].position,[100,20,30]);
});

test('shell visuals bind original assets, screen blend and manager pose',async()=>{
  const config=JSON.parse(await readFile(new URL('../public/assets/config.json',import.meta.url)));
  const manifest=JSON.parse(await readFile(new URL('../public/assets/manifest.json',import.meta.url)));
  const spec=getNativeBubbleShellSpec(config,manifest);
  assert.equal(spec.mesh,'meshes/bubb0001.json');
  assert.equal(spec.texture,'textures/weapon.tga.png');
  const bodies=[{position:[1,2,3],sector:4,waypoint:5}];
  const controller=new NativeBubbleAttachments(bodies);
  const geometry=new THREE.BoxGeometry(),texture=new THREE.Texture();
  const viewer={group:new THREE.Group(),track:{placements:[]},
    simulation:{actors:bodies},combat:{shots:[],secondaryShots:[]},
    model:async()=>geometry,texture:async()=>texture};
  const visual=new BubbleShellVisuals(viewer,controller);
  await visual.load(config,manifest);
  controller.attach(0);visual.capture();
  const mesh=visual.meshes[0];
  assert.equal(mesh.visible,true);
  assert.deepEqual(mesh.position.toArray(),[1,2,3]);
  assert.equal(mesh.userData.sector,4);
  assert.equal(mesh.material.blendSrc,THREE.OneFactor);
  assert.equal(mesh.material.blendDst,THREE.OneMinusSrcColorFactor);
  assert.equal(mesh.material.depthWrite,false);
  controller.entries[0].objectOrder=1000000;
  visual.capture();
  assert.ok(mesh.renderOrder<NATIVE_RENDER_ORDER.skidmarks,
    'relative dynamic allocation counters cannot cross a later effect phase');
  controller.detach(0);visual.capture();assert.equal(mesh.visible,false);
  visual.dispose();geometry.dispose();texture.dispose();
  assert.equal(viewer.group.children.length,0);
});
