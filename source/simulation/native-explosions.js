import { NATIVE_PRECISION } from './native-precision.js';
const f=Math.fround;
const outerIndices=[0,1,3,4,6,7,9,10,12,13,15,16,18,19,21,22,0,1];
const innerIndices=[2,1,23,22,20,19,17,16,14,13,11,10,8,7,5,4,2,1];

/** The actual rocket particle481ec0, separate from inactive generic485710.
 * Construction takes four CRT draws via483060 even though483fc0 overwrites the
 * random lifetime with.75 seconds. Objects are prepended to the original list.
 */
export class NativeExplosions {
  constructor({random,precision=NATIVE_PRECISION}={}) {
    if(!random?.next)throw new Error('Original shared random stream is required');
    Object.assign(this,{random,precision,entries:[],nextId:0,texture:'s_sfx'});
  }
  add(body) {
    const r=this.precision===24?f:Number;
    const range=(min,max)=>r(r(r(this.random.next()*f(1/32767))*r(max-min))+min);
    range(.5,2);
    const position=[f(r(f(body.position[0])+range(-1,1))),f(body.position[1]),
      f(r(f(body.position[2])+range(-1,1)))];
    range(.75,1.25);
    const entry={id:this.nextId++,body,position,age:0,lifetime:.75,active:true};
    this.entries.unshift(entry);
    return entry;
  }
  /**482020 updates explosion list before weather; follows owner's current XYZ. */
  step(deltaSeconds) {
    const r=this.precision===24?f:Number,dt=f(deltaSeconds);
    for(const entry of this.entries) {
      entry.position=entry.body.position.map(f);
      entry.age=f(r(dt+entry.age));
      if(entry.age>=entry.lifetime)entry.active=false;
    }
    this.entries=this.entries.filter(entry=>entry.active);
  }
  /**4844e0: two indexed triangle strips, world-space, SRCALPHA/ONE blend.
   * Draw after weather with depth writes restored and normal depth testing.
   */
  capture() {
    return this.entries.map(entry=>({id:entry.id,...nativeExplosionGeometry(entry,this.precision)}));
  }
}

export function nativeExplosionGeometry({position,age,lifetime=.75},precision=NATIVE_PRECISION) {
  const r=precision===24?f:Number,vertices=[],uv=[],argb=[];
  const alpha=age<=r(lifetime*.5)?255:255-Math.trunc(r(r(age*255)/lifetime));
  for(let index=0;index<24;index+=3) {
    const angle=r(r(index*f(Math.PI))*f(1/12));
    const sinAge=r(Math.sin(angle)*age),cosAge=r(Math.cos(f(angle))*age);
    const middleY=f(r(r(Math.sin(r(r(f(Math.PI)*age)/lifetime))*15)+position[1]));
    for(const [radius,y,a] of [[200,position[1],0],[150,middleY,alpha],[60,position[1],0]]) {
      vertices.push(f(r(position[0]-r(radius*sinAge))),y,f(r(r(radius*cosAge)+position[2])));
      uv.push(f(.45),f(.15));
      argb.push(a?((a<<24)|0xffaf00)>>>0:0);
    }
  }
  return {vertices,uv,argb,strips:[outerIndices,innerIndices]};
}
