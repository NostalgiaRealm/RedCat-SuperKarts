// Test-only input selection. Each candidate advances an independent complete
// race snapshot. Nothing from a candidate is copied into the actual race.
import {tireLateralForce,resistanceForce} from '../../source/simulation/native-forces.js';
const clamp=(v,a,b)=>Math.max(a,Math.min(b,v));
const wrap=v=>Math.atan2(Math.sin(v),Math.cos(v));
export const WHOLE_RACE_SCORE=Object.freeze({progress:.2,accumulatedCrossSquared:.00003,
  finalCrossSquared:.001,newRescue:10000,expired:10000,finished:-10000,nonfinite:100000});

/** Cache immutable original route coordinates and cumulative lengths only. */
export function createForecastRoute(track,line) {
  let total=0;
  const segments=line.slice(0,-1).map((p,i)=>{
    const q=line[i+1],a=track.drive[p.node].position,b=track.drive[q.node].position;
    const dx=b[0]-a[0],dz=b[2]-a[2],length=Math.hypot(dx,dz);
    if(!(length>0))throw new Error('Forecast route contains a zero-length segment');
    const segment=Object.freeze({startSector:p.sector,endSector:q.sector,
      x:a[0],z:a[2],dx,dz,length,lengthSquared:length*length,progress:total});
    total+=length;return segment;
  });
  const sectorSegments=track.route.map((_,sector)=>Object.freeze(segments.flatMap((s,i)=>
    [sector,sector+track.route.length].some(value=>value>=s.startSector-2&&value<=s.endSector+2)?[i]:[])));
  return Object.freeze({segments:Object.freeze(segments),sectorSegments:Object.freeze(sectorSegments),total});
}

export function projectForecastRoute(route,body) {
  let best=null;
  for(const i of route.sectorSegments[body.sector]??[]) {
    const s=route.segments[i];
    const fraction=clamp(((body.x-s.x)*s.dx+(body.z-s.z)*s.dz)/s.lengthSquared,0,1);
    const cross=Math.hypot(body.x-s.x-fraction*s.dx,body.z-s.z-fraction*s.dz);
    if(!best||cross<best.cross)best={i,fraction,cross,progress:s.progress+fraction*s.length};
  }
  if(!best)throw new Error(`No forecast route segment for sector ${body.sector}`);
  return {...best,total:route.total};
}

export function forecastRouteTarget(route,projection,distance,offset) {
  let remaining=distance;
  for(let k=0;k<=route.segments.length;k++) {
    const s=route.segments[(projection.i+k)%route.segments.length];
    const fraction=k?0:projection.fraction,available=s.length*(1-fraction);
    if(remaining<=available) {
      const t=fraction+remaining/s.length;
      return [s.x+s.dx*t+s.dz/s.length*offset,0,s.z+s.dz*t-s.dx/s.length*offset];
    }
    remaining-=available;
  }
  throw new Error('Forecast route target unavailable');
}

/** Returns ordinary browser-convention input, including original mirroring. */
export function executeWholeRacePolicy(simulation,route,policy) {
  const motion=simulation.motion,b=motion.body,p=motion.physics,u=motion.upgrades;
  const projection=projectForecastRoute(route,b);
  const target=forecastRouteTarget(route,projection,40+Math.abs(b.forwardSpeed)*10*policy.look,policy.offset);
  const desired=Math.atan2(-(target[0]-b.x),target[2]-b.z);
  const error=wrap(desired-b.yaw*Math.PI/2048+Math.atan2(b.lateralSpeed,Math.max(1,b.forwardSpeed)));
  const distance=Math.max(5,Math.hypot(target[0]-b.x,target[2]-b.z)/10);
  const desiredRate=2*b.forwardSpeed*Math.sin(error)/distance;
  const desiredTorque=(desiredRate-b.yawRate)/.1/b.inverseInertia;
  const resistance=resistanceForce(b,p,{tireUpgrade:u.tireUpgrade,handbrake:false,
    matrix14:b.matrix[1],matrix34:b.matrix[7]});
  let best=Infinity,steering=0;
  for(let s=-100;s<=100;s+=10) {
    const front=tireLateralForce(b,p,'front',s,u.tireUpgrade,false);
    const rear=tireLateralForce(b,p,'rear',s,u.tireUpgrade,false);
    const torque=-front*p.frontAxleDistance+rear*p.rearAxleDistance-resistance.lateral*p.frontAxleDistance;
    const cost=Math.abs(torque-desiredTorque);
    if(cost<best){best=cost;steering=s;}
  }
  const targetSpeed=policy.speed/(1+Math.abs(error));
  const throttle=clamp((targetSpeed-b.forwardSpeed)*.2,0,1);
  const brake=b.forwardSpeed>targetSpeed+2?clamp((b.forwardSpeed-targetSpeed)*.1,0,1):0;
  const steer=steering/100*(motion.mirrored?-1:1);
  return {throttle,brake,steer,handbrake:0,bonus:0,analog:{throttle,brake,steer}};
}

