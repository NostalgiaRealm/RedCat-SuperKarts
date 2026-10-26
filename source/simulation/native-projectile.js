import { nativeTrigTable } from './native-integrator.js';
import { nativeRotationMatrix } from './native-transform.js';
import { nativeBonusOverlap } from './native-bonus.js';

const f32 = Math.fround;

/** Original 0x455490 launch pose, before bubble fan offsets. */
export function nativeProjectileLaunchPose(body, radius, groundHeight) {
  const { sin, cos } = nativeTrigTable();
  const index = Math.trunc(body.yaw) & 4095;
  const position = [
    f32(body.position[0] - f32(sin[index] * body.forwardSpeed)),
    f32(f32(groundHeight + radius) + 10),
    f32(f32(cos[index] * body.forwardSpeed) + body.position[2]),
  ];
  const angles = [body.pitch ?? 0, body.yaw, body.roll ?? 0];
  return { position, angles, matrix: nativeRotationMatrix(angles),
    inheritedLateral: body.lateralSpeed, inheritedVertical: body.verticalSpeed,
    inheritedForward: body.forwardSpeed };
}

/** 0x4560c0 uses the separate40-record BSS pool and a120-angle-unit spread. */
export function hatchNativeBubbles(shot, pool, extra, geometry = {}) {
  if (!extra) return [];
  shot.angles[1] = f32(shot.angles[1] - f32(f32(extra * 120) * f32(0.5)));
  let yaw = f32(shot.angles[1] + 120);
  const spawned = [];
  for (const child of pool) {
    if (spawned.length === extra) break;
    if (child.state !== 1) continue;
    Object.assign(child, geometry, { type: shot.type, level: shot.level, state: 2, ageSeconds: 0,
      shooter: shot.shooter, target: -2, position: [...shot.position], sector: shot.sector,
      inheritedLateral: shot.inheritedLateral, inheritedVertical: shot.inheritedVertical,
      inheritedForward: shot.inheritedForward });
    // Native changes only yaw; reused secondary slots retain pitch/roll.
    child.angles[1] = yaw;
    yaw = f32(yaw + 120);
    spawned.push(child);
  }
  if (spawned.length < extra) throw new Error('Original secondary bubble pool exhausted');
  return spawned;
}

/** Player input 0x433870 uses unsigned wall-clock subtraction and held input. */
export class NativeFireGate {
  constructor(lastFireMs = 0) { this.lastFireMs = lastFireMs >>> 0; }
  poll(held, nowMs) {
    const now = nowMs >>> 0;
    if (!held || ((now - this.lastFireMs) >>> 0) <= 500) return false;
    this.lastFireMs = now;
    return true;
  }
}

/** Gameplay portion of CShotBonus::SetState(1), 0x456440/0x44fa70. */
export function deactivateNativeProjectile(shot, onState) {
  // 0x456440 removes streams and the homing arm before0x44fa70 stores state1.
  onState?.(shot, 1);
  shot.state = 1;
  shot.ageSeconds = 0;
  shot.heightInitialized = false;
}

/**
 * 0x455ce0. Caller has already advanced age (0x455a10). Matrix is the
 * native row-vector 3x3 render matrix, not a normalized movement heading.
 */
