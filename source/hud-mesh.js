import {resolveAsset} from './asset-animation.js';
import {NATIVE_PRECISION} from './simulation/native-precision.js';

const f=Math.fround, lower=value=>String(value??'').trim().toLowerCase();
const tuple=(value,fallback)=>value===undefined?[...fallback]:String(value).split(';').map(Number)
  .concat(fallback).slice(0,fallback.length).map(f);
const roundFor=precision=>{
  if(![24,53].includes(precision))throw new RangeError('Unsupported native precision');
  return precision===24?f:value=>value;
};

/** HUD has its own90-degree horizontal projection (4604c0/462770), independent
 * of the race camera. Native coordinates look along+Z with+Y upward. A Three
 * scene may negateZ and use a regular perspective camera looking along-Z. */
export function getNativeHudCameraSpec(width=640,height=480,{precision=NATIVE_PRECISION}={}){
  const r=roundFor(precision),horizontalFov=f(f(Math.PI)*.5),near=f(.99),far=10000;
  // FPTAN keeps its extended result; subsequent arithmetic observes PC24/53.
  const tangent=Math.tan(r(horizontalFov*.5));
  const x=f(r(r(r(2/640)*tangent)*near));
  const y=f(r(r(r(r(2/480)*r(480/640))*tangent)*near));
  return {horizontalFov,verticalFov:2*Math.atan(Math.tan(horizontalFov/2)*height/width),
    near,far,width,height,pixelScale:[x,y,y],depthTest:false,blendMode:1};
}

// Parent context used by4589c0 and459440: positionXYZ, an unused carried
// scalar, child-position scaleXY, model scaleXYZ, rotationXYZ(native units).
// 4606c0 builds it at HUD+0x18 from 4f3924(1), 4f3920(.75) and the display
// height/width 4fe934/4fe930; its identity "Screen" element (4585e0) passes it
// through 4589c0 unchanged to the top-level composites (4614d0->458550).
export function nativeHudRootContext(width=640,height=480){
  return [0,0,0,1,f(.75),f(height/width),1,1,1,0,0,0];
}
export function nativeHudCompositeTransform({position=[0,0,0],scale=[1,1,1],
  rotation=[0,0,0],width=1,height=1},parent,{precision=NATIVE_PRECISION}={}){
  const r=roundFor(precision),p=position.map(f),s=scale.map(f),a=rotation.map(f);
  return [
    f(r(r(p[0]*parent[4])+parent[0])),f(r(r(p[1]*parent[5])+parent[1])),
    f(r(p[2]+parent[2])),parent[3],f(f(width)*parent[4]),f(f(height)*parent[5]),
    ...s.map((x,i)=>f(x*parent[6+i])),...a.map((x,i)=>f(x+parent[9+i])),
  ];
}
export function nativeHudElementTransform({position=[0,0,0],scale=[1,1,1],
  rotation=[0,0,0]},parent,{precision=NATIVE_PRECISION}={}){
  const r=roundFor(precision),p=position.map(f),s=scale.map(f),a=rotation.map(f);
  const pixelScale=getNativeHudCameraSpec(640,480,{precision}).pixelScale;
  return {
    position:[f(r(r(p[0]*parent[4])+parent[0])),f(r(r(p[1]*parent[5])+parent[1])),
      f(r(r(p[2]+parent[2])+1))],
    scale:s.map((x,i)=>f(f(x*pixelScale[i])*parent[6+i])),
    rotation:a.map((x,i)=>f(x+parent[9+i])),
  };
}

