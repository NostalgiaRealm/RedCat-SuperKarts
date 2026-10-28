/** rcskmenu TDaviGraphicSlider (VMT 0x45efe4) with its TDaviSliderNeedle thumb
 * (VMT 0x45ee6c, a windowed TDaviGraphicButton). Position, Min and Max are
 * integer fields (+0x204, +0x1fc, +0x200). Geometry is in DFM pixels: slider
 * client width, needle size, needle top and MarginHorz. */

// Constructor 0x45f92c; the DFM overrides LargeStep (17) and MarginVert (6).
export const NATIVE_SLIDER_DEFAULTS=Object.freeze({Min:0,Max:100,LargeStep:5,MarginHorz:5,
  MarginVert:5,DelayTime:250,RepeatTime:50});

export function nativeSliderProperties(properties={}){
  const result={...NATIVE_SLIDER_DEFAULTS};
  for(const key of Object.keys(result))if(Number.isInteger(properties[key]))result[key]=properties[key];
  return result;
}

/** 0x45fd98 SetPosition: an equal request does nothing. Any other request is
 * stored, clamped to Max and then Min, and calls Change (0x45fb60, OnChange),
 * even when clamping leaves the previous value. */
export function nativeSliderSetPosition(position,requested,{Min,Max}){
  if(requested===position)return {position,change:false};
  let value=requested;
  if(value>Max)value=Max;
  if(Min>value)value=Min;
  return {position:value,change:true};
}

/** 0x45fb80 KeyDown, jump table 0x45fba8 for VK 0x21..0x28. The needle's
 * KeyDown 0x45f7ac forwards to it. Other keys return null. */
export function nativeSliderKeyRequest(key,position,{Min,Max,LargeStep}){
  switch(key){
    case 'PageUp':return position+LargeStep;
    case 'PageDown':return position-LargeStep;
    case 'End':return Min;
    case 'Home':return Max;
    case 'ArrowLeft':case 'ArrowDown':return position-1;
    case 'ArrowUp':case 'ArrowRight':return position+1;
    default:return null;
  }
}

/** 0x45fac0: the track pixel a press is compared with (0x45fc24). */
export function nativeSliderPixel(position,{width,margin},{Min,Max}){
  if(Min===Max)return 0;
  return Math.trunc((width-2*margin)*(position-Min)/(Max-Min))+margin;
}

/** 0x45fb08: needle Left for a position, applied by 0x45fd00. */
export function nativeSliderNeedleLeft(position,{width,margin,needleWidth},{Min,Max}){
  if(Min===Max)return margin;
  return Math.trunc((width-needleWidth-2*margin)*(position-Min)/(Max-Min))+margin;
}

/** 0x45fa58: position for a dragged needle Left. */
export function nativeSliderDragPosition(left,{width,margin,needleWidth},{Min,Max}){
  if(width-needleWidth===2*margin)return 0;
  return Math.trunc((left-margin)*(Max-Min)/(width-needleWidth-2*margin))+Min;
}

/** Keyboard, track press with timer repeat, and needle drag. Timers follow
 * Win32 SetTimer: periodic, and re-setting an id restarts it. */
export class NativeSliderController {
  constructor(properties,{position=properties.Min,geometry,onChange=()=>{},alive=()=>true,timers=globalThis}={}){
    this.properties=properties;this.position=position;this.geometry=geometry;this.onChange=onChange;
    this.alive=alive;this.timers=timers;this.timerIds=new Map();
    // Needle Left after a drag; null means the 0x45fd00 position.
    this.needle=null;this.cursor=null;this.drag=null;
  }
  sync(position){this.position=position;this.needle=null;}
  needleRect(geometry){
    const left=this.needle??nativeSliderNeedleLeft(this.position,geometry,this.properties);
    return {left,top:geometry.needleTop,right:left+geometry.needleWidth,bottom:geometry.needleTop+geometry.needleHeight};
  }
  set(requested){
    const result=nativeSliderSetPosition(this.position,requested,this.properties);
    if(!result.change)return;
    this.position=result.position;this.needle=null;this.onChange(result.position);
  }
  key(key){
    const requested=nativeSliderKeyRequest(key,this.position,this.properties);
    if(requested===null)return false;
    this.set(requested);return true;
  }
  /** Returns 'needle' when the press is on the needle (its own window), else
   * 'track'. Any mouse button steps on the track; only the left drags. */
  pointerDown(point,button=0){
    const geometry=this.geometry();this.cursor=point;
    if(pointInRect(this.needleRect(geometry),point)){
      // 0x45f7cc records the press in slider coordinates.
      this.drag=button===0?{lastX:point.x}:null;
      return 'needle';
    }
    this.trackPress(point,geometry);
    return 'track';
  }
  // 0x45fc24: one LargeStep towards the press, then SetTimer(1, DelayTime).
  trackPress(point,geometry){
    const {LargeStep}=this.properties;
    this.set(point.x<nativeSliderPixel(this.position,geometry,this.properties)?this.position-LargeStep:this.position+LargeStep);
    this.setTimer(1);
  }
  pointerMove(point,leftButton){
    this.cursor=point;
    if(this.drag&&leftButton)this.dragTo(point.x);
  }
  // 0x45f814 needle MouseMove with ssLeft.
  dragTo(x){
    const geometry=this.geometry(),{width,margin,needleWidth}=geometry,drag=this.drag;
    if(x===drag.lastX)return;
    if(width-needleWidth-2*margin===0)return;
    const current=this.needle??nativeSliderNeedleLeft(this.position,geometry,this.properties);
    let left=x-drag.lastX+current;
    if(left<margin)left=margin;
    if(left>width-needleWidth-margin)left=width-needleWidth-margin;
    if(left===current)return;
    drag.lastX=x;this.needle=left;
    // Stores Position directly (no clamp or comparison) and calls Change.
    this.position=nativeSliderDragPosition(left,geometry,this.properties);
    this.onChange(this.position);
  }
  // 0x45fca8 MouseUp kills both timers.
  pointerUp(){this.killTimer(1);this.killTimer(2);this.drag=null;}
  setTimer(id){
    this.killTimer(id);
    const delay=id===1?this.properties.DelayTime:this.properties.RepeatTime;
    this.timerIds.set(id,this.timers.setInterval(()=>this.timer(id),delay));
  }
  killTimer(id){
    if(this.timerIds.has(id))this.timers.clearInterval(this.timerIds.get(id));
    this.timerIds.delete(id);
  }
  // 0x45fde4 WM_TIMER.
  timer(id){
    if(!this.alive()){this.pointerUp();return;}
    if(id===1){this.killTimer(1);this.setTimer(2);}
    this.repeat();
  }
  // 0x45fe38: stop timer 2 once the needle holds the cursor, else press again.
  repeat(){
    const geometry=this.geometry();
    if(pointInRect(this.needleRect(geometry),this.cursor))this.killTimer(2);
    else this.trackPress(this.cursor,geometry);
  }
}

