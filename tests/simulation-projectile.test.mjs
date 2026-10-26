import { test } from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { updateNativeProjectileFlight, NativeFireGate, selectNativeProjectileTarget,
  nativeProjectileLaunchPose, nativeProjectileFacing, hatchNativeBubbles } from '../source/simulation/native-projectile.js';

const fixtures = JSON.parse(await readFile(new URL('../evidence/gameplay/native-projectile-fixtures.json', import.meta.url)));

test('projectile flight matches 480 original x86 cases at initialized 4096 angles', () => {
  for (const [index, fixture] of fixtures.cases.entries()) {
    const shot = structuredClone(fixture.shot);
    updateNativeProjectileFlight(shot, fixture.delta, fixture.parameters, {
      groundHeight: () => fixture.groundHeight,
      targetPosition: fixture.targetPosition, rotationSpeed: 3000,
    });
    for (const [key, expected] of Object.entries(fixture.expected)) {
      assert.deepEqual(shot[key], expected, `case ${index} ${key}`);
    }
  }
});

test('firing direction matches 360 original lane and graph queries across all six tracks', async () => {
  const tracks = await Promise.all(Array.from({ length: 6 }, (_, id) => readFile(
    new URL(`../public/assets/tracks/etappe${id}.json`, import.meta.url)).then(JSON.parse)));
  for (const [index, fixture] of fixtures.facing.entries()) {
    assert.equal(nativeProjectileFacing(tracks[fixture.track], fixture.body, fixture.options), fixture.expected,
      `facing ${index} on track ${fixture.track}`);
  }
});

test('held-fire unsigned timer gate matches 120 native cases including wrap', () => {
  for (const fixture of fixtures.gates) {
    const gate = new NativeFireGate(fixture.previous);
    assert.equal(gate.poll(fixture.held, fixture.now), fixture.fired);
    assert.equal(gate.lastFireMs, fixture.lastFireMs);
  }
});

test('homing sector target selection matches 240 native queries', () => {
  for (const fixture of fixtures.targets) {
    assert.equal(selectNativeProjectileTarget(fixture.shooter, fixture.racers, fixture.sectorCount,
      fixture.lockRange, fixture.forward), fixture.expected);
  }
});

test('projectile launch pose and inherited velocity match 180 original cases', () => {
  for (const [index, fixture] of fixtures.launches.entries()) {
    const result = nativeProjectileLaunchPose(fixture.body, fixture.radius, fixture.groundHeight);
    for (const [key, expected] of Object.entries(fixture.expected)) {
      assert.deepEqual(result[key], expected, `launch ${index} ${key}`);
    }
    assert.equal(fixture.untouchedClearance, 17.25);
  }
});

test('120 original bubble fans preserve pool order, inherited velocity and reused slot angles', () => {
  for (const [index, fixture] of fixtures.fans.entries()) {
    const shot = structuredClone(fixture.shot), pool = structuredClone(fixture.pool);
    hatchNativeBubbles(shot, pool, fixture.extra);
    for (const [key, expected] of Object.entries(fixture.expectedShot)) assert.deepEqual(shot[key], expected, `fan ${index} main ${key}`);
    for (const [slot, expectedSlot] of fixture.expectedPool.entries()) {
      for (const [key, expected] of Object.entries(expectedSlot)) {
        assert.deepEqual(pool[slot][key], expected, `fan ${index} slot ${slot} ${key}`);
      }
    }
  }
});
