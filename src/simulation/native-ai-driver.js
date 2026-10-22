import { prepareNativeNormalAI, prepareNativeChaseAI, prepareNativeForcedRouteAI,
  prepareNativeAIRecovery, prepareNativeAIFinished, nativeAIPlayerBehind,
  nativeAIStartChase, nativeAIStuck, updateNativeAITransition,
  nearestNativeAIWaypoint, updateNativeAIWheels, applyNativeAICatchup } from './native-ai.js';
import { nativeAIItemGuard, nativeAICatchupGuard, prepareNativeAIFireState,
  prepareNativeAICatchupState, resetNativeAIItemState, applyNativeAITrackTriggers } from './native-ai-items.js';
import { nativeStandardKartInertia } from './native-motion.js';
import { integrateNativeEuler, quantizeNativePlanarVelocity } from './native-integrator.js';
import { nativeRotationMatrix } from './native-transform.js';
import { applyNativeRailContact } from './native-collision.js';
import { createNativeGroundState, updateNativeGround } from './native-ground.js';
import { selectNativeSector, sampleNativeTrack } from './native-track.js';

const f32 = Math.fround;
const NO_FORCE = Object.freeze({ lateralForce: 0, verticalForce: 0, longitudinalForce: 0, torque: 0 });

/** 0x4944e0/0x494510 waypoint actor lists, capped at ten entries. */
export class NativeWaypointOccupancy {
  constructor(track) {
    this.track = track; this.nodes = new Map(); this.membership = new Map();
    // 0x40ed40 can leave output components untouched. Native caller stack
    // contents have no defined initial value; this adapter explicitly zeros
    // shared handler scratch and retains components the routine does not write.
    this.pathScratch = { steering: [0, 0, 0], speed: [0, 0, 0] };
  }
  remove(body) {
    const waypoint = this.membership.get(body);
    if (waypoint === undefined) return;
    const actors = this.nodes.get(waypoint);
    const index = actors.indexOf(body);
    if (index >= 0) actors.splice(index, 1);
    this.membership.delete(body);
  }
  insert(body, { side = -1 } = {}) {
    const waypoint = nearestNativeAIWaypoint(this.track, body, { side });
    if (waypoint < 0) return -1;
    let actors = this.nodes.get(waypoint);
    if (!actors) this.nodes.set(waypoint, actors = []);
    if (actors.length < 10) { actors.push(body); this.membership.set(body, waypoint); }
    body.waypoint = waypoint;
    return waypoint;
  }
}

/**
 * Connected racer movement and the active original FSM. Supply decision
 * context for automatic selection; isolated handler tests can omit selection.
 * Run prepare() for every actor, then integrate() in native object-list order.
 */
