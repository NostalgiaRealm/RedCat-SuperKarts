import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeFinishCamera } from '../source/simulation/native-camera.js';
const read = path => JSON.parse(readFileSync(new URL(`../${path}`, import.meta.url)));
const fixtures = read('evidence/native/finish-camera-fixtures.json');
const tracks = Array.from({ length: 6 }, (_, i) => read(`public/assets/tracks/etappe${i}.json`));
test('120 original finish-camera setups and later target tracking match across all six tracks', () => {
  assert.equal(fixtures.cases.length, 120);
  for (const [i, c] of fixtures.cases.entries()) {
    const camera = new NativeFinishCamera(tracks[c.track], c.body, c);
    assert.deepEqual({ position: camera.position, target: camera.target }, c.initial, `setup ${i}`);
    assert.equal(c.activeCamera, 5);
    camera.step({ ...c.body, position: c.moved });
    assert.deepEqual({ position: camera.position, target: camera.target }, c.updated, `tracking ${i}`);
    assert.deepEqual(camera.up, [0, 1, 0]);
  }
});
