// Replays rcskspel.dat's frames (source/render/recorder.js) with WebGL2, in the render worker
// (source/web/render-worker.js), on the page's canvas, and smooths the 25 ms passes of the game to the display's
// rate.
//
// The flip chain. The game's screens are two buffers and one Z-buffer, so the renderer keeps two colour buffers
// (front and back, swapped at FLIP as DirectDraw swaps them) and one depth buffer. Every frame of the game is
// replayed into them once, exactly, in the order the game made its calls: 3D draws and 2D changes (IMAGE, FILL)
// to the back screen, FLIP swaps, PRESENT shows the front screen as it is. A frame that changes part of a screen
// (the quit requester's buttons) keeps the rest, as on Windows.
//
// Smoothing (on unless options.smooth is false). A frame of 3D draws that ends in a FLIP is also kept, with the
// one before it, and the display shows a blend of the two (the A2 Racer 4 port's model, source/render/
// d3d-renderer.js there): each draw of the newer frame is paired with the draw of the older one with the same
// texture, primitive and counts that lies nearest, and its world matrix, the camera's view and projection, and,
// when the vertices themselves move (smoke, sparks, animated meshes), its vertices are blended. A draw without a
// partner, one that moved more than TELEPORT units in a pass, or a turn of more than SPIN degrees (a wheel at
// speed: its rotation is the newer one's, only its place is blended) shows the newer frame. The display lags one
// pass (25 ms) behind the game. Frames with 2D changes are shown as they are. The blended picture goes to a
// buffer of its own, so the flip chain stays exactly the game's.
//
// Tags (CMD.TAG, source/host/shadows.js) say what a draw belongs to. A FOLLOW draw (a kart's shadow, an engine
// flare) pairs only with the same owner's in the pass before, and its vertices are blended unless the owner (the
// kart's matrix) moved more than TELEPORT, so it moves exactly as its kart, which is blended by the same rule; a HOLD
// draw always shows the newer pass; a DECAL (the surface shadow) gets a polygon offset and writes no depth.
//
// Screen shape, resolution, MSAA. The buffers have the drawing size the page asks for (resize: any shape, any
// size, 0/2/4/8 samples; multisampled buffers are resolved when shown). The game's 3D view fills all of it: on a
// wider screen the clip volume is widened (more at the sides, the original's vertical framing), on a taller one
// heightened (more above and below), as A2 Racer 4 does; at 4:3 it is the original's. The HUD is drawn with the
// same clip: the game worker moves its groups to the edges in game memory around its draw, and cuts each group to
// its frame (CMD.CLIP, a scissor) where the JS reconstruction's HUD clips it; the bonus box it leaves as at 4:3, to be
// drawn into its frame (CMD.CLIP mode 2). 2D screens and screen-space vertices keep the game's 640x480 in the largest
// 4:3 area in the middle (`area`); a 2D picture of the whole screen blacks out the rest.
//
// Direct3D conventions: row vectors, v' = v * World * View * Projection, matrices row-major in memory. Uploaded
// to GLSL as they are, a matrix reads transposed, so P * V * W * v there is the same product. The viewport's clip
// volume (SetViewport2: dvClipX/Y/Width/Height, here -1, aspect, 2, 2*aspect) maps to GL through uClip, and
// Direct3D's 0..w depth to GL's -w..w. Vertices arrive in the D3DLVERTEX layout (x y z reserved color specular
// u v); vertex type 3 (D3DTLVERTEX: pixels, depth, rhw) is drawn through uScreen.
import { CMD, CMD_SIZE, TAG } from './recorder.js';

const RS = {
  ZENABLE: 7, ZWRITEENABLE: 14, TEXTUREMAG: 17, TEXTUREMIN: 18, SRCBLEND: 19, DESTBLEND: 20,
  TEXTUREMAPBLEND: 21, CULLMODE: 22, ZFUNC: 23, ALPHABLENDENABLE: 27,
};
// Direct3D 5 defaults (d3dtypes.h), for states the game never sets
const RS_DEFAULT = { 7: 1, 14: 1, 17: 1, 18: 1, 19: 2, 20: 1, 21: 2, 22: 3, 23: 4, 27: 0 };
// A pass moving a draw further than this is a jump, not motion (track units; a kart at racing speed covers 13.8 per
// pass on average and at most 28.1 with a turbo, measured over 4000 passes on Frankrijk, 2026-11-25; true jumps,
// rescues and respawns, are 400 and more)
const TELEPORT = 30;
// A vertex of a moving mesh further than this from its place in the pass before belongs to something else
// (the game reuses vertex arrays for other puffs and sparks)
const VERTEX_JUMP = 10;
// A turn of more than this per pass keeps the newer rotation: blended element by element, two poses far apart
// shrink and skew the object halfway
const SPIN_COS = Math.cos(20 * Math.PI / 180);

const VERT = `#version 300 es
precision highp float;
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;    // D3DCOLOR as bytes B G R A
layout(location = 2) in vec2 aUV;
layout(location = 3) in vec3 aPrev;     // the vertex in the pass before (smoothing), else aPos again
uniform mat4 uWorld, uView, uProj, uClip, uScreen;
uniform int uScreenSpace;
uniform float uVertT;
uniform float uSheet;                   // the finish flag's sheet grown on other shapes than 4:3, else 1
out vec4 vColor;
out vec2 vUV;
void main() {
  vec3 p = mix(aPrev, aPos, uVertT);
  p.xy *= uSheet;
  if (uScreenSpace != 0) gl_Position = uScreen * vec4(p, 1.0);
  else gl_Position = uClip * uProj * uView * uWorld * vec4(p, 1.0);
  vColor = aColor.bgra;
  vUV = aUV;
}`;

