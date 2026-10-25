import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),environment:'Linux Chromium / SwiftShader; simulated controller and touch contacts',checks:[],errors:[]};
await mkdir('evidence/driving',{recursive:true});
try{
  const context=await browser.newContext({viewport:{width:1024,height:768}});
  const page=await context.newPage();
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error'&&!message.text().includes('favicon.ico'))report.errors.push(message.text());});
  page.on('response',r=>{if(r.status()>=400&&!r.url().endsWith('favicon.ico'))report.errors.push(r.status()+' '+r.url());});
  await page.goto(origin+'/?skipIntro');await page.waitForSelector('[data-form=TFRMMAIN]');
  for(let id=0;id<6;id++){
    await page.evaluate(({character,country})=>localStorage.setItem('rcsk.selection.v1',
      JSON.stringify({character,difficulty:1,country,race:0})),{character:id%4,country:id});
    await page.goto(origin+'/?drive='+id);
    await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
    await page.waitForFunction(()=>window.rcsk.viewer.clock.tick>2);
    const state=await page.evaluate(()=>{
      const v=window.rcsk.viewer,renderer=v.renderer,gl=renderer.getContext();
      v.suspend({notifyPause:false});
      const width=Math.round(document.getElementById('race-hud').getBoundingClientRect().width*devicePixelRatio);
      const height=Math.round(document.getElementById('race-hud').getBoundingClientRect().height*devicePixelRatio);
      const read=()=>{const pixels=new Uint8Array(width*height*4);gl.readPixels(0,0,width,height,gl.RGBA,gl.UNSIGNED_BYTE,pixels);return pixels;};
      // Compare two presentations of the same frozen RGB565 world. The first
      // omits overlay draws; the second uses the real glyph/mesh GPU path.
      v.renderScene({present:false});v.multisampling.compose(()=>null,width,height);
      const worldOnly=read();v.hud.render();const complete=read();
      let hudPixels=0;
      for(let i=0;i<complete.length;i+=4)if(complete[i]!==worldOnly[i]
        ||complete[i+1]!==worldOnly[i+1]||complete[i+2]!==worldOnly[i+2])hudPixels++;
      const state={errors:v.errors,driverFrames:v.driverFrames.size,triangles:v.renderStats.world.triangles,
        presentationTriangles:v.renderStats.presentation.triangles,hud:v.renderStats.hud,
        text:v.hud.text,atlas:[...v.hud.textures].map(([name,texture])=>({name,
          format:texture.userData.nativeTextureFormat,packed:!!texture.isDataTexture,
          premultiplyAlpha:texture.premultiplyAlpha,width:texture.image.width,height:texture.image.height})),
        hudPixels,glError:gl.getError(),position:[...v.motion.body.position],
        visibleRanges:v.visibleSectorRanges,shadowCount:v.shadows.length,
        researchHeaderHidden:document.querySelector('#viewer-hud').hidden};
      v.resume();return state;
    });
    assert.deepEqual(state.errors,[]);assert.ok(state.driverFrames>10);assert.ok(state.triangles>1000);
    assert.equal(state.presentationTriangles,1);assert.ok(state.hud.glyphs>0);assert.equal(state.glError,0);
    assert.equal(state.text.string_lap,'Ronde');assert.equal(state.text.string_lap_value,'1');
    assert.ok(state.hudPixels>1000);assert.ok(state.atlas.length>0);
    assert.ok(state.atlas.every(texture=>/^overlay[12]\.tga$/.test(texture.name)
      &&texture.format==='RGB565'&&texture.packed&&!texture.premultiplyAlpha&&texture.width>0&&texture.height>0));
    assert.equal(state.researchHeaderHidden,true);
    assert.equal(state.shadowCount,5);assert.ok(state.visibleRanges.length>0);
    await page.keyboard.down('ArrowUp');await page.waitForTimeout(1000);await page.keyboard.up('ArrowUp');
    const moved=await page.evaluate(()=>window.rcsk.viewer.motion.snapshot());
    assert.ok(moved.forwardSpeed>0);assert.ok(Math.hypot(...moved.position.map((value,i)=>value-state.position[i]))>1);
    await page.screenshot({path:`evidence/driving/track-${id}.png`});
    report.checks.push({track:id,character:id%4,originalHud:true,hudPixels:state.hudPixels,
      hudGlyphs:state.hud.glyphs,worldTriangles:state.triangles,presentationTriangles:state.presentationTriangles,
      forwardSpeed:moved.forwardSpeed});
  }
  await page.evaluate(()=>{
    window.testPad={id:'Explicitly simulated standard pad',connected:true,mapping:'standard',axes:[0,0,0,0],
      buttons:Array.from({length:17},()=>({value:0,pressed:false}))};
    Object.defineProperty(navigator,'getGamepads',{value:()=>[window.testPad],configurable:true});
    window.testPad.buttons[1]={value:1,pressed:true};
  });
  await page.waitForFunction(()=>window.rcsk.state.input.brake===1);
  assert.equal(await page.evaluate(()=>window.rcsk.state.mode),'race');
  await page.evaluate(()=>window.testPad.buttons[1]={value:0,pressed:false});
  report.checks.push('Controller brake stays in the race; it does not trigger menu Back');
  await page.evaluate(()=>{
    window.testPad.axes[0]=.59;
    window.testPad.buttons[7]={value:.35,pressed:false};
  });
  await page.waitForFunction(()=>{
    const viewer=window.rcsk.viewer,{controls}=viewer.motion;
    // Original4341d0 reverses analog steering on the authored MAPS-mirrored
    // courses (England, France, Italy); the browser axis itself stays+.5.
    const expectedSteering=[2,3,5].includes(viewer.track.id)?-50:50;
    return controls.throttle===36&&controls.steering===expectedSteering;
  });
  const analogSteering=await page.evaluate(()=>({track:rcsk.viewer.track.id,
    mirrored:rcsk.viewer.motion.mirrored,controls:{...rcsk.viewer.motion.controls}}));
  assert.equal(analogSteering.track,5);assert.equal(analogSteering.mirrored,true);
  assert.equal(analogSteering.controls.steering,-50);
  report.analogSteering=analogSteering;
  assert.equal(await page.evaluate(()=>window.rcsk.state.input.analog.throttle),.35);
  await page.keyboard.down('ArrowUp');
  await page.waitForFunction(()=>window.rcsk.state.input.analog===undefined);
  await page.keyboard.up('ArrowUp');
  await page.waitForFunction(()=>window.rcsk.state.input.analog?.throttle===.35);
  await page.evaluate(()=>{
    window.testPad.axes[0]=0;window.testPad.buttons[7]={value:0,pressed:false};
    window.testPad.buttons[6]={value:.4,pressed:false};
  });
  await page.waitForFunction(()=>{
    const {controls}=window.rcsk.viewer.motion;
    return controls.throttle===0&&controls.brake===40&&controls.steering===0;
  });
  await page.evaluate(()=>window.testPad.buttons[6]={value:0,pressed:false});
  report.checks.push('Simulated analog axes produce original proportional throttle, steering and brake; held keyboard input takes control and releases back to the pad');
  await page.evaluate(()=>window.dispatchEvent(new Event('blur')));
  const paused=await page.evaluate(()=>({mode:window.rcsk.state.mode,tick:window.rcsk.viewer.clock.tick}));
  assert.equal(paused.mode,'paused');await page.waitForTimeout(350);
  assert.equal(await page.evaluate(()=>window.rcsk.viewer.clock.tick),paused.tick);
  await page.locator('#world').click({position:{x:300,y:300}});
  await page.waitForFunction(()=>window.rcsk.viewer.clock.tick>0&&window.rcsk.state.mode==='race');
  assert.ok(await page.evaluate(tick=>window.rcsk.viewer.clock.tick-tick<8,paused.tick));
  report.checks.push('Focus loss freezes motion; click resumes without accumulated catch-up');
  await page.evaluate(()=>window.dispatchEvent(new Event('blur')));
  await page.keyboard.press('Enter');await page.waitForFunction(()=>window.rcsk.state.mode==='race');
  await page.evaluate(()=>{
    window.dispatchEvent(new Event('blur'));
    window.testPad.buttons[9]={value:1,pressed:true};
  });
  await page.waitForFunction(()=>window.rcsk.state.mode==='race');
  await page.evaluate(()=>window.testPad.buttons[9]={value:0,pressed:false});
  report.checks.push('Keyboard Enter and controller Start also resume a focus pause');
  await page.evaluate(async()=>{
    const {writeSettings}=await import('/src/settings.js');
    writeSettings({...window.rcsk.state.settings,touch:'on'});
  });
  await page.setViewportSize({width:390,height:844});await page.reload();
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving');
  const a=await page.locator('#touch-wheel').boundingBox(),b=await page.locator('#touch-brake').boundingBox();
  assert.ok(a&&b);const cdp=await context.newCDPSession(page);
  await cdp.send('Input.dispatchTouchEvent',{type:'touchStart',touchPoints:[
    {x:a.x+a.width*.2,y:a.y+a.height*.12,id:1},{x:b.x+b.width/2,y:b.y+b.height/2,id:2},
  ]});
  await page.waitForFunction(()=>window.rcsk.state.input.throttle===1&&window.rcsk.state.input.steer<-.5&&window.rcsk.state.input.handbrake===1);
  await cdp.send('Input.dispatchTouchEvent',{type:'touchCancel',touchPoints:[]});
  await page.waitForFunction(()=>window.rcsk.state.input.throttle===0&&window.rcsk.state.input.steer===0&&window.rcsk.state.input.handbrake===0);
  assert.equal(await page.evaluate(()=>document.documentElement.scrollWidth>innerWidth),false);
  await page.screenshot({path:'evidence/driving/portrait.png'});
  report.checks.push('Actual wheel and brake pedal combine two browser touch contacts and clear cancellation in portrait');
  for(const [width,height]of [[320,740],[390,844],[844,390]]){
    await page.setViewportSize({width,height});
    await page.waitForTimeout(120);
    const bounds=await page.evaluate(async()=>{
      const {Vector3}=await import('three'),v=window.rcsk.viewer,layout=v.hud.layout;
      const controls=document.getElementById('touch-controls').getBoundingClientRect();
      const boxes=['bonusframe','track'].map(id=>{
        const {mesh}=v.hudMeshes.elements.get(id),layer=v.config?.['overlay.ini']?.[id]?.parent
          ??v.hudMeshes.config['overlay.ini'][id].parent.toLowerCase();
        const viewport=layout.group(layer.toLowerCase()),p=mesh.geometry.attributes.position;
        const vertices=Array.from({length:p.count},(_,i)=>{
          const point=new Vector3().fromBufferAttribute(p,i).applyMatrix4(mesh.matrixWorld).project(v.hudMeshes.camera);
          return [viewport.x+(point.x+1)*viewport.width/2,viewport.y+(1-point.y)*viewport.height/2];
        });
        return {id,left:Math.min(...vertices.map(p=>p[0])),right:Math.max(...vertices.map(p=>p[0])),
          top:Math.min(...vertices.map(p=>p[1])),bottom:Math.max(...vertices.map(p=>p[1]))};
      });
      return {boxes,controlTop:controls.top,scale:layout.scale};
    });
    for(const box of bounds.boxes){
      assert.ok(box.left>=-1&&box.right<=width+1,`${width}×${height} ${box.id} stays horizontally visible`);
      assert.ok(box.top>=0&&box.bottom<=bounds.controlTop+1,`${width}×${height} ${box.id} stays above touch controls`);
    }
    report.checks.push({viewport:[width,height],touchBandReserved:true,hudBounds:bounds.boxes});
  }
  await page.setViewportSize({width:390,height:844});await page.waitForTimeout(120);
  await page.screenshot({path:'evidence/driving/portrait.png'});
  await page.locator('#touch-stop').click();
  await page.waitForSelector('[data-form=RACE_STOPPEN]');
  await page.getByRole('button',{name:'Nee',exact:true}).click();
  await page.waitForFunction(()=>window.rcsk.state.mode==='race');
  report.checks.push('Touch Stoppen opens the original race quit requester and Nee resumes');
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile('evidence/driving/report.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();console.log(JSON.stringify(report,null,2));
}
