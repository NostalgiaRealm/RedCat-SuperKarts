import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS} from '../src/simulation/clock.js';
import {RouteTestDriver} from '../tests/helpers/route-test-driver.mjs';
import {nativeAdventureQualification} from '../src/simulation/native-adventure.js';

const root=new URL('../',import.meta.url),hash=b=>crypto.createHash('sha256').update(b).digest('hex');
const planPath=process.argv[2],output=process.argv[3];
if(!planPath||!output)throw new Error('Supply a probe plan JSON path and a separate report path');
const read=path=>fs.readFile(new URL(path,root));
const planBytes=await read(planPath),plan=JSON.parse(planBytes),assetSha256={};
async function asset(path){
  const bytes=await read(`public/assets/${path}`);assetSha256[path]=hash(bytes);return bytes;
}
const json=async path=>JSON.parse(await asset(path));
async function sourceSnapshot(){
  const paths=['tools/native-blockage-germany-npc-line.mjs','tools/timed-de-uk-slip-corridors.mjs','tools/timed-de-uk-slip-probe.mjs','tools/timed-de-uk-instrumented-probe.mjs','tools/timed-de-uk-probe.mjs','tools/validate-driven-races.mjs',
    'tests/helpers/route-test-driver.mjs','tests/helpers/star-approach-planner.mjs',planPath];
  async function visit(path){
    for(const entry of await fs.readdir(new URL(path,root),{withFileTypes:true})){
      const name=`${path}/${entry.name}`;
      if(entry.isDirectory())await visit(name);else if(entry.isFile())paths.push(name);
    }
  }
  await visit('src');
  return Object.fromEntries(await Promise.all(paths.sort().map(async path=>[path,hash(await read(path))])));
}
const sourceAtStart=await sourceSnapshot();
const [config,manifest,cars]=await Promise.all(['config.json','manifest.json','cars.json'].map(json));
const report={format:'superkarts-control-only-timed-policy-v1',
  scope:'Original timed race, controlled only by ordinary analog inputs. The private test policy '+
    'may select authored road links, change its own speed/lookahead by current sector, or change '+
    'its heading-error speed penalty. No game poses, velocities, physics, pickups, triggers, '+
    'timers, or race limits are written. This is not an original Windows process comparison.',
  startedAt:new Date().toISOString(),sourceAtStart,assetSha256,planSha256:hash(planBytes),runs:[]};
