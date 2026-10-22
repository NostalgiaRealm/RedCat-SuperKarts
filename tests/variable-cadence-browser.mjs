import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,readdir,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';

const output=process.env.RCSK_CADENCE_OUTPUT||'evidence/variable-cadence/browser';
await mkdir(output,{recursive:true});
const sourceFiles=(await readdir('src',{recursive:true})).filter(file=>/\.(js|css)$/.test(file)).map(file=>'src/'+file);
const files=[...sourceFiles,'tests/variable-cadence-browser.mjs',
  'tests/native-timing-consumers.test.mjs','public/assets/config.json'];
const hashes=async()=>Object.fromEntries(await Promise.all(files.map(async file=>[file,
  createHash('sha256').update(await readFile(file)).digest('hex')])));
const report={status:'running',scope:'Source-only Chromium software-WebGL. Controlled cases use Playwright clock emulation for the real production timer loop, independently schedule display callbacks at declared nominal rates, and retain actual source update/render/clock observations. They do not set actor poses, race phases, timer values or physics outputs. The pause lap-notification is a disclosed controlled ID8 event. A separate unmodified real-time sample records host jitter. No full races, builds, packages, native game or existing user session are involved.',checks:[],errors:[],hashesBefore:await hashes()};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const url=(process.env.RCSK_URL||'http://127.0.0.1:4174')+'/?drive=0';
const instrument=async page=>page.evaluate(()=>{
  const v=rcsk.viewer;
  window.cadence={updates:[],renders:[],sceneCalls:0,hudCalls:0};
  const update=v.clock.update;
  v.clock.update=function(raw,now,tick){
    const row={at:performance.now(),rawDelta:raw,now,tick};
    const result=update.apply(this,arguments);
    Object.assign(row,{clock:this.snapshot(performance.now()),raceMs:v.race.elapsedMs,
      engineMs:v.simulation.engineMs,movement:v.simulation.movementActive,
      countdown:v.simulation.countdown?.snapshot()??null,camera:[...v.simulation.camera.position],
      lapText:v.hud.text.string_laptime_value,lapHold:{...v.hud.lapDisplay.state},
      position:[...v.motion.body.position]});
    cadence.updates.push(row);return result;
  };
  const tick=v.onTick;v.onTick=function(dt,now){
    cadence.filteredDelta=dt;return tick.apply(this,arguments);
  };
  // Capture the filter return associated with the same admitted callback.
  const capture=v.clock.update;v.clock.update=function(...args){
    const result=capture.apply(this,args);cadence.updates.at(-1).filteredDelta=cadence.filteredDelta;return result;
  };
  const render=v.render;v.render=function(time){
    const before=this.clock.tick;const result=render.apply(this,arguments);
    const clock=this.clock.snapshot(performance.now()),alpha=clock.alpha,p=this.previousCamera,c=this.currentCamera;
    const expected=p.position.toArray().map((value,i)=>
      (value+(c.position.getComponent(i)-value)*alpha)*(i===0&&this.track.mirrored?-1:1));
    cadence.renders.push({at:time,before,after:this.clock.tick,clock,
      camera:this.camera.position.toArray(),expectedCamera:expected});return result;
  };
  const scene=v.renderScene;v.renderScene=function(...args){cadence.sceneCalls++;return scene.apply(this,args);};
  const hud=v.hud.render;v.hud.render=function(...args){cadence.hudCalls++;return hud.apply(this,args);};
  window.cadenceRestore=()=>{
    v.clock.update=update;v.onTick=tick;v.render=render;v.renderScene=scene;v.hud.render=hud;
    window.cadenceRestore=null;
  };
});
const observePage=page=>{
  page.on('pageerror',error=>report.errors.push(error.stack||error.message));
  page.on('console',m=>{if(m.type()==='error')report.errors.push(m.text());});
  page.on('response',r=>{if(r.status()>=400)report.errors.push(`${r.status()} ${r.url()}`);});
};
const selectDefaults=()=>{
  localStorage.setItem('rcsk.selection.v1',JSON.stringify({character:1,difficulty:0,country:0,race:0}));
  localStorage.setItem('rcsk.settings.v1',JSON.stringify({touch:'off',renderScale:50}));
};
const scheduleDisplay=async(page,hz,duration)=>page.evaluate(({hz,duration})=>{
  const timestamps=[];
  for(let n=0;n<=Math.floor(duration*hz/1000);n++){
    const delay=Math.round(n*1000/hz);timestamps.push(delay);
    setTimeout(()=>{
      const callbacks=window.cadenceRaf.splice(0);
      for(const callback of callbacks)callback(performance.now());
    },delay);
  }
  return timestamps;
},{hz,duration});
const data=page=>page.evaluate(()=>({updates:cadence.updates,renders:cadence.renders,
  sceneCalls:cadence.sceneCalls,hudCalls:cadence.hudCalls,
  clock:rcsk.viewer.clock.snapshot(performance.now()),mode:rcsk.state.mode}));
