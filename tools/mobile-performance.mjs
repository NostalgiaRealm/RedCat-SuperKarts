#!/usr/bin/env node
// Repeatable browser benchmark for the race on an emulated phone. It measures
// the main-thread cost of updates and frames, GPU drain, draw calls, uploads,
// allocation and loading. Software-rendered GPU numbers are a relative measure
// of fill work between two builds, not a prediction of any phone's frame rate.
//
//   node tools/serve.mjs &
//   node tools/mobile-performance.mjs --out report.json [--profile portrait]
//     [--track 0] [--throttle 4] [--ticks 400] [--url http://127.0.0.1:4173]
import {chromium} from 'playwright';
import {writeFile} from 'node:fs/promises';

const option=(name,fallback)=>{const index=process.argv.indexOf('--'+name);return index<0?fallback:process.argv[index+1];};
const url=(option('url',process.env.RCSK_URL||'http://127.0.0.1:4173')).replace(/\/?$/,'/');
const track=Number(option('track','0')),throttle=Number(option('throttle','4')),ticks=Number(option('ticks','400'));
const profiles={
  portrait:{viewport:{width:393,height:852},deviceScaleFactor:3,isMobile:true,hasTouch:true},
  landscape:{viewport:{width:852,height:393},deviceScaleFactor:3,isMobile:true,hasTouch:true},
  budget:{viewport:{width:360,height:800},deviceScaleFactor:2,isMobile:true,hasTouch:true},
  desktop:{viewport:{width:1280,height:720},deviceScaleFactor:1},
};
const profileName=option('profile','portrait'),device=profiles[profileName];
if(!device)throw new Error('Unknown profile '+profileName);
const launch=()=>chromium.launch({executablePath:process.env.CHROME_PATH||undefined,headless:true,
  args:['--autoplay-policy=no-user-gesture-required','--enable-precise-memory-info','--js-flags=--expose-gc']});
const statistics=values=>{
  const sorted=[...values].sort((a,b)=>a-b),count=sorted.length;
  const at=p=>sorted[Math.min(count-1,Math.floor(p*count))]??0;
  const round=value=>Math.round(value*1000)/1000;
  return {count,mean:round(sorted.reduce((sum,value)=>sum+value,0)/Math.max(1,count)),p50:round(at(.5)),p95:round(at(.95)),max:round(sorted.at(-1)??0)};
};

async function openRace(browser,{countCalls=false}={}){
  const context=await browser.newContext(device),page=await context.newPage();
  const responses={count:0,failed:[]};
  page.on('response',response=>{responses.count++;if(response.status()>=400)responses.failed.push(response.url());});
  const errors=[];
  page.on('pageerror',error=>errors.push(error.message));
  await page.addInitScript(countCalls=>{
    performance.setResourceTimingBufferSize(20000);
    window.__perf={navigationStart:performance.now()};
    if(!countCalls)return;
    // Count every WebGL call; used only in the separate counting pass because
    // the wrappers themselves cost main-thread time.
    const counts=window.__glCounts={calls:{},bufferBytes:0,bufferDataBytes:0,textureBytes:0,enabled:false};
    const prototype=WebGL2RenderingContext.prototype;
    for(const name of Object.getOwnPropertyNames(prototype)){
      const descriptor=Object.getOwnPropertyDescriptor(prototype,name);
      if(typeof descriptor.value!=='function')continue;
      const original=descriptor.value;
      prototype[name]=function(...args){
        if(counts.enabled){
          counts.calls[name]=(counts.calls[name]??0)+1;
          if(name==='bufferSubData'){const data=args[2];counts.bufferBytes+=args.length>4&&args[4]?args[4]*(data.BYTES_PER_ELEMENT||1):(data?.byteLength??0);}
          if(name==='bufferData'&&typeof args[1]==='object')counts.bufferDataBytes+=args[1]?.byteLength??0;
          if(name==='texSubImage2D'||name==='texImage2D')counts.textureBytes+=args.at(-1)?.byteLength??0;
        }
        return original.apply(this,args);
      };
    }
  },countCalls);
  const started=Date.now();
  await page.goto(url+'?drive='+track);
  await page.waitForFunction(()=>window.rcsk?.state.page==='driving'&&window.rcsk.viewer.clock.tick>1,null,{timeout:300000});
  return {context,page,responses,errors,loadMs:Date.now()-started};
}

