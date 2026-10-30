import * as THREE from 'three';
import {getHudMeshSpec,getNativeHudCameraSpec,nativeHudIniTransform,nativeHudElementTransform} from './hud-mesh.js';
import {createNativeMeshMaterial} from './asset-materials.js';
import {nativeMatrix} from './render-transforms.js';
import {nativeRotationMatrix} from './simulation/native-transform.js';
import {nativeMinimapRacers} from './simulation/native-minimap.js';
import {createNativeHudPortraits,updateNativeHudPortraits,getNativeHudPortraitCommands} from './hud-portraits.js';
import {NativeBonusHud} from './simulation/native-bonus-hud.js';
import {nativeBonusVisual} from './simulation/native-bonus.js';
import {nativeCountdownY} from './simulation/native-countdown.js';
import {raceHudLayout} from './race-hud-layout.js';
import {createNativeStarHudConfig,getNativeStarHudCommands} from './simulation/native-star-hud.js';
import {NativeHudArrows,NATIVE_ARROW_ALPHA} from './simulation/native-hud-arrows.js';
import {nativeProjectileFacing} from './simulation/native-projectile.js';

const NONE=Object.freeze({}),scratchScale=new THREE.Vector3();
const ARROW_IDS=['backarrow','junctionarrow'];
const portraitsMoved=(state,memo)=>{
  let changed=false,k=0;
  for(const {position}of state.portraits)for(let i=0;i<3;i++,k++)if(memo[k]!==position[i]){memo[k]=position[i];changed=true;}
  for(const y of state.labelY){if(memo[k]!==y){memo[k]=y;changed=true;}k++;}
  return changed;
};
function applyLayerViewport(renderer){
  const v=this.parent.userData.viewport;renderer.setViewport(v.x,v.y,v.width,v.height);
}
const mergeOverrides=(base={},extra={})=>{
  const result={...base};
  for(const [id,value]of Object.entries(extra))result[id]={...result[id],...value};
  return result;
};

/**
 * Render the original overlay models at HUD resolution, independently of the
 * race render scale. Groups retain the authored 640x480 projection; wide and
 * portrait views anchor each group without stretching its original artwork.
 */
