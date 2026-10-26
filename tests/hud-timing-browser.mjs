import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';

const output=process.env.RCSK_HUD_TIMING_OUTPUT||'evidence/hud-timing/browser';
await mkdir(output,{recursive:true});
const files=['source/main.js','source/input.js','source/driving-view.js','source/race-hud.js',
  'source/hud-text.js','source/hud-notifications.js','source/hud-gameplay-events.js',
  'source/race-requester.js','source/native-quit-requester.js','source/style.css',
  'source/simulation/native-lap-display.js','source/simulation/native-race-lifecycle.js',
  'public/assets/config.json','tests/hud-timing-browser.mjs'];
const hashes=async()=>Object.fromEntries(await Promise.all(files.map(async file=>[file,
  createHash('sha256').update(await readFile(file)).digest('hex')])));
const report={status:'running',scope:'Source-only Chromium software-WebGL integration. Lap boundary cases supply disclosed race/absolute-clock snapshots to the real RaceHud; pause and requester cases use actual keyboard, pointer, and emulated standard Gamepad API input in the running game. The lap event in the pause case is controlled; no completed race is claimed. Audio observation calls through the original HTMLMediaElement.play. No packaged app or existing user session is accessed.',checks:[],errors:[],hashesBefore:await hashes()};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
try{
  const page=await browser.newPage({viewport:{width:1280,height:720}});
  page.on('pageerror',error=>report.errors.push(error.stack||error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.addInitScript(()=>{
    // A race loads far more than Chromium's default 250 resource records.
    performance.setResourceTimingBufferSize(20000);
    localStorage.setItem('rcsk.selection.v1',JSON.stringify({character:1,difficulty:0,country:0,race:0}));
    localStorage.setItem('rcsk.settings.v1',JSON.stringify({touch:'on'}));
    window.timingPad={id:'Explicit automated standard controller',connected:true,mapping:'standard',
      axes:[0,0],buttons:Array.from({length:16},()=>({value:0,pressed:false,touched:false}))};
    Object.defineProperty(navigator,'getGamepads',{value:()=>[window.timingPad]});
    window.timingMedia=[];
    const play=HTMLMediaElement.prototype.play;
    HTMLMediaElement.prototype.play=function(...args){
      if(this.src.toLowerCase().includes('click4.wav')){
        timingMedia.push({event:'play',time:performance.now(),src:this.src});
        this.addEventListener('playing',()=>timingMedia.push({event:'playing',time:performance.now(),src:this.src}),{once:true});
      }
      return play.apply(this,args);
    };
  });
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4174')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
  await page.evaluate(()=>rcsk.viewer.clock.pause());
  const lap=await page.evaluate(()=>{
    const v=rcsk.viewer,h=v.hud;
    const base={elapsedMs:12345,lapStartMs:0,lapTimerLimitMs:999999,lapCount:0,lapLimit:5,
      bestLapMs:0x0fffffff,raceType:0,remainingMs:0,events:[]};
    const rows=[];
    const capture=(name,race,nowSeconds)=>{
      h.update(race,.025,{nowSeconds});
      rows.push({name,nowSeconds,text:h.text.string_laptime_value,...h.lapDisplay.state});
    };
    capture('previous displayed value',base,100.7);
    const event={type:'native-notification',id:8};
    const next={...base,elapsedMs:12425,lapStartMs:12399,lapCount:1,events:[event]};
    capture('lap event uses integer absolute engine stamp',next,100.975);
    capture('same event is not repeated', {...next,elapsedMs:12500},101.5);
    capture('before absolute threshold',{...next,elapsedMs:14423},102.999);
    capture('threshold clears stamp but keeps old text',{...next,elapsedMs:14424},103);
    capture('following capture reads live lap timer',{...next,elapsedMs:14449},103.025);
    h.render();return rows;
  });
  assert.equal(lap[0].text,'00:12:34');
  for(const row of lap.slice(1,5))assert.equal(row.text,lap[0].text);
  for(const row of lap.slice(1,4))assert.equal(row.holdStampSeconds,100);
  assert.equal(lap[4].holdStampSeconds,-1);assert.equal(lap[5].text,'00:02:05');
  report.checks.push({case:'retained rendered lap text, integer absolute clock, one clearing capture',rows:lap});

  // Reload the original race to discard the isolated HUD input snapshots.
  await page.evaluate(async()=>{const v=rcsk.viewer;await v.load(0,{character:1,difficulty:0,raceMode:0});v.resume();});
  await page.waitForFunction(()=>rcsk.viewer.simulation.engineMs>300);
  await page.evaluate(()=>{
    const v=rcsk.viewer,h=v.hud;
    window.timingUpdates=[];window.timingResumes=[];window.timingNotices=[];
    const update=h.update;h.update=function(...args){
      const before={...this.lapDisplay.state};const result=update.apply(this,args);
      timingUpdates.push({time:performance.now(),nowSeconds:this.nowSeconds,before,
        after:{...this.lapDisplay.state},text:this.text.string_laptime_value});return result;
    };
    const resume=v.resume;v.resume=function(...args){
      const result=resume.apply(this,args);timingResumes.push({time:performance.now(),nowSeconds:this.simulation.engineMs/1000});return result;
    };
    const notify=h.notify;h.notify=function(id,...args){timingNotices.push({id,time:performance.now()});return notify.call(this,id,...args);};
    h.notify(8,0,{lapCount:1,nowSeconds:v.simulation.engineMs/1000});
  });
  await page.keyboard.down('p');
  await page.waitForFunction(()=>rcsk.state.mode==='paused');
  await page.keyboard.up('p');
  const beforePause=await page.evaluate(()=>({text:rcsk.viewer.hud.text.string_laptime_value,
    hold:{...rcsk.viewer.hud.lapDisplay.state},updates:timingUpdates.length,raceMs:rcsk.viewer.race.elapsedMs}));
  await page.waitForTimeout(3150);
  const duringPause=await page.evaluate(()=>({text:rcsk.viewer.hud.text.string_laptime_value,
    hold:{...rcsk.viewer.hud.lapDisplay.state},updates:timingUpdates.length,raceMs:rcsk.viewer.race.elapsedMs}));
  assert.deepEqual(duringPause,beforePause);
  await page.keyboard.down('x');await page.keyboard.up('x');
  await page.waitForFunction(()=>rcsk.state.mode==='race'&&timingUpdates.some(x=>x.after.holdStampSeconds===-1));
  await page.waitForTimeout(150);
  const pause=await page.evaluate(({updates})=>({before:timingUpdates.slice(updates,updates+3),
    notices:timingNotices.map(x=>x.id),resumes:[...timingResumes]}),beforePause);
  assert.ok(pause.before.length>=2);assert.equal(pause.before[0].after.holdStampSeconds,-1);
  assert.equal(pause.before[0].text,beforePause.text);
  assert.equal(pause.before[1].before.holdStampSeconds,-1);
  assert.ok(pause.before[0].nowSeconds-beforePause.hold.holdStampSeconds>=3);
  assert.ok(pause.notices.includes(1)&&pause.notices.includes(2));
  report.checks.push({case:'actual pause freezes capture and resumed absolute clock clears hold before refreshing',beforePause,duringPause,...pause});
  await page.screenshot({path:`${output}/race-after-lap-hold.png`});

  const open=async()=>{
    await page.evaluate(()=>{
      timingMedia.length=0;timingResumes.length=0;timingNotices.length=0;
      const h=rcsk.viewer.hud;h.notify(2,0,{capture:true});h.notify(5,0,{capture:true});
      window.timingPriorNotice=h.notifications.text;timingNotices.length=0;
    });
    await page.keyboard.down('Escape');
    await page.waitForFunction(()=>rcsk.state.mode==='paused');
    await page.waitForTimeout(125);
    const held=await page.evaluate(()=>({mode:rcsk.state.mode,
      shown:!!document.querySelector('[data-form=RACE_STOPPEN]')?.getClientRects().length,
      stage:document.querySelector('[data-form=RACE_STOPPEN]')?.dataset.state,
      notices:[...timingNotices],text:rcsk.viewer.hud.notifications.text,prior:timingPriorNotice,
      media:timingMedia.filter(x=>x.event==='play')}));
    assert.equal(held.shown,false);assert.equal(held.stage,'initial-release');
    assert.deepEqual(held.notices,[]);assert.equal(held.text,held.prior);assert.deepEqual(held.media,[]);
    await page.keyboard.up('Escape');
    await page.waitForFunction(()=>document.querySelector('[data-form=RACE_STOPPEN]')?.dataset.state==='input');
    await page.evaluate(()=>{
      const stage=document.querySelector('[data-form=RACE_STOPPEN]'),wrap=stage.parentElement;
      window.timingRequester={rows:[],resumesAtStart:timingResumes.length,notice:timingPriorNotice};
      const record=()=>{
        const state=wrap.requesterState;
        timingRequester.rows.push({...state,time:performance.now(),mode:rcsk.state.mode,
          images:Object.fromEntries([...stage.querySelectorAll('button')].map(b=>[b.dataset.choice,{
            pressed:b.dataset.pressed,image:getComputedStyle(b).backgroundImage}]))});
      };
      for(const name of ['update','choose']){const original=wrap[name];wrap[name]=function(...args){const result=original.apply(this,args);record();return result;};}
      record();
    });
    return held;
  };
  const result=async(name,{quit=false}={})=>{
    await page.waitForFunction(quit?()=>rcsk.state.mode!=='paused':()=>rcsk.state.mode==='race',null,{timeout:10000});
    await page.waitForTimeout(150);
    const row=await page.evaluate(()=>({rows:timingRequester.rows,media:[...timingMedia],resumes:[...timingResumes],
      notices:[...timingNotices],mode:rcsk.state.mode,notice:rcsk.viewer.hud?.notifications.text,prior:timingRequester.notice}));
    const pressed=row.rows.find(x=>x.stage==='pressed'),done=row.rows.find(x=>x.stage==='done');
    assert.ok(pressed&&done,`${name}: pressed and done observed`);
    assert.ok((((done.time>>>0)-pressed.startedMs)>>>0)>=100,`${name}: >=100 ms original deadline`);
    assert.equal(row.media.filter(x=>x.event==='play').length,1,`${name}: click4 exactly once`);
    assert.equal(row.media.filter(x=>x.event==='playing').length,1,`${name}: click4 actually playing`);
    assert.ok(pressed.images[pressed.pressed].image.includes(pressed.pressed==='yes'?'ja_i.tga.png':'nee_i.tga.png'));
    assert.ok(row.rows.filter(x=>x.stage==='pressed').every(x=>x.code===pressed.code));
    assert.equal(row.notices.some(x=>x.id===1||x.id===2),false,`${name}: quit path does not alter pause notices`);
    assert.equal(row.resumes.length,quit?0:1);
    if(!quit)assert.equal(row.notice,row.prior);
    const compact={case:name,pressed,done,media:row.media,resumes:row.resumes,notices:row.notices,
      finalMode:row.mode,minimumDelayMs:((done.time>>>0)-pressed.startedMs)>>>0,notice:row.notice};
    report.checks.push(compact);return compact;
  };

  const opening=await open();
  // The CSS artwork is lazy loaded when the native wrapper becomes visible.
  // Wait only for currently displayed images before visual capture; do not
  // preload the unselected pressed sprites in this first-use regression.
  report.firstUseArtwork=await page.evaluate(async()=>{
    const stage=document.querySelector('[data-form=RACE_STOPPEN]');
    const started=performance.now();
    const urls=[stage,...stage.querySelectorAll('button')].map(e=>getComputedStyle(e).backgroundImage.match(/url\("?(.*?)"?\)/)?.[1]).filter(Boolean);
    const images=await Promise.all(urls.map(async url=>{const image=new Image();image.src=url;await image.decode();return {url,width:image.naturalWidth,height:image.naturalHeight,readyMs:performance.now()};}));
    await new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve)));
    return {startedMs:started,images,resourceBeforePress:performance.getEntriesByType('resource').filter(e=>/\/(esc_hi|ja_[ufi]|nee_[ufi])\.tga\.png/.test(e.name)).map(e=>({url:e.name,start:e.startTime,finished:e.responseEnd}))};
  });
  await page.screenshot({path:`${output}/original-stoppen.png`});
  report.checks.push({case:'opening Escape waits for release and preserves existing notice',opening});
  const no=page.locator('[data-choice=no]');const box=await no.boundingBox();
  await page.mouse.move(box.x+box.width/2,box.y+box.height/2);await page.mouse.down();
  await page.evaluate(()=>{
    const wrap=document.querySelector('[data-form=RACE_STOPPEN]').parentElement;
    wrap.choose(2);wrap.choose(3); // Repeated host activations must not replace the pending choice.
  });
  await page.screenshot({path:`${output}/pointer-pressed.png`});
  await result('pointer down commits No after pressed interval, before pointer release; repeats ignored');
  await page.mouse.up();

  for(const [key,label]of [['n','keyboard N'],['Escape','keyboard Escape']]){
    await open();await page.keyboard.down(key);await page.waitForTimeout(180);
    const held=await page.evaluate(()=>({state:document.querySelector('[data-form=RACE_STOPPEN]').dataset.state,
      media:timingMedia.filter(x=>x.event==='play').length,resumes:timingResumes.length}));
    assert.deepEqual(held,{state:'key-release',media:0,resumes:0});
    await page.keyboard.up(key);const row=await result(`${label} waits release, then pressed art and delayed No`);row.held=held;
  }
  for(const [index,label]of [[0,'A focused No'],[1,'Back No']]){
    await open();
    await page.evaluate(index=>Object.assign(timingPad.buttons[index],{value:1,pressed:true,touched:true}),index);
    const row=await result(`standard gamepad ${label} activates once while held`);
    await page.waitForTimeout(150);assert.equal(await page.evaluate(()=>timingResumes.length),1);
    await page.evaluate(index=>Object.assign(timingPad.buttons[index],{value:0,pressed:false,touched:false}),index);
    row.emulatedStandardGamepad=true;
  }
  await open();await page.keyboard.down('j');await page.waitForTimeout(180);
  const yesHeld=await page.evaluate(()=>({state:document.querySelector('[data-form=RACE_STOPPEN]').dataset.state,
    media:timingMedia.filter(x=>x.event==='play').length,mode:rcsk.state.mode}));
  assert.deepEqual(yesHeld,{state:'key-release',media:0,mode:'paused'});
  await page.keyboard.up('j');const yes=await result('keyboard J release selects original Ja pressed art before delayed quit',{quit:true});yes.held=yesHeld;
  await page.screenshot({path:`${output}/after-original-quit.png`});
  report.artworkResources=await page.evaluate(()=>performance.getEntriesByType('resource').filter(e=>/\/(esc_hi|ja_[ufi]|nee_[ufi])\.tga\.png/.test(e.name)).map(e=>({url:e.name,start:e.startTime,finished:e.responseEnd,duration:e.duration})));
  report.hashesAfter=await hashes();report.changedDuringRun=files.filter(file=>report.hashesBefore[file]!==report.hashesAfter[file]);
  assert.deepEqual(report.changedDuringRun,[]);assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=error.stack;throw error;}
finally{await writeFile(output+'/report.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(`HUD timing browser: ${report.checks.length} check groups passed`);
