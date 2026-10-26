import test from 'node:test';
import assert from 'node:assert/strict';
import {mkdtemp,mkdir,writeFile,rm} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import path from 'node:path';
import {assertServerRuntime} from '../tools/server-runtime.mjs';

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
