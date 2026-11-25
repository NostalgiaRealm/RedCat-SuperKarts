// The pad in the game's own loops (source/input/gamepad.js) and the quit requester's focus (requester-focus.js), against
// the JS reconstruction's pad (its input.js:144-166, main.js:750-803): what the game worker would see in shared memory.
// The game side is tools/check-touch-pad.mjs.
import test from 'node:test';
import assert from 'node:assert/strict';
import { IN } from '../source/web/shared.js';
import { SharedInput } from '../source/input/shared-input.js';
import { Gamepads } from '../source/input/gamepad.js';
import { RequesterFocus, REQUESTER_BUTTONS } from '../source/input/requester-focus.js';

const VK = { ENTER: 0x0D, ESC: 0x1B, P: 0x50, J: 0x4A, N: 0x4E, CTRL: 0x11, ALT: 0x12, SPACE: 0x20, LEFT: 0x25, UP: 0x26 };
const wait = (ms) => new Promise((r) => setTimeout(r, ms));

function rig() {
  const input = new Int32Array(new SharedArrayBuffer(IN.SIZE * 4));
  const shared = new SharedInput(input);
  const focus = new RequesterFocus(shared);
  const pad = { id: 'test', connected: true, mapping: 'standard', axes: [0, 0, 0, 0], buttons: Array.from({ length: 17 }, () => ({ value: 0 })) };
  navigator.getGamepads = () => [pad];
  const game = { waiting: false, pauseKind: 0, phase: 0, flying: false, focus: false };
  const pads = new Gamepads(shared, () => ({ ...game }), { focus });
  const press = (n, v = 1) => { pad.buttons[n].value = v; pads.poll(); };
  const key = (vk) => Atomics.load(input, vk) === 1;
  const mouse = () => [Atomics.load(input, IN.MOUSE_X), Atomics.load(input, IN.MOUSE_Y), Atomics.load(input, IN.BUTTONS)];
  return { input, shared, focus, pad, game, pads, press, key, mouse };
}

test('requester: focus starts on "nee"; A presses it (the pointer on its centre, left button held >= 80 ms); B is N', async () => {
  const r = rig();
  r.game.waiting = true; r.game.pauseKind = 2;
  r.pads.poll();
  assert.equal(r.focus.focus, 'no');
  r.press(0);                                        // A
  assert.deepEqual(r.mouse(), [...REQUESTER_BUTTONS.no, 1]);
  assert.equal(r.key(VK.J), false, 'A is not J in the requester');
  r.press(0, 0);
  assert.equal(r.mouse()[2], 1, 'a short press is held for 80 ms');
  await wait(100);
  assert.equal(r.mouse()[2], 0);
  r.press(1);                                        // B
  assert.equal(r.key(VK.N), true);
  r.press(1, 0);
  assert.equal(r.key(VK.N), false);
});

test('requester: a direction moves the focus to "ja" and back; A then presses "ja"', () => {
  const r = rig();
  r.game.waiting = true; r.game.pauseKind = 2;
  r.pads.poll();
  r.press(14);                                       // D-pad left
  assert.equal(r.focus.focus, 'yes');
  assert.deepEqual(r.mouse().slice(0, 2), [...REQUESTER_BUTTONS.yes]);
  r.press(14, 0);
  r.pad.axes[0] = 0.9; r.pads.poll();                // the stick past half way: the next one again
  assert.equal(r.focus.focus, 'no');
  r.pads.poll();                                     // held: no new press
  assert.equal(r.focus.focus, 'no');
  r.pad.axes[0] = 0; r.pads.poll();
  r.press(12); r.press(12, 0);                       // up too (the JS port moves to the next button on any arrow)
  assert.equal(r.focus.focus, 'yes');
  r.press(0);
  assert.deepEqual(r.mouse(), [...REQUESTER_BUTTONS.yes, 1]);
});

test('requester: nothing while Esc is held (the opening Esc), and the focus is "nee" again when it opens again', () => {
  const r = rig();
  r.shared.hold('key', VK.ESC, true);
  r.game.waiting = true; r.game.pauseKind = 2;
  r.press(14); r.press(14, 0); r.press(0);
  assert.equal(r.focus.focus, 'no');
  assert.equal(r.mouse()[2], 0);
  r.press(0, 0);
  r.shared.hold('key', VK.ESC, false);
  r.press(14); r.press(14, 0);
  assert.equal(r.focus.focus, 'yes');
  r.game.waiting = false; r.game.pauseKind = 0; r.pads.poll();
  r.game.waiting = true; r.game.pauseKind = 2; r.pads.poll();
  assert.equal(r.focus.focus, 'no');
});

