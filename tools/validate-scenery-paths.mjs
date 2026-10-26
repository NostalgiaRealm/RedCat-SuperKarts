// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,
  args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
try{
  const page=await browser.newPage({viewport:{width:960,height:720}});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/assets/config.json');
  await page.setContent('<script type="importmap">{"imports":{"three":"/node_modules/three/build/three.module.js","three/addons/":"/node_modules/three/examples/jsm/"}}</script><canvas style="width:960px;height:720px"></canvas>');
  await page.evaluate(async()=>{
    const [{TrackViewer},{NativeSceneryPaths}]=await Promise.all([import('/source/world.js'),import('/source/scenery-paths.js')]);
    window.PathController=NativeSceneryPaths;window.viewer=new TrackViewer(document.querySelector('canvas'));
    viewer.renderer.setSize(960,720,false);
  });
  const tracks=[];
  await mkdir('evidence/scenery-paths',{recursive:true});
  for(let id=0;id<6;id++){
    const result=await page.evaluate(async id=>{
      const loaded=await viewer.load(id),checks=[];
      viewer.clock.pause();
      for(const spec of viewer.sceneryPaths.paths){
        viewer.sceneryPaths=new PathController(viewer.track);
        viewer.captureSceneryPaths();
        const mesh=viewer.sceneryPathMeshes.get(spec.placementIndex);
        const initial=mesh.position.toArray();
        viewer.stepSceneryPaths({playerSector:spec.startSector,lapCount:Math.max(0,spec.unknown-1),deltaSeconds:.025});
        const beforeCapture=mesh.position.toArray();
        const state=viewer.sceneryPaths.objects.get(spec.placementIndex);
        const first=[...state.position];
        viewer.captureSceneryPaths();
        const captured=mesh.position.toArray();
        for(let tick=0;tick<30;tick++)viewer.stepSceneryPaths({
          playerSector:spec.startSector,lapCount:Math.max(0,spec.unknown-1),deltaSeconds:.03125,
        });
        viewer.captureSceneryPaths();
        const moved=mesh.position.toArray();
        if(spec.endSector){
          viewer.stepSceneryPaths({playerSector:spec.endSector,lapCount:Math.max(0,spec.unknown-1),deltaSeconds:.025});
          const visibleBeforeCapture=mesh.visible;
          viewer.captureSceneryPaths();
          checks.push({path:spec.index,animation:spec.animation,initial,beforeCapture,first,captured,moved,
            visibleBeforeCapture,visibleAfterCapture:mesh.visible,geometryVertices:mesh.geometry.attributes.position.count});
        }
      }
      // Inspection camera, deliberately separate from the verified race camera.
      if(viewer.sceneryPaths.paths.length){
        const spec=viewer.sceneryPaths.paths[0];
        viewer.sceneryPaths=new PathController(viewer.track);
        viewer.stepSceneryPaths({playerSector:spec.startSector,lapCount:Math.max(0,spec.unknown-1),deltaSeconds:.025});
        for(let i=0;i<30;i++)viewer.stepSceneryPaths({playerSector:spec.startSector,lapCount:Math.max(0,spec.unknown-1),deltaSeconds:.025});
        viewer.captureSceneryPaths();
        const p=viewer.sceneryPaths.objects.get(spec.placementIndex).position;
        viewer.camera.aspect=4/3;viewer.camera.updateProjectionMatrix();
        viewer.camera.position.set(p[0]+220,p[1]+120,-p[2]+220);
        viewer.camera.lookAt(p[0],p[1],-p[2]);
        viewer.renderer.render(viewer.scene,viewer.camera);
      }
      return{id,errors:loaded.errors,checks,pathCount:viewer.sceneryPaths.paths.length};
    },id);
    assert.deepEqual(result.errors,[]);
    for(const row of result.checks){
      assert.deepEqual(row.beforeCapture,row.initial);
      assert.deepEqual(row.captured,row.first);
      assert.ok(row.moved.every(Number.isFinite));
      assert.notDeepEqual(row.moved,row.captured);
      assert.equal(row.visibleBeforeCapture,true);
      assert.equal(row.visibleAfterCapture,false);
      assert.ok(row.geometryVertices>0);
    }
    tracks.push(result);
    if(id===0||id===5)await page.screenshot({path:`evidence/scenery-paths/track-${id}-inspection.png`});
  }
  assert.equal(tracks.reduce((count,track)=>count+track.pathCount,0),35);
  await writeFile('evidence/scenery-paths/browser.json',JSON.stringify({tracks},null,2)+'\n');
  console.log('All35 native scenery paths: original meshes, delayed capture, movement and endpoint hiding passed across6 tracks.');
}finally{await browser.close();}
