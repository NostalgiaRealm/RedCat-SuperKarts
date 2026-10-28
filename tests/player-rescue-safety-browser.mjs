import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const directory=process.env.RCSK_RESCUE_OUTPUT||'evidence/race-completion/rescue-browser';
const output=directory+'/player-rescue-safety-browser';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),checks:[],errors:[],scope:
  'Controlled Italy danger-zone starting pose and a stationary finished NPC occupying the authored return. '+
  'This synthetic blocker is distinct from the retained race trace, whose NPC was in recovery mode10. '+
  'Normal browser clock, original rescue animation/audio and the authorized player-safety controller run after setup. '+
  'No forced rescue enqueue, destination override or timer advance.'};
await mkdir(directory,{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=5');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  const initial=await page.evaluate(async()=>{
    const view=rcsk.viewer,sim=view.simulation,body=view.motion.body,track=view.track;
    const {nativeRescueNearestSector,nativeRescueHeading,nativeRescueDestination}=await import('/source/simulation/native-rescue.js');
    const {sampleNativeTrack}=await import('/source/simulation/native-track.js');
    const {nativeRotationMatrix}=await import('/source/simulation/native-transform.js');
    const {rescuePlacementClear}=await import('/source/simulation/rescue-safety.js');
    view.clock.pause();
    function place(target,position){
      sim.occupancy.remove(target);
      target.position.splice(0,3,...position);
      const ground=sampleNativeTrack(sim.world,nativeRescueNearestSector(track,position),...position);
      target.position[1]=ground.height;
      target.sector=target.previousSector=ground.sector;
      target.yaw=nativeRescueHeading(sim.world,ground.sector);
      target.matrix=nativeRotationMatrix([0,target.yaw,0]);
      for(const key of ['lateralSpeed','verticalSpeed','forwardSpeed','yawRate','rollRate','pitchRate'])
        target[key]=0;
      sim.occupancy.insert(target);
      return ground;
    }
    const ground=place(body,[-6008.787109375,0,943.1793823242188]);
    const blocker=sim.opponents[0];
    place(blocker.body,track.drive[514].position);
    Object.assign(blocker.state,{mode:9,finished:true,disabled:true,blockRecovery:false,
      previousSector:blocker.body.sector,sectorTime:0});
    sim.race.previousSector=body.sector;
    sim.playerCamera.reset(body);sim.camera=sim.playerCamera;
    sim.cameraSector=body.sector;sim.cameraSectors.set(sim.playerCamera,body.sector);
    window.safetyTrace={frames:[],sounds:[],blockerStart:[...blocker.body.position],relocation:null};
    const step=sim.rescue.step.bind(sim.rescue);
    sim.rescue.step=dt=>{
      const result=step(dt),entry=sim.rescue.get(body);
      if(entry){
        safetyTrace.frames.push({tick:view.clock.tick,dt,frame:entry.frame,shrinking:entry.shrinking,
          scale:entry.scale,blocked:entry.safetyBlocked??false,waitSeconds:entry.safetyWaitSeconds??0,
          fallback:entry.safetyFallback??false,relocated:entry.relocated,finished:entry.finished,
          destination:entry.destination,position:[...body.position]});
        if(entry.relocated)safetyTrace.relocation={
          position:[...body.position],destination:entry.destination,
          placementClear:rescuePlacementClear(view.motion.collision,body,entry.destination),
          ground:sampleNativeTrack(sim.world,body.sector,...body.position).kind,
          blockerPosition:[...blocker.body.position],
        };
      }
      return result;
    };
    const bank=view.audio.voices.banks[sim.voices.voiceId(body.id)];
    const samples=Object.fromEntries(['DISAPP','REAPP'].map(sample=>[
      bank.find(item=>item.sample===sample).event.toLowerCase(),sample]));
    const execute=view.audio.execute.bind(view.audio);
    view.audio.execute=commands=>{
      const result=execute(commands);
      for(const command of commands){
        const sample=samples[command.event?.toLowerCase()];
        if(command.op==='play'&&sample)safetyTrace.sounds.push({
          sample,playing:view.audio.isPlaying(command.event),context:view.audio.context.state});
      }
      return result;
    };
    return {position:[...body.position],waypoint:body.waypoint,marker:track.drive[body.waypoint].unknown[1],
      ground:ground.kind,blockerPosition:[...blocker.body.position],blockerMode:blocker.state.mode,
      nativeDestination:nativeRescueDestination(track,sim.world,body,{
        environment:true,occupants:sim.actors.map(actor=>actor.body)}),
      safetyEnabled:sim.rescue.playerSafety?.body===body,rescueCount:sim.rescue.entries.length};
  });
  assert.equal(initial.marker,50);assert.equal(initial.blockerMode,9);
  assert.deepEqual(initial.nativeDestination,{blocked:true});
  assert.equal(initial.safetyEnabled,true);assert.equal(initial.rescueCount,0);
  report.checks.push({case:'controlled occupied original return, player safeguard enabled',...initial});
  await page.evaluate(()=>rcsk.viewer.updateLoop.start());
  await page.waitForFunction(()=>safetyTrace.frames.some(frame=>frame.blocked&&frame.waitSeconds>=.75),
    null,{timeout:20000});
  const waiting=await page.evaluate(()=>{
    const view=rcsk.viewer;view.clock.pause();view.updatePresentation(1);view.renderer.render(view.scene,view.camera);
    const entry=view.simulation.rescue.get(view.motion.body);
    return {frame:entry.frame,scale:entry.scale,waitSeconds:entry.safetyWaitSeconds,
      relocated:safetyTrace.frames.some(frame=>frame.relocated),
      rings:view.rescueVisuals.meshes.filter(mesh=>mesh.visible).length};
  });
  assert.ok(waiting.waitSeconds<2);assert.equal(waiting.relocated,false);
  assert.ok(waiting.scale<=Math.fround(.15));assert.ok(waiting.rings>0);
  report.checks.push({case:'original blocked shrinking state remains during safety delay',...waiting});
  await page.screenshot({path:output+'-waiting.png'});
  await page.evaluate(()=>rcsk.viewer.updateLoop.start());
  await page.waitForFunction(()=>safetyTrace.frames.some(frame=>frame.finished),null,{timeout:20000});
  await page.waitForFunction(()=>safetyTrace.sounds.some(sound=>sound.sample==='REAPP'),null,{timeout:10000});
  const recovered=await page.evaluate(()=>{
    const view=rcsk.viewer;view.clock.pause();view.updatePresentation(1);view.renderer.render(view.scene,view.camera);
    return {...safetyTrace,rescueRemaining:Boolean(view.simulation.rescue.get(view.motion.body)),
      position:[...view.motion.body.position],sector:view.motion.body.sector,
      visible:view.playerVisual.group.visible,geometry:view.playerVisual.group.matrix.elements,
      camera:{position:view.nativeCamera.position,target:view.nativeCamera.target,sector:view.simulation.cameraSector},
      blockerPosition:[...view.simulation.opponents[0].body.position],errors:view.errors};
  });
  const relocated=recovered.frames.find(frame=>frame.relocated);
  assert.ok(relocated);assert.ok(relocated.waitSeconds>=2);
  assert.equal(relocated.destination.safetyFallback,true);assert.notEqual(relocated.destination.waypoint,514);
  assert.equal(recovered.relocation.placementClear,true);assert.equal(recovered.relocation.ground,'road');
  assert.equal(recovered.rescueRemaining,false);assert.equal(recovered.visible,true);
  assert.ok(recovered.geometry.every(Number.isFinite));
  assert.ok([...recovered.camera.position,...recovered.camera.target].every(Number.isFinite));
  for(const axis of [0,2])assert.equal(recovered.blockerPosition[axis],recovered.blockerStart[axis]);
  assert.deepEqual(recovered.sounds.map(sound=>sound.sample),['DISAPP','REAPP']);
  assert.ok(recovered.sounds.every(sound=>sound.playing&&sound.context==='running'));
  assert.deepEqual(recovered.errors,[]);
  report.checks.push({case:'delayed free-road fallback grows and finishes with both actual original sounds',...recovered});
  await page.screenshot({path:output+'-recovered.png'});
  await page.keyboard.down('ArrowUp');
  await page.evaluate(()=>rcsk.viewer.updateLoop.start());
  await page.waitForFunction(position=>Math.hypot(
    rcsk.viewer.motion.body.x-position[0],rcsk.viewer.motion.body.z-position[2])>60,
  recovered.position,{timeout:10000});
  await page.keyboard.up('ArrowUp');
  const driven=await page.evaluate(()=>{
    const view=rcsk.viewer;view.clock.pause();
    return {position:[...view.motion.body.position],forwardSpeed:view.motion.body.forwardSpeed,
      rescueRemaining:Boolean(view.simulation.rescue.get(view.motion.body)),errors:view.errors};
  });
  assert.equal(driven.rescueRemaining,false);assert.deepEqual(driven.errors,[]);
  report.checks.push({case:'ordinary ArrowUp input drives onward after recovery',...driven});
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile(output+'.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors}));
}
