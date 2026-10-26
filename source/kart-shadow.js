import {resolveAsset} from './asset-animation.js';
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
export function getNativeKartShadowPose(body, plane, {precision = 24} = {}) {
  const r = precision === 24 ? f : Number, [x, y, z] = body.position;
  const translation=body.matrixTranslation??body.position;
  const height = f(r(r(r(plane.distance - r(x * plane.normal[0])) - r(z * plane.normal[2])) / plane.normal[1]));
  //4260c0 samples logical +50/+58, then copies the separate draw matrix.
  //Spawn relocation can change the former one frame before matrix translation.
  return {position: [f(r(translation[0] + 2)), Math.min(y, height), f(r(translation[2] + 2))], matrix: [...body.matrix]};
}
