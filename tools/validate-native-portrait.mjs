// Module-level browser diagnostic: start tools/serve.mjs with --inspect-source.
import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir, writeFile} from 'node:fs/promises';

const browser = await chromium.launch({executablePath:process.env.CHROME_PATH || '/usr/bin/google-chrome', headless:true});
const checks = [];
await mkdir('evidence/portrait', {recursive:true});
try {
  const page = await browser.newPage({viewport:{width:1024,height:768}});
  await page.goto((process.env.RCSK_URL || 'http://127.0.0.1:4173') + '/assets/ui/forms.json');
  await page.setContent('<!doctype html><meta name="viewport" content="width=device-width,initial-scale=1"><link rel="stylesheet" href="/src/style.css"><div id="screen"></div>');
  await page.evaluate(async () => {
    const [{NativeMenu}, {adaptNativePortrait}, forms, manifest, config] = await Promise.all([
      import('/source/native-menu.js'), import('/source/native-portrait.js'),
      fetch('/assets/ui/forms.json').then(r=>r.json()), fetch('/assets/manifest.json').then(r=>r.json()),
      fetch('/assets/config.json').then(r=>r.json()),
    ]);
    window.portraitFixture = (name) => {
      const menu = new NativeMenu(forms,manifest.menu);
      menu.language=config['ini/shellang.ini'].dutch;
      const images = {imgControlPic:'mn_0601a.bmp',imgResPic:'mn_0617x.bmp'};
      const text = {lblForward:'Gas geven',lblBackwards:'Remmen',lblLeft:'Links',lblRight:'Rechts',
        lblBonus:'Gebruik bonus',lblHandbrake:'Handrem',lblKEY_ACCELERATE:'↑',lblKEY_BRAKE:'↓',
        lblKEY_STEERLEFT:'←',lblKEY_STEERRIGHT:'→',lblKEY_USEBONUS:'Ctrl',lblKEY_HANDBRAKE:'Alt',
        lblQuit:'Wil je echt stoppen?',lblNameText:'Vul je naam in:',lblPlayerName:'RedCat'};
      if(name==='TFRMSELECTCHAR')Object.assign(images,{imgPrevious:'mn_0204x.bmp',imgCurrent:'mn_0201x.bmp',imgNext:'mn_0202x.bmp'});
      if(name==='TFRMSELECTCOUNTRY')Object.assign(images,{imgLeftSelected:'mn_0306a.bmp',imgSelectedCountry:'mn_0301a.bmp',imgRightSelected:'mn_0302a.bmp'});
      if(name==='TFRMLANDINFO')for(let i=0;i<4;i++){
        const[image,label]=config['ini/shellimg.dat'].nederland_overview[i].split(',');
        images[`imgPhoto${i+1}`]=image;text[`lblPhoto${i+1}`]=label.trim();
      }
      if(name==='TFRMDEBRIEF'){
        const pictures=config['ini/shellimg.dat'],languageImages=config['ini/shellang.ini'].dutch_images;
        images.imgReward=pictures.rewardpics[0];images.imgBackGround=languageImages[27];
        for(const[i,character]of ['redcat','whizzkitty','brutus','max','nederland'].entries()){
          images[`imgPosition${i+1}`]=pictures.debriefpics[character].split(',')[0];
          images[`imgFinPos${i+1}`]=languageImages[28+i];
        }
        text.lblTotal=config['ini/shellang.ini'].dutch[34]+' 03:12:34';
        text.lblBestLap=config['ini/shellang.ini'].dutch[35]+' 00:38:24';
      }
      Object.assign(text,{lblCharname:'RedCat',lblCountryName:'Nederland'});
      const actions = Object.fromEntries(['btnOk','btnQuickRace','btnNext','rdoHard','imgPhoto1',
        'imgKEY_ACCELERATE','sldMusicVolume','edtName'].map(id=>[id,value=>{
        window.portraitAction = {id,value};
      }]));
      const root=menu.render(name,{images,text,actions});
      const stage=root.firstElementChild;
      document.getElementById('screen').replaceChildren(root);
      document.getElementById('screen').scrollTop=0;
      const positions=()=>Object.fromEntries([...stage.querySelectorAll('[data-element]')].map(e=>{
        const r=e.getBoundingClientRect();return [e.dataset.element,[r.x,r.y,r.width,r.height]];
      }));
      const before=positions();
      const identity=[...stage.querySelectorAll('[data-element]')];
      adaptNativePortrait(stage,name);
      const after=positions();
      return {before,after,retained:identity.every(e=>stage.contains(e))};
    };
  });
  const forms = ['TFRMOPTIONS','TFRMCONTROLSETTINGS','TFRMREQUESTER','TFRMEDITBOX',
    'TFRMADVENTUREMAIN','TFRMADVENTBRIEF','TFRMHIGHSCORE','TFRMENTERNAME',
    'TFRMMAIN','TFRMSELECTCHAR','TFRMSELECTCOUNTRY','TFRMLANDINFO','TFRMDEBRIEF'];
  for (const name of forms) {
    await page.setViewportSize({width:1024,height:768});
    const landscape=await page.evaluate(name=>window.portraitFixture(name),name);
    assert.deepEqual(landscape.after,landscape.before,`${name}: landscape changed`);
    assert.ok(landscape.retained,`${name}: original control replaced`);
    for (const width of [390,320]) {
      await page.setViewportSize({width,height:844});
      await page.evaluate(async()=>{await document.fonts.ready;await Promise.all([...document.querySelectorAll('#screen img')].map(i=>i.decode()));});
      const result=await page.evaluate(()=>{
        const stage=document.querySelector('.native-portrait'),rect=stage.getBoundingClientRect();
        const controls=[...stage.querySelectorAll('button,input,[role=button]')].map(e=>{
          const r=e.getBoundingClientRect();return {name:e.dataset.element,x:r.x,y:r.y,width:r.width,height:r.height};
        });
        return {clientWidth:document.getElementById('screen').clientWidth,scrollWidth:document.getElementById('screen').scrollWidth,
          stage:{x:rect.x,right:rect.right,height:rect.height},controls};
      });
      assert.equal(result.scrollWidth,result.clientWidth,`${name}/${width}: horizontal scrolling`);
      for (const c of result.controls) {
        assert.ok(c.x>=15 && c.x+c.width<=width-15,`${name}/${width}: ${c.name} outside viewport`);
        assert.ok(c.height>=40,`${name}/${width}: ${c.name} touch height ${c.height}`);
      }
      checks.push({form:name,width,...result});
      if(width===390)await page.screenshot({path:`evidence/portrait/${name.toLowerCase()}.png`,fullPage:true});
    }
    await page.setViewportSize({width:1024,height:768});
    const restored=await page.evaluate(()=>Object.fromEntries([...document.querySelectorAll('.native-stage [data-element]')].map(e=>{
      const r=e.getBoundingClientRect();return [e.dataset.element,[r.x,r.y,r.width,r.height]];
    })));
    assert.deepEqual(restored,landscape.before,`${name}: rotation failed to restore landscape`);
  }
  await page.setViewportSize({width:390,height:844});
  await page.evaluate(()=>window.portraitFixture('TFRMREQUESTER'));
  await page.locator('[data-native=btnOk]').click();
  assert.equal(await page.evaluate(()=>window.portraitAction.id),'btnOk');
  await page.evaluate(()=>window.portraitFixture('TFRMCONTROLSETTINGS'));
  await page.locator('[data-element=imgKEY_ACCELERATE]').click();
  assert.equal(await page.evaluate(()=>window.portraitAction.id),'imgKEY_ACCELERATE');
  await page.evaluate(()=>window.portraitFixture('TFRMEDITBOX'));
  await page.locator('[data-element=edtName]').fill('RedCat');
  assert.deepEqual(await page.evaluate(()=>window.portraitAction),{id:'edtName',value:'RedCat'});
  for(const[form,id]of [['TFRMMAIN','btnQuickRace'],['TFRMSELECTCHAR','btnNext'],
    ['TFRMSELECTCHAR','rdoHard'],['TFRMLANDINFO','imgPhoto1'],['TFRMDEBRIEF','btnOk']]){
    await page.evaluate(form=>window.portraitFixture(form),form);
    await page.locator(`[data-element=${id}]`).click();
    assert.equal(await page.evaluate(()=>window.portraitAction.id),id);
  }
  await writeFile('evidence/portrait/validation.json',JSON.stringify({browser:browser.version(),
    scope:'Synthetic viewport sizes; original live controls, landscape geometry and callbacks checked. Not physical device testing.',
    checks,callbacks:['btnOk','imgKEY_ACCELERATE','edtName','btnQuickRace','btnNext','rdoHard','imgPhoto1']},null,2)+'\n');
  console.log(`Validated ${checks.length} portrait layouts, original landscape positions, rotation, and original control callbacks.`);
} finally { await browser.close(); }