// Page helpers: stop the live loops and drive the race with fixed 25 ms updates.
const installHelpers=page=>page.evaluate(()=>{
  const view=window.rcsk.viewer,timers=window.__timers={};
  view.updateLoop.stop();view.active=false;view.clock.pause?.();
  window.__now=view.clock.simulationMs;
  const wrap=(object,name,label=name)=>{
    if(!object||typeof object[name]!=='function')return;
    const original=object[name];
    object[name]=function(...args){
      const start=performance.now();
      try{return original.apply(this,args);}
      finally{(timers[label]??=[]).push(performance.now()-start);}
    };
  };
  window.__wrapAll=()=>{
    wrap(view.simulation,'step','simulation.step');
    wrap(view,'applyVisibleSectors');
    wrap(view,'updatePresentation');
    wrap(view,'advanceSceneryCallbacks');
    wrap(view.multisampling,'render','world pass');
    wrap(view.multisampling,'compose','hud compose');
    wrap(view.hud,'render','hud.render');
    wrap(view.hudMeshes,'capture','hudMeshes.capture');
    for(const name of ['streamVisuals','smokeVisuals','skidmarkVisuals','weatherVisuals','explosionVisuals','projectiles','bubbleVisuals','rescueVisuals','homingArmVisuals','finishFlag'])
      wrap(view[name],'capture',name+'.capture');
    for(const shadow of view.shadows)wrap(shadow,'capture','shadow.capture');
    for(const visual of [view.playerVisual,...view.opponentVisuals]){
      wrap(visual,'advanceAnimation','kart.advanceAnimation');
      wrap(visual,'captureColor','kart.captureColor');
      wrap(visual,'capturePose','kart.capturePose');
    }
    wrap(view.audio,'updateScenery','audio.updateScenery');
    wrap(view.audio,'updateVoices','audio.updateVoices');
    wrap(view.audio,'updateEngine','audio.updateEngine');
    wrap(view.audio,'updateSkid','audio.updateSkid');
  };
  window.__tick=()=>view.onTick(.025,window.__now+=25);
  window.__frame=alpha=>{view.updatePresentation(alpha);view.renderScene({present:!view.hud});view.hud?.render();};
  window.__sync=()=>{const gl=view.renderer.getContext();gl.readPixels(0,0,1,1,gl.RGBA,gl.UNSIGNED_BYTE,new Uint8Array(4));};
  window.__stat=()=>{const info=view.renderer.info,world=view.renderStats?.world,gl=view.renderer.getContext();
    return {canvas:[gl.drawingBufferWidth,gl.drawingBufferHeight],world:world?{calls:world.calls,triangles:world.triangles,width:world.width,height:world.height}:null,
      hud:view.hud?.stats?{glyphs:view.hud.stats.glyphs,elements:view.hud.stats.order.length}:null,
      memory:{...info.memory},programs:info.programs?.length,objects:view.group.children.length,
      activeJets:view.simulation.streams.jets.length,ribbons:view.simulation.streams.ribbons.length,
      ribbonVertices:view.simulation.streams.ribbons.reduce((sum,entry)=>sum+entry.vertices.length,0),speed:view.simulation.playerSpeedKmh};};
  return true;
});