export class RaceHudMeshes {
  constructor(viewer,config,manifest,simulation) {
    Object.assign(this,{viewer,config:createNativeStarHudConfig(config),manifest,simulation});
    this.renderer=viewer.renderer;
    const projection=getNativeHudCameraSpec();
    this.camera=new THREE.PerspectiveCamera(projection.verticalFov*180/Math.PI,640/480,projection.near,projection.far);
    this.layers=new Map();this.elements=new Map();this.resources=new Map();this.textures=new Map();
    this.loadedTextures=new Set();this.materials=new Map();
    this.arrowEvents=new WeakSet();
  }
  layer(name) {
    if(!this.layers.has(name)){
      const scene=new THREE.Scene(),group=new THREE.Group();group.scale.z=-1;scene.add(group);
      // The layer never moves: compose once so per-mesh world updates stay O(1).
      group.updateMatrix();group.matrixAutoUpdate=false;group.updateMatrixWorld();
      this.layers.set(name,{scene,group});
    }
    return this.layers.get(name);
  }
  spec(id,options={}) {
    return getHudMeshSpec(this.config,this.manifest,id,{trackId:this.viewer.track.id,...options});
  }
  texture(file) {
    if(!this.textures.has(file))this.textures.set(file,this.viewer.texture(file).then(source=>{
      // The overlay owns sampler state independently of the restored world
      // state. Keep its source image/key/gamma shared; see native-hud-sampler.
      const map=source.clone();map.minFilter=map.magFilter=THREE.LinearFilter;
      map.needsUpdate=true;this.loadedTextures.add(map);return map;
    }));
    return this.textures.get(file);
  }
  setSampler({min,mag}) {
    const minFilter=min===2?THREE.LinearFilter:THREE.NearestFilter;
    const magFilter=mag===2?THREE.LinearFilter:THREE.NearestFilter;
    for(const map of this.loadedTextures){
      if(map.minFilter===minFilter&&map.magFilter===magFilter)continue;
      map.minFilter=minFilter;map.magFilter=magFilter;map.needsUpdate=true;
    }
  }
  async resource(spec) {
    const key=`${spec.mesh}|${spec.texture}|${spec.rgba.join(',')}`;
    if(!this.resources.has(key))this.resources.set(key,(async()=>{
      const [original,map]=await Promise.all([this.viewer.model(spec.mesh),this.texture(spec.texture)]);
      const geometry=original.clone(),colors=new Uint8Array(geometry.attributes.position.count*4);
      for(let i=0;i<geometry.attributes.position.count;i++)colors.set(spec.rgba,i*4);
      geometry.setAttribute('color',new THREE.Uint8BufferAttribute(colors,4,true));
      let material=this.materials.get(map);
      if(!material){
        material=createNativeMeshMaterial(map,{blendMode:1});
        material.depthTest=false;material.depthWrite=false;this.materials.set(map,material);
      }
      return {geometry,material};
    })());
    return this.resources.get(key);
  }
  async add(id,{layer,animation,frames=[0],overrides={},variants}={}) {
    const choices=new Map(variants?Object.entries(variants):frames.map(frame=>[frame,{animation,frame}]));
    const resources=await Promise.all([...choices].map(async([key,choice])=>{
      const spec=this.spec(id,{...choice,overrides:mergeOverrides(overrides,choice.overrides)});
      if(!spec.mesh||!spec.texture)throw new Error(`Missing original HUD model for ${id}`);
      return [key,await this.resource(spec)];
    }));
    const mesh=new THREE.Mesh();mesh.matrixAutoUpdate=false;mesh.frustumCulled=false;
    mesh.renderOrder=this.elements.size;mesh.onBeforeRender=applyLayerViewport;
    const parent=layer??this.config['overlay.ini'][id].parent.toLowerCase();
    this.layer(parent).group.add(mesh);
    // Overlay.ini-only inputs of getHudMeshSpec, parsed once per element.
    const first=this.spec(id,{...choices.values().next().value}),section=this.config['overlay.ini'][id];
    const ini=nativeHudIniTransform(section);
    this.elements.set(id,{mesh,choices,defaultKey:choices.keys().next().value,frames:new Map(resources),
      last:new Float64Array(9).fill(NaN),basis:null,
      base:{context:first.parentContext,parents:first.parents,position:ini.position,scale:ini.scale,rotation:ini.rotation,
        visible:String(section.visible??'').trim().toLowerCase()!=='false'}});
    this.update(id,{overrides});
  }
  update(id,{frame,variant,overrides=NONE,visible}={}) {
    const element=this.elements.get(id);
    if(!element)throw new Error(`HUD element has not been loaded: ${id}`);
    const key=variant??frame??element.defaultKey,resource=element.frames.get(key);
    if(!resource)throw new Error(`HUD frame has not been loaded: ${id}/${key}`);
    const {mesh,base,last}=element,authored=element.choices.get(key)?.overrides;
    const own=overrides[id],fixed=authored?.[id];
    mesh.geometry=resource.geometry;mesh.material=resource.material;
    if(visible===undefined){
      visible=true;
      // Same result as getHudMeshSpec's parent chain: only .visible overrides reach here.
      for(const [parent,shown]of base.parents)visible=visible&&(overrides[parent]?.visible??authored?.[parent]?.visible??shown);
      visible=visible&&(own?.visible??fixed?.visible??base.visible);
    }
    mesh.visible=visible;
    const position=own?.position??fixed?.position??base.position;
    const scale=own?.scale??fixed?.scale??base.scale,rotation=own?.rotation??fixed?.rotation??base.rotation;
    if(last[0]===position[0]&&last[1]===position[1]&&last[2]===position[2]
      &&last[3]===scale[0]&&last[4]===scale[1]&&last[5]===scale[2]
      &&last[6]===rotation[0]&&last[7]===rotation[1]&&last[8]===rotation[2])return;
    const turned=!(last[6]===rotation[0]&&last[7]===rotation[1]&&last[8]===rotation[2]);
    last[0]=position[0];last[1]=position[1];last[2]=position[2];
    last[3]=scale[0];last[4]=scale[1];last[5]=scale[2];
    last[6]=rotation[0];last[7]=rotation[1];last[8]=rotation[2];
    const transform=nativeHudElementTransform({position,scale,rotation},base.context);
    if(turned)element.basis=nativeRotationMatrix(transform.rotation);
    nativeMatrix(element.basis,transform.position,mesh.matrix);
    mesh.matrix.scale(scratchScale.fromArray(transform.scale));
    mesh.matrixWorldNeedsUpdate=true;
  }
  async load() {
    const {setup,rankStates}=this.simulation;
    this.portraits=createNativeHudPortraits({
      characters:[...setup.opponents,setup.player].map(character=>character.name),
      playerIndex:setup.opponents.length,
    });
    updateNativeHudPortraits(this.portraits,0,rankStates.map(actor=>actor.rank));
    for(const {id,overrides}of getNativeHudPortraitCommands(this.portraits,this.config))
      await this.add(id,{overrides});
    this.arrows=new NativeHudArrows();
    for(const command of this.arrows.commands()){
      const variants=Object.fromEntries(NATIVE_ARROW_ALPHA.map((alpha,index)=>[index,{
        overrides:{[command.id]:{rgba:[255,255,255,alpha]}},
      }]));
      await this.add(command.id,{layer:'arrows',variants,overrides:command.overrides});
    }
    await this.add('track');
    await this.add('dotplayer');
    for(let i=0;i<this.simulation.opponents.length;i++)await this.add(`dotracer${i}`);
    await this.add('bonusframe');
    const variants={};
    for(let type=1;type<=5;type++)for(let level=1;level<=3;level++){
      const spec=nativeBonusVisual(this.config,this.manifest,type,level,'owned');
      variants[`${type}:${level}`]={animation:spec.sequence,frame:spec.frame};
    }
    await this.add('bonusobject',{variants,overrides:{bonusobject:{visible:false}}});
    this.bonus=new NativeBonusHud({
      destination:nativeHudIniTransform(this.config['overlay.ini'].bonusobject).position,
      owned:this.simulation.pickups.owned.at(-1),
    });
    const starOptions={raceType:this.simulation.race.raceType};
    const emptyStars=getNativeStarHudCommands(0,starOptions);
    const collectedStars=getNativeStarHudCommands(12,starOptions);
    for(const [index,command]of emptyStars.entries()){
      const variants=command.id==='starflag'?undefined:{
        empty:{overrides:command.overrides},
        collected:{overrides:collectedStars[index].overrides},
      };
      await this.add(command.id,{overrides:command.overrides,variants});
    }
    if(this.simulation.countdown){
      this.countdownFrames=[0,0,0];this.countdownY=1.25;
      for(let i=0;i<3;i++)await this.add(`321timer${i}`,{animation:'321player',frames:[0,1,2]});
    }
  }
  arrowInput(deltaSeconds){
    const {race,motion,routeOptions,engineMs,rescue}=this.simulation;
    // 415be0 reads the rendered basis, including rescue's squash/rotation.
    const body={sector:motion.body.sector,matrix:rescue.get(motion.body)?.matrix??motion.body.matrix};
    return {forward:nativeProjectileFacing(race.track,body,routeOptions),
      nowSeconds:Math.fround(engineMs/1000),deltaSeconds};
  }
  processEvents(events,deltaSeconds=0){
    for(const event of events){
      if(event.type!=='native-notification'||event.id!==9||this.arrowEvents.has(event))continue;
      this.arrowEvents.add(event);
      // 4420f0 calls 465840 before movement. Its immediate update and the
      // later regular overlay update both consume the native frame delta.
      this.arrows.requestJunction(this.arrowInput(deltaSeconds));
    }
  }
  capture(playerPosition,deltaSeconds=0) {
    const simulation=this.simulation,flying=simulation.freeFlightActive;
    if(!flying)this.arrows.step(this.arrowInput(deltaSeconds));
    for(const id of ARROW_IDS){
      const arrow=this.arrows.elements[id],element=this.elements.get(id);
      if(arrow.visible===element.arrowVisible&&arrow.alphaStep===element.arrowStep)continue;
      element.arrowVisible=arrow.visible;element.arrowStep=arrow.alphaStep;
      this.update(id,{variant:String(arrow.alphaStep),visible:arrow.visible});
    }
    const ranks=this.ranks??=[],rankStates=simulation.rankStates;
    for(let i=0;i<rankStates.length;i++)ranks[i]=rankStates[i].rank;
    updateNativeHudPortraits(this.portraits,deltaSeconds,ranks);
    if(portraitsMoved(this.portraits,this.portraitMemo??=[]))
      for(const command of getNativeHudPortraitCommands(this.portraits,this.config))this.update(command.id,command);
    const stars=simulation.pickups.stars,raceType=simulation.race.raceType;
    if(stars!==this.lastStars||raceType!==this.lastRaceType){
      this.lastStars=stars;this.lastRaceType=raceType;
      this.starCommands=getNativeStarHudCommands(stars,{raceType});
      for(const command of this.starCommands)this.update(command.id,command);
    }
    const positions=nativeMinimapRacers(this.viewer.track.id,playerPosition,
      simulation.opponents.map(actor=>actor.body.position));
    for(const dot of positions){
      const id=dot.player?'dotplayer':`dotracer${dot.index}`;
      this.update(id,{overrides:{[id]:{position:dot.position}}});
    }
    const owned=simulation.pickups.owned.at(-1),bonus=this.bonus.step(owned,deltaSeconds);
    if(owned.type>=1&&owned.type<=5)this.update('bonusobject',{
      variant:`${owned.type}:${owned.level}`,visible:bonus.visible,
      overrides:{bonusobject:{position:bonus.position,rotation:bonus.angles}},
    });
    if(simulation.countdown){
      for(const event of simulation.countdown.events){
        if(event.type==='frame')this.countdownFrames[event.element]=event.frame;
        if(event.type==='slide-in'||event.type==='slide-out')
          this.countdownY=nativeCountdownY(event.elapsed,{exiting:event.type==='slide-out'});
      }
      const visible=simulation.countdownStarted&&simulation.countdown.phase!==6;
      if(visible||this.countdownShown!==false)for(let i=0;i<3;i++){
        const id=`321timer${i}`;
        this.update(id,{frame:this.countdownFrames[i],visible,overrides:{
          [id]:{position:[[-.328125,0,.328125][i],this.countdownY,0]},
        }});
      }
      this.countdownShown=visible;
    }
  }
  renderElement(renderer,id,width,height,layout=raceHudLayout(width,height)) {
    const element=this.elements.get(id);
    if(!element?.mesh.visible)return false;
    const mesh=element.mesh,parent=this.config['overlay.ini'][id].parent.toLowerCase();
    const viewport=layout.group(['backarrow','junctionarrow'].includes(id)?'arrows':parent);
    renderer.setViewport(viewport.x,height-viewport.y-viewport.height,viewport.width,viewport.height);
    // Render the original node on its own so text and meshes can follow the
    // native Composite child list, including the label inside Bonus.
    mesh.updateMatrixWorld();
    renderer.render(mesh,this.camera);
    return true;
  }
  /** Group the layers into draw-order runs and order each mesh by its native index. */
  batch(drawOrder) {
    drawOrder.forEach((id,index)=>{
      const element=this.elements.get(id);if(element)element.mesh.renderOrder=index;
    });
  }
  applyLayout(layout,height) {
    for(const [name,{group}]of this.layers){
      const v=layout.group(name);
      group.userData.viewport={x:v.x,y:height-v.y-v.height,width:v.width,height:v.height};
    }
  }
  async dispose() {
    const [resources,textures]=await Promise.all([
      Promise.allSettled(this.resources.values()),Promise.allSettled(this.textures.values()),
    ]);
    for(const result of resources)if(result.status==='fulfilled'){
      result.value.geometry.dispose();
    }
    for(const material of this.materials.values())material.dispose();this.materials.clear();
    // The renderer and source images belong to the world. Retire only the
    // overlay's geometry/materials and independently sampled texture clones.
    for(const result of textures)if(result.status==='fulfilled')result.value.dispose();
    this.loadedTextures.clear();this.textures.clear();this.resources.clear();
  }
}
