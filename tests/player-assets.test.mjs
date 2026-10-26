import assert from 'node:assert/strict';
import fs from 'node:fs';
import test from 'node:test';
import {getPlayerVisualSpec, getDrivingAnimationRequests, createDriverAnimation,
  requestDriverAnimation, advanceDriverAnimation} from '../source/player-assets.js';

const json = path => JSON.parse(fs.readFileSync(new URL(path, import.meta.url)));
const config = json('../public/assets/config.json');
const manifest = json('../public/assets/manifest.json');
const native = json('../evidence/native/player-asset-fixtures.json');

test('four selectable drivers have all original body, wheel and animation resources', () => {
  const names = ['RedCat', 'WhizzKitty', 'Brutus', 'Max'];
  const prefixes = ['r', 'w', 'b', 'm'];
  for (let character = 0; character < 4; character++) {
    const spec = getPlayerVisualSpec(config, manifest, character);
    assert.equal(spec.name, names[character]);
    assert.equal(spec.body.texture, 'textures/indyred.tga.png');
    assert.equal(spec.wheels.length, 4);
    assert.deepEqual(spec.driver.offset, [0, 0, 0]);
    assert.equal(Object.keys(spec.driver.sequences).length, 26);
    assert.equal(spec.driver.sequences.idle.frames[0].source, `${prefixes[character]}idl0001.d3d`);
    const paths = [spec.body.mesh, spec.body.texture, spec.driver.texture,
      ...spec.wheels.flatMap(wheel => [wheel.mesh, wheel.texture]),
      ...Object.values(spec.driver.sequences).flatMap(sequence => sequence.frames.map(frame => frame.file))];
    for (const path of paths) {
      assert.ok(path, `${names[character]}: missing resource`);
      assert.ok(fs.existsSync(new URL(`../public/assets/${path}`, import.meta.url)), path);
    }
  }
});

test('mesh bounds and collision radii match original x86 for car, wheels and pickups', () => {
  for (const [name, expected] of Object.entries(native.bounds)) {
    assert.deepEqual(manifest.meshes[name].bounds, expected.bounds, name);
    assert.equal(manifest.meshes[name].horizontalRadius, expected.horizontalRadius, name);
    const mesh = json(`../public/assets/${manifest.meshes[name].file}`);
    assert.equal(mesh.source.sha256, expected.sourceSHA256);
  }
  const spec = getPlayerVisualSpec(config, manifest, 0);
  assert.equal(spec.wheels[0].radius, Math.abs(native.bounds['wiela.d3d'].bounds.minY));
  assert.equal(spec.wheels[2].radius, Math.abs(native.bounds['wielv.d3d'].bounds.minY));
  assert.deepEqual(spec.body.bounds, native.bounds['kart03.d3d'].bounds);
});

test('147 request admission cases match original x86 character-state gate', () => {
  const driver = getPlayerVisualSpec(config, manifest, 0).driver;
  for (const row of native.admission) {
    const state = createDriverAnimation(driver);
    state.nativeState = row.currentState;
    state.queue = Array(row.queueLength).fill('idle');
    requestDriverAnimation(state, {name: 'idle', from: row.from, to: row.to});
    assert.equal(state.nativeState, row.resultState);
    assert.equal(state.queue.length, row.resultQueueLength);
  }
});

test('turn requests follow signed lateral velocity, speed threshold and native order', () => {
  assert.equal(getDrivingAnimationRequests(config, {lateralSpeed: 1.38})[0].name, 'right_idle');
  assert.deepEqual(getDrivingAnimationRequests(config, {lateralSpeed: 1.4}).slice(0, 3), [
    {name: 'idle_steer_left', from: 0, to: 3},
    {name: 'steer_left', from: 3, to: 3},
    {name: 'steer_left_idle', from: 3, to: 0},
  ]);
  assert.equal(getDrivingAnimationRequests(config, {lateralSpeed: -1.4})[0].name, 'idle_steer_right');
  assert.deepEqual(getDrivingAnimationRequests(config, {forwardSpeed: -0.01}).map(r => r.name),
    ['right_idle', 'left_idle', 'idle_back', 'back', 'brake_idle']);
  assert.equal(getDrivingAnimationRequests(config, {brake: 1})[2].name, 'brake');
  assert.equal(getDrivingAnimationRequests(config, {handbrake: true})[2].name, 'brake');
  assert.equal(getDrivingAnimationRequests(config, {turboAgeMs: 4999})[2].name, 'turbo');
  assert.equal(getDrivingAnimationRequests(config, {turboAgeMs: 5000})[2].name, 'turbo_idle');
});

test('finite driver clips keep their last rendered frame on queue completion', () => {
  const driver = getPlayerVisualSpec(config, manifest, 0).driver;
  const state = createDriverAnimation(driver);
  for (let i = 1; i <= 14; i++) advanceDriverAnimation(state, i * 67);
  assert.equal(state.displayedFrame.source, 'ridl0015.d3d');
  const lastTime = state.clocks.idle.lastTime;
  advanceDriverAnimation(state, 15 * 67);
  assert.equal(state.queue.length, 0);
  assert.equal(state.displayedFrame.source, 'ridl0015.d3d');
  assert.ok(state.clocks.idle.lastTime > lastTime);
  requestDriverAnimation(state, {name: 'idle', from: 0, to: 0});
  assert.equal(state.clocks.idle.lastTime, 15 * 67); // admission does not reset its timer
  advanceDriverAnimation(state, 15 * 67);
  assert.equal(state.displayedFrame.source, 'ridl0001.d3d');
});
