import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile,readFile} from 'node:fs/promises';

const base=process.env.RCSK_URL||'http://127.0.0.1:4173';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const errors={page:[],console:[],http:[],requests:[]};
const report={status:'running',browser:browser.version(),errors,checks:[]};
await mkdir('evidence/texture-precision',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  // The synthetic module document has no game icon; satisfy Chromium's implicit
  // default request so all captured errors describe the rendering under test.
  await page.route('**/favicon.ico',route=>route.fulfill({status:204,body:''}));
  page.on('pageerror',error=>errors.page.push(error.message));
  page.on('console',message=>{if(message.type()==='error')errors.console.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)errors.http.push(`${response.status()} ${response.url()}`);});
  page.on('requestfailed',request=>errors.requests.push(`${request.failure()?.errorText} ${request.url()}`));
  await page.goto(base+'/assets/manifest.json');
  await page.setContent('<script type="importmap">{"imports":{"three":"/node_modules/three/build/three.module.js","three/addons/":"/node_modules/three/examples/jsm/"}}</script>');
  report.synthetic=await page.evaluate(async fixtures=>{
    const THREE=await import('three');
    const {createNativeMeshMaterial,applyNativeByteColorPipeline}=await import('/src/asset-materials.js');
    const {packNativeTextureRGBA,nativeTexturePixelsRGBA}=await import('/src/native-texture-upload.js');
    const {TrackViewer}=await import('/src/world.js');
    const renderer=new THREE.WebGLRenderer({alpha:false,antialias:false,preserveDrawingBuffer:true});
    renderer.setSize(8,8);renderer.outputColorSpace=THREE.SRGBColorSpace;
    renderer.toneMapping=THREE.ACESFilmicToneMapping;
    const gl=renderer.getContext(),camera=new THREE.OrthographicCamera(-1,1,1,-1,0,10);
    camera.position.z=2;
    const scene=new THREE.Scene(),geometry=new THREE.PlaneGeometry(2,2);
    geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(16).fill(255),4,true));
    const destination=[32,96,160];
    const backgroundTexture=new THREE.DataTexture(new Uint8Array([...destination,255]),1,1);
    backgroundTexture.needsUpdate=true;
    const background=applyNativeByteColorPipeline(new THREE.MeshBasicMaterial({map:backgroundTexture}));
    const back=new THREE.Mesh(new THREE.PlaneGeometry(2,2),background);
    back.position.z=-.5;scene.add(back);
    const front=new THREE.Mesh(geometry);scene.add(front);
    const checks=[];
    const makeMap=(rgba,{format='RGB565',gamma=false}={})=>{
      const map=new THREE.DataTexture(nativeTexturePixelsRGBA(packNativeTextureRGBA(rgba,{format,gamma}),{format}),rgba.length/4,1);
      map.userData.nativeTextureFormat=format;map.userData.nativeGamma=gamma;
      map.minFilter=map.magFilter=THREE.LinearFilter;map.generateMipmaps=false;map.needsUpdate=true;
      return map;
    };
    const setUV=(u,v=.5)=>{
      for(let i=0;i<4;i++)geometry.attributes.uv.array.set([u,v],i*2);
      geometry.attributes.uv.needsUpdate=true;
    };
    const sample=(material,{u=.5,v=.5,vertex=[255,255,255,255]}={})=>{
      setUV(u,v);
      for(let i=0;i<4;i++)geometry.attributes.color.array.set(vertex,i*4);
      geometry.attributes.color.needsUpdate=true;front.material=material;
      renderer.render(scene,camera);
      const rgba=new Uint8Array(4);gl.readPixels(4,4,1,1,gl.RGBA,gl.UNSIGNED_BYTE,rgba);
      return [...rgba].slice(0,3);
    };
    const decode=(packed,format)=>format==='RGB565'
      ?[(packed>>11&31)*255/31,(packed>>5&63)*255/63,(packed&31)*255/31]
      :[(packed>>10&31)*255/31,(packed>>5&31)*255/31,(packed&31)*255/31];
    for(const fixture of fixtures.uploads){
      const format=fixture.pixelFormat,map=makeMap(fixture.sourceRGBA.flat(),{format,gamma:fixture.gamma});
      map.minFilter=map.magFilter=THREE.NearestFilter;
      const material=createNativeMeshMaterial(map);
      fixture.packedPixels.forEach((packed,index)=>checks.push({case:'original TGA instruction fixture',format,
        gamma:fixture.gamma,sourceBits:fixture.sourceBits,source:fixture.sourceRGBA[index],packed,
        expected:packed===0?destination:decode(packed,format).map(Math.round),
        actual:sample(material,{u:(index+.5)/fixture.packedPixels.length})}));
      material.dispose();map.dispose();
    }
    // Constant UVs isolate the sampler at exact controlled subtexel positions.
    // Expected RGB uses the normalized native component values before filtering.
    for(const format of ['RGB565','RGB555']){
      for(const rgba of [[255,0,127,255,255,255,255,255],[0,0,0,255,40,120,200,255]]){
        const map=makeMap(rgba,{format}),packed=packNativeTextureRGBA(rgba,{format});
        const left=decode(packed[0],format),right=decode(packed[1],format);
        const material=createNativeMeshMaterial(map);
        for(const coverage of [0,1/256,1/128,.01,.125,.25,.49,.5,.75,1]){
          const expected=packed[0]===0&&coverage===0?destination
            :left.map((value,index)=>Math.round(value*(1-coverage)+right[index]*coverage));
          checks.push({case:'bilinear native component precision and nonzero key coverage',format,rgba,coverage,
            expected,actual:sample(material,{u:.25+.5*coverage})});
        }
        material.dispose();map.dispose();
      }
    }
    const coverage=.25,blendMap=makeMap([255,0,127,255,40,120,200,255]);
    const rgb=decode(packNativeTextureRGBA([40,120,200,255])[0],'RGB565');
    for(const mode of [0,1,2,3,'additive','alpha-additive']){
      const material=createNativeMeshMaterial(blendMap,{blendMode:typeof mode==='number'?mode:1});
      if(mode==='additive')material.blendSrc=material.blendDst=THREE.OneFactor;
      if(mode==='alpha-additive'){material.blendSrc=THREE.SrcAlphaFactor;material.blendDst=THREE.OneFactor;}
      for(const alpha of [0,32,128,255]){
        const vertex=[255,153,77,alpha],source=rgb.map((value,index)=>value*coverage*vertex[index]/255);
        const a=alpha/255;
        const expected=source.map((s,i)=>Math.round(Math.min(255,mode===0?s:mode===2?s+destination[i]*(1-s/255)
          :mode==='additive'?s+destination[i]:mode==='alpha-additive'?s*a+destination[i]:s*a+destination[i]*(1-a))));
        checks.push({case:'key coverage stays separate from vertex alpha and native blend factors',mode,coverage,vertex,
          expected,actual:sample(material,{u:.25+.5*coverage,vertex})});
      }
      material.dispose();
    }
    blendMap.dispose();
    const skyMap=makeMap([40,120,200,255]),sky=applyNativeByteColorPipeline(new THREE.MeshBasicMaterial({map:skyMap}));
    checks.push({case:'sky material decodes native counts without color transfer',
      expected:rgb.map(Math.round),actual:sample(sky)});
    sky.dispose();skyMap.dispose();

    const viewer=new TrackViewer(document.createElement('canvas'));
    const [,manifest]=await viewer.resources;
    const selected=['s_sfx.tga','fran07.tga','fran08.tga'].map(name=>Object.entries(manifest.images)
      .find(([key])=>key.toLowerCase()===name)?.[1]).filter(Boolean);
    if(selected.length!==3)throw Error('Original effects and 32-bit source texture records were not found');
    const originalAssets=[];
    for(const record of selected){
      const map=await viewer.texture(record.file),material=createNativeMeshMaterial(map);
      const image=new Image();image.src='/assets/'+record.file;await image.decode();
      const canvas=document.createElement('canvas');canvas.width=image.width;canvas.height=image.height;
      const context=canvas.getContext('2d',{willReadFrequently:true});context.drawImage(image,0,0);
      const source=context.getImageData(0,0,image.width,image.height).data;
      const unique=new Set(),chosen=[];
      for(let offset=0;offset<source.length&&chosen.length<12;offset+=4){
        const pixel=Array.from(source.slice(offset,offset+4)),key=pixel.join(',');
        if(unique.has(key))continue;unique.add(key);chosen.push({index:offset/4,pixel});
      }
      map.minFilter=map.magFilter=THREE.NearestFilter;map.needsUpdate=true;
      for(const {index,pixel}of chosen){
        const [r,g,b,a]=pixel,packed=a===0?0:((r>>3)<<11|(g>>2)<<5|b>>3)||0x0800;
        checks.push({case:'original PNG through shared runtime texture loader',file:record.file,source:pixel,
          expected:packed===0?destination:decode(packed,'RGB565').map(Math.round),
          actual:sample(material,{u:(index%image.width+.5)/image.width,v:(Math.floor(index/image.width)+.5)/image.height})});
      }
      originalAssets.push({file:record.file,nativeRGB:record.nativeRGB,nativeTextureFormat:map.userData.nativeTextureFormat,
        nativeGamma:map.userData.nativeGamma,isDataTexture:map.isDataTexture,premultiplyAlpha:map.premultiplyAlpha,samples:chosen.length});
      material.dispose();
    }
    for(const pending of viewer.textures.values())(await pending).dispose();
    viewer.renderer.dispose();viewer.controls.dispose();viewer.multisampling.dispose();
    front.material=new THREE.MeshBasicMaterial();front.material.dispose();
    background.dispose();backgroundTexture.dispose();geometry.dispose();back.geometry.dispose();renderer.dispose();
    return {checks,originalAssets,glError:gl.getError()};
  },JSON.parse(await readFile(new URL('../evidence/native/texture-key-fixtures.json',import.meta.url))));
  for(const row of report.synthetic.checks)row.actual.forEach((value,index)=>
    assert.ok(Math.abs(value-row.expected[index])<=1,JSON.stringify(row)));
  assert.equal(report.synthetic.glError,0);
  for(const row of report.synthetic.originalAssets){
    assert.equal(row.nativeRGB,true);assert.equal(row.nativeTextureFormat,'RGB565');
    assert.equal(row.isDataTexture,true);assert.equal(row.premultiplyAlpha,false);
  }
  report.checks.push({case:'native quantization, filtering, blend, sky and original loader pixels',
    samples:report.synthetic.checks.length,toleranceBytes:1});

  await page.goto(base+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:60000});
  report.integration=await page.evaluate(async()=>{
    const THREE=await import('three'),view=rcsk.viewer;
    const {resolveAsset}=await import('/src/asset-animation.js');
    view.updateLoop?.stop();view.clock.pause();
    const [,manifest]=await view.resources;
    const textures=await Promise.all([...view.textures].map(async([file,pending])=>({file,map:await pending})));
    const world=textures.map(({file,map})=>({file,format:map.userData.nativeTextureFormat,
      gamma:map.userData.nativeGamma,dataTexture:!!map.isDataTexture,premultiplyAlpha:map.premultiplyAlpha,
      minFilter:map.minFilter,magFilter:map.magFilter}));
    const clones=[...view.hud.meshes.loadedTextures].map(map=>({format:map.userData.nativeTextureFormat,
      dataTexture:!!map.isDataTexture,premultiplyAlpha:map.premultiplyAlpha,
      separateTexture:textures.every(item=>item.map!==map),sharedPixels:textures.some(item=>item.map.image===map.image)}));
    const fonts=[];
    for(const [name,map]of view.hud.textures){
      const file=resolveAsset(manifest,'images',name),sourceTexture=await view.texture(file),data=map.image.data;
      const image=new Image();image.src='/assets/'+file;await image.decode();
      const canvas=document.createElement('canvas');canvas.width=image.width;canvas.height=image.height;
      const context=canvas.getContext('2d',{willReadFrequently:true});context.drawImage(image,0,0);
      const rgba=context.getImageData(0,0,image.width,image.height).data;
      let opaque=0,keyed=0,mismatches=0;
      for(let offset=0;offset<data.length;offset+=4){
        if(rgba[offset+3]===0){
          keyed++;if(data.slice(offset,offset+4).some(value=>value!==0))mismatches++;
          continue;
        }
        opaque++;
        const rgb=Array.from(rgba.slice(offset,offset+3),value=>map.userData.nativeGamma?value*value>>8:value);
        const expected=[rgb[0]>>3,rgb[1]>>2,rgb[2]>>3,255];
        if(expected.slice(0,3).every(value=>value===0))expected[0]=1;
        if(expected.some((value,index)=>data[offset+index]!==value))mismatches++;
      }
      fonts.push({name,file,dataTexture:map.isDataTexture===true,format:map.userData.nativeTextureFormat,
        sharedPixels:map.image===sourceTexture.image,independentSampler:map!==sourceTexture,
        gammaPreserved:map.userData.nativeGamma===sourceTexture.userData.nativeGamma,
        keyBeforeFiltering:map.userData.nativeColorKeyFilter===true,premultiplyAlpha:map.premultiplyAlpha,
        width:map.image.width,height:map.image.height,opaque,keyed,mismatches});
    }
    const effects=[['streams',view.streamVisuals.material],['weather',view.weatherVisuals.material]].filter(([,material])=>material)
      .map(([name,material])=>({name,format:material.map?.userData.nativeTextureFormat,
        colorKeyThreshold:material.userData.native.colorKeyThreshold,source:material.blendSrc,destination:material.blendDst}));
    view.updatePresentation(1);view.renderScene();view.hud.render();
    const sky=view.sky?.material;
    return {world,clones,fonts,effects,sky:{format:sky?.map?.userData.nativeTextureFormat,nativeByteColors:sky?.userData.nativeByteColors},
      hudText:view.hud.text,assetErrors:view.errors,glError:view.renderer.getContext().getError(),
      filter:{linear:THREE.LinearFilter,nearest:THREE.NearestFilter}};
  });
  const integration=report.integration;
  assert.ok(integration.world.length>20);
  assert.ok(integration.world.every(row=>row.format==='RGB565'&&row.dataTexture&&row.premultiplyAlpha===false));
  assert.ok(integration.clones.length>0);
  assert.ok(integration.clones.every(row=>row.format==='RGB565'&&row.dataTexture&&row.separateTexture&&row.sharedPixels&&!row.premultiplyAlpha));
  assert.ok(integration.fonts.length>0);
  for(const font of integration.fonts){
    assert.equal(font.dataTexture,true);assert.equal(font.format,'RGB565');
    assert.equal(font.sharedPixels,true);assert.equal(font.independentSampler,true);
    assert.equal(font.gammaPreserved,true);assert.equal(font.keyBeforeFiltering,true);
    assert.equal(font.premultiplyAlpha,false);assert.equal(font.mismatches,0);
    assert.ok(font.opaque>0);assert.ok(font.keyed>0);
  }
  assert.equal(integration.sky.format,'RGB565');assert.equal(integration.sky.nativeByteColors,true);
  for(const effect of integration.effects){assert.equal(effect.format,'RGB565');assert.equal(effect.colorKeyThreshold,null);}
  assert.deepEqual(integration.assetErrors,[]);assert.equal(integration.glError,0);
  assert.ok(Object.keys(integration.hudText).length>0);
  report.checks.push({case:'live race shared textures, sky, effects, HUD clones and original packed font pixels',
    worldTextures:integration.world.length,hudClones:integration.clones.length,fonts:integration.fonts.length});
  assert.deepEqual(errors,{page:[],console:[],http:[],requests:[]});
  report.status='passed';
  report.scope='Focused Chromium SwiftShader WebGL2 checks. RGB565/RGB555 upload references are original x86 instruction fixtures. CPU bilinear and blend calculations check the port shader with a one-byte raster tolerance; this does not establish every historical GPU filtering implementation. No full races or builds.';
  console.log(JSON.stringify({status:report.status,checks:report.checks,errors}));
}catch(error){report.status='failed';report.failure=error.stack;throw error;}
finally{
  await writeFile('evidence/texture-precision/browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
}
