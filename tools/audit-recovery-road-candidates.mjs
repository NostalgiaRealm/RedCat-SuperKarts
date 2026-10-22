import fs from 'node:fs';
import crypto from 'node:crypto';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {isSafePlayerRecoveryPose,nativeRescueDestinationAtWaypoint} from '../src/simulation/player-recovery-position.js';
const hashes={};
const read=file=>{const bytes=fs.readFileSync(file);hashes[file]=crypto.createHash('sha256').update(bytes).digest('hex');return bytes;};
const json=name=>JSON.parse(read('public/assets/'+name));
const config=json('config.json'),manifest=json('manifest.json'),cars=json('cars.json');
const tracks=[];
for(let id=0;id<6;id++){
  const track=json(`tracks/etappe${id}.json`),sim=new RaceSimulation({config,manifest,cars,track,
    physicsBytes:read('public/assets/physics/phys0.dat'),racerBytes:read('public/assets/racer-tables/cars0.dat'),
    random:new NativeRandom(0),character:1,difficulty:0,raceMode:0});
  const usable=[];let marker50=0;
  for(let waypoint=0;waypoint<track.drive.length;waypoint++){
    if(track.drive[waypoint].unknown[1]===50){marker50++;continue;}
    const pose=nativeRescueDestinationAtWaypoint(track,sim.world,waypoint);
    if(isSafePlayerRecoveryPose({track,world:sim.world,motion:sim.motion},pose))
      usable.push({waypoint,sector:pose.sector,position:pose.position});
  }
  const sectors=new Set(usable.map(p=>p.sector)),gaps=window=>Array.from({length:track.route.length},(_,i)=>i)
    .filter(s=>![...sectors].some(n=>(s-n+track.route.length)%track.route.length<=window));
  const row={track:id,sectors:track.route.length,driveNodes:track.drive.length,marker50,
    safeCount:usable.length,safeSectors:sectors.size,noCandidateWithin12Behind:gaps(12),
    noCandidateWithinHalfCircuitBehind:gaps(Math.floor(track.route.length/2)-1),usable};
  tracks.push(row);console.log(JSON.stringify({...row,usable:undefined}));
}
for(const file of ['src/simulation/player-recovery-position.js','src/simulation/rescue-safety.js'])read(file);
const report={scope:'Current initial original occupancy and car0 bounds. Every candidate passes full road footprint, live SAT and a 30-unit forward exit. Candidate availability is not a guarantee for arbitrary moving occupancy, an 80-unit relocation, or same-lap history eligibility.',
  hashes,bodyBounds:cars.cars[0].bodyBounds,tracks};
fs.mkdirSync('evidence/player-recovery',{recursive:true});
fs.writeFileSync('evidence/player-recovery/initial-road-candidates.json',JSON.stringify(report,null,2)+'\n');
