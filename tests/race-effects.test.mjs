import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNativeKartShadowSpec, getNativeKartShadowPose} from '../source/kart-shadow.js';
import {getNativeFinishFlagSpec, NativeFinishFlag} from '../source/finish-flag.js';
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/race-effect-fixtures.json', import.meta.url)));
const manifest = JSON.parse(fs.readFileSync(new URL('../public/assets/manifest.json', import.meta.url)));

test('original kart shadow bounds and pose match native sector-plane projection', () => {
  for (const row of fixture.shadows) {
    assert.deepEqual(getNativeKartShadowSpec(manifest, row.bounds).position, row.expected.vertices);
    assert.deepEqual(getNativeKartShadowPose(row.body, row.plane, row),
      {position: row.expected.position, matrix: row.expected.matrix});
  }
});
test('finish flag uses original grid and atlas coordinates', () => {
  for (const row of fixture.flagGeometry) {
    const spec = getNativeFinishFlagSpec(manifest, row);
    assert.deepEqual(spec.position, row.position);
    assert.deepEqual(spec.uv, row.uv);
  }
});
test('finish flag waves and colors match original instructions', () => {
  for (const row of fixture.flags) {
    const flag = new NativeFinishFlag(row);
    flag.setEnabled(true, row.deltaSeconds);
    assert.equal(flag.period, row.period);
    flag.tick = row.tick;
    const frame = flag.capture();
    assert.deepEqual(frame.z, row.z);
    assert.deepEqual(frame.argb, row.argb);
    assert.equal(flag.tick, (row.tick + 1) % row.period);
  }
});
