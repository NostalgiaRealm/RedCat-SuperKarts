import * as THREE from 'three';
import {getPlayerVisualSpec,createDriverAnimation,advanceDriverAnimation} from './player-assets.js';
import {nativeMatrix,setNativeMatrix} from './render-transforms.js';
import {nativeRotationMatrix} from './simulation/native-transform.js';
import {createNativeMeshMaterial} from './asset-materials.js';
import {nativeBonusVisual} from './simulation/native-bonus.js';
import {resolveAsset} from './asset-animation.js';
import {getNativeRescueVisualSpec} from './rescue-assets.js';
import {nativeRescueRingPositions} from './simulation/native-rescue.js';
import {getNativeKartShadowSpec,getNativeKartShadowPose,getSurfaceKartShadowGrid,surfaceKartShadowPositions} from './kart-shadow.js';
import {getNativeFinishFlagSpec,NativeFinishFlag} from './finish-flag.js';
import {nativeKartBrightness,sampleNativeKartGroundColor,advanceNativeKartColor} from './simulation/native-kart-color.js';
import {NATIVE_RENDER_ORDER,nativeObjectRenderOrder} from './render-order.js';

const pose=(body,rescue)=>({
  position:new THREE.Vector3(...(rescue?.renderPosition??body.position)),
  matrix:nativeMatrix(rescue?.matrix??body.matrix,rescue?.renderPosition??body.position),
});
// Copy packed native ARGB directly into existing GPU buffers. Particle and
// trail captures can touch thousands of vertices without temporary RGBA arrays.
const writeVertexColor=(target,index,color)=>{
  const offset=index*4;
  target[offset]=color>>>16&255;target[offset+1]=color>>>8&255;
  target[offset+2]=color&255;target[offset+3]=color>>>24;
};

// What the two shadow routines read from a kart, reused by every capture.
const shadowSource={position:null,sector:0,matrixTranslation:null,matrix:null};

