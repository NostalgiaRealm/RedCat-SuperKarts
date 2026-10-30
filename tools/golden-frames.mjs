#!/usr/bin/env node
// Exact framebuffer hashes of races, to prove that render optimizations do not
// change a single pixel. Races run with fixed updates and seeds, so two builds
// can be compared; software rendering keeps the pixels reproducible.
//
//   node tools/serve.mjs &
//   node tools/golden-frames.mjs --out frames.json [--images folder]
//   node tools/golden-frames.mjs --compare frames.json [--images folder]
import {chromium} from 'playwright';
import {mkdir,readFile,writeFile} from 'node:fs/promises';

const option=(name,fallback)=>{const index=process.argv.indexOf('--'+name);return index<0?fallback:process.argv[index+1];};
const url=(option('url',process.env.RCSK_URL||'http://127.0.0.1:4173')).replace(/\/?$/,'/');
const images=option('images'),only=option('only');
const CHECKPOINTS=[1,20,60,120,200,320,480];
const CASES=[
  ...[0,1,2,3,4,5].map(track=>({name:`track-${track}`,track,viewport:{width:800,height:600},deviceScaleFactor:1,raceMode:0,difficulty:1,character:track%4})),
  {name:'portrait-touch',track:0,viewport:{width:390,height:844},deviceScaleFactor:1,hasTouch:true,isMobile:true,raceMode:0,difficulty:1,character:0},
  {name:'landscape-touch',track:3,viewport:{width:844,height:390},deviceScaleFactor:1,hasTouch:true,isMobile:true,raceMode:0,difficulty:0,character:1},
  {name:'msaa',track:2,viewport:{width:800,height:600},deviceScaleFactor:1,raceMode:0,difficulty:2,character:2,settings:{msaaEnabled:true,msaaSamples:4}},
  {name:'render-scale-50',track:4,viewport:{width:800,height:600},deviceScaleFactor:1,raceMode:0,difficulty:1,character:3,settings:{renderScale:50}},
  {name:'render-scale-150',track:5,viewport:{width:800,height:600},deviceScaleFactor:1,raceMode:2,difficulty:1,character:0,settings:{renderScale:150}},
  {name:'original-shadows-lights',track:3,viewport:{width:800,height:600},deviceScaleFactor:1,raceMode:0,difficulty:1,character:1,settings:{surfaceShadows:false,smoothEngineLights:false}},
  {name:'nearest-low-effects',track:1,viewport:{width:800,height:600},deviceScaleFactor:1,raceMode:0,difficulty:1,character:2,settings:{display:{brightnessLight:false,bilinearFiltering:false,alphaBlending:false,particles:false}}},
].filter(item=>!only||item.name===only);

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||undefined,headless:true,args:['--autoplay-policy=no-user-gesture-required']});
const results={};
try{
  if(images)await mkdir(images,{recursive:true});
  for(const item of CASES){
    const {name,track,viewport,deviceScaleFactor,hasTouch,isMobile,settings,raceMode,difficulty,character}=item;
    const context=await browser.newContext({viewport,deviceScaleFactor,hasTouch:Boolean(hasTouch),isMobile:Boolean(isMobile)});
    const page=await context.newPage(),errors=[];
    page.on('pageerror',error=>errors.push(error.message));
    await page.addInitScript(settings=>{
      if(settings)localStorage.setItem('rcsk.settings.v1',JSON.stringify(settings));
      // Sound is real-time; a silent no-op context keeps the run reproducible.
      window.AudioContext=class extends AudioContext{constructor(){super({latencyHint:'playback'});this.suspend();}};
    },settings??null);
    await page.goto(url+'?drive='+track);
    await page.waitForFunction(()=>window.rcsk?.state.page==='driving'&&window.rcsk.viewer.active,null,{timeout:180000});
    await page.keyboard.down('ArrowUp');
    // Reload the race with the loops stopped, so that it starts from a known state.
    await page.evaluate(async({track,raceMode,difficulty,character})=>{
      const view=window.rcsk.viewer;
      view.updateLoop.stop();view.active=false;
      await view.load(track,{character,difficulty,raceMode,countdown:false});
      view.active=false;view.updateLoop?.stop();
      window.__tick=0;window.__now=0;
      window.__hash=async alpha=>{
        view.updatePresentation(alpha);view.renderScene({present:!view.hud});view.hud?.render();
        const gl=view.renderer.getContext(),width=gl.drawingBufferWidth,height=gl.drawingBufferHeight;
        gl.bindFramebuffer(gl.FRAMEBUFFER,null);
        const pixels=new Uint8Array(width*height*4);gl.readPixels(0,0,width,height,gl.RGBA,gl.UNSIGNED_BYTE,pixels);
        const digest=await crypto.subtle.digest('SHA-256',pixels);
        return {width,height,sha:[...new Uint8Array(digest)].slice(0,12).map(byte=>byte.toString(16).padStart(2,'0')).join('')};
      };
    },{track,raceMode,difficulty,character});
    const frames={};
    for(const at of CHECKPOINTS){
      const frame=await page.evaluate(async at=>{
        const view=window.rcsk.viewer;
        while(window.__tick<at){window.__tick++;view.onTick(.025,window.__now+=25);}
        return {one:await window.__hash(1),half:await window.__hash(.5),paused:(view.hud?.render(),await window.__hash(.5))};
      },at);
      frames[at]=frame;
      if(images&&(at===60||at===320)){
        await page.evaluate(()=>{window.__hash(1);});
        await page.screenshot({path:`${images}/${name}-${at}.png`});
      }
    }
    results[name]={frames,errors};
    await page.keyboard.up('ArrowUp');
    await context.close();
    console.log(name.padEnd(26),`${frames[480].one.width}x${frames[480].one.height}`,frames[480].one.sha,errors.length?'ERRORS '+errors.join(';').slice(0,160):'');
  }
}finally{await browser.close();}
const out=option('out');
if(out)await writeFile(out,JSON.stringify(results,null,1)+'\n');
if(option('compare')){
  const expected=JSON.parse(await readFile(option('compare'),'utf8'));
  let different=0,total=0;
  for(const [name,result]of Object.entries(results))for(const [at,frame]of Object.entries(result.frames))for(const [kind,value]of Object.entries(frame)){
    total++;
    const reference=expected[name]?.frames[at]?.[kind];
    if(reference?.sha!==value.sha){different++;console.log(`DIFFERENT ${name} tick ${at} ${kind}: ${reference?.width}x${reference?.height} ${reference?.sha} -> ${value.width}x${value.height} ${value.sha}`);}
  }
  console.log(`${total-different} of ${total} frames identical`);
  process.exitCode=different?1:0;
}
