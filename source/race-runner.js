// Runs races of the recompiled rcskspel.dat on the page, any number of them one after another. The menu
// (source/main.js) starts races through this interface only:
//   const runner = new RaceRunner({ canvas, touchRoot, fpsElement, settings });
//   const outcome = await runner.start({ country, character, difficulty, raceType,
//     save: { bestTimes, playerPosition }, settings, onProgress(percent, stage), onRunning(), onEffects(percent) });
//   // outcome: { patch, effectsPercent, exitCode, error } (patch and effectsPercent: source/host/race-handoff.js
//   //   readResult; a race that crashed: { patch: { PLAYER: { finished: 0 } }, effectsPercent: null, exitCode: null, error })
//   // onEffects: once, after boot, with the effects percent the race plays with (race.ini FX_VOLUME after 0x437560,
//   //   which makes an enabled 0 into 75): the menu adopts it there, as the JS port's main.js:716-719 after its load
//   runner.applySettings(settings);   // drawing size, render scale, MSAA, FPS counter, touch, dead zone, bindings, the
//                                     // music and effects levels (source/host/live-volume.js);
//                                     // returns the drawing size { baseWidth, baseHeight, width, height, scale, limited }
//   runner.suspend(); runner.resume(); // the page is hidden / shown again (the menu calls these; the runner also
//                                     // follows visibilitychange itself while a race runs)
//   runner.active                      // true while a race runs
//   runner.msaaStatus                  // { enabled, requestedSamples, actualSamples, supportedSamples } (JS port shape)
//   runner.error                       // set when races cannot run here (no cross-origin isolation); start() resolves
//                                      // at once with it
//   runner.preload()                   // optional: fetch the module and the files now, so the first race starts sooner
//   runner.flying, runner.waiting      // free flight is on (settings.freeFlight, source/host/free-flight.js); the game
//                                      // waits in a loop of its own (its pause, its quit requester)
//   runner.menu(on)                    // the menu's settings over a running race (the flight panel's Instellingen): the
//                                      // race is held (game thread, sound, input, touch, FPS) until menu(false)
// For the development page and checks: runner.on(type, fn) ('stats', 'rstats', 'status', 'loaded', 'fps', 'reset',
// 'log', 'messagebox'), runner.inputState(), runner.audioState(), runner.lastLoad, runner.lastFiles (the game files at the
// last race's end: reads it waited for, all fetched; source/web/game-files.js stats), runner.lastRaceIni; start() also
// takes config.fixed (a fixed clock and date).
// country 0..5 in track.ini order (NED, DUI, ENG, FRA, SPA, ITA), character 0..3 (RedCat, WhizzKitty, Brutus, Max),
// difficulty 0..2, raceType 0..3 (Landenrace, Tijdrace, Sterrenrace, duel); settings: rcsk.settings.v1 (normalized).
// onProgress gets the overall percent (files 0..90, boot 90..100) and the stage ('files' | 'boot'); onRunning is
// called once, when the race's first picture that is not all black is on the canvas (the game's own loading screen,
// 0x424360, drawn while it boots).
// While a race runs the runner owns the canvas (shown) and the keyboard, pad and touch input; the menu hides its
// screens and ignores input until start() resolves. Outside races the canvas is hidden, no keyboard listener of the
// runner is attached and nothing is held.
//
// How: one game worker (source/web/worker.js) and one render worker (source/web/render-worker.js) per page, made
// here once; the game worker keeps the compiled module and the game files between races, the render worker keeps
// the canvas (an OffscreenCanvas can be taken only once) and its renderer, and drops a race's textures at its end.
// Input goes to the game worker through shared memory (source/web/shared.js, source/input/*). Sound plays on this
// page (source/web/audio.js), freed at the end of every race.
//
// The JS reconstruction's race-time behaviour kept here (its settings.js, fps-counter.js, frame-limit.js, input.js):
// the drawing size (renderDimensions: auto with about one megapixel on touch devices, every device pixel, presets,
// render scale, the GPU's limit), MSAA with the JS fallback rule, "FPS weergeven", 60 pictures a second at most on
// phones, the touch controls (auto/on/off), the pad's dead zone and bindings for pad and touch (also changed during a
// race: they reach the game's own table before its next pass, source/input/race-keys.js), and a pause when the page
// loses focus or the driving pad goes away: here the game's own pause, by pressing its P wherever 0x42f9c0 takes P
// (phases 0, 1 and 8, focusPause) and the game is not already waiting in a loop of its own; any key, the pad's A, B,
// Start, D-pad or stick (as they resume the JS port's focus pause: gamepad.js) or a tap on the picture resumes it, as
// the game's pause loop 0x42f220 waits for one (the touch controls stay up but inert, touch.js). On the result screens
// (phases 3 and 6), where the game ignores P, the race is held instead (focusHeld) until a key, one of those pad
// buttons or a tap on the picture; there a tap on the picture also holds Space (attachInput). In the quit requester the
// pad and the keyboard move a focus on its buttons (source/input/requester-focus.js).
// A focus pause is silent, as the JS port's (focusMuted: its DrivingView.suspend pauses music and effects, only its P
// pause keeps them) until the game leaves the loop it waits in; the FPS counter shows only while the race runs (not
// while the game waits in its pause or requester, as the JS port shows it in its modes race and viewer only).
import { CTRL, IN, CTRL_WAITING, OPT, HOLD } from './web/shared.js';
import { SharedInput } from './input/shared-input.js';
import { Gamepads } from './input/gamepad.js';
import { TouchControls } from './input/touch.js';
import { vkOf } from './input/keyboard.js';
import { RequesterFocus } from './input/requester-focus.js';
import { publishKeys, drivable } from './input/race-keys.js';
import { createAudioSink } from './web/audio.js';
import * as handoff from './host/race-handoff.js';
import { packVolumes } from './host/live-volume.js';

