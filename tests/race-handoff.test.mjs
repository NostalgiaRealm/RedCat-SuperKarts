// node --test tests/race-handoff.test.mjs
// The menu -> race INI handoff (source/host/race-handoff.js) against the original's recorded handoff
// (../RedCat Superkarts/evidence/native/runtime/race-before-start.ini -> race-after-launch.ini), the JS reconstruction's
// own functions (nativeRaceRoster, configWithNativeDisplaySettings, settingsAudioPercent, nativeBindingCode,
// nativeRaceResultPatch, applyRaceResult) and the race's exit files from the headless probe
// (evidence/checks/race-handoff/*.race-exit.ini, written by tools/checks/race-handoff-probe.mjs and race-handoff-drive.mjs).
import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync, readdirSync, existsSync } from 'node:fs';
import { join } from 'node:path';
import {
  writeHandoff, readResult, codeToVk, bindingsToVk, audioPercent, COUNTRY_NAMES, COUNTRY_MESHES, CHARACTER_NAMES,
  OPPONENTS, DEFAULT_VK, INPUT_KEYS, BINDING_ACTIONS, PRISTINE_FILES, NO_RECORD,
} from '../source/host/race-handoff.js';
import { pinRace, COUNTRIES } from '../source/host/race-setup.js';
import { vkOf } from '../source/input/keyboard.js';
import { IniFile } from '../source/host/vfs.js';
import {
  installationVfs, haveData, haveJs, jsModule, defaultSettings, expectedPatch, text, iniObject, DATA, RECORDED, EVIDENCE, RACE_KEYS,
} from '../tools/checks/race-handoff-lib.mjs';

const skip = !haveData() ? 'installation data not found (SUPERKARTS_DATA)' : !haveJs() ? 'JS reconstruction not found (SUPERKARTS_JS)' : false;
const ini = (vfs, file) => new IniFile(text(vfs.read(file)));
const get = (vfs, file, s, k) => vfs.iniGet(file, s, k);
const bytesOf = (vfs) => Object.fromEntries(PRISTINE_FILES.map((f) => [f, text(vfs.read(f))]));
const NED = 0, DUI = 1, ENG = 2, FRA = 3, SPA = 4, ITA = 5;

test('countries follow track.ini [MAPS] and the menu table 0x47bc80', { skip }, () => {
  const maps = iniObject(readFileSync(join(DATA, 'track.ini'), 'latin1')).maps;
  const names = Array.from({ length: Number(maps.count) }, (_, i) => maps[i].split(',')[8]);
  assert.deepEqual([...COUNTRY_NAMES], names);
  assert.deepEqual([...COUNTRIES], names);
  assert.deepEqual([...COUNTRY_MESHES], names.map((n) => n.toUpperCase()));
});

