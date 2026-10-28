import { NATIVE_PRECISION } from './native-precision.js';
const f32 = Math.fround;
/**
 * x87 precision control: register intermediates are rounded to 24 bits under
 * PC=24 and to 53 bits (JS doubles) under PC=53. Values the original stores
 * with FSTP/FST float ptr stay f32 at both precisions.
 */
function registerRounding(precision) {
  if (precision !== 24 && precision !== 53) throw new RangeError('Native x87 precision must be 24 or 53');
  return precision === 24 ? f32 : Number;
}
const subtract = (a, b) => a.map((v, i) => f32(v - b[i]));
const normalize = (a, r = f32) => {
  // 0x405f40 sums X² + Y², then Z², in x87 registers; FSQRT and FDIV stay in
  // registers and each component is stored with FSTP float (0x495d1f-0x495d3c).
  const length = r(Math.sqrt(r(r(r(a[0] * a[0]) + r(a[1] * a[1])) + r(a[2] * a[2]))));
  return a.map(v => f32(v / length));
};
// 0x495dcc-0x495e0c: both FMULs and the FSUBP stay in registers, then each
// component is stored with FSTP float.
const cross = (a, b, r) => [
  f32(r(r(a[1] * b[2]) - r(a[2] * b[1]))),
  f32(r(r(a[2] * b[0]) - r(a[0] * b[2]))),
  f32(r(r(a[0] * b[1]) - r(a[1] * b[0]))),
];

/** Original XZ winding test 0x495ed0; Y is deliberately ignored. */
export function nativeTriangleContainsXZ(x, z, vertices, { precision = NATIVE_PRECISION } = {}) {
  const r = registerRounding(precision);
  const quadrant = p => x <= p[0] ? (z <= p[2] ? 0 : 3) : (z <= p[2] ? 1 : 2);
  let previous = 2;
  let previousQuadrant = quadrant(vertices[previous]);
  let winding = 0;
  for (let i = 0; i < 3; i++) {
    const current = vertices[i];
    const q = quadrant(current);
    if (q !== previousQuadrant) {
      if (((previousQuadrant + 1) & 3) === q) winding++;
      else if (((q + 1) & 3) === previousQuadrant) winding--;
      else {
        const last = vertices[previous];
        // 0x495f81-0x495fa0: FSUB/FMUL/FSUBP stay in registers until FCOMP.
        const side = r(r(z - last[2]) * r(current[0] - last[0])) -
          r(r(x - last[0]) * r(current[2] - last[2]));
        winding += side > 0 ? 2 : -2;
      }
    }
    previous = i;
    previousQuadrant = q;
  }
  return winding !== 0;
}

/**
 * Native 0x494f40 triangle plane, preserving original vertex winding. The road
 * (0x495087-0x49522f) and land (0x4953d7-0x49557f) loops are identical; the
 * extra loop (0x495a2d-0x495c3f) differs only in the distance sum order.
 */
export function nativeTrianglePlane([a, b, c], { precision = NATIVE_PRECISION, kind = 'road' } = {}) {
  const r = registerRounding(precision);
  if (kind !== 'road' && kind !== 'land' && kind !== 'extra') throw new RangeError(`No native plane loop for ${kind}`);
  // 0x495087-0x495132: five edge differences are spilled with FSTP float;
  // the last one, c.z - a.z (0x49514b), stays in ST0.
  const ux = f32(b[0] - a[0]), uy = f32(b[1] - a[1]), uz = f32(b[2] - a[2]);
  const vx = f32(c[0] - a[0]), vy = f32(c[1] - a[1]), vz = r(c[2] - a[2]);
  // 0x495159-0x495190: FMUL/FMUL/FSUBP per component. X and Y are stored with
  // FSTP float; Z is stored with FST float and its register value is reused.
  const nx = f32(r(r(vz * uy) - r(vy * uz)));
  const ny = f32(r(r(vx * uz) - r(vz * ux)));
  const nz = r(r(vy * ux) - r(vx * uy));
  // 0x495192-0x4951a7: (Z² + X²) + Y² with register Z, then FSQRT. The extra
  // loop adds X² + Z² first (0x495ba0-0x495ba8), the same single addition.
  const length = r(Math.sqrt(r(r(r(nz * nz) + r(nx * nx)) + r(ny * ny))));
  // 0x4951ad-0x4951d7: FDIV ST0,ST1 then FSTP float; Z divides register Z.
  const normal = [f32(nx / length), f32(ny / length), f32(nz / length)];
  // 0x4951e7-0x49522f (road/land): f32(a.y*n.y), + a.z*n.z, both spilled with
  // FSTP float, then + a.x*n.x and FSTP float. 0x495bf0-0x495c3f (extra)
  // spills a.z*n.z first, then adds a.y*n.y.
  const [first, second] = kind === 'extra' ? [2, 1] : [1, 2];
  const partial = f32(r(a[second] * normal[second]) + f32(a[first] * normal[first]));
  return { normal, distance: f32(r(a[0] * normal[0]) + partial) };
}

/**
 * Native 0x496290 plane intersection; all four branches (0x4962a4, 0x4962c1,
 * 0x4962f6, 0x496329) run FMUL, FSUBR, FMUL, FSUBP, FDIV in ST0 and return it.
 */
