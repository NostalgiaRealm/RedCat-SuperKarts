import {getRotationSpec,createNativeRotation,advanceNativeRotation,getSceneryAnimation,
  createNativeMeshAnimation,advanceNativeMeshAnimation} from '../asset-animation.js';
import {getNativeScenerySounds,nativeObjectCallbackCount} from '../spatial-audio.js';
import {nativeRotationMatrix,nativePlacementAngles} from './native-transform.js';
import {nativeSquashTargets} from './native-squash-activation.js';
import {NATIVE_PRECISION} from './native-precision.js';

/** OMP construction order; pass an existing map when the presentation loader
 * already performed these original random-phase draws. */
export function createNativeSceneryRotations(track,config,random){
  const states=new Map();
  track.placements.forEach((placement,index)=>{
    const spec=getRotationSpec(config,placement);
    if(spec)states.set(index,createNativeRotation(spec,placement.nativeRotationDegrees,()=>random.next()));
  });
  return states;
}

/** The shipped squash hazards: rotating type43, self-squashing type44 and
 * animated type46. Type47 shares the original callback but has no placements. */
export class NativeSceneryHazards{
  constructor({track,config,manifest,rotationStates,squash,precision=NATIVE_PRECISION}){
    Object.assign(this,{track,config,manifest,rotationStates,squash,precision});
    this.byPlacement=new Map();this.animations=new Map();
    const always=new Set(getNativeScenerySounds(config,manifest,track).map(x=>x.placementIndex));
    const f=Math.fround;
    this.objects=track.placements.flatMap((placement,placementIndex)=>{
      if(![43,44,46,47].includes(placement.type))return[];
      const rotation=rotationStates.get(placementIndex);
      const angles=rotation?.angles??nativePlacementAngles(placement.nativeRotationDegrees);
      const mesh=track.objectDefinitions[placement.animation.toLowerCase()].mesh.toLowerCase();
      const object={type:placement.type,placementIndex,position:placement.position.map(f),angles,
        yaw:angles[1],roll:angles[2],pitch:angles[0],matrix:nativeRotationMatrix(angles,{precision}),
        mesh,sector:placement.sector,visible:true,alwaysUpdate:always.has(placementIndex),
        lateralSpeed:0,verticalSpeed:0,forwardSpeed:0};
      if(placement.type===44)squash.register(object,{externalMatrix:false,durationMs:1200});
      if([46,47].includes(placement.type)){
        const animation=getSceneryAnimation(config,manifest,track.id,placement.animation);
        if(!animation||animation.sequences.length!==1)throw Error(`Unsupported hazard sequence ${placement.animation}`);
        this.animations.set(placementIndex,createNativeMeshAnimation(animation.sequences[0]));
      }
      this.byPlacement.set(placementIndex,object);return[object];
    });
  }
  stepPlacement(index,deltaSeconds,nowMs,{player,opponents,playerPosition,ranges}){
    const object=this.byPlacement.get(index);if(!object)return;
    const count=nativeObjectCallbackCount({visible:object.visible,alwaysUpdate:object.alwaysUpdate,
      sector:object.sector,ranges});
    for(let n=0;n<count;n++){
      const rotation=this.rotationStates.get(index),animation=this.animations.get(index);
      if(rotation){
        advanceNativeRotation(rotation,deltaSeconds,{precision:this.precision});
        [object.pitch,object.yaw,object.roll]=object.angles;
      }
      if(animation){
        const mesh=advanceNativeMeshAnimation(animation,nowMs);
        if(mesh)object.mesh=mesh.source;
        object.matrix=nativeRotationMatrix(object.angles,{precision:this.precision});
      }
      for(const target of nativeSquashTargets(object,{player,opponents,playerPosition,
        frame:animation?.frame??0,hitAngle:this.squash.settings.hitAngle,precision:this.precision}))
        this.squash.trigger(target,nowMs);
      if(rotation)object.matrix=nativeRotationMatrix(object.angles,{precision:this.precision});
    }
  }
}
