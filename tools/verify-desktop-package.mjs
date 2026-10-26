import assert from 'node:assert/strict';
import {createReadStream} from 'node:fs';
import {readdir,readFile,writeFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import path from 'node:path';
import {fileURLToPath,pathToFileURL} from 'node:url';
import {listPackage,extractFile} from '@electron/asar';
import {Arch} from 'builder-util';

const project=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
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
  const source=path.join(project,'dist'),destination=path.join(resources,'game');
  const names=await files(source);
  assert.deepEqual(await files(destination),names,'Packaged game must contain every built file, including Three.js');
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
  assert.equal(metadata.main,'electron/main.mjs');
  assert.equal(metadata.version,JSON.parse(await readFile(path.join(project,'package.json'),'utf8')).version);
  assert.equal(metadata.devDependencies,undefined,'Development dependencies must not ship');
  return {status:'passed',gameFiles:names.length,gameTreeSha256:tree.digest('hex'),wrapperFiles:wrapper.length+1,
    checks:['All game files match dist byte-for-byte, including Three.js and original media',
      'Wrapper matches source; no research, tests, development dependencies or unrelated project files in app.asar']};
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
