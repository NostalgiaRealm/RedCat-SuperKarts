import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {NativeBonusCombat} from '../source/simulation/native-combat.js';
import {NativeCharacterVoices} from '../source/simulation/native-character-voice.js';
import {NativeRandom} from '../source/simulation/native-random.js';

const read = path => JSON.parse(readFileSync(new URL(path, import.meta.url)));
const fixture = read('../evidence/native/powerup-sound-flow-fixtures.json');
const originalConfig = read('../public/assets/config.json');

test('180 complete original turbo dispatches retain character-before-effect order, RNG and inventory state', () => {
  for (const row of fixture.rows) {
    const random = new NativeRandom(row.seed);
    const voices = new NativeCharacterVoices({random, racerAvailableIndices: row.roster});
    const owned = row.roster.map(() => ({type: 5, level: row.level, state: 2, ageSeconds: 0}));
    const actors = row.roster.map(() => ({radius: 1, body: {forwardSpeed: 100}}));
    // The original probe supplies these factors explicitly to isolate its
    // complete dispatcher from config loading. Keep the same boundary here.
    const config = {...originalConfig, 'game.ini': {...originalConfig['game.ini'], bonus_data: {
      ...originalConfig['game.ini'].bonus_data,
      bonus_turbo_factor0: '150', bonus_turbo_factor1: '200', bonus_turbo_factor2: '250',
    }}};
    const combat = new NativeBonusCombat({pickups: {random, voices, owned}, actors,
      config, manifest: {}, world: {sectors: []}, shotClearance: 0});
    combat.fire(row.shooter);
    const label = `player=${row.player}, level=${row.level}, seed=${row.seed}, character=${row.roster[1]}`;
    assert.deepEqual(voices.commands, row.expected.commands, label);
    assert.equal(random.state, row.expected.randomState, label);
    assert.equal(actors[row.shooter].body.forwardSpeed, row.expected.speed, label);
    assert.equal(owned[row.shooter].state, row.expected.ownedState, label);
  }
});
