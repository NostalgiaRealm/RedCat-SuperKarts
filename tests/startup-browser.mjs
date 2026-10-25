import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const directory='evidence/startup-blue-screen';
await mkdir(directory,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=user-gesture-required']});
const report={browser:browser.version(),scope:'Plain source-server startup with a single explicitly rejected autoplay attempt, then real Start click/playback, original menu artwork and one actual race render. The rejection fixture makes the blocked-autoplay branch reproducible on Chromium builds that allow autoplay under automation.',checks:[],errors:[],requests:[]};
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  await page.addInitScript(()=>{
    const play=HTMLMediaElement.prototype.play;let firstIntroAttempt=true;
    HTMLMediaElement.prototype.play=function(...args){
      if(this.id==='movie'&&firstIntroAttempt){
        firstIntroAttempt=false;
        return Promise.reject(new DOMException('Autoplay blocked by startup test fixture','NotAllowedError'));
      }
      return play.apply(this,args);
    };
  });
  page.on('pageerror',error=>report.errors.push(String(error.stack||error)));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('requestfailed',request=>{
    if(request.failure()?.errorText!=='net::ERR_ABORTED')report.requests.push({url:request.url(),failure:request.failure()});
  });
  page.on('response',response=>{if(response.status()>=400)report.requests.push({url:response.url(),status:response.status()});});
  await page.goto(origin+'/');
  await page.waitForFunction(()=>window.rcsk?.state.page==='intro'&&document.getElementById('movie').readyState>=2);
  assert.equal(await page.locator('#intro').isVisible(),true);
  await page.waitForSelector('#message:not([hidden])');
  await page.screenshot({path:directory+'/intro.png'});
  report.checks.push('Plain root URL loads the original intro and Start despite blocked autoplay');
  assert.equal(await page.locator('#message').evaluate(element=>getComputedStyle(element).pointerEvents),'none');
  await page.locator('#play-movie').click({timeout:3000});
  await page.waitForFunction(()=>!document.getElementById('movie').paused&&document.getElementById('movie').currentTime>0);
  report.checks.push('Real Start click works while autoplay notice is visible');
  await page.keyboard.press('Enter');await page.waitForSelector('[data-form=TFRMMAIN]');
  await page.waitForLoadState('networkidle');
  const menu=await page.evaluate(async()=>{
    await document.fonts.ready;
    const images=[...document.querySelectorAll('#screen img')];
    await Promise.all(images.map(image=>image.decode()));
    const backgrounds=[...document.querySelectorAll('#screen button')].map(button=>getComputedStyle(button).backgroundImage);
    await Promise.all(backgrounds.map(background=>new Promise((resolve,reject)=>{
      const image=new Image();image.onload=resolve;image.onerror=reject;
      image.src=background.match(/url\(["']?(.*?)["']?\)/)[1];
    })));
    return{images:images.length,allReady:images.every(image=>image.naturalWidth>0),buttons:backgrounds.length};
  });
  assert.ok(menu.allReady&&menu.images>=3&&menu.buttons>=6);
  await page.screenshot({path:directory+'/menu.png'});
  report.checks.push('Skipping intro reaches the original menu with decoded imagery and button artwork');
  await page.goto(origin+'/?skipIntro');await page.waitForSelector('[data-form=TFRMMAIN]');
  report.checks.push('Direct main-menu URL loads');
  await page.goto(origin+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving'&&window.rcsk.viewer.clock.tick>2,null,{timeout:60000});
  await page.waitForFunction(()=>rcsk.viewer.renderStats.hud?.glyphs>0);
  report.race=await page.evaluate(()=>({triangles:rcsk.viewer.renderStats.world.triangles,
    presentationTriangles:rcsk.viewer.renderStats.presentation.triangles,hud:rcsk.viewer.renderStats.hud,errors:rcsk.viewer.errors}));
  assert.ok(report.race.triangles>1000);assert.deepEqual(report.race.errors,[]);
  assert.equal(report.race.presentationTriangles,1);assert.ok(report.race.hud.glyphs>0);
  await page.screenshot({path:directory+'/race.png'});
  report.checks.push('Three.js, OrbitControls and the actual race render successfully');
  assert.deepEqual(report.errors,[]);assert.deepEqual(report.requests,[]);
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);process.exitCode=1;}
finally{
  await writeFile(directory+'/browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();console.log(JSON.stringify(report,null,2));
}
