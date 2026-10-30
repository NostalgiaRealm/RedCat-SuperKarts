import {resolveAsset} from './asset-animation.js';
import {NATIVE_PRECISION} from './simulation/native-precision.js';
import {nativeTrackHeight} from './simulation/native-track.js';
const f = Math.fround;

/** 416270 uses the shared original quad;4260c0 replaces only its X/Z bounds. */
export function getNativeKartShadowSpec(manifest, bounds) {
  const texture = manifest.images['s_shadow.tga'];
  if (!texture) throw new Error('Original kart shadow texture is missing');
  const b = f(2 / texture.width), a = f(1 - b);
  return {mesh: resolveAsset(manifest, 'meshes', 's_shadow.d3d'), texture: texture.file,
    position: [bounds.maxX, 0, bounds.maxZ, bounds.minX, 0, bounds.maxZ,
      bounds.minX, 0, bounds.minZ, bounds.maxX, 0, bounds.minZ],
    uv: [a, b, b, b, b, a, a, a],
    rgba: [0, 0, 0, 128, 0, 0, 0, 128, 0, 0, 0, 128, 0, 0, 0, 128],
    blendMode: 1, nativeFunctions: ['00416270', '004260c0', '00494b70']};
}

/** Native shadow keeps kart tilt/scale, but its origin follows the CURRENT
 * sector fallback plane. It is not projected onto each triangle below it. */
export function getNativeKartShadowPose(body, plane, {precision = NATIVE_PRECISION} = {}) {
  const r = precision === 24 ? f : Number, [x, y, z] = body.position;
  const translation=body.matrixTranslation??body.position;
  const height = f(r(r(r(plane.distance - r(x * plane.normal[0])) - r(z * plane.normal[2])) / plane.normal[1]));
  //4260c0 samples logical +50/+58, then copies the separate draw matrix.
  //Spawn relocation can change the former one frame before matrix translation.
  return {position: [f(r(translation[0] + 2)), Math.min(y, height), f(r(translation[2] + 2))], matrix: [...body.matrix]};
}

/* Browser enhancement, not in the original ("Schaduwen op het wegdek"): the
 * 4260c0 quad is split into a grid whose points lie on the ground surface
 * under them (sampleNativeTrack, the same road/land/extra triangles the karts
 * drive on). The original's single quad on the sector fallback plane is hidden
 * wherever that plane runs below the road. Texture, colour, alpha, footprint,
 * drawn matrix and the +2 X/Z offset stay as in 4260c0. */
export const SURFACE_SHADOW_SEGMENTS = 8;
// With the material's polygon offset this keeps the shadow out of the road's
// depth without visibly floating above it.
export const SURFACE_SHADOW_LIFT = .25;

/** Grid over the 4260c0 quad. `quadIndex` is the loaded S_SHADOW index over
 * its four corners (maxX/maxZ, minX/maxZ, minX/minZ, maxX/minZ); every cell
 * repeats it, so the faces keep the original winding. */
export function getSurfaceKartShadowGrid(spec, quadIndex, segments = SURFACE_SHADOW_SEGMENTS) {
  const p = spec.position, maxX = p[0], maxZ = p[2], minX = p[3], minZ = p[8];
  const a = spec.uv[0], b = spec.uv[1], n = segments, count = (n + 1) * (n + 1);
  const local = new Float32Array(count * 3), uv = new Float32Array(count * 2), rgba = new Uint8Array(count * 4);
  for (let j = 0; j <= n; j++) for (let i = 0; i <= n; i++) {
    const k = j * (n + 1) + i, s = i / n, t = j / n;
    local[k * 3] = maxX + (minX - maxX) * s; local[k * 3 + 2] = maxZ + (minZ - maxZ) * t;
    uv[k * 2] = a + (b - a) * s; uv[k * 2 + 1] = b + (a - b) * t;
    rgba.set(spec.rgba.slice(0, 4), k * 4);
  }
  const index = [];
  for (let j = 0; j < n; j++) for (let i = 0; i < n; i++) {
    const corner = [j * (n + 1) + i, j * (n + 1) + i + 1, (j + 1) * (n + 1) + i + 1, (j + 1) * (n + 1) + i];
    for (const vertex of quadIndex) index.push(corner[vertex]);
  }
  return {local, uv, rgba, index, count};
}

/** World positions for the grid: 4260c0's drawn matrix (row vectors, so tilt
 * and rescue scale shape the footprint) and +2 X/Z, then the ground height
 * under each point from the kart's current sector hint. */
export function surfaceKartShadowPositions(body, world, grid, out = new Float32Array(grid.count * 3),
  {precision = NATIVE_PRECISION} = {}) {
  const m = body.matrix, t = body.matrixTranslation ?? body.position;
  for (let k = 0; k < grid.count; k++) {
    const lx = grid.local[k * 3], lz = grid.local[k * 3 + 2];
    // Sample at the float position the vertex is drawn at.
    const x = f(lx * m[0] + lz * m[6] + t[0] + 2), z = f(lx * m[2] + lz * m[8] + t[2] + 2);
    out[k * 3] = x; out[k * 3 + 2] = z;
    out[k * 3 + 1] = nativeTrackHeight(world, body.sector, x, z, precision) + SURFACE_SHADOW_LIFT;
  }
  return out;
}
