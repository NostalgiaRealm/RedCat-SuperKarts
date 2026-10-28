import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {createNativeRescue, updateNativeRescue, nativeRescueRingPositions,
  NativeRescueController, nativeRescuePositionFree, nativeRescueWaypoint,
  nativeRescueNearestSector, nativeRescueHeading} from '../source/simulation/native-rescue.js';
import {getNativeRescueVisualSpec} from '../source/rescue-assets.js';

const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/rescue-fixtures.json', import.meta.url)));
const identity = [1, 0, 0, 0, 1, 0, 0, 0, 1];
const makeBody = (position = [5, 6, 7]) => ({id: 0, position: [...position],
  matrix: [...identity], lateralSpeed: 4, verticalSpeed: -8, forwardSpeed: 12, yawRate: 7});
const resolveDestination = () => ({position: [100, 25, 300], sector: 0, yaw: 0});

test('native recovery initialization records position and only clears linear velocity', () => {
  for (const item of fixture.initial) {
    const body = makeBody(item.position), state = createNativeRescue(body);
    assert.deepEqual(state.origin, item.recordedPosition);
    assert.deepEqual([body.lateralSpeed, body.verticalSpeed, body.forwardSpeed], item.velocity);
    assert.equal(body.yawRate, 7);
    assert.equal(state.frame, item.frame);
    assert.equal(state.shrinking, item.shrinking);
  }
});

test('80 original rescue update cases preserve twenty-tick phases, relocation and launch velocity', () => {
  for (const item of fixture.updates) {
    const body = makeBody(), state = createNativeRescue(body);
    Object.assign(state, {frame: item.frame, shrinking: item.shrinking});
    updateNativeRescue(state, .025, {resolveDestination, precision: item.precision, effectsEnabled: false});
    assert.deepEqual(state.matrix, [0, 1, 2, 4, 5, 6, 8, 9, 10].map(i => item.matrix[i]));
    assert.deepEqual(body.position, item.position);
    assert.deepEqual([body.lateralSpeed, body.verticalSpeed, body.forwardSpeed], item.velocity);
    assert.equal(state.frame, item.frameAfter);
    assert.equal(state.shrinking, item.shrinkingAfter);
    assert.equal(state.finished, item.finished);
  }
});

test('all 6720 original effect vertices and 48 clock updates match native instructions', () => {
  for (const item of fixture.rings) {
    const body = makeBody(item.position), state = createNativeRescue(body);
    Object.assign(state, {frame: item.scale === 1 ? 3 : 19, angle: item.angle});
    updateNativeRescue(state, item.deltaSeconds, {resolveDestination, precision: item.precision});
    assert.equal(state.angle, item.angleAfter, JSON.stringify(item));
    const actual = nativeRescueRingPositions(state, {precision: item.precision});
    actual.forEach((value, i) => assert.equal(value, item.positions[i],
      `${item.precision}-bit dt=${item.deltaSeconds} angle=${item.angle} scale=${item.scale} vertex component ${i}`));
  }
});

test('queue deduplication, ten-object cap and completion retirement preserve block flags', () => {
  const controller = new NativeRescueController({});
  const drivers = Array.from({length: 11}, (_, id) => ({body: {...makeBody(), id}, state: {blockRecovery: false}}));
  drivers.forEach(driver => controller.enqueue(driver));
  assert.equal(controller.entries.length, 10);
  // 0x48dd51/0x48dca1 insert at begin(): storage is newest first.
  assert.deepEqual(controller.entries.map(entry => entry.driver), drivers.slice(0, 10).reverse());
  // 0x48dce0/0x48dc30 test the cap before scanning for a duplicate.
  assert.equal(controller.enqueue(drivers[0]), null);
  assert.equal(controller.entries[9].driver, drivers[0]);
  assert.equal(drivers[10].state.blockRecovery, false);
  controller.entries[0].finished = true;
  controller.finishRender();
  assert.equal(drivers[9].state.blockRecovery, false);
  assert.equal(controller.entries[0].driver, drivers[0]);
});

