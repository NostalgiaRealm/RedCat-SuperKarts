import {selectNativeSector} from './native-track.js';
import {nativeTrigTable} from './native-integrator.js';
import {nativeRotationMatrix} from './native-transform.js';
import {createNativeGroundState} from './native-ground.js';
import {rescuePlacementClear,rescuePlacementOverlapsPlayer,safeRescueAlternative} from './rescue-safety.js';
import {nativeRescueDestinationAtWaypoint,selectPlayerRecoveryDestination} from './player-recovery-position.js';
import {NATIVE_PRECISION} from './native-precision.js';
export {nativeRescueNearestSector,nativeRescueHeading,nativeRescueDestinationAtWaypoint} from './player-recovery-position.js';

const f32 = Math.fround;
export const NATIVE_RESCUE_SHRINK = Object.freeze(
  [1.2, 1.4, 1.2, 1, .9, .85, .8, .7, .65, .6, .55, .5, .45, .4, .35, .3, .25, .2, .15, .1].map(f32));
export const NATIVE_RESCUE_GROW = Object.freeze([...NATIVE_RESCUE_SHRINK].reverse());
const positionOf = body => body.position ?? [body.x, body.y, body.z];
const stop = body => { body.lateralSpeed = body.verticalSpeed = body.forwardSpeed = 0; };
// 0x48ca60 -> 0x4a17c0 multiplies by diag(s, s, s, 1); each entry's sum ends
// with the +0 product of column 3, so a -0 entry stores +0.
const scaleRescueMatrix = (matrix, scale, r) => matrix.map(value => f32(r(value * scale)) + 0);

/** 0x48c030/0x494b70: marker50 and strict height above the selected route plane. */
export function nativeEnvironmentRescueRequired(track, world, body, {precision = NATIVE_PRECISION} = {}) {
  const r = precision === 24 ? f32 : Number, [x, y, z] = positionOf(body);
  const sector = selectNativeSector(world, body.sector, x, z);
  const {normal, distance} = world.sectors[sector].fallback;
  const height = r(r(r(distance - r(x * normal[0])) - r(z * normal[2])) / normal[1]);
  return track.drive[body.waypoint]?.unknown[1] === 50 && r(y - height) < 1.5;
}

/** 0x48bf80 scans array slots, wrapping; it does not follow waypoint links. */
export function nativeEnvironmentRescueWaypoint(track, start, direction = 0) {
  if (!track.drive[start]) return -1;
  let index = start;
  do {
    index = (index + (direction === 1 ? -1 : 1) + track.drive.length) % track.drive.length;
    if (track.drive[index].unknown[1] === 51) return index;
  } while (index !== start);
  return -1;
}

/** 0x48c170: planar 2000-unit squared exclusion, including equality. */
export function nativeRescuePositionFree(body, position, occupants, {precision = NATIVE_PRECISION} = {}) {
  const r = precision === 24 ? f32 : Number;
  return occupants.every(other => {
    if (other === body || (body.id !== undefined && other.id === body.id)) return true;
    // dx is stored (0x48c261); dz stays in ST0 (0x48c2af..0x48c2b8).
    const p = positionOf(other), x = f32(r(p[0] - position[0])), z = r(p[2] - position[2]);
    return r(r(x * x) + r(z * z)) > 2000;
  });
}

/** 0x404be0 differs from the NPC path-direction selector 0x40ed40. */
export function nativeRescueNextWaypoint(track, index, deltaSeconds) {
  const links = track.drive[index]?.links;
  if (!links) return -1;
  if (links[0] !== -1) return links[0];
  const order = (Math.trunc(f32(deltaSeconds)) & 1) ? [2, 1] : [1, 2];
  return links[order[0]] !== -1 ? links[order[0]] : links[order[1]] !== -1 ? links[order[1]] : index;
}

