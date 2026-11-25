// What the page tells the game worker about input, in shared memory (source/web/shared.js IN). Keys are held per
// source (keyboard, pad, touch), so a key one source releases stays down while another still holds it, after the
// Spookkasteel port's holdKeys. The virtual joystick (WinMM joystick 0, source/host/winmm.js) carries the pad's
// and the touch wheel's analog steering and pedals for the game's own analog handler 0x4341d0.
import { IN } from '../web/shared.js';

export const JOY_CENTRE = 32767;

export class SharedInput {
  constructor(input) {
    this.input = input;
    this.holders = new Array(256).fill(null).map(() => new Set());
    this.joys = new Map();          // source -> { steer, drive, buttons } while it drives
    // source -> the mouse buttons it holds (IN.BUTTONS is their union): the pointer on the canvas, and the quit
    // requester's focus clicking for the pad or the keyboard (requester-focus.js), so one letting go does not let go of
    // the other's
    this.mice = new Map();
    Atomics.store(input, IN.JOY_X, JOY_CENTRE);
    Atomics.store(input, IN.JOY_Y, JOY_CENTRE);
  }

  changed() {
    Atomics.add(this.input, IN.SEQ, 1);
    Atomics.notify(this.input, IN.SEQ);
  }

  /** source holds (down) or lets go of virtual key vk. */
  hold(source, vk, down) {
    const h = this.holders[vk & 0xFF];
    const was = h.size > 0;
    if (down) h.add(source); else h.delete(source);
    if ((h.size > 0) !== was) {
      Atomics.store(this.input, vk & 0xFF, h.size > 0 ? 1 : 0);
      this.changed();
    }
  }

  /** Lets go of everything every source holds: keys, the joystick, the mouse buttons (between races). */
  clear() {
    const i = this.input;
    for (let vk = 0; vk < 256; vk++) { this.holders[vk].clear(); Atomics.store(i, vk, 0); }
    this.joys.clear();
    this.mice.clear();
    Atomics.store(i, IN.JOY_X, JOY_CENTRE);
    Atomics.store(i, IN.JOY_Y, JOY_CENTRE);
    Atomics.store(i, IN.JOY_BUTTONS, 0);
    Atomics.store(i, IN.JOY_ACTIVE, 0);
    Atomics.store(i, IN.JOY_GAS, 0);
    Atomics.store(i, IN.JOY_BRAKE, 0);
    Atomics.store(i, IN.BUTTONS, 0);
    Atomics.store(i, IN.DX, 0); Atomics.store(i, IN.DY, 0); Atomics.store(i, IN.DZ, 0);
    this.changed();
  }

  /** Is virtual key vk held by any source? */
  held(vk) {
    return this.holders[vk & 0xFF].size > 0;
  }

  /** Lets go of every key source holds, of its joystick and of its mouse buttons. */
  releaseAll(source) {
    for (let vk = 0; vk < 256; vk++) if (this.holders[vk].has(source)) this.hold(source, vk, false);
    this.joystick(source, null);
    this.mouse(source, 0);
  }

  /** source holds the mouse buttons bits (1 left, 2 right, 4 middle; 0: none); IN.BUTTONS holds them all. */
  mouse(source, bits) {
    if (bits) this.mice.set(source, bits); else this.mice.delete(source);
    let all = 0;
    for (const b of this.mice.values()) all |= b;
    if (Atomics.load(this.input, IN.BUTTONS) !== all) {
      Atomics.store(this.input, IN.BUTTONS, all);
      this.changed();
    }
  }

  /** The pointer in the game's screen pixels (GetCursorPos), put somewhere by the page rather than a mouse. */
  pointer(x, y) {
    Atomics.store(this.input, IN.MOUSE_X, x | 0);
    Atomics.store(this.input, IN.MOUSE_Y, y | 0);
    this.changed();
  }

  /**
   * source's analog input, or null when it does not drive: steer -1..1 (right +), drive -1..1 (gas +, brake -),
   * buttons (bit 0 bonus, bit 1 handbrake, as 0x4341d0 reads them), and optionally gas and brake 0..1 apart (the
   * pad's two pedals; else they follow from drive, as the touch wheel's single axis gives them). The sources are
   * summed and clamped. A value past the source's own dead zone maps onto the game's ±10% window and beyond (0x4bac90
   * ignores the window and jumps to ±10 at its edge), so the two dead zones do not add up. The pedals apart go to
   * IN.JOY_GAS and IN.JOY_BRAKE as they are, the largest of the sources (the JS reconstruction's InputState.value,
   * its input.js:33-42), for the stuck recovery (source/input/race-keys.js stuckInput).
   */
  joystick(source, value) {
    if (value) this.joys.set(source, value); else this.joys.delete(source);
    let steer = 0, drive = 0, buttons = 0, gas = 0, brake = 0;
    for (const v of this.joys.values()) {
      steer += v.steer; drive += v.drive; buttons |= v.buttons;
      gas = Math.max(gas, v.gas ?? Math.max(0, v.drive));
      brake = Math.max(brake, v.brake ?? Math.max(0, -v.drive));
    }
    const window = (s) => (s === 0 ? 0 : Math.sign(s) * (0.1 + 0.9 * Math.min(1, Math.abs(s))));
    const axis = (s) => Math.max(0, Math.min(65535, Math.round(JOY_CENTRE + window(Math.max(-1, Math.min(1, s))) * 32768)));
    const pedal = (p) => Math.round(Math.max(0, Math.min(1, p)) * 1e4);
    const i = this.input;
    const active = this.joys.size > 0 && [...this.joys.values()].some((v) => v.steer || v.drive);
    const x = axis(steer), y = axis(-drive), g = pedal(gas), b = pedal(brake);
    if (Atomics.load(i, IN.JOY_X) !== x || Atomics.load(i, IN.JOY_Y) !== y || Atomics.load(i, IN.JOY_BUTTONS) !== buttons || Atomics.load(i, IN.JOY_ACTIVE) !== (active ? 1 : 0)
      || Atomics.load(i, IN.JOY_GAS) !== g || Atomics.load(i, IN.JOY_BRAKE) !== b) {
      Atomics.store(i, IN.JOY_X, x);
      Atomics.store(i, IN.JOY_Y, y);
      Atomics.store(i, IN.JOY_BUTTONS, buttons);
      Atomics.store(i, IN.JOY_ACTIVE, active ? 1 : 0);
      Atomics.store(i, IN.JOY_GAS, g);
      Atomics.store(i, IN.JOY_BRAKE, b);
      this.changed();
    }
  }
}