test('roster, car, race type and etappe for every race type, character and country = JS port nativeRaceRoster', { skip }, async () => {
  const { nativeRaceRoster, NATIVE_MENU_OPPONENT_COUNTS, NATIVE_PLAYER_NAMES, NATIVE_COUNTRY_MESHES } = await jsModule('simulation/native-race-setup.js');
  assert.deepEqual([...OPPONENTS], [...NATIVE_MENU_OPPONENT_COUNTS]);
  assert.deepEqual([...CHARACTER_NAMES], [...NATIVE_PLAYER_NAMES]);
  assert.deepEqual([...COUNTRY_MESHES], [...NATIVE_COUNTRY_MESHES]);
  const config = { 'game.ini': iniObject(readFileSync(join(DATA, 'game.ini'), 'latin1')), 'npc_ai.ini': iniObject(readFileSync(join(DATA, 'npc_ai.ini'), 'latin1')) };
  const vfs = installationVfs();                         // one Vfs for all 96: every call starts from the installation copies
  let n = 0;
  for (let raceType = 0; raceType < 4; raceType++) for (let character = 0; character < 4; character++) for (let country = 0; country < 6; country++) {
    const sum = writeHandoff(vfs, { country, character, raceType, difficulty: 1 });
    const js = nativeRaceRoster(config, { selectedCharacter: character, trackIndex: country, opponentCount: OPPONENTS[raceType] });
    const opp = js.opponents.length;
    const want = [...js.opponents.map((o) => `${o.name},${o.mesh},${o.aiId},${o.color}`), `${js.player.name},${js.player.mesh},-1,${js.player.color}`];
    const got = Array.from({ length: opp + 1 }, (_, i) => get(vfs, 'race.ini', 'CHARDATA', String(i)));
    const at = `raceType ${raceType} character ${character} country ${country}`;
    assert.deepEqual(got, want, at);
    assert.deepEqual(sum.roster, want, at);
    assert.equal(get(vfs, 'race.ini', 'CHARDATA', 'count'), String(opp + 1), at);
    assert.equal(get(vfs, 'race.ini', 'RACETYPEINFO', 'opponents'), String(opp), at);
    assert.equal(get(vfs, 'race.ini', 'RACETYPEINFO', 'RaceType'), String(raceType), at);
    assert.equal(get(vfs, 'race.ini', 'ETAPPE', 'etappe'), String(country), at);
    assert.equal(get(vfs, 'race.ini', 'PLAYER', 'car'), String(js.player.carIndex), at);
    // the old rows 0..4 went (0x46edd0); the installation's rows 5..9 stay
    for (let i = opp + 1; i < 5; i++) assert.equal(get(vfs, 'race.ini', 'CHARDATA', String(i)), null, at);
    assert.equal(get(vfs, 'race.ini', 'CHARDATA', '5'), 'Engeland,ENGELAND,6,0', at);
    // [RACERS] 0..opponents-1 readable (load_racer_info)
    for (let i = 0; i < opp; i++) assert.match(get(vfs, 'race.ini', 'RACERS', String(i)), /^-?\d+,-?\d+,-?\d+$/, at);
    assert.equal(get(vfs, 'race.ini', 'ETAPPE', 'british'), '0', at);
    assert.equal(get(vfs, 'race.ini', 'ETAPPE', 'direction'), null, at);
    n++;
  }
  assert.equal(n, 96);
});

test('roster examples of the spec (menu traces)', { skip }, () => {
  const rows = (cfg) => writeHandoff(installationVfs(), cfg).roster;
  assert.deepEqual(rows({ character: 1, country: ENG, raceType: 0 }),
    ['Engeland,ENGELAND,5,0', 'RedCat,REDCAT,0,0', 'Brutus,BRUTUS,2,0', 'Max,MAX,3,0', 'WhizzKitty,WHIZZKITTY,-1,0']);
  assert.deepEqual(rows({ character: 2, country: FRA, raceType: 1 }),
    ['RedCat,REDCAT,0,0', 'WhizzKitty,WHIZZKITTY,1,0', 'Max,MAX,3,0', 'Brutus,BRUTUS,-1,0']);
  assert.deepEqual(rows({ character: 3, country: SPA, raceType: 2 }),
    ['RedCat,REDCAT,0,0', 'WhizzKitty,WHIZZKITTY,1,0', 'Brutus,BRUTUS,2,0', 'Max,MAX,-1,0']);
  assert.deepEqual(rows({ character: 0, country: ITA, raceType: 3 }), ['Italie,ITALIE,9,0', 'RedCat,REDCAT,-1,0']);
  assert.deepEqual(rows({ character: 0, country: DUI, raceType: 3 }), ['Duitsland,DUITSLAND,6,0', 'RedCat,REDCAT,-1,0']);
});

