import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {advanceNativeArmAudio} from '../src/arm-audio.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/arm-audio-fixtures.json', import.meta.url)));
test('1200 original arm beep updates include unordered ratios and24/53 precision', () => {
  for (const [index, row] of fixture.rows.entries())
    assert.deepEqual(advanceNativeArmAudio({...row.input,ratio:Number(row.input.ratio)}), row.expected, String(index));
});
