import test from 'node:test';
import assert from 'node:assert/strict';
import {FpsCounter} from '../source/fps-counter.js';
import {DEFAULT_SETTINGS,normalizeSettings} from '../source/settings.js';

test('FPS counter reports drawn frames per second and restarts after a stall',()=>{
  const counter=new FpsCounter();let time=1000;
  const run=(fps,seconds)=>{for(let i=0;i<fps*seconds;i++)counter.frame(time+=1000/fps);};
  run(30,1);assert.equal(counter.label,'FPS: …');
  run(30,1.5);run(30,1.5);assert.equal(counter.label,'30 FPS');
  run(60,2.1);assert.equal(counter.label,'60 FPS');
  counter.frame(time+=5000);assert.equal(counter.label,'FPS: …');
  counter.reset();assert.equal(counter.label,'FPS: …');
});
test('the FPS setting is off by default and an explicit on is kept',()=>{
  assert.equal(DEFAULT_SETTINGS.showFps,false);
  assert.equal(normalizeSettings({}).showFps,false);
  assert.equal(normalizeSettings({showFps:true}).showFps,true);
});