test('recorded handoff: RedCat / Normaal / Nederland / Landenrace from the WhizzKitty state = race-after-launch.ini', { skip }, async () => {
  const before = readFileSync(join(RECORDED, 'race-before-start.ini'));
  const after = new IniFile(readFileSync(join(RECORDED, 'race-after-launch.ini'), 'latin1'));
  const settings = await defaultSettings();
  const vfs = installationVfs();
  writeHandoff(vfs, { country: NED, character: 0, difficulty: 1, raceType: 0 }, { bestTimes: {} }, settings, { 'race.ini': new Uint8Array(before) });
  const got = ini(vfs, 'race.ini');
  for (const [, s, k] of RACE_KEYS) assert.equal(got.get(s, k), after.get(s, k), `race.ini [${s}] ${k}`);
  // every key outside the menu's own profile sections is the recorded one
  for (const s of after.sections()) {
    if (/^(playerdata|advmatrix)$/i.test(s)) continue;
    for (const k of after.keys(s)) assert.equal(got.get(s, k), after.get(s, k), `race.ini [${s}] ${k}`);
    for (const k of got.keys(s)) assert.notEqual(after.get(s, k), null, `race.ini [${s}] ${k} is extra`);
  }
  // game.ini and SndGfx.ini: the default settings are the installation's values
  const game = ini(vfs, 'game.ini'), gfx = ini(vfs, 'SndGfx.ini');
  assert.equal(game.get('OPTIONS', 'Difficulty'), '1');
  assert.equal(game.get('OPTIONS', 'FILTER'), '2');
  assert.deepEqual(INPUT_KEYS.map((k) => game.get('INPUT', k)), ['38', '40', '37', '39', '17', '18']);
  assert.equal(game.get('PROGRAM', 'RESOLUTION'), '3');
  assert.deepEqual(['gamma', 'alpha_blending', 'particles', 'windowed'].map((k) => gfx.get('GFX OPTIONS', k)), ['0', '2', '1', '0']);
  assert.equal(gfx.get('DIRECTX', 'index'), '0');
  // and from the installation copy (itself this recorded handoff), nothing the race reads changes
  const plain = installationVfs();
  const install = ini(plain, 'race.ini');
  writeHandoff(plain, { country: NED, character: 0, difficulty: 1, raceType: 0 }, null, settings);
  for (const [, s, k] of RACE_KEYS) assert.equal(get(plain, 'race.ini', s, k), install.get(s, k), `installation race.ini [${s}] ${k}`);
});

test('key bindings: uppercase virtual keys, the page keyboard table, the JS port codes', { skip }, async () => {
  const { nativeBindingCode, NATIVE_DEFAULT_KEYS, NATIVE_CONTROL_ACTIONS, browserBindingCode } = await jsModule('native-control-settings.js');
  assert.deepEqual([...BINDING_ACTIONS], [...NATIVE_CONTROL_ACTIONS]);
  assert.deepEqual(BINDING_ACTIONS.map((a) => DEFAULT_VK[a]), [...NATIVE_DEFAULT_KEYS]);
  const codes = ['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight', 'ControlLeft', 'ControlRight', 'AltLeft', 'AltRight', 'ShiftLeft',
    'ShiftRight', 'Space', 'Enter', 'Tab', 'Backspace', 'Escape', 'PageUp', 'PageDown', 'End', 'Home', 'Delete', 'Insert', 'NumpadEnter',
    'F1', 'F12', 'Numpad0', 'Numpad9', ...Array.from({ length: 26 }, (_, i) => 'Key' + String.fromCharCode(65 + i)),
    ...Array.from({ length: 10 }, (_, i) => 'Digit' + i)];
  for (const code of codes) assert.equal(codeToVk(code), vkOf({ code }), code);     // what the page sets for that key
  // every key the original dialog accepts (4620ec: A..Z, Enter, Shift/Ctrl/Alt, Space..Down), through the JS port's codes
  const accepted = [...Array.from({ length: 26 }, (_, i) => 65 + i), 13, 16, 17, 18, 32, 33, 34, 35, 36, 37, 38, 39, 40];
  for (const vk of accepted) {
    const code = browserBindingCode(vk);
    const js = nativeBindingCode(code);
    assert.equal(codeToVk(code), js >= 97 && js <= 122 ? js - 32 : js, `${code}: JS ${js}`);
  }
  assert.equal(codeToVk(''), 0);
  assert.equal(codeToVk('Nonsense'), 0);
  assert.equal(codeToVk(undefined), 0);
  assert.deepEqual(bindingsToVk(null), { ...DEFAULT_VK });
  assert.deepEqual(bindingsToVk(await defaultSettings()), { ...DEFAULT_VK });
  const wasd = { bindings: { accelerate: 'KeyW', brake: 'KeyS', left: 'KeyA', right: 'KeyD', bonus: 'Space', handbrake: '' } };
  assert.deepEqual(bindingsToVk(wasd), { accelerate: 87, brake: 83, left: 65, right: 68, bonus: 32, handbrake: 0 });
  assert.deepEqual(bindingsToVk({ bindings: { accelerate: 'KeyQ' } }), { ...DEFAULT_VK, accelerate: 81 });
  const vfs = installationVfs();
  const sum = writeHandoff(vfs, { raceType: 0 }, null, wasd);
  assert.deepEqual(INPUT_KEYS.map((k) => get(vfs, 'game.ini', 'INPUT', k)), ['87', '83', '65', '68', '32', '0']);
  assert.deepEqual(sum.bindings, bindingsToVk(wasd));
  writeHandoff(vfs, { raceType: 0 }, null, null);       // no settings: the installation's keys again
  assert.deepEqual(INPUT_KEYS.map((k) => get(vfs, 'game.ini', 'INPUT', k)), ['38', '40', '37', '39', '17', '18']);
});