const FRAG = `#version 300 es
precision highp float;
uniform sampler2D uTex;
uniform int uTextured;
uniform int uMapBlend;
uniform vec4 uFill;
uniform int uMode;          // 0 a 3D draw, 1 an IMAGE (texel as it is, keyed texels left out), 2 a FILL
in vec4 vColor;
in vec2 vUV;
out vec4 outColor;
void main() {
  if (uMode == 2) { outColor = uFill; return; }
  vec4 t = texture(uTex, vUV);
  if (uMode == 1) { if (t.a < 0.5) discard; outColor = vec4(t.rgb, 1.0); return; }
  vec4 c = vColor;
  if (uTextured != 0) {
    // colour-keyed texels are stored with alpha 0 (and black)
    if (t.a < 0.5) discard;
    t.rgb /= t.a;
    // D3DTBLEND_MODULATE (2): texture colour times vertex colour, the texture's alpha if it has one (RGB 565
    // has none: the vertex alpha). MODULATEALPHA (4): both multiplied. DECAL (1), COPY (7): the texel.
    if (uMapBlend == 2) c = vec4(t.rgb * vColor.rgb, vColor.a);
    else if (uMapBlend == 4) c = t * vColor;
    else c = vec4(t.rgb, 1.0);
  }
  outColor = c;
}`;

