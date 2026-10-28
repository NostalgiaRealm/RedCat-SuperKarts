import {NativePlayerMotion} from './simulation/native-motion.js';
import {createNativeTrack,selectNativeSector} from './simulation/native-track.js';
import {NativeRailCollision} from './simulation/native-collision.js';
import {parsePhysicsTable,parseRacerTable,applyNativeRaceTypeTable} from './simulation/native-tables.js';
import {NativeAIDriver,NativeWaypointOccupancy} from './simulation/native-ai-driver.js';
import {captureNPCLinearVelocity,resetNewlyNonfiniteNPCVelocity} from './simulation/npc-velocity-safety.js';
import {nativeRaceSetup,NativeAIProgress,NATIVE_MENU_OPPONENT_COUNTS} from './simulation/native-race-setup.js';
import {NativeRaceState,nativeRaceSettings,nativeSectorDistance,nativeCrossedTriggers} from './simulation/native-race.js';
import {NativeBonusPickups,nativeTrackPickups,nativeBonusOverlap} from './simulation/native-bonus.js';
import {NativeBonusCombat} from './simulation/native-combat.js';
import {NativeBubbleAttachments} from './simulation/native-bubble-attachments.js';
import {nativeProjectileFacing} from './simulation/native-projectile.js';
import {nativeJumpSettings,applyNativePlayerJump} from './simulation/native-jump.js';
import {updateNativeRankings} from './simulation/native-rank.js';
import {NativeRescueController} from './simulation/native-rescue.js';
import {nativeAIBonusCollected,nativeAITriggerSpeedLimits,recordNativeNPCFinish} from './simulation/native-ai-items.js';
import {nativeRaceTimerSetup} from './simulation/native-game-timers.js';
import {NativeStartCountdown} from './simulation/native-countdown.js';
import {NativePlayerCamera,NativeFinishCamera,NativeFailureCamera} from './simulation/native-camera.js';
import {NativeRaceLifecycle,nativeRaceKeyDown} from './simulation/native-race-lifecycle.js';
import {finalizeNativeOpponentResults,nativeRaceResultPatch} from './simulation/native-results.js';
import {nativeRacePlayerOptions,initializeNativeRacePlayerOptions,nativeRaceRouteOptions} from './simulation/native-race-options.js';
import {nativeAnalogFromNormalized} from './simulation/native-input.js';
import {NativeStartCamera} from './simulation/native-start-camera.js';
import {nativeCameraMatrix} from './simulation/native-camera-matrix.js';
import {NativeSmoke} from './simulation/native-smoke.js';
import {NativeWeather,getNativeWeatherSpec} from './simulation/native-weather.js';
import {NativeSkidmarks} from './simulation/native-skidmarks.js';
import {NativeExplosions} from './simulation/native-explosions.js';
import {NativeStreams} from './simulation/native-streams.js';
import {NativeSquash} from './simulation/native-squash.js';
import {NativeSceneryHazards,createNativeSceneryRotations} from './simulation/native-scenery-hazards.js';
import {NativeSceneryBodies} from './simulation/native-scenery-contact.js';
import {NativeSceneryReactions} from './simulation/native-scenery-reactions.js';
import {NativeSceneryPaths} from './scenery-paths.js';
import {nativeObjectCallbackRanges,nativeAdjustVisibleChunks} from './simulation/native-render.js';
import {NativeCharacterVoices} from './simulation/native-character-voice.js';
import {NativeCrashAudio} from './native-crash-audio.js';
import {NativeKeyAudio} from './native-key-audio.js';
import {nativeAudioLoadSettings} from './audio-mixing.js';
import {NATIVE_REFERENCE_UPTIME_MS} from './simulation/clock.js';
import {getPlayerLookAnimationRequests,getPlayerAnimationEventRequests,getNPCAnimationEventRequests} from './player-assets.js';
import {captureFlightPose,roadFlightPose,nearestFlightSector,advanceFreeFlight,restoreFlightPose} from './simulation/free-flight.js';
import {nativeRescueDestinationAtWaypoint} from './simulation/native-rescue.js';
import {PlayerStuckRecovery} from './simulation/player-stuck-recovery.js';
import {isSafePlayerRecoveryPose,selectPlayerRecoveryDestination} from './simulation/player-recovery-position.js';

/**
 * Composition of recovered racer, opponent, contact and bonus handlers.
 * Front-end race transitions and tournament progression are separate owners.
 */
