import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeRaceState, nativeRaceSettings, nativeSectorDistance, nativeCrossedTriggers } from '../source/simulation/native-race.js';

const read = path => JSON.parse(readFileSync(new URL(path, import.meta.url)));
const fixtures = read('../evidence/gameplay/native-race-fixtures.json');
const tracks = Array.from({ length: 6 }, (_, i) => read(`../public/assets/tracks/etappe${i}.json`));
const config = read('../public/assets/config.json');

function makeRace(input = {}) {
  const race = new NativeRaceState({
    track: tracks[0], startSector: input.previous ?? 10,
    raceType: input.raceType ?? 0, lapLimit: input.lapLimit ?? 5,
    lapTimerLimitMs: 10000000, bestLapMs: input.bestLapMs ?? 0,
    bestRaceMs: input.bestRaceMs ?? 0,
    gateTimes: input.gateTimes ?? [25000, 23000, 25000, 23000],
  });
  for (const key of ['phase', 'finishArmed', 'lapCount', 'sessionBestLapMs', 'gateIndex', 'gateDistance', 'distance', 'lastTickSecond']) {
    if (key in input) race[key] = input[key];
  }
  race.elapsedMs = input.elapsedMs ?? 0;
  race.lapStartMs = race.elapsedMs - (input.lapTimeMs ?? 0);
  race.gateDeadlineMs = race.elapsedMs + (input.remainingMs ?? 0);
  return race;
}

test('240 native finish handler cases preserve direction guard, lap records, and finish phase', () => {
  for (const [index, fixture] of fixtures.finishCases.entries()) {
    const { input, expected } = fixture;
    const race = makeRace(input);
    race.trigger(14, { previous: input.previous, current: input.current });
    for (const key of ['phase', 'finishArmed', 'lapCount', 'sessionBestLapMs', 'bestLapMs', 'bestRaceMs', 'finished']) {
      assert.equal(race[key], expected[key], `finish ${index} ${key}`);
    }
    assert.equal(race.raceTimeMs ?? 0, expected.raceTimeMs);
    const laps = race.events.filter(event => event.type === 'lap');
    assert.equal(laps.length, expected.timerResetCount);
    assert.equal(laps[0]?.timeMs ?? 0, expected.lastLapTimeMs);
    const notifications = race.events.filter(event => ['last-lap', 'lap-record', 'native-notification'].includes(event.type));
    assert.equal(notifications.length, expected.notifications);
  }
});

test('240 native time-gate cases preserve sequential values and reverse re-entry guard', () => {
  for (const [index, fixture] of fixtures.gateCases.entries()) {
    const { input, expected } = fixture;
    const race = makeRace(input);
    race.trigger(74 + index % 3, { player: input.player });
    for (const key of ['phase', 'gateIndex', 'gateDistance', 'remainingMs']) {
      assert.equal(race[key], expected[key], `gate ${index} ${key}`);
    }
    assert.equal(race.events.filter(event => event.sound).length, expected.sounds);
  }
});

test('120 native timeout and countdown cases preserve event thresholds', () => {
  for (const [index, fixture] of fixtures.expiryCases.entries()) {
    const { input, expected } = fixture;
    const race = makeRace(input);
    race.endUpdate();
    for (const key of ['phase', 'lastTickSecond']) assert.equal(race[key], expected[key], `expiry ${index} ${key}`);
    assert.equal(race.events.filter(event => event.sound).length, expected.sounds);
  }
});

test('1296 native sector crossings preserve source trigger order, wrap, and signed progress', () => {
  for (const fixture of fixtures.crossings) {
    const track = tracks[fixture.track];
    assert.deepEqual(nativeCrossedTriggers(track, fixture.previous, fixture.current), fixture.triggers);
    assert.equal(nativeSectorDistance(fixture.current, fixture.previous, track.route.length) || 0, fixture.distance || 0);
  }
});

test('original lap counts and all eighteen time-gate configurations come from shipped INIs', () => {
  for (let track = 0; track < 6; track++) {
    for (let difficulty = 0; difficulty < 3; difficulty++) {
      const settings = nativeRaceSettings(config, track, difficulty, 1);
      assert.equal(settings.lapLimit, 5);
      assert.equal(settings.lapTimerLimitMs, 10000000);
      const source = config['track.ini'].time_gates[track * 3 + difficulty].split(',').map(Number);
      assert.deepEqual(settings.gateTimes, source.slice(1));
    }
  }
});

test('actual track routes complete five laps and time gates cannot be farmed by reversing', () => {
  for (const track of tracks) {
    const race = new NativeRaceState({
      track, startSector: 0, ...nativeRaceSettings(config, track.id ?? tracks.indexOf(track), 1, 0),
    });
    let activeMs = 0;
    for (let lap = 0; lap < 6 && !race.finished; lap++) {
      for (let sector = 1; sector <= track.route.length && !race.finished; sector++) {
        race.beginUpdate(sector % track.route.length, activeMs += 25);
        race.endUpdate();
      }
    }
    assert.equal(race.lapCount, 5);
    assert.equal(race.phase, 3);
  }
  const timed = makeRace({ raceType: 1, distance: 40, gateDistance: 0, remainingMs: 10000 });
  timed.trigger(74);
  const remaining = timed.remainingMs;
  for (const distance of [39, 40, 41]) {
    timed.distance = distance;
    timed.trigger(74);
    assert.equal(timed.remainingMs, remaining);
  }
  timed.distance = 42;
  timed.trigger(75);
  assert.ok(timed.remainingMs > remaining);
});
