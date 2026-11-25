// The race's key bindings during a race and the stuck recovery's input (source/input/race-keys.js), and the pedals the
// pad and the touch wheel publish apart (source/input/shared-input.js IN.JOY_GAS/IN.JOY_BRAKE). The game side is
// tools/check-keys.mjs.
import test from 'node:test';
import assert from 'node:assert/strict';
import { CTRL, IN } from '../source/web/shared.js';
import { SharedInput } from '../source/input/shared-input.js';
import { StuckDetector } from '../source/host/stuck.js';
import { publishKeys, readKeys, writeGameKeys, gameKeys, stuckInput, drivable, GAME_KEY_TABLE, LIB_KEY_TABLE } from '../source/input/race-keys.js';

const ARROWS = { accelerate: 0x26, brake: 0x28, left: 0x25, right: 0x27, bonus: 0x11, handbrake: 0x12 };
const WFUD = { accelerate: 0x57, brake: 0x46, left: 0x55, right: 0x44, bonus: 0x11, handbrake: 0x12 };
const ctrlWords = () => new Int32Array(new SharedArrayBuffer(CTRL.SIZE * 4));
const inputWords = () => new Int32Array(new SharedArrayBuffer(IN.SIZE * 4));

test('the new words fit: CTRL.KEYS..KEYS_SEQ below CTRL.SIZE, clear of the other words; the pedals below IN.SIZE', () => {
  const used = Object.entries(CTRL).filter(([k]) => k !== 'SIZE' && k !== 'KEYS').map(([, v]) => v);
  for (let k = 0; k < 6; k++) assert.ok(!used.includes(CTRL.KEYS + k));
  assert.ok(CTRL.KEYS_SEQ >= CTRL.KEYS + 6 && CTRL.KEYS_SEQ < CTRL.SIZE);
  assert.ok(IN.JOY_GAS < IN.SIZE && IN.JOY_BRAKE < IN.SIZE && ![IN.JOY_X, IN.JOY_Y, IN.JOY_BUTTONS, IN.JOY_ACTIVE].includes(IN.JOY_GAS));
});

test('publishKeys: the six keys, KEYS_SEQ + 1 only when one changed; readKeys gives them back', () => {
  const ctrl = ctrlWords();
  assert.equal(publishKeys(ctrl, ARROWS), true);
  assert.equal(Atomics.load(ctrl, CTRL.KEYS_SEQ), 1);
  assert.equal(publishKeys(ctrl, { ...ARROWS }), false);     // the same settings applied again (a volume change)
  assert.equal(Atomics.load(ctrl, CTRL.KEYS_SEQ), 1);
  assert.equal(publishKeys(ctrl, WFUD), true);
  assert.equal(Atomics.load(ctrl, CTRL.KEYS_SEQ), 2);
  assert.deepEqual(readKeys(ctrl), WFUD);
  publishKeys(ctrl, { ...WFUD, bonus: 0 });                   // unbound
  assert.equal(readKeys(ctrl).bonus, 0);
});

test('writeGameKeys: 0x42ec40\'s order, left, right, accelerate, brake, bonus, handbrake, in both tables', () => {
  const m = { i32: new Int32Array(0x700000 / 4) };
  writeGameKeys(m, WFUD);
  assert.deepEqual([0, 1, 2, 3, 4, 5].map((k) => m.i32[(GAME_KEY_TABLE + 4 * k) >> 2]), [0x55, 0x44, 0x57, 0x46, 0x11, 0x12]);
  assert.deepEqual([0, 1, 2, 3, 4, 5].map((k) => m.i32[(LIB_KEY_TABLE + 8 * k) >> 2]), [0x55, 0x44, 0x57, 0x46, 0x11, 0x12]);
  assert.deepEqual(gameKeys(m), WFUD);
  assert.equal(m.i32[(GAME_KEY_TABLE + 24) >> 2], 0);        // the two spare slots 0x53a5d0/d4 stay 0
});

