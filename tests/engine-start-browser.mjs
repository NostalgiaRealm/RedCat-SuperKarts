import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader',
    '--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),checks:[],errors:[]};
await mkdir('evidence/audio',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  page.on('requestfailed',request=>report.errors.push(`${request.failure()?.errorText} ${request.url()}`));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');
  // Observe the actual WebAudio service. No camera, countdown or sound state is
  // changed; the real menu flow and normal browser animation loop run below.
  await page.evaluate(async()=>{
    const {NativeRaceAudio}=await import('/src/native-race-audio.js');
    const execute=NativeRaceAudio.prototype.execute;
    window.engineStartTrace=[];
    NativeRaceAudio.prototype.execute=function(commands){
      const result=execute.call(this,commands);
      for(const command of commands){
        if(command.op!=='play'||command.event!==this.engine.spec.start.event)continue;
        const sim=window.rcsk.viewer?.simulation;
        window.engineStartTrace.push({event:command.event,loop:command.loop,
          panDone:sim?.startCamera?.done,countdownStarted:sim?.countdownStarted,
          movementActive:sim?.movementActive,phase:sim?.race.phase,
          engineActive:this.engine.active,playing:this.isPlaying(command.event),
          contextState:this.context.state,sourceStartTime:this.context.currentTime});
      }
      return result;
    };
  });
  await page.locator('[data-native=btnQuickRace]').click();
  await page.waitForSelector('[data-form=TFRMSELECTCHAR]');
  await page.locator('[data-native=btnOk]').click();
  await page.waitForSelector('[data-form=TFRMSELECTCOUNTRY]');
  await page.locator('[data-native=btnOk]').click();
  await page.waitForSelector('[data-form=TFRMCONTROLSETTINGS]');
  await page.locator('[data-native=btnOk]').click();
  await page.waitForFunction(()=>window.rcsk.state.page==='driving',null,{timeout:60000});
  const state=()=>page.evaluate(()=>{
    const view=rcsk.viewer,audio=view.audio,sim=view.simulation;
    return {panStage:sim.startCamera?.stage,panDone:sim.startCamera?.done,
      countdownStarted:sim.countdownStarted,movementActive:sim.movementActive,
      active:audio.engine.active,gear:audio.engine.gear,
      starter:audio.isPlaying(audio.engine.spec.start.event),
      layers:audio.engine.spec.layers.map(layer=>({event:layer.sound.event,
        playing:audio.isPlaying(layer.sound.event),loop:audio.slots.get(layer.sound.event.toLowerCase())?.source?.loop??false})),
      starts:window.engineStartTrace};
  });
  const loaded=await state();
  assert.equal(loaded.panDone,false);assert.equal(loaded.countdownStarted,false);
  assert.equal(loaded.active,false);assert.equal(loaded.starter,false);
  assert.equal(loaded.layers.some(layer=>layer.playing),false);
  assert.deepEqual(loaded.starts,[]);
  report.checks.push({case:'samples preloaded while engine stays silent at race load',...loaded});
  await page.waitForFunction(()=>rcsk.viewer.simulation.startCamera.stage===1);
  const pan=await state();
  assert.equal(pan.panDone,false);assert.equal(pan.countdownStarted,false);
  assert.equal(pan.active,false);assert.deepEqual(pan.starts,[]);
  report.checks.push({case:'authored opening pan remains silent',...pan});
  await page.waitForFunction(()=>engineStartTrace.length>0,null,{timeout:60000});
  const started=await state();
  assert.equal(started.starts.length,1);
  assert.deepEqual({...started.starts[0],sourceStartTime:0},{
    event:'cmstartm',loop:false,panDone:true,countdownStarted:true,
    movementActive:false,phase:1,engineActive:true,playing:true,contextState:'running',sourceStartTime:0});
  assert.equal(started.gear,-1);assert.equal(started.starter,true);
  assert.equal(started.layers.some(layer=>layer.playing),false);
  report.checks.push({case:'one original starter source begins after pan at countdown START',...started});
  await page.waitForFunction(()=>rcsk.viewer.audio.engine.gear===0,null,{timeout:30000});
  const layers=await state();
  assert.equal(layers.starter,false);assert.equal(layers.starts.length,1);
  assert.ok(layers.layers.every(layer=>layer.playing&&layer.loop));
  report.checks.push({case:'three engine loops wait for the starter PCM to end',...layers});
  assert.deepEqual(await page.evaluate(()=>rcsk.viewer.errors),[]);
  assert.deepEqual(report.errors,[]);
  report.status='passed';
}catch(error){
  report.status='failed';report.failure=String(error.stack||error);throw error;
}finally{
  report.sourceHashes=Object.fromEntries(await Promise.all(
    ['src/engine-audio.js','src/native-race-audio.js','src/driving-view.js','src/race-simulation.js']
      .map(async file=>[file,createHash('sha256').update(await readFile(file)).digest('hex')])));
  report.scope='Actual menu launch, authored opening camera, countdown and WebAudio playback. No native Wine race rendering comparison; source timing is established by original instruction fixtures.';
  await writeFile('evidence/audio/browser-engine-start.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors}));
}
