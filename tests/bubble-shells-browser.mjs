import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const directory='evidence/bubble-shells';
await mkdir(directory,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),checks:[],errors:[],
  scope:'Controlled real-browser weapon contacts and termination inputs exercise the actual combat, shell manager, DrivingView capture and WebGL draw. Inventory grants and victim contact positions are explicit test fixtures, not a claim of an unaided race. Original manager behavior is separately checked against 480 x86 operations.'};
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  await page.evaluate(()=>{
    const view=rcsk.viewer;view.clock.pause();
    window.bubbleProbe={now:view.clock.tick*25,draws:0,preMovement:null};
    const manager=view.simulation.bubbles,step=manager.step.bind(manager);
    manager.step=()=>{
      step();
      bubbleProbe.preMovement=manager.entries.map(entry=>entry&&[...entry.position]);
    };
    for(const mesh of view.bubbleVisuals.meshes)mesh.onBeforeRender=()=>bubbleProbe.draws++;
  });
  const hit=async(type,victim)=>page.evaluate(({type,victim})=>{
    const view=rcsk.viewer,sim=view.simulation,index=victim==='player'?sim.actors.length-1:0;
    const shooter=index===0?sim.actors.length-1:0;
    // Isolate this controlled contact from level2's other fan projectiles.
    // Those have separate coverage; they must not re-hit during replacement.
    for(const old of [...sim.combat.shots,...sim.combat.secondaryShots])if(old.state===2){
      sim.combat.onProjectileState?.(old,1);sim.combat.arms.remove(old);old.state=1;
    }
    Object.assign(sim.pickups.owned[shooter],{type,level:2,state:2});
    const shot=sim.combat.fire(shooter).shots[0];
    sim.actors[index].body.position.splice(0,3,...shot.position);
    // Keep the other starting-grid racers outside this isolated hit query.
    const others=sim.actors.map(actor=>[...actor.body.position]);
    sim.actors.forEach((actor,i)=>{if(i!==index)actor.body.position[0]+=50000;});
    const events=sim.combat.step(.025,sim.engineMs/1000);
    sim.actors.forEach((actor,i)=>{if(i!==index)actor.body.position.splice(0,3,...others[i]);});
    return {index,events:events.map(event=>({type:event.type,racer:event.racer})),
      attached:sim.bubbles.entries.filter(Boolean).map(entry=>entry.racer)};
  },{type,victim});
  const tick=async()=>page.evaluate(()=>{
    const view=rcsk.viewer;view.onTick(.025,bubbleProbe.now+=25);
    view.updatePresentation(1);bubbleProbe.draws=0;view.renderer.render(view.scene,view.camera);view.hud.render();
    return {draws:bubbleProbe.draws,preMovement:bubbleProbe.preMovement,
      shells:view.simulation.bubbles.entries.map(entry=>entry&&({racer:entry.racer,position:entry.position,sector:entry.sector})),
      meshes:view.bubbleVisuals.meshes.map(mesh=>({visible:mesh.visible,position:mesh.position.toArray(),
        sector:mesh.userData.sector,mode:mesh.material.userData.native.mode})),
      playerPosition:[...view.motion.body.position],kartVisible:view.playerVisual.group.visible,
      cameraMode:view.playerCamera.mode,errors:view.errors};
  });
  const attached=await hit(2,'player');
  assert.ok(attached.events.some(event=>event.type==='hit'&&event.racer===attached.index));
  assert.deepEqual(attached.attached,[attached.index]);
  const moved=await tick(),slot=moved.shells.findIndex(Boolean);
  assert.ok(slot>=0);assert.ok(moved.draws>0);
  assert.deepEqual(moved.shells[slot].position,moved.preMovement[slot]);
  assert.deepEqual(moved.meshes[slot].position,moved.preMovement[slot]);
  assert.equal(moved.meshes[slot].mode,2);
  assert.notDeepEqual(moved.playerPosition,moved.preMovement[slot]);
  report.checks.push({case:'native contact attaches original shell at captured pre-movement pose',attached,moved});
  await page.screenshot({path:`${directory}/player-hit.png`});
  await page.keyboard.down('Digit2');
  const firstPerson=await tick();
  await page.keyboard.up('Digit2');
  assert.equal(firstPerson.cameraMode,3);assert.equal(firstPerson.kartVisible,false);
  assert.ok(firstPerson.meshes.some(mesh=>mesh.visible));assert.ok(firstPerson.draws>0);
  report.checks.push({case:'first-person kart hiding leaves independent shell submitted',firstPerson});
  await page.screenshot({path:`${directory}/first-person-hit.png`});
  const replacement=await hit(4,'player'),replaced=await tick();
  report.replacementDebug={replacement,replaced};
  assert.deepEqual(replacement.attached,[]);
  assert.ok(replaced.meshes.every(mesh=>!mesh.visible));
  report.checks.push({case:'replacement hit detaches previous bubble',replacement,replaced});
  const npc=await hit(2,'npc');
  assert.deepEqual(npc.attached,[0]);
  await tick();
  const settled=await page.evaluate(()=>{
    const view=rcsk.viewer,sim=view.simulation,actor=sim.actors[0];
    sim.combat.effects[0].remaining=-1;
    actor.ground.groundCount=4;actor.ground.wheels[2].verticalSpeed=0;
    const active=sim.combat.prepareEffect(0,.025);
    view.bubbleVisuals.capture();
    return {active,visible:sim.combat.effects[0].bubbleVisible,
      entries:sim.bubbles.entries.filter(Boolean).length,
      meshes:view.bubbleVisuals.meshes.filter(mesh=>mesh.visible).length};
  });
  assert.deepEqual(settled,{active:false,visible:false,entries:0,meshes:0});
  report.checks.push({case:'NPC shell uses actual settled-effect cleanup',npc,settled});
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile(`${directory}/browser.json`,JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors}));
}
