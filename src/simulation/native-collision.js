import { nativeTrigTable } from './native-integrator.js';
import { applyNativeKartContact } from './native-kart-contact.js';
const f32 = Math.fround;
/** 0x491d30 contact dispatch after response, including its directed pair latch order. */
export function finishNativeContactStep(body, contact, impulse = 0) {
  if (!contact) { body.contactLatch = false; return; }
  const firstBody = contact.firstBody ?? body, secondBody = contact.secondBody;
  const event = { ...contact, firstBody, secondBody, impulse,
    contactType: secondBody ? 1 : 0 };
  if (body.onCollision && !body.contactLatch) body.onCollision(event);
  body.contactLatch = true;
  firstBody.contactLatch = true;
  if (secondBody?.onCollision && !secondBody.contactLatch) {
    secondBody.onCollision(event);
    secondBody.contactLatch = true;
  }
}
/** Static rail impulse, original 0x49c220. Contact coordinates/normals are in body space. */
export function applyNativeRailContact(body, contact, { precision = 24 } = {}) {
  const r = precision === 24 ? f32 : Number;
  const [nx,ny,nz] = contact.normal;
  const px = f32(r(contact.point[0] * f32(.1)));
  const pz = f32(r(contact.point[2] * f32(.1)));
  const vx = f32(r(f32(r(body.yawRate * -pz)) + body.lateralSpeed));
  const vz = f32(r(f32(r(body.yawRate * px)) + body.forwardSpeed));
  const incoming = r(r(vx * nx) + r(vz * nz));
  let impulse = 0;
  if (incoming > 0 || (body.inverseMass === 0 && body.inverseInertia === 0)) return { impulse, impulseWritten: false };
  impulse = -r(r(body.restitution + 1) * incoming);
  if (body.inverseMass !== 0) impulse = r(impulse / body.inverseMass);
  const velocityImpulse = r(body.inverseMass * impulse);
  const lever = f32(r(r(nx * -pz) + r(nz * px)));
  let angularImpulse = r(r(r(body.inverseInertia * impulse) * lever) * f32(.34));
  angularImpulse = Math.max(-6,Math.min(6,angularImpulse));
  body.lateralSpeed = f32(r(f32(r(velocityImpulse * nx)) + body.lateralSpeed));
  body.verticalSpeed = f32(r(f32(r(velocityImpulse * ny)) + body.verticalSpeed));
  body.forwardSpeed = f32(r(f32(r(velocityImpulse * nz)) + body.forwardSpeed));
  body.yawRate = f32(r(r(angularImpulse * f32(.25)) + body.yawRate));
  body.pitchRate = f32(r(r(r(r(body.inverseMass * nz) * impulse) * 16) + (body.pitchRate ?? 0)));
  body.rollRate = f32(r((body.rollRate ?? 0) - r(r(r(body.inverseMass * nx) * impulse) * 16)));
  body.verticalSpeed = f32(r(r(body.inverseMass * impulse) * f32(1.5)));
  return { impulse: f32(impulse) };
}

/** Native Liang–Barsky helper 0x49a7f0, including its inside-to-inside case. */
export function nativePointRectangleSweep(start, end, bounds, { precision = 24 } = {}) {
  const r = precision === 24 ? f32 : Number;
  const dx = f32(r(end[0] - start[0])), dz = f32(r(end[2] - start[2]));
  if (dx === 0 && dz === 0) return { fraction: 1, edge: null };
  const distances = p => [f32(r(p[2] - bounds[2])), f32(r(bounds[3] - p[0])), f32(r(bounds[5] - p[2])), f32(r(p[0] - bounds[0]))];
  const first = distances(start);
  if (first.every(v => v > 0)) {
    if (distances(end).every(v => v > 0)) return { fraction: 0, edge: first.indexOf(Math.min(...first)) };
    return { fraction: 1, edge: null };
  }
  let low = 0, high = 1, edge = null;
  const pairs = [[dx, r(bounds[0] - start[0]),3],[-dx,r(start[0] - bounds[3]),1],[dz,r(bounds[2] - start[2]),0],[-dz,r(start[2] - bounds[5]),2]];
  for(const [p,q,e] of pairs) {
    if(p === 0) { if(q > 0) return {fraction:1,edge:null}; continue; }
    const t = f32(r(f32(q) / p));
    if(p < 0) {
      if(t < low) return {fraction:1,edge:null};
      if(t < high) high=t;
    } else {
      if(high < t) return {fraction:1,edge:null};
      if(low < t) { low=t; edge=e; }
    }
  }
  return low>0 ? {fraction:low,edge} : {fraction:1,edge:null};
}

