import {readFile,writeFile} from 'node:fs/promises';

// package.json is the version source for npm, Electron and the browser menu.
// npm version runs this hook before refreshing the runtime bundles.
// The small generated module is a build input; the game executes src/ bundles.
const {version}=JSON.parse(await readFile(new URL('../package.json',import.meta.url),'utf8'));
const output=new URL('../source/version.js',import.meta.url);
const source=`// Generated from package.json by tools/sync-version.mjs.\nexport const GAME_VERSION = ${JSON.stringify(version)};\n`;
if(await readFile(output,'utf8').catch(error=>{
  if(error.code==='ENOENT')return '';
  throw error;
})!==source)await writeFile(output,source);