const MODE_W = 640, MODE_H = 480;
const VK_P = 0x50, VK_SPACE = 0x20, VK_C = 0x43;
const FOCUS_PAUSE_MS = 150;          // how long the focus pause holds P (at least, in game passes of 25 ms)
// The race phases (0x53b9c0, written only by 0x42f740) in which 0x42f9c0 takes P (`phase != 6 && phase != 3`, its last
// check; 0x42f740 is called with 0, 1, 3, 4, 6 and 8): racing, the start camera and countdown, the arrest (0x40a3b0).
// Not 4: the race is leaving (the JS reconstruction has left its race mode by then, main.js finishRace).
const P_PHASES = new Set([0, 1, 8]);
// The result screens (0x41fd90 finish, 0x420850 game over), where 0x42f9c0 ignores P: the runner holds the race instead.
const RESULT_PHASES = new Set([3, 6]);
const KEY_MIN_HOLD_MS = 80;         // the shortest key press the game sees (the pointer and touch buttons use 80 ms too)
const ACTIONS = ['accelerate', 'brake', 'left', 'right', 'bonus', 'handbrake'];
export const DEFAULT_KEYS = Object.freeze({ accelerate: 0x26, brake: 0x28, left: 0x25, right: 0x27, bonus: 0x11, handbrake: 0x12 });
const NOT_FINISHED = () => ({ PLAYER: { finished: 0 } });
// keys the browser keeps (reload, full screen, developer tools); the game gets them too
const BROWSER_KEYS = new Set(['F5', 'F11', 'F12']);
// the JS reconstruction's menu keys (its input.js:66), which it keeps from the browser while its race waits
const MENU_CODES = new Set(['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight', 'Enter', 'Space']);

// --- the JS reconstruction's drawing size (source/settings.js there) -------------------------------------------
export const RESOLUTIONS = Object.freeze({ auto: null, native: null, '640x480': [640, 480], '800x600': [800, 600], '1024x768': [1024, 768], '1280x720': [1280, 720], '1920x1080': [1920, 1080], '2560x1440': [2560, 1440], '3840x2160': [3840, 2160] });
const bounded = (v, a, b, d) => (typeof v === 'number' && Number.isFinite(v) ? Math.min(b, Math.max(a, v)) : d);
/** "Automatisch" on phones and tablets stops at about a megapixel (MOBILE_AUTO_PIXELS). */
export const MOBILE_AUTO_PIXELS = 1e6;
export const autoPixelBudget = () => (globalThis.matchMedia?.('(pointer: coarse)').matches ? MOBILE_AUTO_PIXELS : Infinity);
/**
 * The drawing size, as the JS reconstruction's renderDimensions: width and height in CSS pixels; resolution 'auto'
 * (CSS pixels times the device pixel ratio, at most autoPixels), 'native' (every device pixel) or a preset 'WxH'
 * (the largest rectangle of the viewport's shape inside it; any WxH is taken); renderScale 25..200 percent;
 * maxSize the GPU's limit (limited: the scale was cut to fit it).
 */
export function renderDimensions({ width, height, dpr = 1, resolution = 'auto', renderScale = 100, maxSize = 16384, autoPixels = Infinity }) {
  width = Math.max(1, Number(width) || 1); height = Math.max(1, Number(height) || 1);
  dpr = bounded(dpr, 0.25, 8, 1);
  const m = /^(\d+)x(\d+)$/.exec(resolution || '');
  const preset = RESOLUTIONS[resolution] || (m ? [Number(m[1]), Number(m[2])] : null);
  let baseWidth, baseHeight;
  if (!preset) {
    const ratio = resolution === 'native' || resolution === 'full' ? dpr : Math.min(dpr, Math.sqrt(autoPixels / (width * height)));
    baseWidth = Math.round(width * ratio); baseHeight = Math.round(height * ratio);
  } else {
    const fit = Math.min(preset[0] / width, preset[1] / height);
    baseWidth = Math.max(1, Math.round(width * fit)); baseHeight = Math.max(1, Math.round(height * fit));
  }
  const scale = bounded(renderScale, 25, 200, 100) / 100;
  const factor = Math.min(scale, maxSize / baseWidth, maxSize / baseHeight);
  return { baseWidth, baseHeight, width: Math.max(1, Math.round(baseWidth * factor)), height: Math.max(1, Math.round(baseHeight * factor)), scale: factor, limited: factor < scale };
}

/** The virtual keys bound to the six actions (race-handoff.js bindingsToVk or codeToVk; else the defaults). */
export function boundKeys(settings) {
  const keys = { ...DEFAULT_KEYS };
  const take = (action, vk) => { if (Number.isInteger(vk) && vk >= 0 && vk < 256) keys[action] = vk; };
  try {
    if (typeof handoff.bindingsToVk === 'function') {
      const r = handoff.bindingsToVk(settings);
      if (Array.isArray(r)) ACTIONS.forEach((a, k) => take(a, r[k]));
      else if (r && typeof r === 'object') for (const a of ACTIONS) take(a, r[a] ?? r[a.toUpperCase()]);
    } else if (typeof handoff.codeToVk === 'function' && settings && settings.bindings) {
      for (const a of ACTIONS) if (typeof settings.bindings[a] === 'string') take(a, settings.bindings[a] === '' ? 0 : handoff.codeToVk(settings.bindings[a]));
    }
  } catch (e) { /* the defaults */ }
  return keys;
}

