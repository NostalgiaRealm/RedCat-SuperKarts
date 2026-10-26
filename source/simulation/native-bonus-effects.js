import { nativeYawTrig } from './native-ground.js';

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

/** Shared 0x411830/0x411b40/0x411e50/0x412090 gameplay initialization. */
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
export function updateNativeSpinEffect(effect, body, deltaSeconds, parameters) {
  effect.remaining = f32(effect.remaining - f32(deltaSeconds));
  if (effect.remaining <= 0) return finishSpin(effect, body);
  body.lateralSpeed = body.verticalSpeed = body.forwardSpeed = 0;
  body.yawRate = f32(f32(6.5 / parameters.duration) * (effect.mode === 0 ? 1 : -1));
  const angle = effect.mode === 0 ? f32(body.yaw - effect.originalAngles[1])
    : f32(effect.originalAngles[1] - body.yaw);
  if (Math.trunc(f32(angle * f32(1 / 4096))) >= 1) return finishSpin(effect, body);
  return true;
}

/** 0x412280 checks the timer before subtracting, unlike the spin handler. */
export function updateNativeGumEffect(effect, body, deltaSeconds, parameters) {
  if (effect.remaining > 0) {
    body.forwardSpeed = f32(parameters.firstSpeedFactor * effect.originalVelocity[2]);
    effect.remaining = f32(effect.remaining - f32(deltaSeconds));
    return true;
  }
  body.forwardSpeed = effect.restoredVelocity[2];
  return false;
}

/** 0x413330 vertical spring and 0x4130e0/0x412fd0 pitch/roll springs. */
export function updateNativeBubbleSprings(body, deltaSeconds, sampleGround, random) {
  const dt = f32(deltaSeconds);
  const { sin, cos } = nativeYawTrig(body.yaw);
  const vx = f32(f32(cos * body.lateralSpeed) - f32(sin * body.forwardSpeed));
  const vz = f32(f32(sin * body.lateralSpeed) + f32(cos * body.forwardSpeed));
  const x = f32(f32(f32(dt * vx) * 10) + body.position[0]);
  const z = f32(f32(f32(dt * vz) * 10) + body.position[2]);
  const height = f32(sampleGround(x, body.position[1], z));
  const acceleration = f32(f32(body.verticalSpeed * -3) - f32(f32(body.position[1] - height) * 3));
  body.verticalSpeed = f32(f32(dt * acceleration) + body.verticalSpeed);
  for (const [angle, rate] of [['pitch', 'pitchRate'], ['roll', 'rollRate']]) {
    const force = f32(f32(body[rate] * -3) - f32(body[angle] * 3));
    body[rate] = f32(f32(dt * force) + body[rate]);
    body[angle] = f32(f32(dt * body[rate]) + body[angle]);
    const noise = f32(f32(dt * body.forwardSpeed) * 4);
    body[rate] = f32(body[rate] + (random.next() % 10 < 5 ? noise : -noise));
  }
  return height;
}

/** 0x412560: grounded/expired bubbles finish once rear wheel vertical speed settles. */
export function updateNativeBubbleEffect(effect, body, deltaSeconds, {
  groundCount, rearWheelVerticalSpeed, sampleGround, random,
}) {
  const floating = effect.remaining >= 0 && groundCount < 4;
  if (floating) {
    effect.remaining = f32(effect.remaining - f32(deltaSeconds));
    body.lateralSpeed = body.forwardSpeed = 0;
  }
  updateNativeBubbleSprings(body, deltaSeconds, sampleGround, random);
  if (floating) return true;
  if (effect.bubbleVisible) {
    if (rearWheelVerticalSpeed > 0) return true;
    effect.bubbleVisible = false;
  }
  return false;
}

/** Shared status dispatcher used by player 0x4359a0 and NPC 0x40b910. */
export function updateNativeHitEffect(effect, body, deltaSeconds, parameters, options) {
  if (!effect?.active) return false;
  let active;
  if (effect.mode === 4) active = updateNativeGumEffect(effect, body, deltaSeconds, parameters);
  else if (effect.mode === 6) active = updateNativeBubbleEffect(effect, body, deltaSeconds, options);
  else if (effect.mode === 0 || effect.mode === 1) active = updateNativeSpinEffect(effect, body, deltaSeconds, parameters);
  else throw new RangeError(`Hit mode ${effect.mode} belongs to a separate trigger effect`);
  effect.active = active;
  return active;
}
