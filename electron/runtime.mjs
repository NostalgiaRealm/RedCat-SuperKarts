import path from 'node:path';

export const APP_NAME='RedCat SuperKarts';
export const GAME_SCHEME='rcsk';
export const GAME_ORIGIN='rcsk://game';

export function gamePaths({packaged,appPath,resourcesPath}){
  const root=packaged?path.join(resourcesPath,'game'):appPath;
  return {root,assetsRoot:path.join(root,packaged?'assets':'public/assets'),
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
