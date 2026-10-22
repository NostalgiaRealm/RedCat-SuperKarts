import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const directory='evidence/streams-regression';
await mkdir(directory,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const errors=[];
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('pageerror',error=>errors.push(error.message));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  await page.evaluate(()=>rcsk.viewer.clock.pause());
  const pixels=await page.evaluate(async()=>{
    const THREE=await import('three');
    const {StreamVisuals}=await import('/src/race-visuals.js');
    const {createNativeJetFlare,updateNativeJetFlare}=await import('/src/simulation/native-streams.js');
    const {createNativeMeshMaterial}=await import('/src/asset-materials.js');
    const original=rcsk.viewer,manifest=(await original.resources)[1];
    const renderer=new THREE.WebGLRenderer({antialias:false,preserveDrawingBuffer:true});
    renderer.setSize(512,512);renderer.setClearColor(0);
    const scene=new THREE.Scene(),group=new THREE.Group();group.scale.z=-1;scene.add(group);
    const visual=await new StreamVisuals({group,texture:original.texture.bind(original)}).load(manifest);
    const shared=await original.texture('textures/s_sfx.tga.png');
    // Retain all native quantization/gamma/sampler metadata, changing only
    // hidden key RGB. Own the source as Texture.clone otherwise shares it.
    const control=shared.clone();
    control.source=new THREE.Source({...shared.image,data:shared.image.data.slice()});
    const keyRGB=shared.userData.nativeGamma?[31,0,7]:[31,0,15];
    for(let i=0;i<control.image.data.length;i+=4){
      if(control.image.data[i+3]===0)control.image.data.set(keyRGB,i);
    }
    control.needsUpdate=true;
    const body={matrix:[1,0,0,0,1,0,0,0,1],position:[0,0,0]};
    const entry=createNativeJetFlare(body,{offset:[0,0,0],size:40,colorIndex:5});
    entry.angle=-15;updateNativeJetFlare(entry,{player:true,throttle:0});
    visual.capture({jets:[entry.vertices]});
    const camera=new THREE.OrthographicCamera(-22,22,22,-22,.1,100);
    camera.position.z=50;camera.lookAt(0,0,0);
    const target=new THREE.WebGLRenderTarget(512,512);
    const render=()=>{
      renderer.setRenderTarget(target);renderer.render(scene,camera);
      const data=new Uint8Array(512*512*4);
      renderer.readRenderTargetPixels(target,0,0,512,512,data);return data;
    };
    visual.material.map=control;visual.material.needsUpdate=true;
    const before=render();
    visual.material.map=shared;visual.material.needsUpdate=true;
    const after=render();
    let edgePixelsRemoved=0,edgePixelsReduced=0,unexpectedIncreases=0,interiorChanges=0,visiblePixels=0;
    for(let y=0;y<512;y++)for(let x=0;x<512;x++){
      const index=(y*512+x)*4;
      const old=before.slice(index,index+3),now=after.slice(index,index+3);
      if(now.some(value=>value>0))visiblePixels++;
      if(old.some(value=>value>0)&&now.every(value=>value===0))edgePixelsRemoved++;
      if(now.some((value,axis)=>value<old[axis]))edgePixelsReduced++;
      if(now.some((value,axis)=>value>old[axis]))unexpectedIncreases++;
      if(x>50&&x<460&&y>50&&y<460&&now.some((value,axis)=>value!==old[axis]))interiorChanges++;
    }
    const center=Array.from(after.slice((256*512+256)*4,(256*512+256)*4+3));
    const png=data=>{
      const canvas=document.createElement('canvas');canvas.width=canvas.height=512;
      const context=canvas.getContext('2d'),image=context.createImageData(512,512);
      for(let y=0;y<512;y++)image.data.set(data.subarray(y*512*4,(y+1)*512*4),(511-y)*512*4);
      context.putImageData(image,0,0);return canvas.toDataURL();
    };
    const beforePng=png(before),afterPng=png(after);
    // Read back EVERY atlas texel at its center. Compare against independent
    // native RGB565 truncation/gamma/protected-black arithmetic, not the
    // unquantized PNG or the conversion helper being exercised by the loader.
    group.visible=false;
    const atlasMap=shared.clone();
    atlasMap.minFilter=atlasMap.magFilter=THREE.NearestFilter;atlasMap.needsUpdate=true;
    const atlasMaterial=createNativeMeshMaterial(atlasMap,{colorKeyThreshold:0});
    const plane=new THREE.Mesh(new THREE.PlaneGeometry(2,2),atlasMaterial);
    plane.geometry.setAttribute('color',new THREE.Float32BufferAttribute(new Float32Array(12).fill(1),3));
    scene.add(plane);
    const atlasCamera=new THREE.OrthographicCamera(-1,1,1,-1,.1,10);atlasCamera.position.z=1;
    const atlasTarget=new THREE.WebGLRenderTarget(128,128);
    renderer.setRenderTarget(atlasTarget);renderer.render(scene,atlasCamera);
    const uploaded=new Uint8Array(128*128*4);renderer.readRenderTargetPixels(atlasTarget,0,0,128,128,uploaded);
    const canvas=document.createElement('canvas');canvas.width=canvas.height=128;
    const sourceImage=await createImageBitmap(await(await fetch('/assets/textures/s_sfx.tga.png')).blob());
    const context=canvas.getContext('2d');context.drawImage(sourceImage,0,0);sourceImage.close();
    const source=context.getImageData(0,0,128,128).data;
    let opaque=0,opaqueBlack=0,key=0,texelMismatches=0;const texelExamples=[];
    for(let i=0;i<source.length;i+=4){
      if(source[i+3]===0){key++;if(uploaded.slice(i,i+3).some(v=>v!==0))texelMismatches++;}
      else{
        opaque++;if(source.slice(i,i+3).every(v=>v===0))opaqueBlack++;
        const channels=Array.from(source.slice(i,i+3),value=>shared.userData.nativeGamma?value*value>>8:value);
        const counts=[channels[0]>>3,channels[1]>>2,channels[2]>>3];
        if(counts.every(value=>value===0))counts[0]=1;
        const expected=counts.map((value,axis)=>Math.round(value*255/(axis===1?63:31)));
        if(expected.some((v,axis)=>uploaded[i+axis]!==v)){
          texelMismatches++;
          if(texelExamples.length<3)texelExamples.push({index:i/4,source:Array.from(source.slice(i,i+4)),expected,actual:Array.from(uploaded.slice(i,i+4))});
        }
      }
    }
    const result={edgePixelsRemoved,edgePixelsReduced,unexpectedIncreases,interiorChanges,visiblePixels,center,
      opaque,opaqueBlack,key,texelMismatches,texelExamples,sharedTexture:visual.material.map===shared,
      sharedPremultiplyAlpha:shared.premultiplyAlpha,keyFilter:shared.userData.nativeColorKeyFilter,
      sharedFormat:shared.userData.nativeTextureFormat,controlFormat:control.userData.nativeTextureFormat,
      independentControlPixels:control.image.data!==shared.image.data,
      blendSrc:visual.material.blendSrc,
      blendDst:visual.material.blendDst,depthWrite:visual.material.depthWrite,
      indices:Array.from(visual.jets[0].geometry.index.array.slice(0,6)),
      drawCount:visual.jets[0].geometry.drawRange.count,beforePng,afterPng};
    visual.dispose();plane.geometry.dispose();atlasMaterial.dispose();control.dispose();atlasMap.dispose();
    target.dispose();atlasTarget.dispose();renderer.dispose();
    return result;
  });
  for(const label of ['before','after']){
    await writeFile(`${directory}/isolated-flare-${label}.png`,
      Buffer.from(pixels[`${label}Png`].split(',')[1],'base64'));
    delete pixels[`${label}Png`];
  }
  await writeFile(`${directory}/pixels.json`,JSON.stringify(pixels,null,2)+'\n');
  assert.ok(pixels.edgePixelsReduced>0,'control reproduces pink RGB bleeding at filtered key edges');
  assert.equal(pixels.unexpectedIncreases,0);
  assert.equal(pixels.interiorChanges,0,'the visible glow interior must remain unchanged');
  assert.ok(pixels.visiblePixels>1000);assert.ok(pixels.center.some(v=>v>100));
  assert.equal(pixels.texelMismatches,0);
  assert.equal(pixels.opaque,8682);assert.equal(pixels.opaqueBlack,2621);assert.equal(pixels.key,7702);
  assert.equal(pixels.sharedTexture,true);assert.equal(pixels.sharedPremultiplyAlpha,false);assert.equal(pixels.keyFilter,true);
  assert.equal(pixels.sharedFormat,'RGB565');assert.equal(pixels.controlFormat,pixels.sharedFormat);
  assert.equal(pixels.independentControlPixels,true);
  assert.equal(pixels.blendSrc,201);assert.equal(pixels.blendDst,201);assert.equal(pixels.depthWrite,true);
  assert.deepEqual(pixels.indices,[0,1,2,2,1,3]);assert.equal(pixels.drawCount,6);
  await page.keyboard.down('ArrowUp');
  const driving=await page.evaluate(()=>{
    const view=rcsk.viewer;let now=view.clock.tick*25;
    for(let frame=0;frame<80;frame++)view.onTick(.025,now+=25);
    view.updatePresentation(1);view.renderer.render(view.scene,view.camera);view.hud.render();
    return {speed:view.motion.body.forwardSpeed,jets:view.simulation.streamFrames.jets.length,
      ribbons:view.simulation.streamFrames.ribbons.length,errors:view.errors};
  });
  await page.keyboard.up('ArrowUp');
  assert.ok(driving.speed>1);assert.ok(driving.jets>0);assert.ok(driving.ribbons>0);
  assert.deepEqual(driving.errors,[]);assert.deepEqual(errors,[]);
  await page.screenshot({path:`${directory}/driving-after.png`});
  const report={status:'passed',browser:browser.version(),pixels,driving,errors,
    scope:'Original stream geometry/UVs and native RGB565 atlas texel readback. The control changes only retained key RGB to reproduce filtering contamination. Protected black retains the original red quantum. This is not original-driver screenshot parity.'};
  await writeFile(`${directory}/browser.json`,JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify(report));
}finally{await browser.close();}
