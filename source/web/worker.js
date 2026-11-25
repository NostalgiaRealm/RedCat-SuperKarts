// Game thread. Runs the recompiled race: the CRT and init_main, then one pass of WinMain's loop every 25 ms of
// real time (WinMain's own gate, 0x4432a0). Inside a pass the game may wait in a loop of its own as on Windows
// (the pause, the quit requester, a key it waits to see released): input comes through shared memory, so such
// a loop sees keys change while it runs, the clock follows real time (VirtualClock.realNow), and the thread
// sleeps while it waits (VirtualClock.idle). Frames go to the render worker (source/render/recorder.js); no GPU
// object lives here. Shared memory needs a cross-origin isolated page. The model is RedCat Spookkasteel's
// recompiled port (source/web/worker.js there).
//
// One game worker serves every race of the page (source/race-runner.js), as the original launcher starts
// rcskspel.dat anew for every race: the module is compiled once and the game files fetched once and kept (a second
// race fetches nothing it already has; source/web/game-files.js: the files a race's lists name, the packed archives
// by byte ranges), and every race gets a fresh Vfs over those bytes, a fresh Race
// (a new wasm instance), its INI handoff (source/host/race-handoff.js writeHandoff) and a recorder of its own. At
// the end of a race the worker posts its race.ini and goes back to its event loop for the next one; a race that
// fails posts 'crash' and the next one still starts from scratch.
//
// Page -> this worker:
//   { t: 'init', ctrl, input, port, baseUrl, urls? }          once: shared memory, the frame port, where files are
//       urls (relative to baseUrl; the same on the development server, the website and the desktop app): game ('game/',
//       rcskspel.wasm, .meta.json, .codemap.bin), data ('data/', the game's files), index ('game/files.json', every file
//       with its size and the archives read by byte ranges), preload ('game/preload.json', per race what it reads,
//       fetched before it starts; the rest is fetched when first read)
//   { t: 'race', race, config, save, settings, keys, fixed }   a race: config { country, character, difficulty,
//       raceType }, save { bestTimes, playerPosition }, settings (rcsk.settings.v1), keys (the bound virtual keys
//       { accelerate, brake, left, right, bonus, handbrake }), fixed (development: a fixed clock and date)
//   { t: 'preload' }                                           fetch the module and the files now (optional)
// This worker -> page:
//   { t: 'progress', race, stage: 'files'|'boot', percent }, { t: 'loaded', race, ms, fetched, cached, requests },
//   { t: 'running', race, volumes: { music, effects } } (race.ini's levels after boot, live-volume.js), { t: 'stats', ... } (twice a second), { t: 'audio', list }, { t: 'log', s },
//   { t: 'messagebox', caption, text }, { t: 'exit', race, code, files (GameFiles.stats), raceIni }, { t: 'crash', race, message, stack }
import { Race, DATA } from '../host/race.js';
import * as handoff from '../host/race-handoff.js';
import { createRecorder } from '../render/recorder.js';
import { HudLayout } from '../host/hud-layout.js';
import { CTRL, IN, CTRL_WAITING, OPT, HOLD } from './shared.js';
import { drivable, readKeys, writeGameKeys, gameKeys, stuckInput } from '../input/race-keys.js';
import { JOY_CENTRE } from '../input/shared-input.js';
import { LiveVolume } from '../host/live-volume.js';
import { GameFiles } from './game-files.js';

const TICK_MS = 25;
const post = (msg, transfer) => self.postMessage(msg, transfer || []);
const sleepCell = new Int32Array(new SharedArrayBuffer(4));
const sleep = (ms) => { if (ms > 0) Atomics.wait(sleepCell, 0, 0, ms); };
const DEFAULT_URLS = { game: 'game/', data: 'data/', index: 'game/files.json', preload: 'game/preload.json' };
const DEFAULT_KEYS = { accelerate: 0x26, brake: 0x28, left: 0x25, right: 0x27, bonus: 0x11, handbrake: 0x12 };

let page = null;            // { ctrl, input, port, url(name) }
// what stays between races: the compiled module and the game files (GameFiles: the files and archive pages fetched)
const kept = { module: null, files: null };
let busy = Promise.resolve();

