import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRandom} from '../source/simulation/native-random.js';
import {nativeGameRenderSettings,nativeGameRenderStateCalls,nativeFogSelection,nativeVisibleChunkStart,
 nativeVisibleChunkRanges,nativeObjectCallbackRanges,nativeAdjustVisibleChunks} from '../source/simulation/native-render.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/render-fixtures.json',import.meta.url)));
test('Native render settings issue the original cached Direct3D states',()=>{
 for(const c of fixture.settings)assert.deepEqual(nativeGameRenderStateCalls(c.input),c.expected);
 assert.equal(nativeGameRenderSettings().filter,'linear');
 assert.equal(nativeGameRenderSettings().mipmaps,false);
});
test('Native camera-facing chunk selection matches x86 at both FPU precisions',()=>{
 for(const c of fixture.visibility)assert.equal(nativeVisibleChunkStart(c.input),c.expected,JSON.stringify(c.input));
});
test('Native visibility traversal preserves inclusive ends and wrapping',()=>{
 for(const c of fixture.ranges)assert.deepEqual(nativeVisibleChunkRanges(...c.input),c.expected);
});
test('Original callback window follows the player and is separate from camera visibility',()=>{
 for(const c of fixture.callbacks)assert.deepEqual(nativeObjectCallbackRanges(...c.input),c.expected);
});
test('Native adaptive visibility preserves phase, precision and minimum gates',()=>{
 for(const c of fixture.adaptive)assert.equal(nativeAdjustVisibleChunks(c.count,c.input),c.expected,JSON.stringify(c));
});
test('Disabled native fog consumes no random state; enabled hardware fog uses one draw',()=>{
 for(const c of fixture.fog){
  const random=new NativeRandom(c.seed),result=nativeFogSelection(c.fog,c.hardware,random);
  assert.deepEqual({enabled:result.enabled,draws:result.draws},c.expected);
  assert.equal(random.state,c.state);
 }
 let draws=0;const random={next:()=>{draws++;return 1;}};
 assert.deepEqual(nativeFogSelection(0,true,random),{enabled:false,draws:0});
 assert.deepEqual(nativeFogSelection(1,false,random),{enabled:false,draws:0});
 assert.equal(draws,0);
 assert.deepEqual(nativeFogSelection(1,true,random),{enabled:true,draws:1,mode:'linear',color:0xb4b4c8,
  start:3.5,end:1000,textureBlend:'copy'});
 assert.equal(draws,1);
});
