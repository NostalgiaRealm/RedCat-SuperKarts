import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeRandom, collectNativeBonus, advanceNativePickup, applyNativeTurbo, nativeBonusOverlap,
  nativeEnabledBonuses, nativeCanCollectBonus, NativeBonusPickups, nativeTrackPickups,
  nativeBonusParameters, updateNativeOwnedBonusVisual } from '../source/simulation/native-bonus.js';
import { SimulationClock } from '../source/simulation/clock.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/gameplay/native-bonus-fixtures.json', import.meta.url)));
const config = JSON.parse(readFileSync(new URL('../public/assets/config.json', import.meta.url)))['game.ini'].bonus_data;

test('420 native bonus pickups preserve stacking, replacement, random types, stars, and AI extra levels', () => {
  for (const fixture of fixtures.collections) {
    const pickup = { ...fixture.pickup }, owned = { ...fixture.owned };
    const controller = { stars: fixture.stars }, random = new NativeRandom(fixture.seed);
    collectNativeBonus(pickup, owned, controller, { player: fixture.player, random });
    assert.deepEqual(pickup, fixture.expected.pickup);
    assert.deepEqual(owned, fixture.expected.owned);
    assert.equal(controller.stars, fixture.expected.stars);
    assert.equal(random.state, fixture.expected.randomState);
  }
});

test('180 native respawn cases preserve the five-second threshold, forty-object cap, and permanent stars', () => {
  for (const fixture of fixtures.respawns) {
    const pickup = { ...fixture.pickup };
    advanceNativePickup(pickup, fixture.delta, {
      respawnSeconds: Number(config.bonus_respawn_time) / 1000,
      enabled: fixture.enabled, activeBonusCount: fixture.activeCount,
    });
    assert.deepEqual(pickup, fixture.expected);
  }
});

test('33 native turbo cases multiply signed speed once, including standstill and reverse', () => {
  for (const fixture of fixtures.turbo) {
    const body = { forwardSpeed: fixture.speed };
    assert.equal(applyNativeTurbo(body, fixture.level, config), fixture.expected);
  }
});

test('240 native pickup contact cases preserve planar and vertical strict radius comparisons', () => {
  for (const fixture of fixtures.overlaps) {
    assert.equal(nativeBonusOverlap(fixture.a, fixture.b), fixture.expected);
  }
});

test('native mode constructors and 120 cooldown checks preserve original visibility and strict deadlines', () => {
  for (const fixture of fixtures.modes) {
    assert.deepEqual([...nativeEnabledBonuses(fixture.mode)].sort(), fixture.enabledTypes);
  }
  for (const fixture of fixtures.cooldowns) {
    assert.equal(nativeCanCollectBonus(fixture.now, fixture.deadline), fixture.expected);
  }
});

test('all twelve projectile parameter records match original static constructor and INI loader', () => {
  assert.deepEqual(nativeBonusParameters(config), fixtures.parameters);
});

test('120 native owned-item visual updates preserve yaw and the original cosine-valued pitch', () => {
  for (const fixture of fixtures.ownedVisuals) {
    const owned = { angles: [...fixture.angles] };
    updateNativeOwnedBonusVisual(owned, fixture.delta, fixture.rotationSpeed);
    assert.deepEqual(owned.angles, fixture.expected);
  }
});

test('connected pickup ordering gives opponents first contact and reserves stars for the player', () => {
  const pickups = [
    { type: 1, position: [0, 0, 0], radius: 10 },
    { type: 6, position: [0, 0, 0], radius: 10 },
  ];
  const controller = new NativeBonusPickups({ pickups, racerCount: 2, raceType: 2, bonusConfig: config, random: new NativeRandom(1) });
  const racers = [{ position: [0, 0, 0], radius: 10 }, { position: [0, 0, 0], radius: 10 }];
  const events = controller.step(0.025, 0.025, racers);
  assert.equal(events[0].racer, 0);
  assert.equal(events[0].type, 'bonus');
  assert.equal(events[1].racer, 1);
  assert.equal(events[1].type, 'star');
  assert.equal(controller.stars, 1);
  assert.equal(controller.owned[0].level, 3);
  assert.equal(controller.owned[1].state, 1);
  controller.step(5, 5.025, racers);
  assert.equal(controller.pickups[0].state, 2);
  assert.equal(controller.pickups[1].state, 1);
  assert.equal(controller.stars, 1);
});

test('soft-lock return suppresses player collection while opponents and subsequent normal collection continue', () => {
  const controller=new NativeBonusPickups({pickups:[
    {type:1,position:[0,0,0],radius:10},{type:6,position:[0,0,0],radius:10},
  ],racerCount:2,raceType:2,bonusConfig:config,random:new NativeRandom(1)});
  const racers=[{position:[0,0,0],radius:10},{position:[0,0,0],radius:10,canCollect:false}];
  const events=controller.step(.025,.025,racers);
  assert.equal(events.length,1);assert.equal(events[0].racer,0);
  assert.equal(controller.stars,0);assert.equal(controller.pickups[1].state,2);
  assert.equal(controller.eligibleAfter[1],0);
  delete racers[1].canCollect;
  racers[1].excludedPickups=new Set([1]);
  assert.equal(controller.step(.025,.05,racers).length,0);
  assert.equal(controller.stars,0);
  racers[1].excludedPickups.clear();
  const resumed=controller.step(.025,.075,racers);
  assert.equal(resumed.length,1);assert.equal(resumed[0].type,'star');
  assert.equal(controller.stars,1);
});

test('all six source pickup layouts collect identically across render rates and retain twelve permanent stars', () => {
  const manifest = JSON.parse(readFileSync(new URL('../public/assets/manifest.json', import.meta.url)));
  for (let trackId = 0; trackId < 6; trackId++) {
    const track = JSON.parse(readFileSync(new URL(`../public/assets/tracks/etappe${trackId}.json`, import.meta.url)));
    const pickups = nativeTrackPickups(track, manifest);
    const run = fps => {
      const controller = new NativeBonusPickups({
        pickups, racerCount: 1, raceType: 2, bonusConfig: config, random: new NativeRandom(2000),
      });
      const events = [], endMs = pickups.length * 500;
      const clock = new SimulationClock({ intervalMs: 25, update: (dt, activeMs) => {
        // Contact positions are explicit replay inputs, not a claimed native driving trace.
        const target = Math.min(pickups.length - 1, Math.floor((activeMs - 25) / 500));
        const racer = { position: pickups[target].position, radius: manifest.meshes['kart03.d3d'].horizontalRadius };
        events.push(...controller.step(dt, activeMs / 1000, [racer]).map(event => ({ ...event, activeMs })));
      } });
      clock.frame(0);
      for (let time = 1000 / fps; time < endMs; time += 1000 / fps) clock.frame(time);
      clock.frame(endMs);
      return { stars: controller.stars, events, owned: controller.owned, pickups: controller.pickups };
    };
    const expected = run(32);
    assert.equal(expected.stars, 12, `track ${trackId}`);
    for (const fps of [31, 60, 120, 144, 240]) assert.deepEqual(run(fps), expected, `track ${trackId}, ${fps} FPS`);
  }
});
