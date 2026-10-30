import {nativeTrigTable} from './native-integrator.js';
import {NATIVE_PRECISION} from './native-precision.js';
const f=Math.fround, identity=[1,0,0,0,1,0,0,0,1];
const uvFrames=[
 [.199703,.1634,0,.326801,0,0,.395406,0,.395406,.326801,0,.326801],
 [.199703,.491571,0,.654971,0,.328171,.395406,.328171,.395406,.654971,0,.654971],
 [.199703,.820462,0,.983863,0,.657062,.395406,.657062,.395406,.983863,0,.983863],
].map(values=>values.map(f));
const sortStack=[];
const smokeFrame=()=>({id:0,active:true,position:[0,0,0],matrix:[...identity],velocity:[0,0,0],period:0,tick:0,
 width:0,height:0,alpha:0,uvFrame:0,vertices:new Array(18).fill(0),uv:[...uvFrames[0]],
 rgba:[132,132,164,0,100,100,100,0,100,100,100,0,100,100,100,0,100,100,100,0,100,100,100,0]});

/** Original CRT4bf5b9/4bf70d, including equal-key swaps and small partitions.
 * Smoke sorts ALL70records in place, so sorting also changes later free slots. */
export function nativeSmokeSort(values,compare){
 const stack=sortStack;stack.length=0;stack.push(0,values.length-1);
 while(stack.length){
  let hi=stack.pop(),lo=stack.pop();
  while(lo<hi){
   const count=hi-lo+1;
   if(count<=8){
    for(let end=hi;end>lo;end--){let greatest=lo;
     for(let at=lo+1;at<=end;at++)if(compare(values[at],values[greatest])>0)greatest=at;
     const value=values[greatest];values[greatest]=values[end];values[end]=value;
    }
    break;
   }
   const middle=lo+Math.floor(count/2),pivot=values[middle];values[middle]=values[lo];values[lo]=pivot;
   let left=lo,right=hi+1;
   while(true){
    do{left++;}while(left<=hi&&compare(values[left],values[lo])<=0);
    do{right--;}while(right>lo&&compare(values[right],values[lo])>=0);
    if(left>right)break;
    const value=values[left];values[left]=values[right];values[right]=value;
   }
   const value=values[lo];values[lo]=values[right];values[right]=value;
   if(right-lo-1<hi-left){
    if(left<hi)stack.push(left,hi);
    if(lo+1<right)hi=right-1;else break;
   }else{
    if(lo+1<right)stack.push(lo,right-1);
    if(left<hi)lo=left;else break;
   }
  }
 }
 return values;
}

/** Original cloud pool428690/428490/4282e0/428a00. These are tyre/damage
 * smoke fans using S_SFX, separate from the general particle-system manager. */
