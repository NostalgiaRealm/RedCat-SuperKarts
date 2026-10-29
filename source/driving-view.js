import * as THREE from 'three';
import {TrackViewer} from './world.js';
import {NATIVE_CAMERA_PROJECTION} from './simulation/native-camera.js';
import {adaptVerticalFov} from './settings.js';
import {getDrivingAnimationRequests,getNPCDrivingAnimationRequests,requestDriverAnimation,advanceDriverAnimation} from './player-assets.js';
import {nativeRotationMatrix} from './simulation/native-transform.js';
import {setNativeMatrix,presentNativeRaceCamera} from './render-transforms.js';
import {getTrackMusic} from './asset-animation.js';
import {TrackMusic} from './game-audio.js';
import {RaceHud} from './race-hud.js';
import {createNativeMeshMaterial} from './asset-materials.js';
import {RaceSimulation} from './race-simulation.js';
import {KartVisual,KartShadowVisual,FinishFlagVisual,SmokeVisuals,HomingArmVisuals,ProjectileVisuals,RescueVisuals,WeatherVisuals,SkidmarkVisuals,ExplosionVisuals,StreamVisuals} from './race-visuals.js';
import {RaceHudMeshes} from './race-hud-meshes.js';
import {BubbleShellVisuals} from './bubble-visuals.js';
import {NativeBlendState} from './native-blend-state.js';
import {NativeHudSamplerState} from './simulation/native-hud-sampler.js';
import {NativeRaceAudio} from './native-race-audio.js';
import {getNativeSoundListener} from './spatial-audio.js';
import {nativeAudioLoadSettings,settingsAudioPercent} from './audio-mixing.js';
import {NATIVE_REFERENCE_UPTIME_MS} from './simulation/clock.js';
import {readRaceSave,configWithRaceSave} from './race-save.js';
import {nativeVisibleChunkStart,nativeVisibleChunkRanges} from './simulation/native-render.js';

const json=async url=>{const r=await fetch(url);if(!r.ok)throw Error(`${url}: ${r.status}`);return r.json();};

/**
 * Race renderer shared with the explicit driving research view.
 * Menu progression and race transitions are owned outside this renderer.
 */
