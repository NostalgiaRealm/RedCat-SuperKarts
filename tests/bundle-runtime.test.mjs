import test from 'node:test';
import assert from 'node:assert/strict';
import {mkdtemp,mkdir,writeFile,readFile,readdir,stat,rm} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import path from 'node:path';
import {spawn} from 'node:child_process';
import {pathToFileURL} from 'node:url';
import {bundleRuntime} from '../tools/bundle.mjs';
import {assertGameRuntime,createGameProtocolHandler} from '../electron/game-protocol.mjs';
import {createWebServer} from '../tools/server-runtime.mjs';

async function fixture(t){
  const root=await mkdtemp(path.join(tmpdir(),'rcsk-bundle-test-'));
  t.after(()=>rm(root,{recursive:true,force:true}));
  const put=async(file,text)=>{await mkdir(path.dirname(path.join(root,file)),{recursive:true});await writeFile(path.join(root,file),text);};
  await put('source/index.html','<!doctype html><script type="importmap">{"imports":{"three":"unused"}}</script><script type="module" src="/src/main.js"></script>');
  await put('source/style.css','body { color: red; }');
  await put('source/main.js',`import {value} from './shared.js'; globalThis.bundleOrder.push('menu'); export const initial=value; export const load=()=>import('./race.js');`);
  await put('source/shared.js',`globalThis.bundleOrder=['shared']; export const value=Math.fround(1/3); export function unused(){throw Error('unused');}`);
  await put('source/race.js',`import {value} from './shared.js'; globalThis.bundleOrder.push('race'); await Promise.resolve(); export class NativeDriver{}; export const result=value*3;`);
  const output=path.join(root,'output');
  const result=await bundleRuntime(output,{root});
  for(const file of ['ui/forms.json','menu/manifest.json','config.json','manifest.json'])await put('output/assets/'+file,'{}');
  return {sourceRoot:root,root:output,assetsRoot:path.join(output,'assets'),result,put:(file,text)=>put('output/'+file,text)};
}

test('bundle preserves lazy evaluation, shared singleton state, names and numeric expressions',async t=>{
  const f=await fixture(t);
  const entry=await import(pathToFileURL(path.join(f.root,'src/main.js')).href);
  assert.deepEqual(globalThis.bundleOrder,['shared','menu']);
  assert.equal(entry.initial,Math.fround(1/3));
  const race=await entry.load();
  assert.deepEqual(globalThis.bundleOrder,['shared','menu','race']);
  assert.equal(race.NativeDriver.name,'NativeDriver');assert.equal(race.result,Math.fround(1/3)*3);
  assert.equal(await entry.load(),race);
  assert.ok(f.result.manifest.files.filter(file=>file.endsWith('.js')).length>=2);
  assert.doesNotMatch(await readFile(path.join(f.root,'index.html'),'utf8'),/importmap|node_modules/);
  for(const file of f.result.manifest.files.filter(file=>file.endsWith('.js'))){
    const map=JSON.parse(await readFile(path.join(f.root,file+'.map'),'utf8'));
    assert.ok(map.sourcesContent.length>0);
  }
  delete globalThis.bundleOrder;
});

test('desktop validates and serves every bundled chunk without standalone Three files',async t=>{
  const f=await fixture(t);await assertGameRuntime(f);
  const handle=await createGameProtocolHandler(f);
  for(const file of f.result.manifest.files){
    const r=await handle(new Request('rcsk://game/'+file));assert.equal(r.status,200,file);await r.arrayBuffer();
  }
  const chunk=f.result.manifest.files.find(file=>file.includes('chunks/'));
  await rm(path.join(f.root,chunk));await assert.rejects(assertGameRuntime(f),/Required game files/);
  await f.put('runtime-manifest.json',JSON.stringify({format:'rcsk-runtime-v1',entry:'src/main.js',files:['src/main.js','src/style.css','src/../../outside.js']}));
  await assert.rejects(assertGameRuntime(f),/Invalid bundled runtime manifest/);
});

