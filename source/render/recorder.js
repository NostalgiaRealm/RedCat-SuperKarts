// The renderer as the game thread (source/web/worker.js) sees it: every Direct3D call and every 2D change of a
// screen is written down, and each frame goes to the render worker (source/web/render-worker.js) as one message,
// which replays it on the WebGL renderer (gl-renderer.js). The game thread never returns to its event loop while
// the race runs (its own waits: the pause, the quit requester), so no GPU object may live there: a picture made
// in such a thread is never freed (RedCat Spookkasteel, source/render/remote.js there, measured 8 MB per frame).
//
// A frame ends at Flip (FLIP), or at a 2D change of the front screen, which is on view at once (PRESENT).
// One frame is { buf, nc, nv, ni, nb, t }: nc commands (float64), nv vertices (8 uint32 each: the D3DLVERTEX
// layout x y z reserved color specular u v), ni indices (uint32, counted from their draw's base vertex), nb bytes
// of pixels (RGBA); t, the time of the pass that made it (performance.timeOrigin + now(), ms), for smoothing. It travels in one of two shared buffers used in turn, or in a buffer of its own when it does
// not fit or the render worker is behind.
import { CTRL } from '../web/shared.js';

export const CMD = {
  STATE: 1,       // state, value
  TRANSFORM: 2,   // type, 16 floats
  VIEWPORT: 3,    // x, y, w, h, clipX, clipY, clipW, clipH
  TEXTURE: 4,     // id, w, h, byte offset (RGBA)
  FREE: 5,        // id
  DRAW: 6,        // prim, vtype, first vertex, count, texture id (0 none), flags (1: the HUD's, 2: the finish flag's sheet)
  DRAWIDX: 7,     // prim, vtype, first index, count, texture id, base vertex, vertex count (indices count from the base), flags
  CLEAR: 8,       // flags (1 target, 2 z)
  IMAGE: 9,       // target (0 back, 1 front), x, y, w, h (screen pixels), source w, h, keyed, byte offset (RGBA)
  FILL: 10,       // target, x, y, w, h, rgb
  FLIP: 11,
  PRESENT: 12,
  MODE: 13,       // w, h
  TAG: 14,        // id, flags (TAG), owner x, y, z: what the next DRAW or DRAWIDX belongs to (source/host/shadows.js)
  CLIP: 15,       // x, y, w, h, mode: the HUD's draws after it are cut to that rect of the drawing (fractions, from its
                  // top left; w 0: not cut), their group's frame (source/host/hud-layout.js); mode 2: also drawn into
                  // it, the rect as the viewport with the game's 4:3 clip
};
// Words per command (the opcode included), for every reader of a frame (gl-renderer.js, render-worker.js)
export const CMD_SIZE = [1, 3, 18, 9, 5, 2, 7, 9, 2, 10, 7, 1, 1, 3, 6, 6];
// TAG flags. FOLLOW: the draw belongs to the object (a kart, a rocket) whose place is the owner x, y, z: it pairs only
// with the same id in the pass before, and its vertices are blended unless the owner jumped (the renderer's TELEPORT,
// the test the owner's own matrix gets), so it moves with the owner. HOLD: never blended (the newer pass). DECAL: lies
// on the ground (drawn with a polygon offset and no depth writes).
export const TAG = { DECAL: 1, FOLLOW: 2, HOLD: 4 };
const SLOT_BYTES = 8 << 20;
// The finish flag (gfx_flag, 0x4235c0): a waving sheet of ten strips of 34 vertices, one array per strip from
// 0x5091a0 in steps of 0x440 (drawn at 0x4237db; seen in a finish), fixed to the camera and sized for 4:3. The
// renderer grows it on other shapes so its edges stay off screen.
const FLAG_VERTS = [0x005091a0, 0x005091a0 + 10 * 34 * 32];
const AHEAD = 1;
const STALL_MS = 2000;

/** RGB 565 -> RGBA bytes, the keyed texel transparent (alpha 0, black). */
export function rgbaOf(u16, ptr, pitch, sx, sy, w, h, key, out, at) {
  for (let y = 0; y < h; y++) {
    let s = (ptr + (sy + y) * pitch + sx * 2) >> 1;
    let d = at + y * w * 4;
    for (let x = 0; x < w; x++, s++, d += 4) {
      const c = u16[s];
      if (c === key) { out[d] = 0; out[d + 1] = 0; out[d + 2] = 0; out[d + 3] = 0; continue; }
      out[d] = ((c >> 11) * 527 + 23) >> 6;
      out[d + 1] = (((c >> 5) & 63) * 259 + 33) >> 6;
      out[d + 2] = ((c & 31) * 527 + 23) >> 6;
      out[d + 3] = 255;
    }
  }
}

