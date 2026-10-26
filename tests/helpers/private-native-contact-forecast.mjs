// Private test-driver forecast only. Other bodies retain their observed poses
// while copied velocities may respond to predicted contact. This is not a
// whole-race AI/scenery prediction, and no result is written into the race.
import {NativeGroundClock} from '../../source/simulation/native-ground.js';
import {sampleNativeTrack} from '../../source/simulation/native-track.js';
import {NativeRailCollision} from '../../source/simulation/native-collision.js';
import {nativeAnalogFromNormalized} from '../../source/simulation/native-input.js';

export class PrivateDynamicContact extends Error {}
function bodyCopy(body) {
  const copy=Object.defineProperties({},Object.getOwnPropertyDescriptors(body));
  copy.position=[...body.position];
  if(body.matrix)copy.matrix=[...body.matrix];
  if(body.bounds)copy.bounds={...body.bounds};
  copy.onCollision=undefined;
  copy.contactLatch=false;
  return copy;
}
export function copyPlayerForRailForecast(motion) {
  const copy=Object.assign(Object.create(Object.getPrototypeOf(motion)),motion);
  const bodies=new Map([[motion.body,bodyCopy(motion.body)]]);
  for(const body of motion.collision.bodies)
    if(!bodies.has(body))bodies.set(body,bodyCopy(body));
  for(const [original,body] of bodies){
    body.sourceBody=original.sourceBody?bodies.get(original.sourceBody):undefined;
    if(original.ignoredBodies)body.ignoredBodies=original.ignoredBodies.map(other=>bodies.get(other)).filter(Boolean);
  }
  copy.body=bodies.get(motion.body);
  copy.controls={...motion.controls};copy.upgrades={...motion.upgrades};
  copy.ground={...motion.ground,wheels:motion.ground.wheels.map(w=>({...w,local:[...w.local],position:w.position&&[...w.position]}))};
  copy.groundClock=new NativeGroundClock(motion.groundClock.delta);
  copy.prepared=null;copy.mirrored=false;
  copy.railContacts=0;copy.railImpulse=0;copy.dynamicContacts=0;copy.dynamicImpulse=0;
  const source=motion.collision;
  const collision=Object.assign(Object.create(Object.getPrototypeOf(source)),source,{
    contactState:{impulse:source.contactState.impulse},
    bodies:source.bodies.map(body=>bodies.get(body)),
  });
  const privateBodies=new Set(bodies.values());
  collision.resolve=(body,contact)=>{
    if(!privateBodies.has(body)||contact.secondBody&&
      (!privateBodies.has(contact.firstBody)||!privateBodies.has(contact.secondBody)))
      throw new Error('Private contact forecast may never resolve against a source body');
    const response=NativeRailCollision.prototype.resolve.call(collision,body,contact);
    const kind=contact.secondBody?'dynamic':'rail';
    copy[`${kind}Contacts`]++;copy[`${kind}Impulse`]+=Math.abs(response.impulse??0);
    return response;
  };
  collision.finishStep=()=>{};
  copy.collision=collision;
  copy.sampleGround=(x,y,z)=>sampleNativeTrack(copy.world,copy.body.sector,x,y,z).height;
  return copy;
}
export function advancePrivateRailFrame(copy,input,dt=.025) {
  copy.prepare({},dt,{analog:nativeAnalogFromNormalized(input)});
  return copy.integrate();
}
