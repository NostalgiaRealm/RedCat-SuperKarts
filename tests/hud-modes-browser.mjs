import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';

const output=process.env.RCSK_HUD_MODE_OUTPUT||'evidence/hud-mode-audit/browser';
await mkdir(output,{recursive:true});
const files=['src/race-hud.js','src/race-hud-meshes.js','src/hud-text.js',
  'src/hud-text-renderer.js','src/hud-draw-order.js','src/multisample-renderer.js',
  'src/race-hud-layout.js','src/hud-gameplay-events.js','src/driving-view.js',
  'src/simulation/native-combat.js','src/simulation/native-star-hud.js',
  'src/simulation/native-hud-arrows.js','src/simulation/native-race.js',
  'public/assets/config.json','tests/hud-modes-browser.mjs'];
const hashes=async()=>Object.fromEntries(await Promise.all(files.map(async file=>[file,
  createHash('sha256').update(await readFile(file)).digest('hex')])));
const report={status:'running',scope:'Source-only software-WebGL HUD integration. Mode reloads use original assets/config. Combat cases fire original weapons and place only the projectile at a controlled contact before the real NativeBonusCombat.step. Arrow cases use disclosed controlled orientation/velocity and an original marker54 dispatch. Actor positions, race progress and HUD text are not assigned. No full-race or packaged-app coverage is claimed.',checks:[],errors:[],hashesBefore:await hashes()};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
try{
  const page=await browser.newPage({viewport:{width:1280,height:720}});
  page.on('pageerror',error=>report.errors.push(error.stack||error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.addInitScript(()=>{
    localStorage.setItem('rcsk.selection.v1',JSON.stringify({character:1,difficulty:0,country:0,race:0}));
    localStorage.setItem('rcsk.settings.v1',JSON.stringify({touch:'on'}));
  });
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4174')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
  await page.evaluate(()=>rcsk.viewer.clock.pause());
  const load=async mode=>page.evaluate(async mode=>{
    const v=rcsk.viewer;v.clock.pause();
    await v.load(0,{character:1,difficulty:0,raceMode:mode});v.clock.pause();
    v.hudMeshes.capture(v.motion.body.position,0);v.hud.update(v.race,0);
    v.updatePresentation(1);v.renderScene();v.hud.render();
  },mode);
  const snapshot=()=>page.evaluate(()=>{
    const v=rcsk.viewer,h=v.hudMeshes;
    return {mode:v.race.raceType,opponents:v.opponents.length,
      characters:[...v.simulation.setup.opponents,v.simulation.setup.player].map(c=>c.name),
      text:{...v.hud.text},remainingMs:v.race.remainingMs,
      elements:Object.fromEntries([...h.elements].map(([id,e])=>[id,{visible:e.mesh.visible,
        mesh:h.spec(id).mesh,texture:h.spec(id).texture,rgba:[...e.mesh.geometry.attributes.color.array.slice(0,4)]}])),
      layout:{portrait:v.hud.layout.portrait,scale:v.hud.layout.scale}};
  });
  const rankIds=['first','second','third','fourth','fifth'];
  for(const mode of [0,1,2,3]){
    await load(mode);const state=await snapshot();
    assert.equal(state.opponents,[4,3,3,1][mode]);
    assert.ok(state.elements.track.visible&&state.elements.dotplayer.visible);
    for(let i=0;i<5;i++)assert.equal(Boolean(state.elements[`dotracer${i}`]?.visible),i<state.opponents);
    for(let i=0;i<5;i++)assert.equal(Boolean(state.elements[rankIds[i]]?.visible),i<=state.opponents);
    assert.equal(Object.keys(state.elements).filter(id=>id.startsWith('portr')).length,state.opponents+1);
    for(const id of ['string_lap','string_laptime','string_bestlap','string_lap_value',
      'string_lapof_value','string_laptime_value','string_bestlap_value'])assert.ok(state.text[id]);
    assert.equal('string_countdown_value' in state.text,mode===1);
    assert.ok(state.elements.bonusframe.visible);assert.equal(state.text.string_bonus,'BONUS');
    for(const [id,mesh]of [['backarrow','meshes/ovlypijl.json'],['junctionarrow','meshes/spltpijl.json']]){
      assert.equal(state.elements[id].mesh,mesh);assert.equal(state.elements[id].texture,'textures/overlay1.tga.png');
    }
    assert.equal(state.elements.starflag.visible,mode===2);
    for(let i=1;i<=12;i++)assert.equal(state.elements[`star${i}`].visible,mode===2);
    report.checks.push({case:`native HUD elements and original roster in mode ${mode}`,state});
    await page.screenshot({path:`${output}/mode-${mode}-wide.png`});
    if(mode===1||mode===2){
      await page.setViewportSize({width:390,height:844});
      await page.evaluate(()=>{const v=rcsk.viewer;v.renderScene();v.hud.render();});
      assert.equal((await snapshot()).layout.portrait,true);
      await page.screenshot({path:`${output}/mode-${mode}-portrait.png`});
      await page.setViewportSize({width:1280,height:720});
    }
  }
  await load(0);
  const arrows=await page.evaluate(async()=>{
    const {nativeRotationMatrix}=await import('/src/simulation/native-transform.js');
    const v=rcsk.viewer,s=v.simulation,h=v.hudMeshes,b=s.motion.body;
    let now=s.wallMs;
    const tick=()=>v.onTick(.025,now+=25);
    const snap=()=>({input:h.arrowInput(.025),state:{...h.arrows.state},
      nodes:Object.fromEntries(['backarrow','junctionarrow'].map(id=>[id,{
        visible:h.elements.get(id).mesh.visible,
        rgba:[...h.elements.get(id).mesh.geometry.attributes.color.array.slice(0,4)]}]))});
    const originalSnapshot=v.input.snapshot;
    v.input.snapshot=()=>({throttle:0,brake:0,steer:0,bonus:0,handbrake:0});
    try{
      const initial=snap();
      b.forwardSpeed=-10;tick();const reversingWhileFacingForward=snap();
      const yaw=b.yaw;
      b.forwardSpeed=b.lateralSpeed=b.verticalSpeed=b.yawRate=0;
      b.yaw=Math.fround(yaw+2048);b.matrix=nativeRotationMatrix([b.pitch,b.yaw,b.roll]);
      const fades=[];
      for(let i=0;i<40;i++){tick();fades.push(snap());}
      v.updatePresentation(1);v.renderScene();h.viewer.hud.render();
      const wrongwayImage=v.renderer.domElement.toDataURL();
      b.yaw=yaw;b.matrix=nativeRotationMatrix([b.pitch,b.yaw,b.roll]);tick();
      const restored=snap();
      // The marker event is emitted through the original race dispatcher at
      // the pre-movement boundary, not by assigning arrow state/visibility.
      const begin=s.race.beginUpdate;
      s.race.beginUpdate=function(...args){
        s.race.beginUpdate=begin;const result=begin.apply(this,args);this.trigger(54);return result;
      };
      try{tick();}finally{s.race.beginUpdate=begin;}
      const junctionStart=snap();
      for(let i=0;i<12;i++)tick();const junctionVisible=snap();
      v.updatePresentation(1);v.renderScene();h.viewer.hud.render();
      const junctionImage=v.renderer.domElement.toDataURL();
      for(let i=0;i<32;i++)tick();const junctionEnd=snap();
      return {initial,reversingWhileFacingForward,fades,restored,junctionStart,junctionVisible,junctionEnd,wrongwayImage,junctionImage};
    }finally{v.input.snapshot=originalSnapshot;}
  });
  assert.equal(arrows.initial.input.forward,true);
  assert.equal(arrows.reversingWhileFacingForward.nodes.backarrow.visible,false);
  assert.ok(arrows.fades.every(row=>row.input.forward===false&&row.nodes.backarrow.visible));
  assert.ok(arrows.fades.some(row=>row.nodes.backarrow.rgba[3]>0));
  assert.equal(Math.max(...arrows.fades.map(row=>row.nodes.backarrow.rgba[3])),236);
  assert.equal(arrows.restored.nodes.backarrow.visible,false);
  assert.equal(arrows.junctionStart.nodes.junctionarrow.visible,true);
  assert.ok(arrows.junctionVisible.nodes.junctionarrow.rgba[3]>0);
  assert.equal(arrows.junctionEnd.nodes.junctionarrow.visible,false);
  for(const [key,file]of [['wrongwayImage','wrongway-hud.png'],['junctionImage','junction-hud.png']]){
    await writeFile(output+'/'+file,Buffer.from(arrows[key].split(',')[1],'base64'));delete arrows[key];
  }
  report.checks.push({case:'original arrow meshes follow facing, native fade, marker54 and timeout',arrows});
  await load(0);
  const contacts=await page.evaluate(()=>{
    const v=rcsk.viewer,s=v.simulation,c=s.combat,h=v.hud,player=s.actors.length-1;
    let now=s.wallMs;
    const tick=()=>v.onTick(.025,now+=25);
    const originalSnapshot=v.input.snapshot;
    v.input.snapshot=()=>({throttle:0,brake:0,steer:0,bonus:0,handbrake:0});
    const rows=[];
    try{
      for(const [name,shooter,victim]of [['player-to-NPC',player,0],['NPC-to-player',0,player],['NPC-to-NPC',0,1]]){
        h.notify(2,0,{capture:true});
        Object.assign(s.pickups.owned[shooter],{type:3,level:1,state:2});
        const shot=c.fire(shooter).shots[0],originalStep=c.step;
        let contactPose;
        c.step=function(dt,seconds){
          c.step=originalStep;
          contactPose=[...s.actors[victim].body.position];shot.position=[...contactPose];
          shot.sector=s.actors[victim].body.sector;
          return originalStep.call(c,dt,seconds);
        };
        try{tick();}finally{c.step=originalStep;}
        const hit=v.pickupEvents.find(e=>e.type==='hit'&&e.shooter===shooter&&e.racer===victim);
        if(!hit)throw Error(`Controlled ${name} projectile did not hit intended actor`);
        const afterHit={captured:h.text.string_special??null,queued:h.notifications.text,
          visible:h.notifications.visible,queue:h.notifications.queue.map(q=>q.text)};
        tick();
        rows.push({name,hit:{type:hit.type,shooter:hit.shooter,racer:hit.racer,bonus:hit.bonus,level:hit.level},
          contactPose,afterHit,nextCapture:h.text.string_special??null,
          nextAlpha:h.specialOverride?.rgba?.[3]??null});
        if(shooter===player){
          for(let i=0;i<12;i++)tick();
          v.updatePresentation(1);v.renderScene();h.render();
          rows.at(-1).hudImage=v.renderer.domElement.toDataURL();
        }
      }
    }finally{v.input.snapshot=originalSnapshot;}
    return rows;
  });
  const positive=contacts[0];
  assert.equal(positive.afterHit.captured,null);assert.equal(positive.afterHit.queued,'Raak!');
  assert.equal(positive.nextCapture,'Raak!');assert.ok(positive.nextAlpha>0);
  await writeFile(output+'/hit-hud.png',Buffer.from(positive.hudImage.split(',')[1],'base64'));
  delete positive.hudImage;
  for(const row of contacts.slice(1))assert.equal(row.nextCapture,null);
  report.checks.push({case:'actual weapon contacts dispatch Raak only for player hits, after the rendered frame',contacts});
  report.hashesAfter=await hashes();
  report.changedDuringRun=files.filter(file=>report.hashesBefore[file]!==report.hashesAfter[file]);
  assert.deepEqual(report.changedDuringRun,[]);assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=error.stack;throw error;}
finally{await writeFile(output+'/report.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(`HUD modes browser: ${report.checks.length} check groups passed`);
