const f32 = Math.fround;
const subtract = (a, b) => a.map((v, i) => f32(v - b[i]));
const normalize = a => {
  // 0x405f40 sums X² + Y², then Z², in the selected 24-bit x87 mode.
  const length = f32(Math.sqrt(f32(f32(f32(a[0] * a[0]) + f32(a[1] * a[1])) + f32(a[2] * a[2]))));
  return a.map(v => f32(v / length));
};
const cross = (a, b) => [
  f32(a[1] * b[2] - a[2] * b[1]),
  f32(a[2] * b[0] - a[0] * b[2]),
  f32(a[0] * b[1] - a[1] * b[0]),
];
const dot = (a, b) => f32(a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);

/** Original XZ winding test 0x495ed0; Y is deliberately ignored. */
export function nativeTriangleContainsXZ(x, z, vertices) {
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
        const side = f32(f32(z - last[2]) * f32(current[0] - last[0])) -
          f32(f32(x - last[0]) * f32(current[2] - last[2]));
        winding += side > 0 ? 2 : -2;
      }
    }
    previous = i;
    previousQuadrant = q;
  }
  return winding !== 0;
}

/** Native 0x494f40 triangle plane, preserving original vertex winding. */
export function nativeTrianglePlane(vertices) {
  const normal = normalize(cross(subtract(vertices[1], vertices[0]), subtract(vertices[2], vertices[0])));
  return { normal, distance: dot(normal, vertices[0]) };
}

/** Native 0x496290 plane intersection. */
export function nativePlaneHeight(plane, x, z) {
  return f32((plane.distance - x * plane.normal[0] - z * plane.normal[2]) / plane.normal[1]);
}

/** Exact order and route representation retained by the asset converter. */
export function createNativeTrack(track) {
  if (track.route.length !== track.sectorCount) throw new RangeError('Route/sector count mismatch');
  const sectors = track.route.map((route, i) => {
    const previous = track.route[(i + track.route.length - 1) % track.route.length].position;
    const next = track.route[(i + 1) % track.route.length].position;
    const position = [...route.position];
    // 0x495cb0 builds the transverse direction from previous/next centers.
    const side = normalize([
      f32(-f32(position[2] - next[2]) - f32(previous[2] - position[2])),
      0,
      f32(f32(previous[0] - position[0]) + f32(position[0] - next[0])),
    ]);
    const forward = normalize(subtract(next, position));
    const normal = normalize(cross(forward, side));
    return { position, side, forward, fallback: { normal, distance: dot(normal, position) },
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
      sectors[group.sector].triangles[group.kind].push({ vertices, diffuse, ...nativeTrianglePlane(vertices) });
    }
  }
  return { sectors };
}

/** Original sequential sector search 0x4977d0, including wrap behavior. */
export function selectNativeSector(world, hint, x, z) {
  const { sectors } = world;
  const sideOf = index => {
    const sector = sectors[index];
    return f32(f32(x - sector.position[0]) * sector.side[2]) -
      f32(f32(z - sector.position[2]) * sector.side[0]);
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
export function sampleNativeTrack(world, hint, x, y, z) {
  const index = selectNativeSector(world, hint, x, z);
  const sector = world.sectors[index];
  if (!sector) throw new RangeError(`Native route search returned invalid sector ${index}`);
  for (const kind of ['road', 'land', 'extra']) {
    const triangles = sector.triangles[kind];
    for (let triangle = 0; triangle < triangles.length; triangle++) {
      const plane = triangles[triangle];
      if (plane.normal[1] > f32(0.4) && nativeTriangleContainsXZ(x, z, plane.vertices)) {
        return { height: nativePlaneHeight(plane, x, z), sector: index, kind, triangle, normal: plane.normal };
      }
    }
  }
  return { height: nativePlaneHeight(sector.fallback, x, z), sector: index,
    kind: 'fallback', triangle: -1, normal: sector.fallback.normal };
}
