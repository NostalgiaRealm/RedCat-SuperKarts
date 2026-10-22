import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';

const output='evidence/more-settings';
const hash=async file=>crypto.createHash('sha256').update(await fs.readFile(file)).digest('hex');
const json=async file=>JSON.parse(await fs.readFile(file,'utf8'));
async function files(dir){
  const found=[];
  for(const entry of await fs.readdir(dir,{withFileTypes:true})){
    const path=dir+'/'+entry.name;
    if(entry.isDirectory())found.push(...await files(path));else found.push(path);
  }
  return found.sort();
}
const before=await json(output+'/runtime-before.json');
const runtimeFiles=['index.html','package.json',...await files('src')].sort();
assert.deepEqual(Object.keys(before).sort(),runtimeFiles,'Runtime file set changed during final checks');
const runtime={};
for(const file of runtimeFiles){runtime[file]=await hash(file);assert.equal(runtime[file],before[file],file+' changed during checks');}
const unit=await fs.readFile(output+'/unit.log','utf8');
assert.match(unit,/ℹ fail 0\b/);
const count=Number(unit.match(/ℹ pass (\d+)/)?.[1]);assert.ok(count>=504);
const paths=[
  'evidence/more-settings/msaa-validation.json','evidence/shadow-audit/browser.json',
  'evidence/ui/more-settings-browser.json','evidence/free-flight/browser.json',
  'evidence/browser/report.json','evidence/driving/report.json','evidence/display/runtime-browser.json',
];
const browser=[];
for(const file of paths){
  const result=await json(file);assert.equal(result.status,'passed',file);
  assert.deepEqual(result.errors,[],file);
  browser.push({file,sha256:await hash(file),checks:result.checks.length,browser:result.browser});
}
const nativeFile='evidence/shadow-audit/native.json',native=await json(nativeFile);
assert.equal(native.initializers.length,10);
assert.ok(native.assets.every(asset=>asset.extractedBytesEqual));
assert.ok(native.assets[0].convertedRGBAndExactKeyMatch);

const expected=new Map([['dist/index.html','index.html']]);
for(const [source,destination]of [['src','dist/src'],['public/assets','dist/assets'],
  ['node_modules/three/examples/jsm/controls','dist/node_modules/three/examples/jsm/controls']])
  for(const file of await files(source))expected.set(destination+file.slice(source.length),file);
for(const name of ['three.module.js','three.core.js'])
  expected.set('dist/node_modules/three/build/'+name,'node_modules/three/build/'+name);
const actual=await files('dist');assert.deepEqual(actual,[...expected.keys()].sort());
let assetBytes=0;
for(const [destination,source]of expected){
  assert.equal(await hash(destination),await hash(source),'Build copy differs: '+destination);
  if(source.startsWith('public/assets/'))assetBytes+=(await fs.stat(source)).size;
}
const tests=['tests/multisample-settings.test.mjs','tests/multisample-browser.mjs',
  'tests/more-settings-browser.mjs','tests/free-flight.test.mjs','tests/free-flight-browser.mjs',
  'tests/kart-shadow.test.mjs','tests/kart-shadow-browser.mjs','tests/browser.mjs',
  'tests/driving-browser.mjs','tests/display-runtime-browser.mjs','tools/native-shadow-audit.py'];
const testHashes={};for(const file of tests)testHashes[file]=await hash(file);
const report={status:'passed',createdAt:new Date().toISOString(),
  scope:'Requested shadow fixes and optional extra settings. Existing original-code comparisons plus real browser rendering/input/save checks; no new full-race matrix or original Windows framebuffer replay.',
  units:{passed:count,failed:0,log:output+'/unit.log',sha256:await hash(output+'/unit.log')},
  browser:{checks:browser.reduce((sum,item)=>sum+item.checks,0),reports:browser},
  nativeShadow:{report:nativeFile,sha256:await hash(nativeFile),originalExecutableSha256:native.sourceSha256,
    executedInitializers:10,originalAssetIdentities:native.assets.length},
  build:{files:actual.length,allCopiesIdentical:true,originalAssetCopyBytes:assetBytes,log:output+'/build.log'},
  runtimeUnchangedDuringFinalChecks:true,runtime,testHashes,
  retainedInitialFailure:{report:output+'/driving-initial.json',log:output+'/driving-initial.log',
    resolution:'The older driving harness expected +50 analog steering on mirrored Italy. Original4341d0 and independently authored mirrored-track flags require -50. Only the assertion changed; all15 driving checks then passed.'},
  limits:['SwiftShader supports only4 samples;2x and8x requests use the reported4x fallback.',
    'Prior72-case full-race results remain historical and were not rerun for this feature request.',
    'Original Windows race framebuffer and physical GPU/mobile/controller comparisons remain unavailable.']};
await fs.writeFile(output+'/validation.json',JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({status:report.status,units:count,browserChecks:report.browser.checks,buildFiles:actual.length,runtimeFiles:runtimeFiles.length}));
