// The surface shadow grid (source/host/shadows.js) against the JS reconstruction's own (its source/kart-shadow.js,
// getSurfaceKartShadowGrid and surfaceKartShadowPositions, imported read-only with its kart03 bounds and S_SHADOW mesh):
// the same points, UVs, colour, indices and lift, the original quad's corners and winding; the footprint from the
// drawn body's box record (quadOverBox, bodyMesh) and the world points through a kart's matrix.
import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync, existsSync } from 'node:fs';
import { join, dirname } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { shadowGridVerts, shadowGridIndices, quadOverBox, bodyMesh, QUAD_BOX, ADDR, SEGMENTS, LIFT } from '../source/host/shadows.js';

const JS = process.env.SUPERKARTS_JS || join(dirname(fileURLToPath(import.meta.url)), '..', '..', 'RedCat Superkarts');
const have = existsSync(join(JS, 'source', 'kart-shadow.js'));
const read = (p) => JSON.parse(readFileSync(join(JS, p), 'utf8'));
const f = Math.fround;

/** The quad as 0x4260c0 leaves it for kart03: D3DLVERTEX words of the JS spec's corners (S_SHADOW Y 0, ARGB 80000000). */
function quadOf(spec) {
  const buf = new ArrayBuffer(4 * 32), qf = new Float32Array(buf), qu = new Uint32Array(buf);
  for (let c = 0; c < 4; c++) {
    qf[c * 8] = spec.position[c * 3]; qf[c * 8 + 1] = spec.position[c * 3 + 1]; qf[c * 8 + 2] = spec.position[c * 3 + 2];
    qu[c * 8 + 4] = 0x80000000; qu[c * 8 + 5] = 0; qf[c * 8 + 6] = spec.uv[c * 2]; qf[c * 8 + 7] = spec.uv[c * 2 + 1];
  }
  return { qf, qu };
}
function grid(quad, W, height) {
  const n = (SEGMENTS + 1) ** 2, buf = new ArrayBuffer(n * 32);
  const out = { f: new Float32Array(buf), u: new Uint32Array(buf) };
  shadowGridVerts(quad.qf, quad.qu, 0, W, height, out.f, out.u, 0);
  return out;
}
const IDENTITY = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];

test('the grid is the JS reconstruction\'s: points, UVs, colour, indices and lift', { skip: !have && 'no JS reconstruction checkout' }, async () => {
  const js = await import(pathToFileURL(join(JS, 'source', 'kart-shadow.js')).href);
  const manifest = read('public/assets/manifest.json'), mesh = read('public/assets/meshes/s_shadow.json');
  assert.deepEqual(mesh.index, [2, 0, 3, 1, 0, 2]);                 // the index list the recomp's trace saw in 0x4260c0
  assert.equal(js.SURFACE_SHADOW_SEGMENTS, SEGMENTS);
  assert.equal(js.SURFACE_SHADOW_LIFT, LIFT);
  const spec = js.getNativeKartShadowSpec(manifest, manifest.meshes['kart03.d3d'].bounds);
  const ref = js.getSurfaceKartShadowGrid(spec, mesh.index);
  const g = grid(quadOf(spec), IDENTITY, (x, z) => 20 + x * 0.01 - z * 0.02);
  assert.equal(ref.count, 81);
  for (let k = 0; k < 81; k++) {
    assert.equal(g.f[k * 8], ref.local[k * 3], 'x ' + k);
    assert.equal(g.f[k * 8 + 2], ref.local[k * 3 + 2], 'z ' + k);
    assert.equal(g.f[k * 8 + 6], ref.uv[k * 2], 'u ' + k);
    assert.equal(g.f[k * 8 + 7], ref.uv[k * 2 + 1], 'v ' + k);
    assert.equal(g.u[k * 8 + 4], 0x80000000);
    assert.deepEqual([...ref.rgba.slice(k * 4, k * 4 + 4)], [0, 0, 0, 128]);
    assert.equal(g.f[k * 8 + 1], f(f(20 + g.f[k * 8] * 0.01 - g.f[k * 8 + 2] * 0.02) + LIFT), 'lift ' + k);
  }
  const idx = new Uint16Array(384);
  assert.equal(shadowGridIndices(mesh.index, idx), 384);
  assert.deepEqual([...idx], ref.index);
});

