import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativePlacementAngles} from '../source/simulation/native-transform.js';
import {createNativeRotation, getRotationSpec} from '../source/asset-animation.js';
import {nativeBonusTypeFromObject} from '../source/simulation/native-bonus.js';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';

// rcskspel.dat 0x497070 -> 0x43e140 (0x43e283..0x43e2ad) on every shipped OMP
// record, at both CRT control words: tools/native-placement-angle-fixtures.py.
const read = path => fs.readFileSync(new URL(`../${path}`, import.meta.url));
const json = path => JSON.parse(read(path));
const fixture = json('evidence/native/placement-angle-fixtures.json');
const config = json('public/assets/config.json'), manifest = json('public/assets/manifest.json');
const cars = json('public/assets/cars.json');
const trackFile = id => `public/assets/tracks/etappe${id}.json`;
const tracks = fixture.tracks.map(entry => json(trackFile(entry.track)));
const rows = fixture.tracks.map(entry => entry.rows.map(([index, sector, type, raw, degrees, angles24, angles53]) =>
  ({index, sector, type, raw, degrees, angles24, angles53})));
const native = (track, index) => rows[track][index].angles53;
const pose = object => [object.pitch, object.yaw, object.roll];

test('the original OMP loader passes every raw degree record; the converter carries the 0x43e2a0 Y sign', () => {
  assert.deepEqual(fixture.tracks.map(entry => entry.track), [0, 1, 2, 3, 4, 5]);
  let angles = 0;
  tracks.forEach((track, t) => {
    assert.equal(fixture.tracks[t].sha256, track.source.omp);
    assert.equal(rows[t].length, track.placements.length);
    rows[t].forEach((row, i) => {
      const placement = track.placements[i], raw = Buffer.from(row.raw, 'hex');
      assert.deepEqual([row.index, row.sector, row.type], [i, placement.sector, placement.type]);
      assert.deepEqual([0, 4, 8].map(offset => raw.readFloatLE(offset)), row.degrees);
      assert.deepEqual(placement.nativeRotationDegrees, [row.degrees[0], -row.degrees[1], row.degrees[2]], `${t}:${i}`);
      angles += 3;
    });
  });
  assert.equal(angles, 4857);
});

test('all 4857 placement angles match the original at PC=24 and PC=53, including signed zeros', () => {
  let divideBy360 = 0;
  tracks.forEach((track, t) => rows[t].forEach((row, i) => {
    assert.deepEqual(row.angles24, row.angles53);
    const degrees = track.placements[i].nativeRotationDegrees;
    assert.deepEqual(nativePlacementAngles(degrees), row.angles53, `${t}:${i}`);
    divideBy360 += degrees.filter((value, axis) => !Object.is(Math.fround(value * 4096 / 360), row.angles53[axis])).length;
  }));
  // The former value*4096/360 conversion is distinguishable on these inputs.
  assert.equal(divideBy360, 433);
});

test('rotating scenery starts from the converted placement angles unless 0x43e140 randomizes the axis', () => {
  let checked = 0;
  tracks.forEach((track, t) => track.placements.forEach((placement, i) => {
    const plain = createNativeRotation({increment: [0, 0, 0], randomize: [false, false, false]},
      placement.nativeRotationDegrees);
    assert.deepEqual(plain.angles, native(t, i), `${t}:${i}`);
    const spec = getRotationSpec(config, placement);
    if (!spec) return;
    const state = createNativeRotation(spec, placement.nativeRotationDegrees, () => 2001);
    state.angles.forEach((angle, axis) => {
      assert.equal(angle, spec.randomize[axis] ? 1 : native(t, i)[axis], `${t}:${i}:${axis}`);
      if (!spec.randomize[axis]) checked++;
    });
  }));
  assert.equal(checked, 24);
});

test('race scenery, hazards, path objects and pickups use the original converted angles', () => {
  const counts = {bodies: 0, reactions: 0, hazards: 0, paths: 0, pickups: 0};
  fixture.tracks.forEach(({track: id}, t) => {
    const sim = new RaceSimulation({config, manifest, cars, track: json(trackFile(id)), random: new NativeRandom(0),
      physicsBytes: read('public/assets/physics/phys1.dat'), racerBytes: read('public/assets/racer-tables/cars1.dat')});
    for (const body of sim.scenery.bodies) {
      assert.deepEqual(pose(body), native(t, body.placementIndex)); counts.bodies++;
    }
    for (const object of sim.sceneryReactions.objects) {
      assert.deepEqual(pose(object), native(t, object.placementIndex)); counts.reactions++;
    }
    for (const object of sim.sceneryHazards.objects) {
      const spec = getRotationSpec(config, tracks[t].placements[object.placementIndex]);
      object.angles.forEach((angle, axis) => {
        if (!spec?.randomize[axis]) assert.equal(angle, native(t, object.placementIndex)[axis]);
      });
      counts.hazards++;
    }
    for (const [index, object] of sim.sceneryPaths.objects) {
      assert.equal(object.yaw, native(t, index)[1]); counts.paths++;
    }
    for (const pickup of sim.pickups.pickups) {
      assert.ok(nativeBonusTypeFromObject(tracks[t].placements[pickup.placementIndex].type));
      assert.equal(pickup.yaw, native(t, pickup.placementIndex)[1]); counts.pickups++;
    }
  });
  assert.deepEqual(counts, {bodies: 270, reactions: 174, hazards: 10, paths: 28, pickups: 180});
});