export class KartVisual {
  static async load(viewer,config,manifest,character,carIndex,actor) {
    const visual=new KartVisual();
    visual.spec=getPlayerVisualSpec(config,manifest,character,carIndex);
    visual.actor=actor;
    visual.diffuse=0xffffffff;visual.renderDiffuse=0xffffffff;
    visual.brightness=nativeKartBrightness(config,viewer.track.id);
    visual.colorGeometries=new Set();visual.colorFrames=new Map();
    visual.group=new THREE.Group();visual.group.matrixAutoUpdate=false;
    visual.body=await viewer.mesh(visual.spec.body);
    visual.group.add(visual.body);
    visual.wheels=await Promise.all(visual.spec.wheels.map(spec=>viewer.mesh(spec)));
    visual.wheels.forEach((mesh,i)=>{
      mesh.position.fromArray(visual.spec.wheels[i].offset);visual.group.add(mesh);
    });
    const spec=visual.spec.driver;
    visual.driver=await viewer.mesh({mesh:spec.sequences.idle.frames[0].file,texture:spec.texture});
    visual.driver.position.fromArray(spec.offset);visual.group.add(visual.driver);
    const files=[...new Set(Object.values(spec.sequences).flatMap(sequence=>sequence.frames.map(frame=>frame.file)))];
    visual.frames=new Map(await Promise.all(files.map(async file=>[file,await viewer.model(file)])));
    for(const mesh of [visual.body,...visual.wheels]){
      mesh.geometry=visual.cloneColorGeometry(mesh.geometry);
    }
    visual.driver.geometry=visual.colorFrame(spec.sequences.idle.frames[0].file);
    visual.applyDiffuse(visual.diffuse);
    visual.animation=createDriverAnimation(spec);
    visual.previous=visual.current=pose(actor.body);
    const creationIndex=actor===viewer.motion?0:viewer.opponents.indexOf(actor)+1;
    visual.objectOrder=viewer.track.placements.length+creationIndex;
    //490d40 draws the parent then child slots0..4. Promise completion order
    // can allocate Three IDs differently, so give each native child a slot.
    [visual.body,...visual.wheels,visual.driver].forEach((mesh,part)=>
      mesh.renderOrder=nativeObjectRenderOrder(visual.objectOrder,{part}));
    viewer.group.add(visual.group);
    return visual;
  }
  tick(now,requests=[],rescue=null) {
    this.advanceAnimation(now,requests);
    this.capturePose(rescue);
  }
  capturePose(rescue=null){
    this.previous=this.current;this.current=pose(this.actor.body,rescue);
    this.group.userData.sector=this.actor.body.sector;
  }
  advanceAnimation(now,requests=[]){
    this.driver.geometry=this.colorFrame(advanceDriverAnimation(this.animation,now,requests).file);
    //44cac0 applies persistent body diffuse when it assigns the animated
    // frame.4903c0 will overwrite it with ground+country brightness on draw,
    // so only a kart drawn without that capture ever shows this one (present).
    this.pendingDiffuse=this.diffuse;
  }
  cloneColorGeometry(source){
    const geometry=source.clone();
    geometry.setAttribute('color',new THREE.Uint8BufferAttribute(
      new Uint8Array(geometry.attributes.position.count*4),4,true));
    this.colorGeometries.add(geometry);
    return geometry;
  }
  colorFrame(file){
    if(!this.colorFrames.has(file))this.colorFrames.set(file,this.cloneColorGeometry(this.frames.get(file)));
    return this.colorFrames.get(file);
  }
  applyDiffuse(color){
    // All racer children use native mode0. Modes1/2 are excluded by4902d0.
    this.writeDiffuse(this.body,color);this.writeDiffuse(this.driver,color);
    for(let i=0;i<this.wheels.length;i++)this.writeDiffuse(this.wheels[i],color);
  }
  writeDiffuse(mesh,color){
    // Each cloned frame remembers its bytes, so an unchanged colour uploads nothing.
    const attribute=mesh.geometry.attributes.color,array=attribute.array;
    if(attribute.nativeColor===color)return;
    attribute.nativeColor=color;
    for(let offset=0;offset<array.length;offset+=4)writeVertexColor(array,offset/4,color);
    attribute.needsUpdate=true;
  }
  captureColor(world,deltaSeconds,rescue=null){
    const body=this.actor.body;
    //4903c0 reads logical render+50, even on the Spawn relocation frame when
    //the separate matrix translation still draws the kart at its old position.
    const color=advanceNativeKartColor(this.diffuse,sampleNativeKartGroundColor(world,body),
      body.forwardSpeed,deltaSeconds,this.brightness);
    this.diffuse=color.diffuse;this.renderDiffuse=color.renderDiffuse;
    this.pendingDiffuse=null;
    this.applyDiffuse(this.renderDiffuse);
  }
  dispose(){
    this.group.removeFromParent();
    for(const geometry of this.colorGeometries)geometry.dispose();
    const materials=new Set();
    this.group.traverse(mesh=>{if(mesh.isMesh)materials.add(mesh.material);});
    for(const material of materials)material.dispose();
    this.colorGeometries.clear();this.colorFrames.clear();
  }
  present(alpha) {
    if(this.pendingDiffuse!=null){this.applyDiffuse(this.pendingDiffuse);this.pendingDiffuse=null;}
    this.group.position.lerpVectors(this.previous.position,this.current.position,alpha);
    // Suspension produces a non-orthonormal basis. Preserve its native scale
    // and tilt at each tick endpoint instead of converting it to a quaternion.
    for(let i=0;i<16;i++)this.group.matrix.elements[i]=
      this.previous.matrix.elements[i]*(1-alpha)+this.current.matrix.elements[i]*alpha;
    this.group.matrixWorldNeedsUpdate=true;
    this.wheels.forEach((mesh,i)=>{
      const wheel=this.actor.ground.wheels[i];mesh.position.fromArray(wheel.local);
      setNativeMatrix(mesh,nativeRotationMatrix([wheel.spin,wheel.steeringAngle,0]));
    });
  }
}

/** Shared native shadow shape is copied per browser draw, because the source
 * rebuilds the same four vertices immediately before each kart is rendered. */
