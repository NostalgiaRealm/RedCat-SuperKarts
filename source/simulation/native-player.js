import { tireLateralForce, driveForce, resistanceForce, handbrakeForce, nativeReverseClamp } from './native-forces.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f32 = Math.fround;
// x87 register rounding: PC=24 rounds every result to float, PC=53 to double.
const arithmetic = precision => (precision === 24 ? f32 : Number);
// Native constant table 0x4e025c, used by 0x415840 rather than Phys transmission.
const rpmRatios = [8.699999809265137, 4.900000095367432, 3.700000047683716, 2.5, 2, 1.600000023841858];

/** Native 0x415840 RPM/gear selection, after force calculation. */
export function selectNativeGear(physics, forwardSpeed, motorUpgrade = 0, gearboxUpgrade = 0, { precision = NATIVE_PRECISION } = {}) {
  const r = arithmetic(precision);
  if (forwardSpeed < 0) return { rpm: 800, gear: 0 };
  const pi = f32(Math.PI);
  // 0x4158a2..0x4158e3 keep wheel RPM in ST0; only RPM is stored (0x4158f7).
  const wheelRpm = r(((r(r(r(forwardSpeed * 3600) * f32(0.016666668)) /
    r(r(physics.wheelRadius * pi) + r(physics.wheelRadius * pi)))) * f32(3.07)));
  const count = gearboxUpgrade ? 6 : 5;
  let gear = 0;
  let rpm;
  for (; gear < count; gear++) {
    rpm = f32(r(rpmRatios[gear] * wheelRpm) * f32(0.666)); // FSTP float 0x4158f7/0x415930
    if (rpm <= physics.maxRpm[motorUpgrade]) break;
  }
  if (gear >= count) {
    gear = count - 1;
    rpm = f32(r(wheelRpm * rpmRatios[gear]) * f32(0.666)); // FSTP float 0x415954
  }
  return { rpm: Math.max(800, rpm), gear };
}

/**
 * Active racing player force path 0x415990; mutates only velocity damping and
 * returns forces. World movement, wheel contact and collision are separate.
 * `options.precision` (NATIVE_PRECISION default, 24 or 53) selects x87 register rounding.
 */
export function calculateNativePlayerForces(body, physics, controls, deltaSeconds, options = {}) {
  const {
    rpm = 800, gear = 0, motorUpgrade = 0, tireUpgrade = 0,
    gearboxUpgrade = 0, turbo = false, matrix14 = 0, matrix34 = 0, phase = 0,
    precision = NATIVE_PRECISION,
  } = options;
  const r = arithmetic(precision);
  const dt = f32(deltaSeconds);
  if (phase === 8) {
    // 0x4140b0 stores speed*10 as float, then dt*that stays in ST0 for FSUBR.
    for (const key of ['lateralSpeed', 'forwardSpeed', 'yawRate'])
      body[key] = f32(body[key] - r(dt * f32(body[key] * 10)));
    return { lateralForce: 0, longitudinalForce: 0, torque: 0, rpm, gear,
      slipMagnitude: options.slipMagnitude ?? 0 };
  }
  // 0x415990 keeps input polling in results but overrides the force arguments.
  // Only handbrake is a global store; retained throttle/brake controls stay intact.
  if (phase !== 0) controls.handbrake = true;
  const throttle = phase === 0 ? controls.throttle : 0;
  const brake = phase === 0 ? controls.brake : 0;
  let steering = controls.steering;
  // 0x4159fa..0x415a04: both squares and their sum are register values.
  const speedSquared = f32(r(body.forwardSpeed * body.forwardSpeed) + r(body.lateralSpeed * body.lateralSpeed));
  let lateralForce = 0;
  let torque = 0;
  if (speedSquared >= 100) {
    // The native inner speedSquared<20 condition is unreachable and is omitted.
    const front = tireLateralForce(body, physics, 'front', steering, tireUpgrade, controls.handbrake, { precision });
    const rear = tireLateralForce(body, physics, 'rear', steering, tireUpgrade, controls.handbrake, { precision });
    // 0x4914d0 stores each force sum, but its torque cross product stays in
    // ST0 until it is added to the stored accumulator.
    lateralForce = f32(front + rear);
    torque = f32(f32(r(-front * physics.frontAxleDistance)) + r(rear * physics.rearAxleDistance));
  } else {
    if (speedSquared < 5) steering = f32(r(speedSquared * f32(0.2)) * steering); // FSTP float 0x415a3c
    const oldYaw = body.yawRate;
    // 0x414e70: dt*yaw*3 is stored (0x414ea3); the steering delta stays in ST0.
    const steeringDelta = r(r(dt * steering) * (body.forwardSpeed >= 0 ? f32(0.05) : f32(-0.05)));
    body.yawRate = f32(f32(body.yawRate - f32(r(dt * oldYaw) * 3)) - steeringDelta);
    body.lateralSpeed = f32(body.lateralSpeed - r(r(dt * body.lateralSpeed) * 4));
  }
  const resistance = resistanceForce(body, physics, { tireUpgrade, handbrake: controls.handbrake, matrix14, matrix34, precision });
  let longitudinalForce = f32(driveForce(physics, {
    rpm: body.forwardSpeed < 0 ? 4000 : rpm,
    gear, throttle, brake, turbo, motorUpgrade, gearboxUpgrade, precision,
  }) + resistance.longitudinal);
  if (controls.handbrake) longitudinalForce = f32(longitudinalForce + handbrakeForce(body.forwardSpeed, { precision }));
  lateralForce = f32(lateralForce + resistance.lateral);
  torque = f32(torque - r(resistance.lateral * physics.frontAxleDistance));
  const nextGear = selectNativeGear(physics, body.forwardSpeed, motorUpgrade, gearboxUpgrade, { precision });
  body.forwardSpeed = nativeReverseClamp(body.forwardSpeed);
  // Halving a float is exact, so this product is precision-independent.
  let slipMagnitude = Math.min(10, Math.trunc(Math.abs(f32(body.lateralSpeed * .5))));
  if ((controls.handbrake && Math.abs(body.forwardSpeed) > 1) ||
      (nextGear.gear === 0 && throttle >= 80)) slipMagnitude = 10;
  return { lateralForce, longitudinalForce, torque, ...nextGear, slipMagnitude };
}
