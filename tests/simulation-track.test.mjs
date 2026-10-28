import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeTrack, sampleNativeTrack } from '../source/simulation/native-track.js';
import { nativePlayerStart } from '../source/simulation/native-start.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/gameplay/native-track-fixtures.json', import.meta.url)));
// The 0x007f capture; tests/native-track-precision.test.mjs covers both widths.
const options = { precision: 24 };
// null marks the x87 default NaN that native 0x494f40 stores for zero-area triangles.
const same = (actual, expected) => expected === null ? Number.isNaN(actual) : Object.is(actual, expected);

test('24-bit 0x495cb0 axes, fallback planes and 0x494f40 triangle planes match native exactly', () => {
  for (const data of fixtures.tracks) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${data.id}.json`, import.meta.url)));
    const world = createNativeTrack(track, options);
    data.sectors.forEach((expected, i) => {
      const sector = world.sectors[i];
      for (const key of ['side', 'forward']) sector[key].forEach((value, axis) => {
        assert.equal(value, expected[key][axis], `${data.id} sector ${i} ${key}`);
      });
      sector.fallback.normal.forEach((value, axis) => {
        assert.equal(value, expected.fallback.normal[axis], `${data.id} sector ${i} fallback normal[${axis}]`);
      });
      assert.equal(sector.fallback.distance, expected.fallback.distance, `${data.id} sector ${i} fallback distance`);
      for (const kind of ['road', 'land', 'extra']) {
        assert.equal(sector.triangles[kind].length, expected.planes[kind].length, `${data.id} sector ${i} ${kind} count`);
        expected.planes[kind].forEach(([nx, ny, nz, distance], t) => {
          const plane = sector.triangles[kind][t];
          [nx, ny, nz].forEach((value, axis) => assert.ok(same(plane.normal[axis], value),
            `${data.id} sector ${i} ${kind} ${t} normal[${axis}] ${plane.normal[axis]} != ${value}`));
          assert.ok(same(plane.distance, distance), `${data.id} sector ${i} ${kind} ${t} distance ${plane.distance} != ${distance}`);
        });
      }
    });
  }
});

test('960 sector and triangle selections and heights match native instructions on all six original tracks', () => {
  let cases = 0;
  for (const data of fixtures.tracks) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${data.id}.json`, import.meta.url)));
    const world = createNativeTrack(track, options);
    for (const fixture of data.cases) {
      cases++;
      const sample = sampleNativeTrack(world, fixture.hint, ...fixture.point, options);
      for (const key of ['sector', 'kind', 'triangle', 'height']) {
        assert.ok(Object.is(sample[key], fixture.expected[key]), `track ${data.id} ${key} ${sample[key]} != ${fixture.expected[key]}`);
      }
    }
  }
  assert.equal(cases, 960);
});

test('native player grid starts and heading match original instructions on all six tracks', () => {
  for (const data of fixtures.tracks) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${data.id}.json`, import.meta.url)));
    const world = createNativeTrack(track, options);
    for (const expected of data.starts) {
      const actual = nativePlayerStart(track, world, { opponentCount: expected.opponentCount, ...options });
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