export class KartShadowVisual {
  static async load(viewer,manifest,bodySpec,actor) {
    const visual=new KartShadowVisual();
    visual.actor=actor;
    const spec=getNativeKartShadowSpec(manifest,bodySpec.bounds);
    const [original,map]=await Promise.all([viewer.model(spec.mesh),viewer.texture(spec.texture)]);
    const geometry=original.clone();
    geometry.setAttribute('position',new THREE.Float32BufferAttribute(spec.position,3));
    geometry.setAttribute('uv',new THREE.Float32BufferAttribute(spec.uv,2));
    geometry.setAttribute('color',new THREE.Uint8BufferAttribute(spec.rgba,4,true));
    // The shared S_SHADOW model is smaller than the kart-sized quad written
    // by4260c0. A clone retains the source sphere until explicitly refreshed.
    geometry.computeBoundingBox();geometry.computeBoundingSphere();
    const material=createNativeMeshMaterial(map,{blendMode:1,side:THREE.FrontSide});
    // 4260c0 draws immediately, BEFORE the corresponding kart. It does not
    // enter48f600's transparent queue and inherits enabled Z writes.
    material.transparent=false;material.depthWrite=true;
    visual.mesh=new THREE.Mesh(geometry,material);
    //4918f0 has already applied the kart's engine visibility range.4260c0
    // submits this resized quad directly; clipping belongs to the GPU. Avoid
    // an extra Three sphere rejection, including tilted/nonorthogonal poses.
    visual.mesh.frustumCulled=false;
    const graphics=(viewer.runtimeConfig??viewer.config)?.['sndgfx.ini']?.['gfx options']??{};
    visual.mesh.userData.nativeInheritBlend=Number(graphics.alpha_blending??1)===0;
    visual.mesh.userData.ownedGeometry=true;
    visual.mesh.matrixAutoUpdate=false;
    const creationIndex=actor===viewer.motion?0:viewer.opponents.indexOf(actor)+1;
    visual.mesh.renderOrder=nativeObjectRenderOrder(viewer.track.placements.length+creationIndex,{shadow:true});
    // "Schaduwen op het wegdek" (browser enhancement): the same quad as a grid
    // on the ground surface. World positions, so the mesh matrix is identity.
    visual.nativeGeometry=geometry;
    visual.grid=getSurfaceKartShadowGrid(spec,Array.from(original.index.array));
    const surface=new THREE.BufferGeometry();
    surface.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(visual.grid.count*3),3)
      .setUsage(THREE.DynamicDrawUsage));
    surface.setAttribute('uv',new THREE.Float32BufferAttribute(visual.grid.uv,2));
    surface.setAttribute('color',new THREE.Uint8BufferAttribute(visual.grid.rgba,4,true));
    surface.setIndex(visual.grid.index);
    visual.surfaceGeometry=surface;
    visual.surfacePositions=[new Float32Array(visual.grid.count*3),new Float32Array(visual.grid.count*3)];
    visual.setSurface(viewer.surfaceShadows===true);
    viewer.group.add(visual.mesh);
    return visual;
  }
  setSurface(enabled,world=null,rescue=null) {
    this.surface=Boolean(enabled);
    this.mesh.geometry=this.surface?this.surfaceGeometry:this.nativeGeometry;
    this.mesh.userData.inactiveGeometry=this.surface?this.nativeGeometry:this.surfaceGeometry;
    // Pull the draped quad in front of the coplanar road in depth. As a decal
    // it writes no Z, so it cannot hide wheel bottoms just below the lift.
    Object.assign(this.mesh.material,this.surface?
      {polygonOffset:true,polygonOffsetFactor:-1,polygonOffsetUnits:-4,depthWrite:false}:
      {polygonOffset:false,polygonOffsetFactor:0,polygonOffsetUnits:0,depthWrite:true});
    if(this.surface)this.mesh.matrix.identity();
    this.mesh.matrixWorldNeedsUpdate=true;
    // Restart interpolation in the new mode instead of blending across it.
    this.current=null;
    if(world){this.capture(world,rescue);this.present(1);}
  }
  capture(world,rescue=null) {
    const body=this.actor.body;
    this.mesh.userData.sector=body.sector;
    const source=shadowSource;
    source.position=body.position;source.sector=body.sector;
    source.matrixTranslation=rescue?.renderPosition??body.position;source.matrix=rescue?.matrix??body.matrix;
    const current=getNativeKartShadowPose(source,world.sectors[body.sector].fallback);
    // Convert each captured endpoint once. Unlocked presentation can reuse
    // these matrices until the next simulation capture without allocations.
    current.renderMatrix=nativeMatrix(current.matrix,current.position);
    if(this.surface){
      // Two reused buffers: the previous capture and this one.
      const first=!this.current;
      if(!first)this.surfacePositions.reverse();
      surfaceKartShadowPositions(source,world,this.grid,this.surfacePositions[1]);
      if(first)this.surfacePositions[0].set(this.surfacePositions[1]);
    }
    this.previous=this.current??current;this.current=current;
  }
  present(alpha) {
    if(!this.current)return;
    if(this.surface){
      const [before,after]=this.surfacePositions,target=this.surfaceGeometry.attributes.position;
      for(let i=0;i<after.length;i++)target.array[i]=before[i]*(1-alpha)+after[i]*alpha;
      target.needsUpdate=true;
      return;
    }
    const before=this.previous.renderMatrix,after=this.current.renderMatrix;
    for(let i=0;i<16;i++)this.mesh.matrix.elements[i]=
      before.elements[i]*(1-alpha)+after.elements[i]*alpha;
    this.mesh.matrixWorldNeedsUpdate=true;
  }
}

/** Original camera-relative flag strips. Capture once at the render boundary;
 * presentation never advances the source's per-frame wave counter. */