export class RaceSimulation {
  constructor({config,manifest,cars,physicsBytes,racerBytes,track,random,
    character=0,difficulty=1,raceMode=0,opponentCount=NATIVE_MENU_OPPONENT_COUNTS[raceMode],countdown=false,
    rotationStates}) {
    this.rotationStates=rotationStates??createNativeSceneryRotations(track,config,random);
    this.world=createNativeTrack(track);
    this.routeOptions=nativeRaceRouteOptions(config);
    this.setup=nativeRaceSetup(config,track,this.world,{
      selectedCharacter:character,trackIndex:track.id,opponentCount,difficulty,raceType:raceMode,
      // 42c680 reads Race.ini PLAYER.position, last written by a finished race (42c570).
      previousFinishPosition:Math.trunc(Number(config['race.ini'].player.position))||0,
    });
    this.difficulty=difficulty;
    this.racerCharacters=[...this.setup.opponents.map(spec=>spec.availableIndex),this.setup.player.availableIndex];
    this.voices=new NativeCharacterVoices({random,racerAvailableIndices:this.racerCharacters});
    this.voices.onRequest=request=>this.onVoiceRequest?.(request);
    this.keyAudio=new NativeKeyAudio({racerCharacters:this.racerCharacters});
    this.crashAudio=new NativeCrashAudio({random,enabled:nativeAudioLoadSettings(config).controllerEnabled});
    const physics=parsePhysicsTable(physicsBytes);
    const racers=applyNativeRaceTypeTable(parseRacerTable(racerBytes),{raceType:raceMode,difficulty});
    const player=this.setup.player,geometry=cars.cars[player.carIndex];
    this.loadedUpgrades=nativeRacePlayerOptions(config);
    // 42b870 loads the INI first; player construction4319f0 clears these
    // switches before opponents, force updates and timer setup42d360.
    this.upgrades=initializeNativeRacePlayerOptions(this.loadedUpgrades);
    this.jumpSettings=nativeJumpSettings(config);
    const collision=()=>new NativeRailCollision(track,geometry.bodyBounds);
    this.motion=new NativePlayerMotion({
      physics:physics[player.carIndex],geometry,world:this.world,start:player.start,
      collision:collision(),carIndex:player.carIndex,upgrades:this.upgrades,
      mirrored:Boolean(track.mirrored),
    });
    this.motion.radius=manifest.meshes[geometry.body].horizontalRadius;
    this.motion.phase=0;
    // Logical CHARDATA identities are used for target comparisons. Absolute
    // engine indices include scenery; their separate rank-lookup quirk is below.
    this.motion.body.id=opponentCount;
    this.onPlayerCollision=contact=>{
      const sound=this.crashAudio.contact(contact);
      if(sound)this.onDirectSound?.(sound.event);
    };
    this.race=new NativeRaceState({
      track,startSector:this.motion.body.sector,
      ...nativeRaceSettings(config,track.id,difficulty,raceMode),
    });
    this.timers=nativeRaceTimerSetup({config,trackIndex:track.id,difficulty,
      raceType:raceMode,opponentCount,playerRacer:racers[player.racerRecord],...this.upgrades});
    this.countdown=countdown?new NativeStartCountdown():null;
    // 442fc0 initializes/caps the native delta at .1 BEFORE the first update;
    // startup freezes its path duration from that value. Port wall epoch is0.
    this.startCamera=countdown&&track.paths.some(path=>path.type===1)
      ?new NativeStartCamera(track,this.motion.body,.1,0):null;
    this.playerCamera=new NativePlayerCamera().reset(this.motion.body);
    this.camera=this.startCamera??this.playerCamera;
    this.cameraSectors=new WeakMap();
    this.cameraSector=this.motion.body.sector;
    this.countdownStarted=Boolean(countdown&&!this.startCamera);
    // 464740 constructs the overlay in hidden phase6. 420d90 starts it only
    // after the authored track camera finishes.
    if(this.startCamera)this.countdown.phase=6;
    this.movementActive=!countdown;
    this.race.phase=countdown?1:0;
    this.lifecycle=new NativeRaceLifecycle({phase:this.race.phase,
      movementActive:this.movementActive,playerActive:this.movementActive});
    this.damage=Math.min(100,Math.max(0,Number(config['race.ini'].player.damage)||0));
    this.wallMs=0;this.engineMs=0;this.nativeTickMs=NATIVE_REFERENCE_UPTIME_MS;
    if(!countdown)this.timers.startRace(0,{opponentCount,raceType:raceMode});
    this.occupancy=new NativeWaypointOccupancy(track);
    this.occupancy.insert(this.motion.body);
    this.motion.occupancy=this.occupancy;
    this.opponents=this.setup.opponents.map(spec=>{
      const actor=new NativeAIDriver({
        track,world:this.world,geometry,start:spec.start,racer:racers[spec.racerRecord],
        playerRacer:racers[player.racerRecord],random,groundClock:this.motion.groundClock,
        collision:collision(),occupancy:this.occupancy,efficiency:spec.profile.efficiency,
        id:spec.index,carIndex:spec.carIndex,
      });
      actor.radius=this.motion.radius;
      actor.voices=this.voices;
      actor.progress=new NativeAIProgress(actor.body.sector,track.route.length,this.setup.progressOriginSector);
      return actor;
    });
    // Render objects are created player first. CHARDATA bonus slots instead
    // contain opponents first and the player last; preserve both orders.
    this.actors=[...this.opponents,this.motion];
    this.bubbles=new NativeBubbleAttachments(this.actors.map(actor=>actor.body));
    this.rankStates=[...this.setup.opponents.map(spec=>({
      objectId:spec.index,distance:this.opponents[spec.index].progress.distance,
      rank:spec.start.rank,finished:false,finishTimeMs:0,
    })),{distance:0,rank:this.setup.player.start.rank,finished:false,finishTimeMs:0}];
    const bodies=[this.motion,...this.opponents].map(actor=>actor.body);
    // Both 4319f0 and 417640 install 434c40. A directed pair can therefore
    // reach the player crash callback twice; the selector owns its 300ms gate.
    for(const body of bodies)body.onCollision=contact=>{
      if(contact.firstBody===this.motion.body||contact.secondBody===this.motion.body)
        this.onPlayerCollision?.({...contact,nowMs:this.nativeTickMs});
    };
    this.scenery=new NativeSceneryBodies({track,config,manifest,world:this.world,collision:collision()});
    this.sceneryReactions=new NativeSceneryReactions({track,manifest,world:this.world,random});
    this.squash=new NativeSquash({config,timers:this.timers});
    this.squash.register(this.motion.body,{timerId:19});
    this.opponents.forEach((actor,index)=>this.squash.register(actor.body,{timerId:20+index}));
    this.sceneryHazards=new NativeSceneryHazards({track,config,manifest,
      rotationStates:this.rotationStates,squash:this.squash});
    this.sceneryPaths=new NativeSceneryPaths(track);
    this.sceneryObjects=new Map(this.sceneryPaths.objects);
    for(const body of this.scenery.bodies)this.sceneryObjects.set(body.placementIndex,body);
    for(const object of this.sceneryReactions.objects)this.sceneryObjects.set(object.placementIndex,object);
    for(const object of this.sceneryHazards.objects)this.sceneryObjects.set(object.placementIndex,object);
    this.physicalBodies=[...this.scenery.bodies,...bodies];
    this.contactState={impulse:0};
    this.scenery.collision.bodies=this.physicalBodies;
    this.scenery.collision.contactState=this.contactState;
    for(const actor of this.actors){
      actor.collision.bodies=this.physicalBodies;
      actor.collision.contactState=this.contactState;
    }
    this.visibleChunks=Number(config['game.ini']?.options?.visiblechunks??40);
    this.callbackRanges=nativeObjectCallbackRanges(this.motion.body.sector,this.visibleChunks,track.sectorCount);
    this.sharedAI={dropperCounter:0};
    this.npcFinishTimes=this.opponents.map(()=>null);
    this.circuit=Number(config['track.ini'].maps[track.id].split(',')[0])!==0;
    this.speedLimits=nativeAITriggerSpeedLimits(config);
    const gfx=config['sndgfx.ini']?.['gfx options']??{};
    this.rescue=new NativeRescueController({track,world:this.world,...this.routeOptions,
      occupants:()=>bodies,occupancy:this.occupancy,
      playerSafety:{body:this.motion.body,collision:this.motion.collision},
      effectsEnabled:Number(gfx.jetstreams??0)!==0&&Number(gfx.alpha_blending??0)!==0});
    this.pickups=new NativeBonusPickups({
      pickups:nativeTrackPickups(track,manifest,config),racerCount:this.actors.length,
      raceType:raceMode,bonusConfig:config['game.ini'].bonus_data,random,voices:this.voices,
    });
    this.combat=new NativeBonusCombat({
      pickups:this.pickups,actors:this.actors,config,manifest,world:this.world,
      // The original primary heap slot +0x3c is uninitialized. A deterministic
      // zero policy is explicit here; it is not an original verified value.
      shotClearance:0,forwardDirection:body=>nativeProjectileFacing(track,body,this.routeOptions),
    });
    this.combat.onAnimationEvent=(racer,event)=>this.dispatchAnimation(racer,event);
    this.combat.onBubbleAttach=racer=>this.bubbles.attach(racer);
    this.combat.onBubbleDetach=racer=>this.bubbles.detach(racer);
    this.pickups.onAnimationEvent=(racer,event)=>{
      if(event.callback===0x40d610){
        const actor=this.opponents[racer];
        event={...event,fsmState:actor?.state.mode??0};
        if(actor){
          const animation=nativeAIBonusCollected(actor.state,Math.fround(this.engineMs/1000));
          if(animation)actor.events.push(animation);
        }
      }
      this.dispatchAnimation(racer,event);
    };
    this.playerTurboAt=0;
    this.smoke=new NativeSmoke({random,carIndex:player.carIndex,
      enabled:Number(gfx.clouds??0)!==0,alphaBlending:Number(gfx.alpha_blending??0)!==0});
    this.smokeFrames=[];
    this.streams=new NativeStreams({playerBody:this.motion.body,
      jetstreams:Number(gfx.jetstreams??0)!==0,alphaBlending:Number(gfx.alpha_blending??0)!==0});
    this.streamTurboTimes=this.actors.map(()=>0);
    this.actors.forEach((actor,index)=>this.streams.racer(actor.body,index));
    this.combat.onTurbo=(shooter,level)=>{
      this.streamTurboTimes[shooter]=this.nativeTickMs>>>0;
      this.streams.racer(this.actors[shooter].body,shooter,level);
    };
    this.combat.onProjectileState=(shot,state)=>{
      if(state===2)this.streams.projectile(shot);else this.streams.remove(shot);
    };
    this.streamFrames={jets:[],ribbons:[]};
    this.skidmarks=new NativeSkidmarks({
      enabled:Number(gfx.skidmarks??0)!==0,fade:Number(gfx.fade_skmarks??0)!==0,
    });
    this.skidmarkFrames=[];
    this.explosions=new NativeExplosions({random});
    this.combat.onExplosion=body=>this.explosions.add(body);
    this.explosionFrames=[];
    // 4818c0 is the final42d7d0 construction stage, before42f930 reseeds
    // gameplay. Even an initially paused weather pool consumes its1600 draws.
    const weatherSpec=getNativeWeatherSpec(config,raceMode,track.id);
    this.weather=weatherSpec?new NativeWeather({...weatherSpec,random}):null;
    this.weatherFrames=[];
    this.events=[];
    this.velocitySafetyCorrections=0;
    this.freeFlightEnabled=false;this.freeFlightActive=false;
    this.flightClockOffsetMs=0;this.flightRawWallMs=0;
    this.flightAnchor=captureFlightPose(this.motion.body);
    this.flightGridAnchor=captureFlightPose(this.motion.body);
    this.playerRecovery=new PlayerStuckRecovery();
  }

