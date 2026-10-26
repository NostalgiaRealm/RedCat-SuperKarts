import test from 'node:test';
import assert from 'node:assert/strict';
import {normalizeSettings,readSettings,writeSettings} from '../source/settings.js';
import {chooseMultisampleCount,supportedMultisampleCounts} from '../source/multisample-renderer.js';

test('MSAA and free-flight defaults preserve old saves and reject invalid persisted values',()=>{
  for(const source of [{},{msaaEnabled:'yes',msaaSamples:16,freeFlight:1}]){
    const value=normalizeSettings(source);
    assert.equal(value.msaaEnabled,false);assert.equal(value.msaaSamples,4);assert.equal(value.freeFlight,false);
  }
  const data=new Map(),storage={getItem:key=>data.get(key),setItem:(key,value)=>data.set(key,value)};
  for(const samples of [2,4,8]){
    const value=normalizeSettings({msaaEnabled:true,msaaSamples:samples,freeFlight:true,music:.37});
    assert.equal(writeSettings(value,storage),true);assert.deepEqual(readSettings(storage),value);
  }
});
test('MSAA respects actual common color/depth sample counts, including hardware-only 4x',()=>{
  const gl={RENDERBUFFER:1,RGB565:2,DEPTH_COMPONENT24:3,SAMPLES:4,RGBA8:5,
    getInternalformatParameter(target,format,pname){assert.equal(target,1);assert.equal(pname,4);
      assert.ok([2,3].includes(format),'query native RGB565 color and depth formats');
      return new Int32Array(format===2?[8,4,2]:[4,2]);}};
  assert.deepEqual(supportedMultisampleCounts(gl),[2,4]);
  assert.equal(chooseMultisampleCount(2,[2,4,8]),2);
  assert.equal(chooseMultisampleCount(4,[2,4,8]),4);
  assert.equal(chooseMultisampleCount(8,[2,4,8]),8);
  assert.equal(chooseMultisampleCount(8,[2,4]),4);
  assert.equal(chooseMultisampleCount(2,[4]),4);
  assert.equal(chooseMultisampleCount(8,[]),0);
});