export class FinishFlagVisual {
  static async load(viewer,manifest) {
    const visual=new FinishFlagVisual(),spec=getNativeFinishFlagSpec(manifest);
    const original=await viewer.texture(spec.texture),map=original.clone();
    map.minFilter=map.magFilter=THREE.NearestFilter;map.generateMipmaps=false;map.needsUpdate=true;
    const geometry=new THREE.BufferGeometry();
    geometry.setAttribute('position',new THREE.Float32BufferAttribute(spec.position,3));
    geometry.setAttribute('uv',new THREE.Float32BufferAttribute(spec.uv,2));
    geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(340*4),4,true));
    // Native strips face the camera in its +Z coordinate frame. Three camera
    // space faces -Z, so reverse localZ without changing the original data.
    geometry.setIndex(spec.index);
    const material=createNativeMeshMaterial(map,{blendMode:1,side:THREE.FrontSide});
    material.depthTest=false;material.depthWrite=false;
    visual.mesh=new THREE.Mesh(geometry,material);
    visual.mesh.scale.z=-1;visual.mesh.visible=false;visual.mesh.frustumCulled=false;
    visual.mesh.renderOrder=NATIVE_RENDER_ORDER.finishFlag;
    visual.controller=new NativeFinishFlag();
    viewer.camera.add(visual.mesh);
    if(!viewer.camera.parent)viewer.scene.add(viewer.camera);
    return visual;
  }
  setEnabled(enabled,deltaSeconds) {this.controller.setEnabled(enabled,deltaSeconds);}
  capture() {
    const frame=this.controller.capture();this.mesh.visible=Boolean(frame);
    if(!frame)return;
    const positions=this.mesh.geometry.attributes.position;
    frame.z.forEach((z,i)=>{positions.array[i*3+2]=z;});
    positions.needsUpdate=true;
    const colors=this.mesh.geometry.attributes.color;
    colors.array.set(frame.rgba);colors.needsUpdate=true;
  }
  dispose() {
    this.mesh.removeFromParent();this.mesh.geometry.dispose();
    this.mesh.material.map.dispose();this.mesh.material.dispose();
  }
}

/** Original428a00 six-vertex cloud fans, in the controller's sorted order.
 * Simulation owns emission, random calls, ageing and the camera snapshot. */
export class SmokeVisuals {
  constructor(viewer){this.viewer=viewer;this.meshes=[];}
  async load(manifest) {
    const file=resolveAsset(manifest,'images','s_sfx.tga'),map=await this.viewer.texture(file);
    const material=createNativeMeshMaterial(map,{blendMode:1,side:THREE.FrontSide});
    material.blendSrc=THREE.SrcAlphaFactor;material.blendDst=THREE.OneFactor;
    material.depthWrite=true;
    // One buffer per attribute for all 70 fans: 3 uploads per update, not 3 per cloud.
    const position=new THREE.Float32BufferAttribute(new Float32Array(70*18),3);
    const uv=new THREE.Float32BufferAttribute(new Float32Array(70*12),2);
    const color=new THREE.Uint8BufferAttribute(new Uint8Array(70*24),4,true);
    const indices=[];
    for(let index=0;index<70;index++)for(const i of [0,1,2,0,2,3,0,3,4,0,4,5])indices.push(index*6+i);
    const shared=new THREE.BufferAttribute(new Uint16Array(indices),1);
    this.attributes={position,uv,color};
    for(let index=0;index<70;index++){
      const geometry=new THREE.BufferGeometry();
      geometry.setAttribute('position',position);geometry.setAttribute('uv',uv);geometry.setAttribute('color',color);
      geometry.setIndex(shared);geometry.setDrawRange(index*12,12);
      const mesh=new THREE.Mesh(geometry,material);
      mesh.matrixAutoUpdate=false;mesh.visible=false;mesh.frustumCulled=false;
      mesh.userData.ownedGeometry=true;mesh.renderOrder=NATIVE_RENDER_ORDER.smoke+index;
      this.viewer.group.add(mesh);this.meshes.push(mesh);
    }
    return this;
  }
  capture(frames=[]) {
    const meshes=this.meshes,count=frames.length,{position,uv,color}=this.attributes;
    for(let index=0;index<meshes.length;index++){
      const mesh=meshes[index],frame=frames[index];mesh.visible=index<count;
      if(index>=count)continue;
      const p=frame.vertices,t=frame.uv,c=frame.rgba,base=index*18,baseUV=index*12,baseColor=index*24;
      for(let i=0;i<18;i++)position.array[base+i]=p[i];
      for(let i=0;i<12;i++)uv.array[baseUV+i]=t[i];
      for(let i=0;i<24;i++)color.array[baseColor+i]=c[i];
      nativeMatrix(frame.matrix,frame.position,mesh.matrix);mesh.matrixWorldNeedsUpdate=true;
    }
    if(!count)return;
    position.clearUpdateRanges();position.addUpdateRange(0,count*18);position.needsUpdate=true;
    uv.clearUpdateRanges();uv.addUpdateRange(0,count*12);uv.needsUpdate=true;
    color.clearUpdateRanges();color.addUpdateRange(0,count*24);color.needsUpdate=true;
  }
}

/**483350 draws camera-space triangle lists after the finish flag. Parenting
 * to the camera cancels its view matrix; local-Z reflection converts native
 * +Z camera coordinates to Three's -Z without changing the source vertices. */
