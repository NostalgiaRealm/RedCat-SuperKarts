// Render thread: owns the page's canvas (an OffscreenCanvas, taken once per page) and draws on it what the game
// thread sends, one message per frame (source/render/recorder.js), replayed by gl-renderer.js, which also blends
// the last two frames on the display's rate (smoothing; options.smooth false switches it off). Unlike the game
// thread it returns to its event loop after every frame, which is what lets the browser show the picture and free
// what it used. The page runs many races on one canvas (source/race-runner.js): the canvas and the renderer stay,
// and between races the recorder sends { reset: true } on the frame port, which deletes every texture, puts the
// renderer's state back and clears the picture (GLRenderer.reset).
//
// Page -> this worker:
//   { t: 'init', canvas, ctrl, port, width, height, samples, debug, smooth, frameCap }   once
//   { t: 'resize', width, height, samples }   the drawing size or MSAA changed
//   { t: 'fps', on }                            count the pictures shown per second (FPS weergeven) or not
// This worker -> page:
//   { t: 'ready', width, height, samples, supportedSamples, maxSize }, { t: 'resized', ... } (the same fields)
//   { t: 'shown', race }       the race's first picture that is not all black (its loading screen) is on the canvas
//   { t: 'reset', race, textures }   a race's textures are deleted
//   { t: 'fps', fps }          pictures per second (null while it warms up), the JS reconstruction's FpsCounter
//   { t: 'rstats', shownPerSec, framesPerSec, paired, unpaired, textures, decals, followed, followSnapped, held }   once a
//       second (draws in that second: surface shadows replayed; tagged draws paired with their owner's, of them cut loose
//       because the owner jumped; engine flares held at the newer pass; source/host/shadows.js)
//   { t: 'fatal', message }
import { GLRenderer } from '../render/gl-renderer.js';
import { CMD_SIZE } from '../render/recorder.js';
import { CTRL } from './shared.js';

let renderer = null, ctrl = null;
// a frame that came in a shared buffer is copied to this thread's memory first: the game thread writes there
// again two frames later, and not every browser lets WebGL read from shared memory
let mine = new ArrayBuffer(0);
// the race the frames belong to; waiting: its first picture with something on it is not on the canvas yet;
// shownAt: the shown-picture count after which the display loop tells the page (-1: not yet / already told)
let race = 0, waiting = false, shownAt = -1;
let fpsOn = false;

/**
 * Does a frame put something on the screen other than black? A race starts with black full-screen pictures (the
 * primary written black, frames 1-2), then the game's own loading screen (0x424360) and the race: a draw, a fill
 * or a picture with a coloured pixel (every 61st looked at) counts.
 */
function hasContent(buf, f) {
  const c = new Float64Array(buf, 0, f.nc);
  const bytes = new Uint8Array(buf, f.nc * 8 + f.nv * 32 + f.ni * 4, f.nb);
  for (let k = 0; k < f.nc;) {
    const op = c[k];
    if (op === 6 || op === 7) return true;                              // DRAW, DRAWIDX
    if (op === 10 && c[k + 6] !== 0) return true;                       // FILL with a colour
    if (op === 9) {                                                     // IMAGE: w x h source pixels (RGBA) at its offset
      const at = c[k + 9], n = c[k + 6] * c[k + 7] * 4;
      for (let p = at; p < at + n; p += 61 * 4) if (bytes[p] | bytes[p + 1] | bytes[p + 2]) return true;
    }
    k += CMD_SIZE[op] || 1;
  }
  return false;
}

const sizeInfo = () => ({ width: renderer.width, height: renderer.height, samples: renderer.samples, supportedSamples: renderer.supportedSamples, maxSize: renderer.maxSize });
const fatal = (err) => self.postMessage({ t: 'fatal', message: String(err && err.message ? err.message : err) });

/** "FPS weergeven", as the JS reconstruction's fps-counter.js: shown pictures per second over one-second windows
 * after a two-second warm-up; a pause or stall of more than a second starts it again. */
const fps = {
  previous: null, elapsed: 0, frames: 0, warmup: 2, value: null,
  reset() { this.previous = null; this.elapsed = 0; this.frames = 0; this.warmup = 2; if (this.value !== null) { this.value = null; self.postMessage({ t: 'fps', fps: null }); } },
  frame(time, count) {
    const dt = this.previous === null ? 0 : (time - this.previous) / 1000;
    this.previous = time;
    if (dt <= 0) return;
    if (dt > 1) { this.elapsed = this.frames = 0; this.warmup = 2; if (this.value !== null) { this.value = null; self.postMessage({ t: 'fps', fps: null }); } return; }
    if (this.warmup > 0) { this.warmup -= dt; return; }
    this.elapsed += dt; this.frames += count;
    if (this.elapsed < 1) return;
    this.value = this.frames / this.elapsed; this.elapsed = this.frames = 0;
    self.postMessage({ t: 'fps', fps: this.value });
  },
};

