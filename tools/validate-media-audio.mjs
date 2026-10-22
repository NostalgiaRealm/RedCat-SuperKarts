import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required']});
try{
  const page=await browser.newPage();
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/assets/manifest.json');
  const media=await page.evaluate(async()=>{
    const manifest=await fetch('/assets/manifest.json').then(r=>r.json()),result=[];
    for(const [kind,entries] of [['movie',Object.values(manifest.movies).map(x=>x.file)],
      ['music',Object.values(manifest.trackMusic)]]){
      for(const file of entries){
        const element=document.createElement(kind==='movie'?'video':'audio');
        element.src='/assets/'+file;element.volume=1;element.muted=false;document.body.append(element);
        try{
          await element.play();
          const started=performance.now();
          while((element.currentTime<.15||!element.webkitAudioDecodedByteCount)&&performance.now()-started<10000)
            await new Promise(resolve=>setTimeout(resolve,50));
          result.push({kind,file,duration:element.duration,time:element.currentTime,
            readyState:element.readyState,audioDecodedBytes:element.webkitAudioDecodedByteCount,
            paused:element.paused,muted:element.muted,volume:element.volume,
            width:element.videoWidth??null,height:element.videoHeight??null});
        }catch(error){result.push({kind,file,error:String(error)});}
        element.pause();element.removeAttribute('src');element.load();element.remove();
      }
    }
    return result;
  });
  const report={browser:browser.version(),scope:'Playback startup and positive decoded audio bytes for all11 converted movies and six original race music streams. Does not play every movie to completion or test reward eligibility.',media};
  report.status=media.every(x=>!x.error&&x.time>=.15&&x.audioDecodedBytes>0&&!x.paused&&!x.muted)?'passed':'failed';
  await mkdir('evidence/audio',{recursive:true});
  await writeFile('evidence/audio/media-playback.json',JSON.stringify(report,null,2)+'\n');
  assert.equal(report.status,'passed');assert.equal(media.length,17);
  console.log('All11 original movie conversions and six music streams start playback with decoded audio.');
}finally{await browser.close();}
