import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeLapDisplay} from '../source/simulation/native-lap-display.js';

const fixtures=JSON.parse(readFileSync(new URL('../evidence/native/lap-display-fixtures.json',import.meta.url)));
test('Lap display matches original initialization and every mode/precision hold callback',()=>{
  for(const trace of fixtures.traces){
    const display=new NativeLapDisplay({precision:trace.precision});
    assert.deepEqual(display.state,{holdStampSeconds:trace.initial.holdStampSeconds,text:trace.initial.text});
    assert.deepEqual(trace.initial.writtenElements,['STRING_LAPOF_VALUE']);
    for(const [index,frame]of trace.frames.entries()){
      if(frame.method==='notify')display.notifyLap(frame);else display.update(frame);
      assert.deepEqual(display.state,frame.state,`${trace.name}/${trace.raceType}/${trace.precision}/${index}`);
    }
  }
});
test('Lap event holds the prior string and expires on the absolute truncated clock',()=>{
  const display=new NativeLapDisplay();
  assert.equal(display.update({lapText:'00:39:95',nowSeconds:99.95}),'00:39:95');
  display.notifyLap({lapCount:1,nowSeconds:100.975});
  assert.equal(display.state.holdStampSeconds,100);
  assert.equal(display.update({lapText:'00:00:02',nowSeconds:100.975}),'00:39:95');
  assert.equal(display.update({lapText:'00:02:05',nowSeconds:103}),'00:39:95','Clearing callback retains the previous display');
  assert.equal(display.state.holdStampSeconds,-1);
  assert.equal(display.update({lapText:'00:02:07',nowSeconds:103.025}),'00:02:07');
});
test('No paused callbacks means no display mutation; resumed absolute time expires before next display update',()=>{
  for(const reset of fixtures.pauseResets){
    assert.equal(reset.afterSeconds,Math.fround(reset.wallMilliseconds/1000));
    assert.equal(reset.deltaSeconds,0);
    assert.deepEqual(reset.history,Array(4).fill(Math.fround(.1)));
  }
  const display=new NativeLapDisplay({initialText:'00:15:70'});
  display.notifyLap({lapCount:1,nowSeconds:50.725});
  const saved=structuredClone(display.state);
  assert.deepEqual(display.state,saved);
  assert.equal(display.update({lapText:'00:00:02',nowSeconds:150.75}),'00:15:70');
  assert.equal(display.update({lapText:'00:00:05',nowSeconds:150.775}),'00:00:05');
});
