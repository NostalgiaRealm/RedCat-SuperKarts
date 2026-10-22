import * as THREE from 'three';

const factors={1:THREE.ZeroFactor,2:THREE.OneFactor,4:THREE.OneMinusSrcColorFactor,
  5:THREE.SrcAlphaFactor,6:THREE.OneMinusSrcAlphaFactor};

/** Direct3D keeps blend factors while blending is disabled.4260c0 leaves
 * them untouched when ALPHA_BLENDING=0;4a0d80 still enables its mode1 draw.
 * The active hardware HUD462320 explicitly resets them to5/6 each frame.
 */
export class NativeBlendState {
  constructor(){this.source=THREE.OneFactor;this.destination=THREE.ZeroFactor;this.bound=new WeakSet();}
  setNative(source,destination){
    this.source=factors[source];this.destination=factors[destination];
  }
  beforeDraw(mesh,material){
    if(mesh.userData.nativeInheritBlend){
      material.blendSrc=this.source;material.blendDst=this.destination;
    }else if(material.blending===THREE.CustomBlending){
      this.source=material.blendSrc;this.destination=material.blendDst;
    }
  }
  bindScene(scene,{hud=false}={}){
    if(this.bound.has(scene))return;
    this.bound.add(scene);
    const tracker=this,previous=scene.onBeforeRender;
    scene.onBeforeRender=function(...args){
      previous?.apply(this,args);
      if(hud){tracker.setNative(5,6);return;}
      this.traverse(mesh=>{
        if(!mesh.isMesh||tracker.bound.has(mesh))return;
        tracker.bound.add(mesh);
        const old=mesh.onBeforeRender;
        mesh.onBeforeRender=function(renderer,scene,camera,geometry,material,group){
          old?.call(this,renderer,scene,camera,geometry,material,group);
          tracker.beforeDraw(this,material);
        };
      });
    };
  }
}
