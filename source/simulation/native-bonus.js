import { NativeRandom } from './native-random.js';
import { nativePickupSoundRequest } from '../bonus-audio.js';
import { nativeTrigTable, NATIVE_ANGLE_COUNT } from './native-integrator.js';
export { NativeRandom };
const f32 = Math.fround;

export const NATIVE_BONUS_TYPES = Object.freeze({
  rocket: 1, bubble: 2, oil: 3, gum: 4, turbo: 5, star: 6, random: 7,
});

/** 0x453780. Runs for every owned slot, including hidden/inactive slots. */
export function updateNativeOwnedBonusVisual(owned, deltaSeconds, rotationSpeed, precision = 24) {
  const r = precision === 24 ? f32 : Number;
  owned.angles ??= [0, 0, 0];
  owned.angles[1] = f32(r(r(rotationSpeed * f32(deltaSeconds)) + owned.angles[1]));
  // The original writes the cosine value itself into the pitch-angle field.
  owned.angles[0] = nativeTrigTable(precision).cos[NATIVE_ANGLE_COUNT / 8];
  return owned;
}

/** Original static race-type constructors 0x42a8f0..0x42a9e0. */
export function nativeEnabledBonuses(raceType) {
  if (raceType === 1) return new Set();
  return new Set([1, 2, 3, 4, 5, 7, ...([2, 5].includes(raceType) ? [6] : [])]);
}

/** Original OMP type switch, 0x451f80. Visual names do not select behavior. */
export function nativeBonusTypeFromObject(type) {
  return ({ 29: 1, 30: 2, 32: 3, 33: 4, 35: 5, 36: 5, 41: 7, 42: 6 })[type] ?? 0;
}

/** Only the bonus placement branch; other OMP visibility rules stay separate. */
export function isNativeBonusPlacementVisible(placement, raceType) {
  if (placement.type < 29 || placement.type > 42) return true;
  return nativeEnabledBonuses(raceType).has(nativeBonusTypeFromObject(placement.type));
}

/** 0x4d2744/0x4500e0. Placement, owned and shot constructors use offsets 0,1,4. */
export function nativeBonusVisual(config, manifest, type, level = 1, kind = 'pickup') {
  const sequence = ['kogel0', 'kogel0', 'kogel1', 'dropper0', 'dropper1', 'turbo0', 'star', 'bonus0'][type];
  const offset = { pickup: 0, owned: 1, shot: 4 }[kind];
  if (!sequence || offset === undefined || level < 1 || level > 3) throw new RangeError('Invalid native bonus visual');
  const frame = level + offset - 1;
  const [mesh, texture] = config['gen_anim.ini'][sequence][frame].split(',').map(value => value.trim().toLowerCase());
  const radius = manifest.meshes[mesh]?.horizontalRadius;
  if (!Number.isFinite(radius)) throw new TypeError(`Missing original collision radius for ${mesh}`);
  return { sequence, frame, mesh, texture, radius };
}

/** 0x43e140/0x451f80/0x44fb00 preserve OMP positions without a height offset. */
export function nativeTrackPickups(track, manifest, config) {
  return track.placements.flatMap((placement, placementIndex) => {
    const type = nativeBonusTypeFromObject(placement.type);
    if (!type) return [];
    const yaw = f32((placement.nativeRotationDegrees?.[1] ?? 0) * (4096 / 360));
    if (config) return [{ type, placementIndex, position: [...placement.position], yaw,
      ...nativeBonusVisual(config, manifest, type) }];
    const definition = track.objectDefinitions[placement.animation.toLowerCase()];
    const mesh = definition.mesh.toLowerCase();
    const radius = manifest.meshes[mesh]?.horizontalRadius;
    if (!Number.isFinite(radius)) throw new TypeError(`Missing original collision radius for ${mesh}`);
    return [{ type, placementIndex, position: [...placement.position], radius, mesh, yaw }];
  });
}

/** 0x410650 uses strict greater-than, so exactly the deadline is ineligible. */
export function nativeCanCollectBonus(nowSeconds, eligibleAfterSeconds) {
  return f32(nowSeconds) > f32(eligibleAfterSeconds);
}

