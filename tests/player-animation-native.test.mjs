import assert from 'node:assert/strict';
import fs from 'node:fs';
import test from 'node:test';
import {getDrivingAnimationRequests, getPlayerLookAnimationRequests,
  getPlayerAnimationEventRequests, advanceDriverAnimation} from '../src/player-assets.js';
import {createNativeMeshAnimation} from '../src/asset-animation.js';

const json = path => JSON.parse(fs.readFileSync(new URL(path, import.meta.url)));
const fixtures = json('../evidence/native/player-animation-fixtures.json');
const config = json('../public/assets/config.json');

test('480 original player steering, braking, reverse, turbo, legacy AI and finish request paths', () => {
  for (const row of fixtures.requests)
    assert.deepEqual(getDrivingAnimationRequests(config, row), row.expected, JSON.stringify(row));
});

test('400 original nearest-racer look paths include orientation, range and ties', () => {
  for (const row of fixtures.looks)
    assert.deepEqual(getPlayerLookAnimationRequests({...row, playerPosition: row.player.position}),
      row.expected, JSON.stringify(row));
});

test('player hit callbacks and pickup cheer match original requests and completion gate', () => {
  for (const row of fixtures.events)
    assert.deepEqual(getPlayerAnimationEventRequests(row), row.expected);
});

test('30 original mesh queues reset and display the next clip immediately when a clip ends', () => {
  for (const row of fixtures.queues) {
    const clocks = Object.fromEntries(row.initial.map((initial, index) => {
      const sequence = {...initial, name: `${index}`, frames: Array.from({length: initial.count},
        (_, frame) => ({source: `${index}:${frame}`}))};
      return [`${index}`, {...createNativeMeshAnimation(sequence), ...initial}];
    }));
    const state = {clocks, queue: row.queue.map(String), displayedSequence: 'old',
      displayedFrame: {source: 'old'}};
    advanceDriverAnimation(state, row.now);
    assert.deepEqual(state.queue, row.expectedQueue.map(String));
    for (let index = 0; index < row.expected.length; index++)
      for (const key of ['frame', 'completedLoops', 'lastTime'])
        assert.equal(clocks[index][key], row.expected[index][key], `${JSON.stringify(row)}: ${index}.${key}`);
    assert.equal(state.displayedFrame.source, row.expectedQueue.length
      ? `${state.queue[0]}:${clocks[state.queue[0]].frame}` : 'old');
  }
});
