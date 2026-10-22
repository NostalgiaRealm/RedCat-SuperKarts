import test from 'node:test';
import assert from 'node:assert/strict';
import {mkdtemp,mkdir,writeFile,cp,rm} from 'node:fs/promises';
import {tmpdir} from 'node:os';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {spawnSync} from 'node:child_process';
import {assertServerRuntime,SERVER_RUNTIME_FILES} from '../tools/server-runtime.mjs';

const project=fileURLToPath(new URL('..',import.meta.url));
async function fixture(t){
  const root=await mkdtemp(path.join(tmpdir(),'rcsk-server-runtime-'));
  t.after(()=>rm(root,{recursive:true,force:true}));return root;
}
async function add(root,file){await mkdir(path.dirname(path.join(root,file)),{recursive:true});await writeFile(path.join(root,file),'// fixture runtime module\n');}

test('server fails before listening when the browser import graph is absent',async t=>{
  const root=await fixture(t);await mkdir(path.join(root,'tools'));
  for(const file of ['serve.mjs','server-runtime.mjs'])await cp(path.join(project,'tools',file),path.join(root,'tools',file));
  const result=spawnSync(process.execPath,[path.join(root,'tools','serve.mjs')],{
    cwd:root,env:{...process.env,PORT:'0'},encoding:'utf8',timeout:3000,
  });
  assert.equal(result.error,undefined);assert.equal(result.status,1);
  assert.doesNotMatch(result.stdout,/Local:/);
  for(const file of SERVER_RUNTIME_FILES)assert.ok(result.stderr.includes(file));
  assert.match(result.stderr,/npm ci/);assert.match(result.stderr,/npm install/);assert.match(result.stderr,/npm start/);
});

test('partial installation reports the actual missing transitive module',async t=>{
  const root=await fixture(t);
  await add(root,SERVER_RUNTIME_FILES[0]);await add(root,SERVER_RUNTIME_FILES[2]);
  await assert.rejects(assertServerRuntime(root),error=>{
    assert.ok(error.message.includes(SERVER_RUNTIME_FILES[1]));
    assert.ok(!error.message.includes(SERVER_RUNTIME_FILES[0]));return true;
  });
  // A directory with the right filename is not a usable browser module.
  await mkdir(path.join(root,SERVER_RUNTIME_FILES[1]));
  await assert.rejects(assertServerRuntime(root),/three\.core\.js/);
});

test('complete runtime files pass without requiring unrelated assets or development tools',async t=>{
  const root=await fixture(t);
  for(const file of SERVER_RUNTIME_FILES)await add(root,file);
  await assert.doesNotReject(assertServerRuntime(root));
});