test('drivable: P and Esc never, 0 and out of range never', () => {
  assert.deepEqual([0x50, 0x1b, 0, 256, -1, 0x26, 0x57].map(drivable), [false, false, false, false, false, true, true]);
});

test('stuckInput: the Shift rule, P never, the pedals apart, the largest source', () => {
  const input = inputWords();
  const held = new Set();
  const down = (vk) => held.has(vk);
  held.add(0x26);
  assert.deepEqual(stuckInput(ARROWS, down, input), { throttle: 1, brake: 0, handbrake: false });
  held.add(0x10);                                             // Shift: 0x4b3880 answers the binding "up"
  assert.deepEqual(stuckInput(ARROWS, down, input), { throttle: 0, brake: 0, handbrake: false });
  held.clear(); held.add(0x50);
  assert.equal(stuckInput({ ...ARROWS, accelerate: 0x50 }, down, input).throttle, 0);   // P bound: never drives
  held.clear();
  Atomics.store(input, IN.JOY_GAS, 1500);                    // a light pedal: 0.15, not 0.1 + 0.9 * 0.15
  assert.equal(stuckInput(ARROWS, down, input).throttle, 0.15);
  Atomics.store(input, IN.JOY_GAS, 10000); Atomics.store(input, IN.JOY_BRAKE, 5000);
  assert.deepEqual(stuckInput(ARROWS, down, input), { throttle: 1, brake: 0.5, handbrake: false });
  Atomics.store(input, IN.JOY_BUTTONS, 2); held.add(0x10);   // the pad's Y with Shift held: still the handbrake
  assert.equal(stuckInput(ARROWS, down, input).handbrake, true);
});

test('the detector on that input: Shift+Up, a light pedal and gas with half brake are not driving', () => {
  const DT = 0.025;
  const run = (input) => { const d = new StuckDetector(); let f = false; for (let k = 0; k < 400; k++) f = d.step({ position: [0, 0, 0] }, input, DT) || f; return f; };
  const input = inputWords();
  const keys = new Set([0x10, 0x26]);
  assert.equal(run(stuckInput(ARROWS, (vk) => keys.has(vk), input)), false);
  keys.delete(0x10);
  assert.equal(run(stuckInput(ARROWS, (vk) => keys.has(vk), input)), true);
  keys.clear();
  Atomics.store(input, IN.JOY_GAS, 1500);
  assert.equal(run(stuckInput(ARROWS, (vk) => keys.has(vk), input)), false);
  Atomics.store(input, IN.JOY_GAS, 10000); Atomics.store(input, IN.JOY_BRAKE, 5000);
  assert.equal(run(stuckInput(ARROWS, (vk) => keys.has(vk), input)), false);
  Atomics.store(input, IN.JOY_BRAKE, 0);
  assert.equal(run(stuckInput(ARROWS, (vk) => keys.has(vk), input)), true);
});

test('SharedInput: the pedals apart and unwindowed, the largest source; Y keeps the window; clear() zeroes them', () => {
  const input = inputWords();
  const s = new SharedInput(input);
  s.joystick('pad', { steer: 0, drive: 0.5, buttons: 0, gas: 1, brake: 0.5 });
  assert.deepEqual([Atomics.load(input, IN.JOY_GAS), Atomics.load(input, IN.JOY_BRAKE)], [10000, 5000]);
  assert.equal(Atomics.load(input, IN.JOY_Y), Math.round(32767 - (0.1 + 0.9 * 0.5) * 32768));
  s.joystick('touch', { steer: 0, drive: -0.15, buttons: 0 });            // the wheel: brake from its one axis
  assert.deepEqual([Atomics.load(input, IN.JOY_GAS), Atomics.load(input, IN.JOY_BRAKE)], [10000, 5000]);
  s.joystick('pad', null);
  assert.deepEqual([Atomics.load(input, IN.JOY_GAS), Atomics.load(input, IN.JOY_BRAKE)], [0, 1500]);
  s.clear();
  assert.deepEqual([Atomics.load(input, IN.JOY_GAS), Atomics.load(input, IN.JOY_BRAKE)], [0, 0]);
});
