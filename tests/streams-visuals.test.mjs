import test from 'node:test';
import assert from 'node:assert/strict';
import * as THREE from 'three';
import fs from 'node:fs';
import {StreamVisuals} from '../source/race-visuals.js';
import {NativeStreams} from '../source/simulation/native-streams.js';
import {DEFAULT_SETTINGS,normalizeSettings} from '../source/settings.js';
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

test('"Motorlicht volgt de kart" interpolates kart flares between tick captures; rocket flares keep theirs',async()=>{
  const identity=()=>[1,0,0,0,1,0,0,0,1];
  const body={position:[0,20,0],matrix:identity()},shot={position:[50,20,0],matrix:identity(),type:1,level:0};
  const streams=new NativeStreams({playerBody:body});streams.racer(body,0);streams.projectile(shot);
  const visual=new StreamVisuals({group:new THREE.Group(),texture:async()=>new THREE.Texture()});await visual.load(manifest);
  const kart=streams.jets.find(jet=>jet.body===body),rocket=streams.jets.find(jet=>jet.body===shot);
  const tick=()=>{body.position[2]+=8;shot.position[2]+=8;streams.step(.025,{playerSpeedKmh:100,playerThrottle:1});
    const frames=streams.draw();visual.capture(frames,{follow:[kart.vertices]});return frames;};
  const mesh=frames=>visual.jets[frames.jets.indexOf(kart.vertices)],rocketMesh=frames=>visual.jets[frames.jets.indexOf(rocket.vertices)];
  const positions=(target,count)=>Array.from(target.geometry.attributes.position.array.slice(0,count*3));
  const native=entry=>entry.vertices.flatMap(vertex=>vertex.position);
  let frames=tick();
  const first=native(kart);visual.present(.5);
  assert.deepEqual(positions(mesh(frames),4),first,'the first capture has no earlier pose');
  frames=tick();
  const second=native(kart),alpha=.25;visual.present(alpha);
  assert.deepEqual(positions(mesh(frames),4),first.map((value,i)=>Math.fround(value*(1-alpha)+second[i]*alpha)));
  assert.deepEqual(positions(rocketMesh(frames),4),native(rocket),'rockets are not interpolated, nor are their flares');
  // The flare centre stays at the native [0,10,-28] offset of the drawn kart.
  const centre=positions(mesh(frames),4).reduce((sum,value,i)=>(sum[i%3]+=value/4,sum),[0,0,0]);
  const kartZ=(body.position[2]-8)*(1-alpha)+body.position[2]*alpha;
  assert.ok(Math.abs(centre[2]-(kartZ-28))<1e-4&&Math.abs(centre[1]-30)<1e-4&&Math.abs(centre[0])<1e-4,String(centre));
  visual.present(1);assert.deepEqual(positions(mesh(frames),4),second,'alpha 1 is the exact native capture');
  visual.present(0);visual.unfollow();
  assert.deepEqual(positions(mesh(frames),4),second);assert.equal(mesh(frames).userData.follow,null);
  frames=tick();visual.present(0);
  assert.deepEqual(positions(mesh(frames),4),native(kart),'a new history starts after unfollow');
  streams.step(.025,{playerSpeedKmh:100,playerThrottle:1});frames=streams.draw();visual.capture(frames);visual.present(0);
  assert.deepEqual(positions(mesh(frames),4),native(kart),'without follow the flare keeps its tick position');
  visual.dispose();
});

test('the engine light setting is on by default and an explicit off is kept',()=>{
  assert.equal(DEFAULT_SETTINGS.smoothEngineLights,true);
  assert.equal(normalizeSettings({}).smoothEngineLights,true);
  assert.equal(normalizeSettings({smoothEngineLights:false}).smoothEngineLights,false);
});
