import * as THREE from 'three';
import {OrbitControls} from 'three/addons/controls/OrbitControls.js';
import {renderDimensions,adaptVerticalFov} from './settings.js';
import {NativeUpdateClock,NativeEngineTimer,NATIVE_REFERENCE_UPTIME_MS} from './simulation/clock.js';
import {NativeUpdateLoop} from './native-update-loop.js';
import {getSkySpec,getSceneryAnimation,getRotationSpec,createNativeRotation,advanceNativeRotation,createNativeMeshAnimation,advanceNativeMeshAnimation,placementExistsInMode,resolveAsset} from './asset-animation.js';
import {nativeRotationMatrix} from './simulation/native-transform.js';
import {NATIVE_ANGLE_COUNT} from './simulation/native-integrator.js';
import {NativeRandom} from './simulation/native-random.js';
import {setNativeMatrix} from './render-transforms.js';
import {isNativeBonusPlacementVisible,nativeBonusTypeFromObject,nativeBonusVisual} from './simulation/native-bonus.js';
import {nativeColorAttribute,createNativeMeshMaterial,applyNativeByteColorPipeline,configureNativeTextureColorKey} from './asset-materials.js';
import {NativeSceneryPaths} from './scenery-paths.js';
import {nativeObjectCallbackCount} from './spatial-audio.js';
import {NATIVE_RENDER_ORDER,nativeObjectRenderOrder,nativeRoadDrawGroups} from './render-order.js';
import {configWithNativeDisplaySettings} from './simulation/native-display-settings.js';
import {packNativeTextureRGBA,nativeTexturePixelsRGBA,nativeTextureChannelScale} from './native-texture-upload.js';
import {MultisampleSceneRenderer} from './multisample-renderer.js';

