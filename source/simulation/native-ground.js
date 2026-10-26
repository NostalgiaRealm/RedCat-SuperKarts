import { nativeTrigTable, NATIVE_ANGLE_COUNT } from './native-integrator.js';

const f32 = Math.fround;

// 0x442fc0 passes 4096 to 0x4ac410, overriding the PE's initial 1024.
// The callback indexes that runtime table by truncating the stored yaw.
export { NATIVE_ANGLE_COUNT };
export function nativeYawTrig(yaw, precision = 24) {
  const { sin, cos } = nativeTrigTable(precision);
  const index = Math.trunc(yaw) & (NATIVE_ANGLE_COUNT - 1);
  return { sin: sin[index], cos: cos[index] };
}

function transform(offset, matrix, position) {
  // 0x4a25f0 accumulates three rounded x87 products in index order.
  return [0, 1, 2].map(axis => f32(f32(f32(
    f32(offset[0] * matrix[axis]) + f32(offset[1] * matrix[3 + axis])) +
    f32(offset[2] * matrix[6 + axis])) + position[axis]));
}

/** Four original child wheel offsets and mesh radii are required inputs. */
export function createNativeGroundState(body, wheels) {
  if (wheels.length !== 4) throw new RangeError('The native kart callback requires four wheels');
  return {
    wheels: wheels.map(wheel => ({
      local: [...wheel.local], radius: wheel.radius,
      position: transform(wheel.local, body.matrix, body.position),
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
  sample(delta) {
    if (this.delta === undefined) this.delta = f32(delta);
    this.delta = f32(f32(f32(this.delta * 9) + f32(delta)) * f32(0.1));
    return this.delta;
  }
}

/** Native 0x41c0b0 child-wheel spin, steering and local suspension position. */
export function updateNativeWheelPose(body, state, deltaSeconds, steering, sampleGround) {
  const radius = state.wheels[0].radius;
  const spin = f32(f32(f32(NATIVE_ANGLE_COUNT / f32(radius + radius)) * f32(deltaSeconds)) * body.forwardSpeed);
  const steeringAngle = f32(f32(f32(NATIVE_ANGLE_COUNT * f32(0.083333336)) * f32(-0.01)) * steering);
  for (let i = 0; i < 4; i++) {
    const wheel = state.wheels[i];
    wheel.spin = f32((wheel.spin ?? 0) - spin);
    wheel.steeringAngle = i < 2 ? steeringAngle : 0;
    const point = transform([wheel.local[0], 0, wheel.local[2]], body.matrix, body.position);
    const difference = f32(sampleGround(...point) - point[1]);
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
 */
export function updateNativeGround(body, state, deltaSeconds, sampleGround, options = {}) {
  const { clock, player = true, gravity = player ? 400 : 100 } = options;
  if (!clock) throw new TypeError('A shared NativeGroundClock is required');
  const dt = clock.sample(deltaSeconds);
  const { sin, cos } = nativeYawTrig(body.yaw);
  // Native stores Z velocity, but retains X arithmetic on the x87 stack.
  const velocityZ = f32(f32(cos * body.forwardSpeed) + f32(sin * body.lateralSpeed));
  const velocityX = f32(f32(cos * body.lateralSpeed) - f32(sin * body.forwardSpeed));
  state.groundCount = 0;
  if (player) state.playerContact = true;
  for (let i = 0; i < 4; i++) {
    const wheel = state.wheels[i];
    const point = transform(wheel.local, body.matrix, body.position);
    point[1] = wheel.position[1];
    const oldHeight = f32(sampleGround(...point));
    point[0] = f32(f32(f32(velocityX * dt) * 10) + point[0]);
    point[2] = f32(f32(f32(velocityZ * dt) * 10) + point[2]);
    const newHeight = f32(sampleGround(...point));
    if (oldHeight < f32(point[1] - wheel.radius)) {
      wheel.verticalSpeed = f32(wheel.verticalSpeed - f32(f32(gravity) * dt));
    }
    const candidateY = f32(f32(dt * wheel.verticalSpeed) + point[1]);
    if (f32(candidateY - wheel.radius) <= newHeight) {
      state.groundCount++;
      wheel.verticalSpeed = f32(f32(newHeight - oldHeight) / dt);
      if (wheel.verticalSpeed >= 0) {
        if (newHeight < f32(oldHeight + f32(1.8))) {
          wheel.verticalSpeed = f32(wheel.verticalSpeed * f32(0.25));
        } else {
          wheel.verticalSpeed = Math.min(10, wheel.verticalSpeed);
          wheel.verticalSpeed = f32(f32(body.forwardSpeed * f32(0.015)) * wheel.verticalSpeed);
        }
      }
      point[1] = f32(newHeight + wheel.radius);
    } else {
      point[1] = candidateY;
      // Original callback checks only wheel 3 for this particular player flag.
      if (player && i === 3) state.playerContact = false;
    }
    wheel.position = point;
  }
  const [a, b, c, d] = state.wheels.map(wheel => wheel.position);
  body.position[1] = f32(f32(f32(f32(f32(d[1] + c[1]) + b[1]) + a[1]) * f32(0.25)) - state.wheels[0].radius);
  const forward = [0, 1, 2].map(i => f32(f32(b[i] - d[i]) + f32(a[i] - c[i])));
  const lateral = [0, 1, 2].map(i => f32(f32(d[i] - c[i]) + f32(b[i] - a[i])));
  const length = ([x, y, z]) => f32(Math.sqrt(f32(f32(f32(z * z) + f32(y * y)) + f32(x * x))));
  const forwardLength = length(forward);
  const lateralLength = length(lateral);
  const f = forward.map(n => f32(n / forwardLength));
  const r = lateral.map(n => f32(n / lateralLength));
  const up = [
    f32(f32(r[2] * f[1]) - f32(r[1] * f[2])),
    f32(f32(f[2] * r[0]) - f32(r[2] * f[0])),
    f32(f32(r[1] * f[0]) - f32(f[1] * r[0])),
  ];
  const upLength = f32(Math.sqrt(f32(f32(f32(up[0] * up[0]) + f32(up[2] * up[2])) + f32(up[1] * up[1]))));
  // The original leaves matrix +0x24 (up Y) untouched; verified in assembly.
  body.matrix = [
    ...r,
    f32(up[0] / upLength), body.matrix[4], f32(up[2] / upLength),
    ...f,
  ];
  return state;
}