async function fetchOk(url, how) {
  const r = await fetch(url);
  if (!r.ok) throw new Error(`${url}: ${r.status} ${r.statusText}`);
  return r[how]();
}

/** The recompiled module (compiled once) and the game's files with their lists (source/web/game-files.js). */
function module() {
  if (!kept.module) {
    kept.module = Promise.all([
      fetchOk(page.url('game', 'rcskspel.meta.json'), 'json'),
      fetchOk(page.url('game', 'rcskspel.codemap.bin'), 'arrayBuffer').then((b) => new Uint8Array(b)),
      fetchOk(page.url('game', 'rcskspel.wasm'), 'arrayBuffer').then((b) => WebAssembly.compile(b)),
      fetchOk(page.url('index'), 'json'),
      // without the lists every first read is fetched while the game waits: slower, not wrong
      fetch(page.url('preload')).then((r) => (r.ok ? r.json() : null)).catch(() => null),
    ]).then(([meta, codeMap, wasm, manifest, preload]) => {
      kept.files = new GameFiles((name) => page.url('data', encodeURIComponent(name)), manifest, preload);
      return { meta, codeMap, wasm };
    });
    kept.module.catch(() => { kept.module = null; });
  }
  return kept.module;
}

/** A fresh Vfs over the kept files; what the race's lists name and is not kept yet is fetched first (reported as progress). */
async function filesFor(race, config, onProgress) {
  const t0 = performance.now();
  const { fetched, cached, requests } = await kept.files.prepare(config, onProgress);
  post({ t: 'loaded', race, ms: Math.round(performance.now() - t0), fetched, cached, requests });
  return kept.files.vfs();
}

/** The handoff builder's bindings, or the defaults (arrows, Ctrl, Alt). */
function keysOf(d) {
  return { ...DEFAULT_KEYS, ...(d.keys || {}) };
}