test('display options = JS port configWithNativeDisplaySettings, all 16 combinations', { skip }, async () => {
  const { configWithNativeDisplaySettings } = await jsModule('simulation/native-display-settings.js');
  const base = { 'game.ini': iniObject(readFileSync(join(DATA, 'game.ini'), 'latin1')), 'sndgfx.ini': iniObject(readFileSync(join(DATA, 'SndGfx.ini'), 'latin1')) };
  const vfs = installationVfs();
  for (let m = 0; m < 16; m++) {
    const display = { brightnessLight: !!(m & 1), bilinearFiltering: !!(m & 2), alphaBlending: !!(m & 4), particles: !!(m & 8) };
    const js = configWithNativeDisplaySettings(base, display);
    writeHandoff(vfs, {}, null, { display });
    assert.equal(get(vfs, 'game.ini', 'OPTIONS', 'FILTER'), js['game.ini'].options.filter, JSON.stringify(display));
    for (const k of ['gamma', 'alpha_blending', 'particles']) assert.equal(get(vfs, 'SndGfx.ini', 'GFX OPTIONS', k), js['sndgfx.ini']['gfx options'][k], `${k} ${JSON.stringify(display)}`);
  }
  writeHandoff(vfs, {}, null, { display: { particles: false } });        // only booleans count
  assert.equal(get(vfs, 'game.ini', 'OPTIONS', 'FILTER'), '2');
  assert.equal(get(vfs, 'SndGfx.ini', 'GFX OPTIONS', 'particles'), '0');
});

test('volumes = JS port settingsAudioPercent; CONTROL 0 and the pins always', { skip }, async () => {
  const { settingsAudioPercent } = await jsModule('audio-mixing.js');
  const vfs = installationVfs();
  for (const f of [0, 0.004, 0.005, 0.07, 0.29, 0.5, 0.555, 0.994, 0.995, 1]) {
    const sum = writeHandoff(vfs, {}, null, { music: f, effects: 1 - f });
    assert.equal(get(vfs, 'race.ini', 'GAME_SETTINGS', 'MX_VOLUME'), String(settingsAudioPercent(f)), `music ${f}`);
    assert.equal(get(vfs, 'race.ini', 'GAME_SETTINGS', 'FX_VOLUME'), String(settingsAudioPercent(1 - f)), `effects ${1 - f}`);
    assert.deepEqual(sum.volumes, { music: settingsAudioPercent(f), effects: settingsAudioPercent(1 - f) });
    assert.equal(audioPercent(f), settingsAudioPercent(f));
  }
  vfs.iniSet('race.ini', 'GAME_SETTINGS', 'CONTROL', '2');
  vfs.iniSet('game.ini', 'PROGRAM', 'RESOLUTION', '5');
  writeHandoff(vfs, {}, null, null, { 'race.ini': text(vfs.read('race.ini')), 'game.ini': text(vfs.read('game.ini')) });
  assert.equal(get(vfs, 'race.ini', 'GAME_SETTINGS', 'CONTROL'), '0');
  assert.equal(get(vfs, 'race.ini', 'GAME_SETTINGS', 'MX_VOLUME'), '100');  // that pristine copy's values: no settings, no change
  assert.equal(get(vfs, 'race.ini', 'GAME_SETTINGS', 'FX_VOLUME'), '0');
  assert.equal(get(vfs, 'game.ini', 'PROGRAM', 'RESOLUTION'), '3');
  for (const k of ['DEBUGON', 'TWEAK_MODE', 'ENABLE_RRM']) assert.equal(get(vfs, 'game.ini', 'HELPDESK', k), '0');
  assert.equal(get(vfs, 'game.ini', 'PROGRAM', 'switch'), '0');
  assert.equal(get(vfs, 'SndGfx.ini', 'GFX OPTIONS', 'windowed'), '0');
  assert.equal(get(vfs, 'SndGfx.ini', 'DIRECTX', 'index'), '0');
});

