// Two of the JS reconstruction's race visuals, added around the original code (docs/intentional-differences.md, Kart
// shadow and Engine light): "Schaduwen op het wegdek" (settings.surfaceShadows) and "Motorlicht volgt de kart"
// (settings.smoothEngineLights), both on by default (its settings.js:4) and switched during a race through CTRL.OPTIONS
// (OPT.SURFACE_SHADOWS, OPT.SMOOTH_ENGINE_LIGHTS), which the game worker copies to host.options before every pass.
// Neither changes the game's state: the original code runs as it is in both modes, and only what the recorder sends
// (source/render/recorder.js, tagger) and how the renderer blends it (gl-renderer.js, TAG) differ.
//
// Kart shadow (all confirmed in the export unless marked). init_main registers 0x4260c0 as the shadow callback
// (0x42d7d0 -> 0x4264c0 -> 0x493190 writes 0x6802c4); 0x4918f0 calls it through 0x4931a0(k) right before it draws
// kart k, for the slots whose +0x28 is not -1 (the five racers; their +0x28 is 0, one shared shadow object, measured).
// 0x4260c0 writes the S_SHADOW quad's X/Z corners from a mesh box (0x490ce0's; Footprint below), copies the kart's drawn matrix
// (tilt, scale, a rescue's shrink) into the shadow object with X/Z + 2, puts its Y on the sector's fallback plane
// (0x494b70, capped by the kart's Y) and draws it through 0x4a0d80: SetTransform(WORLD, 0x6a61dc), then one
// DrawIndexedPrimitive (type 4, vtype 2, 4 vertices at mesh+0x80, indices 2,0,3,1,0,2, ARGB 80000000, SRCALPHA /
// INVSRCALPHA; runtime trace, 6743 calls on Nederland). That plane can lie far under the road (Frankrijk's start:
// Y 0, the road at 20 and more), and the shadow is then hidden under it. 0x4260c0 is a wrap hook (build.py GAME_HOOKS
// 'KartShadow', reached only by address through 0x6802c4): the wrapper below marks the call and runs the body; the
// tagger sees its one draw and, with the setting on, sends instead the JS reconstruction's 8x8 grid over the quad
// (its kart-shadow.js:36-77) in world coordinates, every point 0.25 above the ground the game's own triangle
// search finds under it: 0x4977d0 the sector from the kart's route hint +0x1c, 0x495fe0 the first upward face of
// that sector (ny > 0.4; else none), 0x496290 its height or the fallback plane's (the call shapes of the rescue code,
// 0x4169cb..0x416a55; the JS reconstruction's nativeTrackHeight, native-track.js:208, is the same sequence). The
// texture, the colour, the blend states and the place in the draw order stay the game's. Off: the original quad.
//
// Footprint. 0x4260c0 takes the quad's X/Z corners (0x42616a..0x426262: box corners +0x4c, +0x40, +0x10, +0x1c into
// vertices 0..3) from the box record of the mesh 0x490ce0 names for the kart object; for its type 2 that is the
// animation frame's mesh, redcar.d3d (gen_anim.ini [racer_N] part 0, 54 vertices, 28 x 37 units), but 0x4a0d80 draws
// the object's +0x99 mesh when it is set, and for every racer it is a copy of kart03.d3d (193 vertices, 41 x 64;
// measured in six races that cover the six countries, the four characters and race types 0-3, 2026-11-25: +0x99
// 1301..1304 and 6 at Frankrijk).
// The JS reconstruction sizes its shadow, on and off, by the drawn body's mesh (race-visuals.js:144
// getNativeKartShadowSpec(manifest, bodySpec.bounds); player-assets.js:63-65, car_ssr.ini [indy] mesh=kart03.d3d for
// every racer, driving-view.js:128-129), so from the chase camera its shadow shows around the kart where the
// original's lies under it. With the setting on the grid therefore spans the drawn body's box (bodyMesh below: the
// mesh 0x490d40/0x4a0d80 draw; its record's corners are the JS manifest's kart03 bounds, bit for bit), through the
// same world matrix; off, the original quad is drawn as 0x4260c0 left it.
//
// Engine light (confirmed in the export unless marked). 0x488b40 draws the flare pool *(*(*(0x545100)+4)+4) (0x17c
// a flare) through 0x4888b0: a 4-vertex strip (DrawPrimitive type 5, vtype 2) whose vertices are the flare itself, in
// world coordinates with the identity world matrix; +0x138 is its owner's engine slot (0x488850 compares it with the
// player's 0x53be28). The game builds the flare and draws the kart from the same place each pass; the renderer then
// blends the kart between two passes, while the flare's vertices, which move 14 units a pass at racing speed, were cut
// loose by its 10-unit vertex rule and shown at the newer pass, about 7 units ahead of the kart (2026-11-25 probe,
// Frankrijk: 13517 of 20332 flare pairings). With the setting on, a racer's flare is tagged FOLLOW with its kart, so it
// is blended with it; off, HOLD: at the newer pass, as the JS reconstruction draws it off (race-visuals.js:503-525).
// Flares of other owners (rockets, inferred: short-lived slots without a shadow) always follow theirs: the JS
// reconstruction draws a rocket's flare on its rocket, which it does not blend, and the recomp blends rockets.
import { TAG } from '../render/recorder.js';
import { OPT } from '../web/shared.js';