/**
 * port: MessagePort to the render worker; ctrl: shared control words (or null: frames are only counted);
 * opts.race: the race's number on this page. One recorder per race: the render worker keeps its canvas and
 * renderer across races, so a new recorder first tells it to drop the last race's textures and state
 * ({ reset: true, race }, render-worker.js), and counts its frames on from CTRL.FRAMES (the render worker's count
 * since the page started), which pace() compares with what it sent. close() waits until the render worker has
 * drawn every frame sent (so the next race starts from an exact count) and tells it to free the race's textures.
 */
export function createRecorder(port, ctrl, opts = {}) {
  let cmd = new Float64Array(65536), nc = 0;
  let vb = new Uint32Array(1 << 19), nv = 0;           // vertices (8 words each)
  let ib = new Uint32Array(1 << 18), ni = 0;
  let bytes = new Uint8Array(1 << 20), nb = 0;
  const grow = (a, n) => { const b = new a.constructor(Math.max(a.length * 2, n)); b.set(a); return b; };
  const want = (n) => { if (nc + n > cmd.length) cmd = grow(cmd, nc + n); };
  const wantBytes = (n) => { if (nb + n > bytes.length) bytes = grow(bytes, nb + n); };
  const slots = ctrl && typeof SharedArrayBuffer === 'function' ? [new SharedArrayBuffer(SLOT_BYTES), new SharedArrayBuffer(SLOT_BYTES)] : null;
  const slotViews = slots && slots.map((buf) => ({ f64: new Float64Array(buf), u32: new Uint32Array(buf), u8: new Uint8Array(buf), msg: { buf, nc: 0, nv: 0, ni: 0, nb: 0, t: 0 } }));
  let sent = ctrl ? Atomics.load(ctrl, CTRL.FRAMES) : 0, off = false, nextTex = 1;
  if (port) port.postMessage({ reset: true, race: opts.race ?? 0 });
  let m = null, host = null;
  const textures = new Set();       // source surfaces with a texture id
  let bound = -1;
  // the device's world matrix as the game last set it (SetTransform 1): what a draw that a tag moves to world
  // coordinates (tag.worldSpace) is put back to after it, so the draws after it see the game's device state
  const world = new Float32Array([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
  const IDENTITY = new Float32Array([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
  const transform = (type, f) => { want(18); cmd[nc++] = CMD.TRANSFORM; cmd[nc++] = type; for (let k = 0; k < 16; k++) cmd[nc++] = f[k]; };
  /** A tag (r.tagger's answer) before its draw. */
  const tagCmd = (tag) => {
    want(6); cmd[nc++] = CMD.TAG; cmd[nc++] = tag.id; cmd[nc++] = tag.flags; cmd[nc++] = tag.ox; cmd[nc++] = tag.oy; cmd[nc++] = tag.oz;
    const st = r.stats;
    if (tag.flags & TAG.DECAL) st.decals++;
    if (tag.flags & TAG.FOLLOW) st.follow++;
    if (tag.flags & TAG.HOLD) st.hold++;
  };
  // The HUD's cut (hudClip): the rect its next draws get, and the last one written. Written only before a HUD draw
  // that needs another one: the game asks before every group, also those that draw nothing (hidden).
  let clipWanted = null, clipWritten = null;
  const sameRect = (a, b) => a === b || (a !== null && b !== null && a.x === b.x && a.y === b.y && a.w === b.w && a.h === b.h && !a.frame === !b.frame);
  const clipCmd = () => {
    if (sameRect(clipWanted, clipWritten)) return;
    const c = clipWanted;
    want(6); cmd[nc++] = CMD.CLIP; cmd[nc++] = c ? c.x : 0; cmd[nc++] = c ? c.y : 0; cmd[nc++] = c ? c.w : 0; cmd[nc++] = c ? c.h : 0; cmd[nc++] = c && c.frame ? 2 : 1;
    clipWritten = c;
  };

  const texOf = (surface) => {
    if (!surface) return 0;
    const src = surface.source || surface;
    if (!src.texId) { src.texId = nextTex++; textures.add(src); }
    if (src.sentGeneration !== src.generation) {
      const w = src.width, h = src.height;
      const ptr = src.memory();
      wantBytes(w * h * 4);
      const at = nb;
      if (src.format.a === 0xF000) {
        const u16 = m.u16;
        for (let y = 0; y < h; y++) {
          let s = (ptr + y * src.pitch) >> 1, d = at + y * w * 4;
          for (let x = 0; x < w; x++, s++, d += 4) {
            const c = u16[s];
            bytes[d] = ((c >> 8) & 15) * 17; bytes[d + 1] = ((c >> 4) & 15) * 17; bytes[d + 2] = (c & 15) * 17; bytes[d + 3] = ((c >> 12) & 15) * 17;
          }
        }
      } else {
        // the texel the game keys is 0 in memory (8-bit index 254 packed to 0 when converted): docs/host.md
        rgbaOf(m.u16, ptr, src.pitch, 0, 0, w, h, src.colorKey === -1 ? 0 : src.colorKey & 0xFFFF, bytes, at);
      }
      nb += w * h * 4;
      want(5);
      cmd[nc++] = CMD.TEXTURE; cmd[nc++] = src.texId; cmd[nc++] = w; cmd[nc++] = h; cmd[nc++] = at;
      src.sentGeneration = src.generation;
    }
    return src.texId;
  };

  const pushVerts = (vtype, verts, count) => {
    if ((nv + count) * 8 > vb.length) vb = grow(vb, (nv + count) * 8);
    const u32 = m.u32;
    let p = verts >> 2, d = nv * 8;
    if (vtype === 1) {
      // D3DVERTEX: no light is ever created (no CreateLight call), drawn white as A2 Racer 4 does
      for (let k = 0; k < count; k++, p += 8, d += 8) {
        vb[d] = u32[p]; vb[d + 1] = u32[p + 1]; vb[d + 2] = u32[p + 2]; vb[d + 3] = 0;
        vb[d + 4] = 0xFFFFFFFF; vb[d + 5] = 0; vb[d + 6] = u32[p + 6]; vb[d + 7] = u32[p + 7];
      }
    } else {
      for (let k = 0, n = count * 8; k < n; k++) vb[d + k] = u32[p + k];
    }
    const first = nv;
    nv += count;
    return first;
  };

  const post = () => {
    r.stats.frames++;
    if (!port || off) { nc = 0; nv = 0; ni = 0; nb = 0; return; }
    const size = nc * 8 + nv * 32 + ni * 4 + nb;
    const shared = slots !== null && size <= SLOT_BYTES && ((sent - Atomics.load(ctrl, CTRL.FRAMES)) | 0) <= AHEAD;
    if (shared) {
      const s = slotViews[(sent + 1) & 1], d = s.msg;
      s.f64.set(cmd.subarray(0, nc), 0);
      s.u32.set(vb.subarray(0, nv * 8), nc * 2);
      s.u32.set(ib.subarray(0, ni), nc * 2 + nv * 8);
      s.u8.set(bytes.subarray(0, nb), nc * 8 + nv * 32 + ni * 4);
      d.nc = nc; d.nv = nv; d.ni = ni; d.nb = nb; d.t = performance.timeOrigin + performance.now();
      port.postMessage(d);
    } else {
      const buf = new ArrayBuffer(size);
      new Float64Array(buf, 0, nc).set(cmd.subarray(0, nc));
      new Uint32Array(buf, nc * 8, nv * 8).set(vb.subarray(0, nv * 8));
      new Uint32Array(buf, nc * 8 + nv * 32, ni).set(ib.subarray(0, ni));
      new Uint8Array(buf, nc * 8 + nv * 32 + ni * 4, nb).set(bytes.subarray(0, nb));
      port.postMessage({ buf, nc, nv, ni, nb, t: performance.timeOrigin + performance.now() }, [buf]);
    }
    sent = (sent + 1) | 0;
    nc = 0; nv = 0; ni = 0; nb = 0;
    r.pace();
  };

  /** A 2D change of a screen: IMAGE of RGB 565 pixels (sx, sy, sw, sh of surface src) into rect dr of the screen. */
  const image = (dst, dr, src, sr, keyed) => {
    const sw = sr.r - sr.l, sh = sr.b - sr.t;
    if (sw <= 0 || sh <= 0 || dr.r <= dr.l || dr.b <= dr.t || src.format.bits !== 16) return;
    wantBytes(sw * sh * 4);
    const at = nb;
    rgbaOf(m.u16, src.memory(), src.pitch, sr.l, sr.t, sw, sh, keyed ? src.colorKey & 0xFFFF : -1, bytes, at);
    nb += sw * sh * 4;
    want(10);
    cmd[nc++] = CMD.IMAGE; cmd[nc++] = dst.isPrimary ? 1 : 0; cmd[nc++] = dr.l; cmd[nc++] = dr.t; cmd[nc++] = dr.r - dr.l; cmd[nc++] = dr.b - dr.t;
    cmd[nc++] = sw; cmd[nc++] = sh; cmd[nc++] = keyed ? 1 : 0; cmd[nc++] = at;
    if (dst.isPrimary) { want(1); cmd[nc++] = CMD.PRESENT; post(); }
  };

  const r = {
    stats: { frames: 0, draws: 0, tris: 0, textures: 0, decals: 0, follow: 0, hold: 0, dropped: 0 },
    // set while the game draws its HUD (race.js wraps the HUD pass 0x467d30): those draws are never blended,
    // so the HUD changes as in the original, from one pass to the next
    hud: false,
    // tagger(prim, vtype, verts, nverts, indices, nindices, world) -> null, or a tag for the draw (source/host/shadows.js):
    // { id, flags (TAG), ox, oy, oz } and optionally drop (the draw is left out), or verts, nverts, indices, nindices
    // (game memory: drawn instead of the game's) with worldSpace (those vertices are world coordinates). Not asked
    // while the HUD draws.
    tagger: null,
    /** The rect of the drawing the HUD's next draws are cut to ({ x, y, w, h }, fractions from its top left; frame:
     * drawn into it too), or null (source/host/hud-layout.js, before each of its groups, and null after the HUD's draw). */
    hudClip(rect) { clipWanted = rect && rect.w > 0 && rect.h > 0 ? rect : null; },
    lastFrameDraws: 0,
    frameDraws: 0,
    attach(machine, h) {
      m = machine;
      host = h;
      want(3); cmd[nc++] = CMD.MODE; cmd[nc++] = h.screen.width; cmd[nc++] = h.screen.height;
    },
    sent: () => sent,
    freeTexture(surface) {
      if (surface.texId) { want(2); cmd[nc++] = CMD.FREE; cmd[nc++] = surface.texId; textures.delete(surface); surface.texId = 0; surface.sentGeneration = undefined; }
    },
    loadTexture(dst, src) { dst.source = src; },
    setRenderState(state, value) {
      if (state === 1) return;        // the texture handle: resolved per draw (host.renderState.texture)
      want(3); cmd[nc++] = CMD.STATE; cmd[nc++] = state; cmd[nc++] = value >>> 0;
    },
    setLightState() {},
    setBackground() {},
    setIndexed() {},
    setPalette() {},
    setViewport(vp) {
      want(9);
      cmd[nc++] = CMD.VIEWPORT; cmd[nc++] = vp.x; cmd[nc++] = vp.y; cmd[nc++] = vp.width; cmd[nc++] = vp.height;
      cmd[nc++] = vp.clipX; cmd[nc++] = vp.clipY; cmd[nc++] = vp.clipW; cmd[nc++] = vp.clipH;
    },
    setTransform(type, p) {
      if (type < 1 || type > 3) return;
      want(18);
      cmd[nc++] = CMD.TRANSFORM; cmd[nc++] = type;
      const f32 = m.f32;
      for (let k = 0, q = p >> 2; k < 16; k++) cmd[nc++] = f32[q + k];
      if (type === 1) world.set(f32.subarray(p >> 2, (p >> 2) + 16));
    },
    beginScene() {},
    endScene() {},
    clear(flags = 3) { want(2); cmd[nc++] = CMD.CLEAR; cmd[nc++] = flags; },
    drawPrimitive(prim, vtype, verts, count) {
      if (count <= 0 || prim < 4 || prim > 6) return;      // points and lines: debug drawing only
      const tag = r.tagger && !r.hud ? r.tagger(prim, vtype, verts, count, 0, 0, world) : null;
      if (tag && tag.drop) { r.stats.dropped++; return; }
      const tex = texOf(host.renderState.texture);
      const first = pushVerts(vtype, verts, count);
      const flag = verts >= FLAG_VERTS[0] && verts < FLAG_VERTS[1] ? 2 : 0;
      if (r.hud) clipCmd();
      if (tag) tagCmd(tag);
      want(7); cmd[nc++] = CMD.DRAW; cmd[nc++] = prim; cmd[nc++] = vtype; cmd[nc++] = first; cmd[nc++] = count; cmd[nc++] = tex; cmd[nc++] = (r.hud ? 1 : 0) | flag;
      r.stats.draws++; r.frameDraws++;
    },
    drawIndexed(prim, vtype, verts, nverts, indices, nindices) {
      if (nindices <= 0 || prim < 4 || prim > 6) return;
      const tag = r.tagger && !r.hud ? r.tagger(prim, vtype, verts, nverts, indices, nindices, world) : null;
      if (tag && tag.drop) { r.stats.dropped++; return; }
      // a tag may hand other vertices and indices for the draw (the surface shadow's grid): the game's texture and
      // states stay
      if (tag && tag.verts) { verts = tag.verts; nverts = tag.nverts; indices = tag.indices; nindices = tag.nindices; }
      const tex = texOf(host.renderState.texture);
      const base = pushVerts(vtype, verts, nverts);
      if (ni + nindices > ib.length) ib = grow(ib, ni + nindices);
      const u16 = m.u16;
      const first = ni;
      for (let k = 0, q = indices >> 1; k < nindices; k++) ib[ni++] = u16[q + k];
      const worldSpace = tag && tag.worldSpace;
      if (worldSpace) transform(1, IDENTITY);
      if (r.hud) clipCmd();
      if (tag) tagCmd(tag);
      want(9); cmd[nc++] = CMD.DRAWIDX; cmd[nc++] = prim; cmd[nc++] = vtype; cmd[nc++] = first; cmd[nc++] = nindices; cmd[nc++] = tex; cmd[nc++] = base; cmd[nc++] = nverts; cmd[nc++] = r.hud ? 1 : 0;
      if (worldSpace) transform(1, world);
      r.stats.draws++; r.frameDraws++;
    },
    screenFill(dst, rect, color) {
      // RGB 565 -> 0xRRGGBB
      const rr = (((color >> 11) & 31) * 527 + 23) >> 6, gg = (((color >> 5) & 63) * 259 + 33) >> 6, bb = ((color & 31) * 527 + 23) >> 6;
      want(7);
      cmd[nc++] = CMD.FILL; cmd[nc++] = dst.isPrimary ? 1 : 0; cmd[nc++] = rect.l; cmd[nc++] = rect.t; cmd[nc++] = rect.r - rect.l; cmd[nc++] = rect.b - rect.t;
      cmd[nc++] = (rr << 16) | (gg << 8) | bb;
      if (dst.isPrimary) { want(1); cmd[nc++] = CMD.PRESENT; post(); }
    },
    screenBlit(dst, dr, src, sr, flags) { image(dst, dr, src, sr, (flags & 0x8000) !== 0); },
    screenWritten(surface, rect) {
      const rc = rect || { l: 0, t: 0, r: surface.width, b: surface.height };
      image(surface, rc, surface, rc, false);
    },
    flip() {
      r.lastFrameDraws = r.frameDraws;
      r.frameDraws = 0;
      want(1); cmd[nc++] = CMD.FLIP;
      post();
    },
    endFrame() {},
    /** The end of the race: waits (at most waitMs) until the render worker has drawn every frame sent, then has
     * it free the race's textures and clear the picture. */
    close(waitMs = 1000) {
      if (ctrl && !off) {
        const t = performance.now();
        for (;;) {
          const done = Atomics.load(ctrl, CTRL.FRAMES);
          if (((sent - done) | 0) <= 0 || Atomics.load(ctrl, CTRL.DEAD) || performance.now() - t > waitMs) break;
          Atomics.wait(ctrl, CTRL.FRAMES, done, 50);
        }
      }
      if (port) port.postMessage({ reset: true, ended: true });
      textures.clear();
    },
    /** Keeps the game thread at most AHEAD frames ahead of the render worker; a dead or stalled worker is left behind. */
    pace() {
      if (!ctrl || off) return;
      const t = performance.now();
      for (;;) {
        const done = Atomics.load(ctrl, CTRL.FRAMES);
        if (((sent - done) | 0) <= AHEAD || Atomics.load(ctrl, CTRL.PAUSED)) return;
        if (Atomics.load(ctrl, CTRL.DEAD) || performance.now() - t > STALL_MS) { off = true; return; }
        Atomics.wait(ctrl, CTRL.FRAMES, done, 50);
      }
    },
  };
  return r;
}
