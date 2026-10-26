// Explicit port safeguard: use actual planar travel, never wheel/engine speed.
// Eight seconds of attempted driving within roughly one kart length identifies
// a persistent trap while leaving ordinary stops, turns and reversing alone.
export const PLAYER_STUCK_SECONDS=8;
export const PLAYER_STUCK_RADIUS=60;
const separation=(a,b)=>Math.hypot(a[0]-b[0],a[2]-b[2]);

export class PlayerStuckRecovery {
  constructor(){
    this.anchors=[];this.lapCount=0;this.lapStartDistance=0;
    this.recoveries=0;this.lastRecovery=null;this.excludedPickups=new Set();this.reset();
  }
  reset(){this.origin=null;this.attemptSeconds=0;this.idleSeconds=0;}
  observeLap(race){
    if(race.lapCount!==this.lapCount){
      this.lapCount=race.lapCount;this.lapStartDistance=race.distance;
      this.anchors=[];this.reset();
    }
  }
  remember(body,race,isSafe){
    this.observeLap(race);
    const previous=this.anchors[0];
    // Only retain genuinely travelled, separated road poses. A trapped pose
    // cannot overwrite the useful history merely by surviving more frames.
    if(previous&&separation(previous.position,body.position)<100)return;
    const pose={position:[...body.position],yaw:body.yaw,sector:body.sector,
      previousSector:body.sector,waypoint:body.waypoint,distance:race.distance,
      lapCount:race.lapCount,finishArmed:race.finishArmed};
    if(!isSafe(pose))return;
    this.anchors.unshift(pose);this.anchors.length=Math.min(this.anchors.length,32);
  }
  step(body,input,dt,{eligible=true}={}){
    const controls=input.analog??input;
    const throttle=controls.throttle??0,brake=controls.brake??0;
    const driving=Math.abs(throttle-brake)>=.2&&!(throttle>.1&&brake>.1)&&!controls.handbrake;
    if(!eligible||!body.position.every(Number.isFinite)||!(dt>0&&dt<=Math.fround(.1))){
      this.reset();return false;
    }
    if(!driving){
      this.idleSeconds+=dt;
      if(this.idleSeconds>=.75)this.reset();
      return false;
    }
    this.idleSeconds=0;
    if(!this.origin||separation(this.origin,body.position)>PLAYER_STUCK_RADIUS){
      this.origin=[...body.position];this.attemptSeconds=0;
    }
    this.attemptSeconds+=dt;
    return this.attemptSeconds+1e-9>=PLAYER_STUCK_SECONDS;
  }
  request(body,race){
    const reference={position:[...body.position],yaw:body.yaw,sector:body.sector,
      waypoint:body.waypoint,distance:race.distance,lapCount:race.lapCount,
      lapStartDistance:this.lapStartDistance,finishArmed:race.finishArmed};
    return {anchors:this.anchors.map(pose=>({...pose,position:[...pose.position]})),reference};
  }
  started(recovery){
    this.recoveries++;this.lastRecovery={reason:'blocked-driving',reference:recovery.reference};
    this.reset();
  }
  retryAfter(){
    // Recheck a temporarily occupied track once per simulated second while
    // retaining normal controls and appearance until a safe return exists.
    this.attemptSeconds=PLAYER_STUCK_SECONDS-1;
  }
}