export class DrivingView extends TrackViewer{
  constructor(canvas,input,hudCanvas){
    super(canvas);this.input=input;this.camera.near=NATIVE_CAMERA_PROJECTION.near;this.camera.far=NATIVE_CAMERA_PROJECTION.far;
    this.controls.enabled=false;this.driverFrames=[];this.hudCanvas=hudCanvas;
  }
  async mesh(spec){
    const [geometry,map]=await Promise.all([this.model(spec.mesh),this.texture(spec.texture)]);
    return new THREE.Mesh(geometry,createNativeMeshMaterial(map));
  }
  async load(id,{character=0,difficulty=1,raceMode=0,countdown=false}={}){
    this.updateLoop?.stop();
    this.active=false;
    const previousHudMeshes=this.hudMeshes;
    // Inactive browser frames still paint the HUD (for pause). Detach it
    // before awaiting cleanup so a loading frame cannot re-upload old maps.
    this.hud?.dispose();this.hud=null;this.hudMeshes=null;
    await previousHudMeshes?.dispose();
    this.finishFlag?.dispose();
    this.weatherVisuals?.dispose();
    this.explosionVisuals?.dispose();
    this.streamVisuals?.dispose();
    this.bubbleVisuals?.dispose();
    this.playerVisual?.dispose();
    for(const visual of this.opponentVisuals??[])visual.dispose();
    this.music?.pause();await this.audio?.dispose();this.flightAudioPaused=false;
    // 4b14e0 seeds construction from time(); 42f930 later reseeds gameplay
    // from GetTickCount. Browser clocks replace those operating-system APIs.
    // The explicit driving research view keeps both seeds zero for replay.
    this.constructionSeed=countdown?Math.floor(Date.now()/1000):0;
    const result=await super.load(id,{raceMode,randomSeed:this.constructionSeed});
    if(!result)return null;
    this.onLoadProgress?.(2);
    this.active=false;
    const binary=async url=>{const r=await fetch(url);if(!r.ok)throw Error(`Original table missing: ${url}`);return r.arrayBuffer();};
    const [[originalConfig,manifest],cars,physicsBytes,racerBytes]=await Promise.all([
      this.resources,json('/assets/cars.json'),binary(`/assets/physics/phys${difficulty}.dat`),
      binary(`/assets/racer-tables/cars${difficulty}.dat`),
    ]);
    const config=configWithRaceSave(this.runtimeConfig??originalConfig,readRaceSave());
    this.simulation=new RaceSimulation({config,manifest,cars,physicsBytes,racerBytes,
      track:result.track,random:this.random,character,difficulty,raceMode,countdown,
      rotationStates:new Map(this.rotations.map(({mesh,state})=>[mesh.userData.placementIndex,state]))});
    this.bindScenerySimulation(this.simulation);
    this.gameplaySeed=countdown?Math.floor(performance.now()):0;
    this.random.seed(this.gameplaySeed);
    // One declared host epoch for the native absolute timer and raw deadlines.
    this.engineEpochMs=NATIVE_REFERENCE_UPTIME_MS;this.pausedDurationMs=0;this.pausedAt=null;
    const {motion,race,pickups,combat}=this.simulation;
    Object.assign(this,{motion,race,pickups,combat});
    this.opponents=this.simulation.opponents;
    this.onLoadProgress?.(3);
    this.playerRadius=motion.radius;
    this.pickupMeshes=new Map(this.group.children.filter(mesh=>Number.isInteger(mesh.userData.placementIndex))
      .map(mesh=>[mesh.userData.placementIndex,mesh]));
    this.pickupEvents=[];
    this.hud=new RaceHud(this.hudCanvas,config,manifest);
    this.hudMeshes=new RaceHudMeshes(this,config,manifest,this.simulation);
    await this.hudMeshes.load();this.hud.meshes=this.hudMeshes;
    await this.hud.load(file=>this.hudMeshes.texture(file));
    this.hud.present=(draw,width,height)=>this.multisampling.compose(draw,width,height);
    this.hud.update(this.race,0,{nowSeconds:this.simulation.engineMs/1000});
    this.hudSampler=new NativeHudSamplerState({filter:Number(config['game.ini'].options.filter)});
    // Reuse the scene tracker across reloads, avoiding stacked callbacks.
    this.nativeBlendState??=new NativeBlendState();
    this.nativeBlendState.setNative(2,1);
    this.nativeBlendState.bindScene(this.scene);
    for(const {scene}of this.hudMeshes.layers.values())this.nativeBlendState.bindScene(scene,{hud:true});
    this.hudMeshes.capture(this.motion.body.position);
    this.onLoadProgress?.(4);
    this.music=new TrackMusic(getTrackMusic(manifest,id));
    this.audio=new NativeRaceAudio(config,manifest,{groupVolume:settingsAudioPercent(this.audioSettings?.effects??1)});
    this.nativeAudioSettings=nativeAudioLoadSettings(config);
    await this.audio.prepareVoices(this.simulation.racerCharacters);
    await this.audio.prepareRaceEvents();
    this.simulation.onVoiceRequest=request=>this.audio.requestVoice(request);
    this.simulation.onDirectSound=event=>{
      if(this.audio.voices.enabled)this.audio.execute([{event,op:'play',loop:false}]);
    };
    await this.audio.prepareEngine();
    this.simulation.onEngineStart=()=>this.audio.startEngine();
    if(!countdown||this.simulation.countdownStarted)await this.audio.startEngine();
    await this.audio.prepareScenery(result.track);
    this.simulation.onSceneryImpact=(index,object)=>this.audio.playSceneryImpact(index,this.soundListener,object);
    this.sceneryAlwaysUpdate=new Set(this.audio.scenery.map(entry=>entry.placementIndex));
    this.sceneryCallbacksOwned=true;
    this.soundListener={position:[0,0,0],forward:[0,0,0],velocity:[0,0,0]};
    this.onLoadProgress?.(5);
    const {setup}=this.simulation;
    this.playerVisual=await KartVisual.load(this,config,manifest,character,setup.player.carIndex,motion);
    this.onLoadProgress?.(6);
    this.opponentVisuals=[];
    for(let i=0;i<setup.opponents.length;i++)this.opponentVisuals.push(
      await KartVisual.load(this,config,manifest,setup.opponents[i].availableIndex,setup.player.carIndex,this.opponents[i]));
    this.simulation.onAnimationRequest=(racer,request)=>{
      const visual=[...this.opponentVisuals,this.playerVisual][racer];
      requestDriverAnimation(visual.animation,request);
    };
    this.shadows=await Promise.all([this.playerVisual,...this.opponentVisuals]
      .map(visual=>KartShadowVisual.load(this,manifest,visual.spec.body,visual.actor)));
    for(const shadow of this.shadows)shadow.capture(this.simulation.world);
    this.finishFlag=await FinishFlagVisual.load(this,manifest);
    this.onLoadProgress?.(7);
    this.kart=this.playerVisual.group;this.wheels=this.playerVisual.wheels;
    this.driver=this.playerVisual.driver;this.driverFrames=this.playerVisual.frames;
    this.driverAnimation=this.playerVisual.animation;
    this.projectiles=new ProjectileVisuals(this,combat);await this.projectiles.load(config,manifest);
    this.bubbleVisuals=new BubbleShellVisuals(this,this.simulation.bubbles);
    await this.bubbleVisuals.load(config,manifest);
    this.rescueVisuals=new RescueVisuals(this,this.simulation.rescue);
    await this.rescueVisuals.load(manifest);
    this.smokeVisuals=new SmokeVisuals(this);
    await this.smokeVisuals.load(manifest);
    this.weatherVisuals=new WeatherVisuals(this,this.simulation.weather);
    await this.weatherVisuals.load(manifest);
    this.skidmarkVisuals=new SkidmarkVisuals(this);
    await this.skidmarkVisuals.load(manifest);
    this.explosionVisuals=new ExplosionVisuals(this);
    await this.explosionVisuals.load(manifest);
    this.streamVisuals=new StreamVisuals(this);
    await this.streamVisuals.load(manifest);
    this.homingArmVisuals=new HomingArmVisuals(this,combat.arms);
    await this.homingArmVisuals.load(manifest);
    this.onLoadProgress?.(8);
    this.playerCamera=this.simulation.playerCamera;
    this.nativeCamera=this.simulation.camera;
    this.visibleChunks=this.simulation.visibleChunks;
    this.previousCamera=this.currentCamera=this.cameraPose();
    this.previousSkyPosition=this.currentSkyPosition=new THREE.Vector3().fromArray(this.motion.body.position);
    this.onLoadProgress?.(9);
    // Explicit times also keep deterministic diagnostic callers independent
    // of the live browser scheduler. Production supplies both clock domains.
    this.onTick=(dt,now,{wallMs=now+this.pausedDurationMs,
      engineMs=this.engineEpochMs+wallMs}={})=>{
      this.previousCamera=this.currentCamera;
      const input=this.input.snapshot();
      // Keyboard/buttons use native ramps; pad and touch wheel use4341d0 axes.
      // 0042f4c0 renders after movement and before CBonusController::Handle.
      // Keep discrete pickup visibility from before this tick's bonus update.
      this.pickupEvents=this.simulation.step(input,dt,now,{
        wallMs,
        // Actual elapsed time includes pauses; timer 0 separately excludes them.
        engineMs,
        keys:this.input.keys,
        afterSceneryPrepare:()=>{
          this.advanceSceneryCallbacks(dt,this.simulation.nativeTickMs,
            {ranges:this.simulation.callbackRanges,alwaysUpdate:this.sceneryAlwaysUpdate});
          // Scenery callbacks precede player/NPC callbacks and the new listener.
          this.audio.updateScenery(this.soundListener,this.simulation.sceneryObjects);
        },
        beforePlayerProgress:motion=>this.audio.updateEngine(motion),
        beforePlayerPrepare:()=>this.hudMeshes.processEvents(this.race.events,dt),
        afterPlayerPrepare:state=>this.playerVisual.advanceAnimation(this.simulation.nativeTickMs,
          getDrivingAnimationRequests(config,state)),
        afterOpponentPrepare:(actor,index)=>{
          this.opponentVisuals[index].advanceAnimation(this.simulation.nativeTickMs,getNPCDrivingAnimationRequests({
            events:actor.animationEvents??[],turboActive:actor.state.turboVisible,
            turboStartedSeconds:actor.state.turboTime,nowSeconds:now/1000,...actor.animationTurbo,
            racePhase:this.race.phase,rank:this.simulation.rankStates[index].rank,
          }));
          if(actor.animationEvents)actor.animationEvents.length=0;
        },
        afterCamera:()=>{
          this.nativeCamera=this.simulation.camera;
          this.soundListener=getNativeSoundListener(this.nativeCamera,this.simulation.cameraBody,{
            matrixTranslation:this.nativeCamera===this.playerCamera||this.nativeCamera===this.simulation.failureCamera
              ?this.simulation.cameraBody.position:[0,0,0],
          });
        },
        afterParticles:()=>{
          this.audio.updateVoices({listener:this.soundListener,bodies:this.simulation.actors.map(actor=>actor.body)});
          this.audio.updateSkid({slipMagnitude:this.motion.slipMagnitude,
            playerContact:this.motion.ground.playerContact,
            soundEnabled:this.nativeAudioSettings.skidEnabled,controllerEnabled:this.audio.voices.enabled});
        },
        beforeBonuses:()=>{
        this.captureSceneryPaths();
        this.captureSceneryBodies();
        for(const pickup of this.pickups.pickups){
          const mesh=this.pickupMeshes.get(pickup.placementIndex);
          if(mesh){
            mesh.visible=pickup.state===2;
            setNativeMatrix(mesh,nativeRotationMatrix([mesh.userData.nativeAngles[0],pickup.yaw,mesh.userData.nativeAngles[2]]));
          }
        }
        this.projectiles.capture();
        this.bubbleVisuals.capture();
        this.rescueVisuals.capture();
        this.smokeVisuals.capture(this.simulation.smokeFrames);
        this.skidmarkVisuals.capture(this.simulation.skidmarkFrames);
        this.streamVisuals.capture(this.simulation.streamFrames);
        this.homingArmVisuals.capture();
        this.finishFlag.capture();
        this.weatherVisuals.capture(this.simulation.weatherFrames);
        this.explosionVisuals.capture(this.simulation.explosionFrames);
        for(const shadow of this.shadows){
          if(this.simulation.freeFlightActive&&shadow.actor===this.motion){shadow.mesh.visible=false;continue;}
          shadow.capture(this.simulation.world,this.simulation.rescue.get(shadow.actor.body));
        }
        this.hudMeshes.capture(this.simulation.playerHudPosition,this.simulation.freeFlightActive?0:dt);
        if(!this.simulation.freeFlightActive)this.hud.update(this.race,dt,{
          nowSeconds:this.simulation.engineMs/1000,
        });
        // 467d30 enters/exits the sampler once for the entire overlay. Reuse
        // the captured state for all intervening uncapped browser redraws.
        const hudSampler=this.hudSampler.capture();
        this.hudMeshes.setSampler(hudSampler);this.hud.filter=hudSampler.min;
        this.nativeCamera=this.simulation.camera;
        const cameraSector=this.simulation.cameraSector;
        this.currentCamera=this.cameraPose();
        this.playerVisual.capturePose(this.simulation.freeFlightActive?null:this.simulation.rescue.get(this.motion.body));
        //423010 samples logical renderXYZ, which relocation changes one tick
        //before the retained kart draw matrix moves. Keep its own snapshots.
        this.previousSkyPosition=this.currentSkyPosition;
        this.currentSkyPosition=new THREE.Vector3().fromArray(this.motion.body.position);
        //4918f0's player visibility gate covers its entire render tree and
        // shadow callback. HUD, smoke and other effect passes stay independent.
        this.playerVisual.group.visible=this.playerCamera.bodyVisible;
        this.shadows[0].mesh.visible=this.playerCamera.bodyVisible&&!this.simulation.freeFlightActive;
        for(let index=0;index<this.opponentVisuals.length;index++){
          const actor=this.opponents[index];
          this.opponentVisuals[index].capturePose(this.simulation.rescue.get(actor.body));
        }
        const start=nativeVisibleChunkStart({sector:cameraSector,routeCount:this.track.route.length,
          visibleChunks:this.simulation.visibleChunks,forward:this.motion.world.sectors[cameraSector].forward,
          position:this.nativeCamera.position,target:this.nativeCamera.target});
        this.applyVisibleSectors(this.simulation.freeFlightActive?[[0,this.track.sectorCount-1]]
          :nativeVisibleChunkRanges(start,this.simulation.visibleChunks,this.track.sectorCount).ranges);
        //4918f0 submits only visible objects in each inclusive sector range;
        //490d40 updates persistent diffuse once per native draw submission.
        for(const visual of [this.playerVisual,...this.opponentVisuals]){
          if(!visual.group.visible)continue;
          if(this.simulation.freeFlightActive&&visual===this.playerVisual)continue;
          for(const [first,last]of this.visibleSectorRanges)
            if(visual.actor.body.sector>=first&&visual.actor.body.sector<=last)
              visual.captureColor(this.simulation.world,dt,this.simulation.rescue.get(visual.actor.body));
        }
        // 430020 polls DirectShow completion after the scene/HUD draws.
        // Browser refreshes and blocking native pauses do not run this poll.
        this.music.pollCompletion();
      },
        beforeGameActions:()=>{
          // 420dc0 submits conditional CHEER in CHARDATA order, then performs
          // a second 44a6c0 visual update. Keep the pre-render mesh captured
          // above; this advances the sequence for the following render.
          if(!this.simulation.movementActive&&this.simulation.countdownStarted){
            const visuals=[...this.opponentVisuals,this.playerVisual];
            for(const visual of visuals)requestDriverAnimation(visual.animation,{name:'cheer',from:0,to:0});
            for(const visual of visuals)advanceDriverAnimation(visual.animation,this.simulation.nativeTickMs);
          }
        }});
      if(Boolean(this.input.freeFlightActive)!==this.simulation.freeFlightActive){
        this.input.clear();this.input.freeFlightActive=this.simulation.freeFlightActive;
      }
      this.syncFreeFlightAudio();
      this.visibleChunks=this.simulation.visibleChunks;
      if(this.simulation.lifecycle.resultGate?.finishFlagRequested&&!this.finishFlag.controller.enabled)
        this.finishFlag.setEnabled(true,dt);
      for(const event of this.pickupEvents){
        if(event.type==='green'){
          this.nativeCamera=this.playerCamera;
        }
        if(event.type==='race-exit'){
          this.active=false;this.updateLoop.stop();
          queueMicrotask(()=>this.onExit?.(this.simulation.resultPatch(event.completed)));
        }
      }
      // Pickups, projectile hits and EndUpdate run after the original HUD
      // render. Queue their notices now; capture them on the next render tick.
      // Race events already handled before rendering are identity-deduplicated.
      if(!this.simulation.freeFlightActive)this.hud.processEvents(this.pickupEvents,dt,{
        playerIndex:this.simulation.actors.length-1,lapCount:this.race.lapCount,
        nowSeconds:this.simulation.engineMs/1000,
      });
    };
    this.controls.enabled=false;this.active=true;this.updatePresentation(0);
    this.onLoadProgress?.(10);
    return result;
  }
  /** "Schaduwen op het wegdek": kart shadows on the ground surface
   * (browser enhancement) or the original sector-plane quad. */
  setSurfaceShadows(enabled){
    this.surfaceShadows=Boolean(enabled);
    for(const shadow of this.shadows??[])if(shadow.surface!==this.surfaceShadows)
      shadow.setSurface(this.surfaceShadows,this.simulation?.world,this.simulation?.rescue.get(shadow.actor.body));
  }
  setFreeFlight(enabled){
    this.freeFlightEnabled=Boolean(enabled);
    this.simulation?.setFreeFlight(this.freeFlightEnabled);
    this.input.clear();this.input.freeFlightActive=Boolean(this.simulation?.freeFlightActive);
    this.syncFreeFlightAudio();
    if(this.simulation&&!this.simulation.freeFlightActive&&this.playerVisual){
      this.nativeCamera=this.simulation.camera;
      this.previousCamera=this.currentCamera=this.cameraPose();
      this.playerVisual.capturePose(this.simulation.rescue.get(this.motion.body));
      this.playerVisual.previous=this.playerVisual.current;
      this.previousSkyPosition=this.currentSkyPosition=new THREE.Vector3().fromArray(this.motion.body.position);
    }
    return this.freeFlightEnabled;
  }
  syncFreeFlightAudio(){
    const flying=Boolean(this.simulation?.freeFlightActive);
    if(!this.audio||flying===Boolean(this.flightAudioPaused))return;
    this.flightAudioPaused=flying;
    if(flying)this.audio.pause();
    else{
      this.audio.updateEngine(this.motion);
      this.audio.execute([{event:'SLIP',op:'stop'}]);
      if(this.active)this.audio.resume();
    }
  }
  cameraPose(){
    return {position:new THREE.Vector3(this.nativeCamera.position[0],this.nativeCamera.position[1],-this.nativeCamera.position[2]),
      target:new THREE.Vector3(this.nativeCamera.target[0],this.nativeCamera.target[1],-this.nativeCamera.target[2]),
      up:new THREE.Vector3(this.nativeCamera.up[0],this.nativeCamera.up[1],-this.nativeCamera.up[2])};
  }
  updatePresentation(alpha){
    if(!this.motion)return;
    this.playerVisual.present(alpha);
    for(const visual of this.opponentVisuals)visual.present(alpha);
    for(const shadow of this.shadows)shadow.present(alpha);
    presentNativeRaceCamera(this.group,this.camera,this.previousCamera,this.currentCamera,alpha,this.track.mirrored);
    // Sky follows the active racer, not the chase camera (native 0x423010).
    this.sky?.position.lerpVectors(this.previousSkyPosition,this.currentSkyPosition,alpha);
  }
  resize(settings){
    const result=super.resize(settings);
    this.camera.fov=adaptVerticalFov(NATIVE_CAMERA_PROJECTION.verticalDegrees,this.camera.aspect);
    this.camera.updateProjectionMatrix();return result;
  }
  renderScene(options){this.multisampling.render(this.scene,this.camera,options);}
  render(time){
    if(!this.active){this.hud?.render();return;}
    // A RAF timestamp can precede a timer callback that ran earlier in this
    // browser frame. Read the same live monotonic clock as the update loop.
    const clock=this.clock.snapshot(performance.now());this.updatePresentation(clock.alpha);
    this.renderScene({present:!this.hud});
    this.hud?.render();
  }
  playSound(name){this.audio?.playEvent(name).catch(error=>this.errors.push({sound:name,reason:String(error)}));}
  setAudioSettings(settings){
    this.audioSettings=settings;this.music?.setVolume(settingsAudioPercent(settings.music));
    // Reapplying437e30 on an ordinary resume would overwrite the source levels
    // of scenery clones created after the original initial volume write.
    const effects=settingsAudioPercent(settings.effects);
    if(this.audio&&this.audio.groupVolume!==effects)this.audio.setGroupVolume(effects);
    if(this.simulation&&this.audio)this.simulation.crashAudio.enabled=this.audio.controllerEnabled;
    if(this.active)this.music?.resume();
  }
  resumeAudio(){if(this.active){this.music?.resume();if(!this.simulation?.freeFlightActive)this.audio?.unlock().catch(()=>{});}}
  suspend({notifyPause=true,pauseAudio=true,nativePause=false}={}){
    const time=performance.now();
    this.input.clear();
    if(this.simulation&&this.pausedAt===null){
      this.pausedAt=time;
      this.simulation.pause(this.clock.snapshot(time).wallMs,{native:nativePause});
      this.pauseNoticeActive=notifyPause;
      if(notifyPause)this.hud?.notify(1,0,{capture:true});
    }
    super.suspend(time);
    // 42f350/42f220/42f290 block simulation and race timers, while the
    // DirectSound buffers and DirectShow music keep playing. Focus loss and
    // leaving the race retain the browser host's separate audio suspension.
    if(pauseAudio){this.music?.pause();this.audio?.pause();}
    else this.music?.pollCompletion(); // 42f350's final pre-pause poll.
  }
  resume(){
    const time=performance.now();
    if(this.simulation&&this.pausedAt!==null){
      this.pausedDurationMs+=time-this.pausedAt;this.pausedAt=null;
      this.simulation.resume(this.clock.snapshot(time).wallMs);
      if(this.pauseNoticeActive)this.hud?.notify(2,0,{capture:true});
      this.pauseNoticeActive=false;
    }
    super.resume(time);this.controls.enabled=false;this.music?.resume();
    if(this.simulation?.freeFlightActive)this.audio?.pause();else this.audio?.resume();
  }
}
