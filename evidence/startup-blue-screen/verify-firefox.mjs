import assert from 'node:assert/strict';
import {writeFile} from 'node:fs/promises';
const endpoint='http://127.0.0.1:4447',origin='http://127.0.0.1:4173';
const report={scope:'Plain root URL in a disposable Firefox profile, Xvfb and software OpenGL. Intro playback may require its normal Start button under default autoplay policy. No production edits; existing game server remains untouched.',startedAt:new Date().toISOString(),checks:[]};
let session;
async function request(path,body,method=body?'POST':'GET'){
  const response=await fetch(endpoint+path,{method,headers:{'Content-Type':'application/json'},...(body?{body:JSON.stringify(body)}:{})});
  const result=await response.json();if(!response.ok||result.value?.error)throw Error(JSON.stringify(result.value));return result.value;
}
const script=(source,args=[])=>request(`/session/${session}/execute/sync`,{script:source,args});
async function until(source,timeout=60000){
  const start=Date.now();while(Date.now()-start<timeout){if(await script(source))return;await new Promise(r=>setTimeout(r,100));}
  throw Error('Firefox condition timed out: '+source);
}
async function click(selector){
  const element=await request(`/session/${session}/element`,{using:'css selector',value:selector});
  await request(`/session/${session}/element/${element['element-6066-11e4-a52e-4f735466cecf']}/click`,{});
}
async function screenshot(name){
  const png=await request(`/session/${session}/screenshot`);
  await writeFile(`evidence/startup-blue-screen/firefox-${name}.png`,Buffer.from(png,'base64'));
}
try{
  const created=await request('/session',{capabilities:{alwaysMatch:{browserName:'firefox','moz:firefoxOptions':{
    binary:'/usr/lib64/firefox/firefox',prefs:{'media.volume_scale':'0.0','webgl.force-enabled':true}}}}});
  session=created.sessionId;report.capabilities=created.capabilities;
  await request(`/session/${session}/window/rect`,{width:1024,height:900});
  await request(`/session/${session}/url`,{url:origin+'/'});
  await until("return window.rcsk?.state.page==='intro' && document.querySelector('#movie').readyState>=2");
  const initial=await script("const v=document.querySelector('#movie');return{url:location.href,page:rcsk.state.page,paused:v.paused,time:v.currentTime,readyState:v.readyState,error:v.error?.message??null,startVisible:!document.querySelector('#play-movie').hidden}");
  report.introInitial=initial;assert.equal(initial.url,origin+'/');assert.equal(initial.error,null);
  if(initial.paused){report.autoplayNotice=await script("const m=document.querySelector('#message');return{visible:!m.hidden,text:m.textContent,pointerEvents:getComputedStyle(m).pointerEvents}");assert.equal(report.autoplayNotice.visible,true);assert.equal(report.autoplayNotice.pointerEvents,'none');await click('#play-movie');report.introStartedBy='normal Start button while autoplay notice is visible';}else report.introStartedBy='autoplay';
  await until("const v=document.querySelector('#movie');return !v.paused&&v.currentTime>.3");
  await screenshot('intro');
  report.introPlaying=await script("const v=document.querySelector('#movie');return{time:v.currentTime,duration:v.duration,width:v.videoWidth,height:v.videoHeight,paused:v.paused,error:v.error?.message??null}");
  assert.ok(report.introPlaying.width>0&&report.introPlaying.height>0);
  report.checks.push('Plain root URL initializes the app and plays the original converted introduction');
  await request(`/session/${session}/actions`,{actions:[{type:'key',id:'keyboard',actions:[{type:'keyDown',value:'\uE007'},{type:'keyUp',value:'\uE007'}]}]});
  await until("return rcsk.state.page==='main'&&!!document.querySelector('[data-form=TFRMMAIN]')");
  await until("return document.fonts.status==='loaded'&&[...document.querySelectorAll('#screen img')].every(i=>i.complete&&i.naturalWidth>0)");
  report.menu=await script("return{page:rcsk.state.page,images:[...document.querySelectorAll('#screen img')].map(i=>({src:i.src,width:i.naturalWidth})),buttons:[...document.querySelectorAll('#screen button')].map(b=>b.textContent.trim())}");
  assert.ok(report.menu.images.length>0);await screenshot('main');
  report.checks.push('Skipping the introduction opens the original main menu with all images loaded');
  await request(`/session/${session}/url`,{url:origin+'/?drive=0'});
  await until("return window.rcsk?.state.page==='driving'&&rcsk.viewer.clock.tick>2");
  report.race=await script("const v=rcsk.viewer;return{page:rcsk.state.page,assetErrors:v.errors,triangles:v.renderer.info.render.triangles,driverFrames:v.driverFrames.size,webgl:v.renderer.getContext().getParameter(v.renderer.getContext().VERSION),position:[...v.motion.body.position],updates:v.motion.updates}");
  assert.deepEqual(report.race.assetErrors,[]);assert.ok(report.race.triangles>1000);assert.ok(report.race.driverFrames>10);
  await request(`/session/${session}/actions`,{actions:[{type:'key',id:'keyboard',actions:[{type:'keyDown',value:'\uE013'},{type:'pause',duration:1000},{type:'keyUp',value:'\uE013'}]}]});
  report.moved=await script("return rcsk.viewer.motion.snapshot()");
  assert.ok(report.moved.forwardSpeed>0&&report.moved.updates>report.race.updates);
  assert.ok(Math.hypot(...report.moved.position.map((v,i)=>v-report.race.position[i]))>1);
  await screenshot('race');report.checks.push('Race scene renders and real WebDriver acceleration moves the original kart');
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);process.exitCode=1;}
finally{
  if(session)await request(`/session/${session}`,undefined,'DELETE').catch(()=>{});
  report.completedAt=new Date().toISOString();
  await writeFile('evidence/startup-blue-screen/firefox.json',JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,version:report.capabilities?.browserVersion,checks:report.checks,failure:report.failure},null,2));
}