export class RaceRunner {
  /**
   * canvas: the page's <canvas id="game"> (hidden outside races; taken by the render worker once);
   * touchRoot: the #touch-controls block (or null); fpsElement: the FPS label (or null); settings: rcsk.settings.v1.
   * Development and packaging options: baseUrl (where game/ is; default: the folder above source/), urls (worker.js
   * DEFAULT_URLS overrides, relative to baseUrl or absolute; data defaults to the page's folder's data/), dev: { smooth
   * (false: ?nosmooth), debug: { noCull, blendAt } }.
   * cheats: the original's debug and cheat keys answer (OPT.CHEATS, source/host/safeguards.js): the development page
   * unless ?nocheats, the menu only with ?cheats; runner.cheats can change it, applySettings() passes it on.
   */
  constructor({ canvas, touchRoot = null, fpsElement = null, settings = null, baseUrl = null, urls = null, dev = {}, cheats = false } = {}) {
    this.canvas = canvas;
    this.touchRoot = touchRoot;
    this.fpsElement = fpsElement;
    this.active = false;
    this.running = false;
    this.error = null;
    this.raceCount = 0;
    this.pending = null;
    this.listeners = new Map();
    this.settings = settings || {};
    this.cheats = cheats === true;
    this.size = null;
    this.maxSize = 8192;
    this.supportedSamples = null;
    this.msaaStatus = { enabled: false, requestedSamples: 4, actualSamples: 0, supportedSamples: [] };
    this.hiddenPage = false;
    this.pageSuspended = false;
    this.menuHeld = false;
    this.focusHold = null;
    this.focusHeld = false;
    this.focusMuted = false;            // a focus pause's silence (muteFocus)
    this.focusMuteWaited = false;
    this.effectsPercent = null;         // the effects level the race plays with, after boot (onEffects)
    this.lastLoad = null;
    this.lastFiles = null;
    this.lastRaceIni = '';
    this.fpsLabel = 'FPS: …';
    this.coarse = !!globalThis.matchMedia?.('(pointer: coarse)').matches;
    this.hideCanvas();
    if (fpsElement) fpsElement.hidden = true;
    if (!self.crossOriginIsolated) {
      this.error = 'Deze pagina moet cross-origin isolated zijn (COOP/COEP)';
      return;
    }
    const ctrl = this.ctrl = new Int32Array(new SharedArrayBuffer(CTRL.SIZE * 4));
    const input = this.input = new Int32Array(new SharedArrayBuffer(IN.SIZE * 4));
    // the virtual joystick is centred before a game starts: it calibrates once, at boot (0x4ba5e0)
    this.shared = new SharedInput(input);
    // pauseKind: while waiting, 1 the game's pause, 2 its quit requester, 0 another wait (CTRL.PAUSE_KIND, shared.js)
    // focus: the runner's focus pause is on (focusMuted), whose pause the pad's B and stick also end (gamepad.js)
    const gameState = () => ({ waiting: Atomics.load(ctrl, CTRL_WAITING) === 1, pauseKind: Atomics.load(ctrl, CTRL.PAUSE_KIND), phase: Atomics.load(ctrl, CTRL.PHASE), flying: Atomics.load(ctrl, CTRL.FLIGHT_ACTIVE) === 1, focus: this.focusMuted === true });
    this.gameState = gameState;
    this.keys = boundKeys(this.settings);
    // the quit requester's focus for the pad and the keyboard (as the JS port's focused ja/nee buttons)
    this.requesterFocus = new RequesterFocus(this.shared);
    this.pads = new Gamepads(this.shared, gameState, { deadzone: bounded(this.settings.deadzone, 0, 0.5, 0.18), keys: this.keys, onLost: () => this.focusPause('pad'), focus: this.requesterFocus });
    this.touch = touchRoot ? new TouchControls(touchRoot, this.shared, gameState, { keys: this.keys }) : null;
    if (this.touch) this.touch.hide();
    this.sound = createAudioSink();
    // the safe area's insets: env(safe-area-inset-*) on a probe element (hudShape)
    this.hudProbe = document.createElement('div');
    this.hudProbe.style.cssText = 'position:fixed;left:0;top:0;width:0;height:0;visibility:hidden;pointer-events:none;'
      + 'padding:env(safe-area-inset-top,0px) env(safe-area-inset-right,0px) env(safe-area-inset-bottom,0px) env(safe-area-inset-left,0px)';
    document.body.append(this.hudProbe);

    // the workers: one of each per page
    const channel = new MessageChannel();
    this.renderWorker = new Worker(new URL('./web/render-worker.js', import.meta.url), { type: 'module' });
    this.renderWorker.onmessage = (e) => this.onRender(e.data);
    this.renderWorker.onerror = (e) => this.emit('log', 'render worker: ' + (e.message || e));
    const size = this.drawingSize();
    this.size = size;
    Atomics.store(ctrl, CTRL.ASPECT, Math.round(size.width / size.height * 1e6));
    const offscreen = canvas.transferControlToOffscreen();
    this.renderWorker.postMessage({ t: 'init', canvas: offscreen, width: size.width, height: size.height, samples: this.samples(), ctrl: ctrl.buffer, port: channel.port2,
      debug: (dev && dev.debug) || {}, smooth: !dev || dev.smooth !== false, frameCap: this.coarse, fps: this.settings.showFps === true }, [offscreen, channel.port2]);
    this.gameWorker = new Worker(new URL('./web/worker.js', import.meta.url), { type: 'module' });
    this.gameWorker.onmessage = (e) => this.onGame(e.data);
    // a game worker that fails outside a race (its module did not load) fails every race after it
    this.gameWorker.onerror = (e) => {
      e.preventDefault?.();
      const error = 'game worker: ' + (e.message || 'failed to load');
      if (this.pending) this.finish({ error }); else this.workerError = error;
    };
    this.gameWorker.postMessage({ t: 'init', ctrl: ctrl.buffer, input: input.buffer, port: channel.port1,
      // game/ (the module and its lists) beside source/, data/ (the original files) beside the page: in a package these
      // are app/<revision>/game/ and the site's data/ (tools/package.mjs), on the development server /game/ and /data/
      baseUrl: baseUrl || new URL('..', import.meta.url).href, urls: { data: new URL('data/', document.baseURI).href, ...(urls || {}) } }, [channel.port1]);

    // always there, active only while a race runs
    addEventListener('resize', () => { if (!this.active) return; clearTimeout(this.resizeTimer); this.resizeTimer = setTimeout(() => this.resize(), 150); this.hudShape(); });
    this.applySettings(this.settings);
  }

  /** For the development page and checks: 'stats', 'rstats', 'log', 'messagebox', 'status', 'loaded', 'fps'. */
  on(type, fn) {
    if (!this.listeners.has(type)) this.listeners.set(type, new Set());
    this.listeners.get(type).add(fn);
    return () => this.listeners.get(type).delete(fn);
  }

  emit(type, value) {
    const set = this.listeners.get(type);
    if (set) for (const fn of set) { try { fn(value); } catch (e) { console.error(e); } }
  }

  /** Fetch the module and the files a race needs now (optional: the first race then starts at once). */
  preload() {
    if (this.gameWorker) this.gameWorker.postMessage({ t: 'preload' });
  }

  samples() {
    const s = this.settings;
    return s.msaaEnabled === true ? ([2, 4, 8].includes(s.msaaSamples) ? s.msaaSamples : 4) : 0;
  }

  drawingSize() {
    const c = this.canvas;
    const width = (this.active && c.clientWidth) || innerWidth, height = (this.active && c.clientHeight) || innerHeight;
    const s = this.settings;
    return renderDimensions({ width, height, dpr: devicePixelRatio, resolution: s.resolution || 'auto', renderScale: s.renderScale ?? 100, maxSize: this.maxSize, autoPixels: autoPixelBudget() });
  }