/** 0x48d930 checks six nodes ahead, then five...zero. Final fallback is kept. */
function rescueWaypointResult(track, start, body, {
  deltaSeconds = 0, occupied = new Set(), occupants = [], precision = NATIVE_PRECISION,
} = {}) {
  if (!track.drive[start]) throw new RangeError(`Invalid native respawn waypoint ${start}`);
  const has = index => occupied instanceof Map ? (occupied.get(index)?.length ?? 0) !== 0 : occupied.has(index);
  let candidate = start;
  for (let ahead = 6; ahead >= 0; ahead--) {
    candidate = start;
    for (let step = 0; step < ahead; step++) candidate = nativeRescueNextWaypoint(track, candidate, deltaSeconds);
    const node = track.drive[candidate];
    if (!node) throw new RangeError(`Native respawn selected absent waypoint ${candidate}`);
    const next = node.links[0], previous = node.links[3];
    if (!has(candidate) && (next === -1 || !has(next)) && (previous === -1 || !has(previous)) &&
        nativeRescuePositionFree(body, node.position, occupants, {precision})) return {waypoint: candidate, free: true};
  }
  return {waypoint: candidate, free: false};
}

export function nativeRescueWaypoint(track, start, body, options = {}) {
  return rescueWaypointResult(track, start, body, options).waypoint;
}

/** 0x493430/0x48d930/0x450690/0x493540/0x430ff0 normal recovery branch. */
export function nativeRescueDestination(track, world, body, options = {}) {
  const {british = 0, direction = 0, precision = NATIVE_PRECISION, environment = false} = options;
  let waypoint;
  if (environment) {
    waypoint = nativeEnvironmentRescueWaypoint(track, body.waypoint);
    if (waypoint < 0) return null;
    if (!nativeRescuePositionFree(body, track.drive[waypoint].position, options.occupants ?? [], options))
      return {blocked: true};
  } else {
    const side = (direction === 0 ? british === 1 : british !== 1) ? 0 : 1;
    const route = track.route[body.sector], lanes = side ? route.driveIndices : route.driveLeftIndices;
    const selected = rescueWaypointResult(track, lanes[0] ?? 0, body, options);
    // 48d930 returns AL=1 even after exhausting all candidates.
    waypoint = selected.waypoint;
  }
  return nativeRescueDestinationAtWaypoint(track,world,waypoint,{precision});
}

/** 0x48c9a0: record position and stop linear velocities; angular rates survive. */
export function createNativeRescue(body, driver = null, {environment = false,softLock} = {}) {
  stop(body);
  if (driver?.state) driver.state.blockRecovery = true;
  return {body, driver, environment, origin: [...positionOf(body)], frame: 0, shrinking: true,
    finished: false, scale: 1, angle: 0, matrix: [...body.matrix],
    renderPosition: [...positionOf(body)], sounds: [],
    ...(softLock?{softLock:structuredClone(softLock)}:{})};
}

/** One original outer-game tick (0x48ca60), independent of elapsed duration. */
export function updateNativeRescue(entry, deltaSeconds, {
  resolveDestination, precision = NATIVE_PRECISION, effectsEnabled = true,
} = {}) {
  if (entry.finished) return entry;
  const body = entry.body, r = precision === 24 ? f32 : Number;
  stop(body);
  entry.renderPosition = [...positionOf(body)];
  entry.sounds = [];
  entry.relocated = false;
  if (entry.frame === 3) entry.sounds.push(entry.shrinking ? 'DISAPP' : 'REAPP');
  if (!entry.shrinking && entry.frame === 0) {
    if (typeof resolveDestination !== 'function') throw new TypeError('Native recovery requires a destination resolver');
    const destination = resolveDestination(body);
    entry.destination = destination;
    if (destination?.blocked) {
      entry.frame = 19;
      entry.shrinking = true;
      entry.scale = NATIVE_RESCUE_SHRINK[19];
      entry.matrix = scaleRescueMatrix(body.matrix, entry.scale, r);
      return entry;
    }
    if (destination) {
      body.position.splice(0, 3, ...destination.position);
      body.sector = destination.sector;
      if (destination.previousSector !== undefined) body.previousSector = destination.previousSector;
      if(entry.softLock){body.previousSector=body.sector;body.waypoint=destination.waypoint;}
      body.yaw = destination.yaw;
      if(destination.safetyFallback){
        body.pitch=body.roll=body.pitchRate=body.rollRate=body.yawRate=0;
        body.matrix=nativeRotationMatrix([0,body.yaw,0],{precision});
        const driver=entry.driver;
        if(driver?.ground?.wheels){
          const restored=createNativeGroundState(body,driver.ground.wheels);
          restored.wheels.forEach((wheel,index)=>{
            const previous=driver.ground.wheels[index];
            previous.position=wheel.position;
            previous.position[1]=f32((driver.sampleGround?.(...wheel.position)??body.position[1])+previous.radius);
            previous.verticalSpeed=0;
            if(entry.softLock)previous.steeringAngle=0;
          });
          driver.groundInitialized=true;
          driver.ground.groundCount=4;
          driver.ground.playerContact=true;
        }
        body.contactLatch=false;
        entry.safetyFallback=true;
      }
      if(entry.softLock&&entry.driver){
        Object.assign(entry.driver,{controls:{throttle:0,brake:0,steering:0,handbrake:false},
          gear:0,rpm:0,slipMagnitude:0,lowSpeedTurn:false,prepared:null});
      }
      entry.relocated = true;
    }
  }
  entry.scale = (entry.shrinking ? NATIVE_RESCUE_SHRINK : NATIVE_RESCUE_GROW)[entry.frame];
  entry.matrix = scaleRescueMatrix(body.matrix, entry.scale, r);
  if (++entry.frame === 20) {
    entry.frame = 0;
    if (entry.shrinking) entry.shrinking = false;
    else {
      entry.shrinking = true;
      entry.finished = true;
      body.forwardSpeed = entry.softLock?0:5;
      if(entry.softLock)body.pitchRate=body.rollRate=body.yawRate=0;
    }
  }
  if (effectsEnabled) {
    // Preserve the original reciprocal sequence and its precision boundaries.
    const delta = f32(deltaSeconds);
    const angle = r(r(r(60 / r(1 / delta)) * 60) + entry.angle);
    entry.angle = f32(angle > 4096 ? r(angle - 4096) : angle);
  }
  return entry;
}