export function nativePlaneHeight(plane, x, z, { precision = NATIVE_PRECISION } = {}) {
  const r = registerRounding(precision);
  return r(r(r(plane.distance - r(x * plane.normal[0])) - r(z * plane.normal[2])) / plane.normal[1]);
}

/** Exact order and route representation retained by the asset converter. */
export function createNativeTrack(track, { precision = NATIVE_PRECISION } = {}) {
  const r = registerRounding(precision);
  if (track.route.length !== track.sectorCount) throw new RangeError('Route/sector count mismatch');
  const sectors = track.route.map((route, i) => {
    const previous = track.route[(i + track.route.length - 1) % track.route.length].position;
    const next = track.route[(i + 1) % track.route.length].position;
    const position = [...route.position];
    // 0x495cb0 builds the transverse direction from previous/next centers.
    // Only -(previous.z - z) is spilled with FSTP float (0x495cd8); the other
    // differences and both sums stay in registers until FSTP float.
    const side = normalize([
      f32(-r(position[2] - next[2]) - f32(previous[2] - position[2])),
      0,
      f32(r(previous[0] - position[0]) + r(position[0] - next[0])),
    ], r);
    const forward = normalize(subtract(next, position), r);
    const normal = normalize(cross(forward, side, r), r);
    // 0x495e57-0x495e6c adds the Z, Y, then X products in registers.
    const distance = f32(r(r(r(normal[2] * position[2]) + r(position[1] * normal[1])) + r(normal[0] * position[0])));
    return { position, side, forward, fallback: { normal, distance },
      triangles: { road: [], land: [], extra: [] } };
  });
  // 0x496b40 copies the penultimate derived axes and fallback plane to last.
  if (sectors.length > 1) {
    const source = sectors.at(-2), last = sectors.at(-1);
    last.side = [...source.side];
    last.forward = [...source.forward];
    last.fallback = { normal: [...source.fallback.normal], distance: source.fallback.distance };
  }
  for (const group of track.groups) {
    if (!(group.kind in sectors[group.sector].triangles)) continue;
    for (let offset = group.start; offset < group.start + group.count; offset += 3) {
      const vertices = [0, 1, 2].map(i => {
        const index = track.index[offset + i] * 3;
        return track.position.slice(index, index + 3);
      });
      const colorIndex = track.index[offset + 2] * 3;
      // 0x496360 uses vertex 2 of the selected triangle, without interpolation.
      const rgb = track.color?.slice(colorIndex, colorIndex + 3).map(v => Math.round(v * 255));
      const diffuse = rgb?.length === 3 ? ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]) >>> 0 : 0xffffff;
      sectors[group.sector].triangles[group.kind].push({ vertices, diffuse,
        ...nativeTrianglePlane(vertices, { precision, kind: group.kind }) });
    }
  }
  return { sectors };
}

/** Original sequential sector search 0x4977d0, including wrap behavior. */
export function selectNativeSector(world, hint, x, z, { precision = NATIVE_PRECISION } = {}) {
  const r = registerRounding(precision);
  const { sectors } = world;
  // 0x497813-0x49786d: both differences, products and FSUBP stay in registers.
  const sideOf = index => {
    const sector = sectors[index];
    return r(r(x - sector.position[0]) * sector.side[2]) -
      r(r(z - sector.position[2]) * sector.side[0]);
  };
  const count = sectors.length;
  if (!Number.isInteger(hint) || hint < 0 || hint >= count) throw new RangeError('Invalid native sector hint');
  let index = hint;
  if (sideOf(index) <= 0) {
    for (; index < count; index++) {
      if (sideOf(index) > 0) return index === 0 ? count - 1 : index - 1;
    }
  } else {
    for (; index >= 0; index--) if (sideOf(index) < 0) return index;
  }
  if (index === 0) {
    for (index = count - 1; index >= 0; index--) if (sideOf(index) < 0) return index;
    return index;
  }
  for (index = 0; index < count; index++) {
    if (sideOf(index) > 0) return index === 0 ? count - 1 : index - 1;
  }
  return index;
}

/** Native 0x495fe0 + 0x496290: first upward face in road/land/extra order. */
export function sampleNativeTrack(world, hint, x, y, z, { precision = NATIVE_PRECISION } = {}) {
  const options = { precision };
  const index = selectNativeSector(world, hint, x, z, options);
  const sector = world.sectors[index];
  if (!sector) throw new RangeError(`Native route search returned invalid sector ${index}`);
  for (const kind of ['road', 'land', 'extra']) {
    const triangles = sector.triangles[kind];
    for (let triangle = 0; triangle < triangles.length; triangle++) {
      const plane = triangles[triangle];
      if (plane.normal[1] > f32(0.4) && nativeTriangleContainsXZ(x, z, plane.vertices, options)) {
        return { height: nativePlaneHeight(plane, x, z, options), sector: index, kind, triangle, normal: plane.normal };
      }
    }
  }
  return { height: nativePlaneHeight(sector.fallback, x, z, options), sector: index,
    kind: 'fallback', triangle: -1, normal: sector.fallback.normal };
}
