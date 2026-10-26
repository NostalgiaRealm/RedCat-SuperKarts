import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const introOnly=process.argv.includes('--intro-only');
const directory=introOnly?'evidence/intro-autoplay':'evidence/startup-blue-screen';
await mkdir(directory,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),scope:'Source intro autoplay, explicit audible/muted policy-rejection fixtures, real mouse/touch/keyboard audio activation, natural finish and skipping. The --intro-only run excludes race rendering.',checks:[],errors:[],requests:[]};
async function blockAutoplay(page,count=1){
  await page.addInitScript(count=>{
    const play=HTMLMediaElement.prototype.play;let attempts=0;
    HTMLMediaElement.prototype.play=function(...args){
      if(this.id==='movie'&&attempts++<count)return Promise.reject(new DOMException('Autoplay blocked by startup test fixture','NotAllowedError'));
      return play.apply(this,args);
    };
  },count);
}
function observe(page){
  page.on('pageerror',error=>report.errors.push(String(error.stack||error)));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('requestfailed',request=>{
    if(request.failure()?.errorText!=='net::ERR_ABORTED')report.requests.push({url:request.url(),failure:request.failure()});
  });
  page.on('response',response=>{if(response.status()>=400)report.requests.push({url:response.url(),status:response.status()});});
}
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  await blockAutoplay(page);observe(page);
  await page.goto(origin+'/');
  await page.waitForFunction(()=>window.rcsk?.state.page==='intro'&&document.getElementById('movie').readyState>=2);
  assert.equal(await page.locator('#intro').isVisible(),true);
  await page.waitForFunction(()=>!document.getElementById('movie').paused&&document.getElementById('movie').currentTime>0);
  assert.equal(await page.locator('#movie').evaluate(video=>video.muted),true);
  assert.equal(await page.locator('#play-movie').count(),0);
  assert.equal(await page.locator('#message').isVisible(),false);
  const audio=page.locator('#movie-audio');assert.equal(await audio.isVisible(),true);
  const bounds=await audio.boundingBox();assert.ok(bounds.x<40&&bounds.y>650);
  await page.screenshot({path:directory+'/intro.png'});
  report.checks.push('Blocked audible autoplay retries muted immediately, without a Start button or notice; audio action sits bottom left');
  const time=await page.locator('#movie').evaluate(video=>video.currentTime);
  await audio.click({timeout:3000});
  await page.waitForFunction(()=>!document.getElementById('movie').paused&&!document.getElementById('movie').muted&&document.getElementById('movie-audio').hidden);
  await page.waitForFunction(()=>document.fullscreenElement===document.documentElement);
  assert.equal(await page.evaluate(()=>rcsk.state.page),'intro');
  assert.ok(await page.locator('#movie').evaluate(video=>video.currentTime)>=time);
  report.checks.push('Mouse enables audio and fullscreen without restarting or skipping the movie');
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
  for(const [name,viewport,method,blocked]of [
    ['portrait-enter',{width:390,height:844},'Enter',1],
    ['landscape-space',{width:844,height:390},'Space',1],
    ['strict-touch',{width:390,height:844},'touch',2],
  ]){
    const other=await browser.newPage({viewport,hasTouch:method==='touch'});observe(other);await blockAutoplay(other,blocked);
    await other.goto(origin+'/');await other.waitForSelector('#movie-audio:not([hidden])');
    if(blocked===1)await other.waitForFunction(()=>!document.getElementById('movie').paused&&document.getElementById('movie').currentTime>0);
    const control=other.locator('#movie-audio'),box=await control.boundingBox();
    assert.ok(box.x>=0&&box.x<40&&box.x+box.width<=viewport.width&&box.y>viewport.height/2&&box.y+box.height<=viewport.height);
    await other.screenshot({path:directory+'/'+name+'.png'});
    const before=await other.locator('#movie').evaluate(video=>video.currentTime);
    if(method==='touch')await control.tap();else{await control.focus();await other.keyboard.press(method);}
    await other.waitForFunction(()=>!document.getElementById('movie').paused&&!document.getElementById('movie').muted&&document.getElementById('movie-audio').hidden);
    await other.waitForFunction(()=>document.fullscreenElement===document.documentElement);
    assert.equal(await other.evaluate(()=>rcsk.state.page),'intro');
    assert.ok(await other.locator('#movie').evaluate(video=>video.currentTime)>=before);
    assert.equal(await other.locator('#message').isVisible(),false);
    if(method==='Enter'){
      await other.locator('#movie').evaluate(video=>{video.currentTime=video.duration-.1;});
      await other.waitForSelector('[data-form=TFRMMAIN]');
      assert.equal(await other.locator('#movie').getAttribute('src'),null);
    }else{
      await other.locator('#movie').click();await other.waitForSelector('[data-form=TFRMMAIN]');
    }
    report.checks.push(name+': audio activation enters fullscreen and preserves playback; '+(method==='Enter'?'natural end':'click skip')+' cleans up and opens the menu');
    await other.close();
  }
  const allowed=await browser.newPage();observe(allowed);await allowed.goto(origin+'/');
  await allowed.waitForFunction(()=>document.getElementById('movie').currentTime>0&&!document.getElementById('movie').paused);
  assert.equal(await allowed.locator('#movie').evaluate(video=>video.muted),false);
  assert.equal(await allowed.locator('#movie-audio').isVisible(),false);
  report.checks.push('Allowed audible autoplay starts with sound and hides the unnecessary audio control');
  await allowed.close();
  if(!introOnly){
  await page.goto(origin+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving'&&window.rcsk.viewer.clock.tick>2,null,{timeout:60000});
  await page.waitForFunction(()=>rcsk.viewer.renderStats.hud?.glyphs>0);
  report.race=await page.evaluate(()=>({triangles:rcsk.viewer.renderStats.world.triangles,
    presentationTriangles:rcsk.viewer.renderStats.presentation.triangles,hud:rcsk.viewer.renderStats.hud,errors:rcsk.viewer.errors}));
  assert.ok(report.race.triangles>1000);assert.deepEqual(report.race.errors,[]);
  assert.equal(report.race.presentationTriangles,1);assert.ok(report.race.hud.glyphs>0);
  await page.screenshot({path:directory+'/race.png'});
  report.checks.push('Three.js, OrbitControls and the actual race render successfully');
  }
  assert.deepEqual(report.errors,[]);assert.deepEqual(report.requests,[]);
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);process.exitCode=1;}
finally{
  await writeFile(directory+'/browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();console.log(JSON.stringify(report,null,2));
}
