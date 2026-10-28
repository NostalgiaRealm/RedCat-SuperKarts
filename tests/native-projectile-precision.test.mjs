import { test } from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { updateNativeProjectileFlight, NativeFireGate, selectNativeProjectileTarget,
  nativeProjectileLaunchPose, nativeProjectileFacing, hatchNativeBubbles } from '../source/simulation/native-projectile.js';
import { updateNativeHitEffect, initializeNativeHitEffect } from '../source/simulation/native-bonus-effects.js';
import { NativeRandom } from '../source/simulation/native-random.js';

// Same inputs as the 24-bit fixtures, probed at the CRT control word 0x027f.
const projectile = JSON.parse(await readFile(new URL('../evidence/gameplay/native-projectile-fixtures-53.json', import.meta.url)));
const effects = JSON.parse(await readFile(new URL('../evidence/gameplay/native-effect-fixtures-53.json', import.meta.url)));
const precision = 53;

test('53-bit fixtures are the 0x027f probes of the original routines', () => {
  assert.equal(projectile.precision, 53);
  assert.equal(effects.precision, 53);
  assert.equal(projectile.entry, '0x455ce0');
});

test('53-bit projectile flight matches 480 original x86 cases', () => {
  for (const [index, fixture] of projectile.cases.entries()) {
    const shot = structuredClone(fixture.shot);
    updateNativeProjectileFlight(shot, fixture.delta, fixture.parameters, {
      groundHeight: () => fixture.groundHeight,
      targetPosition: fixture.targetPosition, rotationSpeed: 3000, precision,
    });
    for (const [key, expected] of Object.entries(fixture.expected)) {
      assert.deepEqual(shot[key], expected, `case ${index} ${key}`);
    }
  }
});

test('53-bit firing direction matches 360 original lane and graph queries', async () => {
  const tracks = await Promise.all(Array.from({ length: 6 }, (_, id) => readFile(
    new URL(`../public/assets/tracks/etappe${id}.json`, import.meta.url)).then(JSON.parse)));
  for (const [index, fixture] of projectile.facing.entries()) {
    assert.equal(nativeProjectileFacing(tracks[fixture.track], fixture.body, { ...fixture.options, precision }),
      fixture.expected, `facing ${index} on track ${fixture.track}`);
  }
});

test('53-bit held-fire gate and homing target selection are integer-only', () => {
  for (const fixture of projectile.gates) {
    const gate = new NativeFireGate(fixture.previous);
    assert.equal(gate.poll(fixture.held, fixture.now), fixture.fired);
    assert.equal(gate.lastFireMs, fixture.lastFireMs);
  }
  for (const fixture of projectile.targets) {
    assert.equal(selectNativeProjectileTarget(fixture.shooter, fixture.racers, fixture.sectorCount,
      fixture.lockRange, fixture.forward), fixture.expected);
  }
});

test('53-bit projectile launch pose matches 180 original cases', () => {
  for (const [index, fixture] of projectile.launches.entries()) {
    const result = nativeProjectileLaunchPose(fixture.body, fixture.radius, fixture.groundHeight, { precision });
    for (const [key, expected] of Object.entries(fixture.expected)) {
      assert.deepEqual(result[key], expected, `launch ${index} ${key}`);
    }
    assert.equal(fixture.untouchedClearance, 17.25);
  }
});

test('53-bit bubble fans match 120 original cases', () => {
  for (const [index, fixture] of projectile.fans.entries()) {
    const shot = structuredClone(fixture.shot), pool = structuredClone(fixture.pool);
    hatchNativeBubbles(shot, pool, fixture.extra, {}, { precision });
    for (const [key, expected] of Object.entries(fixture.expectedShot)) assert.deepEqual(shot[key], expected, `fan ${index} main ${key}`);
    for (const [slot, expectedSlot] of fixture.expectedPool.entries()) {
      for (const [key, expected] of Object.entries(expectedSlot)) {
        assert.deepEqual(pool[slot][key], expected, `fan ${index} slot ${slot} ${key}`);
      }
    }
  }
});

test('53-bit spin, gum and bubble updates match 600 original x86 effect cases', () => {
  for (const [index, fixture] of effects.cases.entries()) {
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

test('53-bit hit initializers match 120 original cases (precision-independent stores)', () => {
  for (const [index, fixture] of effects.initializations.entries()) {
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
