import { NATIVE_PRECISION } from './native-precision.js';
const f32 = Math.fround;

/** Five-word records copied from the original PE table0x4f4620 by0x466360. */
export const NATIVE_MINIMAP_TRANSFORMS = Object.freeze([
  [-.000057, -.275, -.000063, .346, 0],
  [-.000066, -.351, -.000068, .182, 0],
  [.000057, .275, -.000059, .312, 0],
  [.000066, .240, -.000068, .182, 0],
  [.000058, .290, .000056, -.293, 1],
  [-.000058, -.290, -.000056, .220, 3],
].map(row => Object.freeze(row.map((value, i) => i < 4 ? f32(value) : value))));

/** 0x466830/0x4669d0. Returns the overlay element's local XYZ, before its parent transform. */
export function nativeMinimapPosition(trackIndex, position, {
  precision = NATIVE_PRECISION, transform = NATIVE_MINIMAP_TRANSFORMS[trackIndex],
} = {}) {
  if (!transform) throw new RangeError('Original minimap track must be0..5');
  const r = precision === 53 ? Number : f32;
  const [scaleX, offsetX, scaleZ, offsetZ, orientation] = transform;
  let x = f32(r(r(f32(position[0]) * scaleX) + offsetX));
  let y = f32(r(r(f32(position[2]) * scaleZ) + offsetZ));
  if (orientation === 1) [x, y] = [y, -x];
  else if (orientation === 2) { x = -x; y = -y; }
  else if (orientation === 3) [x, y] = [y, x];
  return [x, y, 0];
}

/** Original update order is the player dot first, then NPC dots in roster order. */
export function nativeMinimapRacers(trackIndex, playerPosition, opponentPositions, options) {
  return [
    { player: true, index: opponentPositions.length, position: nativeMinimapPosition(trackIndex, playerPosition, options) },
    ...opponentPositions.map((position, index) => ({
      player: false, index, position: nativeMinimapPosition(trackIndex, position, options),
    })),
  ];
}