  /** The settings that act during a race (see the header); returns the drawing size. */
  applySettings(settings) {
    if (settings) this.settings = settings;
    const s = this.settings;
    this.showTouch = s.touch === 'on' || (s.touch !== 'off' && this.coarse);
    this.msaaStatus = { enabled: s.msaaEnabled === true, requestedSamples: [2, 4, 8].includes(s.msaaSamples) ? s.msaaSamples : 4, actualSamples: this.msaaStatus.actualSamples, supportedSamples: [...(this.supportedSamples || [])] };
    if (this.error) return this.drawingSize();
    // free flight (Vrij vliegen): the game worker takes off at the next racing pass and lands when it goes off
    Atomics.store(this.ctrl, CTRL.FLIGHT, s.freeFlight === true ? 1 : 0);
    // the debug and cheat keys (not a menu setting: the JS reconstruction has none); only this bit of CTRL.OPTIONS
    if (this.cheats) Atomics.or(this.ctrl, CTRL.OPTIONS, OPT.CHEATS); else Atomics.and(this.ctrl, CTRL.OPTIONS, ~OPT.CHEATS);
    // Schaduwen op het wegdek and Motorlicht volgt de kart, on unless switched off (the JS reconstruction's
    // settings.js:12), at race start and live after OK (source/host/shadows.js reads them before every pass)
    const visuals = (s.surfaceShadows !== false ? OPT.SURFACE_SHADOWS : 0) | (s.smoothEngineLights !== false ? OPT.SMOOTH_ENGINE_LIGHTS : 0);
    Atomics.and(this.ctrl, CTRL.OPTIONS, ~(OPT.SURFACE_SHADOWS | OPT.SMOOTH_ENGINE_LIGHTS));
    Atomics.or(this.ctrl, CTRL.OPTIONS, visuals);
    this.pads.deadzone = bounded(s.deadzone, 0, 0.5, 0.18);
    this.keys = boundKeys(s);
    // to the game worker too, which writes a change during a race into the game's table before the next pass (the JS
    // reconstruction applies new bindings at once, its input.js:71)
    publishKeys(this.ctrl, this.keys);
    // the music and effects levels: the game worker puts a change during a race into the race's own volume code
    // before its next pass (source/host/live-volume.js), as the JS port's resumeViewer -> setAudioSettings applies both
    // at once (main.js:732, driving-view.js:378-383); at the start the handoff writes them into race.ini
    Atomics.store(this.ctrl, CTRL.VOLUME, packVolumes(s));
    // the pad's X and Y and the touch Bonus and Rem hold the keys bound to the bonus and the handbrake, but never P or
    // Esc (bound, they do not drive, race-keys.js drivable): the JS port's pad and touch buttons are actions, not keys
    const held = (vk) => (drivable(vk) ? vk : 0);
    const padKeys = { bonus: held(this.keys.bonus), handbrake: held(this.keys.handbrake) };
    this.pads.setKeys(padKeys);
    if (this.touch) this.touch.setKeys(padKeys);
    this.renderWorker.postMessage({ t: 'fps', on: s.showFps === true });
    this.updateFps();
    return this.resize();
  }

  /** The drawing size for the canvas's size now; the render worker makes its buffers anew when it changed. */
  resize(force = false) {
    if (this.error) return this.drawingSize();
    const size = this.drawingSize();
    const samples = this.samples();
    const last = this.size;
    this.size = size;
    if (force || !last || last.width !== size.width || last.height !== size.height || this.lastSamples !== samples) {
      this.lastSamples = samples;
      Atomics.store(this.ctrl, CTRL.ASPECT, Math.round(size.width / size.height * 1e6));
      this.renderWorker.postMessage({ t: 'resize', width: size.width, height: size.height, samples });
    }
    if (this.active) this.hudShape();
    return size;
  }

  // --- HUD insets and touch band (source/host/hud-layout.js; the game worker reads them before every pass) ---
  // What the JS reconstruction's measureRaceHudLayout measures (its source/race-hud-layout.js:38-47), from which
  // hud-layout.js places and sizes the HUD as its raceHudLayout does: the safe area's insets (env(safe-area-inset-*)
  // on a probe element, the part over the canvas), at least 8 CSS px at the top and the sides of an upright canvas,
  // and the touch controls' band (their box's height less the bottom inset, which the box's padding already holds),
  // as fractions of the canvas's width (left, right) or height (top, bottom, band in CTRL.CONTROLS_L).
  // CTRL.HUD_SCALE stays 1000: the HUD's size follows from these (race-hud-layout.js:9-13).
  hudShape() {
    const ctrl = this.ctrl;
    const r = this.canvas.getBoundingClientRect();
    if (!r.width || !r.height) return;
    const cs = getComputedStyle(this.hudProbe);
    const upright = r.height > r.width;
    const px = (side, edge) => Math.max(0, (parseFloat(cs['padding' + side]) || 0) - edge);
    const bottom = px('Bottom', innerHeight - r.bottom);
    // While the game waits in its quit requester the controls only step aside (touch.js) and the HUD is not drawn
    // (0x42f290 only polls keys and the mouse): the band stays, so the first passes after it keep the HUD's size.
    const root = this.touchRoot;
    let band = 0;
    if (root && !root.hidden) band = this.hudBand = Math.max(0, root.getBoundingClientRect().height - bottom);
    else if (root && this.showTouch && this.gameState().waiting) band = this.hudBand || 0;
    Atomics.store(ctrl, CTRL.INSET_L, Math.round(Math.max(upright ? 8 : 0, px('Left', r.left)) / r.width * 1e4));
    Atomics.store(ctrl, CTRL.INSET_R, Math.round(Math.max(upright ? 8 : 0, px('Right', innerWidth - r.right)) / r.width * 1e4));
    Atomics.store(ctrl, CTRL.INSET_T, Math.round(Math.max(upright ? 8 : 0, px('Top', r.top)) / r.height * 1e4));
    Atomics.store(ctrl, CTRL.INSET_B, Math.round(bottom / r.height * 1e4));
    Atomics.store(ctrl, CTRL.CONTROLS_L, Math.round(band / r.height * 1e4));
    Atomics.store(ctrl, CTRL.CONTROLS_R, 0);
    Atomics.store(ctrl, CTRL.HUD_SCALE, 1000);
    // a game thread that sleeps on CTRL.PAUSED (a held race, or its pause loop under a hidden page) wakes to draw the
    // held picture with the HUD laid out for the new shape (worker.js repaint); its pause loop looks every nap anyway
    Atomics.notify(ctrl, CTRL.PAUSED);
  }

  // --- the page hidden, focus lost ------------------------------------------------------------------------------
  /** The page is hidden (or the menu wants the race held): the game thread sleeps (CTRL.PAUSED), sound stops. */
  suspend() {
    this.pageSuspended = true;
    this.focusPause('suspend');
    this.updatePaused();
  }

  resume() {
    this.pageSuspended = false;
    this.updatePaused();
  }

