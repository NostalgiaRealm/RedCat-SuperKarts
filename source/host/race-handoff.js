// The menu -> race handoff: what the original menu (rcskmenu.dat) writes into the INI files before it starts the
// race, and the race's results read back into the JS reconstruction's result patch. Spec, traces and the headless
// checks: tools/checks/race-handoff-probe.mjs, evidence/checks/race-handoff/; unit tests: tests/race-handoff.test.mjs.
// Interface (fixed; other modules code against it):
//   writeHandoff(vfs, config, save, settings[, pristine]) -> summary { opponents, car, roster, bindings, ... }
//     config: { country 0..5 (track.ini order: NED, DUI, ENG, FRA, SPA, ITA), character 0..3 (RedCat, WhizzKitty,
//               Brutus, Max), difficulty 0..2 (undefined: the installation's 1), raceType 0..3 (Landenrace,
//               Tijdrace, Sterrenrace, duel) }
//     save:   { bestTimes: { lap_record_e0: ms, ... } (lowercase keys, as rcsk.race-save.v1 stores them), playerPosition }
//             (a whole rcsk.race-save.v1 object works too: without playerPosition a finished lastResult's position counts,
//             as in the JS port's race-save.js configWithRaceSave)
//     settings: normalized rcsk.settings.v1 (music, effects 0..1, bindings, display, ...) or null (installation values)
//     pristine: optional { 'race.ini': bytes|text, ... }: the installation copies; by default the bytes the Vfs holds the
//               first time writeHandoff (or pinRace) sees it, kept per Vfs, so a Vfs reused for a second race starts
//               from the installation copies again and nothing of an earlier race leaks except through `save`
//   readResult(raceIniText) -> { patch, effectsPercent }
//     patch: the JS reconstruction's nativeRaceResultPatch shape (source/simulation/native-results.js there):
//            { PLAYER: { finished: 1, damage, tracktime, position, EUROSTARS, FASTEST_LAP } (integers),
//              RACERS: { '0'..'<opponents>': 'car,rank,ms' } (rows above the race's opponents are stale and left out;
//              the player is the last row), 'BEST TIMES': { LAP_RECORD_Et, RACE_RECORD_Et, TIME_CHECK_COUNT_Et,
//              TIME_CHECK_Et_C0.. } (integers, this etappe only) },
//            or { PLAYER: { finished: 0 } } for a race that was not finished (aborted, game over, fatal exit)
//     effectsPercent: race.ini [GAME_SETTINGS] FX_VOLUME as the race left it (0..100; the race repairs an enabled 0 to
//            75 at boot, 0x437560; a level changed during the race is written there too, source/host/live-volume.js),
//            or null. The menu adopts the level after boot instead (race-runner.js onEffects), as the JS port does
//            after its load (main.js:716-719), so a result never brings back the level the race started with.
//   codeToVk(code), bindingsToVk(settings) -> { accelerate, brake, left, right, bonus, handbrake }: the key bindings
//     (KeyboardEvent.code) as the Windows virtual keys the race polls; letters are uppercase VKs 65..90 (the original
//     menu's lowercase 97..122 makes the race poll F-keys and the numpad: an original bug, docs/intentional-differences).
//
// Original writers (rcskmenu.dat): 0x46edd0 clears [CHARDATA]; 0x46e9bc writes the roster, [RACETYPEINFO] and
// [ETAPPE] (guest 0x46efa8, player 0x46ef14, core test 0x46e74c); 0x45a5dc the profile ([PLAYER] car via 0x45aa8c,
// opponents, game.ini Difficulty); 0x45b334 the settings (volumes, CONTROL, FILTER, gamma, alpha_blending, particles,
// RESOLUTION); 0x458e88 the key bindings. Readers in rcskspel.dat: 0x4295f0, 0x42ac60, 0x42b960, 0x42c0a0, 0x42c170,
// 0x42c320, 0x42c680, 0x42ce10; exit writers 0x42c570 (PLAYER, the player's RACERS row), 0x42c4d0 (opponent rows),
// 0x42c3b0 (BEST TIMES).
import { IniFile, latin1, encodeLatin1 } from './vfs.js';

