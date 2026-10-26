import {_electron as electron} from 'playwright';
import assert from 'node:assert/strict';
import {mkdtemp,mkdir,readFile,writeFile,rm,stat} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {createHash} from 'node:crypto';
import {spawn} from 'node:child_process';

const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const executable=process.env.RCSK_DESKTOP_EXECUTABLE;
const variant=executable?'packaged':'source';
const directory=path.join(root,'evidence/desktop',variant);
await mkdir(directory,{recursive:true});
const profile=await mkdtemp(path.join(tmpdir(),'rcsk-desktop-test-'));
const noSandbox=process.env.RCSK_DESKTOP_NO_SANDBOX==='1';
const graphicsArgs=[...(noSandbox?['--no-sandbox']:[]),'--ozone-platform=x11','--disable-dev-shm-usage','--use-angle=swiftshader',
  '--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required'];
const report={status:'running',variant,platform:process.platform,profile,graphicsArgs,
  windowManager:process.env.RCSK_DESKTOP_WINDOW_MANAGER||'host desktop/window manager (required for native fullscreen)',
  scope:'Automated Linux Electron under Xvfb with SwiftShader software GPU. Real original media decoding/playback, native menu actions, authored race opening and ordinary keyboard movement. No full-race, physical GPU, sound-card output, or Windows/macOS execution claim. Renderer Node isolation is checked separately.',
  chromiumSandboxDisabled:noSandbox,
  checks:[],errors:[],warnings:[],launches:[],screenshots:[]};
let app,page,launchNumber=0;
const check=async(name,fn)=>{const details=await fn();report.checks.push({name,...(details||{})});console.log(`PASS ${name}`);};
const native=name=>page.locator(`[data-native=${name}]`);
const form=name=>page.waitForSelector(`[data-form=${name}]`,{timeout:30000});
const shot=async name=>{await page.screenshot({path:path.join(directory,name+'.png')});report.screenshots.push(name+'.png');};

async function launch(skipIntro=false){
  const env={...process.env,RCSK_USER_DATA:profile};delete env.ELECTRON_RUN_AS_NODE;
  const args=[...(executable?[]:['.']),...graphicsArgs,...(skipIntro?['--skip-intro']:[])];
  app=await electron.launch({...(executable?{executablePath:executable}:{}),args,cwd:root,env,timeout:180000});
  const run={number:++launchNumber,args,stdout:'',stderr:''};report.launches.push(run);
  for(const stream of ['stdout','stderr'])app.process()[stream]?.on('data',data=>{run[stream]=(run[stream]+data.toString()).slice(-30000);});
  app.context().on('page',observe);
  for(const existing of app.context().pages())observe(existing);
  page=await app.firstWindow({timeout:60000});page.setDefaultTimeout(30000);
  await page.waitForLoadState('domcontentloaded');
  run.runtime=await app.evaluate(({app,BrowserWindow})=>({
    packaged:app.isPackaged,appPath:app.getAppPath(),resourcesPath:process.resourcesPath,
    profile:app.getPath('userData'),sessionData:app.getPath('sessionData'),versions:process.versions,
    preferences:BrowserWindow.getAllWindows()[0].webContents.getLastWebPreferences(),
  }));
  assert.equal(run.runtime.profile,profile);assert.equal(run.runtime.sessionData,profile);
  assert.equal(run.runtime.packaged,Boolean(executable));
}
const observed=new WeakSet();
function observe(window){
  if(observed.has(window))return;observed.add(window);
  window.on('pageerror',error=>report.errors.push({launch:launchNumber,type:'pageerror',message:String(error.stack||error)}));
  window.on('console',message=>{
    if(message.type()==='error')report.errors.push({launch:launchNumber,type:'console',message:message.text()});
    else if(message.type()==='warning')report.warnings.push({launch:launchNumber,message:message.text()});
  });
  window.on('response',response=>{if(response.status()>=400)report.errors.push({launch:launchNumber,type:'http',status:response.status(),url:response.url()});});
  window.on('requestfailed',request=>{if(request.failure()?.errorText!=='net::ERR_ABORTED')report.errors.push({launch:launchNumber,type:'request',url:request.url(),failure:request.failure()});});
}
async function observePlayback(){
  await page.evaluate(()=>{
    window.desktopPlayback={media:[],buffers:[]};
    const play=HTMLMediaElement.prototype.play;
    HTMLMediaElement.prototype.play=function(...args){
      this.addEventListener('playing',()=>window.desktopPlayback.media.push({
        source:this.currentSrc,duration:this.duration,readyState:this.readyState,volume:this.volume,
      }),{once:true});
      return play.apply(this,args);
    };
    const start=AudioBufferSourceNode.prototype.start;
    AudioBufferSourceNode.prototype.start=function(...args){
      const result=start.apply(this,args);
      window.desktopPlayback.buffers.push({duration:this.buffer?.duration,frames:this.buffer?.length,
        sampleRate:this.buffer?.sampleRate,context:this.context.state,loop:this.loop});
      return result;
    };
  });
}

