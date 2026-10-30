import { nativeTrigTable, NATIVE_ANGLE_COUNT, NATIVE_SIN, NATIVE_COS } from './native-integrator.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f32 = Math.fround;
// Rounding of a value that stays in an x87 register: 24-bit under PC=24,
// 53-bit (a JS double) under PC=53. Float stores always use f32.
const registerRounding = precision => (precision === 24 ? f32 : Number);

// 0x442fc0 passes 4096 to 0x4ac410, overriding the PE's initial 1024.
// The callback indexes that runtime table by truncating the stored yaw.
export { NATIVE_ANGLE_COUNT };
export function nativeYawTrig(yaw, precision = NATIVE_PRECISION) {
  const { sin, cos } = nativeTrigTable(precision);
  const index = Math.trunc(yaw) & (NATIVE_ANGLE_COUNT - 1);
  return { sin: sin[index], cos: cos[index] };
}

function transform(offset, matrix, position, precision = NATIVE_PRECISION) {
  const r = registerRounding(precision);
  // 0x4a25f0 accumulates three x87 products in index order in ST0 and stores
  // the float sum (0x4a262f); callers then add the position and FSTP float.
  return [0, 1, 2].map(axis => f32(f32(r(r(
    r(offset[0] * matrix[axis]) + r(offset[1] * matrix[3 + axis])) +
    r(offset[2] * matrix[6 + axis]))) + position[axis]));
}

// One axis of transform(), without its arrays.
const toWorld = (x, y, z, matrix, position, axis, r) => f32(f32(r(r(
  r(x * matrix[axis]) + r(y * matrix[3 + axis])) + r(z * matrix[6 + axis]))) + position[axis]);

/** Four original child wheel offsets and mesh radii are required inputs. */
export function createNativeGroundState(body, wheels, options = {}) {
  const { precision = NATIVE_PRECISION } = options;
  if (wheels.length !== 4) throw new RangeError('The native kart callback requires four wheels');
  return {
    wheels: wheels.map(wheel => ({
      local: [...wheel.local], radius: wheel.radius,
      // First-call block 0x4167dc..0x4168af of 0x416650.
      position: transform(wheel.local, body.matrix, body.position, precision),
      verticalSpeed: 0,
    })),
    groundCount: 0,
    playerContact: true,
  };
}

/**
 * Shared native 0x507f70 filter. One instance belongs to the whole race:
 * 0x416650 filters again for every car, rather than once for each frame.
 */
export class NativeGroundClock {
  constructor(initialDelta) { this.delta = initialDelta === undefined ? undefined : f32(initialDelta); }
  sample(delta, precision = NATIVE_PRECISION) {
    const r = registerRounding(precision);
    if (this.delta === undefined) this.delta = f32(delta);
    // 0x4166da..0x4166f5: old*9 + new and the *0.1 product stay in ST0;
    // only FSTP float [0x507f70] rounds to float.
    this.delta = f32(r(r(this.delta * 9) + f32(delta)) * f32(0.1));
    return this.delta;
  }
}

