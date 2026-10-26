import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNativeSceneryPaths, nativePathDurationTicks, sampleNativeSceneryPath,
  advanceNativeSceneryPath, NativeSceneryPaths} from '../source/scenery-paths.js';

const read = path => JSON.parse(fs.readFileSync(new URL(`../${path}`, import.meta.url)));
const fixture = read('evidence/native/scenery-path-fixtures.json');
const tracks = Array.from({length: 6}, (_, i) => read(`public/assets/tracks/etappe${i}.json`));
const paths = tracks.map(track => new Map(getNativeSceneryPaths(track).map(path => [path.index, path])));

test('all 35 dynamic paths resolve their original registered scenery and flag bits', () => {
  assert.equal(paths.reduce((total, entries) => total + entries.size, 0), 35);
  const sheep = [...paths[2].values()].filter(path => path.animation === 'shpj0001');
  assert.equal(new Set(sheep.map(path => path.placementIndex)).size, 1);
  assert.equal(tracks[2].placements[sheep[0].placementIndex].value, 1);
});

test('210 original duration conversions freeze and quantize ticks at activation', () => {
  for (const row of fixture.durations) assert.equal(
    nativePathDurationTicks(paths[row.track].get(row.path), row.delta, row.precision), row.ticks, JSON.stringify(row));
});

test('original spline samples retain float operation order, closed seams and terminal clamping', () => {
  for (const row of fixture.samples) assert.deepEqual(
    sampleNativeSceneryPath(paths[row.track].get(row.path), row.ticks, row.tick, row.precision),
    row.position, JSON.stringify(row));
});

test('1050 original dynamic updates retain repeat, heading and stop-sector behavior', () => {
  for (const row of fixture.updates) {
    const state = {path: paths[row.track].get(row.path), tick: row.tick, durationTicks: row.ticks,
      position: row.beforePosition, yaw: row.beforeYaw, visible: true, active: true};
    advanceNativeSceneryPath(state, row.sector, row.precision);
    assert.deepEqual(state.position, row.position, JSON.stringify(row));
    assert.equal(state.tick, row.afterTick);
    assert.ok(Math.abs(state.yaw - row.yaw) <= .0005, `heading: ${JSON.stringify(row)} actual ${state.yaw}`);
    assert.equal(!state.active, row.done);
  }
});

test('original activation traces require changed sector and reset started flags only on lap change', () => {
  const controllers = tracks.map(track => new NativeSceneryPaths(track));
  for (const row of fixture.activations) {
    const controller = controllers[row.track];
    const before = row.lap === controller.previousLap ? new Set(controller.started) : new Set();
    controller.step({playerSector: row.sector, lapCount: row.lap, deltaSeconds: .025});
    assert.deepEqual([...controller.started].filter(index => !before.has(index)), row.started, JSON.stringify(row));
  }
});
