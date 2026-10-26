import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const output=process.env.RCSK_HUD_FRAMEBUFFER_OUTPUT||'evidence/hud-framebuffer';
await mkdir(output,{recursive:true});
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--autoplay-policy=no-user-gesture-required']});
const report={status:'running',browser:browser.version(),checks:[],errors:[],
  scope:'Focused source-only Chromium SwiftShader WebGL2 checks. The original font atlas and glyph rectangles are compared with CPU sampling and RGB565 per-draw rounding, including controlled vertex tint/alpha. Frozen original-track checks cover composition, order, resizing and MSAA transitions. No full race, build or historical GPU screenshot equivalence is claimed.'};
try{
  const page=await browser.newPage({viewport:{width:800,height:600}});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  await page.addInitScript(()=>localStorage.setItem('rcsk.settings.v1',JSON.stringify({touch:'off'})));
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?drive=0');
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
  await page.evaluate(()=>{const v=rcsk.viewer;v.updateLoop.stop();v.clock.pause();});

  report.synthetic=await page.evaluate(async()=>{
    const THREE=await import('three');
    const {HudTextRenderer}=await import('/source/hud-text-renderer.js');
    const {getHudStringSpec,layoutHudText}=await import('/source/hud-text.js');
    const {MultisampleSceneRenderer}=await import('/source/multisample-renderer.js');
    const view=rcsk.viewer,[config,manifest]=await view.resources;
    const renderer=new THREE.WebGLRenderer({alpha:false,antialias:false,preserveDrawingBuffer:true});
    renderer.setSize(96,96);renderer.outputColorSpace=THREE.SRGBColorSpace;renderer.setClearColor(0x5192c7);
    const pipeline=new MultisampleSceneRenderer(renderer),gl=renderer.getContext();
    pipeline.configure({msaaEnabled:false},96,96);
    const spec=getHudStringSpec(config,'string_lap');spec.rgba=[255,153,77,128];
    const hud={config,manifest,specs:new Map([['string_lap',spec]])};
    const glyphs=new HudTextRenderer(hud,file=>view.hudMeshes.texture(file));await glyphs.load();
    const glyph=layoutHudText(spec,'R')[0],source=glyph.source,map=glyphs.textures.get(source.texture);
    const priorFilter={min:map.minFilter,mag:map.magFilter};
    map.minFilter=map.magFilter=THREE.LinearFilter;map.needsUpdate=true;
    const scale=2.5,left=16.25,top=16.25;
    const layout={scale,text:()=>({x:left-glyph.x*scale,y:top-glyph.y*scale})};
    const scene=new THREE.Scene(),camera=new THREE.Camera(),pixels=[];
    const read=()=>{const bytes=new Uint8Array(96*96*4);gl.readPixels(0,0,96,96,gl.RGBA,gl.UNSIGNED_BYTE,bytes);return bytes;};
    pipeline.render(scene,camera);const base=read();
    const background=[...base.slice(0,3)];
    const draw=()=>glyphs.renderString(renderer,'string_lap','R',96,96,layout);
    const ditherDuring=[];
    pipeline.compose(r=>{ditherDuring.push(gl.isEnabled(gl.DITHER));draw();},96,96);const single=read();
    const firstMesh=glyphs.strings.get('string_lap').meshes[0],firstMaterial=firstMesh.material;
    const uv=[...firstMesh.geometry.attributes.uv.array],rgba=[...firstMesh.geometry.attributes.color.array];
    pipeline.compose(()=>{draw();draw();},96,96);const double=read();
    const sameMesh=firstMesh===glyphs.strings.get('string_lap').meshes[0];
    const sameMaterial=firstMaterial===glyphs.strings.get('string_lap').meshes[0].material;
    const {data,width,height}=map.image,maxima=[31,63,31];
    // Keep normalized 5/6-bit values between draws. Readback expansion rounds
    // them to bytes only at presentation, not before the next native blend.
    const quantize=rgb=>rgb.map((value,c)=>Math.round(Math.min(255,Math.max(0,value))*maxima[c]/255)*255/maxima[c]);
    const storedBackground=quantize(background);
    const sample=(u,v)=>{
      const sx=u*width-.5,sy=v*height-.5,x0=Math.floor(sx),y0=Math.floor(sy),fx=sx-x0,fy=sy-y0;
      const result=[0,0,0,0];
      for(const [dx,dy,weight]of [[0,0,(1-fx)*(1-fy)],[1,0,fx*(1-fy)],[0,1,(1-fx)*fy],[1,1,fx*fy]]){
        const x=((x0+dx)%width+width)%width,y=((y0+dy)%height+height)%height,offset=(y*width+x)*4;
        for(let c=0;c<3;c++)result[c]+=data[offset+c]/maxima[c]*255*weight;
        result[3]+=data[offset+3]/255*weight;
      }
      return result;
    };
    const coverageCounts={keyed:0,partial:0,opaque:0},selected={keyed:0,partial:0,opaque:0};
    const alpha=spec.rgba[3]/255;
    for(let y=Math.ceil(top);y<top+glyph.height*scale-1;y++)for(let x=Math.ceil(left);x<left+glyph.width*scale-1;x++){
      const u=(source.x+(x+.5-left)/(glyph.width*scale)*source.width)/width;
      const v=(source.y+(y+.5-top)/(glyph.height*scale)*source.height)/height;
      const texel=sample(u,v),kind=texel[3]<=1e-7?'keyed':texel[3]>=1-1e-7?'opaque':'partial';
      coverageCounts[kind]++;if(selected[kind]>=20)continue;
      selected[kind]++;
      const fragment=texel.slice(0,3).map((value,c)=>value*spec.rgba[c]/255);
      const blend=destination=>texel[3]<=1e-7?destination:quantize(fragment.map((value,c)=>value*alpha+destination[c]*(1-alpha)));
      const once=blend(storedBackground),twice=blend(once),offset=((95-y)*96+x)*4;
      pixels.push({kind,x,y,coverage:texel[3],single:{expected:once.map(Math.round),actual:[...single.slice(offset,offset+3)]},
        double:{expected:twice.map(Math.round),actual:[...double.slice(offset,offset+3)]}});
    }
    const countBefore=glyphs.strings.get('string_lap').glyphCount;
    glyphs.renderString(renderer,'string_lap','',96,96,layout);
    const empty={count:glyphs.strings.get('string_lap').glyphCount,visible:firstMesh.visible};
    const isDataTexture=map.isDataTexture,format=map.userData.nativeTextureFormat,flipY=map.flipY;
    let textureDisposals=0;map.addEventListener('dispose',()=>textureDisposals++);
    glyphs.dispose();pipeline.dispose();renderer.dispose();
    map.minFilter=priorFilter.min;map.magFilter=priorFilter.mag;map.needsUpdate=true;
    return {source,atlas:{width,height,isDataTexture,format,flipY},uv,rgba,background,coverageCounts,pixels,
      ditherDuring,sameMesh,sameMaterial,countBefore,empty,textureDisposals,glError:gl.getError()};
  });
  const synthetic=report.synthetic;
  assert.deepEqual(synthetic.background,[82,146,197]);
  assert.equal(synthetic.atlas.isDataTexture,true);assert.equal(synthetic.atlas.format,'RGB565');assert.equal(synthetic.atlas.flipY,false);
  const {source,atlas}=synthetic;
  const expectedUV=[source.x/atlas.width,source.y/atlas.height,(source.x+source.width)/atlas.width,source.y/atlas.height,
    source.x/atlas.width,(source.y+source.height)/atlas.height,(source.x+source.width)/atlas.width,(source.y+source.height)/atlas.height];
  synthetic.uv.forEach((value,i)=>assert.ok(Math.abs(value-expectedUV[i])<1e-7));
  assert.deepEqual(synthetic.rgba,Array.from({length:4},()=>[255,153,77,128]).flat());
  assert.ok(Object.values(synthetic.coverageCounts).every(count=>count>0));
  for(const row of synthetic.pixels)for(const name of ['single','double'])
    row[name].actual.forEach((value,c)=>assert.ok(Math.abs(value-row[name].expected[c])<=1,JSON.stringify({name,...row})));
  assert.ok(synthetic.ditherDuring.every(value=>value===false));
  assert.equal(synthetic.sameMesh,true);assert.equal(synthetic.sameMaterial,true);assert.equal(synthetic.countBefore,1);
  assert.deepEqual(synthetic.empty,{count:0,visible:false});assert.equal(synthetic.textureDisposals,0);assert.equal(synthetic.glError,0);
  report.checks.push({case:'original glyph UVs, packed texture orientation, tint/alpha and keyed bilinear edges round on each RGB565 draw',
    pixelComparisons:synthetic.pixels.length*2,toleranceBytes:1});

  report.integration=await page.evaluate(async()=>{
    const view=rcsk.viewer,renderer=view.renderer,gl=renderer.getContext(),frames=[];
    const read=()=>{const w=renderer.domElement.width,h=renderer.domElement.height,bytes=new Uint8Array(w*h*4);gl.readPixels(0,0,w,h,gl.RGBA,gl.UNSIGNED_BYTE,bytes);return bytes;};
    const describe=target=>{
      const props=renderer.properties.get(target),prior=gl.getParameter(gl.FRAMEBUFFER_BINDING);
      gl.bindFramebuffer(gl.FRAMEBUFFER,props.__webglFramebuffer);
      const bits=[gl.FRAMEBUFFER_ATTACHMENT_RED_SIZE,gl.FRAMEBUFFER_ATTACHMENT_GREEN_SIZE,
        gl.FRAMEBUFFER_ATTACHMENT_BLUE_SIZE,gl.FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE]
        .map(parameter=>gl.getFramebufferAttachmentParameter(gl.FRAMEBUFFER,gl.COLOR_ATTACHMENT0,parameter));
      const complete=gl.checkFramebufferStatus(gl.FRAMEBUFFER)===gl.FRAMEBUFFER_COMPLETE;
      gl.bindFramebuffer(gl.FRAMEBUFFER,prior);
      return {bits,complete,size:[target.width,target.height],samples:target.samples};
    };
    view.hud.notify(1,0,{capture:true}); // Original PAUZE notification without advancing physics.
    const clockBefore={race:view.race.elapsedMs,notice:view.hud.notifications.elapsedTotal};
    const textureRows=[...view.hud.textures].map(([name,map])=>({name,format:map.userData.nativeTextureFormat,
      dataTexture:map.isDataTexture,hasCanvas:!!map.canvasImage}));
    const pixels=[];
    for(const samples of [0,4,0]){
      view.resize({resolution:'800x600',renderScale:50,msaaEnabled:samples>0,msaaSamples:4});
      view.updatePresentation(1);view.renderScene({present:false});
      view.multisampling.compose(()=>null,800,600);const world=read();
      view.hud.render();const shown=read();pixels.push(shown);
      const stats={...view.hud.stats};let changed=0;
      for(let i=0;i<shown.length;i+=4)if(shown[i]!==world[i]||shown[i+1]!==world[i+1]||shown[i+2]!==world[i+2])changed++;
      view.hud.render();const repeated=read();let redrawn=0;
      for(let i=0;i<shown.length;i++)if(shown[i]!==repeated[i])redrawn++;
      frames.push({requested:samples,status:{...view.msaaStatus},world:describe(view.multisampling.target),
        display:describe(view.multisampling.compositionTarget),canvas:[renderer.domElement.width,renderer.domElement.height],
        changedPixels:changed,redrawDifferences:redrawn,stats,renderStats:view.renderStats,glError:gl.getError()});
    }
    let resetDifferences=0;for(let i=0;i<pixels[0].length;i++)if(pixels[0][i]!==pixels[2][i])resetDifferences++;
    const clockAfter={race:view.race.elapsedMs,notice:view.hud.notifications.elapsedTotal};
    return {frames,textureRows,clockBefore,clockAfter,resetDifferences,errors:view.errors,
      text:[...view.hud.glyphs.strings].map(([id,entry])=>({id,count:entry.glyphCount}))};
  });
  const integration=report.integration;
  assert.ok(integration.textureRows.length>0);
  assert.ok(integration.textureRows.every(row=>row.dataTexture&&row.format==='RGB565'&&!row.hasCanvas));
  for(const frame of integration.frames){
    for(const target of [frame.world,frame.display]){assert.deepEqual(target.bits,[5,6,5,0]);assert.equal(target.complete,true);}
    assert.deepEqual(frame.world.size,[400,300]);assert.deepEqual(frame.display.size,[800,600]);assert.deepEqual(frame.canvas,frame.display.size);
    assert.equal(frame.display.samples,frame.status.actualSamples);assert.equal(frame.world.samples,frame.status.actualSamples);
    if(frame.requested&&frame.status.supportedSamples.length)assert.ok(frame.status.actualSamples>=2);
    assert.ok(frame.changedPixels>1000);assert.equal(frame.redrawDifferences,0);assert.equal(frame.glError,0);
    assert.ok(frame.stats.calls>10&&frame.stats.triangles>100&&frame.stats.glyphs>20);
    assert.ok(frame.stats.order.indexOf('bonusframe')>=0);
    assert.ok(frame.stats.order.indexOf('string_bonus')>frame.stats.order.indexOf('bonusframe'));
    assert.ok(frame.stats.order.includes('string_special'));assert.equal(frame.renderStats.presentation.triangles,1);
    assert.ok(frame.renderStats.world.triangles>1000);assert.equal(frame.renderStats.hud.glyphs,frame.stats.glyphs);
  }
  assert.equal(integration.resetDifferences,0);assert.deepEqual(integration.clockBefore,integration.clockAfter);assert.deepEqual(integration.errors,[]);
  report.checks.push({case:'frozen native race HUD uses full-display RGB565, native order, identical paused redraws and MSAA off/on/off',
    configurations:integration.frames.length});
  await page.screenshot({path:output+'/native-hud-rgb565.png'});
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=error.stack;process.exitCode=1;}
finally{await writeFile(output+'/browser.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
console.log(JSON.stringify({status:report.status,checks:report.checks,failure:report.failure,errors:report.errors}));