const BLEND = (gl) => ({
  1: gl.ZERO, 2: gl.ONE, 3: gl.SRC_COLOR, 4: gl.ONE_MINUS_SRC_COLOR, 5: gl.SRC_ALPHA, 6: gl.ONE_MINUS_SRC_ALPHA,
  7: gl.DST_ALPHA, 8: gl.ONE_MINUS_DST_ALPHA, 9: gl.DST_COLOR, 10: gl.ONE_MINUS_DST_COLOR, 11: gl.SRC_ALPHA_SATURATE,
});
const ZFUNC = (gl) => ({ 1: gl.NEVER, 2: gl.LESS, 3: gl.EQUAL, 4: gl.LEQUAL, 5: gl.GREATER, 6: gl.NOTEQUAL, 7: gl.GEQUAL, 8: gl.ALWAYS });
const identity = () => new Float32Array([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);

/** Cosine of the turn between the 3x3 parts of two matrices, rows normalised for scale. */
function turnCos(a, b) {
  let trace = 0;
  for (let r = 0; r < 12; r += 4) {
    const la = Math.hypot(a[r], a[r + 1], a[r + 2]), lb = Math.hypot(b[r], b[r + 1], b[r + 2]);
    if (!la || !lb) return 1;
    trace += (a[r] * b[r] + a[r + 1] * b[r + 1] + a[r + 2] * b[r + 2]) / (la * lb);
  }
  return (trace - 1) / 2;
}
/** The eye of a view matrix (row vectors: eye = -t * R^T). */
function eye(v, out) {
  for (let k = 0; k < 3; k++) out[k] = -(v[12] * v[k * 4] + v[13] * v[k * 4 + 1] + v[14] * v[k * 4 + 2]);
  return out;
}
const eyeA = new Float32Array(3), eyeB = new Float32Array(3);

/**
 * out = a blend of matrices a (older) and b (newer) at t. Returns false when they are too far apart to blend
 * (out is then b). isView: the distance is the eye's, not the translation's.
 */
function blendMatrix(out, a, b, t, isView) {
  let d;
  if (isView) { eye(a, eyeA); eye(b, eyeB); d = Math.hypot(eyeB[0] - eyeA[0], eyeB[1] - eyeA[1], eyeB[2] - eyeA[2]); }
  else d = Math.hypot(b[12] - a[12], b[13] - a[13], b[14] - a[14]);
  if (d > TELEPORT) { out.set(b); return false; }
  if (turnCos(a, b) < SPIN_COS) {
    out.set(b);
    if (!isView) for (let k = 12; k < 15; k++) out[k] = a[k] + (b[k] - a[k]) * t;
    return true;
  }
  for (let k = 0; k < 16; k++) out[k] = a[k] + (b[k] - a[k]) * t;
  return true;
}

export class GLRenderer {
  constructor(canvas, options = {}) {
    this.canvas = canvas;
    const gl = canvas.getContext('webgl2', { antialias: false, alpha: false, depth: false, preserveDrawingBuffer: !!options.preserveDrawingBuffer });
    if (!gl) throw new Error('WebGL2 is not available');
    this.gl = gl;
    this.blend = BLEND(gl);
    this.zfunc = ZFUNC(gl);
    this.program = this.makeProgram(VERT, FRAG);
    const p = this.program;
    this.u = {};
    for (const n of ['uWorld', 'uView', 'uProj', 'uClip', 'uScreen', 'uScreenSpace', 'uTex', 'uTextured', 'uMapBlend', 'uFill', 'uMode', 'uVertT', 'uSheet']) this.u[n] = gl.getUniformLocation(p, n);
    this.vao = gl.createVertexArray();
    gl.bindVertexArray(this.vao);
    for (let k = 0; k < 4; k++) gl.enableVertexAttribArray(k);
    // two frames' vertex and index buffers: the one being shown and the one before it
    this.slots = [0, 1].map(() => ({ vbo: gl.createBuffer(), ibo: gl.createBuffer() }));
    this.nextSlot = 0;
    // the quad of IMAGE and FILL
    this.quadVbo = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, this.quadVbo);
    gl.bufferData(gl.ARRAY_BUFFER, 4 * 32, gl.DYNAMIC_DRAW);
    gl.bindVertexArray(null);
    this.quad = new ArrayBuffer(4 * 32);
    this.quadF = new Float32Array(this.quad);
    this.quadU = new Uint32Array(this.quad);
    this.imageTex = gl.createTexture();
    this.textures = new Map();
    this.state = new Map();
    this.world = identity(); this.view = identity(); this.proj = identity(); this.clip = identity(); this.screenMap = new Float32Array(16);
    this.bw = identity(); this.bv = identity(); this.bp = identity();          // blended matrices of one draw
    this.setMode(640, 480);
    this.vp = null;
    this.cut = null;            // the HUD group's frame its draws are cut to (CMD.CLIP: x, y, w, h fractions, mode), or null
    this.scissorOn = false;     // the scissor is on for the draw just prepared (prepare)
    this.screens = null;
    this.smooth = options.smooth !== false;
    this.prev = null;           // the two frames the display blends
    this.cur = null;
    this.shownT = -1;           // what the display last showed: frame time and blend
    this.shownFrame = null;
    this.stats = { frames: 0, draws: 0, displayed: 0, paired: 0, unpaired: 0, decals: 0, followed: 0, followSnapped: 0, held: 0 };
    this.pendingTag = null;     // a TAG for the next draw (replay)
    this.debug = options.debug || {};
    // MSAA: the sample counts both the colour and the depth buffers take (the JS reconstruction's
    // supportedMultisampleCounts), and the largest renderbuffer side (the drawing size's limit)
    const counts = (format) => { try { return Array.from(gl.getInternalformatParameter(gl.RENDERBUFFER, format, gl.SAMPLES) || []); } catch (e) { return []; } };
    const depthCounts = new Set(counts(gl.DEPTH_COMPONENT24));
    this.supportedSamples = [...new Set(counts(gl.RGBA8).filter((v) => v >= 2 && depthCounts.has(v)))].sort((a, b) => a - b);
    this.maxSize = Math.min(gl.getParameter(gl.MAX_RENDERBUFFER_SIZE), gl.getParameter(gl.MAX_TEXTURE_SIZE)) || 4096;
    this.resize(canvas.width, canvas.height, options.samples || 0);
  }

  /** The sample count used for a request: the largest supported one up to it, else the smallest (JS chooseMultisampleCount). */
  chooseSamples(requested) {
    if (!(requested >= 2)) return 0;
    const s = this.supportedSamples;
    return s.filter((v) => v <= requested).at(-1) ?? s[0] ?? 0;
  }

  /**
   * Between two races (the page runs many on one canvas): every texture is deleted, the game's state, matrices,
   * viewport and display mode go back to their defaults, the kept frames are dropped, and the screens and the
   * canvas are cleared to black. The buffers keep their size and samples.
   */
  reset() {
    const gl = this.gl;
    for (const t of this.textures.values()) gl.deleteTexture(t);
    this.textures.clear();
    this.state = new Map();
    for (const m of [this.world, this.view, this.proj, this.clip, this.bw, this.bv, this.bp]) m.set(identity());
    this.setMode(640, 480);
    this.vp = null;
    this.cut = null;
    this.prev = null;
    this.cur = null;
    this.shownT = -1;
    this.shownFrame = null;
    this.nextSlot = 0;
    for (const slot of this.slots) {
      gl.bindBuffer(gl.ARRAY_BUFFER, slot.vbo); gl.bufferData(gl.ARRAY_BUFFER, 0, gl.STREAM_DRAW);
      gl.bindVertexArray(this.vao);
      gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, slot.ibo); gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, 0, gl.STREAM_DRAW);
      gl.bindVertexArray(null);
    }
    gl.bindTexture(gl.TEXTURE_2D, this.imageTex);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA8, 1, 1, 0, gl.RGBA, gl.UNSIGNED_BYTE, new Uint8Array(4));
    gl.disable(gl.SCISSOR_TEST);
    gl.colorMask(true, true, true, true);
    gl.depthMask(true);
    gl.clearColor(0, 0, 0, 1);
    gl.clearDepth(1);
    for (const t of [...this.screens, this.display, ...(this.resolve ? [this.resolve] : [])]) {
      gl.bindFramebuffer(gl.FRAMEBUFFER, t.fbo);
      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    }
    gl.bindFramebuffer(gl.FRAMEBUFFER, null);
    gl.clear(gl.COLOR_BUFFER_BIT);
    this.front = 0;
    this.updateWideClip();
  }

  makeProgram(vs, fs) {
    const gl = this.gl;
    const sh = (type, src) => {
      const s = gl.createShader(type);
      gl.shaderSource(s, src);
      gl.compileShader(s);
      if (!gl.getShaderParameter(s, gl.COMPILE_STATUS)) throw new Error(gl.getShaderInfoLog(s));
      return s;
    };
    const p = gl.createProgram();
    gl.attachShader(p, sh(gl.VERTEX_SHADER, vs));
    gl.attachShader(p, sh(gl.FRAGMENT_SHADER, fs));
    gl.linkProgram(p);
    if (!gl.getProgramParameter(p, gl.LINK_STATUS)) throw new Error(gl.getProgramInfoLog(p));
    return p;
  }

  /** A colour buffer (multisampled with samples > 1) on the given depth buffer, at the drawing size. */
  makeTarget(w, h, depth, samples) {
    const gl = this.gl;
    const color = gl.createRenderbuffer();
    gl.bindRenderbuffer(gl.RENDERBUFFER, color);
    if (samples > 1) gl.renderbufferStorageMultisample(gl.RENDERBUFFER, samples, gl.RGBA8, w, h);
    else gl.renderbufferStorage(gl.RENDERBUFFER, gl.RGBA8, w, h);
    const fbo = gl.createFramebuffer();
    gl.bindFramebuffer(gl.FRAMEBUFFER, fbo);
    gl.framebufferRenderbuffer(gl.FRAMEBUFFER, gl.COLOR_ATTACHMENT0, gl.RENDERBUFFER, color);
    gl.framebufferRenderbuffer(gl.FRAMEBUFFER, gl.DEPTH_ATTACHMENT, gl.RENDERBUFFER, depth);
    gl.clearColor(0, 0, 0, 1);
    gl.clearDepth(1);
    gl.depthMask(true);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    return { color, fbo };
  }

  /**
   * The two screens with their Z-buffer, and the display buffer with its own, at the drawing size (the canvas's)
   * and samples (MSAA: 0, 2, 4, 8, at most what the GPU offers). Their contents start black.
   */
  resize(w, h, samples = this.samples || 0) {
    const gl = this.gl;
    w = Math.max(1, Math.round(w));
    h = Math.max(1, Math.round(h));
    samples = this.chooseSamples(samples | 0);
    this.canvas.width = w;
    this.canvas.height = h;
    if (this.screens) {
      for (const s of [...this.screens, this.display, ...(this.resolve ? [this.resolve] : [])]) { gl.deleteFramebuffer(s.fbo); gl.deleteRenderbuffer(s.color); }
      gl.deleteRenderbuffer(this.depth);
      gl.deleteRenderbuffer(this.displayDepth);
      if (this.resolveDepth) gl.deleteRenderbuffer(this.resolveDepth);
    }
    const depth = () => {
      const d = gl.createRenderbuffer();
      gl.bindRenderbuffer(gl.RENDERBUFFER, d);
      if (samples > 1) gl.renderbufferStorageMultisample(gl.RENDERBUFFER, samples, gl.DEPTH_COMPONENT24, w, h);
      else gl.renderbufferStorage(gl.RENDERBUFFER, gl.DEPTH_COMPONENT24, w, h);
      return d;
    };
    this.depth = depth();
    this.displayDepth = depth();
    const depth0 = () => { const d = gl.createRenderbuffer(); gl.bindRenderbuffer(gl.RENDERBUFFER, d); gl.renderbufferStorage(gl.RENDERBUFFER, gl.DEPTH_COMPONENT24, w, h); return d; };
    this.screens = [this.makeTarget(w, h, this.depth, samples), this.makeTarget(w, h, this.depth, samples)];
    this.display = this.makeTarget(w, h, this.displayDepth, samples);
    // A multisampled buffer can only be blitted to one of the same format: the canvas (no alpha) is not RGBA8, so
    // with MSAA a picture is resolved into this single-sample buffer first and copied from there.
    this.resolveDepth = null;
    this.resolve = null;
    if (samples > 1) { this.resolveDepth = depth0(); this.resolve = this.makeTarget(w, h, this.resolveDepth, 0); }
    this.front = 0;
    this.width = w;
    this.height = h;
    this.samples = samples;
    // the largest 4:3 area in the middle (HUD, 2D), and how much wider or taller than 4:3 the whole is
    const a = w / h;
    if (a >= 4 / 3) { const aw = Math.round(h * 4 / 3); this.area = { x: Math.floor((w - aw) / 2), y: 0, w: aw, h }; }
    else { const ah = Math.round(w * 3 / 4); this.area = { x: 0, y: Math.floor((h - ah) / 2), w, h: ah }; }
    this.xr = Math.max(1, a / (4 / 3));
    this.yr = Math.max(1, (4 / 3) / a);
    this.updateWideClip();
    this.shownFrame = null;
  }

  /** The clip mapping of the world's draws: the game's, widened by xr or heightened by yr. */
  updateWideClip() {
    const c = this.clip, w = this.clipWide || (this.clipWide = new Float32Array(16));
    w.set(c);
    w[0] = c[0] / this.xr; w[12] = c[12] / this.xr;
    w[5] = c[5] / this.yr; w[13] = c[13] / this.yr;
  }

  rs(state) {
    const v = this.state.get(state);
    return v === undefined ? (RS_DEFAULT[state] ?? 0) : v;
  }

  setMode(w, h) {
    this.mode = { width: w, height: h };
    const s = this.screenMap;
    s.fill(0);
    s[0] = 2 / w; s[5] = -2 / h; s[10] = 2; s[12] = -1; s[13] = 1; s[14] = -1; s[15] = 1;
  }

  setViewport(c, k) {
    this.vp = { x: c[k], y: c[k + 1], width: c[k + 2], height: c[k + 3] };
    // dvClipX, dvClipY (top), dvClipWidth, dvClipHeight -> GL NDC; z 0..w -> -w..w (column-major)
    const clipX = c[k + 4], clipY = c[k + 5], clipW = c[k + 6], clipH = c[k + 7];
    const m = this.clip;
    m.fill(0);
    m[0] = 2 / clipW; m[5] = 2 / clipH; m[10] = 2;
    m[12] = -2 * clipX / clipW - 1; m[13] = -2 * (clipY - clipH) / clipH - 1; m[14] = -1; m[15] = 1;
    if (this.screens) this.updateWideClip();
  }

  /** A rectangle in the game's screen pixels (y down) -> buffer pixels (y up), inside the 4:3 area. */
  pixelRect(x, y, w, h) {
    const a = this.area, sx = a.w / this.mode.width, sy = a.h / this.mode.height;
    return [Math.round(a.x + x * sx), Math.round(this.height - a.y - (y + h) * sy), Math.round(w * sx), Math.round(h * sy)];
  }

  pixelViewport(x, y, w, h) { this.gl.viewport(...this.pixelRect(x, y, w, h)); }

  /** Is the game's viewport the whole screen (the world's view: drawn over the whole buffer)? */
  fullView() {
    const vp = this.vp;
    return !vp || (vp.x === 0 && vp.y === 0 && vp.width === this.mode.width && vp.height === this.mode.height);
  }

  /** Where draws go: the back screen (replays), the front screen (2D changes of it), or the display buffer. */
  bindTarget(which) {
    const gl = this.gl;
    const t = which === 'display' ? this.display : this.screens[which === 'front' ? this.front : 1 - this.front];
    gl.bindFramebuffer(gl.FRAMEBUFFER, t.fbo);
  }

  uploadTexture(id, w, h, pixels) {
    const gl = this.gl;
    let t = this.textures.get(id);
    if (!t) { t = gl.createTexture(); this.textures.set(id, t); }
    gl.activeTexture(gl.TEXTURE0);
    gl.bindTexture(gl.TEXTURE_2D, t);
    gl.pixelStorei(gl.UNPACK_ALIGNMENT, 1);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA8, w, h, 0, gl.RGBA, gl.UNSIGNED_BYTE, pixels);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT);
  }

  /** Device state of this moment -> GL state and uniforms (matrices are set by the caller). */
  prepare(vtype, tex, hud, sheet, decal) {
    const gl = this.gl;
    gl.useProgram(this.program);
    gl.bindVertexArray(this.vao);
    const vp = this.vp || { x: 0, y: 0, width: this.mode.width, height: this.mode.height };
    // the world's view over the whole buffer with the widened clip, the HUD too (its groups are moved to the edges
    // in game memory around its draw, source/host/hud-layout.js); screen-space vertices in the 4:3 area
    const wide = vtype !== 3 && this.fullView();
    // a HUD group cut to its frame (CMD.CLIP, source/host/hud-layout.js), as the JS reconstruction's viewport of the
    // group cuts it (race-hud-meshes.js:256-257), in whole pixels rounded as three.js's setViewport rounds them; the
    // draw sites turn it off again (endCut), so no clear, blit or 2D picture is cut. Mode 2 (the bonus box, left as
    // at 4:3 in game memory): the frame is also the viewport and the clip the game's own 4:3 one, the JS port's
    // drawing of a group (its camera's aspect is 640/480, race-hud-meshes.js:42), so its 3D model keeps its perspective
    const cut = hud && wide ? this.cut : null;
    const into = cut && cut[4] === 2;
    const W = this.width, H = this.height;
    const rect = cut ? [Math.round(cut[0] * W), Math.round((1 - cut[1] - cut[3]) * H), Math.round(cut[2] * W), Math.round(cut[3] * H)] : null;
    if (into) gl.viewport(...rect);
    else if (wide) gl.viewport(0, 0, W, H);
    else this.pixelViewport(vp.x, vp.y, vp.width, vp.height);
    if (cut) {
      gl.enable(gl.SCISSOR_TEST);
      gl.scissor(...rect);
      this.scissorOn = true;
    }
    const zOn = this.rs(RS.ZENABLE) !== 0;
    if (zOn) { gl.enable(gl.DEPTH_TEST); gl.depthFunc(this.zfunc[this.rs(RS.ZFUNC)] || gl.LEQUAL); } else gl.disable(gl.DEPTH_TEST);
    gl.depthMask(zOn && this.rs(RS.ZWRITEENABLE) !== 0);
    // the surface shadow (a DECAL tag): pulled in front of the coplanar road and no depth written, so it cannot hide
    // the wheels' bottoms just under it (the JS reconstruction's material, race-visuals.js:184-198: polygonOffset
    // factor -1, units -4, depthWrite false)
    if (decal) { gl.depthMask(false); gl.enable(gl.POLYGON_OFFSET_FILL); gl.polygonOffset(-1, -4); }
    else gl.disable(gl.POLYGON_OFFSET_FILL);
    if (this.rs(RS.ALPHABLENDENABLE)) {
      gl.enable(gl.BLEND);
      gl.blendFunc(this.blend[this.rs(RS.SRCBLEND)] ?? gl.ONE, this.blend[this.rs(RS.DESTBLEND)] ?? gl.ZERO);
    } else gl.disable(gl.BLEND);
    // CULLMODE 1 none, 2 cull clockwise, 3 cull counter-clockwise: the winding as it appears on screen, which is
    // what GL's front face means too (uClip keeps the picture upright). British courses mirror the projection
    // and swap the two (0x42d8e0, 0x4302d5, 0x430384).
    const cull = this.debug.noCull ? 1 : this.rs(RS.CULLMODE);
    if (cull === 1) gl.disable(gl.CULL_FACE);
    else { gl.enable(gl.CULL_FACE); gl.cullFace(gl.BACK); gl.frontFace(cull === 2 ? gl.CCW : gl.CW); }
    gl.activeTexture(gl.TEXTURE0);
    const t = tex ? this.textures.get(tex) : null;
    gl.bindTexture(gl.TEXTURE_2D, t || null);
    if (t) {
      gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, this.rs(RS.TEXTUREMAG) === 2 ? gl.LINEAR : gl.NEAREST);
      gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, this.rs(RS.TEXTUREMIN) === 2 ? gl.LINEAR : gl.NEAREST);
    }
    gl.uniform1i(this.u.uMode, 0);
    gl.uniform1i(this.u.uTex, 0);
    gl.uniform1i(this.u.uTextured, t ? 1 : 0);
    gl.uniform1i(this.u.uMapBlend, this.rs(RS.TEXTUREMAPBLEND));
    gl.uniform1i(this.u.uScreenSpace, vtype === 3 ? 1 : 0);
    gl.uniformMatrix4fv(this.u.uClip, false, wide && !into ? this.clipWide : this.clip);
    // the finish flag's sheet, fixed to the camera: grown evenly (its squares stay square) by the screen's
    // widening or heightening, so its waving edges stay off screen (A2 Racer 4 does the same, scaleFlag)
    gl.uniform1f(this.u.uSheet, sheet ? Math.max(this.xr, this.yr) : 1);
    gl.uniformMatrix4fv(this.u.uScreen, false, this.screenMap);
  }

  /** The vertex attributes of one draw: its vertices from base, the older ones (aPrev) from prevBase of prevVbo. */
  bindVerts(vbo, base, prevVbo, prevBase) {
    const gl = this.gl;
    gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
    gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 32, base * 32);
    gl.vertexAttribPointer(1, 4, gl.UNSIGNED_BYTE, true, 32, base * 32 + 16);
    gl.vertexAttribPointer(2, 2, gl.FLOAT, false, 32, base * 32 + 24);
    gl.bindBuffer(gl.ARRAY_BUFFER, prevVbo);
    gl.vertexAttribPointer(3, 3, gl.FLOAT, false, 32, prevBase * 32);
  }

  /** IMAGE and FILL: a rectangle of the game's screen, without depth, blending or culling. */
  rect2d(front, x, y, w, h, mode, rgb) {
    const gl = this.gl;
    this.bindTarget(front ? 'front' : 'back');
    if (x <= 0 && y <= 0 && x + w >= this.mode.width && y + h >= this.mode.height && (this.area.w !== this.width || this.area.h !== this.height)) {
      // a picture of the whole screen (a loading picture, the requester's form): nothing of the world beside it
      gl.disable(gl.SCISSOR_TEST);
      gl.colorMask(true, true, true, true);
      gl.clearColor(0, 0, 0, 1);
      gl.clear(gl.COLOR_BUFFER_BIT);
    }
    gl.useProgram(this.program);
    gl.bindVertexArray(this.vao);
    this.pixelViewport(0, 0, this.mode.width, this.mode.height);
    gl.disable(gl.DEPTH_TEST);
    gl.depthMask(false);
    gl.disable(gl.BLEND);
    gl.disable(gl.CULL_FACE);
    gl.disable(gl.POLYGON_OFFSET_FILL);
    const f = this.quadF, u = this.quadU;
    const corner = (k, px, py, tu, tv) => { f[k * 8] = px; f[k * 8 + 1] = py; f[k * 8 + 2] = 0; u[k * 8 + 4] = 0xFFFFFFFF; f[k * 8 + 6] = tu; f[k * 8 + 7] = tv; };
    corner(0, x, y, 0, 0); corner(1, x + w, y, 1, 0); corner(2, x, y + h, 0, 1); corner(3, x + w, y + h, 1, 1);
    gl.bindBuffer(gl.ARRAY_BUFFER, this.quadVbo);
    gl.bufferSubData(gl.ARRAY_BUFFER, 0, this.quad);
    this.bindVerts(this.quadVbo, 0, this.quadVbo, 0);
    gl.uniform1f(this.u.uVertT, 1);
    gl.uniform1f(this.u.uSheet, 1);
    gl.uniform1i(this.u.uScreenSpace, 1);
    gl.uniformMatrix4fv(this.u.uScreen, false, this.screenMap);
    gl.uniform1i(this.u.uMode, mode);
    if (mode === 2) gl.uniform4f(this.u.uFill, ((rgb >> 16) & 255) / 255, ((rgb >> 8) & 255) / 255, (rgb & 255) / 255, 1);
    gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
  }

  /** Shows a buffer on the canvas. */
  show(which) {
    const gl = this.gl;
    let t = which === 'display' ? this.display : this.screens[which === 'front' ? this.front : 1 - this.front];
    if (this.resolve) {
      gl.bindFramebuffer(gl.READ_FRAMEBUFFER, t.fbo);
      gl.bindFramebuffer(gl.DRAW_FRAMEBUFFER, this.resolve.fbo);
      gl.blitFramebuffer(0, 0, this.width, this.height, 0, 0, this.width, this.height, gl.COLOR_BUFFER_BIT, gl.NEAREST);
      t = this.resolve;
    }
    gl.bindFramebuffer(gl.READ_FRAMEBUFFER, t.fbo);
    gl.bindFramebuffer(gl.DRAW_FRAMEBUFFER, null);
    gl.blitFramebuffer(0, 0, this.width, this.height, 0, 0, this.width, this.height, gl.COLOR_BUFFER_BIT, gl.NEAREST);
    gl.bindFramebuffer(gl.FRAMEBUFFER, null);
    this.stats.displayed++;
  }

  /** After a draw: the scissor prepare() turned on for a HUD group's cut goes off. */
  endCut() {
    if (!this.scissorOn) return;
    this.gl.disable(this.gl.SCISSOR_TEST);
    this.scissorOn = false;
  }

  /** CMD.CLIP at c[k]: the HUD draws after it are cut to x, y, w, h (fractions of the drawing), or not (w 0); mode. */
  setCut(c, k) { this.cut = c[k + 3] > 0 ? [c[k + 1], c[k + 2], c[k + 3], c[k + 4], c[k + 5]] : null; }

  snapshot() {
    return { state: new Map(this.state), vp: this.vp ? { ...this.vp } : null, cut: this.cut, world: this.world.slice(), view: this.view.slice(), proj: this.proj.slice(), clip: this.clip.slice() };
  }

  restore(s) {
    this.state = new Map(s.state);
    this.vp = s.vp ? { ...s.vp } : null;
    this.cut = s.cut;
    this.world.set(s.world); this.view.set(s.view); this.proj.set(s.proj); this.clip.set(s.clip);
    this.updateWideClip();
  }

  /**
   * One frame of the recorder: d = { buf, nc, nv, ni, nb, t } (buf in this thread's memory, reused for the next
   * frame). Replays it into the flip chain, and keeps a frame of 3D draws for the display's blends.
   */
  receive(d) {
    const gl = this.gl;
    const c = new Float64Array(d.buf, 0, d.nc);
    const vOff = d.nc * 8, iOff = vOff + d.nv * 32, bOff = iOff + d.ni * 4;
    // a frame for blending: 3D only, ending in FLIP
    let flat = false, flips = 0;
    for (let k = 0; k < d.nc;) {
      const op = c[k];
      if (op === CMD.IMAGE || op === CMD.FILL || op === CMD.PRESENT) flat = true;
      if (op === CMD.FLIP) flips++;
      k += CMD_SIZE[op] || 1;
    }
    const keep = this.smooth && !flat && flips === 1;
    // its vertices and indices go to the slot the older of the two kept frames had
    const slot = this.slots[this.nextSlot];
    this.nextSlot = 1 - this.nextSlot;
    if (d.nv) { gl.bindBuffer(gl.ARRAY_BUFFER, slot.vbo); gl.bufferData(gl.ARRAY_BUFFER, new Uint8Array(d.buf, vOff, d.nv * 32), gl.STREAM_DRAW); }
    if (d.ni) { gl.bindVertexArray(this.vao); gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, slot.ibo); gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint32Array(d.buf, iOff, d.ni), gl.STREAM_DRAW); }
    // (vx: the frame's vertices as floats, only while it is replayed: each draw's first vertex is its anchor)
    const frame = keep ? { c: c.slice(), t: d.t, slot, start: this.snapshot(), draws: new Map(), vx: new Float32Array(d.buf, vOff, d.nv * 8) } : null;
    this.replay(c, d.nc, slot, (at, n) => new Uint8Array(d.buf, bOff + at, n), frame, !keep);
    if (keep) {
      frame.vx = null;
      if (this.cur && this.cur.slot === slot) this.cur = null;      // (cannot happen with two slots; kept as a guard)
      this.prev = this.cur;
      this.cur = frame;
      if (this.prev) this.pair(this.prev, frame);
    } else {
      // a frame with 2D changes is on view as it is; blending starts again from the next frame of 3D draws
      this.prev = null;
      this.cur = null;
    }
  }

  /**
   * The frame's calls in order, into the flip chain. frame (a kept frame): each draw's matrices and anchor are
   * written down for pairing. showFlip: FLIP also shows the picture (frames that are not blended).
   */
  replay(c, nc, slot, pixels, frame, showFlip) {
    const gl = this.gl;
    const modeOf = (prim) => (prim === 4 ? gl.TRIANGLES : prim === 5 ? gl.TRIANGLE_STRIP : gl.TRIANGLE_FAN);
    this.pendingTag = null;
    for (let k = 0; k < nc;) {
      switch (c[k]) {
        case CMD.STATE: this.state.set(c[k + 1], c[k + 2]); k += 3; break;
        case CMD.TAG: this.pendingTag = k; k += 6; break;
        case CMD.TRANSFORM: {
          const type = c[k + 1];
          const dst = type === 1 ? this.world : type === 2 ? this.view : this.proj;
          for (let j = 0; j < 16; j++) dst[j] = c[k + 2 + j];
          k += 18; break;
        }
        case CMD.VIEWPORT: this.setViewport(c, k + 1); k += 9; break;
        case CMD.TEXTURE: this.uploadTexture(c[k + 1], c[k + 2], c[k + 3], pixels(c[k + 4], c[k + 2] * c[k + 3] * 4)); k += 5; break;
        case CMD.FREE: { const t = this.textures.get(c[k + 1]); if (t) { gl.deleteTexture(t); this.textures.delete(c[k + 1]); } k += 2; break; }
        case CMD.DRAW:
        case CMD.DRAWIDX: {
          const indexed = c[k] === CMD.DRAWIDX;
          const prim = c[k + 1], vtype = c[k + 2], first = c[k + 3], count = c[k + 4], tex = c[k + 5];
          const base = indexed ? c[k + 6] : first, nverts = indexed ? c[k + 7] : count;
          const flags = indexed ? c[k + 8] : c[k + 6], hud = flags & 1, sheet = flags & 2;
          // the TAG just before this draw (source/host/shadows.js), if any: its place in c
          const tag = this.pendingTag;
          this.pendingTag = null;
          const decal = tag !== null && (c[tag + 2] & TAG.DECAL) !== 0;
          if (decal) this.stats.decals++;
          if (frame) frame.draws.set(k, this.drawInfo(frame, prim, vtype, count, tex, base, nverts, hud, sheet, tag === null ? null : c, tag));
          this.bindTarget('back');
          this.prepare(vtype, tex, hud, sheet, decal);
          gl.uniformMatrix4fv(this.u.uWorld, false, this.world);
          gl.uniformMatrix4fv(this.u.uView, false, this.view);
          gl.uniformMatrix4fv(this.u.uProj, false, this.proj);
          gl.uniform1f(this.u.uVertT, 1);
          this.bindVerts(slot.vbo, base, slot.vbo, base);
          if (indexed) { gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, slot.ibo); gl.drawElements(modeOf(prim), count, gl.UNSIGNED_INT, first * 4); }
          else gl.drawArrays(modeOf(prim), 0, count);
          this.endCut();
          this.stats.draws++;
          k += indexed ? 9 : 7; break;
        }
        case CMD.CLIP: this.setCut(c, k); k += 6; break;
        case CMD.CLEAR: this.clear('back', c[k + 1]); k += 2; break;
        case CMD.IMAGE: {
          const sw = c[k + 6], sh = c[k + 7];
          gl.activeTexture(gl.TEXTURE0);
          gl.bindTexture(gl.TEXTURE_2D, this.imageTex);
          gl.pixelStorei(gl.UNPACK_ALIGNMENT, 1);
          gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA8, sw, sh, 0, gl.RGBA, gl.UNSIGNED_BYTE, pixels(c[k + 9], sw * sh * 4));
          gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
          gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
          gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
          gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
          gl.uniform1i(this.u.uTex, 0);
          this.rect2d(c[k + 1] !== 0, c[k + 2], c[k + 3], c[k + 4], c[k + 5], 1, 0);
          k += 10; break;
        }
        case CMD.FILL: this.rect2d(c[k + 1] !== 0, c[k + 2], c[k + 3], c[k + 4], c[k + 5], 2, c[k + 6]); k += 7; break;
        case CMD.FLIP: if (showFlip) this.show('back'); this.front = 1 - this.front; this.stats.frames++; this.pendingTag = null; k += 1; break;
        case CMD.PRESENT: this.show('front'); this.stats.frames++; k += 1; break;
        case CMD.MODE: this.setMode(c[k + 1], c[k + 2]); k += 3; break;
        default: throw new Error('render command ' + c[k] + ' at ' + k);
      }
    }
  }

  clear(which, flags) {
    const gl = this.gl;
    this.bindTarget(which);
    const vp = this.vp || { x: 0, y: 0, width: this.mode.width, height: this.mode.height };
    gl.enable(gl.SCISSOR_TEST);
    if (this.fullView()) gl.scissor(0, 0, this.width, this.height);
    else gl.scissor(...this.pixelRect(vp.x, vp.y, vp.width, vp.height));
    let bits = 0;
    if (flags & 1) { gl.clearColor(0, 0, 0, 1); bits |= gl.COLOR_BUFFER_BIT; }
    if (flags & 2) { gl.depthMask(true); gl.clearDepth(1); bits |= gl.DEPTH_BUFFER_BIT; }
    if (bits) gl.clear(bits);
    gl.disable(gl.SCISSOR_TEST);
  }

  /**
   * A draw of a kept frame: what pairs it, its matrices of the moment, and where it is (its anchor). c, tag: the
   * frame's commands and the place of the draw's TAG in them (or null). A FOLLOW tag adds the owner's id to the key
   * (so a kart's shadow or flare pairs only with the same kart's) and keeps the owner's place (ox, oy, oz).
   */
  drawInfo(frame, prim, vtype, count, tex, base, nverts, hud, sheet, c, tag) {
    const v = frame.vx, o = base * 8;
    const vx = nverts ? v[o] : 0, vy = nverts ? v[o + 1] : 0, vz = nverts ? v[o + 2] : 0;
    const w = this.world;
    const flags = c ? c[tag + 2] : 0, follow = (flags & TAG.FOLLOW) !== 0;
    return {
      key: tex + ':' + prim + ':' + vtype + ':' + count + ':' + nverts + (follow ? ':' + c[tag + 1] : ''),
      world: this.world.slice(), view: this.view.slice(), proj: this.proj.slice(), base, nverts, vx, vy, vz,
      ax: w[12] + vx, ay: w[13] + vy, az: w[14] + vz,
      partner: null, vertexBlend: false, hud, sheet,
      follow, hold: (flags & TAG.HOLD) !== 0, decal: (flags & TAG.DECAL) !== 0,
      ox: follow ? c[tag + 3] : 0, oy: follow ? c[tag + 4] : 0, oz: follow ? c[tag + 5] : 0,
    };
  }

  /** Each draw of the newer frame gets the nearest draw of the older one with the same key that is still free. */
  pair(older, newer) {
    const groups = new Map();
    for (const d of older.draws.values()) {
      if (d.hud || d.hold) continue;
      let g = groups.get(d.key);
      if (!g) groups.set(d.key, (g = []));
      g.push(d);
    }
    const followers = [];
    for (const d of newer.draws.values()) {
      if (d.hud) continue;
      // (HOLD: an engine flare with Motorlicht volgt de kart off, at its newest pass as the JS reconstruction draws it)
      if (d.hold) { this.stats.held++; continue; }
      if (d.follow) { followers.push(d); continue; }
      const g = groups.get(d.key);
      if (!g || !g.length) { this.stats.unpaired++; continue; }
      let best = -1, bestD = Infinity;
      for (let j = 0; j < g.length; j++) {
        const e = g[j];
        const dist = (e.ax - d.ax) ** 2 + (e.ay - d.ay) ** 2 + (e.az - d.az) ** 2;
        if (dist < bestD) { bestD = dist; best = j; }
      }
      const e = g.splice(best, 1)[0];
      d.partner = e;
      // the vertices move by themselves (smoke, sparks, animated meshes) when they differ; blended unless they jumped
      d.vertexBlend = e.nverts === d.nverts && Math.hypot(e.vx - d.vx, e.vy - d.vy, e.vz - d.vz) < VERTEX_JUMP;
      this.stats.paired++;
    }
    if (followers.length) this.pairFollowers(groups, followers);
  }

  /**
   * FOLLOW draws (a kart's shadow, its engine flares) pair only within their owner's (the id is in the key), by their
   * place relative to the owner, the nearest pairs first: a turbo gives a kart up to three flares, and the pool they
   * live in moves them when one comes or goes (2026-11-25, Frankrijk), so neither the draw order nor the absolute
   * place, which moves 14 units a pass at racing speed, tells which is which. A flare that has none in the pass before
   * shows the newer pass, as a new flare does in the JS reconstruction (race-visuals.js:538-541).
   */
  pairFollowers(groups, followers) {
    const cand = [];
    for (const d of followers) {
      const g = groups.get(d.key);
      if (!g) continue;
      for (const e of g) cand.push({ dist: ((d.ax - d.ox) - (e.ax - e.ox)) ** 2 + ((d.ay - d.oy) - (e.ay - e.oy)) ** 2 + ((d.az - d.oz) - (e.az - e.oz)) ** 2, d, e });
    }
    cand.sort((a, b) => a.dist - b.dist);
    const taken = new Set();
    for (const { d, e } of cand) {
      if (d.partner || taken.has(e)) continue;
      taken.add(e);
      d.partner = e;
      // in world coordinates and moving with the kart: blended unless the owner jumped, the test blendMatrix gives
      // the owner's own matrix, so the kart and what follows it snap together
      // (a kart turning more than SPIN a pass keeps its newer rotation, blendMatrix, while these stay blended point by
      // point; measured: no such turn in 4000 passes on Frankrijk and Duitsland, evidence/checks/shadows.txt)
      d.vertexBlend = e.nverts === d.nverts && Math.hypot(e.ox - d.ox, e.oy - d.oy, e.oz - d.oz) <= TELEPORT;
      this.stats.followed++;
      if (!d.vertexBlend) this.stats.followSnapped++;
      this.stats.paired++;
    }
    for (const d of followers) if (!d.partner) this.stats.unpaired++;
  }

  /** The display: a blend of the two kept frames at the time `now` (performance.timeOrigin + now(), ms). */
  present(now) {
    const cur = this.cur;
    if (!cur) return false;
    const prev = this.prev;
    const span = prev ? Math.min(100, Math.max(10, cur.t - prev.t)) : 25;
    // (debug.blendAt: every picture at that point between the two frames, to look at blends in a still)
    const t = !prev ? 1 : this.debug.blendAt !== undefined ? this.debug.blendAt : Math.min(1, Math.max(0, (now - cur.t) / span));
    if (this.shownFrame === cur && this.shownT === t) return false;       // nothing new to show (a paused game)
    this.shownFrame = cur;
    this.shownT = t;
    const gl = this.gl;
    const end = this.snapshot();
    this.restore(cur.start);
    const c = cur.c, slot = cur.slot, prevSlot = prev ? prev.slot : slot;
    const modeOf = (prim) => (prim === 4 ? gl.TRIANGLES : prim === 5 ? gl.TRIANGLE_STRIP : gl.TRIANGLE_FAN);
    for (let k = 0; k < c.length;) {
      switch (c[k]) {
        case CMD.STATE: this.state.set(c[k + 1], c[k + 2]); k += 3; break;
        case CMD.TAG: k += 6; break;                  // written down in its draw's info
        case CMD.TRANSFORM: k += 18; break;           // each draw has its own, written down
        case CMD.VIEWPORT: this.setViewport(c, k + 1); k += 9; break;
        case CMD.TEXTURE: k += 5; break;              // uploaded when the frame came
        case CMD.FREE: k += 2; break;
        case CMD.DRAW:
        case CMD.DRAWIDX: {
          const indexed = c[k] === CMD.DRAWIDX;
          const info = cur.draws.get(k);
          const prim = c[k + 1], vtype = c[k + 2], first = c[k + 3], count = c[k + 4], tex = c[k + 5];
          this.bindTarget('display');
          this.prepare(vtype, tex, info.hud, info.sheet, info.decal);
          const e = prev && info.partner;
          let vertT = 1;
          if (e && t < 1) {
            const moved = blendMatrix(this.bw, e.world, info.world, t, false);
            blendMatrix(this.bv, e.view, info.view, t, true);
            for (let j = 0; j < 16; j++) this.bp[j] = e.proj[j] + (info.proj[j] - e.proj[j]) * t;
            if (moved && info.vertexBlend) vertT = t;
            gl.uniformMatrix4fv(this.u.uWorld, false, this.bw);
            gl.uniformMatrix4fv(this.u.uView, false, this.bv);
            gl.uniformMatrix4fv(this.u.uProj, false, this.bp);
          } else {
            gl.uniformMatrix4fv(this.u.uWorld, false, info.world);
            gl.uniformMatrix4fv(this.u.uView, false, info.view);
            gl.uniformMatrix4fv(this.u.uProj, false, info.proj);
          }
          gl.uniform1f(this.u.uVertT, vertT);
          if (vertT < 1) this.bindVerts(slot.vbo, info.base, prevSlot.vbo, e.base);
          else this.bindVerts(slot.vbo, info.base, slot.vbo, info.base);
          if (indexed) { gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, slot.ibo); gl.drawElements(modeOf(prim), count, gl.UNSIGNED_INT, first * 4); }
          else gl.drawArrays(modeOf(prim), 0, count);
          this.endCut();
          k += indexed ? 9 : 7; break;
        }
        case CMD.CLIP: this.setCut(c, k); k += 6; break;
        case CMD.CLEAR: this.clear('display', c[k + 1]); k += 2; break;
        case CMD.FLIP: k += 1; break;
        case CMD.MODE: k += 3; break;
        default: k += 1; break;                        // (a kept frame has no IMAGE, FILL or PRESENT)
      }
    }
    this.restore(end);
    this.show('display');
    return true;
  }
}
