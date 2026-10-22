/**
 * Isolated force kernels translated from native code. These require the engine
 * integration/collision layer and do not yet constitute driving parity.
 * Values are in the native simulation's units; no guessed conversion is applied.
 */
const f32 = Math.fround;
export function slipAngle(body, physics, axle, steering) {
  if (body.forwardSpeed === 0) return 0;
  let angle;
  if (axle === 'front') {
    angle = f32(f32(f32(steering * physics.maxSteerAngle) * f32(0.01)) -
      Math.atan(f32(f32(body.lateralSpeed - f32(physics.frontAxleDistance * body.yawRate)) / body.forwardSpeed)));
  } else if (axle === 'rear') {
    angle = -Math.atan(f32(f32(f32(body.yawRate * physics.rearAxleDistance) + body.lateralSpeed) / body.forwardSpeed));
  } else {
    throw new RangeError('Axle must be front or rear');
  }
  return body.forwardSpeed < 0 ? -angle : angle; // 0x414ff0
}

export function tireLateralForce(body, physics, axle, steering, tireUpgrade = 0, handbrake = false) {
  if (tireUpgrade !== 0 && tireUpgrade !== 1) throw new RangeError('Invalid tire upgrade');
  const front = axle === 'front';
  const prefix = front ? 'front' : 'rear';
  const angle = f32(slipAngle(body, physics, axle, steering));
  let load = f32(f32(f32(body.mass) * (front ? physics.frontWeightShare : physics.rearWeightShare)) * f32(9.8));
  if (!front && handbrake) load = f32(load * f32(0.6));
  const a = physics[`${prefix}TireA`][tireUpgrade];
  const b = physics[`${prefix}TireB`][tireUpgrade];
  const c = physics[`${prefix}TireC`][tireUpgrade];
  const cosine = Math.cos(f32(f32(steering * physics.maxSteerAngle) * f32(0.01)));
  const curve = f32(f32(a * angle) + f32(Math.sin(f32(c * angle)) * b));
  return f32(cosine * f32(curve * f32(load * .25))); // 0x415160
}

export function enginePower(physics, rpm, motorUpgrade = 0) {
  if (motorUpgrade !== 0 && motorUpgrade !== 1) throw new RangeError('Invalid motor upgrade');
  return f32(f32(f32(f32(physics.engineA[motorUpgrade] * rpm) + physics.engineB[motorUpgrade]) *
    rpm) + physics.engineC[motorUpgrade]); // 0x415410
}

export function driveForce(physics, { rpm, gear, throttle, brake, turbo = false, motorUpgrade = 0, gearboxUpgrade = 0 }) {
  if (!Number.isInteger(gear) || gear < 0 || gear > 5) throw new RangeError('Invalid gear');
  if (gearboxUpgrade !== 0 && gearboxUpgrade !== 1) throw new RangeError('Invalid gearbox upgrade');
  return f32(f32(f32(f32(f32(enginePower(physics, rpm, motorUpgrade) * physics.transmission[gearboxUpgrade][gear]) *
    throttle) * f32(0.030699998)) + (turbo ? 4000 : 0)) -
    f32(f32(brake * physics.maxBrakeForce) * f32(0.01))); // 0x415450
}

export function resistanceForce(body, physics, { tireUpgrade = 0, handbrake = false, matrix14 = 0, matrix34 = 0 } = {}) {
  if (tireUpgrade !== 0 && tireUpgrade !== 1) throw new RangeError('Invalid tire upgrade');
  const speedSquared = f32(body.forwardSpeed * body.forwardSpeed);
  const friction = physics.tireFriction[tireUpgrade];
  const mass = f32(body.mass);
  let longitudinal = 0;
  if (body.forwardSpeed > f32(0.00001)) longitudinal = f32(f32(f32(friction * mass) * f32(-9.8)) - f32(f32(speedSquared * friction) * f32(2.8)));
  else if (body.forwardSpeed < f32(-0.00001)) longitudinal = f32(f32(f32(mass * f32(9.8)) + f32(speedSquared * f32(2.8))) * friction);
  // The original always subtracts this aerodynamic term, including in reverse.
  longitudinal = f32(longitudinal + f32(f32(speedSquared * physics.airSurface) * f32(-0.456)));
  let lateral = body.forwardSpeed > 5 ? f32(f32(matrix14 * mass) * f32(-1.96)) : 0;
  if (!handbrake) longitudinal = f32(f32(f32(matrix34 * mass) * f32(-9.8)) + longitudinal);
  else lateral = 0;
  return { lateral: Math.fround(lateral), longitudinal: Math.fround(longitudinal) }; // 0x415520
}

export function handbrakeForce(forwardSpeed) {
  if (forwardSpeed >= 10) return -30000;
  if (forwardSpeed <= -10) return 30000;
  return -f32(forwardSpeed * 1000); // 0x4156c0
}

export function nativeReverseClamp(forwardSpeed) {
  return Math.max(-15, forwardSpeed); // 0x415990; player, not AI's -13.333 limit.
}
