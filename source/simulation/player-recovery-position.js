import {sampleNativeTrack} from './native-track.js';
import {nativeTrigTable} from './native-integrator.js';
import {rescuePlacementClear} from './rescue-safety.js';
import {NATIVE_PRECISION} from './native-precision.js';

const f32=Math.fround;
export const PLAYER_RECOVERY_MIN_DISTANCE=80;
export const PLAYER_RECOVERY_EXIT_DISTANCES=Object.freeze([0,10,20,30]);

/** 0x450500 selects minimum integer-coordinate Manhattan distance. */
export function nativeRescueNearestSector(track, position, {precision = NATIVE_PRECISION} = {}) {
  const r = precision === 24 ? f32 : Number;
  let selected = 0, best = Infinity;
  track.route.forEach((route, index) => {
    const distance = route.position.reduce((sum, value, axis) =>
      sum + Math.abs(Math.trunc(r(value - position[axis]))), 0);
    if (distance < best) { best = distance; selected = index; }
  });
  return selected;
}

export function nativeRescueHeading(world, sector, precision = NATIVE_PRECISION) {
  const r = precision === 24 ? f32 : Number, [x, , z] = world.sectors[sector].forward;
  const length = r(Math.sqrt(r(r(x * x) + r(z * z))));
  const nx = f32(r(x / length)), nz = r(z / length);
  return f32(r(r(r(Math.atan2(nz, nx) - r(f32(Math.PI) * .5)) * 4096) / f32(Math.PI * 2)));
}

export function nativeRescueDestinationAtWaypoint(track,world,waypoint,{precision=NATIVE_PRECISION}={}) {
  const position = [...track.drive[waypoint].position];
  const previousSector = nativeRescueNearestSector(track, position, {precision});
  const ground = sampleNativeTrack(world, previousSector, ...position);
  position[1] = ground.height;
  return {waypoint, sector: ground.sector, previousSector, position,
    yaw: nativeRescueHeading(world, previousSector, precision)};
}

function validPose(track,pose){
  return Array.isArray(pose?.position)&&pose.position.length===3&&pose.position.every(Number.isFinite)
    &&Number.isFinite(pose.yaw)&&Number.isInteger(pose.sector)&&pose.sector>=0&&pose.sector<track.route.length
    &&Number.isInteger(pose.waypoint)&&pose.waypoint>=0&&pose.waypoint<track.drive.length;
}

function footprint(bounds,position,yaw){
  const {sin,cos}=nativeTrigTable(),angle=(yaw>0?Math.ceil(yaw):Math.floor(yaw))&4095;
  return [[bounds.minX,bounds.minZ],[bounds.maxX,bounds.minZ],
    [bounds.maxX,bounds.maxZ],[bounds.minX,bounds.maxZ]]
    .map(([x,z])=>[position[0]+cos[angle]*x-sin[angle]*z,position[1],
      position[2]+sin[angle]*x+cos[angle]*z]);
}

/** Added recovery safety, not an original game rule. Recheck live occupancy
 * and a short forward exit so a remembered clear pose cannot return into a wall.
 */
export function isSafePlayerRecoveryPose({track,world,motion},pose){
  if(!motion?.body||!motion.collision||!validPose(track,pose)
    ||track.drive[pose.waypoint].unknown[1]===50)return false;
  const bounds=motion.body.bounds??motion.collision.bounds;
  if(!bounds||!['minX','maxX','minZ','maxZ'].every(key=>Number.isFinite(bounds[key]))
    ||bounds.minX>=bounds.maxX||bounds.minZ>=bounds.maxZ)return false;
  const {sin,cos}=nativeTrigTable(),angle=Math.floor(pose.yaw)&4095;
  try{
    for(const distance of PLAYER_RECOVERY_EXIT_DISTANCES){
      const position=[pose.position[0]-sin[angle]*distance,pose.position[1],
        pose.position[2]+cos[angle]*distance];
      const ground=sampleNativeTrack(world,pose.sector,...position);
      if(ground.kind!=='road'||!Number.isFinite(ground.height)
        ||Math.abs(ground.height-position[1])>=25)return false;
      // The native broad phase depends on sector, so never use a stale hint
      // for clearance, including when the short exit crosses a boundary.
      if(distance===0&&ground.sector!==pose.sector)return false;
      const candidate={...pose,position,sector:ground.sector};
      if(!rescuePlacementClear(motion.collision,motion.body,candidate))return false;
      for(const corner of footprint(bounds,position,pose.yaw)){
        const support=sampleNativeTrack(world,ground.sector,...corner);
        if(support.kind!=='road'||!Number.isFinite(support.height)
          ||Math.abs(support.height-position[1])>=25)return false;
      }
    }
    return true;
  }catch{return false;}
}

