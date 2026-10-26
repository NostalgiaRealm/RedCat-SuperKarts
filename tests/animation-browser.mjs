import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),checks:[],errors:[],
  scope:'Actual browser key events feed DrivingView ticks; deterministic clock stepping accelerates observation. Separate controlled animation queue fixtures inspect pickup/hit dispatch and the mesh submitted for all four drivers. Native instruction fixtures establish the original request and timing rules; no Wine race image comparison is claimed.'};
await mkdir('evidence/animations',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');
  for(let character=0;character<4;character++){
    await page.evaluate(character=>localStorage.setItem('rcsk.selection.v1',
      JSON.stringify({character,difficulty:1,country:0,race:0})),character);
    await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
    await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
    await page.evaluate(()=>{
      const view=rcsk.viewer;view.clock.pause();
      window.animationProbe={now:view.clock.tick*25,rows:[],geometryMismatches:0};
      const visual=view.playerVisual,advance=visual.advanceAnimation.bind(visual);
      visual.advanceAnimation=(now,requests)=>{
        advance(now,requests);
        const animation=visual.animation;
        const expected=visual.frames.get(animation.displayedFrame.file).attributes.position.array;
        const actual=visual.driver.geometry.attributes.position.array;
        if(expected.length!==actual.length||expected.some((value,i)=>value!==actual[i]))
          animationProbe.geometryMismatches++;
        animationProbe.rows.push({now,sequence:animation.displayedSequence,
          file:animation.displayedFrame.source,queue:[...animation.queue],
          requests:requests.map(request=>request.name),speed:view.motion.body.forwardSpeed,
          lateral:view.motion.body.lateralSpeed,input:view.input.snapshot()});
      };
    });
    const step=async ticks=>page.evaluate(ticks=>{
      const view=rcsk.viewer;
      for(let i=0;i<ticks;i++)view.onTick(.025,animationProbe.now+=25);
      view.updatePresentation(1);view.renderer.render(view.scene,view.camera);view.hud.render();
    },ticks);
    await page.keyboard.down('ArrowUp');await step(100);
    await page.keyboard.down('ArrowLeft');await step(100);
    await page.keyboard.up('ArrowLeft');await page.keyboard.down('ArrowRight');await step(100);
    await page.keyboard.up('ArrowRight');await page.keyboard.up('ArrowUp');
    await page.keyboard.down('ArrowDown');await step(220);await page.keyboard.up('ArrowDown');
    const driving=await page.evaluate(()=>{
      const p=animationProbe;
      return {sequences:[...new Set(p.rows.map(row=>row.sequence))],
        requested:[...new Set(p.rows.flatMap(row=>row.requests))],
        geometryMismatches:p.geometryMismatches,
        inputs:p.rows.filter(row=>row.input.steer||row.input.brake).length,
        minSpeed:Math.min(...p.rows.map(row=>row.speed)),rows:p.rows};
    });
    assert.equal(driving.geometryMismatches,0);
    assert.ok(driving.inputs>0);
    // Exact sequences reached depend on the actual contacts and nearby racers.
    // Both lean directions must at least reach the real player callback.
    assert.ok(driving.requested.includes('idle_steer_left'),`character${character} left lean requested`);
    assert.ok(driving.requested.includes('idle_steer_right'),`character${character} right lean requested`);
    assert.ok(driving.requested.includes('idle_back'),`character${character} reverse requested`);
    assert.ok(driving.sequences.some(name=>name.includes('steer_')),`character${character} visible lean`);
    await page.screenshot({path:`evidence/animations/character-${character}-driven.png`});
    const events=await page.evaluate(async()=>{
      const {createDriverAnimation}=await import('/source/player-assets.js');
      const view=rcsk.viewer,sim=view.simulation,visual=view.playerVisual,index=sim.actors.length-1;
      const results=[];
      for(const callback of [0x4362f0,0x411830,0x411b40,0x411e50,0x412090]){
        visual.animation=createDriverAnimation(visual.spec.driver);
        visual.animation.clocks.idle.frame=7;
        visual.animation.clocks.idle.completedLoops=0;
        visual.animation.clocks.idle.lastTime=animationProbe.now+60000;
        sim.dispatchAnimation(index,{callback});
        const submitted={queue:[...visual.animation.queue],headFrame:visual.animation.clocks.idle.frame};
        // Finish the existing head through its normal clock. The newly queued
        // CHEER/HIT must become the displayed mesh in that same callback.
        visual.animation.clocks.idle.frame=visual.spec.driver.sequences.idle.frames.length-1;
        visual.advanceAnimation(animationProbe.now+61000,[]);
        const expected=visual.frames.get(visual.animation.displayedFrame.file).attributes.position.array;
        const actual=visual.driver.geometry.attributes.position.array;
        results.push({callback:callback.toString(16),submitted,
          displayed:visual.animation.displayedSequence,source:visual.animation.displayedFrame.source,
          headFrame:visual.animation.clocks[visual.animation.queue[0]].frame,
          geometryMatches:expected.length===actual.length&&expected.every((value,i)=>value===actual[i])});
      }
      return results;
    });
    for(const event of events){
      const expected=event.callback==='4362f0'?'cheer':'hit';
      assert.deepEqual(event.submitted.queue,['idle',expected]);
      assert.equal(event.submitted.headFrame,0);
      assert.equal(event.displayed,expected);
      assert.equal(event.headFrame,0);
      assert.equal(event.geometryMatches,true);
    }
    report.checks.push({character,driving,events});
    await writeFile('evidence/animations/browser.json',JSON.stringify(report,null,2)+'\n');
  }
  assert.deepEqual(report.errors,[]);
  report.status='passed';
  await writeFile('evidence/animations/browser.json',JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,characters:report.checks.length,
    callbackFixtures:report.checks.flatMap(check=>check.events).length,errors:report.errors}));
}finally{await browser.close();}
