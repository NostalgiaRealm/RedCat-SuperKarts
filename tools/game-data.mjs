// The original game files the recompiled race may read, and where each comes from. Shared by tools/build-manifest.mjs
// (public/game/files.json), tools/build-preload.mjs (public/game/preload.json) and tools/package.mjs (dist/site/data/).
//
// The race runs in the installation's data folder (docs/host.md, "Process and files"): the files of the CD's
// data\Game folder and the archives of its data folder (rc.img/rc.ind, rcs.img/rcs.ind), side by side. The
// installation copy (SUPERKARTS_DATA; default the Wine installation inside the SuperKarts reconstruction) is that
// folder after the original ran under Wine, which wrote two of them: debug.txt (DirectDraw's "could not set display
// mode", appended by the race) and race.ini (rewritten by rcskmenu.dat). So every file is taken from the CD copy
// (SUPERKARTS_DISC; default ../RedCat Superkarts/evidence/native/runtime/disc/data, compared 2026-11-25: all equal to
// the installation's except race.ini) under the installation's name, and a file the CD lacks is left out (debug.txt).
// Without a CD copy the installation's own files are taken, debug.txt still left out.
// Left out as well: the programs (RCSK.exe, rcskspel.dat, rcskmenu.dat, RCMovie.dat, SMACKW32.DLL), the help (RCSK.HLP,
// RCSK.cnt) and the menu's folders (gfx/, ini/, Players/): the race reads none of them (evidence/headless/files-read.txt).
//
// RANGED: the packed archives, read in pieces (an index .ind of member names and offsets, the race seeks into the
// .img): the browser fetches the byte ranges a race reads (source/web/game-files.js) and never gets a .gz copy of them
// (a server's gzip_static would answer a Range request with bytes of the .gz).
import { existsSync, readdirSync, statSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';

export const ROOT = join(dirname(fileURLToPath(import.meta.url)), '..');
const JS = join(ROOT, '..', 'RedCat Superkarts');
export const DEFAULT_DATA = join(JS, 'evidence', 'native', 'runtime', 'wineprefix', 'drive_c', 'Program Files (x86)', 'Davilex', 'RedCat Super Karts', 'data');
export const DEFAULT_DISC = join(JS, 'evidence', 'native', 'runtime', 'disc', 'data');
export const RANGED = /\.img$/i;
export const PAGE = 16384;           // the unit of a ranged file the browser fetches and keeps (preload.json counts in it)
const SKIP = /^(rcsk\.exe|rcskspel\.dat|rcskmenu\.dat|rcmovie\.dat|smackw32\.dll|rcsk\.hlp|rcsk\.cnt|rcsk\.gid|debug\.txt)$/i;

/** [{ name, size, from }] sorted by name: the files of files.json and of the package's data/. */
export function raceFiles({ data = process.env.SUPERKARTS_DATA || DEFAULT_DATA, disc = process.env.SUPERKARTS_DISC || DEFAULT_DISC } = {}) {
  if (!existsSync(data)) throw new Error('the game files were not found at ' + data + ' (SUPERKARTS_DATA)');
  const onDisc = new Map();
  for (const dir of [join(disc, 'Game'), disc]) {
    if (!existsSync(dir)) continue;
    for (const n of readdirSync(dir)) { const p = join(dir, n); if (!onDisc.has(n.toLowerCase()) && statSync(p).isFile()) onDisc.set(n.toLowerCase(), p); }
  }
  const files = [];
  for (const name of readdirSync(data).sort()) {
    const own = join(data, name);
    if (!statSync(own).isFile() || SKIP.test(name)) continue;
    const from = onDisc.size ? onDisc.get(name.toLowerCase()) : own;
    if (!from) continue;
    files.push({ name, size: statSync(from).size, from });
  }
  return { files, data, disc: onDisc.size ? disc : null };
}
