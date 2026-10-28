import {nativeTrigTable} from './native-integrator.js';
import {nativeRotationMatrix} from './native-transform.js';
import {NativeGameTimers} from './native-game-timers.js';
import {NATIVE_PRECISION} from './native-precision.js';

const f32=Math.fround;

/** 42b340 uses integer SndGfx values, with ratio multiplied by double .1. */
export function nativeSquashSettings(config,precision=NATIVE_PRECISION){
  const r=precision===24?f32:Number,s=config['sndgfx.ini']?.special_effects??{};
  return {
    speedLimit:f32(Number(s.squash_speed_limit)||0),
    shakeStrength:f32(Number(s.squash_shake_strength)||0),
    durationMs:(Number(s.squash_time)||0)|0,
    ratio:f32(r(f32(Number(s.squash_ratio)||0)*.1)),
    hitAngle:f32(Number(s.squash_hit_angle)||100),
    extraRange:f32(Number(s.squash_extra_range)||0),
  };
}

/** 48e260's seventeen rebound scale matrices. */
export function nativeSquashRebound(ratio){
  return [[1.2,ratio,1.2],[1.4,ratio,1.4],[1.2,ratio,1.2],
    [1.2,.6,1.2],[1,.8,1],[.8,1,.8],[.6,1.2,.6],[.6,1.4,.6],
    [.6,1.6,.6],[.6,1.8,.6],[.6,1.6,.6],[.6,1.4,.6],
    [.6,1.2,.6],[.8,1,.8],[1,.8,1],[1.2,.6,1.2],[1,.8,1]]
    .map(row=>row.map(f32));
}

/** 48e210/48e480/48e560/48e780/48e970. Matrix effects remain in the
 * simulation because source callback transforms also affect later contacts. */
export class NativeSquash {
  constructor({config,precision=NATIVE_PRECISION,timers=new NativeGameTimers()}={}){
    this.precision=precision;
    this.settings=nativeSquashSettings(config??{},precision);
    this.timers=timers;this.entries=[];this.rebound=nativeSquashRebound(this.settings.ratio);
  }
  /** Native order is player (timer19), NPCs (20+index), then OMP type44.
   * Props use externalMatrix=false, duration1200 and no game timer. */
  register(body,{timerId=-1,externalMatrix=true,durationMs=this.settings.durationMs,
    rebuildMatrix=()=>nativeRotationMatrix(body.angles??[body.pitch??0,body.yaw??0,body.roll??0],
      {precision:this.precision,scale:body.scale??[1,1,1]})}={}){
    if(this.entries.length>=32)return null;
    const entry={body,timerId,externalMatrix,durationMs,active:false,shake:false,
      reboundFrame:0,shakeFrame:0,startedMs:0,rebuildMatrix};
    this.entries.push(entry);return entry;
  }
  find(body){return this.entries.find(entry=>entry.body===body);}
  clamp(body){
    const limit=this.settings.speedLimit;
    if(body.forwardSpeed>limit)body.forwardSpeed=limit;
    else if(body.forwardSpeed<-limit)body.forwardSpeed=f32(-limit);
  }
  /** Only matrix coefficient m11 is flattened by 48e650. */
  flatten(entry){
    if(!entry.externalMatrix)entry.body.matrix=entry.rebuildMatrix();
    entry.body.matrix[4]=f32(entry.body.matrix[4]*this.settings.ratio);
  }
  trigger(body,nowMs){
    const entry=this.find(body);
    if(!entry||entry.active)return false;
    entry.active=true;entry.shake=entry.externalMatrix;
    this.flatten(entry);this.clamp(body);entry.startedMs=nowMs>>>0;
    if(entry.timerId>=0){
      this.timers.initialize(entry.timerId,entry.durationMs,true);
      this.timers.start(entry.timerId,nowMs);
    }
    return true;
  }
  /** Native 4a16f0 aliases its input/output. Row2 reads the already replaced
   * row0, rather than a pristine rotation input. */
  wobble(entry){
    const r=this.precision===24?f32:Number;
    const angle=Math.trunc((entry.shakeFrame%2===0?-1:1)*this.settings.shakeStrength)&4095;
    const {sin,cos}=nativeTrigTable(this.precision),s=sin[angle],c=cos[angle],m=entry.body.matrix;
    for(let i=0;i<3;i++)m[i]=f32(r(r(c*m[i])+r(s*m[6+i])));
    for(let i=0;i<3;i++)m[6+i]=f32(r(r(c*m[6+i])-r(s*m[i])));
    entry.shakeFrame=entry.shakeFrame===3?0:entry.shakeFrame+1;
  }
  restore(entry,deltaSeconds){
    const r=this.precision===24?f32:Number;
    if(entry.reboundFrame<17){
      if(!entry.externalMatrix)entry.body.matrix=entry.rebuildMatrix();
      const scale=this.rebound[entry.reboundFrame],m=entry.body.matrix;
      // 4a17c0 multiplies the diagonal scale on the left.
      for(let row=0;row<3;row++)for(let col=0;col<3;col++)
        m[row*3+col]=f32(r(scale[row]*m[row*3+col]));
      if(r(1/r(f32(deltaSeconds)+.01))>=10){entry.reboundFrame++;return;}
    }
    entry.reboundFrame=0;entry.active=false;entry.shake=false;
  }
  step(deltaSeconds,nowMs){
    // Original local_4 is deliberately retained when a later registered
    // prop has timerId=-1. It inherits the preceding timer test.
    let timerExpired=false;
    for(const entry of this.entries){
      if(!entry.active)continue;
      if(entry.timerId>=0)timerExpired=this.timers.expired(entry.timerId,nowMs);
      if(!timerExpired&&(((nowMs>>>0)-entry.startedMs)|0)<=entry.durationMs){
        this.clamp(entry.body);this.flatten(entry);
        if(entry.shake)this.wobble(entry);
      }else this.restore(entry,deltaSeconds);
    }
  }
}
