import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const directory='evidence/full-race-matrix/mirror-browser';
await mkdir(directory,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader',
    '--autoplay-policy=no-user-gesture-required']});
const report={status:'running',browser:browser.version(),checks:[],errors:[],
  scope:'Controlled frozen browser frames compare each authored mirrored course with its exact horizontal image reflection, using original assets. World culling and unmirrored HUD are checked separately. Real browser key input checks the assembled input flag. This is not an original Windows framebuffer comparison.'};
try{
  const page=await browser.newPage({viewport:{width:960,height:720}});
  page.on('pageerror',error=>report.errors.push(error.message));
  for(const id of [2,3,5,0]){
    await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+`/?drive=${id}`);
    await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
    const frame=await page.evaluate(()=>{
      const view=rcsk.viewer,track=view.track;
      view.clock.pause();
      const original=track.mirrored;
      const canvas=view.renderer.domElement,gl=view.renderer.getContext();
      const width=canvas.width,height=canvas.height;
      function capture(mirrored){
        track.mirrored=mirrored;
        view.updatePresentation(0);
        view.renderer.setRenderTarget(null);
        view.renderer.render(view.scene,view.camera);
        gl.bindFramebuffer(gl.FRAMEBUFFER,null);
        const bytes=new Uint8Array(width*height*4);
        gl.readPixels(0,0,width,height,gl.RGBA,gl.UNSIGNED_BYTE,bytes);
        return {bytes,png:canvas.toDataURL('image/png')};
      }
      const normalFrame=capture(false),mirrorFrame=capture(true);
      const ordinary=normalFrame.bytes,mirrored=mirrorFrame.bytes;
      let matching=0,absoluteError=0,nonBackground=0;
      for(let y=0;y<height;y++)for(let x=0;x<width;x++){
        const a=(y*width+x)*4,b=(y*width+width-1-x)*4;
        let max=0;
        for(let c=0;c<3;c++){
          const error=Math.abs(ordinary[a+c]-mirrored[b+c]);
          max=Math.max(max,error);absoluteError+=error;
        }
        if(max<=3)matching++;
        if(ordinary[a]!==21||ordinary[a+1]!==29||ordinary[a+2]!==43)nonBackground++;
      }
      const hud=view.hudCanvas.getContext('2d');
      function captureHud(orientation){
        capture(orientation);view.hud.render();
        return {bytes:hud.getImageData(0,0,view.hudCanvas.width,view.hudCanvas.height).data,
          png:view.hudCanvas.toDataURL('image/png')};
      }
      function compareHud(a,b){
        let differences=0,maxChannelError=0,alphaDifferences=0,opaqueDifferences=0;
        for(let i=0;i<a.length;i++)if(a[i]!==b[i]){
          differences++;maxChannelError=Math.max(maxChannelError,Math.abs(a[i]-b[i]));
          if(i%4===3)alphaDifferences++;
          if(a[(i&~3)+3]===255&&b[(i&~3)+3]===255)opaqueDifferences++;
        }
        return {differences,maxChannelError,alphaDifferences,opaqueDifferences};
      }
      // The first Canvas2D readback can change translucent RGB rounding by one
      // byte on the next identical render. Record that unchanged-orientation
      // control, then require exact equality for the actual mirror comparison.
      const beforeHud=captureHud(original),repeatHud=captureHud(original);
      const afterHud=captureHud(!original),repeatMirroredHud=captureHud(!original);
      const hudBaseline=compareHud(beforeHud.bytes,repeatHud.bytes);
      const hudMirror=compareHud(repeatHud.bytes,afterHud.bytes);
      const hudMirroredBaseline=compareHud(afterHud.bytes,repeatMirroredHud.bytes);
      const hudEqual=hudMirror.differences===0;
      const hudDifferences=hudMirror.differences;
      capture(original);view.hud.render();
      return {id:track.id,authoredMirrored:original,motionMirrored:view.motion.mirrored,
        sceneX:view.scene.scale.x,groupX:view.group.scale.x,cameraParentIsScene:view.camera.parent===view.scene,
        width,height,matchingFraction:matching/(width*height),
        meanChannelError:absoluteError/(width*height*3),nonBackgroundFraction:nonBackground/(width*height),
        hudEqual,hudDifferences,hudBaseline,hudMirror,hudMirroredBaseline,
        hudSceneScales:[...view.hudMeshes.layers.values()].map(layer=>layer.scene.scale.toArray()),
        images:{ordinary:normalFrame.png,mirrored:mirrorFrame.png,hudBefore:repeatHud.png,hudAfter:afterHud.png}};
    });
    for(const [name,url]of Object.entries(frame.images))
      await writeFile(`${directory}/track${id}-${name}.png`,Buffer.from(url.split(',')[1],'base64'));
    delete frame.images;
    (report.probes??=[]).push(frame);
    assert.equal(frame.motionMirrored,frame.authoredMirrored);
    assert.equal(frame.sceneX,1);
    assert.equal(frame.groupX,frame.authoredMirrored?-1:1);
    assert.equal(frame.cameraParentIsScene,true);
    assert.ok(frame.matchingFraction>.98,JSON.stringify(frame));
    assert.ok(frame.meanChannelError<1,JSON.stringify(frame));
    assert.ok(frame.nonBackgroundFraction>.25,JSON.stringify(frame));
    assert.equal(frame.hudEqual,true);
    assert.ok(frame.hudSceneScales.every(scale=>scale.every(value=>value===1)));
    await page.screenshot({path:`${directory}/track${id}.png`});
    const before=await page.evaluate(()=>{
      const view=rcsk.viewer;view.clock.resume();return view.clock.tick;
    });
    await page.keyboard.down('ArrowLeft');
    await page.waitForFunction(tick=>rcsk.viewer.clock.tick>=tick+4,before);
    const control=await page.evaluate(()=>rcsk.viewer.motion.controls.steering);
    await page.keyboard.up('ArrowLeft');
    assert.ok(frame.authoredMirrored?control>0:control<0,`track${id} steering${control}`);
    report.checks.push({...frame,leftControl:control});
  }
  assert.deepEqual(report.errors,[]);
  report.status='passed';
}catch(error){
  report.status='failed';report.failure=error.stack;throw error;
}finally{
  await writeFile(`${directory}/validation.json`,JSON.stringify(report,null,2)+'\n');
  await browser.close();
}
console.log(JSON.stringify({status:report.status,tracks:report.checks.length,errors:report.errors}));