/** track.ini [MAPS] order (etappe index); the menu's country table 0x47bc80 holds the meshes in the same order. */
export const COUNTRY_NAMES = Object.freeze(['Nederland', 'Duitsland', 'Engeland', 'Frankrijk', 'Spanje', 'Italie']);
export const COUNTRY_MESHES = Object.freeze(['NEDERLAND', 'DUITSLAND', 'ENGELAND', 'FRANKRIJK', 'SPANJE', 'ITALIE']);
/** The menu's character table 0x47bcd8 (selection 0..3). */
export const CHARACTER_NAMES = Object.freeze(['RedCat', 'WhizzKitty', 'Brutus', 'Max']);
/** 0x47bd10 by race type (Landenrace, Tijdrace, Sterrenrace, duel); [4] = 6 is the BonusRace, which no menu offers. */
export const OPPONENTS = Object.freeze([4, 3, 3, 1]);
/** The files a race reads its handoff from, plus npc_ai.ini, which the race writes at boot ([Person_N] type). */
export const PRISTINE_FILES = Object.freeze(['race.ini', 'game.ini', 'SndGfx.ini', 'npc_ai.ini']);
/** The race's "no record" (0xFFFFFFF), written back when race.ini held no record for the etappe. */
export const NO_RECORD = 268435455;

export const BINDING_ACTIONS = Object.freeze(['accelerate', 'brake', 'left', 'right', 'bonus', 'handbrake']);
/** game.ini [INPUT] keys in BINDING_ACTIONS order (read by 0x42ce10). */
export const INPUT_KEYS = Object.freeze(['KEY_ACCELERATE', 'KEY_BRAKE', 'KEY_STEERLEFT', 'KEY_STEERRIGHT', 'KEY_USEBONUS', 'KEY_HANDBRAKE']);
/** The installation's [INPUT] and the JS port's NATIVE_DEFAULT_KEYS: arrows, Ctrl, Alt. */
export const DEFAULT_VK = Object.freeze({ accelerate: 0x26, brake: 0x28, left: 0x25, right: 0x27, bonus: 0x11, handbrake: 0x12 });

// KeyboardEvent.code -> Windows virtual key; the same table as source/input/keyboard.js (what the page writes into
// shared memory for a key), a superset of the JS port's nativeBindingCode table with letters uppercase.
const CODE_TO_VK = {
  ArrowLeft: 0x25, ArrowUp: 0x26, ArrowRight: 0x27, ArrowDown: 0x28,
  ControlLeft: 0x11, ControlRight: 0x11, AltLeft: 0x12, AltRight: 0x12, ShiftLeft: 0x10, ShiftRight: 0x10,
  Space: 0x20, Enter: 0x0D, NumpadEnter: 0x0D, Escape: 0x1B, Backspace: 0x08, Tab: 0x09,
  Home: 0x24, End: 0x23, PageUp: 0x21, PageDown: 0x22, Insert: 0x2D, Delete: 0x2E, NumLock: 0x90,
  NumpadMultiply: 0x6A, NumpadAdd: 0x6B, NumpadSubtract: 0x6D, NumpadDecimal: 0x6E, NumpadDivide: 0x6F,
};
for (let k = 0; k < 10; k++) { CODE_TO_VK['Digit' + k] = 0x30 + k; CODE_TO_VK['Numpad' + k] = 0x60 + k; }
for (let k = 0; k < 26; k++) CODE_TO_VK['Key' + String.fromCharCode(65 + k)] = 0x41 + k;
for (let k = 1; k <= 12; k++) CODE_TO_VK['F' + k] = 0x6F + k;

/** A binding (KeyboardEvent.code) as the virtual key the race polls; '' (unbound, as the menu's Escape leaves it) and
 *  unknown codes give 0, which the original menu also writes for an unbound key and which no key ever sets. */
export function codeToVk(code) {
  return (typeof code === 'string' && Object.hasOwn(CODE_TO_VK, code)) ? CODE_TO_VK[code] : 0;
}

