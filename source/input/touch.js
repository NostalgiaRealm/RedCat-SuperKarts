// Touch controls, as in the SuperKarts JavaScript reconstruction (its source/input.js, index.html and style.css):
// a steering wheel bottom left that reads the finger's position (left and right steer in proportion, the upper
// half gives gas, the lower half brakes and then reverses, with a small neutral centre: SuperTuxKart's formula),
// the pedal (Rem: the handbrake), the bonus button and Stoppen (Esc: the original quit requester, while racing or in
// the arrest only, as the JS port's quit gate: STOP_PHASES). Rem and Bonus
// hold the keys bound to the handbrake and the bonus in the settings (Alt and Ctrl unless changed: setKeys).
// The wheel drives the game's own analog handler through the virtual joystick; the buttons hold keys and the
// joystick's buttons. The wheel and a button can be held together; a drag that leaves the wheel keeps control
// until the finger lifts. As in the JS reconstruction the controls hide only for the quit requester (its main.js:882;
// here while the game waits with pause kind 2, CTRL.PAUSE_KIND), where a tap on the picture goes to the game as a mouse
// click on the requester's buttons. In the game's pause (kind 1, P or a focus loss) and the runner's focus hold on the
// result screens they stay drawn but inert: a press shows on them and holds nothing, and a tap on the picture around
// them ends the pause, as the JS port's suspended race reads none of their sources (its input.setMode('menu') on
// pausing, main.js:746, :763) and only #world's pointerdown resumes (main.js:850-851; #touch-controls is not inside
// #world, its index.html:14, :27). A press held as the pause starts or ends is let go (the JS port's setMode there and
// in resumeViewer, main.js:730, clears every touch: input.js:85, :82, :32, :81). The result screens have no button of
// their own: a tap on the picture holds Space there (source/race-runner.js, the JS port's main.js:852).
// Free flight's Omhoog and Omlaag (#flight-touch, which
// main.js puts in this block as the JS reconstruction's main.js:77-81 does) hold Space and C, the keys that lift and
// lower the flying kart (its input.js:51-52), and let go when the flight ends.
import { axisDeadzone, DEFAULT_KEYS } from './gamepad.js';

const VK = { ESC: 0x1B, CTRL: 0x11, ALT: 0x12, SPACE: 0x20, C: 0x43 };
// CTRL.PAUSE_KIND while the game waits (source/web/shared.js): the pause and the quit requester
const PAUSE = 1, REQUESTER = 2;
const MIN_HOLD_MS = 80;
// the race phases (0x53b9c0) in which Stoppen holds Esc (TouchControls constructor)
const STOP_PHASES = new Set([0, 8]);

/** SuperTuxKart's wheel: absolute X/Y position, dead zone 0.1, sensitivities 0.2 (X) and 0.65 (Y). */
export function touchWheelInput(clientX, clientY, { left, top, width, height }) {
  if (!(width > 0 && height > 0)) return { steer: 0, drive: 0 };
  const factor = (value, sensitivity) => Math.max(-1, Math.min(1, axisDeadzone(value, 0.1) / (1 - sensitivity)));
  return { steer: factor(((clientX - left) / width) * 2 - 1, 0.2), drive: factor(1 - ((clientY - top) / height) * 2, 0.65) };
}

export class TouchControls {
  /** root: the #touch-controls element; shared: SharedInput; state(): { waiting, pauseKind, flying }. */
  constructor(root, shared, state, { keys = DEFAULT_KEYS } = {}) {
    this.root = root;
    this.shared = shared;
    this.state = state;
    this.buttons = 0;
    this.wheelValue = null;
    this.inert = false;
    this.keys = { ...DEFAULT_KEYS, ...keys };
    const $ = (id) => root.querySelector('#' + id);
    this.bindWheel($('touch-wheel'));
    this.bindHold($('touch-brake'), 'touch-brake', () => this.keys.handbrake, 2);
    this.bindHold($('touch-bonus'), 'touch-bonus', () => this.keys.bonus, 1);
    // Stoppen: Esc only where the JS port's Stoppen opens the requester. Its requestTouchQuit (main.js:835-839) only goes
    // through its quit gate, nativeRacePauseRequest (native-race-lifecycle.js:107-111: not in phases 1, 3 and 6), and
    // never reaches the result screens' own Esc (0x41fd90, 0x420850 take it and end the screen); in the countdown
    // (phase 1) the original's 0x42f9c0 ignores Esc itself. So 0 (racing) and 8 (the arrest), as P_PHASES less 1.
    const stop = $('touch-stop');
    const stopKey = () => (STOP_PHASES.has(this.state().phase) ? VK.ESC : 0);
    this.bindHold(stop, 'touch-stop', stopKey, 0);
    // Enter or Space on the focused Stoppen (Tab reaches it): the JS port's button click (its onclick, main.js:840)
    // asks the same; a pointer's click (detail >= 1) already pressed it on pointerdown
    if (stop) stop.addEventListener('click', (e) => {
      if (e.detail !== 0 || this.inert || this.root.hidden || !stopKey()) return;
      clearTimeout(this.stopTimer);
      this.shared.hold('touch-stop-key', VK.ESC, true);
      this.stopTimer = setTimeout(() => this.shared.hold('touch-stop-key', VK.ESC, false), MIN_HOLD_MS);
    });
    const lift = root.querySelectorAll('#flight-touch button');
    this.flightReleasers = [];
    if (lift[0]) this.flightReleasers.push(this.bindHold(lift[0], 'touch-up', () => VK.SPACE, 0));
    if (lift[1]) this.flightReleasers.push(this.bindHold(lift[1], 'touch-down', () => VK.C, 0));
    this.flying = false;
  }

