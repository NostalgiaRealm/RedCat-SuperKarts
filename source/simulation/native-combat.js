import { applyNativeTurbo, nativeBonusParameters, nativeBonusVisual } from './native-bonus.js';
import { advanceNativeProjectile, deactivateNativeProjectile, nativeProjectileLaunchPose,
  selectNativeProjectileTarget, NativeFireGate, hatchNativeBubbles } from './native-projectile.js';
import { createNativeHitRecord, initializeNativeHitEffect, updateNativeHitEffect } from './native-bonus-effects.js';
import { sampleNativeTrack, selectNativeSector } from './native-track.js';
import { markNativeNPCWeaponHit } from './native-ai-items.js';
import { nativePlayerHitSoundRequests } from './native-character-voice.js';
import { nativeFiringSoundRequest } from '../bonus-audio.js';
import { NativeHomingArms } from './native-homing-arm.js';

const f32 = Math.fround;

/**
 * Original controller ownership, projectile pools and hit-effect composition.
 * The caller supplies the original actor order (NPCs, then player), shared RNG
 * through pickups, and an explicit initial value for the uninitialized native
 * shot +0x3c field. That field is not silently invented as a collision radius.
 */
export class NativeBonusCombat {
  constructor({ pickups, actors, config, manifest, world, shotClearance, forwardDirection, voices = pickups.voices,
    paletted = false }) {
    if (!Number.isFinite(shotClearance)) throw new TypeError('An explicit native shot +0x3c initialization policy is required');
    if (!actors.length || actors.some(actor => !Number.isFinite(actor.radius))) {
      throw new TypeError('Every actor requires its current original model collision radius');
    }
    this.pickups = pickups;
    this.actors = actors;
    this.config = config;
    this.manifest = manifest;
    this.world = world;
    this.random = pickups.random;
    this.voices = voices;
    this.parameters = nativeBonusParameters(config['game.ini'].bonus_data);
    this.rotationSpeed = Number(config['game.ini'].bonus_data.weapon_rotation_speed);
    this.invincibilitySeconds = f32(Number(config['game.ini'].bonus_data.weapon_invince_time) * f32(0.001));
    if (!Number.isFinite(this.rotationSpeed)) throw new TypeError('Original bonus rotation speed is required');
    this.forwardDirection = forwardDirection;
    this.fireGate = new NativeFireGate();
    const slot = () => ({ state: 1, ageSeconds: 0, type: 0, level: 0, shooter: -1, target: -1,
      position: [0, 0, 0], angles: [0, 0, 0], matrix: [1, 0, 0, 0, 1, 0, 0, 0, 1],
      clearance: f32(shotClearance), previousHeight: 0, heightInitialized: false });
    // 0x450fa0 uses <=40; 0x455470 initializes a separate 40-record array.
    this.shots = Array.from({ length: 41 }, slot);
    this.secondaryShots = Array.from({ length: 40 }, () => ({ ...slot(), clearance: 0 }));
    this.effects = actors.map(() => null);
    const graphics = config['sndgfx.ini']?.['gfx options'] ?? {};
    this.arms = new NativeHomingArms({actors, voices,
      jetstreams: Number(graphics.jetstreams ?? 0) !== 0,
      alphaBlending: Number(graphics.alpha_blending ?? 0) !== 0, paletted});
  }

  groundHeight = shot => {
    shot.sector = selectNativeSector(this.world, shot.sector ?? 0, shot.position[0], shot.position[2]);
    return sampleNativeTrack(this.world, shot.sector, ...shot.position).height;
  };

  activeCount() {
    let primary=0,secondary=0;
    for(const shot of this.shots)if(shot.state===2)primary++;
    for(const shot of this.secondaryShots)if(shot.state===2)secondary++;
    return primary+secondary;
  }

  emitAnimation(racer, event) {
    // With a renderer attached, enqueue at the original callback instant.
    // Headless users can retain the ordered callback records for later review.
    if (this.onAnimationEvent) this.onAnimationEvent(racer, event);
    else (this.actors[racer].animationEvents ??= []).push(event);
  }