async function runRace(d) {
  const { ctrl, input, port } = page;
  const raceNo = d.race;
  const config = d.config || {};
  // the bindings the page published (CTRL.KEYS, CTRL.KEYS_SEQ), taken before the first pass and after every change (a
  // binding changed during the race in the flight panel's Instellingen, or while the race loaded): 0 = not yet, so the
  // first pass takes the newest, whatever d.keys (the handoff's) held; a page that never published keeps d.keys
  let keysSeq = 0;
  // the menu's music and effects levels (CTRL.VOLUME) as the race starts: the handoff writes them; a later change goes
  // into the running race (source/host/live-volume.js)
  const volume = new LiveVolume(Atomics.load(ctrl, CTRL.VOLUME));
  Atomics.store(ctrl, CTRL.TICKS, 0);
  Atomics.store(ctrl, CTRL.PHASE, -1);
  Atomics.store(ctrl, CTRL_WAITING, 0);
  Atomics.store(ctrl, CTRL.PAUSE_KIND, 0);
  Atomics.store(ctrl, CTRL.FLIGHT_ACTIVE, 0);
  Atomics.store(ctrl, CTRL.DEAD, 0);
  for (const w of [CTRL.SAFE_STUCK, CTRL.SAFE_NPC, CTRL.SAFE_KEYS]) Atomics.store(ctrl, w, 0);
  const progress = (stage, percent) => post({ t: 'progress', race: raceNo, stage, percent });
  progress('files', 0);
  const { meta, codeMap, wasm } = await module();
  const vfs = await filesFor(raceNo, config, (p) => progress('files', p));
  // what the original menu writes into the INI files before it starts the race (race-handoff.js)
  handoff.writeHandoff(vfs, config, d.save || null, d.settings || null);
  progress('boot', 0);

  const render = createRecorder(port, ctrl, { race: raceNo });
  // Sound: the game's DirectSound and DirectShow calls keep their state here on the race's clock (dsound.js,
  // dshow.js); what the page must play goes there in batches, one message per frame and one per nap while the
  // game waits inside a pass (its pause, its requester).
  const audioQ = [], transfers = [];
  const flushAudio = () => { if (audioQ.length) post({ t: 'audio', list: audioQ.splice(0) }, transfers.splice(0)); };
  const audio = {
    data: (id, bytes, fmt) => { audioQ.push({ t: 'data', id, bytes, fmt }); transfers.push(bytes.buffer); },
    alias: (id, of) => audioQ.push({ t: 'alias', id, of }),
    play: (id, loop, offset) => audioQ.push({ t: 'play', id, loop, offset }),
    stop: (id) => audioQ.push({ t: 'stop', id }),
    volume: (id, v) => audioQ.push({ t: 'volume', id, v }),
    pan: (id, v) => audioQ.push({ t: 'pan', id, v }),
    frequency: (id, hz) => audioQ.push({ t: 'frequency', id, hz }),
    free: (id) => audioQ.push({ t: 'free', id }),
  };
  const music = {
    open: (name, bytes) => { const copy = bytes.slice(); audioQ.push({ t: 'music-open', name, bytes: copy }); transfers.push(copy.buffer); },
    run: (offset) => audioQ.push({ t: 'music-run', offset }),
    pause: () => audioQ.push({ t: 'music-pause' }),
    stop: () => audioQ.push({ t: 'music-stop' }),
    volume: (v) => audioQ.push({ t: 'music-volume', v }),
  };
  const host = {
    vfs, render, audio, music,
    screen: { width: 640, height: 480, bits: 16 },
    tickSeconds: TICK_MS / 1000,
    clockStart: d.fixed ? 1 : undefined,
    fixedDate: d.fixed ? Date.UTC(2000, 3, 17, 12) : undefined,
    input: {
      keyDown: (vk) => Atomics.load(input, vk & 0xFF) !== 0,
      get mouseX() { return Atomics.load(input, IN.MOUSE_X); },
      get mouseY() { return Atomics.load(input, IN.MOUSE_Y); },
      get mouseButtons() { return Atomics.load(input, IN.BUTTONS); },
      takeMouseDelta: () => ({ dx: Atomics.exchange(input, IN.DX, 0), dy: Atomics.exchange(input, IN.DY, 0), dz: Atomics.exchange(input, IN.DZ, 0) }),
      // SetCursorPos (the quit requester parks the pointer): the game's own idea of where it is, until it moves
      setMouse: (x, y) => { Atomics.store(input, IN.MOUSE_X, x); Atomics.store(input, IN.MOUSE_Y, y); },
    },
    onFlip: () => flushAudio(),
    onMessageBox: (caption, text) => post({ t: 'messagebox', caption, text }),
    onStdout: (s) => post({ t: 'log', s }),
    log: (s) => post({ t: 'log', s }),
  };
  // the cheats option (OPT.CHEATS) as the race starts: boot and load poll keys too (G held at load, 0x431bfb)
  host.cheats = (Atomics.load(ctrl, CTRL.OPTIONS) & OPT.CHEATS) !== 0;
  // the race visuals' bits (OPT.SURFACE_SHADOWS, OPT.SMOOTH_ENGINE_LIGHTS; source/host/shadows.js), read again before
  // every pass, so a frame is all in one mode
  host.options = Atomics.load(ctrl, CTRL.OPTIONS);
  let race = null;
  try {
    race = new Race(meta, host);
    await race.instantiate(wasm, codeMap);
    if (race.unbound.some((n) => !n.startsWith('hook!'))) post({ t: 'log', s: 'unbound imports: ' + race.unbound.join(' ') });
    render.attach(race.m, host);
    // the HUD laid out for the page's shape (CTRL.ASPECT), inside its safe area (CTRL.INSET_*) and above the touch
    // band (CTRL.CONTROLS_L), read before every pass; race.js hands L to HudLayout.apply around the HUD's draw, which
    // cuts each group to its frame through clip (the recorder's CMD.CLIP)
    const insets = { left: 0, right: 0, top: 0, bottom: 0 };
    const controls = { left: 0, right: 0 };
    host.hudLayout = { layout: new HudLayout(race.m), xr: 1, yr: 0.75, aspect: 0, scale: 1, insets, controls, clip: (rect) => render.hudClip(rect) };
    // true when any of the words changed since the last call (the held picture is drawn again then: repaint below)
    let shapeSeen = '';
    const shape = () => {
      let a = Atomics.load(ctrl, CTRL.ASPECT) / 1e6;
      if (Math.abs(a - 4 / 3) < 1e-3) a = 4 / 3;          // a 4:3 drawing rounded to millionths is still the original's
      const L = host.hudLayout;
      L.scale = Math.max(1, Atomics.load(ctrl, CTRL.HUD_SCALE) / 1000);
      insets.left = Atomics.load(ctrl, CTRL.INSET_L) / 1e4;
      insets.right = Atomics.load(ctrl, CTRL.INSET_R) / 1e4;
      insets.top = Atomics.load(ctrl, CTRL.INSET_T) / 1e4;
      insets.bottom = Atomics.load(ctrl, CTRL.INSET_B) / 1e4;
      controls.left = Atomics.load(ctrl, CTRL.CONTROLS_L) / 1e4;
      controls.right = Atomics.load(ctrl, CTRL.CONTROLS_R) / 1e4;
      const seen = [a, L.scale, insets.left, insets.right, insets.top, insets.bottom, controls.left, controls.right].join();
      const changed = seen !== shapeSeen;
      shapeSeen = seen;
      if (a && a !== L.aspect) {
        const c = HudLayout.clipFor(a);
        L.aspect = a; L.xr = c.xr; L.yr = c.yr;
      }
      return changed;
    };
    shape();
    // The held picture drawn again for a new shape (render-replay.js repaint(): the pause render 0x430020 and the present
    // 0x430470 with the HUD laid out anew), while the game waits in its pause loop 0x42f220 (pause kind 1 after the pause
    // entry's render, also free flight's pause) or the page holds the race between passes (CTRL.PAUSED: a result-screen
    // hold, a hidden page, the menu over the race), as the JS port lays its HUD out for every picture it draws (race-hud.js
    // render). Not in the quit requester (its own 640x480 form: resend2d below) nor in a short wait for a key's release,
    // and not before the race's first pass (the loading picture). Not nested: a render that reads the clock may come back
    // to idle(), which then neither waits nor draws.
    let repainting = false;
    const repaint = () => {
      if (repainting || !race.ticks) return;
      repainting = true;
      try { race.renderReplay.repaint(); } finally { repainting = false; }
      flushAudio();
    };
    // Game code run between two passes while the race is held (the held picture, the notice) sees the clock as the last
    // pass's render saw it (render-replay.js renderUs), and nothing it reads moves it: VirtualClock.query catches the
    // clock up with real time once a pass is 40 ms old, and the HUD reads the timers through it, so a hold of N seconds
    // moved the race's time on by N (measured: the finish screen's lap time 00:04:40 before a 6 s hold, 00:10:25 forty
    // passes after it); and on a pass slower than 40 ms the clock moves on after its render (inferred from
    // VirtualClock.query, not measured). Its real time stands at the pass's start, and the clock is put back after it.
    const still = (fn) => {
      const clock = race.clock, real = clock.realNow, at = clock.tickReal, us = clock.us;
      const seen = race.renderReplay.renderUs();
      clock.realNow = () => at;
      if (seen >= clock.tickUs && seen <= us) clock.us = seen;
      try { return fn(); } finally { clock.realNow = real; clock.us = us; }
    };
    // The quit requester's form (0x42f290 -> 0x473780 -> 0x470aa0) is a 640x480 picture written into the screens'
    // memory (directx.js keeps their pixels in game memory, Lock/Unlock and Blt), and its loop sends nothing while the
    // pointer rests: the render worker, which makes its buffers anew at a new size (gl-renderer.js resize), keeps only
    // 3D frames to draw again, so the canvas stayed black after a turn. Once a whole-screen 2D write is on view (a
    // write of all 640x480, and no flip of 3D draws since), a new shape sends the front screen's pixels again
    // (recorder.js screenWritten: an IMAGE of the whole front screen and its present), the form with the hand as they are.
    let screen2d = false;
    for (const k of ['screenWritten', 'screenBlit']) {
      const fn = render[k];
      render[k] = (dst, dr, ...rest) => {
        const r = k === 'screenWritten' ? (dr || { l: 0, t: 0, r: dst.width, b: dst.height }) : dr;
        if (r.l <= 0 && r.t <= 0 && r.r >= dst.width && r.b >= dst.height) screen2d = true;
        return fn(dst, dr, ...rest);
      };
    }
    const flip = render.flip;
    render.flip = () => { if (render.frameDraws > 0) screen2d = false; return flip(); };
    const resend2d = () => {
      if (!screen2d) return;
      for (const s of race.m.objects.values()) if (s && s.isPrimary && typeof s.memory === 'function') { render.screenWritten(s, null); return; }
    };
    // The sound's clock (dsound.js, dshow.js: host.soundUs): the game's clock less the game time that passed while the
    // page held the race's sound (CTRL.HOLD SOUND: its AudioContext suspended, which stops the music's and the effects'
    // places there), so after a focus pause of N seconds, whose loop runs the game's clock in real time, the track ends
    // and restarts (EC_COMPLETE, 0x48ef80) where the page's ends, and one-shot effects end where they are heard, as the JS
    // port's paused <audio> and effects keep their place (game-audio.js:18, driving-view.js:401). Each look adds the time
    // since the last one to the held time when the sound was held at that last look: idle() looks every nap of a wait
    // loop, the loop below before every pass and around a hold.
    let heldUs = 0, lookedUs = race.clock.us, lookedHeld = false;
    const soundUs = () => {
      const us = race.clock.us;
      if (lookedHeld) heldUs += us - lookedUs;
      lookedUs = us;
      lookedHeld = (Atomics.load(ctrl, CTRL.HOLD) & HOLD.SOUND) !== 0;
      return us - heldUs;
    };
    host.soundUs = soundUs;
    // While the game waits inside a pass: real time for its clock, and sleep until input changes (at most 2 ms).
    race.clock.realNow = () => performance.now();
    // A hidden page (CTRL.PAUSED) stops these naps too.
    race.clock.idle = () => {
      if (repainting) return;
      flushAudio();
      // which loop it is (0x53b9f8: 1 the pause, 2 the requester; set by 0x42f9c0 before 0x42f350 and cleared by
      // 0x42f4c0 after it), before CTRL_WAITING, so the page never sees the wait without its kind (shared.js PAUSE_KIND)
      const kind = race.m.u32[DATA.PAUSE_KIND >> 2];
      Atomics.store(ctrl, CTRL.PAUSE_KIND, kind);
      Atomics.store(ctrl, CTRL_WAITING, 1);
      soundUs();
      // in the pause loop (the pause entry's render drew the pause picture, render-replay.js held()) a new shape draws it
      // again, in the requester (its form on view) the form is sent again; race-runner.js hudShape() wakes the wait below
      const look = () => {
        if (kind === 1 && race.renderReplay.held()) { if (shape()) repaint(); } else if (kind === 2 && screen2d && shape()) resend2d();
      };
      look();
      while (Atomics.load(ctrl, CTRL.PAUSED)) {
        Atomics.wait(ctrl, CTRL.PAUSED, 1, 500);
        look();
      }
      soundUs();
      const s = Atomics.load(input, IN.SEQ);
      Atomics.wait(input, IN.SEQ, s, 2);
    };
    // The pad and the touch wheel: the virtual joystick 0, always there (centred when nothing moves it), and the
    // game's own analog handler 0x4341d0 while one of them drives and no driving key is held; else the keyboard's
    // ramps (0x433870), with the pad's and the wheel's actions as pressed bindings (host.joyAction). The race starts
    // with CONTROL=0 (keyboard) and the host chooses the handler before each pass by writing the device word 0x53a5d8,
    // which only 0x42ee60, 0x42ef90 and 0x4325b0 read, each in its own device (evidence/checks/input-modes.txt;
    // docs/intentional-differences.md). In the analog handler the keys bound to
    // the bonus and the handbrake (Ctrl and Alt unless changed) count as the joystick's buttons, as it reads no keys.
    // P and Esc never drive (source/input/race-keys.js drivable; safeguards.js answers 0x4b3880's polls of them "up").
    let keys, driveKeys;
    const useKeys = (k) => { keys = k; driveKeys = [keys.accelerate, keys.brake, keys.left, keys.right].filter(drivable); };
    useKeys(keysOf(d));
    const down = (vk) => (vk > 0 && vk < 256 ? Atomics.load(input, vk) !== 0 : false);
    // A driving key held, also under Shift, keeps the keyboard's ramps, as any keyboard source keeps the JS
    // reconstruction digital (its input.js:49-50: a key: source, also one its Shift rule drops, :34-41); the pad and the
    // wheel then drive through the bindings: 0x4b3880's polls from 0x42ee60 answer "down" for every action they work
    // (safeguards.js BINDING_SLOTS), also under Shift, as the JS port drops only its keyboard sources there, so ArrowLeft
    // with the pad's RT steers left at full throttle, and Shift+ArrowUp with RT 0.3 too (its race-simulation.js:390-392
    // takes every action > 0 as pressed).
    const driveKeyHeld = () => driveKeys.some((vk) => Atomics.load(input, vk));
    // 0x42ee60's table slot k (left, right, accelerate, brake, bonus, handbrake) worked by the pad or the touch wheel: the
    // virtual joystick's side (IN.JOY_X, the sum of both), its pedals apart (IN.JOY_GAS, IN.JOY_BRAKE, the largest) and
    // its buttons (IN.JOY_BUTTONS: the pad's X and Y, the touch Bonus and Rem)
    host.joyAction = (k) => {
      switch (k) {
        case 0: return Atomics.load(input, IN.JOY_X) < JOY_CENTRE;
        case 1: return Atomics.load(input, IN.JOY_X) > JOY_CENTRE;
        case 2: return Atomics.load(input, IN.JOY_GAS) > 0;
        case 3: return Atomics.load(input, IN.JOY_BRAKE) > 0;
        case 4: return (Atomics.load(input, IN.JOY_BUTTONS) & 1) !== 0;
        case 5: return (Atomics.load(input, IN.JOY_BUTTONS) & 2) !== 0;
        default: return false;
      }
    };
    host.joystick = (id) => (id !== 0 ? null : {
      x: Atomics.load(input, IN.JOY_X), y: Atomics.load(input, IN.JOY_Y),
      buttons: Atomics.load(input, IN.JOY_BUTTONS) | (drivable(keys.bonus) && down(keys.bonus) ? 1 : 0) | (drivable(keys.handbrake) && down(keys.handbrake) ? 2 : 0),
    });
    host.beforeTick = (r) => {
      // bindings changed during the race: the worker's (device choice, joystick buttons, stuck recovery, flight) and the
      // game's own table (0x53a5b8, which 0x42ee60 polls), before this pass reads them
      const seq = Atomics.load(ctrl, CTRL.KEYS_SEQ);
      if (seq !== keysSeq) { keysSeq = seq; useKeys(readKeys(ctrl)); writeGameKeys(r.m, keys); }
      const analog = Atomics.load(input, IN.JOY_ACTIVE) && !driveKeyHeld();
      r.m.i32[DATA.DEVICE >> 2] = analog ? 3 : 1;
      // the cheats option for this pass (safeguards.js takes it once per pass)
      host.cheats = (Atomics.load(ctrl, CTRL.OPTIONS) & OPT.CHEATS) !== 0;
      host.options = Atomics.load(ctrl, CTRL.OPTIONS);
      // the menu's music or effects level changed during the race: into the race's own volume code (live-volume.js)
      const done = volume.update(r.m, vfs, Atomics.load(ctrl, CTRL.VOLUME));
      if (done) post({ t: 'log', s: 'volume ' + JSON.stringify(done) });
    };
    // The stuck recovery's input (source/host/stuck.js; the JS reconstruction's step reads InputState.snapshot,
    // player-stuck-recovery.js:33-35): per action the largest of the bound keys (none while Shift is held) and the pad's
    // and the wheel's pedals apart and without the ±10% window (IN.JOY_GAS, IN.JOY_BRAKE), the handbrake from the key or
    // the joystick's button (source/input/race-keys.js stuckInput).
    host.driveInput = () => stuckInput(keys, down, input);
    // Free flight (source/host/free-flight.js): asked for by the page (CTRL.FLIGHT, settings.freeFlight), steered with
    // the driving keys bound in the settings (only while Shift is up: 0x4b3880's rule, as the JS reconstruction's
    // InputState.value, its input.js:31-41), the pad's and the touch wheel's steering and pedals (the virtual joystick,
    // its ±10% window taken off again: SharedInput.joystick) and Space and C for up and down (the pad's LB and RB and
    // the touch buttons Omhoog and Omlaag hold them; input.js:51-52, :152); per action the larger of keys and stick.
    host.flightWanted = () => Atomics.load(ctrl, CTRL.FLIGHT) === 1;
    const unwindow = (a) => { const v = (a - 32767) / 32768; return Math.sign(v) * Math.max(0, (Math.abs(v) - 0.1) / 0.9); };
    host.flightInput = () => {
      const shift = down(0x10);
      const key = (vk) => (vk !== 0x20 && vk !== 0x43 && drivable(vk) && !shift && down(vk) ? 1 : 0);
      const joy = Atomics.load(input, IN.JOY_ACTIVE) ? unwindow(Atomics.load(input, IN.JOY_X)) : 0;
      const pedal = Atomics.load(input, IN.JOY_ACTIVE) ? -unwindow(Atomics.load(input, IN.JOY_Y)) : 0;
      return { steer: Math.max(key(keys.right), joy) - Math.max(key(keys.left), -joy), throttle: Math.max(key(keys.accelerate), pedal),
        brake: Math.max(key(keys.brake), -pedal), lift: (down(0x20) ? 1 : 0) - (down(0x43) ? 1 : 0) };
    };
    progress('boot', 50);
    race.boot();
    flushAudio();
    progress('boot', 100);
    // with the levels the race plays with (an enabled FX_VOLUME 0 is 75 after 0x437560): the menu adopts the effects
    // level as the JS reconstruction's does after its load (main.js:716-719)
    post({ t: 'running', race: raceNo, volumes: volume.boot(vfs) });

    let next = performance.now();
    let lastStats = 0;
    for (;;) {
      if (Atomics.load(ctrl, CTRL.PAUSED)) {
        // The race held between passes (CTRL.PAUSED). On a result screen held for a focus loss (HOLD.RESULTS: the finish
        // 0x41fd90, phase 3, game over 0x420850, phase 6) the original's "pauze" shows over it while the special text is
        // idle and goes again before the next pass (render-replay.js notice(): the passes after it are the same), as the
        // JS port's suspend shows "pauze" there (driving-view.js:395) and its resume removes it (:409). A new shape, or
        // the notice, draws the held picture again (repaint).
        soundUs();
        let notice = false;
        while (Atomics.load(ctrl, CTRL.PAUSED)) {
          const phase = race.m.u32[0x0053b9c0 >> 2];
          const wanted = race.ticks > 0 && (Atomics.load(ctrl, CTRL.HOLD) & HOLD.RESULTS) !== 0 && (phase === 3 || phase === 6);
          let draw = shape();
          if (wanted && !notice && still(() => race.renderReplay.notice(true))) { notice = true; draw = true; }
          if (draw) still(repaint);
          Atomics.wait(ctrl, CTRL.PAUSED, 1, 500);
        }
        if (notice) still(() => race.renderReplay.notice(false));
        soundUs();
        next = performance.now();
      }
      const now = performance.now();
      if (now < next) { sleep(next - now); continue; }
      // WinMain's gate: a pass when 25 ms have gone by; a late pass is not made up for
      next += TICK_MS;
      if (now - next > 100) next = now + TICK_MS;
      shape();
      soundUs();
      const going = race.tick(TICK_MS / 1000);
      Atomics.store(ctrl, CTRL_WAITING, 0);
      Atomics.store(ctrl, CTRL.PAUSE_KIND, 0);
      flushAudio();
      if (!going) break;
      Atomics.store(ctrl, CTRL.TICKS, race.ticks);
      Atomics.store(ctrl, CTRL.PHASE, race.m.u32[0x0053b9c0 >> 2]);
      Atomics.store(ctrl, CTRL.FLIGHT_ACTIVE, race.flight.active ? 1 : 0);
      const safe = race.safeguards;
      Atomics.store(ctrl, CTRL.SAFE_STUCK, safe.stuck.stats ? safe.stuck.stats.started : 0);
      Atomics.store(ctrl, CTRL.SAFE_NPC, safe.stats.npc);
      Atomics.store(ctrl, CTRL.SAFE_KEYS, safe.stats.keys);
      if (now - lastStats > 500) { lastStats = now; post({ t: 'stats', race: raceNo, ticks: race.ticks, phase: race.m.u32[0x0053b9c0 >> 2], frames: render.stats.frames, draws: render.lastFrameDraws,
        // the driving handler's input (0x4325b0): device 1 keyboard ramps / 3 analog, steer -100..100, throttle 0..100
        device: race.m.i32[DATA.DEVICE >> 2], steer: +race.m.f32[0x0053bd70 >> 2].toFixed(1), throttle: +race.m.f32[0x0053bd74 >> 2].toFixed(1), kmh: race.m.i32[0x0053be34 >> 2],
        flight: race.flight.state(),
        // the renders without an object pass (render-replay.js): pause and flight renders, karts put back, parts drawn off their body
        replay: race.renderReplay && { ...race.renderReplay.stats },
        // the sound's clock (soundUs): the game time kept out of it while the page held the sound, the music's place
        // there (dshow.js) and when this was posted (ms since the page's time origin), for the checks of a focus pause
        // the game files (game-files.js): reads the game thread waited for (not in the race's lists), all fetched so far
        files: kept.files.stats(),
        sound: { heldSeconds: +(heldUs / 1e6).toFixed(3), music: host.musicPosition ? host.musicPosition() : null, at: performance.timeOrigin + performance.now() },
        // the game's clock in ms (its field: a reading through query() here would move it), for the checks of a hold
        clockMs: Math.round(race.clock.us / 1000),
        // the bindings in the game's table (0x53a5b8, source/input/race-keys.js), for the checks of a change mid-race
        bindings: gameKeys(race.m),
        // the safeguards (safeguards.js): stuck recoveries started and moved, NPC speed corrections, filtered key polls,
        // binding polls answered for the pad or the wheel (joy)
        safe: { stuck: safe.stuck.stats && safe.stuck.stats.started, relocated: safe.stuck.stats && safe.stuck.stats.relocated, npc: safe.stats.npc, keys: safe.stats.keys, joy: safe.stats.joyPolls, cheats: host.cheats } }); }
    }
    flushAudio();
    render.close();
    Atomics.store(ctrl, CTRL.PHASE, -1);
    Atomics.store(ctrl, CTRL.FLIGHT_ACTIVE, 0);
    post({ t: 'exit', race: raceNo, code: race.exitCode, files: kept.files.stats(), raceIni: new TextDecoder('latin1').decode(vfs.read('race.ini') || new Uint8Array()) });
  } catch (err) {
    try { flushAudio(); render.close(200); } catch (e) { /* the race is gone anyway */ }
    Atomics.store(ctrl, CTRL.PHASE, -1);
    Atomics.store(ctrl, CTRL.FLIGHT_ACTIVE, 0);
    throw err;
  }
}

function crash(raceNo, err) {
  post({ t: 'crash', race: raceNo, message: String(err && err.message ? err.message : err), stack: err && err.stack ? String(err.stack).split('\n').slice(0, 12).join('\n') : '' });
}

self.onmessage = (e) => {
  const d = e.data;
  if (d.t === 'init') {
    const base = d.baseUrl || self.location.href;
    const urls = { ...DEFAULT_URLS, ...(d.urls || {}) };
    page = {
      ctrl: new Int32Array(d.ctrl), input: new Int32Array(d.input), port: d.port,
      url: (kind, name) => new URL(urls[kind] + (name || ''), base).href,
    };
  } else if (d.t === 'preload') {
    busy = busy.then(async () => {
      await module();
      await filesFor(-1, { country: 0, raceType: 0, character: 0 }, () => {});
    }).catch((err) => post({ t: 'log', s: 'preload: ' + (err && err.message ? err.message : err) }));
  } else if (d.t === 'race') {
    // one race at a time; the next waits for this one to end
    busy = busy.then(() => runRace(d)).catch((err) => crash(d.race, err));
  }
};
