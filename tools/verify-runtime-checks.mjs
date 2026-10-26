// Historical checkpoint verifier: the recorded src/ hashes and copy-layout
// assertions below belong to its frozen evidence snapshot, before source/ was
// separated from bundled runtime output. Use the matching historical checkout;
// do not regenerate these records as evidence of the current runtime.
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {spawn} from 'node:child_process';
import {fileURLToPath} from 'node:url';

const root=fileURLToPath(new URL('../',import.meta.url));
const base='evidence/full-race-matrix';
const sha=bytes=>crypto.createHash('sha256').update(bytes).digest('hex');
const read=file=>fs.readFileSync(path.join(root,file));
const files=directory=>fs.readdirSync(path.join(root,directory),{withFileTypes:true})
  .flatMap(entry=>entry.isDirectory()?files(`${directory}/${entry.name}`):[`${directory}/${entry.name}`]).sort();
const runtime=()=>Object.fromEntries(['index.html',...files('src')].map(file=>[file,sha(read(file))]));
const expected=JSON.parse(read(`${base}/verified-runtime-checkpoint.json`)).files;
const report={format:'superkarts-bound-runtime-checks-v1',status:'running',
  startedAt:new Date().toISOString(),runtime:runtime(),checks:[]};
assert.deepEqual(report.runtime,expected);
const save=()=>fs.writeFileSync(path.join(root,base,'runtime-checks.json'),JSON.stringify(report,null,2)+'\n');
save();
const commands=[
  {name:'unit',command:'npm',args:['test'],log:`${base}/final-unit-tests.log`,outputs:[]},
  {name:'mirrored-rendering',command:process.execPath,args:['tests/track-mirror-browser.mjs'],
    log:`${base}/mirror-browser/final-bound-run.log`,outputs:[`${base}/mirror-browser/validation.json`]},
  {name:'player-return',command:process.execPath,args:['tests/player-rescue-safety-browser.mjs'],
    log:`${base}/rescue-browser/final-player-bound-run.log`,outputs:[`${base}/rescue-browser/player-rescue-safety-browser.json`]},
  {name:'environment-return',command:process.execPath,args:['tests/environment-rescue-browser.mjs'],
    log:`${base}/rescue-browser/final-environment-bound-run.log`,outputs:[`${base}/rescue-browser/environment-rescue-browser.json`]},
];
try{
  for(const command of commands){
    const before=runtime();
    assert.deepEqual(before,expected);
    const check={name:command.name,command:[command.command,...command.args],
      startedAt:new Date().toISOString(),runtimeBefore:before,
      testSources:Object.fromEntries(files('tests').map(file=>[file,sha(read(file))]))};
    report.checks.push(check);
    const fd=fs.openSync(path.join(root,command.log),'w');
    try{
      check.exitCode=await new Promise((resolve,reject)=>{
        const child=spawn(command.command,command.args,{cwd:root,stdio:['ignore',fd,fd],
          env:{...process.env,RCSK_RESCUE_OUTPUT:`${base}/rescue-browser`}});
        child.once('error',reject);child.once('exit',resolve);
      });
    }finally{fs.closeSync(fd);}
    check.completedAt=new Date().toISOString();
    check.runtimeAfter=runtime();
    check.log={file:command.log,sha256:sha(read(command.log))};
    check.outputs=command.outputs.map(file=>({file,sha256:sha(read(file))}));
    assert.deepEqual(check.runtimeAfter,before);
    assert.deepEqual(files('tests'),Object.keys(check.testSources),'test files changed during check');
    for(const [file,hash] of Object.entries(check.testSources))assert.equal(sha(read(file)),hash,file);
    assert.equal(check.exitCode,0,`${command.name}: see ${command.log}`);
    console.log(JSON.stringify({name:check.name,exitCode:check.exitCode,completedAt:check.completedAt}));
    save();
  }
  report.status='passed';
}catch(error){
  report.status='failed';report.error=error.stack;process.exitCode=1;
}finally{
  report.completedAt=new Date().toISOString();save();
}
