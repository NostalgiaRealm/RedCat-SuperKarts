// electron-builder's afterPack hook (electron-builder.json), the JS port's tools/verify-desktop-package.mjs for the
// recomp: before a package is archived or signed, its resources/site must be dist/site byte for byte (less the .gz
// and .br copies the builder's filter leaves out, which are for web servers), the race module and the original data
// files included, and app.asar must hold only the shell. The report goes next to the packages as
// integrity-<platform>-<arch>.json; equal gameTreeSha256 values mean every platform got the same game.
//   node tools/verify-desktop-package.mjs release/2.0.0/linux-unpacked/resources
import assert from 'node:assert/strict';
import {createReadStream} from 'node:fs';
import {readdir,readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import path from 'node:path';
import {fileURLToPath,pathToFileURL} from 'node:url';
import {listPackage,extractFile} from '@electron/asar';
import {Arch} from 'builder-util';

const project=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const webOnly=name=>/\.(?:gz|br)$/.test(name);
async function files(root,prefix=''){
  const output=[];
  for(const entry of await readdir(path.join(root,prefix),{withFileTypes:true})){
    const relative=prefix?prefix+'/'+entry.name:entry.name;
    if(entry.isDirectory())output.push(...await files(root,relative));
    else {assert.ok(entry.isFile(),`Unexpected non-regular file: ${relative}`);output.push(relative);}
  }
  return output.sort();
}
async function hash(file){
  const digest=createHash('sha256');
  for await(const chunk of createReadStream(file))digest.update(chunk);
  return digest.digest('hex');
}

export async function verifyDesktopPackage(resources){
  // RCSK_SITE: a site built elsewhere, given to electron-builder too (-c.extraResources.0.from=...; docs/building.md)
  const source=process.env.RCSK_SITE?path.resolve(process.env.RCSK_SITE):path.join(project,'dist/site'),destination=path.join(resources,'site');
  const names=(await files(source)).filter(name=>!webOnly(name));
  assert.deepEqual(await files(destination),names,'Packaged site must contain every file of dist/site');
  const build=JSON.parse(await readFile(path.join(destination,'build.json'),'utf8'));
  for(const name of ['index.html',`app/${build.revision}/source/main.js`,`app/${build.revision}/game/rcskspel.wasm`])
    assert.ok(names.includes(name),`Packaged site lacks ${name}`);
  assert.ok(names.some(name=>name.startsWith('data/')),'Packaged site lacks the original data files');
  const tree=createHash('sha256');
  for(const name of names){
    const expected=await hash(path.join(source,name));
    assert.equal(await hash(path.join(destination,name)),expected,`Packaged file differs: ${name}`);
    tree.update(name+'\0'+expected+'\n');
  }
  const archive=path.join(resources,'app.asar');
  const wrapper=['desktop/icons/icon.png',...await files(path.join(project,'electron')).then(names=>names.map(name=>'electron/'+name))];
  const entries=new Set(['/package.json']);
  for(const name of wrapper){
    const parts=name.split('/');
    while(parts.length){entries.add('/'+parts.join('/'));parts.pop();}
    assert.deepEqual(extractFile(archive,path.normalize(name)),await readFile(path.join(project,name)),`Packaged wrapper differs: ${name}`);
  }
  const archiveEntries=listPackage(archive).map(name=>name.replaceAll('\\','/')).sort();
  assert.deepEqual(archiveEntries,[...entries].sort(),'Unexpected files in app.asar');
  const metadata=JSON.parse(extractFile(archive,'package.json'));
  const own=JSON.parse(await readFile(path.join(project,'package.json'),'utf8'));
  assert.equal(metadata.main,'electron/main.mjs');
  assert.equal(metadata.version,own.version);
  assert.equal(metadata.devDependencies,undefined,'Development dependencies must not ship');
  const {GAME_VERSION}=await import(pathToFileURL(path.join(project,'source/version.js')).href);
  assert.equal(GAME_VERSION,own.version,'source/version.js must match package.json (npm run version:sync)');
  return {status:'passed',version:own.version,siteRevision:build.revision,gameFiles:names.length,
    gameTreeSha256:tree.digest('hex'),wrapperFiles:wrapper.length+1,
    checks:['All site files match dist/site byte-for-byte, including the recompiled race and the original data files',
      'Wrapper matches source; no tests, tools, development dependencies or unrelated project files in app.asar',
      'package.json and source/version.js carry the same version']};
}

// Runs before signing/archiving unless the release explicitly disables build checks.
export default async function afterPack(context){
  if(process.env.RCSK_SKIP_BUILD_CHECKS==='1'){
    console.log('Skipping packaged-payload checks (RCSK_SKIP_BUILD_CHECKS=1).');
    return;
  }
  const resources=context.electronPlatformName==='darwin'
    ?path.join(context.appOutDir,context.packager.appInfo.productFilename+'.app','Contents','Resources')
    :path.join(context.appOutDir,'resources');
  const result=await verifyDesktopPackage(resources);
  const platform=context.electronPlatformName,arch=Arch[context.arch];
  await writeFile(path.join(path.dirname(context.appOutDir),`integrity-${platform}-${arch}.json`),
    JSON.stringify({...result,platform,arch},null,2)+'\n');
  console.log(`Verified desktop payload: ${result.gameFiles} game files and ${result.wrapperFiles} wrapper files.`);
}

if(process.argv[1]&&import.meta.url===pathToFileURL(path.resolve(process.argv[1])).href){
  if(!process.argv[2])throw Error('Usage: node tools/verify-desktop-package.mjs /path/to/app/resources');
  console.log(JSON.stringify(await verifyDesktopPackage(path.resolve(process.argv[2])),null,2));
}