  /** Call during player input, before calculating this frame's forces. */
  playerFire(held, nowMs) {
    if (!this.fireGate.poll(held, nowMs)) return null;
    return this.fire(this.actors.length - 1);
  }

  /** 0x451640. AI fire decisions call this directly, without the player gate. */
  fire(shooter) {
    const owned = this.pickups.owned[shooter];
    if (owned.state === 1) return null;
    const body = this.actors[shooter].body;
    const type = owned.type, level = owned.level;
    const requestFiringSound = () => {
      if (!this.voices) return;
      const request = nativeFiringSoundRequest(type, level, { player: shooter === this.actors.length - 1 });
      if (request) this.voices.submit(request.voiceId, request.sample, request.replace);
    };
    if (type === 5) {
      applyNativeTurbo(body, level, this.config['game.ini'].bonus_data);
      this.voices?.turbo(shooter);
      this.onTurbo?.(shooter, level);
      requestFiringSound();
      owned.state = 1;
      owned.ageSeconds = 0;
      return { type: 'turbo', shooter, level };
    }
    const shot = this.shots.find(slot => slot.state === 1);
    if (!shot) throw new Error('Original main projectile pool exhausted');
    owned.state = 1;
    owned.ageSeconds = 0;
    // 0x455490 begins with FIRE_* before selecting the target/launch pose.
    requestFiringSound();
    const parameters = this.parameters[type][level - 1];
    const geometry = nativeBonusVisual(this.config, this.manifest, type, level, 'shot');
    let target = -2;
    if (parameters.homing && this.actors.length > 1) {
      if (typeof this.forwardDirection !== 'function') throw new TypeError('Original 0x415be0 facing adapter is required for homing');
      target = selectNativeProjectileTarget(shooter, this.actors.map(actor => actor.body),
        this.world.sectors.length, parameters.lockRange, this.forwardDirection(body));
    }
    Object.assign(shot, geometry, nativeProjectileLaunchPose(body, geometry.radius,
      this.groundHeight({ position: [...body.position], sector: body.sector })), {
      type, level, state: 2, ageSeconds: 0, shooter, target, sector: body.sector,
    });
    this.onProjectileState?.(shot, 2);
    this.arms.create(shot); // 0x456440 SetState(2), before bubble hatching.
    const spawned = [shot];
    if (parameters.count > 1) {
      spawned.push(...hatchNativeBubbles(shot, this.secondaryShots, parameters.count - 1, geometry));
    }
    return { type: 'fire', shooter, bonus: type, level, shots: spawned };
  }

  /** Apply after actor force preparation, before integration (0x4325b0). */
  prepareEffect(index, deltaSeconds) {
    const actor = this.actors[index], effect = this.effects[index];
    if (!effect?.active) return false;
    const body = actor.body;
    body.pitch ??= 0;
    body.roll ??= 0;
    const bubbleWasVisible = effect.bubbleVisible;
    const active = updateNativeHitEffect(effect, body, deltaSeconds, this.parameters[effect.type][effect.level - 1], {
      groundCount: actor.ground.groundCount ?? 0, rearWheelVerticalSpeed: actor.ground.wheels[2].verticalSpeed,
      sampleGround: (x, y, z) => this.groundHeight({ position: [x, y, z], sector: body.sector }),
      random: this.random,
    });
    // 412560 detaches the separate shell when its grounded/settled branch ends.
    if (bubbleWasVisible && !effect.bubbleVisible) this.onBubbleDetach?.(index);
    return active;
  }

