import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {readFile,writeFile,mkdir} from 'node:fs/promises';

const native=JSON.parse(await readFile('evidence/full-source-audit/menu-entry-native.json'));
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required']});
const context=await browser.newContext({viewport:{width:1024,height:768}});
await context.addInitScript(()=>{
  const play=HTMLMediaElement.prototype.play;
  HTMLMediaElement.prototype.play=function(){this.playbackRate=16;return play.call(this);};
});
const page=await context.newPage();
const report={browser:browser.version(),nativeSourceSha256:native.sourceSha256,
  scope:'Actual source menu entry and held/released keyboard actions compared with original instruction fixtures. Audio transport is accelerated; no race or desktop build.',checks:[],errors:[]};
page.on('pageerror',error=>report.errors.push(error.message));
page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
const form=name=>page.waitForSelector(`[data-form=${name}]`);
const button=name=>page.locator(`[data-native=${name}]`);
const field=()=>page.locator('[data-element=edtName]');
const current=()=>page.evaluate(()=>document.activeElement?.dataset.native||null);
const saved=()=>page.evaluate(()=>JSON.parse(localStorage.getItem('rcsk.race-save.v1')));
async function focus(name,{phase=2,okEnabled=true}={}){
  await form(name);
  const expected=native.focus.find(row=>row.form===name&&row.phase===phase&&row.okEnabled===okEnabled);
  assert.ok(expected,name+' has original instruction evidence');
  const target=expected.events.find(event=>event.focus)?.focus;
  if(target)await page.waitForFunction(target=>document.activeElement?.dataset.native===target,target);
  else assert.notEqual(await current(),'btnOk');
}
async function check(name,fn){await fn();report.checks.push(name);}
try{
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');
  await focus('TFRMMAIN');
  await check('Empty Adventure keeps OK disabled and does not focus it, matching4762ec',async()=>{
    await page.keyboard.press('Enter');await focus('TFRMADVENTUREMAIN',{phase:3,okEnabled:false});
    assert.equal(await button('btnOk').isDisabled(),true);
  });
  await check('Held Enter does not create a player; release accepts the name and focuses character OK',async()=>{
    await button('btnNewPlayer').click();await form('TFRMEDITBOX');
    await field().fill('Broncontrole');await page.keyboard.down('Enter');
    assert.equal(await field().isVisible(),true);
    assert.equal((await saved())?.profiles?.filter(Boolean).length||0,0);
    await page.keyboard.up('Enter');await focus('TFRMSELECTCHAR',{phase:3});
    assert.equal((await saved()).profiles.filter(Boolean).length,1);
    assert.equal((await saved()).profiles[0].name,'Broncontrole');
  });
  await check('Same-form difficulty redraw retains the player-selected radio focus',async()=>{
    await button('rdoHard').click();
    await page.waitForFunction(()=>document.querySelector('[data-native=rdoHard]').getAttribute('aria-pressed')==='true');
    assert.equal(await current(),'rdoHard');
  });
  await check('Adventure briefing entry focuses Start/OK, matching479074',async()=>{
    await button('btnOk').click();await focus('TFRMADVENTBRIEF',{phase:3});
  });
  await check('Returning to an occupied Adventure bank focuses Continue',async()=>{
    await button('btnBack').click();await focus('TFRMMAIN');
    await page.keyboard.press('Enter');await focus('TFRMADVENTUREMAIN',{phase:3});
  });
  await check('Empty Enter is accepted on release without creating a profile, matching470600 and its caller',async()=>{
    await button('btnNewPlayer').click();await form('TFRMEDITBOX');
    assert.equal(await button('btnOk').isDisabled(),true);
    const row=native.nameEntry.find(row=>row.length===0&&row.keyCode===13);
    assert.equal(row.events.find(event=>event.close)?.close,4);
    await page.keyboard.down('Enter');assert.equal(await field().isVisible(),true);
    await page.keyboard.up('Enter');await form('TFRMADVENTUREMAIN');
    assert.equal((await saved()).profiles.filter(Boolean).length,1);
  });
  await check('Numpad Enter shares native VK_RETURN release semantics without duplicate profile creation',async()=>{
    await button('btnNewPlayer').click();await form('TFRMEDITBOX');await field().fill('Tweede speler');
    await page.keyboard.down('NumpadEnter');await page.keyboard.down('NumpadEnter');
    assert.equal(await field().isVisible(),true);
    await page.keyboard.up('NumpadEnter');await focus('TFRMSELECTCHAR',{phase:3});
    assert.equal((await saved()).profiles.filter(Boolean).length,2);
    await button('btnBack').click();await form('TFRMADVENTUREMAIN');
    await button('btnBack').click();await focus('TFRMMAIN');
  });
  await check('QuickRace supports consecutive Enter from character to country to original start information',async()=>{
    await button('btnQuickRace').click();await focus('TFRMSELECTCHAR');
    await page.keyboard.press('Enter');await focus('TFRMSELECTCOUNTRY');
    await page.keyboard.press('Enter');await focus('TFRMCONTROLSETTINGS');
    assert.equal(await page.evaluate(()=>window.rcsk.state.page),'start-info');
  });
  assert.deepEqual(report.errors,[]);
}finally{
  await mkdir('evidence/full-source-audit',{recursive:true});
  await writeFile('evidence/full-source-audit/menu-entry-browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();
}
console.log(JSON.stringify({checks:report.checks.length,errors:report.errors.length}));
