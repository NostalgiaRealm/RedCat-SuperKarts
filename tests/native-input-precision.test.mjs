import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeInputState, updateNativeInput } from '../source/simulation/native-input.js';

const buttons = mask => ({ left: Boolean(mask & 1), right: Boolean(mask & 2), accelerate: Boolean(mask & 4),
  brake: Boolean(mask & 8), handbrake: Boolean(mask & 32) });

for (const [precision, name] of [[24, 'native-fixtures.json'], [53, 'native-fixtures-53.json']]) {
  test(`0x433870 input updates match the original exactly at ${precision}-bit x87 precision`, () => {
    const fixtures = JSON.parse(readFileSync(new URL(`../evidence/gameplay/${name}`, import.meta.url)));
    assert.equal(fixtures.fpuControlWord, `0x${(precision === 24 ? 0x7f : 0x27f).toString(16).padStart(4, '0')} (${precision}-bit precision)`);
    let frames = 0;
    for (const trace of fixtures.inputTraces) {
      const state = createNativeInputState();
      for (const [index, frame] of trace.frames.entries()) {
        updateNativeInput(state, buttons(frame.mask), frame.delta, trace.mirrored, undefined, { precision });
        const where = `${trace.interval}:${trace.mirrored}:${index}`;
        for (const key of ['throttle', 'steering', 'brake', 'handbrake'])
          assert.ok(Object.is(state[key], frame.expected[key]), `${where}:${key} ${state[key]} != ${frame.expected[key]}`);
        frames++;
      }
    }
    assert.equal(frames, 1600);
  });
}
