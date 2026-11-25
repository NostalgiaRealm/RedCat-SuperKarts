import path from 'node:path';

// The JS port's desktop app identity (../RedCat Superkarts/electron/runtime.mjs, 1.0.x), unchanged on purpose: the
// same name, scheme, origin and profile folder give 2.0.0 the localStorage of an installed 1.0.x (rcsk.* keys,
// read and written by the same menu code), so saves, settings and highscores carry over with nothing to do.
export const APP_NAME='RedCat SuperKarts';
export const GAME_SCHEME='rcsk';
export const GAME_ORIGIN='rcsk://game';

// The packaged website (npm run package -> dist/site) is the game: inside a package it is resources/site, in a
// checkout dist/site, or the absolute folder RCSK_SITE names (a checkout only: a package runs what it ships). The
// icon is in app.asar in both.
export function gamePaths({packaged,appPath,resourcesPath,site=process.env.RCSK_SITE}){
  if(!packaged&&site&&!path.isAbsolute(site))throw Error('RCSK_SITE must be an absolute directory path.');
  return {root:packaged?path.join(resourcesPath,'site'):site?path.normalize(site):path.join(appPath,'dist','site'),
    icon:path.join(appPath,'desktop/icons/icon.png')};
}

export function userDataPath(appData,override){
  if(override!==undefined){
    if(!path.isAbsolute(override))throw Error('RCSK_USER_DATA must be an absolute directory path.');
    return path.normalize(override);
  }
  return path.join(appData,APP_NAME);
}

export function launchURL(argv){return GAME_ORIGIN+'/'+(argv.includes('--skip-intro')?'?skipIntro':'');}

// Only the page itself may be shown (any query: the menu's ?skipIntro, ?drive=N and its reload after an import).
export function isGameNavigation(value){
  try{
    const url=new URL(value);
    return url.protocol===GAME_SCHEME+':'&&url.hostname==='game'&&!url.port
      &&!url.username&&!url.password&&['/','/index.html'].includes(url.pathname);
  }catch{return false;}
}

export const RENDERER_PREFERENCES=Object.freeze({
  nodeIntegration:false,nodeIntegrationInWorker:false,nodeIntegrationInSubFrames:false,
  contextIsolation:true,sandbox:true,webSecurity:true,allowRunningInsecureContent:false,
  webviewTag:false,spellcheck:false,autoplayPolicy:'no-user-gesture-required',
});
