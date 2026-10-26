import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {getNPCAnimationEventRequests, getNPCTurboAnimationRequests,
  getNPCDrivingAnimationRequests, requestDriverAnimation} from '../source/player-assets.js';

const fixtures = JSON.parse(fs.readFileSync(new URL('../evidence/native/npc-animation-fixtures.json', import.meta.url)));

test('NPC steering uses original callback branches, including exact deadband boundaries', () => {
  for (const item of fixtures.steering) {
    assert.deepEqual(getNPCAnimationEventRequests(item), item.expected);
  }
});

test('NPC turbo, finish, pickup and damage submissions match 65 original instruction cases', () => {
  for (const item of fixtures.turbo) {
    assert.deepEqual(getNPCTurboAnimationRequests(item), item.expected);
  }
  for (const item of fixtures.normal) {
    assert.deepEqual(getNPCDrivingAnimationRequests(item), item.expected);
  }
  for (const item of fixtures.events) {
    assert.deepEqual(getNPCAnimationEventRequests(item), item.expected);
  }
});

test('unconditional requests append and restart the head without changing animation state', () => {
  const names = ['idle', 'hit', 'cheer'];
  for (const item of fixtures.queueAppend) {
    const state = {nativeState: 4, queue: item.existing.map(i => names[i]),
      clocks: Object.fromEntries(names.map((name, i) => [name,
        {completedLoops: 2 + i, frame: 7 + i, retained: 12345 + i}]))};
    assert.equal(requestDriverAnimation(state, {name: names[item.added], enqueue: true}), true);
    assert.equal(state.nativeState, 4);
    assert.deepEqual(state.queue, item.queue.map(i => names[i]));
    assert.deepEqual(names.map(name => ({loops: state.clocks[name].completedLoops,
      frame: state.clocks[name].frame, retained: state.clocks[name].retained})), item.sequences);
  }
});

test('NPC normal update preserves steering before turbo before settling requests', () => {
  const event = {callback: '0040c0c0', argument: -1};
  assert.deepEqual(getNPCDrivingAnimationRequests({events: [event],
    turboActive: true, turboStartedSeconds: 10, nowSeconds: 12, racePhase: 3, rank: 0}), [
    ...getNPCAnimationEventRequests(event),
    ...getNPCTurboAnimationRequests({turboActive: true, turboStartedSeconds: 10, nowSeconds: 12}),
    ...getNPCDrivingAnimationRequests({racePhase: 3, rank: 0}),
  ]);
});