export class WeatherVisuals {
  constructor(viewer,controller){this.viewer=viewer;this.controller=controller;this.mesh=null;this.written=0;}
  async load(manifest){
    if(!this.controller)return this;
    const map=await this.viewer.texture(resolveAsset(manifest,'images','s_sfx.tga'));
    const geometry=new THREE.BufferGeometry(),count=this.controller.count;
    geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(count*18),3));
    geometry.setAttribute('uv',new THREE.Float32BufferAttribute(new Float32Array(count*12),2));
    geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(count*24),4,true));
    const material=createNativeMeshMaterial(map,{blendMode:1});
    material.blendSrc=THREE.SrcAlphaFactor;material.blendDst=THREE.OneFactor;
    material.depthTest=true;material.depthWrite=false;
    this.mesh=new THREE.Mesh(geometry,material);
    this.mesh.scale.z=-1;this.mesh.renderOrder=NATIVE_RENDER_ORDER.weather;this.mesh.frustumCulled=false;this.mesh.visible=false;
    this.viewer.camera.add(this.mesh);
    if(!this.viewer.camera.parent)this.viewer.scene.add(this.viewer.camera);
    return this;
  }
  capture(frames=[]){
    if(!this.mesh)return;
    const count=frames.length,attributes=this.mesh.geometry.attributes,position=attributes.position,target=position.array;
    this.mesh.visible=count>0;
    if(!count)return;
    for(let index=0;index<count;index++){
      const vertices=frames[index].vertices,base=index*18;
      for(let i=0;i<18;i++)target[base+i]=vertices[i];
    }
    // A slot's UV and colour never change: write each slot the first time it is used.
    if(count>this.written){
      for(let index=this.written;index<count;index++){
        attributes.uv.array.set(frames[index].uv,index*12);
        frames[index].argb.forEach((color,vertex)=>writeVertexColor(attributes.color.array,index*6+vertex,color));
      }
      attributes.uv.addUpdateRange(this.written*12,(count-this.written)*12);attributes.uv.needsUpdate=true;
      attributes.color.addUpdateRange(this.written*24,(count-this.written)*24);attributes.color.needsUpdate=true;
      this.written=count;
    }
    this.mesh.geometry.setDrawRange(0,count*6);
    position.clearUpdateRanges();position.addUpdateRange(0,count*18);position.needsUpdate=true;
  }
  dispose(){
    if(!this.mesh)return;
    this.mesh.removeFromParent();this.mesh.geometry.dispose();this.mesh.material.dispose();
  }
}

/**426e50 submits left/right triangle strips immediately after the world.
 * Source INVSRCALPHA/SRCALPHA blending makes increasing alpha fade the marks. */
export class SkidmarkVisuals {
  constructor(viewer){this.viewer=viewer;this.meshes=[];}
  async load(manifest){
    const map=await this.viewer.texture(resolveAsset(manifest,'images','s_sfx.tga'));
    const material=createNativeMeshMaterial(map,{blendMode:1});
    material.blendSrc=THREE.OneMinusSrcAlphaFactor;material.blendDst=THREE.SrcAlphaFactor;
    material.depthWrite=true;
    const indices=[];
    for(let index=0;index<96;index++)indices.push(...(index%2
      ?[index+1,index,index+2]:[index,index+1,index+2]));
    for(let id=0;id<20;id++)for(let side=0;side<2;side++){
      const geometry=new THREE.BufferGeometry();
      geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(98*3),3));
      geometry.setAttribute('uv',new THREE.Float32BufferAttribute(new Float32Array(98*2),2));
      geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(98*4),4,true));
      geometry.setIndex(indices);
      const mesh=new THREE.Mesh(geometry,material);
      mesh.visible=false;mesh.frustumCulled=false;mesh.renderOrder=NATIVE_RENDER_ORDER.skidmarks+id*2+side;
      mesh.userData.ownedGeometry=true;
      this.viewer.group.add(mesh);this.meshes.push(mesh);
    }
    return this;
  }
  capture(frames=[]){
    const meshes=this.meshes;
    for(let i=0;i<meshes.length;i++)meshes[i].visible=false;
    for(let f=0;f<frames.length;f++){
      const frame=frames[f];
      for(let side=0;side<2;side++){
        const vertices=frame.sides[side],count=vertices.length,mesh=meshes[frame.id*2+side];
        mesh.visible=count>2;
        // Vertices only ever append, and only alpha fades until it reaches 255.
        const state=mesh.userData;
        if(state.source!==vertices){state.source=vertices;state.written=0;state.settled=false;}
        if(state.settled&&state.written===count)continue;
        const {position,uv,color}=mesh.geometry.attributes,c=color.array,first=state.written;
        for(let i=first;i<count;i++){
          const vertex=vertices[i],q=vertex.position,t=vertex.uv,ip=i*3,it=i*2;
          position.array[ip]=q[0];position.array[ip+1]=q[1];position.array[ip+2]=q[2];
          uv.array[it]=t[0];uv.array[it+1]=t[1];
          writeVertexColor(c,i,vertex.argb);
        }
        let changed=first<count,settled=true;
        for(let i=0;i<first;i++){
          const alpha=vertices[i].argb>>>24;
          if(alpha!==255)settled=false;
          if(c[i*4+3]!==alpha){c[i*4+3]=alpha;changed=true;}
        }
        if(first<count){
          for(let i=first;i<count;i++)if(vertices[i].argb>>>24!==255)settled=false;
          position.clearUpdateRanges();position.addUpdateRange(0,count*3);position.needsUpdate=true;
          uv.clearUpdateRanges();uv.addUpdateRange(0,count*2);uv.needsUpdate=true;
          mesh.geometry.setDrawRange(0,Math.max(0,count-2)*3);
          state.written=count;
        }
        if(changed){color.clearUpdateRanges();color.addUpdateRange(0,count*4);color.needsUpdate=true;}
        state.settled=settled;
      }
    }
  }
}

