import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { createNativeTrack, sampleNativeTrack } from '../source/simulation/native-track.js';
import { nativePlayerStart } from '../source/simulation/native-start.js';
import { NATIVE_PRECISION } from '../source/simulation/native-precision.js';

const read = path => JSON.parse(readFileSync(new URL(`../${path}`, import.meta.url)));
const fixtures = read('evidence/gameplay/native-track-fixtures-53.json');
const tracks = new Map(fixtures.tracks.map(data => [data.id, read(`public/assets/tracks/etappe${data.id}.json`)]));
const options = { precision: 53 };
// null marks the x87 default NaN that native 0x494f40 stores for zero-area triangles.
const same = (actual, expected) => expected === null ? Number.isNaN(actual) : Object.is(actual, expected);

test('53-bit fixture comes from the 0x027f control word on the same inputs', () => {
  assert.equal(fixtures.fpuControlWord, '0x027f');
  const base = read('evidence/gameplay/native-track-fixtures.json');
  assert.equal(fixtures.sourceSha256, base.sourceSha256);
  fixtures.tracks.forEach((data, i) => assert.deepEqual(
    data.cases.map(({ hint, point }) => [hint, point]), base.tracks[i].cases.map(({ hint, point }) => [hint, point])));
});

test('53-bit 0x495cb0 sector axes and fallback planes match native exactly on all six tracks', () => {
  for (const data of fixtures.tracks) {
    const world = createNativeTrack(tracks.get(data.id), options);
    assert.equal(world.sectors.length, data.sectors.length);
    data.sectors.forEach((expected, i) => {
      const sector = world.sectors[i];
      for (const key of ['side', 'forward']) sector[key].forEach((value, axis) => {
        assert.equal(value, expected[key][axis], `${data.id} sector ${i} ${key}[${axis}]`);
      });
      sector.fallback.normal.forEach((value, axis) => {
        assert.equal(value, expected.fallback.normal[axis], `${data.id} sector ${i} fallback normal[${axis}]`);
      });
      assert.equal(sector.fallback.distance, expected.fallback.distance, `${data.id} sector ${i} fallback distance`);
    });
  }
});

test('53-bit 0x494f40 triangle planes match native exactly on all six tracks', () => {
  let planes = 0;
  for (const data of fixtures.tracks) {
    const world = createNativeTrack(tracks.get(data.id), options);
    data.sectors.forEach((expected, i) => {
      for (const kind of ['road', 'land', 'extra']) {
        const triangles = world.sectors[i].triangles[kind];
        assert.equal(triangles.length, expected.planes[kind].length, `${data.id} sector ${i} ${kind} count`);
        expected.planes[kind].forEach(([nx, ny, nz, distance], t) => {
          planes++;
          const { normal, distance: actual } = triangles[t];
          [nx, ny, nz].forEach((value, axis) => assert.ok(same(normal[axis], value),
            `${data.id} sector ${i} ${kind} ${t} normal[${axis}] ${normal[axis]} != ${value}`));
          assert.ok(same(actual, distance), `${data.id} sector ${i} ${kind} ${t} distance ${actual} != ${distance}`);
        });
      }
    });
  }
  assert.equal(planes, 52516);
});

test('53-bit 0x4977d0/0x495fe0/0x496290 selections and heights match native exactly', () => {
  let cases = 0;
  for (const data of fixtures.tracks) {
    const world = createNativeTrack(tracks.get(data.id), options);
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

test('53-bit 0x493540 grid heading matches native exactly on all six tracks', () => {
  for (const data of fixtures.tracks) {
    const track = tracks.get(data.id);
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

test('precision defaults to NATIVE_PRECISION and rejects other control words', () => {
  const track = tracks.get(5);
  const world = createNativeTrack(track), current = { precision: NATIVE_PRECISION };
  assert.deepEqual(createNativeTrack(track, current), world);
  assert.notDeepEqual(createNativeTrack(track, { precision: NATIVE_PRECISION === 24 ? 53 : 24 }), world);
  const [fixture] = fixtures.tracks.find(data => data.id === 5).cases;
  assert.deepEqual(sampleNativeTrack(world, fixture.hint, ...fixture.point, current),
    sampleNativeTrack(world, fixture.hint, ...fixture.point));
  assert.deepEqual(nativePlayerStart(track, world, current), nativePlayerStart(track, world));
  assert.throws(() => createNativeTrack(track, { precision: 64 }), RangeError);
  assert.throws(() => sampleNativeTrack(world, 0, 0, 0, 0, { precision: 64 }), RangeError);
  assert.throws(() => nativePlayerStart(track, world, { precision: 64 }), RangeError);
});
