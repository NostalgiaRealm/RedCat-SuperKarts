import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {mkdir,readFile,writeFile} from 'node:fs/promises';

const origin=process.env.RCSK_URL||'http://127.0.0.1:4173';
const data=JSON.parse(await readFile(new URL('../public/assets/help/topics.json',import.meta.url)));
const config=JSON.parse(await readFile(new URL('../public/assets/config.json',import.meta.url)));
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--use-angle=swiftshader','--enable-unsafe-swiftshader']});
const context=await browser.newContext({viewport:{width:1024,height:768}});
const page=await context.newPage();
const report={browser:browser.version(),scope:'Focused original Help navigation in an isolated browser profile. Actual menu clicks and DOM identity probes; one Adventure profile is created through the UI. No races, injected race results, builds, or native runtime execution.',
  limitations:['Debrief button routing is covered by native-help-context.test.mjs; this browser check opens contexts 11 and 12 through the original keyword index without running a race.'],checks:[],errors:[]};
const output='evidence/help-navigation';await mkdir(output,{recursive:true});
page.on('pageerror',error=>report.errors.push(error.message));
page.on('response',response=>{if(response.status()>=400&&!response.url().endsWith('favicon.ico'))report.errors.push(`${response.status()} ${response.url()}`);});
const control=name=>page.locator(`[data-native="${name}"]`);
const element=name=>page.locator(`[data-element="${name}"]`);
const form=name=>page.waitForSelector(`[data-form="${name}"]`);
const action=name=>page.locator(`[data-help-action="${name}"]`);
const article=page.locator('.original-help');
const topic=context=>data.contextMap[String(context)]??context;
const expectTopic=async value=>{
  await page.waitForFunction(id=>document.querySelector('.original-help')?.dataset.topic===id,topic(value));
  assert.equal(await page.locator('.help-window').count(),1);
};
const chooseTopic=async id=>{await page.locator(`.help-window nav [data-help-topic="${topic(id)}"]`).click();await expectTopic(id);};
const close=async()=>{await page.locator('.help-window header button').click();await page.waitForFunction(()=>window.rcsk.state.page!=='help');};
const check=async(name,callback)=>{await callback();report.checks.push(name);console.log(name);};
const openHelp=async(context,button='btnMainHelp')=>{await control(button).click();await expectTopic(context);};
const probeCaller=async(field,button='btnMainHelp')=>page.evaluate(({field,button})=>{
  window.helpCallerProbe={root:document.querySelector('#screen').firstElementChild,
    field:document.querySelector(`[data-element="${field}"]`)||document.querySelector(field),
    button:document.querySelector(`[data-native="${button}"]`)||document.querySelector(button)};
},{field,button});
const checkCaller=async value=>{
  const restored=await page.evaluate(()=>({sameRoot:document.querySelector('#screen').firstElementChild===window.helpCallerProbe.root,
    sameField:window.helpCallerProbe.field.isConnected,value:window.helpCallerProbe.field.value??window.helpCallerProbe.field.textContent,
    sameFocus:document.activeElement===window.helpCallerProbe.button}));
  assert.deepEqual(restored,{sameRoot:true,sameField:true,value,sameFocus:true});
};

