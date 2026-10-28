import { NATIVE_PRECISION } from './native-precision.js';
const f32 = Math.fround;
const TWO_PI = f32(2 * Math.PI);
const UNIT = f32(0.0001);
const tables = new Map();
export const NATIVE_ANGLE_COUNT = 4096;

/** 0x442fc0 selects 4096 entries for 0x4ac410 -> 0x4a1510 at runtime.
 * 0x4ac410 builds the table (0x4ac425) before it creates the Direct3D device,
 * still under the CRT's 53-bit precision (0x4c17bc), so the angle product is
 * not rounded to float in either arithmetic precision. FSIN/FCOS results are
 * stored as floats. */
export function nativeTrigTable(precision = NATIVE_PRECISION, count = NATIVE_ANGLE_COUNT) {
  if (!tables.has(count)) {
    tables.set(count, {
      sin: Float32Array.from({ length: count }, (_, i) => Math.sin((i / count) * TWO_PI)),
      cos: Float32Array.from({ length: count }, (_, i) => Math.cos((i / count) * TWO_PI)),
    });
  }
  return tables.get(count);
}

/**
 * Original Euler kernel 0x4911a0. Mutates body position, yaw and local velocity.
 * Units: body speed m/s, positions native world units (10 per metre), yaw
 * 4096/revolution, yawRate radians/s. Collision supplies fraction/override.
 * Explicit precision supports both CRT 53-bit and Direct3D-style 24-bit math;
 * full Windows runtime precision is not established by isolated emulation.
 */
export function integrateNativeEuler(body, force, deltaSeconds, options = {}) {
  const { fraction = 1, stopYaw = false, velocityOverride, precision = NATIVE_PRECISION } = options;
  const r = precision === 24 ? f32 : Number;
  const dt = f32(deltaSeconds);
  if (!Number.isFinite(dt) || dt < 0) throw new RangeError('Native integrator requires finite nonnegative dt');
  const { sin, cos } = nativeTrigTable(precision);
  const heading = Math.floor(body.yaw) & 4095; // 0x4c062b temporarily selects round-down.
  let dx, dz;
  if (velocityOverride) {
    dx = f32(r(r(f32(velocityOverride[0]) * 10) * dt));
    dz = f32(r(f32(r(f32(velocityOverride[2]) * 10)) * dt));
  } else {
    dx = f32(r(r(r(f32(fraction) * body.lateralSpeed) * 10) * dt));
    dz = f32(r(f32(r(f32(r(f32(fraction) * body.forwardSpeed)) * 10)) * dt));
  }
  const worldX = r(r(cos[heading] * dx) - r(sin[heading] * dz));
  const worldZ = f32(r(r(sin[heading] * dx) + r(cos[heading] * dz)));
  const stepX = r(Math.trunc(r(worldX * 10000)) * UNIT);
  const stepZ = f32(r(Math.trunc(r(worldZ * 10000)) * UNIT));
  body.x = f32(r(body.x + stepX));
  body.z = f32(r(body.z + stepZ));
  const deltaYaw = r(r(4096 * f32(r(dt * body.yawRate))) / TWO_PI);
  if (!stopYaw) body.yaw = f32(r(body.yaw + deltaYaw));
  const turn = -Math.trunc(deltaYaw) & 4095;
  const oldLateral = body.lateralSpeed, oldForward = body.forwardSpeed;
  body.lateralSpeed = f32(r(r(cos[turn] * oldLateral) - r(sin[turn] * oldForward)));
  body.forwardSpeed = f32(r(r(sin[turn] * oldLateral) + r(cos[turn] * oldForward)));
  const invMass = body.inverseMass ?? f32(1 / body.mass);
  const invInertia = body.inverseInertia ?? f32(1 / body.inertia);
  const ax = f32(r(invMass * force.lateralForce));
  const ay = f32(r(invMass * (force.verticalForce ?? 0)));
  const az = r(invMass * force.longitudinalForce);
  body.lateralSpeed = f32(r(body.lateralSpeed + f32(r(ax * dt))));
  body.verticalSpeed = f32(r((body.verticalSpeed ?? 0) + f32(r(ay * dt))));
  body.forwardSpeed = f32(r(body.forwardSpeed + r(az * dt)));
  body.yawRate = f32(r(body.yawRate + r(r(force.torque * invInertia) * dt)));
  return body;
}

/** 0x491d30 truncates the two planar speeds once before its substep loop. */
export function quantizeNativePlanarVelocity(body, precision = NATIVE_PRECISION) {
  const r = precision === 24 ? f32 : Number;
  for (const key of ['lateralSpeed', 'forwardSpeed']) body[key] = f32(r(Math.trunc(r(body[key] * 10000)) * UNIT));
  return body;
}

/** Player is selected by 0x493110 and always receives eight substeps. */
export function nativeIntegrationSchedule(deltaSeconds, { player = true, flags = 3 } = {}) {
  const dt = f32(deltaSeconds);
  const count = player || ((flags & 4) !== 0 && dt > f32(0.0666)) ? 8 : 1;
  return { count, dt: Math.max(0, f32(dt / count)), kernel: flags & 4 ? 'rk4' : 'euler' };
}
