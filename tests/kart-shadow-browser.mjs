import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile,readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {execFileSync} from 'node:child_process';
const directory='evidence/shadow-audit';
await mkdir(directory,{recursive:true});
const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={browser:browser.version(),checks:[],errors:[],
  scope:'Original shadow texture/quad through actual WebGL materials. An isolated viewport-edge control recreates the old stale sphere; live loaded races verify kart/road ordering and both scene resolve paths. Controlled inspection cameras are not original-game screenshots.'};
report.sourceSha256=Object.fromEntries(await Promise.all(['source/world.js','source/kart-shadow.js','source/race-visuals.js',
  'source/asset-materials.js','source/multisample-renderer.js','tests/kart-shadow-browser.mjs']
  .map(async path=>[path,createHash('sha256').update(await readFile(path)).digest('hex')])));
try{
  const page=await browser.newPage({viewport:{width:960,height:720}});
  page.on('pageerror',error=>report.errors.push(error.message));
  // HTTP failures are recorded with their URL below, except optional favicon.
  page.on('console',message=>{if(message.type()==='error'&&!message.text().startsWith('Failed to load resource:'))report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400&&!response.url().endsWith('favicon.ico'))report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto(origin+'/assets/config.json');
  await page.setContent('<style>body{margin:0}</style><script type="importmap">{"imports":{"three":"/node_modules/three/build/three.module.js","three/addons/":"/node_modules/three/examples/jsm/"}}</script><canvas style="width:960px;height:720px"></canvas>');
  const edge=await page.evaluate(async()=>{
    const [THREE,{TrackViewer},{KartShadowVisual}]=await Promise.all([
      import('three'),import('/source/world.js'),import('/source/race-visuals.js')]);
    const viewer=new TrackViewer(document.querySelector('canvas'));
    viewer.renderer.setSize(960,720,false);viewer.renderer.setClearColor(0xffffff);
    const [,manifest]=await viewer.resources;
    viewer.track={placements:[]};viewer.group=new THREE.Group();viewer.scene.add(viewer.group);
    viewer.motion={body:{position:[0,0,0],sector:0,matrix:[1,0,0,0,1,0,0,0,1]}};viewer.opponents=[];
    const shadow=await KartShadowVisual.load(viewer,manifest,manifest.meshes['kart03.d3d'],viewer.motion);
    shadow.capture({sectors:[{fallback:{normal:[0,1,0],distance:0}}]});shadow.present(1);
    const original=await viewer.model('meshes/s_shadow.json'),actualSphere=shadow.mesh.geometry.boundingSphere.clone();
    viewer.camera=new THREE.OrthographicCamera(-30,30,15,-15,1,200);
    viewer.camera.position.set(0,100,47);viewer.camera.up.set(0,0,-1);viewer.camera.lookAt(0,0,47);
    const gl=viewer.renderer.getContext(),pixels=()=>{
      viewer.renderScene();gl.bindFramebuffer(gl.FRAMEBUFFER,null);
      const out=new Uint8Array(960*720*4);gl.readPixels(0,0,960,720,gl.RGBA,gl.UNSIGNED_BYTE,out);
      let changed=0;const values=new Set();
      for(let i=0;i<out.length;i+=4)if(out[i]<255){changed++;values.add(out[i]);}
      const offset=((720-1-50)*960+480)*4;
      return{changed,values:[...values].sort((a,b)=>a-b),sampleRGBA:Array.from(out.slice(offset,offset+4))};
    };
    // Deliberately reconstruct only the pre-fix clipping state.
    shadow.mesh.geometry.boundingSphere=original.boundingSphere.clone();shadow.mesh.frustumCulled=true;
    const before=pixels();
    shadow.mesh.geometry.boundingSphere=actualSphere;shadow.mesh.frustumCulled=false;
    const after=pixels();
    viewer.multisampling.configure({msaaEnabled:true,msaaSamples:4},960,720);
    const multisampled=pixels();
    viewer.group.scale.x=-1;const mirrored=pixels();
    window.shadowProbe={viewer,shadow};
    return{before,after,multisampled,mirrored,msaa:viewer.msaaStatus,context:gl.getContextAttributes(),
      oldSphere:original.boundingSphere.radius,newSphere:actualSphere.radius,
      color:Array.from(shadow.mesh.geometry.attributes.color.array),
      texture:{premultiplyAlpha:shadow.mesh.material.map.premultiplyAlpha,filter:shadow.mesh.material.map.magFilter,
        format:shadow.mesh.material.map.userData.nativeTextureFormat}};
  });
  assert.equal(edge.before.changed,0);
  assert.ok(edge.after.changed>1000);assert.ok(edge.after.values.includes(123));
  assert.ok(edge.multisampled.changed>1000);assert.ok(edge.multisampled.values.includes(123));
  // Original alpha128 black over white is rounded into the RGB565 scene
  // attachment: red/blue15 of31 and green31 of63, with opaque presentation.
  assert.deepEqual(edge.after.sampleRGBA,[123,125,123,255]);
  assert.deepEqual(edge.multisampled.sampleRGBA,[123,125,123,255]);
  assert.equal(edge.mirrored.changed,edge.multisampled.changed);
  // A hardware MSAA sample pattern need not be reflection-symmetric at edges.
  assert.equal(edge.mirrored.values[0],123);
  assert.equal(edge.texture.premultiplyAlpha,false);assert.equal(edge.texture.format,'RGB565');
  assert.ok(edge.newSphere>edge.oldSphere);report.checks.push({kind:'viewport-edge',...edge});
  await page.screenshot({path:`${directory}/edge-corrected.png`});
  const screenPixel=JSON.parse(execFileSync('python3',['-c',
    'from PIL import Image; import json,sys; print(json.dumps(Image.open(sys.argv[1]).convert("RGB").getpixel((480,50))))',
    `${directory}/edge-corrected.png`],{encoding:'utf8'}));
  edge.screenshotPixel=screenPixel;
  report.checks[0].screenshotPixel=screenPixel;
  assert.deepEqual(screenPixel,edge.mirrored.sampleRGBA.slice(0,3),
    'Browser-composited shadow must match original backbuffer RGB, without extra canvas-alpha blending');
  await page.evaluate(()=>shadowProbe.viewer.disposeRenderer());
  for(const track of [0,3]){
    await page.goto(origin+'/?drive='+track);
    await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
    await page.waitForFunction(()=>rcsk.viewer.clock.tick>2);
    const checks=await page.evaluate(async()=>{
      const view=rcsk.viewer;view.clock.pause();view.active=false;view.updatePresentation(1);
      const THREE=await import('three'),{sampleNativeTrack}=await import('/source/simulation/native-track.js');
      const p=view.playerVisual.group.getWorldPosition(new THREE.Vector3());
      // Inspection camera shows the authored shadow under the current live kart.
      view.camera.position.set(p.x+80,p.y+100,p.z+100);view.camera.up.set(0,1,0);view.camera.lookAt(p);
      view.camera.updateProjectionMatrix();
      const gl=view.renderer.getContext(),width=gl.drawingBufferWidth,height=gl.drawingBufferHeight;
      const shadow=view.shadows[0].mesh,order=[];
      shadow.onAfterRender=()=>order.push('shadow');view.playerVisual.body.onAfterRender=()=>order.push('kart');
      const pixels=()=>{view.renderScene();gl.bindFramebuffer(gl.FRAMEBUFFER,null);
        const a=new Uint8Array(width*height*4);gl.readPixels(0,0,width,height,gl.RGBA,gl.UNSIGNED_BYTE,a);return a;};
      const checks=[];
      // Original sector-plane quad, then "Schaduwen op het wegdek".
      for(const surface of [false,true])for(const enabled of [false,true]){
        view.setSurfaceShadows(surface);
        view.multisampling.configure({msaaEnabled:enabled,msaaSamples:4},width,height);
        shadow.visible=false;const before=pixels();shadow.visible=true;order.length=0;const after=pixels();
        let changed=0,darker=0,lighter=0;
        for(let i=0;i<before.length;i+=4){const a=before[i]+before[i+1]+before[i+2],b=after[i]+after[i+1]+after[i+2];
          if(a!==b){changed++;if(b<a)darker++;else lighter++;}}
        checks.push({surface,enabled,changed,darker,lighter,order:[...order],msaa:view.msaaStatus,
          shadowCount:view.shadows.length,pose:view.shadows[0].current,
          logicalPosition:[...view.motion.body.position],
          fallback:view.simulation.world.sectors[view.motion.body.sector].fallback,
          ground:sampleNativeTrack(view.simulation.world,view.motion.body.sector,...view.motion.body.position),
          sector:shadow.userData.sector,visibleSectorRanges:view.visibleSectorRanges,
          vertices:Array.from(shadow.geometry.attributes.position.array),errors:view.errors});
      }
      return checks;
    });
    await page.screenshot({path:`${directory}/track-${track}-surface.png`});
    await page.evaluate(()=>{const view=rcsk.viewer;view.setSurfaceShadows(false);view.renderScene();});
    await page.screenshot({path:`${directory}/track-${track}-inspection.png`});
    for(const check of checks){
      report.checks.push({kind:'loaded-race',track,...check});
      // The surface shadow is visible on both starts; the original only on
      // the Netherlands, while France's quad stays below the road.
      if(track===0||check.surface)assert.ok(check.changed>10,`track ${track} surface ${check.surface}`);
      if(track===3&&!check.surface)assert.equal(check.changed,0);
      assert.equal(check.lighter,0);assert.equal(check.darker,check.changed);
      assert.deepEqual(check.order,['shadow','kart']);assert.equal(check.shadowCount,5);
      if(track===3){assert.equal(check.pose.position[1],0);assert.ok(check.ground.height>check.pose.position[1]+10);}
      assert.deepEqual(check.errors,[]);
    }
  }
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile(`${directory}/browser.json`,JSON.stringify(report,null,2)+'\n');
  await browser.close();console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors}));
}
