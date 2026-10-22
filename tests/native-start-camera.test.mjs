import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeStartCamera} from '../src/simulation/native-start-camera.js';
const fixture = JSON.parse(readFileSync(new URL('../evidence/native/start-camera-fixtures.json', import.meta.url)));
const tracks = Array.from({length: 6}, (_, i) => JSON.parse(readFileSync(
  new URL(`../public/assets/tracks/etappe${i}.json`, import.meta.url))));

test('all six original startup camera paths, wall ticks and convergence match native instructions', () => {
  for (const [i, c] of fixture.cases.entries()) {
    const camera = new NativeStartCamera(tracks[c.track], c.body, c.delta, c.startedMs, c);
    assert.equal(camera.durationTicks, c.ticks);
    for (const key of ['position', 'target', 'up']) assert.deepEqual(camera[key], c.initial[key], `${i}/initial/${key}`);
    for (const [j, expected] of c.updates.entries()) {
      assert.equal(camera.advance(c.body, expected.nowMs), expected.done, `${i}/${j}/done`);
      camera.step(c.body);
      for (const key of ['stage', 'tick', 'lastPathMs', 'position', 'target', 'up']) {
        assert.deepEqual(camera[key], expected[key], `${i}/${j}/${key}`);
      }
    }
  }
});
