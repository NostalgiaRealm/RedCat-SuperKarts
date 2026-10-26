import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import {
  nativeAdventureConfiguration, resetNativeAdventureProfile, nativeNextAdventureIndex,
  applyNativeAdventureResult, createNativeAdventureProfile, nativeAdventureProfilePatch,
  nativeAdventureSaveSlot, nativeFirstAdventureSaveSlot, nativeAdventureSavePath,
  readNativeAdventureProfile, nativeAdventureBriefing, beginNativeAdventureEvent,
  restartNativeAdventureProfile, nativeAdventureReward,
} from '../source/simulation/native-adventure.js';
import {NativeMenuRandom,nativeMenuRandomSeed,nativeAdventureOutcomeVoice} from '../source/simulation/native-menu-random.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/adventure-fixtures.json', import.meta.url)));
const config = JSON.parse(readFileSync(new URL('../public/assets/config.json', import.meta.url)));

test('960 original menu adventure results retain qualification, matrix progress and shared unlock order', () => {
  for (const f of fixtures.progression) {
    const profile = structuredClone(f.profile), options = structuredClone(f.options);
    const outcome = applyNativeAdventureResult(profile, f.result, options);
    assert.deepEqual(profile, f.expectedProfile, JSON.stringify(f));
    assert.deepEqual(options.locks, f.expectedLocks);
    assert.equal(outcome.advanced, f.expectedAdvanced);
    assert.equal(outcome.campaignCompleted, f.expectedCompleted);
  }
});

test('80 original new-profile resets preserve the reusable slot/type while clearing campaign fields', () => {
  for (const f of fixtures.resets) assert.deepEqual(resetNativeAdventureProfile(structuredClone(f.profile)), f.expected);
});

test('80 original completed-profile replay resets retain name, character, difficulty and country/type', () => {
  for (const f of fixtures.replays) assert.deepEqual(restartNativeAdventureProfile(structuredClone(f.profile)), f.expected);
});

test('128 original Delphi menu draws retain their separate unsigned stream and result voice pairs', () => {
  for (const f of fixtures.random) {
    const random=new NativeMenuRandom(f.seed);
    assert.equal(random.next(f.upper),f.expected);assert.equal(random.seed,f.nextSeed);
  }
  assert.equal(nativeMenuRandomSeed(new Date('2026-10-20T23:59:59.999Z')),86399999);
  for(let type=0;type<4;type++){
    assert.equal(nativeAdventureOutcomeVoice(false,type,new NativeMenuRandom(0)),47+type*2);
    assert.equal(nativeAdventureOutcomeVoice(true,type,new NativeMenuRandom(0)),55+type*2);
  }
  assert.equal(nativeAdventureReward(config,'star',0).source,'ster5.mpg');
  assert.equal(nativeAdventureReward(config,'win',3).source,'mxwin.mpg');
  assert.equal(nativeAdventureReward(config,'win',0).skippable,false);
});

test('45 original sequence transitions retain the thirty-event ceiling and completion sentinel', () => {
  for (const f of fixtures.nextIndex) assert.equal(nativeNextAdventureIndex(f.current, f.count), f.expected);
});

test('240 original debrief gates play the character movie only for successful adventure completion', () => {
  for (const fixture of fixtures.winMovieGate) {
    const options = nativeAdventureConfiguration(config);
    const profile = structuredClone(fixture.profile);
    const outcome = fixture.mode === 3
      ? applyNativeAdventureResult(profile, fixture.result, options) : null;
    assert.equal(Boolean(outcome?.campaignCompleted), fixture.expectedMovie,
      `mode${fixture.mode} character${profile.character} event${fixture.profile.adventure} rank${fixture.result.rank}`);
    if (fixture.expectedMovie) {
      assert.equal(fixture.profile.adventure, 23);
      assert.equal(fixture.nextPhase, 8);
      const order = fixture.events.filter(event => ['highscore', 'win-movie', 'profile-save', 'close-debrief'].includes(event));
      assert.deepEqual(order, ['highscore', 'win-movie', 'profile-save', 'close-debrief']);
    }
    if (fixture.mode !== 3) {
      assert.equal(fixture.expectedMovie, false);
      assert.deepEqual(fixture.events, ['highscore', 'quickrace-save', 'close-debrief']);
    }
  }
  for (const event of [5, 11, 17]) {
    assert.ok(fixtures.winMovieGate
      .filter(fixture => fixture.profile.adventure === event)
      .every(fixture => !fixture.expectedMovie), `completing race type at event${event} is not campaign end`);
  }
});

test('all four original movie constructors select the matching character WINMOVIES entry', () => {
  const names = ['RedCat', 'WhizzKitty', 'Brutus', 'Max'];
  const movies = ['rcwin.mpg', 'wkwin.mpg', 'brwin.mpg', 'mxwin.mpg'];
  for (const fixture of fixtures.winMovieKeys) {
    assert.equal(fixture.key, names[fixture.character]);
    assert.equal(fixture.isMovie, true);
    const reward = nativeAdventureReward(config, 'win', fixture.character);
    assert.equal(reward.source, config['ini/settings.ini'].winmovies[fixture.key.toLowerCase()]);
    assert.equal(reward.source, movies[fixture.character]);
    assert.equal(reward.form, 'TFRMADVENTWIN');
    assert.equal(reward.skippable, false);
    assert.equal(reward.image, false);
    const converted = new URL(`../public/assets/media/${movies[fixture.character].replace('.mpg', '.mp4')}`, import.meta.url);
    assert.ok(readFileSync(converted).length > 0);
  }
});

test('shipped adventure configuration contains the original 24 races, country locks and save matrix', () => {
  const adventure = nativeAdventureConfiguration(config);
  assert.equal(adventure.sequence.length, 24);
  assert.deepEqual(adventure.sequence.slice(0, 6).map(entry => entry.country), [0, 1, 4, 2, 3, 5]);
  assert.deepEqual(adventure.sequence.map(entry => entry.raceType), [0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3]);
  assert.deepEqual(adventure.locks, [false, false, true, true, true, true]);
  assert.deepEqual(adventure.requiredTypes, [true, true, true, true, false]);
  assert.deepEqual(adventure.unlockCountries, [4, 3, 2, 5, 0]);
  const profile = createNativeAdventureProfile('RedCat', { slot: 0 });
  const saved = nativeAdventureProfilePatch(profile);
  assert.equal(saved.playerdata.name, 'RedCat');
  assert.equal(saved.playerdata.difficulty, 1);
  assert.equal(Object.keys(saved.advmatrix).length, 6);
  for (const row of Object.values(saved.advmatrix)) assert.equal(row, '0,0,0,0,0');
  assert.deepEqual(readNativeAdventureProfile(saved, { slot: 0 }), profile);
  assert.equal(nativeAdventureSavePath(29), 'players/player29.dat');
  profile.adventure = 6;
  assert.deepEqual(nativeAdventureBriefing(profile, adventure), { index: 6, country: 1, raceType: 1, difficulty: 1 });
  assert.equal(profile.raceType, 0);
  beginNativeAdventureEvent(profile, adventure);
  assert.equal(profile.country, 1);
  assert.equal(profile.raceType, 1);
});

test('480 original save-slot lookups preserve ordering, no wrapping and the extra first-slot byte read', () => {
  for (const f of fixtures.slots) {
    for (const action of ['new', 'next', 'previous']) assert.equal(nativeAdventureSaveSlot(f.occupied, action, f.current), f.expected[action]);
    assert.equal(nativeFirstAdventureSaveSlot(f.occupied, f.trailingByte), f.expected.first);
  }
});
