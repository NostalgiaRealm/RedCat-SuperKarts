import {RouteTestDriver as OpeningDriver} from '../tests/helpers/private-ground-hazard-line.mjs';
import {tireLateralForce,resistanceForce} from '../source/simulation/native-forces.js';
import {authoredBranchGoal} from '../tests/helpers/private-nl-authored-branch.mjs';
import fs from 'node:fs/promises';
import {predictSteering} from '../tests/helpers/private-predictive-driving-v3.mjs';
import crypto from 'node:crypto';
import { RaceSimulation } from '../source/race-simulation.js';
import { NativeRandom } from '../source/simulation/native-random.js';
import { NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS } from '../source/simulation/clock.js';
import { RouteTestDriver } from '../tests/helpers/route-test-driver.mjs';
import { nativeAdventureQualification } from '../source/simulation/native-adventure.js';
import {validationSourceDependencies} from './validation-source-dependencies.mjs';

const root = new URL('../', import.meta.url), assets = new URL('public/assets/', root);
const assetSha256={};
const read = async file => {
  const bytes=await fs.readFile(new URL(file,assets));
  assetSha256[file]=crypto.createHash('sha256').update(bytes).digest('hex');
  return bytes;
};
const json = async file => JSON.parse(await read(file));
async function sourceSnapshot() {
  const paths = ['tools/timed-nl-authored-opening.mjs','tests/helpers/private-ground-hazard-line.mjs','tools/timed-nl-authored-branch-observed.mjs','tools/timed-nl-authored-branch.mjs','tests/helpers/private-nl-authored-branch.mjs','tools/timed-nl-windmill-offset.mjs','tools/timed-predictive-shortest-v3.mjs', 'tools/timed-predictive-v3.mjs','tools/timed-predictive-v2.mjs','tools/timed-germany-predictive.mjs','tests/helpers/private-predictive-driving-v3.mjs', 'tools/native-blockage-timed-road-inverse.mjs', 'tools/native-blockage-timed-road-profile.mjs', 'tools/native-blockage-timed-road-center.mjs', 'tools/native-blockage-timed-corridors.mjs', 'tools/native-blockage-timed-waypoints.mjs', 'tools/native-blockage-timed-seeded-lane.mjs', 'tools/native-blockage-timed-lane.mjs', 'tests/helpers/private-timed-lane-driver.mjs', 'tools/native-blockage-timed-character.mjs', 'tools/native-blockage-timed-probe.mjs', 'tools/validate-driven-races.mjs', 'tests/helpers/route-test-driver.mjs',
    'tests/helpers/star-approach-planner.mjs','tools/validation-source-dependencies.mjs'];
  async function visit(directory) {
    for (const entry of await fs.readdir(new URL(directory, root), { withFileTypes: true })) {
      const path = `${directory}/${entry.name}`;
      if (entry.isDirectory()) await visit(path);
      else if (entry.isFile()) paths.push(path);
    }
  }
  await visit('source');
  return Object.fromEntries(await Promise.all(paths.sort().map(async path =>
    [path, crypto.createHash('sha256').update(await fs.readFile(new URL(path, root))).digest('hex')])));
}
const sourceAtStart = await sourceSnapshot();
const executionDependencies=await validationSourceDependencies(new URL(import.meta.url),root);
const sourceGuard=process.env.RCSK_SOURCE_SCOPE==='execution'?'execution-dependencies':'all-source';
const [config, manifest, cars] = await Promise.all(['config.json', 'manifest.json', 'cars.json'].map(json));
// Tuples are track,difficulty,mode. Default covers all courses/difficulties
// in ordinary five-lap races, retaining the configured opponent counts.
const cases = process.env.RCSK_DRIVEN_CASES
  ? process.env.RCSK_DRIVEN_CASES.split(';').map(value => value.split(',').map(Number))
  : Array.from({ length: 18 }, (_, i) => [i % 6, Math.floor(i / 6), 0]);