/**
 * 0x48dc30 queue (maximum ten, no duplicate physical object), 0x48db00 update,
 * 0x48db30 post-render retirement. Call after every actor's ordinary motion.
 * NPC recovery-mode resets stay in prepareNativeAIRecovery, its original caller.
 */
export class NativeRescueController {
  constructor({track, world, occupants = () => [], occupancy, playerSafety, ...options}) {
    Object.assign(this, {track, world, occupants, occupancy, playerSafety, options});
    this.entries = [];
    this.playerOverlapDeferrals=0;
  }
  get(body) {
    return this.entries.find(entry => entry.body === body ||
      (body.id !== undefined && entry.body.id === body.id));
  }
  enqueue(driver, options = {}) {
    const body = driver.body ?? driver;
    // 0x48dce0/0x48dc30 test the cap of 10 before scanning for a duplicate.
    if (this.entries.length >= 10) return null;
    const existing = this.get(body);
    if (existing) return existing;
    const entry = createNativeRescue(body, driver.body ? driver : null, options);
    // 0x48dd51/0x48dca1 insert at begin(); 0x48db00 then updates newest first.
    this.entries.unshift(entry);
    return entry;
  }
  checkEnvironment(driver) {
    const body = driver.body ?? driver;
    if (nativeEnvironmentRescueRequired(this.track, this.world, body, this.options))
      return this.enqueue(driver, {environment: true});
    return null;
  }
  step(deltaSeconds) {
    for (const entry of this.entries) {
      if(entry.safetyBlocked)entry.safetyWaitSeconds=(entry.safetyWaitSeconds??0)+Math.max(0,deltaSeconds);
      updateNativeRescue(entry, deltaSeconds, {
        ...this.options,
        resolveDestination: body => {
          if(entry.softLock){
            const destination=selectPlayerRecoveryDestination({track:this.track,world:this.world,
              motion:entry.driver,recovery:entry.softLock});
            entry.safetyBlocked=Boolean(destination.blocked);
            return destination;
          }
          const destination=nativeRescueDestination(this.track,this.world,body,{
            ...this.options,environment:entry.environment,deltaSeconds,occupants:this.occupants(),
            occupied:this.occupancy?.nodes??new Set(),
          });
          const safety=this.playerSafety;
          if(!safety)return destination;
          if(body!==safety.body){
            // Authorized safety exception: native2000-distance clearance can
            // put a returning NPC's rectangle inside the player, freezing both.
            // Wait at the native return; leave NPC/NPC clearance unchanged.
            entry.playerOverlapBlocked=rescuePlacementOverlapsPlayer(safety.collision,body,destination,safety.body);
            if(entry.playerOverlapBlocked){
              this.playerOverlapDeferrals++;
              return {blocked:true};
            }
            return destination;
          }
          if(rescuePlacementClear(safety.collision,body,destination)){
            entry.safetyBlocked=false;
            return destination;
          }
          entry.safetyBlocked=true;
          if((entry.safetyWaitSeconds??0)<2)return {blocked:true};
          const waypoint=entry.environment?nativeEnvironmentRescueWaypoint(this.track,body.waypoint)
            :destination?.waypoint??body.waypoint;
          if(waypoint<0)return {blocked:true};
          const alternative=safeRescueAlternative({
            track:this.track,world:this.world,body,collision:safety.collision,
            reference:nativeRescueDestinationAtWaypoint(this.track,this.world,waypoint,this.options),
            destinationForWaypoint:index=>nativeRescueDestinationAtWaypoint(this.track,this.world,index,this.options),
            environmentRequired:probe=>nativeEnvironmentRescueRequired(this.track,this.world,probe,this.options),
          });
          if(!alternative.blocked)entry.safetyBlocked=false;
          return alternative;
        },
      });
      // Recheck at full size: another kart can enter during the grow animation.
      const safety=this.playerSafety;
      const destination={position:entry.body.position,sector:entry.body.sector,yaw:entry.body.yaw};
      const playerBlocked=entry.finished&&safety&&entry.body===safety.body&&
        !rescuePlacementClear(safety.collision,entry.body,destination);
      const npcBlocked=entry.finished&&safety&&entry.body!==safety.body&&
        rescuePlacementOverlapsPlayer(safety.collision,entry.body,destination,safety.body);
      if(playerBlocked||npcBlocked){
        entry.finished=false;
        entry.frame=0;
        entry.shrinking=true;
        if(playerBlocked)entry.safetyBlocked=true;
        if(npcBlocked){entry.playerOverlapBlocked=true;this.playerOverlapDeferrals++;}
        stop(entry.body);
      }
    }
    return this.entries;
  }
  /** 0x48db30 walks the original count, including stale slots past the
   * shrinking end, and copies back() over each finished slot without
   * re-checking it. On a stale slot the original copies back() even when that
   * is another entry, dropping it with its flag set; this retires only the
   * stale slot's own entry, so an unfinished rescue is never dropped. */
  finishRender() {
    const storage = [...this.entries], count = storage.length;
    let live = count;
    for (let i = 0; i < count; i++) {
      const entry = storage[i];
      if (!entry.finished) continue;
      if (entry.driver?.state) entry.driver.state.blockRecovery = false;
      const index = i < live ? i : storage.indexOf(entry);
      if (index < live) storage[index] = storage[--live];
    }
    this.entries = storage.slice(0, live);
  }
}

