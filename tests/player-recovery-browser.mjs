import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile,readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
const output=process.env.RCSK_RECOVERY_OUTPUT||'evidence/player-recovery/browser';
await mkdir(output,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={status:'running',scope:'Isolated source browser with software WebGL. Controlled clear road pose, then standard gamepad input; no forced enqueue or relocation. Real frame-loop recovery, original visuals and actual WebAudio source starts. Negative cases use accelerated 25ms DrivingView callbacks.',checks:[],errors:[]};
const sourceFiles=['src/race-simulation.js','src/simulation/player-stuck-recovery.js',
  'src/simulation/player-recovery-position.js','src/simulation/native-rescue.js',
  'src/simulation/native-bonus.js','src/driving-view.js',
  'tests/helpers/england-tyre-fixture.mjs','tests/player-recovery-integration.test.mjs',
  'tests/player-recovery-browser.mjs'];
const hashes=async()=>Object.fromEntries(await Promise.all(sourceFiles.map(async file=>[file,
  createHash('sha256').update(await readFile(file)).digest('hex')])));
report.sourceAtStart=await hashes();
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',e=>report.errors.push(e.stack||e.message));
  page.on('console',m=>{if(m.type()==='error')report.errors.push(m.text());});
  page.on('response',r=>{if(r.status()>=400)report.errors.push(`${r.status()} ${r.url()}`);});
  await page.addInitScript(()=>{
    localStorage.setItem('rcsk.selection.v1',JSON.stringify({character:1,difficulty:0,country:2,race:0}));
    localStorage.setItem('rcsk.settings.v1',JSON.stringify({deadzone:0}));
    window.recoveryPad={id:'Isolated regression gamepad',connected:true,mapping:'standard',
      axes:[0,0],buttons:Array.from({length:16},()=>({value:0,pressed:false,touched:false}))};
    navigator.getGamepads=()=>[window.recoveryPad];
  });
  const load=async()=>{
    await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4174')+'/?drive=2');
    await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
    await page.evaluate(()=>rcsk.viewer.clock.pause());
  };
  await load();
  const negatives=await page.evaluate(()=>{
    const view=rcsk.viewer,sim=view.simulation,b=sim.motion.body;
    let now=view.clock.tick*25;
    for(let i=0;i<360;i++)view.onTick(.025,now+=25);
    const idle={recoveries:sim.playerRecovery.recoveries,attemptSeconds:sim.playerRecovery.attemptSeconds};
    const reverseStart=[...b.position];
    view.input.set('key:ArrowDown','brake');
    for(let i=0;i<360;i++)view.onTick(.025,now+=25);
    view.input.clear();
    const reverse={recoveries:sim.playerRecovery.recoveries,
      travel:Math.hypot(b.x-reverseStart[0],b.z-reverseStart[2]),speed:b.forwardSpeed};
    view.setFreeFlight(true);view.input.set('key:ArrowUp','accelerate');
    for(let i=0;i<360;i++)view.onTick(.025,now+=25);
    const flight={active:sim.freeFlightActive,recoveries:sim.playerRecovery.recoveries,
      attemptSeconds:sim.playerRecovery.attemptSeconds};
    return {idle,reverse,flight};
  });
  assert.equal(negatives.idle.recoveries,0);assert.equal(negatives.idle.attemptSeconds,0);
  assert.equal(negatives.reverse.recoveries,0);assert.ok(negatives.reverse.travel>100);
  assert.equal(negatives.flight.active,true);assert.equal(negatives.flight.recoveries,0);
  assert.equal(negatives.flight.attemptSeconds,0);
  report.checks.push({case:'nine seconds each of idle, moving reverse and free flight do not auto-rescue',...negatives});
  await load();
  const initial=await page.evaluate(async()=>{
    const view=rcsk.viewer,sim=view.simulation,b=view.motion.body;
    const {nativeRotationMatrix}=await import('/src/simulation/native-transform.js');
    const {sampleNativeTrack}=await import('/src/simulation/native-track.js');
    const {rescuePlacementClear}=await import('/src/simulation/rescue-safety.js');
    b.position.splice(0,3,-7027,0,6317);
    Object.assign(b,{yaw:512,pitch:0,roll:0,sector:124,previousSector:124,waypoint:589,
      forwardSpeed:0,lateralSpeed:0,verticalSpeed:0,yawRate:0,pitchRate:0,rollRate:0});
    b.matrix=nativeRotationMatrix([0,b.yaw,0]);view.motion.groundInitialized=false;
    sim.occupancy.remove(b);sim.occupancy.insert(b);sim.race.previousSector=b.sector;
    sim.playerRecovery.reset();sim.playerRecovery.anchors=[];
    sim.playerCamera.reset(b);sim.camera=sim.playerCamera;view.nativeCamera=sim.camera;
    sim.cameraSector=b.sector;sim.cameraSectors.set(sim.playerCamera,b.sector);
    await view.audio.unlock();
    window.recoveryProbe={frames:[],sounds:[],contacts:[],finishedAt:null,startTick:view.clock.tick};
    const contact=sim.onPlayerCollision;
    sim.onPlayerCollision=e=>{contact(e);const other=e.firstBody===b?e.secondBody:e.firstBody;
      recoveryProbe.contacts.push({tick:view.clock.tick,placement:other?.placementIndex,mesh:other?.mesh});};
    const bank=view.audio.voices.banks[sim.voices.voiceId(b.id)];
    const names=Object.fromEntries(['DISAPP','REAPP'].map(sample=>[bank.find(x=>x.sample===sample).event.toLowerCase(),sample]));
    const execute=view.audio.execute.bind(view.audio);
    view.audio.execute=commands=>{const result=execute(commands);for(const c of commands){
      const sample=names[c.event?.toLowerCase()];if(c.op==='play'&&sample)
        recoveryProbe.sounds.push({sample,event:c.event,playing:view.audio.isPlaying(c.event),context:view.audio.context.state});
    }return result;};
    const tick=view.onTick.bind(view);
    view.onTick=(...args)=>{const e=sim.rescue.get(b),result=tick(...args),entry=sim.rescue.get(b);
      if(entry?.softLock)recoveryProbe.frames.push({tick:view.clock.tick,frame:entry.frame,
        scale:entry.scale,shrinking:entry.shrinking,position:[...b.position],relocated:entry.relocated});
      if(e?.softLock&&e.finished&&!recoveryProbe.finishedAt){recoveryProbe.finishedAt=view.clock.tick;
        recoveryPad.axes[0]=0;recoveryProbe.finishedPosition=[...b.position];}
      return result;};
    view.updatePresentation(1);view.renderScene();view.hud.render();
    return {position:[...b.position],ground:sampleNativeTrack(sim.world,b.sector,...b.position).kind,
      clear:rescuePlacementClear(view.motion.collision,b,b),selection:rcsk.state.selection,
      tyre:sim.physicalBodies.find(p=>p.placementIndex===230).mesh};
  });
  assert.equal(initial.ground,'road');assert.equal(initial.clear,true);assert.equal(initial.selection.character,1);
  report.checks.push({case:'clear England road start beside the original solid tyre wall',...initial});
  await page.evaluate(()=>{recoveryPad.axes[0]=.3;recoveryPad.buttons[7].value=1;rcsk.viewer.clock.resume();});
  await page.waitForFunction(()=>rcsk.viewer.simulation.playerRecovery.attemptSeconds>5,null,{timeout:30000});
  await page.screenshot({path:output+'/tyre-blocked.png'});
  await page.waitForFunction(()=>{
    const v=rcsk.viewer,e=v.simulation.rescue.get(v.motion.body);
    if(e?.softLock&&e.shrinking&&e.frame>=11){v.clock.pause();return true;}return false;
  },null,{timeout:20000,polling:'raf'});
  const shrinking=await page.evaluate(()=>{
    const v=rcsk.viewer,e=v.simulation.rescue.get(v.motion.body);
    v.updatePresentation(1);v.renderScene();v.hud.render();
    return {frame:e.frame,scale:e.scale,environment:e.environment,
      rings:v.rescueVisuals.meshes.filter(m=>m.visible).length,recoveries:v.simulation.playerRecovery.recoveries};
  });
  assert.ok(shrinking.scale<1);assert.ok(shrinking.rings>0);assert.equal(shrinking.recoveries,1);
  await page.screenshot({path:output+'/tyre-shrinking.png'});
  report.checks.push({case:'automatic detection uses the original shrinking kart and rescue rings',...shrinking});
  await page.evaluate(()=>rcsk.viewer.clock.resume());
  await page.waitForFunction(()=>recoveryProbe.finishedAt&&rcsk.viewer.clock.tick>=recoveryProbe.finishedAt+80,null,{timeout:15000});
  await page.waitForFunction(()=>recoveryProbe.sounds.some(s=>s.sample==='REAPP'),null,{timeout:10000});
  const final=await page.evaluate(async()=>{
    const v=rcsk.viewer,sim=v.simulation,b=v.motion.body;v.clock.pause();
    v.updatePresentation(1);v.renderScene();v.hud.render();
    const {isSafePlayerRecoveryPose}=await import('/src/simulation/player-recovery-position.js');
    return {...recoveryProbe,recoveries:sim.playerRecovery.recoveries,lastRecovery:sim.playerRecovery.lastRecovery,
      position:[...b.position],speed:b.forwardSpeed,activeRescue:!!sim.rescue.get(b),
      travelledAfterRecovery:Math.hypot(b.x-recoveryProbe.finishedPosition[0],b.z-recoveryProbe.finishedPosition[2]),
      destinationClear:isSafePlayerRecoveryPose({track:v.track,world:sim.world,motion:v.motion},sim.playerRecovery.lastRecovery.destination),
      lapCount:sim.race.lapCount,stars:sim.pickups.stars,errors:v.errors};
  });
  assert.ok(final.contacts.some(c=>c.placement===230&&c.mesh==='banden00.d3d'));
  assert.equal(final.recoveries,1);assert.equal(final.activeRescue,false);
  assert.ok(final.travelledAfterRecovery>100);assert.ok(final.speed>5);assert.equal(final.destinationClear,true);
  assert.deepEqual(final.sounds.map(s=>s.sample),['DISAPP','REAPP']);
  assert.ok(final.sounds.every(s=>s.playing&&s.context==='running'));
  assert.equal(final.lapCount,0);assert.equal(final.stars,0);assert.deepEqual(final.errors,[]);
  await page.screenshot({path:output+'/tyre-recovered.png'});
  report.checks.push({case:'both original voice sources really start and normal driving resumes without a lap/star award',...final});
  report.sourceAtEnd=await hashes();
  report.changedDuringRun=sourceFiles.filter(f=>report.sourceAtEnd[f]!==report.sourceAtStart[f]);
  assert.deepEqual(report.errors,[]);assert.deepEqual(report.changedDuringRun,[]);report.status='passed';
}catch(e){report.status='failed';report.failure=e.stack;throw e;}
finally{await writeFile(output+'/report.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(`Player recovery browser: ${report.checks.length} checks passed`);
