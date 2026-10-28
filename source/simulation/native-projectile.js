import { nativeTrigTable } from './native-integrator.js';
import { nativeRotationMatrix } from './native-transform.js';
import { nativeBonusOverlap } from './native-bonus.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f32 = Math.fround;

/**
 * Original 0x455490 launch pose, before bubble fan offsets. Products and the
 * ground+radius sum stay in x87 registers (0x4558d7, 0x4558e8, 0x455922);
 * each coordinate is stored as float (0x4558de, 0x455938, 0x4558f0).
 */
export function nativeProjectileLaunchPose(body, radius, groundHeight, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 24 ? f32 : Number;
  const { sin, cos } = nativeTrigTable(precision);
  const index = Math.trunc(body.yaw) & 4095;
  const position = [
    f32(body.position[0] - r(sin[index] * body.forwardSpeed)),
    f32(r(groundHeight + radius) + 10),
    f32(r(cos[index] * body.forwardSpeed) + body.position[2]),
  ];
  const angles = [body.pitch ?? 0, body.yaw, body.roll ?? 0];
  return { position, angles, matrix: nativeRotationMatrix(angles, { precision }),
    inheritedLateral: body.lateralSpeed, inheritedVertical: body.verticalSpeed,
    inheritedForward: body.forwardSpeed };
}

/**
 * 0x4560c0 uses the separate40-record BSS pool and a120-angle-unit spread.
 * extra*120 is stored (0x4560e4); its half stays in a register (0x4560f1)
 * before the stored yaw subtraction (0x4560fc). Every later yaw is stored.
 */
export function hatchNativeBubbles(shot, pool, extra, geometry = {}, { precision = NATIVE_PRECISION } = {}) {
  if (!extra) return [];
  const r = precision === 24 ? f32 : Number;
  shot.angles[1] = f32(shot.angles[1] - r(f32(extra * 120) * f32(0.5)));
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
 * `precision` selects the x87 precision-control width for register values;
 * float stores (FSTP/FST float ptr) round to float32 at either width.
 */
export function updateNativeProjectileFlight(shot, deltaSeconds, parameters, {
  groundHeight, targetPosition, rotationSpeed, onExplosion, onState, precision = NATIVE_PRECISION,
}) {
  const r = precision === 24 ? f32 : Number;
  const dt = f32(deltaSeconds);
  if (shot.ageSeconds >= parameters.lifetime) {
    deactivateNativeProjectile(shot, onState);
    return 'expired';
  }
  const speed = f32(parameters.speed + shot.inheritedForward); // FSTP 0x455d2f
  let dx, dz;
  if (shot.target === -2 || shot.level === 1) {
    const { sin, cos } = nativeTrigTable(precision);
    const index = Math.trunc(shot.angles[1]) & 4095;
    // 0x455fc0/0x455fc5 and 0x455fec/0x455fef keep both products in ST0.
    dx = -r(r(dt * sin[index]) * speed);
    dz = r(r(dt * cos[index]) * speed);
  } else {
    if (!targetPosition) throw new TypeError('The original selected target position is required');
    const divisor = parameters.lockRange + 1;
    // Differences (0x455dbb..) and quotients (0x455e08..) are stored; the
    // forward-row sums are not: x stays in ST1, y is stored (0x455e5e), and
    // z is stored by FST (0x455e69) while its register copy is squared.
    const [x, y, z] = targetPosition.map((value, axis) => (
      r(f32(f32(value - shot.position[axis]) / divisor) + shot.matrix[6 + axis])
    ));
    const storedY = f32(y), storedZ = f32(z);
    // 0x455e6d..0x455e81 accumulate z*z', y*y, x*x in registers; FSQRT
    // result is stored (0x455e83) and divides register x / stored y, z.
    const length = f32(r(Math.sqrt(r(r(r(z * storedZ) + r(storedY * storedY)) + r(x * x)))));
    const forward = [f32(r(x / length)), f32(storedY / length), f32(storedZ / length)];
    shot.matrix.splice(6, 3, ...forward);
    dx = r(r(dt * forward[0]) * speed);
    dz = r(r(dt * forward[2]) * speed);
  }
  // FILD*dt is a register value (0x455f0f/0x455f9a) before the stored add.
  shot.angles[2] = f32(r(rotationSpeed * dt) + shot.angles[2]);
  shot.position[0] = f32(shot.position[0] + dx);
  shot.position[2] = f32(shot.position[2] + dz);
  // 0x456004 adds clearance in ST0; 0x456012 stores after the +10.
  shot.position[1] = f32(r(groundHeight(shot) + shot.clearance) + 10);
  if (shot.type === 1 && shot.level === 3) return null;
  if (shot.heightInitialized) {
    // 0x45604b subtracts the FILD height in a register before FCOMP.
    if (r(shot.position[1] - shot.previousHeight) > 20) {
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
  shot.matrix = nativeRotationMatrix(shot.angles, { precision: options.precision });
  for (let racer = 0; racer < racers.length; racer++) {
    if ((racer !== shot.shooter || shot.ageSeconds > (options.invincibilitySeconds ?? f32(0.5)))
      && nativeBonusOverlap(shot, racers[racer], { precision: options.precision })) {
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

/**
 * 0x415be0 selects lane0, follows 0x404be0's links, then tests forward dot.
 * Differences, products and their sum all stay in registers (0x415c92..
 * 0x415cc3) until FCOMP against zero.
 */
export function nativeProjectileFacing(track, body, { british = 0, direction = 0, precision = NATIVE_PRECISION } = {}) {
  const r = precision === 24 ? f32 : Number;
  const side = (direction === 0 ? british === 1 : british !== 1) ? 0 : 1;
  const route = track.route[body.sector];
  const waypoint = (side === 0 ? route.driveLeftIndices : route.driveIndices)[0] ?? 0;
  const origin = track.drive[waypoint];
  // 0x404be0 truncates capped nativeDt (<=0.1) to0: +14, +1c, +18, self.
  const nextIndex = origin.links.slice(0, 3).find(index => index !== -1) ?? waypoint;
  const next = track.drive[nextIndex];
  const dx = r(next.position[0] - origin.position[0]);
  const dz = r(next.position[2] - origin.position[2]);
  return r(r(body.matrix[6] * dx) + r(body.matrix[8] * dz)) >= 0;
}
