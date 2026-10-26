// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,
  args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
try{
  const page=await browser.newPage({viewport:{width:960,height:720}});
  const errors=[];page.on('pageerror',error=>errors.push(String(error)));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/assets/config.json');
  await page.setContent('<script type="importmap">{"imports":{"three":"/node_modules/three/build/three.module.js","three/addons/":"/node_modules/three/examples/jsm/"}}</script><canvas style="width:960px;height:720px"></canvas>');
  await mkdir('evidence/race-effects',{recursive:true});
  const shadow=await page.evaluate(async()=>{
    const [{TrackViewer},{KartShadowVisual,FinishFlagVisual},{getPlayerVisualSpec},{createNativeTrack},
      {setNativeMatrix},THREE,{createNativeMeshMaterial},{nativeObjectRenderOrder}]=await Promise.all([import('/source/world.js'),import('/source/race-visuals.js'),
      import('/source/player-assets.js'),import('/source/simulation/native-track.js'),import('/source/render-transforms.js'),
      import('three'),import('/source/asset-materials.js'),import('/source/render-order.js')]);
    window.viewer=new TrackViewer(document.querySelector('canvas'));
    viewer.renderer.setSize(960,720,false);await viewer.load(0);viewer.clock.pause();
    const [config,manifest]=await viewer.resources,spec=getPlayerVisualSpec(config,manifest,0,0);
    window.world=createNativeTrack(viewer.track);
    const position=[...viewer.track.route[0].position];position[1]+=12;
    const actor={body:{position,matrix:[1,0,0,0,1,0,0,0,1],sector:0}};
    viewer.motion=actor;viewer.opponents=[];
    const kart=new THREE.Mesh(await viewer.model(spec.body.mesh),createNativeMeshMaterial(await viewer.texture(spec.body.texture)));
    kart.position.fromArray(position);kart.renderOrder=nativeObjectRenderOrder(viewer.track.placements.length);
    setNativeMatrix(kart,actor.body.matrix);viewer.group.add(kart);
    window.shadow=await KartShadowVisual.load(viewer,manifest,spec.body,actor);
    shadow.capture(world);shadow.present(1);
    viewer.camera.aspect=4/3;viewer.camera.updateProjectionMatrix();
    viewer.camera.position.set(position[0]+60,position[1]+80,-position[2]+95);
    viewer.camera.lookAt(position[0],position[1]-5,-position[2]);
    const gl=viewer.renderer.getContext();
    const pixels=()=>{viewer.renderer.render(viewer.scene,viewer.camera);const a=new Uint8Array(960*720*4);
      gl.readPixels(0,0,960,720,gl.RGBA,gl.UNSIGNED_BYTE,a);return a;};
    shadow.mesh.visible=false;const before=pixels();shadow.mesh.visible=true;const after=pixels();
    let changed=0,darker=0;
    for(let i=0;i<before.length;i+=4)if(before[i]!==after[i]||before[i+1]!==after[i+1]||before[i+2]!==after[i+2]){
      changed++;if(after[i]+after[i+1]+after[i+2]<before[i]+before[i+1]+before[i+2])darker++;
    }
    window.finishFlag=await FinishFlagVisual.load(viewer,manifest);
    return{changed,darker,position:shadow.current.position,vertices:shadow.mesh.geometry.attributes.position.count,
      alpha:Array.from(shadow.mesh.geometry.attributes.color.array).filter((_,i)=>i%4===3)};
  });
  assert.ok(shadow.changed>10);assert.equal(shadow.darker,shadow.changed);assert.equal(shadow.vertices,4);
  assert.deepEqual(shadow.alpha,[128,128,128,128]);
  await page.screenshot({path:'evidence/race-effects/shadow-inspection.png'});
  const flag=await page.evaluate(()=>{
    const gl=viewer.renderer.getContext(),pixels=()=>{viewer.renderer.render(viewer.scene,viewer.camera);
      const a=new Uint8Array(960*720*4);gl.readPixels(0,0,960,720,gl.RGBA,gl.UNSIGNED_BYTE,a);return a;};
    const before=pixels();finishFlag.setEnabled(true,.025);finishFlag.capture();const after=pixels();
    let changed=0;for(let i=0;i<before.length;i+=4)
      if(before[i]!==after[i]||before[i+1]!==after[i+1]||before[i+2]!==after[i+2])changed++;
    const z=finishFlag.mesh.geometry.attributes.position.array.filter((_,i)=>i%3===2);
    return{changed,visible:finishFlag.mesh.visible,vertices:z.length,minimumZ:Math.min(...z),maximumZ:Math.max(...z)};
  });
  assert.ok(flag.changed>10000);assert.equal(flag.vertices,340);assert.equal(flag.visible,true);
  await page.screenshot({path:'evidence/race-effects/finish-flag-inspection.png'});
  assert.deepEqual(errors,[]);
  await writeFile('evidence/race-effects/browser.json',JSON.stringify({shadow,flag,errors},null,2)+'\n');
  console.log('Original kart shadow darkens actual track; original finish flag renders340 animated atlas vertices.');
}finally{await browser.close();}
