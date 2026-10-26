// Test-only native player copies. World data are read-only; no real body or
// shared contact callback is ever passed to a resolving forecast.
import {NativeGroundClock} from '../../source/simulation/native-ground.js';
import {sampleNativeTrack} from '../../source/simulation/native-track.js';
import {applyNativeRailContact} from '../../source/simulation/native-collision.js';
import {nativeAnalogFromNormalized} from '../../source/simulation/native-input.js';
export class PrivateDynamicContact extends Error {}
export function copyPlayerForRailForecast(motion) {
  const copy=Object.assign(Object.create(Object.getPrototypeOf(motion)),motion);
  copy.body=Object.defineProperties({},Object.getOwnPropertyDescriptors(motion.body));
  copy.body.position=[...motion.body.position];copy.body.matrix=[...motion.body.matrix];
  copy.body.onCollision=undefined;copy.body.contactLatch=false;
  copy.controls={...motion.controls};copy.upgrades={...motion.upgrades};
  copy.ground={...motion.ground,wheels:motion.ground.wheels.map(w=>({...w,local:[...w.local],position:w.position&&[...w.position]}))};
  copy.groundClock=new NativeGroundClock(motion.groundClock.delta);
  copy.prepared=null;copy.mirrored=false;copy.railContacts=0;copy.railImpulse=0;
  const source=motion.collision;
  const collision=Object.assign(Object.create(Object.getPrototypeOf(source)),source,{contactState:{impulse:0},
    bodies:source.bodies.filter(b=>b!==motion.body).map(b=>({...b,position:[...b.position],bounds:b.bounds&&{...b.bounds},onCollision:undefined}))});
  const nativeSample=source.sample;
  collision.sample=(body,dt)=>{
    const contact=nativeSample.call(collision,body,dt);
    if(contact?.contact?.secondBody)throw new PrivateDynamicContact('Private forecast reached another body');
    return contact;
  };
  collision.resolve=(body,contact)=>{
    const response=applyNativeRailContact(body,contact,{precision:collision.precision});
    copy.railContacts++;copy.railImpulse+=Math.abs(response.impulse??0);
    return response;
  };
  collision.finishStep=()=>{};
  copy.collision=collision;
  copy.sampleGround=(x,y,z)=>sampleNativeTrack(copy.world,copy.body.sector,x,y,z).height;
  return copy;
}
export function advancePrivateRailFrame(copy,input,dt=.025) {
  // Reuse the actual player prepare/integrate methods: wheel pose, controls,
  // forces, wheel pose; quantization; eight sample→Euler→matrix→response steps;
  // then sector selection and the original wheel-ground callback.
  copy.prepare({},dt,{analog:nativeAnalogFromNormalized(input)});
  return copy.integrate();
}