  /**
   * The menu's settings over the race (the flight panel's Instellingen, as the JS reconstruction's showSettings('viewer')
   * suspends its race, main.js:74, :108): every key, pad and touch hold let go, the game thread and the sound held
   * (CTRL.PAUSED, music too), the runner's keys, pad and touch controls off and the FPS counter hidden, so the menu has
   * the input; a hidden page or focus loss under it changes nothing. menu(false) gives the race back.
   */
  menu(on) {
    if (!this.active || this.error || this.menuHeld === !!on) return;
    this.menuHeld = !!on;
    if (on) {
      this.focusHeld = false;           // the menu has the race now
      this.shared.releaseAll('key');
      this.shared.releaseAll('tap');
      this.pads.release();
      if (this.touch) { this.touch.releaseAll(); this.touch.root.hidden = true; }
      this.shared.mouse('pointer', 0);
      this.requesterFocus.release();
      this.shared.changed();
    }
    this.updatePaused();
  }

  /** Free flight is on in the game worker (CTRL.FLIGHT_ACTIVE). */
  get flying() { return !this.error && this.active && Atomics.load(this.ctrl, CTRL.FLIGHT_ACTIVE) === 1; }
  /** The game waits in a loop of its own (its pause, its quit requester). */
  get waiting() { return !this.error && this.active && Atomics.load(this.ctrl, CTRL_WAITING) === 1; }

  updatePaused() {
    if (this.error) return;
    const paused = this.pageSuspended || this.hiddenPage || this.menuHeld || this.focusHeld;
    // what the game thread must know of the holds (shared.js HOLD), before CTRL.PAUSED wakes it: the sound held (its
    // clock then leaves out the game time, worker.js soundUs) and the result-screen hold (the "pauze" notice over it)
    Atomics.store(this.ctrl, CTRL.HOLD, (this.soundOn() ? 0 : HOLD.SOUND) | (this.focusHeld ? HOLD.RESULTS : 0));
    if ((Atomics.load(this.ctrl, CTRL.PAUSED) === 1) !== paused) {
      Atomics.store(this.ctrl, CTRL.PAUSED, paused ? 1 : 0);
      Atomics.notify(this.ctrl, CTRL.PAUSED);
    }
    // the sound also stays off through a focus pause (focusMuted), whose pause loop the game thread runs
    if (this.soundOn()) this.sound.resume(); else this.sound.suspend();
    this.updateFps();
  }

  /** The game waits in its pause (0x42f220, also free flight's) or its quit requester (0x42f290): CTRL.PAUSE_KIND 1 or 2. */
  inPause() {
    const { waiting, pauseKind } = this.gameState();
    return waiting && pauseKind !== 0;
  }

  /** The race's sound plays: a race runs and nothing holds it (the page, the menu, a result-screen hold) or mutes it. */
  soundOn() {
    return this.active && !this.pageSuspended && !this.hiddenPage && !this.menuHeld && !this.focusHeld && !this.focusMuted;
  }

  /**
   * A focus pause is silent, as the JS port's: back('focus') calls DrivingView.suspend() with pauseAudio true, which
   * pauses its music and effects (main.js:741-747, driving-view.js:388-402), and only resume() plays them again
   * (driving-view.js:404-414, after a key, a pad button or a click: main.js:757, :851); its own P pause keeps them
   * (pauseAudio false, main.js:769), as the original's pause 0x42f350 lets DirectSound and DirectShow play on. Here the
   * page's sound stops (the AudioContext, music and effects alike) until focusMuteCheck sees the game leave the loop it
   * waits in, or sees the P hold end without the game waiting (P not taken).
   */
  muteFocus(reason) {
    if (this.focusMuted) return;
    this.focusMuted = true;
    this.focusMuteWaited = false;
    this.emit('log', 'focus mute (' + reason + ')');
    this.updatePaused();
  }

  /**
   * Once per frame while a race runs: a focus pause's silence ends when the game leaves its pause or requester
   * (CTRL_WAITING 1 -> 0, the JS port's resume), or when the P hold is over and the game never waited. In free flight
   * the music comes back and the effects stay held (dsound.js hold), as the JS port's resume pauses the effects again
   * while it flies (driving-view.js:413).
   */
  focusMuteCheck() {
    if (!this.focusMuted) return;
    if (this.gameState().waiting) { this.focusMuteWaited = true; return; }
    if (!this.focusMuteWaited && this.focusHold) return;
    this.focusMuted = false;
    this.emit('log', 'focus mute ended');
    this.updatePaused();
  }

  /**
   * Focus lost while racing (window blur, the page hidden, the driving pad gone): everything held is let go, and
   * the original's P is pressed so the game's own pause ("pauze") shows, as the JS reconstruction pauses on focus
   * loss in every phase of its race mode (its input.js:75-77, suspend -> onPause('focus'); main.js:741-747 back('focus')
   * -> DrivingView.suspend with the "pauze" notice, driving-view.js:388-395; Esc, a menu key or a click on the picture
   * resumes, main.js:757, 798, 851). P only where 0x42f9c0 takes it (P_PHASES: racing, the start camera and countdown,
   * the arrest) and while the game is not already waiting in a loop of its own (P there would answer it). P is held
   * until the game waits in its pause loop (0x42f220 first waits for P's release) or for FOCUS_PAUSE_MS of game passes,
   * so a page hidden at once still pauses when it comes back. On the result screens (RESULT_PHASES) the game ignores P:
   * the race is held there (focusHeld: the game thread, its clock and the sound stop, as CTRL.PAUSED does for a hidden
   * page) until a key, a pad button or a tap on the picture, which only ends the hold, as the JS port's resume key does not reach its
   * race (resumeViewer's input.setMode clears it, main.js:727-730). Its "pauze" notice over the results: the game thread
   * shows the original's (0x430610(1), HOLD.RESULTS) while the race is held, when the game's special text is idle, and
   * takes it off before the next pass (worker.js, render-replay.js notice; docs/intentional-differences.md, Focus loss).
   */
  focusPause(reason) {
    if (!this.active || this.menuHeld) return;
    const shared = this.shared;
    shared.releaseAll('key');
    shared.releaseAll('tap');
    this.pads.release();
    if (this.touch) this.touch.releaseAll();
    shared.mouse('pointer', 0);
    this.requesterFocus.release();
    shared.changed();
    if (!this.running || this.focusHold || this.focusHeld) return;
    const { waiting, phase } = this.gameState();
    // inside the game's pause or requester: no P (it would answer it), but silent until the game leaves it, as the JS
    // port's focus loss in its mode 'paused' suspends the race's sound too (main.js:743-745)
    if (waiting) { if (this.inPause()) this.muteFocus(reason); return; }
    if (RESULT_PHASES.has(phase)) {
      this.emit('log', 'focus hold (' + reason + ', phase ' + phase + ')');
      this.focusHeld = true;
      this.padHeldAtHold = true;          // a pad button held through the focus loss must be let go first
      this.updatePaused();
      return;
    }
    if (!P_PHASES.has(phase)) return;
    this.emit('log', 'focus pause (' + reason + ')');
    const ticks0 = Atomics.load(this.ctrl, CTRL.TICKS), t0 = performance.now();
    shared.hold('focus', VK_P, true);
    const hold = this.focusHold = { reason, timer: 0 };
    const check = () => {
      if (this.focusHold !== hold) return;
      const passes = Atomics.load(this.ctrl, CTRL.TICKS) - ticks0;
      const done = !this.active || Atomics.load(this.ctrl, CTRL_WAITING) === 1
        || (passes * 25 >= FOCUS_PAUSE_MS && performance.now() - t0 >= FOCUS_PAUSE_MS) || performance.now() - t0 > 60000;
      if (!done) { hold.timer = setTimeout(check, 20); return; }
      this.focusHold = null;
      shared.hold('focus', VK_P, false);
    };
    hold.timer = setTimeout(check, 20);
    this.muteFocus(reason);
  }