export const SEGMENTS = 8;         // SURFACE_SHADOW_SEGMENTS (kart-shadow.js:36): 81 points, 384 indices
export const LIFT = 0.25;          // SURFACE_SHADOW_LIFT (kart-shadow.js:39), with the renderer's polygon offset
export const DEFAULT_OPTIONS = OPT.SURFACE_SHADOWS | OPT.SMOOTH_ENGINE_LIGHTS;      // settings.js:4, both on

export const ADDR = {
  KART_SHADOW: 0x004260c0,   // the shadow callback, wrapped as 'KartShadow' (cdecl, the engine slot; plain RET 0x4264b1)
  KARTS: 0x0067ee20,         // engine slots, 0xd0 each: +0xc object index, +0x1c route chunk (the sector hint), +0x28 shadow object or -1
  KART_COUNT: 0x0067ee24,
  OBJECTS: 0x006a5c38,       // objects, 0xa9 each (unaligned): +0 type, +4 animation, +8 frame, +0x10 the drawn matrix (its place at +0x40/+0x44/+0x48), +0x99 mesh or -1
  MESHES: 0x006a5ee0,        // mesh records, 0xbc each: +0x10 the box, 8 corners x y z (0x4aa0c0), +0x80 vertices, +0x84 their count
  ANIMS: 0x006a5f78,         // animations, 9 bytes each (unaligned): +4 the frame table (frame -> entry)
  FRAMES: 0x006a5f30,        // animation entries, 0x10 each: +0 mesh
  PLAYER: 0x0053be28,        // the player's engine slot
  ROUTE: 0x00680218,         // this of 0x4977d0
  SECTORS: 0x00680b28,       // sectors, 0x984 each
  SECTOR_AT: 0x004977d0,     // thiscall ROUTE (int hint, vec3 by value: x, y unused, z) -> sector, RET 0x10
  FACE_AT: 0x00495fe0,       // thiscall sector (vec3, int *index, int *kind, int *tri), kind 1, 0, 2 or -1, RET 0x18
  FACE_HEIGHT: 0x00496290,   // thiscall sector (vec3, int kind, int tri) -> ST0, the fallback plane for kind -1, RET 0x14
  FLARES: 0x00545100,        // the flare pool's owner: data at *(*(*(0x545100)+4)+4)
};
const FLARE = { SIZE: 0x17c, OWNER: 0x138, VERTS: 0x154, MAX: 64 };

/** The box corners 0x4260c0 copies into the quad's vertices 0..3, X at +0 and Z at +8 (read 0x42617c..0x4261d7,
 * written 0x4261da..0x426262). In the box's corner order (minX/minZ at +0x10, maxX/minZ at +0x1c, minX/maxZ at +0x40,
 * maxX/maxZ at +0x4c, these four at minY; measured) that is maxX/maxZ, minX/maxZ, minX/minZ, maxX/minZ, the JS
 * reconstruction's spec.position order (kart-shadow.js:12-13). */
export const QUAD_BOX = [0x4c, 0x40, 0x10, 0x1c];

