import { nativeYawTrig } from './native-ground.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f32 = Math.fround;

/** 0x40c820 + 0x455b00 capture the victim at contact, consuming shared CRT RNG. */
export function createNativeHitRecord(shot, body, parameters, random) {
  const originalVelocity = [body.lateralSpeed, body.verticalSpeed, body.forwardSpeed];
  return {
    shooter: shot.shooter, type: shot.type, level: shot.level, mode: random.next() % 7,
    originalVelocity,
    restoredVelocity: originalVelocity.map(value => f32(value * parameters.restoredSpeedFactor)),
    originalAngles: [body.pitch ?? 0, body.yaw, body.roll ?? 0],
  };
}

/**
 * Shared 0x411830/0x411b40/0x411e50/0x412090 gameplay initialization.
 * Precision-independent: the gum speed is one float product stored at once
 * (0x412165 FMUL, 0x412169 FSTP), and the duration is a float copy.
 */
export function initializeNativeHitEffect(record, body, parameters, random, { player = false } = {}) {
  const effect = { ...structuredClone(record), phase: 1, remaining: parameters.duration,
    active: true, bubbleVisible: false, launchedWheelSpeeds: [null, null, null, null] };
  const multiplier = player ? 2 : 1;
  if (record.type === 1 || record.type === 3) {
    effect.mode = random.next() % 2 === 0 ? 1 : 0;
    if (record.type === 1) {
      effect.launchedWheelSpeeds[2] = effect.launchedWheelSpeeds[3] = (record.level * 6 + 60) * multiplier;
    }
  } else if (record.type === 2) {
    effect.mode = 6;
    effect.bubbleVisible = true;
    if (record.level > 1) effect.launchedWheelSpeeds.fill((record.level * 10 + 100) * multiplier);
  } else if (record.type === 4) {
    body.forwardSpeed = f32(parameters.firstSpeedFactor * record.originalVelocity[2]);
    effect.mode = 4;
    effect.launchedWheelSpeeds[2] = effect.launchedWheelSpeeds[3] = (record.level * 6 + 60) * multiplier;
  } else {
    throw new RangeError('Native hit effects require rocket, bubble, oil or gum');
  }
  return effect;
}

/** 0x412330, used for spin termination. Only forward speed is restored. */
function finishSpin(effect, body) {
  body.yawRate = 0;
  body.forwardSpeed = effect.restoredVelocity[2];
  effect.remaining = 0;
  return false;
}

/** 0x412390; deliberately compares unwrapped stored angles. */
export function updateNativeSpinEffect(effect, body, deltaSeconds, parameters, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 24 ? f32 : Number;
  // 0x4123a8 FST stores the timer but 0x4123ae compares the register copy.
  const remaining = r(effect.remaining - f32(deltaSeconds));
  effect.remaining = f32(remaining);
  if (remaining <= 0) return finishSpin(effect, body);
  body.lateralSpeed = body.verticalSpeed = body.forwardSpeed = 0;
  // 0x412429 FDIVR and 0x412487 FMUL stay in ST0 until 0x41248b stores.
  body.yawRate = f32(r(6.5 / parameters.duration) * (effect.mode === 0 ? 1 : -1));
  // 0x4124cf/0x412530 subtract and 0x412533 scales in registers before _ftol.
  const angle = effect.mode === 0 ? r(body.yaw - effect.originalAngles[1])
    : r(effect.originalAngles[1] - body.yaw);
  if (Math.trunc(r(angle * f32(1 / 4096))) >= 1) return finishSpin(effect, body);
  return true;
}

/**
 * 0x412280 checks the timer before subtracting, unlike the spin handler.
 * Precision-independent: the speed product (0x4122dd) and timer difference
 * (0x4122f0) are each a single operation stored to float at once.
 */
export function updateNativeGumEffect(effect, body, deltaSeconds, parameters) {
  if (effect.remaining > 0) {
    body.forwardSpeed = f32(parameters.firstSpeedFactor * effect.originalVelocity[2]);
    effect.remaining = f32(effect.remaining - f32(deltaSeconds));
    return true;
  }
  body.forwardSpeed = effect.restoredVelocity[2];
  return false;
}