/** settings.bindings as virtual keys; an action without a binding string keeps the installation's key. */
export function bindingsToVk(settings) {
  const b = settings && settings.bindings && typeof settings.bindings === 'object' ? settings.bindings : {};
  const out = {};
  for (const a of BINDING_ACTIONS) out[a] = typeof b[a] === 'string' ? codeToVk(b[a]) : DEFAULT_VK[a];
  return out;
}

/** The JS port's settingsAudioPercent (audio-mixing.js): the slider's integer back from its fraction. */
export function audioPercent(fraction) {
  const n = Math.round(Number(fraction) * 100);
  return Number.isFinite(n) ? Math.max(0, Math.min(100, n)) : null;
}

/** settings.display -> the INI fields 0x45b334 writes (the JS port's configWithNativeDisplaySettings); only booleans count. */
export function displayFields(display) {
  const out = {};
  if (!display || typeof display !== 'object') return out;
  if (typeof display.bilinearFiltering === 'boolean') out.FILTER = display.bilinearFiltering ? 2 : 0;     // game.ini [OPTIONS]
  if (typeof display.brightnessLight === 'boolean') out.gamma = display.brightnessLight ? 0 : 1;           // SndGfx [GFX OPTIONS]
  if (typeof display.alphaBlending === 'boolean') out.alpha_blending = display.alphaBlending ? 2 : 0;
  if (typeof display.particles === 'boolean') out.particles = display.particles ? 1 : 0;
  return out;
}

/** GetPrivateProfileInt's reading: optional sign and leading digits, 32-bit; null when there are none. */
export function iniInt(value) {
  if (value === null || value === undefined) return null;
  const m = /^\s*([+-]?\d+)/.exec(String(value));
  return m ? Number(m[1]) | 0 : null;
}

const validPosition = (v) => Number.isInteger(v) && v >= 0 && v <= 9;
/** race-save.js savedPlayerPosition: race.ini [PLAYER] position survives unfinished races. */
export function savedPlayerPosition(save) {
  if (!save) return undefined;
  if (validPosition(save.playerPosition)) return save.playerPosition;
  const p = save.lastResult && save.lastResult.PLAYER;
  return p && p.finished && validPosition(p.position) ? p.position : undefined;
}

/** game.ini [AVAILABLE_CHARACTERS] rows. */
export function availableCharacters(gameIni) {
  const get = (k) => gameIni.get('AVAILABLE_CHARACTERS', k);
  const n = iniInt(get('count')) || 0;
  const out = [];
  for (let i = 0; i < n; i++) {
    const v = get(String(i));
    if (v === null) continue;
    const [name = '', mesh = '', ai = '0', color = '0'] = v.split(',').map((x) => x.trim());
    out.push({ index: i, name, mesh, ai: iniInt(ai) ?? 0, color: iniInt(color) ?? 0 });
  }
  return out;
}

/**
 * 0x46e9bc: [4,3,3,1][raceType] opponents; with more than 3 or exactly 1 the country's guest first (the AVAILABLE entry
 * whose mesh is the country's), then the other core characters in AVAILABLE order without the player, the player last
 * (row `opponents`, ai -1). Rows: { name, mesh, ai, color, index (AVAILABLE index) }.
 */
export function raceRoster(available, { country, character, raceType }) {
  const opponents = OPPONENTS[raceType];
  const isCore = (r) => CHARACTER_NAMES.some((p) => p.toLowerCase() === r.name.toLowerCase());
  const me = available.find((r) => r.name.toLowerCase() === CHARACTER_NAMES[character].toLowerCase());
  if (!me) throw new Error(`race handoff: ${CHARACTER_NAMES[character]} is not in game.ini [AVAILABLE_CHARACTERS]`);
  const rows = [];
  if (opponents > 3 || opponents === 1) {
    const guest = available.find((r) => r.mesh.toUpperCase() === COUNTRY_MESHES[country]);
    if (!guest) throw new Error(`race handoff: no ${COUNTRY_MESHES[country]} in game.ini [AVAILABLE_CHARACTERS]`);
    rows.push(guest);
  }
  for (const r of available) {
    if (rows.length >= opponents) break;
    if (isCore(r) && r !== me) rows.push(r);
  }
  if (rows.length !== opponents) throw new Error(`race handoff: ${rows.length} opponents found, ${opponents} needed`);
  rows.push({ ...me, ai: -1 });
  return { opponents, rows, player: me };
}