test('records of this etappe (uppercase), position and difficulty from the save', { skip }, () => {
  const vfs = installationVfs();
  const save = { bestTimes: { lap_record_e0: 61234, race_record_e0: 345678, lap_record_e2: 70000, race_record_e2: 400000,
    time_check_count_e2: 2, time_check_e2_c0: 20000, time_check_e2_c1: 41000, time_check_e0_c0: 1, LAP_RECORD_E3: 5, race_record_e4: -1 }, playerPosition: 3 };
  const sum = writeHandoff(vfs, { country: ENG, difficulty: 0, raceType: 0 }, save);
  const bt = ini(vfs, 'race.ini');
  assert.deepEqual(bt.keys('BEST TIMES'), ['LAP_RECORD_E2', 'RACE_RECORD_E2', 'TIME_CHECK_COUNT_E2', 'TIME_CHECK_E2_C0', 'TIME_CHECK_E2_C1']);
  assert.deepEqual(bt.keys('BEST TIMES').map((k) => bt.get('BEST TIMES', k)), ['70000', '400000', '2', '20000', '41000']);
  assert.equal(get(vfs, 'race.ini', 'PLAYER', 'position'), '3');
  assert.equal(sum.position, 3);
  assert.equal(get(vfs, 'game.ini', 'OPTIONS', 'Difficulty'), '0');
  assert.equal(get(vfs, 'race.ini', 'PLAYER', 'finished'), '0');
  assert.equal(get(vfs, 'race.ini', 'PLAYER', 'damage'), '0');
  writeHandoff(vfs, { country: NED, raceType: 0 }, save);           // every save key of the etappe, as the JS port's configWithRaceSave
  assert.deepEqual(ini(vfs, 'race.ini').keys('BEST TIMES'), ['LAP_RECORD_E0', 'RACE_RECORD_E0', 'TIME_CHECK_E0_C0']);
  writeHandoff(vfs, { country: 3, raceType: 0 }, save);             // uppercase save keys work too
  assert.deepEqual(ini(vfs, 'race.ini').keys('BEST TIMES'), ['LAP_RECORD_E3']);
  // a finished lastResult's position counts when playerPosition is missing (race-save.js savedPlayerPosition)
  writeHandoff(vfs, {}, { bestTimes: {}, lastResult: { PLAYER: { finished: 1, position: 2 } } });
  assert.equal(get(vfs, 'race.ini', 'PLAYER', 'position'), '2');
  writeHandoff(vfs, {}, { bestTimes: {}, playerPosition: 12, lastResult: { PLAYER: { finished: 0 } } });
  assert.equal(get(vfs, 'race.ini', 'PLAYER', 'position'), '0');       // the installation's
  writeHandoff(vfs, {}, null);
  assert.equal(get(vfs, 'game.ini', 'OPTIONS', 'Difficulty'), '1');      // no difficulty: the installation's
});

test('a Vfs used for a second race starts from the installation copies (nothing of the first race leaks)', { skip }, async () => {
  const settings = await defaultSettings();
  const cfg2 = { country: SPA, character: 3, difficulty: 2, raceType: 2 };
  const fresh = installationVfs();
  writeHandoff(fresh, cfg2, { bestTimes: { lap_record_e4: 80000 } }, settings);
  const reused = installationVfs();
  writeHandoff(reused, { country: ENG, character: 1, difficulty: 0, raceType: 0 }, { bestTimes: { lap_record_e2: 1 }, playerPosition: 4 },
    { ...settings, music: 0.2, display: { brightnessLight: false, bilinearFiltering: false, alphaBlending: false, particles: false },
      bindings: { ...settings.bindings, accelerate: 'KeyW' } });
  // what a race writes (its boot and exit writes, full-race-gaps evidence)
  for (const [f, s, k, v] of [['race.ini', 'PLAYER', 'finished', '1'], ['race.ini', 'RACERS', '9', '1,2,3'], ['race.ini', 'BEST TIMES', 'LAP_RECORD_E2', '60000'],
    ['race.ini', 'GAME_SETTINGS', 'FX_VOLUME', '75'], ['game.ini', 'PROGRAM', 'RESTART', '1'], ['game.ini', 'PROGRAM', 'switch', '1'],
    ['npc_ai.ini', 'Person_0', 'type', 'X'], ['race.ini', 'ETAPPE', 'direction', '1']]) reused.iniSet(f, s, k, v);
  writeHandoff(reused, cfg2, { bestTimes: { lap_record_e4: 80000 } }, settings);
  assert.deepEqual(bytesOf(reused), bytesOf(fresh));
  // pristine copies handed over explicitly win over the remembered ones
  const given = installationVfs();
  const raceText = text(given.read('race.ini')).replace('Euro=991', 'Euro=5');
  writeHandoff(given, cfg2, null, null, new Map([['Race.INI', raceText]]));
  assert.equal(get(given, 'race.ini', 'PLAYER', 'Euro'), '5');
  writeHandoff(given, cfg2);
  assert.equal(get(given, 'race.ini', 'PLAYER', 'Euro'), '5');
});

