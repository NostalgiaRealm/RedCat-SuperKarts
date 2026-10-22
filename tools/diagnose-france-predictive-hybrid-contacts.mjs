import assert from 'node:assert/strict';
import {predictClosedLoop,executeClosedLoopPolicy} from '../tests/helpers/private-closed-loop-contact-driving.mjs';
import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import { RaceSimulation } from '../src/race-simulation.js';
import { NativeRandom } from '../src/simulation/native-random.js';
import { NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS } from '../src/simulation/clock.js';
import { RouteTestDriver } from '../tests/helpers/private-france-hybrid-driver.mjs';
import { nativeAdventureQualification } from '../src/simulation/native-adventure.js';
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
  const paths = ['tests/helpers/private-france-hybrid-driver.mjs','evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json','tools/diagnose-france-predictive-hybrid-contacts.mjs','tests/helpers/private-ground-chord-driver.mjs','tests/helpers/private-timed-lane-driver.mjs','evidence/full-race-matrix/timed-france-hard-reset-ground0.json','evidence/full-race-matrix/france-ground-chord-audit.json','tests/helpers/private-native-contact-forecast.mjs','tests/helpers/private-closed-loop-contact-driving.mjs','tools/diagnose-france-corner-profiles.mjs','tools/diagnose-france-line-travel.mjs','tools/diagnose-countdown-projected-line.mjs', 'tools/diagnose-countdown-races.mjs', 'tools/native-blockage-timed-seeded-lane.mjs', 'tools/native-blockage-timed-lane.mjs', 'tests/helpers/private-projected-line-driver.mjs', 'tools/native-blockage-timed-character.mjs', 'tools/native-blockage-timed-probe.mjs', 'tools/validate-driven-races.mjs', 'tests/helpers/route-test-driver.mjs',
    'tests/helpers/star-approach-planner.mjs','tools/validation-source-dependencies.mjs'];
  async function visit(directory) {
    for (const entry of await fs.readdir(new URL(directory, root), { withFileTypes: true })) {
      const path = `${directory}/${entry.name}`;
      if (entry.isDirectory()) await visit(path);
      else if (entry.isFile()) paths.push(path);
    }
  }
  await visit('src');
  return Object.fromEntries(await Promise.all(paths.sort().map(async path =>
    [path, crypto.createHash('sha256').update(await fs.readFile(new URL(path, root))).digest('hex')])));
}
const sourceAtStart = await sourceSnapshot();
const auditedGroundReport=JSON.parse(await fs.readFile(new URL('evidence/full-race-matrix/timed-france-hard-reset-ground0.json',root)));
const auditedGroundLine=auditedGroundReport.runs[0].racingLine;
const projectedReport=JSON.parse(await fs.readFile(new URL('evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json',root)));
const projectedLine=projectedReport.runs[0].racingLine;
const executionDependencies=await validationSourceDependencies(new URL(import.meta.url),root);
const sourceGuard=process.env.RCSK_SOURCE_SCOPE==='execution'?'execution-dependencies':'all-source';
const [config, manifest, cars] = await Promise.all(['config.json', 'manifest.json', 'cars.json'].map(json));
// Tuples are track,difficulty,mode. Default covers all courses/difficulties
// in ordinary five-lap races, retaining the configured opponent counts.
const cases = process.env.RCSK_DRIVEN_CASES
  ? process.env.RCSK_DRIVEN_CASES.split(';').map(value => value.split(',').map(Number))
  : Array.from({ length: 18 }, (_, i) => [i % 6, Math.floor(i / 6), 0]);
