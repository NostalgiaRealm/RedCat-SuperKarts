import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),environment:'Linux Chromium / SwiftShader',checks:[],errors:[]};
await mkdir('evidence/quickrace',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto(origin+'/?skipIntro');
  await page.locator('[data-native=btnQuickRace]').click();
  await page.waitForSelector('[data-form=TFRMSELECTCHAR]');
  await page.locator('[data-native=rdoHard]').click();
  await page.waitForFunction(()=>window.rcsk.state.selection.difficulty===2);
  await page.locator('[data-native=btnOk]').click();
  await page.waitForSelector('[data-form=TFRMSELECTCOUNTRY]');
  await page.locator('[data-native=btnOk]').click();
  await page.waitForSelector('[data-form=TFRMCONTROLSETTINGS]');
  let releaseLoading;
  const loadingBarrier=new Promise(resolve=>releaseLoading=resolve);
  await page.route('**/assets/tracks/etappe0.json',async route=>{await loadingBarrier;await route.continue();},{times:1});
  await page.locator('[data-native=btnOk]').click();
  await page.waitForSelector('[data-form=RACE_LOADING]');
  await page.waitForFunction(()=>[...document.querySelectorAll('[data-form=RACE_LOADING] img')].every(img=>img.complete&&img.naturalWidth>0));
  const loadingImages=await page.locator('[data-form=RACE_LOADING] img').evaluateAll(images=>images.map(img=>img.src));
  assert.match(loadingImages[0],/e00_a_hi/);assert.match(loadingImages[1],/image_01/);
  await page.screenshot({path:'evidence/quickrace/loading.png'});
  releaseLoading();
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  const initial=await page.evaluate(()=>{
    const v=window.rcsk.viewer;
    return {difficulty:v.simulation.difficulty,phase:v.race.phase,elapsed:v.race.elapsedMs,
      frames:[...v.hudMeshes.elements.keys()].filter(id=>id.startsWith('321timer')),
      racerTable:v.simulation.setup.racerTableFile,engineActive:v.audio.engine.active,
      sceneryVoices:v.audio.scenery.length};
  });
  assert.equal(initial.difficulty,2);assert.equal(initial.phase,1);assert.equal(initial.elapsed,0);
  assert.deepEqual(initial.frames,['321timer0','321timer1','321timer2']);
  assert.equal(initial.racerTable,'assets/racer-tables/cars2.dat');assert.equal(initial.engineActive,false);
  assert.ok(initial.sceneryVoices>0);
  await page.waitForFunction(()=>window.rcsk.viewer.simulation.startCamera?.stage===1);
  assert.equal(await page.evaluate(()=>window.rcsk.viewer.simulation.countdownStarted),false);
  assert.equal(await page.evaluate(()=>window.rcsk.viewer.hudMeshes.elements.get('321timer0').mesh.visible),false);
  await page.screenshot({path:'evidence/quickrace/start-camera.png'});
  await page.keyboard.down('ArrowUp');
  await page.waitForFunction(()=>window.rcsk.viewer.simulation.countdown.phase===2);
  assert.equal(await page.evaluate(()=>window.rcsk.viewer.motion.body.forwardSpeed),0);
  await page.screenshot({path:'evidence/quickrace/countdown.png'});
  await page.waitForFunction(()=>window.rcsk.viewer.simulation.movementActive);
  await page.waitForFunction(()=>window.rcsk.viewer.motion.body.forwardSpeed>1);
  await page.keyboard.up('ArrowUp');
  await page.screenshot({path:'evidence/quickrace/green.png'});
  report.checks.push({flow:'Main → character/difficulty → country/mode → controls → race',
    ...initial,originalLoadingImages:true,authoredFlyThroughBefore321:true,countdownPreventsAcceleration:true,greenStartsMotion:true});
  await page.keyboard.press('KeyP');
  await page.waitForFunction(()=>window.rcsk.state.mode==='paused');
  const pausedTick=await page.evaluate(()=>window.rcsk.viewer.clock.tick);
  await page.waitForTimeout(200);
  assert.equal(await page.evaluate(()=>window.rcsk.viewer.clock.tick),pausedTick);
  await page.keyboard.press('ArrowUp');
  await page.waitForFunction(()=>window.rcsk.state.mode==='race');
  await page.keyboard.press('Escape');
  await page.waitForSelector('[data-form=RACE_STOPPEN]');
  await page.screenshot({path:'evidence/quickrace/quit-requester.png'});
  await page.getByRole('button',{name:'Nee',exact:true}).click();
  await page.waitForFunction(()=>window.rcsk.state.mode==='race');
  report.checks.push('Native P pause/release and original race quit requester No resume correctly');
  // A controlled finish-trigger fixture exercises UI/result persistence. This
  // deliberately does not claim that the test drove a complete original race.
  await page.evaluate(()=>{
    const race=window.rcsk.viewer.race;
    race.lapCount=race.lapLimit-1;race.finishArmed=true;
    race.trigger(14,{previous:0,current:1});
  });
  await page.waitForFunction(()=>{
    const gate=window.rcsk.viewer.simulation.lifecycle.resultGate;
    return gate&&gate.startedMs!==0xffffffff;
  });
  await page.waitForTimeout(1600);
  await page.waitForFunction(()=>window.rcsk.viewer.finishFlag.mesh.visible);
  await page.screenshot({path:'evidence/quickrace/finish-flag.png'});
  await page.keyboard.press('Enter',{delay:100});
  await page.waitForSelector('[data-form=TFRMDEBRIEF]');
  await page.screenshot({path:'evidence/quickrace/results.png'});
  await page.getByRole('button',{name:'Opnieuw',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMEDITBOX]');
  await page.locator('[data-element=edtName]').fill('Fixture');
  await page.getByRole('button',{name:'OK',exact:true}).click();
  await page.waitForFunction(()=>window.rcsk.state.mode==='race');
  assert.equal(await page.evaluate(()=>window.rcsk.viewer.race.phase),1);
  const saved=await page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1')));
  assert.equal(saved.boards[0][0].name,'Fixture');
  assert.equal(saved.boards[0][0].difficulty,2);
  report.checks.push('Controlled finish-trigger fixture → original debrief → highscore name → saved score → retry countdown');
  assert.deepEqual(await page.evaluate(()=>window.rcsk.viewer.errors),[]);
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile('evidence/quickrace/report.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();console.log(JSON.stringify(report,null,2));
}
