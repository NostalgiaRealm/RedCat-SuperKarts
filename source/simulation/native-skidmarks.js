import { NATIVE_PRECISION } from './native-precision.js';
const f=Math.fround;

/**426aa0/426900/4269e0 + render-time426db0/426c50.
 * No RNG.20 strip pairs,98 vertices each, using the original rear-wheel local
 * positions and current body matrix; these are not ground-projected decals.
 */
export class NativeSkidmarks {
  constructor({precision=NATIVE_PRECISION,enabled=true,fade=true}={}) {
    Object.assign(this,{precision,enabled,fade,lastSlip:0,currentIndex:-1,texture:'s_sfx'});
    this.strips=Array.from({length:20},(_,id)=>({id,active:false,period:0,tick:0,sides:[[],[]]}));
  }
  emit({deltaSeconds,slipMagnitude,playerContact,matrix,position,wheelOffsets}) {
    if (!this.enabled||!playerContact) return;
    if (slipMagnitude>3) {
      if (this.lastSlip<4) {
        const strip=this.strips.find(value=>!value.active);
        if (!strip) {this.lastSlip=3;return;}
        strip.sides=this.vertices(slipMagnitude,matrix,position,wheelOffsets);
        strip.period=Math.trunc((this.precision===24?f:Number)(20/f(deltaSeconds)));
        strip.active=true;
        this.currentIndex=strip.id;
        this.lastSlip=slipMagnitude;
        return;
      }
      const strip=this.strips[this.currentIndex];
      if (!strip?.active) {this.currentIndex=-1;this.lastSlip=3;return;}
      if (strip.sides[0].length+2<100) {
        const sides=this.vertices(slipMagnitude,matrix,position,wheelOffsets);
        strip.sides.forEach((side,i)=>side.push(...sides[i]));
      }
    }
    this.lastSlip=slipMagnitude;
  }
  vertices(slip,matrix,position,wheelOffsets) {
    const r=this.precision===24?f:Number;
    const alpha=Math.max(0,Math.min(255,200-16*Math.max(0,slip-4)));
    const argb=((alpha<<24)|0x404040)>>>0;
    return [2,3].map(wheelIndex=>[4,-4].map((offset,i)=>{
      const wheel=wheelOffsets[wheelIndex],p=[f(r(wheel[0]+offset)),1,f(wheel[2])];
      return {position:[0,1,2].map(axis=>f(r(r(r(r(p[2]*matrix[6+axis])+r(p[1]*matrix[3+axis]))
        +r(p[0]*matrix[axis]))+position[axis]))),
      argb,uv:[i===0?.8125:.984375,.109375]};
    }));
  }
  /**Original fading happens just before the strips draw. Inverse alpha blend
   * makes alpha255 invisible: src*(1-alpha)+destination*alpha.
   */
  capture() {
    if (!this.enabled) return [];
    for (const strip of this.strips) if (strip.active) {
      strip.tick++;
      if (strip.tick>=strip.period) {
        strip.active=false;strip.tick=0;strip.sides=[[],[]];continue;
      }
      if (this.fade) {
        const remaining=strip.period-strip.tick;
        strip.sides[0].forEach((vertex,index)=>{
          const alpha=vertex.argb>>>24;
          const next=Math.min(255,alpha+Math.max(1,Math.floor((255-alpha)/remaining)));
          const argb=((vertex.argb&0xffffff)|(next<<24))>>>0;
          vertex.argb=argb;
          strip.sides[1][index].argb=argb;
        });
      }
    }
    return this.strips.filter(strip=>strip.active&&strip.sides[0].length>2).map(strip=>({
      id:strip.id, sides:strip.sides.map(side=>side.map(vertex=>({...vertex,position:[...vertex.position],uv:[...vertex.uv]}))),
    }));
  }
}