export function updateNativeProjectileFlight(shot, deltaSeconds, parameters, {
  groundHeight, targetPosition, rotationSpeed, onExplosion, onState,
}) {
  const dt = f32(deltaSeconds);
  if (shot.ageSeconds >= parameters.lifetime) {
    deactivateNativeProjectile(shot, onState);
    return 'expired';
  }
  const speed = f32(parameters.speed + shot.inheritedForward);
  let dx, dz;
  if (shot.target === -2 || shot.level === 1) {
    const { sin, cos } = nativeTrigTable();
    const index = Math.trunc(shot.angles[1]) & 4095;
    dx = f32(-f32(f32(dt * sin[index]) * speed));
    dz = f32(f32(dt * cos[index]) * speed);
  } else {
    if (!targetPosition) throw new TypeError('The original selected target position is required');
    const divisor = parameters.lockRange + 1;
    const weighted = targetPosition.map((value, axis) => (
      f32(f32(f32(value - shot.position[axis]) / divisor) + shot.matrix[6 + axis])
    ));
    const [x, y, z] = weighted;
    const length = f32(Math.sqrt(f32(f32(f32(z * z) + f32(y * y)) + f32(x * x))));
    const forward = weighted.map(value => f32(value / length));
    shot.matrix.splice(6, 3, ...forward);
    dx = f32(f32(dt * forward[0]) * speed);
    dz = f32(f32(dt * forward[2]) * speed);
  }
  shot.angles[2] = f32(f32(rotationSpeed * dt) + shot.angles[2]);
  shot.position[0] = f32(shot.position[0] + dx);
  shot.position[2] = f32(shot.position[2] + dz);
  shot.position[1] = f32(f32(groundHeight(shot) + shot.clearance) + 10);
  if (shot.type === 1 && shot.level === 3) return null;
  if (shot.heightInitialized) {
    if (f32(shot.position[1] - shot.previousHeight) > 20) {
      // 0x455ce0 calls 0x481ec0 with this shot's engine body before SetState(1).
      onExplosion?.(shot);
      deactivateNativeProjectile(shot, onState);
      return 'height-impact';
    }
  } else {
    // The native routine stores the first height only; it never follows slopes.
    shot.previousHeight = Math.trunc(shot.position[1]);
    shot.heightInitialized = true;
  }
  return null;
}

/** 0x455a10: state update, matrix rebuild, then first intersecting racer. */
export function advanceNativeProjectile(shot, deltaSeconds, parameters, racers, options) {
  shot.ageSeconds = f32(shot.ageSeconds + f32(deltaSeconds));
  if (shot.state === 1) return null;
  let endReason = null;
  if (shot.type === 3 || shot.type === 4) {
    shot.position[1] = f32(options.groundHeight(shot));
  } else {
    endReason = updateNativeProjectileFlight(shot, deltaSeconds, parameters, {
      ...options, targetPosition: racers[shot.target]?.position,
    });
  }
  // The caller rebuilds from stored angles even after homing changed forward.
  shot.matrix = nativeRotationMatrix(shot.angles);
  for (let racer = 0; racer < racers.length; racer++) {
    if ((racer !== shot.shooter || shot.ageSeconds > (options.invincibilitySeconds ?? f32(0.5)))
      && nativeBonusOverlap(shot, racers[racer])) {
      return { type: 'hit', racer, endReason };
    }
  }
  // Native still performs contact tests after a flight step deactivates a shot.
  return endReason ? { type: endReason } : null;
}

/** 0x4561e0: route distance target selection; direction comes from 0x415be0. */
export function selectNativeProjectileTarget(shooter, racers, sectorCount, lockRange, forward) {
  let selected = -2;
  let bestDistance = 0x7fffffff;
  for (let index = 0; index < racers.length; index++) {
    let distance = forward ? racers[index].sector - racers[shooter].sector
      : racers[shooter].sector - racers[index].sector;
    if (distance < 0) distance += sectorCount;
    if (distance > 1 && index !== shooter && distance < bestDistance) {
      selected = index;
      bestDistance = distance;
    }
  }
  return bestDistance <= lockRange || lockRange < 2 ? selected : -2;
}

/** 0x415be0 selects lane0, follows 0x404be0's links, then tests forward dot. */
export function nativeProjectileFacing(track, body, { british = 0, direction = 0 } = {}) {
  const side = (direction === 0 ? british === 1 : british !== 1) ? 0 : 1;
  const route = track.route[body.sector];
  const waypoint = (side === 0 ? route.driveLeftIndices : route.driveIndices)[0] ?? 0;
  const origin = track.drive[waypoint];
  // 0x404be0 truncates capped nativeDt (<=0.1) to0: +14, +1c, +18, self.
  const nextIndex = origin.links.slice(0, 3).find(index => index !== -1) ?? waypoint;
  const next = track.drive[nextIndex];
  const dx = f32(next.position[0] - origin.position[0]);
  const dz = f32(next.position[2] - origin.position[2]);
  return f32(f32(body.matrix[6] * dx) + f32(body.matrix[8] * dz)) >= 0;
}
