/** Host adaptation only: preserve original group proportions while reserving
 * safe areas and the touch-control band. Native 640×480 coordinates stay intact. */
const raceTimeStrings=new Set(['string_lap','string_lap_value','string_lapof_value',
  'string_laptime','string_laptime_value','string_bestlap','string_bestlap_value']);
export function raceHudLayout(width,height,{left=0,right=0,top=0,bottom=0,touchHeight=0}={}){
  const portrait=height>width;
  const usableWidth=Math.max(1,width-left-right);
  const availableHeight=Math.max(1,height-top-bottom-touchHeight);
  const scale=portrait?Math.min(usableWidth/480,availableHeight/480)
    :Math.min(usableWidth/640,availableHeight/480);
  // Compact the vertical standings/bonus stack around a large touch wheel,
  // but keep the top-right race times at their normal readable landscape size.
  const timeScale=portrait?scale:Math.min(usableWidth/640,(height-top-bottom)/480);
  const w=640*scale,h=480*scale;
  const topY=top,bottomY=height-bottom-touchHeight-h;
  const centerX=(width-w)/2,centerY=top+(availableHeight-h)/2;
  const rightX=width-right-w;
  const groups=new Map(),texts=new Map();
  return {portrait,scale,width:w,height:h,
    group(name){
      let value=groups.get(name);
      if(!value)groups.set(name,value={x:name==='map'?rightX:['321timer','arrows'].includes(name)?centerX:left,
        y:['map','bonus'].includes(name)?bottomY:['321timer','arrows'].includes(name)&&portrait?centerY
          :name==='stars'&&portrait?topY+110*scale:topY,
        width:w,height:h});
      return value;
    },
    text(id){
      let value=texts.get(id);
      if(!value)texts.set(id,value=raceTimeStrings.has(id)?{x:width-right-640*timeScale,y:topY,scale:timeScale}
        :{x:id==='string_bonus'?left:['string_special','string_countdown_value'].includes(id)?centerX:rightX,
          y:id==='string_bonus'?bottomY:id==='string_special'?centerY:topY});
      return value;
    },
  };
}

export function measureRaceHudLayout(canvas,width,height,dpr=devicePixelRatio||1){
  const style=getComputedStyle(canvas);
  const safe=name=>Math.max(height>width&&name!=='bottom'?8:0,
    parseFloat(style.getPropertyValue(`--hud-safe-${name}`))||0)*dpr;
  const controls=document.getElementById('touch-controls');
  return raceHudLayout(width,height,{left:safe('left'),right:safe('right'),
    top:safe('top'),bottom:safe('bottom'),
    // The controls' box already includes its bottom safe-area padding.
    touchHeight:controls&&!controls.hidden?Math.max(0,controls.getBoundingClientRect().height*dpr-safe('bottom')):0});
}

/** Re-measure only when an input can have changed. Width, height and DPR are compared on
 * every frame by the caller; RaceHud.invalidateLayout covers #touch-controls.hidden toggles
 * (DrivingView.resize, zero-size frames), the observer CSS-driven box changes and the age
 * limit env(safe-area-inset-*) changes that leave the canvas size alone. */
export class RaceHudLayoutCache{
  constructor(canvas){this.canvas=canvas;this.layout=null;this.dirty=true;this.age=0;this.observer=null;this.connected=false;}
  connect(){
    this.connected=true;
    const controls=document.getElementById('touch-controls');
    if(!controls||typeof ResizeObserver!=='function')return;
    this.observer=new ResizeObserver(()=>{this.dirty=true;});this.observer.observe(controls);
  }
  get(width,height,dpr){
    if(!this.connected)this.connect();
    if(this.dirty||width!==this.width||height!==this.height||dpr!==this.dpr||++this.age>=60){
      this.layout=measureRaceHudLayout(this.canvas,width,height,dpr);
      this.width=width;this.height=height;this.dpr=dpr;this.dirty=false;this.age=0;
    }
    return this.layout;
  }
  dispose(){this.observer?.disconnect();this.observer=null;}
}
