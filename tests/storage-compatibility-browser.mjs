import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import path from 'node:path';

const fixture=JSON.parse(await readFile(new URL('./fixtures/legacy-storage-v1.json',import.meta.url)));
const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const reportPath=process.env.RCSK_REPORT||'evidence/code-efficiency/storage-browser.json';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required']});
const context=await browser.newContext({viewport:{width:1024,height:768}});
await context.addInitScript(values=>{
  if(!localStorage.getItem('rcsk.race-save.v1'))
    for(const [key,value]of Object.entries(values))localStorage.setItem(key,typeof value==='string'?value:JSON.stringify(value));
  const play=HTMLMediaElement.prototype.play;
  HTMLMediaElement.prototype.play=function(){this.playbackRate=16;return play.call(this);};
},fixture.storage);
const page=await context.newPage();
const report={browser:browser.version(),origin,fixtureVersion:fixture.version,
  scope:'Synthetic released-schema saves in a fresh browser context; real menu loads, writes and reloads. No real user profile or race completion is modified.',checks:[],errors:[]};
page.on('pageerror',error=>report.errors.push(error.message));
page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
const form=name=>page.waitForSelector(`[data-form=${name}]`);
const button=name=>page.locator(`[data-native=${name}]`);
const element=name=>page.locator(`[data-element=${name}]`);
const settings=()=>page.evaluate(()=>window.rcsk.state.settings);
const save=()=>page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1')));
const check=async(name,callback)=>{await callback();report.checks.push(name);};
try{
  await page.goto(origin+'/?skipIntro');await form('TFRMMAIN');
  await check('Existing settings and QuickRace selection load with no migration prompt',async()=>{
    assert.deepEqual(await settings(),fixture.storage['rcsk.settings.v1']);
    assert.deepEqual(await page.evaluate(()=>window.rcsk.state.selection),fixture.storage['rcsk.selection.v1']);
    assert.deepEqual(await save(),fixture.storage['rcsk.race-save.v1']);
  });
  await button('btnAdventure').click();await form('TFRMADVENTUREMAIN');
  await check('Existing selected Adventure profile opens its next briefing directly',async()=>{
    assert.equal(await element('lblPlayerName').textContent(),'Zoë & RedCat');
    await button('btnOk').click();await form('TFRMADVENTBRIEF');
    assert.deepEqual(await page.evaluate(()=>window.rcsk.state.selection),{character:1,difficulty:2,country:5,race:0});
    assert.deepEqual(await save(),fixture.storage['rcsk.race-save.v1']);
    await button('btnBack').click();await form('TFRMMAIN');
    await button('btnAdventure').click();await form('TFRMADVENTUREMAIN');
  });
  await check('Profile navigation keeps the save until OK, which writes the same save schema, including first and last occupied slots',async()=>{
    const name=value=>page.waitForFunction(value=>document.querySelector('[data-element=lblPlayerName]')?.textContent===value,value);
    await button('btnLeft').click();await name('Vroege speler');
    await button('btnRight').click();await name('Zoë & RedCat');
    await button('btnRight').click();await name('Laatste winnaar');
    assert.deepEqual(await save(),fixture.storage['rcsk.race-save.v1']);
    await page.reload();await form('TFRMMAIN');await button('btnAdventure').click();await form('TFRMADVENTUREMAIN');
    assert.equal(await element('lblPlayerName').textContent(),'Zoë & RedCat');
    await button('btnLeft').click();await name('Vroege speler');
    await button('btnOk').click();await form('TFRMADVENTBRIEF');
    assert.deepEqual(await save(),{...fixture.storage['rcsk.race-save.v1'],selectedSlot:0});
    await button('btnBack').click();await form('TFRMMAIN');
    await button('btnAdventure').click();await form('TFRMADVENTUREMAIN');
    assert.equal(await element('lblPlayerName').textContent(),'Vroege speler');
    await button('btnRight').click();await name('Zoë & RedCat');
    await button('btnOk').click();await form('TFRMADVENTBRIEF');
    assert.deepEqual(await save(),fixture.storage['rcsk.race-save.v1']);
    await button('btnBack').click();await form('TFRMMAIN');
    await button('btnAdventure').click();await form('TFRMADVENTUREMAIN');
  });
  await button('btnBack').click();await form('TFRMMAIN');await button('btnHighscore').click();await form('TFRMHIGHSCORE');
  await check('All six countries still show their existing five high-score names',async()=>{
    for(let country=0;country<6;country++){
      if(country){await button('btnRight').click();await page.waitForFunction(name=>document.querySelector('[data-element=lblName1]')?.textContent===name,`Speler ${country}:0`);}
      for(let row=1;row<=5;row++)assert.equal(await element('lblName'+row).textContent(),`Speler ${country}:${row-1}`);
    }
  });
  await button('btnOk').click();await form('TFRMMAIN');await button('btnMainOptions').click();await form('TFRMOPTIONS');
  await check('Existing custom volume, keys, display and additional settings survive ordinary OK and reload',async()=>{
    assert.equal(await element('sldMusicVolume').inputValue(),'37');
    assert.equal(await element('sldEffectVolume').inputValue(),'64');
    await button('btnControlsAdvanced').click();await form('TFRMCONTROLSETTINGS');
    assert.equal(await element('lblKEY_ACCELERATE').textContent(),'w');
    assert.equal(await element('lblKEY_USEBONUS').textContent(),'');
    await button('btnCancel').click();await form('TFRMOPTIONS');
    await button('btnOk').click();await form('TFRMMAIN');
    await page.reload();await form('TFRMMAIN');
    assert.deepEqual(await settings(),fixture.storage['rcsk.settings.v1']);
    assert.deepEqual(await save(),fixture.storage['rcsk.race-save.v1']);
    const stored=await page.evaluate(()=>Object.fromEntries(Object.entries(localStorage)));
    for(const [key,value]of Object.entries(fixture.storage))
      assert.deepEqual(typeof value==='string'?stored[key]:JSON.parse(stored[key]),value,key);
  });
  assert.deepEqual(report.errors,[]);
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await mkdir(path.dirname(reportPath),{recursive:true});
  await writeFile(reportPath,JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify(report,null,2));
}