test('shared HTTP adapter preserves byte seeking, HEAD and private-tree restrictions',async t=>{
  const f=await fixture(t);await f.put('assets/movie.mp4','0123456789');
  const server=await createWebServer(f);
  await new Promise(resolve=>server.listen(0,'127.0.0.1',resolve));
  t.after(()=>new Promise(resolve=>{server.closeAllConnections();server.close(resolve);}));
  const origin='http://127.0.0.1:'+server.address().port;
  for(const [headers,status,text]of [[{},200,'0123456789'],[{Range:'bytes=-3'},206,'789'],[{Range:'bytes=3-'},206,'3456789']]){
    const response=await fetch(origin+'/assets/movie.mp4',{headers});assert.equal(response.status,status);assert.equal(await response.text(),text);
    const head=await fetch(origin+'/assets/movie.mp4',{headers,method:'HEAD'});assert.equal(head.status,status);assert.equal(await head.text(),'');
    assert.equal(head.headers.get('content-length'),String(text.length));
  }
  const invalid=await fetch(origin+'/assets/movie.mp4',{headers:{Range:'bytes=20-'}});assert.equal(invalid.status,416);
  for(const route of ['/original-source/inputs/rcskspel.dat','/source/main.js','/node_modules/three/build/three.module.js'])
    assert.equal((await fetch(origin+route)).status,403,route);
  const entry=await fetch(origin+'/src/main.js');assert.equal(entry.status,200);assert.match(entry.headers.get('content-type'),/^text\/javascript/);
  assert.ok(entry.headers.get('content-security-policy').includes("script-src 'self'"));
});

test('editable modules are available only in explicit browser diagnostic mode',async t=>{
  const f=await fixture(t);
  await f.put('source/probe.js','export const probe=42;');
  await f.put('source/README.md','Editing inputs only.');
  await f.put('node_modules/three/build/three.module.js','export const probe=42;');
  const ordinary=await createGameProtocolHandler(f);
  for(const route of ['/source/probe.js','/node_modules/three/build/three.module.js'])
    assert.equal((await ordinary(new Request('rcsk://game'+route))).status,403,route);
  const diagnostic=await createGameProtocolHandler({...f,inspectSource:true});
  const response=await diagnostic(new Request('rcsk://game/'));
  const html=await response.text();
  assert.match(html,/type="importmap"/);assert.match(html,/node_modules\/three\/build\/three\.module\.js/);
  assert.match(html,/src="\/src\/main\.js"/);
  assert.ok(response.headers.get('content-security-policy').includes('sha256-'));
  for(const route of ['/source/probe.js','/node_modules/three/build/three.module.js']){
    const r=await diagnostic(new Request('rcsk://game'+route));assert.equal(r.status,200,route);await r.text();
  }
  assert.equal((await diagnostic(new Request('rcsk://game/source/README.md'))).status,403);
});

test('runtime refresh replaces stale generated chunks, preserves editable files and survives compilation failure',async t=>{
  const {refreshRuntime}=await import('../tools/refresh-runtime.mjs');
  const f=await fixture(t),root=f.sourceRoot;
  const original=await readFile(path.join(root,'source/main.js'),'utf8');
  await refreshRuntime({root});
  await writeFile(path.join(root,'src/chunks/stale.js'),'old generated chunk');
  await refreshRuntime({root});
  await assert.rejects(readFile(path.join(root,'src/chunks/stale.js')),error=>error.code==='ENOENT');
  assert.equal(await readFile(path.join(root,'source/main.js'),'utf8'),original);
  const before=await readFile(path.join(root,'src/main.js'),'utf8');
  await writeFile(path.join(root,'source/main.js'),'this is not JavaScript {{{');
  await assert.rejects(refreshRuntime({root}));
  assert.equal(await readFile(path.join(root,'src/main.js'),'utf8'),before);
  assert.equal(await readFile(path.join(root,'source/main.js'),'utf8'),'this is not JavaScript {{{');
});


