#!/usr/bin/env node
// Lists the original game files the race may read (name and size) into public/game/files.json, with the packed
// archives that are read by byte ranges (tools/game-data.mjs RANGED) and the page size the browser fetches them in.
// The game worker mounts every file of this list and fetches each when a race needs it (source/web/game-files.js);
// tools/package.mjs copies exactly these files to dist/site/data/.
//   node tools/build-manifest.mjs
import { writeFileSync, mkdirSync } from 'node:fs';
import { join } from 'node:path';
import { ROOT, raceFiles, RANGED, PAGE } from './game-data.mjs';

const { files, data, disc } = raceFiles();
mkdirSync(join(ROOT, 'public/game'), { recursive: true });
writeFileSync(join(ROOT, 'public/game/files.json'), JSON.stringify({ base: 'data/', page: PAGE, ranged: files.filter((f) => RANGED.test(f.name)).map((f) => f.name), files: files.map((f) => [f.name, f.size]) }));
console.log(`${files.length} files, ${(files.reduce((s, f) => s + f.size, 0) / 1048576).toFixed(1)} MB -> public/game/files.json
  from ${disc || data}${disc ? `\n  (named as in ${data})` : ''}`);