// IniFile45b2e0 fixes its authored coordinate extent at640x480x1000.
// Elements45c370 normalizeX by640. Composites45c4d0 normalizeX by480
// and apply LEFT/TOP alignment by default. Do not flatten these as pixel sums.
export function nativeHudIniTransform(section,{composite=false,precision=NATIVE_PRECISION}={}){
  const r=roundFor(precision),size=[f(Number(section.width??640)/640),f(Number(section.height??480)/480)];
  let position=[0,0,0];
  if(section.position!==undefined){
    const [x,y,z]=tuple(section.position,[0,0,0]);
    // 45c370/45c4d0 keep each quotient in ST (FDIV, FADD ST0,ST0); only FSTP stores.
    const nx=r(x/(composite?480:640)),ny=r(y/480);
    position=[f(r(r(nx+nx)-(composite?r(640/480):1))),f(r(1-r(ny+ny))),f(z/1000)];
    if(composite){
      const [h='left',v='top']=lower(section.alignment).split('&').filter(Boolean);
      if(h==='left')position[0]=f(r(position[0]+r(r(640/480)*size[0])));
      else if(h==='right')position[0]=f(r(position[0]-r(r(640/480)*size[0])));
      if(v==='top')position[1]=f(r(position[1]-size[1]));
      else if(v==='bottom')position[1]=f(r(position[1]+size[1]));
    }
  }
  if(section.rotation!==undefined)throw new Error('HUD INI rotation conversion has not been recovered');
  return {position,scale:tuple(section.scale,[1,1,1]),rotation:[0,0,0],width:size[0],height:size[1]};
}

/** Resolve an original mesh overlay and its render-space transform.
 * overrides contains native normalized position/scale/rotation/visible fields
 * by lower-case node ID; e.g {'321timer0':{position:[-.328125,.4,0]}}.
 * Dynamic state controllers must select animation/frame/visibility themselves.
 */
export function getHudMeshSpec(config,manifest,id,{trackId=0,animation=null,frame=0,
  overrides={},width=640,height=480,precision=NATIVE_PRECISION}={}){
  const overlay=config['overlay.ini'],name=lower(id),section=overlay?.[name];
  if(!section)throw new Error(`Missing original HUD element: ${id}`);
  const options={precision};
  const compositeNames=new Set(Object.values(overlay.composites).map(lower));
  const seen=new Set();
  const parentContext=parentName=>{
    const key=lower(parentName);
    if(!key||key==='screen')return {context:nativeHudRootContext(width,height),visible:true};
    if(seen.has(key))throw new Error(`Cyclic original HUD hierarchy: ${key}`);
    seen.add(key);
    const node=overlay[key];
    if(!node||!compositeNames.has(key))throw new Error(`Missing original HUD parent: ${key}`);
    const parent=parentContext(node.parent),override=overrides[key]??{};
    return {context:nativeHudCompositeTransform({...nativeHudIniTransform(node,{composite:true,...options}),...override},parent.context,options),
      visible:parent.visible&&(override.visible??lower(node.visible)!=='false')};
  };
  const parent=parentContext(section.parent),override=overrides[name]??{};
  const transform=nativeHudElementTransform({...nativeHudIniTransform(section,options),...override},parent.context,options);
  const animationName=lower(animation??override.animation??section.anim);
  const sequence=config[`e${String(trackId).padStart(2,'0')}_anim.ini`]?.[animationName]??config['gen_anim.ini']?.[animationName];
  let source=null,textureSource=null,mesh=null,texture=null;
  if(animationName){
    if(!sequence?.[frame])throw new Error(`Missing HUD animation frame: ${animationName}[${frame}]`);
    [source,textureSource]=sequence[frame].split(',').map(lower);
    mesh=resolveAsset(manifest,'meshes',source);
    texture=resolveAsset(manifest,'images',textureSource.replace(/\.[^.]+$/,'.tga'));
  }
  return {id:name,animation:animationName||null,frame,source,textureSource,mesh,texture,
    transform,rgba:override.rgba??tuple(section.rgba,[255,255,255,255]),
    visible:parent.visible&&(override.visible??lower(section.visible)!=='false'),
    blendMode:1,depthTest:false,
    //459440 replaces every model vertex ARGB with this element's tint.
    colorOperation:'replace-vertex-rgba',nativeFunctions:['0045b2e0','0045c370','0045c4d0','00462770','00459910','004589c0','00459440']};
}

/** Project a render-space point using the recovered D3D viewport4acf40.
 * Geometry rotation/scale must already be applied. Useful for HUD anchors. */
export function projectNativeHudPoint([x,y,z],{width=640,height=480}={}){
  const {horizontalFov}=getNativeHudCameraSpec(width,height);
  const factor=width/(2*Math.tan(horizontalFov/2)*z);
  return [width/2+x*factor,height/2-y*factor];
}