  /** The focus hold on the result screens ends (a key, a pad button or a tap). */
  endFocusHeld() {
    if (!this.focusHeld) return;
    this.focusHeld = false;
    this.emit('log', 'focus hold ended');
    this.updatePaused();
  }

  updateFps() {
    const el = this.fpsElement;
    if (!el) return;
    // only while the race runs: not while the game waits in its pause or requester (CTRL.PAUSE_KIND 1, 2; a short wait
    // for a key's release is not a pause), nor in a focus pause, as the JS port shows it in its modes race and viewer
    // only (main.js:865; its pauses are mode 'paused')
    // and not over the game's own loading picture (0x424360, drawn while it boots: shown but not yet running), as the JS
    // port's counter starts with its race mode (main.js:865)
    const show = this.settings.showFps === true && this.active && this.shown && this.running && !this.pageSuspended && !this.hiddenPage && !this.menuHeld && !this.focusHeld
      && !this.focusMuted && !this.inPause();
    if (el.hidden === show) {
      el.hidden = !show;
      // shown again: the count starts over (warm-up first), as the JS port resets its FpsCounter while it hides it
      // (main.js:870); the render worker's counter restarts on its 'fps' message
      if (show && this.active) { this.fpsLabel = 'FPS: …'; this.renderWorker.postMessage({ t: 'fps', on: true }); }
    }
    if (show && el.textContent !== this.fpsLabel) el.textContent = this.fpsLabel;
  }

  showCanvas() { this.canvas.hidden = false; this.canvas.style.display = ''; }
  hideCanvas() { this.canvas.hidden = true; this.canvas.style.display = 'none'; }

  // --- a race -----------------------------------------------------------------------------------------------------
  start(config = {}) {
    if (this.active) return Promise.reject(new Error('a race is already running'));
    if (this.error || this.workerError) return Promise.resolve({ patch: NOT_FINISHED(), effectsPercent: null, exitCode: null, error: this.error || this.workerError });
    const race = ++this.raceCount;
    this.active = true;
    this.running = false;
    this.shown = false;
    this.messageBox = null;
    this.renderError = null;
    this.fpsLabel = 'FPS: …';
    this.hiddenPage = document.hidden;
    this.menuHeld = false;
    this.focusHeld = false;
    this.focusMuted = false;
    this.effectsPercent = null;
    this.showCanvas();
    this.applySettings(config.settings || this.settings);
    this.shared.clear();
    this.attachInput();
    this.updatePaused();
    this.sound.reset();
    if (this.soundOn()) this.sound.resume();
    const strip = (o) => (o ? JSON.parse(JSON.stringify(o)) : null);
    // (difficulty left out: the installation's, 1; opponents follow from raceType in the handoff)
    const raceConfig = { country: config.country ?? 0, character: config.character ?? 0, raceType: config.raceType ?? 0 };
    if (config.difficulty !== undefined && config.difficulty !== null) raceConfig.difficulty = config.difficulty;
    return new Promise((resolve) => {
      this.pending = { race, resolve, onProgress: config.onProgress || null, onRunning: config.onRunning || null, onEffects: config.onEffects || null };
      this.gameWorker.postMessage({ t: 'race', race, config: raceConfig, save: strip(config.save), settings: strip(this.settings), keys: { ...this.keys }, fixed: !!config.fixed });
    });
  }

