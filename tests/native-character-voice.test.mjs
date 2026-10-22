import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeRandom } from '../src/simulation/native-random.js';
import { NativeCharacterVoices, nativeCharacterVoiceId, selectNativeVoiceSample,
  nativePlayerHitSoundRequests } from '../src/simulation/native-character-voice.js';
import { NativeBonusPickups } from '../src/simulation/native-bonus.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/character-voice-fixtures.json', import.meta.url)));

test('400 original character/commentator selectors retain samples and shared random state', () => {
  for (const fixture of fixtures.selectors) {
    const random = new NativeRandom(fixture.seed);
    assert.equal(selectNativeVoiceSample(fixture.kind, random), fixture.sample);
    assert.equal(random.state, fixture.nextState);
  }
});

test('80 original racer mappings retain player fallback and country voices', () => {
  for (const f of fixtures.mapping) assert.equal(nativeCharacterVoiceId(f.racer, f.roster), f.expected);
});

test('560 original requests retain chance, replacement and exact draw order', () => {
  for (const f of fixtures.dispatch) {
    const random = new NativeRandom(f.seed);
    const voices = new NativeCharacterVoices({ random, racerAvailableIndices: f.roster });
    if (f.kind === 'replacePlayer') voices.replacePlayer('FIXED');
    else if (f.kind === 'replaceRacer') voices.replaceRacer(f.racer, 'FIXED');
    else if (f.kind === 'passing') voices.passing(f.racer, f.other);
    else if (f.kind === 'playerHitOther') voices.playerHitOther();
    else if (f.kind === 'npcHit') voices.npcHit(f.racer, f.shooter);
    else if (f.kind === 'npcHitPlayer') voices.npcHitPlayer(f.racer, f.mode);
    else if (f.kind === 'pickupBefore') voices.pickupBefore(f.racer);
    else assert.fail(f.kind);
    assert.deepEqual(voices.drain(), f.commands, `${f.kind} seed${f.seed}`);
    assert.equal(random.state, f.nextState, `${f.kind} seed${f.seed}`);
  }
});

test('160 original NPC catch-up requests retain mode/distance guards and horn queue order', () => {
  for (const f of fixtures.npcCatchup) {
    const random = new NativeRandom(f.seed);
    const voices = new NativeCharacterVoices({ random, racerAvailableIndices: f.roster });
    voices.npcCatchup(f);
    assert.deepEqual(voices.drain(), f.commands, `seed${f.seed}`);
    assert.equal(random.state, f.nextState);
  }
});

test('120 original rescue updates queue the correct actor only at frame3 without random draws', () => {
  for (const f of fixtures.rescue) {
    const random = new NativeRandom(f.seed);
    const voices = new NativeCharacterVoices({random, racerAvailableIndices: f.roster});
    const received = [];
    voices.onRequest = request => received.push(request);
    // Racer5 is an unmatched physical object in the original fixture.
    if (f.frame === 3 && f.racer < f.roster.length)
      voices.rescue(f.racer, f.shrinking ? 'DISAPP' : 'REAPP');
    assert.deepEqual(voices.commands, f.commands);
    assert.deepEqual(received, f.commands, 'logical requests reach the transport synchronously');
    assert.equal(random.state, f.nextState);
  }
});

test('120 original hit initializers retain player-only effects requests and native names', () => {
  for (const f of fixtures.hitEffects)
    assert.deepEqual(nativePlayerHitSoundRequests(f.type, f.level, f.player), f.commands);
});

test('140 complete native pickup dispatches preserve voice/random-type/AI-upgrade draw order', () => {
  const config = JSON.parse(readFileSync(new URL('../public/assets/config.json', import.meta.url)));
  for (const f of fixtures.collections) {
    const random = new NativeRandom(f.seed);
    const voices = new NativeCharacterVoices({random, racerAvailableIndices: f.roster});
    const pickups = new NativeBonusPickups({
      pickups: [{...f.pickup, position: [0, 0, 0], radius: 10}],
      racerCount: f.roster.length, raceType: 2,
      bonusConfig: config['game.ini'].bonus_data, random, voices,
    });
    Object.assign(pickups.pickups[0], f.pickup);
    Object.assign(pickups.owned[f.racer], f.owned);
    pickups.stars = f.stars;
    const animations = [];
    pickups.onAnimationEvent = (racer, {callback}) =>
      animations.push({callback, racer, randomState: random.state});
    pickups.step(0, 10, f.roster.map((_, index) => ({
      position: index === f.racer ? [0, 0, 0] : [10000, 0, 10000], radius: 10,
    })));
    assert.deepEqual(voices.commands, f.commands);
    assert.deepEqual(animations, f.animationCallbacks);
    assert.equal(random.state, f.expected.nextState);
    assert.equal(pickups.stars, f.expected.stars);
    for (const key of ['type', 'state', 'level', 'ageSeconds']) {
      assert.equal(pickups.owned[f.racer][key], f.expected.owned[key], `owned.${key}`);
      assert.equal(pickups.pickups[0][key], f.expected.pickup[key], `pickup.${key}`);
    }
  }
});

test('player hit requests preserve missing original symbolic names rather than inventing replacements', () => {
  assert.deepEqual(nativePlayerHitSoundRequests(1, 2), [
    { voiceId: 10, sample: 'HIT_BY_ROCKET', replace: true },
    { voiceId: 10, sample: 'IMR2', replace: false },
  ]);
  assert.deepEqual(nativePlayerHitSoundRequests(2, 3), [
    { voiceId: 10, sample: 'HIT_BY_SOAP', replace: true },
    { voiceId: 10, sample: 'SOAP_UP3', replace: false },
  ]);
  assert.deepEqual(nativePlayerHitSoundRequests(3, 1), [
    { voiceId: 10, sample: 'HIT_BY_OIL', replace: true },
    { voiceId: 10, sample: 'IMO1', replace: false },
  ]);
  assert.deepEqual(nativePlayerHitSoundRequests(4, 1), [
    { voiceId: 10, sample: 'HIT_BY_GUM', replace: true },
  ]);
  assert.deepEqual(nativePlayerHitSoundRequests(1, 2, false), []);
});