/**
 * 0x413330 vertical spring and 0x4130e0/0x412fd0 pitch/roll springs.
 * Products and differences stay in x87 registers; every named value below
 * is stored to float (vx 0x4133c6, vz 0x4133df, x 0x4133fb, z 0x413430,
 * height 0x41346e, acceleration 0x413496, verticalSpeed 0x4134a5, force
 * 0x41312b/0x41301b, rates 0x41313a/0x41302a, angles 0x413176/0x413066,
 * noisy rates 0x4131b5|0x4131e6 / 0x4130a5|0x4130d6).
 * sampleGround must be the 0x413330 route-plane sampler (0x4977d0 from the
 * body's sector hint, then 0x494b70); see nativeRouteSpringHeight.
 * clearSlip is the player's [0x50728c] reset: 0x4134a7 FADDs 2.0 to the
 * stored height in ST0 and 0x4134b1 compares it with the entry Y.
 */
export function updateNativeBubbleSprings(body, deltaSeconds, sampleGround, random, {
  precision = NATIVE_PRECISION, clearSlip = null,
} = {}) {
  const r = precision === 24 ? f32 : Number;
  const dt = f32(deltaSeconds);
  const { sin, cos } = nativeYawTrig(body.yaw, precision);
  const vx = f32(r(cos * body.lateralSpeed) - r(sin * body.forwardSpeed));
  const vz = f32(r(sin * body.lateralSpeed) + r(cos * body.forwardSpeed));
  const x = f32(r(r(dt * vx) * 10) + body.position[0]);
  const z = f32(r(r(dt * vz) * 10) + body.position[2]);
  const y = body.position[1];
  const height = f32(sampleGround(x, y, z));
  const acceleration = f32(r(body.verticalSpeed * -3) - r(r(y - height) * 3));
  body.verticalSpeed = f32(r(dt * acceleration) + body.verticalSpeed);
  if (clearSlip && r(height + 2) < y) clearSlip();
  for (const [angle, rate] of [['pitch', 'pitchRate'], ['roll', 'rollRate']]) {
    const force = f32(r(body[rate] * -3) - r(body[angle] * 3));
    body[rate] = f32(r(dt * force) + body[rate]);
    body[angle] = f32(r(dt * body[rate]) + body[angle]);
    // 0x4131a6/0x4131ad (0x413096/0x41309d) keep the noise in ST0.
    const noise = r(r(dt * body.forwardSpeed) * 4);
    body[rate] = f32(body[rate] + (random.next() % 10 < 5 ? noise : -noise));
  }
  return height;
}

/** 0x412560: grounded/expired bubbles finish once rear wheel vertical speed settles. */
export function updateNativeBubbleEffect(effect, body, deltaSeconds, {
  groundCount, rearWheelVerticalSpeed, sampleGround, random, clearSlip = null, precision = NATIVE_PRECISION,
}) {
  const floating = effect.remaining >= 0 && groundCount < 4;
  if (floating) {
    effect.remaining = f32(effect.remaining - f32(deltaSeconds));
    body.lateralSpeed = body.forwardSpeed = 0;
  }
  updateNativeBubbleSprings(body, deltaSeconds, sampleGround, random, { precision, clearSlip });
  if (floating) return true;
  if (effect.bubbleVisible) {
    if (rearWheelVerticalSpeed > 0) return true;
    effect.bubbleVisible = false;
  }
  return false;
}

/** Shared status dispatcher used by player 0x4359a0 and NPC 0x40b910. options.precision: NATIVE_PRECISION (default), 24 or 53. */
export function updateNativeHitEffect(effect, body, deltaSeconds, parameters, options) {
  if (!effect?.active) return false;
  let active;
  if (effect.mode === 4) active = updateNativeGumEffect(effect, body, deltaSeconds, parameters);
  else if (effect.mode === 6) active = updateNativeBubbleEffect(effect, body, deltaSeconds, options);
  else if (effect.mode === 0 || effect.mode === 1) active = updateNativeSpinEffect(effect, body, deltaSeconds, parameters, options);
  else throw new RangeError(`Hit mode ${effect.mode} belongs to a separate trigger effect`);
  effect.active = active;
  return active;
}
