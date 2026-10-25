import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const output='evidence/touch-controls';
await mkdir(output,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const context=await browser.newContext({viewport:{width:844,height:390},hasTouch:true,isMobile:true,deviceScaleFactor:1});
const page=await context.newPage();
const cdp=await context.newCDPSession(page);
const report={browser:browser.version(),touchProtocol:'Selective CDP touchEnd sends the ending contact. The live pointerup trace asserts only the released control receives pointerup; other contacts retain their state. Empty touchCancel ends all contacts. Verified against an independent three-contact DOM event probe on this Chromium version.',scope:'Focused source-only mobile Chromium check. Real Quickrace menu launch and browser-dispatched multi-touch feed the running original motion simulation. Viewport, blur and visibility lifecycle checks are explicitly controlled. No full races, package builds or releases.',checks:[],errors:[]};
page.on('pageerror',error=>report.errors.push(error.message));
page.on('response',response=>{if(response.status()>=400&&!response.url().endsWith('favicon.ico'))report.errors.push(`${response.status()} ${response.url()}`);});
await page.addInitScript(()=>{
  window.touchControlEvents=[];
  for(const type of ['pointerdown','pointerup','pointercancel'])window.addEventListener(type,event=>{
    const target=event.target.closest?.('#touch-wheel,#touch-brake,#touch-bonus,#touch-stop');
    if(target)touchControlEvents.push({type,target:target.id,pointerId:event.pointerId});
  });
  localStorage.setItem('rcsk.settings.v1',JSON.stringify({touch:'auto',renderScale:50}));
  localStorage.setItem('rcsk.selection.v1',JSON.stringify({character:0,difficulty:0,country:0,race:0}));
});
const firstCheck=Number(process.env.RCSK_TOUCH_FIRST_CHECK||1);let checkIndex=0;report.firstCheck=firstCheck;if(firstCheck===11)report.scope='Layout-only source check via the existing direct driving route. Mobile viewport bounds and screenshots; no input gameplay groups, full races, builds or releases.';if(firstCheck===12)report.scope='Direct DrivingView suspend/resume ownership regression on source in mobile Chromium. Browser-dispatched wheel and pedal contacts exercise the simulation-owned InputState.clear path. No previous gameplay/layout checks, screenshots, full races, builds or releases.';
const check=async(name,callback)=>{if(++checkIndex<firstCheck||(firstCheck===11&&checkIndex>11))return;const detail=await callback();report.checks.push({name,...(detail?{detail}:{})});console.log(name);};
const input=()=>page.evaluate(()=>window.rcsk.state.input);
const contacts=new Map();
const send=type=>cdp.send('Input.dispatchTouchEvent',{type,touchPoints:[...contacts.values()]});
const start=async(id,point)=>{contacts.set(id,{id,...point});await send('touchStart');};
// Chromium may coalesce pointermove until its next animation frame.
const move=async(id,point)=>{contacts.set(id,{id,...point});await send('touchMove');await page.evaluate(()=>new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve))));};
// CDP touchEnd lists the contacts ending, rather than those still held.
const end=async id=>{const ended=contacts.get(id);contacts.delete(id);await cdp.send('Input.dispatchTouchEvent',{type:'touchEnd',touchPoints:[ended]});};
const cancel=async()=>{contacts.clear();await send('touchCancel');};
const point=async(selector,x=.5,y=.5)=>{const b=await page.locator(selector).boundingBox();assert.ok(b,selector+' visible');return {x:b.x+b.width*x,y:b.y+b.height*y};};
const wheel=(x=.5,y=.12)=>point('#touch-wheel',x,y);
const assertNeutral=async()=>{
  const state=await input();
  for(const key of ['throttle','brake','steer','handbrake','bonus'])assert.equal(state[key],0,key+' cleared');
  assert.equal(state.analog,undefined,'touch analog ownership cleared');
  assert.equal(await page.locator('#touch-controls .held').count(),0,'pressed artwork cleared');
  assert.equal(await page.locator('#touch-wheel').getAttribute('data-drive'),'neutral');
};
const waitRace=()=>page.waitForFunction(()=>window.rcsk?.state.mode==='race');
const approximately=(actual,expected,tolerance=.00001)=>assert.ok(Math.abs(actual-expected)<tolerance,`${actual} should be ${expected}`);

