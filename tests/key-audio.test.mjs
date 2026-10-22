import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeKeyAudio} from '../src/native-key-audio.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/key-audio-fixtures.json', import.meta.url)));
test('240 original Space branches retain voice-ID mismatch, order and native counters', () => {
  for (const [index, row] of fixture.rows.entries()) {
    const state = new NativeKeyAudio(row.input);
    assert.deepEqual(state.step(row.input.pressed), row.commands, String(index));
    assert.equal(state.sampleNumber, row.sampleNumber, String(index));
    assert.equal(state.repetitions, row.repetitions, String(index));
  }
});
