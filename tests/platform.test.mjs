import test from 'node:test';
import assert from 'node:assert/strict';
import {normalizeSettings,renderDimensions,readSettings,writeSettings,adaptVerticalFov} from '../source/settings.js';
import {InputState,axisDeadzone} from '../source/input.js';

test('Auto applies DPR once, each render scale multiplies both dimensions',()=>{
  for(const scale of [25,100,200]){
    const size=renderDimensions({width:800,height:600,dpr:2,renderScale:scale});
    assert.equal(size.width,1600*scale/100);assert.equal(size.height,1200*scale/100);
  }
});
test('preset resolutions preserve viewport aspect and do not multiply DPR',()=>{
  for(const [width,height]of [[1920,1080],[390,844],[1024,768],[2560,1080]])for(const scale of [25,100,200]){
    const a=renderDimensions({width,height,dpr:1,resolution:'1280x720',renderScale:scale});
    const b=renderDimensions({width,height,dpr:3,resolution:'1280x720',renderScale:scale});
    assert.deepEqual(a,b);assert.ok(Math.abs(a.width/a.height-width/height)<2/a.height);
    assert.ok(a.baseWidth<=1280&&a.baseHeight<=720);
  }
});
test('GPU limits proportionally constrain the buffer without stretching',()=>{
  const s=renderDimensions({width:3840,height:2160,dpr:2,renderScale:200,maxSize:4096});
  assert.equal(s.width,4096);assert.equal(s.height,2304);assert.equal(s.limited,true);
});
test('settings roundtrip, corrupt storage and invalid types are handled',()=>{
  const data=new Map(),storage={getItem:k=>data.get(k),setItem:(k,v)=>data.set(k,v)};
  const settings=normalizeSettings({renderScale:175,deadzone:.25,resolution:'1920x1080',music:.4});
  assert.equal(writeSettings(settings,storage),true);assert.deepEqual(readSettings(storage),settings);
  storage.setItem('rcsk.settings.v1','oops');assert.equal(readSettings(storage).renderScale,100);
  assert.equal(normalizeSettings({renderScale:Infinity}).renderScale,100);
  assert.equal(normalizeSettings({renderScale:500}).renderScale,200);
  assert.equal(writeSettings(settings,{setItem(){throw Error('quota');}}),false);
});
test('independent simultaneous pointers and keyboard release never release other inputs',()=>{
  const input=new InputState();input.set('pointer:1','accelerate');input.set('pointer:2','left');input.set('key:up','accelerate');
  assert.deepEqual(input.snapshot(),{throttle:1,brake:0,steer:-1,handbrake:0,bonus:0});
  input.release('pointer:1');assert.equal(input.snapshot().throttle,1);
  input.release('key:up');assert.equal(input.snapshot().throttle,0);assert.equal(input.snapshot().steer,-1);
  input.clear();assert.deepEqual(input.snapshot(),{throttle:0,brake:0,steer:0,handbrake:0,bonus:0});
});
test('analog deadzone is continuous and normalized',()=>{
  assert.equal(axisDeadzone(.15,.18),0);assert.equal(axisDeadzone(1,.18),1);
  assert.equal(axisDeadzone(-1,.18),-1);assert.ok(Math.abs(axisDeadzone(.59,.18)-.5)<1e-12);
});
test('FOV adaptation preserves reference and reveals width, portrait preserves horizontal',()=>{
  assert.equal(adaptVerticalFov(60,4/3),60);assert.equal(adaptVerticalFov(60,16/9),60);
  const portrait=adaptVerticalFov(60,9/16);
  assert.ok(Math.abs(Math.tan(portrait*Math.PI/360)*9/16-Math.tan(Math.PI/6)*4/3)<1e-12);
});