try{
  assert.equal(process.platform,'linux','This smoke test currently validates Linux Electron only.');
  if(executable){assert.ok(path.isAbsolute(executable),'RCSK_DESKTOP_EXECUTABLE must be absolute.');assert.ok((await stat(executable)).isFile());}
  report.sourceSha256={};
  for(const name of ['package.json','electron/main.mjs','electron/runtime.mjs','electron/game-protocol.mjs','tests/desktop.mjs'])
    report.sourceSha256[name]=createHash('sha256').update(await readFile(path.join(root,name))).digest('hex');
  await launch();
  await check('Original intro decodes and advances in the desktop protocol',async()=>{
    await page.waitForFunction(()=>window.rcsk?.state.page==='intro'&&document.querySelector('#movie').readyState>=2,null,{timeout:60000});
    if(await page.locator('#movie').evaluate(video=>video.paused||video.muted))await page.locator('#movie-audio').click();
    await page.waitForFunction(()=>{
      const video=document.querySelector('#movie');
      return !video.paused&&video.currentTime>.4&&video.webkitDecodedFrameCount>0&&video.webkitAudioDecodedByteCount>0;
    },null,{timeout:30000});
    const media=await page.locator('#movie').evaluate(video=>({url:video.currentSrc,currentTime:video.currentTime,
      duration:video.duration,width:video.videoWidth,height:video.videoHeight,frames:video.webkitDecodedFrameCount,
      decodedAudioBytes:video.webkitAudioDecodedByteCount,muted:video.muted,volume:video.volume}));
    assert.equal(media.url,'rcsk://game/assets/media/intro.mp4');assert.ok(media.duration>0);
    assert.equal(media.muted,false);assert.equal(media.volume,1);await shot('intro');return {media};
  });
  await check('Local media HEAD and byte-range responses support playback',async()=>{
    const response=await page.evaluate(async()=>{
      const url='/assets/media/intro.mp4';
      const head=await fetch(url,{method:'HEAD'}),range=await fetch(url,{headers:{Range:'bytes=0-31'}});
      return {head:{status:head.status,length:Number(head.headers.get('content-length')),bytes:(await head.arrayBuffer()).byteLength,
        type:head.headers.get('content-type'),acceptRanges:head.headers.get('accept-ranges')},
      range:{status:range.status,contentRange:range.headers.get('content-range'),bytes:[...new Uint8Array(await range.arrayBuffer())]}};
    });
    assert.equal(response.head.status,200);assert.ok(response.head.length>32);assert.equal(response.head.bytes,0);
    assert.equal(response.head.type,'video/mp4');assert.equal(response.head.acceptRanges,'bytes');
    assert.equal(response.range.status,206);assert.equal(response.range.contentRange,`bytes 0-31/${response.head.length}`);
    assert.equal(response.range.bytes.length,32);assert.equal(Buffer.from(response.range.bytes).subarray(4,8).toString(),'ftyp');
    return response;
  });
  await check('Renderer has no Node globals and retains isolated sandbox preferences',async()=>{
    const renderer=await page.evaluate(()=>({require:typeof require,process:typeof process,module:typeof module,origin:location.origin}));
    assert.deepEqual(renderer,{require:'undefined',process:'undefined',module:'undefined',origin:'rcsk://game'});
    const prefs=report.launches[0].runtime.preferences;
    for(const key of ['nodeIntegration','nodeIntegrationInWorker','nodeIntegrationInSubFrames'])assert.equal(prefs[key],false,key);
    assert.equal(prefs.contextIsolation,true);assert.equal(prefs.sandbox,true);assert.equal(prefs.webSecurity,true);
    return {renderer};
  });
  await observePlayback();
  await page.keyboard.press('Enter');await form('TFRMMAIN');
  await check('Original main-menu artwork and greeting play',async()=>{
    await page.waitForFunction(()=>window.desktopPlayback.media.some(event=>event.source.endsWith('/mn_hm02.wav')&&event.duration>0));
    const menu=await page.evaluate(async()=>{
      await document.fonts.ready;
      const images=[...document.querySelectorAll('#screen img')];await Promise.all(images.map(image=>image.decode()));
      return {images:images.map(image=>({url:image.src,width:image.naturalWidth,height:image.naturalHeight})),
        quickrace:getComputedStyle(document.querySelector('[data-native=btnQuickRace]')).backgroundImage,
        greeting:window.desktopPlayback.media.find(event=>event.source.endsWith('/mn_hm02.wav'))};
    });
    assert.ok(menu.images.length>=3&&menu.images.every(image=>image.width>0&&image.url.startsWith('rcsk://game/assets/menu/')));
    assert.match(menu.quickrace,/mn_0102/);await shot('menu');return menu;
  });
  await check('F11 enters and leaves native fullscreen',async()=>{
    assert.equal(await app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows()[0].isFullScreen()),false);
    // CDP keys target the renderer. Desktop accelerators must traverse
    // Electron's browser-side before-input-event path instead.
    await desktopKey('F11');
    await poll(()=>app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows()[0].isFullScreen()));
    await desktopKey('F11');
    await poll(async()=>!await app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows()[0].isFullScreen()));
  });
  await check('A second launch with the same profile returns to the existing window',async()=>{
    const before=await app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows().map(window=>window.id));
    const env={...process.env,RCSK_USER_DATA:profile};delete env.ELECTRON_RUN_AS_NODE;
    const args=[...(executable?[]:['.']),...graphicsArgs,'--skip-intro'];
    const second=spawn(app.process().spawnfile,args,{cwd:root,env,stdio:['ignore','pipe','pipe']});
    let stderr='';second.stderr.on('data',data=>{stderr=(stderr+data).slice(-4000);});
    const result=await new Promise((resolve,reject)=>{
      const timer=setTimeout(()=>{second.kill('SIGKILL');reject(Error('Second desktop launch did not exit after handing off its profile.'));},15000);
      second.once('error',error=>{clearTimeout(timer);reject(error);});
      second.once('close',(code,signal)=>{clearTimeout(timer);resolve({code,signal});});
    });
    assert.equal(result.code,0);assert.equal(result.signal,null);
    assert.deepEqual(await app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows().map(window=>window.id)),before);
    await poll(()=>app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows()[0].isFocused()));
    return {...result,stderr};
  });
  await native('btnQuickRace').click();await form('TFRMSELECTCHAR');
  await native('btnNext').click();await page.waitForFunction(()=>rcsk.state.selection.character===1);
  await native('rdoMedium').click();await native('btnOk').click();await form('TFRMSELECTCOUNTRY');
  await native('rdoItem').click();await native('btnOk').click();await form('TFRMCONTROLSETTINGS');
  await native('btnOk').click();
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:120000});
  await check('Native QuickRace selections enter the authored camera opening',async()=>{
    const state=await page.evaluate(()=>({selection:rcsk.state.selection,phase:rcsk.viewer.race.phase,
      elapsed:rcsk.viewer.race.elapsedMs,startCamera:!!rcsk.viewer.simulation.startCamera,
      countdownStarted:rcsk.viewer.simulation.countdownStarted,movementActive:rcsk.viewer.simulation.movementActive,
      difficulty:rcsk.viewer.simulation.difficulty,mode:rcsk.viewer.race.raceType}));
    assert.deepEqual(state.selection,{character:1,difficulty:1,country:0,race:2});
    assert.equal(state.phase,1);assert.equal(state.elapsed,0);assert.equal(state.startCamera,true);
    assert.equal(state.countdownStarted,false);assert.equal(state.movementActive,false);
    assert.equal(state.difficulty,1);assert.equal(state.mode,2);await shot('race-opening');return state;
  });
  await page.keyboard.down('ArrowUp');
  await check('Original countdown prevents motion until green',async()=>{
    await page.waitForFunction(()=>rcsk.viewer.simulation.countdown.phase===2,null,{timeout:60000});
    const speed=await page.evaluate(()=>rcsk.viewer.motion.body.forwardSpeed);assert.equal(speed,0);
    await shot('race-countdown');
    await page.waitForFunction(()=>rcsk.viewer.simulation.movementActive,null,{timeout:60000});
  });
  await check('Keyboard driving renders the original course and starts race audio',async()=>{
    const before=await page.evaluate(()=>[...rcsk.viewer.motion.body.position]);
    await page.waitForFunction(()=>rcsk.viewer.motion.body.forwardSpeed>5,null,{timeout:30000});
    await page.waitForTimeout(1000);await page.keyboard.up('ArrowUp');
    await page.waitForFunction(()=>desktopPlayback.buffers.some(event=>event.context==='running'&&event.frames>0)
      &&rcsk.viewer.music.audio.currentTime>0&&!rcsk.viewer.music.audio.paused,null,{timeout:30000});
    const race=await page.evaluate(()=>{
      const v=rcsk.viewer,gl=v.renderer.getContext(),extension=gl.getExtension('WEBGL_debug_renderer_info');
      return {position:[...v.motion.body.position],speed:v.motion.body.forwardSpeed,triangles:v.renderStats.world.triangles,
        presentationTriangles:v.renderStats.presentation.triangles,hud:v.renderStats.hud,
        errors:v.errors,canvas:[v.renderer.domElement.width,v.renderer.domElement.height],engineActive:v.audio.engine.active,
        audioState:v.audio.context.state,bufferStarts:desktopPlayback.buffers,music:{url:v.music.audio.currentSrc,
          currentTime:v.music.audio.currentTime,decodedBytes:v.music.audio.webkitAudioDecodedByteCount,volume:v.music.audio.volume},
        renderer:extension?gl.getParameter(extension.UNMASKED_RENDERER_WEBGL):gl.getParameter(gl.RENDERER)};
    });
    assert.ok(Math.hypot(...race.position.map((value,index)=>value-before[index]))>1);
    assert.ok(race.triangles>1000&&race.canvas.every(size=>size>0));assert.deepEqual(race.errors,[]);
    assert.equal(race.presentationTriangles,1);assert.ok(race.hud.glyphs>0);
    assert.equal(race.engineActive,true);assert.equal(race.audioState,'running');assert.ok(race.music.decodedBytes>0);
    assert.match(race.music.url,/^rcsk:\/\/game\/assets\/.*\.mp3$/);assert.match(race.renderer,/SwiftShader/i);
    await shot('race-driving');return race;
  });
  await page.keyboard.press('Escape');await form('RACE_STOPPEN');
  await page.getByRole('button',{name:'Ja',exact:true}).click();await form('TFRMMAIN');
  let persisted;
  await check('Native race exit and settings OK commit the local save',async()=>{
    await native('btnMainOptions').click();await form('TFRMOPTIONS');
    await native('rdoLowQual').click();await native('btnOk').click();await form('TFRMMAIN');
    persisted=await page.evaluate(()=>({selection:rcsk.state.selection,settings:rcsk.state.settings,
      storage:Object.fromEntries(['rcsk.selection.v1','rcsk.settings.v1','rcsk.race-save.v1'].map(key=>[key,localStorage.getItem(key)]))}));
    assert.equal(persisted.settings.resolution,'640x480');
    assert.ok(Object.values(persisted.storage).every(value=>value!==null));return persisted;
  });
  await app.close();app=null;
  await launch(true);await form('TFRMMAIN');
  await check('Selections, settings and save survive app relaunch with --skip-intro',async()=>{
    const restored=await page.evaluate(()=>({selection:rcsk.state.selection,settings:rcsk.state.settings,
      storage:Object.fromEntries(['rcsk.selection.v1','rcsk.settings.v1','rcsk.race-save.v1'].map(key=>[key,localStorage.getItem(key)])),
      introHidden:document.querySelector('#intro').hidden,movieSource:document.querySelector('#movie').getAttribute('src')}));
    assert.deepEqual(restored.selection,persisted.selection);assert.deepEqual(restored.settings,persisted.settings);
    assert.deepEqual(restored.storage,persisted.storage);assert.equal(restored.introHidden,true);assert.equal(restored.movieSource,null);
    await shot('relaunch');return restored;
  });
  await check('Original menu quit requester closes the Electron application',async()=>{
    await native('btnMainStop').click();await form('TFRMREQUESTER');
    const prompt=await page.locator('[data-element=lblQuit]').textContent();assert.ok(prompt.trim().length>10);
    assert.equal(await native('btnOk').textContent(),'Ja');await shot('quit-requester');
    const closed=app.waitForEvent('close',{timeout:30000});await native('btnOk').click();await closed;app=null;
    return {prompt};
  });
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){
  report.status='failed';report.failure=String(error.stack||error);process.exitCode=1;
  if(page&&!page.isClosed())try{await shot('failure');}catch{}
}finally{
  if(app)try{await app.close();}catch(error){report.cleanupError=String(error);}
  await rm(profile,{recursive:true,force:true}).catch(error=>{report.profileCleanupError=String(error);});
  await writeFile(path.join(directory,'report.json'),JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors,failure:report.failure,report:path.join(directory,'report.json')}));
}

async function poll(predicate,timeout=10000){
  const until=Date.now()+timeout;
  while(Date.now()<until){if(await predicate())return;await new Promise(resolve=>setTimeout(resolve,50));}
  throw Error('Desktop window state did not change before timeout.');
}
async function desktopKey(keyCode){
  await app.evaluate(({BrowserWindow},key)=>{
    const contents=BrowserWindow.getAllWindows()[0].webContents;
    contents.sendInputEvent({type:'keyDown',keyCode:key});
    contents.sendInputEvent({type:'keyUp',keyCode:key});
  },keyCode);
}
