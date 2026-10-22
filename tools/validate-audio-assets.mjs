import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true});
try{
  const page=await browser.newPage();
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/assets/manifest.json');
  const files=await page.evaluate(async()=>{
    const manifest=await fetch('/assets/manifest.json').then(r=>r.json());
    const entries=Object.entries(manifest.audio),output=[];
    // Sequential decode releases buffers promptly and avoids loading the entire
    // original voice library into memory at once.
    const context=new OfflineAudioContext(2,1,22050);
    for(const [name,asset] of entries){
      try{
        const response=await fetch('/assets/'+asset.file);
        if(!response.ok)throw Error('HTTP '+response.status);
        const buffer=await context.decodeAudioData(await response.arrayBuffer());
        let peak=0,finite=true;
        for(let channel=0;channel<buffer.numberOfChannels;channel++){
          const samples=buffer.getChannelData(channel);
          for(const sample of samples){
            if(!Number.isFinite(sample)){finite=false;break;}
            peak=Math.max(peak,Math.abs(sample));
          }
        }
        output.push({name,file:asset.file,sha256:asset.sha256,channels:buffer.numberOfChannels,
          frames:buffer.length,sampleRate:buffer.sampleRate,duration:buffer.duration,peak,finite});
      }catch(error){output.push({name,file:asset.file,error:String(error)});}
    }
    return output;
  });
  const report={browser:browser.version(),scope:'Browser decoder compatibility and finite PCM samples for every extracted audio lookup. This does not establish gameplay trigger coverage or audibility through speakers.',
    total:files.length,wav:files.filter(x=>x.name.endsWith('.wav')).length,
    streams:files.filter(x=>!x.name.endsWith('.wav')).length,
    silent:files.filter(x=>x.peak===0).map(x=>x.name),files};
  report.status=files.every(x=>!x.error&&x.frames>0&&x.finite)?'passed':'failed';
  await mkdir('evidence/audio',{recursive:true});
  await writeFile('evidence/audio/all-assets-decode.json',JSON.stringify(report,null,2)+'\n');
  assert.equal(report.status,'passed');
  assert.equal(report.total,1226);
  console.log(JSON.stringify({status:report.status,total:report.total,wav:report.wav,streams:report.streams,silent:report.silent}));
}finally{await browser.close();}