const rosterRow = (r) => `${r.name},${r.mesh},${r.ai},${r.color}`;

function checkedConfig(config) {
  const c = config || {};
  const int = (name, v, max, def) => {
    if (v === undefined || v === null) return def;
    if (!Number.isInteger(v) || v < 0 || v > max) throw new RangeError(`race handoff: ${name} must be 0..${max}, not ${v}`);
    return v;
  };
  return {
    country: int('country', c.country, 5, 0),
    character: int('character', c.character, 3, 0),
    difficulty: int('difficulty', c.difficulty, 2, undefined),
    raceType: int('raceType', c.raceType, 3, 0),
  };
}

// --- the installation copies --------------------------------------------------------------------------------
const pristineByVfs = new WeakMap();

function toBytes(v) {
  if (v === null || v === undefined) return null;
  if (typeof v === 'string') return encodeLatin1(v);
  if (v instanceof Uint8Array) return v.slice();
  if (v instanceof ArrayBuffer) return new Uint8Array(v.slice(0));
  throw new TypeError('race handoff: pristine files are bytes or text');
}

function lookup(obj, name) {
  if (!obj) return undefined;
  if (obj instanceof Map) {
    for (const [k, v] of obj) if (k.toLowerCase() === name.toLowerCase()) return v;
    return undefined;
  }
  for (const k of Object.keys(obj)) if (k.toLowerCase() === name.toLowerCase()) return obj[k];
  return undefined;
}

/** Puts race.ini, game.ini, SndGfx.ini and npc_ai.ini back to their installation bytes (see the header). */
export function restorePristine(vfs, given = null) {
  let saved = pristineByVfs.get(vfs);
  if (!saved) {
    saved = new Map();
    for (const name of PRISTINE_FILES) {
      const f = vfs.stat(name);
      saved.set(name, { name: f ? f.name : name, bytes: f ? toBytes(vfs.read(name)) : null });
    }
    pristineByVfs.set(vfs, saved);
  }
  for (const name of PRISTINE_FILES) {
    const v = lookup(given, name);
    if (v !== undefined) saved.set(name, { name: (vfs.stat(name) || { name }).name, bytes: toBytes(v) });
  }
  for (const { name, bytes } of saved.values()) {
    if (bytes) vfs.add(name, bytes.slice());
    else if (vfs.stat(name)) vfs.remove(name);
  }
}

