import { nativeTrigTable, NATIVE_ANGLE_COUNT } from './native-integrator.js';
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
export function multiplyNativeMatrices(left, right, precision = NATIVE_PRECISION) {
  const r = precision === 24 ? f32 : Number;
  return [0, 1, 2].flatMap(row => [0, 1, 2].map(col => {
    let sum = 0;
    for (let k = 0; k < 3; k++) sum = r(sum + r(left[row * 3 + k] * right[k * 3 + col]));
    return f32(sum);
  }));
}

/**
 * Render-object rotation 0x4a09e0. Angles are native units (4096/revolution).
 * 0x42ccf0 selects order 0: Z then X then Y. Each angle truncates toward zero
 * before the 4095 mask. Return row-vector 3x3 storage, as in native body.matrix.
 */
export function nativeRotationMatrix(angles, { precision = NATIVE_PRECISION, order = 0, scale = [1, 1, 1] } = {}) {
  if (angles.length !== 3 || !angles.every(Number.isFinite)) throw new RangeError('Three finite native angles are required');
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
  return matrix.map((value, i) => f32(value * f32(scale[Math.floor(i / 3)])));
}
