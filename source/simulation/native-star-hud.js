import {nativeTrigTable} from './native-integrator.js';
import {NATIVE_PRECISION} from './native-precision.js';

const f=Math.fround;
export const NATIVE_STAR_HUD_COUNT=12;
export const NATIVE_STAR_HUD_COLORS=Object.freeze({
  empty:Object.freeze([127,127,127,255]),collected:Object.freeze([255,255,255,255]),
});

/** CRcoStars::Init creates these elements dynamically (0046dce0/0046e070).
 * Keep the shipped overlay/config untouched; its Stars/Starflag art is reused.
 */
export function createNativeStarHudConfig(config){
  const overlay={...config['overlay.ini']};
  for(let index=0;index<NATIVE_STAR_HUD_COUNT;index++)overlay[`star${index+1}`]={
    parent:'Stars',anim:'ovrlster',rgba:'127;127;127;255',
  };
  return {...config,'overlay.ini':overlay};
}

/** Original 00467e30 enables CRcoStars only in ItemRace (2). The twelve slots
 * start at the top and progress clockwise; 0046e260 turns collected slots white.
 * Positions/scales are native normalized HUD values, not pixel coordinates.
 */
export function getNativeStarHudCommands(starCount,{raceType=2,precision=NATIVE_PRECISION}={}){
  if(!Number.isInteger(starCount)||starCount<0)throw new RangeError('Collected stars must be a nonnegative integer');
  if(precision!==24&&precision!==53)throw new RangeError('Unsupported native precision');
  const count=Math.min(starCount,NATIVE_STAR_HUD_COUNT),visible=raceType===2;
  const {sin,cos}=nativeTrigTable(precision),radius=f(.14),scale=[f(.18),f(.18),1];
  const commands=[{id:'starflag',visible,overrides:{stars:{visible}}}];
  for(let index=0;index<NATIVE_STAR_HUD_COUNT;index++){
    const id=`star${index+1}`,angle=Math.trunc(index*4096/NATIVE_STAR_HUD_COUNT)&4095;
    const variant=index<count?'collected':'empty';
    commands.push({id,variant,visible,overrides:{stars:{visible},[id]:{
      position:[f(sin[angle]*radius),f(cos[angle]*radius),f(.001)],scale:[...scale],
      rgba:[...NATIVE_STAR_HUD_COLORS[variant]],visible,
    }}});
  }
  return commands;
}