export function nativeRectangleVertices(rect) {
  const y=rect.minY??0;
  return [[rect.minX,y,rect.minZ],[rect.maxX,y,rect.minZ],[rect.maxX,y,rect.maxZ],[rect.minX,y,rect.maxZ]];
}
function rotateNativePoint(point, angle, precision) {
  const r = precision===24 ? f32 : Number;
  const {sin,cos}=nativeTrigTable(precision), a=angle&4095;
  return [f32(r(r(cos[a]*point[0])-r(sin[a]*point[2]))),point[1],f32(r(r(sin[a]*point[0])+r(cos[a]*point[2])))];
}
/** Directed moving-corner sweep 0x49a120; movement is in obstacle local space. */
export function nativeRectangleSweep(obstacle, moving, movement, {precision=24}={}) {
  const r=precision===24?f32:Number;
  const vertices=nativeRectangleVertices(moving).map(point=>{
    const world=rotateNativePoint(point,moving.angle,precision);
    for(let k=0;k<3;k++) world[k]=f32(r(r(moving.position[k]-obstacle.position[k])+world[k]));
    return rotateNativePoint(world,-obstacle.angle,precision);
  });
  let minX=f32(9999.9),maxX=f32(-9999.9),minZ=minX,maxZ=maxX;
  for(const v of vertices){
    minX=Math.min(minX,v[0],f32(r(v[0]+movement[0])));maxX=Math.max(maxX,v[0],f32(r(v[0]+movement[0])));
    minZ=Math.min(minZ,v[2],f32(r(v[2]+movement[2])));maxZ=Math.max(maxZ,v[2],f32(r(v[2]+movement[2])));
  }
  if(r(maxX+1)<obstacle.minX||obstacle.maxX<r(minX-1)||r(maxZ+1)<obstacle.minZ||obstacle.maxZ<r(minZ-1)) return {fraction:1,edge:null,vertex:null};
  const bounds=[obstacle.minX,0,obstacle.minZ,obstacle.maxX,0,obstacle.maxZ];
  let best={fraction:Infinity,edge:null,vertex:null};
  for(let i=0;i<4;i++){
    const v=vertices[i],end=v.map((x,k)=>f32(r(x+movement[k])));
    const result=nativePointRectangleSweep(v,end,bounds,{precision});
    if(result.fraction<best.fraction)best={...result,vertex:i};
  }
  return best.fraction<1?best:{fraction:1,edge:null,vertex:null};
}

