// Historical checkpoint verifier: the recorded src/ hashes and copy-layout
// assertions below belong to its frozen evidence snapshot, before source/ was
// separated from bundled runtime output. Use the matching historical checkout;
// do not regenerate these records as evidence of the current runtime.
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {fileURLToPath} from 'node:url';
import {execFileSync} from 'node:child_process';
import {nativeRaceSettings} from '../source/simulation/native-race.js';

const root=fileURLToPath(new URL('../',import.meta.url)),base='evidence/full-race-matrix';
const read=file=>fs.readFileSync(path.join(root,file));
const json=file=>JSON.parse(read(file));
const sha=data=>crypto.createHash('sha256').update(data).digest('hex');
const files=directory=>fs.readdirSync(path.join(root,directory),{withFileTypes:true})
  .flatMap(entry=>entry.isDirectory()?files(`${directory}/${entry.name}`):[`${directory}/${entry.name}`]).sort();
// An interim audit checks all existing evidence without calling incomplete
// race coverage a delivery pass or writing the final validation filename.
const auditCurrent=process.argv.includes('--audit-current');
execFileSync(process.execPath,['tools/verify-full-race-matrix.mjs',...(auditCurrent?[]:['--require-all'])],{cwd:root,stdio:'pipe'});
const matrix=json(`${base}/race-matrix.json`);
if(!auditCurrent)assert.equal(matrix.status,'all-72-completed');
assert.equal(matrix.counts.expected,72);
assert.equal(matrix.counts.completed+matrix.missing.length,72);
const checkpoint=json(`${base}/verified-runtime-checkpoint.json`).files;
assert.deepEqual(matrix.runtime,checkpoint,'race matrix and unit/browser runtime must match');
const before=json(`${base}/runtime-before.json`).files;
const changedRuntimeFiles=Object.keys(checkpoint).filter(file=>checkpoint[file]!==before[file]);
const copiedFiles=['index.html',...files('src'),...files('public/assets')];
for(const file of copiedFiles)
  assert.equal(sha(read(file)),sha(read('dist/'+file.replace(/^public\//,''))),file);
const unit=read(`${base}/final-unit-tests.log`).toString();
const tests=Number(unit.match(/ℹ tests (\d+)/)?.[1]);
assert.ok(tests>=492);
assert.match(unit,/ℹ fail 0/);
assert.equal(Number(unit.match(/ℹ pass (\d+)/)?.[1]),tests);
const boundChecks=json(`${base}/runtime-checks.json`);
assert.equal(boundChecks.status,'passed');
assert.deepEqual(boundChecks.runtime,checkpoint);
assert.deepEqual(boundChecks.checks.map(check=>check.name),
  ['unit','mirrored-rendering','player-return','environment-return']);
for(const check of boundChecks.checks){
  assert.equal(check.exitCode,0,check.name);
  assert.deepEqual(check.runtimeBefore,checkpoint,check.name);
  assert.deepEqual(check.runtimeAfter,checkpoint,check.name);
  assert.equal(sha(read(check.log.file)),check.log.sha256,check.log.file);
  for(const output of check.outputs)assert.equal(sha(read(output.file)),output.sha256,output.file);
  assert.deepEqual(files('tests'),Object.keys(check.testSources),'current test inventory must match the bound check');
  for(const [file,hash] of Object.entries(check.testSources))assert.equal(sha(read(file)),hash,file);
}
const browserFiles=[['mirror-browser/validation.json',4],
  ['rescue-browser/environment-rescue-browser.json',3],
  ['rescue-browser/player-rescue-safety-browser.json',4]];
const browsers=browserFiles.map(([name,expectedChecks])=>{
  const file=`${base}/${name}`,report=json(file);
  assert.equal(report.status,'passed',file);assert.deepEqual(report.errors,[],file);
  assert.ok(Array.isArray(report.checks),`${file}: recorded browser checks`);
  assert.equal(report.checks.length,expectedChecks,`${file}: complete browser cases`);
  return {file,sha256:sha(read(file)),checks:report.checks.length};
});
const assets=json(`${base}/original-asset-validation.json`);
assert.equal(assets.status,'passed');
const manifest=json('public/assets/manifest.json');
const nativePath=path.join(manifest.sourceInstallation,'data','rcskspel.dat');
const nativeHash=sha(fs.readFileSync(nativePath));
for(const file of ['evidence/native/cadence-quantization.json','evidence/native/upgrade-writer-audit.json'])
  assert.equal(json(file).sourceSha256,nativeHash,file);
const tables=json(`${base}/original-table-comparison.json`);
assert.equal(tables.files.length,6);
for(const entry of tables.files){
  assert.equal(entry.exact,true,entry.port);
  assert.equal(sha(read(entry.port)),entry.sha256,entry.port);
  assert.equal(sha(fs.readFileSync(entry.original)),entry.sha256,entry.original);
}
const timed=json(`${base}/timed-native-audit.json`);
assert.equal(timed.nativeSourceSha256,nativeHash);
assert.equal(timed.cases.length,18);
assert.equal(new Set(timed.cases.map(row=>`${row.track},${row.difficulty}`)).size,18);
for(const row of timed.cases){
  for(const [file,hash] of Object.entries(row.inputs))assert.equal(sha(read(file)),hash,file);
  const settings=nativeRaceSettings(json('public/assets/config.json'),row.track,row.difficulty,1);
  assert.equal(settings.lapLimit,row.lapLimit);
  assert.deepEqual(settings.gateTimes,[row.firstDeadlineMs,...row.repeatGateAdditionsMs]);
}
for(const file of ['native-track-mirror.json','normal-germany-native-rescue-overlap.json'])
  assert.equal(json(`${base}/${file}`).sourceSha256,nativeHash,file);
const overflow=json('evidence/native/ai-vertical-overflow.json');
assert.equal(overflow.summary.activeCapturedTransitions,119);
assert.equal(overflow.summary.activeTransitionMismatches,0);
assert.equal(overflow.summary.finalOriginalResult.bitsLE,'0000807f');
assert.equal(overflow.summary.normalSpringCalls,0);
assert.equal(overflow.summary.groundPreservationFailures,0);
assert.equal(sha(read(overflow.capture)),overflow.captureSha256);
const repaired=json(`${base}/timed-england-overflow-repaired.json`);
assert.deepEqual(repaired.sourceChangedDuringRun,[]);
assert.deepEqual(repaired.assetsChangedDuringRun,[]);
assert.equal(repaired.runs[0].events['npc-velocity-safety'],1);
assert.equal(repaired.runs[0].status,'time-expired');
// This whole-race reproduction predates the independently corrected startup
// reset. Its captured boundary is also exercised by the current composed
// unit regression; do not present its old trajectory as a current full race.
const overflowReplayCheckpoint=json(`${base}/pre-upgrade-reset/verified-runtime-checkpoint.json`).files;
for(const [file,hash] of Object.entries(overflowReplayCheckpoint))
  if(file!=='index.html')assert.equal(repaired.sourceAtStart[file],hash,file);
const startup=json('evidence/native/startup-upgrades.json');
assert.equal(startup.sourceSha256,nativeHash);
assert.equal(startup.cases.length,128);
assert.equal(startup.timerCases.length,72);
for(const c of startup.cases)
  assert.ok(Object.values(c.expected).every(value=>value===0));
for(const c of startup.timerCases)
  assert.equal(c.limits.afterConstruction[18],c.limits.loaded[18]);
const germanyTimed=json('evidence/native/germany-timed-success-audit.json');
assert.equal(germanyTimed.sourceSha256,nativeHash);
assert.equal(sha(read(germanyTimed.report)),germanyTimed.reportSha256);
assert.equal(sha(read(germanyTimed.track)),germanyTimed.trackSha256);
assert.equal(sha(read('public/assets/config.json')),germanyTimed.configSha256);
assert.equal(germanyTimed.summary.acceptedNativeCalls,16);
assert.equal(germanyTimed.summary.adjacentRejectedCalls,11);
assert.equal(germanyTimed.summary.nativeRemainingAtFinishMs,16625);
const nederlandTimed=json(`${base}/nl-authored-completion-audit.json`);
assert.equal(nederlandTimed.status,'passed');
assert.equal(sha(read(nederlandTimed.report)),nederlandTimed.reportSha256);
assert.equal(nederlandTimed.laps,5);
assert.equal(nederlandTimed.gates,15);
assert.equal(nederlandTimed.remainingMs,23825);
assert.equal(nederlandTimed.authoredBranch.originalLinkedEdges,46);
const nederlandCountdown=json(`${base}/nl-authored-countdown-audit.json`);
assert.equal(nederlandCountdown.status,'passed');
assert.equal(sha(read(nederlandCountdown.report)),nederlandCountdown.reportSha256);
assert.equal(nederlandCountdown.laps,5);
assert.equal(nederlandCountdown.gates,15);
assert.equal(nederlandCountdown.wallMs-nederlandCountdown.greenWallMs,nederlandCountdown.elapsedMs);
assert.equal(nederlandCountdown.firstDriverInputWallMs,nederlandCountdown.greenWallMs+25);
assert.equal(nederlandCountdown.remainingMs,23025);
assert.equal(nederlandCountdown.npcVelocitySafetyEvents,1);
const report={
  format:'superkarts-full-race-delivery-v1',
  status:matrix.missing.length?'incomplete-race-coverage':'passed',
  verifiedAt:new Date().toISOString(),missing:matrix.missing,
  scope:matrix.scope,counts:matrix.counts,matrix:{file:`${base}/race-matrix.json`,
    sha256:sha(read(`${base}/race-matrix.json`))},runtime:checkpoint,changedRuntimeFiles,
  unitTests:{passed:tests,failed:0,file:`${base}/final-unit-tests.log`},browserTests:browsers,
  runtimeCheckProvenance:{file:`${base}/runtime-checks.json`,sha256:sha(read(`${base}/runtime-checks.json`))},
  originalAssets:{file:`${base}/original-asset-validation.json`,checks:assets.checks,
    movies:Object.keys(assets.movies).length},
  nativeEvidence:{originalExecutable:nativePath,sha256:nativeHash,
    projectionCases:json(`${base}/native-track-mirror.json`).cases.length,
    mirrorREA:`${base}/native-mirror-setup-rea.json`,
    npcReturnOverlap:`${base}/normal-germany-native-rescue-overlap.json`,
    npcVelocityOverflow:'evidence/native/ai-vertical-overflow.json',
    repairedOverflowReplay:`${base}/timed-england-overflow-repaired.json`,
    repairedOverflowReplayScope:'Historical pre-constructor-reset trajectory; current composed boundary regression is included in the unit suite.',
    playerInitialization:'evidence/native/startup-upgrades.json',
    initializationWriterAudit:'evidence/native/upgrade-writer-audit.json',
    frameCadence:'evidence/native/cadence-quantization.json',
    difficultyTables:`${base}/original-table-comparison.json`,
    timeGates:`${base}/timed-native-audit.json`,
    germanyTimedAwards:'evidence/native/germany-timed-success-audit.json',
    nederlandTimedRoute:`${base}/nl-authored-completion-audit.json`,
    nederlandTimedCountdown:`${base}/nl-authored-countdown-audit.json`},
  build:{copiedFilesVerified:copiedFiles.length,totalFiles:files('dist').length,log:`${base}/build.log`},
  restoredNativeBehavior:'England, France and Italy now reflect the race world and camera-relative effects, and reverse player input using the original MAPS flag. The original constructor clears loaded upgrade flags before player physics, shared NPC steering and timer setup; active motor, tire and gearbox indices start at zero. Original time-trial budgets and table bytes are unchanged.',
  deliberateDeviation:'The prior player rescue safeguard remains. In addition, an opponent waits at its original rescue destination if its rectangle would overlap the player; full-size growth is rechecked. Opponent/opponent native clearance is retained. A separately reproduced original hard-mode catchup overflow is stopped by resetting only a linear velocity component that changes from finite to nonfinite during NPC preparation. Every finite result, original native kernel, AI state, race deadline and progress rule is retained. No opponent is teleported to a different return and no blockers are moved.',
  limits:matrix.limitations,
};
fs.writeFileSync(path.join(root,base,auditCurrent?'interim-validation.json':'validation.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({status:report.status,...report.counts,tests,build:report.build}));