/** Recovered 0x48c370 seven vertices and 0x48d610 matrix sequence. */
export function nativeRescueRingPositions(entry, {precision = NATIVE_PRECISION} = {}) {
  const r = precision === 24 ? f32 : Number;
  const {sin, cos} = nativeTrigTable(precision);
  const vertices = [[-.5, -.5], [-.5, .5], [.5, -.5], [.5, .5], [.5, -.5], [-.5, .5], [-.5, -.5]];
  const output = [];
  const car = [
    ...entry.matrix.slice(0, 3), 0, ...entry.matrix.slice(3, 6), 0,
    ...entry.matrix.slice(6, 9), 0, ...entry.renderPosition, 1,
  ];
  const multiply = (a, b) => Array.from({length: 16}, (_, i) => {
    const row = Math.floor(i / 4), col = i % 4;
    let sum = 0;
    for (let k = 0; k < 4; k++) sum = r(r(a[row * 4 + k] * b[k * 4 + col]) + sum);
    return f32(sum);
  });
  for (let ring = 0; ring < 20; ring++) {
    const index = Math.trunc(r(entry.angle + ring * 408)) & 4095;
    const s = sin[index], c = cos[index];
    const rotation = [c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1];
    const translate = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, (ring + 1) * 2, -40, 1];
    const scale = [10, 0, 0, 0, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
    const matrix = multiply(multiply(scale, multiply(translate, rotation)), car);
    for (const [x, y] of vertices) {
      for (let axis = 0; axis < 3; axis++) {
        output.push(f32(r(r(r(r(x * matrix[axis]) + r(y * matrix[4 + axis])) + r(0 * matrix[8 + axis])) + matrix[12 + axis])));
      }
    }
  }
  return output;
}
