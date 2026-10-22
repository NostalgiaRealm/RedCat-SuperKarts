import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),checks:[],errors:[],
  scope:'Actual browser keyboard events feed25ms DrivingView callbacks. Free-flight is an explicit cheat, not native behavior; original race services remain frozen while it is active.'};
await mkdir('evidence/free-flight',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=3');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  const initial=await page.evaluate(async()=>{
    const view=rcsk.viewer;view.clock.pause();
    window.flightProbe={now:view.clock.tick*25};
    await view.audio.unlock();await view.music.resume();
    view.audio.execute([{event:view.audio.engine.spec.start.event,op:'stop'}]);
    view.audio.updateEngine({gear:2,rpm:5000});
    view.audio.updateSkid({slipMagnitude:8,playerContact:true,soundEnabled:true,controllerEnabled:true});
    const audioBefore={context:view.audio.context.state,skid:view.audio.isPlaying('SLIP'),
      engines:view.audio.engine.spec.layers.filter(layer=>view.audio.isPlaying(layer.sound.event)).length};
    view.setFreeFlight(true);view.onTick(.025,flightProbe.now+=25);
    flightProbe.frozen=JSON.stringify({race:view.race.snapshot(),stars:view.pickups.stars,
      opponents:view.opponents.map(actor=>actor.body.position),random:view.random.state});
    flightProbe.anchor=structuredClone(view.simulation.flightReturnPose);
    return {position:[...view.motion.body.position],active:view.simulation.freeFlightActive,audioBefore};
  });
  assert.equal(initial.active,true);
  assert.equal(initial.audioBefore.context,'running');assert.equal(initial.audioBefore.skid,true);
  assert.ok(initial.audioBefore.engines>0);
  await page.waitForFunction(()=>rcsk.viewer.audio.context.state==='suspended');
  await page.evaluate(()=>rcsk.viewer.resumeAudio());
  const flightAudio=await page.evaluate(()=>({context:rcsk.viewer.audio.context.state,musicPaused:rcsk.viewer.music.audio.paused}));
  assert.equal(flightAudio.context,'suspended');assert.equal(flightAudio.musicPaused,false);
  report.checks.push('entering flight suspends active engine/skid loops, preserves music and ignores movement unlock requests');
  const step=ticks=>page.evaluate(ticks=>{
    const view=rcsk.viewer;
    for(let tick=0;tick<ticks;tick++)view.onTick(.025,flightProbe.now+=25);
    view.updatePresentation(1);view.renderScene();view.hud.render();
    return {position:[...view.motion.body.position],camera:view.camera.position.toArray(),
      target:view.currentCamera.target.toArray(),input:view.input.snapshot(),
      unchanged:flightProbe.frozen===JSON.stringify({race:view.race.snapshot(),stars:view.pickups.stars,
        opponents:view.opponents.map(actor=>actor.body.position),random:view.random.state}),
      ranges:view.visibleSectorRanges,sectorCount:view.track.sectorCount,
      meshVisible:view.playerVisual.group.visible,groups:view.roadMesh.geometry.groups.length};
  },ticks);
  await page.keyboard.down('ArrowUp');await page.keyboard.down('c');
  const below=await step(120);
  await page.keyboard.up('c');await page.keyboard.down('Space');
  const above=await step(180);
  await page.keyboard.up('Space');
  assert.ok(below.position[1]<initial.position[1]-1100);
  assert.ok(above.position[1]>initial.position[1]+500);
  assert.ok(Math.hypot(above.position[0]-initial.position[0],above.position[2]-initial.position[2])>4500);
  assert.ok(below.unchanged&&above.unchanged);
  assert.ok(above.camera.every(Number.isFinite)&&above.target.every(Number.isFinite));
  assert.deepEqual(above.ranges,[[0,above.sectorCount-1]]);
  assert.ok(above.meshVisible&&above.groups>100);
  report.checks.push('keyboard forward/C/Space crosses ground freely; whole race frozen; camera and entire scenery remain visible');
  await page.screenshot({path:'evidence/free-flight/airborne.png'});
  await page.keyboard.down('Space');
  await page.evaluate(()=>window.dispatchEvent(new Event('blur')));
  const paused=await page.evaluate(()=>({input:rcsk.viewer.input.snapshot(),active:rcsk.viewer.active,mode:rcsk.state.mode}));
  assert.equal(paused.mode,'paused');assert.equal(paused.active,false);
  assert.equal(paused.input.throttle,0);assert.equal(paused.input.lift,0);
  await page.keyboard.up('Space');await page.keyboard.up('ArrowUp');
  report.checks.push('blur pauses flight and clears every held movement/lift input');
  // Simulated clock callbacks above were deliberately accelerated; restore the
  // browser clock tick to that same observed time before exercising resume.
  const restored=await page.evaluate(()=>{
    const view=rcsk.viewer;view.clock.tick=flightProbe.now/25;
    view.setFreeFlight(false);
    return {position:[...view.motion.body.position],anchor:flightProbe.anchor.position,
      input:view.input.snapshot(),active:view.simulation.freeFlightActive,
      skid:view.audio.isPlaying('SLIP'),audio:view.audio.context.state,
      speeds:['forwardSpeed','verticalSpeed','lateralSpeed','yawRate','pitchRate','rollRate'].map(k=>view.motion.body[k])};
  });
  assert.equal(restored.active,false);assert.deepEqual(restored.position,restored.anchor);
  assert.ok(restored.speeds.every(value=>value===0));assert.equal(restored.input.throttle,0);
  assert.equal(restored.skid,false);assert.equal(restored.audio,'suspended');
  report.checks.push('disabling during pause returns to safe saved road pose with zero velocity and neutral input');
  report.initial=initial;report.below=below;report.above=above;report.restored=restored;
  assert.deepEqual(report.errors,[]);
  report.status='passed';
}catch(error){report.status='failed';report.failure=error.stack;throw error;}
finally{await writeFile('evidence/free-flight/browser.json',JSON.stringify(report,null,2));await browser.close();}
console.log(`Free flight browser: ${report.checks.length} checks passed`);
