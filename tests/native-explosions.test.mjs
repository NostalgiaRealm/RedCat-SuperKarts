import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRandom} from '../src/simulation/native-random.js';
import {NativeExplosions} from '../src/simulation/native-explosions.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/explosion-fixtures.json',import.meta.url)));
test('original rocket ring constructor RNG, lifetime, following and indexed draw geometry',()=>{
  for(const trace of fixture.traces) {
    const random=new NativeRandom(trace.seed),body={position:[100,25,-200]};
    const explosions=new NativeExplosions({random,precision:trace.precision});
    const entry=explosions.add(body);
    assert.equal(random.state,trace.randomState);
    assert.deepEqual(entry.position,trace.initialPosition);
    for(const [index,frame] of trace.frames.entries()) {
      body.position=frame.position;
      explosions.step(trace.delta);
      assert.equal(explosions.entries.length,frame.alive?1:0);
      assert.equal(entry.age,frame.age);
      if(!frame.alive)continue;
      const geometry=explosions.capture()[0];
      assert.equal(frame.drawn.length,2);
      for(const [strip,draw]of frame.drawn.entries()) {
        assert.deepEqual(geometry.strips[strip],draw.indices);
        assert.deepEqual(geometry.uv,draw.uv);
        assert.deepEqual(geometry.argb,draw.argb);
        assert.deepEqual(geometry.vertices,draw.vertices,`${trace.precision}/${trace.delta}/${index}`);
      }
    }
  }
});
