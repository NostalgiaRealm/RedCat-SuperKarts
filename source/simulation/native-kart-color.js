import { nativeTriangleContainsXZ } from './native-track.js';
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
  const [x, , z] = body.position ?? [body.x, body.y, body.z];
  for (const kind of ['road', 'land', 'extra']) {
    for (const plane of sector.triangles[kind]) {
      if (plane.normal[1] > f32(.4) && nativeTriangleContainsXZ(x, z, plane.vertices)) {
        return plane.diffuse;
      }
    }
  }
  return 0xffffff;
}

/**
 * Complete 0x4903c0 color arithmetic. `diffuse` is persistent body+0x34
 * (0x48fef0 initializes FFFFFFFF). `renderDiffuse` is copied to the body and
 * ordinary child meshes at draw time. Do not feed the brightened value back.
 */
export function advanceNativeKartColor(diffuse, groundDiffuse, forwardSpeed, deltaSeconds,
  brightness = [0, 0, 0], { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 24 ? f32 : value => value;
  const alpha = diffuse >>> 24;
  const old = [(diffuse >>> 16) & 255, (diffuse >>> 8) & 255, diffuse & 255];
  const target = [(groundDiffuse >>> 16) & 255, (groundDiffuse >>> 8) & 255, groundDiffuse & 255];
  const speedFactor = f32(r(r(Math.abs(f32(forwardSpeed)) * f32(.1)) + 1));
  const factor = r(f32(deltaSeconds) * speedFactor);
  const smooth = old.map((value, i) => {
    const channel = r(r((target[i] - value) * factor) + value);
    // Blue stays on the x87 stack; red and green spill to float locals.
    return i === 2 ? channel : f32(channel);
  });
  const render = smooth.map((value, i) => {
    const channel = r(value + f32(brightness[i]));
    return Math.min(255, i === 2 ? channel : f32(channel));
  });
  return { diffuse: pack(alpha, ...smooth), renderDiffuse: pack(alpha, ...render) };
}
