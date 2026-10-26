import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
import {createNativeAdventureProfile} from '../source/simulation/native-adventure.js';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),scope:'Original menu/progression integration with controlled native finish-trigger fixtures; not a driven full-campaign parity claim.',checks:[],errors:[]};
await mkdir('evidence/adventure',{recursive:true});
const form=(page,name)=>page.waitForSelector(`[data-form=${name}]`);
const control=(page,name)=>page.locator(`[data-native=${name}]`);
const save=page=>page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1')));
async function open(seed){
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  if(seed)await page.addInitScript(value=>localStorage.setItem('rcsk.race-save.v1',JSON.stringify(value)),seed);
  await page.goto(origin+'/?skipIntro');
  return page;
}
async function startAdventureRace(page){
  await control(page,'btnAdventure').click();await form(page,'TFRMADVENTUREMAIN');
  await control(page,'btnOk').click();await form(page,'TFRMADVENTBRIEF');
  await control(page,'btnOk').click();await form(page,'TFRMCONTROLSETTINGS');
  await control(page,'btnOk').click();
  await page.waitForFunction(()=>window.rcsk.state.page==='driving',null,{timeout:60000});
  await page.waitForFunction(()=>window.rcsk.viewer.simulation.movementActive);
}
async function controlledFinish(page){
  await page.evaluate(()=>{
    const race=window.rcsk.viewer.race;
    race.lapCount=race.lapLimit-1;race.finishArmed=true;
    race.trigger(14,{previous:0,current:1});
  });
  await page.waitForFunction(()=>window.rcsk.viewer.simulation.lifecycle.resultGate?.startedMs!==0xffffffff);
  await page.waitForTimeout(1650);await page.keyboard.press('Enter',{delay:100});
  await form(page,'TFRMDEBRIEF');
}
function seededProfile(index){
  const profile=createNativeAdventureProfile('Avontuur',{slot:0});
  profile.difficulty=0;profile.adventure=index;
  return {profiles:[profile,...Array(29).fill(null)],selectedSlot:0,locks:[false,false,true,true,true,true]};
}
try{
  const page=await open();
  await control(page,'btnAdventure').click();await form(page,'TFRMADVENTUREMAIN');
  assert.equal(await control(page,'btnOk').isDisabled(),true);
  assert.equal(await control(page,'btnDeletePlayer').isDisabled(),true);
  await control(page,'btnNewPlayer').click();await form(page,'TFRMEDITBOX');
  assert.equal(await control(page,'btnOk').isDisabled(),true);
  await control(page,'btnCancel').click();await form(page,'TFRMADVENTUREMAIN');
  await control(page,'btnNewPlayer').click();
  await page.locator('[data-element=edtName]').fill('Kat');
  await control(page,'btnOk').click();await form(page,'TFRMSELECTCHAR');
  let stored=await save(page);
  assert.equal(stored.profiles[0].name,'Kat');assert.equal(stored.profiles[0].difficulty,1);
  assert.equal(await control(page,'btnPrevious').isDisabled(),true);
  assert.match(await control(page,'btnPrevious').evaluate(el=>getComputedStyle(el).backgroundImage),/mn_0210d\.png/);
  await control(page,'btnNext').click();await page.waitForFunction(()=>window.rcsk.state.selection.character===1);await control(page,'rdoHard').click();
  await control(page,'btnOk').click();await form(page,'TFRMADVENTBRIEF');
  stored=await save(page);assert.equal(stored.profiles[0].character,1);assert.equal(stored.profiles[0].difficulty,2);
  assert.match(await page.locator('[data-element=lblBriefing]').innerText(),/^Welkom in Nederland/);
  assert.match(await page.locator('[data-element=img0NORMALRACE]').getAttribute('src'),/mn_0911b\.png$/);
  await page.screenshot({path:'evidence/adventure/new-profile-briefing.png'});
  await control(page,'btnBack').click();await form(page,'TFRMMAIN');
  await control(page,'btnAdventure').click();await control(page,'btnNewPlayer').click();
  await page.locator('[data-element=edtName]').fill('Tweede');await control(page,'btnOk').click();
  await form(page,'TFRMSELECTCHAR');await control(page,'btnBack').click();await form(page,'TFRMMAIN');
  stored=await save(page);assert.equal(stored.profiles[1].name,'Tweede');
  await control(page,'btnAdventure').click();await form(page,'TFRMADVENTUREMAIN');
  assert.equal(await control(page,'btnRight').isDisabled(),true);
  await control(page,'btnLeft').click();assert.equal(await control(page,'btnLeft').isDisabled(),true);
  await control(page,'btnRight').click();await control(page,'btnDeletePlayer').click();await form(page,'TFRMREQUESTER');
  await control(page,'btnCancel').click();assert.equal((await save(page)).profiles[1].name,'Tweede');
  await control(page,'btnDeletePlayer').click();await form(page,'TFRMREQUESTER');await control(page,'btnOk').click();await form(page,'TFRMADVENTUREMAIN');
  stored=await save(page);assert.equal(stored.profiles[1],null);assert.equal(stored.selectedSlot,0);
  await page.reload();await form(page,'TFRMMAIN');await control(page,'btnAdventure').click();
  assert.equal(await page.locator('[data-element=lblPlayerName]').innerText(),'Kat');
  await control(page,'btnOk').click();await form(page,'TFRMADVENTBRIEF');
  await control(page,'btnBack').click();await control(page,'btnQuickRace').click();
  await control(page,'btnOk').click();await form(page,'TFRMSELECTCOUNTRY');
  await control(page,'btnRight').click();await page.waitForFunction(()=>window.rcsk.state.selection.country===1);
  await control(page,'btnRight').click();await page.waitForFunction(()=>window.rcsk.state.selection.country===2);
  assert.match(await page.locator('[data-element=imgSelectedCountry]').getAttribute('src'),/mn_0304h\.png$/);
  await control(page,'btnOk').click();await form(page,'TFRMREQUESTER');
  assert.match(await page.locator('[data-element=lblQuit]').innerText(),/Groot-Brittanië/);
  report.checks.push('Name cancellation, immediate new-profile save, character/difficulty commit, preserved Back, bounded profile carousel, delete cancellation/confirmation, reload and QuickRace lock artwork/prompt');
  await page.close();

  const normalSeed=seededProfile(5);
  for(let c=0;c<5;c++)normalSeed.profiles[0].matrix[c][0]=1;
  const normal=await open(normalSeed);await startAdventureRace(normal);
  assert.equal(await normal.evaluate(()=>window.rcsk.viewer.simulation.setup.opponents.length),4);
  await controlledFinish(normal);await control(normal,'btnOk').click();await form(normal,'TFRMREQUESTER');
  assert.match(await normal.locator('[data-element=lblQuit]').innerText(),/volgende race/);
  await control(normal,'btnOk').click();await normal.waitForFunction(()=>document.querySelector('[data-element=lblQuit]')?.textContent.includes('Spanje'));
  assert.match(await normal.locator('[data-element=lblQuit]').innerText(),/Spanje/);
  await normal.screenshot({path:'evidence/adventure/country-unlocked.png'});
  await control(normal,'btnOk').click();await form(normal,'TFRMEDITBOX');await control(normal,'btnCancel').click();
  await form(normal,'TFRMADVENTBRIEF');
  stored=await save(normal);assert.equal(stored.profiles[0].adventure,6);assert.equal(stored.locks[4],false);
  assert.equal(await normal.locator('[data-element=lblCountry]').innerText(),'Duitsland');
  assert.equal(await normal.locator('[data-element=lblType]').innerText(),'Tijdrace');
  assert.match(await normal.locator('[data-element=img5NORMALRACE]').getAttribute('src'),/mn_0911a\.png$/);
  report.checks.push('Controlled sixth Landenrace finish → qualification → Spain unlock → highscore cancellation → next original Tijdrace briefing with saved matrix');
  await normal.close();

  const finalSeed=seededProfile(23);
  finalSeed.profiles[0].character=3;
  finalSeed.profiles[0].matrix=Array.from({length:6},(_,c)=>[1,1,1,c===0?0:1,0]);
  const final=await open(finalSeed);await startAdventureRace(final);
  assert.equal(await final.evaluate(()=>window.rcsk.viewer.simulation.setup.opponents.length),1);
  await controlledFinish(final);await control(final,'btnOk').click();
  await final.waitForFunction(()=>window.rcsk.state.mode==='reward');
  assert.match(await final.locator('#movie').getAttribute('src'),/ster5\.mp4$/);
  assert.equal(await final.locator('#skip-movie').isVisible(),false);
  await final.keyboard.press('Escape');assert.equal(await final.evaluate(()=>window.rcsk.state.mode),'reward');
  await final.waitForFunction(()=>document.getElementById('movie').duration>0);
  await final.screenshot({path:'evidence/adventure/final-country-star.png'});
  await final.evaluate(()=>{const v=document.getElementById('movie');v.currentTime=v.duration-.05;});
  await form(final,'TFRMREQUESTER');await control(final,'btnOk').click();
  await form(final,'TFRMEDITBOX');await final.locator('[data-element=edtName]').fill('Kampioen');
  await control(final,'btnOk').click();await final.waitForFunction(()=>window.rcsk.state.mode==='reward');
  assert.match(await final.locator('#movie').getAttribute('src'),/mxwin\.mp4$/);
  await final.waitForFunction(()=>document.getElementById('movie').duration>0);
  await final.evaluate(()=>{const v=document.getElementById('movie');v.currentTime=v.duration-.05;});
  await form(final,'TFRMMAIN');
  stored=await save(final);assert.equal(stored.profiles[0].completed,true);assert.equal(stored.profiles[0].name,'Kampioen');
  assert.equal(stored.profiles[0].adventure,0);assert.equal(stored.locks[5],false);
  await control(final,'btnAdventure').click();await control(final,'btnOk').click();await form(final,'TFRMADVENTBRIEF');
  stored=await save(final);assert.equal(stored.profiles[0].completed,false);
  assert.equal(stored.profiles[0].character,3);assert.equal(stored.profiles[0].difficulty,0);
  assert.ok(stored.profiles[0].matrix.every(row=>row.every(cell=>cell===0)));
  report.checks.push('Controlled final duel → original Netherlands star movie without key skip → Italy unlock → profile-named highscore → Max win movie → completed save → replay reset preserving identity/difficulty');
  await final.close();
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{await writeFile('evidence/adventure/report.json',JSON.stringify(report,null,2)+'\n');await browser.close();console.log(JSON.stringify(report,null,2));}