  attachInput() {
    const abort = this.abort = new AbortController();
    const opts = { signal: abort.signal };
    const shared = this.shared, input = this.input, canvas = this.canvas;
    // browsers start sound only after a gesture on the page
    // (not under a focus pause: its sound comes back with the race, focusMuteCheck)
    const unlock = () => { if (this.soundOn()) this.sound.resume(); };
    // a key press lasts at least KEY_MIN_HOLD_MS for the game, as the pointer's and the touch buttons' do: a quick
    // tap (or a synthetic press with down and up at once) could otherwise fall between two of its looks
    const downAt = new Map(), upTimers = new Map();
    abort.signal.addEventListener('abort', () => { for (const t of upTimers.values()) clearTimeout(t); upTimers.clear(); });
    // the key that ended a focus hold does not reach the game, up to its release (focusPause)
    const swallowed = new Set();
    const key = (e, down) => {
      if (this.menuHeld) return;          // the menu's keys (menu(true)); everything was let go there
      if (down && this.focusHeld && !e.repeat && !BROWSER_KEYS.has(e.code)) { e.preventDefault(); swallowed.add(e.code); this.endFocusHeld(); return; }
      if (swallowed.has(e.code)) { if (!down) swallowed.delete(e.code); e.preventDefault(); return; }
      const vk = vkOf(e);
      if (!vk) return;
      // The browser keeps a key the race does not drive with, as the JS port calls preventDefault only for its bound
      // actions (input.js:70-72), Space and C while flying (:67-68) and its menu keys while its race waits (:66): Tab
      // moves the focus (to the touch wheel and buttons), Enter or Space press a focused button. With the race's cheats
      // on (the development page) every key but Tab stays the game's, so the original's debug keys (Ctrl+F+I, F7, ...)
      // do not open the browser's tools.
      const { waiting, pauseKind } = this.gameState();
      const inLoop = waiting && (pauseKind === 1 || pauseKind === 2);
      const drives = (drivable(vk) && ACTIONS.some((a) => this.keys[a] === vk)) || (this.flying && (vk === VK_SPACE || vk === VK_C));
      if (!BROWSER_KEYS.has(e.code) && (drives || (inLoop && MENU_CODES.has(e.code)) || (this.cheats && e.code !== 'Tab'))) e.preventDefault();
      // the quit requester: an arrow moves its focus, Enter or Space press the focused button (requester-focus.js, the JS
      // port's menuKey, main.js:799-803); the keys still reach the game, which ignores them there
      const focus = this.requesterFocus;
      focus.update(waiting && pauseKind === 2);
      if (down && !e.repeat && focus.open) {
        if (e.code.startsWith('Arrow')) focus.move();
        else if (e.code === 'Enter' || e.code === 'Space') focus.press('key', true);
      } else if (!down && (e.code === 'Enter' || e.code === 'Space')) focus.press('key', false);
      if (e.repeat) return;
      clearTimeout(upTimers.get(vk));
      upTimers.delete(vk);
      const now = performance.now();
      if (down) downAt.set(vk, now);
      else {
        const left = KEY_MIN_HOLD_MS - (now - (downAt.get(vk) ?? -Infinity));
        if (left > 0) {
          upTimers.set(vk, setTimeout(() => { upTimers.delete(vk); shared.hold('key', vk, false); }, left));
          return;
        }
      }
      shared.hold('key', vk, down);
    };
    addEventListener('keydown', (e) => { unlock(); key(e, true); }, opts);
    addEventListener('keyup', (e) => key(e, false), opts);
    addEventListener('pointerdown', unlock, opts);
    addEventListener('blur', () => this.focusPause('blur'), opts);
    addEventListener('gamepaddisconnected', () => this.pads.poll(), opts);
    document.addEventListener('visibilitychange', () => {
      this.hiddenPage = document.hidden;
      if (document.hidden) this.focusPause('hidden');
      this.updatePaused();
    }, opts);
    // the pointer in the game's screen pixels (GetCursorPos), its buttons (GetAsyncKeyState 1, 2, 4) and its
    // movement (DirectInput's mouse)
    let pressAt = 0, pressTimer = 0;
    // A press on the picture holds Space on the finish and game-over screens (phases 3 and 6) until a pointer is let go
    // anywhere, for at least KEY_MIN_HOLD_MS, as the JS reconstruction's #world pointerdown holds it there (its
    // main.js:850-854, released on every pointerup and pointercancel of the window): 0x41fd90 and 0x420850 take Esc,
    // Enter or Space after 1.5 s and 1 s (its native-race-lifecycle.js:11, :33-38). Not while the game waits in a loop
    // of its own (a result screen waiting for its key's release, the requester): there a press is the mouse's only.
    let spaceDown = false, spaceAt = 0, spaceTimer = 0;
    const tapSpace = (down) => {
      clearTimeout(spaceTimer);
      if (down) { spaceDown = true; spaceAt = performance.now(); shared.hold('tap', VK_SPACE, true); return; }
      if (!spaceDown) return;
      const left = KEY_MIN_HOLD_MS - (performance.now() - spaceAt);
      if (left > 0) { spaceTimer = setTimeout(() => tapSpace(false), left); return; }
      spaceDown = false;
      shared.hold('tap', VK_SPACE, false);
    };
    for (const type of ['pointerup', 'pointercancel']) addEventListener(type, () => tapSpace(false), opts);
    abort.signal.addEventListener('abort', () => clearTimeout(spaceTimer));
    const pointer = (e) => {
      // a press that ends a focus hold is not the game's (focusPause)
      if (e.type === 'pointerdown' && this.focusHeld) { this.endFocusHeld(); return; }
      if (e.type === 'pointerdown') {
        const { waiting, phase } = this.gameState();
        if (RESULT_PHASES.has(phase) && !waiting) tapSpace(true);
      }
      // the game's 640x480 is the largest 4:3 area in the middle of the canvas
      const r = canvas.getBoundingClientRect();
      const s = Math.min(r.width / MODE_W, r.height / MODE_H);
      const ax = r.left + (r.width - MODE_W * s) / 2, ay = r.top + (r.height - MODE_H * s) / 2;
      Atomics.store(input, IN.MOUSE_X, Math.max(0, Math.min(MODE_W - 1, Math.floor((e.clientX - ax) / s))));
      Atomics.store(input, IN.MOUSE_Y, Math.max(0, Math.min(MODE_H - 1, Math.floor((e.clientY - ay) / s))));
      if (e.movementX || e.movementY) { Atomics.add(input, IN.DX, e.movementX | 0); Atomics.add(input, IN.DY, e.movementY | 0); }
      // a press lasts at least 80 ms for the game: a tap or a quick click could otherwise fall between its looks
      // (the requester's buttons, 0x474040)
      const buttons = (e.buttons & 1 ? 1 : 0) | (e.buttons & 2 ? 2 : 0) | (e.buttons & 4 ? 4 : 0);
      const now = performance.now();
      if (e.type === 'pointerdown') pressAt = now;
      clearTimeout(pressTimer);
      // (the pointer's own buttons: IN.BUTTONS also holds the requester focus's presses, SharedInput.mouse)
      if (!buttons && shared.mice.get('pointer') && now - pressAt < 80) {
        pressTimer = setTimeout(() => shared.mouse('pointer', 0), 80 - (now - pressAt));
      } else shared.mouse('pointer', buttons);
      shared.changed();
    };
    canvas.addEventListener('pointermove', pointer, opts);
    canvas.addEventListener('pointerdown', pointer, opts);
    canvas.addEventListener('pointerup', pointer, opts);
    canvas.addEventListener('contextmenu', (e) => e.preventDefault(), opts);
    // a mouse button let go outside the canvas
    addEventListener('pointerup', (e) => {
      if (e.target === canvas || e.pointerType !== 'mouse') return;
      clearTimeout(pressTimer);
      shared.mouse('pointer', (e.buttons & 1 ? 1 : 0) | (e.buttons & 2 ? 2 : 0) | (e.buttons & 4 ? 4 : 0));
      shared.changed();
    }, opts);
    canvas.addEventListener('wheel', (e) => { Atomics.add(input, IN.DZ, -Math.sign(e.deltaY) * 120); shared.changed(); }, { passive: true, signal: abort.signal });
    // (a tap on the touch controls does not end a focus hold: they are inert under it, touch.js update, as the JS
    // reconstruction's are in its focus pause and only its #world's pointerdown resumes, main.js:850-851)
    abort.signal.addEventListener('abort', () => clearTimeout(pressTimer));
    // once per animation frame: the pad, the touch controls (shown for the game's state), the FPS label
    let touchShown = null;
    const frame = () => {
      if (abort.signal.aborted) return;
      // the quit requester's focus starts on "nee" whenever it opens (requester-focus.js)
      const gs = this.gameState();
      this.requesterFocus.update(gs.waiting && gs.pauseKind === 2);
      if (this.focusHeld) {
        // a new press of a pad button that resumes the JS port's focus pause (A, B, Start, the D-pad, the stick past
        // half way: gamepad.js pressed) ends the focus hold; the pad is read again after it
        const pressed = this.pads.pressed();
        if (pressed && !this.padHeldAtHold) this.endFocusHeld();
        this.padHeldAtHold = pressed;
      } else if (!this.menuHeld) this.pads.poll();
      if (this.touch) {
        this.touch.update(this.showTouch && !this.menuHeld, this.focusHeld);
        const shownNow = !this.touchRoot.hidden;
        if (shownNow !== touchShown) { touchShown = shownNow; this.hudShape(); }
      }
      this.focusMuteCheck();
      this.updateFps();
      requestAnimationFrame(frame);
    };
    requestAnimationFrame(frame);
    this.hudShape();
  }

