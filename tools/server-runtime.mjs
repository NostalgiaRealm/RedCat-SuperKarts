import {stat} from 'node:fs/promises';
import path from 'node:path';

// index.html's import map and world.js's eager OrbitControls import require
// these files before main.js can display either the intro or the menu.
export const SERVER_RUNTIME_FILES=Object.freeze([
  'node_modules/three/build/three.module.js',
  'node_modules/three/build/three.core.js',
  'node_modules/three/examples/jsm/controls/OrbitControls.js',
]);

export async function assertServerRuntime(root){
  const checks=await Promise.all(SERVER_RUNTIME_FILES.map(async file=>{
    try{return (await stat(path.join(root,file))).isFile()?null:file;}
    catch{return file;}
  }));
  const missing=checks.filter(Boolean);
  if(missing.length)throw new Error(
    `Cannot start: required browser runtime files are missing or unreadable:\n${missing.map(file=>'  '+file).join('\n')}\n`+
    'Run npm ci in the project folder (or npm install), then run npm start again.'
  );
}