test('the grid\'s corners are the original quad\'s through its world matrix, every triangle turns as the quad\'s', () => {
  // a quad like 0x4260c0's (maxX/maxZ, minX/maxZ, minX/minZ, maxX/minZ) and a drawn matrix with a turn, a tilt, a
  // shrink and the +2 X/Z
  const spec = { position: [20.1, 0, 36.4, -20.7, 0, 36.4, -20.7, 0, -27.6, 20.1, 0, -27.6], uv: [f(1 - 2 / 64), f(2 / 64), f(2 / 64), f(2 / 64), f(2 / 64), f(1 - 2 / 64), f(1 - 2 / 64), f(1 - 2 / 64)] };
  const a = 0.7, b = 0.1, s = 0.8;
  const W = [s * Math.cos(a), s * Math.sin(b), -s * Math.sin(a), 0, 0, s * Math.cos(b), 0, 0, s * Math.sin(a), 0, s * Math.cos(a), 0, 1000 + 2, 55, -300 + 2, 1].map(f);
  const g = grid(quadOf(spec), W, () => 7);
  [0, 8, 80, 72].forEach((k, c) => {
    const lx = spec.position[c * 3], lz = spec.position[c * 3 + 2];
    assert.ok(Math.abs(g.f[k * 8] - (lx * W[0] + lz * W[8] + W[12])) < 1e-3, 'x of corner ' + c);
    assert.ok(Math.abs(g.f[k * 8 + 2] - (lx * W[2] + lz * W[10] + W[14])) < 1e-3, 'z of corner ' + c);
    assert.equal(g.f[k * 8 + 6], spec.uv[c * 2]); assert.equal(g.f[k * 8 + 7], spec.uv[c * 2 + 1]);
    assert.equal(g.f[k * 8 + 1], f(7 + LIFT));
  });
  const idx = new Uint16Array(384);
  shadowGridIndices([2, 0, 3, 1, 0, 2], idx);
  const xz = (k) => [g.f[k * 8], g.f[k * 8 + 2]];
  const sign = (p, q, r) => Math.sign((q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]));
  const quad = [0, 8, 80, 72].map(xz);
  const want = sign(quad[2], quad[0], quad[3]);
  assert.equal(sign(quad[1], quad[0], quad[2]), want);
  for (let i = 0; i < 384; i += 3) assert.equal(sign(xz(idx[i]), xz(idx[i + 1]), xz(idx[i + 2])), want, 'triangle ' + i / 3);
  assert.equal(Math.max(...idx), 80);
});

/** A mesh box record (0xbc bytes) as the game holds it for bounds b: 8 corners x y z from +0x10, in the order measured
 * at runtime for kart03 and redcar (min/min/min, max/min/min, max/max/min, min/max/min, then the same at maxZ). */
function boxRecord(view, at, b) {
  const corners = [[b.minX, b.minY, b.minZ], [b.maxX, b.minY, b.minZ], [b.maxX, b.maxY, b.minZ], [b.minX, b.maxY, b.minZ],
    [b.minX, b.minY, b.maxZ], [b.maxX, b.minY, b.maxZ], [b.maxX, b.maxY, b.maxZ], [b.minX, b.maxY, b.maxZ]];
  corners.forEach((c, k) => c.forEach((v, a) => view.setFloat32(at + 0x10 + k * 12 + a * 4, v, true)));
}

test('the footprint: kart03\'s box record gives the JS reconstruction\'s quad, the rest of the quad stays the game\'s', { skip: !have && 'no JS reconstruction checkout' }, async () => {
  const js = await import(pathToFileURL(join(JS, 'source', 'kart-shadow.js')).href);
  const manifest = read('public/assets/manifest.json');
  assert.deepEqual(QUAD_BOX, [0x4c, 0x40, 0x10, 0x1c]);
  const buf = new ArrayBuffer(0x400), view = new DataView(buf);
  // the drawn quad as 0x4260c0 leaves it for redcar (the original footprint), then the same quad over kart03's box
  const redcar = js.getNativeKartShadowSpec(manifest, manifest.meshes['redcar.d3d'].bounds);
  const kart03 = js.getNativeKartShadowSpec(manifest, manifest.meshes['kart03.d3d'].bounds);
  const q = quadOf(redcar);
  new Uint32Array(buf, 0x100, 32).set(q.qu);
  boxRecord(view, 0x200, manifest.meshes['kart03.d3d'].bounds);
  const out = new Uint32Array(32), outF = new Float32Array(out.buffer);
  quadOverBox(view, 0x100, 0x200, out);
  for (let c = 0; c < 4; c++) {
    assert.equal(outF[c * 8], kart03.position[c * 3], 'x of corner ' + c);
    assert.equal(outF[c * 8 + 2], kart03.position[c * 3 + 2], 'z of corner ' + c);
    for (const w of [1, 3, 4, 5, 6, 7]) assert.equal(out[c * 8 + w], q.qu[c * 8 + w], 'word ' + w + ' of corner ' + c);
  }
  // 41 x 64 against the original's 28 x 37
  assert.deepEqual([outF[0] - outF[8], outF[2] - outF[18]].map((v) => Math.round(v)), [41, 64]);
  assert.deepEqual([q.qf[0] - q.qf[8], q.qf[2] - q.qf[18]].map((v) => Math.round(v)), [28, 37]);
});

