// Gamepads (the browser's standard mapping), after the SuperKarts JavaScript reconstruction's controller mapping
// (source/input.js poll there, its input.js:144-166) and the A2 Racer 4 port's dialogs:
//   left stick or D-pad steers; RT or A gas, LT or B brake (analog, through the game's own analog handler);
//   X bonus, Y handbrake (the keys bound to them in the settings, as game.ini [INPUT] has them: setKeys);
//   Start P (pause);
//   in the game's pause (pause kind 1: 0x42f220, which any key ends) A is J and Start P, as the JS port's pause gate
//     takes the pad's Enter and P (its input.js:149 puts them among its keys; native-race-lifecycle.js:139-150); in a
//     focus pause (the runner's: pause kind 1 under its focus mute) also B (N) and the stick or D-pad past half way (an
//     arrow key for MIN_HOLD_MS, so the loop sees it let go at once), as they resume the JS port's focus pause
//     (input.js:156-162 -> back() main.js:757, menuKey main.js:798); X, Y, LB and RB do not reach the pause, as the JS
//     port's pad holds no action there (input.setMode('menu'), main.js:746, :763; input.js:153-154);
//   in the quit requester (pause kind 2) a focus on its buttons, from "nee", moved by the stick or D-pad and pressed
//     with A (requester-focus.js; the JS port's main.js:799-803, :883); B is N (nee: the JS port's back() chooses No,
//     main.js:750-754); Start does nothing there (back('pause'), main.js:751-755) and is not P again until let go;
//   no Back: the JS port maps none (input.js:149-162), so a pad alone has no way into the quit requester there either
//     (docs/intentional-differences.md, Input device);
//   on the finish and game-over screens (race phase 3 and 6) A is Enter (the JS port's pad Enter, input.js:149, which
//     its result gate takes, native-race-lifecycle.js:11);
//   while flying (free flight, source/host/free-flight.js) LB up and RB down: Space and C (its input.js:152).
// B, the stick and the D-pad answer the game's loops only with a new press, as the JS port's menu keys come from
// lastPadButtons edges (input.js:157-165): B held for braking as the requester opens does not answer it "nee".
// A pad that was driving and goes away pauses the race, as the JavaScript reconstruction does: onLost (the race
// runner presses the game's own P), or without it P held here for a moment.
import { JOY_CENTRE } from './shared-input.js';

const VK = { ENTER: 0x0D, P: 0x50, J: 0x4A, N: 0x4E, CTRL: 0x11, ALT: 0x12, SPACE: 0x20, C: 0x43 };
const ARROW = { left: 0x25, up: 0x26, right: 0x27, down: 0x28 };
export const DEFAULT_KEYS = Object.freeze({ bonus: VK.CTRL, handbrake: VK.ALT });
// CTRL.PAUSE_KIND while the game waits (source/web/shared.js): its pause and its quit requester
const PAUSE = 1, REQUESTER = 2;
const MIN_HOLD_MS = 80;
// What ends the JS port's focus pause (its menu keys and Pause, input.js:156: A Enter, B Escape, Start, the D-pad; the
// stick past half way is read apart): the runner's focus hold on the result screens ends on these too.
const RESUME_BUTTONS = [0, 1, 9, 12, 13, 14, 15];

export function axisDeadzone(value, deadzone = 0.18) {
  if (!Number.isFinite(value)) return 0;
  const magnitude = Math.min(1, Math.abs(value)), limit = Math.min(0.99, Math.max(0, deadzone));
  return magnitude <= limit ? 0 : Math.sign(value) * (magnitude - limit) / (1 - limit);
}

const standardPad = () => {
  let pads = [];
  try { pads = navigator.getGamepads ? [...navigator.getGamepads()] : []; } catch (e) { pads = []; }
  return pads.find((p) => p && p.connected && p.mapping === 'standard') || null;
};

export class Gamepads {
  /**
   * shared: SharedInput; state(): { waiting, pauseKind, phase, flying, focus } of the game (focus: the runner's focus
   * pause is on); focus: the quit requester's RequesterFocus (requester-focus.js), shared with the keyboard.
   */
  constructor(shared, state, { deadzone = 0.18, keys = DEFAULT_KEYS, onLost = null, focus = null } = {}) {
    this.shared = shared;
    this.state = state;
    this.deadzone = deadzone;
    this.keys = { ...DEFAULT_KEYS, ...keys };
    this.onLost = onLost;
    this.focus = focus;
    this.id = null;
    this.used = false;
    this.pausePulse = 0;
    this.last = {};             // last poll's directions and buttons, for new presses
    this.startInRequester = false;
    this.bAnswers = false;
    this.resumeVk = 0;
    this.resumeUntil = 0;
  }

  /** The virtual keys X and Y hold: { bonus, handbrake } (the settings' bindings). */
  setKeys(keys) {
    const next = { ...DEFAULT_KEYS, ...keys };
    if (next.bonus === this.keys.bonus && next.handbrake === this.keys.handbrake) return;
    this.release();
    this.keys = next;
  }

  release() {
    this.shared.releaseAll('pad');
    this.shared.releaseAll('pad-resume');
    this.resumeVk = 0;
    this.bAnswers = false;
    if (this.focus) this.focus.press('pad', false);
  }

