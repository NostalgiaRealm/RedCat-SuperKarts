import test from 'node:test';
import assert from 'node:assert/strict';
import path from 'node:path';
import {mkdtemp,mkdir,writeFile,readFile,symlink,rm} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import {createHash} from 'node:crypto';
import {byteRange,createGameProtocolHandler,gameContentSecurityPolicy,assertGameRuntime} from '../electron/game-protocol.mjs';
import {APP_NAME,GAME_ORIGIN,gamePaths,userDataPath,isGameNavigation,launchURL,RENDERER_PREFERENCES} from '../electron/runtime.mjs';

async function fixture(t,packaged=false){
  const workspace=await mkdtemp(path.join(tmpdir(),'rcsk-electron-runtime-'));
  t.after(()=>rm(workspace,{recursive:true,force:true}));
  const paths=gamePaths({packaged,appPath:workspace,resourcesPath:path.join(workspace,'resources')});
  const put=async(file,data)=>{await mkdir(path.dirname(file),{recursive:true});await writeFile(file,data);};
  const map='{"imports":{"three":"/node_modules/three/build/three.module.js"}}';
  const html=`<!doctype html><script type="importmap">${map}</script><script type="module" src="/src/main.js"></script>`;
  await put(path.join(paths.root,'index.html'),html);
  await put(path.join(paths.root,'src/main.js'),'import * as THREE from "three";');
  await put(path.join(paths.root,'src/style.css'),'body{color:white}');
  for(const file of ['build/three.module.js','build/three.core.js','examples/jsm/controls/OrbitControls.js'])
    await put(path.join(paths.root,'node_modules/three',file),'export const fixture=true;');
  for(const file of ['ui/forms.json','menu/manifest.json','config.json','manifest.json'])await put(path.join(paths.assetsRoot,file),'{}');
  await put(path.join(paths.assetsRoot,'media/intro.mp4'),Buffer.from('0123456789'));
  await put(path.join(paths.assetsRoot,'data/cars0.dat'),Buffer.from([0,255,1,254]));
  await put(path.join(paths.assetsRoot,'empty.wav'),'');
  await put(path.join(workspace,'secret.txt'),'not runtime data');
  return {...paths,workspace,html,map,put};
}
const request=(route,options)=>new Request(GAME_ORIGIN+route,options);

test('desktop source and packaged paths share origin but resolve their own asset trees',async t=>{
  for(const packaged of [false,true]){
    const files=await fixture(t,packaged);await assertGameRuntime(files);
    const handle=await createGameProtocolHandler(files);
    const root=await handle(request('/?skipIntro'));
    assert.equal(root.status,200);assert.equal(await root.text(),files.html);
    assert.match(root.headers.get('content-type'),/^text\/html/);
    for(const route of ['/src/main.js','/src/style.css','/assets/ui/forms.json','/node_modules/three/build/three.core.js','/node_modules/three/examples/jsm/controls/OrbitControls.js']){
      const response=await handle(request(route));assert.equal(response.status,200,route);await response.arrayBuffer();
    }
    const binary=await handle(request('/assets/data/cars0.dat'));
    assert.deepEqual([...new Uint8Array(await binary.arrayBuffer())],[0,255,1,254]);
  }
});

test('SVG touch controls load with an image MIME type in both desktop layouts',async t=>{
  for(const packaged of [false,true]){
    const files=await fixture(t,packaged),handle=await createGameProtocolHandler(files);
    for(const name of ['steering-wheel.svg','brake-pedal.svg']){
      const source=await readFile(new URL('../public/assets/touch/'+name,import.meta.url),'utf8');
      await files.put(path.join(files.assetsRoot,'touch',name),source);
      const response=await handle(request('/assets/touch/'+name));
      assert.equal(response.status,200);assert.equal(response.headers.get('content-type'),'image/svg+xml');
      assert.equal(await response.text(),source);
    }
  }
});

test('media responds with exact full, bounded, open and suffix bytes, plus HEAD metadata',async t=>{
  const files=await fixture(t),handle=await createGameProtocolHandler(files);
  for(const [range,status,text,contentRange]of [
    [null,200,'0123456789',null],['bytes=2-5',206,'2345','bytes 2-5/10'],
    ['bytes=7-',206,'789','bytes 7-9/10'],['bytes=-3',206,'789','bytes 7-9/10'],
    ['bytes=8-999',206,'89','bytes 8-9/10'],['bytes=-20',206,'0123456789','bytes 0-9/10'],
  ]){
    const headers=range?{Range:range}:{};
    const response=await handle(request('/assets/media/intro.mp4',{headers}));
    assert.equal(response.status,status);assert.equal(response.headers.get('content-type'),'video/mp4');
    assert.equal(response.headers.get('accept-ranges'),'bytes');
    assert.equal(response.headers.get('content-range'),contentRange);
    assert.equal(response.headers.get('content-length'),String(text.length));assert.equal(await response.text(),text);
    const head=await handle(request('/assets/media/intro.mp4',{method:'HEAD',headers}));
    assert.equal(head.status,status);assert.equal(head.headers.get('content-length'),String(text.length));assert.equal(await head.text(),'');
  }
  for(const range of ['bytes=10-','bytes=5-2','bytes=-0','bytes=0-1,4-5','items=0-1','bytes=-','bytes=99999999999999999999-']){
    const response=await handle(request('/assets/media/intro.mp4',{headers:{Range:range}}));
    assert.equal(response.status,416,range);assert.equal(response.headers.get('content-range'),'bytes */10');
  }
  const empty=await handle(request('/assets/empty.wav'));assert.equal(empty.status,200);assert.equal(await empty.text(),'');
});