export class NativeAIDriver {
  constructor({ track, world, geometry, start, racer, playerRacer, random, groundClock,
    collision, occupancy, efficiency, id, carIndex = 1 }) {
    if (!collision || typeof collision.sweep !== 'function') throw new TypeError('NPC requires an explicit native collision sweep');
    if (!random || !groundClock || !occupancy) throw new TypeError('NPC requires shared random, ground clock and waypoint occupancy');
    if (!Number.isFinite(efficiency)) throw new TypeError('Original NPC efficiency setting is required');
    Object.assign(this, { track, world, racer, playerRacer, random, groundClock, collision, occupancy, efficiency });
    this.body = {
      ...nativeStandardKartInertia(carIndex), id,
      position: start.position.map(f32), yaw: f32(start.yaw), pitch: 0, roll: 0,
      matrix: nativeRotationMatrix([0, start.yaw, 0]), sector: start.sector, previousSector: start.sector,
      lateralSpeed: 0, verticalSpeed: 0, forwardSpeed: 0,
      yawRate: 0, pitchRate: 0, rollRate: 0,
      get x() { return this.position[0]; }, set x(value) { this.position[0] = value; },
      get y() { return this.position[1]; }, set y(value) { this.position[1] = value; },
      get z() { return this.position[2]; }, set z(value) { this.position[2] = value; },
    };
    this.controls = { steering: 0, throttle: 0, brake: 0 };
    this.state = {
      mode: 0, gear: 0, reverseLatch: false, disabled: false,
      turnTime: 0, turnIntegral: 0, turnStartHeading: 0, special: false, specialTime: 0,
      priorities: [0, 1, 2], waypoint: start.waypoint, previousSector: start.sector, sectorTime: 0,
      chaseTime: 0, targetId: -1, blockRecovery: false, recoveryTime: 0,
      lastRecoveryTime: 0, recoveryCounter: 0, forcedRoute: false,
      reactionMode: -1, reactionDeadline: 0, lastBonusTime: 0,
      lastRank: -1, rankTime: 0, finished: false, slippery: false,
      laps: 0, finishMarker: 0, lastFinishTime: 0, speedLimit: 0,
      turboVisible: false, turboTime: 0,
    };
    this.ground = { wheels: geometry.wheelOffsets.map((local, i) => ({
      local: local.map(f32), radius: i < 2 ? geometry.frontRadius : geometry.rearRadius,
      spin: 0, steeringAngle: 0, verticalSpeed: 0,
    })) };
    this.occupancy.insert(this.body);
    this.groundInitialized = false;
    // Event callbacks can run after rendering (pickup/projectile controller).
    // They remain pending until the next driver visual callback consumes them.
    this.animationEvents = [];
    this.animationTurbo = { turboActive: false, turboStartedSeconds: 0, nowSeconds: 0 };
    this.updates = 0;
  }

  sampleGround = (x, y, z) => sampleNativeTrack(this.world, this.body.sector, x, y, z).height;
  sampleRouteHeight = (x, y, z) => {
    const sector = selectNativeSector(this.world, this.body.sector, x, z);
    const plane = this.world.sectors[sector].fallback;
    return f32(f32(f32(plane.distance - f32(x * plane.normal[0])) - f32(z * plane.normal[2])) / plane.normal[1]);
  };

  get phase() { return this.state.mode; }
  set phase(value) { this.state.mode = value; }

  /** 0x4024d0 runs before state dispatch and uses the pre-update race ranks. */
  decide(dt, context) {
    const { player, racers, rank, playerRank, time, owned, shared,
      reactionMs, catchupMs, playerProtected, itemRank } = context;
    if (!player || !racers || !owned || !shared || !Number.isInteger(rank)
      || !Number.isInteger(playerRank) || !Number.isFinite(time)) {
      throw new TypeError('Complete original NPC decision context is required');
    }
    return updateNativeAITransition(this.state, {
      '402040': () => nativeAIStuck(this.state),
      '401570': () => nativeAIPlayerBehind(this.body, this.state, player, rank),
      '4016e0': () => nativeAIStartChase(this.body, this.state, rank, dt, this.random),
      '40ca90': () => !this.state.forcedRoute,
      '40cd00': () => false, // Empty original condition.
      '40cd30': () => false, // Computes an unused scan limit; always returns0.
      '40cde0': () => {
        if (owned.state === 2 && [1, 2].includes(owned.type) && !Number.isInteger(itemRank)) {
          throw new TypeError('Native shooter rank uses its object index and must be supplied explicitly');
        }
        return nativeAIItemGuard(this.track, this.body, this.state, owned, {
          player, racers, rank: itemRank ?? rank, now: time, shared, reactionMs, playerProtected,
        });
      },
      '40d070': () => {
        const mode = this.state.mode;
        const result = nativeAICatchupGuard(this.state, {
          rank, playerRank, catchupMs, now: time, reactionMs,
        });
        if (result) this.voices?.npcCatchup({
          racer: this.body.id, mode, activated: result.announce,
          sector: this.body.sector, playerSector: player.sector,
          sectorCount: this.track.sectorCount,
        });
        return Boolean(result);
      },
    });
  }