test('0x48db30 retirement walks stale slots without dropping an unfinished rescue', () => {
  const retire = finished => {
    const controller = new NativeRescueController({});
    const drivers = finished.map((_, id) => ({body: {...makeBody(), id}, state: {blockRecovery: false}}));
    [...drivers].reverse().forEach(driver => controller.enqueue(driver));
    controller.entries.forEach((entry, i) => { entry.finished = finished[i]; });
    controller.finishRender();
    return {ids: controller.entries.map(entry => entry.body.id),
      blocked: drivers.map(driver => driver.state.blockRecovery)};
  };
  // The stale second slot retires its own entry: both finish in one pass.
  assert.deepEqual(retire([true, true]), {ids: [], blocked: [false, false]});
  assert.deepEqual(retire([false, true, true]), {ids: [0], blocked: [true, false, false]});
  assert.deepEqual(retire([true, false, true]), {ids: [1], blocked: [false, true, false]});
  assert.deepEqual(retire([false, true, false]), {ids: [0, 2], blocked: [true, false, true]});
  assert.deepEqual(retire([true, false, false]), {ids: [2, 1], blocked: [false, true, true]});
});

test('respawn clearance excludes self and compares planar squared distance inclusively', () => {
  const body = makeBody();
  assert.equal(nativeRescuePositionFree(body, [0, 0, 0], [body]), true);
  assert.equal(nativeRescuePositionFree(body, [0, 0, 0], [{position: [40, 9999, 20]}]), false);
  assert.equal(nativeRescuePositionFree(body, [0, 0, 0], [{position: [40, 0, 21]}]), true);
  // One case queries from z=0.1f, so only an unrounded dz gives its 53-bit result.
  assert.ok(fixture.clearance.some(item => item.query[2] !== 0 && item.precision === 53 && item.expected));
  for (const item of fixture.clearance) {
    assert.equal(nativeRescuePositionFree(body, item.query.map(Math.fround), [
      {position: item.other.map(Math.fround)}, {position: [1000, 0, 1000]},
    ], item), item.expected);
  }
});

test('360 original destination-node and nearest-sector selections cover all six tracks', () => {
  const tracks = Array.from({length: 6}, (_, i) =>
    JSON.parse(fs.readFileSync(new URL(`../public/assets/tracks/etappe${i}.json`, import.meta.url))));
  for (const item of fixture.waypoints) {
    assert.equal(nativeRescueWaypoint(tracks[item.track], item.start, makeBody(), {
      precision: item.precision, deltaSeconds: .025, occupied: new Set(item.occupied),
      occupants: [{position: [100000, 100000, 100000]}, {position: [100000, 100000, 100000]}],
    }), item.expected, JSON.stringify(item));
  }
  for (const item of fixture.nearestSectors) {
    assert.equal(nativeRescueNearestSector(tracks[item.track], item.position, item), item.expected);
  }
});

test('original 0x493540 restoration headings preserve both x87 precision modes', () => {
  for (const item of fixture.headings) {
    assert.equal(nativeRescueHeading({sectors: [{forward: item.forward}]}, 0, item.precision), item.expected);
  }
});

test('rescue visual uses every original UV and vertex color with its shipped texture', () => {
  const manifest = JSON.parse(fs.readFileSync(new URL('../public/assets/manifest.json', import.meta.url)));
  const visual = getNativeRescueVisualSpec(manifest);
  assert.deepEqual(visual.uv, Array.from({length: 20}, () => fixture.uv).flat());
  assert.deepEqual(visual.rgba, fixture.rgba.flat());
  assert.equal(visual.index.length, 300);
  assert.equal(visual.vertexCount, 140);
  assert.ok(fs.existsSync(new URL(`../public/assets/${visual.texture}`, import.meta.url)));
});