/** Original CRT defaults 0x455190 followed by loader 0x451810's exact setters. */
export function nativeBonusParameters(config) {
  const value = key => Number(config[key]);
  const seconds = key => f32(value(key) * f32(0.001));
  const factor = key => f32(value(key) * f32(0.01));
  const result = {};
  for (let type = 1; type <= 4; type++) {
    result[type] = Array.from({ length: 3 }, (_, index) => ({
      duration: 15, lifetime: 15, homing: type === 1 && index > 0,
      lockRange: 0, speed: 100, firstSpeedFactor: 1, restoredSpeedFactor: 1,
      count: type === 2 ? [1, 3, 5][index] : 1,
    }));
  }
  for (let level = 0; level < 3; level++) {
    result[1][level].speed = value('bullet0_speed');
    result[2][level].speed = value('bullet1_speed');
    result[2][level].lifetime = seconds(`bullet${level}_lifetime`);
    result[1][level].lockRange = value(`weapon${level}_lock_range`);
    for (const [type, key] of [[1, 'rocket_turn'], [2, 'bubble_fly'], [3, 'oil_turn'], [4, 'gum_stick']]) {
      result[type][level].duration = seconds(`${key}_time${level}`);
    }
    result[2][level].restoredSpeedFactor = factor(`bubble_speed_factor${level}`);
    result[3][level].restoredSpeedFactor = factor(`oil_speed_factor${level}`);
  }
  // The native loader assigns BULLET3_LIFETIME only to rocket level2.
  result[1][1].lifetime = seconds('bullet3_lifetime');
  result[4][0].firstSpeedFactor = factor('gum_speedfactor00');
  result[4][1].firstSpeedFactor = factor('gum_speedfactor10');
  result[4][1].restoredSpeedFactor = factor('gum_speedfactor11');
  result[4][2].firstSpeedFactor = factor('gum_speedfactor20');
  result[4][2].restoredSpeedFactor = factor('gum_speedfactor21');
  return result;
}

/** CBonusController::PickUp, 0x4514e0; spatial eligibility is a separate query. */
export function collectNativeBonus(pickup, owned, controller, {
  player, random, maxLevel = 3, beforeCollect, afterInventory,
}) {
  if (pickup.state !== 2) throw new Error('Native pickup requires an active bonus point');
  // 0x4514e0 calls0x4106b0 BEFORE random-type and NPC extra-level draws.
  beforeCollect?.();
  let type = pickup.type;
  if (type === 7) type = random.next() % 5 + 1;
  const increase = () => { owned.level = Math.min(maxLevel, owned.level + 1); };
  if (type === 6) {
    controller.stars++;
    // Native stars call the NPC pickup callback even for the player index.
    afterInventory?.({callback: 0x40d610, type});
    pickup.state = 1;
    pickup.ageSeconds = 0;
    return { type: 'star', stars: controller.stars };
  }
  if (owned.state !== 1 && owned.type === type) {
    increase();
  } else {
    owned.type = type;
    owned.level = pickup.level;
    owned.state = pickup.state;
  }
  afterInventory?.({callback: player ? 0x4362f0 : 0x40d610, type});
  // The original AI gets one extra level, and another on an odd RNG result.
  if (!player) {
    increase();
    if (random.next() % 2 !== 0) increase();
  }
  pickup.state = 1;
  pickup.ageSeconds = 0;
  owned.state = 2;
  owned.ageSeconds = 0;
  return { type: 'bonus', bonus: owned.type, level: owned.level };
}

/** 0x453fd0/0x454260. The native active count includes owned and shot bonuses. */
export function advanceNativePickup(pickup, deltaSeconds, {
  respawnSeconds, enabled, activeBonusCount,
}) {
  pickup.ageSeconds = f32(f32(deltaSeconds) + pickup.ageSeconds);
  if (pickup.state === 1 && pickup.type !== 6 && pickup.ageSeconds >= respawnSeconds
    && enabled && activeBonusCount < 40) {
    // Respawning calls CBonusData::SetState directly, retaining elapsed age.
    pickup.state = 2;
    return true;
  }
  return false;
}

/** 0x497bd0 followed by 0x44fc80; both comparisons are strict. */
export function nativeBonusOverlap(a, b) {
  const dx = f32(a.position[0] - b.position[0]);
  const dz = f32(a.position[2] - b.position[2]);
  const radius = f32(a.radius + b.radius);
  if (f32(f32(dx * dx) + f32(dz * dz)) >= f32(radius * radius)) return false;
  return Math.abs(f32(a.position[1] - b.position[1])) < radius;
}

/** 0x4537f0 boosts existing signed forward speed once; it is not timed thrust. */
export function applyNativeTurbo(body, level, bonusConfig) {
  if (!Number.isInteger(level) || level < 1 || level > 3) throw new RangeError('Turbo level must be 1..3');
  const factor = Number(bonusConfig[`bonus_turbo_factor${level - 1}`]);
  body.forwardSpeed = f32(f32(factor * f32(0.01)) * body.forwardSpeed);
  return body.forwardSpeed;
}

