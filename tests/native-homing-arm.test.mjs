import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {createNativeHomingArm, updateNativeHomingArm, NativeHomingArms,
  advanceNativeArmQueue} from '../source/simulation/native-homing-arm.js';

const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/arm-fixtures.json', import.meta.url)));
const fields = ['active', 'scale', 'count', 'growthAngle', 'angle', 'initialDistanceSquared', 'colors', 'vertices'];
const snapshot = entry => Object.fromEntries(fields.map(key => [key, entry[key]]));
const expected = entry => Object.fromEntries(fields.map(key => [key, entry[key]]));

test('360 original homing-arm initializations retain target mapping and squared distance', () => {
  for (const f of fixture.rows) {
    const shot = {position: f.shotPosition}, body = {position: f.origin, matrix: f.matrix};
    const entry = createNativeHomingArm(body, shot, f);
    assert.deepEqual(snapshot(entry), expected(f.initial));
    const manager = new NativeHomingArms({actors: Array.from({length: 5}, () => ({body}))});
    assert.equal(manager.targetRacer({target: f.target}), f.initial.body);
  }
});

test('360 complete original homing-arm geometry updates preserve all vertices, colors, ratio and retirement', () => {
  for (const [index, f] of fixture.rows.entries()) {
    const shot = {position: f.shotPosition}, body = {position: [...f.origin], matrix: f.matrix};
    const entry = createNativeHomingArm(body, shot, f);
    Object.assign(entry, structuredClone(f.state));
    body.position = f.bodyPosition;
    updateNativeHomingArm(entry, f.deltaSeconds, {precision: f.precision, player: false});
    assert.equal(entry.ratio, f.ratio === 'nan' ? NaN : f.ratio === 'inf' ? Infinity : f.ratio, `case${index} ratio`);
    for (const key of fields)
      assert.deepEqual(entry[key], f.expected[key], `case${index} ${f.precision}bit ${key}`);
  }
});

test('a target under rescue uses the rescue-scaled render matrix (0x486ec0 after 0x48cc7f)', () => {
  const f = fixture.rows[0], s = Math.fround(.1);
  const rotation = [0, 1, 2, 4, 5, 6, 8, 9, 10].map(i => f.matrix[i]);
  const scaled = rotation.map(value => Math.fround(value * s));
  const run = (matrix, renderPose) => {
    const body = {position: [...f.origin], matrix};
    const entry = createNativeHomingArm(body, {position: f.shotPosition}, f);
    Object.assign(entry, structuredClone(f.state));
    body.position = f.bodyPosition;
    updateNativeHomingArm(entry, f.deltaSeconds, {precision: f.precision, player: false, renderPose});
    return entry;
  };
  // 0x4a17c0 scales rows 0-2 of the shared 4x4 and keeps its translation.
  const native = run([...scaled.slice(0, 3), 0, ...scaled.slice(3, 6), 0,
    ...scaled.slice(6, 9), 0, ...f.matrix.slice(12)]);
  const port = run(rotation, () => ({matrix: scaled, position: f.matrix.slice(12, 15)}));
  assert.deepEqual(port.vertices, native.vertices);
  assert.equal(port.ratio, native.ratio);
  const unscaled = run(rotation, () => null);
  assert.notDeepEqual(unscaled.vertices.map(v => v.position), port.vertices.map(v => v.position));
});

test('upgraded rockets use their homing target, preserve fallback player and native graphics gates', () => {
  const actors = Array.from({length: 5}, (_, id) => ({body: {
    id, position: [id * 100, 0, 0], matrix: [1, 0, 0, 0, 1, 0, 0, 0, 1],
  }}));
  const manager = new NativeHomingArms({actors});
  const shot = {type: 1, level: 2, shooter: 0, target: 2, position: [0, 0, 0]};
  assert.equal(manager.create(shot).body, actors[2].body);
  assert.equal(manager.create({...shot, shooter: 1}), null, 'duplicate target rejected');
  assert.equal(manager.create({...shot, target: -2}).body, actors[4].body);
  assert.equal(manager.create({...shot, target: 1, level: 1}), null);
  assert.equal(manager.create({...shot, target: 1, type: 2}), null);
  manager.remove(shot);
  assert.equal(manager.entries.length, 1);
  assert.equal(manager.entries[0].body, actors[4].body);
  for (const gate of [{jetstreams: false}, {alphaBlending: false}, {paletted: true}])
    assert.equal(new NativeHomingArms({actors, ...gate}).create(shot), null);
});

test('six original vector updates preserve the stale trailing callback and copied-record state', () => {
  for (const f of fixture.managers) {
    const calls = [];
    const remaining = advanceNativeArmQueue(f.flags.map((remove, id) => ({id, remove, updates: 0})), entry => {
      calls.push(entry.id);
      entry.updates++;
      return entry.remove;
    });
    assert.deepEqual(calls, f.updates);
    assert.deepEqual(remaining.map(({id, updates}) => ({id, updates})), f.remaining);
  }
});

test('native arm draws always submit two24-vertex triangle lists and only disable blending afterwards', () => {
  for (const f of fixture.draws) {
    assert.deepEqual(f.calls, f.active ? [
      {primitive: 4, vertexType: 2, offset: 0, count: 24, flags: 1},
      {primitive: 4, vertexType: 2, offset: 768, count: 24, flags: 1},
      {state: 27, value: 0},
    ] : []);
  }
});
