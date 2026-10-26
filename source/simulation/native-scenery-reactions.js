import {nativeTrigTable} from './native-integrator.js';
import {nativeRotationMatrix} from './native-transform.js';
import {selectNativeSector} from './native-track.js';
import {nativeObjectCallbackCount} from '../spatial-audio.js';

const f=Math.fround;
const round=precision=>precision===24?f:Number;

/** 497bd0/43df60: type2 tests only the player, using a strict XZ radius sum. */
export function nativeSceneryPlayerOverlap(object,player,{precision=24}={}){
  const r=round(precision),dx=f(r(object.position[0]-player.position[0])),
    dz=f(r(object.position[2]-player.position[2])),radius=f(r(object.radius+player.radius));
  return r(r(dx*dx)+r(dz*dz))<r(radius*radius);
}

/** 43c5c0, type2 mass4. The three random draws occur in X,Y,Z order. */
export function launchNativeScenery(object,player,random,{precision=24,mass=4}={}){
  const r=round(precision),{sin,cos}=nativeTrigTable(precision);
  const x=r(r(player.lateralSpeed*3)/f(mass)),z=r(f(r(player.forwardSpeed*3))/f(mass));
  const angle=Math.trunc(player.yaw)&4095;
  object.velocity=[
    f(r(r(cos[angle]*x)-r(sin[angle]*z))),
    f(r(r(z+x)*f(.25))),
    f(r(r(cos[angle]*z)+r(sin[angle]*x))),
  ];
  for(let i=0;i<3;i++)object.velocity[i]=f(r(r(r((random.next()%256)*f(1/512))+f(.75))*object.velocity[i]));
  const own=(-Math.trunc(object.yaw))&4095,[vx,,vz]=object.velocity;
  object.pitchRate=f(r(r(cos[own]*vx)-r(sin[own]*vz)));
  object.rollRate=f(r(r(cos[own]*vz)+r(sin[own]*vx)));
  object.gravity=-45;object.mode=1;
}

/** 43c870 flight/bounce and43cbf0 settling. Source adds velocity directly to
 * position once per callback; delta scales drag/gravity/rotation, not displacement. */
export function updateNativeSceneryReaction(object,deltaSeconds,{
  precision=24,selectSector=()=>object.sector,groundHeight=()=>0,
}={}){
  const r=round(precision),dt=f(deltaSeconds),mode=object.mode;
  if(mode!==1&&mode!==3)return false;
  const damping=mode===1?f(.6):f(.8),v=object.velocity;
  const ax=f(r(-v[0]*damping)),az=f(r(-v[2]*damping));
  v[0]=f(r(r(dt*ax)+v[0]));v[2]=f(r(r(dt*az)+v[2]));
  if(mode===1)v[1]=f(r(r(dt*object.gravity)+v[1]));
  object.position[0]=f(r(object.position[0]+v[0]));
  if(mode===1)object.position[1]=f(r(object.position[1]+v[1]));
  object.position[2]=f(r(object.position[2]+v[2]));
  let bounced=false;
  if(mode===1){
    object.sector=selectSector(object);
    const height=f(groundHeight(object)),distance=f(r(object.position[1]-height));
    if(r(distance*distance)<r(object.radius*object.radius)){
      v[1]=f(r(v[1]*f(-.7)));object.pitchRate=f(-object.pitchRate);object.rollRate=f(-object.rollRate);
      object.position[1]=f(r(height+2));
      if(v[1]<2)object.mode=3;
      bounced=true;
    }
  }else{
    object.pitchRate=f(r(object.pitchRate*f(1.15)));
    object.rollRate=f(r(object.rollRate*f(1.15)));
  }
  const scale=mode===1?80:50;
  object.pitch=f(r(r(r(dt*object.rollRate)*scale)+object.pitch));
  object.roll=f(r(object.roll-r(r(dt*object.pitchRate)*scale)));
  // 4a09e0 precedes the terminal angle clamps; the last matrix retains the
  // pre-clamp pose once state2 becomes inert.
  object.matrix=nativeRotationMatrix([object.pitch,object.yaw,object.roll],{precision});
  if(mode===3){
    if(object.pitch<=1024&&object.roll<=1024&&object.pitch>=-1024&&object.roll>=-1024)return false;
    if(object.pitch>1024){object.pitch=1024;object.roll=0;}
    if(object.pitch< -1024){object.pitch=-1024;object.roll=0;}
    if(object.roll>1024){object.pitch=0;object.roll=1024;}
    if(object.roll< -1024){object.pitch=0;object.roll=-1024;}
    object.mode=2;
    return true;
  }
  return bounced;
}

/** Original non-solid type2 object callbacks, in OMP creation order. */
export class NativeSceneryReactions{
  constructor({track,manifest,world,random,precision=24}){
    Object.assign(this,{track,manifest,world,random,precision});
    this.byPlacement=new Map();
    const r=round(precision),factor=f(r(4096*f(.0027777778)));
    this.objects=track.placements.flatMap((placement,placementIndex)=>{
      if(placement.type!==2)return[];
      const mesh=track.objectDefinitions[placement.animation.toLowerCase()].mesh.toLowerCase();
      const angles=placement.nativeRotationDegrees.map(value=>f(r(value*factor)));
      const object={placementIndex,mesh,type:2,position:placement.position.map(f),
        pitch:angles[0],yaw:angles[1],roll:angles[2],matrix:nativeRotationMatrix(angles,{precision}),
        sector:placement.sector,visible:true,mode:0,velocity:[0,0,0],pitchRate:0,rollRate:0,gravity:0,
        radius:manifest.meshes[mesh].horizontalRadius,
        get lateralSpeed(){return this.velocity[0];},
        get verticalSpeed(){return this.velocity[1];},
        get forwardSpeed(){return this.velocity[2];}};
      this.byPlacement.set(placementIndex,object);return[object];
    });
  }
  step(deltaSeconds,player,ranges,onSound,placementIndex=null){
    const r=round(this.precision);
    const objects=placementIndex===null?this.objects
      :this.byPlacement.has(placementIndex)?[this.byPlacement.get(placementIndex)]:[];
    for(const object of objects){
      const count=nativeObjectCallbackCount({visible:object.visible,alwaysUpdate:false,sector:object.sector,ranges});
      for(let n=0;n<count;n++){
        if(object.mode===0){
          if(nativeSceneryPlayerOverlap(object,player,{precision:this.precision})){
            launchNativeScenery(object,player,this.random,{precision:this.precision});
            onSound?.(object.placementIndex,object);
          }
        }else updateNativeSceneryReaction(object,deltaSeconds,{
          precision:this.precision,
          selectSector:o=>selectNativeSector(this.world,o.sector,o.position[0],o.position[2]),
          groundHeight:o=>{
            const plane=this.world.sectors[o.sector].fallback;
            return f(r(r(r(plane.distance-r(o.position[0]*plane.normal[0]))
              -r(o.position[2]*plane.normal[2]))/plane.normal[1]));
          },
        });
      }
    }
  }
}