  step(input,dt,now,{wallMs=now,engineMs=now,keys={},beforeBonuses,
    afterSceneryPrepare,beforePlayerProgress,beforePlayerPrepare,afterPlayerPrepare,afterOpponentPrepare,
    afterCamera,afterParticles,beforeGameActions}={}) {
    if(this.freeFlightEnabled&&!this.freeFlightActive&&this.movementActive&&this.race.phase===0)
      this.beginFreeFlight();
    if(this.freeFlightActive){
      this.playerRecovery.reset();
      this.flightClockOffsetMs+=Math.max(0,wallMs-this.flightRawWallMs);
      this.flightRawWallMs=wallMs;
      advanceFreeFlight(this.motion,input,dt);
      const body=this.motion.body;
      body.sector=nearestFlightSector(this.race.track,body.position);
      this.cameraSector=body.sector;this.playerCamera.step(body);this.camera=this.playerCamera;
      this.cameraBody={position:[...body.position],yaw:body.yaw,lateralSpeed:0,forwardSpeed:0};
      this.cameraMatrix=nativeCameraMatrix(this.camera);
      this.playerHudPosition=[...body.position];this.playerSpeedKmh=0;
      this.events=[];
      afterCamera?.();beforeBonuses?.();
      return this.events;
    }
    this.flightRawWallMs=wallMs;
    wallMs-=this.flightClockOffsetMs;engineMs-=this.flightClockOffsetMs;
    this.wallMs=wallMs;this.engineMs=engineMs;
    this.nativeTickMs=wallMs+NATIVE_REFERENCE_UPTIME_MS;
    if(!this.lifecycle.running){this.playerRecovery.reset();return [];}
    if(this.lifecycle.resultGate?.waitingForRelease){this.playerRecovery.reset();return this.updateResult(wallMs,keys);}
    const velocitySafetyEvents=[];
    this.voices.drain();
    //428cc0 precedes scene callbacks and restores baseline streams only when
    // a positive raw GetTickCount timestamp is strictly more than5s old.
    this.streamTurboTimes.forEach((started,index)=>{
      if((started|0)>0&&(((this.nativeTickMs>>>0)-started)|0)>5000){
        this.streamTurboTimes[index]=0;this.streams.racer(this.actors[index].body,index);
      }
    });
    // 42f4fb calls457b60 before scenery/racer callbacks. Shells retain that
    // pre-movement pose for this frame rather than inheriting the kart transform.
    this.bubbles.step();
    this.callbackRanges=nativeObjectCallbackRanges(this.motion.body.sector,this.visibleChunks,this.race.track.sectorCount);
    const hazardOpponents=this.opponents.map(actor=>actor.body);
    // 491530 walks engine objects in OMP order. A hazard can clamp a racer's
    // speed before a later type2 launch samples it, so keep callback families
    // interleaved rather than processing one family at a time.
    for(let index=0;index<this.race.track.placements.length;index++){
      this.scenery.prepare(this.nativeTickMs,this.callbackRanges,index);
      this.sceneryReactions.step(dt,{...this.motion.body,radius:this.motion.radius},this.callbackRanges,
        (placement,object)=>this.onSceneryImpact?.(placement,object),index);
      this.sceneryHazards.stepPlacement(index,dt,this.nativeTickMs,{
        player:this.motion.body,opponents:hazardOpponents,
        playerPosition:this.playerHudPosition??[0,0,0],ranges:this.callbackRanges});
    }
    afterSceneryPrepare?.();
    // 4325b0 begins with48c030, including during the inactive startup phase.
    this.rescue.checkEnvironment(this.motion);
    const activeMs=this.timers.read(3,wallMs),engineSeconds=Math.fround(engineMs/1000);
    this.playerHudPosition=[...this.motion.body.position];
    this.playerSpeedKmh=Math.trunc(Math.fround(Math.fround(this.motion.body.forwardSpeed)*Math.fround(3.6)));
    // 432ab5 samples engine sound before ranks and crossed track markers.
    // A jump can change forward speed later in this same player callback.
    beforePlayerProgress?.(this.motion);
    // 004325b0 updates player progress then ranks, before its trigger callback
    // and before any NPC callback updates that NPC's progress.
    for(let i=0;i<this.opponents.length;i++)this.rankStates[i].distance=this.opponents[i].progress.distance;
    const playerRank=this.rankStates.at(-1);
    playerRank.distance=this.race.distance+nativeSectorDistance(
      this.motion.body.sector,this.motion.body.previousSector,this.world.sectors.length);
    playerRank.finished=this.race.finished;playerRank.finishTimeMs=this.race.raceTimeMs??0;
    const overtakes=updateNativeRankings(this.rankStates);
    for(const event of overtakes)this.voices.passing(event.behind,event.ahead);
    // 4938e0 dispatches the two crossed PMP markers in their stored order.
    // Its generic callback table is called by the player; NPC406470 has a
    // separate marker switch without the weather or jump callbacks.
    for(const marker of nativeCrossedTriggers(
      this.race.track,this.motion.body.previousSector,this.motion.body.sector)){
      applyNativePlayerJump(marker,{track:this.race.track,body:this.motion.body,
        wheels:this.motion.ground.wheels,settings:this.jumpSettings,routeOptions:this.routeOptions});
      this.weather?.trigger(marker,{player:true,
        waypointMarker:this.race.track.drive[this.motion.body.waypoint]?.unknown[1]??0,
        forward:marker===83||marker===88?nativeProjectileFacing(this.race.track,this.motion.body,this.routeOptions):true});
    }
    this.race.beginUpdate(this.motion.body.sector,activeMs,{
      previousSector:this.motion.body.previousSector});
    this.playerRecovery.observeLap(this.race);
    // Capture only after real crossings have updated lap/distance metadata.
    if(this.playerRecoveryEligible()&&this.motion.ground.groundCount>=2)
      this.playerRecovery.remember(this.motion.body,this.race,pose=>isSafePlayerRecoveryPose({
        track:this.race.track,world:this.world,motion:this.motion},pose));
    if(this.race.phase!==this.lifecycle.phase)this.lifecycle.enter(this.race.phase);
    if(this.race.phase===3&&!this.finishCamera){
      this.finishCamera=new NativeFinishCamera(this.race.track,this.motion.body);
      this.camera=this.finishCamera;
    }
    for(const event of this.race.events){
      if(event.type==='lap')this.timers.start(0,wallMs);
      // 440d70 pauses lap timer0 right after 440c30 restarts it; its timer3
      // pause is represented by the fixed race.raceTimeMs.
      if(event.type==='finished')this.timers.pause(0,wallMs);
      if(event.type==='time-gate')this.timers.setLimit(18,this.race.remainingMs,wallMs);
      if(event.type==='last-lap')this.voices.gameEvent(5);
      if(event.type==='lap-record')this.voices.gameEvent(6);
      if(event.sound)this.onDirectSound?.(event.sound);
    }
    // Use the pose whose real crossings were just consumed above. Capturing
    // after integration would pair the next sector with the previous lap state.
    if(this.playerRecovery.step(this.motion.body,input,dt,{eligible:this.playerRecoveryEligible()})){
      const recovery=this.playerRecovery.request(this.motion.body,this.race);
      // Do not turn an unavailable return into a permanently shrunken kart.
      // The rescue controller revalidates live occupancy when it relocates.
      const destination=selectPlayerRecoveryDestination({track:this.race.track,world:this.world,
        motion:this.motion,recovery});
      if(!destination.blocked&&this.rescue.enqueue(this.motion,{softLock:recovery}))
        this.playerRecovery.started(recovery);
      else this.playerRecovery.retryAfter();
    }
    let fire=null;
    // 4325b0 samples lateral speed before input/forces; its other animation
    // requests observe prepared controls, before any actor is integrated.
    this.playerAnimationState={lateralSpeed:this.motion.body.lateralSpeed,
      movementActive:this.movementActive,phase:this.race.phase,rank:playerRank.rank};
    beforePlayerPrepare?.(this.motion);
    this.motion.prepare({
      accelerate:input.throttle>0,brake:input.brake>0,
      left:input.steer<0,right:input.steer>0,handbrake:input.handbrake>0,
    },dt,{active:this.movementActive,phase:this.race.phase,
      analog:input.analog?nativeAnalogFromNormalized(input.analog):null,
      onBonus:()=>{
        // 433870/433cf0/4341d0 fire after the first wheel pass and before
        // forces; inactive startup never polls the fire gate.
        fire=this.combat.playerFire(input.bonus>0,this.nativeTickMs>>>0);
        if(fire?.type==='turbo')this.playerTurboAt=this.nativeTickMs;
      }});
    if(this.movementActive)this.combat.prepareEffect(this.actors.length-1,dt);
    Object.assign(this.playerAnimationState,{forwardSpeed:this.motion.body.forwardSpeed,
      brake:this.motion.controls.brake,handbrake:this.motion.controls.handbrake,
      turboAgeMs:this.nativeTickMs-this.playerTurboAt,
      // 53be64 is an unwritten legacy-autopilot flag, unrelated to rescue.
      legacyAutopilotActive:false,
      lookRequests:getPlayerLookAnimationRequests({playerPosition:this.motion.body.position,
        opponents:this.opponents.map(actor=>actor.body)})});
    afterPlayerPrepare?.(this.playerAnimationState);
    for(let index=0;index<this.opponents.length;index++){
      const actor=this.opponents[index];
      // 40b0b0 performs the same check before the NPC state dispatch.
      this.rescue.checkEnvironment(actor);
      const profile=this.setup.opponents[index].profile;
      if(this.movementActive)actor.progress.update(actor.body.sector,dt);
      const previousVelocity=captureNPCLinearVelocity(actor.body);
      actor.prepare(dt,{
        active:this.movementActive,
        playerGlobals:{tireUpgrade:this.upgrades.tireUpgrade,lowSpeedTurn:this.motion.lowSpeedTurn},
        difficulty:this.difficulty,progressDifference:actor.progress.distance-this.race.distance,
        effect:()=>this.combat.prepareEffect(index,dt),
        decision:{
          player:this.motion.body,racers:this.actors.map(actor=>actor.body),
          rank:this.rankStates[index].rank,playerRank:playerRank.rank,
          // 0x40cde0 passes an engine object index to the roster-index rank
          // accessor. Loaded scenery places every racer beyond the roster;
          // 0x417e90 therefore returns the player rank on all six shipped maps.
          itemRank:playerRank.rank,
          time:engineSeconds,owned:this.pickups.owned[index],shared:this.sharedAI,
          reactionMs:profile.reaction,catchupMs:profile.catchupMs,
          catchupDurationMs:profile.catchupDurationMs,
          playerProtected:Boolean(this.combat.effects.at(-1)?.active),
          fire:()=>this.combat.fire(index),rescue:()=>this.rescue.enqueue(actor),
          triggers:{circuit:this.circuit,lapCount:this.race.lapLimit,
            playerForwardSpeed:this.motion.body.forwardSpeed,
            drivingStyle:profile.drivingStyle,speedLimits:this.speedLimits},
        },
      });
      for(const correction of resetNewlyNonfiniteNPCVelocity(actor.body,previousVelocity)){
        this.velocitySafetyCorrections++;
        velocitySafetyEvents.push({type:'npc-velocity-safety',racer:index,wallMs,...correction});
      }
      afterOpponentPrepare?.(actor,index);
      for(const event of actor.events)if(event.type==='finish')recordNativeNPCFinish(
        actor.body.id,this.rankStates.slice(0,-1),
        timer=>this.timers.read(timer,wallMs),
        timer=>{this.timers.pause(timer,wallMs);this.npcFinishTimes[timer-9]=this.timers.read(timer,wallMs);});
    }
    this.scenery.integrate(dt,this.callbackRanges);
    this.motion.integrate();
    for(const actor of this.opponents)actor.integrate();
    if(this.playerCamera.handleKeys(keys,this.race.phase)){
      this.camera=this.playerCamera;
      this.cameraSectors.set(this.playerCamera,this.motion.body.sector);
    }
    // 41d920 selects from the previous camera position; 498c00 then updates it.
    this.cameraSector=selectNativeSector(this.world,this.cameraSectors.get(this.camera)??this.motion.body.sector,
      this.camera.position[0],this.camera.position[2]);
    this.cameraSectors.set(this.camera,this.cameraSector);
    this.camera.step(this.motion.body);
    this.cameraMatrix=nativeCameraMatrix(this.camera);
    this.cameraBody={position:[...this.motion.body.position],yaw:this.motion.body.yaw,
      lateralSpeed:this.motion.body.lateralSpeed,forwardSpeed:this.motion.body.forwardSpeed};
    afterCamera?.();
    this.explosions.step(dt);
    this.weather?.step(dt,[this.motion.body.lateralSpeed,this.motion.body.verticalSpeed,this.motion.body.forwardSpeed]);
    // Original482020 particle update precedes437c10 voice service/432240 skid.
    afterParticles?.();
    this.smoke.emitSkid({slipMagnitude:this.motion.slipMagnitude,nowMs:this.nativeTickMs,deltaSeconds:dt,
      position:this.playerHudPosition,body:this.motion.body,cameraMatrix:this.cameraMatrix});
    this.skidmarks.emit({deltaSeconds:dt,slipMagnitude:this.motion.slipMagnitude,
      playerContact:this.motion.ground.playerContact,matrix:this.motion.body.matrix,
      position:this.motion.body.position,wheelOffsets:this.motion.ground.wheels.map(wheel=>wheel.local)});
    this.squash.step(dt,this.nativeTickMs);
    const playerRescue=this.rescue.get(this.motion.body);
    this.rescue.step(dt);
    if(playerRescue?.softLock&&playerRescue.relocated){
      const body=this.motion.body,destination=playerRescue.destination;
      this.occupancy.remove(body);this.occupancy.insert(body);
      body.previousSector=body.sector;this.race.previousSector=body.sector;
      this.race.distance=Math.min(this.race.distance,destination.recoveryDistance);
      this.race.finishArmed=this.race.finishArmed&&destination.recoveryFinishArmed;
      this.updateRecoveryPickupExclusions(true);
      if(this.playerRecovery.lastRecovery)
        this.playerRecovery.lastRecovery.destination={...destination,position:[...destination.position]};
      this.playerCamera.reset(body);this.cameraSector=body.sector;
      this.cameraSectors.set(this.playerCamera,body.sector);
      this.cameraMatrix=nativeCameraMatrix(this.camera);
      this.cameraBody={position:[...body.position],yaw:body.yaw,lateralSpeed:0,forwardSpeed:0};
    }
    if(playerRescue?.relocated){this.playerSpeedKmh=0;this.playerHudPosition=[...this.motion.body.position];}
    for(const entry of this.rescue.entries)
      for(const sample of entry.sounds)this.voices.rescue(entry.body.id,sample);
    this.streams.step(dt,{playerSpeedKmh:this.playerSpeedKmh,playerThrottle:this.motion.controls.throttle,
      renderPose:body=>{
        const rescue=this.rescue.get(body);
        return rescue?{matrix:rescue.matrix,position:rescue.renderPosition}:null;
      }});
    this.combat.arms.step(dt);
    if(this.countdownStarted){
      this.countdown.step(dt);
      for(const event of this.countdown.events)if(event.type==='sound')this.onDirectSound?.(event.name);
    }
    // 428a00 sorts every pool slot in place. Keep this in the simulation:
    // its first-free allocation order affects the shared original RNG stream.
    this.skidmarkFrames=this.skidmarks.capture();
    this.streamFrames=this.streams.draw();
    this.smokeFrames=this.smoke.capture({deltaSeconds:dt,cameraPosition:this.camera.position,
      cameraMatrix:this.cameraMatrix});
    this.weatherFrames=this.weather?.capture()??[];
    this.explosionFrames=this.explosions.capture();
    // 0042f4c0 renders the moved actors before the bonus controller updates.
    beforeBonuses?.();
    // 42f9c0's hardwired Space handler follows the render, independently of
    // remappable driving controls. Preserve its available-index/roster quirk.
    const space=nativeRaceKeyDown(keys,32);
    for(const command of this.keyAudio.step(space)){
      if(command.kind==='voice')this.onVoiceRequest?.(command.request);
      else this.onDirectSound?.(command.event);
    }
    this.rescue.finishRender();
    this.updateRecoveryPickupExclusions();
    const pickups=this.pickups.step(dt,engineSeconds,this.actors.map(actor=>({
      position:actor.body.position,radius:actor.radius,
      // Returning through a bonus must not collect it without driving there.
      canCollect:actor!==this.motion||!playerRescue?.softLock,
      excludedPickups:actor===this.motion?this.playerRecovery.excludedPickups:undefined,
    })),{activeProjectileCount:this.combat.activeCount()});
    const combat=this.combat.step(dt,engineSeconds);
    // 445900 updates authored paths after rendering/bonuses, before startup
    // actions. Physical poses are written only on original path write ticks.
    this.sceneryPaths.step({playerSector:this.race.previousSector,
      lapCount:this.race.lapCount,deltaSeconds:dt});
    this.scenery.syncPaths(this.sceneryPaths);
    if(this.startCamera&&!this.countdownStarted&&this.startCamera.advance(this.motion.body,wallMs)){
      this.countdown=new NativeStartCountdown();
      this.countdownStarted=true;
      // 420d90 starts the motor exactly once before starting the321 overlay.
      this.onEngineStart?.();
    }
    beforeGameActions?.();
    const startEvents=[];
    if(!this.movementActive&&this.countdownStarted&&this.countdown.snapshot().green){
      this.movementActive=true;this.race.phase=0;
      startEvents.push(...this.lifecycle.enter(0,{startRace:()=>this.timers.startRace(wallMs,{
        opponentCount:this.opponents.length,raceType:this.race.raceType})}));
      this.playerCamera.startRace(this.motion.body);
      this.camera=this.playerCamera;
      this.cameraSectors.set(this.playerCamera,this.motion.body.sector);
    }
    this.failureCamera?.advance();
    if(this.race.phase===6&&this.damage>98)this.smoke.emitDamage({
      nowMs:this.nativeTickMs,deltaSeconds:dt,position:this.playerHudPosition,body:this.motion.body,
      cameraMatrix:this.cameraMatrix});
    const resultEvents=this.updateResult(wallMs,keys);
    const beforeExpiry=this.race.events.length;
    this.race.endUpdate(this.timers.read(3,wallMs),{damage:this.damage});
    // 46ecc0 draws the lap time from timer0, not from race timer3.
    this.race.lapTimerMs=this.timers.read(0,wallMs);
    for(const event of this.race.events.slice(beforeExpiry))
      if(event.sound)this.onDirectSound?.(event.sound);
    this.lifecycle.gameOverMode=this.race.gameOverMode;
    if(this.race.phase!==this.lifecycle.phase){
      this.lifecycle.enter(this.race.phase);
      if(this.race.phase===6){
        this.playerCamera.setMode(1);
        this.failureCamera=new NativeFailureCamera(this.motion.body,dt);
        this.camera=this.failureCamera;
      }
    }
    this.events=[...overtakes,...(fire?[fire]:[]),...velocitySafetyEvents,
      ...this.opponents.flatMap((actor,racer)=>actor.events.map(event=>({...event,racer}))),
      ...pickups,...combat,...this.race.events,...(this.countdown?.events??[]),...startEvents,...resultEvents];
    this.visibleChunks=nativeAdjustVisibleChunks(this.visibleChunks,{phase:this.race.phase,hardware:true,delta:dt});
    if(!this.rescue.get(this.motion.body)&&roadFlightPose(this.motion))this.flightAnchor=captureFlightPose(this.motion.body);
    return this.events;
  }

