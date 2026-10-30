import { NATIVE_PRECISION } from './native-precision.js';
/**
 * Isolated force kernels translated from native code. These require the engine
 * integration/collision layer and do not yet constitute driving parity.
 * Values are in the native simulation's units; no guessed conversion is applied.
 *
 * `precision` selects the x87 precision-control rounding of register
 * intermediates: 24 (default, every operation rounds to float) or 53 (register
 * results round to double). Values the original stores with FSTP/FST float
 * keep Math.fround at both precisions. FSIN/FCOS/FPATAN return extended
 * results that JavaScript can only approximate with its double functions.
 */
const f32 = Math.fround;
const arithmetic = precision => (precision === 24 ? f32 : Number);

export function slipAngle(body, physics, axle, steering, { precision = NATIVE_PRECISION } = {}) {
  const r = arithmetic(precision);
  if (body.forwardSpeed === 0) return 0;
  let angle;
  if (axle === 'front') {
    // 0x415054..0x415080: steer angle, quotient and FSUBP stay in registers.
    angle = r(r(r(steering * physics.maxSteerAngle) * f32(0.01)) -
      Math.atan(r(r(body.lateralSpeed - r(physics.frontAxleDistance * body.yawRate)) / body.forwardSpeed)));
  } else if (axle === 'rear') {
    // 0x4150b7..0x4150cd: FPATAN result is negated by FCHS and returned extended.
    angle = -Math.atan(r(r(r(body.yawRate * physics.rearAxleDistance) + body.lateralSpeed) / body.forwardSpeed));
  } else {
    throw new RangeError('Axle must be front or rear');
  }
  return body.forwardSpeed < 0 ? -angle : angle; // 0x414ff0
}

export function tireLateralForce(body, physics, axle, steering, tireUpgrade = 0, handbrake = false, { precision = NATIVE_PRECISION } = {}) {
  if (tireUpgrade !== 0 && tireUpgrade !== 1) throw new RangeError('Invalid tire upgrade');
  const r = arithmetic(precision);
  const front = axle === 'front';
  // 0x415388/0x4153b4 store the slip angle into a float argument.
  const angle = f32(slipAngle(body, physics, axle, steering, { precision }));
  // 0x4150f0 returns 1/inverseMass * share * 9.8 (* 0.6) in ST0, unstored.
  let load = r(r(r(body.mass) * (front ? physics.frontWeightShare : physics.rearWeightShare)) * f32(9.8));
  if (!front && handbrake) load = r(load * f32(0.6));
  const a = (front ? physics.frontTireA : physics.rearTireA)[tireUpgrade];
  const b = (front ? physics.frontTireB : physics.rearTireB)[tireUpgrade];
  const c = (front ? physics.frontTireC : physics.rearTireC)[tireUpgrade];
  // 0x41521f FSTP float stores the steer angle that FCOS later reads.
  const cosine = Math.cos(f32(r(steering * physics.maxSteerAngle) * f32(0.01)));
  // 0x415242 FST keeps the extended FSIN result in ST0 for the FMUL.
  const curve = r(r(a * angle) + r(Math.sin(r(c * angle)) * b));
  return f32(cosine * r(curve * r(load * .25))); // 0x415160, FSTP float 0x415262
}

export function enginePower(physics, rpm, motorUpgrade = 0, { precision = NATIVE_PRECISION } = {}) {
  if (motorUpgrade !== 0 && motorUpgrade !== 1) throw new RangeError('Invalid motor upgrade');
  const r = arithmetic(precision);
  return r(r(r(r(physics.engineA[motorUpgrade] * rpm) + physics.engineB[motorUpgrade]) *
    rpm) + physics.engineC[motorUpgrade]); // 0x415410 returns ST0 unstored.
}

export function driveForce(physics, { rpm, gear, throttle, brake, turbo = false, motorUpgrade = 0, gearboxUpgrade = 0, precision = NATIVE_PRECISION }) {
  if (!Number.isInteger(gear) || gear < 0 || gear > 5) throw new RangeError('Invalid gear');
  if (gearboxUpgrade !== 0 && gearboxUpgrade !== 1) throw new RangeError('Invalid gearbox upgrade');
  const r = arithmetic(precision);
  return f32(r(r(r(r(enginePower(physics, rpm, motorUpgrade, { precision }) * physics.transmission[gearboxUpgrade][gear]) *
    throttle) * f32(0.030699998)) + (turbo ? 4000 : 0)) -
    r(r(brake * physics.maxBrakeForce) * f32(0.01))); // 0x415450, FSTP float 0x415506
}

export function resistanceForce(body, physics, { tireUpgrade = 0, handbrake = false, matrix14 = 0, matrix34 = 0, precision = NATIVE_PRECISION } = {}) {
  if (tireUpgrade !== 0 && tireUpgrade !== 1) throw new RangeError('Invalid tire upgrade');
  const r = arithmetic(precision);
  const speedSquared = f32(body.forwardSpeed * body.forwardSpeed); // FSTP float 0x415595
  const friction = physics.tireFriction[tireUpgrade]; // FSTP float 0x415582
  const mass = f32(body.mass); // FSTP float 0x415570
  let longitudinal = 0;
  // 0x4155c8..0x4155e4 and 0x4155fd..0x415613 leave this term in ST0.
  if (body.forwardSpeed > f32(0.00001)) longitudinal = r(r(r(friction * mass) * f32(-9.8)) - r(r(speedSquared * friction) * f32(2.8)));
  else if (body.forwardSpeed < f32(-0.00001)) longitudinal = r(r(r(mass * f32(9.8)) + r(speedSquared * f32(2.8))) * friction);
  // The original always subtracts this aerodynamic term, including in reverse.
  // Aero is stored at 0x4155af; the sum is stored at 0x41563f.
  longitudinal = f32(longitudinal + f32(r(speedSquared * physics.airSurface) * f32(-0.456)));
  let lateral = body.forwardSpeed > 5 ? f32(r(matrix14 * mass) * f32(-1.96)) : 0; // FSTP float 0x415687
  if (!handbrake) longitudinal = f32(r(r(matrix34 * mass) * f32(-9.8)) + longitudinal); // FSTP float 0x415697
  else lateral = 0;
  return { lateral: Math.fround(lateral), longitudinal: Math.fround(longitudinal) }; // 0x415520
}

export function handbrakeForce(forwardSpeed, { precision = NATIVE_PRECISION } = {}) {
  if (forwardSpeed >= 10) return -30000;
  if (forwardSpeed <= -10) return 30000;
  // 0x4157d0 FMUL leaves the product in ST0 for FSUBR; the caller stores the sum.
  return -arithmetic(precision)(forwardSpeed * 1000); // 0x4156c0
}

export function nativeReverseClamp(forwardSpeed) {
  return Math.max(-15, forwardSpeed); // 0x415990; player, not AI's -13.333 limit.
}