/** The JS reconstruction's frame-limit.js: on phones and tablets (the page says so: frameCap) a 90 or 120 Hz
 * display gets at most about 60 pictures a second; 60 Hz and slower displays never skip one. */
const limiter = {
  intervalMs: 1000 / 60, toleranceMs: 2, next: -Infinity,
  due(time) {
    if (time < this.next - this.toleranceMs) return false;
    this.next += this.intervalMs;
    if (this.next <= time) this.next = time + this.intervalMs;
    return true;
  },
};

function init(d) {
  ctrl = new Int32Array(d.ctrl);
  const smooth = d.smooth !== false;
  renderer = new GLRenderer(d.canvas, { debug: d.debug || {}, smooth, samples: d.samples || 0 });
  renderer.resize(d.width, d.height, d.samples || 0);
  fpsOn = !!d.fps;
  // the display loop: a blend of the last two passes of the game at the display's own rate (gl-renderer.js
  // present), at most 60 a second on a phone; it also counts the pictures shown (FPS) and tells the page when a
  // race's first picture is on the canvas
  let lastShown = renderer.stats.displayed;
  const display = (time) => {
    self.requestAnimationFrame(display);
    if (d.frameCap && !limiter.due(time)) return;
    if (smooth) {
      try { renderer.present(performance.timeOrigin + performance.now()); } catch (err) { fatal(err); }
    }
    const shown = renderer.stats.displayed;
    if (shown !== lastShown) {
      if (fpsOn) fps.frame(time, 1);
      if (shownAt >= 0 && shown > shownAt) { shownAt = -1; self.postMessage({ t: 'shown', race }); }
      lastShown = shown;
    }
  };
  self.requestAnimationFrame(display);
  d.port.onmessage = (m) => {
    const f = m.data;
    if (f.reset) {
      // a race starts or ended: its textures and state go, the picture is cleared
      try { renderer.reset(); } catch (err) { fatal(err); }
      Atomics.store(ctrl, CTRL.DEAD, 0);
      if (f.race !== undefined) { race = f.race; waiting = true; shownAt = -1; }
      fps.reset();
      self.postMessage({ t: 'reset', race: f.race, ended: !!f.ended, textures: renderer.textures.size });
      return;
    }
    try {
      let buf = f.buf;
      if (typeof SharedArrayBuffer === 'function' && buf instanceof SharedArrayBuffer) {
        const n = f.nc * 8 + f.nv * 32 + f.ni * 4 + f.nb;
        if (mine.byteLength < n) mine = new ArrayBuffer(Math.max(n, mine.byteLength * 2));
        new Uint8Array(mine).set(new Uint8Array(buf, 0, n));
        buf = mine;
      }
      const first = waiting && hasContent(buf, f);
      const before = renderer.stats.displayed;
      renderer.receive({ buf, nc: f.nc, nv: f.nv, ni: f.ni, nb: f.nb, t: f.t });
      if (first) {
        // the race's first picture with something on it: on the canvas now (a 2D frame, or no smoothing), or at the
        // display loop's next picture
        waiting = false;
        if (renderer.stats.displayed > before) self.postMessage({ t: 'shown', race });
        else shownAt = renderer.stats.displayed;
      }
    } catch (err) {
      Atomics.store(ctrl, CTRL.DEAD, 1);
      fatal(err);
    }
    Atomics.add(ctrl, CTRL.FRAMES, 1);
    Atomics.notify(ctrl, CTRL.FRAMES);
  };
  // once a second: pictures shown, game frames received, draws paired for blending, textures held (for checks and
  // ?stats)
  let last = { ...renderer.stats }, lastAt = performance.now();
  setInterval(() => {
    const s = renderer.stats, now = performance.now(), dt = (now - lastAt) / 1000;
    self.postMessage({ t: 'rstats', shownPerSec: Math.round((s.displayed - last.displayed) / dt), framesPerSec: Math.round((s.frames - last.frames) / dt), paired: s.paired - last.paired, unpaired: s.unpaired - last.unpaired, textures: renderer.textures.size,
      decals: s.decals - last.decals, followed: s.followed - last.followed, followSnapped: s.followSnapped - last.followSnapped, held: s.held - last.held });
    last = { ...s }; lastAt = now;
  }, 1000);
  self.postMessage({ t: 'ready', ...sizeInfo() });
}

self.onmessage = (e) => {
  const d = e.data;
  try {
    if (d.t === 'init') init(d);
    else if (d.t === 'resize') {
      // the drawing size or MSAA changed (the page was resized, a setting): buffers made anew, the next frame fills them
      if (!renderer) return;
      renderer.resize(d.width, d.height, d.samples);
      self.postMessage({ t: 'resized', ...sizeInfo() });
    } else if (d.t === 'fps') {
      fpsOn = !!d.on;
      fps.reset();
    }
  } catch (err) {
    if (ctrl) Atomics.store(ctrl, CTRL.DEAD, 1);
    fatal(err);
  }
};
