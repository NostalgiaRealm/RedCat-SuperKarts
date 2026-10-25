import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const result={browser:browser.version(),platform:process.platform,rendering:'headless Chromium / SwiftShader, not display refresh or physical-device testing',checks:[],errors:[],tracks:[]};
await mkdir('evidence/browser',{recursive:true});
function check(name,fn){return Promise.resolve().then(fn).then(()=>result.checks.push(name));}
try{
  const context=await browser.newContext({viewport:{width:1024,height:768}});
  const page=await context.newPage();page.on('pageerror',e=>result.errors.push(e.message));
  page.on('console',message=>{if(message.type()==='error'&&!message.text().includes('favicon.ico'))result.errors.push(message.text());});
  page.on('response',r=>{if(r.status()>=400&&!r.url().endsWith('favicon.ico'))result.errors.push(r.status()+' '+r.url());});
  await page.goto(origin+'/?skipIntro');await page.waitForSelector('[data-native=btnQuickRace]');await page.evaluate(()=>document.fonts.ready);
  await check('original main menu artwork and native form',async()=>{
    assert.equal(await page.locator('[data-form=TFRMMAIN]').count(),1);
    assert.equal(await page.locator('[data-native=btnAdventure]').evaluate(el=>document.activeElement===el),true);
    assert.match(await page.locator('[data-native=btnAdventure]').evaluate(el=>getComputedStyle(el).backgroundImage),/mn_0103b/);
    assert.match(await page.locator('[data-native=btnQuickRace]').evaluate(el=>getComputedStyle(el).fontFamily),/Original Comic Sans/);
    assert.match(await page.locator('[data-native=btnQuickRace]').evaluate(el=>getComputedStyle(el).clipPath),/native-menu-region/);
  });
  await page.screenshot({path:'evidence/browser/main.png'});
  await page.getByRole('button',{name:'QuickRace',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMSELECTCHAR]');
  await page.getByRole('button',{name:'Volgend karakter',exact:true}).click();
  await page.waitForFunction(()=>window.rcsk.state.selection.character===1);
  await page.getByRole('button',{name:'Moeilijk',exact:true}).click();
  await page.waitForFunction(()=>window.rcsk.state.selection.difficulty===2);
  await page.getByRole('button',{name:'Verder',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMSELECTCOUNTRY]');
  await page.getByRole('button',{name:'Volgend land',exact:true}).click();
  await page.waitForFunction(()=>window.rcsk.state.selection.country===1);
  await page.getByRole('button',{name:'Sterrenrace',exact:true}).click();
  await page.getByRole('button',{name:'OK',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMCONTROLSETTINGS]');
  await check('original selections and QuickRace start control information',async()=>{
    const state=await page.evaluate(()=>window.rcsk.state);
    assert.deepEqual(state.selection,{character:1,difficulty:2,country:1,race:2});
    assert.equal(state.page,'start-info');
    assert.equal(await page.locator('[data-element=lblForward]').textContent(),'Gas geven');
    assert.equal(await page.locator('[data-native=btnDefault]').count(),0);
  });
  await page.locator('[data-native=btnOk]').click();
  await page.waitForFunction(()=>window.rcsk.state.page==='driving',null,{timeout:60000});
  await page.waitForFunction(()=>window.rcsk.viewer.renderStats.hud?.glyphs>0);
  await check('selected star race enters original start sequence with the correct difficulty and roster',async()=>{
    const state=await page.evaluate(()=>({phase:window.rcsk.viewer.race.phase,
      mode:window.rcsk.viewer.race.raceType,difficulty:window.rcsk.viewer.simulation.difficulty,
      opponents:window.rcsk.viewer.opponents.length,render:window.rcsk.viewer.renderStats}));
    assert.deepEqual({phase:state.phase,mode:state.mode,difficulty:state.difficulty,opponents:state.opponents},
      {phase:1,mode:2,difficulty:2,opponents:3});
    assert.ok(state.render.world.triangles>1000);assert.ok(state.render.hud.glyphs>0);
    assert.equal(state.render.presentation.triangles,1);
  });
  await page.goto(origin+'/?skipIntro');
  await page.getByRole('button',{name:'Instellingen',exact:true}).click();
  await page.locator('[data-native=btnMoreSettings]').click();
  await page.locator('#resolution').selectOption('1280x720');
  await page.locator('#scale').fill('175');await page.locator('#scale').dispatchEvent('input');
  await page.getByRole('button',{name:'OK',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMOPTIONS]');
  await page.locator('[data-native=btnOk]').click();
  await page.waitForSelector('[data-form=TFRMMAIN]');
  await page.reload();await page.waitForSelector('[data-form=TFRMMAIN]');
  await check('settings and selected character/difficulty/country/mode survive reload',async()=>{
    const state=await page.evaluate(()=>window.rcsk.state);
    assert.equal(state.settings.renderScale,175);assert.equal(state.settings.resolution,'1280x720');
    assert.deepEqual(state.selection,{character:1,difficulty:2,country:1,race:2});
  });
  // Real UI events with an explicitly simulated standard controller.
  await page.evaluate(()=>{
    window.testPad={id:'Simulated standard pad',connected:true,mapping:'standard',axes:[0,0,0,0],buttons:Array.from({length:17},()=>({value:0,pressed:false}))};
    Object.defineProperty(navigator,'getGamepads',{value:()=>[window.testPad],configurable:true});
  });
  await page.getByRole('button',{name:'QuickRace',exact:true}).focus();
  await page.evaluate(()=>window.testPad.buttons[0]={value:1,pressed:true});
  await page.waitForFunction(()=>window.rcsk.state.page==='characters');
  await page.waitForTimeout(150);
  await check('held controller confirm does not activate successive screens',async()=>assert.equal(await page.evaluate(()=>window.rcsk.state.page),'characters'));
  await page.evaluate(()=>window.testPad.buttons[0]={value:0,pressed:false});
  await page.goto(origin+'/?skipIntro');
  await page.getByRole('button',{name:'Help',exact:true}).click();
  await page.waitForSelector('.original-help');
  await check('Help uses shipped Dutch WinHelp text and imagery',async()=>{
    assert.match(await page.locator('.original-help').textContent(),/In het hoofdmenu kun je/);
    assert.equal(await page.locator('.help-window nav a').count(),13);
    await page.locator('.help-window nav a').filter({hasText:'Bonussen'}).click();
    await page.waitForSelector('[data-topic=Bonussen]');
    const images=await page.locator('.original-help img').evaluateAll(async images=>{await Promise.all(images.map(img=>img.decode()));return images.map(img=>({src:img.src,width:img.naturalWidth}));});
    assert.ok(images.length>0);assert.ok(images.every(img=>img.width>0&&img.src.includes('/assets/help/images/')));
  });
  await page.screenshot({path:'evidence/browser/help-bonussen.png'});
  await page.goto(origin+'/?skipIntro');
  await page.getByRole('button',{name:'Instellingen',exact:true}).click();
  await page.getByRole('button',{name:'Instellen',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMCONTROLSETTINGS]');
  await page.locator('[data-element=lblKEY_ACCELERATE]').click();await page.keyboard.press('KeyW');
  await check('original controls dialog reassigns keys and retains them after reload',async()=>{
    assert.equal(await page.locator('[data-element=lblKEY_ACCELERATE]').textContent(),'w');
    assert.equal(await page.evaluate(()=>window.rcsk.state.settings.bindings.accelerate),'ArrowUp');
    await page.locator('[data-native=btnOk]').click();
    await page.waitForSelector('[data-form=TFRMOPTIONS]');
    await page.reload();await page.waitForSelector('[data-form=TFRMMAIN]');
    assert.equal(await page.evaluate(()=>window.rcsk.state.settings.bindings.accelerate),'KeyW');
  });
  for(let id=0;id<6;id++){
    await page.goto(origin+'/?track='+id);await page.waitForFunction(()=>window.rcsk?.state.page==='viewer',null,{timeout:60000});
    await page.waitForFunction(()=>window.rcsk.viewer.renderStats.world!==null);
    const stats=await page.evaluate(()=>({state:window.rcsk.state,render:window.rcsk.viewer.renderStats}));
    assert.equal(stats.state.track,id);assert.deepEqual(stats.state.assetErrors,[]);assert.ok(stats.render.world.triangles>1000);
    assert.equal(stats.render.presentation.triangles,1);
    const animation=await page.evaluate(()=>({sky:!!window.rcsk.viewer.sky,animations:window.rcsk.viewer.animations.length,tick:window.rcsk.viewer.clock.tick}));
    assert.equal(animation.sky,true);assert.ok(animation.animations>0);assert.ok(animation.tick>=0);
    result.tracks.push({id,objects:stats.state.objects,triangles:stats.render.world.triangles,
      presentationTriangles:stats.render.presentation.triangles});
    await page.screenshot({path:`evidence/browser/track-${id}.png`});
  }
  await check('all six original track/scenery sets render without missing resources',()=>{});
  for(const scale of [25,100,200]){
    await page.getByRole('button',{name:'Instellingen',exact:true}).click();
    await page.locator('[data-native=btnMoreSettings]').click();
    await page.locator('#resolution').selectOption('auto');await page.locator('#scale').fill(String(scale));await page.locator('#scale').dispatchEvent('input');
    await page.getByRole('button',{name:'OK',exact:true}).click();
    await page.waitForSelector('[data-form=TFRMOPTIONS]');
    await page.locator('[data-native=btnOk]').click();
    await page.waitForFunction(()=>window.rcsk.state.page==='viewer');
    const size=await page.locator('#world').evaluate(canvas=>[canvas.width,canvas.height]);
    assert.deepEqual(size,[1024*scale/100,768*scale/100]);
  }
  await check('25/100/200 percent actual WebGL drawing buffers match viewport',()=>{});
  await page.setViewportSize({width:390,height:844});await page.goto(origin+'/?skipIntro');
  await page.getByRole('button',{name:'QuickRace',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMSELECTCHAR]');
  for(const selected of [2,3]){
    await page.getByRole('button',{name:'Volgend karakter',exact:true}).click();
    await page.waitForFunction(value=>window.rcsk.state.selection.character===value,selected);
  }
  await page.getByRole('button',{name:'Verder',exact:true}).click();
  await page.waitForSelector('[data-form=TFRMSELECTCOUNTRY]');
  await page.locator('[data-element=imgSelectedCountry]').evaluate(img=>img.decode());
  await check('portrait reflows original country artwork without overflow',async()=>{
    assert.equal(await page.locator('[data-form=TFRMSELECTCOUNTRY]').count(),1);
    assert.equal(await page.evaluate(()=>document.documentElement.scrollWidth>innerWidth),false);
    for(const card of await page.locator('[data-element=imgSelectedCountry]').all()){
      const ratio=await card.evaluate(img=>({actual:img.width/img.height,original:img.naturalWidth/img.naturalHeight}));
      assert.ok(Math.abs(ratio.actual-ratio.original)<.02);
    }
  });
  await page.screenshot({path:'evidence/browser/portrait-countries.png'});
  await page.setViewportSize({width:844,height:390});await page.waitForSelector('[data-form=TFRMSELECTCOUNTRY]');
  await check('orientation changes return to original landscape layout',()=>{});
  // Actual multi-contact touch dispatch on a separate explicit input harness.
  await page.evaluate(async()=>{
    const {InputController}=await import('/src/input.js');window.touchTest=new InputController();
    const a=document.createElement('button'),b=document.createElement('button');
    a.id='touch-a';b.id='touch-b';a.textContent='Gas';b.textContent='Links';
    a.style.cssText='position:fixed;left:20px;top:100px;width:100px;height:100px;z-index:100';b.style.cssText='position:fixed;left:200px;top:100px;width:100px;height:100px;z-index:100';
    document.body.append(a,b);window.touchTest.bindTouch(a,'accelerate');window.touchTest.bindTouch(b,'left');
  });
  const cdp=await context.newCDPSession(page);
  await cdp.send('Input.dispatchTouchEvent',{type:'touchStart',touchPoints:[{x:60,y:150,id:1},{x:240,y:150,id:2}]});
  await check('two simultaneous browser touch contacts combine throttle and steering',async()=>assert.deepEqual(await page.evaluate(()=>window.touchTest.state.snapshot()),{throttle:1,brake:0,steer:-1,handbrake:0,bonus:0}));
  await cdp.send('Input.dispatchTouchEvent',{type:'touchCancel',touchPoints:[]});
  await check('touch cancellation releases every held action',async()=>assert.equal(await page.evaluate(()=>window.touchTest.state.sources.size),0));
  assert.deepEqual(result.errors,[]);
  result.status='passed';console.log(JSON.stringify(result,null,2));
}catch(error){result.status='failed';result.failure=String(error.stack||error);throw error;}
finally{await writeFile('evidence/browser/report.json',JSON.stringify(result,null,2)+'\n');await browser.close();}