// USER32 PtInRect: right and bottom edges are outside.
const pointInRect=(rect,{x,y})=>x>=rect.left&&x<rect.right&&y>=rect.top&&y<rect.bottom;

/** Browser geometry in DFM pixels. The thumb size comes from the registered
 * --native-slider-thumb property, so portrait layouts measure their own size. */
export function nativeSliderGeometry(element,{Width,NeedleWidth=35}){
  const rect=element.getBoundingClientRect(),style=getComputedStyle(element);
  const unit=rect.width/Width||1,thumbValue=style.getPropertyValue('--native-slider-thumb').trim();
  const thumb=thumbValue.endsWith('px')?parseFloat(thumbValue):NeedleWidth*unit;
  // The thumb is centred in the content box: MarginVert below the top in the
  // native layout (0x45fd00), centred where a layout has no vertical padding.
  const top=parseFloat(style.paddingTop)||0,bottom=parseFloat(style.paddingBottom)||0;
  return {rect,unit,width:Width,margin:parseFloat(style.paddingLeft)/unit||0,
    needleWidth:thumb/unit,needleHeight:thumb/unit,needleTop:(top+(rect.height-top-bottom-thumb)/2)/unit};
}

/** Original keyboard and mouse/pen rules on an <input type=range>. Touch keeps
 * the browser's direct range handling (adaptation), reported through input. */
export function bindNativeSlider(element,properties,onChange){
  const props={...nativeSliderProperties(properties),Width:properties.Width,NeedleWidth:properties.NeedleWidth};
  let geometry=null;
  const measure=()=>geometry??nativeSliderGeometry(element,props);
  const controller=new NativeSliderController(props,{position:Number(element.value),geometry:measure,
    alive:()=>element.isConnected,onChange:position=>{element.value=String(position);onChange?.(position);}});
  const point=event=>{
    const g=measure();
    return {x:Math.floor((event.clientX-g.rect.left)/g.unit),y:Math.floor((event.clientY-g.rect.top)/g.unit)};
  };
  element.addEventListener('keydown',event=>{if(!event.metaKey&&controller.key(event.key))event.preventDefault();});
  element.addEventListener('pointerdown',event=>{
    if(event.pointerType==='touch'||event.button<0||event.button>2)return;
    event.preventDefault();
    geometry=nativeSliderGeometry(element,props);
    if(controller.pointerDown(point(event),event.button)==='needle'&&event.button===0)element.focus({preventScroll:true});
    element.setPointerCapture?.(event.pointerId);
  });
  element.addEventListener('pointermove',event=>{
    if(event.pointerType==='touch'||!geometry)return;
    controller.pointerMove(point(event),(event.buttons&1)!==0);
  });
  for(const type of ['pointerup','pointercancel','lostpointercapture'])element.addEventListener(type,event=>{
    if(event.pointerType==='touch'||!geometry)return;
    controller.pointerUp();geometry=null;
  });
  // Right-button track presses step in the original; no browser menu here.
  element.addEventListener('contextmenu',event=>event.preventDefault());
  element.addEventListener('input',()=>controller.sync(Number(element.value)));
  element.nativeSlider=controller;
  return controller;
}