/**4844e0 draws two explosion strips in world space after the weather pass.
 * The original list prepends new entries; frame order preserves that list. */
export class ExplosionVisuals {
  constructor(viewer){this.viewer=viewer;this.meshes=new Map();}
  async load(manifest){
    const map=await this.viewer.texture(resolveAsset(manifest,'images','s_sfx.tga'));
    this.material=createNativeMeshMaterial(map,{blendMode:1});
    this.material.blendSrc=THREE.SrcAlphaFactor;this.material.blendDst=THREE.OneFactor;
    this.material.depthTest=true;this.material.depthWrite=true;
    return this;
  }
  capture(frames=[]){
    if(!frames.length&&!this.meshes.size)return;
    const active=new Set(frames.map(frame=>frame.id));
    for(const [id,mesh]of this.meshes)if(!active.has(id)){
      mesh.removeFromParent();mesh.geometry.dispose();this.meshes.delete(id);
    }
    frames.forEach((frame,index)=>{
      let mesh=this.meshes.get(frame.id);
      if(!mesh){
        const geometry=new THREE.BufferGeometry(),indices=[];
        geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(24*3),3));
        geometry.setAttribute('uv',new THREE.Float32BufferAttribute(new Float32Array(24*2),2));
        geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(24*4),4,true));
        for(const strip of frame.strips)for(let i=0;i<strip.length-2;i++)
          indices.push(...(i%2?[strip[i+1],strip[i],strip[i+2]]:[strip[i],strip[i+1],strip[i+2]]));
        geometry.setIndex(indices);
        mesh=new THREE.Mesh(geometry,this.material);
        mesh.frustumCulled=false;mesh.userData.ownedGeometry=true;
        this.meshes.set(frame.id,mesh);this.viewer.group.add(mesh);
      }
      mesh.renderOrder=NATIVE_RENDER_ORDER.explosions+index;
      const attributes=mesh.geometry.attributes;
      attributes.position.array.set(frame.vertices);attributes.uv.array.set(frame.uv);
      frame.argb.forEach((color,vertex)=>writeVertexColor(attributes.color.array,vertex,color));
      for(const attribute of Object.values(attributes))attribute.needsUpdate=true;
    });
  }
  dispose(){
    for(const mesh of this.meshes.values()){mesh.removeFromParent();mesh.geometry.dispose();}
    this.meshes.clear();this.material?.dispose();
  }
}

/**488b40 jet strips, then48a530 trail strips. The controller already performs
 * native draw-time shrinking; this layer only copies the captured vertices. */