/**
 * The mesh the game draws for kart slot `kart`'s body: 0x490d40 puts the slot's +0xcc into the object's +0x99 for the
 * draw when both +0xcc and +0xc8 are set (0x490d4c..0x490d91); 0x4a0d80 draws +0x99, or when that is -1 the mesh of
 * the object's animation frame (0x4a0ecf..), which is also what 0x490ce0 returns for a type 2 object. Reads only.
 */
export function bodyMesh(m, kart) {
  const v = m.view;
  const override = v.getInt32(kart + 0xcc, true);
  if (override !== -1 && v.getInt32(kart + 0xc8, true) !== -1) return override;
  const obj = m.u32[ADDR.OBJECTS >> 2] + v.getInt32(kart + 0xc, true) * 0xa9;
  const mesh = v.getInt32(obj + 0x99, true);
  if (mesh !== -1) return mesh;
  const frames = v.getUint32(m.u32[ADDR.ANIMS >> 2] + v.getInt32(obj + 4, true) * 9 + 4, true);
  return v.getInt32(m.u32[ADDR.FRAMES >> 2] + v.getInt32(frames + v.getInt32(obj + 8, true) * 4, true) * 0x10, true);
}

/**
 * The quad 0x4260c0 would write for a mesh's box: the 32 words of the drawn quad at quadAt (D3DLVERTEX x y z reserved
 * colour specular u v, 4 vertices) copied to outU, with each vertex's X and Z taken from the box record at boxAt as
 * 0x4260c0 takes them (QUAD_BOX); Y, colour and UV stay the quad's (S_SHADOW's). Bits are copied, nothing rounds.
 */
export function quadOverBox(view, quadAt, boxAt, outU) {
  for (let w = 0; w < 32; w++) outU[w] = view.getUint32(quadAt + w * 4, true);
  for (let c = 0; c < 4; c++) {
    outU[c * 8] = view.getUint32(boxAt + QUAD_BOX[c], true);
    outU[c * 8 + 2] = view.getUint32(boxAt + QUAD_BOX[c] + 8, true);
  }
  return outU;
}

/**
 * The surface grid's vertices over a quad like 0x4260c0's: the JS reconstruction's getSurfaceKartShadowGrid and
 * surfaceKartShadowPositions (kart-shadow.js:44-77). The quad's four corners (D3DLVERTEX, 8 words: x y z reserved
 * colour specular u v) are read from qf/qu at word qAt; point (i, j) is their bilinear blend at s = i/n, t = j/n, so
 * for the axis-aligned quad 0x4260c0 writes (maxX/maxZ, minX/maxZ, minX/minZ, maxX/minZ) X and U run along s, Z and
 * V along t, as in the JS reconstruction. W: the world matrix the quad is drawn with (Direct3D row vectors, the +2
 * X/Z included); height(x, z): the ground under a world point. Writes (n+1)^2 vertices in world coordinates, 8 words
 * each, to f32/u32 from word vAt, with the first corner's colour and specular.
 */
export function shadowGridVerts(qf, qu, qAt, W, height, f32, u32, vAt, n = SEGMENTS) {
  const f = Math.fround;
  const color = qu[qAt + 4], specular = qu[qAt + 5];
  // the corners' x y z u v (words 0 1 2 6 7)
  const c = [0, 1, 2, 6, 7].map((k) => [qf[qAt + k], qf[qAt + 8 + k], qf[qAt + 16 + k], qf[qAt + 24 + k]]);
  for (let j = 0; j <= n; j++) {
    const t = j / n;
    for (let i = 0; i <= n; i++) {
      const s = i / n;
      const w0 = (1 - s) * (1 - t), w1 = s * (1 - t), w2 = s * t, w3 = (1 - s) * t;
      const mix = (q) => f(w0 * q[0] + w1 * q[1] + w2 * q[2] + w3 * q[3]);
      const lx = mix(c[0]), ly = mix(c[1]), lz = mix(c[2]);
      // sampled at the float place the point is drawn at (kart-shadow.js:70-71)
      const x = f(lx * W[0] + ly * W[4] + lz * W[8] + W[12]);
      const z = f(lx * W[2] + ly * W[6] + lz * W[10] + W[14]);
      const d = vAt + (j * (n + 1) + i) * 8;
      f32[d] = x; f32[d + 1] = f(height(x, z) + LIFT); f32[d + 2] = z; u32[d + 3] = 0;
      u32[d + 4] = color; u32[d + 5] = specular;
      f32[d + 6] = mix(c[3]); f32[d + 7] = mix(c[4]);
    }
  }
}

