import {chromium} from 'playwright';
import assert from 'node:assert/strict';

// Smoke test for a built site served below a URL folder, such as the website
// deployment at /redcatsuperkarts/. Every request must stay inside that folder.
//   RCSK_URL=https://games.nostalgiarealm.com/redcatsuperkarts node tests/subpath-browser.mjs
const base=(process.env.RCSK_URL||'http://127.0.0.1:4180/redcatsuperkarts').replace(/\/?$/,'/');
const {origin,pathname:prefix}=new URL(base);
const report={base,checks:[],outside:[],failed:[],errors:[]};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',headless:true,
  args:['--autoplay-policy=no-user-gesture-required']});
try{
  const page=await browser.newPage({viewport:{width:1024,height:768}});
  page.on('request',request=>{const url=new URL(request.url());
    if(url.origin===origin&&!url.pathname.startsWith(prefix)&&url.pathname!=='/favicon.ico')report.outside.push(url.pathname);});
  page.on('response',response=>{if(response.status()>=400)report.failed.push(response.status()+' '+response.url());});
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('console',message=>{if(message.type()==='error')report.errors.push(message.text());});
  const check=async(name,fn)=>{await fn();report.checks.push(name);};

  await page.goto(base);
  await check('Intro movie loads from the folder',async()=>{
    const src=await page.waitForFunction(()=>{const video=document.querySelector('video');
      return video?.readyState>=2&&video.currentSrc;},null,{timeout:30000}).then(handle=>handle.jsonValue());
    assert.ok(src.startsWith(base+'assets/media/'),src);
  });
  await page.goto(base+'?skipIntro');await page.waitForSelector('[data-form=TFRMMAIN]');
  await check('Main menu artwork, buttons and style sheet load from the folder',async()=>{
    const art=await page.evaluate(async()=>{
      await Promise.all([...document.images].map(image=>image.decode().catch(()=>{})));
      const button=getComputedStyle(document.querySelector('[data-native=btnMainOptions]')).backgroundImage;
      const url=button.match(/url\("?([^")]+)/)[1];
      return {images:[...document.images].map(image=>[image.src,image.naturalWidth]),button:url,
        buttonOk:(await fetch(url)).ok,styles:[...document.styleSheets].map(sheet=>sheet.href)};
    });
    assert.ok(art.images.length>0);
    for(const [src,width]of art.images){assert.ok(src.startsWith(base),src);assert.ok(width>0,src);}
    assert.ok(art.button.startsWith(base+'assets/menu/')&&art.buttonOk,art.button);
    assert.ok(art.styles.includes(base+'src/style.css'),String(art.styles));
  });
  await check('Original help opens with its pictures',async()=>{
    await page.locator('[data-native=btnMainHelp]').click();await page.waitForSelector('.help-window');
    const topic=await page.evaluate(()=>[...document.querySelectorAll('.help-window nav [data-help-topic]')]
      .map(link=>link.dataset.helpTopic));
    // Find a topic with a picture; the first topics may be text only.
    let pictures=[];
    for(const id of topic){
      await page.locator(`.help-window nav [data-help-topic="${id}"]`).click();
      pictures=await page.evaluate(async()=>Promise.all([...document.querySelectorAll('.help-window article img')]
        .map(async image=>{await image.decode().catch(()=>{});return [image.src,image.naturalWidth];})));
      if(pictures.length)break;
    }
    assert.ok(pictures.length>0,'a help topic with pictures');
    for(const [src,width]of pictures){assert.ok(src.startsWith(base+'assets/help/images/'),src);assert.ok(width>0,src);}
    await page.locator('.help-window header button').click();
  });
  await page.goto(base+'?drive=0');
  await check('A race loads its track, karts and sounds from the folder',async()=>{
    await page.waitForFunction(()=>window.rcsk?.state.page==='driving',null,{timeout:90000});
    await page.waitForFunction(()=>window.rcsk.viewer.clock.tick>2,null,{timeout:30000});
    assert.deepEqual(await page.evaluate(()=>window.rcsk.viewer.errors),[]);
  });
  assert.deepEqual(report.outside,[],'requests outside the folder');
  assert.deepEqual(report.failed,[],'failed requests');
  assert.deepEqual(report.errors,[],'page errors');
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);process.exitCode=1;}
finally{await browser.close();console.log(JSON.stringify(report,null,2));}
