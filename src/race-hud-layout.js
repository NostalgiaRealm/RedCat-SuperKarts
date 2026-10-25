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
  return {portrait,scale,width:w,height:h,
    group(name){
      return {x:name==='map'?rightX:['321timer','arrows'].includes(name)?centerX:left,
        y:['map','bonus'].includes(name)?bottomY:['321timer','arrows'].includes(name)&&portrait?centerY
          :name==='stars'&&portrait?topY+110*scale:topY,
        width:w,height:h};
    },
    text(id){
      if(raceTimeStrings.has(id))return {x:width-right-640*timeScale,y:topY,scale:timeScale};
      return {x:id==='string_bonus'?left:['string_special','string_countdown_value'].includes(id)?centerX:rightX,
        y:id==='string_bonus'?bottomY:id==='string_special'?centerY:topY};
    },
  };
}

export function measureRaceHudLayout(canvas,width,height){
  const dpr=devicePixelRatio||1,style=getComputedStyle(canvas);
  const safe=name=>Math.max(height>width&&name!=='bottom'?8:0,
    parseFloat(style.getPropertyValue(`--hud-safe-${name}`))||0)*dpr;
  const controls=document.getElementById('touch-controls');
  return raceHudLayout(width,height,{left:safe('left'),right:safe('right'),
    top:safe('top'),bottom:safe('bottom'),
    // The controls' box already includes its bottom safe-area padding.
    touchHeight:controls&&!controls.hidden?Math.max(0,controls.getBoundingClientRect().height*dpr-safe('bottom')):0});
}
