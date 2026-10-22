import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeSkidmarks} from '../src/simulation/native-skidmarks.js';
const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/native/skidmark-fixtures.json',import.meta.url)));

test('520 original skidmark emission, pool exhaustion, stripe size, fading and expiry frames',()=>{
  for(const trace of fixture.traces) {
    const marks=new NativeSkidmarks({precision:trace.precision});
    for(const [index,frame] of trace.frames.entries()) {
      marks.enabled=frame.input.enabled;marks.fade=frame.input.fade;
      marks.emit(frame.input);marks.capture();
      assert.equal(marks.lastSlip,frame.lastSlip,`lastSlip/${trace.precision}/${index}`);
      assert.equal(marks.currentIndex>>>0,frame.currentIndex,`current/${trace.precision}/${index}`);
      assert.deepEqual(marks.strips.filter(strip=>strip.active),frame.strips,`strips/${trace.precision}/${index}`);
    }
  }
});
