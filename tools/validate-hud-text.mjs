import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true});
await mkdir('evidence/hud',{recursive:true});
try{
  const page=await browser.newPage({viewport:{width:640,height:480},deviceScaleFactor:1});
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/assets/config.json');
  await page.setContent('<style>html,body{margin:0;background:#222}canvas{width:100vw;height:100vh;display:block}</style><canvas></canvas>');
  const result=await page.evaluate(async()=>{
    const [{RaceHud},config,manifest]=await Promise.all([import('/src/race-hud.js'),
      fetch('/assets/config.json').then(r=>r.json()),fetch('/assets/manifest.json').then(r=>r.json())]);
    const hud=window.hud=new RaceHud(document.querySelector('canvas'),config,manifest);await hud.load();
    const race=window.race={events:[],elapsedMs:12345,lapCount:0,lapLimit:5,lapTimerLimitMs:120000,
      lapStartMs:0,bestLapMs:0xfffffff,raceType:0};
    hud.update(race,0);hud.render();
    const pixels=hud.context.getImageData(0,0,640,480).data;
    const bounds={left:640,right:0,top:480,bottom:0,count:0};
    for(let y=300;y<430;y++)for(let x=0;x<200;x++)if(pixels[(y*640+x)*4+3]){
      bounds.left=Math.min(bounds.left,x);bounds.right=Math.max(bounds.right,x);
      bounds.top=Math.min(bounds.top,y);bounds.bottom=Math.max(bounds.bottom,y);bounds.count++;
    }
    hud.notify(1);hud.update(race,0);hud.render();
    const pause={text:hud.notifications.text,visible:hud.notifications.visible,
      alpha:hud.notifications.rgbaPacked>>>24};
    return {bonus:bounds,pause};
  });
  assert.ok(result.bonus.count>100);
  assert.ok(result.bonus.left>0&&result.bonus.right<140&&result.bonus.top>345&&result.bonus.bottom<375);
  assert.deepEqual(result.pause,{text:'PAUZE',visible:true,alpha:255});
  await page.screenshot({path:'evidence/hud/hud-text-640.png'});
  await page.evaluate(()=>{window.hud.notify(2);window.hud.notify(5);window.hud.update(window.race,2.6);window.hud.render();});
  await page.screenshot({path:'evidence/hud/hud-notification-640.png'});
  await page.setViewportSize({width:390,height:844});
  await page.evaluate(()=>window.hud.render());
  await page.screenshot({path:'evidence/hud/hud-notification-portrait.png'});
  await writeFile('evidence/hud/text-browser.json',JSON.stringify({browser:browser.version(),...result},null,2)+'\n');
  console.log('Original HUD atlas rendered: BONUS native anchor, PAUZE, animated final-lap notice, portrait anchoring.');
}finally{await browser.close();}