/** The grid's indices: every cell repeats the quad's own index list over its corners (i,j), (i+1,j), (i+1,j+1),
 * (i,j+1), the quad's corners 0..3, so its triangles keep the original's winding (kart-shadow.js:54-58). */
export function shadowGridIndices(quadIndex, out, at = 0, n = SEGMENTS) {
  let o = at;
  for (let j = 0; j < n; j++) {
    for (let i = 0; i < n; i++) {
      const c0 = j * (n + 1) + i, corner = [c0, c0 + 1, c0 + n + 2, c0 + n + 1];
      for (const q of quadIndex) out[o++] = corner[q];
    }
  }
  return o - at;
}

/**
 * Installs both on a Race's machine (race.js instantiate): the wrapper of 0x4260c0 and host.render.tagger.
 * host.options: the OPT bits of the pass (the game worker; without it both are on, the JS defaults); host.flightActive:
 * free flight is on, the player's shadow is left out (the JS reconstruction hides it, driving-view.js:228; the game
 * still runs the callback).
 */
export function installShadows(m, host) {
  const npts = (SEGMENTS + 1) * (SEGMENTS + 1), nidx = SEGMENTS * SEGMENTS * 6;
  const grid = m.lowAlloc(npts * 32), gridIdx = m.lowAlloc(nidx * 2), outs = m.lowAlloc(12);
  const opts = () => host.options ?? DEFAULT_OPTIONS;
  const bits = new Float32Array(1), bitsU = new Uint32Array(bits.buffer);
  const fbits = (x) => { bits[0] = x; return bitsU[0]; };
  let cur = -1, surface = false, hint = 0, idxSig = '';
  const quadU = new Uint32Array(32), quadF = new Float32Array(quadU.buffer);   // the quad over the body's box
  // mesh: the body mesh of the last grid
  const stats = host.shadowStats = { callbacks: 0, grids: 0, points: 0, kinds: { '-1': 0, 0: 0, 1: 0, 2: 0 }, flares: 0, ms: 0, mesh: -1 };

  const hook = m.meta.hooks && m.meta.hooks.KartShadow;
  if (hook && hook.kind === 'wrap' && hook.addr === ADDR.KART_SHADOW) {
    m.wrap('KartShadow', (esp, ecx, edx, eax, next) => {
      cur = m.i32[(esp + 4) >> 2];
      surface = (opts() & OPT.SURFACE_SHADOWS) !== 0;
      stats.callbacks++;
      try { return next(esp, ecx, edx, eax); } finally { cur = -1; }
    });
  } else if (host.log) host.log('shadows: no KartShadow wrap hook in this build, the original shadows stay');

  /** The ground under a world point: the rescue code's sequence (0x4169cb..0x416a55) from the kart's hint. */
  const height = (x, z) => {
    const xb = fbits(x), zb = fbits(z);
    const s = m.call(ADDR.SECTOR_AT, [hint, xb, 0, zb], ADDR.ROUTE);
    const sec = (m.u32[ADDR.SECTORS >> 2] + s * 0x984) >>> 0;
    m.call(ADDR.FACE_AT, [xb, 0, zb, outs, outs + 4, outs + 8], sec);
    const kind = m.i32[(outs + 4) >> 2];
    stats.kinds[kind] = (stats.kinds[kind] || 0) + 1;
    m.call(ADDR.FACE_HEIGHT, [xb, 0, zb, kind >>> 0, m.u32[(outs + 8) >> 2]], sec);
    return m.gSt0.value;
  };

  const shadowTag = { id: 0, flags: 0, ox: 0, oy: 0, oz: 0, drop: false, verts: 0, nverts: 0, indices: 0, nindices: 0, worldSpace: false };
  const flareTag = { id: 0, flags: 0, ox: 0, oy: 0, oz: 0, drop: false, verts: 0, worldSpace: false };
  const DROP = { drop: true };
  /** The owner's place: its object's drawn matrix (what 0x4a0d80 hands SetTransform for the kart), row 3. */
  const owner = (slot, tag) => {
    const kart = m.u32[ADDR.KARTS >> 2] + slot * 0xd0;
    const obj = m.u32[ADDR.OBJECTS >> 2] + m.i32[(kart + 0xc) >> 2] * 0xa9;
    tag.ox = m.view.getFloat32(obj + 0x40, true); tag.oy = m.view.getFloat32(obj + 0x44, true); tag.oz = m.view.getFloat32(obj + 0x48, true);
    return kart;
  };

  const tagger = (prim, vtype, verts, nverts, indices, nindices, world) => {
    if (vtype !== 2) return null;
    if (cur >= 0) {
      // the shadow callback's one draw (0x4a96b0 from 0x4a0d80)
      if (prim !== 4 || nverts !== 4 || nindices !== 6) return null;
      const k = cur;
      cur = -1;
      if (host.flightActive && k === m.i32[ADDR.PLAYER >> 2]) return DROP;
      const kart = owner(k, shadowTag);
      shadowTag.id = k + 1;
      if (!surface) {
        // the original quad; the tag only pairs it with the same kart's in the pass before
        shadowTag.flags = TAG.FOLLOW; shadowTag.verts = 0; shadowTag.worldSpace = false;
        return shadowTag;
      }
      const t0 = performance.now();
      const sig = m.u16[indices >> 1] + ',' + m.u16[(indices >> 1) + 1] + ',' + m.u16[(indices >> 1) + 2] + ',' + m.u16[(indices >> 1) + 3] + ',' + m.u16[(indices >> 1) + 4] + ',' + m.u16[(indices >> 1) + 5];
      if (sig !== idxSig) { idxSig = sig; shadowGridIndices(sig.split(',').map(Number), m.u16, gridIdx >> 1); }
      // the game's registers a nested call may change; the callers keep none of them across a COM call, but they are
      // put back so the draw leaves no trace
      const st0 = m.gSt0.value, edxG = m.gEdx.value, cw = m.gCw.value;
      hint = m.i32[(kart + 0x1c) >> 2];
      // the footprint of the body the game draws (the JS reconstruction's), not of 0x490ce0's never-drawn mesh: the
      // head of this file; a body without a mesh (none seen) keeps the original quad's
      const mesh = bodyMesh(m, kart);
      if (mesh >= 0) quadOverBox(m.view, verts, m.u32[ADDR.MESHES >> 2] + mesh * 0xbc, quadU);
      else for (let w = 0; w < 32; w++) quadU[w] = m.u32[(verts >> 2) + w];
      stats.mesh = mesh;
      shadowGridVerts(quadF, quadU, 0, world, height, m.f32, m.u32, grid >> 2);
      m.gSt0.value = st0; m.gEdx.value = edxG; m.gCw.value = cw;
      stats.grids++; stats.points += npts; stats.ms += performance.now() - t0;
      shadowTag.flags = TAG.FOLLOW | TAG.DECAL;
      shadowTag.verts = grid; shadowTag.nverts = npts; shadowTag.indices = gridIdx; shadowTag.nindices = nidx; shadowTag.worldSpace = true;
      return shadowTag;
    }
    if (prim !== 5) return null;
    // an engine flare (0x4888b0): its vertices are the flare in the pool
    const mg = m.u32[ADDR.FLARES >> 2];
    if (!mg) return null;
    const data = m.u32[(m.u32[(mg + 4) >> 2] + 4) >> 2];
    const d = verts - data;
    if (d < 0 || d % FLARE.SIZE || d / FLARE.SIZE >= FLARE.MAX || m.i32[(verts + FLARE.VERTS) >> 2] !== nverts) return null;
    const slot = m.i32[(verts + FLARE.OWNER) >> 2];
    if (slot < 0 || slot >= m.i32[ADDR.KART_COUNT >> 2]) return null;
    const kart = owner(slot, flareTag);
    stats.flares++;
    flareTag.id = slot + 1;
    // a racer (a kart with a shadow, the gate 0x4918f0 uses): HOLD when the setting is off
    const racer = m.i32[(kart + 0x28) >> 2] !== -1;
    flareTag.flags = racer && !(opts() & OPT.SMOOTH_ENGINE_LIGHTS) ? TAG.HOLD : TAG.FOLLOW;
    return flareTag;
  };
  if (host.render) host.render.tagger = tagger;
  return { tagger, stats };
}
