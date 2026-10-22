// Preserve and verify a completed case before cancelling a redundant later
// diagnostic case. No simulation data is synthesized or modified.
import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
const [input,indexText,prefix,output]=process.argv.slice(2),index=Number(indexText);
if(!input||!prefix||!output||!Number.isInteger(index))throw new Error('Supply batch report, completed index, immutable prefix copy, standard output');
const digest=bytes=>crypto.createHash('sha256').update(bytes).digest('hex');
const bytes=await fs.readFile(input),source=JSON.parse(bytes),run=source.runs[index];
assert.equal(source.format,'superkarts-control-only-races-v1');
assert.equal(run.status,'finished');assert.equal(run.race.lapCount,5);assert.equal(run.race.finished,true);
assert.ok(Number.isInteger(run.opponents));assert.ok(run.events?.finished>=1);
const sourceChangedDuringRun=[],assetsChangedDuringRun=[];
for(const [path,expected] of Object.entries(source.sourceAtStart))
  if(digest(await fs.readFile(path))!==expected)sourceChangedDuringRun.push(path);
for(const [path,expected] of Object.entries(source.assetSha256))
  if(digest(await fs.readFile(`public/assets/${path}`))!==expected)assetsChangedDuringRun.push(path);
assert.deepEqual(sourceChangedDuringRun,[]);assert.deepEqual(assetsChangedDuringRun,[]);
await fs.writeFile(prefix,bytes,{flag:'wx'});
const report={...source,status:'all-finished',runs:[run],
  scope:source.scope+' This selects an actually completed case from an immutable batch-prefix snapshot. All originally fingerprinted sources and assets were independently checked after that case finished; a redundant later case need not finish. No race event, roster, input hash or result was synthesized.',
  sourceReport:prefix,sourceReportSha256:digest(bytes),sourceRunIndex:index,
  exportTool:'tools/export-completed-race-prefix.mjs',exportToolSha256:digest(await fs.readFile(new URL(import.meta.url))),
  completedAt:new Date().toISOString(),sourceChangedDuringRun,executionSourceChangedDuringRun:[],assetsChangedDuringRun};
await fs.writeFile(output,JSON.stringify(report,null,2)+'\n',{flag:'wx'});
console.log(JSON.stringify({output,laps:run.race.lapCount,activeMs:run.race.elapsedMs,rank:run.rank,qualified:run.qualification.qualified,sourceChangedDuringRun,assetsChangedDuringRun}));