export function predictWholeRace(simulation,filter,snapshotter,route,{
  frames=48,lookaheads=[.4,.7,1],speeds=[50,75,120],offsets=[-60,0,60],
  score=WHOLE_RACE_SCORE,
}={}) {
  const started=performance.now(),start=projectForecastRoute(route,simulation.motion.body);
  let best=Infinity,selection=null,cloneMs=0,stepMs=0;
  const candidates=[];
  for(const look of lookaheads)for(const speed of speeds)for(const offset of offsets) {
    const cloning=performance.now(),privateState=snapshotter.clone(simulation,{filter});
    cloneMs+=performance.now()-cloning;
    const copy=privateState.simulation,b=copy.motion.body,policy={look,speed,offset};
    const initialRescue=copy.rescue.get(b);
    let cost=0,newRescue=false,nonfinite=false,executedFrames=0;
    const stepping=performance.now();
    for(let frame=0;frame<frames;frame++) {
      const input=executeWholeRacePolicy(copy,route,policy);
      const wallMs=copy.wallMs+25,engineMs=copy.engineMs+25;
      copy.step(input,privateState.filter.sample(.025),wallMs,{wallMs,engineMs});
      // Match the actual headless harness; all simulation services still ran.
      for(const actor of copy.actors)if(actor.animationEvents)actor.animationEvents.length=0;
      executedFrames++;
      if(copy.actors.some(actor=>![...actor.body.position,actor.body.yaw,
        actor.body.lateralSpeed,actor.body.verticalSpeed,actor.body.forwardSpeed].every(Number.isFinite))) {
        nonfinite=true;cost+=score.nonfinite;break;
      }
      const rescue=copy.rescue.get(b);
      if(rescue&&rescue!==initialRescue&&!newRescue){newRescue=true;cost+=score.newRescue;}
      const point=projectForecastRoute(route,b);
      cost+=point.cross*point.cross*score.accumulatedCrossSquared;
      if(copy.race.phase===3){cost+=score.finished;break;}
      if(copy.race.phase===6){cost+=score.expired;break;}
    }
    stepMs+=performance.now()-stepping;
    let progress=0,cross=Infinity;
    if(!nonfinite) {
      const point=projectForecastRoute(route,b);cross=point.cross;progress=point.progress-start.progress;
      if(progress<-start.total/2)progress+=start.total;
      if(progress>start.total/2)progress-=start.total;
      cost-=progress*score.progress;cost+=cross*cross*score.finalCrossSquared;
    }
    const result={...policy,cost,progress,cross,newRescue,nonfinite,executedFrames,
      finalSector:b.sector,finalSpeed:b.forwardSpeed,phase:copy.race.phase,
      laps:copy.race.lapCount,remainingMs:copy.race.remainingMs};
    candidates.push(result);
    if(cost<best){best=cost;selection=result;}
  }
  if(!selection)throw new Error('No finite whole-race forecast candidate');
  return {selection,candidates,timing:{totalMs:performance.now()-started,cloneMs,stepMs}};
}