async function mainThreadPass(browser,{profiling=false}={}){
  const {context,page,errors,responses,loadMs}=await openRace(browser);
  const client=await context.newCDPSession(page);
  const load=await page.evaluate(()=>{
    const entries=performance.getEntriesByType('resource');
    const byType={};
    for(const entry of entries){
      const extension=new URL(entry.name).pathname.split('.').pop();
      const group=byType[extension]??={count:0,bytes:0,decoded:0};
      group.count++;group.bytes+=entry.transferSize||0;group.decoded+=entry.decodedBodySize||0;
    }
    return {requests:entries.length,transferBytes:entries.reduce((s,e)=>s+(e.transferSize||0),0),decodedBytes:entries.reduce((s,e)=>s+(e.decodedBodySize||0),0),byType};
  });
  await page.keyboard.down('ArrowUp');
  await installHelpers(page);
  // Warm the JIT and reach racing speed before anything is timed.
  await page.evaluate(ticks=>{for(let i=0;i<ticks;i++){window.__tick();if(i%2===0)window.__frame(1);}},120);
  await page.evaluate(()=>window.gc?.());
  const heapBefore=await page.evaluate(()=>performance.memory.usedJSHeapSize);
  await client.send('Emulation.setCPUThrottlingRate',{rate:throttle});
  if(profiling){
    await client.send('HeapProfiler.enable');
    await client.send('HeapProfiler.startSampling',{samplingInterval:8192,includeObjectsCollectedByMajorGC:true,includeObjectsCollectedByMinorGC:true});
    await client.send('Profiler.enable');
    await client.send('Profiler.setSamplingInterval',{interval:500});
    await client.send('Profiler.start');
  }else await page.evaluate(()=>window.__wrapAll());
  const timing=await page.evaluate(ticks=>{
    const tick=[],frame=[];
    let frames=0;
    for(let i=0;i<ticks;i++){
      let start=performance.now();window.__tick();tick.push(performance.now()-start);
      // 60 Hz on a 25 ms update: two frames for most updates, alternating alphas.
      for(const alpha of i%2?[.33,1]:[.66]){start=performance.now();window.__frame(alpha);frame.push(performance.now()-start);frames++;}
    }
    return {tick,frame,frames,timers:window.__timers,stat:window.__stat()};
  },ticks);
  const heapAfter=await page.evaluate(()=>performance.memory.usedJSHeapSize);
  let topSelf,topAllocators,sampledKiBPerTick;
  if(profiling){
    const {profile}=await client.send('Profiler.stop');
    const {profile:heap}=await client.send('HeapProfiler.stopSampling');
    const self=new Map(),dt=profile.timeDeltas,samples=profile.samples,nodes=new Map(profile.nodes.map(node=>[node.id,node]));
    samples.forEach((id,index)=>{
      const node=nodes.get(id),frame=node.callFrame,key=`${frame.functionName||'(anonymous)'} ${frame.url.split('/').pop()}:${frame.lineNumber+1}`;
      self.set(key,(self.get(key)??0)+(dt[index]||0));
    });
    const total=[...self.values()].reduce((a,b)=>a+b,0);
    topSelf=[...self].sort((a,b)=>b[1]-a[1]).slice(0,60).map(([name,us])=>({name,ms:Math.round(us/1000),percent:Math.round(us/total*1000)/10}));
    const allocated=new Map();
    const walk=node=>{const frame=node.callFrame,key=`${frame.functionName||'(anonymous)'} ${frame.url.split('/').pop()}:${frame.lineNumber+1}`;
      allocated.set(key,(allocated.get(key)??0)+node.selfSize);node.children?.forEach(walk);};
    walk(heap.head);
    const totalAllocated=[...allocated.values()].reduce((a,b)=>a+b,0);
    sampledKiBPerTick=Math.round(totalAllocated/1024/ticks*10)/10;
    topAllocators=[...allocated].sort((a,b)=>b[1]-a[1]).slice(0,40).map(([name,bytes])=>({name,kib:Math.round(bytes/1024)}));
  }
  await client.send('Emulation.setCPUThrottlingRate',{rate:1});
  const timers=Object.fromEntries(Object.entries(timing.timers).map(([name,values])=>[name,{...statistics(values),perTick:Math.round(values.reduce((a,b)=>a+b,0)/ticks*1000)/1000}]));
  await page.keyboard.up('ArrowUp');
  await context.close();
  return {loadMs,responses:responses.count,failedResponses:responses.failed,errors,load,throttle,
    tickMs:statistics(timing.tick),frameMs:statistics(timing.frame),frames:timing.frames,timers,stat:timing.stat,
    budgetAt60Hz:Math.round((timing.tick.reduce((a,b)=>a+b,0)/ticks/25+timing.frame.reduce((a,b)=>a+b,0)/timing.frames/(1000/60))*1000)/10,
    heap:{before:heapBefore,after:heapAfter,sampledKiBPerTick},topSelf,topAllocators};
}

async function gpuPass(browser){
  // Unthrottled main thread: what remains is the wait for the (software) GPU.
  const {context,page}=await openRace(browser);
  await page.keyboard.down('ArrowUp');
  await installHelpers(page);
  await page.evaluate(()=>{for(let i=0;i<120;i++){window.__tick();if(i%2===0)window.__frame(1);}window.__frame(1);window.__sync();});
  const result=await page.evaluate(()=>{
    const submit=[],total=[];
    for(let i=0;i<40;i++){
      if(i%2===0)window.__tick();
      const start=performance.now();window.__frame(.5);submit.push(performance.now()-start);window.__sync();total.push(performance.now()-start);
    }
    return {submit,total,stat:window.__stat()};
  });
  await page.keyboard.up('ArrowUp');
  await context.close();
  return {submitMs:statistics(result.submit),totalMs:statistics(result.total),stat:result.stat};
}