  /** The end of a race (exit, crash or a failed worker): everything let go and hidden, sound freed, start() resolves. */
  finish({ code = null, raceIni = null, error = null } = {}) {
    const p = this.pending;
    if (!p) return;
    this.pending = null;
    this.active = false;
    this.running = false;
    this.shown = false;
    this.menuHeld = false;
    this.focusHeld = false;
    this.focusMuted = false;
    if (this.abort) { this.abort.abort(); this.abort = null; }
    if (this.focusHold) { clearTimeout(this.focusHold.timer); this.focusHold = null; }
    this.requesterFocus.update(false);
    this.requesterFocus.release();
    this.shared.clear();
    if (this.touch) this.touch.hide();
    this.hideCanvas();
    this.updateFps();
    this.sound.reset();
    this.sound.suspend();
    let patch = NOT_FINISHED(), effectsPercent = null;
    if (raceIni !== null) {
      this.lastRaceIni = raceIni;
      try { ({ patch, effectsPercent } = handoff.readResult(raceIni)); } catch (e) { error = error || 'readResult: ' + e.message; }
    }
    if (!error && code !== null && code !== 0 && this.messageBox) error = this.messageBox;
    p.resolve({ patch, effectsPercent: effectsPercent ?? null, exitCode: code, error });
  }

  onGame(d) {
    const p = this.pending;
    if (d.t === 'audio') { if (p && d.race === undefined) this.sound.handle(d.list); return; }
    if (d.t === 'log') { this.emit('log', d.s); return; }
    if (d.race !== undefined && (!p || d.race !== p.race)) return;     // a message of an earlier race
    if (d.t === 'progress') {
      const percent = d.stage === 'files' ? Math.round(d.percent * 0.9) : 90 + Math.round(d.percent * 0.1);
      if (p.onProgress) p.onProgress(percent, d.stage);
      this.emit('status', { stage: d.stage, percent });
    } else if (d.t === 'loaded') { this.lastLoad = { ms: d.ms, fetched: d.fetched, cached: d.cached, requests: d.requests }; this.emit('loaded', this.lastLoad); }
    else if (d.t === 'running') {
      this.running = true;
      this.emit('status', { stage: 'running', percent: 100 });
      // the effects level the race plays with (an enabled 0 is 75 now, 0x437560): the menu adopts it (onEffects)
      const fx = d.volumes ? d.volumes.effects : null;
      this.effectsPercent = typeof fx === 'number' ? fx : null;
      if (p.onEffects && this.effectsPercent !== null) { try { p.onEffects(this.effectsPercent); } catch (e) { console.error(e); } }
    }
    else if (d.t === 'stats') this.emit('stats', d);
    else if (d.t === 'messagebox') { this.messageBox = d.caption + ': ' + d.text; this.emit('messagebox', d); }
    else if (d.t === 'exit') { this.lastFiles = d.files || null; this.finish({ code: d.code, raceIni: d.raceIni }); }
    else if (d.t === 'crash') { console.error(d.message, d.stack); this.finish({ error: d.message }); }
  }

  onRender(d) {
    if (d.t === 'ready' || d.t === 'resized') {
      this.supportedSamples = d.supportedSamples;
      this.msaaStatus = { ...this.msaaStatus, actualSamples: d.samples, supportedSamples: [...d.supportedSamples] };
      this.renderSize = { width: d.width, height: d.height, samples: d.samples };
      if (d.t === 'ready' && d.maxSize && d.maxSize !== this.maxSize) { this.maxSize = d.maxSize; if (this.active) this.resize(); }
    } else if (d.t === 'shown') {
      const p = this.pending;
      if (!p || d.race !== p.race || this.shown) return;
      this.shown = true;
      this.updateFps();
      if (p.onRunning) p.onRunning();
    } else if (d.t === 'fps') {
      this.fpsLabel = d.fps === null ? 'FPS: …' : `${Math.round(d.fps)} FPS`;
      this.updateFps();
      this.emit('fps', d.fps);
    } else if (d.t === 'rstats') this.emit('rstats', d);
    else if (d.t === 'reset') this.emit('reset', d);
    else if (d.t === 'fatal') { this.renderError = d.message; this.emit('log', 'render: ' + d.message); console.warn('render worker:', d.message); }
  }

  /** For checks: the shared input as the game sees it. */
  inputState() {
    if (this.error) return null;
    const input = this.input;
    return { joy: [IN.JOY_X, IN.JOY_Y, IN.JOY_BUTTONS, IN.JOY_ACTIVE].map((k) => Atomics.load(input, k)), waiting: this.gameState().waiting, flying: this.gameState().flying, menu: this.menuHeld,
      touch: !!this.touchRoot && !this.touchRoot.hidden, touchInert: !!this.touch && this.touch.inert, pauseKind: this.gameState().pauseKind, p: Atomics.load(input, VK_P), focusHold: !!this.focusHold, focusHeld: this.focusHeld, focusMuted: this.focusMuted, paused: Atomics.load(this.ctrl, CTRL.PAUSED),
      pedals: [IN.JOY_GAS, IN.JOY_BRAKE].map((k) => Atomics.load(input, k)), keys: { ...this.keys },
      held: Array.from({ length: 256 }, (_, vk) => vk).filter((vk) => Atomics.load(input, vk)), buttons: Atomics.load(input, IN.BUTTONS),
      mouse: [Atomics.load(input, IN.MOUSE_X), Atomics.load(input, IN.MOUSE_Y)], requesterFocus: this.requesterFocus.open ? this.requesterFocus.focus : null };
  }

  /** For checks: what sounds now (source/web/audio.js state). */
  audioState() {
    return this.sound ? this.sound.state() : null;
  }
}