const maxMs = Number(process.env.RCSK_DRIVEN_MAX_MS ?? 900000);
const seekStars = process.env.RCSK_DRIVEN_SEEK_STARS === '1';
const character=Number(process.env.RCSK_DRIVEN_CHARACTER??0);
if(![0,1,2,3].includes(character))throw new Error('Original character must be0..3');
const fireHeld = process.env.RCSK_DRIVEN_FIRE_HELD === '1';
const diagnosticDriverTrace = process.env.RCSK_DRIVEN_TRACE_DRIVER === '1';
const sampleMs = Number(process.env.RCSK_DRIVEN_SAMPLE_MS ?? 10000);
const constructionSeed=Number(process.env.RCSK_DRIVEN_CONSTRUCTION_SEED??0)>>>0,gameplaySeed=Number(process.env.RCSK_DRIVEN_GAMEPLAY_SEED??0)>>>0;
const laneOrder=(process.env.RCSK_DRIVEN_LANE_ORDER??'0,1,2').split(',').map(Number);
const predictionSections=JSON.parse(process.env.RCSK_PREDICT_SECTIONS??'[[0,57],[111,186]]');
const predictionAfterMs=Number(process.env.RCSK_PREDICT_AFTER_MS??0);
const prediction={frames:48,lookaheads:[.4,.7,1],speeds:[50,75,120],offsets:[-60,0,60]},forecastIntervalMs=100;
const cornerProfiles=JSON.parse(process.env.RCSK_DRIVEN_CORNER_PROFILES??'[]');
const driverOptions = {
  speed: Number(process.env.RCSK_DRIVEN_SPEED ?? 30),
  lookAheadSeconds: Number(process.env.RCSK_DRIVEN_LOOK ?? .5),
  steeringGain: Number(process.env.RCSK_DRIVEN_P ?? 1.5),
  dampingGain: Number(process.env.RCSK_DRIVEN_D ?? .5),
};
const turnPenalty=Number(process.env.RCSK_DRIVEN_TURN_PENALTY??1000);
const output = new URL(process.env.RCSK_DRIVEN_REPORT ?? 'evidence/gameplay/driven-races.json', root);
const report = {
  format: 'superkarts-control-only-races-v1',
  scope: 'Composed JavaScript race with original physics, AI, contacts, bonuses and timers. A test-only route follower supplies ordinary analog controls. No poses, velocities, triggers, pickups, timers, or physics tables are changed. This is not an original Windows full-process comparison or a full-campaign UI run.',
  predictionSections,predictionAfterMs,prediction,forecastIntervalMs,cornerProfiles,
  contactForecast:'Copied NativePlayerMotion calls retain original prepare, eight collision/Euler/matrix/contact-response substeps, sector and wheel-ground update. All other contact bodies are copies and callbacks are suppressed. Their future AI/scenery movement and global triggers are not forecast; actual race executes them normally.',
  startedAt: new Date().toISOString(), sourceAtStart,sourceGuard,executionDependencies,assetSha256,
  startPolicy: 'Original authored opening camera and321 countdown. Ordinary throttle1/steer0 held until observed native green; route driver first invoked on following tick. No forced phase or timer changes.',
  auditedRouteSource:'evidence/full-race-matrix/timed-france-hard-reset-ground0.json',
  projectedRouteSource:'evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json',
  hybridRoute:{groundEdgeRanges:[[0,57],[171,187]],projectedEdgeRange:[57,171],sharedNodes:[{sector:0,node:0},{sector:57,node:253},{sector:171,node:732}],costMeaning:'sum of world-space segment lengths'},
  auditedGeometry:'evidence/full-race-matrix/france-ground-chord-audit.json',
  testDriverPolicy: 'Hybrid joins exact retained ground route edges0–57 and171–187 with retained projected original-node edges57–171 at identical nodes253/732/0. Original projected feedback is preserved in the middle section outside forecast. Recorded windows use private copied contact forecasts and ordinary steering/throttle/brake; actual obstacles and collision responses remain active. No new geometry or game-state writes.',
  turnPenalty, cadenceMs: 25, constructionSeed, gameplaySeed, character, driverOptions, laneOrder, seekStars, fireHeld, maxMs, runs: [],
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
    random, character, difficulty, raceMode, countdown:true });
  // Native construction consumes time()-seeded values for scenery/weather.
  // 42f930 then reseeds from GetTickCount before the first game loop.
  random.seed(gameplaySeed);
  const driver = new RouteTestDriver(track, { ...driverOptions,
    railBounds: simulation.motion.collision.bounds,
    obstacles: simulation.physicalBodies.filter(body=>body!==simulation.motion.body) }),
    filter = new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
  // Test controller only. Actual physicalBodies/colliders are untouched.
  driver.configureHybridLine(auditedGroundLine,projectedLine);
  assert.equal(trackIndex,3,'This isolated audited route is France only');
  assert.equal(turnPenalty,1000,'Projected retained source uses penalty1000; ground source is penalty0');
  driver.laneOrder=laneOrder;driver.testCollision=null;driver.starPlanner=null;driver.narrowStarPlanner=null;
  const inputHash = crypto.createHash('sha256');
  const run = { track: trackIndex, difficulty, raceMode, opponents: simulation.opponents.length,
    status: 'duration-limit', racingLine:driver.racingLine, racingLineCost:driver.racingLineCost, opening:{countdownStartWallMs:simulation.countdownStarted?0:null,greenWallMs:null,firstDriverInputWallMs:null,initialPlayer:simulation.motion.snapshot(),initialCamera:{pathIndex:simulation.startCamera?.pathIndex,durationTicks:simulation.startCamera?.durationTicks,position:[...simulation.camera.position]},transitions:[]}, events: {}, samples: [], lapEvents: [], pickupEvents: [], gateEvents: [],
    rescue:{entries:0,environmentEntries:0,blockedTicks:0,maxBlockedMs:0,relocations:[],safetyFallbacks:0},
    starApproaches: simulation.pickups.pickups.flatMap((pickup, index) => pickup.type === 6
      ? [{ index, position: [...pickup.position], minDistance: Infinity }] : []) };
  run.travel={laps:[],segments:{},contacts:[],corners:[],totalDistance:0};
  const previousContact=simulation.onPlayerCollision;
  simulation.onPlayerCollision=contact=>{
    if(simulation.movementActive)run.travel.contacts.push({...contact,wallMs:simulation.wallMs,
      activeElapsedMs:simulation.race.elapsedMs,sector:simulation.motion.body.sector,
      position:[...simulation.motion.body.position]});
    previousContact?.(contact);
  };
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
  const forecastLine=driver.racingLine.map(point=>({...point}));
  let now = 0,lastForecast=-Infinity,selectedPolicy=null;
  try {
    for (now = 25; now <= maxMs; now += 25) {
      const wasActive=simulation.movementActive,wasCountdownStarted=simulation.countdownStarted;
      const beforePhase=simulation.countdown?.phase;
      if(wasActive&&run.opening.firstDriverInputWallMs===null)run.opening.firstDriverInputWallMs=now;
      Object.assign(driver,driverOptions);
      for(const profile of cornerProfiles){const [lo,hi]=profile.sectors;if(simulation.motion.body.sector>=lo&&simulation.motion.body.sector<=hi&&simulation.race.elapsedMs>=(profile.afterActiveMs??0))Object.assign(driver,profile.options);}
      const input = wasActive ? driver.input(simulation.motion.body, now, 25, {
        targets: seekStars ? simulation.pickups.pickups.filter(pickup => pickup.type === 6 && pickup.state === 2) : [],
      }) : {throttle:1,brake:0,steer:0,handbrake:0,bonus:0,analog:{throttle:1,brake:0,steer:0}};
      if(wasActive&&simulation.race.elapsedMs>=predictionAfterMs&&simulation.motion.body.forwardSpeed>=10&&predictionSections.some(([a,b])=>simulation.motion.body.sector>=a&&simulation.motion.body.sector<=b)){
        if(!selectedPolicy||now-lastForecast>=forecastIntervalMs){selectedPolicy=predictClosedLoop(simulation.motion,track,forecastLine,prediction).selection;lastForecast=now;}
        const value=executeClosedLoopPolicy(simulation.motion,track,forecastLine,selectedPolicy);Object.assign(input,value);Object.assign(input.analog,value);driver.telemetry.forecast=selectedPolicy;
      }else selectedPolicy=null;
      if(simulation.motion.mirrored){input.steer=-input.steer;input.analog.steer=-input.analog.steer;}
      if(fireHeld&&wasActive)input.bonus=1;
      inputHash.update(JSON.stringify(input) + '\n');
      if(wasActive&&[[18,31],[129,141],[164,176]].some(([a,b])=>simulation.motion.body.sector>=a&&simulation.motion.body.sector<=b))run.travel.corners.push({wallMs:now,activeMs:simulation.race.elapsedMs,sector:simulation.motion.body.sector,position:[...simulation.motion.body.position],yaw:simulation.motion.body.yaw,yawRate:simulation.motion.body.yawRate,lateralSpeed:simulation.motion.body.lateralSpeed,forwardSpeed:simulation.motion.body.forwardSpeed,input,driver:structuredClone(driver.telemetry)});
      const beforePosition=[...simulation.motion.body.position],beforeLap=simulation.race.lapCount,beforeSector=simulation.motion.body.sector;
      const events = simulation.step(input, filter.sample(.025), now,{beforeBonuses:observeRescue});
      if(wasActive){
        const b=simulation.motion.body,travel=Math.hypot(b.x-beforePosition[0],b.z-beforePosition[2]);
        run.travel.totalDistance+=travel;
        const lap=run.travel.laps[beforeLap]??={distance:0,ticks:0,forwardSpeedSum:0,absLateralSpeedSum:0,fullSteerTicks:0};
        lap.distance+=travel;lap.ticks++;lap.forwardSpeedSum+=b.forwardSpeed;lap.absLateralSpeedSum+=Math.abs(b.lateralSpeed);
        if(Math.abs(input.steer)>.99)lap.fullSteerTicks++;
        const segment=run.travel.segments[`${beforeLap}:${Math.floor(beforeSector/10)*10}`]??={distance:0,ticks:0,forwardSpeedSum:0,absLateralSpeedSum:0};
        segment.distance+=travel;segment.ticks++;segment.forwardSpeedSum+=b.forwardSpeed;segment.absLateralSpeedSum+=Math.abs(b.lateralSpeed);
      }
      if(!wasCountdownStarted&&simulation.countdownStarted)run.opening.countdownStartWallMs=now;
      if(beforePhase!==simulation.countdown?.phase)run.opening.transitions.push({wallMs:now,from:beforePhase,to:simulation.countdown?.phase,activeElapsedMs:simulation.race.elapsedMs});
      if(!wasActive&&simulation.movementActive){
        run.opening.greenWallMs=now;
        run.opening.greenPlayer=simulation.motion.snapshot();
        run.opening.greenRace=simulation.race.snapshot();
        run.opening.greenRandomState=random.state;
        console.log(`track${trackIndex} native green wall=${now}ms active=${simulation.race.elapsedMs}ms position=${simulation.motion.body.position}`);
      }
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
        timeMs: now, activeElapsedMs:simulation.race.elapsedMs,movementActive:simulation.movementActive, sector: simulation.motion.body.sector, position: [...simulation.motion.body.position],
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
  run.activeElapsedMs=simulation.race.elapsedMs;
  run.wallSinceGreenMs=run.opening.greenWallMs===null?null:run.durationMs-run.opening.greenWallMs;
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
  console.log(`track${trackIndex} difficulty${difficulty} mode${raceMode}: ${run.status}, ${run.race.lapCount} laps, ${run.durationMs}ms wall/${run.activeElapsedMs}ms active, rank${run.rank}, stars${run.stars}, qualified=${run.qualification.qualified}, ${run.recoveries} reverse recoveries`);
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
