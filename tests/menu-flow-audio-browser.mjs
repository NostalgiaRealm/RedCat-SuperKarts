import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {createNativeAdventureProfile,nativeAdventureConfiguration} from '../src/simulation/native-adventure.js';
import {nativeAdventureBriefingSound,nativeCountryInfoSound} from '../src/menu-sound-events.js';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const directory='evidence/audio/menu-flow';
const config=JSON.parse(await readFile('public/assets/config.json'));
const sequence=nativeAdventureConfiguration(config).sequence;
const generic=index=>config['ini/soundset.dat'].generic_samples[index].toLowerCase();
const character=(bank,index)=>config['ini/'+['rc','wk','br','mx'][bank]+'_snd.dat'].sample_set[index].toLowerCase();
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required','--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),scope:'Actual menu UI and shipped WAV requests/playing/ended/pause events at16x transport speed, except farewell at1x to inspect the waiting state. No substituted audio, full races, listening claim or native sound-card capture.',
  checks:[],briefings:[],errors:[],requests:[]};
await mkdir(directory,{recursive:true});
const context=await browser.newContext({viewport:{width:1024,height:768}});
await context.addInitScript(()=>{
  window.menuAudioEvents=[];window.menuAudioTracks=[];
  const play=HTMLMediaElement.prototype.play,pause=HTMLMediaElement.prototype.pause;
  const file=audio=>(audio.currentSrc||audio.src).split('/').at(-1).toLowerCase();
  const record=(audio,event)=>window.menuAudioEvents.push({event,id:audio.__menuAudioId,file:file(audio),
    time:performance.now(),form:document.querySelector('[data-form]')?.dataset.form,
    duration:Number.isFinite(audio.duration)?audio.duration:null,readyState:audio.readyState});
  HTMLMediaElement.prototype.play=function(){
    if(this.src.toLowerCase().endsWith('.wav')){
      if(this.__menuAudioId===undefined){
        this.__menuAudioId=window.menuAudioTracks.length;window.menuAudioTracks.push(this);
        // Capture runs before MenuAudio's onended callback can admit the next
        // awaited clip, keeping the measured completion/next-play order exact.
        for(const event of ['playing','ended','error'])this.addEventListener(event,()=>record(this,event),{capture:true});
      }
      this.playbackRate=window.menuSlowFiles?.includes(file(this))?1:16;record(this,'play');
    }
    return play.call(this);
  };
  HTMLMediaElement.prototype.pause=function(){if(this.__menuAudioId!==undefined)record(this,'pause');return pause.call(this);};
});
const page=await context.newPage();
page.on('pageerror',error=>report.errors.push(error.message));
page.on('response',response=>{if(response.status()>=400)report.errors.push(response.status()+' '+response.url());});
page.on('request',request=>{if(request.url().toLowerCase().endsWith('.wav'))report.requests.push(request.url().split('/').at(-1).toLowerCase());});
const button=name=>page.locator(`[data-native=${name}]`);
const form=name=>page.waitForSelector(`[data-form=${name}]`);
const events=()=>page.evaluate(()=>window.menuAudioEvents);
const mark=()=>page.evaluate(()=>window.menuAudioEvents.length);
async function played(file,after=0){
  await page.waitForFunction(({file,after})=>window.menuAudioEvents.slice(after).some(event=>event.event==='playing'&&event.file===file&&event.duration>0&&event.readyState>=2),{file,after});
  return (await events()).slice(after).find(event=>event.event==='playing'&&event.file===file);
}
async function open(profiles=[],selectedSlot=0,selection={character:0,difficulty:1,country:0,race:0}){
  if(page.url().startsWith(origin))await page.evaluate(({profiles,selectedSlot,selection})=>{
    localStorage.clear();localStorage.setItem('rcsk.race-save.v1',JSON.stringify({profiles,selectedSlot}));
    localStorage.setItem('rcsk.selection.v1',JSON.stringify(selection));
  },{profiles,selectedSlot,selection});
  else{
    await page.goto(origin+'/?skipIntro');
    return open(profiles,selectedSlot,selection);
  }
  await page.goto(origin+'/?skipIntro');await form('TFRMMAIN');
}
async function adventure(profiles,selectedSlot=0){
  const selected=profiles[selectedSlot];
  await open(profiles,selectedSlot,{character:selected?.character??0,difficulty:selected?.difficulty??1,country:0,race:0});
  await button('btnAdventure').click();await form('TFRMADVENTUREMAIN');
}
async function remember(label){
  await page.evaluate(label=>{
    window.rememberedMenu={label,node:document.querySelector('[data-form]'),focus:document.activeElement};
  },label);
}
async function restored(label){
  assert.equal(await page.evaluate(label=>window.rememberedMenu.label===label&&
    document.querySelector('[data-form]')===window.rememberedMenu.node&&document.activeElement===window.rememberedMenu.focus,label),true,label+' restores exact caller DOM and focus');
}
async function count(file){return (await events()).filter(event=>event.event==='play'&&event.file===file).length;}
try{
  for(const [index,entry] of sequence.entries()){
    const profile=createNativeAdventureProfile('Briefing '+index,{slot:0});
    Object.assign(profile,{adventure:entry.index,character:index%4,difficulty:index%3});
    await adventure([profile]);
    const after=await mark();await button('btnOk').click();await form('TFRMADVENTBRIEF');
    const file=generic(nativeAdventureBriefingSound(entry.country,entry.raceType));
    const playback=await played(file,after);
    const selection=await page.evaluate(()=>window.rcsk.state.selection);
    assert.deepEqual(selection,{character:profile.character,difficulty:profile.difficulty,country:entry.country,race:entry.raceType});
    report.briefings.push({adventure:entry.index,country:entry.country,event:entry.raceType,
      character:profile.character,difficulty:profile.difficulty,file,duration:playback.duration});
    if(index===0)await page.screenshot({path:directory+'/adventure-briefing.png'});
  }
  assert.equal(new Set(report.briefings.map(entry=>entry.file)).size,24);
  report.checks.push('All24 original country/event briefing WAVs decode and play through saved-profile UI; four characters and three difficulties distributed across the24 entries');

  await open();
  const optionsStart=await mark();await button('btnMainOptions').click();await form('TFRMOPTIONS');
  await page.waitForFunction(after=>new Set(window.menuAudioEvents.slice(after).filter(event=>event.event==='playing'&&event.file==='mn_s003.wav').map(event=>event.id)).size===2,optionsStart);
  const optionEvents=(await events()).slice(optionsStart);
  assert.deepEqual(optionEvents.filter(event=>event.event==='play').map(event=>event.file),[generic(46),character(0,23),generic(46)]);
  const endFirst=optionEvents.findIndex(event=>event.event==='ended'&&event.file===generic(46));
  const playVoice=optionEvents.findIndex(event=>event.event==='play'&&event.file===character(0,23));
  const endVoice=optionEvents.findIndex(event=>event.event==='ended'&&event.file===character(0,23));
  const playLast=optionEvents.findLastIndex(event=>event.event==='play'&&event.file===generic(46));
  assert.ok(endFirst>=0&&endFirst<playVoice&&endVoice>playVoice&&endVoice<playLast);
  report.checks.push('Main Options plays shared generic46 to completion, character23 to completion, then Main click generic46 asynchronously');

  const profiles=[0,1].map(slot=>Object.assign(createNativeAdventureProfile('Speler '+slot,{slot}),{character:slot===0?0:3,difficulty:slot===0?0:2,country:slot===0?0:4,raceType:slot===0?0:2}));
  await adventure(profiles);await button('btnRight').click();
  await page.waitForFunction(()=>document.querySelector('[data-element=lblPlayerName]')?.textContent==='Speler 1');
  assert.deepEqual(await page.evaluate(()=>window.rcsk.state.selection),{character:3,difficulty:2,country:4,race:2});
  report.checks.push('Browsing saved profiles updates the active saved character/difficulty/country/event without prematurely applying the next briefing event');

  await button('btnDeletePlayer').focus();await remember('delete');
  const deleteStart=await mark();await button('btnDeletePlayer').click();await form('TFRMREQUESTER');
  await played(character(3,26),deleteStart);
  const greetingCount=await count(generic(25));await button('btnCancel').click();await form('TFRMADVENTUREMAIN');
  await restored('delete');assert.equal(await count(generic(25)),greetingCount);
  report.checks.push('Delete asks with selected character26; Cancel restores identical Adventure form/focus with no entrance greeting');

  await button('btnMainStop').focus();await remember('quit');
  await button('btnMainStop').click();await form('TFRMREQUESTER');
  await button('btnCancel').click();await form('TFRMADVENTUREMAIN');
  await restored('quit');assert.equal(await count(generic(25)),greetingCount);
  report.checks.push('Quit Cancel restores identical Adventure form/focus without replaying its greeting');

  await button('btnNewPlayer').focus();await remember('new-profile-cancel');
  await button('btnNewPlayer').click();await form('TFRMEDITBOX');await button('btnCancel').click();await form('TFRMADVENTUREMAIN');
  await restored('new-profile-cancel');assert.equal(await count(generic(25)),greetingCount);
  report.checks.push('Canceling New profile name entry preserves identical caller and does not play a fresh Adventure greeting');

  await button('btnNewPlayer').click();await form('TFRMEDITBOX');
  await page.locator('[data-element=edtName]').fill('Nieuwe speler');
  let after=await mark();await button('btnOk').click();await form('TFRMSELECTCHAR');await played(generic(53),after);
  assert.equal(await page.evaluate(()=>localStorage.getItem('rcsk.firsttime.characters')),null);
  await button('btnBack').click();await form('TFRMADVENTUREMAIN');
  assert.equal(await page.locator('[data-element=lblPlayerName]').textContent(),'Nieuwe speler');
  assert.equal(await page.evaluate(()=>localStorage.getItem('rcsk.firsttime.characters')),null);
  await button('btnBack').click();await form('TFRMMAIN');
  await button('btnQuickRace').click();await form('TFRMSELECTCHAR');
  assert.equal(await page.evaluate(()=>localStorage.getItem('rcsk.firsttime.characters')),'1');
  report.checks.push('Adventure new-character entry uses generic53 without consuming Quickrace FIRSTTIME; Back returns to profile list; subsequent Quickrace consumes its own flag');

  const briefProfile=createNativeAdventureProfile('Landinfo',{slot:0});
  await adventure([briefProfile]);await button('btnOk').click();await form('TFRMADVENTBRIEF');await played(generic(56));
  const briefCount=await count(generic(56));
  await button('btnOverview').focus();await remember('overview');
  after=await mark();await button('btnOverview').click();await form('TFRMLANDINFO');await played(generic(nativeCountryInfoSound(0)),after);
  assert.deepEqual((await events()).slice(after).filter(event=>event.event==='play').map(event=>event.file),[generic(46),generic(nativeCountryInfoSound(0))]);
  const countryIntroCount=await count(generic(nativeCountryInfoSound(0)));
  await page.evaluate(()=>window.rememberedBriefing=window.rememberedMenu);
  await button('btnMainHelp').focus();await remember('country-help');
  await button('btnMainHelp').click();await form('TFRMREQUESTER');
  assert.equal(await page.locator('[data-element=lblQuit]').textContent(),config['ini/shellang.ini'].dutch[46]);
  await button('btnOk').click();await form('TFRMLANDINFO');await restored('country-help');
  assert.equal(await count(generic(nativeCountryInfoSound(0))),countryIntroCount);
  report.checks.push('Overview requests generic46 then the country introduction; country Help displays original notice46 and restores identical Landinfo without repeating its narration');

  after=await mark();await page.locator('[data-element=imgPhoto1]').click();await played(generic(nativeCountryInfoSound(0,0)),after);
  await button('btnOk').click();await form('TFRMADVENTBRIEF');
  assert.equal(await page.evaluate(()=>document.querySelector('[data-form]')===window.rememberedBriefing.node&&document.activeElement===window.rememberedBriefing.focus),true);
  assert.equal(await count(generic(56)),briefCount);
  assert.equal(await page.evaluate(file=>window.menuAudioTracks.filter(audio=>audio.src.toLowerCase().endsWith(file)).every(audio=>audio.paused||audio.ended),generic(nativeCountryInfoSound(0,0))),true);
  report.checks.push('Landinfo OK stops current photo narration and restores identical briefing/focus without replaying its briefing audio');

  after=await mark();await button('btnOk').click();await form('TFRMCONTROLSETTINGS');
  assert.equal(await page.evaluate(()=>window.rcsk.state.page),'start-info');
  assert.equal(await page.evaluate(()=>window.menuAudioTracks.every(audio=>audio.paused||audio.ended)),true);
  assert.equal(await button('btnCancel').count(),0);
  await page.keyboard.press('Escape');await form('TFRMADVENTBRIEF');await played(generic(56),after);
  assert.equal(await count(generic(56)),briefCount+1);
  report.checks.push('Accepting briefing stops the menu channel before Startinfo, which has no Cancel button; browser-only Escape adaptation re-enters briefing and plays the original recording once (native Startinfo has no Cancel branch)');

  await button('btnOk').click();await form('TFRMCONTROLSETTINGS');
  await button('btnOk').click();
  await page.waitForFunction(()=>window.rcsk.state.mode==='race'&&window.rcsk.state.track===0);
  assert.equal(await page.evaluate(()=>window.menuAudioTracks.every(audio=>audio.paused||audio.ended)),true);
  report.checks.push('One Netherlands race opening leaves no active menu WAV narration; no full race run');

  await open([],0,{character:2,difficulty:1,country:0,race:0});
  const farewell=character(2,27);
  await page.evaluate(file=>{
    window.menuSlowFiles=[file];window.testExitCalls=[];
    window.close=()=>window.testExitCalls.push({time:performance.now(),mode:window.rcsk.state.mode});
  },farewell);
  await button('btnMainStop').click();await form('TFRMREQUESTER');
  after=await mark();await button('btnOk').click();await played(farewell,after);
  assert.equal(await page.locator('[data-form=TFRMREQUESTER] button').evaluateAll(buttons=>buttons.length>0&&buttons.every(button=>button.disabled)),true);
  assert.equal(await page.evaluate(()=>window.testExitCalls.length),0);
  await page.keyboard.press('Escape');
  assert.equal(await page.evaluate(()=>window.rcsk.state.mode),'quitting');
  assert.equal(await page.evaluate(()=>window.rcsk.state.page),'prompt');
  await page.waitForFunction(()=>window.testExitCalls.length===1);
  await form('TFRMMAIN');
  const farewellEnd=(await events()).slice(after).find(event=>event.event==='ended'&&event.file===farewell);
  const exit=(await page.evaluate(()=>window.testExitCalls))[0];
  assert.ok(farewellEnd&&farewellEnd.time<=exit.time);
  report.checks.push('Quit Yes plays selected character27 farewell to completion before window.close; waiting requester disables controls and ignores Escape; blocked browser close falls back to Main');
  assert.deepEqual(report.errors,[]);
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  report.events=await events().catch(()=>[]);
  await writeFile(directory+'/browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();console.log(JSON.stringify({...report,events:report.events.length,requests:report.requests.length},null,2));
}