test('pinRace is a thin wrapper over writeHandoff', { skip }, () => {
  const a = installationVfs(), b = installationVfs();
  pinRace(a, { etappe: ENG, car: 1 });
  writeHandoff(b, { country: ENG, character: 1, raceType: 0 });
  assert.deepEqual(bytesOf(a), bytesOf(b));
  const c = installationVfs(), d = installationVfs();
  pinRace(c, { etappe: ITA, car: 2, raceType: 3, difficulty: 0, fx: 40, music: 55 });
  writeHandoff(d, { country: ITA, character: 2, raceType: 3, difficulty: 0 }, null, { music: 0.55, effects: 0.4 });
  assert.deepEqual(bytesOf(c), bytesOf(d));
  assert.equal(get(c, 'race.ini', 'GAME_SETTINGS', 'FX_VOLUME'), '40');
});

test('config outside the menu choices is refused', { skip }, () => {
  const vfs = installationVfs();
  for (const cfg of [{ raceType: 4 }, { country: 6 }, { character: -1 }, { difficulty: 3 }, { country: '1' }, { raceType: 1.5 }]) {
    assert.throws(() => writeHandoff(vfs, cfg), RangeError, JSON.stringify(cfg));
  }
});

// --- readResult -------------------------------------------------------------------------------------------
const FINISHED = `[RACETYPEINFO]\r\nRaceType=1\r\nopponents=3\r\n[CHARDATA]\r\ncount=4\r\n[RACERS]\r\n0=0,0,95000\r\n1=1,2,99000\r\n2=3,1,97000\r\n3=2,3,101000\r\n` +
  `4=4,4,9\r\n5=5,6,360442\r\n[BEST TIMES]\r\nLAP_RECORD_E0=1\r\nLAP_RECORD_E3=18001\r\nRACE_RECORD_E3=101000\r\nTIME_CHECK_COUNT_E3=2\r\n` +
  `TIME_CHECK_E3_C0=20000\r\nTIME_CHECK_E3_C1=40000\r\nTIME_CHECK_E3_C2=60000\r\n[ETAPPE]\r\netappe=3\r\n[PLAYER]\r\nfinished=1\r\ncar=2\r\n` +
  `damage=12\r\ntracktime=101000\r\nposition=3\r\nEUROSTARS=0\r\nFASTEST_LAP=18001\r\n[GAME_SETTINGS]\r\nFX_VOLUME=75\r\n`;

test('readResult: the nativeRaceResultPatch shape, rows 0..opponents, this etappe only', { skip }, async () => {
  const { patch, effectsPercent } = readResult(FINISHED);
  const want = await expectedPatch([
    ...['finished=1', 'damage=12', 'tracktime=101000', 'position=3', 'EUROSTARS=0', 'FASTEST_LAP=18001'].map((x) => ['race.ini', 'PLAYER', ...x.split('=')]),
    ['race.ini', 'RACERS', '0', '0,0,95000'], ['race.ini', 'RACERS', '1', '1,2,99000'], ['race.ini', 'RACERS', '2', '3,1,97000'], ['race.ini', 'RACERS', '3', '2,3,101000'],
    ['race.ini', 'BEST TIMES', 'LAP_RECORD_E3', '18001'], ['race.ini', 'BEST TIMES', 'RACE_RECORD_E3', '101000'], ['race.ini', 'BEST TIMES', 'TIME_CHECK_COUNT_E3', '2'],
    ['race.ini', 'BEST TIMES', 'TIME_CHECK_E3_C0', '20000'], ['race.ini', 'BEST TIMES', 'TIME_CHECK_E3_C1', '40000'],
  ]);
  assert.deepEqual(patch, want);
  assert.equal(JSON.stringify(patch), JSON.stringify(want));          // same key order too
  assert.equal(effectsPercent, 75);
  assert.deepEqual(Object.keys(patch.RACERS), ['0', '1', '2', '3']);
  assert.deepEqual(readResult(new TextEncoder().encode(FINISHED)).patch, patch);
  // not finished: only finished=0, whatever else race.ini holds
  assert.deepEqual(readResult(FINISHED.replace('finished=1', 'finished=0')), { patch: { PLAYER: { finished: 0 } }, effectsPercent: 75 });
  assert.deepEqual(readResult(''), { patch: { PLAYER: { finished: 0 } }, effectsPercent: null });
  // a time-check count outside 0..9 counts as 0 (nativeRaceResultPatch)
  const bad = readResult(FINISHED.replace('TIME_CHECK_COUNT_E3=2', 'TIME_CHECK_COUNT_E3=12')).patch['BEST TIMES'];
  assert.deepEqual(bad, { LAP_RECORD_E3: 18001, RACE_RECORD_E3: 101000, TIME_CHECK_COUNT_E3: 0 });
  // the installation's race.ini (a recorded handoff, finished=0)
  assert.deepEqual(readResult(readFileSync(join(DATA, 'race.ini'))), { patch: { PLAYER: { finished: 0 } }, effectsPercent: 100 });
});

