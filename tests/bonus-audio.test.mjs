import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativePickupSoundRequest, nativeFiringSoundRequest} from '../src/bonus-audio.js';

const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/bonus-audio-fixtures.json', import.meta.url)));
test('original static pickup names and player-only firing requests, including missing GOT_BONUS', () => {
  for (const row of fixture.rows) {
    if (row.kind === 'pickup') {
      assert.equal(nativePickupSoundRequest(row.type).sample, row.sample);
      assert.equal(nativePickupSoundRequest(row.type, {player: false}), null);
    } else {
      const request = nativeFiringSoundRequest(row.type, row.level, {player: row.player});
      assert.deepEqual(request ? [request] : [], row.commands);
    }
  }
});