  /** Call after static pickups: 0x451200 main shots, then 0x456350 secondary. */
  step(deltaSeconds, nowSeconds) {
    const events = [];
    const racers = this.actors.map(actor => ({
      position: actor.body.position, radius: actor.radius,
    }));
    for (const shot of [...this.shots, ...this.secondaryShots]) {
      const parameters = this.parameters[shot.type]?.[shot.level - 1];
      const result = advanceNativeProjectile(shot, deltaSeconds, parameters, racers, {
        groundHeight: this.groundHeight, rotationSpeed: this.rotationSpeed,
        invincibilitySeconds: this.invincibilitySeconds,
        onExplosion: body => this.onExplosion?.(body),
        onState: (shot, state) => this.onProjectileState?.(shot, state),
      });
      if (result && shot.state === 1) this.arms.remove(shot);
      if (!result) continue;
      if (result.type === 'hit') {
        const actor = this.actors[result.racer];
        const record = createNativeHitRecord(shot, actor.body, parameters, this.random);
        // NPC state9 ignores attacks. Player always accepts the shared handler.
        if (result.racer === this.actors.length - 1 || actor.phase !== 9) {
          const previousEffect = this.effects[result.racer];
          // 435aa0/40d310 call 4126b0 before copying a replacement hit state.
          const cleansPrevious = result.racer === this.actors.length - 1
            ? previousEffect?.active : actor.phase === 25;
          if (cleansPrevious && previousEffect?.bubbleVisible) {
            this.onBubbleDetach?.(result.racer);
            previousEffect.bubbleVisible = false;
          }
          // 0x40d310 calls 0x40f380 before copying/initializing the NPC hit.
          if (result.racer !== this.actors.length - 1 && actor.state) {
            actor.state.priorities = [1, 0, 2];
            markNativeNPCWeaponHit(actor.state, nowSeconds);
          }
          if (result.racer !== this.actors.length - 1) {
            // 0x40d260 precedes the effect initializer's spin-direction draw.
            this.voices?.npcHit(result.racer, record.shooter);
          }
          this.emitAnimation(result.racer, {
            callback: [null, 0x411830, 0x411b40, 0x411e50, 0x412090][record.type],
          });
          const effect = initializeNativeHitEffect(record, actor.body, parameters, this.random,
            { player: result.racer === this.actors.length - 1 });
          // 0x411830: spin/launch initialization, then 0x481ec0 on the
          // victim's engine body, then HIT_BY_ROCKET and the later AMHIT.
          if (record.type === 1) this.onExplosion?.(actor.body);
          this.effects[result.racer] = effect;
          effect.launchedWheelSpeeds.forEach((speed, wheel) => {
            if (speed !== null) actor.ground.wheels[wheel].verticalSpeed = speed;
          });
          if (this.voices && result.racer === this.actors.length - 1) {
            for (const request of nativePlayerHitSoundRequests(record.type, record.level))
              this.voices.submit(request.voiceId, request.sample, request.replace);
          }
          // 411b40 attaches after HIT_BY_SOAP/SOAP_UP and before the caller's
          // AMHIT request. NPCs take the same initializer without those sounds.
          if (record.type === 2) this.onBubbleAttach?.(result.racer);
          if (this.voices && result.racer === this.actors.length - 1) {
            // 0x435aa0 requests AMHIT after effect initialization.
            this.voices.playerHit();
          }
          actor.phase = 25;
        }
        if (this.voices && result.racer !== this.actors.length - 1
          && this.voices.isPlayer(shot.shooter)) this.voices.playerHitOther();
        // 0x455b00 invokes 0x40de60 only for an NPC hitting the player.
        if (result.racer === this.actors.length - 1 && shot.shooter >= 0
          && shot.shooter < this.actors.length - 1 && this.actors[shot.shooter].phase !== 9) {
          this.voices?.npcHitPlayer(shot.shooter, this.actors[shot.shooter].phase);
          this.emitAnimation(shot.shooter, {
            callback: 0x40de60, fsmState: this.actors[shot.shooter].phase,
          });
        }
        deactivateNativeProjectile(shot, (shot, state) => this.onProjectileState?.(shot, state));
        this.arms.remove(shot);
      }
      events.push({ ...result, shooter: shot.shooter, bonus: shot.type, level: shot.level, shot });
    }
    return events;
  }
}