  playerRecoveryEligible(){
    return this.movementActive&&this.race.phase===0&&this.lifecycle.running
      &&!this.race.finished&&!this.freeFlightActive&&!this.rescue.get(this.motion.body)
      &&!this.combat.effects.at(-1)?.active&&!this.squash.find(this.motion.body)?.active
      &&(this.motion.ground.groundCount>0||Math.abs(this.motion.body.verticalSpeed)<1);
  }

  updateRecoveryPickupExclusions(relocated=false){
    const excluded=this.playerRecovery.excludedPickups;
    if(!relocated&&!excluded.size)return;
    const player={position:this.motion.body.position,radius:this.motion.radius};
    this.pickups.pickups.forEach((pickup,index)=>{
      if(!nativeBonusOverlap(player,pickup))excluded.delete(index);
      else if(relocated)excluded.add(index);
    });
  }

  beginFreeFlight(){
    this.playerRecovery.reset();
    const valid=pose=>roadFlightPose(this.motion,pose,{clear:true});
    let anchor=[captureFlightPose(this.motion.body),this.flightAnchor,this.flightGridAnchor].find(valid);
    // If a kart occupies the remembered pose, use an authored recovery point
    // behind it. The cheat never awards the relocation as race progress.
    if(!anchor){
      const track=this.race.track,count=track.route.length,reference=this.flightAnchor.sector;
      const candidates=track.drive.map((node,waypoint)=>({node,waypoint,
        behind:(reference-nearestFlightSector(track,node.position)+count)%count})).filter(x=>x.node.unknown[1]!==50)
        .sort((a,b)=>a.behind-b.behind||a.waypoint-b.waypoint);
      for(const {waypoint}of candidates){
        const pose=nativeRescueDestinationAtWaypoint(track,this.world,waypoint);
        if(valid(pose)){anchor=pose;break;}
      }
    }
    if(!anchor)return false;
    this.flightReturnPose=anchor;this.flightOriginSector=this.motion.body.sector;this.freeFlightActive=true;
    this.occupancy.remove(this.motion.body);
    this.flightCamera=this.camera;this.flightCameraMode=this.playerCamera.mode;
    this.playerCamera.setMode(1).reset(this.motion.body);this.camera=this.playerCamera;
    return true;
  }
  setFreeFlight(enabled){
    this.freeFlightEnabled=Boolean(enabled);
    if(!this.freeFlightEnabled&&this.freeFlightActive){
      restoreFlightPose(this.motion,this.flightReturnPose);
      this.rescue.entries=this.rescue.entries.filter(entry=>entry.body!==this.motion.body);
      this.occupancy.insert(this.motion.body);
      this.race.previousSector=this.motion.body.sector;
      if(this.motion.body.sector!==this.flightOriginSector)this.race.finishArmed=false;
      this.playerCamera.setMode(this.flightCameraMode).reset(this.motion.body);
      this.camera=this.flightCamera??this.playerCamera;this.camera.step(this.motion.body);
      this.cameraSector=this.motion.body.sector;
      this.cameraSectors.set(this.camera,this.cameraSector);
      this.freeFlightActive=false;
    }
    return this.freeFlightEnabled;
  }
  /** native: the P/Escape pause 42f350, reachable only outside phases 3/6
   * (42f9c0). Other host suspensions restore exactly the timers they paused,
   * so 440d70's finish pause survives a focus loss during the results. */
  pause(wallMs,{native=false}={}){
    this.playerRecovery.reset();
    if(this.freeFlightActive){this.flightPausedAt=wallMs;return;}
    const nowMs=wallMs-this.flightClockOffsetMs;
    if(native){this.hostPausedTimers=null;this.timers.pauseGame(nowMs);}
    else this.hostPausedTimers=this.timers.pauseHost(nowMs);
  }
  dispatchAnimation(racer,event){
    const requests=event.callback===0x4362f0
      ?getPlayerAnimationEventRequests({...event,completed:this.race.finished})
      :getNPCAnimationEventRequests(event);
    if(this.onAnimationRequest)for(const request of requests)this.onAnimationRequest(racer,request);
    else(this.actors[racer].animationEvents??=[]).push(event);
  }
  resume(wallMs){
    this.playerRecovery.reset();
    if(this.flightPausedAt!==undefined){
      const paused=Math.max(0,wallMs-this.flightPausedAt);
      this.flightClockOffsetMs+=paused;this.flightRawWallMs+=paused;
      delete this.flightPausedAt;return;
    }
    const nowMs=wallMs-this.flightClockOffsetMs;
    if(this.hostPausedTimers)this.timers.resumeTimers(this.hostPausedTimers,nowMs);
    else this.timers.resumeGame(nowMs);
    this.hostPausedTimers=null;
  }
  updateResult(wallMs,keys){
    const events=this.lifecycle.updateResult(wallMs,keys);
    if(events.some(event=>event.type==='race-exit')){
      this.movementActive=false;this.race.phase=4;
    }
    return events;
  }
  resultPatch(completed=this.lifecycle.raceCompleted){
    const opponents=this.rankStates.slice(0,-1);
    if(completed)finalizeNativeOpponentResults(opponents,{
      playerDistance:this.race.distance,sectorCount:this.race.track.route.length,lapCount:this.race.lapLimit,
      readTimer:id=>this.timers.read(id,this.wallMs),pauseTimer:id=>this.timers.pause(id,this.wallMs),
      trailingRecordTimeMs:0,
    });
    return nativeRaceResultPatch({finished:completed,trackIndex:this.race.track.id,
      player:{damage:this.damage,finishTimeMs:this.race.raceTimeMs??0,rank:this.rankStates.at(-1).rank,
        stars:this.pickups.stars,bestLapMs:this.race.sessionBestLapMs,carIndex:this.setup.player.availableIndex},
      opponents:opponents.map((state,i)=>({...state,carIndex:this.setup.opponents[i].aiId})),
      bestLapRecordMs:this.race.bestLapMs,raceRecordMs:this.race.bestRaceMs,
    });
  }
}