// --- writeHandoff -------------------------------------------------------------------------------------------
/** See the header. Throws a RangeError for a config outside the menu's choices, an Error for a broken handoff. */
export function writeHandoff(vfs, config = {}, save = null, settings = null, pristine = null) {
  const c = checkedConfig(config);
  restorePristine(vfs, pristine);
  const set = (file, section, key, value) => vfs.iniSet(file, section, key, value === null ? null : String(value));
  const race = (section, key, value) => set('race.ini', section, key, value);
  const game = vfs.parsedIni('game.ini');

  // 0x46edd0: the old roster rows 0..count-1 go, count=0
  const oldCount = iniInt(vfs.iniGet('race.ini', 'CHARDATA', 'count')) || 0;
  for (let i = 0; i < Math.min(oldCount, 64); i++) race('CHARDATA', String(i), null);
  race('CHARDATA', 'count', 0);

  // 0x46e9bc: roster, race type, opponents, etappe (never [ETAPPE] british or direction: both fatal on these tracks)
  const roster = raceRoster(availableCharacters(game), c);
  const opp = roster.opponents;
  race('CHARDATA', 'count', opp + 1);
  race('RACETYPEINFO', 'RaceType', c.raceType);
  race('RACETYPEINFO', 'opponents', opp);
  race('ETAPPE', 'etappe', c.country);
  roster.rows.forEach((r, i) => race('CHARDATA', String(i), rosterRow(r)));

  // 0x45a5dc: the player's car is the character's AVAILABLE index; the difficulty for global 0x53b9f4
  race('PLAYER', 'car', roster.player.index);
  if (c.difficulty !== undefined) set('game.ini', 'OPTIONS', 'Difficulty', c.difficulty);

  // written by the race only: start clean, the grid position (0x42c680) and the records from the save
  race('PLAYER', 'finished', 0);
  race('PLAYER', 'damage', 0);
  const position = savedPlayerPosition(save);
  if (position !== undefined) race('PLAYER', 'position', position);
  const records = recordsFor(save, c.country);
  for (const [key, value] of records) race('BEST TIMES', key, value);

  // 0x45b334: volumes, the device (always the keyboard: the host picks the handler per pass), display options
  const mx = settings ? audioPercent(settings.music) : null;
  const fx = settings ? audioPercent(settings.effects) : null;
  if (mx !== null) race('GAME_SETTINGS', 'MX_VOLUME', mx);
  if (fx !== null) race('GAME_SETTINGS', 'FX_VOLUME', fx);
  race('GAME_SETTINGS', 'CONTROL', 0);
  const display = displayFields(settings && settings.display);
  if (display.FILTER !== undefined) set('game.ini', 'OPTIONS', 'FILTER', display.FILTER);
  for (const k of ['gamma', 'alpha_blending', 'particles']) if (display[k] !== undefined) set('SndGfx.ini', 'GFX OPTIONS', k, display[k]);

  // 0x458e88: the key bindings, as uppercase virtual keys
  const bindings = bindingsToVk(settings);
  if (settings && settings.bindings) BINDING_ACTIONS.forEach((a, i) => set('game.ini', 'INPUT', INPUT_KEYS[i], bindings[a]));

  // [RACERS] rows 0..opponents-1 must hold three integers (else load_racer_info, Gm_ini.cpp 739/748, is fatal);
  // their values make no difference (three variants checked)
  for (let i = 0; i < opp; i++) {
    const v = vfs.iniGet('race.ini', 'RACERS', String(i));
    if (!racersRowValid(v)) race('RACERS', String(i), `${i},${i + 1},360442`);
  }

  // pins: no debug log, no RRM program after the race, the shipped 640x480x16 mode (the browser's resolution, scale
  // and MSAA are the page's), no pending mode switch, full screen, the primary DirectDraw driver
  set('game.ini', 'HELPDESK', 'DEBUGON', 0);
  set('game.ini', 'HELPDESK', 'TWEAK_MODE', 0);
  set('game.ini', 'HELPDESK', 'ENABLE_RRM', 0);
  set('game.ini', 'PROGRAM', 'RESOLUTION', 3);
  set('game.ini', 'PROGRAM', 'switch', 0);
  set('SndGfx.ini', 'GFX OPTIONS', 'windowed', 0);
  set('SndGfx.ini', 'DIRECTX', 'index', 0);

  checkHandoff(vfs, roster);
  return {
    ...c, opponents: opp, car: roster.player.index, position: position ?? iniInt(vfs.iniGet('race.ini', 'PLAYER', 'position')),
    roster: roster.rows.map(rosterRow), records: Object.fromEntries(records), bindings,
    volumes: { music: iniInt(vfs.iniGet('race.ini', 'GAME_SETTINGS', 'MX_VOLUME')), effects: iniInt(vfs.iniGet('race.ini', 'GAME_SETTINGS', 'FX_VOLUME')) },
  };
}

function racersRowValid(v) {
  if (v === null || v === undefined) return false;
  const parts = v.split(',');
  return parts.length === 3 && parts.every((p) => /^\s*[+-]?\d+\s*$/.test(p));
}

const RECORD_FAMILIES = ['lap_record', 'race_record', 'time_check_count'];
/** save.bestTimes entries for etappe t, as uppercase race.ini keys, in the race's write order (0x42c3b0). */
function recordsFor(save, t) {
  const out = [];
  const bt = save && save.bestTimes && typeof save.bestTimes === 'object' ? save.bestTimes : {};
  const lower = {};
  for (const [k, v] of Object.entries(bt)) if (Number.isInteger(v) && v >= 0) lower[k.toLowerCase()] = v;
  for (const f of RECORD_FAMILIES) if (lower[`${f}_e${t}`] !== undefined) out.push([`${f}_e${t}`.toUpperCase(), lower[`${f}_e${t}`]]);
  const checks = Object.keys(lower).map((k) => new RegExp(`^time_check_e${t}_c(\\d+)$`).exec(k)).filter(Boolean)
    .map((m) => Number(m[1])).sort((a, b) => a - b);
  for (const i of checks) out.push([`TIME_CHECK_E${t}_C${i}`, lower[`time_check_e${t}_c${i}`]]);
  return out;
}