try{
  if(firstCheck>=11)await page.goto(origin+'/?drive=0');
  else{
    await page.goto(origin+'/?skipIntro');
    await page.locator('[data-native=btnQuickRace]').click();
    for(const form of ['TFRMSELECTCHAR','TFRMSELECTCOUNTRY','TFRMCONTROLSETTINGS']){
      await page.waitForSelector(`[data-form=${form}]`);await page.locator('[data-native=btnOk]').click();
    }
  }
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
  await check('Touch auto detects a mobile browser and loads all three control images',async()=>{
    assert.equal(await page.evaluate(()=>matchMedia('(pointer:coarse)').matches),true);
    assert.equal(await page.locator('#touch-controls').isVisible(),true);
    const images=await page.locator('#touch-wheel img,#touch-brake img,#touch-bonus img').evaluateAll(async nodes=>{
      await Promise.all(nodes.map(async image=>{try{await image.decode();}catch{throw new Error(`Cannot decode control image: ${image.src}`);}}));
      return nodes.map(image=>({src:new URL(image.src).pathname,width:image.naturalWidth,height:image.naturalHeight}));
    });
    assert.equal(images.length,3);assert.ok(images.every(image=>image.width>0&&image.height>0));
    return images;
  });
  await page.waitForFunction(()=>rcsk.viewer.simulation.movementActive,null,{timeout:60000});
  if(firstCheck===11)await page.waitForFunction(()=>rcsk.viewer.hudMeshes.portraits.portraits.every(p=>p.state===2));
  await check('The lower wheel feeds the original brake/reverse action and moves the kart backwards',async()=>{
    await start(1,await wheel(.5,.88));
    const state=await input();assert.equal(state.brake,1);assert.equal(state.throttle,0);assert.equal(state.steer,0);assert.equal(state.analog.brake,1);
    assert.equal(await page.locator('#touch-wheel').getAttribute('data-drive'),'reverse');
    await page.waitForFunction(()=>rcsk.viewer.motion.body.forwardSpeed<-.25,null,{timeout:10000});
    const speed=await page.evaluate(()=>rcsk.viewer.motion.body.forwardSpeed);
    await end(1);await assertNeutral();return {reverseSpeed:speed};
  });
  await check('The upper wheel accelerates and a held drag gives proportional left and right steering',async()=>{
    await start(1,await wheel());
    await page.waitForFunction(()=>rcsk.viewer.motion.body.forwardSpeed>.25,null,{timeout:10000});
    const speed=await page.evaluate(()=>rcsk.viewer.motion.body.forwardSpeed);
    await move(1,await wheel(.35,.12));
    const left=await input();assert.equal(left.throttle,1);assert.equal(left.brake,0);approximately(left.steer,-(.3-.1)/.9/.8);approximately(left.analog.steer,left.steer);
    await page.waitForFunction(()=>rcsk.viewer.motion.controls.steering<0&&rcsk.viewer.motion.controls.steering>-100);
    const nativeLeft=await page.evaluate(()=>({...rcsk.viewer.motion.controls}));
    await move(1,await wheel(.65,.12));const right=await input();approximately(right.steer,(.3-.1)/.9/.8);
    await move(1,await wheel(.5,.5));const center=await input();assert.equal(center.steer,0);assert.equal(center.throttle,0);assert.equal(center.brake,0);
    await end(1);await assertNeutral();return {forwardSpeed:speed,left:left.steer,right:right.steer,nativeLeft};
  });
  await check('The separate brake pedal enters the same native handbrake path as Alt',async()=>{
    await page.keyboard.down('AltLeft');await page.waitForFunction(()=>rcsk.viewer.motion.controls.handbrake===true);
    const keyboard=await input();assert.equal(keyboard.handbrake,1);assert.equal(keyboard.brake,0);
    await page.keyboard.up('AltLeft');
    await start(2,await point('#touch-brake'));await page.waitForFunction(()=>rcsk.viewer.motion.controls.handbrake===true);
    const pedal=await input();assert.deepEqual(pedal,keyboard);
    await end(2);await assertNeutral();return {keyboard,pedal};
  });
  await check('Three simultaneous contacts combine wheel, brake pedal and power-up without releasing each other',async()=>{
    await start(1,await wheel(.3,.12));await start(2,await point('#touch-brake'));await start(3,await point('#touch-bonus'));
    const state=await input();assert.equal(state.throttle,1);assert.ok(state.steer<0);assert.equal(state.handbrake,1);assert.equal(state.bonus,1);
    assert.equal(state.analog.handbrake,1);assert.equal(state.analog.bonus,1);
    assert.equal(await page.locator('#touch-controls .held').count(),3);
    const eventStart=await page.evaluate(()=>touchControlEvents.length);
    await end(3);assert.equal((await input()).bonus,0);assert.equal((await input()).handbrake,1);
    const selectiveReleaseEvents=await page.evaluate(start=>touchControlEvents.slice(start),eventStart);
    assert.deepEqual(selectiveReleaseEvents.map(({type,target})=>({type,target})),[{type:'pointerup',target:'touch-bonus'}]);
    await end(2);assert.equal((await input()).handbrake,0);assert.equal((await input()).throttle,1);
    await end(1);await assertNeutral();return {state,selectiveReleaseEvents};
  });
  await check('Wheel capture continues outside its hitbox and release/cancel cannot leave a held input',async()=>{
    await start(1,await wheel());
    const b=await page.locator('#touch-wheel').boundingBox();await move(1,{x:b.x+b.width+30,y:b.y-12});
    const outside=await input();assert.equal(outside.throttle,1);assert.equal(outside.steer,1);
    await end(1);await assertNeutral();
    await start(1,await wheel());await start(2,await point('#touch-brake'));await start(3,await point('#touch-bonus'));await cancel();await assertNeutral();
  });
  await check('Resizing a held wheel clears it until a fresh touch begins',async()=>{
    await start(1,await wheel());await page.setViewportSize({width:390,height:844});await page.waitForTimeout(120);await assertNeutral();
    await move(1,await wheel());await assertNeutral();await end(1);
    await start(1,await wheel());assert.equal((await input()).throttle,1);await end(1);await assertNeutral();
  });
  await check('The original Stoppen requester clears held controls and Nee resumes with neutral input',async()=>{
    await page.setViewportSize({width:390,height:844});await page.waitForTimeout(100);
    await start(1,await wheel());await start(2,await point('#touch-stop'));await end(2);
    await page.waitForSelector('[data-form=RACE_STOPPEN]');await assertNeutral();await end(1);
    await page.getByRole('button',{name:'Nee',exact:true}).tap();await waitRace();await assertNeutral();
  });
  await check('Focus loss clears contacts and artwork, ignores stale movement, and resumes on a fresh world tap',async()=>{
    await start(1,await wheel());await start(2,await point('#touch-brake'));
    await page.evaluate(()=>window.dispatchEvent(new Event('blur')));
    assert.equal(await page.evaluate(()=>rcsk.state.mode),'paused');await assertNeutral();
    await move(1,await wheel(.3,.12));await assertNeutral();await cancel();
    await page.locator('#world').tap({position:{x:195,y:300}});await waitRace();await assertNeutral();
  });
  await check('A controlled hidden-document lifecycle clears all touch inputs and permits a fresh gesture after resuming',async()=>{
    await start(1,await wheel());await start(3,await point('#touch-bonus'));
    await page.evaluate(()=>{
      Object.defineProperty(document,'hidden',{configurable:true,get:()=>true});
      document.dispatchEvent(new Event('visibilitychange'));delete document.hidden;
    });
    assert.equal(await page.evaluate(()=>rcsk.state.mode),'paused');await assertNeutral();await cancel();
    await page.locator('#world').tap({position:{x:195,y:300}});await waitRace();
    await start(1,await wheel());assert.equal((await input()).throttle,1);await end(1);await assertNeutral();
  });
  await check('Portrait and landscape controls have separate large targets and leave the original bonus/minimap above them',async()=>{
    const layouts=[];
    for(const [width,height]of [[320,740],[390,844],[480,320],[844,390]]){
      await page.setViewportSize({width,height});
      await page.waitForFunction(()=>rcsk.viewer.hud.glyphs.width===innerWidth&&rcsk.viewer.hud.glyphs.height===innerHeight);
      await page.evaluate(()=>new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve))));
      const bounds=await page.evaluate(async()=>{
        const {Vector3}=await import('three'),v=rcsk.viewer,layout=v.hud.layout;
        const rect=id=>{const b=document.getElementById(id).getBoundingClientRect();return {id,x:b.x,y:b.y,width:b.width,height:b.height};};
        const controls=['touch-wheel','touch-brake','touch-bonus','touch-stop'].map(rect);
        const hud=['bonusframe','track',...[...v.hudMeshes.elements.keys()].filter(id=>/^(frame|portr)(redcat|whizzkitty|brutus|max|cou)$/.test(id))].map(id=>{
          const {mesh}=v.hudMeshes.elements.get(id),layer=v.hudMeshes.config['overlay.ini'][id].parent.toLowerCase();
          const viewport=layout.group(layer),p=mesh.geometry.attributes.position;
          const vertices=Array.from({length:p.count},(_,i)=>{const point=new Vector3().fromBufferAttribute(p,i).applyMatrix4(mesh.matrixWorld).project(v.hudMeshes.camera);
            return [viewport.x+(point.x+1)*viewport.width/2,viewport.y+(1-point.y)*viewport.height/2];});
          return {id,left:Math.min(...vertices.map(p=>p[0])),right:Math.max(...vertices.map(p=>p[0])),top:Math.min(...vertices.map(p=>p[1])),bottom:Math.max(...vertices.map(p=>p[1]))};
        });
        const timeScale=layout.text('string_laptime').scale??layout.scale;
        const timeEntry=v.hud.glyphs.strings.get('string_laptime'),timePosition=timeEntry.meshes[0].geometry.attributes.position;
        const {layoutHudText}=await import('/src/hud-text.js'),nativeTimeGlyph=layoutHudText(timeEntry.spec,v.hud.text.string_laptime)[0];
        const timeGlyphHeight=Math.abs(timePosition.getY(2)-timePosition.getY(0));
        const digitEntry=v.hud.glyphs.strings.get('string_laptime_value');
        const digitHeights=digitEntry.meshes.filter(mesh=>mesh.visible).map(mesh=>{const p=mesh.geometry.attributes.position;return Math.abs(p.getY(2)-p.getY(0));});
        return {controls,hud,scale:layout.scale,timeScale,timeGlyphHeight,digitHeights,nativeTimeGlyphHeight:nativeTimeGlyph.height,controlTop:document.getElementById('touch-controls').getBoundingClientRect().top,overflow:document.documentElement.scrollWidth>innerWidth};
      });
      assert.equal(bounds.overflow,false);
      approximately(bounds.timeGlyphHeight,bounds.nativeTimeGlyphHeight*bounds.timeScale,.001);
      if(width>height){approximately(bounds.timeScale,Math.min(width/640,height/480));assert.ok(bounds.timeScale>bounds.scale,'race times retain readable size above the smaller HUD stack');assert.ok(Math.max(...bounds.digitHeights)>=8,'actual time digits stay at least8 CSS pixels high');}
      for(const b of bounds.controls){assert.ok(b.x>=0&&b.y>=0&&b.x+b.width<=width+1&&b.y+b.height<=height+1,b.id+' within viewport');assert.ok(b.width>=42&&b.height>=42,b.id+' usable target');}
      assert.ok(bounds.controls[0].width>=130&&bounds.controls[0].height>=130,'large steering wheel');
      for(const id of ['touch-brake','touch-bonus']){const b=bounds.controls.find(b=>b.id===id);assert.ok(b.width>=64&&b.height>=64,id+' large action target');}
      for(let a=0;a<bounds.controls.length;a++)for(let b=a+1;b<bounds.controls.length;b++){
        const x=bounds.controls[a],y=bounds.controls[b];assert.ok(x.x+x.width<=y.x+.5||y.x+y.width<=x.x+.5||x.y+x.height<=y.y+.5||y.y+y.height<=x.y+.5,`${x.id} and ${y.id} do not overlap`);
      }
      for(const b of bounds.hud){assert.ok(b.left>=-1&&b.right<=width+1,b.id+' horizontally visible: '+JSON.stringify(b));assert.ok(b.top>=0&&b.bottom<=bounds.controlTop+1,b.id+' above controls');}
      const bonus=bounds.hud.find(b=>b.id==='bonusframe');
      for(const standing of bounds.hud.filter(b=>/^(frame|portr)/.test(b.id)))assert.ok(standing.bottom<=bonus.top,standing.id+' clear of bonus frame');
      layouts.push({viewport:[width,height],...bounds});await page.screenshot({path:`${output}/${width>height?width===480?'landscape-small':'landscape':width===320?'portrait-small':'portrait'}.png`});
    }
    return layouts;
  });
  await check('Direct DrivingView suspension clears captured touches and artwork; stale moves stay neutral and a fresh resumed wheel stays analog',async()=>{
    await start(1,await wheel(.3,.12));await start(2,await point('#touch-brake'));
    const held=await input();assert.equal(held.throttle,1);assert.equal(held.handbrake,1);assert.ok(held.analog.steer<0);
    assert.equal(await page.locator('#touch-controls .held').count(),2);
    await page.evaluate(()=>rcsk.viewer.suspend({notifyPause:false}));
    assert.equal(await page.evaluate(()=>rcsk.viewer.active),false);await assertNeutral();
    await move(1,await wheel(.7,.12));await assertNeutral();
    await end(2);await end(1);await page.evaluate(()=>rcsk.viewer.resume());
    assert.equal(await page.evaluate(()=>rcsk.viewer.active),true);
    await start(1,await wheel(.65,.12));
    const resumed=await input();assert.equal(resumed.throttle,1);assert.ok(resumed.analog.steer>0&&resumed.analog.steer<1);
    assert.equal(await page.locator('#touch-wheel.held').count(),1);
    await end(1);await assertNeutral();return {held,resumed};
  });
  assert.deepEqual(await page.evaluate(()=>rcsk.viewer.errors),[]);assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);await page.screenshot({path:output+'/failure.png'}).catch(()=>{});throw error;}
finally{
  report.sourceHashes=Object.fromEntries(await Promise.all(['index.html','src/input.js','src/main.js','src/style.css','src/race-hud-layout.js','src/hud-text-renderer.js','tests/touch-controls-browser.mjs'].map(async file=>[file,createHash('sha256').update(await readFile(file)).digest('hex')])));
  await writeFile(output+(firstCheck===1?'/browser.json':firstCheck===8?'/browser-remaining.json':`/browser-from-${firstCheck}.json`),JSON.stringify(report,null,2)+'\n');await browser.close();
}
console.log(`Touch browser: ${report.checks.length} checks passed`);
