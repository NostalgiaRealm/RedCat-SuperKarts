import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import {
  finalizeNativeOpponentResults, nativeRaceResultPatch, nativeHighscoreIndex,
  insertNativeHighscore, serializeNativeHighscore, nativeQuickRaceDebriefAction,
  nativeResultTimeParts, formatNativeResultTime,
} from '../src/simulation/native-results.js';

const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/result-fixtures.json', import.meta.url)));

test('360 complete original result finalizations preserve integer estimates and trailing-record quirk', () => {
  for (const f of fixtures.finalization) {
    const opponents = structuredClone(f.opponents), paused = [];
    finalizeNativeOpponentResults(opponents, {
      ...f.options, readTimer: index => f.timerValues[index], pauseTimer: index => paused.push(index),
    });
    assert.deepEqual(opponents, f.expected);
    assert.deepEqual(paused, f.paused);
  }
});

test('120 original save operations preserve completion gating, player/racer fields and checkpoint limits', () => {
  for (const f of fixtures.patches) assert.deepEqual(nativeRaceResultPatch(f.input), f.expected);
});

test('500 original menu high-score lookups sort best laps and preserve ties and signed arithmetic', () => {
  for (const f of fixtures.highscoreIndex) assert.equal(nativeHighscoreIndex(f.entries, f.bestLapMs), f.expected);
});

test('500 original menu high-score insertions retain complete rows and shift only lower scores', () => {
  for (const f of fixtures.highscoreInsert) {
    assert.deepEqual(insertNativeHighscore(f.entries, f.record, f.index).entries, f.expected);
  }
});

test('source-derived score record and QuickRace debrief transitions match their original formats', () => {
  assert.equal(serializeNativeHighscore({ name: 'RedCat', character: 0, totalRaceMs: 65432, bestLapMs: 21000, difficulty: 2 }), 'RedCat,0,65432,21000,2');
  assert.deepEqual(nativeQuickRaceDebriefAction('retry'), { processHighscore: true, modalResult: 4, nextPhase: 'PHASE_RETRY' });
  assert.deepEqual(nativeQuickRaceDebriefAction('main'), { processHighscore: true, modalResult: 8, nextPhase: 'PHASE_MAIN' });
});

test('528 original Delphi time components retain precision-dependent truncation and centisecond rounding', () => {
  for (const f of fixtures.timeParts) assert.deepEqual(nativeResultTimeParts(f.milliseconds, f), f.expected, JSON.stringify(f));
  assert.equal(formatNativeResultTime(0), '0:00:00');
  assert.equal(formatNativeResultTime(60000), '1:60:00');
  assert.equal(formatNativeResultTime(999), '0:00:100');
});