export class StreamVisuals {
  constructor(viewer){this.viewer=viewer;this.jets=[];this.ribbons=[];this.followed=new WeakMap();}
  async load(manifest){
    // The shared loader applies the original key-to-black conversion to every
    // RGB texture, before filtering; streams no longer need a private upload.
    const map=await this.viewer.texture(resolveAsset(manifest,'images','s_sfx.tga'));
    this.material=createNativeMeshMaterial(map,{blendMode:1});
    this.material.blendSrc=this.material.blendDst=THREE.OneFactor;
    this.material.depthWrite=true;
    return this;
  }
  mesh(pool,index,capacity,order){
    if(!pool[index]){
      const geometry=new THREE.BufferGeometry(),indices=[];
      geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(capacity*3),3));
      geometry.setAttribute('uv',new THREE.Float32BufferAttribute(new Float32Array(capacity*2),2));
      geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(capacity*4),4,true));
      for(let i=0;i<capacity-2;i++)indices.push(...(i%2?[i+1,i,i+2]:[i,i+1,i+2]));
      geometry.setIndex(indices);
      const mesh=new THREE.Mesh(geometry,this.material);
      mesh.frustumCulled=false;mesh.userData.ownedGeometry=true;mesh.renderOrder=order+index;
      this.viewer.group.add(mesh);pool.push(mesh);
    }
    return pool[index];
  }
  copy(pool,frames,capacity,order){
    for(let i=0;i<pool.length;i++)pool[i].visible=false;
    for(let index=0;index<frames.length;index++){
      const vertices=frames[index],count=vertices.length,mesh=this.mesh(pool,index,capacity,order);
      const {position,uv,color}=mesh.geometry.attributes,p=position.array,t=uv.array,c=color.array;
      mesh.visible=count>2;
      let uvChanged=false,colorChanged=false;
      for(let i=0;i<count;i++){
        const vertex=vertices[i],q=vertex.position,s=vertex.uv,argb=vertex.color,ip=i*3,it=i*2,ic=i*4;
        p[ip]=q[0];p[ip+1]=q[1];p[ip+2]=q[2];
        if(t[it]!==s[0]||t[it+1]!==s[1]){t[it]=s[0];t[it+1]=s[1];uvChanged=true;}
        const red=argb>>>16&255,green=argb>>>8&255,blue=argb&255,alpha=argb>>>24;
        if(c[ic]!==red||c[ic+1]!==green||c[ic+2]!==blue||c[ic+3]!==alpha){
          c[ic]=red;c[ic+1]=green;c[ic+2]=blue;c[ic+3]=alpha;colorChanged=true;
        }
      }
      mesh.geometry.setDrawRange(0,Math.max(0,count-2)*3);
      // Only the used vertices: ribbon buffers hold 1000, ribbons use about 10-24.
      if(count>0){position.clearUpdateRanges();position.addUpdateRange(0,count*3);position.needsUpdate=true;}
      if(uvChanged){uv.addUpdateRange(0,count*2);uv.needsUpdate=true;}
      if(colorChanged){color.addUpdateRange(0,count*4);color.needsUpdate=true;}
    }
  }
  capture({jets=[],ribbons=[]}={},{follow=[]}={}){
    this.copy(this.jets,jets,7,NATIVE_RENDER_ORDER.jets);
    this.copy(this.ribbons,ribbons,1000,NATIVE_RENDER_ORDER.ribbons);
    // "Motorlicht volgt de kart" (browser enhancement): 488850 and the kart
    // draw read one matrix per native update. Karts are drawn between their
    // last two tick poses, so their flares keep both tick captures as well,
    // keyed by the flare's own vertex list across pool reordering.
    for(let index=0;index<jets.length;index++){
      const vertices=jets[index],mesh=this.jets[index],position=mesh.geometry.attributes.position.array;
      if(!follow.includes(vertices)){mesh.userData.follow=null;continue;}
      const size=vertices.length*3;
      let record=this.followed.get(vertices);
      if(!record){
        record={before:position.slice(0,size),after:position.slice(0,size)};
        this.followed.set(vertices,record);
      }else{
        const before=record.after,after=record.before;
        for(let i=0;i<size;i++)after[i]=position[i];
        record.before=before;record.after=after;
      }
      mesh.userData.follow=record;
    }
  }
  /** Same alpha as KartVisual.present; rocket flares keep their tick pose. */
  present(alpha){
    for(const mesh of this.jets){
      const follow=mesh.userData.follow;
      if(!mesh.visible||!follow)continue;
      const {before,after}=follow,target=mesh.geometry.attributes.position;
      for(let i=0;i<after.length;i++)target.array[i]=before[i]*(1-alpha)+after[i]*alpha;
      target.needsUpdate=true;
    }
  }
  /** Back to the latest tick positions; the next captures start afresh. */
  unfollow(){
    for(const mesh of this.jets){
      const follow=mesh.userData.follow;
      if(!follow)continue;
      mesh.geometry.attributes.position.array.set(follow.after);
      mesh.geometry.attributes.position.needsUpdate=true;mesh.userData.follow=null;
    }
    this.followed=new WeakMap();
  }
  dispose(){
    for(const mesh of [...this.jets,...this.ribbons]){mesh.removeFromParent();mesh.geometry.dispose();}
    this.jets=[];this.ribbons=[];this.material?.dispose();
  }
}