/**
 * Static pickup portion of CBonusController. Racers are in native order:
 * opponents first, player last. Caller supplies original model collision radii
 * and any active projectiles for the shared forty-active-bonus respawn limit.
 */
export class NativeBonusPickups {
  constructor({ pickups, racerCount, raceType, bonusConfig, random, voices = null }) {
    if (!(random instanceof NativeRandom)) throw new TypeError('The shared native RNG is required');
    this.random = random;
    this.voices = voices;
    this.config = bonusConfig;
    this.enabledTypes = nativeEnabledBonuses(raceType);
    this.stars = 0;
    this.pickups = pickups.map(pickup => {
      if (!Number.isFinite(pickup.radius)) throw new TypeError('Original pickup collision radius is required');
      return {
        ...pickup, position: pickup.position.map(f32), yaw: f32(pickup.yaw ?? 0),
        state: this.enabledTypes.has(pickup.type) ? 2 : 1, level: 1, ageSeconds: 0,
      };
    });
    this.owned = Array.from({ length: racerCount }, () => ({
      type: 0, state: 1, level: 0, ageSeconds: 0, angles: [0, 0, 0],
    }));
    this.eligibleAfter = Array(racerCount).fill(0);
  }

  activeCount(projectileCount = 0) {
    // Called at each pickup's native update point, so recount current state
    // without allocating filtered arrays or caching across collection callbacks.
    let pickups=0,owned=0;
    for(const pickup of this.pickups)if(pickup.state===2)pickups++;
    for(const bonus of this.owned)if(bonus.state===2)owned++;
    return projectileCount+pickups+owned;
  }

  step(deltaSeconds, nowSeconds, racers, { activeProjectileCount = 0 } = {}) {
    if (racers.length !== this.owned.length) throw new RangeError('Racer count must preserve native order');
    const events = [];
    const playerIndex = racers.length - 1;
    const cooldown = f32(Number(this.config.bonus_timeout_pickup_next) * f32(0.001));
    const respawnSeconds = f32(Number(this.config.bonus_respawn_time) * f32(0.001));
    for (const owned of this.owned) {
      updateNativeOwnedBonusVisual(owned, deltaSeconds, Number(this.config.weapon_rotation_speed));
    }
    for (let index = 0; index < this.pickups.length; index++) {
      const pickup = this.pickups[index];
      const wasActive = pickup.state === 2;
      const respawned = advanceNativePickup(pickup, deltaSeconds, {
        respawnSeconds, enabled: this.enabledTypes.has(pickup.type),
        activeBonusCount: this.activeCount(activeProjectileCount),
      });
      if (respawned) events.push({ type: 'respawn', pickup: index });
      // An inactive point that respawns is not tested for contact until next update.
      if (!wasActive) continue;
      pickup.yaw = f32(f32(Number(this.config.weapon_rotation_speed) * f32(deltaSeconds)) + pickup.yaw);
      for (let racer = pickup.type === 6 ? playerIndex : 0; racer <= playerIndex; racer++) {
        if(racers[racer].canCollect===false||racers[racer].excludedPickups?.has(index))continue;
        if (!nativeCanCollectBonus(nowSeconds, this.eligibleAfter[racer])
          || !nativeBonusOverlap(racers[racer], pickup)) continue;
        // 0x4514e0 passes the loop index to 0x4106b0, which only arms the
        // player's own +0x100 deadline for index -1. The player's index N lands
        // in an unread opponent slot, so only opponents wait for the cooldown.
        if (racer !== playerIndex) this.eligibleAfter[racer] = f32(f32(nowSeconds) + cooldown);
        const result = collectNativeBonus(pickup, this.owned[racer], this, {
          player: racer === playerIndex, random: this.random,
          maxLevel: Number(this.config.max_bonus_level),
          beforeCollect: () => this.voices?.pickupBefore(racer),
          afterInventory: event => this.onAnimationEvent?.(racer, event),
        });
        if (this.voices && racer === playerIndex) {
          // 0x4540c0 retains the STATIC type, then requests a second BONUS line.
          const request = nativePickupSoundRequest(pickup.type);
          this.voices.submit(request.voiceId, request.sample, request.replace);
          this.voices.pickupAfter(racer);
        }
        events.push({ ...result, pickup: index, racer });
        break;
      }
    }
    return events;
  }
}
