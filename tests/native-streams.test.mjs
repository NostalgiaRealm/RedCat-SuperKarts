import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import { createNativeJetFlare, updateNativeJetFlare, createNativeRibbon,
  updateNativeRibbon, shrinkNativeRibbon, NativeStreams, nativeRacerStreamOptions,
  nativeProjectileStreamOptions, nativeRibbonDrawPackets } from '../src/simulation/native-streams.js';

const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/stream-fixtures.json', import.meta.url)));
test('post-rescue render poses retain original body ownership and native geometry', () => {
  const trace = fixture.traces[0], frame = trace.frames[0];
  const body = {...structuredClone(frame.body), position: [999, 999, 999]};
  const streams = new NativeStreams({playerBody: body});
  streams.racer(body, 0);
  const expected = new NativeStreams({playerBody: frame.body});
  expected.racer(frame.body, 0);
  streams.step(frame.dt, {playerSpeedKmh: 80, playerThrottle: 20, renderPose: candidate => {
    assert.equal(candidate, body);
    return frame.body;
  }});
  expected.step(frame.dt, {playerSpeedKmh: 80, playerThrottle: 20});
  assert.deepEqual(streams.jets.map(x => x.vertices), expected.jets.map(x => x.vertices));
  assert.deepEqual(streams.ribbons.map(x => x.vertices), expected.ribbons.map(x => x.vertices));
  assert.deepEqual(body.position, [999, 999, 999]);
  assert.equal(streams.ribbons[0].body, body);
  streams.remove(body);
  assert.equal(streams.ribbons.length, 0);
});
test('960 original jet flare frames retain native geometry, color and UV', () => {
  for (const [t, trace] of fixture.traces.entries()) {
    const body = structuredClone(trace.frames[0].body);
    const jet = createNativeJetFlare(body, trace.jetOptions);
    for (const [i, frame] of trace.frames.entries()) {
      Object.assign(body, frame.body);
      updateNativeJetFlare(jet, {...frame, precision: trace.precision});
      assert.deepEqual({angle: jet.angle, vertices: jet.vertices}, frame.jet, `trace${t} frame${i}`);
    }
  }
});
test('16 original draw traces preserve additive states, strip order and draw-time shrink', () => {
  for (const c of fixture.draws) {
    let packets;
    if (c.jet) packets = [c.jet.vertices];
    else {
      const entry = {active: true, doubleSided: c.doubleSided, fastShrink: c.fastShrink,
        ...structuredClone(c.before)};
      shrinkNativeRibbon(entry, {precision: c.precision});
      assert.deepEqual({angle: entry.angle, colors: entry.colors, vertices: entry.vertices}, c.after);
      packets = nativeRibbonDrawPackets(entry);
    }
    const states = c.calls.filter(call => call.state);
    assert.deepEqual(states, [
      {state: 27, value: 1}, {state: 19, value: 2}, {state: 20, value: 2}, {state: 27, value: 0},
    ]);
    assert.deepEqual(c.calls.filter(call => call.primitive), packets.map(vertices =>
      ({primitive: 5, vertexType: 2, flags: 1, vertices})));
  }
});
test('30 original racer/turbo/projectile setup branches', () => {
  const source = JSON.parse(fs.readFileSync(new URL('../evidence/native/stream-setup-fixtures.json', import.meta.url)));
  for (const c of source.turbo) assert.deepEqual(c.commands, [
    {op: 'remove', body: c.body}, {op: 'add', body: c.body, options: nativeRacerStreamOptions(c.racer, c.level)},
  ]);
  for (const c of source.projectiles) assert.deepEqual(c.commands,
    c.type === 1 ? [{op: 'add', body: c.body, options: nativeProjectileStreamOptions(c.type, c.level)}] : []);
  for (const c of source.initial) {
    // The extra player-color2 and repeated NPC calls are duplicate-gated.
    const first = c.commands.filter(v => v.op === 'add').slice(0, c.opponents + 1);
    assert.deepEqual(first, [...c.npcBodies, c.playerBody].map((body, racer) =>
      ({op: 'add', body, options: nativeRacerStreamOptions(racer)})));
  }
});
test('720 original manager operations preserve duplicate gates, limits and swap removal', () => {
  for (const [t, trace] of fixture.managers.entries()) {
    const bodies = Array.from({length: 50}, (_, id) => ({id}));
    const streams = new NativeStreams({...trace.flags, precision: trace.precision, playerBody: bodies[4]});
    const snapshot = () => ({
      ribbons: streams.ribbons.map(({body, offset, rotate, colorIndex, rainbow, doubleSided, size, flare, fastShrink}) =>
        ({body: body.id, offset, rotate, colorIndex, rainbow, doubleSided, size, flare, fastShrink})),
      jets: streams.jets.map(({body, offset, clockwise, colorIndex, rainbow, crossed, size}) =>
        ({body: body.id, offset, clockwise, colorIndex, rainbow, crossed, size})),
      pairCount: streams.pairCount,
    });
    for (const [i, command] of trace.operations.entries()) {
      if (command.op === 'remove') streams.remove(bodies[command.body]);
      else {
        const options = command.op === 'add' ? [command.options] : [-18, 18].map(x => ({
          offset: [x, 12, -12], rotate: command.rotate, colorIndex: 2, rainbow: command.rotate,
          doubleSided: command.rotate, size: command.size, flare: true, fastShrink: false,
        }));
        streams.add(bodies[command.body], options);
      }
      assert.deepEqual(snapshot(), command.expected, `trace${t} operation${i}`);
    }
  }
});
test('960 original ribbon update and draw-time shrink frames', () => {
  for (const [t, trace] of fixture.traces.entries()) {
    const body = structuredClone(trace.frames[0].body);
    const ribbon = createNativeRibbon(body, trace.options);
    const snapshot = () => ({angle: ribbon.angle, colors: ribbon.colors, vertices: ribbon.vertices});
    for (const [i, frame] of trace.frames.entries()) {
      Object.assign(body, frame.body);
      updateNativeRibbon(ribbon, frame.dt, {...frame, precision: trace.precision});
      assert.deepEqual(snapshot(), frame.updated, `update trace${t} frame${i}`);
      shrinkNativeRibbon(ribbon, {precision: trace.precision});
      assert.deepEqual(snapshot(), frame.drawn, `draw trace${t} frame${i}`);
    }
  }
});