async function getJSON(url){const r=await fetch(url);if(!r.ok)throw Error(`${url}: ${r.status}`);return r.json();}
function geometry(data){
  const g=new THREE.BufferGeometry();
  for(const [key,size]of [['position',3],['uv',2]])if(data[key])g.setAttribute(key,new THREE.Float32BufferAttribute(data[key],size));
  g.setAttribute('color',nativeColorAttribute(data));
  if(data.index)g.setIndex(data.index);g.computeVertexNormals();g.computeBoundingSphere();return g;
}
export class TrackViewer{
  constructor(canvas){
    // Three r186 requests an alpha-bearing context even with alpha:false.
    // Native SRCALPHA blending also writes alpha; an HTML compositor would
    // otherwise blend the completed shadow with the page a second time.
    // Original Direct3D presents opaque RGB, so create that context explicitly.
    const context=canvas.getContext('webgl2',{alpha:false,antialias:false});
    if(!context)throw new Error('WebGL2 is niet beschikbaar.');
    this.renderer=new THREE.WebGLRenderer({canvas,context,antialias:false,alpha:false});
    this.renderer.setPixelRatio(1);this.renderer.outputColorSpace=THREE.SRGBColorSpace;this.renderer.setClearColor(0x151d2b);
    // Native transparent work is queued in traversal order, not depth-sorted.
    this.renderer.setTransparentSort((a,b)=>a.groupOrder-b.groupOrder||a.renderOrder-b.renderOrder||a.id-b.id);
    this.renderer.setOpaqueSort((a,b)=>a.groupOrder-b.groupOrder||a.renderOrder-b.renderOrder||a.id-b.id);
    this.multisampling=new MultisampleSceneRenderer(this.renderer);
    this.scene=new THREE.Scene();this.camera=new THREE.PerspectiveCamera(60,1,.5,100000);
    this.controls=new OrbitControls(this.camera,canvas);this.controls.enableDamping=false;
    this.controls.minDistance=30;this.controls.maxDistance=30000;this.controls.maxPolarAngle=Math.PI*.49;
    this.textureLoader=new THREE.TextureLoader();this.textures=new Map();this.meshData=new Map();
    this.textureFilter=THREE.LinearFilter;this.textureGamma=false;
    this.group=null;this.active=false;this.errors=[];this.generation=0;
    this.animations=[];this.rotations=[];
    this.resources=Promise.all([getJSON('/assets/config.json'),getJSON('/assets/manifest.json')]);
    this.textureRecords=this.resources.then(([,manifest])=>new Map(
      Object.values(manifest.images).map(record=>[record.file,record])));
  }
  async texture(file){
    if(!this.textures.has(file))this.textures.set(file,Promise.all([
      this.textureLoader.loadAsync('/assets/'+file),this.textureRecords,
    ]).then(([source,records])=>{
      const record=records.get(file);let t=source;
      if(record?.nativeRGB){
        const canvas=document.createElement('canvas');
        canvas.width=source.image.width;canvas.height=source.image.height;
        const context=canvas.getContext('2d',{willReadFrequently:true});
        context.drawImage(source.image,0,0);
        const image=context.getImageData(0,0,canvas.width,canvas.height);
        // Canvas erases hidden RGB. Only nativeRGB PNGs encode the exact
        // original key in alpha, so restore that key before the native packer.
        for(let i=0;i<image.data.length;i+=4)if(image.data[i+3]===0)
          image.data.set(record.colorKeyRGB,i);
        // Original texture enumeration depends on the old display/driver.
        // Use its RGB565 16-bit display path; retain RGB555 in the packer tests.
        const format='RGB565',packed=packNativeTextureRGBA(image.data,{format,gamma:this.textureGamma});
        t=new THREE.DataTexture(nativeTexturePixelsRGBA(packed,{format}),canvas.width,canvas.height);
        t.userData.nativeTextureFormat=format;t.userData.nativeGamma=this.textureGamma;
        source.dispose();
      }
      t.colorSpace=THREE.NoColorSpace;t.flipY=false;t.wrapS=t.wrapT=THREE.RepeatWrapping;
      // 42cff0 selects linear only for FILTER2, otherwise point. No mipmaps.
      t.minFilter=t.magFilter=this.textureFilter;t.generateMipmaps=false;t.needsUpdate=true;
      return configureNativeTextureColorKey(t,record);
    }));
    return this.textures.get(file);
  }
  async textureImage(file){
    const texture=await this.texture(file);
    if(!texture.userData.nativeTextureFormat)return texture.image;
    // Canvas HUD glyphs need an image rather than a DataTexture. Expand only
    // for that consumer; WebGL continues to filter exact packed-channel counts.
    if(!texture.canvasImage){
      const {data,width,height}=texture.image,canvas=document.createElement('canvas');
      canvas.width=width;canvas.height=height;
      const context=canvas.getContext('2d'),image=context.createImageData(width,height);
      const scale=nativeTextureChannelScale(texture.userData.nativeTextureFormat);
      for(let i=0;i<data.length;i+=4){
        for(let c=0;c<3;c++)image.data[i+c]=Math.round(data[i+c]*scale[c]);
        image.data[i+3]=data[i+3];
      }
      context.putImageData(image,0,0);texture.canvasImage=canvas;
    }
    return texture.canvasImage;
  }
  async model(name){
    const file=name.toLowerCase().replace(/^meshes\//,'').replace(/\.(d3d|json)$/,'');
    if(!this.meshData.has(file))this.meshData.set(file,getJSON(`/assets/meshes/${file}.json`).then(geometry));
    return this.meshData.get(file);
  }
  async load(id,{raceMode=0,randomSeed=0}={}){
    this.updateLoop?.stop();
    const generation=++this.generation;this.active=false;this.errors=[];
    this.sceneryBodies=null;this.sceneryReactions=null;this.sceneryHazards=null;this.sceneryCallbacksOwned=false;
    const [track,[originalConfig,manifest]]=await Promise.all([getJSON(`/assets/tracks/etappe${id}.json`),this.resources]);
    const config=configWithNativeDisplaySettings(originalConfig,this.displaySettings);
    this.runtimeConfig=config;
    const filter=Number(config['game.ini'].options.filter)===2?THREE.LinearFilter:THREE.NearestFilter;
    const gamma=Number(config['sndgfx.ini']['gfx options'].gamma)!==0;
    if(filter!==this.textureFilter||gamma!==this.textureGamma){
      for(const pending of this.textures.values())pending.then(texture=>texture.dispose());
      this.textures.clear();this.textureFilter=filter;this.textureGamma=gamma;
    }
    const group=new THREE.Group();
    const animations=[],rotations=[],random=new NativeRandom(randomSeed);
    // Direct3D left-handed XYZ -> Three right-handed XYZ, preserving Y up.
    group.scale.z=-1;
    const maps=await Promise.all(track.textures.map(file=>this.texture(file)));
    this.onLoadProgress?.(1);
    const mats=maps.map(map=>createNativeMeshMaterial(map));
    const g=geometry(track);for(const chunk of nativeRoadDrawGroups(track))g.addGroup(chunk.start,chunk.count,chunk.textureIndex);
    const roadMesh=new THREE.Mesh(g,mats);roadMesh.renderOrder=NATIVE_RENDER_ORDER.road;group.add(roadMesh);
    const definitions=track.objectDefinitions;
    const definitionFor=obj=>{
      const bonusType=nativeBonusTypeFromObject(obj.type);
      if(bonusType){
        // 00453ed0/004500e0 replace the authored OMP art with the level-one
        // logical bonus frame. In England this changes two turbo meshes to oil.
        const spec=nativeBonusVisual(config,manifest,bonusType);
        return {mesh:spec.mesh,textureFile:resolveAsset(manifest,'images',spec.texture.replace(/\.pcx$/i,'.tga'))};
      }
      const def=definitions[obj.animation.toLowerCase()];
      return def&&{...def,textureFile:'textures/'+def.texture.toLowerCase()+'.png'};
    };
    const resources=new Map();
    const placements=track.placements.filter(obj=>placementExistsInMode(obj,raceMode)&&isNativeBonusPlacementVisible(obj,raceMode));
    const animationResources=new Map();
    for(const obj of placements){
      const def=definitionFor(obj);if(!def){this.errors.push({animation:obj.animation,reason:'No object definition'});continue;}
      const key=def.mesh+'|'+def.textureFile+'|'+obj.type;
      if(!resources.has(key))resources.set(key,Promise.all([
        this.model(def.mesh),this.texture(def.textureFile)
      ]).then(([geo,map])=>({geo,mat:createNativeMeshMaterial(map,{placementType:obj.type})})));
      const animation=getSceneryAnimation(config,manifest,id,obj.animation);
      // All currently placed definitions have one sequence. Finite transitions
      // remain the responsibility of each recovered object controller.
      if(animation?.sequences.length===1&&animation.sequences[0].frames.length>1&&!animationResources.has(obj.animation)){
        const sequence=animation.sequences[0];
        animationResources.set(obj.animation,Promise.all(sequence.frames.map(frame=>this.model(frame.file))).then(frames=>({sequence,frames})));
      }
    }
    const loaded=new Map();
    await Promise.all([...resources].map(async([key,promise])=>{
      try{loaded.set(key,await promise);}catch(error){this.errors.push({resource:key,reason:String(error)});}
    }));
    const loadedAnimations=new Map();
    await Promise.all([...animationResources].map(async([key,promise])=>{
      try{loadedAnimations.set(key,await promise);}catch(error){this.errors.push({animation:key,reason:String(error)});}
    }));
    for(const obj of placements){
      const def=definitionFor(obj);if(!def)continue;
      const resource=loaded.get(def.mesh+'|'+def.textureFile+'|'+obj.type);if(!resource)continue;
      const mesh=new THREE.Mesh(resource.geo,resource.mat);mesh.position.fromArray(obj.position);
      mesh.renderOrder=nativeObjectRenderOrder(track.placements.indexOf(obj));
      // Native 0x43e140 converts degrees/negates Y; initialized 0x4a09e0
      // composes Z then X then Y in the 4096-entry lookup table.
      const nativeAngles=obj.nativeRotationDegrees.map(value=>Math.fround(value*NATIVE_ANGLE_COUNT/360));
      setNativeMatrix(mesh,nativeRotationMatrix(nativeAngles));
      mesh.userData={source:obj.animation,nativeMesh:def.mesh,nativeAngles,sector:obj.sector,placementIndex:track.placements.indexOf(obj)};group.add(mesh);
      const animation=loadedAnimations.get(obj.animation);
      if(animation){
        mesh.geometry=animation.frames[0];
        animations.push({mesh,frames:animation.frames,state:createNativeMeshAnimation(animation.sequence)});
      }
      const rotation=getRotationSpec(config,obj);
      if(rotation){
        // 497070 constructs placements in OMP order. The caller supplies the
        // initial time() seed; standalone inspection explicitly uses zero.
        rotations.push({mesh,state:createNativeRotation(rotation,obj.nativeRotationDegrees,()=>random.next())});
      }
    }
    let sky=null;
    const skySpec=getSkySpec(config,manifest,id,raceMode);
    if(skySpec){
      try{
        const [geo,map]=await Promise.all([this.model(skySpec.mesh),this.texture(skySpec.texture)]);
        //423010 submits the sky after4971f0;4a0d80 inherits enabled depth writes.
        sky=new THREE.Mesh(geo,applyNativeByteColorPipeline(new THREE.MeshBasicMaterial({map,side:THREE.FrontSide,depthWrite:true})));
        sky.scale.fromArray(skySpec.scale);sky.position.fromArray(track.route[0].position);sky.renderOrder=NATIVE_RENDER_ORDER.sky;group.add(sky);
      }catch(error){this.errors.push({resource:'sky',reason:String(error)});}
    }
    if(generation!==this.generation){this.disposeGroup(group);return null;}
    if(this.group){this.scene.remove(this.group);this.disposeGroup(this.group);}
    this.group=group;this.scene.add(group);this.track=track;this.sky=sky;this.random=random;
    this.roadMesh=roadMesh;
    this.sceneryPaths=new NativeSceneryPaths(track);
    this.sceneryPathMeshes=new Map(group.children.filter(mesh=>this.sceneryPaths.objects.has(mesh.userData.placementIndex))
      .map(mesh=>[mesh.userData.placementIndex,mesh]));
    this.animations=animations;this.rotations=rotations;
    this.deltaFilter=new NativeEngineTimer({absoluteSeconds:NATIVE_REFERENCE_UPTIME_MS/1000});
    // 4432a0 admits one update after at least 25 actual milliseconds. Its
    // clock is independent of display refresh and never catches up in bursts.
    this.clock=new NativeUpdateClock({update:(dt,now)=>{
      const nativeDelta=this.deltaFilter.sampleAbsoluteSeconds(
        (NATIVE_REFERENCE_UPTIME_MS+this.clock.wallMs)/1000);
      this.onTick?.(nativeDelta,now,{wallMs:this.clock.wallMs,
        engineMs:NATIVE_REFERENCE_UPTIME_MS+this.clock.wallMs});
      if(!this.sceneryCallbacksOwned)this.advanceSceneryCallbacks(nativeDelta,
        this.clock.wallMs+NATIVE_REFERENCE_UPTIME_MS);
    }});
    this.clockStarted=false;
    this.updateLoop=new NativeUpdateLoop({clock:this.clock,
      beforeUpdate:time=>this.beforeUpdate?.(time)});
    const p=track.route[0]?.position||[0,0,0];
    this.controls.target.set(p[0],p[1]+30,-p[2]);this.camera.position.set(p[0]+600,p[1]+700,-p[2]+950);
    this.controls.update();this.active=true;return {track,errors:this.errors,objects:group.children.length-1};
  }
  // Native path movement is after render. Capture the previous path update at
  // the next render boundary, separately from advancing its controller.
  captureSceneryPaths(){
    for(const [placementIndex,state] of this.sceneryPaths?.objects??[]){
      if(this.sceneryBodies?.byPlacement.has(placementIndex)||this.sceneryReactions?.byPlacement.has(placementIndex))continue;
      const mesh=this.sceneryPathMeshes.get(placementIndex);if(!mesh)continue;
      mesh.position.fromArray(state.position);mesh.visible=state.visible;
      mesh.userData.sector=state.sector;
      const [x,,z]=mesh.userData.nativeAngles;
      setNativeMatrix(mesh,nativeRotationMatrix([x,state.yaw,z]));
    }
  }
  bindScenerySimulation(simulation){
    this.sceneryBodies=simulation.scenery;
    this.sceneryReactions=simulation.sceneryReactions;
    this.sceneryHazards=simulation.sceneryHazards;
    this.sceneryPaths=simulation.sceneryPaths;
    this.sceneryBodyMeshes=new Map(this.group.children
      .filter(mesh=>this.sceneryBodies.byPlacement.has(mesh.userData.placementIndex)
        ||this.sceneryReactions.byPlacement.has(mesh.userData.placementIndex)
        ||this.sceneryHazards.byPlacement.has(mesh.userData.placementIndex))
      .map(mesh=>[mesh.userData.placementIndex,mesh]));
    this.sceneryBodyAnimations=new Map(this.animations
      .filter(animation=>this.sceneryBodies.byPlacement.has(animation.mesh.userData.placementIndex)
        ||this.sceneryHazards.byPlacement.has(animation.mesh.userData.placementIndex))
      .map(animation=>[animation.mesh.userData.placementIndex,animation]));
  }
  captureSceneryBodies(){
    for(const body of [...(this.sceneryBodies?.bodies??[]),...(this.sceneryReactions?.objects??[]),
      ...(this.sceneryHazards?.objects??[])]){
      const mesh=this.sceneryBodyMeshes.get(body.placementIndex);if(!mesh)continue;
      mesh.position.fromArray(body.position);mesh.visible=body.active??body.visible;
      mesh.userData.sector=body.sector;mesh.userData.nativeMesh=body.mesh;
      setNativeMatrix(mesh,body.matrix);
      const animation=this.sceneryBodyAnimations.get(body.placementIndex);
      const state=this.sceneryBodies.animations.get(body.placementIndex)
        ??this.sceneryHazards.animations.get(body.placementIndex);
      if(animation&&state)mesh.geometry=animation.frames[state.frame];
    }
  }
  stepSceneryPaths(input){return this.sceneryPaths?.step(input);}
  advanceSceneryCallbacks(dt,now,{ranges,alwaysUpdate=new Set()}={}){
    const callbacks=mesh=>{
      if(!ranges)return 1; // Explicit orbit inspection runs every object.
      const id=mesh.userData.placementIndex,state=this.sceneryBodies?.byPlacement.get(id)
        ??this.sceneryReactions?.byPlacement.get(id)??this.sceneryPaths?.objects.get(id);
      return nativeObjectCallbackCount({visible:state?.visible??mesh.visible,
        alwaysUpdate:alwaysUpdate.has(id),sector:state?.sector??mesh.userData.sector,ranges});
    };
    for(const animation of this.animations){
      if(this.sceneryBodies?.byPlacement.has(animation.mesh.userData.placementIndex)
        ||this.sceneryHazards?.byPlacement.has(animation.mesh.userData.placementIndex))continue;
      for(let n=callbacks(animation.mesh);n>0;n--){
      advanceNativeMeshAnimation(animation.state,now);
      animation.mesh.geometry=animation.frames[animation.state.frame];
      }
    }
    for(const rotation of this.rotations){
      if(this.sceneryHazards?.byPlacement.has(rotation.mesh.userData.placementIndex))continue;
      for(let n=callbacks(rotation.mesh);n>0;n--){
      advanceNativeRotation(rotation.state,dt);
      setNativeMatrix(rotation.mesh,nativeRotationMatrix(rotation.state.angles));
      }
    }
  }
  /** Native inclusive chunk ranges gate render submission, independently of
   * controller visibility (pickups and paths still update outside this window). */
  applyVisibleSectors(ranges){
    this.visibleSectorRanges=ranges;
    const visible=sector=>ranges.some(([start,end])=>sector>=start&&sector<=end);
    this.roadMesh.geometry.clearGroups();
    for(const chunk of nativeRoadDrawGroups(this.track,ranges))
      this.roadMesh.geometry.addGroup(chunk.start,chunk.count,chunk.textureIndex);
    for(const object of this.group.children){
      if(!Number.isInteger(object.userData.sector))continue;
      const enabled=visible(object.userData.sector);
      object.traverse(mesh=>enabled?mesh.layers.enable(0):mesh.layers.disable(0));
    }
  }
  resize(settings){
    const canvas=this.renderer.domElement,rect=canvas.getBoundingClientRect();
    const size=renderDimensions({width:rect.width,height:rect.height,dpr:devicePixelRatio,...settings,maxSize:this.renderer.capabilities.maxTextureSize});
    this.renderer.setSize(size.width,size.height,false);
    this.multisampling.configure(settings,size.width,size.height);
    this.camera.aspect=rect.width/Math.max(1,rect.height);
    // 60° is solely the inspection camera, never a claimed original race FOV.
    this.camera.fov=adaptVerticalFov(60,this.camera.aspect);this.camera.updateProjectionMatrix();return size;
  }
  get msaaStatus(){return this.multisampling.status;}
  get renderStats(){return this.multisampling.stats;}
  renderScene(){this.multisampling.render(this.scene,this.camera);}
  disposeRenderer(){this.updateLoop?.stop();this.multisampling.dispose();this.renderer.dispose();}
  render(time){if(this.active){this.controls.update();this.renderScene();}}
  suspend(time=performance.now()){
    this.active=false;this.controls.enabled=false;this.updateLoop?.stop(time);
  }
  resume(time=performance.now()){
    this.active=true;this.controls.enabled=true;
    if(this.updateLoop&&!this.updateLoop.running){
      if(this.clockStarted)this.deltaFilter.resetAbsoluteSeconds(
        (NATIVE_REFERENCE_UPTIME_MS+this.clock.snapshot(time).wallMs)/1000);
      this.updateLoop.start(time);this.clockStarted=true;
    }
  }
  disposeGroup(group){
    const materials=new Set();group.traverse(o=>{if(o.isMesh){if(o===group.children[0]||o.userData.ownedGeometry)o.geometry.dispose();for(const m of Array.isArray(o.material)?o.material:[o.material])materials.add(m);}});
    for(const m of materials)m.dispose();
  }
}
