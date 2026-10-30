import { NATIVE_PRECISION } from './native-precision.js';
const f = Math.fround;
export const NATIVE_ARROW_INTERVAL = f(1 / 14);
export const NATIVE_ARROW_ALPHA = Object.freeze(Array.from({length:14}, (_, step) =>
  Math.trunc(f(f(step * NATIVE_ARROW_INTERVAL) * 255))));

/** Original CRcoArrow (004653c0/004654b0/00465570/00465840).
 * `forward` is the original facing-dot result, not the sign of kart speed.
 * Both controller clocks are seconds; nowSeconds is the absolute engine clock.
 */
export class NativeHudArrows {
  constructor({precision=NATIVE_PRECISION, backRgba=[255,255,255,255], junctionRgba=[255,255,255,255]}={}) {
    if (![24,53].includes(precision)) throw new RangeError('Unsupported native precision');
    this.precision=precision;
    this.state={phase:0,type:0,alphaStep:0,timestampSeconds:0,remainingSeconds:0};
    this.elements={backarrow:{visible:false,rgba:[...backRgba],alphaStep:0},
      junctionarrow:{visible:false,rgba:[...junctionRgba],alphaStep:0}};
  }
  selected() { return this.elements[this.state.type===2?'junctionarrow':'backarrow']; }
  stop() { this.selected().visible=false; this.state.phase=0; }
  start(input) {
    this.state.alphaStep=0;this.state.phase=1;
    this.state.timestampSeconds=f(input.nowSeconds);
    this.selected().visible=true;
    this.advance(input); // Native start immediately calls the update, including junction dt.
  }
  advance({nowSeconds,deltaSeconds}) {
    const s=this.state,r=this.precision===24?f:Number;
    if(s.type===2){
      if(s.remainingSeconds<=0){this.stop();return;}
      s.remainingSeconds=f(r(s.remainingSeconds-f(deltaSeconds)));
    }
    if(r(f(nowSeconds)-s.timestampSeconds)>=NATIVE_ARROW_INTERVAL){
      s.timestampSeconds=f(r(s.timestampSeconds+NATIVE_ARROW_INTERVAL));
      if(s.phase===1){if(++s.alphaStep===13)s.phase=2;}
      else if(s.phase===2){if(--s.alphaStep===0)s.phase=1;}
      else throw new RangeError('Cannot advance an inactive original arrow');
    }
    const element=this.selected();
    element.alphaStep=s.alphaStep;
    element.rgba[3]=Math.trunc(r(r(s.alphaStep*NATIVE_ARROW_INTERVAL)*255));
  }
  step(input) {
    const s=this.state;
    if(!input.forward){
      if(s.phase!==0){
        if(s.type!==2){this.advance(input);return;}
        this.stop();
      }
      s.type=1;this.start(input);
    }else if(s.phase!==0){
      if(s.type===1)this.stop();else this.advance(input);
    }
  }
  update(input) {
    this.step(input);
    return this.commands();
  }
  requestJunction(input) {
    if(input.forward&&this.state.phase===0){
      this.state.type=2;this.state.remainingSeconds=1;this.start(input);
    }
    return this.commands();
  }
  commands() {
    return Object.entries(this.elements).map(([id,element])=>({id,variant:element.alphaStep,
      visible:element.visible,overrides:{[id]:{visible:element.visible,rgba:[...element.rgba]}}}));
  }
}