const exits = existsSync(EVIDENCE) ? readdirSync(EVIDENCE).filter((f) => f.endsWith('.race-exit.ini')) : [];
test('readResult on the race\'s own exit files = nativeRaceResultPatch of the race\'s exit writes', { skip: skip || (!exits.length && 'no probe evidence yet (node tools/checks/race-handoff-probe.mjs)') }, async () => {
  let finished = 0, aborted = 0;
  for (const f of exits) {
    const rec = JSON.parse(readFileSync(join(EVIDENCE, f.replace('.race-exit.ini', '.json')), 'utf8'));
    const { patch, effectsPercent } = readResult(readFileSync(join(EVIDENCE, f)));
    const want = await expectedPatch(rec.iniWritesAtExit);
    assert.equal(JSON.stringify(patch), JSON.stringify(want), f);
    assert.deepEqual(patch, rec.result.patch, `${f}: the probe's own readResult`);
    assert.equal(effectsPercent, rec.result.effectsPercent, f);
    if (patch.PLAYER.finished) {
      finished++;
      assert.equal(Object.keys(patch.RACERS).length, rec.handoff.opponents + 1, f);
      assert.ok(Object.keys(patch['BEST TIMES']).every((k) => k.endsWith(`E${rec.handoff.country}`) || k.includes(`E${rec.handoff.country}_C`)), f);
    } else aborted++;
  }
  assert.ok(finished >= 5, `${finished} finished races`);
  assert.ok(aborted >= 1, `${aborted} aborted races`);
});

test('readResult -> JS port applyRaceResult -> writeHandoff: records and position go round', { skip }, async () => {
  const { readRaceSave, applyRaceResult } = await jsModule('race-save.js');
  const store = new Map();
  const storage = { getItem: (k) => store.get(k) ?? null, setItem: (k, v) => store.set(k, v) };
  const save = readRaceSave(storage);
  const { patch } = readResult(FINISHED);
  applyRaceResult(save, patch);
  assert.deepEqual(save.bestTimes, { lap_record_e3: 18001, race_record_e3: 101000, time_check_count_e3: 2, time_check_e3_c0: 20000, time_check_e3_c1: 40000 });
  assert.equal(save.playerPosition, 3);
  const vfs = installationVfs();
  writeHandoff(vfs, { country: 3, character: 2, raceType: 1 }, save);
  const r = ini(vfs, 'race.ini');
  assert.deepEqual(Object.fromEntries(r.keys('BEST TIMES').map((k) => [k, Number(r.get('BEST TIMES', k))])), patch['BEST TIMES']);
  assert.equal(r.get('PLAYER', 'position'), '3');
  // the no-record value is kept as the JS port keeps it (open question 4 of the spec)
  applyRaceResult(save, { PLAYER: { finished: 1, position: 1 }, RACERS: {}, 'BEST TIMES': { LAP_RECORD_E0: NO_RECORD } });
  writeHandoff(vfs, { country: 0 }, save);
  assert.equal(get(vfs, 'race.ini', 'BEST TIMES', 'LAP_RECORD_E0'), String(NO_RECORD));
});
