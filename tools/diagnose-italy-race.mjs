import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import { RaceSimulation } from '../source/race-simulation.js';
import { NativeRandom } from '../source/simulation/native-random.js';
import { NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS } from '../source/simulation/clock.js';
import { RouteTestDriver } from './diagnose-italy-driver.mjs';
import { nativeAdventureQualification } from '../source/simulation/native-adventure.js';
import {validationSourceDependencies} from './validation-source-dependencies.mjs';

const root = new URL('../', import.meta.url), assets = new URL('public/assets/', root);
const read = file => fs.readFile(new URL(file, assets));
const json = async file => JSON.parse(await read(file));
async function sourceSnapshot() {
  const paths = ['tools/diagnose-italy-race.mjs','tools/diagnose-italy-driver.mjs','tools/diagnose-italy-planner.mjs','tools/validate-driven-races.mjs', 'tests/helpers/route-test-driver.mjs',
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
  : [[5,0,0]];
const maxMs = Number(process.env.RCSK_DRIVEN_MAX_MS ?? 900000);
const seekStars = process.env.RCSK_DRIVEN_SEEK_STARS === '1';
const diagnosticDriverTrace = process.env.RCSK_DRIVEN_TRACE_DRIVER === '1';
const sampleMs = Number(process.env.RCSK_DRIVEN_SAMPLE_MS ?? 1000);
const driverOptions = {
  avoidEnvironment:process.env.ITALY_AVOID_ENVIRONMENT==='1',
  speed: Number(process.env.RCSK_DRIVEN_SPEED ?? 30),
  lookAheadSeconds: Number(process.env.RCSK_DRIVEN_LOOK ?? .5),
  steeringGain: Number(process.env.RCSK_DRIVEN_P ?? 1.5),
  dampingGain: Number(process.env.RCSK_DRIVEN_D ?? .5),
};
const output = new URL(process.env.RCSK_DRIVEN_REPORT ?? 'evidence/race-completion/italy-baseline.json', root);
const report = {
  format: 'superkarts-control-only-races-v1',
  scope: 'Composed JavaScript race with original physics, AI, contacts, bonuses and timers. A test-only route follower supplies ordinary analog controls. No poses, velocities, triggers, pickups, timers, or physics tables are changed. This is not an original Windows full-process comparison or a full-campaign UI run.',
  startedAt: new Date().toISOString(), sourceAtStart,sourceGuard,executionDependencies,
  cadenceMs: 25, constructionSeed: 0, gameplaySeed: 0, character: 0, driverOptions, seekStars, maxMs, runs: [],
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
  const random = new NativeRandom(0);
  const simulation = new RaceSimulation({ config, manifest, cars, track, physicsBytes, racerBytes,
    random, character: 0, difficulty, raceMode });
  // Native construction consumes time()-seeded values for scenery/weather.
  // 42f930 then reseeds from GetTickCount before the first game loop.
  random.seed(0);
  const driver = new RouteTestDriver(track, { ...driverOptions,
    railBounds: simulation.motion.collision.bounds,
    obstacles: simulation.physicalBodies.filter(body=>body!==simulation.motion.body) }),
    filter = new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
  let lastContact=null;
  const nativeSample=simulation.motion.collision.sample.bind(simulation.motion.collision);
  simulation.motion.collision.sample=(body,dt)=>{
    const result=nativeSample(body,dt),c=result.contact;
    lastContact={fraction:result.fraction,stopYaw:result.stopYaw,dt,point:c?.point,normal:c?.normal,
      firstId:c?.firstBody?.id,secondId:c?.secondBody?.id,firstPosition:c?.firstBody?.position&&[...c.firstBody.position],
      secondPosition:c?.secondBody?.position&&[...c.secondBody.position],velocityOverride:result.velocityOverride};
    return result;
  };
  const inputHash = crypto.createHash('sha256');
  const seenRescues=new WeakSet();
  const run = { hazardWaypointTicks:0,environmentRescues:[],maxPositionStep:0, track: trackIndex, difficulty, raceMode, opponents: simulation.opponents.length,
    status: 'duration-limit', events: {}, samples: [], lapEvents: [], pickupEvents: [],
    starApproaches: simulation.pickups.pickups.flatMap((pickup, index) => pickup.type === 6
      ? [{ index, position: [...pickup.position], minDistance: Infinity }] : []) };
  report.runs.push(run);
  let now = 0;
  try {
    for (now = 25; now <= maxMs; now += 25) {
      const input = driver.input(simulation.motion.body, now, 25, {
        targets: seekStars ? simulation.pickups.pickups.filter(pickup => pickup.type === 6 && pickup.state === 2) : [],
      });
      inputHash.update(JSON.stringify(input) + '\n');
      const previousPosition=[...simulation.motion.body.position];
      const events = simulation.step(input, filter.sample(.025), now);
      run.maxPositionStep=Math.max(run.maxPositionStep,Math.hypot(...simulation.motion.body.position.map((x,i)=>x-previousPosition[i])));
      if(track.drive[simulation.motion.body.waypoint]?.unknown[1]===50)run.hazardWaypointTicks++;
      for(const entry of simulation.rescue.entries)if(entry.body===simulation.motion.body&&!seenRescues.has(entry)){
        seenRescues.add(entry);run.environmentRescues.push({timeMs:now,environment:entry.environment,origin:[...entry.origin]});
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
      }
      if (now % sampleMs === 0) run.samples.push({
        timeMs: now, sector: simulation.motion.body.sector, position: [...simulation.motion.body.position],
        speed: simulation.motion.body.forwardSpeed, lap: simulation.race.lapCount,
        distance: simulation.race.distance, rank: simulation.rankStates.at(-1).rank,
        stars: simulation.pickups.stars, recoveries: driver.recoveries,
        ...(diagnosticDriverTrace ? {
          lastContact:structuredClone(lastContact),motion:simulation.motion.snapshot(),
          waypoint:simulation.motion.body.waypoint,waypointMarker:track.drive[simulation.motion.body.waypoint]?.unknown[1],
          rescue:simulation.rescue.get(simulation.motion.body)?(()=>{const e=simulation.rescue.get(simulation.motion.body);return {environment:e.environment,frame:e.frame,shrinking:e.shrinking,destination:e.destination,origin:e.origin,finished:e.finished};})():null,
          allBodies:simulation.actors.map(a=>({id:a.body.id,position:[...a.body.position],sector:a.body.sector,waypoint:a.body.waypoint,phase:a.phase,state:a.state&&structuredClone(a.state)})),
          allRescues:simulation.rescue.entries.map(e=>({id:e.body.id,environment:e.environment,frame:e.frame,shrinking:e.shrinking,destination:e.destination,origin:e.origin,finished:e.finished})),
          effect:simulation.combat.effects.at(-1),
          nearbyBodies:simulation.physicalBodies.filter(b=>b!==simulation.motion.body&&Math.hypot(b.x-simulation.motion.body.x,b.z-simulation.motion.body.z)<200).map(b=>({id:b.id,position:[...b.position],yaw:b.yaw,sector:b.sector,forward:b.forwardSpeed,lateral:b.lateralSpeed,bounds:b.bounds})),
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
  console.log(`track${trackIndex} difficulty${difficulty} mode${raceMode}: ${run.status}, ${run.race.lapCount} laps, ${run.durationMs}ms, ${run.recoveries} reverse recoveries`);
  await save();
}
report.status = report.runs.every(run => run.status === 'finished') ? 'all-finished' : 'incomplete';
const sourceAtEnd = await sourceSnapshot();
report.sourceChangedDuringRun = [...new Set([...Object.keys(sourceAtStart), ...Object.keys(sourceAtEnd)])]
  .filter(path => sourceAtStart[path] !== sourceAtEnd[path]);
report.executionSourceChangedDuringRun=report.sourceChangedDuringRun.filter(path=>executionDependencies.includes(path));
const relevantChanges=sourceGuard==='execution-dependencies'?report.executionSourceChangedDuringRun:report.sourceChangedDuringRun;
if(relevantChanges.length)report.status='source-changed';
report.completedAt = new Date().toISOString();
await save();
if (report.runs.some(run => run.status === 'error') || relevantChanges.length) process.exitCode = 1;
