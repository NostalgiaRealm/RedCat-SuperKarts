import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {createNativeMeshAnimation,advanceNativeMeshAnimation,createNativeRotation,advanceNativeRotation,
  getSceneryAnimation,getSkySpec,placementExistsInMode,getTrackMusic} from '../src/asset-animation.js';
const json = path => JSON.parse(readFileSync(new URL(path,import.meta.url)));
const fixtures=json('../evidence/native/animation-fixtures.json');

test('mesh clock matches original x86 traces including strict threshold, ping-pong and uint32 wrap',()=>{
  for(const trace of fixtures.meshTraces){
    const sequence={fps:trace.fps,loops:trace.loops,frames:Array.from({length:trace.count},(_,i)=>i)};
    const state=createNativeMeshAnimation(sequence,trace.initialTime);
    for(const expected of trace.steps){
      advanceNativeMeshAnimation(state,expected.now,trace.speedPercent);
      for(const key of ['frame','completedLoops','lastTime','forward'])
        assert.equal(state[key],expected[key],`${trace.count}/${trace.loops}/${expected.now}:${key}`);
    }
  }
});
test('rotating scenery state matches original x86 float32 updates',()=>{
  for(const trace of fixtures.rotations){
    const state={precision:trace.precision,angles:[...trace.initial],spec:{increment:trace.increments}};
    advanceNativeRotation(state,trace.delta);
    assert.deepEqual(state.angles,trace.angles);
  }
});
test('active initialization uses 4096 angle units per full rotation',()=>{
  const state=createNativeRotation({increment:[0,0,0],randomize:[false,false,false]},[90,180,360]);
  assert.deepEqual(state.angles,[1024,2048,4096]);
  assert.deepEqual(advanceNativeRotation(state,0),[Math.PI/2,Math.PI,Math.PI*2]);
});
test('all listed scenery frames and all sky variants resolve to converted original assets',()=>{
  const config=json('../public/assets/config.json'),manifest=json('../public/assets/manifest.json');
  let count=0;
  for(let track=0;track<6;track++){
    for(const [key,name] of Object.entries(config[`animobj${track}.ini`].objects)){
      if(!/^\d+$/.test(key))continue;
      const animation=getSceneryAnimation(config,manifest,track,name);
      // Retain original texture typos. The placement already has its own material.
      for(const sequence of animation.sequences)for(const frame of sequence.frames){
        assert.ok(frame.file,`${track}:${name}:${frame.source}`);count++;
      }
    }
    for(let mode=0;mode<4;mode++){
      const sky=getSkySpec(config,manifest,track,mode);
      assert.ok(sky.mesh);assert.ok(sky.texture);assert.deepEqual(sky.scale,[10,4,10]);
    }
    assert.ok(getTrackMusic(manifest,track));
  }
  assert.ok(count>1000);
  assert.equal(placementExistsInMode({type:3},0),false);
  assert.equal(placementExistsInMode({type:3},1),true);
  assert.equal(placementExistsInMode({type:4},2),true);
});