try{
  await page.goto(origin+'/?skipIntro');await form('TFRMMAIN');
  await openHelp(1);
  await check('Initial main Help uses original contents and has no invented browse-chain controls',async()=>{
    assert.equal(await action('back').isDisabled(),true);
    assert.equal(await page.locator('.help-window nav a').count(),13);
    assert.equal(await page.locator('[data-help-action="next"],[data-help-action="previous"]').count(),0);
    assert.equal(await page.locator('.help-window header h1').textContent(),data.title);
    assert.match(await article.innerText(),/In het hoofdmenu kun je/);
  });
  await check('All 13 original topics, 59 image placements and nine links render and navigate in one Help window',async()=>{
    let imageCount=0,linkCount=0;const images=new Set();
    for(const item of data.topics){
      await chooseTopic(item.id);
      const decoded=await article.locator('img').evaluateAll(async elements=>{
        await Promise.all(elements.map(image=>image.decode()));
        return elements.map(image=>({src:new URL(image.src).pathname,width:image.naturalWidth,height:image.naturalHeight}));
      });
      assert.deepEqual(decoded.map(image=>image.src),item.images,item.id);
      assert.ok(decoded.every(image=>image.width>0&&image.height>0));
      imageCount+=decoded.length;for(const image of decoded)images.add(image.src);
      assert.equal(await article.locator('[data-help-topic]').count(),item.links.length,item.id);
      for(const [index,link]of item.links.entries()){
        const source=article.locator('[data-help-topic]').nth(index);
        await source.scrollIntoViewIfNeeded();await source.focus();
        const scroll=await page.locator('#screen').evaluate(node=>node.scrollTop);
        await source.click();await expectTopic(link.target);
        assert.equal(context.pages().length,1);
        await action('back').click();await expectTopic(item.id);
        assert.equal(await source.evaluate(node=>document.activeElement===node),true);
        assert.equal(await page.locator('#screen').evaluate(node=>node.scrollTop),scroll);
        linkCount++;
      }
    }
    assert.equal(imageCount,59);assert.equal(images.size,46);assert.equal(linkCount,9);
    Object.assign(report,{topics:data.topics.length,imagePlacements:imageCount,distinctImages:images.size,links:linkCount});
  });
  await check('Contents, Back and History retain visited topic navigation',async()=>{
    await chooseTopic(2);await article.locator('[data-help-topic="Besturing"]').click();await expectTopic(3);
    await action('contents').click();await expectTopic(1);
    await action('back').click();await expectTopic(3);
    await action('history').click();
    const history=page.locator('[data-help-panel="history"]');
    const ids=await history.locator('a').evaluateAll(nodes=>nodes.map(node=>node.dataset.helpTopic));
    assert.deepEqual(ids.slice(0,3),[topic(1),topic(3),topic(2)]);
    await history.locator('[data-help-topic="Instellingen"]').first().click();await expectTopic(2);
    assert.equal(await history.count(),0);
  });
  await check('Index uses all 13 original binary keywords and their actual context mappings',async()=>{
    await action('index').click();
    const panel=page.locator('[data-help-panel="index"]'),search=panel.getByRole('searchbox',{name:'Trefwoord'});
    const rows=await panel.locator('li').evaluateAll(nodes=>nodes.map(node=>({keyword:node.querySelector('span').textContent.slice(0,-2),
      topics:[...node.querySelectorAll('a')].map(link=>link.dataset.helpTopic)})));
    assert.deepEqual(rows,data.keywordIndex.map(item=>({keyword:item.keyword,topics:item.contextIds.map(topic)})));
    await search.fill('aVoNtUuR');
    assert.equal(await panel.locator('li').count(),4);
    await search.fill('Einde race (Quickrace)');
    assert.equal(await panel.locator('li').count(),1);
    await panel.locator('a').click();await expectTopic(12);
    await action('index').click();await panel.getByRole('searchbox').fill('Einde race (Avontuur)');
    await panel.locator('a').click();await expectTopic(11);
    await action('index').click();await panel.getByRole('searchbox').fill('geen bestaande term');
    assert.equal(await panel.locator('li').count(),0);
    await page.keyboard.press('Escape');await page.waitForSelector('[data-help-panel="index"]',{state:'detached'});
    await expectTopic(11);assert.equal(await action('index').evaluate(node=>document.activeElement===node),true);
    await page.keyboard.press('Escape');await form('TFRMMAIN');
  });
  await check('Closing Help with its button or Escape preserves the exact Options DOM, focus and uncommitted slider draft',async()=>{
    await control('btnMainOptions').click();await form('TFRMOPTIONS');
    const saved=await page.evaluate(()=>window.rcsk.state.settings);
    await element('sldMusicVolume').fill('40');await element('sldMusicVolume').dispatchEvent('input');
    await probeCaller('sldMusicVolume');await openHelp(2);await close();await form('TFRMOPTIONS');await checkCaller('40');
    assert.deepEqual(await page.evaluate(()=>window.rcsk.state.settings),saved);
    await element('sldEffectVolume').fill('25');await element('sldEffectVolume').dispatchEvent('input');
    await probeCaller('sldEffectVolume');await openHelp(2);await page.keyboard.press('Escape');await form('TFRMOPTIONS');await checkCaller('25');
    assert.equal(await element('sldMusicVolume').inputValue(),'40');
    await control('btnOk').click();await form('TFRMMAIN');
    const updated=await page.evaluate(()=>window.rcsk.state.settings);assert.equal(updated.music,.4);assert.equal(updated.effects,.25);
  });
  await check('More settings and Controls keep their own uncommitted edits across Help',async()=>{
    await control('btnMainOptions').click();await form('TFRMOPTIONS');
    await control('btnMoreSettings').click();
    await page.locator('#scale').fill('175');await page.locator('#scale').dispatchEvent('input');
    await probeCaller('#scale','.menu-header button');
    await page.locator('.menu-header button').click();await expectTopic(2);await close();await checkCaller('175');
    assert.equal(await page.evaluate(()=>window.rcsk.state.settings.renderScale),100);
    await page.locator('.more-settings-accept').click();await form('TFRMOPTIONS');
    await control('btnControlsAdvanced').click();await form('TFRMCONTROLSETTINGS');
    await element('lblKEY_ACCELERATE').click();await page.keyboard.press('KeyW');
    assert.equal(await element('lblKEY_ACCELERATE').textContent(),'w');
    await probeCaller('lblKEY_ACCELERATE','btnHelp');await openHelp(3,'btnHelp');await close();await form('TFRMCONTROLSETTINGS');await checkCaller('w');
    assert.equal(await page.evaluate(()=>window.rcsk.state.settings.bindings.accelerate),'ArrowUp');
    await control('btnCancel').click();await form('TFRMOPTIONS');await control('btnBack').click();await form('TFRMMAIN');
  });
  await check('Quickrace character, country and start-information Help use their original numeric contexts',async()=>{
    await control('btnQuickRace').click();await form('TFRMSELECTCHAR');await openHelp(9);await close();await form('TFRMSELECTCHAR');
    await control('btnOk').click();await form('TFRMSELECTCOUNTRY');await openHelp(10);await close();await form('TFRMSELECTCOUNTRY');
    await control('btnOk').click();await form('TFRMCONTROLSETTINGS');await openHelp(3,'btnHelp');await close();
    assert.equal(await page.evaluate(()=>window.rcsk.state.page),'start-info');
    await page.goto(origin+'/?skipIntro');await form('TFRMMAIN');
  });
  await check('Adventure list, new character and briefing Help use contexts 5, 6 and 7',async()=>{
    await control('btnAdventure').click();await form('TFRMADVENTUREMAIN');await openHelp(5);await close();
    await control('btnNewPlayer').click();await form('TFRMEDITBOX');await element('edtName').fill('Helpcontrole');
    await control('btnOk').click();await form('TFRMSELECTCHAR');await openHelp(6);await close();await form('TFRMSELECTCHAR');
    await control('btnOk').click();await form('TFRMADVENTBRIEF');await openHelp(7);await close();await form('TFRMADVENTBRIEF');
  });
  await check('Country-information Help displays the original notice 46 and returns to that form',async()=>{
    await control('btnOverview').click();await form('TFRMLANDINFO');await control('btnMainHelp').click();await form('TFRMREQUESTER');
    assert.equal(await element('lblQuit').textContent(),config['ini/shellang.ini'].dutch[46]);
    assert.equal(await page.locator('.help-window').count(),0);
    await control('btnOk').click();await form('TFRMLANDINFO');
    assert.equal(await page.evaluate(()=>window.rcsk.state.page),'country-info');
  });
  await control('btnOk').click();await form('TFRMADVENTBRIEF');await openHelp(7);
  await check('Help index and original content remain usable at portrait width',async()=>{
    await page.setViewportSize({width:390,height:844});await action('index').click();
    await page.getByRole('searchbox',{name:'Trefwoord'}).fill('Spelerkeuze');
    assert.equal(await page.locator('[data-help-panel="index"] li').count(),2);
    assert.equal(await page.evaluate(()=>document.documentElement.scrollWidth>innerWidth),false);
    await page.screenshot({path:output+'/portrait-index.png'});
  });
  assert.deepEqual(report.errors,[]);report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);await page.screenshot({path:output+'/failure.png'}).catch(()=>{});throw error;}
finally{await writeFile(output+'/browser.json',JSON.stringify(report,null,2)+'\n');await browser.close();}
