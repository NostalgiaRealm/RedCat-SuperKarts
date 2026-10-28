import { test } from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { updateNativeHitEffect, initializeNativeHitEffect } from '../source/simulation/native-bonus-effects.js';
import { NativeRandom } from '../source/simulation/native-random.js';

const fixtures = JSON.parse(await readFile(new URL('../evidence/gameplay/native-effect-fixtures.json', import.meta.url)));
// The 0x007f capture; tests/native-projectile-precision.test.mjs covers both widths.
const precision = 24;

test('spin, gum and bubble updates match 600 original x86 effect cases', () => {
  for (const [index, fixture] of fixtures.cases.entries()) {
    const body = structuredClone(fixture.body);
    const effect = structuredClone(fixture.effect);
    const random = new NativeRandom(fixture.seed);
    updateNativeHitEffect(effect, body, fixture.delta, fixture.parameters, {
      sampleGround: () => fixture.groundHeight, groundCount: fixture.groundCount,
      rearWheelVerticalSpeed: fixture.rearWheelVerticalSpeed, random, precision,
    });
    for (const [key, expected] of Object.entries(fixture.expected.body)) {
      assert.equal(body[key], expected, `case ${index} ${fixture.kind} body.${key}`);
    }
    for (const key of ['remaining', 'bubbleVisible', 'active']) {
      assert.equal(effect[key], fixture.expected[key], `case ${index} ${fixture.kind} effect.${key}`);
    }
    assert.equal(random.state, fixture.expected.randomState, `case ${index} RNG`);
  }
});

test('all four hit initializers match 120 original cases including player/NPC wheel launch', () => {
  for (const [index, fixture] of fixtures.initializations.entries()) {
    const body = structuredClone(fixture.body);
    const random = new NativeRandom(fixture.seed);
    const effect = initializeNativeHitEffect(fixture.record, body, fixture.parameters, random, { player: fixture.player });
    for (const key of ['phase', 'remaining', 'mode', 'bubbleVisible', 'launchedWheelSpeeds']) {
      assert.deepEqual(effect[key], fixture.expected[key], `case ${index} initialization ${key}`);
    }
    assert.equal(body.forwardSpeed, fixture.expected.forwardSpeed, `case ${index} initial speed`);
    assert.equal(random.state, fixture.expected.randomState, `case ${index} initial RNG`);
  }
});
