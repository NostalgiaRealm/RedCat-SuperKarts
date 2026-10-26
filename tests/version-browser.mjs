import assert from 'node:assert/strict';
import {createHash} from 'node:crypto';
import {mkdir,readFile,writeFile} from 'node:fs/promises';
import {chromium} from 'playwright';
import {GAME_VERSION} from '../source/version.js';

const pkg=JSON.parse(await readFile('package.json','utf8'));
const lock=JSON.parse(await readFile('package-lock.json','utf8'));
const output=`evidence/version-${pkg.version}`;
await mkdir(output,{recursive:true});
const report={date:new Date().toISOString(),version:pkg.version,
  scope:'Source version metadata and menu display only; no full suite, races or builds.',
  metadata:{package:pkg.version,lockfile:lock.version,lockfileRoot:lock.packages[''].version,menu:GAME_VERSION},
  checks:[],errors:[]};
const browser=await chromium.launch({executablePath:process.env.CHROME_PATH||'/usr/bin/google-chrome',
  headless:true,args:['--autoplay-policy=no-user-gesture-required']});
try{
  for(const version of Object.values(report.metadata))assert.equal(version,pkg.version);
  const page=await browser.newPage();
  await page.addInitScript(()=>{
    const play=HTMLMediaElement.prototype.play;
    HTMLMediaElement.prototype.play=function(){this.playbackRate=8;return play.call(this);};
  });
  page.on('pageerror',error=>report.errors.push(error.message));
  page.on('response',response=>{if(response.status()>=400)report.errors.push(`${response.status()} ${response.url()}`);});
  for(const [name,viewport]of [['landscape',{width:1024,height:768}],['portrait',{width:390,height:844}]]){
    await page.setViewportSize(viewport);
    await page.goto((process.env.RCSK_URL||'http://127.0.0.1:4173')+'/?skipIntro');
    await page.waitForSelector('[data-form=TFRMMAIN]');
    await page.locator('[data-native=btnMainOptions]').click();
    await page.waitForSelector('[data-form=TFRMOPTIONS]');
    await page.locator('[data-native=btnMoreSettings]').click();
    assert.equal(await page.locator('h1').textContent(),'Meer instellingen');
    const label=page.locator('#game-version');
    assert.equal(await label.count(),1);
    assert.equal(await label.textContent(),`Versie ${pkg.version}`);
    await label.scrollIntoViewIfNeeded();
    assert.equal(await label.isVisible(),true);
    const bounds=await label.boundingBox();
    assert.ok(bounds.x>=0&&bounds.y>=0&&bounds.x+bounds.width<=viewport.width&&bounds.y+bounds.height<=viewport.height);
    assert.equal(await page.evaluate(()=>document.documentElement.scrollWidth>innerWidth),false);
    const screenshot=`${output}/${name}.png`;
    await page.screenshot({path:screenshot});
    await page.getByRole('button',{name:'Terug',exact:true}).click();
    await page.waitForSelector('[data-form=TFRMOPTIONS]');
    report.checks.push({name,viewport,label:`Versie ${pkg.version}`,bounds,screenshot,backNavigation:'passed'});
  }
  assert.deepEqual(report.errors,[]);
  report.browser=browser.version();
  report.status='passed';
}catch(error){report.status='failed';report.failure=String(error.stack||error);process.exitCode=1;}
finally{
  await browser.close();
  report.sha256={};
  for(const file of ['package.json','package-lock.json','source/version.js','source/main.js','source/style.css',
    'tools/sync-version.mjs','tests/version-browser.mjs','CHANGELOG.md','docs/releases/v0.9.0.md']){
    report.sha256[file]=createHash('sha256').update(await readFile(file)).digest('hex');
  }
  await writeFile(`${output}/validation.json`,JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({status:report.status,version:report.version,layouts:report.checks.length,errors:report.errors,failure:report.failure}));
}
