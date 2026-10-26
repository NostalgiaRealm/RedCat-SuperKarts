import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeHudSamplerState} from '../source/simulation/native-hud-sampler.js';

const fixture=JSON.parse(fs.readFileSync(new URL(
  '../evidence/native/hud-sampler-fixtures.json',import.meta.url)));
const sampler=state=>({min:state.min,mag:state.mag,cached:state.cached});

test('144 complete original HUD enter/leave pairs retain the independent filter cache',()=>{
  let frames=0;
  for(const trace of fixture.traces) {
    const state=new NativeHudSamplerState(trace);
    for(const frame of trace.frames) {
      assert.deepEqual(state.enter(),sampler(frame.draw));
      assert.deepEqual(state.leave(),sampler(frame.after));
      frames++;
    }
  }
  assert.equal(frames,144);
});

test('native constructors and projection leave the unspecified HUD filter byte unchanged',()=>{
  assert.equal(fixture.constructorCases.length,4);
  for(const row of fixture.constructorCases) {
    assert.equal(row.afterConstructor.filter,row.before);
    assert.equal(row.afterConstructor.hardware,0);
    assert.equal(row.afterProjection.filter,row.before);
    assert.equal(row.afterProjection.hardware,0);
  }
});

test('one captured sampler state serves all HUD groups and intervening presentation frames',()=>{
  for(const filter of [0,2])for(const hudFilterByte of [0,1,165,255]) {
    const state=new NativeHudSamplerState({filter,hudFilterByte});
    for(let frame=0;frame<4;frame++) {
      const draw=state.capture();
      assert.equal(draw.min,filter===2||frame===0?2:1);
      assert.equal(draw.mag,draw.min);
      for(let refresh=0;refresh<10;refresh++) {
        assert.equal(state.current,draw);
        assert.equal(state.frames,frame+1);
      }
      assert.equal(state.min,filter===2?2:1);
      assert.equal(state.mag,state.min);
    }
  }
});
