import fs from 'node:fs';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS} from '../src/simulation/clock.js';
import {RouteTestDriver} from '../tests/helpers/route-test-driver.mjs';

const root=new URL('../',import.meta.url);
const hash=bytes=>crypto.createHash('sha256').update(bytes).digest('hex');
const read=path=>fs.readFileSync(new URL(path,root));
const json=path=>JSON.parse(read(path));
const retained=json('evidence/full-race-matrix/normal-d1-baseline.json');
const baseline=retained.runs.find(run=>run.track===1);
const assetHashes={};
const asset=path=>{
  const bytes=read(`public/assets/${path}`);
  assetHashes[path]=hash(bytes);
  return bytes;
};
const assetJSON=path=>JSON.parse(asset(path));
const sourceChanges=()=>Object.entries(retained.sourceAtStart)
  .filter(([path,expected])=>hash(read(path))!==expected).map(([path])=>path);
assert.deepEqual(sourceChanges(),[]);
const random=new NativeRandom(0),track=assetJSON('tracks/etappe1.json');
const simulation=new RaceSimulation({
  config:assetJSON('config.json'),manifest:assetJSON('manifest.json'),cars:assetJSON('cars.json'),
  track,physicsBytes:asset('physics/phys1.dat'),
  racerBytes:asset('racer-tables/cars1.dat'),random,
  character:0,difficulty:1,raceMode:0,
});
random.seed(0);
const driver=new RouteTestDriver(track,{
  railBounds:simulation.motion.collision.bounds,
  obstacles:simulation.physicalBodies.filter(body=>body!==simulation.motion.body),
});
const filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
const inputHash=crypto.createHash('sha256'),samples=[],approach=[];
const pose=body=>({id:body.id,position:[...body.position],yaw:body.yaw,pitch:body.pitch,roll:body.roll,
  matrix:body.matrix&&[...body.matrix],sector:body.sector,waypoint:body.waypoint,
  forwardSpeed:body.forwardSpeed,lateralSpeed:body.lateralSpeed,verticalSpeed:body.verticalSpeed,
  yawRate:body.yawRate,mesh:body.mesh,placementIndex:body.placementIndex});
for(let now=25;now<=100000;now+=25){
  const input=driver.input(simulation.motion.body,now,25);
  inputHash.update(JSON.stringify(input)+'\n');
  simulation.step(input,filter.sample(.025),now);
  for(const actor of simulation.actors)if(actor.animationEvents)actor.animationEvents.length=0;
  if(now%10000===0){
    const reference=baseline.samples.find(sample=>sample.timeMs===now);
    assert.deepEqual(simulation.motion.body.position,reference.position);
    assert.equal(simulation.motion.body.yaw,reference.yaw);
    assert.equal(simulation.motion.body.forwardSpeed,reference.speed);
    samples.push({now,position:[...simulation.motion.body.position],matchedRetainedSample:true});
  }
  if(now>=73000&&now<=80000&&now%250===0)
    approach.push({now,actors:simulation.actors.map(actor=>pose(actor.body)),
      rescue:simulation.rescue.entries.map(entry=>({id:entry.body.id,frame:entry.frame,
        shrinking:entry.shrinking,finished:entry.finished,destination:entry.destination}))});
}
const body=simulation.motion.body,collision=simulation.motion.collision;
const contactInfo=contact=>contact&&({point:contact.point,normal:contact.normal,
  first:contact.firstBody&&pose(contact.firstBody),second:contact.secondBody&&pose(contact.secondBody)});
const queries=[];
for(const yaw of[body.yaw,...Array.from({length:8},(_,i)=>i*512)]){
  for(const forwardSpeed of[-10,10]){
    const result=collision.sweep({...body,sourceBody:body,position:[...body.position],
      yaw,forwardSpeed,lateralSpeed:0,verticalSpeed:0,yawRate:0},.2);
    queries.push({yaw,forwardSpeed,fraction:result.fraction,stopYaw:result.stopYaw,
      contact:contactInfo(result.contact)});
  }
}
const report={
  scope:'Control-only 100-second prefix replay, exactly matching all ten retained baseline samples. '+
    'After replay, synthetic read-only sweep queries inspect the captured contact. No race pose, '+
    'velocity, timer, trigger, pickup, or physics table was altered.',
  baseline:'evidence/full-race-matrix/normal-d1-baseline.json',
  sourceAtStart:retained.sourceAtStart,sourceChangedDuringRun:sourceChanges(),assetHashes,
  diagnosticSha256:hash(fs.readFileSync(new URL(import.meta.url))),
  inputSha256:inputHash.digest('hex'),samples,approach,
  actors:simulation.actors.map(actor=>pose(actor.body)),
  player:simulation.motion.snapshot(),queries,
};
assert.deepEqual(report.sourceChangedDuringRun,[]);
fs.writeFileSync(new URL('evidence/full-race-matrix/normal-germany-medium-contact.json',root),
  JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({prefixSamples:samples.length,player:pose(body),
  queries:queries.slice(0,2),sourceChanges:report.sourceChangedDuringRun},null,2));
