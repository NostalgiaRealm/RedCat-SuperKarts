import { nativeFacePlane } from './native-track.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f32 = Math.fround;
const pack = (alpha, red, green, blue) =>
  (((((alpha << 8) | Math.trunc(red)) << 8) | Math.trunc(green)) << 8 | Math.trunc(blue)) >>> 0;

/** 0x42bbf0 fields11..13 -> signed shorts -> 0x42d7d0/0x493b10. */
export function nativeKartBrightness(config, trackId) {
  const fields = config['track.ini'].maps[trackId].split(',');
  return fields.slice(11, 14).map(value => (Number(value) << 16) >> 16);
}

/** 0x495fe0/0x496360 use the body's existing sector, not a fresh sector search. */
export function sampleNativeKartGroundColor(world, body) {
  const sector = world.sectors[body.sector];
  if (!sector) throw new RangeError('Invalid native kart sector');
  const position = body.position, x = position ? position[0] : body.x, z = position ? position[2] : body.z;
  return nativeFacePlane(sector, x, z)?.diffuse ?? 0xffffff;
}

/**
 * Complete 0x4903c0 color arithmetic. `diffuse` is persistent body+0x34
 * (0x48fef0 initializes FFFFFFFF). `renderDiffuse` is copied to the body and
 * ordinary child meshes at draw time. Do not feed the brightened value back.
 */
export function advanceNativeKartColor(diffuse, groundDiffuse, forwardSpeed, deltaSeconds,
  brightness = [0, 0, 0], { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 24 ? f32 : Number;
  const alpha = diffuse >>> 24;
  const oldR = (diffuse >>> 16) & 255, oldG = (diffuse >>> 8) & 255, oldB = diffuse & 255;
  const speedFactor = f32(r(r(Math.abs(f32(forwardSpeed)) * f32(.1)) + 1));
  const factor = r(f32(deltaSeconds) * speedFactor);
  // Blue stays on the x87 stack; red and green spill to float locals.
  const smoothR = f32(r(r((((groundDiffuse >>> 16) & 255) - oldR) * factor) + oldR));
  const smoothG = f32(r(r((((groundDiffuse >>> 8) & 255) - oldG) * factor) + oldG));
  const smoothB = r(r(((groundDiffuse & 255) - oldB) * factor) + oldB);
  return { diffuse: pack(alpha, smoothR, smoothG, smoothB), renderDiffuse: pack(alpha,
    Math.min(255, f32(r(smoothR + f32(brightness[0])))),
    Math.min(255, f32(r(smoothG + f32(brightness[1])))),
    Math.min(255, r(smoothB + f32(brightness[2])))) };
}
