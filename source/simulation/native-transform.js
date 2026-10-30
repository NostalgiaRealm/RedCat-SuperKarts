import { nativeTrigTable, NATIVE_ANGLE_COUNT, NATIVE_SIN, NATIVE_COS } from './native-integrator.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f32 = Math.fround;
const identity = () => [1, 0, 0, 0, 1, 0, 0, 0, 1];
const DEGREE = f32(1 / 360); // rcskspel.dat 0x4d2468 = 0x3b360b61

/**
 * OMP placement degrees to native angle units, rcskspel.dat 0x43e140
 * (0x43e283..0x43e2ad): ST0 = float[0x4fc8f4] (runtime count 4096 from
 * 0x4a1510) * float[0x4d2468]; then per axis FLD ST0, FMUL float, FSTP float,
 * with FCHS on Y before its store. Track nativeRotationDegrees already carry
 * that Y sign, and negation commutes with rounding. Both products are exact
 * before the one float store, so x87 PC=24 and PC=53 agree
 * (evidence/native/placement-angle-fixtures.json).
 */
export function nativePlacementAngle(degrees, angleCount = NATIVE_ANGLE_COUNT) {
  return f32(degrees * (angleCount * DEGREE));
}

export function nativePlacementAngles(degrees, angleCount = NATIVE_ANGLE_COUNT) {
  return degrees.map(value => nativePlacementAngle(value, angleCount));
}

/** Native row-vector matrix composition, matching 0x4a2560 operation order. */
export function multiplyNativeMatrices(a, b, precision = NATIVE_PRECISION) {
  if (precision === 24) {
    const out = new Array(9);
    for (let row = 0; row < 3; row++) for (let col = 0; col < 3; col++) {
      let sum = 0;
      for (let k = 0; k < 3; k++) sum = f32(sum + f32(a[row * 3 + k] * b[k * 3 + col]));
      out[row * 3 + col] = f32(sum);
    }
    return out;
  }
  // The leading 0 is the original accumulator: it turns a -0 first product into +0.
  return [
    f32(0 + a[0] * b[0] + a[1] * b[3] + a[2] * b[6]), f32(0 + a[0] * b[1] + a[1] * b[4] + a[2] * b[7]), f32(0 + a[0] * b[2] + a[1] * b[5] + a[2] * b[8]),
    f32(0 + a[3] * b[0] + a[4] * b[3] + a[5] * b[6]), f32(0 + a[3] * b[1] + a[4] * b[4] + a[5] * b[7]), f32(0 + a[3] * b[2] + a[4] * b[5] + a[5] * b[8]),
    f32(0 + a[6] * b[0] + a[7] * b[3] + a[8] * b[6]), f32(0 + a[6] * b[1] + a[7] * b[4] + a[8] * b[7]), f32(0 + a[6] * b[2] + a[7] * b[5] + a[8] * b[8]),
  ];
}

/**
 * Order 0 of 0x4a09e0 at 53 bits without intermediate arrays. Against finite
 * entries the zero terms of each axis matrix only add signed zeros to a sum
 * that starts at +0, so 0+x keeps the accumulator's result exactly.
 */
export function nativeRotationMatrix53(pitch, yaw, roll) {
  if (!Number.isFinite(pitch) || !Number.isFinite(yaw) || !Number.isFinite(roll)) throw new RangeError('Three finite native angles are required');
  let m0 = 1, m1 = 0, m2 = 0, m3 = 0, m4 = 1, m5 = 0, m6 = 0, m7 = 0, m8 = 1, n0, n1, n3, n4, n6, n7;
  let angle = f32(roll);
  if (angle !== 0) { // Z
    const i = Math.trunc(angle) & 4095, s = NATIVE_SIN[i], c = NATIVE_COS[i], t = -s;
    n0 = f32(0 + m0 * c + m1 * s); n1 = f32(0 + m0 * t + m1 * c); n3 = f32(0 + m3 * c + m4 * s); n4 = f32(0 + m3 * t + m4 * c);
    n6 = f32(0 + m6 * c + m7 * s); n7 = f32(0 + m6 * t + m7 * c);
    m0 = n0; m1 = n1; m2 = f32(0 + m2); m3 = n3; m4 = n4; m5 = f32(0 + m5); m6 = n6; m7 = n7; m8 = f32(0 + m8);
  }
  angle = f32(pitch);
  if (angle !== 0) { // X
    const i = Math.trunc(angle) & 4095, s = NATIVE_SIN[i], c = NATIVE_COS[i], t = -s;
    n1 = f32(0 + m1 * c + m2 * s); n4 = f32(0 + m4 * c + m5 * s); n7 = f32(0 + m7 * c + m8 * s);
    m2 = f32(0 + m1 * t + m2 * c); m5 = f32(0 + m4 * t + m5 * c); m8 = f32(0 + m7 * t + m8 * c);
    m0 = f32(0 + m0); m3 = f32(0 + m3); m6 = f32(0 + m6); m1 = n1; m4 = n4; m7 = n7;
  }
  angle = f32(yaw);
  if (angle !== 0) { // Y
    const i = Math.trunc(angle) & 4095, s = NATIVE_SIN[i], c = NATIVE_COS[i], t = -s;
    n0 = f32(0 + m0 * c + m2 * t); n3 = f32(0 + m3 * c + m5 * t); n6 = f32(0 + m6 * c + m8 * t);
    m2 = f32(0 + m0 * s + m2 * c); m5 = f32(0 + m3 * s + m5 * c); m8 = f32(0 + m6 * s + m8 * c);
    m1 = f32(0 + m1); m4 = f32(0 + m4); m7 = f32(0 + m7); m0 = n0; m3 = n3; m6 = n6;
  }
  return [m0, m1, m2, m3, m4, m5, m6, m7, m8];
}

/**
 * Render-object rotation 0x4a09e0. Angles are native units (4096/revolution).
 * 0x42ccf0 selects order 0: Z then X then Y. Each angle truncates toward zero
 * before the 4095 mask. Return row-vector 3x3 storage, as in native body.matrix.
 */
export function nativeRotationMatrix(angles, { precision = NATIVE_PRECISION, order = 0, scale } = {}) {
  if (angles.length !== 3) throw new RangeError('Three finite native angles are required');
  if (order === 0 && !scale && precision !== 24) return nativeRotationMatrix53(angles[0], angles[1], angles[2]);
  if (!Number.isFinite(angles[0]) || !Number.isFinite(angles[1]) || !Number.isFinite(angles[2])) throw new RangeError('Three finite native angles are required');
  const { sin, cos } = nativeTrigTable(precision);
  let matrix = identity();
  for (const axis of order === 0 ? [2, 0, 1] : order === 1 ? [2, 1, 0] : [0, 1, 2]) {
    const angle = f32(angles[axis]);
    if (angle === 0) continue;
    const index = Math.trunc(angle) & 4095;
    const s = sin[index], c = cos[index];
    const rotation = axis === 0 ? [1, 0, 0, 0, c, -s, 0, s, c]
      : axis === 1 ? [c, 0, s, 0, 1, 0, -s, 0, c]
        : [c, -s, 0, s, c, 0, 0, 0, 1];
    matrix = multiplyNativeMatrices(matrix, rotation, precision);
  }
  const factor = scale ?? [1, 1, 1];
  return matrix.map((value, i) => f32(value * f32(factor[Math.floor(i / 3)])));
}
