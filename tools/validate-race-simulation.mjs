import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS} from '../source/simulation/clock.js';
import {validationSourceDependencies} from './validation-source-dependencies.mjs';

const assets=new URL('../public/assets/',import.meta.url);
const read=file=>fs.readFile(new URL(file,assets));
const json=async file=>JSON.parse(await read(file));
const project=new URL('../',import.meta.url);
const output=new URL(process.env.RCSK_SIM_REPORT??'evidence/native/race-simulation-endurance.json',project);
async function sourceSnapshot(){
  const paths=['tools/validate-race-simulation.mjs','tools/validation-source-dependencies.mjs'];
  async function visit(directory){
    for(const entry of await fs.readdir(new URL(directory,project),{withFileTypes:true})){
      const path=`${directory}/${entry.name}`;
      if(entry.isDirectory())await visit(path);else if(entry.isFile())paths.push(path);
    }
  }
  await visit('source');
  return Object.fromEntries(await Promise.all(paths.sort().map(async path=>
    [path,crypto.createHash('sha256').update(await fs.readFile(new URL(path,project))).digest('hex')])));
}
const sourceAtStart=await sourceSnapshot();
const executionDependencies=await validationSourceDependencies(new URL(import.meta.url),project);
const sourceGuard=process.env.RCSK_SOURCE_SCOPE==='execution'?'execution-dependencies':'all-source';
const [config,manifest,cars]=await Promise.all(['config.json','manifest.json','cars.json'].map(json));
const duration=Number(process.env.RCSK_SIM_DURATION_MS??300000);
const report={scope:'Composed JavaScript race; stationary player, four original opponents, original kernels at the documented 25ms reference cadence. Not an original full-process replay.',
  durationMs:duration,constructionSeed:0,gameplaySeed:0,sourceAtStart,sourceGuard,executionDependencies,
  startedAt:new Date().toISOString(),host:process.version,runs:[]};
let failures=0;
for(let difficulty=0;difficulty<3;difficulty++)for(let trackIndex=0;trackIndex<6;trackIndex++){
  const [track,physicsBytes,racerBytes]=await Promise.all([
    json(`tracks/etappe${trackIndex}.json`),read(`physics/phys${difficulty}.dat`),read(`racer-tables/cars${difficulty}.dat`),
  ]);
  const random=new NativeRandom(0);
  const simulation=new RaceSimulation({config,manifest,cars,track,physicsBytes,racerBytes,
    random,difficulty,character:trackIndex%4});
  random.seed(0);
  const run={track:trackIndex,difficulty,status:'passed',states:{},events:{},samples:[]};
  const filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
  let now=25;
  try{
    for(;now<=duration;now+=25){
      const events=simulation.step({throttle:0,brake:0,steer:0,handbrake:0,bonus:0},filter.sample(.025),now);
      for(const actor of simulation.actors)if(![...actor.body.position,actor.body.yaw,
        actor.body.forwardSpeed,actor.body.lateralSpeed,actor.body.verticalSpeed].every(Number.isFinite))
        throw new Error(`Nonfinite actor${actor.body.id}`);
      for(const actor of simulation.opponents)run.states[actor.phase]=(run.states[actor.phase]??0)+1;
      for(const event of events)if(event.type)run.events[event.type]=(run.events[event.type]??0)+1;
      // The renderer normally consumes these once per simulation update.
      for(const actor of simulation.actors)if(actor.animationEvents)actor.animationEvents.length=0;
      if(now%10000===0)run.samples.push({timeMs:now,opponents:simulation.opponents.map((actor,index)=>({
        sector:actor.body.sector,position:[...actor.body.position],speed:actor.body.forwardSpeed,
        progress:actor.progress.distance,mode:actor.phase,laps:actor.state.laps,
        rank:simulation.rankStates[index].rank,finished:simulation.rankStates[index].finished,
        finishTimeMs:simulation.rankStates[index].finishTimeMs,
      }))});
    }
  }catch(error){
    run.status='failed';run.timeMs=now;run.error=error.stack;
    run.actors=simulation.actors.map(actor=>({body:actor.body,state:actor.state,path:actor.path}));
    failures++;
  }
  report.runs.push(run);
  console.log(`track${trackIndex}, difficulty${difficulty}: ${run.status} (${now-25}ms)`);
  await fs.writeFile(output,JSON.stringify(report,null,2)+'\n');
}
report.status=failures?'failed':'passed';
const sourceAtEnd=await sourceSnapshot();
report.sourceChangedDuringRun=[...new Set([...Object.keys(sourceAtStart),...Object.keys(sourceAtEnd)])]
  .filter(path=>sourceAtStart[path]!==sourceAtEnd[path]);
report.executionSourceChangedDuringRun=report.sourceChangedDuringRun.filter(path=>executionDependencies.includes(path));
const relevantChanges=sourceGuard==='execution-dependencies'?report.executionSourceChangedDuringRun:report.sourceChangedDuringRun;
if(relevantChanges.length)report.status='source-changed';
report.completedAt=new Date().toISOString();
await fs.writeFile(output,JSON.stringify(report,null,2)+'\n');
if(failures||relevantChanges.length)process.exitCode=1;
