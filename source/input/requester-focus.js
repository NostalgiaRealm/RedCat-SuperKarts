// A focus on the quit requester's two buttons for the pad and the keyboard, as the JS reconstruction gives its
// requester: focus starts on "nee" when it shows (its main.js:883), a direction (the pad's stick or D-pad past half
// way, an arrow key) moves it to the other button (main.js:803: the next of the two, whichever direction), and A,
// Enter or Space press the focused button (main.js:802; input.js:66, :156, controller A as Enter). Its research calls
// these browser and controller adaptations of the original's requester (its docs/research-quit-requester.md).
//
// Here the requester is the original's own (0x473780: 0x473820 draws it, 0x473f20 loops on 0x474040), which knows J,
// N, Esc and the mouse only. The focus is the game's pointer: 0x473820 parks it on the centre of "nee" (0x4b9e40 ->
// SetCursorPos, "Setting mouse on no button", its button size / 2 + position), and the original draws the hover art
// and its paw wherever the pointer is (0x473d40 -> 0x4739c0), so a move puts the pointer (IN.MOUSE_X/Y) on the other
// button's centre, and a press puts it on the focused one and holds the left mouse button for at least MIN_HOLD_MS:
// 0x474040 takes a held left button over a button's rectangle (position, position + size, PtInRect) at once, without
// waiting for its release (0x474040 -> 0x4b9ea0 -> 0x4b3830(1)). The buttons: SndGfx.ini [STOPPEN] HYES_NORMAL ja_u at
// 150,350 and HNO_NORMAL nee_u at 425,350 (the hi-res set, the JS port's race-requester.js:42-45 places the same), each
// 115x38 (the JS port's docs/research-hud-notice-audit.md:71), so the centres are 207,369 and 482,369 (C's integer
// halves, as 0x473820 computes them; tools/check-touch-pad.mjs reads the parked pointer back).
//
// Nothing happens while Esc is held: the JS port's requester takes keys only after the Esc that opened it is let go
// (main.js:800, stage 'input'), as the original draws it only then (0x42f290's first loop).
export const REQUESTER_BUTTONS = Object.freeze({ yes: Object.freeze([207, 369]), no: Object.freeze([482, 369]) });
const VK_ESC = 0x1B;
const MIN_HOLD_MS = 80;

export class RequesterFocus {
  /** shared: SharedInput. */
  constructor(shared) {
    this.shared = shared;
    this.open = false;
    this.focus = 'no';
    this.pressedAt = new Map();      // source -> when its press began (the button is held for it)
    this.timers = new Map();
  }

  /**
   * Whether the game waits in its quit requester now (CTRL.PAUSE_KIND 2): on opening the focus is "nee" again, where
   * the game parks its pointer; on closing every press is let go (after its MIN_HOLD_MS), so a button still held does
   * not reach the pause loop 0x42f220, which also scans the mouse buttons (VK 1, 2, 4).
   */
  update(open) {
    open = !!open;
    if (open === this.open) return;
    this.open = open;
    if (open) this.focus = 'no';
    else for (const source of [...this.pressedAt.keys()]) this.press(source, false);
  }

  ready() { return this.open && !this.shared.held(VK_ESC); }

  /** A direction: the other button, the pointer on it. False when the requester does not take it now. */
  move() {
    if (!this.ready()) return false;
    this.focus = this.focus === 'no' ? 'yes' : 'no';
    this.point();
    return true;
  }

  point() {
    const [x, y] = REQUESTER_BUTTONS[this.focus];
    this.shared.pointer(x, y);
  }

  /** source ('pad', 'key') presses (down) or lets go of the focused button; a press lasts MIN_HOLD_MS at least. */
  press(source, down) {
    if (down) {
      if (!this.ready()) return false;
      clearTimeout(this.timers.get(source));
      this.timers.delete(source);
      this.point();
      this.pressedAt.set(source, performance.now());
      this.shared.mouse(source, 1);
      return true;
    }
    const at = this.pressedAt.get(source);
    if (at === undefined) return false;
    this.pressedAt.delete(source);
    const left = MIN_HOLD_MS - (performance.now() - at);
    if (left > 0) this.timers.set(source, setTimeout(() => { this.timers.delete(source); this.shared.mouse(source, 0); }, left));
    else this.shared.mouse(source, 0);
    return true;
  }

  /** Everything let go now (the race held by the menu, a focus loss, the race's end). */
  release() {
    for (const t of this.timers.values()) clearTimeout(t);
    for (const source of new Set([...this.timers.keys(), ...this.pressedAt.keys()])) this.shared.mouse(source, 0);
    this.timers.clear();
    this.pressedAt.clear();
  }
}
