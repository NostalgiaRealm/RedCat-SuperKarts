import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeCrashAudio, NATIVE_CRASH_SOUNDS} from '../src/native-crash-audio.js';
import {NativeRandom} from '../src/simulation/native-random.js';

const fixtures = JSON.parse(fs.readFileSync(new URL('../evidence/native/crash-audio-fixtures.json', import.meta.url)));
test('840 original crash callbacks preserve impact thresholds, timer wrap, suppression and shared RNG', () => {
  for (const [index, row] of fixtures.rows.entries()) {
    const random = new NativeRandom(row.input.seed);
    const controller = new NativeCrashAudio({...row.input, random});
    const sound = controller.contact(row.input);
    assert.deepEqual(sound ? [{index: NATIVE_CRASH_SOUNDS.indexOf(sound.event), loop: sound.loop}] : [],
      row.sounds, String(index));
    assert.equal(controller.lastTimeMs, row.lastTimeMs, String(index));
    assert.equal(random.state, row.nextState, String(index));
  }
});
