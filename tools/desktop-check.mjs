#!/usr/bin/env node
// Launch check of a packaged Linux desktop build (the JS port's tests/desktop.mjs and run-desktop-test-linux.sh, for
// the recomp), in Xvfb with SwiftShader, through Playwright's Electron driver. Not a gameplay test.
//   1. With --legacy EXE (the JS port's 1.0.x linux executable, e.g. from its release tar.gz): that app writes its
//      saves in a fresh profile with its own menu (an Adventure profile "Rick", Meer instellingen, Alles
//      ontgrendelen, a QuickRace selection), plus a finished race and a highscore through the same save code
//      (source/menu/race-save.js, a copy of the JS port's), written in its page. Then it is closed.
//   2. The 2.0.0 build starts on that profile (RCSK_USER_DATA, as the 1.0.x app would be replaced): the intro and the
//      menu appear, the page is cross-origin isolated, the protocol's answers carry the isolation headers, the policy,
//      the right types and byte ranges, every rcsk.* key of step 1 is there unchanged and the menu shows them, the menu
//      bar, F11, single instance and the navigation lock work, a QuickRace starts and draws, Esc + J leaves it, and a
//      relaunch with --skip-intro keeps the saves; the menu's Stoppen > Ja closes the app.
//   node tools/desktop-check.mjs [--exe release/2.0.0/linux-unpacked/redcat-superkarts] [--legacy EXE] [--no-sandbox]
//   node tools/desktop-check.mjs --source [--legacy EXE]   (electron . on dist/site, or on RCSK_SITE)
// --out DIR puts the report and screenshots elsewhere (default evidence/desktop).
// Re-runs itself under xvfb-run (and dbus-run-session when there is one) unless RCSK_DESKTOP_TEST_DISPLAY_READY=1.
// Without a window manager F11 is checked through Electron's own fullscreen state only. Report and screenshots:
// evidence/desktop/ (report.json). Exit code 1 when a check failed or the page reported an error.
import assert from 'node:assert/strict';
import {mkdtemp,mkdir,readFile,writeFile,rm,stat} from 'node:fs/promises';
import {spawn,spawnSync} from 'node:child_process';
import {inflateSync} from 'node:zlib';
import {tmpdir} from 'node:os';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {readRaceSave,writeRaceSave,applyRaceResult,saveHighscore} from '../source/menu/race-save.js';

const root=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const args=process.argv.slice(2);
const opt=(name,fallback)=>{const k=args.indexOf('--'+name);return k<0?fallback:args[k+1];};
const version=JSON.parse(await readFile(path.join(root,'package.json'),'utf8')).version;
const source=args.includes('--source');
const executable=source?'source':path.resolve(root,opt('exe',`release/${version}/linux-unpacked/redcat-superkarts`));
const legacy=opt('legacy',process.env.RCSK_LEGACY_EXECUTABLE)?path.resolve(opt('legacy',process.env.RCSK_LEGACY_EXECUTABLE)):null;

