import { nativeTrigTable } from './native-integrator.js';
import { nativeRaceKeyDown } from './native-race-lifecycle.js';
const f32=Math.fround;
const NATIVE_HORIZONTAL_FOV=1.4137166738510132;
export const NATIVE_CAMERA_PROJECTION=Object.freeze({
 near:1.5,far:12500,horizontalRadians:NATIVE_HORIZONTAL_FOV,
 horizontalDegrees:NATIVE_HORIZONTAL_FOV*180/Math.PI,
 referenceAspect:4/3,
 verticalDegrees:2*Math.atan(Math.tan(NATIVE_HORIZONTAL_FOV/2)*3/4)*180/Math.PI,
});
/** 0x4acf40 viewport clip height2H/W supplies the native aspect correction. */
export function nativeVerticalFov(aspect=4/3){
 if(!Number.isFinite(aspect)||aspect<=0)throw new RangeError('Aspect must be positive');
 return 2*Math.atan(Math.tan(NATIVE_HORIZONTAL_FOV/2)/aspect)*180/Math.PI;
}
/** Body matrix uses native row-vector 3x3 storage, matching NativePlayerMotion. */
function transformVector(v,m,r){
 return [0,1,2].map(column=>{
  let sum=0;
  for(let row=0;row<3;row++)sum=r(sum+r(v[row]*m[row*3+column]));
  return f32(sum);
 });
}
/**0x41e280(mode1),0x498c00: one native camera update; coefficients are per update. */
export class NativePlayerCamera {
 constructor({precision=24}={}){
  this.precision=precision;this.position=null;this.target=null;this.up=[0,1,0];
  this.rememberedMode=1;this.setMode(1);
 }
 /** 0x41e280: the four modes reachable with shipped, non-debug camera keys. */
 setMode(mode){
  if(![0,1,3,5].includes(mode))throw new RangeError('Unsupported original player-camera mode');
  this.mode=mode;
  if(mode===0||mode===1){
   this.positionOffset=[0,50,-150];this.targetOffset=[0,mode===0?25:50,0];
   this.positionDamping=true;this.bodyUp=false;this.targetLocked=true;this.bodyVisible=true;
  }else if(mode===3){
   this.positionOffset=[0,15.5,-1];this.positionDamping=false;
   this.bodyUp=true;this.targetLocked=false;this.bodyVisible=false;
  }else{
   this.positionOffset=[0,23,40];this.targetOffset=[0,50,0];
   this.bodyUp=false;this.targetLocked=true;this.bodyVisible=true;
   // Rear view inherits the position-damping flag from the preceding mode.
  }
  return this;
 }
 /** 0x41d920; numeric virtual-key codes, checked in the original 1/2/3/4 order.
  * Returns true when the native code selects camera0, including repeated keys.
  */
 handleKeys(keys={},phase=0){
  const down=key=>nativeRaceKeyDown(keys,key);
  let selected=false;
  const select=mode=>{this.setMode(mode);selected=true;};
  if(down(49)&&phase===0)select(1);
  if(down(50))select(3);
  if(phase===0){
   if(down(51)){
    if(this.mode!==5){this.rememberedMode=this.mode;select(5);}
   }else if(this.mode===5)select(this.rememberedMode);
  }
  if(down(52)&&phase===0)select(0);
  return selected;
 }
 reset(body){
  const r=this.precision===24?f32:Number;
  this.position=transformVector([0,20,-150],body.matrix,r).map((x,k)=>f32(r(x+body.position[k])));
  this.target=transformVector([0,50,0],body.matrix,r).map((x,k)=>f32(r(x+body.position[k])));
  return this;
 }
 step(body){
  if(!this.position)this.reset(body);
  const r=this.precision===24?f32:Number;
  const desired=transformVector(this.positionOffset,body.matrix,r).map((x,k)=>f32(r(x+body.position[k])));
  this.target=this.targetLocked
   ?transformVector(this.targetOffset,body.matrix,r).map((x,k)=>f32(r(x+body.position[k])))
   :desired.map((x,k)=>f32(r(x+body.matrix[6+k])));
  this.up=this.bodyUp?body.matrix.slice(3,6):[0,1,0];
  if(!this.positionDamping){this.position=desired;return this;}
  const inverse=[0,1,2].flatMap(row=>[0,1,2].map(col=>body.matrix[col*3+row]));
  const difference=desired.map((x,k)=>f32(r(x-this.position[k])));
  const local=transformVector(difference,inverse,r).map((x,k)=>f32(r(x*[f32(.1),f32(.1),f32(.5)][k])));
  const delta=transformVector(local,body.matrix,r);
  this.position=delta.map((x,k)=>f32(r(x+this.position[k])));
  return this;
 }
 /**0x420f00 updates camera0 at green, then restores/selects normal chase mode. */
 startRace(body){this.step(body);return this.setMode(1);}
}

/** 0x41fc60: fixed finish camera at logical route sector+3, tracking the kart. */
export class NativeFinishCamera {
 constructor(track,body,{precision=24}={}){
  this.precision=precision;
  const position=track.route[body.sector+3]?.position;
  if(!position)throw new RangeError('Original finish-camera sector+3 lies outside the route allocation');
  this.position=[position[0],f32(position[1]+40),position[2]];
  this.up=[0,1,0];
  this.step(body);
 }
 step(body){
  const r=this.precision===24?f32:Number;
  this.target=transformVector([0,20,0],body.matrix,r).map((value,index)=>f32(r(value+body.position[index])));
  return this;
 }
}

/** 0x420730/0x420850: phase6 camera, local orbit advanced AFTER rendering. */
export class NativeFailureCamera {
 constructor(body,deltaSeconds,{precision=24}={}){
  if(!Number.isFinite(deltaSeconds)||deltaSeconds<=0)throw new RangeError('Original camera-entry delta is required');
  this.precision=precision;
  const r=precision===24?f32:Number;
  this.localPosition=[0,50,-150];
  this.radius=150;
  this.angle=-1024;
  this.orbitFrames=Math.trunc(r(8/f32(deltaSeconds)));
  const increment=r(4096/this.orbitFrames);
  this.angleIncrement=Number.isFinite(increment)?Math.trunc(increment)|0:0;
  this.step(body);
 }
 /** Run with other cameras after integration, before the world is rendered. */
 step(body){
  const r=this.precision===24?f32:Number;
  this.position=transformVector(this.localPosition,body.matrix,r).map((v,k)=>f32(r(v+body.position[k])));
  this.target=transformVector([0,50,0],body.matrix,r).map((v,k)=>f32(r(v+body.position[k])));
  // Unlike finish camera5, camera6 retains the constructor's body-up lock.
  this.up=body.matrix.slice(3,6);
  return this;
 }
 /** Run in the post-render action stage, even before the one-second key gate. */
 advance(){
  const r=this.precision===24?f32:Number,{sin,cos}=nativeTrigTable(this.precision);
  const index=this.angle&4095;
  this.localPosition=[f32(r(cos[index]*this.radius)),50,f32(r(sin[index]*this.radius))];
  this.angle=(this.angle+this.angleIncrement)|0;
  return this;
 }
}
