// Saves between sites: the recomp keeps its saves where the JavaScript reconstruction keeps them (localStorage keys
// rcsk.race-save.v1, rcsk.settings.v1, rcsk.selection.v1, rcsk.firsttime.*, read and written by the same code in
// source/menu/), so on one site (one origin: scheme, host and port) the two share them without anything else
// (tools/checks/save-transfer.mjs). localStorage is per origin, so another host or port, or the JS port's desktop
// app (its own Electron profile), starts empty: this file moves them by hand, as a JSON file.
//   file: { format: 'rcsk-saves', version: 1, exported: ISO date, keys: { 'rcsk.…': string, … } }
// A plain object of rcsk.* keys is accepted too. The JS port has no export button; on its site this console line
// writes the same file (README "Saves"):
export const EXPORT_SNIPPET = "(()=>{const k=Object.fromEntries(Object.keys(localStorage).filter(x=>x.startsWith('rcsk.')).map(x=>[x,localStorage.getItem(x)]));const a=document.createElement('a');a.href=URL.createObjectURL(new Blob([JSON.stringify({format:'rcsk-saves',version:1,keys:k})],{type:'application/json'}));a.download='redcat-superkarts-opslag.json';a.click();})()";
import { readRaceSave, writeRaceSave } from './menu/race-save.js';
import { readSettings, writeSettings } from './menu/settings.js';

const KEY = /^rcsk\.(race-save\.v1|settings\.v1|selection\.v1|firsttime\.[a-z0-9-]+)$/;
const FILE = 'redcat-superkarts-opslag.json';

const rcskKeys = (storage) => {
  const out = [];
  for (let k = 0; k < storage.length; k++) { const key = storage.key(k); if (key && KEY.test(key)) out.push(key); }
  return out.sort();
};

/** Every save key on this site, as the file's object. */
export function collectSaves(storage = globalThis.localStorage) {
  return { format: 'rcsk-saves', version: 1, exported: new Date().toISOString(),
    keys: Object.fromEntries(rcskKeys(storage).map((k) => [k, storage.getItem(k)])) };
}

/** Offers the saves as a file download. */
export function exportSaves(storage = globalThis.localStorage) {
  const url = URL.createObjectURL(new Blob([JSON.stringify(collectSaves(storage), null, 1)], { type: 'application/json' }));
  const a = document.createElement('a');
  a.href = url; a.download = FILE; document.body.append(a); a.click(); a.remove();
  setTimeout(() => URL.revokeObjectURL(url), 10000);
}

/**
 * Reads a saves file. Returns { keys, summary } with the keys as they will be written: the race save and the
 * settings go through the menu's own readers (readRaceSave/readSettings, which repair or drop what they do not
 * know), the selection must be an object and first-time marks are kept as they are. Throws an Error with a Dutch
 * message for a file that is not a saves file.
 */
export function parseSaves(text) {
  let data;
  try { data = JSON.parse(text); } catch { throw new Error('Dit bestand is geen opslagbestand (geen JSON).'); }
  const raw = data && typeof data === 'object' && data.format === 'rcsk-saves' ? data.keys : data;
  if (!raw || typeof raw !== 'object' || Array.isArray(raw)) throw new Error('Dit bestand is geen opslagbestand van RedCat SuperKarts.');
  const given = Object.entries(raw).filter(([k, v]) => KEY.test(k) && typeof v === 'string');
  if (!given.length) throw new Error('Er staat geen opslag van RedCat SuperKarts in dit bestand.');
  const map = Object.fromEntries(given);
  const fake = { getItem: (k) => map[k] ?? null, setItem: (k, v) => { map[k] = v; } };
  const keys = {};
  for (const [k, v] of given) if (k.startsWith('rcsk.firsttime.')) keys[k] = v;
  if (map['rcsk.selection.v1']) {
    try { const s = JSON.parse(map['rcsk.selection.v1']); if (s && typeof s === 'object' && !Array.isArray(s)) keys['rcsk.selection.v1'] = JSON.stringify(s); } catch {}
  }
  const sink = { setItem: (k, v) => { keys[k] = v; } };
  let save = null;
  if (map['rcsk.race-save.v1']) { save = readRaceSave(fake); writeRaceSave(save, sink); }
  if (map['rcsk.settings.v1']) writeSettings(readSettings(fake), sink);
  const profiles = save ? save.profiles.filter(Boolean).map((p) => p.name) : [];
  const scores = save ? save.boards.flat().filter((e) => e.name).length : 0;
  return { keys, summary: { profiles, scores, settings: 'rcsk.settings.v1' in keys } };
}

/** Replaces this site's saves with the file's: every rcsk.* key here is removed first. */
export function importSaves(keys, storage = globalThis.localStorage) {
  for (const k of rcskKeys(storage)) storage.removeItem(k);
  for (const [k, v] of Object.entries(keys)) storage.setItem(k, v);
}
