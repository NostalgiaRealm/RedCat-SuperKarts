import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const output='evidence/full-source-audit/pause-audio';
await mkdir(output,{recursive:true});
const report={status:'running',scope:'Source-only Chromium. Real P/Escape/cancel keys and media playback; controlled near-end music seek for completion; synthetic blur and one synchronous pointerdown/blur pair through existing host handlers. No full race, native Windows playback, build or package test.',checks:[],errors:[]};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,
  args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
try{
  const page=await browser.newPage({viewport:{width:960,height:720}});
  page.on('pageerror',error=>report.errors.push(error.stack||error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4184')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
  await page.evaluate(async()=>{const v=rcsk.viewer;await v.audio.unlock();await v.music.resume();});
  await page.waitForFunction(()=>rcsk.viewer.music.audio.currentTime>0&&rcsk.viewer.audio.context.state==='running');
  const sample=()=>page.evaluate(()=>{
    const v=rcsk.viewer;return {mode:rcsk.state.mode,tick:v.clock.tick,raceMs:v.race.elapsedMs,
      audioTime:v.audio.context.currentTime,audioState:v.audio.context.state,
      musicTime:v.music.audio.currentTime,musicPaused:v.music.audio.paused,musicEnded:v.music.audio.ended,
      automaticLoop:v.music.audio.loop};
  });
  const continuing=async name=>{
    const before=await sample();await page.waitForTimeout(350);const after=await sample();
    assert.equal(after.mode,'paused');assert.equal(after.tick,before.tick);assert.equal(after.raceMs,before.raceMs);
    assert.equal(after.audioState,'running');assert.ok(after.audioTime-before.audioTime>.2);
    assert.equal(after.musicPaused,false);assert.ok(after.musicTime-before.musicTime>.2);
    report.checks.push({name,before,after});
  };
  const heldFocusPause=async name=>{
    await page.waitForFunction(()=>rcsk.viewer.audio.context.state==='suspended'&&rcsk.viewer.music.audio.paused);
    const before=await sample();await page.waitForTimeout(300);const after=await sample();
    assert.equal(after.mode,'paused');assert.equal(after.tick,before.tick);assert.equal(after.raceMs,before.raceMs);
    assert.equal(after.audioState,'suspended');assert.equal(after.audioTime,before.audioTime);
    assert.equal(after.musicPaused,true);assert.equal(after.musicTime,before.musicTime);
    assert.equal(await page.locator('#screen').evaluate(element=>element.hidden),true);
    assert.equal(await page.locator('#race-hud').evaluate(element=>element.hidden),false);
    await page.keyboard.press('Enter');await page.waitForFunction(()=>rcsk.state.mode==='race');
    await page.waitForFunction(()=>rcsk.viewer.audio.context.state==='running'&&!rcsk.viewer.music.audio.paused);
    report.checks.push({name,before,after,resumed:await sample()});
  };
  await page.keyboard.press('p');await page.waitForFunction(()=>rcsk.state.mode==='paused');
  await continuing('P pause freezes race while original music and sound buffers continue');
  await page.keyboard.press('x');await page.waitForFunction(()=>rcsk.state.mode==='race');
  await page.keyboard.press('Escape');
  await page.waitForFunction(()=>document.querySelector('[data-form=RACE_STOPPEN]')?.dataset.state==='input');
  await continuing('Escape requester preserves original background audio');
  await page.evaluate(()=>dispatchEvent(new Event('blur')));
  await page.waitForFunction(()=>rcsk.viewer.audio.context.state==='suspended'&&rcsk.viewer.music.audio.paused);
  const focusBefore=await sample();await page.waitForTimeout(250);const focusAfter=await sample();
  assert.equal(focusAfter.audioTime,focusBefore.audioTime);assert.equal(focusAfter.musicTime,focusBefore.musicTime);
  await page.keyboard.press('n');await page.waitForFunction(()=>document.getElementById('screen').hidden);
  await heldFocusPause('focus loss from open requester remains paused after cancellation until deliberate resume');

  await page.keyboard.press('Escape');
  await page.waitForFunction(()=>document.querySelector('[data-form=RACE_STOPPEN]')?.dataset.state==='input');
  await page.keyboard.down('n');
  await page.evaluate(()=>dispatchEvent(new Event('blur')));
  await page.keyboard.up('n');
  await page.waitForFunction(()=>document.getElementById('screen').hidden);
  await heldFocusPause('blur while cancellation waits for key release cannot restart race or audio');

  await page.keyboard.press('Escape');
  await page.waitForFunction(()=>document.querySelector('[data-form=RACE_STOPPEN]')?.dataset.state==='input');
  await page.evaluate(()=>{
    document.querySelector('[data-choice=no]').dispatchEvent(new PointerEvent('pointerdown',{button:0,bubbles:true}));
    dispatchEvent(new Event('blur'));
  });
  await page.waitForFunction(()=>document.getElementById('screen').hidden);
  await heldFocusPause('blur during the requester pressed-frame delay cannot restart race or audio');

  await page.keyboard.press('p');await page.waitForFunction(()=>rcsk.state.mode==='paused');
  await page.keyboard.down('x');
  await page.evaluate(()=>dispatchEvent(new Event('blur')));
  await page.keyboard.up('x');
  await heldFocusPause('blur during P resume key release retains the host pause');

  await page.keyboard.press('p');await page.waitForFunction(()=>rcsk.state.mode==='paused');
  const seek=await page.evaluate(()=>{
    const music=rcsk.viewer.music.audio;
    music.currentTime=music.duration-.2;return {duration:music.duration,loop:music.loop};
  });
  assert.equal(seek.loop,false);
  await page.waitForFunction(()=>rcsk.viewer.music.audio.ended);
  const endBefore=await sample();await page.waitForTimeout(250);const endAfter=await sample();
  assert.equal(endAfter.musicEnded,true);assert.equal(endAfter.musicTime,endBefore.musicTime);
  assert.equal(endAfter.audioState,'running');
  await page.keyboard.press('x');await page.waitForFunction(()=>rcsk.state.mode==='race');
  await page.waitForFunction(()=>!rcsk.viewer.music.audio.paused&&rcsk.viewer.music.audio.currentTime<2);
  report.checks.push({name:'music finishes during pause and restarts on resume',seek,before:endBefore,after:endAfter,resumed:await sample()});
  await page.evaluate(()=>{const v=rcsk.viewer;v.music.audio.currentTime=v.music.audio.duration-.15;});
  await page.waitForFunction(()=>rcsk.viewer.music.audio.currentTime<2);
  report.checks.push({name:'normal native updates restart completed music',state:await sample()});

  // Confirming quit must retire race media, not leave the restored loops on.
  await page.keyboard.press('Escape');
  await page.waitForFunction(()=>document.querySelector('[data-form=RACE_STOPPEN]')?.dataset.state==='input');
  await page.keyboard.press('j');await page.waitForFunction(()=>rcsk.state.mode==='menu',null,{timeout:10000});
  const exit=await sample();assert.equal(exit.musicPaused,true);assert.notEqual(exit.audioState,'running');
  report.checks.push({name:'leaving race stops its audio',state:exit});
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=error.stack;throw error;}
finally{await writeFile(output+'/browser.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(`Pause audio browser: ${report.checks.length} checks passed`);