async function countPass(browser){
  const {context,page}=await openRace(browser,{countCalls:true});
  await page.keyboard.down('ArrowUp');
  await installHelpers(page);
  await page.evaluate(()=>{for(let i=0;i<120;i++){window.__tick();if(i%2===0)window.__frame(1);}window.__frame(1);});
  const result=await page.evaluate(()=>{
    const counts=window.__glCounts;
    counts.enabled=true;for(const key of Object.keys(counts.calls))delete counts.calls[key];
    counts.bufferBytes=counts.bufferDataBytes=counts.textureBytes=0;
    const ticks=40;let frames=0;
    for(let i=0;i<ticks;i++){window.__tick();for(const alpha of i%2?[.33,1]:[.66]){window.__frame(alpha);frames++;}}
    counts.enabled=false;
    return {ticks,frames,calls:{...counts.calls},bufferBytes:counts.bufferBytes,bufferDataBytes:counts.bufferDataBytes,textureBytes:counts.textureBytes};
  });
  await page.keyboard.up('ArrowUp');
  await context.close();
  const per=(value,count)=>Math.round(value/count*10)/10;
  return {perFrame:Object.fromEntries(Object.entries(result.calls).sort((a,b)=>b[1]-a[1]).slice(0,28).map(([name,value])=>[name,per(value,result.frames)])),
    uploadKiBPerTick:Math.round((result.bufferBytes+result.bufferDataBytes)/1024/result.ticks*10)/10,
    textureKiBPerTick:Math.round(result.textureBytes/1024/result.ticks*10)/10};
}

async function livePass(browser){
  // The real loops with rAF, timers and throttled main thread.
  const {context,page}=await openRace(browser);
  const client=await context.newCDPSession(page);
  await client.send('Emulation.setCPUThrottlingRate',{rate:throttle});
  await page.keyboard.down('ArrowUp');
  const live=await page.evaluate(()=>new Promise(resolve=>{
    const view=window.rcsk.viewer,frames=[],long=[];
    const startTick=view.clock.tick;
    new PerformanceObserver(list=>{for(const entry of list.getEntries())long.push(entry.duration);}).observe({type:'longtask',buffered:false});
    let last=performance.now();const end=last+12000;
    const step=now=>{frames.push(now-last);last=now;if(now<end)requestAnimationFrame(step);
      else resolve({frames,long,ticks:view.clock.tick-startTick,seconds:12});};
    requestAnimationFrame(step);
  }));
  await page.keyboard.up('ArrowUp');
  await context.close();
  return {fps:Math.round(live.frames.length/live.seconds*10)/10,updatesPerSecond:Math.round(live.ticks/live.seconds*10)/10,
    frameIntervalMs:statistics(live.frames),longTasks:{count:live.long.length,totalMs:Math.round(live.long.reduce((a,b)=>a+b,0))}};
}

const browser=await launch();
try{
  const report={url,track,profile:profileName,device,browser:browser.version(),throttle,ticks};
  report.mainThread=await mainThreadPass(browser);
  report.profile=await mainThreadPass(browser,{profiling:true});
  report.gpu=await gpuPass(browser);
  report.calls=await countPass(browser);
  report.live=await livePass(browser);
  const out=option('out');
  if(out)await writeFile(out,JSON.stringify(report,null,2)+'\n');
  const {mainThread:m,gpu,calls,live}=report;
  console.log(JSON.stringify({profile:profileName,track,throttle,
    canvas:gpu.stat.canvas,world:gpu.stat.world,programs:gpu.stat.programs,gpuMemory:gpu.stat.memory,
    load:{ms:m.loadMs,requests:m.load.requests,transferMiB:Math.round(m.load.transferBytes/1048576*10)/10,decodedMiB:Math.round(m.load.decodedBytes/1048576*10)/10},
    tickMs:m.tickMs,frameMs:m.frameMs,budgetPercentAt60Hz:m.budgetAt60Hz,gpuTotalMs:gpu.totalMs,gpuSubmitMs:gpu.submitMs,
    allocKiBPerTick:report.profile.heap.sampledKiBPerTick,uploadKiBPerTick:calls.uploadKiBPerTick,textureKiBPerTick:calls.textureKiBPerTick,
    live,errors:m.errors},null,1));
}finally{await browser.close();}
