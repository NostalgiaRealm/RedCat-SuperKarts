import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNativeSpatialAudioCommands, getNativeSoundListener, nativePanGains,nativeObjectCallbackCount} from '../source/spatial-audio.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/spatial-audio-fixtures.json', import.meta.url)));

test('spatial distance, pan, doppler and playback match original instructions', () => {
  for (const [index, row] of fixture.rows.entries())
    assert.deepEqual(getNativeSpatialAudioCommands(row.input), row.commands, `case ${index}`);
});
test('listener uses camera matrix translation rather than camera position', () => {
  for (const row of fixture.listeners) {
    const result = getNativeSoundListener({position: row.cameraPosition, target: row.cameraTarget},
      {yaw: row.yaw, lateralSpeed: row.localVelocity[0], forwardSpeed: row.localVelocity[2]}, row);
    assert.deepEqual(result, row.expected);
  }
});
test('DirectSound pan attenuates only the opposite channel', () => {
  assert.deepEqual(nativePanGains(0), [1, 1]);
  assert.deepEqual(nativePanGains(10000), [1e-5, 1]);
  assert.deepEqual(nativePanGains(-10000), [1, 1e-5]);
});
test('attached source callbacks bypass both sector ranges but obey visibility', () => {
  for(const row of fixture.callbackGates)assert.equal(nativeObjectCallbackCount(row),row.calls);
});
