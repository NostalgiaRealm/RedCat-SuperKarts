import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeHudPortraitCurve, updateNativeHudPortrait, createNativeHudPortraits,
  updateNativeHudPortraits, getNativeHudPortraitCommands} from '../source/hud-portraits.js';
import {getHudMeshSpec} from '../source/hud-mesh.js';

const load = name => JSON.parse(fs.readFileSync(new URL(`../${name}`, import.meta.url)));
const fixtures = load('evidence/native/hud-portrait-fixtures.json');
const close = (actual, expected, context) => {
  assert.equal(actual.length, expected.length, context);
  actual.forEach((value, i) => assert.ok(Math.abs(value - expected[i]) <= 1e-6,
    `${context}[${i}]: ${value} vs ${expected[i]}`));
};
const stateEqual = (actual, expected, context) => {
  for (const key of ['state', 'elapsedMs', 'durationMs', 'curved', 'rank']) {
    assert.equal(actual[key], expected[key], `${context}.${key}`);
  }
  for (const key of ['start', 'target', 'position']) close(actual[key], expected[key], `${context}.${key}`);
};

test('112 original curve samples preserve source half-circle direction and linear correction', () => {
  for (const item of fixtures.curves) {
    close(nativeHudPortraitCurve(item.start, item.target, item.fraction, item), item.expected, JSON.stringify(item));
  }
});

test('96 native portrait updates preserve millisecond boundaries and exact finish state', () => {
  for (const item of fixtures.moving) {
    const state = structuredClone(item.before);
    updateNativeHudPortrait(state, item.delta, item);
    stateEqual(state, item.expected, JSON.stringify(item.before));
  }
});

test('600 original manager frames preserve delayed rank changes, corrections and ordinal placement', () => {
  for (const item of fixtures.managers) {
    const state = createNativeHudPortraits({characters: ['redcat', 'whizzkitty', 'brutus', 'max', 'country'],
      playerIndex: item.playerIndex, precision: item.precision});
    for (const [tick, frame] of item.frames.entries()) {
      updateNativeHudPortraits(state, item.delta, frame.ranks);
      frame.portraits.forEach((expected, i) => stateEqual(state.portraits[i], expected,
        `PC${item.precision} player${item.playerIndex} tick${tick} racer${i}`));
      close(state.labelY, frame.labels.map(position => position[1]), `labels ${tick}`);
    }
  }
});

test('all six country portraits resolve original assets and retain original tint and player scaling', () => {
  const config = load('public/assets/config.json'), manifest = load('public/assets/manifest.json');
  const state = createNativeHudPortraits({characters: ['redcat', 'whizzkitty', 'brutus', 'max', 'Ferdinand'],
    playerIndex: 1});
  updateNativeHudPortraits(state, .025, [0, 1, 2, 3, 4]);
  const commands = getNativeHudPortraitCommands(state, config);
  assert.equal(commands.length, 20);
  assert.deepEqual(commands.find(command => command.id === 'portrwhizzkitty').overrides.portrwhizzkitty.scale,
    [.5, .5, Math.fround(.001)]);
  for (let trackId = 0; trackId < 6; trackId++) {
    for (const command of commands) {
      const spec = getHudMeshSpec(config, manifest, command.id, {...command, trackId});
      assert.ok(spec.mesh && spec.texture, `${trackId}:${command.id}`);
      assert.equal(spec.visible, true);
      assert.equal(spec.rgba[3], command.id.startsWith('back') ? 64 : 255);
    }
  }
});
