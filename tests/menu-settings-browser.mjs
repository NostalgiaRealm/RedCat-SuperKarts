import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,writeFile} from 'node:fs/promises';

const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required']});
const report={browser:browser.version(),scope:'Real browser controls and storage, compared with the original menu handler fixtures. No native runtime interaction claimed.',checks:[],errors:[]};
const context=await browser.newContext({viewport:{width:1024,height:768}});
await context.addInitScript(()=>{
  const play=HTMLMediaElement.prototype.play;
  HTMLMediaElement.prototype.play=function(){this.playbackRate=8;return play.call(this);};
});
const page=await context.newPage();
page.on('pageerror',error=>report.errors.push(error.message));
page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
const form=name=>page.waitForSelector(`[data-form=${name}]`);
const button=name=>page.locator(`[data-native=${name}]`);
const element=name=>page.locator(`[data-element=${name}]`);
const settings=()=>page.evaluate(()=>window.rcsk.state.settings);
const check=async(name,callback)=>{await callback();report.checks.push(name);};
const slider=async(name,value)=>element(name).evaluate((el,value)=>{el.value=value;el.dispatchEvent(new Event('input'));},String(value));
const openOptions=async()=>{await button('btnMainOptions').click();await form('TFRMOPTIONS');};
const openControls=async()=>{await button('btnControlsAdvanced').click();await form('TFRMCONTROLSETTINGS');};
const capture=async key=>{await element('lblKEY_ACCELERATE').click();await page.keyboard.press(key);};
try{
  await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');await form('TFRMMAIN');
  await check('Main menu focuses native Adventure and first Enter opens it',async()=>{
    assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),'btnAdventure');
    await page.keyboard.press('Enter');await form('TFRMADVENTUREMAIN');
    await button('btnBack').click();await form('TFRMMAIN');
  });
  await check('Main Tab and reverse Tab use original Options-before-Help order',async()=>{
    for(const name of ['btnQuickRace','btnHighscore','btnMainOptions','btnMainHelp','btnMainStop']){
      await page.keyboard.press('Tab');assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),name);
    }
    await page.keyboard.press('Shift+Tab');assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),'btnMainHelp');
    await page.keyboard.press('ArrowLeft');assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),'btnMainOptions');
  });
  const original=await settings();
  await openOptions();
  await check('Options keyboard navigation follows original nested group order',async()=>{
    await element('sldEffectVolume').focus();await page.keyboard.press('Tab');
    assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),'rdoLowQual');
    await page.keyboard.press('ArrowDown');
    assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),'rdoHighQual');
    await page.keyboard.press('Enter');
    await page.waitForFunction(()=>document.querySelector('[data-native=rdoHighQual]')?.getAttribute('aria-pressed')==='true');
    assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),'rdoHighQual');
  });
  await slider('sldEffectVolume',25);await slider('sldMusicVolume',40);
  await button('rdoHighQual').click();await button('rdoGamepad').click();await button('chkStartInfo').click();
  await check('Options draft does not alter committed settings',async()=>assert.deepEqual(await settings(),original));
  await check('Gamepad disables original keyboard configuration button',async()=>assert.equal(await button('btnControlsAdvanced').isDisabled(),true));
  await button('btnMainStop').click();await form('TFRMREQUESTER');await button('btnCancel').click();await form('TFRMOPTIONS');
  await check('Options Stop then No returns to the same uncommitted draft',async()=>{
    assert.equal(await element('sldEffectVolume').inputValue(),'25');
    assert.equal(await button('rdoGamepad').getAttribute('aria-pressed'),'true');
    assert.deepEqual(await settings(),original);
  });
  await button('btnBack').click();await form('TFRMMAIN');
  await check('Options Back discards all changed native controls',async()=>assert.deepEqual(await settings(),original));
  await openOptions();
  await slider('sldEffectVolume',25);await slider('sldMusicVolume',40);
  await button('rdoHighQual').click();await button('rdoJoystick').click();await button('chkStartInfo').click();
  await check('Joystick disables keyboard configuration',async()=>assert.equal(await button('btnControlsAdvanced').isDisabled(),true));
  await button('rdoKeyboard').click();
  await check('Keyboard reenables keyboard configuration',async()=>assert.equal(await button('btnControlsAdvanced').isDisabled(),false));
  await button('btnOk').click();await form('TFRMMAIN');
  await page.reload();await form('TFRMMAIN');
  await check('Options OK commits volume, quality and start-information preference across reload',async()=>{
    const saved=await settings();assert.equal(saved.effects,.25);assert.equal(saved.music,.4);
    assert.equal(saved.resolution,'800x600');assert.equal(saved.startInfo,false);assert.equal(saved.controlType,0);
  });
  await openOptions();await openControls();
  await check('Control dialog Tab order follows Default, Cancel, Help, OK',async()=>{
    await button('btnDefault').focus();
    for(const name of ['btnCancel','btnHelp','btnOk']){
      await page.keyboard.press('Tab');assert.equal(await page.evaluate(()=>document.activeElement.dataset.native),name);
    }
  });
  await check('Original arrow art and labels replace generic Unicode keycaps',async()=>{
    assert.match(await element('imgKEY_ACCELERATE').getAttribute('src'),/pijl0003\.png$/);
    assert.equal(await element('lblKEY_ACCELERATE').textContent(),'');
    assert.equal(await element('lblKEY_USEBONUS').textContent(),'Ctrl');
    assert.equal(await button('btnCancel').getAttribute('aria-label'),'Terug');
  });
  await capture('q');
  await check('Assigned key remains a draft until OK',async()=>{
    assert.equal((await settings()).bindings.accelerate,'ArrowUp');
    assert.equal(await element('lblKEY_ACCELERATE').textContent(),'q');
    assert.match(await element('imgKEY_ACCELERATE').getAttribute('src'),/toetskld\.png$/);
  });
  await button('btnCancel').click();await form('TFRMOPTIONS');await openControls();
  await check('Controls Cancel reloads the saved original binding',async()=>{
    assert.equal((await settings()).bindings.accelerate,'ArrowUp');
    assert.match(await element('imgKEY_ACCELERATE').getAttribute('src'),/pijl0003\.png$/);
  });
  await capture('ArrowDown');await form('TFRMREQUESTER');await button('btnOk').click();await form('TFRMCONTROLSETTINGS');
  await check('Duplicate warning retains capture, cleared value and disabled OK',async()=>{
    assert.equal(await button('btnOk').isDisabled(),true);
    assert.equal(await element('lblKEY_ACCELERATE').textContent(),'');
    assert.match(await element('imgKEY_ACCELERATE').getAttribute('src'),/toetskl0\.png$/);
  });
  await page.keyboard.press('Digit1');
  await check('Invalid key leaves capture active',async()=>assert.equal(await button('btnOk').isDisabled(),true));
  await page.keyboard.press('r');
  await check('Valid key after warning completes the same capture',async()=>{
    assert.equal(await button('btnOk').isDisabled(),false);
    assert.equal(await element('lblKEY_ACCELERATE').textContent(),'r');
  });
  await button('btnOk').click();await form('TFRMOPTIONS');await button('btnBack').click();await form('TFRMMAIN');
  await page.reload();await form('TFRMMAIN');
  await check('Controls OK saves independently of outer Options Back',async()=>assert.equal((await settings()).bindings.accelerate,'KeyR'));
  await openOptions();await openControls();await button('btnDefault').click();
  await check('Defaults change only the control draft',async()=>{
    assert.equal((await settings()).bindings.accelerate,'KeyR');
    assert.match(await element('imgKEY_ACCELERATE').getAttribute('src'),/pijl0003\.png$/);
  });
  await button('btnCancel').click();await form('TFRMOPTIONS');await openControls();
  await check('Cancel also discards Defaults',async()=>assert.equal(await element('lblKEY_ACCELERATE').textContent(),'r'));
  await capture('Escape');
  await check('Escape ends capture and leaves native zero binding',async()=>{
    assert.equal(await button('btnOk').isDisabled(),false);
    assert.equal(await element('lblKEY_ACCELERATE').textContent(),'');
    assert.match(await element('imgKEY_ACCELERATE').getAttribute('src'),/toetskld\.png$/);
  });
  await button('btnOk').click();await form('TFRMOPTIONS');await button('btnBack').click();await form('TFRMMAIN');
  await page.reload();await form('TFRMMAIN');
  await check('Explicit native unbound key survives persistence',async()=>assert.equal((await settings()).bindings.accelerate,''));
  await openOptions();await openControls();await button('btnDefault').click();await button('btnOk').click();await form('TFRMOPTIONS');
  await button('btnAdvanced').click();await form('TFRMDISPLAYSETTINGS');
  await check('Advanced opens original General tab with original captions',async()=>{
    assert.equal(await button('tabAlgemeen').getAttribute('aria-selected'),'true');
    assert.equal(await page.locator('.native-display-caption').textContent(),'Geavanceerde beeldscherm instellingen');
    assert.equal(await button('rdoBrightnessLight').isChecked(),true);
    assert.equal(await element('GroupBox2').count(),0);
  });
  await button('rdoBrightnessDark').check();await button('Problemen').click();
  for(const name of ['chkBilinearFiltering','chkAlphaBlending','chkParticles'])await button(name).check();
  await check('Applicable original display controls remain enabled; browser-managed controls explain limits',async()=>{
    for(const name of ['chkBilinearFiltering','chkAlphaBlending','chkParticles'])assert.equal(await button(name).isDisabled(),false);
    assert.equal(await button('chkRenderToSystemMemory').isDisabled(),true);
    assert.equal(await button('chkWaitVbl').isDisabled(),true);
    assert.match(await page.locator('.native-display-notes').textContent(),/browser/);
  });
  await button('btnCancel').click();await form('TFRMOPTIONS');
  await check('Advanced Cancel preserves all committed display settings',async()=>assert.deepEqual((await settings()).display,original.display));
  await button('btnAdvanced').click();await form('TFRMDISPLAYSETTINGS');
  await button('rdoBrightnessDark').check();await button('Problemen').click();
  for(const name of ['chkBilinearFiltering','chkAlphaBlending','chkParticles'])await button(name).check();
  await button('btnOk').click();await form('TFRMOPTIONS');await button('btnBack').click();await form('TFRMMAIN');
  await page.reload();await form('TFRMMAIN');
  await check('Advanced OK persists independently of outer Options Back',async()=>{
    assert.deepEqual((await settings()).display,{brightnessLight:false,bilinearFiltering:false,alphaBlending:false,particles:false});
  });
  await openOptions();await button('btnAdvanced').click();await form('TFRMDISPLAYSETTINGS');
  await button('rdoBrightnessLight').check();await button('Problemen').click();
  for(const name of ['chkBilinearFiltering','chkAlphaBlending','chkParticles'])await button(name).uncheck();
  await check('Original advanced dialog no longer contains the browser settings button',async()=>assert.equal(await button('btnBrowserSettings').count(),0));
  await button('btnOk').click();await form('TFRMOPTIONS');
  await button('btnMoreSettings').click();await page.waitForSelector('#scale');
  await check('More settings opens directly from Options with the requested title',async()=>assert.equal(await page.locator('h1').textContent(),'Meer instellingen'));
  await page.locator('#scale').fill('175');await page.locator('#scale').dispatchEvent('input');
  await page.locator('#resolution').selectOption('1280x720');
  await page.getByRole('button',{name:'OK',exact:true}).click();await form('TFRMOPTIONS');
  await check('More settings OK retains changes in the outer uncommitted Options draft',async()=>{
    assert.equal((await settings()).renderScale,100);assert.equal((await settings()).resolution,'800x600');
  });
  await button('btnOk').click();await form('TFRMMAIN');
  await check('Options OK also commits modern resolution and render-scale additions',async()=>{
    assert.equal((await settings()).renderScale,175);assert.equal((await settings()).resolution,'1280x720');
  });
  await openOptions();await button('btnAdvanced').click();await form('TFRMDISPLAYSETTINGS');
  await page.setViewportSize({width:390,height:844});await button('Problemen').click();
  await check('Original advanced display controls reflow without portrait overflow',async()=>{
    assert.equal(await page.evaluate(()=>document.documentElement.scrollWidth>innerWidth),false);
    for(const name of ['chkBilinearFiltering','chkAlphaBlending','chkParticles'])assert.equal(await button(name).isVisible(),true);
  });
  await page.screenshot({path:'evidence/ui/display-settings-portrait.png'});
  await page.setViewportSize({width:1024,height:768});
  await page.screenshot({path:'evidence/ui/display-settings-problems.png'});
  await button('btnCancel').click();await form('TFRMOPTIONS');await button('btnBack').click();await form('TFRMMAIN');
  await openOptions();await button('chkStartInfo').click();await button('btnOk').click();await form('TFRMMAIN');
  await button('btnQuickRace').click();await form('TFRMSELECTCHAR');await button('btnOk').click();await form('TFRMSELECTCOUNTRY');
  await button('btnOk').click();await form('TFRMCONTROLSETTINGS');
  await check('Start-information uses original OK and positive checked caption',async()=>{
    assert.equal(await page.evaluate(()=>window.rcsk.state.page),'start-info');
    assert.equal(await button('btnOk').getAttribute('aria-label'),'OK');
    assert.equal(await element('lblShowStartInfo').textContent(),'Startinfoscherm weergeven');
    assert.equal(await button('chkShowInfo').getAttribute('aria-pressed'),'true');
    assert.equal(await button('btnDefault').count(),0);assert.equal(await button('btnCancel').count(),0);
  });
  await page.screenshot({path:'evidence/ui/start-info-corrected.png'});
  for(const [control,name]of [[1,'rdoGamepad'],[2,'rdoJoystick']]){
    await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');await form('TFRMMAIN');
    await openOptions();await button(name).click();await button('btnOk').click();await form('TFRMMAIN');
    await button('btnQuickRace').click();await form('TFRMSELECTCHAR');await button('btnOk').click();await form('TFRMSELECTCOUNTRY');
    await button('btnOk').click();
    await page.waitForFunction(()=>['loading','driving'].includes(window.rcsk.state.page));
    await check(`Control type${control} starts loading without keyboard-only start information`,async()=>{
      assert.equal((await settings()).startInfo,true);
      assert.equal(await page.locator('[data-form=TFRMCONTROLSETTINGS]').count(),0);
    });
  }
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);throw error;}
finally{
  await mkdir('evidence/ui',{recursive:true});
  await writeFile('evidence/ui/menu-settings-browser.json',JSON.stringify(report,null,2)+'\n');
  await browser.close();console.log(JSON.stringify(report,null,2));
}
