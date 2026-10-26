import fs from 'node:fs';
import {RaceSimulation} from '../../source/race-simulation.js';
import {NativeRandom} from '../../source/simulation/native-random.js';
import {nativeRotationMatrix} from '../../source/simulation/native-transform.js';
import {sampleNativeTrack} from '../../source/simulation/native-track.js';
import {isSafePlayerRecoveryPose} from '../../source/simulation/player-recovery-position.js';
import {rescuePlacementClear} from '../../source/simulation/rescue-safety.js';

const root=new URL('../../',import.meta.url);
const read=name=>fs.readFileSync(new URL('public/assets/'+name,root));
const json=name=>JSON.parse(read(name));
export const ENGLAND_TYRE_START=Object.freeze({position:[-7027,0,6317],yaw:512,sector:124,waypoint:589});
export const ENGLAND_TYRE_INPUT=Object.freeze({throttle:1,brake:0,steer:.3,
  analog:Object.freeze({throttle:1,brake:0,steer:.3,handbrake:false})});

export function createEnglandTyreFixture(raceMode=0){
  const sim=new RaceSimulation({config:json('config.json'),manifest:json('manifest.json'),
    cars:json('cars.json'),track:json('tracks/etappe2.json'),
    physicsBytes:read('physics/phys0.dat'),racerBytes:read('racer-tables/cars0.dat'),
    random:new NativeRandom(0),character:1,difficulty:0,raceMode});
  const body=sim.motion.body;
  // Controlled, non-overlapping initial road pose near the user's tyre wall.
  // Everything after this setup is ordinary input through the full simulation.
  body.position.splice(0,3,...ENGLAND_TYRE_START.position);
  Object.assign(body,{yaw:ENGLAND_TYRE_START.yaw,sector:ENGLAND_TYRE_START.sector,
    previousSector:ENGLAND_TYRE_START.sector,waypoint:ENGLAND_TYRE_START.waypoint});
  body.matrix=nativeRotationMatrix([0,body.yaw,0]);
  sim.occupancy.remove(body);sim.occupancy.insert(body);
  sim.race.previousSector=body.sector;
  sim.playerCamera.reset(body);sim.camera=sim.playerCamera;
  sim.cameraSector=body.sector;sim.cameraSectors.set(sim.playerCamera,body.sector);
  return sim;
}

const pose=body=>({position:[...body.position],yaw:body.yaw,sector:body.sector,
  waypoint:body.waypoint,forwardSpeed:body.forwardSpeed,lateralSpeed:body.lateralSpeed});
const progress=sim=>({lapCount:sim.race.lapCount,distance:sim.race.distance,
  gateIndex:sim.race.gateIndex,gateDeadlineMs:sim.race.gateDeadlineMs,
  elapsedMs:sim.race.elapsedMs,stars:sim.pickups.stars});

export function runEnglandTyreFixture(raceMode=0){
  const sim=createEnglandTyreFixture(raceMode),body=sim.motion.body;
  const report={scope:'Controlled clear road start, then ordinary analog throttle/steering only. '+
    'No forced rescue, timer, progress, pickup, actor pose or velocity changes after setup.',
    raceMode,playerVoiceId:sim.voices.voiceId(body.id),start:pose(body),ground:sampleNativeTrack(sim.world,body.sector,...body.position),
    startClear:rescuePlacementClear(sim.motion.collision,body,body),
    contacts:[],samples:[],rescueFrames:[],voiceRequests:[],relocations:[],events:[]};
  const original=sim.onPlayerCollision;
  let now=0,previousRecovery=0,finishedAt=null;
  sim.onPlayerCollision=event=>{
    original(event);
    const other=event.firstBody===body?event.secondBody:event.firstBody;
    report.contacts.push({timeMs:now,position:[...body.position],sector:body.sector,
      otherId:other?.id??null,placementIndex:other?.placementIndex??null,mesh:other?.mesh??null,
      impulse:event.impulse});
  };
  sim.onVoiceRequest=request=>{if(['DISAPP','REAPP'].includes(request.sample))
    report.voiceRequests.push({timeMs:now,...request});};
  for(now=25;now<=16000;now+=25){
    const input=finishedAt?{throttle:1,brake:0,steer:0,analog:{throttle:1,brake:0,steer:0}}
      :ENGLAND_TYRE_INPUT;
    const before=progress(sim);
    sim.step(input,Math.fround(.025),now,{beforeBonuses:()=>{
      const entry=sim.rescue.get(body);
      if(!entry?.softLock)return;
      report.rescueFrames.push({timeMs:now,frame:entry.frame,shrinking:entry.shrinking,
        scale:entry.scale,relocated:entry.relocated,finished:entry.finished,position:[...body.position]});
      if(entry.relocated)report.relocations.push({timeMs:now,before,after:progress(sim),
        destination:structuredClone(entry.destination),
        occupancyCount:[...sim.occupancy.nodes.values()].flat().filter(actor=>actor===body).length,
        occupancyWaypoint:sim.occupancy.membership.get(body),bodyWaypoint:body.waypoint,
        bodyPreviousSector:body.previousSector,racePreviousSector:sim.race.previousSector,
        clear:isSafePlayerRecoveryPose({track:sim.race.track,world:sim.world,motion:sim.motion},entry.destination)});
      if(entry.finished&&!finishedAt)finishedAt=now;
    }});
    if(sim.playerRecovery.recoveries!==previousRecovery){
      report.detectedAt=now;report.detected=pose(body);previousRecovery=sim.playerRecovery.recoveries;
    }
    for(const event of sim.events)if(['lap','time-gate','bonus-pickup'].includes(event.type))
      report.events.push({timeMs:now,...event});
    if(report.relocations.at(-1)?.timeMs===now-25)
      report.relocations.at(-1).followingFrame={progress:progress(sim),events:structuredClone(sim.race.events)};
    if(now%250===0)report.samples.push({timeMs:now,...pose(body),
      attemptSeconds:sim.playerRecovery.attemptSeconds,recoveries:sim.playerRecovery.recoveries,
      progress:progress(sim)});
    if(finishedAt&&now>=finishedAt+2000)break;
  }
  report.finishedAt=finishedAt;report.final=pose(body);report.progress=progress(sim);
  report.recoveries=sim.playerRecovery.recoveries;
  report.lastRecovery=structuredClone(sim.playerRecovery.lastRecovery);
  report.activeRescue=Boolean(sim.rescue.get(body));
  return report;
}
