import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
const directory='evidence/more-settings';
await mkdir(directory,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,
  args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={status:'running',browser:browser.version(),checks:[],errors:[],
  scope:'Real RGB565 scene attachments, sequential blend rounding, optional WebGL2 multisample color/depth attachments, diagonal edge coverage and frozen original-track rendering. Hardware fallback is recorded; unsupported sample counts are not claimed.'};
try {
  const page=await browser.newPage({viewport:{width:800,height:600}});
  page.on('pageerror',error=>report.errors.push(error.message));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>rcsk.state.page==='driving',null,{timeout:60000});
  const result=await page.evaluate(async()=>{
    const THREE=await import('three');
    const {applyNativeByteColorPipeline}=await import('/source/asset-materials.js');
    const {MultisampleSceneRenderer}=await import('/source/multisample-renderer.js');
    const view=rcsk.viewer;view.suspend();view.clock.pause();
    const renderer=view.renderer,gl=renderer.getContext(),frames=[],data=[];
    function read(){const width=renderer.domElement.width,height=renderer.domElement.height;
      const bytes=new Uint8Array(width*height*4);gl.readPixels(0,0,width,height,gl.RGBA,gl.UNSIGNED_BYTE,bytes);return bytes;}
    function describeAttachments(target=view.multisampling.target){
      // Observe actual GL allocation through Three's retained attachment handles.
      const props=renderer.properties.get(target),oldFramebuffer=gl.getParameter(gl.FRAMEBUFFER_BINDING),oldRenderbuffer=gl.getParameter(gl.RENDERBUFFER_BINDING);
      gl.bindFramebuffer(gl.FRAMEBUFFER,props.__webglFramebuffer);
      const bits=[gl.FRAMEBUFFER_ATTACHMENT_RED_SIZE,gl.FRAMEBUFFER_ATTACHMENT_GREEN_SIZE,
        gl.FRAMEBUFFER_ATTACHMENT_BLUE_SIZE,gl.FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE]
        .map(parameter=>gl.getFramebufferAttachmentParameter(gl.FRAMEBUFFER,gl.COLOR_ATTACHMENT0,parameter));
      const complete=gl.checkFramebufferStatus(gl.FRAMEBUFFER)===gl.FRAMEBUFFER_COMPLETE;
      gl.bindFramebuffer(gl.FRAMEBUFFER,oldFramebuffer);
      const handles=[...(props.__webglColorRenderbuffer??[]),props.__webglDepthRenderbuffer].filter(Boolean);
      const samples=handles.map(handle=>{gl.bindRenderbuffer(gl.RENDERBUFFER,handle);
        const count=gl.getRenderbufferParameter(gl.RENDERBUFFER,gl.RENDERBUFFER_SAMPLES);
        return count;});
      gl.bindRenderbuffer(gl.RENDERBUFFER,oldRenderbuffer);
      return {bits,complete,samples,internalFormat:target.texture.internalFormat};
    }
    for(const samples of [0,2,4,8,0]){
      view.resize({resolution:'800x600',renderScale:100,msaaEnabled:samples>0,msaaSamples:samples||4});
      view.updatePresentation(0);view.renderScene();const bytes=read();data.push(bytes);
      frames.push({requested:samples,status:{...view.msaaStatus},attachment:describeAttachments(),
        glError:gl.getError(),png:renderer.domElement.toDataURL()});
    }
    const comparisons=data.slice(1).map(bytes=>{let different=0,total=0,max=0;
      for(let i=0;i<bytes.length;i+=4){let error=0;for(let c=0;c<3;c++){const d=Math.abs(bytes[i+c]-data[0][i+c]);error=Math.max(error,d);total+=d;max=Math.max(max,d);}if(error>0)different++;}
      return {differentFraction:different/(bytes.length/4),meanError:total/(bytes.length/4*3),max};});
    const originalScene=view.scene,originalCamera=view.camera;
    const scene=new THREE.Scene(),camera=new THREE.OrthographicCamera(-1,1,1,-1,.1,10);camera.position.z=1;
    const geometry=new THREE.BufferGeometry();geometry.setAttribute('position',new THREE.Float32BufferAttribute([-.8,-.7,0,.8,-.63,0,-.13,.84,0],3));
    const material=applyNativeByteColorPipeline(new THREE.MeshBasicMaterial({color:0xffffff}));
    scene.add(new THREE.Mesh(geometry,material));view.scene=scene;view.camera=camera;
    const edge=[];const originalClear=renderer.getClearColor(new THREE.Color());renderer.setClearColor(0);
    for(const samples of [0,4]){
      view.resize({resolution:'800x600',renderScale:100,msaaEnabled:samples>0,msaaSamples:4});
      view.renderScene();const bytes=read();let coveragePixels=0,whitePixels=0;
      for(let i=0;i<bytes.length;i+=4){if(bytes[i]>0&&bytes[i]<255)coveragePixels++;if(bytes[i]===255)whitePixels++;}
      edge.push({samples,actual:view.msaaStatus.actualSamples,coveragePixels,whitePixels,glError:gl.getError()});
    }
    // The same native 16-bit rounding applies with MSAA disabled and enabled.
    scene.remove(scene.children[0]);renderer.setClearColor(0x5192c7);
    const clears=[];for(const samples of [0,4]){view.resize({resolution:'800x600',renderScale:100,msaaEnabled:samples>0,msaaSamples:4});view.renderScene();clears.push([...read().slice(0,4)]);}
    // Two black alpha blends must round after EACH draw. Quantizing only the
    // final 8-bit result would produce [66,65,66], rather than [58,61,58].
    const blendGeometry=new THREE.PlaneGeometry(2,2),blendMaterial=applyNativeByteColorPipeline(
      new THREE.MeshBasicMaterial({color:0,opacity:128/255,transparent:true,
        depthTest:false,depthWrite:false,blending:THREE.CustomBlending,
        blendSrc:THREE.SrcAlphaFactor,blendDst:THREE.OneMinusSrcAlphaFactor}));
    const ditherDuring=[],ditherBefore=gl.isEnabled(gl.DITHER),blends=[];
    const first=new THREE.Mesh(blendGeometry,blendMaterial),second=new THREE.Mesh(blendGeometry,blendMaterial);
    first.onBeforeRender=()=>ditherDuring.push(gl.isEnabled(gl.DITHER));
    second.onBeforeRender=first.onBeforeRender;renderer.setClearColor(0xffffff);
    for(const samples of [0,4]){
      view.resize({resolution:'800x600',renderScale:100,msaaEnabled:samples>0,msaaSamples:4});
      renderer.state.enable(gl.DITHER);scene.add(first);view.renderScene();
      const single=[...read().slice(0,4)],restoredEnabled=gl.isEnabled(gl.DITHER);
      renderer.state.disable(gl.DITHER);scene.add(second);view.renderScene();
      blends.push({samples,single,double:[...read().slice(0,4)],restoredEnabled,restoredDisabled:!gl.isEnabled(gl.DITHER)});
      scene.remove(first,second);
    }
    if(ditherBefore)renderer.state.enable(gl.DITHER);else renderer.state.disable(gl.DITHER);
    blendGeometry.dispose();blendMaterial.dispose();
    // An inspection view can render before configure()/resize().
    const lazy=new MultisampleSceneRenderer(renderer);lazy.render(scene,camera);
    const lazyTarget=lazy.target;let lazyDisposals=0;lazyTarget.addEventListener('dispose',()=>lazyDisposals++);
    const lazyResult={attachment:describeAttachments(lazyTarget),samples:lazyTarget.samples,
      size:[lazyTarget.width,lazyTarget.height],canvas:[renderer.domElement.width,renderer.domElement.height]};
    lazy.dispose();Object.assign(lazyResult,{disposed:lazyDisposals,targetReleased:lazy.target===null,uniformReleased:lazy.material.uniforms.image.value===null});
    geometry.dispose();material.dispose();renderer.setClearColor(originalClear);view.scene=originalScene;view.camera=originalCamera;
    // A resize must dispose/reallocate its sample attachment without retaining the old dimensions.
    const oldTarget=view.multisampling.target;let resizeDisposals=0;oldTarget.addEventListener('dispose',()=>resizeDisposals++);
    view.resize({resolution:'auto',renderScale:50,msaaEnabled:true,msaaSamples:4});view.renderScene();
    const resized={canvas:[renderer.domElement.width,renderer.domElement.height],target:[view.multisampling.target.width,view.multisampling.target.height],disposed:resizeDisposals,error:gl.getError()};
    const multisampleTarget=view.multisampling.target;let disableDisposals=0;multisampleTarget.addEventListener('dispose',()=>disableDisposals++);
    view.resize({resolution:'800x600',renderScale:100,msaaEnabled:false});
    view.renderScene();
    return {contextAntialias:gl.getContextAttributes().antialias,contextAlpha:gl.getContextAttributes().alpha,frames,comparisons,edge,clears,blends,ditherDuring,lazyResult,resized,
      disabled:{disposed:disableDisposals,replaced:view.multisampling.target!==multisampleTarget,samples:view.multisampling.target.samples,attachment:describeAttachments()}};
  });
  for(const [index,frame]of result.frames.entries()){
    await writeFile(`${directory}/msaa-${index}-${frame.requested}.png`,Buffer.from(frame.png.split(',')[1],'base64'));delete frame.png;
    assert.equal(frame.glError,0);assert.equal(frame.attachment.complete,true);assert.deepEqual(frame.attachment.bits,[5,6,5,0]);assert.equal(frame.attachment.internalFormat,'RGB565');
    if(frame.requested){assert.ok(frame.status.actualSamples>=2);assert.ok(frame.attachment.samples.length>=2);assert.ok(frame.attachment.samples.every(value=>value===frame.status.actualSamples));}
    else assert.equal(frame.status.actualSamples,0);
  }
  assert.equal(result.contextAntialias,false);
  assert.equal(result.contextAlpha,false);
  assert.equal(result.edge[0].coveragePixels,0);
  assert.ok(result.edge[1].coveragePixels>100,JSON.stringify(result.edge));
  assert.ok(result.edge.every(row=>row.whitePixels>10000&&row.glError===0));
  assert.deepEqual(result.clears,[[82,146,197,255],[82,146,197,255]]);
  for(const blend of result.blends){
    assert.deepEqual(blend.single,[123,125,123,255]);assert.deepEqual(blend.double,[58,61,58,255]);
    assert.equal(blend.restoredEnabled,true);assert.equal(blend.restoredDisabled,true);
  }
  assert.ok(result.ditherDuring.length>=6);assert.ok(result.ditherDuring.every(enabled=>!enabled));
  assert.deepEqual(result.lazyResult.attachment.bits,[5,6,5,0]);assert.equal(result.lazyResult.attachment.complete,true);
  assert.equal(result.lazyResult.samples,0);assert.deepEqual(result.lazyResult.size,result.lazyResult.canvas);
  assert.equal(result.lazyResult.disposed,1);assert.equal(result.lazyResult.targetReleased,true);assert.equal(result.lazyResult.uniformReleased,true);
  assert.equal(result.comparisons.at(-1).differentFraction,0,'off/on/off must reproduce the same frozen image');
  assert.ok(result.comparisons.slice(0,3).every(row=>row.meanError<4),'MSAA must preserve scene colors');
  assert.deepEqual(result.resized.canvas,result.resized.target);assert.equal(result.resized.error,0);assert.equal(result.resized.disposed,1);
  assert.equal(result.disabled.disposed,1);assert.equal(result.disabled.replaced,true);assert.equal(result.disabled.samples,0);
  assert.deepEqual(result.disabled.attachment.bits,[5,6,5,0]);assert.equal(result.disabled.attachment.complete,true);
  report.checks.push('actual RGB565 and multisample attachments','per-draw blend rounding','dither disabled during drawing and caller state restored',
    'resolved fractional edge coverage','native quantized clear colors and exact off/on/off image','lazy allocation, resize and sample attachment disposal');
  report.result=result;assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.error=error.stack;process.exitCode=1;}
finally{await writeFile(`${directory}/msaa-validation.json`,JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(JSON.stringify(report,null,2));
