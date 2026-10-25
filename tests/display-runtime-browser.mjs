import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const report={origin,browser:browser.version(),checks:[],errors:[],
  scope:'Actual DrivingView settings, native RGB565 channel-count bytes before GPU filtering, packed HUD atlas reuse, sampler state, weather construction and cache reuse. No native framebuffer comparison.'};
await mkdir('evidence/display',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:800,height:600}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.goto(origin+'/?drive=1');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  for(const enabled of [false,true,false]){
    const result=await page.evaluate(async enabled=>{
      const v=rcsk.viewer;
      v.suspend();
      v.displaySettings={brightnessLight:enabled,bilinearFiltering:enabled,alphaBlending:enabled,particles:enabled};
      await v.load(1);
      v.active=false;v.clock.pause();
      const map=await v.texture('textures/s_sfx.tga.png');
      const source=await createImageBitmap(await(await fetch('/assets/textures/s_sfx.tga.png')).blob());
      const pixels=image=>{
        const canvas=document.createElement('canvas');canvas.width=image.width;canvas.height=image.height;
        const context=canvas.getContext('2d',{willReadFrequently:true});context.drawImage(image,0,0);
        return context.getImageData(0,0,image.width,image.height).data;
      };
      const original=pixels(source),actual=map.image.data;source.close();
      let opaque=0,changed=0,mismatches=0,alphaMismatches=0,keyRGBMismatches=0;
      for(let i=0;i<actual.length;i+=4){
        if(actual[i+3]!==original[i+3])alphaMismatches++;
        if(original[i+3]!==255){
          if(actual.slice(i,i+3).some(value=>value!==0))keyRGBMismatches++;
          continue;
        }
        opaque++;
        // Independent original arithmetic: optional byte gamma, bit
        // truncation, then protected black when the packed value is zero.
        const sourceRGB=Array.from(original.slice(i,i+3),value=>enabled?value:value*value>>8);
        const counts=[sourceRGB[0]>>3,sourceRGB[1]>>2,sourceRGB[2]>>3];
        if(counts.every(value=>value===0))counts[0]=1;
        for(let c=0;c<3;c++){
          if(actual[i+c]!==counts[c])mismatches++;
          const expanded=Math.round(actual[i+c]*255/(c===1?63:31));
          if(expanded!==original[i+c])changed++;
        }
      }
      const THREE=await import('three');
      const font=[...v.hud.textures.keys()][0];
      const fontRecord=v.hud.manifest.images[font];
      const fontTexture=await v.texture(fontRecord.file);
      const fontMap=v.hud.textures.get(font);
      const samplerFrames=[];
      for(let frame=1;frame<=3;frame++){
        v.onTick(.025,frame*25);v.hud.render();
        samplerFrames.push({frame,captured:v.hudSampler.frames,draw:{...v.hudSampler.current},
          fontFilter:{min:fontMap.minFilter,mag:fontMap.magFilter},
          maps:[...v.hudMeshes.loadedTextures].map(map=>({min:map.minFilter,mag:map.magFilter}))});
        for(let refresh=0;refresh<3;refresh++)v.hud.render();
      }
      const hudMaps=await Promise.all([...v.hudMeshes.textures].map(async([file,pending])=>{
        const map=await pending,world=await v.texture(file);
        return {file,linear:map.minFilter===THREE.LinearFilter&&map.magFilter===THREE.LinearFilter,
          sharedImage:map.image===world.image,independentSampler:map!==world,
          worldFilter:world.minFilter,keyPreserved:map.premultiplyAlpha===world.premultiplyAlpha};
      }));
      return {enabled,opaque,changed,mismatches,alphaMismatches,keyRGBMismatches,
        format:map.userData.nativeTextureFormat,isDataTexture:map.isDataTexture===true,
        minFilter:map.minFilter,magFilter:map.magFilter,
        expectedFilter:enabled?THREE.LinearFilter:THREE.NearestFilter,
        keyBeforeFiltering:map.userData.nativeColorKeyFilter===true,premultiplyAlpha:map.premultiplyAlpha,
        gamma:map.userData.nativeGamma??false,weather:!!v.simulation.weather,
        fontUsesPackedPixels:fontMap.isDataTexture===true&&fontMap.image===fontTexture.image,
        fontIndependentSampler:fontMap!==fontTexture,
        fontFormat:fontMap.userData.nativeTextureFormat,
        fontKeyBeforeFiltering:fontMap.userData.nativeColorKeyFilter===true,
        fontGammaPreserved:fontMap.userData.nativeGamma===fontTexture.userData.nativeGamma,
        fontFilter:{min:fontMap.minFilter,mag:fontMap.magFilter},
        hudMaps,samplerFrames,capturedFrames:v.hudSampler.frames,
        graphics:v.runtimeConfig['sndgfx.ini']['gfx options'],
        errors:v.errors};
    },enabled);
    assert.equal(result.mismatches,0);assert.equal(result.alphaMismatches,0);assert.equal(result.keyRGBMismatches,0);
    assert.equal(result.format,'RGB565');assert.equal(result.isDataTexture,true);
    assert.ok(result.opaque>0);assert.equal(result.gamma,!enabled);
    assert.equal(result.minFilter,result.expectedFilter);assert.equal(result.magFilter,result.expectedFilter);
    assert.equal(result.keyBeforeFiltering,true);assert.equal(result.premultiplyAlpha,false);assert.equal(result.weather,enabled);
    assert.equal(result.fontUsesPackedPixels,true);assert.equal(result.fontIndependentSampler,true);
    assert.equal(result.fontFormat,'RGB565');assert.equal(result.fontKeyBeforeFiltering,true);
    assert.equal(result.fontGammaPreserved,true);
    assert.equal(result.fontFilter.min,result.expectedFilter);assert.equal(result.fontFilter.mag,result.expectedFilter);
    assert.equal(result.capturedFrames,3);
    for(const frame of result.samplerFrames){
      const linear=enabled||frame.frame===1;
      assert.equal(frame.captured,frame.frame);assert.equal(frame.draw.min,linear?2:1);
      assert.equal(frame.draw.mag,linear?2:1);
      const filter=linear?1006:1003; // Three LinearFilter / NearestFilter.
      assert.equal(frame.fontFilter.min,filter);assert.equal(frame.fontFilter.mag,filter);
      for(const map of frame.maps){assert.equal(map.min,filter);assert.equal(map.mag,filter);}
    }
    assert.ok(result.hudMaps.length>0);
    for(const map of result.hudMaps){
      assert.equal(map.linear,enabled);assert.equal(map.sharedImage,true);
      assert.equal(map.independentSampler,true);assert.equal(map.worldFilter,result.expectedFilter);
      assert.equal(map.keyPreserved,true);
    }
    assert.equal(Number(result.graphics.alpha_blending),enabled?2:0);
    assert.deepEqual(result.errors,[]);
    assert.ok(result.changed>0,'native 16-bit truncation changes some original 8-bit source colors');
    report.checks.push(result);
  }
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{await writeFile('evidence/display/runtime-browser.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
