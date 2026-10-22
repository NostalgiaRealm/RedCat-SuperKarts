import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
const directory='evidence/display';
await mkdir(directory,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),checks:[],errors:[],
  scope:'Controlled native rescue enqueue and blend-state presets test actual WebGL draw callbacks; source instruction fixtures separately prove the option branches. No original framebuffer comparison.'};
try{
  const page=await browser.newPage({viewport:{width:800,height:600}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  for(const enabled of [false,true]){
    const state=await page.evaluate(async enabled=>{
      const THREE=await import('three'),view=rcsk.viewer;
      view.clock.pause();view.displaySettings={alphaBlending:enabled};
      await view.load(0);view.clock.pause();
      const sim=view.simulation;
      sim.rescue.enqueue(view.motion);
      view.onTick(.025,25);view.updatePresentation(1);
      const shadow=view.shadows[0].mesh,draws=[];
      shadow.onAfterRender=()=>draws.push([shadow.material.blendSrc,shadow.material.blendDst]);
      view.nativeBlendState.setNative(6,5);
      view.renderer.render(view.scene,view.camera);
      const first=draws[0];draws.length=0;
      view.hud.render();
      view.renderer.render(view.scene,view.camera);
      return {enabled,first,afterHud:draws[0],shadowInherited:shadow.userData.nativeInheritBlend,
        expectedInherited:[THREE.OneMinusSrcAlphaFactor,THREE.SrcAlphaFactor],
        expectedNormal:[THREE.SrcAlphaFactor,THREE.OneMinusSrcAlphaFactor],
        clouds:sim.smoke.enabled,arms:sim.combat.arms.enabled,
        ribbons:sim.streams.ribbons.length,jets:sim.streams.jets.length,
        rescueAngle:sim.rescue.get(view.motion.body).angle,
        rescueStrips:view.rescueVisuals.meshes.filter(mesh=>mesh.visible).length,errors:view.errors};
    },enabled);
    assert.equal(state.shadowInherited,!enabled);
    assert.deepEqual(state.first,enabled?state.expectedNormal:state.expectedInherited);
    assert.deepEqual(state.afterHud,state.expectedNormal);
    assert.equal(state.clouds,enabled);assert.equal(state.arms,enabled);
    assert.equal(state.rescueAngle>0,enabled);assert.equal(state.rescueStrips>0,enabled);
    if(!enabled){assert.equal(state.ribbons,0);assert.equal(state.jets,0);}
    assert.deepEqual(state.errors,[]);report.checks.push(state);
  }
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile(`${directory}/alpha-browser.json`,JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors}));
}
