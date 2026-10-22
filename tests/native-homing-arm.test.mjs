import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {createNativeHomingArm, updateNativeHomingArm, NativeHomingArms,
  advanceNativeArmQueue} from '../src/simulation/native-homing-arm.js';

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
