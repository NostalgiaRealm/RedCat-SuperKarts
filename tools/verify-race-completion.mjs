import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';

const root=fileURLToPath(new URL('../',import.meta.url));
const read=file=>fs.readFileSync(path.join(root,file));
const json=file=>JSON.parse(read(file));
const sha=bytes=>crypto.createHash('sha256').update(bytes).digest('hex');
const files=directory=>fs.readdirSync(path.join(root,directory),{withFileTypes:true})
  .flatMap(entry=>entry.isDirectory()?files(`${directory}/${entry.name}`):[`${directory}/${entry.name}`]).sort();
const base='evidence/race-completion/';
const results=['germany','france','italy'].map((name,index)=>{
  const file=`${base}final-${name}.json`,report=json(file),run=report.runs[0];
  assert.equal(report.status,'all-finished',name);
  assert.deepEqual(report.sourceChangedDuringRun,[],name);
  assert.equal(report.runs.length,1,name);
  assert.deepEqual([run.track,run.difficulty,run.raceMode],[index*2+1,0,0]);
  assert.equal(run.opponents,4);
  assert.equal(run.status,'finished');
  assert.equal(run.race.finished,true);
  assert.equal(run.race.lapCount,5);
  assert.deepEqual(run.lapEvents.map(event=>event.lap),[1,2,3,4,5]);
  assert.equal(run.events.finished,1);
  for(const [file,digest] of Object.entries(report.sourceAtStart))assert.equal(sha(read(file)),digest,file);
  return {name,file,sha256:sha(read(file)),source:report.sourceAtStart,
    durationMs:run.durationMs,lapTimes:run.race.lapTimes,rank:run.rank,
    qualified:run.qualification.qualified,inputSha256:run.inputSha256};
});
for(const result of results)assert.deepEqual(result.source,results[0].source,'all three use the same frozen source');
const runtime=Object.fromEntries(['index.html',...files('src')].map(file=>[file,sha(read(file))]));
const before=json(`${base}runtime-before.json`).files;
const changedRuntimeFiles=Object.keys(runtime).filter(file=>runtime[file]!==before[file]);
const buildFiles=['index.html',...files('src'),...files('public/assets')];
for(const file of buildFiles){
  const destination='dist/'+file.replace(/^public\//,'');
  assert.equal(sha(read(file)),sha(read(destination)),destination);
}
const unitLog=read(`${base}final-unit-tests.log`).toString();
const testCount=Number(unitLog.match(/ℹ tests (\d+)/)?.[1]);
assert.ok(testCount>=440);
assert.match(unitLog,/ℹ fail 0/);
assert.equal(Number(unitLog.match(/ℹ pass (\d+)/)?.[1]),testCount);
const browsers=['player-rescue-safety-browser','environment-rescue-browser'].map(name=>{
  const file=`${base}rescue-browser/${name}.json`,report=json(file);
  assert.equal(report.status,'passed');
  assert.deepEqual(report.errors,[]);
  return {file,sha256:sha(read(file)),checks:report.checks.length};
});
const jump=json(`${base}france-native-jump-fixtures.json`);
const contact=json(`${base}france-native-frame-comparison.json`);
assert.equal(contact.status,'active-precision-exact');
const report={
  format:'superkarts-three-course-completion-v1',status:'passed',completedAt:new Date().toISOString(),
  scope:'Three easy normal five-lap races, character0, four opponents, original seed0 and ordinary analog controls. Native jump/direction corrections and the user-authorized player rescue safeguard are active. No forced finish, position, timer or pickup writes occur in these driven checks. Browser rescue tests use explicitly controlled starting fixtures.',
  races:results.map(({source,...result})=>result),
  sourceAtValidation:runtime,changedRuntimeFiles,
  unitTests:{passed:testCount,failed:0,log:`${base}final-unit-tests.log`},
  browserTests:browsers,
  nativeEvidence:{sourceSha256:jump.sourceSha256,jumpCallbacks:jump.cases.length,
    registeredJumpCrossings:jump.crossings.length,integerLoadCases:jump.loads.length,
    contactFrames:contact.byPrecision,italyRescueClearanceCases:json(`${base}italy-native-rescue.json`).cases.length},
  build:{copiedFilesVerified:buildFiles.length,totalFiles:files('dist').length,log:`${base}build.log`},
  deliberateDeviation:'Player rescue rejects full rectangle overlaps. After two seconds blocked, it searches supported, unoccupied authored road positions within12sectors behind the original return. Fallback resets wheel support and angular motion; clearance is rechecked before growth completes. Opponent native rescue logic is retained.',
  limits:['Full original Windows race rendering/audio/trajectory parity is not established; WineD3D is unsuitable.',
    'The53-bit contact probe retains rounding differences; the port uses the exactly matched24-bit path.',
    'This is the requested three-course easy normal-race check, not a new all-difficulty/all-mode or uninterrupted24-stage Adventure matrix.'],
};
fs.writeFileSync(path.join(root,base,'validation.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({status:report.status,races:report.races.map(({name,durationMs,rank})=>({name,durationMs,rank})),
  tests:testCount,build:report.build},null,2));
