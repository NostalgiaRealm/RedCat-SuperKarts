import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const errors=[],checks=[];
await mkdir('evidence/weather',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>errors.push(error.message));
  for(const [id,kind] of [[1,'snow'],[2,'rain']]){
    await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+`/?drive=${id}`);
    await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
    await page.waitForFunction(()=>rcsk.viewer.weatherVisuals.mesh.visible);
    const state=await page.evaluate(()=>{
      const view=rcsk.viewer,sim=view.simulation,mesh=view.weatherVisuals.mesh;
      return {kind:sim.weather.kind,count:sim.weather.count,paused:sim.weather.paused,
        age:sim.weather.particles[0].age,vertices:mesh.geometry.drawRange.count,
        relativeToCamera:mesh.parent===view.camera,depthTest:mesh.material.depthTest,
        depthWrite:mesh.material.depthWrite,weatherOrder:mesh.renderOrder,flagOrder:view.finishFlag.mesh.renderOrder,
        errors:view.errors};
    });
    assert.equal(state.kind,kind);assert.equal(state.count,400);assert.equal(state.paused,false);
    assert.equal(state.vertices,2400);assert.equal(state.relativeToCamera,true);
    assert.equal(state.depthTest,true);assert.equal(state.depthWrite,false);
    assert.ok(state.weatherOrder>state.flagOrder);assert.ok(state.age>0);
    assert.deepEqual(state.errors,[]);
    await page.screenshot({path:`evidence/weather/${kind}.png`});checks.push(state);
  }
  const effects=await page.evaluate(()=>{
    const view=rcsk.viewer,sim=view.simulation;
    view.clock.pause();
    sim.combat.onExplosion(sim.motion.body);
    let now=view.clock.tick*25;
    for(let tick=0;tick<12;tick++)view.onTick(.025,now+=25);
    view.updatePresentation(1);view.renderer.render(view.scene,view.camera);view.hud.render();
    const mesh=[...view.explosionVisuals.meshes.values()][0],visual=view.playerVisual;
    const rgba=[visual.renderDiffuse>>>16&255,visual.renderDiffuse>>>8&255,visual.renderDiffuse&255,visual.renderDiffuse>>>24];
    return {case:'controlled combat explosion callback and kart color binding',
      explosionCount:view.explosionVisuals.meshes.size,
      vertices:mesh.geometry.attributes.position.count,
      depthWrite:mesh.material.depthWrite,renderOrder:mesh.renderOrder,
      uniformColor:[visual.body,...visual.wheels,visual.driver].every(part=>
        part.geometry.attributes.color.array.every((value,index)=>value===rgba[index%4])),
      diffuse:visual.diffuse,renderDiffuse:visual.renderDiffuse};
  });
  assert.ok(effects.explosionCount>=1);assert.equal(effects.vertices,24);
  assert.equal(effects.depthWrite,true);assert.ok(effects.renderOrder>1100);assert.equal(effects.uniformColor,true);
  checks.push(effects);await page.screenshot({path:'evidence/weather/rocket-ring.png'});
  assert.deepEqual(errors,[]);
  await writeFile('evidence/weather/browser.json',JSON.stringify({status:'passed',browser:browser.version(),
    checks,errors,scope:'Original weather pool, camera-space render binding and source blend/depth settings in Chromium. Native fixtures independently verify geometry and particle arithmetic; no original Wine race screenshot comparison is claimed.'},null,2)+'\n');
  console.log(JSON.stringify({status:'passed',checks:checks.length,errors}));
}finally{await browser.close();}
