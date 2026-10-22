import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={origin,browser:browser.version(),checks:[],errors:[],
  scope:'Actual DrivingView HUD texture allocation/deletion over three reloads and final disposal. Checks GL handles and deletion calls; does not infer GPU process memory from renderer counters.'};
await mkdir('evidence/followup',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:800,height:600}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto(origin+'/?drive=1');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  for(const nextTrack of [2,3,1,null]){
    const result=await page.evaluate(async nextTrack=>{
      const viewer=rcsk.viewer;viewer.suspend();viewer.hud.render();
      viewer.renderer.render(viewer.scene,viewer.camera);
      const hud=viewer.hudMeshes,gl=hud.renderer.getContext();
      const maps=[...hud.loadedTextures];
      const handles=maps.map(map=>hud.renderer.properties.get(map).__webglTexture).filter(Boolean);
      const sources=await Promise.all([...hud.textures].map(async([file,promise])=>{
        const map=await promise,source=await viewer.texture(file);
        return {file,independent:map!==source,sharedImage:map.image===source.image,
          keyPreserved:map.premultiplyAlpha===source.premultiplyAlpha,
          gammaPreserved:map.userData.nativeGamma===source.userData.nativeGamma,
          colorSpace:map.colorSpace,sourceColorSpace:source.colorSpace};
      }));
      const worldGL=viewer.renderer.getContext(),worldHandles=[];
      for(const pending of viewer.textures.values()){
        const map=await pending,handle=viewer.renderer.properties.get(map).__webglTexture;
        if(handle)worldHandles.push(handle);
      }
      let deletes=0;const remove=gl.deleteTexture.bind(gl);
      gl.deleteTexture=handle=>{deletes++;return remove(handle);};
      const before={uploaded:handles.length,live:handles.filter(handle=>gl.isTexture(handle)).length,
        memory:hud.renderer.info.memory.textures,worldLive:worldHandles.filter(handle=>worldGL.isTexture(handle)).length};
      if(nextTrack===null)await hud.dispose();
      else{await viewer.load(nextTrack);viewer.suspend();}
      await Promise.resolve();
      return {nextTrack,sources,before,after:{deletes,
        live:handles.filter(handle=>gl.isTexture(handle)).length,memory:hud.renderer.info.memory.textures,
        worldLive:worldHandles.filter(handle=>worldGL.isTexture(handle)).length},viewerErrors:viewer.errors};
    },nextTrack);
    report.checks.push(result);
    assert.ok(result.before.uploaded>0,'HUD must have uploaded real textures');
    assert.equal(result.before.live,result.before.uploaded);
    assert.equal(result.after.deletes,result.before.uploaded);
    assert.equal(result.after.live,0);
    assert.equal(result.after.memory,0);
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
