import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const errors=[],checks=[];
await mkdir('evidence/streams-squash',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)errors.push(`${response.status()} ${response.url()}`);});
  page.on('requestfailed',request=>errors.push(`${request.failure()?.errorText} ${request.url()}`));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  await page.keyboard.down('ArrowUp');
  const streams=await page.evaluate(()=>{
    const view=rcsk.viewer,sim=view.simulation;view.clock.pause();
    sim.combat.onTurbo(sim.actors.length-1,3);
    let now=view.clock.tick*25;
    for(let tick=0;tick<20;tick++)view.onTick(.025,now+=25);
    view.updatePresentation(1);view.renderer.render(view.scene,view.camera);view.hud.render();
    const exact=(meshes,frames)=>frames.every((vertices,index)=>
      Array.from(meshes[index].geometry.attributes.position.array.slice(0,vertices.length*3))
        .every((value,i)=>value===vertices[Math.floor(i/3)].position[i%3]));
    return {case:'original turbo callback creates native jet/ribbon packets',
      jets:sim.streamFrames.jets.length,ribbons:sim.streamFrames.ribbons.length,
      exactJets:exact(view.streamVisuals.jets,sim.streamFrames.jets),
      exactRibbons:exact(view.streamVisuals.ribbons,sim.streamFrames.ribbons),
      blendSrc:view.streamVisuals.material.blendSrc,blendDst:view.streamVisuals.material.blendDst,
      depthWrite:view.streamVisuals.material.depthWrite,errors:view.errors};
  });
  await page.keyboard.up('ArrowUp');
  assert.ok(streams.jets>0);assert.ok(streams.ribbons>0);
  assert.equal(streams.exactJets,true);assert.equal(streams.exactRibbons,true);
  assert.equal(streams.blendSrc,201);assert.equal(streams.blendDst,201);
  assert.equal(streams.depthWrite,true);assert.deepEqual(streams.errors,[]);
  checks.push(streams);await page.screenshot({path:'evidence/streams-squash/streams.png'});
  const order=await page.evaluate(()=>{
    const view=rcsk.viewer,log=[],restore=[];
    const watch=(mesh,label)=>{
      restore.push([mesh,mesh.onBeforeRender,mesh.frustumCulled]);
      mesh.frustumCulled=false;
      mesh.onBeforeRender=(renderer,scene,camera,geometry,material,group)=>
        log.push({label,group:group?{start:group.start,count:group.count,materialIndex:group.materialIndex}:null});
    };
    watch(view.roadMesh,'road');if(view.sky)watch(view.sky,'sky');
    for(const [index,visual]of [view.playerVisual,...view.opponentVisuals].entries()){
      visual.group.visible=true;visual.group.traverse(mesh=>mesh.layers.enable(0));
      view.shadows[index].mesh.visible=true;view.shadows[index].mesh.layers.enable(0);
      watch(view.shadows[index].mesh,`shadow${index}`);
      [visual.body,...visual.wheels,visual.driver].forEach((mesh,part)=>watch(mesh,`kart${index}:${part}`));
    }
    for(const mesh of view.group.children)
      if(Number.isInteger(mesh.userData.placementIndex)&&!mesh.material.transparent)watch(mesh,'scenery');
    view.renderer.render(view.scene,view.camera);
    for(const [mesh,callback,culled]of restore){mesh.onBeforeRender=callback;mesh.frustumCulled=culled;}
    return {case:'native world draw order',log,
      expectedRoad:view.roadMesh.geometry.groups.map(group=>({start:group.start,count:group.count,materialIndex:group.materialIndex})),
      count:view.opponentVisuals.length+1,skyDepthWrite:view.sky?.material.depthWrite};
  });
  assert.deepEqual(order.log.filter(x=>x.label==='road').map(x=>x.group),order.expectedRoad);
  const labels=order.log.map(x=>x.label);
  assert.ok(labels.lastIndexOf('road')<labels.indexOf('sky'));
  assert.ok(labels.indexOf('sky')<labels.indexOf('shadow0'));
  assert.ok(labels.lastIndexOf('scenery')<labels.indexOf('shadow0'));
  for(let i=0;i<order.count;i++)
    assert.deepEqual(labels.slice(labels.indexOf(`shadow${i}`),labels.indexOf(`shadow${i}`)+7),
      [`shadow${i}`,...Array.from({length:6},(_,part)=>`kart${i}:${part}`)]);
  assert.equal(order.skyDepthWrite,true);checks.push(order);
  const squash=await page.evaluate(()=>{
    const view=rcsk.viewer,sim=view.simulation;
    view.active=false; // Keep the diagnostic prop camera fixed for its screenshot.
    const hazard=sim.sceneryHazards.objects.find(object=>object.type===44);
    const original=hazard.matrix[4];
    sim.sceneryHazards.stepPlacement(hazard.placementIndex,.025,sim.nativeTickMs,{
      player:sim.motion.body,opponents:sim.opponents.map(actor=>actor.body),
      playerPosition:hazard.position,ranges:[[0,sim.world.sectors.length-1]]});
    sim.squash.step(.025,sim.nativeTickMs);view.captureSceneryBodies();
    const mesh=view.sceneryBodyMeshes.get(hazard.placementIndex);
    view.camera.position.set(hazard.position[0]+65,hazard.position[1]+45,-hazard.position[2]+85);
    view.camera.lookAt(hazard.position[0],hazard.position[1],-hazard.position[2]);
    mesh.layers.enable(0);view.renderer.render(view.scene,view.camera);
    return {case:'original type44 source callback self-squashes the displayed prop',
      active:sim.squash.find(hazard).active,playerActive:sim.squash.find(sim.motion.body).active,
      before:original,after:hazard.matrix[4],render:mesh.matrix.elements[5],
      position:hazard.position,meshPosition:mesh.position.toArray()};
  });
  assert.equal(squash.active,true);assert.equal(squash.playerActive,false);
  assert.notEqual(squash.after,squash.before);assert.equal(squash.render,squash.after);
  assert.deepEqual(squash.position,squash.meshPosition);checks.push(squash);
  await page.screenshot({path:'evidence/streams-squash/squashed-prop.png'});
  assert.deepEqual(errors,[]);
  await writeFile('evidence/streams-squash/browser.json',JSON.stringify({
    status:'passed',browser:browser.version(),checks,errors,
    scope:'Controlled original callback inputs validate WebGL packet/transform bindings and draw order. Native x86 fixtures separately establish the rules; no full original race screenshot comparison is claimed.',
  },null,2)+'\n');
  console.log(JSON.stringify({status:'passed',checks:checks.length,errors}));
}finally{await browser.close();}