  /** The virtual keys Bonus and Rem hold: { bonus, handbrake } (the settings' bindings). */
  setKeys(keys) {
    const next = { ...DEFAULT_KEYS, ...keys };
    if (next.bonus === this.keys.bonus && next.handbrake === this.keys.handbrake) return;
    this.releaseAll();
    this.keys = next;
  }

  /** Outside a race: hidden, nothing held. */
  hide() {
    this.releaseAll();
    this.root.hidden = true;
    this.inert = false;
    this.root.classList.remove('inert');
  }

  sendJoystick() {
    const v = this.inert ? null : this.wheelValue;
    this.shared.joystick('touch', v || this.buttons ? { steer: v ? v.steer : 0, drive: v ? v.drive : 0, buttons: this.buttons } : null);
  }

  bindHold(el, source, keyOf, joyBit) {
    const held = new Set();
    let vk = keyOf();
    // The game reads keys once per 25 ms pass, so a short tap (a quick Stoppen) could fall between two passes:
    // a press is held for at least MIN_HOLD_MS.
    let since = 0, timer = 0;
    const set = () => {
      if (!held.size && performance.now() - since < MIN_HOLD_MS) {
        clearTimeout(timer);
        timer = setTimeout(set, MIN_HOLD_MS - (performance.now() - since));
        return;
      }
      const on = held.size > 0;
      el.classList.toggle('held', on);
      // inert (the pause): the press shows and holds nothing
      const press = on && !this.inert;
      if (press && vk !== keyOf()) { if (vk > 0) this.shared.hold(source, vk, false); vk = keyOf(); }
      if (vk > 0) this.shared.hold(source, vk, press);
      if (joyBit) { this.buttons = press ? this.buttons | joyBit : this.buttons & ~joyBit; this.sendJoystick(); }
    };
    el.addEventListener('pointerdown', (e) => {
      e.preventDefault();
      if (!held.size) since = performance.now();
      held.add(e.pointerId);
      el.setPointerCapture(e.pointerId);
      set();
    });
    for (const ev of ['pointerup', 'pointercancel', 'lostpointercapture']) el.addEventListener(ev, (e) => { if (held.delete(e.pointerId)) set(); });
    el.addEventListener('contextmenu', (e) => e.preventDefault());
    this.releasers = this.releasers || [];
    const release = () => { held.clear(); since = 0; set(); };
    this.releasers.push(release);
    return release;
  }

  bindWheel(el) {
    let pointer = null;
    const visual = (v) => {
      el.style.setProperty('--steer-angle', `${(v ? v.steer : 0) * 90}deg`);
      el.dataset.drive = v && v.drive > 0 ? 'forward' : v && v.drive < 0 ? 'reverse' : 'neutral';
      el.classList.toggle('held', pointer !== null);
    };
    const update = (e) => {
      this.wheelValue = touchWheelInput(e.clientX, e.clientY, el.getBoundingClientRect());
      visual(this.wheelValue);
      this.sendJoystick();
    };
    const release = () => {
      if (pointer !== null && el.hasPointerCapture(pointer)) el.releasePointerCapture(pointer);
      pointer = null;
      this.wheelValue = null;
      visual(null);
      this.sendJoystick();
    };
    el.addEventListener('pointerdown', (e) => {
      if (e.pointerType === 'mouse' && e.button !== 0) return;
      e.preventDefault();
      if (pointer !== null) return;
      pointer = e.pointerId;
      el.setPointerCapture(pointer);
      update(e);
    });
    el.addEventListener('pointermove', (e) => { if (e.pointerId === pointer) { e.preventDefault(); update(e); } });
    for (const ev of ['pointerup', 'pointercancel', 'lostpointercapture']) el.addEventListener(ev, (e) => { if (e.pointerId === pointer) release(); });
    el.addEventListener('contextmenu', (e) => e.preventDefault());
    this.releasers = this.releasers || [];
    this.releasers.push(release);
    visual(null);
  }

  releaseAll() {
    for (const r of this.releasers) r();
    clearTimeout(this.stopTimer);
    this.shared.hold('touch-stop-key', VK.ESC, false);
  }

  /**
   * Once per animation frame: shows or hides the controls for the game's state; show: the settings and the runner
   * want them; held: the runner holds the race (its focus hold on the result screens), which leaves them inert too.
   */
  update(show, held = false) {
    const { waiting, pauseKind, flying } = this.state();
    if (this.flying && !flying) for (const r of this.flightReleasers) r();
    this.flying = !!flying;
    const visible = show && !(waiting && pauseKind === REQUESTER);
    if (this.root.hidden === visible) {
      this.root.hidden = !visible;
      if (!visible) this.releaseAll();
    }
    const inert = !!held || (waiting && pauseKind === PAUSE);
    if (inert !== this.inert) {
      this.inert = inert;
      this.root.classList.toggle('inert', inert);
      this.releaseAll();
    }
  }
}
