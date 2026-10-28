import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),checks:[],errors:[]};
const output=process.env.RCSK_RESCUE_OUTPUT||'evidence/regressions';
await mkdir(output,{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  const initial=await page.evaluate(async()=>{
    const view=rcsk.viewer,sim=view.simulation,body=view.motion.body,track=view.track;
    const {nativeRescueNearestSector}=await import('/source/simulation/native-rescue.js');
    const {sampleNativeTrack}=await import('/source/simulation/native-track.js');
    const {nativeRotationMatrix}=await import('/source/simulation/native-transform.js');
    view.clock.pause();
    // Reproduction fixture starts on the raised bridge, pointed toward its
    // unguarded edge. Only normal keyboard acceleration moves it after setup.
    body.position.splice(0,3,...track.drive[452].position);
    const ground=sampleNativeTrack(sim.world,nativeRescueNearestSector(track,body.position),...body.position);
    body.position[1]=ground.height;body.sector=body.previousSector=ground.sector;
    body.yaw=Math.fround((Math.atan2(1,-.6)-Math.PI/2)*4096/(Math.PI*2));
    body.matrix=nativeRotationMatrix([0,body.yaw,0]);
    body.lateralSpeed=body.verticalSpeed=body.forwardSpeed=0;
    sim.occupancy.remove(body);sim.occupancy.insert(body);
    sim.race.previousSector=body.sector;
    sim.playerCamera.reset(body);sim.camera=sim.playerCamera;
    sim.cameraSector=body.sector;sim.cameraSectors.set(sim.playerCamera,body.sector);
    window.rescueTrace={frames:[],sounds:[],relocationRender:null};
    const tick=view.onTick.bind(view);
    view.onTick=(...args)=>{
      tick(...args);
      const entry=sim.rescue.get(body);
      if(entry?.relocated){
        view.updatePresentation(1);
        const shadow=view.shadows[0];
        rescueTrace.relocationRender={logicalPosition:[...body.position],
          matrixPosition:[...entry.renderPosition],kart:view.playerVisual.group.matrix.elements.slice(12,15),
          sky:view.sky.position.toArray(),shadow:shadow.current.position,
          shadowPlane:sim.world.sectors[body.sector].fallback};
      }
    };
    const color=view.playerVisual.captureColor.bind(view.playerVisual);
    view.playerVisual.captureColor=(...args)=>{
      const entry=sim.rescue.get(body);
      if(entry?.relocated)rescueTrace.colorSamplePosition=[...body.position];
      return color(...args);
    };
    const step=sim.rescue.step.bind(sim.rescue);
    sim.rescue.step=dt=>{
      const result=step(dt),entry=sim.rescue.get(body);
      if(entry)rescueTrace.frames.push({frame:entry.frame,shrinking:entry.shrinking,
        scale:entry.scale,environment:entry.environment,relocated:entry.relocated,
        destination:entry.destination,finished:entry.finished,tick:view.clock.tick,position:[...body.position]});
      return result;
    };
    const bank=view.audio.voices.banks[sim.voices.voiceId(body.id)];
    const events=Object.fromEntries(['DISAPP','REAPP'].map(sample=>[bank.find(item=>item.sample===sample).event.toLowerCase(),sample]));
    const execute=view.audio.execute.bind(view.audio);
    view.audio.execute=commands=>{
      const result=execute(commands);
      for(const command of commands){
        const sample=events[command.event?.toLowerCase()];
        if(command.op==='play'&&sample)rescueTrace.sounds.push({sample,event:command.event,
          playing:view.audio.isPlaying(command.event),context:view.audio.context.state});
      }
      return result;
    };
    return {position:[...body.position],waypoint:body.waypoint,ground:ground.kind,height:ground.height,
      recoveries:sim.rescue.entries.length};
  });
  assert.equal(initial.ground,'road');assert.ok(initial.height>50);assert.equal(initial.recoveries,0);
  report.checks.push({case:'controlled start pose on original Nederland bridge',...initial});
  await page.keyboard.down('ArrowUp');
  await page.evaluate(()=>rcsk.viewer.updateLoop.start());
  await page.waitForFunction(()=>{
    const view=rcsk.viewer,entry=view.simulation.rescue.get(view.motion.body);
    if(entry?.shrinking&&entry.frame>=12){view.clock.pause();return true;}
    return false;
  },null,{timeout:30000,polling:'raf'});
  await page.keyboard.up('ArrowUp');
  const shrinking=await page.evaluate(()=>{
    const view=rcsk.viewer,entry=view.simulation.rescue.get(view.motion.body);
    view.updatePresentation(1);view.renderer.render(view.scene,view.camera);
    return {scale:entry.scale,frame:entry.frame,environment:entry.environment,waypoint:view.motion.body.waypoint,
      visibleRings:view.rescueVisuals.meshes.filter(mesh=>mesh.visible).length,
      matrixMatches:view.playerVisual.current.matrix.elements.every((value,i)=>Math.abs(value-view.playerVisual.group.matrix.elements[i])<1e-6)};
  });
  assert.equal(shrinking.environment,true);assert.ok(shrinking.scale<1);
  assert.ok(shrinking.visibleRings>0);assert.equal(shrinking.matrixMatches,true);
  report.checks.push({case:'normal throttle drives off bridge and automatically triggers shrinking/rings',...shrinking});
  await page.screenshot({path:output+'/moat-shrinking.png'});
  await page.evaluate(()=>rcsk.viewer.updateLoop.start());
  await page.waitForFunction(()=>rescueTrace.frames.some(frame=>frame.finished),null,{timeout:15000});
  await page.waitForFunction(()=>rescueTrace.sounds.some(sound=>sound.sample==='REAPP'),null,{timeout:15000});
  await page.waitForFunction(()=>rcsk.viewer.clock.tick-rescueTrace.frames.at(-1).tick>=40);
  const recovered=await page.evaluate(()=>{
    const view=rcsk.viewer;
    view.clock.pause();view.updatePresentation(1);view.renderer.render(view.scene,view.camera);
    return {...rescueTrace,currentRescue:Boolean(view.simulation.rescue.get(view.motion.body)),
      camera:{position:view.nativeCamera.position,target:view.nativeCamera.target,sector:view.simulation.cameraSector},
      player:{position:[...view.motion.body.position],sector:view.motion.body.sector,
        visible:view.playerVisual.group.visible,matrix:view.motion.body.matrix},
      visibleSectors:view.visibleSectorRanges,errors:view.errors};
  });
  assert.equal(recovered.frames.length,40);
  const relocated=recovered.frames.find(frame=>frame.relocated);
  assert.equal(relocated.destination.waypoint,441);
  assert.equal(relocated.position[1],20);
  const render=recovered.relocationRender;
  assert.ok(render);
  assert.deepEqual(render.kart,render.matrixPosition);
  assert.deepEqual(render.sky,render.logicalPosition);
  assert.notDeepEqual(render.kart,render.logicalPosition);
  assert.deepEqual(recovered.colorSamplePosition,render.logicalPosition);
  const {getNativeKartShadowPose}=await import('../source/kart-shadow.js');
  assert.deepEqual(render.shadow,getNativeKartShadowPose({
    position:render.logicalPosition,matrixTranslation:render.matrixPosition,matrix:[],
  },render.shadowPlane).position);
  assert.deepEqual(recovered.sounds.map(sound=>sound.sample),['DISAPP','REAPP']);
  assert.ok(recovered.sounds.every(sound=>sound.playing&&sound.context==='running'));
  assert.equal(recovered.currentRescue,false);assert.deepEqual(recovered.errors,[]);
  assert.ok(Math.abs(recovered.camera.sector-recovered.player.sector)<4);
  report.checks.push({case:'authored return point,40 animation ticks and both actual original WebAudio sources',...recovered});
  await page.screenshot({path:output+'/moat-recovered.png'});
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  report.scope='Controlled pose on bridge followed by real ArrowUp input and normal browser race loop. No forced rescue queue or relocation. Original rules verified separately by x86 instruction fixtures; native race rendering unavailable.';
  await writeFile(output+'/environment-rescue-browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors}));
}