  /** 0x40b0b0 -> selector ->0x406940; no normal-driving substitute for other states. */
  prepare(deltaSeconds, { difficulty, progressDifference, active = true, slippery = false, effect, decision,
    playerGlobals = {} } = {}) {
    if (!Number.isFinite(deltaSeconds) || deltaSeconds <= 0) throw new RangeError('NPC requires a positive finite update interval');
    if (this.prepared) throw new Error('Integrate the prepared native frame before preparing another');
    this.events = [];
    // 0x40b0b0 selects transitions before 0x406940 checks the movement gate.
    // NPCs can change mode during the countdown, while movement remains idle.
    if (decision && (active || decision.player)) this.decide(deltaSeconds, decision);
    if (active) {
      if (!Number.isInteger(progressDifference) || ![0, 1, 2].includes(difficulty)) {
        throw new TypeError('Native catch-up requires difficulty and integer progress difference');
      }
      const normal = () => {
        this.path = prepareNativeNormalAI(this.track, this.body, this.controls, this.state,
          this.racer, this.playerRacer, deltaSeconds, this.random, {
            occupancy: this.occupancy.nodes, efficiency: this.efficiency,
            pathScratch: this.occupancy.pathScratch,
            ...playerGlobals,
          });
      };
      if (this.state.mode === 0) normal();
      else if ([1, 2, 3].includes(this.state.mode)) {
        this.path = prepareNativeChaseAI(this.track, this.body, this.controls, this.state,
          this.racer, this.playerRacer, deltaSeconds, this.random, {
            occupancy: this.occupancy.nodes, player: decision?.player,
            pathScratch: this.occupancy.pathScratch,
            ...playerGlobals,
          });
      } else if (this.state.mode === 9) {
        prepareNativeAIFinished(this.body, this.controls, this.state, this.racer, this.playerRacer,
          deltaSeconds, this.random, { sampleRouteHeight: this.sampleRouteHeight, ...playerGlobals });
      } else if (this.state.mode === 10) {
        prepareNativeAIRecovery(this.body, this.controls, this.state, deltaSeconds, this.random, {
          time: decision?.time, sampleRouteHeight: this.sampleRouteHeight,
          respawn: decision?.rescue,
        });
      } else if ([24, 25].includes(this.state.mode)) {
        // 0x40e6d0 replaces normal driving while the native hit effect is active.
        if (typeof effect !== 'function') throw new TypeError('NPC hit state requires the original effect callback');
        if (!effect()) {
          resetNativeAIItemState(this.state);
          this.state.hitVisible = false;
        }
      } else if (this.state.mode === 26) {
        if (typeof decision?.fire !== 'function') throw new TypeError('Native item firing callback is required');
        const event = prepareNativeAIFireState(this.state, decision.fire, normal);
        if (event) this.events.push(event);
      } else if (this.state.mode === 27) {
        this.path = prepareNativeForcedRouteAI(this.track, this.body, this.controls, this.state,
          this.racer, this.playerRacer, deltaSeconds, this.random, { efficiency: this.efficiency, ...playerGlobals });
      } else if (this.state.mode === 28) {
        prepareNativeAICatchupState(this.state, deltaSeconds,
          { now: decision?.time, durationMs: decision?.catchupDurationMs }, normal);
      } else throw new Error(`Native NPC state ${this.state.mode} needs its original handler`);
      // 0x409530 observes the old sector before the engine integrates.
      if (this.body.sector === this.state.previousSector) this.state.sectorTime = f32(this.state.sectorTime + f32(deltaSeconds));
      else { this.state.previousSector = this.body.sector; this.state.sectorTime = 0; }
      if (decision?.triggers) {
        const triggers = applyNativeAITrackTriggers(this.track, this.body, this.state, {
          ...decision.triggers, now: decision.time, previousEngineSector: this.body.previousSector,
        });
        this.events.push(...triggers);
        for (const event of triggers) if (event.type === 'turbo') {
          this.animationEvents.push({ callback: 0x40dc10, fsmState: this.state.mode });
        }
      }
      if (this.state.mode !== 10) applyNativeAICatchup(this.body, this.state, difficulty, progressDifference);
    }
    // 0x40b0b0 calls 0x40e760 after state dispatch. Preserve that call's
    // pre-expiry flag for this visual frame, then perform its native flag clear.
    const now = f32(decision?.time ?? this.animationTurbo.nowSeconds);
    this.animationTurbo = {
      turboActive: this.state.turboVisible,
      turboStartedSeconds: this.state.turboTime,
      nowSeconds: now,
    };
    if (this.state.turboVisible && f32(now - this.state.turboTime) >= 5) {
      this.state.turboVisible = false;
    }
    // 0x40ea50 is a separate one-second material-flash flag, not the lifetime
    // of the hit effect or its queued mesh animation.
    if (this.state.hitVisible && f32(now - this.state.hitTime) >= 1) this.state.hitVisible = false;
    const slipperyWaypoint = this.track.drive[this.body.waypoint]?.unknown[1] === 68;
    if (slippery || this.state.slippery || slipperyWaypoint) {
      for (const key of ['lateralSpeed', 'verticalSpeed', 'forwardSpeed']) this.body[key] = f32(this.body[key] * f32(.98));
    }
    // NPC 0x41c4b0 uses the route's derived plane, before the triangle ground callback.
    const plane = this.world.sectors[this.body.sector].fallback;
    const height = f32(f32(f32(plane.distance - f32(this.body.x * plane.normal[0])) -
      f32(this.body.z * plane.normal[2])) / plane.normal[1]);
    updateNativeAIWheels(this.body, this.ground, deltaSeconds, height);
    this.prepared = { deltaSeconds };
    return this.path;
  }

