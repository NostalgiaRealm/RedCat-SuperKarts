import test from 'node:test';
import assert from 'node:assert/strict';
import {mkdtemp,mkdir,writeFile,rm} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import net from 'node:net';
import path from 'node:path';
import {assertServerRuntime,createWebServer} from '../tools/server-runtime.mjs';

async function fixture(t){
  const root=await mkdtemp(path.join(tmpdir(),'rcsk-server-runtime-'));
  t.after(()=>rm(root,{recursive:true,force:true}));return root;
}
async function add(root,file,text='// fixture runtime module\n'){
  await mkdir(path.dirname(path.join(root,file)),{recursive:true});await writeFile(path.join(root,file),text);
}
async function addRuntime(root){
  await add(root,'runtime-manifest.json',JSON.stringify({format:'rcsk-runtime-v1',entry:'src/main.js',files:['src/main.js','src/style.css','src/chunks/race.js']}));
  for(const file of ['index.html','src/main.js','src/style.css','src/chunks/race.js',
    'public/assets/ui/forms.json','public/assets/menu/manifest.json','public/assets/config.json','public/assets/manifest.json'])await add(root,file);
}

test('server requires an explicit bundled runtime manifest instead of falling back to editable modules',async t=>{
  const root=await fixture(t);await add(root,'source/main.js');await add(root,'src/main.js');
  await assert.rejects(assertServerRuntime(root),error=>{
    assert.match(error.message,/runtime manifest/i);assert.match(error.message,/npm run bundle/);return true;
  });
});

test('partial runtime identifies a missing generated chunk and rejects directories posing as chunks',async t=>{
  const root=await fixture(t);await addRuntime(root);await rm(path.join(root,'src/chunks/race.js'));
  await assert.rejects(assertServerRuntime(root),error=>{
    assert.ok(error.message.includes('src/chunks/race.js'));assert.ok(!error.message.includes('src/main.js'));return true;
  });
  await mkdir(path.join(root,'src/chunks/race.js'));
  await assert.rejects(assertServerRuntime(root),/src\/chunks\/race\.js/);
});

test('complete runtime works without editable modules, standalone Three or build tools',async t=>{
  const root=await fixture(t);await addRuntime(root);
  await assert.doesNotReject(assertServerRuntime(root));
});

test('requests closed before the file opens leave the server running',async t=>{
  const root=await fixture(t);await addRuntime(root);
  await add(root,'public/assets/media/intro.mp4',Buffer.alloc(1024*1024,1));
  const server=await createWebServer({root,assetsRoot:path.join(root,'public/assets')});
  await new Promise(resolve=>server.listen(0,'127.0.0.1',resolve));t.after(()=>server.close());
  const {port}=server.address();
  // Closing right after the request line aborts while the handler awaits stat.
  for(let i=0;i<20;i++)await new Promise(resolve=>{
    const socket=net.connect(port,'127.0.0.1',()=>{
      socket.end('GET /assets/media/intro.mp4 HTTP/1.1\r\nHost: game\r\n\r\n');socket.destroy();
    });
    socket.on('error',()=>{});socket.on('close',resolve);
  });
  await new Promise(resolve=>setTimeout(resolve,100));
  const response=await fetch(`http://127.0.0.1:${port}/index.html`);
  assert.equal(response.status,200);await response.text();
});
