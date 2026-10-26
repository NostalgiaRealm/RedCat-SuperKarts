import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNativeSkidAudioCommands} from '../source/skid-audio.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/skid-audio-fixtures.json', import.meta.url)));

test('176 original tyre-loop decisions preserve contact, slip, enabled, playing and controller gates', () => {
  assert.equal(fixture.rows.length, 176);
  for (const row of fixture.rows) assert.deepEqual(getNativeSkidAudioCommands(row.input), row.commands, JSON.stringify(row.input));
});