/** 487780 submits two fixed 24-vertex lists in native world coordinates. */
export class HomingArmVisuals {
  constructor(viewer,controller){this.viewer=viewer;this.controller=controller;this.meshes=[];}
  async load(manifest){
    const map=await this.viewer.texture(resolveAsset(manifest,'images','s_sfx.tga'));
    const material=createNativeMeshMaterial(map);
    //430020 draws arms after the world deferred queue, while blending remains
    // disabled. Use the ordered late queue without enabling color blending.
    material.transparent=true;material.blending=THREE.NoBlending;material.depthWrite=true;
    for(let index=0;index<20;index++){
      const geometry=new THREE.BufferGeometry();
      geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(48*3),3));
      geometry.setAttribute('uv',new THREE.Float32BufferAttribute(new Float32Array(48*2),2));
      geometry.setAttribute('color',new THREE.Uint8BufferAttribute(new Uint8Array(48*4),4,true));
      const mesh=new THREE.Mesh(geometry,material);
      mesh.frustumCulled=false;mesh.visible=false;mesh.renderOrder=NATIVE_RENDER_ORDER.arms+index;
      mesh.userData.ownedGeometry=true;this.viewer.group.add(mesh);this.meshes.push(mesh);
    }
  }
  capture(){
    const entries=this.controller.entries;
    for(let index=0;index<this.meshes.length;index++){
      const mesh=this.meshes[index],entry=entries[index];mesh.visible=Boolean(entry);
      if(!entry)continue;
      const attributes=mesh.geometry.attributes,vertices=entry.vertices;
      for(let i=0;i<vertices.length;i++){
        const vertex=vertices[i];
        attributes.position.array.set(vertex.position,i*3);
        attributes.uv.array.set(vertex.uv,i*2);
        writeVertexColor(attributes.color.array,i,vertex.color);
      }
      attributes.position.needsUpdate=attributes.uv.needsUpdate=attributes.color.needsUpdate=true;
    }
  }
}

/** Original Spawn.cpp strips surrounding the shrinking/growing racer. */
export class RescueVisuals {
  constructor(viewer,controller){this.viewer=viewer;this.controller=controller;this.meshes=[];}
  async load(manifest) {
    const graphics=(this.viewer.runtimeConfig??this.viewer.config)?.['sndgfx.ini']?.['gfx options']??{};
    this.enabled=Number(graphics.jetstreams??1)!==0&&Number(graphics.alpha_blending??1)!==0;
    const spec=getNativeRescueVisualSpec(manifest),map=await this.viewer.texture(spec.texture);
    const material=createNativeMeshMaterial(map,{blendMode:1,side:THREE.FrontSide});
    material.blendSrc=material.blendDst=THREE.OneFactor;
    material.depthWrite=true;
    for(let index=0;index<10;index++){
      const geometry=new THREE.BufferGeometry();
      geometry.setAttribute('position',new THREE.Float32BufferAttribute(new Float32Array(spec.vertexCount*3),3));
      geometry.setAttribute('uv',new THREE.Float32BufferAttribute(spec.uv,2));
      geometry.setAttribute('color',new THREE.Uint8BufferAttribute(spec.rgba,4,true));
      geometry.setIndex(spec.index);
      const mesh=new THREE.Mesh(geometry,material);mesh.visible=false;
      mesh.renderOrder=NATIVE_RENDER_ORDER.rescue+index;
      mesh.userData.ownedGeometry=true;
      // Vertices are already in original world space.
      mesh.frustumCulled=false;this.viewer.group.add(mesh);this.meshes.push(mesh);
    }
  }
  capture() {
    const entries=this.controller.entries;
    for(let index=0;index<this.meshes.length;index++){
      const mesh=this.meshes[index],entry=entries[index];mesh.visible=this.enabled&&Boolean(entry);
      if(!mesh.visible)continue;
      nativeRescueRingPositions(entry,{target:mesh.geometry.attributes.position.array});
      mesh.geometry.attributes.position.needsUpdate=true;
    }
  }
}

export class ProjectileVisuals {
  constructor(viewer,combat){this.viewer=viewer;this.combat=combat;this.resources=new Map();this.meshes=new Map();}
  async load(config,manifest) {
    // Preload every original level, including secondary bubbles, so firing
    // never inserts an asynchronous resource boundary into the simulation.
    await Promise.all([1,2,3,4].flatMap(type=>[1,2,3].map(async level=>{
      const spec=nativeBonusVisual(config,manifest,type,level,'shot');
      const [geometry,map]=await Promise.all([
        this.viewer.model(spec.mesh),
        this.viewer.texture(resolveAsset(manifest,'images',spec.texture.replace(/\.pcx$/i,'.tga'))),
      ]);
      this.resources.set(`${type}:${level}`,{geometry,material:createNativeMeshMaterial(map)});
    })));
    for(const shot of [...this.combat.shots,...this.combat.secondaryShots]){
      const mesh=new THREE.Mesh();mesh.visible=false;
      mesh.renderOrder=nativeObjectRenderOrder(this.viewer.track.placements.length+
        this.viewer.simulation.actors.length+this.meshes.size);
      this.viewer.group.add(mesh);this.meshes.set(shot,mesh);
    }
    this.slots=[...this.meshes];
  }
  capture() {
    for(let index=0;index<this.slots.length;index++){
      const shot=this.slots[index][0],mesh=this.slots[index][1];
      mesh.visible=shot.state===2;
      if(!mesh.visible)continue;
      const resource=this.resources.get(`${shot.type}:${shot.level}`);
      mesh.geometry=resource.geometry;mesh.material=resource.material;
      mesh.userData.sector=shot.sector;
      mesh.position.fromArray(shot.position);setNativeMatrix(mesh,shot.matrix);
    }
  }
}
