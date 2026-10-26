import {nativeTrigTable} from './native-integrator.js';
import {sampleNativeTrack} from './native-track.js';

// Deliberate player-safety exception to the original rescue clearance.
// SAT also catches edge crossings which the native corner-only test misses.
function corners(rect, margin = 0) {
  const {sin, cos} = nativeTrigTable(), angle = rect.angle & 4095;
  return [[rect.minX-margin, rect.minZ-margin], [rect.maxX+margin, rect.minZ-margin],
    [rect.maxX+margin, rect.maxZ+margin], [rect.minX-margin, rect.maxZ+margin]]
    .map(([x,z]) => [rect.position[0]+cos[angle]*x-sin[angle]*z,
      rect.position[2]+sin[angle]*x+cos[angle]*z]);
}

export function rescueRectanglesOverlap(first, second, margin = 3) {
  const a = corners(first, margin), b = corners(second);
  for (const polygon of [a,b]) for (let i=0;i<2;i++) {
    const p=polygon[i],q=polygon[i+1],axis=[p[1]-q[1],q[0]-p[0]];
    const project=points=>points.map(point=>point[0]*axis[0]+point[1]*axis[1]);
    const x=project(a),y=project(b);
    if (Math.max(...x)<Math.min(...y)||Math.max(...y)<Math.min(...x)) return false;
  }
  return true;
}

export function rescuePlacementClear(collision, body, destination) {
  if (!destination?.position) return false;
  const moving={...(body.bounds??collision.bounds),position:destination.position,
    angle:destination.yaw>0?Math.ceil(destination.yaw):Math.floor(destination.yaw)};
  const query={...body,sourceBody:body,ignoreRails:false};
  return collision.candidates(destination.sector,query)
    .every(obstacle=>!rescueRectanglesOverlap(moving,obstacle));
}

/** An NPC must not materialize inside the player after the player's own rescue
 * has already finished. Keep the native NPC destination and NPC/NPC rules.
 */
export function rescuePlacementOverlapsPlayer(collision,body,destination,player){
  if(!destination?.position)return false;
  const rectangle=(target,position,yaw)=>({
    ...(target.bounds??collision.bounds),position,
    angle:yaw>0?Math.ceil(yaw):Math.floor(yaw),
  });
  return rescueRectanglesOverlap(rectangle(body,destination.position,destination.yaw),
    rectangle(player,player.position,player.yaw));
}

/** Search nearby authored road positions behind the original return point. */
export function safeRescueAlternative({track,world,body,collision,reference,
  destinationForWaypoint,environmentRequired}) {
  const count=track.route.length;
  const candidates=track.drive.map((node,waypoint)=>({node,waypoint,
    distance:Math.hypot(node.position[0]-reference.position[0],node.position[2]-reference.position[2])}))
    .filter(({node})=>node.unknown[1]!==50)
    .sort((a,b)=>a.distance-b.distance||a.waypoint-b.waypoint);
  for (const {waypoint} of candidates) {
    const destination=destinationForWaypoint(waypoint);
    // Do not move further ahead than the native return or shortcut a lap.
    if ((reference.previousSector-destination.previousSector+count)%count>12) continue;
    const probe={...body,position:destination.position,sector:destination.sector,waypoint};
    if (environmentRequired(probe)||!rescuePlacementClear(collision,body,destination)) continue;
    const rectangle={...(body.bounds??collision.bounds),position:destination.position,
      angle:destination.yaw>0?Math.ceil(destination.yaw):Math.floor(destination.yaw)};
    const support=[destination.position,...corners(rectangle).map(([x,z])=>[x,destination.position[1],z])];
    if (!support.every(point=>{
      const ground=sampleNativeTrack(world,destination.sector,...point);
      return ground.kind==='road'&&Math.abs(ground.height-destination.position[1])<25;
    })) continue;
    return {...destination,safetyFallback:true};
  }
  // Never force a placement into a kart, wall or unsupported terrain.
  return {blocked:true};
}
