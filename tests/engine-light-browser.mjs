import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

// "Motorlicht volgt de kart": 488850 builds each flare from the same render
// matrix the kart is drawn with in that native frame. The browser draws karts
// between their last two tick poses; this checks the flare against that pose.
const directory='evidence/engine-lights';
const report={scope:'Kart flare position and visible pixels against the interpolated kart, setting off and on, with deterministic 25 ms updates. No Windows framebuffer comparison.',checks:[],errors:[]};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true});
try{
  await mkdir(directory,{recursive:true});
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',e=>report.errors.push(e.message));
  page.on('console',e=>{if(e.type()==='error')report.errors.push(e.text());});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  await page.keyboard.down('ArrowUp');
  await page.evaluate(()=>{
    const view=rcsk.viewer,sim=view.simulation;view.clock.pause();
    let now=view.clock.simulationMs;
    for(let tick=0;tick<2000&&sim.playerSpeedKmh<100;tick++)view.onTick(.025,now+=25);
    view.active=false;window.engineLightNow=now;
  });
  for(const follow of [false,true]){
    const rows=await page.evaluate(async follow=>{
      const THREE=await import('three'),view=rcsk.viewer,sim=view.simulation;
      view.setSmoothEngineLights(follow);
      // Two updates: the flare history restarts when the setting changes.
      for(let i=0;i<2;i++)view.onTick(.025,window.engineLightNow+=25);
      const gl=view.renderer.getContext(),width=gl.drawingBufferWidth,height=gl.drawingBufferHeight;
      const pixels=()=>{view.renderScene();gl.bindFramebuffer(gl.FRAMEBUFFER,null);
        const a=new Uint8Array(width*height*4);gl.readPixels(0,0,width,height,gl.RGBA,gl.UNSIGNED_BYTE,a);return a;};
      const kart=view.playerVisual,jet=sim.streams.jets.find(entry=>entry.body===view.motion.body);
      const mesh=view.streamVisuals.jets[sim.streamFrames.jets.indexOf(jet.vertices)];
      const step=kart.current.position.distanceTo(kart.previous.position),rows=[];
      for(const alpha of [0,.25,.5,.75,1]){
        view.updatePresentation(alpha);
        const a=mesh.geometry.attributes.position.array,centre=new THREE.Vector3();
        for(let i=0;i<4;i++)centre.add(new THREE.Vector3(a[i*3],a[i*3+1],a[i*3+2]).multiplyScalar(.25));
        const local=centre.applyMatrix4(kart.group.matrix.clone().invert()).toArray();
        mesh.visible=false;const off=pixels();mesh.visible=true;const on=pixels();
        let changed=0;
        for(let i=0;i<on.length;i+=4)if(on[i]!==off[i]||on[i+1]!==off[i+1]||on[i+2]!==off[i+2])changed++;
        rows.push({follow,alpha,kmh:sim.playerSpeedKmh,step,local,changed,
          following:Boolean(mesh.userData.follow),errors:[...view.errors]});
      }
      view.updatePresentation(0);view.renderScene();
      return rows;
    },follow);
    await page.screenshot({path:`${directory}/alpha-0-${follow?'on':'off'}.png`});
    report.checks.push(...rows);
  }
  await page.keyboard.up('ArrowUp');
  const rows=follow=>report.checks.filter(row=>row.follow===follow);
  for(const row of report.checks){
    assert.ok(row.kmh>=100&&row.step>5,`racing speed ${row.kmh} km/h, ${row.step} units per update`);
    assert.equal(row.following,row.follow);assert.deepEqual(row.errors,[]);
    // Exactly the native offset when the kart and flare share a pose.
    const expected=row.follow||row.alpha===1?[0,10,-28]:[0,10,-28+(1-row.alpha)*row.step];
    row.local.forEach((value,axis)=>assert.ok(Math.abs(value-expected[axis])<(axis===2&&!row.follow?.05*row.step+.01:.01),
      `alpha ${row.alpha} follow ${row.follow}: local ${row.local}`));
  }
  // kart03 ends at z=-27.615: off, a frame early in the update hides the
  // flare's centre in the engine; on, it keeps its pixels at every alpha.
  const at=(follow,alpha)=>rows(follow).find(row=>row.alpha===alpha).changed;
  assert.ok(at(false,0)<at(false,1)*.8,`off: ${at(false,0)} of ${at(false,1)}`);
  for(const row of rows(true))assert.ok(row.changed>at(true,1)*.9,`on alpha ${row.alpha}: ${row.changed} of ${at(true,1)}`);
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);process.exitCode=1;}
finally{
  await writeFile(`${directory}/browser.json`,JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,rows:report.checks.map(({follow,alpha,kmh,step,local,changed})=>
    ({follow,alpha,kmh,step:+step.toFixed(3),local:local.map(v=>+v.toFixed(3)),changed})),failure:report.failure,errors:report.errors},null,1));
}