test('protocol refuses other origins, methods, traversal, private trees and symlink escapes',async t=>{
  const files=await fixture(t),handle=await createGameProtocolHandler(files);
  for(const url of ['https://game/','rcsk://elsewhere/','rcsk://game:444/','rcsk://user@game/'])
    assert.equal((await handle({url,method:'GET',headers:new Headers()})).status,403,url);
  const post=await handle(request('/',{method:'POST'}));assert.equal(post.status,405);assert.equal(post.headers.get('allow'),'GET, HEAD');
  for(const route of ['/electron/main.mjs','/tools/serve.mjs','/docs/secret.txt','/package.json',
    '/node_modules/electron/index.js','/node_modules/three/package.json','/assets/.private.json',
    '/assets/..%2F..%2Fsecret.txt','/assets/%5C..%5Csecret.txt','/assets/invalid%00.png','/src/../secret.txt'])
    assert.equal((await handle(request(route))).status,403,route);
  assert.equal((await handle({url:'rcsk://game/assets/%zz',method:'GET',headers:new Headers()})).status,400);
  await symlink(path.join(files.workspace,'secret.txt'),path.join(files.assetsRoot,'escape.json'));
  assert.equal((await handle(request('/assets/escape.json'))).status,403);
  const missing=await handle(request('/assets/missing.png'));assert.equal(missing.status,404);assert.equal(await missing.text(),'Not found');
});

test('CSP allows only hashed shipped inline scripts and denies remote execution',()=>{
  const inline='{"imports":{"three":"/three.js"}}';
  const csp=gameContentSecurityPolicy(`<script type="importmap">${inline}</script><script src="/src/main.js"></script>`);
  const hash=createHash('sha256').update(inline).digest('base64');
  assert.ok(csp.includes(`script-src 'self' 'sha256-${hash}'`));
  assert.doesNotMatch(csp.split(';').find(part=>part.trim().startsWith('script-src')),/unsafe-inline|unsafe-eval/);
  assert.ok(csp.includes("connect-src 'self'"));assert.ok(csp.includes("object-src 'none'"));
});

test('launcher keeps stable profiles, constrained startup and sandboxed renderer settings',()=>{
  assert.equal(APP_NAME,'RedCat SuperKarts');
  assert.equal(userDataPath('/profiles'),path.join('/profiles',APP_NAME));
  assert.equal(userDataPath('/profiles','/isolated/test'),path.normalize('/isolated/test'));
  assert.throws(()=>userDataPath('/profiles','relative'),/absolute/);
  assert.equal(launchURL(['--skip-intro']),GAME_ORIGIN+'/?skipIntro');
  assert.equal(launchURL(['https://untrusted.invalid/','--url=https://untrusted.invalid/']),GAME_ORIGIN+'/');
  for(const url of [GAME_ORIGIN+'/',GAME_ORIGIN+'/?skipIntro',GAME_ORIGIN+'/index.html#help'])assert.equal(isGameNavigation(url),true);
  for(const url of ['https://example.com/',GAME_ORIGIN+'/src/main.js','rcsk://game.evil/','file:///etc/passwd','rcsk://game:123/'])assert.equal(isGameNavigation(url),false);
  assert.equal(RENDERER_PREFERENCES.sandbox,true);assert.equal(RENDERER_PREFERENCES.contextIsolation,true);
  assert.equal(RENDERER_PREFERENCES.nodeIntegration,false);assert.equal(RENDERER_PREFERENCES.webSecurity,true);
  assert.equal(RENDERER_PREFERENCES.preload,undefined);
  assert.equal(byteRange(null,0),null);assert.equal(byteRange('bytes=0-',0),false);
});

test('desktop startup identifies absent browser runtime before opening a blank window',async t=>{
  const files=await fixture(t);await rm(path.join(files.root,'node_modules/three/build/three.core.js'));
  await assert.rejects(assertGameRuntime(files),error=>{
    assert.match(error.message,/three\.core\.js/);assert.match(error.message,/npm ci/);return true;
  });
});
