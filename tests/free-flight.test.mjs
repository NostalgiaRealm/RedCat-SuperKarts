// node --test tests/free-flight.test.mjs
// Free flight's pieces that need no race (the race itself: tools/checks/flight.mjs and tools/check-flight.mjs):
// the motion and the camera reset against the JS reconstruction's own advanceFreeFlight and NativePlayerCamera.reset
// (../RedCat Superkarts/source/simulation/free-flight.js and native-camera.js, imported read-only), the clock's freeze
// and thaw (source/host/win32.js VirtualClock), and the pad's LB and RB as Space and C only while flying
// (source/input/gamepad.js, the JS port's input.js:152).
import test from 'node:test';
import assert from 'node:assert/strict';
import { FreeFlight, FLIGHT, chaseEye } from '../source/host/free-flight.js';
import { VirtualClock } from '../source/host/win32.js';
import { SharedInput } from '../source/input/shared-input.js';
import { Gamepads } from '../source/input/gamepad.js';
import { IN } from '../source/web/shared.js';
import { haveJs, jsModule } from '../tools/checks/race-handoff-lib.mjs';

test('the flight arc is the JS reconstruction\'s advanceFreeFlight, mirrored tracks included', { skip: !haveJs() && 'no JS reconstruction' }, async () => {
  const js = await jsModule('simulation/free-flight.js');
  assert.deepEqual([FLIGHT.SPEED, FLIGHT.VERTICAL_SPEED, FLIGHT.TURN_SPEED], [js.FREE_FLIGHT_SPEED, js.FREE_FLIGHT_VERTICAL_SPEED, js.FREE_FLIGHT_TURN_SPEED]);
  const unit = 4096 / (Math.PI * 2);
  let seed = 7;
  const rnd = () => { seed = (seed * 1103515245 + 12345) % 2147483648; return seed / 2147483648; };
  for (const mirrored of [false, true]) {
    const ours = { x: -2353.7, y: -0.7, z: 7343.2, yaw: 3.1, mirrored };
    const motion = { body: { position: [ours.x, ours.y, ours.z], yaw: ours.yaw * unit }, mirrored };
    for (let k = 0; k < 400; k++) {
      const input = k % 7 === 0 ? {} : { steer: rnd() * 2.4 - 1.2, throttle: rnd(), brake: rnd() < 0.3 ? rnd() : 0, lift: rnd() * 2 - 1 };
      FreeFlight.prototype.advance.call(ours, input, 0.025);
      js.advanceFreeFlight(motion, input, 0.025);
    }
    const [x, y, z] = motion.body.position;
    assert.ok(Math.abs(ours.x - x) < 1e-6 && Math.abs(ours.y - y) < 1e-6 && Math.abs(ours.z - z) < 1e-6, `${[ours.x, ours.y, ours.z]} vs ${[x, y, z]}`);
    assert.ok(Math.abs(ours.yaw * unit - motion.body.yaw) < 1e-6);
  }
});

test('the camera reset at take-off and landing is the JS reconstruction\'s NativePlayerCamera.reset', { skip: !haveJs() && 'no JS reconstruction' }, async () => {
  const { NativePlayerCamera } = await jsModule('simulation/native-camera.js');
  const { nativeRotationMatrix } = await jsModule('simulation/native-transform.js');
  let seed = 11;
  const rnd = () => { seed = (seed * 1103515245 + 12345) % 2147483648; return seed / 2147483648; };
  for (let k = 0; k < 200; k++) {
    // a driving body (pitch, yaw and roll; take-off) or a level one (landing, restoreFlightPose)
    const angles = k % 2 ? [0, rnd() * 4096, 0] : [rnd() * 200 - 100, rnd() * 4096, rnd() * 200 - 100];
    const matrix = nativeRotationMatrix(angles);
    const position = [rnd() * 16000 - 8000, rnd() * 400 - 100, rnd() * 16000 - 8000].map(Math.fround);
    const js = new NativePlayerCamera().reset({ position, matrix }).position;
    assert.deepEqual(chaseEye(position, matrix.slice(3, 6), matrix.slice(6, 9)), js);
  }
});

test('the game\'s clock stands still while frozen and goes on from there after a thaw; unfrozen it is unchanged', () => {
  const a = new VirtualClock(), b = new VirtualClock();
  a.seconds = b.seconds = 12.345;
  for (let k = 0; k < 40; k++) { a.advance(0.025); b.advance(0.025); }
  assert.equal(a.ms(), b.ms());
  assert.equal(a.ms(), 13345);
  a.freeze();
  const ms = a.ms(), counts = a.counts();
  for (let k = 0; k < 80; k++) a.advance(0.025);
  assert.equal(a.ms(), ms);
  assert.equal(a.counts(), counts);
  assert.equal(a.seconds, 12.345 + 3);             // the raw clock (sound, music) goes on
  a.thaw();
  assert.equal(a.ms(), ms);
  a.advance(0.025);
  assert.equal(a.ms(), ms + 25);
  assert.equal(a.offsetUs, 2000000);
});

test('the pad\'s LB and RB hold Space and C only while flying', () => {
  const input = new Int32Array(new SharedArrayBuffer(IN.SIZE * 4));
  const shared = new SharedInput(input);
  const pad = { id: 'pad', connected: true, mapping: 'standard', axes: [0, 0, 0, 0], buttons: Array.from({ length: 17 }, () => ({ value: 0 })) };
  const nav = Object.getOwnPropertyDescriptor(globalThis, 'navigator');
  Object.defineProperty(globalThis, 'navigator', { value: { getGamepads: () => [pad] }, configurable: true });
  try {
    let flying = false;
    const pads = new Gamepads(shared, () => ({ waiting: false, phase: 0, flying }));
    pad.buttons[4].value = 1;
    pads.poll();
    assert.equal(input[0x20], 0);
    flying = true;
    pads.poll();
    assert.equal(input[0x20], 1);
    pad.buttons[4].value = 0; pad.buttons[5].value = 1;
    pads.poll();
    assert.deepEqual([input[0x20], input[0x43]], [0, 1]);
    flying = false;                                    // the flight ended: let go at the next poll
    pads.poll();
    assert.deepEqual([input[0x20], input[0x43]], [0, 0]);
  } finally {
    if (nav) Object.defineProperty(globalThis, 'navigator', nav); else delete globalThis.navigator;
  }
});