/** CMP rail constructor 0x49ced0/0x4997f0. Source delta is a direction/length. */
export function nativeRailRectangle(record, {precision=24}={}) {
  const r=precision===24?f32:Number;
  const dx=record.delta[0], dz=record.delta[2];
  const length=f32(Math.sqrt(r(r(dx*dx)+r(dz*dz))));
  const nx=f32(r(dx/length)),nz=f32(r(dz/length));
  const yaw=f32(r(r(r(Math.atan2(nz,nx)-r(f32(Math.PI)*.5))*4096)/f32(2*Math.PI)));
  return {minX:-10,maxX:0,minZ:-1,maxZ:f32(r(length+1)),position:record.position,angle:yaw>0?Math.ceil(yaw):Math.floor(yaw),type:0};
}
function rectangleInSpace(obstacle,moving,precision) {
  const r=precision===24?f32:Number;
  return nativeRectangleVertices(moving).map(v=>{
    const p=rotateNativePoint(v,moving.angle,precision);
    for(let k=0;k<3;k++)p[k]=f32(r(r(moving.position[k]-obstacle.position[k])+p[k]));
    return rotateNativePoint(p,-obstacle.angle,precision);
  });
}
/** Native 0x49a480 strict corner-inside test (tested in both directions by caller). */
export function nativeRectangleOverlap(obstacle,moving,{precision=24}={}) {
  return rectangleInSpace(obstacle,moving,precision).some(p=>p[0]>obstacle.minX&&p[0]<obstacle.maxX&&p[2]>obstacle.minZ&&p[2]<obstacle.maxZ);
}
function contactNormal(rect,edge,angle,precision) {
  const r=precision===24?f32:Number,v=nativeRectangleVertices(rect),a=v[edge],b=v[(edge+1)%4];
  const dx=f32(r(b[0]-a[0])),dz=f32(r(b[2]-a[2]));
  const len=f32(Math.sqrt(r(r(dx*dx)+r(dz*dz))));
  const {sin,cos}=nativeTrigTable(precision),i=angle&4095;
  return [f32(r(r(cos[i]*r(dz/len))+r(sin[i]*r(dx/len)))),0,f32(-r(r(cos[i]*r(dx/len))-r(sin[i]*r(dz/len))))];
}