const planarDistance=(a,b)=>Math.hypot(a.position[0]-b.position[0],a.position[2]-b.position[2]);
function sameSectorNotAhead(world,pose,reference){
  if(pose.sector!==reference.sector)return true;
  const forward=world.sectors[reference.sector].forward;
  return (pose.position[0]-reference.position[0])*forward[0]
    +(pose.position[2]-reference.position[2])*forward[2]<=0;
}
function result(pose,distance,finishArmed){
  return {...pose,position:[...pose.position],previousSector:pose.sector,safetyFallback:true,
    recoveryDistance:distance,recoveryFinishArmed:Boolean(finishArmed)};
}

/** Select only a previously passed same-lap pose or a nearby authored road
 * position behind the reference. No state, occupancy, timers or RNG are written.
 */
export function selectPlayerRecoveryDestination({track,world,motion,recovery}){
  const reference=recovery?.reference;
  if(!validPose(track,reference)||!Number.isInteger(reference.lapCount)||reference.lapCount<0
    ||!Number.isFinite(reference.distance)||!Number.isFinite(reference.lapStartDistance))return {blocked:true};
  const reversedBeforeStart=reference.distance<reference.lapStartDistance;
  const safe=pose=>planarDistance(pose,reference)>=PLAYER_RECOVERY_MIN_DISTANCE
    &&isSafePlayerRecoveryPose({track,world,motion},pose);
  const usable=pose=>sameSectorNotAhead(world,pose,reference)&&safe(pose);
  for(const anchor of recovery.anchors??[]){
    if(!validPose(track,anchor)||anchor.lapCount!==reference.lapCount||!Number.isFinite(anchor.distance))continue;
    if(reversedBeforeStart){
      // Reversing past this lap's start can put every known-good pose ahead.
      // A recorded pose was already visited: restore it without giving back
      // any progress or arming a finish that this return would bypass.
      if(safe(anchor)){
        const ahead=anchor.distance>reference.distance||!sameSectorNotAhead(world,anchor,reference);
        return result(anchor,Math.min(reference.distance,anchor.distance),!ahead&&anchor.finishArmed);
      }
      continue;
    }
    if(anchor.distance<reference.lapStartDistance||anchor.distance>reference.distance)continue;
    if(usable(anchor))return result(anchor,anchor.distance,anchor.finishArmed);
  }
  if(reversedBeforeStart)return {blocked:true}; // No invented forward fallback.
  const count=track.route.length;
  // Try the nearest sectors first, but do not wait forever at tracks where
  // twelve sectors contain no fully supported return (Italy17/18). The wider
  // search remains within this lap and strictly below half a circuit.
  const maxBehind=Math.min(Math.floor((count-1)/2),Math.floor(reference.distance-reference.lapStartDistance));
  const candidates=[];
  for(let waypoint=0;waypoint<track.drive.length;waypoint++){
    if(track.drive[waypoint].unknown[1]===50)continue;
    let pose;
    try{pose=nativeRescueDestinationAtWaypoint(track,world,waypoint);}catch{continue;}
    const behind=(reference.sector-pose.sector+count)%count;
    if(behind>maxBehind||!validPose(track,pose))continue;
    candidates.push({pose,behind,distance:planarDistance(pose,reference)});
  }
  candidates.sort((a,b)=>a.behind-b.behind||a.distance-b.distance||a.pose.waypoint-b.pose.waypoint);
  for(const {pose,behind} of candidates)if(usable(pose))
    return result(pose,reference.distance-behind,false);
  return {blocked:true};
}

