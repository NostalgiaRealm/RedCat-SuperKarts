// The six key bindings while a race runs, from the page to the game thread and into the game's own table, and the
// input the stuck recovery reads (source/host/stuck.js). The JS reconstruction looks its bindings up on every key
// press (its input.js:71, bindings() is settings.bindings), so a binding changed in the flight panel's Instellingen
// acts at once; here the race reads its bindings from game.ini [INPUT] once, at boot, so the page publishes them in
// shared memory (CTRL.KEYS.., CTRL.KEYS_SEQ, source/web/shared.js) and the game worker writes them into the game's
// table before the next pass (worker.js host.beforeTick).
//
// The game's table (rcskspel.dat, export of the JS reconstruction's original-source/): 0x42ce10 ("set game input")
// reads game.ini [INPUT] KEY_ACCELERATE, KEY_BRAKE, KEY_STEERLEFT, KEY_STEERRIGHT, KEY_USEBONUS, KEY_HANDBRAKE and
// calls 0x42ec40(left, right, accelerate, brake, bonus, handbrake, 0, 0, sensitivity), which stores its first eight
// arguments at 0x53a5b8..0x53a5d4 (0x42ec83, 0x42ec4c, 0x42ec56, 0x42ec60, 0x42ec6a, 0x42ec74, 0x42ec88, 0x42ec8e)
// and passes each to 0x4bab80(1, slot, key), which keeps a copy at 0x6aba20 + 8 * slot. The only reader of
// 0x53a5b8..0x53a5d4 besides those two setters (and 0x42ed30, which copies them for device 2) is 0x42ee60, the
// keyboard device's poll: 0x4b3880(table[k], mode 0x53a5dc) for k = 0..7, bit k of its result (references.tsv). The
// copy at 0x6aba20 is read only by 0x4baec0, which 0x4b3880 calls for mode bit 1 (the joystick device 2; the
// handoff's CONTROL 0 makes the mode 1). Writing both as 0x42ec40 does makes a new binding the game's own.
import { CTRL, IN } from '../web/shared.js';

export const ACTIONS = Object.freeze(['accelerate', 'brake', 'left', 'right', 'bonus', 'handbrake']);
export const VK_SHIFT = 0x10, VK_ESC = 0x1B, VK_P = 0x50;
/** 0x42ec40's order: table word k of 0x53a5b8 and slot k of 0x4bab80. */
export const TABLE_ORDER = Object.freeze(['left', 'right', 'accelerate', 'brake', 'bonus', 'handbrake']);
export const GAME_KEY_TABLE = 0x53a5b8;
export const LIB_KEY_TABLE = 0x6aba20;

/**
 * A bound key that may drive. P and Esc never drive: the JS reconstruction handles them before it looks up the
 * bindings (its input.js:64-65) and its settings never keep Escape as a binding (its settings.js:18); P can be bound.
 */
export const drivable = (vk) => Number.isInteger(vk) && vk > 0 && vk < 256 && vk !== VK_ESC && vk !== VK_P;

/** The page: the bound virtual keys into CTRL.KEYS.. and, when one changed, CTRL.KEYS_SEQ + 1 (last, after them). */
export function publishKeys(ctrl, keys) {
  let changed = false;
  ACTIONS.forEach((a, k) => {
    const vk = Number.isInteger(keys[a]) && keys[a] >= 0 && keys[a] < 256 ? keys[a] : 0;
    if (Atomics.load(ctrl, CTRL.KEYS + k) !== vk) { Atomics.store(ctrl, CTRL.KEYS + k, vk); changed = true; }
  });
  if (changed) Atomics.add(ctrl, CTRL.KEYS_SEQ, 1);
  return changed;
}

/** The game thread: the keys the page published. */
export function readKeys(ctrl) {
  const keys = {};
  ACTIONS.forEach((a, k) => { keys[a] = Atomics.load(ctrl, CTRL.KEYS + k); });
  return keys;
}

/** The game thread, between two passes: the bindings into the game's table, as 0x42ec40 stores them. */
export function writeGameKeys(m, keys) {
  TABLE_ORDER.forEach((a, k) => {
    const vk = keys[a] | 0;
    m.i32[(GAME_KEY_TABLE + 4 * k) >> 2] = vk;
    m.i32[(LIB_KEY_TABLE + 8 * k) >> 2] = vk;
  });
}

/** The keys in the game's table (for the stats and the checks). */
export function gameKeys(m) {
  const keys = {};
  TABLE_ORDER.forEach((a, k) => { keys[a] = m.i32[(GAME_KEY_TABLE + 4 * k) >> 2]; });
  return keys;
}

/**
 * The stuck recovery's input as the JS reconstruction's step takes it (player-stuck-recovery.js:33-35 reads
 * InputState.snapshot, input.js:43-44): per action the largest of every source, keyboard sources dropped while Shift is
 * held (InputState.value, input.js:34-41, after 0x4b3880, which answers an unmodified binding "up" while Shift is
 * down), P and Esc never; the pad's and the touch wheel's pedals as they are (IN.JOY_GAS, IN.JOY_BRAKE: before the
 * game's ±10% window, gas and brake apart, so both pedals can be told), their handbrake button too.
 * keys: the bindings; down(vk): a key is held; input: the IN words (Int32Array).
 */
export function stuckInput(keys, down, input) {
  const shift = down(VK_SHIFT);
  const key = (vk) => (!shift && drivable(vk) && down(vk) ? 1 : 0);
  return {
    throttle: Math.max(key(keys.accelerate), Atomics.load(input, IN.JOY_GAS) / 1e4),
    brake: Math.max(key(keys.brake), Atomics.load(input, IN.JOY_BRAKE) / 1e4),
    handbrake: key(keys.handbrake) === 1 || (Atomics.load(input, IN.JOY_BUTTONS) & 2) !== 0,
  };
}
