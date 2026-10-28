import {nativeTrigTable} from './native-integrator.js';
import {NATIVE_PRECISION} from './native-precision.js';

const f32=Math.fround;

/**
 * 0x49b9c0: paired kart impulse. Contact point and normal are expressed in
 * first-body coordinates, in original geometry units. This intentionally keeps
 * the original asymmetry: both final vertical speeds use second.inverseMass.
 */
export function applyNativeKartContact(first,second,contact,{precision=NATIVE_PRECISION}={}) {
  const r=precision===24?f32:Number,{sin,cos}=nativeTrigTable(precision);
  const firstAngle=Math.trunc(first.yaw),secondAngle=Math.trunc(second.yaw);
  // storeZ=false: the original keeps the second component on the x87 stack.
  const rotate=(x,z,angle,storeZ=true)=>{
    const second=r(r(x*sin[angle&4095])+r(z*cos[angle&4095]));
    return [f32(r(r(x*cos[angle&4095])-r(z*sin[angle&4095]))),storeZ?f32(second):second];
  };
  const [nx,nz]=rotate(contact.normal[0],contact.normal[2],firstAngle),ny=contact.normal[1];
  const [ax,az]=rotate(f32(r(contact.point[0]*f32(.1))),f32(r(contact.point[2]*f32(.1))),firstAngle);
  const bx=f32(r(f32(r(f32(r(first.position[0]-second.position[0]))*f32(.1)))+ax));
  const bz=f32(r(f32(r(f32(r(first.position[2]-second.position[2]))*f32(.1)))+az));
  const [avx,avz]=rotate(first.lateralSpeed,first.forwardSpeed,firstAngle);
  const [bvx,bvz]=rotate(second.lateralSpeed,second.forwardSpeed,secondAngle);
  // Native leaves three Y stack slots unwritten: both velocity Y inputs (read
  // at 0x49bd3b/0x49bdca) and the rotated normal's Y, which the impulse reads
  // at 0x49bea9 instead of the record normal's Y (that only reaches the unused
  // lever Y). In the composed engine that slot holds the low dword of the
  // floor(yaw) double left by 0x4911a0, which is zero below 2^21 heading units,
  // so the term is zero. Here ny*0 gives the same zero for the planar record
  // normals. Do not substitute vertical body velocity or the normal's Y here.
  const va=[f32(r(f32(r(first.yawRate*-az))+avx)),0,
    f32(r(f32(r(first.yawRate*ax))+avz))];
  const vb=[f32(r(f32(r(second.yawRate*-bz))+bvx)),0,
    f32(r(f32(r(second.yawRate*bx))+bvz))];
  const relative=va.map((value,i)=>f32(r(value-vb[i])));
  let impulse=f32(-r(r(r(r(relative[2]*nz)+r(ny*relative[1]))+r(relative[0]*nx))*
    r(r(r(second.restitution+first.restitution)*f32(.5))+1)));
  // Register values at 53-bit: mass sum 0x49bec5, a·m 0x49bef4, b·m 0x49bf2d,
  // daz 0x49c03b, bnz 0x49c190 and B's angular term 0x49bf5e..0x49c0eb.
  // Stored floats: levers 0x49be1a/0x49be32 and A's angular term 0x49bf5a.
  const inverseMass=r(second.inverseMass+first.inverseMass);
  if(inverseMass!==0)impulse=f32(r(impulse/inverseMass));
  const aImpulse=r(first.inverseMass*impulse),bImpulse=r(second.inverseMass*impulse);
  const [dax,daz]=rotate(f32(r(aImpulse*nx)),f32(r(aImpulse*nz)),-firstAngle,false);
  const [dbx,dbz]=rotate(f32(r(bImpulse*nx)),f32(r(bImpulse*nz)),-secondAngle);
  const aAngular=Math.max(-6,Math.min(6,f32(r(r(r(first.inverseInertia*impulse)*
    f32(r(r(r(nx*-az)+r(ax*nz))+0)))*f32(.34)))));
  const bAngular=Math.max(-6,Math.min(6,r(r(r(second.inverseInertia*impulse)*
    f32(r(r(r(nx*-bz)+r(nz*bx))+0)))*f32(.34))));
  first.lateralSpeed=f32(r(dax+first.lateralSpeed));
  first.forwardSpeed=f32(r(daz+first.forwardSpeed));
  second.lateralSpeed=f32(r(second.lateralSpeed-dbx));
  second.forwardSpeed=f32(r(second.forwardSpeed-dbz));
  first.yawRate=f32(r(aAngular+first.yawRate));
  second.yawRate=f32(r(second.yawRate-bAngular));
  first.pitchRate=f32(r(r(r(r(first.inverseMass*contact.normal[2])*impulse)*16)+(first.pitchRate??0)));
  first.rollRate=f32(r((first.rollRate??0)-r(r(r(first.inverseMass*contact.normal[0])*impulse)*16)));
  const [bnx,bnz]=rotate(nx,nz,-secondAngle,false);
  second.pitchRate=f32(r((second.pitchRate??0)-r(r(r(second.inverseMass*bnz)*impulse)*16)));
  second.rollRate=f32(r(r(r(r(second.inverseMass*bnx)*impulse)*16)+(second.rollRate??0)));
  first.verticalSpeed=second.verticalSpeed=f32(r(r(second.inverseMass*impulse)*f32(1.5)));
  return {impulse};
}
