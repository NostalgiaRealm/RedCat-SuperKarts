import {chromium,_electron as electron} from 'playwright';
import assert from 'node:assert/strict';
import {mkdtemp,mkdir,readFile,writeFile,rm,cp,symlink} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import path from 'node:path';
import {bundleRuntime,projectRoot} from '../tools/bundle.mjs';
import {createWebServer} from '../tools/server-runtime.mjs';
import {assertGameRuntime} from '../electron/game-protocol.mjs';

const output=process.env.RCSK_REPORT_DIR||'evidence/runtime-layout';await mkdir(output,{recursive:true});
const temporary=await mkdtemp(path.join(tmpdir(),'rcsk-runtime-browser-'));
const fixture=JSON.parse(await readFile(new URL('./fixtures/legacy-storage-v1.json',import.meta.url)));
const assetsRoot=path.join(projectRoot,'public/assets');
const report={scope:'Existing/fresh bundled HTTP deployment on one origin; synthetic legacy save; short driving checks, not full races or desktop packages.',checks:[],errors:[]};
let server,browser,desktop;
const stopServer=async()=>{if(server){const previous=server;server=null;await new Promise(resolve=>{previous.closeAllConnections();previous.close(resolve);});}};
async function serve(root,port=0){
  server=await createWebServer({root,assetsRoot});
  await new Promise((resolve,reject)=>{server.once('error',reject);server.listen(port,'127.0.0.1',resolve);});
  return server.address().port;
}
try{
  const bundle=await bundleRuntime(temporary);
  await assertGameRuntime({root:temporary,assetsRoot});
  report.bundle=bundle.manifest;
  report.bundle.inputBytes=Object.values(bundle.metafile.inputs).reduce((sum,item)=>sum+item.bytes,0);
  const port=await serve(projectRoot),origin='http://127.0.0.1:'+port;
  browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,
    args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
  report.browser=browser.version();
  const context=await browser.newContext({viewport:{width:1024,height:768}});
  await context.addInitScript(values=>{
    if(!location.href.startsWith('http:'))return;
    if(!localStorage.getItem('rcsk.race-save.v1'))for(const [key,value]of Object.entries(values))
      localStorage.setItem(key,typeof value==='string'?value:JSON.stringify(value));
    const play=HTMLMediaElement.prototype.play;
    HTMLMediaElement.prototype.play=function(){this.playbackRate=16;return play.call(this);};
  },fixture.storage);
  const page=await context.newPage();
  let scripts=[];
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{
    if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);
    if(response.request().resourceType()==='script')scripts.push({path:new URL(response.url()).pathname,bytes:Number(response.headers()['content-length']||0)});
  });
  const readState=()=>page.evaluate(()=>({settings:rcsk.state.settings,selection:rcsk.state.selection,
    storage:Object.fromEntries(Object.entries(localStorage)),menu:document.querySelector('#screen').innerText}));
  await page.goto(origin+'/?skipIntro');await page.waitForSelector('[data-form=TFRMMAIN]');
  const before=await readState();report.existingMenuScripts=[...scripts];
  assert.ok(!scripts.some(item=>/world\.js|driving-view\.js|three\./.test(item.path)),'Menu must defer 3D');
  await page.goto('about:blank');await stopServer();await serve(temporary,port);scripts=[];
  await page.goto(origin+'/?skipIntro');await page.waitForSelector('[data-form=TFRMMAIN]');
  assert.deepEqual(await readState(),before);
  report.bundledMenuScripts=[...scripts];
  for(const requests of [report.existingMenuScripts,report.bundledMenuScripts]){
    assert.ok(requests.length>0&&requests.length<=bundle.manifest.files.filter(file=>file.endsWith('.js')).length);
    assert.ok(requests.every(item=>item.path.startsWith('/src/')),'Normal launch must load generated JavaScript only');
  }
  for(const route of ['/source/main.js','/source/race-save.js','/node_modules/three/build/three.module.js'])
    assert.equal((await fetch(origin+route)).status,403,route);
  report.checks.push('Same-origin bundled refresh preserves saved profiles, settings, selection and menu exactly; editable modules stay unavailable');
  await page.goto(origin+'/');
  await page.waitForFunction(()=>rcsk.state.page==='intro'&&document.querySelector('#movie').currentTime>0,null,{timeout:30000});
  await page.keyboard.press('Escape');await page.waitForSelector('[data-form=TFRMMAIN]');
  report.checks.push('Bundled original intro autoplays and skips to the menu');
  await page.locator('[data-native=btnAdventure]').click();await page.waitForSelector('[data-form=TFRMADVENTUREMAIN]');
  assert.equal(await page.locator('[data-element=lblPlayerName]').textContent(),'Zoë & RedCat');
  await page.locator('[data-native=btnRight]').click();
  await page.waitForFunction(()=>document.querySelector('[data-element=lblPlayerName]')?.textContent==='Laatste winnaar');
  await page.reload();await page.waitForSelector('[data-form=TFRMMAIN]');
  await page.locator('[data-native=btnAdventure]').click();await page.waitForSelector('[data-form=TFRMADVENTUREMAIN]');
  // Browsing changes only the form slot; the remembered profile is unchanged.
  assert.equal(await page.locator('[data-element=lblPlayerName]').textContent(),'Zoë & RedCat');
  assert.deepEqual(await page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1'))),fixture.storage['rcsk.race-save.v1']);
  report.checks.push('Bundled Adventure browsing reloads the unchanged v1 save');
  // Hold one authored track response to exercise Back while the actual viewer loads.
  let release,requested;
  const held=new Promise(resolve=>release=resolve);
  const entered=new Promise(resolve=>requested=resolve);
  await page.route('**/assets/tracks/etappe0.json',async route=>{requested();await held;await route.continue();});
  await page.goto(origin+'/?track=0');await page.waitForFunction(()=>rcsk.state.page==='loading');
  await entered;
  await page.keyboard.press('Escape');await page.waitForSelector('[data-form=TFRMMAIN]');release();
  await page.waitForFunction(()=>rcsk.viewer?.track?.id===0&&rcsk.viewer.active===false,null,{timeout:60000});
  assert.equal(await page.evaluate(()=>rcsk.state.page),'main');await page.unroute('**/assets/tracks/etappe0.json');
  report.checks.push('Canceled asynchronous viewer load remains in the menu with its renderer suspended');
  // Fresh pages avoid sharing an old runtime object with the next course.
  for(const track of (process.env.RCSK_BUNDLE_TRACKS||'0,1,2,3,4,5').split(',').map(Number)){
    assert.ok(Number.isInteger(track)&&track>=0&&track<6,'Track must be between 0 and 5');
    await page.goto(origin+'/?skipIntro');await page.waitForSelector('[data-form=TFRMMAIN]');
    await page.evaluate(track=>{
      localStorage.setItem('rcsk.selection.v1',JSON.stringify({country:track,character:track%4,difficulty:1,race:0}));
      // Keep the saved custom controls, but use their actual accelerate binding.
    },track);
    scripts=[];await page.goto(origin+'/?drive='+track);
    await page.waitForFunction(()=>rcsk.state.page==='driving'&&rcsk.viewer.clock.tick>2,null,{timeout:90000});
    const start=await page.evaluate(()=>({position:[...rcsk.viewer.motion.body.position],errors:rcsk.viewer.errors,
      glyphs:rcsk.viewer.renderStats.hud?.glyphs,triangles:rcsk.viewer.renderStats.world?.triangles,
      accelerate:rcsk.state.settings.bindings.accelerate}));
    assert.deepEqual(start.errors,[]);assert.ok(start.glyphs>0);assert.ok(start.triangles>1000);
    await page.keyboard.down('KeyW');await page.waitForTimeout(700);await page.keyboard.up('KeyW');
    const result=await page.evaluate(()=>({position:[...rcsk.viewer.motion.body.position],speed:rcsk.viewer.motion.body.forwardSpeed,
      glError:rcsk.viewer.renderer.getContext().getError()}));
    assert.ok(Math.hypot(...result.position.map((value,i)=>value-start.position[i]))>.1);assert.equal(result.glError,0);
    report.checks.push({name:'Bundled course loads and drives',track,scriptRequests:scripts.length,glyphs:start.glyphs,triangles:start.triangles});
  }
  await page.keyboard.press('p');await page.waitForFunction(()=>rcsk.state.mode==='paused');
  await page.keyboard.press('x');await page.waitForFunction(()=>rcsk.state.mode==='race');
  report.checks.push('Bundled native pause and resume remains functional');
  if(process.env.RCSK_BUNDLE_ELECTRON==='1'){
    // Exercise the real custom protocol with temporary bundled files, without
    // creating an installer/archive or touching the user's desktop profile.
    await cp(path.join(projectRoot,'electron'),path.join(temporary,'electron'),{recursive:true});
    await mkdir(path.join(temporary,'public'));await symlink(assetsRoot,path.join(temporary,'public/assets'),'dir');
    await mkdir(path.join(temporary,'desktop/icons'),{recursive:true});
    await cp(path.join(projectRoot,'desktop/icons/icon.png'),path.join(temporary,'desktop/icons/icon.png'));
    await writeFile(path.join(temporary,'package.json'),JSON.stringify({name:'redcat-superkarts-port',type:'module',main:'electron/main.mjs'}));
    const profile=path.join(temporary,'test-profile'),env={...process.env,RCSK_USER_DATA:profile};delete env.ELECTRON_RUN_AS_NODE;
    const launch=()=>electron.launch({args:[temporary,'--skip-intro','--ozone-platform=x11','--use-angle=swiftshader','--enable-unsafe-swiftshader'],env,timeout:60000});
    desktop=await launch();let window=await desktop.firstWindow();
    await window.waitForSelector('[data-form=TFRMMAIN]');
    const identity=await window.evaluate(()=>({origin:location.origin,require:typeof require,process:typeof process}));
    assert.deepEqual(identity,{origin:'rcsk://game',require:'undefined',process:'undefined'});
    assert.equal(await desktop.evaluate(({app})=>app.getPath('userData')),profile);
    await window.evaluate(values=>{for(const [key,value]of Object.entries(values))localStorage.setItem(key,typeof value==='string'?value:JSON.stringify(value));},fixture.storage);
    await desktop.close();desktop=null;
    desktop=await launch();window=await desktop.firstWindow();
    window.on('pageerror',error=>report.errors.push('Electron: '+error.message));
    window.on('console',message=>{if(message.type()==='error')report.errors.push('Electron: '+message.text());});
    await window.waitForSelector('[data-form=TFRMMAIN]');
    assert.deepEqual(await window.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1'))),fixture.storage['rcsk.race-save.v1']);
    assert.deepEqual(await window.evaluate(()=>rcsk.state.settings),fixture.storage['rcsk.settings.v1']);
    report.checks.push('Linux Electron bundled protocol keeps sandboxing and persisted v1 saves across relaunch');
    await window.goto('rcsk://game/?drive=2');
    await window.waitForFunction(()=>rcsk.state.page==='driving'&&rcsk.viewer.clock.tick>2,null,{timeout:90000});
    assert.ok(await window.evaluate(()=>rcsk.viewer.renderStats.hud.glyphs>0&&rcsk.viewer.renderStats.world.triangles>1000));
    report.checks.push('Linux Electron loads the bundled England race and HUD through rcsk://game');
    await desktop.close();desktop=null;
  }
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await desktop?.close();await browser?.close();await stopServer();await rm(temporary,{recursive:true,force:true});
  await writeFile(output+'/bundle-browser.json',JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors,existingMenuScripts:report.existingMenuScripts?.length,bundledMenuScripts:report.bundledMenuScripts?.length,modules:report.bundle?.sourceModules,javascriptBytes:report.bundle?.javascriptBytes,failure:report.failure},null,2));
}