test('the grid\'s world points over kart03\'s box are the JS reconstruction\'s surfaceKartShadowPositions', { skip: !have && 'no JS reconstruction checkout' }, async () => {
  const js = await import(pathToFileURL(join(JS, 'source', 'kart-shadow.js')).href);
  const manifest = read('public/assets/manifest.json'), mesh = read('public/assets/meshes/s_shadow.json');
  const spec = js.getNativeKartShadowSpec(manifest, manifest.meshes['kart03.d3d'].bounds);
  const ref = js.getSurfaceKartShadowGrid(spec, mesh.index);
  // one sector, the whole plane on its positive side (native-track.js nativeSectorAt then returns it), and a flat
  // fallback plane at Y 31.5 (planeHeight: distance / ny)
  const world = { sectors: [{ position: [-1e6, 0, 0], side: [0, 0, 1], triangles: { road: [], land: [], extra: [] }, fallback: { normal: [0, 1, 0], distance: 31.5 } }] };
  for (const [yaw, tilt, s] of [[0, 0, 1], [0.7, 0.1, 0.8], [2.9, -0.2, 1], [-1.3, 0.05, 0.5]]) {
    // the kart's drawn matrix (row vectors) and its place; 0x4260c0 copies it and adds 2 to X/Z (FADD, FSTP float)
    const R = [s * Math.cos(yaw), s * Math.sin(tilt), -s * Math.sin(yaw), 0, s * Math.cos(tilt), 0, s * Math.sin(yaw), 0, s * Math.cos(yaw)].map(f);
    const t = [f(-2353.7), f(12.25), f(7343.2)];
    const body = { matrix: R, position: t, sector: 0 };
    const want = js.surfaceKartShadowPositions(body, world, ref);
    const W = [R[0], R[1], R[2], 0, R[3], R[4], R[5], 0, R[6], R[7], R[8], 0, f(t[0] + 2), 99, f(t[2] + 2), 1];
    const g = grid(quadOf(spec), W, () => 31.5);
    for (let k = 0; k < 81; k++) {
      // bit for bit, although the JS reconstruction adds the 2 in double and 0x4260c0 in float
      for (const a of [0, 1, 2]) assert.equal(g.f[k * 8 + a], want[k * 3 + a], `${'xyz'[a]} of point ${k} (yaw ${yaw})`);
    }
  }
});

test('bodyMesh: the mesh 0x490d40/0x4a0d80 draw for a kart slot', () => {
  const buf = new ArrayBuffer(0x6a7000), view = new DataView(buf), u32 = new Uint32Array(buf);
  const m = { view, u32 };
  const OBJ = 0x10000, ANIM = 0x20000, FR = 0x30000, KART = 0x40000, TAB = 0x50000;
  u32[ADDR.OBJECTS >> 2] = OBJ; u32[ADDR.ANIMS >> 2] = ANIM; u32[ADDR.FRAMES >> 2] = FR;
  const obj = OBJ + 7 * 0xa9;                                         // unaligned, as the game's objects are
  view.setInt32(KART + 0xc, 7, true);
  view.setInt32(obj, 2, true); view.setInt32(obj + 4, 3, true); view.setInt32(obj + 8, 1, true);
  view.setUint32(ANIM + 3 * 9 + 4, TAB, true); view.setInt32(TAB + 4, 6, true); view.setInt32(FR + 6 * 0x10, 2, true);
  view.setInt32(KART + 0xc8, -1, true); view.setInt32(KART + 0xcc, -1, true);
  view.setInt32(obj + 0x99, 1304, true);
  assert.equal(bodyMesh(m, KART), 1304);                              // the object's own drawn mesh (kart03's copy)
  view.setInt32(obj + 0x99, -1, true);
  assert.equal(bodyMesh(m, KART), 2);                                 // its animation frame's (redcar, 0x490ce0's)
  view.setInt32(KART + 0xcc, 55, true);
  assert.equal(bodyMesh(m, KART), 2);                                 // +0xcc alone does not count (0x490d5a)
  view.setInt32(KART + 0xc8, 9, true);
  assert.equal(bodyMesh(m, KART), 55);                                // both set: 0x490d40 draws +0xcc
});
