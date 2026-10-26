import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {readFile,writeFile,mkdir} from 'node:fs/promises';
import {createNativeAdventureProfile,nativeAdventureConfiguration} from '../source/simulation/native-adventure.js';
import {nativeCountryInfoSound} from '../source/menu-sound-events.js';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const config=JSON.parse(await readFile('public/assets/config.json'));
const sequence=nativeAdventureConfiguration(config).sequence;
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),scope:'Actual original menu WAV decoding and playing events, at8x transport speed to shorten the check; no claim of listening or native sound-card capture.',checks:[],errors:[]};
const context=await browser.newContext({viewport:{width:1024,height:768}});
await context.addInitScript(()=>{
  window.soundPlays=[];
  const play=HTMLMediaElement.prototype.play;
  HTMLMediaElement.prototype.play=function(){
    this.playbackRate=8;
    this.addEventListener('playing',()=>window.soundPlays.push({
      file:this.currentSrc.split('/').at(-1),duration:this.duration,readyState:this.readyState,
    }),{once:true});
    return play.call(this);
  };
});
const page=await context.newPage();
page.on('pageerror',error=>report.errors.push(error.message));
page.on('response',response=>{if(response.status()>=400)report.errors.push(response.status()+' '+response.url());});
const button=name=>page.locator(`[data-native=${name}]`);
const form=name=>page.waitForSelector(`[data-form=${name}]`);
async function expectPlayed(file,action){
  const first=await page.evaluate(()=>window.soundPlays.length);
  await action();
  await page.waitForFunction(({first,file})=>window.soundPlays.slice(first).some(x=>x.file===file&&x.duration>0&&x.readyState>=2),{first,file:file.toLowerCase()});
  report.checks.push(file.toLowerCase());
}
const generic=index=>config['ini/soundset.dat'].generic_samples[index];
const bank=character=>config['ini/'+['rc','wk','br','mx'][character]+'_snd.dat'].sample_set;
try{
  await page.goto(origin+'/?skipIntro');
  for(let character=0;character<4;character++){
    await page.evaluate(character=>localStorage.setItem('rcsk.selection.v1',JSON.stringify({character,difficulty:1,country:0,race:0})),character);
    await page.reload();await form('TFRMMAIN');
    await expectPlayed(bank(character)[14],()=>button('btnQuickRace').click());
    await form('TFRMSELECTCHAR');await button('btnOk').click();await form('TFRMSELECTCOUNTRY');
    for(const [mode,name] of ['rdoCountry','rdoTime','rdoItem'].entries())
      await expectPlayed(bank(character)[10+mode],()=>button(name).click());
    await expectPlayed(bank(character)[5],()=>button('btnRight').click());
    await expectPlayed(bank(character)[4],()=>button('btnLeft').click());
  }
  await page.goto(origin+'/?skipIntro');await button('btnHighscore').click();await form('TFRMHIGHSCORE');
  await expectPlayed(generic(47),()=>button('btnRight').click());
  await expectPlayed(generic(48),()=>button('btnLeft').click());
  for(let country=0;country<6;country++){
    const profile=createNativeAdventureProfile('Geluid',{slot:0});
    profile.adventure=sequence.find(entry=>entry.country===country).index;
    await page.evaluate(profile=>localStorage.setItem('rcsk.race-save.v1',JSON.stringify({profiles:[profile],selectedSlot:0})),profile);
    await page.goto(origin+'/?skipIntro');
    await button('btnAdventure').click();await form('TFRMADVENTUREMAIN');
    await button('btnOk').click();await form('TFRMADVENTBRIEF');
    await expectPlayed(generic(nativeCountryInfoSound(country)),()=>button('btnOverview').click());
    await form('TFRMLANDINFO');
    for(let photo=0;photo<4;photo++)
      await expectPlayed(generic(nativeCountryInfoSound(country,photo)),()=>page.locator(`[data-element=imgPhoto${photo+1}]`).click());
  }
  await page.goto(origin+'/?skipIntro');
  await button('btnMainOptions').click();await form('TFRMOPTIONS');
  await button('btnControlsAdvanced').click();await form('TFRMCONTROLSETTINGS');
  await page.locator('[data-element=lblKEY_ACCELERATE]').click();
  await expectPlayed(generic(110),()=>page.keyboard.press('Digit1'));
  assert.equal(await page.evaluate(()=>window.rcsk.state.settings.bindings.accelerate),'ArrowUp');
  assert.equal(await page.locator('[data-element=lblKEY_ACCELERATE]').textContent(),'');
  assert.match(await page.locator('[data-element=imgKEY_ACCELERATE]').getAttribute('src'),/toetskl0/);
  await page.keyboard.down('KeyW');
  assert.equal(await page.evaluate(()=>window.rcsk.state.settings.bindings.accelerate),'ArrowUp');
  await page.keyboard.up('KeyW');
  assert.equal(await page.evaluate(()=>window.rcsk.state.settings.bindings.accelerate),'ArrowUp');
  await button('btnOk').click();
  await form('TFRMOPTIONS');
  assert.equal(await page.evaluate(()=>window.rcsk.state.settings.bindings.accelerate),'KeyW');
  assert.equal(report.checks.length,57);
  assert.deepEqual(report.errors,[]);
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await mkdir('evidence/audio',{recursive:true});
  await writeFile('evidence/audio/menu-playback.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify(report,null,2));
}