if(process.env.RCSK_DESKTOP_TEST_DISPLAY_READY!=='1'){
  if(spawnSync('xvfb-run',['--help']).error){console.error('desktop-check: xvfb-run is needed');process.exit(1);}
  const dbus=!spawnSync('dbus-run-session',['--version']).error?['dbus-run-session','--']:[];
  const child=spawn('xvfb-run',['-a','-s','-screen 0 1280x1024x24',...dbus,process.execPath,fileURLToPath(import.meta.url),...args],
    {stdio:'inherit',env:{...process.env,RCSK_DESKTOP_TEST_DISPLAY_READY:'1'}});
  child.on('exit',code=>process.exit(code??1));
}else{

const {_electron:electron}=await import('playwright');
const directory=path.resolve(root,opt('out','evidence/desktop'));
await mkdir(directory,{recursive:true});
const profile=await mkdtemp(path.join(tmpdir(),'rcsk-desktop-check-'));
const graphicsArgs=[...(args.includes('--no-sandbox')?['--no-sandbox']:[]),'--ozone-platform=x11','--disable-dev-shm-usage',
  '--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required'];
const report={status:'running',version,executable,legacy,profile,graphicsArgs,
  scope:'Linux x64 package under Xvfb with SwiftShader, no window manager, no sound card. Not run: Windows, macOS, a physical GPU, a whole race.',
  checks:[],errors:[],launches:[],screenshots:[]};
let app=null,page=null,launchNumber=0,failed=0;
const check=async(name,fn)=>{
  try{const details=await fn();report.checks.push({name,ok:true,...(details||{})});console.log(`ok    ${name}`);}
  catch(error){failed++;report.checks.push({name,ok:false,error:String(error.message||error).split('\n').slice(0,4).join('\n')});
    console.log(`FAIL  ${name}: ${String(error.message||error).split('\n')[0]}`);if(page&&!page.isClosed())await shot('fail-'+report.checks.length).catch(()=>{});}
};
const native=name=>page.locator(`[data-native=${name}]`);
const form=(name,timeout=30000)=>page.waitForSelector(`[data-form=${name}]`,{timeout});
const shot=async name=>{const file=path.join(directory,name+'.png');await page.screenshot({path:file});report.screenshots.push(name+'.png');return file;};
const dump=()=>page.evaluate(()=>Object.fromEntries(Object.keys(localStorage).filter(k=>k.startsWith('rcsk.')).sort().map(k=>[k,localStorage.getItem(k)])));
const sleep=ms=>new Promise(resolve=>setTimeout(resolve,ms));

async function launch(exe,{skipIntro=false,tag}={}){
  const env={...process.env,RCSK_USER_DATA:profile};delete env.ELECTRON_RUN_AS_NODE;
  const launchArgs=[...graphicsArgs,...(skipIntro?['--skip-intro']:[])];
  app=await electron.launch(exe==='source'?{args:['.',...launchArgs],cwd:root,env,timeout:180000}:{executablePath:exe,args:launchArgs,env,timeout:180000});
  const run={number:++launchNumber,tag,exe,args:launchArgs,stdout:'',stderr:''};report.launches.push(run);
  for(const stream of ['stdout','stderr'])app.process()[stream]?.on('data',data=>{run[stream]=(run[stream]+data.toString()).slice(-20000);});
  page=await app.firstWindow({timeout:60000});page.setDefaultTimeout(30000);
  page.on('pageerror',error=>report.errors.push({launch:launchNumber,type:'pageerror',message:String(error.stack||error)}));
  page.on('console',message=>{if(message.type()==='error'&&!/expected-error/.test(message.location()?.url||''))report.errors.push({launch:launchNumber,type:'console',message:message.text()});});
  page.on('response',response=>{if(response.status()>=400&&!/expected-error/.test(response.url()))report.errors.push({launch:launchNumber,type:'http',status:response.status(),url:response.url()});});
  await page.waitForLoadState('domcontentloaded');
  run.runtime=await app.evaluate(({app,BrowserWindow})=>({packaged:app.isPackaged,name:app.getName(),version:app.getVersion(),
    profile:app.getPath('userData'),sessionData:app.getPath('sessionData'),appData:app.getPath('appData'),
    resourcesPath:process.resourcesPath,electron:process.versions.electron,chrome:process.versions.chrome,
    preferences:BrowserWindow.getAllWindows()[0].webContents.getLastWebPreferences()}));
  return run;
}
async function close(){if(app){await app.close().catch(()=>{});app=null;page=null;}}
async function poll(predicate,timeout=10000){
  const until=Date.now()+timeout;
  while(Date.now()<until){if(await predicate())return true;await sleep(50);}
  throw Error('state did not change before the time-out');
}
async function desktopKey(keyCode){
  await app.evaluate(({BrowserWindow},key)=>{
    const contents=BrowserWindow.getAllWindows()[0].webContents;
    contents.sendInputEvent({type:'keyDown',keyCode:key});contents.sendInputEvent({type:'keyUp',keyCode:key});
  },keyCode);
}
// The share of distinct colours in a grid of a PNG screenshot (8-bit RGB/RGBA, as Chromium writes them): a blank
// or one-colour canvas has one or two.
async function colours(file){
  const png=await readFile(file);let offset=8,width=0,height=0,channels=0;const parts=[];
  while(offset<png.length){
    const length=png.readUInt32BE(offset),type=png.toString('latin1',offset+4,offset+8),data=png.subarray(offset+8,offset+8+length);
    if(type==='IHDR'){width=data.readUInt32BE(0);height=data.readUInt32BE(4);channels={2:3,6:4}[data[9]];assert.equal(data[8],8);}
    else if(type==='IDAT')parts.push(data);
    offset+=12+length;
  }
  const raw=inflateSync(Buffer.concat(parts)),stride=width*channels,rows=[];let previous=Buffer.alloc(stride);
  for(let y=0;y<height;y++){
    const filter=raw[y*(stride+1)],line=Buffer.from(raw.subarray(y*(stride+1)+1,(y+1)*(stride+1)));
    for(let x=0;x<stride;x++){
      const a=x>=channels?line[x-channels]:0,b=previous[x],c=x>=channels?previous[x-channels]:0;
      const p=a+b-c,pa=Math.abs(p-a),pb=Math.abs(p-b),pc=Math.abs(p-c);
      line[x]=(line[x]+[0,a,b,(a+b)>>1,pa<=pb&&pa<=pc?a:pb<=pc?b:c][filter])&255;
    }
    rows.push(line);previous=line;
  }
  const seen=new Set();
  for(let y=0;y<height;y+=8)for(let x=0;x<width;x+=8){const r=rows[y],i=x*channels;seen.add((r[i]<<16)|(r[i+1]<<8)|r[i+2]);}
  return seen.size;
}

let seeded=null;
try{
  assert.equal(process.platform,'linux','This check runs the Linux build only.');
  if(!source)assert.ok((await stat(executable)).isFile(),'no executable '+executable);

  // --- 1. the 1.0.x app writes its saves ---------------------------------------------------------------------------
  if(legacy){
    await launch(legacy,{skipIntro:true,tag:'legacy'});
    await check('the 1.0.x app starts on the scratch profile with the shared identity',async()=>{
      const r=report.launches.at(-1).runtime;
      assert.equal(r.profile,profile);assert.equal(r.name,'RedCat SuperKarts');
      assert.equal(await page.evaluate(()=>location.origin),'rcsk://game');
      return {legacyVersion:r.version,electron:r.electron};
    });
    await form('TFRMMAIN',60000);
    await native('btnAdventure').click();await form('TFRMADVENTUREMAIN');
    await native('btnNewPlayer').click();await form('TFRMEDITBOX');
    await page.locator('[data-element=edtName]').fill('Rick');await page.keyboard.press('Enter');
    await form('TFRMSELECTCHAR');
    await native('btnNext').click();await page.waitForTimeout(1600);
    await native('btnOk').click();await form('TFRMADVENTBRIEF');
    await native('btnBack').click();await form('TFRMMAIN');
    await native('btnMainOptions').click();await form('TFRMOPTIONS');
    await page.locator('[data-native=btnMoreSettings]').click();await page.waitForSelector('.settings-form');
    await page.selectOption('#resolution','1280x720');
    await page.locator('#scale').fill('150');await page.locator('#scale').dispatchEvent('input');
    await page.locator('#surface-shadows').uncheck();
    await page.locator('#unlock-all').click();
    await page.waitForFunction(()=>/ontgrendeld en opgeslagen/.test(document.getElementById('unlock-status').textContent));
    await page.locator('.more-settings-accept').click();await form('TFRMOPTIONS');
    await native('btnOk').click();await form('TFRMMAIN');
    await native('btnQuickRace').click();await form('TFRMSELECTCHAR');
    await native('btnNext').click();await page.waitForTimeout(1600);
    await native('btnOk').click();await form('TFRMSELECTCOUNTRY');
    await native('btnRight').click();await page.waitForTimeout(1600);
    await native('btnBack').click();await form('TFRMSELECTCHAR');
    await native('btnBack').click();await form('TFRMMAIN');
    const written=await dump();
    // a finished Nederland QuickRace and its highscore, through the same save code (a real one takes five laps)
    const store={getItem:k=>written[k]??null,setItem:(k,v)=>{written[k]=v;}};
    const save=readRaceSave(store);
    applyRaceResult(save,{PLAYER:{finished:1,damage:0,tracktime:371250,position:1,EUROSTARS:0,FASTEST_LAP:70110},
      RACERS:{0:'1,0,369000',1:'2,2,372000',2:'3,3,380000',3:'4,4,390000',4:'0,1,371250'},
      'BEST TIMES':{LAP_RECORD_E0:70110,RACE_RECORD_E0:371250,TIME_CHECK_COUNT_E0:0}});
    saveHighscore(save,0,{name:'Rick',character:1,totalRaceMs:371250,bestLapMs:70110,difficulty:1});
    writeRaceSave(save,store);
    await page.evaluate(keys=>{for(const [k,v] of Object.entries(keys))localStorage.setItem(k,v);},written);
    seeded=await dump();
    await shot('legacy-menu');
    await close();          // a normal quit: Chromium writes the profile's localStorage to disk
    report.seeded=seeded;
    await writeFile(path.join(directory,'legacy-localStorage.json'),JSON.stringify(seeded,null,1)+'\n');
  }

  // --- 2. this build on that profile -------------------------------------------------------------------------------
  const run=await launch(executable,{tag:'2.0.0'});
  await check((source?'the checkout':'the packaged app')+' runs as RedCat SuperKarts '+version+' on the given profile, its renderer sandboxed',async()=>{
    const r=run.runtime;
    assert.equal(r.packaged,!source);assert.equal(r.version,version);assert.equal(r.name,'RedCat SuperKarts');
    assert.equal(r.profile,profile);assert.equal(r.sessionData,profile);
    for(const key of ['nodeIntegration','nodeIntegrationInWorker','nodeIntegrationInSubFrames'])assert.equal(r.preferences[key],false,key);
    assert.equal(r.preferences.contextIsolation,true);assert.equal(r.preferences.sandbox,true);
    return {electron:r.electron,chrome:r.chrome,defaultProfile:path.join(r.appData,'RedCat SuperKarts')};
  });
  await check('the intro plays and Enter leads to the menu',async()=>{
    await page.waitForFunction(()=>window.rcsk?.state.page==='intro',null,{timeout:60000});
    await page.waitForTimeout(1500);await shot('intro');
    const movie=await page.locator('#movie').evaluate(v=>({src:v.currentSrc,readyState:v.readyState,error:v.error?.code??null}));
    await page.keyboard.press('Enter');await form('TFRMMAIN',60000);await page.waitForTimeout(800);await shot('menu');
    return {movie};
  });
  await check('the page is rcsk://game, a secure context and cross-origin isolated',async()=>{
    const p=await page.evaluate(()=>({origin:location.origin,secure:isSecureContext,isolated:crossOriginIsolated,
      sab:typeof SharedArrayBuffer,wait:typeof Atomics.wait,offscreen:typeof OffscreenCanvas,
      webgl2:!!new OffscreenCanvas(1,1).getContext('webgl2'),require:typeof require,process:typeof process}));
    assert.deepEqual(p,{origin:'rcsk://game',secure:true,isolated:true,sab:'function',wait:'function',offscreen:'function',
      webgl2:true,require:'undefined',process:'undefined'});
    return p;
  });
  await check('the protocol: isolation headers and the policy on every answer, types, ranges, refusals',async()=>{
    const r=await page.evaluate(async()=>{
      const build=await (await fetch('build.json')).json(),app=`app/${build.revision}/`;
      const look=async(url,init)=>{const x=await fetch(url,init);const h=k=>x.headers.get(k);
        return {url,status:x.status,type:h('content-type'),length:h('content-length'),range:h('content-range'),accept:h('accept-ranges'),
          coop:h('cross-origin-opener-policy'),coep:h('cross-origin-embedder-policy'),corp:h('cross-origin-resource-policy'),csp:h('content-security-policy'),
          bytes:init?.method==='HEAD'?0:(await x.arrayBuffer()).byteLength};};
      const index=await (await fetch('data/index.json')).json();
      const list=Array.isArray(index)?index:index.files||[];
      const big=list.reduce((a,b)=>(b.size>(a?.size||0)?b:a),null);
      return {revision:build.revision,big,answers:[await look('./'),await look(app+'source/main.js'),await look(app+'source/web/worker.js'),
        await look(app+'game/rcskspel.wasm',{method:'HEAD'}),await look('data/index.json'),
        await look('data/'+encodeURIComponent(big.name),{headers:{Range:'bytes=1000-1999'}}),
        await look('data/'+encodeURIComponent(big.name)+'?expected-error',{headers:{Range:`bytes=${big.size}-`}}),
        await look('assets/fonts/comic.ttf',{method:'HEAD'}),await look('expected-404.js?expected-error'),await look('/%2e%2e/%2e%2e/package.json?expected-error')]};
    });
    const [page_,main,worker,wasm,index,range,badRange,font,missing,outside]=r.answers;
    for(const a of r.answers){
      assert.equal(a.coop,'same-origin',a.url);assert.equal(a.coep,'require-corp',a.url);assert.equal(a.corp,'same-origin',a.url);
      assert.match(a.csp||'',/script-src 'self' 'wasm-unsafe-eval'/,a.url);assert.match(a.csp,/worker-src 'self'/,a.url);
    }
    assert.equal(page_.status,200);assert.match(page_.type,/^text\/html/);
    assert.equal(main.status,200);assert.match(main.type,/^text\/javascript/);assert.match(worker.type,/^text\/javascript/);
    assert.equal(wasm.status,200);assert.equal(wasm.type,'application/wasm');assert.ok(Number(wasm.length)>1e6);assert.equal(wasm.bytes,0);
    assert.equal(index.status,200);assert.equal(index.type,'application/json');
    assert.equal(range.status,206);assert.equal(range.range,`bytes 1000-1999/${r.big.size}`);assert.equal(range.bytes,1000);assert.equal(range.accept,'bytes');
    assert.equal(badRange.status,416);
    assert.equal(font.status,200);assert.equal(font.type,'font/ttf');
    assert.equal(missing.status,404);assert.notEqual(outside.status,200);
    return {revision:r.revision,rangeFile:r.big,answers:r.answers.map(({csp,...a})=>a),csp:page_.csp};
  });
  if(seeded)await check('every rcsk.* key the 1.0.x app wrote is there, unchanged',async()=>{
    const now=await dump();
    for(const [k,v] of Object.entries(seeded))assert.equal(now[k],v,k);
    const sel=(await page.evaluate(()=>window.rcsk.state)).selection;
    assert.deepEqual(sel,JSON.parse(seeded['rcsk.selection.v1']));
    return {keys:Object.keys(seeded)};
  });
  if(seeded)await check('the menu shows the 1.0.x saves: Adventure profile, highscore, settings',async()=>{
    await native('btnAdventure').click();await form('TFRMADVENTUREMAIN');await page.waitForTimeout(300);
    assert.equal(await page.locator('[data-element=lblPlayerName]').innerText(),'Rick');await shot('legacy-adventure');
    await native('btnBack').click();await form('TFRMMAIN');
    await native('btnHighscore').click();await form('TFRMHIGHSCORE');await page.waitForTimeout(300);
    assert.equal(await page.locator('[data-element=lblName1]').innerText(),'Rick');await shot('legacy-highscores');
    await native('btnOk').click();await form('TFRMMAIN');
    const s=(await page.evaluate(()=>window.rcsk.state)).settings;
    assert.deepEqual({resolution:s.resolution,renderScale:s.renderScale,surfaceShadows:s.surfaceShadows},{resolution:'1280x720',renderScale:150,surfaceShadows:false});
  });
  await check('the menu bar is the JS app\'s: Spel, Bewerken, Beeld (F11)',async()=>{
    const menu=await app.evaluate(({Menu})=>Menu.getApplicationMenu().items.map(i=>({label:i.label,items:i.submenu.items.map(s=>[s.label,s.role,s.accelerator||null])})));
    assert.deepEqual(menu.map(m=>m.label),['Spel','Bewerken','Beeld']);
    assert.deepEqual(menu[2].items[0].slice(0,3),['Volledig scherm','togglefullscreen','F11']);
    return {menu};
  });
  await check('F11 toggles fullscreen (Electron\'s window state; no window manager here)',async()=>{
    const full=()=>app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows()[0].isFullScreen());
    assert.equal(await full(),false);
    await desktopKey('F11');await poll(full);
    await desktopKey('F11');await poll(async()=>!await full());
  });
  await check('a second start with the same profile hands over to the running window and exits',async()=>{
    const env={...process.env,RCSK_USER_DATA:profile};delete env.ELECTRON_RUN_AS_NODE;
    const second=spawn(app.process().spawnfile,[...(source?['.']:[]),...graphicsArgs,'--skip-intro'],{cwd:root,env,stdio:['ignore','pipe','pipe']});
    const result=await new Promise((resolve,reject)=>{
      const timer=setTimeout(()=>{second.kill('SIGKILL');reject(Error('the second start did not exit'));},20000);
      second.once('close',(code,signal)=>{clearTimeout(timer);resolve({code,signal});});
    });
    assert.equal(result.code,0);
    assert.equal(await app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows().length),1);
    return result;
  });
  await check('a QuickRace starts from the menu, runs the recompiled race and draws',async()=>{
    await native('btnQuickRace').click();await form('TFRMSELECTCHAR');
    await native('btnOk').click();await form('TFRMSELECTCOUNTRY');
    await native('btnOk').click();await form('TFRMCONTROLSETTINGS');
    await native('btnOk').click();
    const t0=Date.now();
    await page.waitForFunction(()=>window.rcsk.state.page==='driving',null,{timeout:240000,polling:100});
    const loadMs=Date.now()-t0;
    // the start camera and the countdown take about 335 passes of 25 ms
    await page.waitForFunction(()=>{const r=window.rcsk.runner;return Atomics.load(r.ctrl,4)===0&&Atomics.load(r.ctrl,3)>=340;},null,{timeout:180000,polling:100});
    const ctrl=()=>page.evaluate(()=>{const r=window.rcsk.runner;return {frames:Atomics.load(r.ctrl,0),ticks:Atomics.load(r.ctrl,3),phase:Atomics.load(r.ctrl,4),dead:Atomics.load(r.ctrl,1)};});
    const before=await ctrl();
    await page.keyboard.down('ArrowUp');await page.waitForTimeout(3000);
    const file=await shot('race-driving');
    await page.keyboard.up('ArrowUp');
    const after=await ctrl();
    const distinct=await colours(file);
    assert.ok(after.ticks>before.ticks+40,`ticks ${before.ticks} -> ${after.ticks}`);
    assert.ok(after.frames>before.frames+20,`frames ${before.frames} -> ${after.frames}`);
    assert.equal(after.dead,0);assert.ok(distinct>50,`only ${distinct} colours on the screenshot`);
    return {loadMs,before,after,colours:distinct,selection:(await page.evaluate(()=>window.rcsk.state)).selection};
  });
  await check('Esc and J leave the race for the menu',async()=>{
    await page.keyboard.press('Escape');await page.waitForTimeout(800);await shot('race-requester');
    await page.keyboard.press('KeyJ');
    await page.waitForFunction(()=>window.rcsk.state.page!=='driving'&&!window.rcsk.state.racing,null,{timeout:60000});
    for(let i=0;i<10&&!(await page.locator('[data-form=TFRMMAIN]').count());i++){await page.keyboard.press('Enter');await page.waitForTimeout(800);}
    await form('TFRMMAIN');
  });
  const persisted=await dump();
  // last on this launch: Playwright keeps waiting for a refused navigation, so nothing after it uses the page
  await check('navigation stays on the game: other pages, other origins and new windows are refused',async()=>{
    const before=page.url();
    const opened=await page.evaluate(()=>window.open('https://example.com/')===null);
    await page.evaluate(()=>{location.href='https://example.com/';});await page.waitForTimeout(1000);
    const afterExternal=page.url();
    await page.evaluate(()=>{location.href='rcsk://game/build.json';});await page.waitForTimeout(1000);
    const afterOther=page.url();
    assert.equal(opened,true);assert.equal(afterExternal,before);assert.equal(afterOther,before);
    assert.equal((await app.evaluate(({BrowserWindow})=>BrowserWindow.getAllWindows().length)),1);
    return {url:before};
  });
  await close();
  await launch(executable,{skipIntro:true,tag:'relaunch'});
  await check('a relaunch with --skip-intro opens the menu with the saves kept',async()=>{
    await form('TFRMMAIN',60000);
    const now=await dump();
    for(const k of ['rcsk.race-save.v1','rcsk.settings.v1','rcsk.selection.v1'])assert.equal(now[k],persisted[k],k);
    if(seeded)assert.ok(JSON.parse(now['rcsk.race-save.v1']).profiles.some(p=>p?.name==='Rick'));
    assert.equal(await page.locator('#intro').evaluate(e=>e.hidden),true);
  });
  await check('Stoppen > Ja in the menu closes the app',async()=>{
    await native('btnMainStop').click();await form('TFRMREQUESTER');await shot('quit-requester');
    const closed=app.waitForEvent('close',{timeout:30000});await native('btnOk').click();await closed;app=null;page=null;
  });
  if(report.errors.length){failed++;report.checks.push({name:'no page errors',ok:false,error:`${report.errors.length} errors`});}
  report.status=failed?'failed':'passed';
}catch(error){
  report.status='failed';report.failure=String(error.stack||error);failed++;
  if(page&&!page.isClosed())try{await shot('failure');}catch{}
}finally{
  await close();
  await rm(profile,{recursive:true,force:true}).catch(()=>{});
  await writeFile(path.join(directory,'report.json'),JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,failed,errors:report.errors.slice(0,10),failure:report.failure,report:path.join(directory,'report.json')}));
  process.exit(failed?1:0);
}
}