test('requester: B held as it opens (braking) does not answer it; Start is not P there nor after it until let go', () => {
  const r = rig();
  r.press(1);                                        // braking with B
  r.game.waiting = true; r.game.pauseKind = 2;
  r.pads.poll();
  assert.equal(r.key(VK.N), false);
  r.press(9);                                        // Start in the requester
  assert.equal(r.key(VK.P), false);
  r.game.waiting = false; r.game.pauseKind = 0; r.pads.poll();
  assert.equal(r.key(VK.P), false, 'still held after it: not P');
  r.press(9, 0); r.press(9);
  assert.equal(r.key(VK.P), true, 'a new press is P');
});

test('no Back: button 8 holds nothing', () => {
  const r = rig();
  r.press(8);
  assert.equal(r.key(VK.ESC), false);
  r.game.waiting = true; r.game.pauseKind = 2; r.pads.poll();
  assert.equal(r.key(VK.ESC), false);
});

test('P pause: A is J, Start P; B, the stick, X, Y and LB reach nothing', () => {
  const r = rig();
  r.game.waiting = true; r.game.pauseKind = 1; r.game.flying = true;
  r.press(0); assert.equal(r.key(VK.J), true); r.press(0, 0);
  r.press(9); assert.equal(r.key(VK.P), true); r.press(9, 0);
  r.press(1); assert.equal(r.key(VK.N), false); r.press(1, 0);
  r.press(14); r.press(14, 0);
  r.press(2); r.press(3); r.press(4);
  assert.deepEqual([VK.LEFT, VK.CTRL, VK.ALT, VK.SPACE, VK.N].map(r.key), [false, false, false, false, false]);
  r.game.waiting = false; r.game.pauseKind = 0; r.pads.poll();
  assert.deepEqual([VK.CTRL, VK.ALT, VK.SPACE].map(r.key), [true, true, true], 'X, Y and LB held on after the pause');
});

test('focus pause: B is N, a new direction holds its arrow key for 80 ms', async () => {
  const r = rig();
  r.game.waiting = true; r.game.pauseKind = 1; r.game.focus = true;
  r.press(1); assert.equal(r.key(VK.N), true); r.press(1, 0); assert.equal(r.key(VK.N), false);
  r.pad.axes[1] = -0.9; r.pads.poll();               // stick up
  assert.equal(r.key(VK.UP), true);
  await wait(100);
  r.pads.poll();
  assert.equal(r.key(VK.UP), false, 'let go after 80 ms although the stick is still up');
  r.pads.poll();
  assert.equal(r.key(VK.UP), false, 'no new press while it stays up');
  r.press(2); assert.equal(r.key(VK.CTRL), false, 'X does not reach the pause');
});

test('pressed(): A, B, Start, the D-pad and the stick end the focus hold; X, Y, LB, RB, LT, RT and Back do not', () => {
  const r = rig();
  for (const n of [2, 3, 4, 5, 6, 7, 8, 10, 11]) { r.pad.buttons[n].value = 1; assert.equal(r.pads.pressed(), false, 'button ' + n); r.pad.buttons[n].value = 0; }
  for (const n of [0, 1, 9, 12, 13, 14, 15]) { r.pad.buttons[n].value = 1; assert.equal(r.pads.pressed(), true, 'button ' + n); r.pad.buttons[n].value = 0; }
  r.pad.axes[0] = -0.8; assert.equal(r.pads.pressed(), true);
  r.pad.axes[0] = 0.3; assert.equal(r.pads.pressed(), false);
});

test('the pointer\'s and the focus\'s mouse buttons are held apart (IN.BUTTONS their union)', async () => {
  const r = rig();
  r.shared.mouse('pointer', 1);
  r.game.waiting = true; r.game.pauseKind = 2;
  r.press(0); r.press(0, 0);
  r.shared.mouse('pointer', 0);
  assert.equal(r.mouse()[2], 1, 'the focus still holds it');
  await wait(100);
  assert.equal(r.mouse()[2], 0);
  r.shared.mouse('pointer', 2);
  r.pads.release();
  assert.equal(r.mouse()[2], 2);
});