test('source maps identify the same embedded editable modules after moving a staged runtime',async t=>{
  const {refreshRuntime}=await import('../tools/refresh-runtime.mjs');
  const f=await fixture(t),root=f.sourceRoot;
  const readSources=async(output,manifest)=>{
    const sources=new Map();
    for(const file of manifest.files.filter(file=>file.endsWith('.js'))){
      const map=JSON.parse(await readFile(path.join(output,file+'.map'),'utf8'));
      assert.equal(map.sourceRoot,'rcsk-source:///');
      assert.equal(map.sources.length,map.sourcesContent.length);
      for(let i=0;i<map.sources.length;i++){
        const source=map.sources[i];
        assert.match(source,/^source\/[\w.-]+\.js$/);
        const identity=new URL(source,map.sourceRoot).href;
        assert.equal(identity,'rcsk-source:///'+source);
        assert.equal(map.sourcesContent[i],await readFile(path.join(root,source),'utf8'));
        sources.set(identity,map.sourcesContent[i]);
      }
    }
    return [...sources].sort(([a],[b])=>a.localeCompare(b));
  };
  const staged=await readSources(f.root,f.result.manifest);
  assert.equal(staged.length,3);
  const refreshed=await refreshRuntime({root});
  assert.deepEqual(await readSources(root,refreshed.manifest),staged);
  const alternate=path.join(root,'nested','deployment');
  const rebuilt=await bundleRuntime(alternate,{root});
  assert.deepEqual(await readSources(alternate,rebuilt.manifest),staged);
});

test('simultaneous separate-process refreshes leave a complete runtime and preserve editable files',{timeout:60000},async t=>{
  const f=await fixture(t),root=f.sourceRoot;
  const sourceFiles=(await readdir(path.join(root,'source'))).sort();
  const before=await Promise.all(sourceFiles.map(async file=>[file,await readFile(path.join(root,'source',file),'utf8')]));
  const children=[];
  t.after(()=>{for(const child of children)if(child.exitCode===null)child.kill();});
  const script=`
    const {refreshRuntime}=await import(process.argv[2]);
    process.once('message',async()=>{
      try{await refreshRuntime({root:process.argv[1]});process.disconnect();}
      catch(error){console.error(error.stack||error);process.exitCode=1;process.disconnect();}
    });
    process.send('ready');
  `;
  const runs=Array.from({length:4},()=>{
    const child=spawn(process.execPath,['--input-type=module','--eval',script,root,new URL('../tools/refresh-runtime.mjs',import.meta.url).href],
      {stdio:['ignore','ignore','pipe','ipc']});
    children.push(child);let stderr='';
    child.stderr.on('data',data=>stderr+=data);
    const ready=new Promise((resolve,reject)=>{
      child.once('message',message=>message==='ready'?resolve():reject(Error('Unexpected child message: '+message)));
      child.once('error',reject);
      child.once('exit',code=>reject(Error('Refresh child exited before ready: '+code+' '+stderr)));
    });
    const done=new Promise((resolve,reject)=>{
      child.once('error',reject);
      child.once('exit',(code,signal)=>code===0?resolve():reject(Error('Concurrent refresh failed: '+code+' '+signal+' '+stderr)));
    });
    // Register the exit handlers before releasing any worker.
    done.catch(()=>{});
    return {child,ready,done};
  });
  await Promise.all(runs.map(run=>run.ready));
  for(const {child}of runs)child.send('refresh');
  await Promise.all(runs.map(run=>run.done));
  await assertGameRuntime({root,assetsRoot:f.assetsRoot});
  const manifest=JSON.parse(await readFile(path.join(root,'runtime-manifest.json'),'utf8'));
  for(const output of manifest.outputs)assert.equal((await stat(path.join(root,output.path))).size,output.bytes,output.path);
  assert.deepEqual(await Promise.all(sourceFiles.map(async file=>[file,await readFile(path.join(root,'source',file),'utf8')])),before);
  const entry=await import(pathToFileURL(path.join(root,'src/main.js')).href);
  assert.equal(entry.initial,Math.fround(1/3));assert.equal((await entry.load()).result,Math.fround(1/3)*3);
  delete globalThis.bundleOrder;
});
