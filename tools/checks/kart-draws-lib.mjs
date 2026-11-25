// Kart draws per picture, for the checks of the renders that no object pass precedes (source/host/render-replay.js):
// the pause entry's (tools/check-safeguards.mjs pause) and free flight's (tools/checks/flight.mjs).
//
// A kart is drawn as its body and five parts (four wheels of 30 vertices and the driver, 0x490d40) plus, for a racer,
// its shadow quad (4 vertices, 0x4260c0), each through SetTransform(WORLD) with the object's matrix (0x4a0d80). A part
// drawn on a second body matrix lands thousands of units away (7,300 on Nederland's grid), so the draws within reach of
// each kart's body (its render object's place, +0x40) tell whether the kart is drawn whole: the same vertex counts as
// in the picture before, and four wheels.
//
// recordFrames(r): wraps r.host.render (a makeRace race of tools/checks/full-race-gaps-lib.mjs) so every flip keeps
// its scene draws ({ nv, t: world translation }) and HUD draws (vertex hash) in r.frames; r.frames is emptied by the
// caller. karts(r): the slots with parts (index, body place). nearSets(frame, karts): per kart the sorted vertex counts
// of the scene draws within REACH of its body and nearer to it than to the others (on the grids of Spanje and
// Italie a neighbour's wheels come within reach: measured 2026-11-25, etappes 4 and 5).
export const REACH = 60;          // render-replay.js PART_OFF: the farthest part measured 30 units from its body
export const WHEEL_VERTICES = 30; // each wheel's mesh (measured on all six tracks, the four characters)

export function recordFrames(r) {
  const rr = r.host.render, m = r.m;
  let W = null, scene = [], hud = [];
  r.frames = [];
  const hash = (p, n) => { let h = 0; for (let k = 0; k < n; k++) h = (Math.imul(h, 31) + (m.u32[(p >> 2) + k] | 0)) | 0; return h >>> 0; };
  const setTransform = rr.setTransform, drawIndexed = rr.drawIndexed, drawPrimitive = rr.drawPrimitive;
  rr.setTransform = (t, p, ...a) => { if (t === 1) W = [12, 13, 14].map((k) => m.f32[(p >> 2) + k]); return setTransform.call(rr, t, p, ...a); };
  const add = (vt, v, nv) => {
    if (rr.hud) hud.push(hash(v, nv * 8) + ':' + (W ? W.join(',') : ''));
    else scene.push({ nv, t: W ? W.slice() : null });
  };
  rr.drawIndexed = (prim, vt, v, nv, ...a) => { add(vt, v, nv); return drawIndexed.call(rr, prim, vt, v, nv, ...a); };
  rr.drawPrimitive = (prim, vt, v, nv, ...a) => { add(vt, v, nv); return drawPrimitive.call(rr, prim, vt, v, nv, ...a); };
  const onFlip = r.host.onFlip;
  r.host.onFlip = (...a) => { r.frames.push({ scene, hud }); scene = []; hud = []; return onFlip.apply(r.host, a); };
  return r;
}

/** The karts: engine slots (u32 0x67ee20, 0xd0 each) with parts (+0x8c), their body's place (object +0x40). */
export function karts(r) {
  const T = r.u32(0x67ee20), objs = r.u32(0x6a5c38), used = r.u32(0x67ee30);
  const out = [];
  for (let i = 0; i < r.i32(0x67ee24); i++) {
    if (r.m.u8[used + i] !== 1) continue;
    const slot = T + i * 0xd0, n = r.i32(slot + 0x8c);
    if (n <= 0 || n > 10) continue;
    const body = objs + r.i32(slot + 0xc) * 0xa9;
    out.push({ i, at: [r.f32(body + 0x40), r.f32(body + 0x44), r.f32(body + 0x48)] });
  }
  return out;
}

/** Per kart: the sorted vertex counts of the frame's scene draws within REACH of its body and nearer to it than to any other. */
export function nearSets(frame, ks) {
  const sets = ks.map(() => []);
  for (const d of frame.scene) {
    if (!d.t) continue;
    let best = -1, bd = REACH;
    ks.forEach((k, j) => { const e = Math.hypot(d.t[0] - k.at[0], d.t[1] - k.at[1], d.t[2] - k.at[2]); if (e < bd) { bd = e; best = j; } });
    if (best >= 0) sets[best].push(d.nv);
  }
  return sets.map((s) => s.sort((a, b) => a - b));
}

/** A kart drawn whole: four wheels among its near draws. */
export const whole = (set) => set.filter((nv) => nv === WHEEL_VERTICES).length === 4;
