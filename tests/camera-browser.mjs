import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const errors=[],checks=[];
await mkdir('evidence/camera',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>errors.push(error.message));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  const state=()=>page.evaluate(()=>{
    const view=rcsk.viewer,sim=view.simulation,camera=sim.playerCamera;
    return {mode:camera.mode,active:sim.camera===camera,body:view.playerVisual.group.visible,
      shadow:view.shadows[0].mesh.visible,damping:camera.positionDamping,
      targetOffset:camera.targetOffset,positionOffset:camera.positionOffset,
      position:camera.position,up:camera.up};
  });
  const wait=mode=>page.waitForFunction(mode=>{
    const view=rcsk.viewer;return view.simulation.playerCamera.mode===mode
      &&view.playerVisual.group.visible===view.simulation.playerCamera.bodyVisible;
  },mode);
  const shiftTick=await page.evaluate(()=>rcsk.viewer.clock.tick);
  await page.keyboard.down('Shift');
  await page.keyboard.down('Digit2');
  await page.waitForFunction(tick=>rcsk.viewer.clock.tick>=tick+4,shiftTick);
  assert.equal((await state()).mode,1);
  await page.keyboard.up('Digit2');await page.keyboard.up('Shift');
  checks.push({case:'native unmodified camera poll rejects Shift+2'});
  await page.keyboard.down('Digit2');await wait(3);await page.keyboard.up('Digit2');
  let camera=await state();
  assert.equal(camera.active,true);assert.equal(camera.body,false);assert.equal(camera.shadow,false);
  assert.equal(camera.damping,false);assert.deepEqual(camera.positionOffset,[0,15.5,-1]);
  checks.push({case:'first-person',camera});
  await page.screenshot({path:'evidence/camera/first-person.png'});
  await page.keyboard.down('Digit3');await wait(5);
  camera=await state();assert.equal(camera.body,true);assert.equal(camera.shadow,true);
  assert.equal(camera.damping,false);assert.deepEqual(camera.positionOffset,[0,23,40]);
  checks.push({case:'rear inherits first-person position damping',camera});
  await page.screenshot({path:'evidence/camera/rear.png'});
  await page.keyboard.up('Digit3');await wait(3);
  assert.equal((await state()).body,false);
  await page.keyboard.down('Digit4');await wait(0);await page.keyboard.up('Digit4');
  camera=await state();assert.deepEqual(camera.targetOffset,[0,25,0]);assert.equal(camera.damping,true);
  checks.push({case:'lower-target chase',camera});
  await page.keyboard.down('Digit3');await wait(5);await page.keyboard.up('Digit3');await wait(0);
  await page.keyboard.down('Digit1');await wait(1);await page.keyboard.up('Digit1');
  camera=await state();assert.deepEqual(camera.targetOffset,[0,50,0]);assert.equal(camera.body,true);
  checks.push({case:'normal chase',camera});
  assert.deepEqual(errors,[]);
  const report={status:'passed',browser:browser.version(),checks,errors,
    scope:'Real browser keydown/keyup controls and render visibility. Native instruction fixtures separately compare camera transform and phase/key ordering; no Wine race image comparison is claimed.'};
  await writeFile('evidence/camera/browser.json',JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,checks:checks.length,errors}));
}finally{await browser.close();}
