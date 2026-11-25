#!/usr/bin/env node
// The JS port's tools/sync-version.mjs: package.json is the version of npm, Electron and the packages, and the menu
// shows source/version.js's (Meer instellingen, "Versie ..."), so that file is written from it. npm version runs it
// as its "version" hook; tools/verify-desktop-package.mjs refuses a package where the two differ.
//   node tools/sync-version.mjs   (npm run version:sync)
import {readFile,writeFile} from 'node:fs/promises';

const {version}=JSON.parse(await readFile(new URL('../package.json',import.meta.url),'utf8'));
const output=new URL('../source/version.js',import.meta.url);
const source=`// Generated from package.json by tools/sync-version.mjs (npm run version:sync): the version shown in Meer\n// instellingen ("Versie ..."), as the JavaScript reconstruction's source/version.js.\nexport const GAME_VERSION = ${JSON.stringify(version)};\n`;
if(await readFile(output,'utf8').catch(error=>{
  if(error.code==='ENOENT')return '';
  throw error;
})!==source)await writeFile(output,source);
