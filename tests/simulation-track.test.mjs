import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeTrack, sampleNativeTrack } from '../src/simulation/native-track.js';
import { nativePlayerStart } from '../src/simulation/native-start.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/gameplay/native-track-fixtures.json', import.meta.url)));

test('960 sector and triangle selections match native instructions on all six original tracks', () => {
  for (const data of fixtures.tracks) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${data.id}.json`, import.meta.url)));
    const world = createNativeTrack(track);
    data.sectors.forEach((expected, i) => {
      for (const key of ['side', 'forward']) world.sectors[i][key].forEach((value, axis) => {
        assert.equal(value, expected[key][axis], `${data.id} sector ${i} ${key}`);
      });
    });
    for (const fixture of data.cases) {
      const sample = sampleNativeTrack(world, fixture.hint, ...fixture.point);
      for (const key of ['sector', 'kind', 'triangle']) assert.equal(sample[key], fixture.expected[key], `track ${data.id} ${key}`);
      assert.ok(Math.abs(sample.height - fixture.expected.height) < 0.01,
        `track ${data.id} height ${sample.height} != ${fixture.expected.height}`);
    }
  }
});

test('native player grid starts and heading match original instructions on all six tracks', () => {
  for (const data of fixtures.tracks) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${data.id}.json`, import.meta.url)));
    const world = createNativeTrack(track);
    for (const expected of data.starts) {
      const actual = nativePlayerStart(track, world, { opponentCount: expected.opponentCount });
      assert.equal(actual.source, 'TRIGGER_POS_REDCAT');
      assert.equal(actual.sector, expected.sector);
      assert.deepEqual(actual.position, expected.position);
      assert.equal(actual.yaw, expected.yaw, `${data.id}: ${actual.yaw} != ${expected.yaw}`);
    }
  }
});

test('rendering texture replacements do not change native ground selection on any shipped course', () => {
  for (const data of fixtures.tracks) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${data.id}.json`, import.meta.url)));
    const world = createNativeTrack(track);
    const replacement = createNativeTrack({
      ...track,
      textures: track.textures.map((_, i) => `unrelated-${i}.png`),
      groups: track.groups.map(group => ({ ...group, textureIndex: 3 - group.textureIndex })),
    });
    for (const fixture of data.cases) {
      assert.deepEqual(sampleNativeTrack(replacement, fixture.hint, ...fixture.point),
        sampleNativeTrack(world, fixture.hint, ...fixture.point));
    }
  }
});
