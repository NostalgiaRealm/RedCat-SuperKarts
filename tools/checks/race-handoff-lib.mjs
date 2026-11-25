// Shared by tools/checks/race-handoff-probe.mjs, race-handoff-drive.mjs and tests/race-handoff.test.mjs:
//  - the JS reconstruction's own modules (read only, from ../RedCat Superkarts/source or SUPERKARTS_JS), so the
//    handoff and the result patch are compared with the functions the JS port's menu uses;
//  - a Vfs over the installation's data folder (lazy, nothing is written back to disk);
//  - expectedPatch(writes): the patch nativeRaceResultPatch gives for what the race itself wrote at exit (its
//    WritePrivateProfileStringA calls, 0x42c570/0x42c4d0/0x42c3b0), independent of race.ini's text.
import { readdirSync, statSync, readFileSync, existsSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { Vfs } from '../../source/host/vfs.js';

export const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..', '..');
export const JS_ROOT = process.env.SUPERKARTS_JS || join(ROOT, '..', 'RedCat Superkarts');
export const DATA = process.env.SUPERKARTS_DATA || join(JS_ROOT, 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c',
  'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
export const RECORDED = join(JS_ROOT, 'evidence', 'native', 'runtime');
export const EVIDENCE = join(ROOT, 'evidence', 'checks', 'race-handoff');

export const haveData = () => existsSync(join(DATA, 'race.ini')) && existsSync(join(DATA, 'game.ini'));
export const haveJs = () => existsSync(join(JS_ROOT, 'source', 'simulation', 'native-results.js'));
export const jsModule = (rel) => import(pathToFileURL(join(JS_ROOT, 'source', rel)).href);

/** A Vfs holding the installation's files (loaded on first read). */
export function installationVfs(dir = DATA) {
  const vfs = new Vfs();
  for (const name of readdirSync(dir)) {
    const p = join(dir, name);
    if (statSync(p).isFile()) vfs.addLazy(name, statSync(p).size, () => new Uint8Array(readFileSync(p)));
  }
  return vfs;
}

export const text = (bytes) => new TextDecoder('latin1').decode(bytes || new Uint8Array());

/** The JS port's default settings (settings.js normalizeSettings()), the menu's state on a first visit. */
export async function defaultSettings() {
  const { normalizeSettings } = await jsModule('settings.js');
  return normalizeSettings();
}

/**
 * nativeRaceResultPatch for the race's exit writes. writes: [[file, section, key, value], ...] or
 * [{ section, key, value }, ...] from the WritePrivateProfileStringA log (full-race-gaps-lib.mjs iniWrites).
 */
export async function expectedPatch(writes) {
  const { nativeRaceResultPatch } = await jsModule('simulation/native-results.js');
  const w = writes.map((x) => (Array.isArray(x) ? { section: x[1], key: x[2], value: x[3] } : x));
  const pick = (s, k) => {
    let v = null;
    for (const x of w) if (x.section && x.key && x.section.toUpperCase() === s && x.key.toUpperCase() === k.toUpperCase()) v = x.value;
    return v;
  };
  const n = (s, k) => (pick(s, k) === null ? undefined : Number(pick(s, k)));
  const finished = n('PLAYER', 'finished') === 1;
  const rows = w.filter((x) => x.section && x.section.toUpperCase() === 'RACERS').map((x) => [Number(x.key), x.value.split(',').map(Number)]);
  const opp = Math.max(-1, ...rows.map(([i]) => i));       // the player's row is the last one written (0x42c570)
  const byIndex = new Map(rows);
  const racer = (i) => { const [carIndex, rank, finishTimeMs] = byIndex.get(i) || []; return { carIndex, rank, finishTimeMs }; };
  const lap = w.find((x) => x.section && x.section.toUpperCase() === 'BEST TIMES' && /^LAP_RECORD_E\d$/i.test(x.key));
  const t = lap ? Number(lap.key.slice(-1)) : 0;
  const count = n('BEST TIMES', `TIME_CHECK_COUNT_E${t}`) ?? 0;
  return nativeRaceResultPatch({
    finished,
    player: { ...racer(opp), damage: n('PLAYER', 'damage'), finishTimeMs: n('PLAYER', 'tracktime'), rank: n('PLAYER', 'position'),
      stars: n('PLAYER', 'EUROSTARS'), bestLapMs: n('PLAYER', 'FASTEST_LAP') },
    opponents: Array.from({ length: Math.max(0, opp) }, (_, i) => racer(i)),
    trackIndex: t, bestLapRecordMs: n('BEST TIMES', `LAP_RECORD_E${t}`), raceRecordMs: n('BEST TIMES', `RACE_RECORD_E${t}`),
    timeCheckCount: count, timeChecks: Array.from({ length: Math.max(0, count) }, (_, i) => n('BEST TIMES', `TIME_CHECK_E${t}_C${i}`)),
  });
}

/** The keys of race.ini, game.ini and SndGfx.ini a race reads or the handoff writes, for side-by-side comparisons. */
export const RACE_KEYS = [
  ['race.ini', 'RACETYPEINFO', 'RaceType'], ['race.ini', 'RACETYPEINFO', 'opponents'], ['race.ini', 'RACETYPEINFO', 'PhysicsModel'],
  ['race.ini', 'CHARDATA', 'count'], ...Array.from({ length: 10 }, (_, i) => ['race.ini', 'CHARDATA', String(i)]),
  ...Array.from({ length: 10 }, (_, i) => ['race.ini', 'RACERS', String(i)]),
  ['race.ini', 'ETAPPE', 'etappe'], ['race.ini', 'ETAPPE', 'british'], ['race.ini', 'ETAPPE', 'direction'],
  ...['finished', 'car', 'damage', 'position', 'money', 'copland', 'motor', 'banden', 'abs', 'turbo', 'versnellingsbak', 'injectie']
    .map((k) => ['race.ini', 'PLAYER', k]),
  ...['CONTROL', 'EFFECTS', 'MX_VOLUME', 'FX_VOLUME', 'groep', 'SENSITIVITY'].map((k) => ['race.ini', 'GAME_SETTINGS', k]),
];

/** An INI text as { section: { key: value } } with lowercase names, the JS port's parsed-config shape. */
export function iniObject(src) {
  const out = {};
  let sec = null;
  for (const raw of src.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line[0] === ';') continue;
    if (line[0] === '[') { const e = line.indexOf(']'); if (e > 0) { sec = line.slice(1, e).trim().toLowerCase(); out[sec] ??= {}; } continue; }
    const eq = line.indexOf('=');
    if (sec === null || eq < 0) continue;
    const k = line.slice(0, eq).trim().toLowerCase();
    if (!(k in out[sec])) out[sec][k] = line.slice(eq + 1).trim();
  }
  return out;
}