  /** Flags3 NPCs use one Euler step and skip the player's sliding second sweep. */
  integrate() {
    if (!this.prepared) throw new Error('Prepare the native frame before integrating');
    const { deltaSeconds } = this.prepared, body = this.body;
    quantizeNativePlanarVelocity(body);
    this.occupancy.remove(body);
    const collision = this.collision.sweep(body, deltaSeconds);
    integrateNativeEuler(body, NO_FORCE, deltaSeconds, collision ?? {});
    body.matrix = nativeRotationMatrix([body.pitch, body.yaw, body.roll]);
    if (collision?.contact) {
      if (this.collision.resolve) this.collision.resolve(body, collision.contact);
      else applyNativeRailContact(body, collision.contact);
    }
    this.collision.finishStep?.(body, collision?.contact);
    body.previousSector = body.sector;
    body.sector = selectNativeSector(this.world, body.sector, body.x, body.z);
    this.occupancy.insert(body);
    if (!this.groundInitialized) {
      const initial = createNativeGroundState(body, this.ground.wheels);
      initial.wheels.forEach((wheel, i) => { this.ground.wheels[i].position = wheel.position; });
      this.groundInitialized = true;
    }
    updateNativeGround(body, this.ground, deltaSeconds, this.sampleGround, { clock: this.groundClock, player: false });
    this.prepared = null;
    this.updates++;
    return this.snapshot();
  }

  snapshot() {
    return {
      id: this.body.id, position: [...this.body.position], yaw: this.body.yaw, matrix: [...this.body.matrix],
      lateralSpeed: this.body.lateralSpeed, forwardSpeed: this.body.forwardSpeed, yawRate: this.body.yawRate,
      sector: this.body.sector, waypoint: this.body.waypoint, gear: this.state.gear, mode: this.state.mode,
      controls: { ...this.controls }, groundCount: this.ground.groundCount ?? 0,
      wheels: this.ground.wheels.map(wheel => ({ ...wheel, local: [...wheel.local], position: wheel.position && [...wheel.position] })),
      updates: this.updates,
    };
  }
}
