import { tireLateralForce, driveForce, resistanceForce, handbrakeForce, nativeReverseClamp } from './native-forces.js';

const f32 = Math.fround;
// Native constant table 0x4e025c, used by 0x415840 rather than Phys transmission.
const rpmRatios = [8.699999809265137, 4.900000095367432, 3.700000047683716, 2.5, 2, 1.600000023841858];

/** Native 0x415840 RPM/gear selection, after force calculation. */
export function selectNativeGear(physics, forwardSpeed, motorUpgrade = 0, gearboxUpgrade = 0) {
  if (forwardSpeed < 0) return { rpm: 800, gear: 0 };
  const pi = f32(Math.PI);
  const wheelRpm = f32(((f32(f32(f32(forwardSpeed * 3600) * f32(0.016666668)) /
    f32(f32(physics.wheelRadius * pi) + f32(physics.wheelRadius * pi)))) * f32(3.07)));
  const count = gearboxUpgrade ? 6 : 5;
  let gear = 0;
  let rpm;
  for (; gear < count; gear++) {
    rpm = f32(f32(rpmRatios[gear] * wheelRpm) * f32(0.666));
    if (rpm <= physics.maxRpm[motorUpgrade]) break;
  }
  if (gear >= count) {
    gear = count - 1;
    rpm = f32(f32(wheelRpm * rpmRatios[gear]) * f32(0.666));
  }
  return { rpm: Math.max(800, rpm), gear };
}

/**
 * Active racing player force path 0x415990; mutates only velocity damping and
 * returns forces. World movement, wheel contact and collision are separate.
 */
export function calculateNativePlayerForces(body, physics, controls, deltaSeconds, options = {}) {
  const {
    rpm = 800, gear = 0, motorUpgrade = 0, tireUpgrade = 0,
    gearboxUpgrade = 0, turbo = false, matrix14 = 0, matrix34 = 0, phase = 0,
  } = options;
  const dt = f32(deltaSeconds);
  if (phase === 8) {
    for (const key of ['lateralSpeed', 'forwardSpeed', 'yawRate'])
      body[key] = f32(body[key] - f32(dt * f32(body[key] * 10)));
    return { lateralForce: 0, longitudinalForce: 0, torque: 0, rpm, gear,
      slipMagnitude: options.slipMagnitude ?? 0 };
  }
  // 0x415990 keeps input polling in results but overrides the force arguments.
  // Only handbrake is a global store; retained throttle/brake controls stay intact.
  if (phase !== 0) controls.handbrake = true;
  const throttle = phase === 0 ? controls.throttle : 0;
  const brake = phase === 0 ? controls.brake : 0;
  let steering = controls.steering;
  const speedSquared = f32(f32(body.forwardSpeed * body.forwardSpeed) + f32(body.lateralSpeed * body.lateralSpeed));
  let lateralForce = 0;
  let torque = 0;
  if (speedSquared >= 100) {
    // The native inner speedSquared<20 condition is unreachable and is omitted.
    const front = tireLateralForce(body, physics, 'front', steering, tireUpgrade, controls.handbrake);
    const rear = tireLateralForce(body, physics, 'rear', steering, tireUpgrade, controls.handbrake);
    lateralForce = f32(front + rear);
    torque = f32(f32(-front * physics.frontAxleDistance) + f32(rear * physics.rearAxleDistance));
  } else {
    if (speedSquared < 5) steering = f32(f32(speedSquared * f32(0.2)) * steering);
    const oldYaw = body.yawRate;
    const steeringDelta = f32(f32(dt * steering) * (body.forwardSpeed >= 0 ? f32(0.05) : f32(-0.05)));
    body.yawRate = f32(f32(body.yawRate - f32(f32(dt * oldYaw) * 3)) - steeringDelta);
    body.lateralSpeed = f32(body.lateralSpeed - f32(f32(dt * body.lateralSpeed) * 4));
  }
  const resistance = resistanceForce(body, physics, { tireUpgrade, handbrake: controls.handbrake, matrix14, matrix34 });
  let longitudinalForce = f32(driveForce(physics, {
    rpm: body.forwardSpeed < 0 ? 4000 : rpm,
    gear, throttle, brake, turbo, motorUpgrade, gearboxUpgrade,
  }) + resistance.longitudinal);
  if (controls.handbrake) longitudinalForce = f32(longitudinalForce + handbrakeForce(body.forwardSpeed));
  lateralForce = f32(lateralForce + resistance.lateral);
  torque = f32(torque - f32(resistance.lateral * physics.frontAxleDistance));
  const nextGear = selectNativeGear(physics, body.forwardSpeed, motorUpgrade, gearboxUpgrade);
  body.forwardSpeed = nativeReverseClamp(body.forwardSpeed);
  let slipMagnitude = Math.min(10, Math.trunc(Math.abs(f32(body.lateralSpeed * .5))));
  if ((controls.handbrake && Math.abs(body.forwardSpeed) > 1) ||
      (nextGear.gear === 0 && throttle >= 80)) slipMagnitude = 10;
  return { lateralForce, longitudinalForce, torque, ...nextGear, slipMagnitude };
}
