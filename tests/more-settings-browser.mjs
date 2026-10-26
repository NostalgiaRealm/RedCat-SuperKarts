import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const report={scope:'New settings navigation, real controls, nested drafts and persistent unlock; no native-equivalence claim for added features.',checks:[],errors:[]};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,args:['--autoplay-policy=no-user-gesture-required']});
const page=await browser.newPage({viewport:{width:1024,height:768}});
await page.addInitScript(()=>{const play=HTMLMediaElement.prototype.play;HTMLMediaElement.prototype.play=function(){this.playbackRate=8;return play.call(this);};});
page.on('pageerror',e=>report.errors.push(e.message));
page.on('console',e=>{if(e.type()==='error')report.errors.push(e.text());});
page.on('response',r=>{if(r.status()>=400)report.errors.push(r.status()+' '+r.url());});
const native=name=>page.locator(`[data-native=${name}]`);
const form=name=>page.waitForSelector(`[data-form=${name}]`);
const settings=()=>page.evaluate(()=>window.rcsk.state.settings);
const flight=()=>page.locator('#free-flight').getAttribute('aria-pressed').then(v=>v==='true');
const setFlight=async value=>{if(await flight()!==value)await page.locator('#free-flight').click();};
const open=async()=>{await native('btnMainOptions').click();await form('TFRMOPTIONS');await native('btnMoreSettings').click();await page.waitForSelector('#msaa-enabled');};
const moreBack=async()=>{await page.getByRole('button',{name:'Terug',exact:true}).click();await form('TFRMOPTIONS');};
const moreOk=async()=>{await page.getByRole('button',{name:'OK',exact:true}).click();await form('TFRMOPTIONS');};
const check=async(name,fn)=>{await fn();report.checks.push(name);};
try{
  await mkdir('evidence/ui',{recursive:true});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');await form('TFRMMAIN');
  await native('btnMainOptions').click();await form('TFRMOPTIONS');
  await check('Meer instellingen sits below both sound sliders with original artwork',async()=>{
    const [more,effect]=await Promise.all([native('btnMoreSettings').boundingBox(),page.locator('[data-element=sldEffectVolume]').boundingBox()]);
    assert.ok(more.y>=effect.y+effect.height);assert.match(await native('btnMoreSettings').evaluate(el=>getComputedStyle(el).backgroundImage),/mn_0004a/);
    await page.screenshot({path:'evidence/ui/more-settings-main-landscape.png'});
  });
  await native('btnMoreSettings').click();
  const original=await settings();
  await check('Defaults are MSAA off with 4× selected and free flight off',async()=>{
    assert.equal(await page.locator('h1').textContent(),'Meer instellingen');
    assert.equal(await page.locator('#msaa-enabled').isChecked(),false);assert.equal(await page.locator('#msaa-samples').inputValue(),'4');
    assert.equal(await page.locator('#msaa-samples').isDisabled(),true);assert.equal(await flight(),false);
  });
  await page.locator('#msaa-enabled').check();await page.locator('#msaa-samples').selectOption('8');await setFlight(true);
  await check('Changing extra settings does not mutate committed settings',async()=>assert.deepEqual(await settings(),original));
  await moreBack();await native('btnMoreSettings').click();
  await check('Extra-page Back discards its local draft',async()=>{
    assert.equal(await page.locator('#msaa-enabled').isChecked(),false);assert.equal(await page.locator('#msaa-samples').inputValue(),'4');assert.equal(await flight(),false);
  });
  await page.locator('#msaa-enabled').check();await page.locator('#msaa-samples').selectOption('2');await setFlight(true);await moreOk();
  await native('btnMoreSettings').click();
  await check('Extra-page OK retains a nested draft until outer OK',async()=>{assert.equal(await page.locator('#msaa-samples').inputValue(),'2');assert.deepEqual(await settings(),original);});
  await page.keyboard.press('Escape');await form('TFRMOPTIONS');await native('btnBack').click();await form('TFRMMAIN');
  await check('Outer Back cancels accepted extra-page changes',async()=>assert.deepEqual(await settings(),original));
  await open();await page.locator('#msaa-enabled').check();await page.locator('#msaa-samples').selectOption('8');await setFlight(true);await page.locator('#touch').selectOption('on');await moreOk();await native('btnOk').click();await form('TFRMMAIN');
  await page.reload();await form('TFRMMAIN');
  await check('Outer OK persists MSAA and flight across reload',async()=>{const s=await settings();assert.equal(s.msaaEnabled,true);assert.equal(s.msaaSamples,8);assert.equal(s.freeFlight,true);});
  const previous=await page.evaluate(async()=>{
    const {readRaceSave,writeRaceSave}=await import('/source/race-save.js');const save=readRaceSave();
    const {createNativeAdventureProfile}=await import('/source/simulation/native-adventure.js');
    save.profiles[4]=createNativeAdventureProfile('Bewaren',{slot:4});save.profiles[4].matrix[1][1]=1;save.selectedSlot=4;
    save.boards[2][0]={name:'Beste',character:2,totalRaceMs:123456,bestLapMs:23456,difficulty:2};save.bestTimes.lap_record_e2=23456;
    save.locks=[false,true,true,true,true,true];writeRaceSave(save);return save;
  });
  await page.reload();await form('TFRMMAIN');await open();
  await page.locator('#unlock-all').click();
  await check('Unlock gives explicit saved confirmation and keeps all other save data',async()=>{
    assert.match(await page.locator('#unlock-status').textContent(),/ontgrendeld en opgeslagen/);
    assert.deepEqual(await page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1'))),{...previous,locks:Array(6).fill(false)});
  });
  await moreBack();await native('btnBack').click();await form('TFRMMAIN');await page.reload();await form('TFRMMAIN');
  await check('Unlock survives both Back actions and reload',async()=>assert.deepEqual(await page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1'))),{...previous,locks:Array(6).fill(false)}));
  await open();await page.evaluate(()=>document.getElementById('screen').scrollTop=0);await page.screenshot({path:'evidence/ui/more-settings-landscape-top.png'});
  await page.getByRole('button',{name:'OK',exact:true}).scrollIntoViewIfNeeded();await page.screenshot({path:'evidence/ui/more-settings-landscape-footer.png'});await moreBack();await native('btnBack').click();await form('TFRMMAIN');
  await page.setViewportSize({width:390,height:844});await native('btnMainOptions').click();await form('TFRMOPTIONS');
  await native('btnMoreSettings').scrollIntoViewIfNeeded();await page.screenshot({path:'evidence/ui/more-settings-main-portrait.png'});
  await native('btnMoreSettings').click();
  await page.evaluate(()=>document.getElementById('screen').scrollTop=0);await page.screenshot({path:'evidence/ui/more-settings-portrait-top.png'});
  await check('Portrait controls fit the screen and remain usable',async()=>{
    assert.equal(await page.evaluate(()=>document.documentElement.scrollWidth>innerWidth),false);
    for(const selector of ['#msaa-enabled','#msaa-samples','#free-flight','#unlock-all']){
      await page.locator(selector).scrollIntoViewIfNeeded();const bounds=await page.locator(selector).boundingBox();assert.ok(bounds.x>=0&&bounds.x+bounds.width<=390);
    }
    await page.getByRole('button',{name:'OK',exact:true}).scrollIntoViewIfNeeded();
    for(const name of ['Terug','Volledig scherm','OK'])assert.equal(await page.getByRole('button',{name,exact:true}).isVisible(),true);
    const footer=await page.screenshot({path:'evidence/ui/more-settings-portrait-footer.png'});
    const bounds=await page.getByRole('button',{name:'OK',exact:true}).boundingBox();
    const orange=await page.evaluate(async({png,bounds})=>{
      const image=new Image();image.src='data:image/png;base64,'+png;await image.decode();
      const canvas=document.createElement('canvas');canvas.width=image.width;canvas.height=image.height;
      const context=canvas.getContext('2d');context.drawImage(image,0,0);
      const pixels=context.getImageData(Math.ceil(bounds.x),Math.ceil(bounds.y),Math.floor(bounds.width)-1,Math.floor(bounds.height)-1).data;
      let count=0;for(let i=0;i<pixels.length;i+=4)if(pixels[i]>180&&pixels[i+1]>60&&pixels[i+1]<210&&pixels[i+2]<70)count++;return count;
    },{png:footer.toString('base64'),bounds});
    assert.ok(orange>500,`OK must visibly paint its orange artwork (${orange} pixels)`);
  });
  await moreBack();await native('btnAdvanced').click();await form('TFRMDISPLAYSETTINGS');
  await check('Original advanced display controls remain accessible separately',async()=>{
    assert.equal(await native('btnBrowserSettings').count(),0);assert.equal(await native('rdoBrightnessLight').isVisible(),true);
  });
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving'&&window.rcsk.viewer.simulation.freeFlightActive,null,{timeout:60000});
  await check('Saved flight option activates the real race UI with touch elevation controls',async()=>{
    assert.equal(await page.locator('#flight-controls').isVisible(),true);
    assert.equal(await page.locator('#flight-touch').getByRole('button',{name:'Omhoog'}).isVisible(),true);
    assert.equal(await page.locator('#flight-touch').getByRole('button',{name:'Omlaag'}).isVisible(),true);
    await page.screenshot({path:'evidence/ui/free-flight-controls-portrait.png'});
  });
  await page.locator('#flight-controls').getByRole('button',{name:'Instellingen',exact:true}).click();await form('TFRMOPTIONS');
  await native('btnMoreSettings').click();
  await check('In-race MSAA status identifies actual hardware fallback',async()=>{
    const status=await page.evaluate(()=>window.rcsk.viewer.msaaStatus);assert.equal(status.requestedSamples,8);
    if(status.actualSamples!==8&&status.actualSamples>0)assert.match(await page.locator('#msaa-status').textContent(),new RegExp(status.actualSamples+'× wordt gebruikt'));
  });
  await setFlight(false);await moreBack();await native('btnBack').click();
  await page.waitForFunction(()=>window.rcsk.state.page==='driving');
  await check('Cancel from in-race settings retains active flight',async()=>assert.equal(await page.evaluate(()=>window.rcsk.viewer.simulation.freeFlightActive),true));
  await page.locator('#flight-controls').getByRole('button',{name:'Instellingen',exact:true}).click();await form('TFRMOPTIONS');await native('btnMoreSettings').click();
  await setFlight(false);await moreOk();await native('btnOk').click();await page.waitForFunction(()=>window.rcsk.state.page==='driving'&&!window.rcsk.viewer.simulation.freeFlightActive);
  await check('In-race OK applies the flight disable and saves it',async()=>{assert.equal((await settings()).freeFlight,false);assert.equal(await page.locator('#flight-controls').isVisible(),false);});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');await form('TFRMMAIN');await open();await setFlight(true);await moreOk();await native('btnOk').click();await form('TFRMMAIN');
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');await page.waitForFunction(()=>window.rcsk?.state.page==='driving'&&window.rcsk.viewer.simulation.freeFlightActive,null,{timeout:60000});
  await page.locator('#flight-controls').getByRole('button',{name:'Stop vliegen'}).click();
  await page.waitForFunction(()=>!window.rcsk.viewer.simulation.freeFlightActive);
  await check('Return-to-track button exits flight and saves its disabled state',async()=>{
    assert.equal((await settings()).freeFlight,false);assert.equal(await page.locator('#flight-controls').isVisible(),false);
    assert.equal(await page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.settings.v1')).freeFlight),false);
  });
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(e){report.status='failed';report.failure=String(e.stack||e);process.exitCode=1;}
finally{await writeFile('evidence/ui/more-settings-browser.json',JSON.stringify(report,null,2)+'\n');await browser.close();console.log(JSON.stringify(report,null,2));}