const save=()=>fs.writeFile(new URL(output,root),JSON.stringify(report,null,2)+'\n');
for(const spec of plan){
  const {track:trackIndex,difficulty}=spec;
  if(![1,2].includes(trackIndex)||![1,2].includes(difficulty))throw new Error('Probe limited to Germany/England medium/hard');
  const track=await json(`tracks/etappe${trackIndex}.json`);
  const random=new NativeRandom(spec.constructionSeed??0);
  const sim=new RaceSimulation({config,manifest,cars,track,random,
    physicsBytes:await asset(`physics/phys${difficulty}.dat`),
    racerBytes:await asset(`racer-tables/cars${difficulty}.dat`),
    character:spec.character??1,difficulty,raceMode:1});
  random.seed(spec.seed??0);
  const base={speed:120,lookAheadSeconds:.8,steeringGain:1.5,dampingGain:.6,...spec.options};
  const driver=new RouteTestDriver(track,{...base,mirrored:sim.motion.mirrored,obstacleAvoidance:false,
    railBounds:sim.motion.collision.bounds,obstacles:sim.physicalBodies.filter(body=>body!==sim.motion.body)});
  if(spec.laneOrder)driver.links=driver.links.map((links,index)=>{
    const chosen=spec.laneOrder.map(i=>track.drive[index].links[i]).find(next=>links.includes(next));
    return chosen===undefined?links:[chosen];
  });
  const filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS}),inputs=crypto.createHash('sha256');
  const run={spec,opponents:sim.opponents.length,events:{},status:'duration-limit',gates:[],lapEvents:[],samples:[],npcLines:[]};report.runs.push(run);
  let now=0;
  for(now=25;now<=(spec.maxMs??900000);now+=25){
    Object.assign(driver,base);
    let penalty=spec.speedPenalty??2;
    for(const profile of spec.profiles??[]){
      const [lo,hi]=profile.sectors,s=sim.motion.body.sector;
      if(lo<=hi?s>=lo&&s<=hi:s>=lo||s<=hi){
        Object.assign(driver,profile.options);
        penalty=profile.speedPenalty??penalty;
      }
    }
    const goal=spec.waypointSchedule?.find(([lo,hi])=>sim.motion.body.sector>=lo&&sim.motion.body.sector<=hi);
    const input=driver.input(sim.motion.body,now,25,{
      targets:goal?[{position:track.drive[goal[2]].position}]:[],
    });
    if(penalty!==2&&!driver.telemetry.reversing){
      const target=driver.speed/(1+penalty*Math.abs(driver.telemetry.headingError));
      input.throttle=input.analog.throttle=Math.max(0,Math.min(1,(target-sim.motion.body.forwardSpeed)*.2));
      input.brake=input.analog.brake=sim.motion.body.forwardSpeed>target+2
        ?Math.max(0,Math.min(1,(sim.motion.body.forwardSpeed-target)*.1)):0;
    }
    if(!driver.telemetry.reversing){
      const body=sim.motion.body;
      const slip=Math.atan2(body.lateralSpeed,Math.max(1,body.forwardSpeed));
      const error=driver.telemetry.headingError+(spec.slipGain??0)*slip;
      const steer=Math.max(-1,Math.min(1,-error*driver.steeringGain+body.yawRate*driver.dampingGain));
      input.steer=input.analog.steer=sim.motion.mirrored?(100-Math.round((steer+1)*50))/50-1:steer;
    }
    inputs.update(JSON.stringify(input)+'\n');
    const events=sim.step(input,filter.sample(.025),now);
    for(const actor of sim.actors){
      if(![...actor.body.position,actor.body.yaw,actor.body.forwardSpeed,actor.body.lateralSpeed,
        actor.body.verticalSpeed].every(Number.isFinite))throw new Error('Nonfinite actor');
      if(actor.animationEvents)actor.animationEvents.length=0;
    }
    for(const event of events){
      if(event.type)run.events[event.type]=(run.events[event.type]??0)+1;
      if(event.type==='time-gate')run.gates.push({...event,now});
      if(event.type==='lap'&&event.racer===undefined)run.lapEvents.push({...event,now});
    }
    if(now%100===0)run.npcLines.push({now,actors:sim.opponents.map((actor,i)=>({id:i,position:[...actor.body.position],yaw:actor.body.yaw,sector:actor.body.sector,speed:actor.body.forwardSpeed,distance:actor.progress.distance,mode:actor.state.mode}))});
    if(now%1000===0)run.samples.push({now,sector:sim.motion.body.sector,
      position:[...sim.motion.body.position],yaw:sim.motion.body.yaw,
      forwardSpeed:sim.motion.body.forwardSpeed,lap:sim.race.lapCount,
      headingError:driver.telemetry.headingError,recoveries:driver.recoveries});
    if(sim.race.phase===3||sim.race.phase===6){run.status=sim.race.phase===3?'finished':'time-expired';break;}
  }
  Object.assign(run,{durationMs:Math.min(now,spec.maxMs??900000),race:sim.race.snapshot(),
    rank:sim.rankStates.at(-1).rank,player:sim.motion.snapshot(),recoveries:driver.recoveries,
    inputSha256:inputs.digest('hex'),npcPlayerRescueDeferrals:sim.rescue.playerOverlapDeferrals});
  run.qualification=nativeAdventureQualification({difficulty,raceType:1},
    {rank:run.rank,finished:sim.race.finished,stars:0});
  console.log(JSON.stringify({name:spec.name,status:run.status,ms:run.durationMs,
    laps:run.race.lapCount,gates:run.gates.length,sector:run.player.sector,recoveries:run.recoveries}));
  await save();
}
const sourceAtEnd=await sourceSnapshot();
report.sourceChangedDuringRun=Object.keys(sourceAtStart).filter(path=>sourceAtStart[path]!==sourceAtEnd[path]);
report.assetsChangedDuringRun=[];
for(const [path,expected]of Object.entries(assetSha256))
  if(hash(await read(`public/assets/${path}`))!==expected)report.assetsChangedDuringRun.push(path);
report.status=report.runs.every(run=>run.status==='finished')?'all-finished':'incomplete';
if(report.sourceChangedDuringRun.length)report.status='source-changed';
if(report.assetsChangedDuringRun.length)report.status='assets-changed';
report.completedAt=new Date().toISOString();
await save();
if(report.status!=='all-finished')process.exitCode=1;