/** Original rail and dynamic rectangle sweeps, preserving candidate order. */
export class NativeRailCollision {
  constructor(track,bounds,{precision=24}={}) {
    this.track=track;this.bounds=bounds;this.precision=precision;
    this.rails=track.collision.map(c=>nativeRailRectangle(c,{precision}));
    this.bodies=[];
    this.contactState={impulse:0};
  }
  candidates(sector,body) {
    const n=this.track.route.length,result=[];
    if (!body.ignoreRails) for(let d=-1;d<=1;d++) for(const index of this.track.route[((sector+d)%n+n)%n].collisionIndices) result.push(this.rails[index]);
    // 0x499b20 appends active objects in creation order after the three sectors
    // of rails. 0x493a40 uses the shortest absolute wrapped sector difference.
    for(const candidate of this.bodies){
      if(candidate===body||candidate===body.sourceBody||candidate.collisionDisabled||candidate.active===false
        ||body.ignoredBodies?.includes(candidate))continue;
      const difference=Math.abs(sector-candidate.sector);
      if(Math.min(difference,n-difference)>=10)continue;
      result.push({... (candidate.bounds??this.bounds),position:candidate.position,
        angle:candidate.yaw>0?Math.ceil(candidate.yaw):Math.floor(candidate.yaw),body:candidate});
    }
    return result;
  }
  sweep(body,dt) {
    const precision=this.precision,r=precision===24?f32:Number;
    if(body.lateralSpeed===0&&body.forwardSpeed===0&&body.yawRate===0) return {fraction:0,stopYaw:true,contact:null};
    const moving={...(body.bounds??this.bounds),position:[body.x,body.y,body.z],angle:body.yaw>0?Math.ceil(body.yaw):Math.floor(body.yaw)};
    const rails=this.candidates(body.sector??0,body);let fraction=1,contact=null;
    for(const rail of rails){
      const {sin,cos}=nativeTrigTable(precision),i=(moving.angle-rail.angle)&4095;
      const velocity=[r(r(cos[i]*body.lateralSpeed)-r(sin[i]*body.forwardSpeed)),0,f32(r(r(cos[i]*body.forwardSpeed)+r(sin[i]*body.lateralSpeed)))];
      const delta=[f32(r(r(velocity[0]*dt)*10)),0,f32(r(f32(r(velocity[2]*dt))*10))];
      const a=nativeRectangleSweep(rail,moving,delta,{precision});
      if(a.fraction<fraction){
        fraction=a.fraction;
        contact={point:nativeRectangleVertices(moving)[a.vertex],normal:contactNormal(rail,a.edge,rail.angle-moving.angle,precision)};
        if(rail.body)Object.assign(contact,{firstBody:body,secondBody:rail.body});
      }
      const backwards=[f32(-r(r(body.lateralSpeed*dt)*10)),f32(-r(f32(r((body.verticalSpeed??0)*dt))*10)),f32(-r(f32(r(body.forwardSpeed*dt))*10))];
      const b=nativeRectangleSweep(moving,rail,backwards,{precision});
      if(b.fraction<fraction){
        fraction=b.fraction;
        contact={point:nativeRectangleVertices(rail)[b.vertex],
          normal:rail.body?contactNormal(moving,b.edge,moving.angle-rail.angle,precision):contactNormal(moving,b.edge,0,precision).map(x=>-x)};
        if(rail.body)Object.assign(contact,{firstBody:rail.body,secondBody:body});
      }
    }
    const {sin,cos}=nativeTrigTable(precision),i=moving.angle&4095;
    const velocity=[r(r(cos[i]*body.lateralSpeed)-r(sin[i]*body.forwardSpeed)),0,f32(r(r(sin[i]*body.lateralSpeed)+r(cos[i]*body.forwardSpeed)))];
    const amount=f32(r(r(fraction*dt)*10));
    const yawDelta=f32(r(r(r(body.yawRate*4096)*dt)/f32(2*Math.PI)));
    const predicted={...moving,position:[f32(r(moving.position[0]+r(velocity[0]*amount))),moving.position[1],f32(r(moving.position[2]+r(velocity[2]*amount)))],angle:moving.angle+(body.yawRate>0?Math.ceil(yawDelta):Math.floor(yawDelta))};
    const stopYaw=body.yawRate!==0&&rails.some(rail=>nativeRectangleOverlap(rail,predicted,{precision})||nativeRectangleOverlap(predicted,rail,{precision}));
    return {fraction,stopYaw,contact};
  }
  /** 0x492470 second sweep provides a sliding displacement but restores body velocity. */
  sample(body,deltaSeconds) {
    const precision=this.precision,r=precision===24?f32:Number,dt=f32(deltaSeconds);
    const result=this.sweep(body,dt);
    if(result.fraction===0||!result.contact)return result;
    const n=result.contact.normal;
    const dot=r(r(r(n[1]*(body.verticalSpeed??0))+r(body.forwardSpeed*n[2]))+r(n[0]*body.lateralSpeed));
    if(dot>0)return result;
    const push=-r(dot-10);
    const trial={...body,sourceBody:body,lateralSpeed:f32(r(body.lateralSpeed+f32(r(n[0]*push)))),verticalSpeed:f32(r((body.verticalSpeed??0)+f32(r(n[1]*push)))),forwardSpeed:f32(r(body.forwardSpeed+r(n[2]*push)))};
    const second=this.sweep(trial,dt);
    result.stopYaw ||= second.stopYaw;
    result.velocityOverride=[trial.lateralSpeed,trial.verticalSpeed,trial.forwardSpeed].map(x=>f32(r(second.fraction*x)));
    return result;
  }
  resolve(body,contact){
    const result = contact.secondBody
      ?applyNativeKartContact(contact.firstBody,contact.secondBody,contact,{precision:this.precision})
      :applyNativeRailContact(body,contact,{precision:this.precision});
    // 49c6d0 clears only contact-active; a skipped rail response leaves the
    // shared impulse at6a5b80 untouched. The race supplies one state to all bodies.
    if(result.impulseWritten!==false)this.contactState.impulse=result.impulse;
    return result;
  }
  finishStep(body, contact) {
    finishNativeContactStep(body, contact, this.contactState.impulse);
  }
}