// Reused capture storage, kept off the controller: only its live state is race state.
const smokeScratches=new WeakMap();
const smokeScratch=smoke=>{
 let scratch=smokeScratches.get(smoke);
 if(!scratch){
  // Distances are pure between position updates, so compute each once per sort.
  const keys=new Float64Array(70);
  scratch={keys,compare:(a,b)=>{const x=keys[a.id],y=keys[b.id];return x<y?1:x===y?0:-1;},
   framePool:Array.from({length:70},smokeFrame),drawn:[]};
  smokeScratches.set(smoke,scratch);
 }
 return scratch;
};
export class NativeSmoke{
 constructor({random,precision=NATIVE_PRECISION,enabled=true,hardware=true,alphaBlending=true,carIndex=0}={}){
  if(!random?.next)throw new Error('Original shared random stream is required');
  if(carIndex<0||carIndex>8)throw new RangeError('Unverified smoke offset for this original car');
  //4288b0 disables CLOUDS at initialization when accelerated alpha blending
  //is unavailable/disabled. No cloud emission or random draws then take place.
  Object.assign(this,{random,precision,enabled:enabled&&(!hardware||alphaBlending),hardware,carIndex,lastSkidMs:0,lastDamageMs:0});
  this.clouds=Array.from({length:70},(_,id)=>({id,active:false,position:[0,0,0],matrix:[...identity],
   velocity:[0,0,0],period:0,tick:0,width:0,height:0,alpha:80,uvFrame:0}));
 }
 emit(position,velocity,deltaSeconds,cameraMatrix=identity){
  const r=this.precision===24?f:Number,dt=f(deltaSeconds);
  if(!this.enabled||!this.hardware||r(1/dt)<12)return 0;
  let count=0;
  for(let i=0;i<2;i++){
   const cloud=this.clouds.find(value=>!value.active);if(!cloud)break;
   const period=Math.trunc(r(4/dt)),tick=this.random.next()%3;
   const vx=f(r(r(r(this.random.next()*f(7.629627e-6))+f(.75))*velocity[0]));
   const vz=f(r(r(r(this.random.next()*f(7.629627e-6))+f(.75))*velocity[2]));
   const vy=f(r(f(r(this.random.next()%35+9))/period));
   Object.assign(cloud,{active:true,position:position.map(f),matrix:[...cameraMatrix],
    velocity:[vx,vy,vz],period,tick,width:7,height:7,alpha:80});
   count++;
  }
  return count;
 }
 /**432240 uses prephysics cachedXYZ, but current local velocities/yaw. */
 emitSkid({slipMagnitude,nowMs,deltaSeconds,position,body,cameraMatrix=identity}){
  if(slipMagnitude<4||(((nowMs>>>0)-this.lastSkidMs)|0)<=99)return 0;
  this.lastSkidMs=nowMs>>>0;
  const r=this.precision===24?f:Number,{sin,cos}=nativeTrigTable(this.precision),angle=Math.trunc(body.yaw)&4095;
  const s=sin[angle],c=cos[angle],rear=f(-r(f(1.01)*10));
  const lateral=r(body.lateralSpeed*f(.6)),forward=r(body.forwardSpeed*f(.6));
  const velocity=[f(r(r(c*lateral)-r(s*forward))),0,f(r(r(c*forward)+r(s*lateral)))];
  let count=0;
  for(const side of [9,-9]){
   const x=f(r(position[0]+r(r(c*side)-r(s*rear))));
   // Both branches store local Z before adding cached world Z (432312/4323fb).
   const localZ=f(r(r(c*rear)+r(s*side)));
   const z=f(r(position[2]+localZ));
   count+=this.emit([x,f(r(position[1]+3)),z],velocity,deltaSeconds,cameraMatrix);
  }
  return count;
 }
 /**420490 is called by failure action420850 only when damage>98. */
 emitDamage({nowMs,deltaSeconds,position,body,cameraMatrix=identity}){
  if((((nowMs>>>0)-this.lastDamageMs)|0)<=199)return 0;
  this.lastDamageMs=nowMs>>>0;
  const r=this.precision===24?f:Number,{sin,cos}=nativeTrigTable(this.precision),angle=Math.trunc(body.yaw)&4095;
  const rear=f(this.random.next()%6-3+16),side=f(this.random.next()%18-9),s=sin[angle],c=cos[angle];
  return this.emit([f(r(position[0]+f(r(r(c*side)-r(s*rear))))),f(r(position[1]+5)),
   f(r(position[2]+r(r(c*rear)+r(side*s))))],[0,0,0],deltaSeconds,cameraMatrix);
 }
 /**428a00 updates before drawing, sorts far-to-near in camera XZ, then ages.
  * Returned snapshots remain visible on the exact frame their slot expires. */
 capture({deltaSeconds,cameraPosition,cameraMatrix=identity}){
  const r=this.precision===24?f:Number;
  if(!this.enabled)return [];
  if(r(1/f(deltaSeconds))<10){for(const cloud of this.clouds)cloud.active=false;return [];}
  const scratch=smokeScratch(this),clouds=this.clouds,keys=scratch.keys,cameraX=cameraPosition[0],cameraZ=cameraPosition[2];
  for(let index=0;index<clouds.length;index++){
   const cloud=clouds[index],p=cloud.position;
   if(cloud.active){
    const remainder=cloud.tick%5;cloud.uvFrame=Math.max(0,Math.min(2,remainder>2?4-remainder:remainder));
    cloud.width=f(r(cloud.width+r(29/cloud.period)));cloud.height=f(r(cloud.height+r(29/cloud.period)));
    if(cloud.alpha!==0)cloud.alpha=(cloud.alpha-Math.max(1,Math.trunc(80/cloud.period)))&255;
    const v=cloud.velocity,m=cloud.matrix;
    p[0]=f(r(p[0]+v[0]));p[1]=f(r(p[1]+v[1]));p[2]=f(r(p[2]+v[2]));
    v[0]=f(r(v[0]*f(.9)));v[1]=f(r(v[1]*f(.9)));v[2]=f(r(v[2]*f(.9)));
    for(let k=0;k<9;k++)m[k]=cameraMatrix[k];
   }
   const x=r(p[0]-cameraX),z=r(p[2]-cameraZ);
   keys[cloud.id]=r(r(z*z)+r(x*x));
  }
  nativeSmokeSort(clouds,scratch.compare);
  const drawn=scratch.drawn;let count=0;
  for(let index=0;index<clouds.length;index++){
   const cloud=clouds[index];
   if(!cloud.active)continue;
   const w=f(r(cloud.width*.5)),h=f(r(cloud.height*.5)),frame=scratch.framePool[count];
   frame.id=cloud.id;frame.period=cloud.period;frame.tick=cloud.tick;frame.width=cloud.width;frame.height=cloud.height;
   frame.alpha=cloud.alpha;frame.uvFrame=cloud.uvFrame;
   const a=cloud.position,b=frame.position,c=cloud.velocity,d=frame.velocity,m=cloud.matrix,n=frame.matrix,q=frame.vertices;
   b[0]=a[0];b[1]=a[1];b[2]=a[2];d[0]=c[0];d[1]=c[1];d[2]=c[2];
   for(let k=0;k<9;k++)n[k]=m[k];
   q[3]=-w;q[4]=-h;q[6]=-w;q[7]=h;q[9]=w;q[10]=h;q[12]=w;q[13]=-h;q[15]=-w;q[16]=-h;
   const uv=uvFrames[cloud.uvFrame],frameUv=frame.uv;
   for(let k=0;k<uv.length;k++)frameUv[k]=uv[k];
   frame.rgba[3]=cloud.alpha;
   drawn[count++]=frame;
   cloud.tick++;
   if(cloud.tick>=cloud.period)cloud.active=false;
  }
  drawn.length=count;
  return drawn;
 }
}
