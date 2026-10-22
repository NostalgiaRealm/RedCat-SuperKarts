import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import { advanceNativeKartColor, nativeKartBrightness, sampleNativeKartGroundColor } from '../src/simulation/native-kart-color.js';
import { createNativeTrack } from '../src/simulation/native-track.js';

const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/kart-color-fixtures.json', import.meta.url)));
test('600 original kart color updates and opaque-child propagation', () => {
  for (const [i, c] of fixture.cases.entries()) {
    assert.deepEqual(advanceNativeKartColor(c.diffuse, c.groundDiffuse, c.forwardSpeed,
      c.deltaSeconds, c.brightness, { precision: c.precision }), c.expected, `case${i}`);
    assert.deepEqual(c.meshColors, [
      Array(3).fill(c.expected.renderDiffuse), Array(3).fill(c.expected.renderDiffuse),
      Array(3).fill(0x12345678), Array(3).fill(0x12345678),
    ]);
  }
});
test('original country offsets and third-vertex colors survive extraction', () => {
  const config = JSON.parse(fs.readFileSync(new URL('../public/assets/config.json', import.meta.url)));
  for (let trackId = 0; trackId < 6; trackId++) {
    assert.deepEqual(nativeKartBrightness(config, trackId), Array(3).fill(trackId ? 128 : 0));
    const track = JSON.parse(fs.readFileSync(new URL(`../public/assets/tracks/etappe${trackId}.json`, import.meta.url)));
    const world = createNativeTrack(track);
    for (const group of track.groups) {
      if (!['road', 'land', 'extra'].includes(group.kind)) continue;
      for (let i = 0; i < group.count; i += 3) {
        const index = track.index[group.start + i + 2] * 3;
        const rgb = track.color.slice(index, index + 3).map(v => Math.round(v * 255));
        assert.equal(world.sectors[group.sector].triangles[group.kind][i / 3].diffuse,
          ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]) >>> 0);
      }
    }
  }
});
test('ground color uses current sector and native road/land/extra priority', () => {
  const plane = diffuse => ({ vertices: [[0, 0, 0], [0, 0, 10], [10, 0, 0]], normal: [0, 1, 0], diffuse });
  const world = { sectors: [{ triangles: { road: [plane(0x123456)], land: [plane(0xabcdef)], extra: [] } },
    { triangles: { road: [], land: [], extra: [] } }] };
  assert.equal(sampleNativeKartGroundColor(world, { sector: 0, position: [1, 900, 1] }), 0x123456);
  assert.equal(sampleNativeKartGroundColor(world, { sector: 1, position: [1, 900, 1] }), 0xffffff);
});
