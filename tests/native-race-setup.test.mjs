import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { nativeRaceRoster, nativeRaceGrid, nativeRaceSetup, NativeAIProgress, nativeAIProfile } from '../source/simulation/native-race-setup.js';
import { createNativeTrack } from '../source/simulation/native-track.js';
const read = name => JSON.parse(readFileSync(new URL(`../${name}`, import.meta.url)));
const config = read('public/assets/config.json');
const tracks = Array.from({ length: 6 }, (_, i) => read(`public/assets/tracks/etappe${i}.json`));
const worlds = tracks.map(createNativeTrack);
const nativeWorlds = read('evidence/gameplay/native-track-fixtures.json').tracks.map(data => ({ sectors: data.sectors }));
const fixtures = read('evidence/native/race-setup-fixtures.json');

test('All original NPC grid slots, heading and rank allocation match executed code', () => {
  for (const [i, c] of fixtures.cases.entries()) {
    const grid = nativeRaceGrid(tracks[c.track], nativeWorlds[c.track], c);
    const positions = [grid.player, ...grid.opponents].map(({ sector, position, yaw }) => ({ sector, position, yaw }));
    assert.deepEqual(positions, c.grid, `grid ${i}`);
    assert.deepEqual(grid.opponents.map(racer => racer.rank), c.ranks, `ranks ${i}`);
  }
});

test('Menu roster follows original country table and excludes selected player', () => {
  const countries = ['NEDERLAND', 'DUITSLAND', 'ENGELAND', 'FRANKRIJK', 'SPANJE', 'ITALIE'];
  const players = ['RedCat', 'WhizzKitty', 'Brutus', 'Max'];
  for (let trackIndex = 0; trackIndex < 6; trackIndex++) for (let selectedCharacter = 0; selectedCharacter < 4; selectedCharacter++) {
    const roster = nativeRaceRoster(config, { trackIndex, selectedCharacter });
    assert.equal(roster.opponents[0].mesh, countries[trackIndex]);
    assert.deepEqual(roster.opponents.slice(1).map(racer => racer.name), players.filter((_, i) => i !== selectedCharacter));
    assert.equal(roster.player.name, players[selectedCharacter]);
    assert.equal(roster.player.aiId, -1);
    assert.equal(roster.player.racerRecord, selectedCharacter);
    assert.ok(roster.opponents.every(racer => racer.racerRecord === racer.aiId && racer.carIndex === 1 && racer.profile.efficiency === 10));
  }
});

test('Race setup uses difficulty table and retains original spawn coordinates', () => {
  for (let difficulty = 0; difficulty < 3; difficulty++) {
    const setup = nativeRaceSetup(config, tracks[0], worlds[0], { difficulty });
    assert.equal(setup.racerTableFile, `assets/racer-tables/cars${difficulty}.dat`);
    assert.equal(setup.opponents.length, 4);
    assert.equal(setup.opponents[0].start.source, 'TRIGGER_POS_70');
  }
});

test('AI progress uses signed sector count and resets stationary-sector timer', () => {
  const progress = new NativeAIProgress(98, 100);
  assert.equal(progress.update(99, .025), 1);
  assert.equal(progress.update(0, .025), 2);
  assert.equal(progress.update(99, .025), 1);
  progress.update(99, .025);
  assert.equal(progress.sectorTime, Math.fround(.025));
  progress.update(98, .025);
  assert.equal(progress.distance, 0);
  assert.equal(progress.sectorTime, 0);
});

test('0x42c680 seeds the live player rank from Race.ini PLAYER.position except in race types 1 and 3', () => {
  for (const [raceType, expected] of [[0, 2], [2, 2], [1, 0], [3, 0]]) {
    const grid = nativeRaceGrid(tracks[0], worlds[0], { opponentCount: 4, previousFinishPosition: 2, raceType });
    assert.equal(grid.player.rank, expected, `race type ${raceType}`);
    assert.deepEqual(grid.opponents.map(racer => racer.rank), [0, 1, 2, 3, 4].filter(rank => rank !== expected));
  }
  assert.equal(nativeRaceGrid(tracks[0], worlds[0], { opponentCount: 2, previousFinishPosition: 4 }).player.rank, 2);
});

test('0x40fe50 keeps the raw efficiency level at profile +0x8 beside its looked-up rate', () => {
  const ini = config['npc_ai.ini'];
  for (let aiId = 0; ini[`person_${aiId}`]; aiId++) {
    const profile = nativeAIProfile(config, aiId), person = ini[`person_${aiId}`];
    assert.equal(profile.efficiencyLevel, Number(person.efficiency));
    assert.equal(profile.efficiency, Number(ini.rcr_global[`efficiency${profile.efficiencyLevel}`]));
    assert.equal(profile.drivingStyle, Number(person.driving_style));
  }
});
