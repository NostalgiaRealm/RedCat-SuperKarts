import * as THREE from 'three';
import {resolveAsset} from './asset-animation.js';
import {createNativeMeshMaterial} from './asset-materials.js';
import {nativeObjectRenderOrder} from './render-order.js';
import {setNativeMatrix} from './render-transforms.js';

/** 457780 uses frame0 of gen_anim.ini [bubble], with render blend mode2. */
export function getNativeBubbleShellSpec(config,manifest) {
  const row=config['gen_anim.ini']?.bubble?.['0'];
  if(!row)throw new Error('Original bubble shell definition is missing');
  const [meshName,textureName]=row.split(',').map(value=>value.trim());
  const mesh=resolveAsset(manifest,'meshes',meshName);
  const texture=resolveAsset(manifest,'images',textureName.replace(/\.pcx$/i,'.tga'));
  if(!mesh||!texture)throw new Error('Original bubble shell assets are missing');
  return {mesh,texture,blendMode:2,nativeFunctions:['00457780','00457b60','00457ab0']};
}

export class BubbleShellVisuals {
  constructor(viewer,controller) {
    this.viewer=viewer;this.controller=controller;this.meshes=[];
  }
  async load(config,manifest) {
    this.spec=getNativeBubbleShellSpec(config,manifest);
    const [geometry,map]=await Promise.all([
      this.viewer.model(this.spec.mesh),this.viewer.texture(this.spec.texture),
    ]);
    this.material=createNativeMeshMaterial(map,{blendMode:2});
    // All shells are allocated after the preallocated projectile objects.
    this.firstOrder=this.viewer.track.placements.length+this.viewer.simulation.actors.length
      +this.viewer.combat.shots.length+this.viewer.combat.secondaryShots.length;
    for(let slot=0;slot<this.controller.entries.length;slot++){
      const mesh=new THREE.Mesh(geometry,this.material);
      mesh.visible=false;this.viewer.group.add(mesh);this.meshes.push(mesh);
    }
  }
  capture() {
    //Only active relative order matters to this draw pass. Compact it so an
    //ever-increasing host allocation counter cannot cross later effect phases.
    //This is submission ranking, not a claim about absolute native heap IDs.
    const orders=this.controller.entries.filter(Boolean).map(entry=>entry.objectOrder).sort((a,b)=>a-b);
    for(let slot=0;slot<this.meshes.length;slot++){
      const mesh=this.meshes[slot],entry=this.controller.entries[slot];
      mesh.visible=Boolean(entry);
      if(!entry)continue;
      mesh.position.fromArray(entry.position);
      setNativeMatrix(mesh,entry.matrix);
      mesh.userData.sector=entry.sector;
      mesh.renderOrder=nativeObjectRenderOrder(this.firstOrder+orders.indexOf(entry.objectOrder));
    }
  }
  dispose() {
    for(const mesh of this.meshes)mesh.removeFromParent();
    this.material?.dispose();this.meshes=[];
  }
}
