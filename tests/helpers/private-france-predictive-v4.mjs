// Private controller: candidate futures own their scalar state. Sweeps query
// the original colliders without resolving contacts or writing game bodies.
import {calculateNativePlayerForces} from '../../source/simulation/native-player.js';
import {integrateNativeEuler,quantizeNativePlanarVelocity,nativeIntegrationSchedule} from '../../source/simulation/native-integrator.js';
import {selectNativeSector,sampleNativeTrack} from '../../source/simulation/native-track.js';
const wrap=value=>Math.atan2(Math.sin(value),Math.cos(value));
export function predictSteering(motion,target,input,{frames=12,slipWeight=0,rateWeight=1,turnGain=1,allowBrake=true}={}){
  const live=motion.body,angle=live.yaw*Math.PI/2048;
  const targetAngle=Math.atan2(-(target[0]-live.x),target[2]-live.z);
  const error=wrap(targetAngle-angle+Math.atan2(live.lateralSpeed,Math.max(1,live.forwardSpeed)));
  const distance=Math.max(5,Math.hypot(target[0]-live.x,target[2]-live.z)/10);
  const desiredRate=turnGain*2*Math.hypot(live.forwardSpeed,live.lateralSpeed)*Math.sin(error)/distance;
  const schedule=nativeIntegrationSchedule(.025);
  let best=Infinity,choice={steer:input.steer,throttle:input.throttle,brake:input.brake};
  for(const brake of (allowBrake?[0,.6]:[0]))for(let steer=-100;steer<=100;steer+=10){
    const body={sourceBody:live,sector:live.sector,x:live.x,y:live.y,z:live.z,yaw:live.yaw,
      lateralSpeed:live.lateralSpeed,forwardSpeed:live.forwardSpeed,
      verticalSpeed:0,yawRate:live.yawRate,mass:live.mass,inverseMass:live.inverseMass,inverseInertia:live.inverseInertia};
    let rpm=motion.rpm,gear=motion.gear,cost=0;
    for(let frame=0;frame<frames;frame++){
      const controls={steering:steer,throttle:brake?0:100,brake:brake*100,handbrake:false};
      const force=calculateNativePlayerForces(body,motion.physics,controls,.025,
        {...motion.upgrades,rpm,gear,matrix14:live.matrix[1],matrix34:live.matrix[7]});
      if(![force.lateralForce,force.longitudinalForce,force.torque].every(Number.isFinite))
        throw new Error('Invalid private prediction');
      rpm=force.rpm;gear=force.gear;
      const hit=motion.collision.sweep(body,.025);
      if(hit.contact||hit.stopYaw){cost+=10000*(1+(frames-frame)/frames);break;}
      quantizeNativePlanarVelocity(body);
      for(let step=0;step<schedule.count;step++)integrateNativeEuler(body,force,schedule.dt);
      body.sector=selectNativeSector(motion.world,body.sector,body.x,body.z);
      const ground=sampleNativeTrack(motion.world,body.sector,body.x,body.y,body.z);
      if(ground.kind==='fallback'){cost+=10000*(1+(frames-frame)/frames);break;}
      body.y=ground.height;
      const slip=Math.atan2(body.lateralSpeed,Math.max(1,body.forwardSpeed));
      cost+=(frame+1)/frames*(rateWeight*(body.yawRate-desiredRate)**2+slipWeight*slip*slip);
    }
    cost+=.000001*steer*steer+.2*Math.max(0,live.forwardSpeed-body.forwardSpeed);
    if(cost<best){best=cost;choice={steer:steer/100,throttle:brake?0:1,brake};}
  }
  return choice;
}