  /** The stick or D-pad past half way, as the JS port's menu arrows (input.js:155-156, the steering dead zone first). */
  directions(pad) {
    const down = (n) => (pad.buttons[n] ? pad.buttons[n].value : 0) > 0.5;
    const x = axisDeadzone(pad.axes[0] || 0, this.deadzone), y = axisDeadzone(pad.axes[1] || 0, this.deadzone);
    return { up: down(12) || y < -0.5, down: down(13) || y > 0.5, left: down(14) || x < -0.5, right: down(15) || x > 0.5 };
  }

  /**
   * A button or direction that resumes the JS port's focus pause (RESUME_BUTTONS, the stick past half way) held now.
   * The runner's focus hold on the result screens ends on a new press of one (race-runner.js).
   */
  pressed() {
    const pad = standardPad();
    if (!pad) return false;
    return RESUME_BUTTONS.some((n) => pad.buttons[n] && pad.buttons[n].value > 0.5) || Object.values(this.directions(pad)).some(Boolean);
  }

  /** Once per animation frame. */
  poll() {
    const pad = standardPad();
    const s = this.shared;
    const now = performance.now();
    if (this.pausePulse && now > this.pausePulse) { s.hold('pad-lost', VK.P, false); this.pausePulse = 0; }
    if (!pad) {
      if (this.id !== null) {
        // the driving pad went away: everything let go, and the race paused (P held for a moment)
        this.release();
        this.last = {};
        if (this.used) {
          if (this.onLost) this.onLost();
          else { s.hold('pad-lost', VK.P, true); this.pausePulse = now + 200; }
        }
        this.id = null;
        this.used = false;
      }
      return;
    }
    this.id = pad.id;
    const b = (n) => Math.max(0, Math.min(1, pad.buttons[n] ? pad.buttons[n].value : 0));
    const down = (n) => b(n) > 0.5;
    const { waiting, pauseKind, phase, flying, focus } = this.state();
    const kind = waiting ? pauseKind : 0;
    const inPause = kind === PAUSE, inRequester = kind === REQUESTER, inLoop = inPause || inRequester;
    const steerAxis = axisDeadzone(pad.axes[0] || 0, this.deadzone);
    const steer = Math.max(-1, Math.min(1, steerAxis - b(14) + b(15)));
    const resultScreen = phase === 3 || phase === 6;
    // new presses since the last poll
    const held = { ...this.directions(pad), a: down(0), b: down(1) };
    const last = this.last;
    const fresh = (k) => held[k] && !last[k];
    const direction = ['up', 'down', 'left', 'right'].find(fresh);
    this.last = held;

    // in the game's own loops A and B answer it (J, N, the requester's focus); there and on the result screens A does
    // not drive
    const gas = waiting || resultScreen ? b(7) : Math.max(b(7), b(0));
    const brake = waiting ? b(6) : Math.max(b(6), b(1));
    const drive = gas - brake;
    const buttons = (down(2) ? 1 : 0) | (down(3) ? 2 : 0);
    // gas and brake also apart: both pedals held is not driving for the stuck recovery (shared-input.js joystick)
    const any = steer || drive || buttons || gas || brake;
    if (any) this.used = true;
    s.joystick('pad', any ? { steer, drive, buttons, gas, brake } : null);
    if (this.keys.bonus > 0) s.hold('pad', this.keys.bonus, !inLoop && down(2));
    if (this.keys.handbrake > 0) s.hold('pad', this.keys.handbrake, !inLoop && down(3));
    // Start: P, but not in the requester and not after it until let go
    if (inRequester && down(9)) this.startInRequester = true;
    else if (!down(9)) this.startInRequester = false;
    s.hold('pad', VK.P, down(9) && !this.startInRequester);
    s.hold('pad', VK.J, inPause && down(0));
    // B: N from a new press, in the requester and in a focus pause (not in a P pause: the JS port's back() does nothing
    // there, main.js:778)
    const bTakes = inRequester || (inPause && !!focus);
    if (!bTakes || !held.b) this.bAnswers = false;
    else if (fresh('b')) this.bAnswers = true;
    s.hold('pad', VK.N, this.bAnswers);
    s.hold('pad', VK.ENTER, resultScreen && down(0));
    s.hold('pad', VK.SPACE, !!flying && !inLoop && down(4));
    s.hold('pad', VK.C, !!flying && !inLoop && down(5));
    // the requester's focus: a direction moves it, A presses the focused button until let go
    if (this.focus) {
      this.focus.update(inRequester);
      if (inRequester && direction) this.focus.move();
      if (inRequester && fresh('a')) this.focus.press('pad', true);
      else if (!held.a || !inRequester) this.focus.press('pad', false);
    }
    // a focus pause: a new direction holds its arrow key for a moment, which 0x42f220's scan sees and sees let go
    if (this.resumeVk && (now >= this.resumeUntil || !inPause)) { s.hold('pad-resume', this.resumeVk, false); this.resumeVk = 0; }
    if (inPause && focus && direction && !this.resumeVk) {
      this.resumeVk = ARROW[direction];
      this.resumeUntil = now + MIN_HOLD_MS;
      s.hold('pad-resume', this.resumeVk, true);
    }
  }
}

export { JOY_CENTRE };
