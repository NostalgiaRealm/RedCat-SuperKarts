import * as THREE from 'three';
import {getHudMeshSpec,getNativeHudCameraSpec,nativeHudIniTransform} from './hud-mesh.js';
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
    this.renderer=new THREE.WebGLRenderer({alpha:true,antialias:true,premultipliedAlpha:true});
    this.renderer.setPixelRatio(1);this.renderer.setClearColor(0,0);
    this.renderer.autoClear=false;
    this.renderer.setTransparentSort((a,b)=>a.renderOrder-b.renderOrder||a.id-b.id);
    const projection=getNativeHudCameraSpec();
    this.camera=new THREE.PerspectiveCamera(projection.verticalFov*180/Math.PI,640/480,projection.near,projection.far);
    this.layers=new Map();this.elements=new Map();this.resources=new Map();this.textures=new Map();
    this.loadedTextures=new Set();
    this.arrowEvents=new WeakSet();
  }
  layer(name) {
    if(!this.layers.has(name)){
      const scene=new THREE.Scene(),group=new THREE.Group();group.scale.z=-1;scene.add(group);
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
      const material=createNativeMeshMaterial(map,{blendMode:1});
      material.depthTest=false;material.depthWrite=false;
      // Retain premultiplied RGB while accumulating coverage into this
      // transparent HUD surface; the final 2D composite applies coverage once.
      material.blendSrcAlpha=THREE.OneFactor;
      material.blendDstAlpha=THREE.OneMinusSrcAlphaFactor;
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
    mesh.renderOrder=this.elements.size;
    const parent=layer??this.config['overlay.ini'][id].parent.toLowerCase();
    this.layer(parent).group.add(mesh);
    this.elements.set(id,{mesh,choices,defaultKey:choices.keys().next().value,frames:new Map(resources)});
    this.update(id,{overrides});
  }
  update(id,{frame,variant,overrides={},visible}={}) {
    const element=this.elements.get(id);
    if(!element)throw new Error(`HUD element has not been loaded: ${id}`);
    const key=variant??frame??element.defaultKey;
    const choice=element.choices.get(key);
    const spec=this.spec(id,{...choice,overrides:mergeOverrides(choice.overrides,overrides)});
    const resource=element.frames.get(key);
    if(!resource)throw new Error(`HUD frame has not been loaded: ${id}/${key}`);
    Object.assign(element.mesh,resource);
    element.mesh.visible=visible??spec.visible;
    const {position,scale,rotation}=spec.transform;
    element.mesh.matrix.copy(nativeMatrix(nativeRotationMatrix(rotation),position));
    element.mesh.matrix.scale(new THREE.Vector3(...scale));
    element.mesh.matrixWorldNeedsUpdate=true;
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
    this.arrowCommands=this.simulation.freeFlightActive?this.arrows.commands()
      :this.arrows.update(this.arrowInput(deltaSeconds));
    for(const command of this.arrowCommands)
      this.update(command.id,{...command,variant:String(command.variant)});
    updateNativeHudPortraits(this.portraits,deltaSeconds,this.simulation.rankStates.map(actor=>actor.rank));
    for(const command of getNativeHudPortraitCommands(this.portraits,this.config))
      this.update(command.id,command);
    this.starCommands=getNativeStarHudCommands(this.simulation.pickups.stars,{
      raceType:this.simulation.race.raceType,
    });
    for(const command of this.starCommands)this.update(command.id,command);
    const positions=nativeMinimapRacers(this.viewer.track.id,playerPosition,
      this.simulation.opponents.map(actor=>actor.body.position));
    for(const dot of positions){
      const id=dot.player?'dotplayer':`dotracer${dot.index}`;
      this.update(id,{overrides:{[id]:{position:dot.position}}});
    }
    const owned=this.simulation.pickups.owned.at(-1),bonus=this.bonus.step(owned,deltaSeconds);
    if(owned.type>=1&&owned.type<=5)this.update('bonusobject',{
      variant:`${owned.type}:${owned.level}`,visible:bonus.visible,
      overrides:{bonusobject:{position:bonus.position,rotation:bonus.angles}},
    });
    if(this.simulation.countdown){
      for(const event of this.simulation.countdown.events){
        if(event.type==='frame')this.countdownFrames[event.element]=event.frame;
        if(event.type==='slide-in'||event.type==='slide-out')
          this.countdownY=nativeCountdownY(event.elapsed,{exiting:event.type==='slide-out'});
      }
      for(let i=0;i<3;i++){
        const id=`321timer${i}`;
        this.update(id,{frame:this.countdownFrames[i],visible:this.simulation.countdownStarted&&this.simulation.countdown.phase!==6,overrides:{
          [id]:{position:[[-.328125,0,.328125][i],this.countdownY,0]},
        }});
      }
    }
  }
  render(context,width,height,layout=raceHudLayout(width,height)) {
    const canvas=this.renderer.domElement;
    if(canvas.width!==width||canvas.height!==height)this.renderer.setSize(width,height,false);
    this.renderer.setViewport(0,0,width,height);this.renderer.clear();
    for(const [name,{scene}]of this.layers){
      const viewport=layout.group(name);
      this.renderer.setViewport(viewport.x,height-viewport.y-viewport.height,viewport.width,viewport.height);
      this.renderer.render(scene,this.camera);
    }
    context.drawImage(canvas,0,0,width,height);
  }
  async dispose() {
    const [resources,textures]=await Promise.all([
      Promise.allSettled(this.resources.values()),Promise.allSettled(this.textures.values()),
    ]);
    for(const result of resources)if(result.status==='fulfilled'){
      result.value.geometry.dispose();result.value.material.dispose();
    }
    // Delete owned GPU objects before renderer.dispose clears the properties
    // used by Three's texture-disposal listeners. Source images stay shared.
    for(const result of textures)if(result.status==='fulfilled')result.value.dispose();
    this.renderer.dispose();
  }
}
