import { nativeTrigTable, NATIVE_SIN, NATIVE_COS } from './native-integrator.js';
import { applyNativeKartContact } from './native-kart-contact.js';
import { NATIVE_PRECISION } from './native-precision.js';
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
export function applyNativeRailContact(body, contact, { precision = NATIVE_PRECISION } = {}) {
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

let hitFraction = 1, hitEdge = null;
/** Native Liang–Barsky helper 0x49a7f0, including its inside-to-inside case. Result in hitFraction/hitEdge. */
function pointSweep(sx, sz, ex, ez, minX, minZ, maxX, maxZ, precision) {
  const r = precision === 24 ? f32 : Number;
  hitFraction = 1; hitEdge = null;
  const dx = f32(r(ex - sx)), dz = f32(r(ez - sz));
  if (dx === 0 && dz === 0) return;
  const d0 = f32(r(sz - minZ)), d1 = f32(r(maxX - sx)), d2 = f32(r(maxZ - sz)), d3 = f32(r(sx - minX));
  if (d0 > 0 && d1 > 0 && d2 > 0 && d3 > 0) {
    if (f32(r(ez - minZ)) > 0 && f32(r(maxX - ex)) > 0 && f32(r(maxZ - ez)) > 0 && f32(r(ex - minX)) > 0) {
      const least = Math.min(d0, d1, d2, d3);
      hitFraction = 0; hitEdge = d0 === least ? 0 : d1 === least ? 1 : d2 === least ? 2 : 3;
    }
    return;
  }
  let low = 0, high = 1, edge = null;
  for (let i = 0; i < 4; i++) {
    const p = i === 0 ? dx : i === 1 ? -dx : i === 2 ? dz : -dz;
    const q = i === 0 ? r(minX - sx) : i === 1 ? r(sx - maxX) : i === 2 ? r(minZ - sz) : r(sz - maxZ);
    if (p === 0) { if (q > 0) return; continue; }
    // 0x49a750 compares the quotient in ST0 and rounds it only on store.
    const t = r(f32(q) / p);
    if (p < 0) {
      if (t < low) return;
      if (t < high) high = f32(t);
    } else {
      if (high < t) return;
      if (low < t) { low = f32(t); edge = i === 0 ? 3 : i === 1 ? 1 : i === 2 ? 0 : 2; }
    }
  }
  if (low > 0) { hitFraction = low; hitEdge = edge; }
}
export function nativePointRectangleSweep(start, end, bounds, { precision = NATIVE_PRECISION } = {}) {
  pointSweep(start[0], start[2], end[0], end[2], bounds[0], bounds[2], bounds[3], bounds[5], precision);
  return { fraction: hitFraction, edge: hitEdge };
}

export function nativeRectangleVertices(rect) {
  const y=rect.minY??0;
  return [[rect.minX,y,rect.minZ],[rect.maxX,y,rect.minZ],[rect.maxX,y,rect.maxZ],[rect.minX,y,rect.maxZ]];
}
// Obstacle-local X/Z of the moving rectangle's four corners, as the float stores
// of 0x49a120/0x49a480 leave them. Y never reaches a result.
const cornerX = new Float64Array(4), cornerZ = new Float64Array(4);
function cornersInObstacle(obstacle, moving, precision) {
  const r = precision === 24 ? f32 : Number, a = moving.angle & 4095, b = -obstacle.angle & 4095;
  const ca = NATIVE_COS[a], sa = NATIVE_SIN[a], cb = NATIVE_COS[b], sb = NATIVE_SIN[b];
  const dx = r(moving.position[0] - obstacle.position[0]), dz = r(moving.position[2] - obstacle.position[2]);
  for (let i = 0; i < 4; i++) {
    const x = i === 0 || i === 3 ? moving.minX : moving.maxX, z = i < 2 ? moving.minZ : moving.maxZ;
    const wx = f32(r(dx + f32(r(r(ca * x) - r(sa * z))))), wz = f32(r(dz + f32(r(r(sa * x) + r(ca * z)))));
    cornerX[i] = f32(r(r(cb * wx) - r(sb * wz)));
    cornerZ[i] = f32(r(r(sb * wx) + r(cb * wz)));
  }
}
const MISS = Object.freeze({fraction:1,edge:null,vertex:null});
const BOX_MIN = f32(9999.9), BOX_MAX = f32(-9999.9);
function rectangleSweep(obstacle, moving, moveX, moveZ, precision) {
  const r = precision === 24 ? f32 : Number;
  cornersInObstacle(obstacle, moving, precision);
  let minX = BOX_MIN, maxX = BOX_MAX, minZ = minX, maxZ = maxX;
  for (let i = 0; i < 4; i++) {
    const x = cornerX[i], z = cornerZ[i], ex = f32(r(x + moveX)), ez = f32(r(z + moveZ));
    minX = Math.min(minX, x, ex); maxX = Math.max(maxX, x, ex);
    minZ = Math.min(minZ, z, ez); maxZ = Math.max(maxZ, z, ez);
  }
  if (r(maxX + 1) < obstacle.minX || obstacle.maxX < r(minX - 1) || r(maxZ + 1) < obstacle.minZ || obstacle.maxZ < r(minZ - 1)) return MISS;
  let fraction = Infinity, edge = null, vertex = null;
  for (let i = 0; i < 4; i++) {
    const x = cornerX[i], z = cornerZ[i];
    pointSweep(x, z, f32(r(x + moveX)), f32(r(z + moveZ)), obstacle.minX, obstacle.minZ, obstacle.maxX, obstacle.maxZ, precision);
    if (hitFraction < fraction) { fraction = hitFraction; edge = hitEdge; vertex = i; }
  }
  return fraction < 1 ? {fraction, edge, vertex} : MISS;
}
/** Directed moving-corner sweep 0x49a120; movement is in obstacle local space. */
export function nativeRectangleSweep(obstacle, moving, movement, {precision=NATIVE_PRECISION}={}) {
  return rectangleSweep(obstacle, moving, movement[0], movement[2], precision);
}

/** CMP rail constructor 0x49ced0/0x4997f0. Source delta is a direction/length. */
export function nativeRailRectangle(record, {precision=NATIVE_PRECISION}={}) {
  const r=precision===24?f32:Number;
  const dx=record.delta[0], dz=record.delta[2];
  const length=f32(Math.sqrt(r(r(dx*dx)+r(dz*dz))));
  const nx=f32(r(dx/length)),nz=f32(r(dz/length));
  const yaw=f32(r(r(r(Math.atan2(nz,nx)-r(f32(Math.PI)*.5))*4096)/f32(2*Math.PI)));
  return {minX:-10,maxX:0,minZ:-1,maxZ:f32(r(length+1)),position:record.position,angle:yaw>0?Math.ceil(yaw):Math.floor(yaw),type:0};
}
function rectangleOverlap(obstacle,moving,precision) {
  cornersInObstacle(obstacle,moving,precision);
  for(let i=0;i<4;i++){
    const x=cornerX[i],z=cornerZ[i];
    if(x>obstacle.minX&&x<obstacle.maxX&&z>obstacle.minZ&&z<obstacle.maxZ)return true;
  }
  return false;
}
/** Native 0x49a480 strict corner-inside test (tested in both directions by caller). */
export function nativeRectangleOverlap(obstacle,moving,{precision=NATIVE_PRECISION}={}) {
  return rectangleOverlap(obstacle,moving,precision);
}
function contactNormal(rect,edge,angle,precision) {
  const r=precision===24?f32:Number,v=nativeRectangleVertices(rect),a=v[edge],b=v[(edge+1)%4];
  const dx=f32(r(b[0]-a[0])),dz=f32(r(b[2]-a[2]));
  const len=f32(Math.sqrt(r(r(dx*dx)+r(dz*dz))));
  const {sin,cos}=nativeTrigTable(precision),i=angle&4095;
  return [f32(r(r(cos[i]*r(dz/len))+r(sin[i]*r(dx/len)))),0,f32(-r(r(cos[i]*r(dx/len))-r(sin[i]*r(dz/len))))];
}

const RESTING = Object.freeze({fraction:0,stopYaw:true,contact:null});
// One sweep at a time: nothing below keeps these past its own sweep().
const NEARBY = [], RECTANGLES = [];
const MOVING = {minX:0,maxX:0,minZ:0,maxZ:0,minY:0,position:[0,0,0],angle:0};
const PREDICTED = {minX:0,maxX:0,minZ:0,maxZ:0,minY:0,position:[0,0,0],angle:0};
const NEAR_SLACK = 2;
const TRIAL = {x:0,y:0,z:0,yaw:0,yawRate:0,sector:0,bounds:undefined,ignoreRails:undefined,ignoredBodies:undefined,sourceBody:null,lateralSpeed:0,verticalSpeed:0,forwardSpeed:0};
const boundsRadius = b => Math.sqrt(Math.max(b.minX*b.minX,b.maxX*b.maxX)+Math.max(b.minZ*b.minZ,b.maxZ*b.maxZ));
/** False only if every corner of either rectangle, with its travel, stays clear of the other. */
function pairNear(rect,x,z,reach){
  const p=rect.position,a=-rect.angle&4095,c=NATIVE_COS[a],s=NATIVE_SIN[a],dx=x-p[0],dz=z-p[2];
  const lx=c*dx-s*dz,lz=s*dx+c*dz;
  // The moving rectangle's corners, in the obstacle's frame (0x49a120's +1 box).
  if(!(lx<rect.minX-reach-1||lx>rect.maxX+reach+1||lz<rect.minZ-reach-1||lz>rect.maxZ+reach+1))return true;
  // The obstacle's own corners, in the moving rectangle's frame. NaN stays near.
  return !(Math.min(Math.abs(lx-rect.minX),Math.abs(lx-rect.maxX))>reach||Math.min(Math.abs(lz-rect.minZ),Math.abs(lz-rect.maxZ))>reach);
}

/** Original rail and dynamic rectangle sweeps, preserving candidate order. */
export class NativeRailCollision {
  constructor(track,bounds,{precision=NATIVE_PRECISION}={}) {
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
    const lateral=body.lateralSpeed,forward=body.forwardSpeed,yawRate=body.yawRate;
    if(lateral===0&&forward===0&&yawRate===0) return RESTING;
    const bounds=body.bounds??this.bounds,moving=MOVING,yaw=body.yaw,x=body.x,z=body.z;
    moving.minX=bounds.minX;moving.maxX=bounds.maxX;moving.minZ=bounds.minZ;moving.maxZ=bounds.maxZ;moving.minY=bounds.minY;
    moving.position[0]=x;moving.position[2]=z;
    moving.angle=yaw>0?Math.ceil(yaw):Math.floor(yaw);
    // A conservative distance filter, never a result: `reach` holds the moving
    // corners, their travel this step and the float rounding around body X/Z.
    // A pair it drops can only return the sweep's miss and the overlap's false.
    const reach=boundsRadius(bounds)+(Math.abs(lateral)+Math.abs(forward))*Math.abs(dt)*10+NEAR_SLACK;
    const nearby=NEARBY,route=this.track.route,n=route.length,sector=body.sector??0;
    let count=0;
    if(!body.ignoreRails) for(let d=-1;d<=1;d++){
      const indices=route[((sector+d)%n+n)%n].collisionIndices;
      for(let i=0;i<indices.length;i++){
        const rail=this.rails[indices[i]];
        if(pairNear(rail,x,z,reach))nearby[count++]=rail;
      }
    }
    // 0x499b20 appends active objects in creation order after the three sectors
    // of rails. 0x493a40 uses the shortest absolute wrapped sector difference.
    const bodies=this.bodies,ignored=body.ignoredBodies,source=body.sourceBody;
    let pooled=0;
    for(let i=0;i<bodies.length;i++){
      const candidate=bodies[i];
      if(candidate===body||candidate===source||candidate.collisionDisabled||candidate.active===false
        ||ignored?.includes(candidate))continue;
      const difference=Math.abs(sector-candidate.sector);
      if(Math.min(difference,n-difference)>=10)continue;
      const rect=RECTANGLES[pooled]??={minX:0,maxX:0,minZ:0,maxZ:0,minY:0,position:null,angle:0,body:null};
      const box=candidate.bounds??this.bounds,candidateYaw=candidate.yaw;
      rect.minX=box.minX;rect.maxX=box.maxX;rect.minZ=box.minZ;rect.maxZ=box.maxZ;rect.minY=box.minY;
      rect.position=candidate.position;rect.angle=candidateYaw>0?Math.ceil(candidateYaw):Math.floor(candidateYaw);rect.body=candidate;
      if(pairNear(rect,x,z,reach)){nearby[count++]=rect;pooled++;}
    }
    let fraction=1,contact=null;
    if(count){
      const backX=f32(-r(r(lateral*dt)*10)),backZ=f32(-r(f32(r(forward*dt))*10));
      for(let k=0;k<count;k++){
        const rail=nearby[k],i=(moving.angle-rail.angle)&4095,sin=NATIVE_SIN[i],cos=NATIVE_COS[i];
        const vx=r(r(cos*lateral)-r(sin*forward)),vz=f32(r(r(cos*forward)+r(sin*lateral)));
        const a=rectangleSweep(rail,moving,f32(r(r(vx*dt)*10)),f32(r(f32(r(vz*dt))*10)),precision);
        if(a.fraction<fraction){
          fraction=a.fraction;
          contact={point:nativeRectangleVertices(moving)[a.vertex],normal:contactNormal(rail,a.edge,rail.angle-moving.angle,precision)};
          if(rail.body)Object.assign(contact,{firstBody:body,secondBody:rail.body});
        }
        const b=rectangleSweep(moving,rail,backX,backZ,precision);
        if(b.fraction<fraction){
          fraction=b.fraction;
          contact={point:nativeRectangleVertices(rail)[b.vertex],
            normal:rail.body?contactNormal(moving,b.edge,moving.angle-rail.angle,precision):contactNormal(moving,b.edge,0,precision).map(x=>-x)};
          if(rail.body)Object.assign(contact,{firstBody:rail.body,secondBody:body});
        }
      }
    }
    let stopYaw=false;
    if(yawRate!==0&&count){
      const i=moving.angle&4095,sin=NATIVE_SIN[i],cos=NATIVE_COS[i];
      const vx=r(r(cos*lateral)-r(sin*forward)),vz=f32(r(r(sin*lateral)+r(cos*forward)));
      const amount=f32(r(r(fraction*dt)*10));
      // 0x499ffc/0x49a009 pass the yaw delta to ceil/floor as a double;
      // 0x499f9f stores z·amount as a float before adding it.
      const yawDelta=r(r(r(yawRate*4096)*dt)/f32(2*Math.PI));
      const predicted=PREDICTED;
      predicted.minX=moving.minX;predicted.maxX=moving.maxX;predicted.minZ=moving.minZ;predicted.maxZ=moving.maxZ;
      predicted.position[0]=f32(r(x+r(vx*amount)));predicted.position[2]=f32(r(z+f32(r(vz*amount))));
      predicted.angle=moving.angle+(yawRate>0?Math.ceil(yawDelta):Math.floor(yawDelta));
      for(let k=0;k<count&&!stopYaw;k++)stopYaw=rectangleOverlap(nearby[k],predicted,precision)||rectangleOverlap(predicted,nearby[k],precision);
    }
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
    const push=-r(dot-10),trial=TRIAL;
    // Everything sweep() reads; the second sweep's contact never leaves sample().
    trial.x=body.x;trial.y=body.y;trial.z=body.z;trial.yaw=body.yaw;trial.yawRate=body.yawRate;trial.sector=body.sector;trial.bounds=body.bounds;
    trial.ignoreRails=body.ignoreRails;trial.ignoredBodies=body.ignoredBodies;trial.sourceBody=body;
    trial.lateralSpeed=f32(r(body.lateralSpeed+f32(r(n[0]*push))));trial.verticalSpeed=f32(r((body.verticalSpeed??0)+f32(r(n[1]*push))));trial.forwardSpeed=f32(r(body.forwardSpeed+r(n[2]*push)));
    const second=this.sweep(trial,dt);
    result.stopYaw ||= second.stopYaw;
    result.velocityOverride=[f32(r(second.fraction*trial.lateralSpeed)),f32(r(second.fraction*trial.verticalSpeed)),f32(r(second.fraction*trial.forwardSpeed))];
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
