import {sampleNativeTrack} from './native-track.js';
import {nativeRotationMatrix} from './native-transform.js';
import {createNativeGroundState} from './native-ground.js';
import {rescuePlacementClear} from './rescue-safety.js';

// Explicit browser cheat controls; these are not reconstructed native physics.
export const FREE_FLIGHT_SPEED=650;
export const FREE_FLIGHT_VERTICAL_SPEED=400;
export const FREE_FLIGHT_TURN_SPEED=1.5;
const angleUnit=4096/(Math.PI*2);
const axis=value=>Number.isFinite(value)?Math.max(-1,Math.min(1,value)):0;

export function captureFlightPose(body){
  return {position:[...body.position],yaw:body.yaw,sector:body.sector,
    previousSector:body.sector,waypoint:body.waypoint};
}

export function roadFlightPose(motion,pose=captureFlightPose(motion.body),{clear=false}={}){
  if(!pose.position.every(Number.isFinite)||!Number.isFinite(pose.yaw))return false;
  try{
    const ground=sampleNativeTrack(motion.world,pose.sector,...pose.position);
    return ground.kind==='road'&&Math.abs(ground.height-pose.position[1])<25
      &&(!clear||rescuePlacementClear(motion.collision,motion.body,pose));
  }catch{return false;} // An off-track pose is never a return anchor.
}

export function nearestFlightSector(track,position){
  let nearest=0,distance=Infinity;
  track.route.forEach((entry,index)=>{
    const next=(position[0]-entry.position[0])**2+(position[2]-entry.position[2])**2;
    if(next<distance){nearest=index;distance=next;}
  });
  return nearest;
}

/** Integrate the requested flight arc analytically, independent of render rate. */
export function advanceFreeFlight(motion,input,dt){
  if(!Number.isFinite(dt)||dt<0)throw new RangeError('Flight delta must be finite and nonnegative');
  const body=motion.body,from=body.yaw/angleUnit;
  const turn=-axis(input.steer)*FREE_FLIGHT_TURN_SPEED*(motion.mirrored?-1:1);
  const speed=(axis(input.throttle)-axis(input.brake))*FREE_FLIGHT_SPEED,to=from+turn*dt;
  body.position[0]+=Math.abs(turn)>1e-12?speed*(Math.cos(to)-Math.cos(from))/turn:-Math.sin(from)*speed*dt;
  body.position[2]+=Math.abs(turn)>1e-12?speed*(Math.sin(to)-Math.sin(from))/turn:Math.cos(from)*speed*dt;
  body.position[1]+=axis(input.lift)*FREE_FLIGHT_VERTICAL_SPEED*dt;
  body.yaw=to*angleUnit;body.pitch=body.roll=0;
  body.matrix=nativeRotationMatrix([0,body.yaw,0]);
  for(const key of ['lateralSpeed','verticalSpeed','forwardSpeed','yawRate','pitchRate','rollRate'])body[key]=0;
  motion.controls={throttle:0,brake:0,steering:0,handbrake:false};
  motion.rpm=0;motion.slipMagnitude=0;motion.lowSpeedTurn=false;
  return body;
}

/** Return to supported road, without retaining airborne wheel or angular energy. */
export function restoreFlightPose(motion,pose){
  const body=motion.body;
  body.position.splice(0,3,...pose.position);
  Object.assign(body,{yaw:pose.yaw,sector:pose.sector,previousSector:pose.sector,
    waypoint:pose.waypoint,pitch:0,roll:0,contactLatch:false});
  advanceFreeFlight(motion,{},0);
  motion.gear=0;motion.prepared=null;
  const ground=createNativeGroundState(body,motion.ground.wheels);
  ground.wheels.forEach((wheel,index)=>{
    wheel.position[1]=Math.fround(motion.sampleGround(...wheel.position)+wheel.radius);
    Object.assign(motion.ground.wheels[index],{position:wheel.position,
      verticalSpeed:0,steeringAngle:0});
  });
  motion.ground.groundCount=4;motion.ground.playerContact=true;motion.groundInitialized=true;
}