const openingCutoff=Number(process.env.RCSK_DRIVEN_OPENING_END??57);
const openingOptions={speed:170,lookAheadSeconds:.5,steeringGain:1.5,dampingGain:.4};
const openingInverse={responseSeconds:.1,slipGain:0,anglePenalty:0};
const authoredBranch=JSON.parse(process.env.RCSK_DRIVEN_AUTHORED_BRANCH??'[441,444,448,452,456,460,464,468,472,479,486,493,501,508,514,520,527,534,542,550,558,565,571,577,583,589,595,601,607,613,619,625,631,637,643,650,658,666,673,679,684,690,696,701,705,709,712]');
const branchProfiles=JSON.parse(process.env.RCSK_DRIVEN_BRANCH_PROFILES??'[]');
const branchPolicy=JSON.parse(process.env.RCSK_DRIVEN_BRANCH_POLICY??'[80,125,.6]');
const windmillOffset=JSON.parse(process.env.RCSK_DRIVEN_WINDMILL_OFFSET??'[55,73,100]');
const maxMs = Number(process.env.RCSK_DRIVEN_MAX_MS ?? 900000);
const seekStars = process.env.RCSK_DRIVEN_SEEK_STARS === '1';
const character=Number(process.env.RCSK_DRIVEN_CHARACTER??0);
if(![0,1,2,3].includes(character))throw new Error('Original character must be0..3');
const fireHeld = process.env.RCSK_DRIVEN_FIRE_HELD === '1';
const diagnosticDriverTrace = process.env.RCSK_DRIVEN_TRACE_DRIVER === '1';
const sampleMs = Number(process.env.RCSK_DRIVEN_SAMPLE_MS ?? 10000);
const constructionSeed=Number(process.env.RCSK_DRIVEN_CONSTRUCTION_SEED??0)>>>0,gameplaySeed=Number(process.env.RCSK_DRIVEN_GAMEPLAY_SEED??0)>>>0;
const waypointSchedule=JSON.parse(process.env.RCSK_DRIVEN_WAYPOINT_SCHEDULE??'[]');
const laneSchedule=JSON.parse(process.env.RCSK_DRIVEN_LANE_SCHEDULE??'[]');
const laneOrder=(process.env.RCSK_DRIVEN_LANE_ORDER??'0,1,2').split(',').map(Number);
const centerSections=JSON.parse(process.env.RCSK_DRIVEN_CENTER_SECTIONS??'[]');
const policyProfiles=JSON.parse(process.env.RCSK_DRIVEN_PROFILES??'[]');
const prediction={frames:Number(process.env.RCSK_PREDICT_FRAMES??12),slipWeight:Number(process.env.RCSK_PREDICT_SLIP??0),rateWeight:Number(process.env.RCSK_PREDICT_RATE??1)};
const inverseControl={responseSeconds:Number(process.env.RCSK_DRIVEN_RESPONSE??.3),slipGain:Number(process.env.RCSK_DRIVEN_SLIP_GAIN??1),anglePenalty:Number(process.env.RCSK_DRIVEN_ANGLE_PENALTY??10)};
const driverOptions = {
  speed: Number(process.env.RCSK_DRIVEN_SPEED ?? 30),
  lookAheadSeconds: Number(process.env.RCSK_DRIVEN_LOOK ?? .5),
  steeringGain: Number(process.env.RCSK_DRIVEN_P ?? 1.5),
  dampingGain: Number(process.env.RCSK_DRIVEN_D ?? .5),
};
const output = new URL(process.env.RCSK_DRIVEN_REPORT ?? 'evidence/gameplay/driven-races.json', root);
const report = {
  format: 'superkarts-control-only-races-v1',
  scope: 'Composed JavaScript race with original physics, AI, contacts, bonuses and timers. A test-only route follower supplies ordinary analog controls. No poses, velocities, triggers, pickups, timers, or physics tables are changed. This is not an original Windows full-process comparison or a full-campaign UI run.',
  startedAt: new Date().toISOString(), sourceAtStart,sourceGuard,executionDependencies,assetSha256,
  testDriverPolicy: 'Before recorded openingCutoff sector each lap, a hazard-aware ground line with inverse original tire-force yaw control supplies ordinary inputs; openingOptions/openingInverse are recorded. A private target follows the explicitly recorded authored DMP nodes through the inner Netherlands branch, retaining all native collisions and body integration. Private steering goals through the recorded windmill sector/window are offset east to anticipate lateral drift; original positions, collisions and squash activation are unchanged. Ordinary steering selected by read-only finite-horizon force/integration predictions on private body copies; no real body writes. Prediction settings are recorded. Recorded policyProfiles adjust only test driver speed/lookahead/gains by sector. Recorded centerSections use ordinary steering toward original PMP centerline lookahead; other sections retain lane priorities and optional authored waypoint goals by sector (waypointSchedule recorded) supplied only to the test controller, no game pickup/trigger calls; fixed authored-link direction priority; original linked-road follower with its optional detour planner disabled; production obstacles and collision responses remain active. Ordinary inputs only.',
  openingCutoff, openingOptions, openingInverse, authoredBranch, branchPolicy, branchProfiles, windmillOffset, cadenceMs: 25, linkedNodePolicy:'Shortest rail-prechecked original DMP link from canonical test helper; private scalar predictions choose only ordinary inputs.', prediction, inverseControl, policyProfiles, centerSections, constructionSeed, gameplaySeed, character, driverOptions, laneOrder, laneSchedule, waypointSchedule, seekStars, fireHeld, maxMs, runs: [],
};
await fs.mkdir(new URL('.', output), { recursive: true });
const save = () => fs.writeFile(output, JSON.stringify(report, null, 2) + '\n');
for (const [trackIndex, difficulty, raceMode] of cases) {
  if (![0, 1, 2, 3, 4, 5].includes(trackIndex) || ![0, 1, 2].includes(difficulty)
    || ![0, 1, 2, 3].includes(raceMode)) throw new Error('Invalid driven case');
  const [track, physicsBytes, racerBytes] = await Promise.all([
    json(`tracks/etappe${trackIndex}.json`), read(`physics/phys${difficulty}.dat`),
    read(`racer-tables/cars${difficulty}.dat`),
  ]);
  const random = new NativeRandom(constructionSeed);
  const simulation = new RaceSimulation({ config, manifest, cars, track, physicsBytes, racerBytes,
    random, character, difficulty, raceMode });
  // Native construction consumes time()-seeded values for scenery/weather.
  // 42f930 then reseeds from GetTickCount before the first game loop.
  random.seed(gameplaySeed);
  const driver = new RouteTestDriver(track, { ...driverOptions, obstacleAvoidance:false,
    railBounds: simulation.motion.collision.bounds,
    obstacles: simulation.physicalBodies.filter(body=>body!==simulation.motion.body) }),
    filter = new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
  // Test controller only. Actual physicalBodies/colliders are untouched.
  driver.laneOrder=laneOrder;driver.testCollision=null;driver.starPlanner=null;driver.narrowStarPlanner=null;
  const openingDriver=new OpeningDriver(track,{...openingOptions,railBounds:simulation.motion.collision.bounds,obstacles:simulation.physicalBodies.filter(body=>body!==simulation.motion.body)});
  openingDriver.configureRacingLine(0);openingDriver.testCollision=openingDriver.starPlanner=openingDriver.narrowStarPlanner=null;
  const inputHash = crypto.createHash('sha256');
  const run = { track: trackIndex, difficulty, raceMode, opponents: simulation.opponents.length,
    status: 'duration-limit', events: {}, samples: [], lapEvents: [], pickupEvents: [], gateEvents: [],
    rescue:{entries:0,environmentEntries:0,blockedTicks:0,maxBlockedMs:0,relocations:[],safetyFallbacks:0},
    starApproaches: simulation.pickups.pickups.flatMap((pickup, index) => pickup.type === 6
      ? [{ index, position: [...pickup.position], minDistance: Infinity }] : []) };
  report.runs.push(run);
  const rescuesSeen=new WeakSet(),rescuesStarted=new WeakMap();
  let blockedMs=0;
  const observeRescue=()=>{
    const entry=simulation.rescue.get(simulation.motion.body);
    if(!entry){blockedMs=0;return;}
    if(!rescuesSeen.has(entry)){
      rescuesSeen.add(entry);rescuesStarted.set(entry,now);run.rescue.entries++;
      if(entry.environment)run.rescue.environmentEntries++;
    }
    if(entry.safetyBlocked){run.rescue.blockedTicks++;blockedMs+=25;}
    else blockedMs=0;
    run.rescue.maxBlockedMs=Math.max(run.rescue.maxBlockedMs,blockedMs);
    if(entry.relocated){
      if(entry.destination.safetyFallback)run.rescue.safetyFallbacks++;
      run.rescue.relocations.push({now,elapsedMs:now-rescuesStarted.get(entry),
        environment:entry.environment,waypoint:entry.destination.waypoint,
        sector:entry.destination.sector,position:[...entry.destination.position],
        safetyFallback:Boolean(entry.destination.safetyFallback)});
    }
  };
  let now = 0;
  run.contacts=[];const originalContact=simulation.onPlayerCollision;
  simulation.onPlayerCollision=contact=>{originalContact(contact);run.contacts.push({now,sector:simulation.motion.body.sector,position:[...simulation.motion.body.position],forwardSpeed:simulation.motion.body.forwardSpeed,impulse:contact.impulse,firstId:contact.firstBody?.id,secondId:contact.secondBody?.id,firstPlacement:contact.firstBody?.placementIndex,secondPlacement:contact.secondBody?.placementIndex});};
  try {
    for (now = 25; now <= maxMs; now += 25) {
      Object.assign(driver,driverOptions);
      for(const profile of policyProfiles){const [lo,hi]=profile.sectors,s=simulation.motion.body.sector;if(s>=lo&&s<=hi)Object.assign(driver,profile.options);}
      driver.laneOrder=laneSchedule.find(([start,end])=>simulation.motion.body.sector>=start&&simulation.motion.body.sector<=end)?.[2]??laneOrder;
      const roadGoal=waypointSchedule.find(([start,end])=>simulation.motion.body.sector>=start&&simulation.motion.body.sector<=end);
      let input = driver.input(simulation.motion.body, now, 25, {
        targets: roadGoal?[{position:track.drive[roadGoal[2]].position}]:seekStars ? simulation.pickups.pickups.filter(pickup => pickup.type === 6 && pickup.state === 2) : [],
      });
      if(centerSections.some(([lo,hi])=>simulation.motion.body.sector>=lo&&simulation.motion.body.sector<=hi)&&!driver.telemetry.reversing){
        const b=simulation.motion.body;let i=b.sector;const route=track.route,n=route.length,a=route[i].position,bb=route[(i+1)%n].position,dx=bb[0]-a[0],dz=bb[2]-a[2];let fraction=Math.max(0,Math.min(1,((b.x-a[0])*dx+(b.z-a[2])*dz)/(dx*dx+dz*dz))),remaining=50+Math.abs(b.forwardSpeed)*10*driver.lookAheadSeconds,target;
        for(let k=0;k<20;k++){let a=route[i%n].position,bb=route[(i+1)%n].position,len=Math.hypot(bb[0]-a[0],bb[2]-a[2]),available=len*(1-fraction);if(remaining<=available||k===19){const t=Math.min(1,fraction+remaining/len);target=[a[0]+t*(bb[0]-a[0]),0,a[2]+t*(bb[2]-a[2])];break;}remaining-=available;fraction=0;i++;}
        const desired=Math.atan2(-(target[0]-b.x),target[2]-b.z),error=Math.atan2(Math.sin(desired-b.yaw*Math.PI/2048),Math.cos(desired-b.yaw*Math.PI/2048));input.steer=Math.max(-1,Math.min(1,-error*driver.steeringGain+b.yawRate*driver.dampingGain));input.analog.steer=input.steer;driver.telemetry.target=target;driver.telemetry.headingError=error;
      }
      {const [lo,hi,dx]=windmillOffset,sector=simulation.motion.body.sector;
        if(sector>=lo&&sector<=hi){
          const target=driver.telemetry.target;
          if(target[0]>=-5050&&target[0]<=-4400&&target[2]>=2700&&target[2]<=3550)
            driver.telemetry.target=[target[0]+dx,target[1],target[2]];
        }
      }
      {const [lo,hi,look]=branchPolicy,b=simulation.motion.body;
        if(b.sector>=lo&&b.sector<=hi&&!driver.telemetry.reversing){
          const target=authoredBranchGoal(track,b,authoredBranch,branchProfiles.find(([lo,hi])=>b.sector>=lo&&b.sector<=hi)?.[2]??look);if(target)driver.telemetry.target=target;
        }
      }
      if(simulation.motion.body.sector<openingCutoff){
        input=openingDriver.input(simulation.motion.body,now,25,{});driver.telemetry=openingDriver.telemetry;
        if(!driver.telemetry.reversing&&simulation.motion.body.forwardSpeed>=10){
          const b=simulation.motion.body,p=simulation.motion.physics,u=simulation.motion.upgrades,target=driver.telemetry.target;
          const dist=Math.max(5,Math.hypot(target[0]-b.x,target[2]-b.z)/10),error=driver.telemetry.headingError;
          const targetYawRate=2*b.forwardSpeed*Math.sin(error)/dist,targetTorque=(targetYawRate-b.yawRate)/openingInverse.responseSeconds/b.inverseInertia;
          const resistance=resistanceForce(b,p,{tireUpgrade:u.tireUpgrade,matrix14:b.matrix[1],matrix34:b.matrix[7]});let best=Infinity,choice=0;
          for(let steering=-100;steering<=100;steering+=2){const front=tireLateralForce(b,p,'front',steering,u.tireUpgrade,false),rear=tireLateralForce(b,p,'rear',steering,u.tireUpgrade,false),torque=-front*p.frontAxleDistance+rear*p.rearAxleDistance-resistance.lateral*p.frontAxleDistance,cost=Math.abs(torque-targetTorque);if(cost<best){best=cost;choice=steering/100;}}
          input.steer=choice;input.analog.steer=choice;
        }
      }
      if(simulation.motion.body.sector>=openingCutoff&&!driver.telemetry.reversing&&simulation.motion.body.forwardSpeed>=10){
        const value=predictSteering(simulation.motion,driver.telemetry.target,input,prediction);
        Object.assign(input,value);Object.assign(input.analog,value);
      }
      if(simulation.motion.mirrored){input.steer=-input.steer;input.analog.steer=-input.analog.steer;}
      if(fireHeld)input.bonus=1;
      inputHash.update(JSON.stringify(input) + '\n');
      const events = simulation.step(input, filter.sample(.025), now,{beforeBonuses:observeRescue});
      for (const approach of run.starApproaches) {
        const body = simulation.motion.body, p = approach.position;
        const distance = Math.hypot(body.x - p[0], body.z - p[2]);
        if (distance < approach.minDistance) Object.assign(approach, {
          minDistance: distance, heightDifference: body.y - p[1], now,
          eligibleAfter: simulation.pickups.eligibleAfter.at(-1),
          state: simulation.pickups.pickups[approach.index].state,
        });
      }
      for (const actor of simulation.actors) {
        if (![...actor.body.position, actor.body.yaw, actor.body.forwardSpeed,
          actor.body.lateralSpeed, actor.body.verticalSpeed].every(Number.isFinite)) {
          throw new Error(`Nonfinite actor ${actor.body.id}`);
        }
      }
      // Rendering normally consumes this pending visual-only queue.
      for (const actor of simulation.actors) if(actor.animationEvents) actor.animationEvents.length = 0;
      for (const event of events) {
        if (event.type) run.events[event.type] = (run.events[event.type] ?? 0) + 1;
        if (event.type === 'lap' && event.racer === undefined) run.lapEvents.push({ ...event, now });
        if (['bonus', 'star'].includes(event.type) && event.racer === simulation.actors.length - 1)
          run.pickupEvents.push({ ...event, now });
        if(event.type==='time-gate')run.gateEvents.push({...event,now});
      }
      if (now % sampleMs === 0) run.samples.push({
        timeMs: now, sector: simulation.motion.body.sector, position: [...simulation.motion.body.position],
        speed: simulation.motion.body.forwardSpeed, lap: simulation.race.lapCount,
        distance: simulation.race.distance, rank: simulation.rankStates.at(-1).rank,
        stars: simulation.pickups.stars, recoveries: driver.recoveries,
        ...(diagnosticDriverTrace ? {
          driver: driver.telemetry, approachPath: structuredClone(driver.approachPath),
          egressPath: structuredClone(driver.egressPath), yaw: simulation.motion.body.yaw,
          yawRate: simulation.motion.body.yawRate,
          input, groundCount: simulation.motion.ground.groundCount,
        } : {}),
      });
      if (simulation.race.phase === 3 || simulation.race.phase === 6) {
        run.status = simulation.race.phase === 3 ? 'finished' : 'time-expired';
        break;
      }
    }
  } catch (error) {
    run.status = 'error';
    run.error = error.stack;
  }
  run.durationMs = Math.min(now, maxMs);
  run.inputSha256 = inputHash.digest('hex');
  run.recoveries = driver.recoveries;
  run.race = simulation.race.snapshot();
  run.rank = simulation.rankStates.at(-1).rank;
  run.stars = simulation.pickups.stars;
  run.qualification = nativeAdventureQualification({ difficulty, raceType: raceMode }, {
    rank: run.rank, finished: simulation.race.finished, stars: run.stars,
  });
  run.finalPosition = [...simulation.motion.body.position];
  run.finalDiagnostics={
    player:simulation.motion.snapshot(),waypoint:simulation.motion.body.waypoint,phase:simulation.motion.phase,
    rescue:simulation.rescue.entries.map(entry=>({id:entry.body.id,environment:entry.environment,
      frame:entry.frame,shrinking:entry.shrinking,finished:entry.finished,
      safetyBlocked:entry.safetyBlocked,safetyWaitSeconds:entry.safetyWaitSeconds,destination:entry.destination})),
    opponents:simulation.opponents.map(actor=>({id:actor.body.id,position:[...actor.body.position],
      sector:actor.body.sector,waypoint:actor.body.waypoint,state:{...actor.state},
      forwardSpeed:actor.body.forwardSpeed,distance:actor.progress.distance})),
  };
  console.log(`track${trackIndex} difficulty${difficulty} mode${raceMode}: ${run.status}, ${run.race.lapCount} laps, ${run.durationMs}ms, rank${run.rank}, stars${run.stars}, qualified=${run.qualification.qualified}, ${run.recoveries} reverse recoveries`);
  await save();
}
report.status = report.runs.every(run => run.status === 'finished') ? 'all-finished' : 'incomplete';
const sourceAtEnd = await sourceSnapshot();
report.sourceChangedDuringRun = [...new Set([...Object.keys(sourceAtStart), ...Object.keys(sourceAtEnd)])]
  .filter(path => sourceAtStart[path] !== sourceAtEnd[path]);
report.executionSourceChangedDuringRun=report.sourceChangedDuringRun.filter(path=>executionDependencies.includes(path));
const relevantChanges=sourceGuard==='execution-dependencies'?report.executionSourceChangedDuringRun:report.sourceChangedDuringRun;
if(relevantChanges.length)report.status='source-changed';
report.assetsChangedDuringRun=[];
for(const [file,expected] of Object.entries(assetSha256)){
  const actual=crypto.createHash('sha256').update(await fs.readFile(new URL(file,assets))).digest('hex');
  if(actual!==expected)report.assetsChangedDuringRun.push(file);
}
if(report.assetsChangedDuringRun.length)report.status='assets-changed';
report.completedAt = new Date().toISOString();
await save();
// A bounded run that never reaches the finish is a failed completion check,
// even when every simulation step remained finite and raised no exception.
if (report.status !== 'all-finished') process.exitCode = 1;
