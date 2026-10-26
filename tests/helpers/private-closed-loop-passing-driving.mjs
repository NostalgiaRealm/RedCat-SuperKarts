// Test controller only: forecast copies never write actual race state.
import {createRouteTrafficForecast} from './private-route-traffic-forecast.mjs';
import {calculateNativePlayerForces} from '../../source/simulation/native-player.js';
import {tireLateralForce,resistanceForce} from '../../source/simulation/native-forces.js';
import {integrateNativeEuler,quantizeNativePlanarVelocity,nativeIntegrationSchedule} from '../../source/simulation/native-integrator.js';
import {selectNativeSector,sampleNativeTrack} from '../../source/simulation/native-track.js';
const wrap=v=>Math.atan2(Math.sin(v),Math.cos(v)),clamp=(v,a,b)=>Math.max(a,Math.min(b,v));
function project(track,line,b){
  let best=null,offset=0;
  for(let i=0;i<line.length-1;i++){
    const a=track.drive[line[i].node].position,z=track.drive[line[i+1].node].position;
    const dx=z[0]-a[0],dz=z[2]-a[2],length=Math.hypot(dx,dz);
    if([b.sector,b.sector+track.route.length].some(s=>s>=line[i].sector-2&&s<=line[i+1].sector+2)){
      const fraction=clamp(((b.x-a[0])*dx+(b.z-a[2])*dz)/(length*length),0,1);
      const cross=Math.hypot(b.x-a[0]-fraction*dx,b.z-a[2]-fraction*dz);
      if(!best||cross<best.cross)best={i,fraction,cross,progress:offset+fraction*length};
    }
    offset+=length;
  }
  return {...best,total:offset};
}
function targetAt(track,line,projection,distance,offset){
  let remaining=distance;
  for(let k=0;k<line.length;k++){
    const i=(projection.i+k)%(line.length-1),a=track.drive[line[i].node].position,z=track.drive[line[i+1].node].position;
    const fraction=k?0:projection.fraction,length=Math.hypot(z[0]-a[0],z[2]-a[2]),available=length*(1-fraction);
    if(remaining<=available){const t=fraction+remaining/length;return[a[0]+(z[0]-a[0])*t+(z[2]-a[2])/length*offset,0,a[2]+(z[2]-a[2])*t-(z[0]-a[0])/length*offset];}
    remaining-=available;
  }
  throw new Error('Forecast line target unavailable');
}
function command(motion,b,target,maxSpeed){
  const p=motion.physics,u=motion.upgrades;
  const desired=Math.atan2(-(target[0]-b.x),target[2]-b.z),error=wrap(desired-b.yaw*Math.PI/2048+Math.atan2(b.lateralSpeed,Math.max(1,b.forwardSpeed)));
  const distance=Math.max(5,Math.hypot(target[0]-b.x,target[2]-b.z)/10);
  const desiredRate=2*b.forwardSpeed*Math.sin(error)/distance;
  const desiredTorque=(desiredRate-b.yawRate)/.1/b.inverseInertia;
  const resistance=resistanceForce(b,p,{tireUpgrade:u.tireUpgrade,handbrake:false,matrix14:motion.body.matrix[1],matrix34:motion.body.matrix[7]});
  let best=Infinity,steering=0;
  for(let s=-100;s<=100;s+=10){
    const front=tireLateralForce(b,p,'front',s,u.tireUpgrade,false),rear=tireLateralForce(b,p,'rear',s,u.tireUpgrade,false);
    const torque=-front*p.frontAxleDistance+rear*p.rearAxleDistance-resistance.lateral*p.frontAxleDistance;
    const cost=Math.abs(torque-desiredTorque);
    if(cost<best){best=cost;steering=s;}
  }
  const speed=maxSpeed/(1+Math.abs(error));
  return{steer:steering/100,throttle:clamp((speed-b.forwardSpeed)*.2,0,1),brake:b.forwardSpeed>speed+2?clamp((b.forwardSpeed-speed)*.1,0,1):0,handbrake:0};
}
export function predictCandidates(motion,track,line,{frames=48,lookaheads=[.4,.7,1],speeds=[50,75,120],offsets=[-60,0,60],opponents=[]}={}){
  const live=motion.body,start=project(track,line,live),schedule=nativeIntegrationSchedule(.025);
  const traffic=createRouteTrafficForecast(motion,track,opponents);
  let best=Infinity,choice=null,selection=null,allCandidatesBlocked=true;
  for(const look of lookaheads)for(const speed of speeds)for(const offset of offsets){
    const b={sourceBody:live,sector:live.sector,x:live.x,y:live.y,z:live.z,yaw:live.yaw,lateralSpeed:live.lateralSpeed,forwardSpeed:live.forwardSpeed,verticalSpeed:0,yawRate:live.yawRate,mass:live.mass,inverseMass:live.inverseMass,inverseInertia:live.inverseInertia};
    let rpm=motion.rpm,gear=motion.gear,cost=0,first=null,position=start,blocked=false;
    for(let frame=0;frame<frames;frame++){
      position=project(track,line,b);
      const target=targetAt(track,line,position,40+Math.abs(b.forwardSpeed)*10*look,offset),input=command(motion,b,target,speed);
      first??=input;
      const controls={steering:input.steer*100,throttle:input.throttle*100,brake:input.brake*100,handbrake:false};
      const force=calculateNativePlayerForces(b,motion.physics,controls,.025,{...motion.upgrades,rpm,gear,matrix14:live.matrix[1],matrix34:live.matrix[7]});
      rpm=force.rpm;gear=force.gear;
      traffic.advance(frame*.025);
      const hit=traffic.collision.sweep(b,.025);
      if(hit.contact||hit.stopYaw){blocked=true;cost+=10000+(frames-frame)*100;break;}
      quantizeNativePlanarVelocity(b);
      for(let j=0;j<schedule.count;j++)integrateNativeEuler(b,force,schedule.dt);
      b.sector=selectNativeSector(motion.world,b.sector,b.x,b.z);
      const ground=sampleNativeTrack(motion.world,b.sector,b.x,b.y,b.z);
      if(ground.kind==='fallback'){blocked=true;cost+=10000+(frames-frame)*100;break;}
      b.y=ground.height;
      cost+=position.cross*position.cross*.00003+(ground.kind==='road'?0:1);
    }
    if(!blocked)allCandidatesBlocked=false;
    position=project(track,line,b);let progress=position.progress-start.progress;
    if(progress<-start.total/2)progress+=start.total;
    if(progress>start.total/2)progress-=start.total;
    cost-=progress*.2;
    cost+=position.cross*position.cross*.001;
    if(cost<best){best=cost;choice=first;selection={look,speed,offset,cost,progress,blocked};}
  }
  return{input:choice,selection,allCandidatesBlocked};
}

export function executeClosedLoopPolicy(motion,track,line,selection){
  const b=motion.body,position=project(track,line,b);
  const target=targetAt(track,line,position,40+Math.abs(b.forwardSpeed)*10*selection.look,selection.offset);
  return command(motion,b,target,selection.speed);
}

/** Only widen passing targets after every standard forecast reports contact/fallback. */
export function choosePassingForecast(evaluate,options={}) {
  const standard=evaluate(options);
  if(!standard.allCandidatesBlocked)return {...standard,fallbackTested:false,
    selection:{...standard.selection,passingFallbackTested:false}};
  const wide=evaluate({...options,offsets:[-140,-100,100,140]});
  const chosen=wide.selection.cost<standard.selection.cost?wide:standard;
  return {...chosen,fallbackTested:true,standardAllBlocked:true,
    selection:{...chosen.selection,passingFallbackTested:true,standardAllBlocked:true}};
}
export function predictClosedLoop(motion,track,line,options={}) {
  return choosePassingForecast(value=>predictCandidates(motion,track,line,value),options);
}
