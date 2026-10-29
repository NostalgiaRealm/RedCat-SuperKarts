export const DEFAULT_BINDINGS=Object.freeze({accelerate:'ArrowUp',brake:'ArrowDown',left:'ArrowLeft',right:'ArrowRight',bonus:'ControlLeft',handbrake:'AltLeft'});
export const DEFAULT_DISPLAY_SETTINGS=Object.freeze({brightnessLight:true,bilinearFiltering:true,alphaBlending:true,particles:true});
// Shipped Race.ini GAME_SETTINGS MX_VOLUME/FX_VOLUME, loaded by45ae70/42c320.
export const DEFAULT_SETTINGS=Object.freeze({resolution:'auto',renderScale:100,msaaEnabled:false,msaaSamples:4,surfaceShadows:true,freeFlight:false,music:1,effects:1,deadzone:0.18,touch:'auto',fullscreen:false,startInfo:true,controlType:0,bindings:DEFAULT_BINDINGS,display:DEFAULT_DISPLAY_SETTINGS});
export const RESOLUTIONS=Object.freeze({'auto':null,'640x480':[640,480],'800x600':[800,600],'1024x768':[1024,768],'1280x720':[1280,720],'1920x1080':[1920,1080],'2560x1440':[2560,1440],'3840x2160':[3840,2160]});
const bounded=(v,a,b,d)=>typeof v==='number'&&Number.isFinite(v)?Math.min(b,Math.max(a,v)):d;
export function normalizeSettings(value={}) {
  if(!value||typeof value!=='object')value={};
  return {resolution:Object.hasOwn(RESOLUTIONS,value.resolution)?value.resolution:'auto',
    renderScale:bounded(value.renderScale,25,200,100),music:bounded(value.music,0,1,1),
    msaaEnabled:value.msaaEnabled===true,msaaSamples:[2,4,8].includes(value.msaaSamples)?value.msaaSamples:4,
    surfaceShadows:value.surfaceShadows!==false,freeFlight:value.freeFlight===true,
    effects:bounded(value.effects,0,1,1),deadzone:bounded(value.deadzone,0,.5,.18),
    touch:['auto','on','off'].includes(value.touch)?value.touch:'auto',fullscreen:value.fullscreen===true,startInfo:value.startInfo!==false,controlType:[0,1,2].includes(value.controlType)?value.controlType:0,
    display:Object.fromEntries(Object.keys(DEFAULT_DISPLAY_SETTINGS).map(key=>[key,value.display?.[key]!==false])),
    // Native capture clears a key first; Escape can intentionally leave it
    // unbound, and OK persists that zero. Preserve an explicit empty binding.
    bindings:Object.fromEntries(Object.entries(DEFAULT_BINDINGS).map(([key,defaultCode])=>[key,value.bindings?.[key]===''?'':/^(Arrow(Up|Down|Left|Right)|Key[A-Z]|Digit[0-9]|Control(Left|Right)|Alt(Left|Right)|Shift(Left|Right)|Space|Enter|Tab|Backspace|[A-Za-z]+)$/.test(value.bindings?.[key]||'')&&value.bindings[key]!=='Escape'?value.bindings[key]:defaultCode]))};
}
export function readSettings(storage) {
  try{
    if(storage===undefined)storage=globalThis.localStorage;
    return normalizeSettings(JSON.parse(storage.getItem('rcsk.settings.v1')));
  }catch{return normalizeSettings();}
}
export function writeSettings(value,storage){
  const safe=normalizeSettings(value);
  try{
    if(storage===undefined)storage=globalThis.localStorage;
    storage.setItem('rcsk.settings.v1',JSON.stringify(safe));return true;
  }catch{return false;}
}
/** Choose a count actually supported by BOTH the color and depth attachment.
 * Some WebGL devices only advertise 4 samples, even for a request of 2. */
export function chooseMultisampleCount(requested,supported) {
  const values=[...new Set(supported.filter(value=>Number.isInteger(value)&&value>=2))].sort((a,b)=>a-b);
  return values.filter(value=>value<=requested).at(-1)??values[0]??0;
}
// A preset is a maximum base rectangle; fit it to the viewport's aspect.
// Auto uses CSS pixels × DPR once. Renderer pixel ratio must be 1.
export function renderDimensions({width,height,dpr=1,resolution='auto',renderScale=100,maxSize=16384}){
  width=Math.max(1,Number(width)||1);height=Math.max(1,Number(height)||1);
  dpr=bounded(dpr,.25,8,1);
  const preset=RESOLUTIONS[resolution];
  let baseWidth,baseHeight;
  if(!preset){baseWidth=Math.round(width*dpr);baseHeight=Math.round(height*dpr);}
  else{const fit=Math.min(preset[0]/width,preset[1]/height);baseWidth=Math.max(1,Math.round(width*fit));baseHeight=Math.max(1,Math.round(height*fit));}
  const scale=bounded(renderScale,25,200,100)/100;
  const factor=Math.min(scale,maxSize/baseWidth,maxSize/baseHeight);
  return {baseWidth,baseHeight,width:Math.max(1,Math.round(baseWidth*factor)),height:Math.max(1,Math.round(baseHeight*factor)),scale:factor,limited:factor<scale};
}
// Original race projection is recovered in native-camera.js. This helper
// expresses the added aspect adaptation policy:
// preserve vertical FOV at/wider than 4:3; preserve horizontal FOV in portrait.
export function adaptVerticalFov(originalVerticalDegrees,aspect,originalAspect=4/3){
  if(aspect>=originalAspect)return originalVerticalDegrees;
  return 2*Math.atan(Math.tan(originalVerticalDegrees*Math.PI/360)*originalAspect/aspect)*180/Math.PI;
}
