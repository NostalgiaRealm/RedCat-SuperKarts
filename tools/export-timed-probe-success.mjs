import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
const [input,indexText,output]=process.argv.slice(2),index=Number(indexText);
if(!input||!output||!Number.isInteger(index))throw new Error('Supply source report, run index and new report path');
const bytes=await fs.readFile(input),source=JSON.parse(bytes),run=source.runs[index];
assert.equal(source.format,'superkarts-control-only-timed-policy-v1');
assert.deepEqual(source.sourceChangedDuringRun,[]);assert.deepEqual(source.assetsChangedDuringRun,[]);
assert.equal(run.status,'finished');assert.equal(run.race.lapCount,5);assert.equal(run.race.finished,true);
assert.ok(Number.isInteger(run.opponents));assert.ok(run.events?.finished>=1);
const spec=run.spec;
const report={format:'superkarts-control-only-races-v1',status:'all-finished',
  scope:source.scope+' This report selects one successful run from the linked immutable probe report; it does not rerun or modify the simulation.',
  sourceReport:input,sourceReportSha256:crypto.createHash('sha256').update(bytes).digest('hex'),sourceRunIndex:index,
  startedAt:source.startedAt,completedAt:source.completedAt,sourceAtStart:source.sourceAtStart,
  sourceGuard:'all-source',sourceChangedDuringRun:[],assetsChangedDuringRun:[],assetSha256:source.assetSha256,
  cadenceMs:25,character:spec.character??1,constructionSeed:spec.constructionSeed??0,gameplaySeed:spec.seed??0,
  driverOptions:{...spec.options,obstacleAvoidance:false,slipGain:spec.slipGain??0},laneOrder:spec.laneOrder,
  waypointSchedule:spec.waypointSchedule??[],projectedRoadProgress:Boolean(spec.projected),
  speedPenalty:spec.speedPenalty??2,profiles:spec.profiles??[],seekStars:false,fireHeld:false,maxMs:spec.maxMs??900000,
  testDriverPolicy:'Recorded private analog controller with authored road-link priorities, sector profiles, optional lateral-slip steering compensation and heading-error speed penalty; all game state remains controlled by the unchanged runtime.',
  runs:[{...run,track:spec.track,difficulty:spec.difficulty,raceMode:1,stars:0,
    gateEvents:run.gates,finalPosition:run.player.position}]};
await fs.writeFile(output,JSON.stringify(report,null,2)+'\n',{flag:'wx'});
console.log(output);
