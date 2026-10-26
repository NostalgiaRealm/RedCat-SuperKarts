import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';
import {nativeAdventureQualification} from '../source/simulation/native-adventure.js';
import {nativeRaceSettings} from '../source/simulation/native-race.js';

const root=fileURLToPath(new URL('../',import.meta.url));
const base='evidence/full-race-matrix';
const read=file=>fs.readFileSync(path.join(root,file));
const json=file=>JSON.parse(read(file));
const sha=bytes=>crypto.createHash('sha256').update(bytes).digest('hex');
const digest=file=>sha(read(file));
const files=directory=>fs.readdirSync(path.join(root,directory),{withFileTypes:true})
  .flatMap(entry=>entry.isDirectory()?files(`${directory}/${entry.name}`):[`${directory}/${entry.name}`]).sort();
// Compare authored modules, not generated bundles: the headless driving harness
// executes source/ directly. Older src/ evidence intentionally fails this check.
const runtime=Object.fromEntries(files('source').map(file=>[file,digest(file)]));
const config=json('public/assets/config.json');
const candidates=new Map(),attempts=[],rejectedReports=[];
for(const file of files(base).filter(file=>file.endsWith('.json'))){
  let report;
  try{report=json(file);}catch{continue;}
  if(report.format!=='superkarts-control-only-races-v1'||!report.completedAt)continue;
  const source=report.sourceAtStart??{};
  const changedRuntime=Object.keys(runtime).filter(file=>file!=='index.html'&&source[file]!==runtime[file]);
  const changedTest=Object.keys(source).filter(file=>!file.startsWith('source/'))
    .filter(file=>!fs.existsSync(path.join(root,file))||digest(file)!==source[file]);
  const changedAssets=Object.entries(report.assetSha256??{})
    .filter(([file,hash])=>digest(`public/assets/${file}`)!==hash).map(([file])=>file);
  const isSha256=value=>typeof value==='string'&&/^[0-9a-f]{64}$/.test(value);
  const requiredAssets=new Set(['config.json','manifest.json','cars.json',
    ...report.runs.flatMap(run=>[`tracks/etappe${run.track}.json`,
      `physics/phys${run.difficulty}.dat`,`racer-tables/cars${run.difficulty}.dat`])]);
  const missingAssetHashes=[...requiredAssets]
    .filter(file=>!isSha256(report.assetSha256?.[file]));
  const missingDependencyHashes=Array.isArray(report.executionDependencies)
    &&report.executionDependencies.length
    ?report.executionDependencies.filter(file=>!isSha256(source[file]))
    :['<executionDependencies>'];
  const invalidInputHashes=report.runs.flatMap((run,index)=>
    isSha256(run.inputSha256)?[]:[index]);
  // A normalized selection must still point to the exact recorded run.
  const changedSourceReport=report.sourceReport
    &&(!fs.existsSync(path.join(root,report.sourceReport))
      ||digest(report.sourceReport)!==report.sourceReportSha256);
  const changedExporter=report.exportTool
    &&(!fs.existsSync(path.join(root,report.exportTool))
      ||digest(report.exportTool)!==report.exportToolSha256);
  let changedExportedRun=false;
  if(report.sourceReport&&!changedSourceReport){
    const original=json(report.sourceReport);
    if(original.format===report.format){
      changedExportedRun=!Number.isInteger(report.sourceRunIndex)||report.runs.length!==1
        ||JSON.stringify(original.runs?.[report.sourceRunIndex])!==JSON.stringify(report.runs[0])
        ||JSON.stringify(original.sourceAtStart)!==JSON.stringify(source);
    }
  }
  const missingRecordedCounters=report.runs.some(run=>
    !Number.isInteger(run.opponents)||!run.events||!Array.isArray(run.lapEvents));
  // These deterministic driving records use a 25 ms reference cadence. The
  // game's native-style update gate can use longer elapsed steps while rendering
  // stays unlocked; this fixed-step evidence does not prove every browser cadence.
  const differentCadence=report.cadenceMs!==25;
  const valid=changedRuntime.length===0&&changedTest.length===0&&changedAssets.length===0
    &&missingAssetHashes.length===0&&missingDependencyHashes.length===0&&invalidInputHashes.length===0
    &&!changedSourceReport&&!changedExporter&&!changedExportedRun&&!missingRecordedCounters&&!differentCadence
    &&report.sourceChangedDuringRun?.length===0&&report.assetsChangedDuringRun?.length===0;
  if(!valid)rejectedReports.push({file,changedRuntime,changedTest,changedAssets,
    missingAssetHashes,missingDependencyHashes,invalidInputHashes,
    changedSourceReport:Boolean(changedSourceReport),
    changedExporter:Boolean(changedExporter),changedExportedRun,
    missingRecordedCounters,differentCadence,cadenceMs:report.cadenceMs,
    sourceChangedDuringRun:report.sourceChangedDuringRun,assetsChangedDuringRun:report.assetsChangedDuringRun});
  report.runs.forEach((run,index)=>{
    const key=[run.track,run.difficulty,run.raceMode].join(',');
    attempts.push({file,index,key,status:run.status,lapCount:run.race?.lapCount,
      stars:run.stars,rank:run.rank,qualified:run.qualification?.qualified,currentSourceAndAssets:valid});
    if(!valid)return;
    assert.equal(run.opponents,[4,3,3,1][run.raceMode],`${file}: original roster`);
    assert.deepEqual(run.qualification,nativeAdventureQualification(
      {difficulty:run.difficulty,raceType:run.raceMode},
      {rank:run.rank,finished:run.race.finished,stars:run.stars}),`${file}: original qualification`);
    if(run.status!=='finished'||run.race.finished!==true||run.race.lapCount!==5)return;
    assert.deepEqual(run.lapEvents.map(event=>event.lap),[1,2,3,4,5],file);
    assert.equal(run.events.finished,1,file);
    assert.equal(run.race.lapTimes.reduce((sum,time)=>sum+time,0),run.race.raceTimeMs,file);
    if(run.raceMode===1){
      assert.ok(run.race.remainingMs>=0,file);
      const settings=nativeRaceSettings(config,run.track,run.difficulty,run.raceMode);
      // Original progress/gate handling can revisit a checkpoint after a
      // detour or rescue. Validate its actual cyclic awards and clock balance,
      // rather than inventing an exact gates-per-lap invariant.
      assert.ok(run.gateEvents.length>=settings.gateTimes.length-1,file);
      for(const [index,event] of run.gateEvents.entries()){
        assert.equal(event.index,index%(settings.gateTimes.length-1)+1,file);
        assert.equal(event.additionalMs,settings.gateTimes[event.index],file);
      }
      assert.equal(run.race.remainingMs,settings.gateTimes[0]
        +run.gateEvents.reduce((sum,event)=>sum+event.additionalMs,0)-run.race.elapsedMs,file);
    }
    if(run.raceMode===2){
      if(run.stars!==12)return;
      assert.equal(new Set(run.pickupEvents.filter(event=>event.type==='star').map(event=>event.pickup)).size,12,file);
    }
    const authoredOpening=Number.isFinite(run.opening?.countdownStartWallMs)
      &&run.opening.countdownStartWallMs>0
      &&Number.isFinite(run.opening.greenWallMs)
      &&run.opening.greenWallMs>run.opening.countdownStartWallMs
      &&run.opening.firstDriverInputWallMs===run.opening.greenWallMs+25;
    if(authoredOpening){
      assert.equal(run.opening.greenRace.elapsedMs,0,`${file}: active clock at green`);
      assert.equal(run.durationMs-run.opening.greenWallMs,run.activeElapsedMs,`${file}: wall/green clock`);
      assert.equal(run.activeElapsedMs,run.race.elapsedMs,`${file}: recorded active clock`);
      assert.equal(run.race.elapsedMs,run.race.raceTimeMs,`${file}: finished active race time`);
    }
    const result={file,index,key,track:run.track,difficulty:run.difficulty,raceMode:run.raceMode,
      character:report.character,constructionSeed:report.constructionSeed,gameplaySeed:report.gameplaySeed,
      cadenceMs:report.cadenceMs,
      driverOptions:report.driverOptions,seekStars:report.seekStars,fireHeld:report.fireHeld,
      testDriverPolicy:report.testDriverPolicy,laneOrder:report.laneOrder,
      laneSchedule:report.laneSchedule,waypointSchedule:report.waypointSchedule,
      profiles:report.profiles,speedPenalty:report.speedPenalty,
      durationMs:run.durationMs,activeRaceTimeMs:run.race.raceTimeMs,
      authoredOpening,startPolicy:report.startPolicy,opening:run.opening,
      rank:run.rank,stars:run.stars,qualified:run.qualification.qualified,
      qualification:run.qualification,lapTimes:run.race.lapTimes,rescue:run.rescue,
      npcVelocitySafetyEvents:run.events['npc-velocity-safety']??0,
      inputSha256:run.inputSha256,reportSha256:digest(file),
      sourceAtStart:source,assetSha256:report.assetSha256};
    const previous=candidates.get(key);
    // Prefer complete authored startup when qualification is equal, then
    // compare actual race times rather than mixing wall and active time.
    if(!previous||Number(result.qualified)>Number(previous.qualified)
      ||result.qualified===previous.qualified&&(
        Number(result.authoredOpening)>Number(previous.authoredOpening)
        ||result.authoredOpening===previous.authoredOpening
          &&result.activeRaceTimeMs<previous.activeRaceTimeMs))candidates.set(key,result);
  });
}
const expected=Array.from({length:72},(_,index)=>{
  const track=index%6,difficulty=Math.floor(index/6)%3,raceMode=Math.floor(index/18);
  return [track,difficulty,raceMode].join(',');
});
const missing=expected.filter(key=>!candidates.has(key));
const races=expected.flatMap(key=>candidates.has(key)?[candidates.get(key)]:[]);
const report={format:'superkarts-full-race-matrix-v1',status:missing.length?'incomplete':'all-72-completed',
  verifiedAt:new Date().toISOString(),
  scope:'Six tracks, three difficulties and four active race modes. Ordinary analog controls only; each accepted case physically completes five laps. Star cases collect twelve distinct stars and timed cases retain original deadlines and gate awards. Finishing and native Adventure qualification are reported separately. Different recorded controller policies, original playable characters and startup seeds are permitted. No pose, timer, pickup, lap or physics-table writes are allowed by the driving harness.',
  runtime,selectionPolicy:'Prefer qualification, then recorded authored opening/countdown, then lower active race time.',
  counts:{expected:72,completed:races.length,qualified:races.filter(run=>run.qualified).length,
    authoredOpening:races.filter(run=>run.authoredOpening).length,
    activeGrid:races.filter(run=>!run.authoredOpening).length,
    npcVelocitySafetyEvents:races.reduce((sum,run)=>sum+run.npcVelocitySafetyEvents,0),
    byMode:[0,1,2,3].map(mode=>({mode,completed:races.filter(run=>run.raceMode===mode).length,
      qualified:races.filter(run=>run.raceMode===mode&&run.qualified).length}))},
  missing,races,attempts,rejectedReports,
  limitations:['These are composed-port full races, not original Windows full-process trajectory or framebuffer comparisons.',
    'Full-race qualification is distinct from finishing; losing to an original opponent does not justify weakening that opponent.',
    'This matrix does not claim all characters, all seeds, all input devices or an uninterrupted Adventure campaign.']};
fs.writeFileSync(path.join(root,base,'race-matrix.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({status:report.status,...report.counts,missing}));
if(process.argv.includes('--require-all'))assert.equal(missing.length,0,'full-race matrix remains incomplete');
