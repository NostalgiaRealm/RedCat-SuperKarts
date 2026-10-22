import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const origin=process.env.RCSK_URL||'http://127.0.0.1:4173',errors=[];
try{
  const page=await browser.newPage();
  page.on('pageerror',error=>errors.push(error.message));
  await page.goto(origin+'/?skipIntro');
  await page.evaluate(()=>localStorage.setItem('rcsk.settings.v1',JSON.stringify({effects:0,music:0})));
  await page.goto(origin+'/?drive=0');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  const race=await page.evaluate(()=>{
    const view=rcsk.viewer,audio=view.audio;
    const initial={effects:rcsk.state.settings.effects,group:audio.groupVolume,
      music: view.music.audio.volume,controller:audio.controllerEnabled,
      stored:JSON.parse(localStorage.getItem('rcsk.settings.v1')).effects,
      clones:audio.scenery.map(entry=>({source:entry.baseVolume,
        actual:audio.slots.get(entry.voiceId).baseVolume}))};
    view.setAudioSettings({...rcsk.state.settings,effects:.25});
    const changed=audio.scenery.map(entry=>audio.slots.get(entry.voiceId).baseVolume);
    const original=audio.setGroupVolume.bind(audio);let repeated=0;
    audio.setGroupVolume=percent=>{repeated++;return original(percent);};
    view.setAudioSettings({...rcsk.state.settings,effects:.25});
    const unchangedWrites=repeated;
    view.setAudioSettings({...rcsk.state.settings,effects:0});
    return {initial,changed,unchangedWrites,muted:{
      controller:audio.controllerEnabled,crashes:view.simulation.crashAudio.enabled,
      queueEnabled:audio.voices.enabled}};
  });
  assert.equal(race.initial.effects,.75);assert.equal(race.initial.group,75);
  assert.equal(race.initial.stored,.75);assert.equal(race.initial.music,0);
  assert.equal(race.initial.controller,true);
  assert.ok(race.initial.clones.every(clone=>clone.actual===clone.source));
  assert.ok(race.changed.every(volume=>volume===25));
  assert.equal(race.unchangedWrites,0);
  assert.deepEqual(race.muted,{controller:false,crashes:false,queueEnabled:false});
  await page.goto(origin+'/');
  await page.waitForFunction(()=>rcsk.state.page==='intro'&&document.querySelector('#movie').src.endsWith('intro.mp4'));
  const movie=await page.locator('#movie').evaluate(movie=>({volume:movie.volume,muted:movie.muted}));
  assert.deepEqual(movie,{volume:1,muted:false});
  assert.deepEqual(errors,[]);
  const report={status:'passed',browser:browser.version(),race,movie,errors,
    scope:'Actual page settings propagation and load-time zero-volume repair; controlled live setter calls check source clones and crash/FIFO gates. The movie keeps its original independent gain.'};
  await writeFile('evidence/audio/settings-playback.json',JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,initialEffects:race.initial.group,clones:race.initial.clones.length,movie}));
}finally{await browser.close();}
