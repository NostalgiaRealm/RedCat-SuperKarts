// A race started without the menu (the development page, tools/run-headless.mjs, the checks): a thin wrapper over
// race-handoff.js writeHandoff, which writes what the original menu (rcskmenu.dat) writes before it hands over to
// the race. Kept for the tools that call pinRace; new code calls writeHandoff.
import { writeHandoff, COUNTRY_NAMES } from './race-handoff.js';

/** Etappe order of track.ini [MAPS] and the menu's country table 0x47bc80: NED, DUI, ENG, FRA, SPA, ITA. */
export const COUNTRIES = COUNTRY_NAMES;

/**
 * opts: { etappe 0..5 (COUNTRIES), car 0..3 (the character: 0 RedCat, 1 WhizzKitty, 2 Brutus, 3 Max),
 *         raceType 0..3 (Landenrace, Tijdrace, Sterrenrace, duel; default 0), difficulty 0..2 (default: game.ini's 1),
 *         fx, music 0..100 (default: race.ini's) }
 * game.ini [PROGRAM] RESOLUTION is always 3 (640x480x16): the browser's resolution, scale and MSAA are the page's.
 * Returns writeHandoff's summary.
 */
export function pinRace(vfs, opts = {}) {
  const settings = opts.fx !== undefined || opts.music !== undefined
    ? { music: opts.music === undefined ? undefined : opts.music / 100, effects: opts.fx === undefined ? undefined : opts.fx / 100 }
    : null;
  return writeHandoff(vfs, {
    country: opts.etappe ?? 0, character: opts.car ?? 0, raceType: opts.raceType ?? 0, difficulty: opts.difficulty,
  }, null, settings);
}