/** Native 0x41c0b0 child-wheel spin, steering and local suspension position. */
export function updateNativeWheelPose(body, state, deltaSeconds, steering, sampleGround, options = {}) {
  // options.matrix: the body render matrix 0x41c29f..0x41c30b reads, which a
  // rescue leaves scaled until 0x491d30 rebuilds it (default body.matrix).
  const { precision = NATIVE_PRECISION, matrix = body.matrix } = options;
  const r = registerRounding(precision), position = body.position;
  const radius = state.wheels[0].radius;
  // 0x41c136..0x41c14e: 2r, 4096/2r and both products stay in ST0 until FSTP [ESP+0x48].
  const spin = f32(r(r(NATIVE_ANGLE_COUNT / r(radius + radius)) * f32(deltaSeconds)) * body.forwardSpeed);
  // 0x41c219..0x41c247: three register products, then FSTP float wheel +0x78.
  const steeringAngle = f32(r(r(NATIVE_ANGLE_COUNT * f32(0.083333336)) * f32(-0.01)) * steering);
  for (let i = 0; i < 4; i++) {
    const wheel = state.wheels[i];
    wheel.spin = f32((wheel.spin ?? 0) - spin);
    wheel.steeringAngle = i < 2 ? steeringAngle : 0;
    const local = wheel.local, lx = local[0], lz = local[2], y = toWorld(lx, 0, lz, matrix, position, 1, r);
    // 0x41c401 FSUB then FST float [ESP+0x44]; the 0.5 clamp compares ST0,
    // which orders identically to the stored float.
    const difference = f32(sampleGround(toWorld(lx, 0, lz, matrix, position, 0, r), y, toWorld(lx, 0, lz, matrix, position, 2, r)) - y);
    // Original uses the front radius for all four wheel suspension offsets.
    wheel.local[1] = f32(Math.max(f32(-1.11), Math.min(f32(0.5), difference)) + radius);
  }
  return state;
}

/**
 * Native wheel contact callback 0x416650.
 *
 * body: position[3], column vectors matrix[9], yaw in native angle units,
 * lateralSpeed, forwardSpeed. sampleGround(x,y,z) returns native height.
 * The sampler is separate because native route/triangle selection is a
 * different engine subsystem; arbitrary Three.js ray hits are not equivalent.
 * options.precision selects x87 precision control (NATIVE_PRECISION default, 24 or 53).
 */
