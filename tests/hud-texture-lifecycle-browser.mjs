import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={origin,browser:browser.version(),checks:[],errors:[],
  scope:'Actual DrivingView shared-renderer HUD texture ownership over three reloads and final disposal. Checks clone properties, exclusive GL handles and preservation of world-owned handles; does not infer GPU process memory from renderer counters.'};
await mkdir('evidence/followup',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:800,height:600}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto(origin+'/?drive=1');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  for(const nextTrack of [2,3,1,null]){
    const result=await page.evaluate(async nextTrack=>{
      const viewer=rcsk.viewer;viewer.suspend();viewer.renderScene();viewer.hud.render();
      const hud=viewer.hudMeshes,renderer=viewer.renderer,gl=renderer.getContext();
      const maps=[...hud.loadedTextures],properties=renderer.properties;
      // Allocate cached, currently hidden bonus variants too. They are owned
      // by the HUD and must be retired if a race ends before they are shown.
      for(const map of maps)renderer.initTexture(map);
      const handles=[...new Set(maps.map(map=>properties.get(map).__webglTexture).filter(Boolean))];
      const sources=await Promise.all([...hud.textures].map(async([file,promise])=>{
        const map=await promise,source=await viewer.texture(file);
        return {file,independent:map!==source,sharedImage:map.image===source.image,
          keyPreserved:map.premultiplyAlpha===source.premultiplyAlpha,
          gammaPreserved:map.userData.nativeGamma===source.userData.nativeGamma,
          colorSpace:map.colorSpace,sourceColorSpace:source.colorSpace};
      }));
      const worldHandles=new Set();
      for(const pending of viewer.textures.values()){
        const map=await pending,handle=properties.get(map).__webglTexture;
        if(handle)worldHandles.add(handle);
      }
      // Three may share a GL texture when independent clones have identical
      // source/sampler state. Only exclusively HUD-owned handles must die.
      const exclusive=handles.filter(handle=>!worldHandles.has(handle));
      const deleted=new Set(),remove=gl.deleteTexture;
      gl.deleteTexture=handle=>{deleted.add(handle);return remove.call(gl,handle);};
      const before={uploaded:handles.length,live:handles.filter(handle=>gl.isTexture(handle)).length,
        exclusive:exclusive.length,shared:handles.length-exclusive.length,
        memory:renderer.info.memory.textures,worldLive:[...worldHandles].filter(handle=>gl.isTexture(handle)).length};
      try{
        if(nextTrack===null){
          viewer.hud.dispose();viewer.hud=null;viewer.hudMeshes=null;await hud.dispose();
        }else{await viewer.load(nextTrack);viewer.suspend();}
        await Promise.resolve();
        return {nextTrack,sharedRenderer:hud.renderer===renderer,sources,before,after:{
          retiredProperties:maps.every(map=>!properties.has(map)),
          exclusiveDeleted:exclusive.filter(handle=>deleted.has(handle)).length,
          exclusiveLive:exclusive.filter(handle=>gl.isTexture(handle)).length,
          sharedLive:handles.filter(handle=>worldHandles.has(handle)&&gl.isTexture(handle)).length,
          memory:renderer.info.memory.textures,
          worldLive:[...worldHandles].filter(handle=>gl.isTexture(handle)).length},viewerErrors:viewer.errors};
      }finally{gl.deleteTexture=remove;}
    },nextTrack);
    report.checks.push(result);
    assert.ok(result.before.uploaded>0,'HUD must have uploaded real textures');
    assert.equal(result.before.live,result.before.uploaded);
    assert.equal(result.sharedRenderer,true);
    assert.equal(result.after.retiredProperties,true,'all retired HUD clone properties must be released');
    assert.equal(result.after.exclusiveDeleted,result.before.exclusive);
    assert.equal(result.after.exclusiveLive,0);
    assert.equal(result.after.sharedLive,result.before.shared);
    assert.ok(result.after.memory>0,'disposing the overlay must keep the world renderer alive');
    assert.equal(result.after.worldLive,result.before.worldLive,'HUD cleanup must preserve shared world texture ownership');
    for(const source of result.sources){
      assert.equal(source.independent,true);
      assert.equal(source.sharedImage,true);
      assert.equal(source.keyPreserved,true);
      assert.equal(source.gammaPreserved,true);
      assert.equal(source.colorSpace,'');
    }
    assert.deepEqual(result.viewerErrors,[]);
  }
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await writeFile('evidence/followup/hud-texture-lifecycle-browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
}
