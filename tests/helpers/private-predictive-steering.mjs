// Private test controller. Predictions own separate scalar bodies. No live
// simulation state, forces, collision responses, timers or physics is changed.
import {calculateNativePlayerForces} from '../../src/simulation/native-player.js';
import {integrateNativeEuler,quantizeNativePlanarVelocity,nativeIntegrationSchedule} from '../../src/simulation/native-integrator.js';

const wrap=value=>Math.atan2(Math.sin(value),Math.cos(value));
export function predictSteering(motion,target,input,{frames=12,slipWeight=0,rateWeight=1}={}){
  const live=motion.body,angle=live.yaw*Math.PI/2048;
  const targetAngle=Math.atan2(-(target[0]-live.x),target[2]-live.z);
  const error=wrap(targetAngle-angle+Math.atan2(live.lateralSpeed,Math.max(1,live.forwardSpeed)));
  const distance=Math.max(5,Math.hypot(target[0]-live.x,target[2]-live.z)/10);
  const desiredRate=2*Math.hypot(live.forwardSpeed,live.lateralSpeed)*Math.sin(error)/distance;
  const schedule=nativeIntegrationSchedule(.025);
  let best=Infinity,choice=0;
  for(let steer=-100;steer<=100;steer+=4){
    const body={x:live.x,y:live.y,z:live.z,yaw:live.yaw,
      lateralSpeed:live.lateralSpeed,forwardSpeed:live.forwardSpeed,
      verticalSpeed:0,yawRate:live.yawRate,inverseMass:live.inverseMass,inverseInertia:live.inverseInertia};
    let rpm=motion.rpm,gear=motion.gear,cost=0;
    for(let frame=0;frame<frames;frame++){
      const controls={steering:steer,throttle:Math.round(input.throttle*50)*2,
        brake:Math.round(input.brake*50)*2,handbrake:Boolean(input.handbrake)};
      const force=calculateNativePlayerForces(body,motion.physics,controls,.025,
        {...motion.upgrades,rpm,gear,matrix14:live.matrix[1],matrix34:live.matrix[7]});
      rpm=force.rpm;gear=force.gear;
      quantizeNativePlanarVelocity(body);
      for(let step=0;step<schedule.count;step++)integrateNativeEuler(body,force,schedule.dt);
      const slip=Math.atan2(body.lateralSpeed,Math.max(1,body.forwardSpeed));
      cost+=(frame+1)/frames*(rateWeight*(body.yawRate-desiredRate)**2+slipWeight*slip*slip);
    }
    cost+=.000001*steer*steer;
    if(cost<best){best=cost;choice=steer/100;}
  }
  return choice;
}
