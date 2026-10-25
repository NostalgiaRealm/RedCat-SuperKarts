import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

// W3C WebDriver against a disposable Firefox profile. No user profile is used.
const endpoint=process.env.WEBDRIVER_URL||'http://127.0.0.1:4447';
const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
let session=null;
const report={environment:'Linux Firefox / Xvfb / software OpenGL; not a physical display or device',checks:[]};
async function request(path,body,method=body?'POST':'GET'){
  const r=await fetch(endpoint+path,{method,headers:{'Content-Type':'application/json'},...(body?{body:JSON.stringify(body)}:{})});
  const data=await r.json();if(!r.ok||data.value?.error)throw Error(JSON.stringify(data.value));
  return data.value;
}
const script=(code,args=[])=>request(`/session/${session}/execute/sync`,{script:code,args});
async function until(code,timeout=60000){
  const start=Date.now();
  while(Date.now()-start<timeout){if(await script(code))return;await new Promise(resolve=>setTimeout(resolve,100));}
  throw Error('Firefox condition timed out: '+code);
}
async function screenshot(name){
  const png=await request(`/session/${session}/screenshot`);
  await writeFile(`evidence/firefox/${name}.png`,Buffer.from(png,'base64'));
}
await mkdir('evidence/firefox',{recursive:true});
try{
  const created=await request('/session',{capabilities:{alwaysMatch:{browserName:'firefox','moz:firefoxOptions':{
    binary:process.env.FIREFOX_PATH||'/usr/lib64/firefox/firefox',
    prefs:{'media.autoplay.default':0,'media.volume_scale':'0.0','webgl.force-enabled':true},
  }}}});
  session=created.sessionId;report.capabilities=created.capabilities;
  await request(`/session/${session}/window/rect`,{width:1024,height:900});
  await request(`/session/${session}/url`,{url:origin+'/?skipIntro'});
  await until("return window.rcsk?.state.page==='main' && !!document.querySelector('[data-form=TFRMMAIN]')");
  await until("return document.fonts.status==='loaded'&&[...document.querySelectorAll('#screen img')].every(img=>img.complete&&img.naturalWidth>0)");
  assert.equal(await script("return [...document.querySelectorAll('#screen img')].every(img=>img.complete&&img.naturalWidth>0)"),true);
  await screenshot('main');report.checks.push('Original native main menu and images');
  for(const track of [0,3,5]){
    await request(`/session/${session}/url`,{url:origin+'/?track='+track});
    await until("return window.rcsk?.state.page==='viewer'&&window.rcsk.viewer.renderStats.world!==null");
    const data=await script(`
      const v=window.rcsk.viewer,maps=new Set();
      v.group.traverse(o=>{for(const m of [o.material].flat()){if(m?.map)maps.add(m.map)}});
      const keyed=[...maps].filter(t=>t.userData.nativeColorKeyFilter);
      const keyPixelsAreZero=texture=>{
        const pixels=texture.image.data;let count=0;
        if(!pixels)return false;
        for(let i=0;i<pixels.length;i+=4)if(pixels[i+3]===0){
          count++;if(pixels[i]!==0||pixels[i+1]!==0||pixels[i+2]!==0)return false;
        }
        return count>0;
      };
      return {state:window.rcsk.state,triangles:v.renderStats.world.triangles,
        presentationTriangles:v.renderStats.presentation.triangles,sky:!!v.sky,animations:v.animations.length,
        keyedTextures:keyed.length,keyedBeforeFiltering:keyed.every(t=>t.isDataTexture
          &&t.userData.nativeTextureFormat==='RGB565'&&!t.premultiplyAlpha&&keyPixelsAreZero(t)),
        webgl:v.renderer.getContext().getParameter(v.renderer.getContext().VERSION)};
    `);
    assert.deepEqual(data.state.assetErrors,[]);assert.ok(data.triangles>1000);assert.ok(data.sky&&data.animations>0);
    assert.equal(data.presentationTriangles,1);
    assert.ok(data.keyedTextures>0);assert.equal(data.keyedBeforeFiltering,true);
    await screenshot('track-'+track);report.checks.push({track,triangles:data.triangles,
      keyedTextures:data.keyedTextures,keyedBeforeFiltering:data.keyedBeforeFiltering,webgl:data.webgl});
  }
  await request(`/session/${session}/url`,{url:origin+'/?drive=0'});
  await until("return window.rcsk?.state.page==='driving'");
  const before=await script("return window.rcsk.viewer.motion.snapshot()");
  // Real WebDriver keyboard events, explicitly in a virtual display.
  await request(`/session/${session}/actions`,{actions:[{type:'key',id:'keyboard',actions:[{type:'keyDown',value:'\uE013'},{type:'pause',duration:1500},{type:'keyUp',value:'\uE013'}]}]});
  const after=await script("return window.rcsk.viewer.motion.snapshot()");
  assert.ok(after.updates>before.updates);assert.ok(after.forwardSpeed>before.forwardSpeed+1);
  assert.ok(Math.hypot(...after.position.map((v,i)=>v-before.position[i]))>1);
  const render=await script('return window.rcsk.viewer.renderStats');
  assert.ok(render.world.triangles>1000);assert.equal(render.presentation.triangles,1);assert.ok(render.hud.glyphs>0);
  await screenshot('driving');report.checks.push('Original kart/driver/camera and keyboard acceleration in driving research view');
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  if(session)await request(`/session/${session}`,undefined,'DELETE').catch(()=>{});
  await writeFile('evidence/firefox/report.json',JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,version:report.capabilities?.browserVersion,checks:report.checks},null,2));
}
