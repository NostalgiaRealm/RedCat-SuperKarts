import {app,BrowserWindow,Menu,dialog,protocol,session} from 'electron';
import {mkdirSync} from 'node:fs';
import {assertGameRuntime,createGameProtocolHandler} from './game-protocol.mjs';
import {APP_NAME,GAME_SCHEME,RENDERER_PREFERENCES,gamePaths,isGameNavigation,launchURL,userDataPath} from './runtime.mjs';

// These privileges must be registered synchronously, before app.ready.
protocol.registerSchemesAsPrivileged([{scheme:GAME_SCHEME,privileges:{
  standard:true,secure:true,supportFetchAPI:true,stream:true,
}}]);
app.setName(APP_NAME);
try{
  const profile=userDataPath(app.getPath('appData'),process.env.RCSK_USER_DATA);
  mkdirSync(profile,{recursive:true});app.setPath('userData',profile);app.setPath('sessionData',profile);
}catch(error){console.error(error.message);app.exit(1);}

let mainWindow,runtimePaths;
const startURL=launchURL(process.argv);
function createWindow(paths){
  const window=new BrowserWindow({title:APP_NAME,icon:paths.icon,width:1024,height:768,
    minWidth:360,minHeight:480,backgroundColor:'#10192b',show:false,
    webPreferences:{...RENDERER_PREFERENCES}});
  mainWindow=window;
  window.once('ready-to-show',()=>window.show());
  window.on('closed',()=>{if(mainWindow===window)mainWindow=null;});
  window.on('page-title-updated',event=>event.preventDefault());
  window.webContents.setWindowOpenHandler(()=>({action:'deny'}));
  for(const event of ['will-navigate','will-redirect'])window.webContents.on(event,(event,url)=>{
    if(!isGameNavigation(url))event.preventDefault();
  });
  window.webContents.on('will-attach-webview',event=>event.preventDefault());
  window.webContents.on('before-input-event',(event,input)=>{
    if(input.type==='keyDown'&&input.key==='F11'){
      event.preventDefault();if(!input.isAutoRepeat)window.setFullScreen(!window.isFullScreen());
    }
  });
  window.loadURL(startURL).catch(error=>{
    dialog.showErrorBox(APP_NAME,'Het spel kon niet worden geladen.\n'+error.message);
    window.destroy();
  });
}

// Use the selected profile for Chromium's lock too: isolated test profiles are
// independent, while a second normal launch focuses the running game.
if(!app.requestSingleInstanceLock()){
  app.quit();
}else{
app.on('second-instance',()=>{
  if(mainWindow&&!mainWindow.isDestroyed()){
    if(mainWindow.isMinimized())mainWindow.restore();
    mainWindow.show();mainWindow.focus();
  }else if(runtimePaths){
    createWindow(runtimePaths);
  }
});
app.whenReady().then(async()=>{
  const paths=gamePaths({packaged:app.isPackaged,appPath:app.getAppPath(),resourcesPath:process.resourcesPath});
  await assertGameRuntime(paths);
  protocol.handle(GAME_SCHEME,await createGameProtocolHandler(paths));
  session.defaultSession.setPermissionRequestHandler((contents,permission,callback)=>{
    callback(permission==='fullscreen'&&isGameNavigation(contents?.getURL()));
  });
  session.defaultSession.setPermissionCheckHandler((contents,permission)=>
    permission==='fullscreen'&&isGameNavigation(contents?.getURL()));
  const mac=process.platform==='darwin';
  Menu.setApplicationMenu(Menu.buildFromTemplate([
    ...(mac?[{role:'appMenu',label:APP_NAME}]:[{label:'Spel',submenu:[{role:'quit',label:'Stoppen'}]}]),
    {label:'Bewerken',submenu:[{role:'undo'},{role:'redo'},{type:'separator'},{role:'cut'},{role:'copy'},{role:'paste'},{role:'selectAll'}]},
    {label:'Beeld',submenu:[{role:'togglefullscreen',label:'Volledig scherm',accelerator:mac?'Control+Command+F':'F11'}]},
    ...(mac?[{role:'windowMenu'}]:[]),
  ]));
  runtimePaths=paths;
  createWindow(paths);
  app.on('activate',()=>{if(BrowserWindow.getAllWindows().length===0)createWindow(paths);});
}).catch(error=>{
  console.error(error);
  dialog.showErrorBox(APP_NAME,'Het spel kan niet starten.\n'+error.message);app.quit();
});
app.on('window-all-closed',()=>{if(process.platform!=='darwin')app.quit();});
}
