import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {readFile,writeFile,mkdir} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const sourceConfig=JSON.parse(await readFile('public/assets/config.json'));
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),checks:[],errors:[],
  scope:'Real original WAV playing events in fresh browser profiles, intro completion/skip, later menu visits and reload. Explicit FIRSTTIME=1/missing variants are controlled source-configuration fixtures. Media runs at8x; no native sound-card recording is claimed.'};

async function open(name,{intro='none',flag='shipped'}={}){
  const context=await browser.newContext({viewport:{width:1024,height:768}});
  await context.addInitScript(()=>{
    window.menuGreetingPlays=[];
    const original=HTMLMediaElement.prototype.play;
    HTMLMediaElement.prototype.play=function(){
      this.playbackRate=8;
      this.addEventListener('playing',()=>window.menuGreetingPlays.push({
        file:this.currentSrc.split('/').at(-1),duration:this.duration,readyState:this.readyState,
      }),{once:true});
      return original.call(this);
    };
  });
  const page=await context.newPage();
  page.on('pageerror',error=>report.errors.push({name,error:error.message}));
  page.on('response',response=>{if(response.status()>=400)report.errors.push({name,error:response.status()+' '+response.url()});});
  if(flag!=='shipped'){
    const config=structuredClone(sourceConfig);
    if(flag==='missing')delete config['ini/settings.ini'].firsttime.phase_main;
    else config['ini/settings.ini'].firsttime.phase_main=String(flag);
    await page.route('**/assets/config.json',route=>route.fulfill({json:config}));
  }
  await page.goto(origin+(intro==='none'?'/?skipIntro':'/'));
  if(intro!=='none'){
    await page.waitForFunction(()=>rcsk.state.page==='intro'&&document.querySelector('#movie').readyState>=2&&!document.querySelector('#movie').paused);
    if(intro==='skip')await page.locator('#movie').click();
    else await page.locator('#movie').evaluate(video=>{video.currentTime=Math.max(0,video.duration-.2);});
  }
  return {context,page,name};
}

async function greeting(run,file,{first=0,label=run.name}={}){
  await run.page.waitForFunction(({file,first})=>rcsk.state.page==='main'
    &&window.menuGreetingPlays.slice(first).some(play=>play.file===file&&play.duration>0&&play.readyState>=2),{file,first});
  const actual=await run.page.evaluate(first=>({
    selected:rcsk.state.menuAudio,plays:window.menuGreetingPlays.slice(first),
    stored:localStorage.getItem('rcsk.firsttime.main'),
  }),first);
  assert.equal(actual.selected,file);
  assert.equal(actual.stored,'1');
  report.checks.push({name:label,expected:file,...actual});
}

try{
  const fresh=await open('fresh profile, direct menu');
  await greeting(fresh,'mn_hm02.wav');
  let first=await fresh.page.evaluate(()=>window.menuGreetingPlays.length);
  await fresh.page.locator('[data-native=btnMainOptions]').click();
  await fresh.page.waitForSelector('[data-form=TFRMOPTIONS]');
  await fresh.page.locator('[data-native=btnBack]').click();
  await greeting(fresh,'mn_hm02.wav',{first,label:'return from options'});
  first=await fresh.page.evaluate(()=>window.menuGreetingPlays.length);
  await fresh.page.setViewportSize({width:390,height:844});
  await fresh.page.waitForTimeout(150);
  assert.equal(await fresh.page.evaluate(()=>window.menuGreetingPlays.length),first);
  report.checks.push({name:'orientation redraw does not repeat greeting',newPlays:0});
  await fresh.page.reload();
  await greeting(fresh,'mn_hm02.wav',{label:'page reload retains native consumed flag'});
  await fresh.context.close();

  for(const intro of ['skip','ended']){
    const run=await open('intro '+intro,{intro});
    await greeting(run,'mn_hm02.wav');
    await run.context.close();
  }
  for(const flag of [1,'missing']){
    const run=await open('controlled FIRSTTIME '+flag,{flag});
    await greeting(run,'mn_hm01.wav');
    await run.page.reload();
    await greeting(run,'mn_hm02.wav',{label:'controlled FIRSTTIME '+flag+' consumed on reload'});
    await run.context.close();
  }
  assert.deepEqual(report.errors,[]);
  report.status='passed';
}catch(error){
  report.status='failed';report.failure=String(error.stack||error);throw error;
}finally{
  await mkdir('evidence/audio',{recursive:true});
  await writeFile('evidence/audio/menu-greeting-playback.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
  console.log(JSON.stringify({status:report.status,checks:report.checks.length,errors:report.errors}));
}