/** Recommendation 2 of the spec: the player row is there and the opponent RACERS rows are readable. */
function checkHandoff(vfs, roster) {
  const opp = roster.opponents;
  const get = (s, k) => vfs.iniGet('race.ini', s, k);
  if (iniInt(get('CHARDATA', 'count')) !== opp + 1) throw new Error('race handoff: [CHARDATA] count not written');
  const me = (get('CHARDATA', String(opp)) || '').split(',').map((x) => x.trim());
  if (me[0] !== roster.player.name || iniInt(me[2]) !== -1) throw new Error('race handoff: no player row in [CHARDATA]');
  for (let i = 0; i < opp; i++) {
    if (!get('CHARDATA', String(i))) throw new Error(`race handoff: [CHARDATA] ${i} missing`);
    if (!racersRowValid(get('RACERS', String(i)))) throw new Error(`race handoff: [RACERS] ${i} is not three integers`);
  }
}

// --- readResult ---------------------------------------------------------------------------------------------
/** See the header. `raceIni` is the text the game worker posts at exit (or the file's bytes). */
export function readResult(raceIni) {
  const text = typeof raceIni === 'string' ? raceIni : raceIni instanceof Uint8Array ? latin1(raceIni) : '';
  const ini = new IniFile(text);
  const int = (s, k) => iniInt(ini.get(s, k));
  const fx = int('GAME_SETTINGS', 'FX_VOLUME');
  const effectsPercent = fx === null ? null : Math.max(0, Math.min(100, fx));
  if (!(int('PLAYER', 'finished') ?? 0)) return { patch: { PLAYER: { finished: 0 } }, effectsPercent };

  const patch = { PLAYER: { finished: 1 } };
  Object.assign(patch.PLAYER, {
    damage: int('PLAYER', 'damage') ?? 0,
    tracktime: int('PLAYER', 'tracktime') ?? 0,
    position: int('PLAYER', 'position') ?? 0,
    EUROSTARS: int('PLAYER', 'EUROSTARS') ?? 0,
    FASTEST_LAP: int('PLAYER', 'FASTEST_LAP') ?? 0,
  });
  // rows 0..opponents: the opponents, then the player (0x42c570 writes row `opponents`); higher rows are stale
  let opp = int('RACETYPEINFO', 'opponents');
  if (opp === null) opp = (int('CHARDATA', 'count') ?? 1) - 1;
  patch.RACERS = {};
  for (let i = 0; i <= Math.min(Math.max(opp, 0), 9); i++) {
    const row = ini.get('RACERS', String(i));
    if (row === null) continue;
    const [car, rank, ms] = row.split(',').map(iniInt);
    patch.RACERS[i] = `${car | 0},${rank | 0},${ms | 0}`;
  }
  // this etappe's records (0x42c3b0): the race writes all three keys, and TIME_CHECK rows 0..count-1
  const t = int('ETAPPE', 'etappe') ?? 0;
  const bt = {};
  for (const f of RECORD_FAMILIES) {
    const v = int('BEST TIMES', `${f}_E${t}`.toUpperCase());
    if (v !== null) bt[`${f}_E${t}`.toUpperCase()] = v;
  }
  const countKey = `TIME_CHECK_COUNT_E${t}`;
  if (bt[countKey] !== undefined && (bt[countKey] < 0 || bt[countKey] > 9)) bt[countKey] = 0;
  for (let i = 0; i < (bt[countKey] || 0); i++) {
    const v = int('BEST TIMES', `TIME_CHECK_E${t}_C${i}`);
    if (v !== null) bt[`TIME_CHECK_E${t}_C${i}`] = v;
  }
  patch['BEST TIMES'] = bt;
  return { patch, effectsPercent };
}