export function updateNativeGround(body, state, deltaSeconds, sampleGround, options = {}) {
  const { clock, player = true, gravity = player ? 400 : 100, precision = NATIVE_PRECISION } = options;
  if (!clock) throw new TypeError('A shared NativeGroundClock is required');
  const r = registerRounding(precision);
  const dt = clock.sample(deltaSeconds, precision);
  const yawIndex = Math.trunc(body.yaw) & (NATIVE_ANGLE_COUNT - 1), sin = NATIVE_SIN[yawIndex], cos = NATIVE_COS[yawIndex];
  // Native stores Z velocity (FSTP [ESP+0x74], 0x416ace), but retains X
  // arithmetic on the x87 stack (0x416ab2 FSUBP .. 0x416ae0 FSTP point X).
  const velocityZ = f32(r(cos * body.forwardSpeed) + r(sin * body.lateralSpeed));
  const velocityX = r(r(cos * body.lateralSpeed) - r(sin * body.forwardSpeed));
  const matrix = body.matrix, position = body.position, wheels = state.wheels;
  state.groundCount = 0;
  if (player) state.playerContact = true;
  for (let i = 0; i < 4; i++) {
    const wheel = wheels[i], local = wheel.local, lx = local[0], ly = local[1], lz = local[2], stored = wheel.position;
    let x = toWorld(lx, ly, lz, matrix, position, 0, r), y = stored[1], z = toWorld(lx, ly, lz, matrix, position, 2, r);
    const oldHeight = f32(sampleGround(x, y, z));
    x = f32(r(r(velocityX * dt) * 10) + x);
    z = f32(r(r(velocityZ * dt) * 10) + z);
    const newHeight = f32(sampleGround(x, y, z));
    // 0x416b94..0x416b9b: y - radius is compared from ST0.
    if (oldHeight < r(y - wheel.radius)) {
      // 0x416bee FMUL, 0x416bf4 FSUBR, 0x416bf6 FSTP float.
      wheel.verticalSpeed = f32(wheel.verticalSpeed - r(f32(gravity) * dt));
    }
    // 0x416c05..0x416c20: candidate and candidate - radius stay in ST0;
    // only the airborne branch stores the candidate (0x416c38).
    const candidateY = r(r(dt * wheel.verticalSpeed) + y);
    if (r(candidateY - wheel.radius) <= newHeight) {
      state.groundCount++;
      // Both the difference (0x416c70) and the quotient (0x416c83) are stored.
      wheel.verticalSpeed = f32(f32(newHeight - oldHeight) / dt);
      if (wheel.verticalSpeed >= 0) {
        // 0x416c9e..0x416ca8: oldHeight + 1.8 is compared from ST0.
        if (newHeight < r(oldHeight + f32(1.8))) {
          wheel.verticalSpeed = f32(wheel.verticalSpeed * f32(0.25));
        } else {
          wheel.verticalSpeed = Math.min(10, wheel.verticalSpeed);
          // 0x416cd8..0x416cf1: both products in ST0, then FSTP float.
          wheel.verticalSpeed = f32(r(body.forwardSpeed * f32(0.015)) * wheel.verticalSpeed);
        }
      }
      y = f32(newHeight + wheel.radius);
    } else {
      y = f32(candidateY);
      // Original callback checks only wheel 3 for this particular player flag.
      if (player && i === 3) state.playerContact = false;
    }
    stored[0] = x; stored[1] = y; stored[2] = z;
  }
  const a = wheels[0].position, b = wheels[1].position, c = wheels[2].position, d = wheels[3].position;
  // 0x416d45..0x416d72 sums in ST0 before FSTP; *0.25 and -radius are stored.
  position[1] = f32(f32(f32(r(r(d[1] + c[1]) + b[1]) + a[1]) * f32(0.25)) - wheels[0].radius);
  // Each half-difference is stored, except b.x-d.x (0x416e0b) and d.x-c.x
  // (0x416e82), which stay in ST0. Forward X itself is never stored before
  // its normalisation (0x416f0a); lateral X is stored at 0x416ed0.
  const forwardY = f32(f32(b[1] - d[1]) + f32(a[1] - c[1])), forwardZ = f32(f32(b[2] - d[2]) + f32(a[2] - c[2]));
  const lateralY = f32(f32(d[1] - c[1]) + f32(b[1] - a[1])), lateralZ = f32(f32(d[2] - c[2]) + f32(b[2] - a[2]));
  const forwardX = r(r(b[0] - d[0]) + f32(a[0] - c[0]));
  const lateralX = f32(r(d[0] - c[0]) + f32(b[0] - a[0]));
  // Forward length is stored to [ESP+0x10] (0x416f06); lateral stays in ST0.
  const forwardLength = f32(Math.sqrt(r(r(r(forwardZ * forwardZ) + r(forwardY * forwardY)) + r(forwardX * forwardX))));
  const lateralLength = r(Math.sqrt(r(r(r(lateralZ * lateralZ) + r(lateralY * lateralY)) + r(lateralX * lateralX))));
  // f.x (0x416f0a) and r.z (0x416f58) stay in ST0 until the matrix stores.
  const fX = r(forwardX / forwardLength);
  const f0 = f32(fX), f1 = f32(forwardY / forwardLength), f2 = f32(forwardZ / forwardLength);
  const rZ = r(lateralZ / lateralLength);
  const side0 = f32(lateralX / lateralLength), side1 = f32(lateralY / lateralLength);
  // ux/uy stay in ST0; uz is stored to [ESP+0x68] (0x416f8a).
  const upX = r(r(rZ * f1) - r(side1 * f2));
  const upY = r(r(f2 * side0) - r(rZ * fX));
  const upZ = f32(r(side1 * fX) - r(f1 * side0));
  // Length sums (ux*ux + uz*uz) + uy*uy and is stored to [ESP+0x2c] (0x416fae).
  const upLength = f32(Math.sqrt(r(r(r(upX * upX) + r(upZ * upZ)) + r(upY * upY))));
  // The original leaves matrix +0x24 (up Y) untouched; verified in assembly.
  body.matrix = [side0, side1, f32(rZ), f32(upX / upLength), matrix[4], f32(upZ / upLength), f0, f1, f2];
  return state;
}
