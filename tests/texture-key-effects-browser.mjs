import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const directory='evidence/texture-key-effects';
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
  const result=await page.evaluate(async()=>{
    const THREE=await import('three');
    const {createNativeMeshMaterial}=await import('/src/asset-materials.js');
    const {getNativeRescueVisualSpec}=await import('/src/rescue-assets.js');
    const {NativeSmoke}=await import('/src/simulation/native-smoke.js');
    const {NativeRandom}=await import('/src/simulation/native-random.js');
    const {getNativeKartShadowSpec}=await import('/src/kart-shadow.js');
    const {getNativeFinishFlagSpec}=await import('/src/finish-flag.js');
    const {createNativeHomingArm,updateNativeHomingArm}=await import('/src/simulation/native-homing-arm.js');
    const {getHudMeshSpec}=await import('/src/hud-mesh.js');
    const viewer=rcsk.viewer,[config,manifest]=await viewer.resources;
    const size=256;
    const renderer=new THREE.WebGLRenderer({antialias:false});
    renderer.setSize(size,size);renderer.setClearColor(0x203040);
    const scene=new THREE.Scene(),group=new THREE.Group();group.scale.z=-1;scene.add(group);
    const camera=new THREE.OrthographicCamera(-22,22,22,-22,.1,10000);
    const target=new THREE.WebGLRenderTarget(size,size);
    const cases=[],checks=[],images=[];
    const geometry=(positions,uv,rgba,indices)=>{
      const g=new THREE.BufferGeometry();
      g.setAttribute('position',new THREE.Float32BufferAttribute(positions,3));
      g.setAttribute('uv',new THREE.Float32BufferAttribute(uv,2));
      g.setAttribute('color',new THREE.Uint8BufferAttribute(rgba,4,true));
      if(indices)g.setIndex(indices);return g;
    };
    const rgba=(color,count=4)=>Array.from({length:count},()=>color).flat();
    const quad=(uv,color)=>geometry([-20,-20,0,-20,20,0,20,-20,0,20,20,0],
      uv,color.length===4?rgba(color):color,[0,1,2,2,1,3]);
    const rect=(u0,v0,u1,v1)=>[u0,v1,u0,v0,u1,v1,u1,v0];
    const sfx='textures/s_sfx.tga.png';
    const rescue=getNativeRescueVisualSpec(manifest);
    cases.push({id:'rescue-ring',file:rescue.texture,geometry:quad(rescue.uv.slice(0,8),rescue.rgba.slice(0,16)),
      mode:1,src:THREE.OneFactor,dst:THREE.OneFactor,requiredChange:true,source:'48c370/48c7e0 first strip'});
    const smoke=new NativeSmoke({random:new NativeRandom(0)});
    smoke.emit([0,0,0],[0,0,0],.025);
    const cloud=smoke.capture({deltaSeconds:.025,cameraPosition:[0,0,-20]})[0];
    cases.push({id:'smoke-fan',file:sfx,geometry:geometry(cloud.vertices,cloud.uv,cloud.rgba,
      [0,1,2,0,2,3,0,3,4,0,4,5]),mode:1,src:THREE.SrcAlphaFactor,dst:THREE.OneFactor,
      source:'428a00 original emitted fan'});
    for(const [id,uv,color]of[
      ['rain',rect(Math.fround(.56),Math.fround(.05),Math.fround(.63),Math.fround(.4)),[96,96,192,128]],
      ['snow',rect(Math.fround(.35),Math.fround(.05),Math.fround(.54),Math.fround(.25)),[255,255,255,128]],
    ])cases.push({id,file:sfx,geometry:quad(uv,color),mode:1,src:THREE.SrcAlphaFactor,dst:THREE.OneFactor,
      source:'482840/483350 original UV window and diffuse; planar sampling patch'});
    cases.push({id:'explosion-constant-uv',file:sfx,geometry:quad(Array.from({length:4},()=>[Math.fround(.45),Math.fround(.15)]).flat(),
      [255,175,0,255]),mode:1,src:THREE.SrcAlphaFactor,dst:THREE.OneFactor,unchanged:true,
      source:'4844e0 constant opaque UV; planar sampling patch'});
    cases.push({id:'skidmark',file:sfx,geometry:quad(rect(.8125,.109375,.984375,.109375),[64,64,64,200]),
      mode:1,src:THREE.OneMinusSrcAlphaFactor,dst:THREE.SrcAlphaFactor,
      source:'426e50 original UV/diffuse and inverse-alpha blend; planar sampling patch'});
    const arm=createNativeHomingArm({matrix:[1,0,0,0,1,0,0,0,1],position:[0,0,0]},
      {position:[0,0,100]});
    updateNativeHomingArm(arm,.025);
    const armVertices=arm.vertices.slice(0,3);
    cases.push({id:'homing-arm-opaque-window',file:sfx,
      geometry:geometry([-20,20,0,20,20,0,0,-20,0],armVertices.flatMap(v=>v.uv),
        armVertices.flatMap(v=>[v.color>>>16&255,v.color>>>8&255,v.color&255,v.color>>>24])),
      mode:0,unchanged:true,source:'486d50/486cc0 original diffuse/UV; planar triangle sampling patch'});
    const shadow=getNativeKartShadowSpec(manifest,{minX:-20,maxX:20,minZ:-20,maxZ:20});
    cases.push({id:'kart-shadow-black-diffuse',file:shadow.texture,geometry:quad(shadow.uv,shadow.rgba),
      mode:1,unchanged:true,source:'416270/4260c0 black diffuse and UV; planar sampling patch'});
    const flag=getNativeFinishFlagSpec(manifest);
    cases.push({id:'finish-flag-nearest',file:flag.texture,
      geometry:geometry(flag.position,flag.uv,rgba([255,255,255,100],flag.position.length/3),flag.index),
      mode:1,nearest:true,unchanged:true,source:'423450 geometry/UV, nearest-filter draw'});
    for(const [id,mesh]of[['bonus-star','ster.d3d'],['projectile-bubble','bubbsml.d3d']]){
      cases.push({id,file:'textures/weapon.tga.png',geometry:(await viewer.model(mesh)).clone(),mode:0,
        source:`original ${mesh} geometry/UV and weapon atlas`});
    }
    for(const id of ['backredcat','portrredcat','bonusframe','track']){
      const spec=getHudMeshSpec(config,manifest,id,{trackId:0});
      const g=(await viewer.model(spec.mesh)).clone();
      g.setAttribute('color',new THREE.Uint8BufferAttribute(rgba(spec.rgba,g.attributes.position.count),4,true));
      cases.push({id:`hud-${id}`,file:spec.texture,geometry:g,mode:1,
        source:'original overlay model/UV and Overlay.ini RGBA'});
    }
    const pixelPng=data=>{
      const canvas=document.createElement('canvas');canvas.width=canvas.height=size;
      const ctx=canvas.getContext('2d'),image=ctx.createImageData(size,size);
      for(let y=0;y<size;y++)image.data.set(data.subarray(y*size*4,(y+1)*size*4),(size-y-1)*size*4);
      ctx.putImageData(image,0,0);return canvas.toDataURL();
    };
    for(const spec of cases){
      const fixed=await viewer.texture(spec.file),control=fixed.clone();
      // Isolate retained-key-RGB bleeding: both maps use the same native
      // quantization, gamma, mask, sampling and shader metadata. Only the
      // control's keyed texels regain pink RGB before filtering.
      control.source=new THREE.Source({...fixed.image,data:fixed.image.data.slice()});
      const keyRGB=fixed.userData.nativeGamma?[31,0,7]:[31,0,15];
      for(let i=0;i<control.image.data.length;i+=4){
        if(control.image.data[i+3]===0)control.image.data.set(keyRGB,i);
      }
      const corrected=fixed.clone();
      if(spec.nearest){
        corrected.minFilter=corrected.magFilter=THREE.NearestFilter;
        control.minFilter=control.magFilter=THREE.NearestFilter;
      }
      control.needsUpdate=corrected.needsUpdate=true;
      const material=createNativeMeshMaterial(control,{blendMode:spec.mode});
      if(spec.src!==undefined)material.blendSrc=spec.src;
      if(spec.dst!==undefined)material.blendDst=spec.dst;
      material.depthWrite=spec.mode===0||['rescue-ring','smoke-fan','explosion-constant-uv',
        'kart-shadow-black-diffuse','skidmark'].includes(spec.id);
      material.depthTest=!spec.id.startsWith('hud-')&&spec.id!=='finish-flag-nearest';
      const mesh=new THREE.Mesh(spec.geometry,material);mesh.frustumCulled=false;group.add(mesh);
      spec.geometry.computeBoundingBox();
      const box=spec.geometry.boundingBox,center=box.getCenter(new THREE.Vector3()),dimensions=box.getSize(new THREE.Vector3());
      const extent=Math.max(dimensions.x,dimensions.y)*.55||1;
      Object.assign(camera,{left:center.x-extent,right:center.x+extent,bottom:center.y-extent,top:center.y+extent});
      camera.position.set(center.x,center.y,-box.min.z+extent*3+1);
      camera.lookAt(center.x,center.y,-center.z);camera.updateProjectionMatrix();
      const render=map=>{
        material.map=map;material.needsUpdate=true;
        renderer.setRenderTarget(target);renderer.render(scene,camera);
        const data=new Uint8Array(size*size*4);
        renderer.readRenderTargetPixels(target,0,0,size,size,data);return data;
      };
      const before=render(control),after=render(corrected);
      // The target receives Three's linear clear-color bytes. Read the known
      // geometry-free corner instead of assuming the input hex is unchanged.
      const backgroundRGB=Array.from(after.slice(0,3));
      let changedPixels=0,nonBackgroundPixels=0;const deltaRGB=[0,0,0];
      for(let i=0;i<before.length;i+=4){
        if([0,1,2].some(axis=>before[i+axis]!==after[i+axis]))changedPixels++;
        if([0,1,2].some(axis=>after[i+axis]!==backgroundRGB[axis]))nonBackgroundPixels++;
        for(let axis=0;axis<3;axis++)deltaRGB[axis]+=after[i+axis]-before[i+axis];
      }
      checks.push({id:spec.id,file:spec.file,source:spec.source,changedPixels,nonBackgroundPixels,backgroundRGB,deltaRGB,
        fixedKeyFilter:fixed.userData.nativeColorKeyFilter===true,
        fixedPremultiplyAlpha:fixed.premultiplyAlpha,unchanged:Boolean(spec.unchanged),requiredChange:Boolean(spec.requiredChange),
        fixedFormat:fixed.userData.nativeTextureFormat,controlFormat:control.userData.nativeTextureFormat,
        independentControlPixels:control.image.data!==fixed.image.data,
        blend:{source:material.blendSrc,destination:material.blendDst,depthWrite:material.depthWrite,depthTest:material.depthTest},
        vertices:spec.geometry.attributes.position.count});
      if(['rescue-ring','smoke-fan','hud-portrredcat','projectile-bubble'].includes(spec.id)){
        images.push({id:spec.id,before:pixelPng(before),after:pixelPng(after)});
      }
      mesh.removeFromParent();spec.geometry.dispose();material.dispose();control.dispose();corrected.dispose();
    }
    target.dispose();renderer.dispose();
    return {checks,images};
  });
  for(const image of result.images)for(const phase of ['before','after']){
    await writeFile(`${directory}/${image.id}-${phase}.png`,Buffer.from(image[phase].split(',')[1],'base64'));
  }
  delete result.images;
  await writeFile(`${directory}/browser.json`,JSON.stringify({status:'checking',...result,errors},null,2)+'\n');
  for(const check of result.checks){
    assert.equal(check.fixedKeyFilter,true,`${check.id}: shared loader must select semantic-key correction`);
    assert.equal(check.fixedPremultiplyAlpha,false,'keyed RGB is already zero before upload');
    assert.equal(check.fixedFormat,'RGB565');assert.equal(check.controlFormat,check.fixedFormat);
    assert.equal(check.independentControlPixels,true);
    assert.ok(check.nonBackgroundPixels>0,`${check.id}: visible output must survive`);
    if(check.unchanged)assert.equal(check.changedPixels,0,`${check.id}: unaffected native sampling must stay unchanged`);
    if(check.requiredChange)assert.ok(check.changedPixels>0,`${check.id}: control must reproduce contamination`);
  }
  assert.deepEqual(errors,[]);
  const report={status:'passed',browser:browser.version(),...result,errors,
    scope:'Representative original effect UV/color/geometry and actual shared RGB565 texture-loader comparisons. Controls differ only in retained pink RGB at keyed texels. Weather, explosion and shadow cases use bounded planar sampling patches. No original GPU screenshot equivalence is claimed.'};
  await writeFile(`${directory}/browser.json`,JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify(report));
}finally{await browser.close();}
