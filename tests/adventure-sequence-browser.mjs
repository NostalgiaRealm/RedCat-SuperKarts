import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {nativeAdventureConfiguration,nativeAdventureReward} from '../src/simulation/native-adventure.js';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const config=JSON.parse(await readFile('public/assets/config.json'));
const adventure=nativeAdventureConfiguration(config);
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),origin,status:'running',stages:[],errors:[],
  scope:'One profile through all24 original Adventure events without resetting browser storage. Each race loads its real track, startup, HUD, opponents and result flow; a controlled final-lap trigger supplies its outcome and ItemRace supplies12 stars. Animation timestamps run4x and HTML media8x. This is consecutive UI/save integration, not a driven campaign or a native whole-race comparison.'};
await mkdir('evidence/adventure-sequence',{recursive:true});
const page=await browser.newPage({viewport:{width:800,height:600}});
const control=name=>page.locator(`[data-native=${name}]`);
const form=name=>page.waitForSelector(`[data-form=${name}]`);
const saved=()=>page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1')));
page.on('pageerror',error=>report.errors.push(error.message));
page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
await page.addInitScript(()=>{
  const frame=window.requestAnimationFrame.bind(window);
  window.requestAnimationFrame=callback=>frame(time=>callback(time*4));
  const play=HTMLMediaElement.prototype.play;
  HTMLMediaElement.prototype.play=function(){this.playbackRate=8;return play.call(this);};
});
try{
  await page.goto(origin+'/?skipIntro');
  await control('btnAdventure').click();await form('TFRMADVENTUREMAIN');
  await control('btnNewPlayer').click();await form('TFRMEDITBOX');
  await page.locator('[data-element=edtName]').fill('Hele avontuur');
  await control('btnOk').click();await form('TFRMSELECTCHAR');
  await control('rdoEasy').click();await control('btnOk').click();await form('TFRMADVENTBRIEF');
  const expectedMatrix=Array.from({length:6},()=>Array(5).fill(0));
  const expectedLocks=[...adventure.locks];
  for(const [index,event]of adventure.sequence.entries()){
    assert.equal((await saved()).profiles[0].adventure,index);
    assert.deepEqual(await page.evaluate(()=>rcsk.state.selection),
      {character:0,difficulty:0,country:event.country,race:event.raceType});
    await control('btnOk').click();await form('TFRMCONTROLSETTINGS');await control('btnOk').click();
    await page.waitForFunction(index=>rcsk.state.page==='driving'&&rcsk.viewer.track.id===index,event.country,{timeout:60000});
    await page.waitForFunction(()=>rcsk.viewer.simulation.movementActive,null,{timeout:60000});
    const started=await page.evaluate(()=>({
      track:rcsk.viewer.track.id,mode:rcsk.viewer.race.raceType,difficulty:rcsk.viewer.simulation.difficulty,
      opponents:rcsk.viewer.opponents.length,errors:rcsk.viewer.errors,
    }));
    assert.equal(started.mode,event.raceType);
    assert.equal(started.opponents,[4,3,3,1][event.raceType]);
    assert.deepEqual(started.errors,[]);
    await page.evaluate(()=>{
      const viewer=rcsk.viewer,race=viewer.race;
      if(race.raceType===2)viewer.pickups.stars=12;
      race.lapCount=race.lapLimit-1;race.finishArmed=true;
      race.trigger(14,{previous:0,current:1});
    });
    await page.waitForFunction(()=>{
      const gate=rcsk.viewer.simulation.lifecycle.resultGate;
      return gate&&gate.startedMs!==0xffffffff&&rcsk.viewer.simulation.wallMs-gate.startedMs>1700;
    },null,{timeout:30000});
    await page.keyboard.press('Enter',{delay:100});await form('TFRMDEBRIEF');
    const before=await saved();
    assert.equal(before.profiles[0].adventure,index);
    assert.deepEqual(before.profiles[0].matrix,expectedMatrix,'displaying results must not advance the saved profile');
    await control('btnOk').click();
    const seen={movies:[],notices:[],highscore:false};
    const deadline=Date.now()+60000;
    let previousMovie='';
    while(true){
      const state=await page.evaluate(()=>({page:rcsk.state.page,mode:rcsk.state.mode,
        form:document.querySelector('[data-form]')?.dataset.form,
        movie:document.querySelector('#movie')?.getAttribute('src'),
        message:document.querySelector('[data-element=lblQuit]')?.textContent}));
      if(state.form==='TFRMADVENTBRIEF'||state.form==='TFRMMAIN')break;
      if(state.mode==='reward'){
        if(state.movie&&state.movie!==previousMovie){seen.movies.push(state.movie.split('/').at(-1));previousMovie=state.movie;}
      }else if(state.form==='TFRMREQUESTER'){
        seen.notices.push(state.message);await control('btnOk').click();
      }else if(state.form==='TFRMEDITBOX'){
        seen.highscore=true;await control('btnCancel').click();
      }
      if(Date.now()>deadline)throw Error('Adventure result stalled: '+JSON.stringify(state));
      await page.waitForTimeout(50);
    }
    expectedMatrix[event.country][event.raceType]=1;
    const unlocked=expectedMatrix.every(row=>row[event.raceType])?adventure.unlockCountries[event.raceType]:null;
    if(unlocked!==null)expectedLocks[unlocked]=false;
    const after=await saved(),profile=after.profiles[0],final=index===adventure.sequence.length-1;
    assert.deepEqual(profile.matrix,expectedMatrix);
    assert.deepEqual(after.locks,expectedLocks);
    assert.equal(profile.adventure,final?0:index+1);
    assert.equal(profile.completed,final);
    assert.equal(profile.name,'Hele avontuur');
    const movies=[];
    if(event.raceType===3)movies.push(nativeAdventureReward(config,'star',event.country).source.replace(/\.[^.]+$/,'.mp4').toLowerCase());
    if(final)movies.push('rcwin.mp4');
    assert.deepEqual(seen.movies,movies);
    report.stages.push({index,...event,...started,...seen,unlocked,savedAdventure:profile.adventure,completed:profile.completed});
    await writeFile('evidence/adventure-sequence/report.json',JSON.stringify(report,null,2)+'\n');
    console.log(`Adventure event ${index+1}/24 passed`);
  }
  await page.reload();await form('TFRMMAIN');
  const restored=await saved();
  assert.equal(restored.profiles[0].completed,true);assert.deepEqual(restored.locks,Array(6).fill(false));
  await control('btnAdventure').click();await control('btnOk').click();await form('TFRMADVENTBRIEF');
  const replay=await saved();
  assert.equal(replay.profiles[0].completed,false);
  assert.ok(replay.profiles[0].matrix.every(row=>row.every(value=>value===0)));
  assert.deepEqual(replay.locks,Array(6).fill(false));
  assert.deepEqual(report.errors,[]);
  report.reloadedCompletedProfile=true;report.replayPreservesGlobalUnlocks=true;report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile('evidence/adventure-sequence/report.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
}