try{
  const page=await browser.newPage({viewport:{width:640,height:480}});observePage(page);
  await page.clock.install({time:new Date('2026-10-21T12:00:00Z')});
  await page.addInitScript(selectDefaults);
  await page.addInitScript(()=>{
    // Only the host's display source is controlled here. Production setTimeout
    // scheduling and NativeUpdateLoop admission remain independent.
    window.cadenceRaf=[];window.requestAnimationFrame=callback=>{cadenceRaf.push(callback);return cadenceRaf.length;};
    window.cancelAnimationFrame=()=>{};
  });
  await page.goto(url);
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000,polling:100});
  await page.evaluate(()=>rcsk.viewer.suspend({notifyPause:false}));
  await page.clock.pauseAt(await page.evaluate(()=>Date.now()+25));
  const load=async(countdown=false)=>{
    await page.evaluate(async countdown=>{
      window.cadenceRestore?.();
      const v=rcsk.viewer;await v.load(0,{character:1,difficulty:0,raceMode:0,countdown});
      v.resume();
    },countdown);
    await instrument(page);
  };
  let firstTrace;
  for(const hz of [31,60,120,144,240]){
    await load();
    const schedule=await scheduleDisplay(page,hz,1000);
    await page.clock.runFor(1000);const row=await data(page);
    assert.equal(row.renders.length,schedule.length);
    assert.equal(row.sceneCalls,schedule.length);assert.equal(row.hudCalls,schedule.length);
    assert.equal(row.updates.length,40);
    assert.ok(row.updates.every(x=>Math.abs(x.rawDelta-.025)<1e-9));
    const trace=row.updates.map(x=>[x.rawDelta,x.filteredDelta,x.now]);
    if(firstTrace)assert.deepEqual(trace,firstTrace);else firstTrace=trace;
    assert.ok(row.renders.every(x=>x.before===x.after),'rendering cannot advance simulation');
    assert.ok(row.renders.some(x=>x.clock.alpha>0&&x.clock.alpha<1));
    for(const r of row.renders)for(let i=0;i<3;i++)assert.ok(Math.abs(r.camera[i]-r.expectedCamera[i])<1e-8);
    report.checks.push({case:`independent ${hz} Hz presentation with 25 ms timer wakes`,hz,schedule,...row});
  }
  const jitter=[];
  for(const milliseconds of [31,27,46,25]){
    const before=await data(page);await page.clock.fastForward(milliseconds);const after=await data(page);
    assert.equal(after.updates.length-before.updates.length,1);
    const sample=after.updates.at(-1);assert.ok(Math.abs(sample.rawDelta-milliseconds/1000)<1e-9);
    jitter.push(sample);
  }
  report.checks.push({case:'late timer wakes use measured 31/27/46/25 ms intervals once each',jitter});
  // An operating-system stall wakes each due timer once; the real update loop
  // must pass the entire measured interval through the native filter once.
  const beforeStall=await data(page);
  await page.clock.fastForward(500);const afterStall=await data(page);
  assert.equal(afterStall.updates.length-beforeStall.updates.length,1);
  const stalled=afterStall.updates.at(-1);
  assert.ok(Math.abs(stalled.rawDelta-.5)<1e-9);
  assert.ok(Math.abs(stalled.filteredDelta-.1)<1e-7);
  await page.clock.runFor(24);assert.equal((await data(page)).updates.length,afterStall.updates.length);
  await page.clock.runFor(1);const recovery=(await data(page)).updates.at(-1);
  assert.ok(Math.abs(recovery.rawDelta-.025)<1e-9);
  report.checks.push({case:'500 ms stall is one measured update, followed by normal scheduling without backlog',stalled,recovery});

  await page.evaluate(()=>{
    const v=rcsk.viewer;v.hud.notify(8,0,{lapCount:1,nowSeconds:v.simulation.engineMs/1000});
  });
  await page.keyboard.down('p');await page.keyboard.up('p');
  const paused=await data(page);assert.equal(paused.mode,'paused');
  await scheduleDisplay(page,60,3200);await page.clock.runFor(3200);
  const stillPaused=await data(page);
  assert.equal(stillPaused.updates.length,paused.updates.length);
  assert.equal(stillPaused.clock.simulationMs,paused.clock.simulationMs);
  assert.ok(stillPaused.clock.wallMs-paused.clock.wallMs>=3200);
  await page.keyboard.down('x');await page.keyboard.up('x');
  await scheduleDisplay(page,60,100);await page.clock.runFor(100);
  const resumed=await data(page),first=resumed.updates[paused.updates.length],second=resumed.updates[paused.updates.length+1];
  assert.equal(resumed.mode,'race');assert.ok(first&&second);
  assert.ok(first.rawDelta<.026,'pause duration must not become a physics delta');
  assert.equal(first.lapHold.holdStampSeconds,-1);
  assert.equal(first.lapText,paused.updates.at(-1).lapText);
  assert.ok(first.engineMs-paused.updates.at(-1).engineMs>=3200);
  assert.ok(first.raceMs-paused.updates.at(-1).raceMs<100);
  report.checks.push({case:'actual P release/resume preserves race time, absolute HUD hold and zero-backlog update',paused:paused.clock,stillPaused:stillPaused.clock,first,second});

  await load(true);
  await scheduleDisplay(page,60,12000);await page.clock.runFor(12000);
  const opening=await data(page),green=opening.updates.findIndex(x=>x.movement);
  assert.ok(green>0&&green<opening.updates.length-1);
  assert.ok(opening.updates.slice(0,green).every(x=>x.raceMs===0));
  assert.ok(opening.updates.at(-1).raceMs>0);
  assert.ok(opening.updates.some(x=>x.countdown?.soundIndex>0));
  assert.ok(new Set(opening.updates.slice(0,green).map(x=>x.camera.join(','))).size>2);
  report.checks.push({case:'authored camera/countdown reaches green with independent timers and HUD capture',greenIndex:green,green:opening.updates[green],beforeGreen:opening.updates[green-1],final:opening.updates.at(-1),updateCount:opening.updates.length,renderCount:opening.renders.length});
  await page.screenshot({path:`${output}/authored-countdown-after-green.png`});
  await page.close();

  const live=await browser.newPage({viewport:{width:640,height:480}});observePage(live);
  await live.addInitScript(selectDefaults);await live.goto(url);
  await live.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
  await instrument(live);await live.waitForTimeout(700);
  const realtime=await data(live);
  assert.ok(realtime.updates.length>0&&realtime.renders.length>0);
  assert.ok(realtime.renders.every(x=>x.before===x.after));
  assert.ok(realtime.updates.every(x=>x.rawDelta>=.024));
  report.checks.push({case:'unmodified real host timers and display callbacks',...realtime});
  await live.close();
  report.hashesAfter=await hashes();report.changedDuringRun=files.filter(file=>report.hashesBefore[file]!==report.hashesAfter[file]);
  assert.deepEqual(report.changedDuringRun,[]);assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=error.stack;throw error;}
finally{await writeFile(output+'/report.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(`Variable cadence browser: ${report.checks.length} groups passed`);
