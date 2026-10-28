import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { NativeGameTimers, NATIVE_PAUSED_TIMER_IDS, resetNativeInactivePlayer, nativeRaceTimerSetup } from '../source/simulation/native-game-timers.js';
import { parseRacerTable } from '../source/simulation/native-tables.js';
const fixtures = JSON.parse(readFileSync(new URL('../evidence/native/game-timer-fixtures.json', import.meta.url)));

test('2880 original timer operations preserve pause, reset, limit, sentinel and uint32 wrap behavior', () => {
  for (const [caseIndex, c] of fixtures.timers.entries()) {
    const bank = new NativeGameTimers();
    bank.initialize(c.index, c.limitMs, c.countdown);
    for (const [step, sample] of c.trace.entries()) {
      if (sample.operation === 'setLimit') bank.setLimit(c.index, sample.value, sample.nowMs);
      else if (sample.operation !== 'read') bank[sample.operation](c.index, sample.nowMs);
      assert.deepEqual(bank.get(c.index), sample.state, `${caseIndex}/${step} state`);
      assert.equal(bank.read(c.index, sample.nowMs), sample.read, `${caseIndex}/${step} read`);
      assert.equal(bank.expired(c.index, sample.nowMs), sample.expired, `${caseIndex}/${step} expiry`);
    }
  }
});

test('80 original inactive-player reset blocks retain angular pitch/roll rates and input state', () => {
  for (const c of fixtures.inactive) {
    const controls = { steering: 30, throttle: 20, brake: 7, handbrake: true };
    const motion = { body: { ...c.body }, rpm: c.rpm, lowSpeedTurn: c.lowSpeedTurn, controls };
    resetNativeInactivePlayer(motion);
    assert.deepEqual(motion, { ...c.expected, controls });
    assert.equal(motion.controls, controls);
  }
});

test('Native game pause excludes pause duration only from the original timer list', () => {
  const bank = new NativeGameTimers();
  for (let index = 0; index < 28; index++) { bank.initialize(index, 100000); bank.start(index, 1000); }
  bank.pauseGame(2000);
  bank.resumeGame(12000);
  for (let index = 0; index < 28; index++) {
    assert.equal(bank.read(index, 13000), NATIVE_PAUSED_TIMER_IDS.includes(index) ? 2000 : 12000);
  }
});

test('0x42a420 game resume clears an earlier pause; host suspensions leave it in place', () => {
  const create = () => {
    const bank = new NativeGameTimers();
    for (const index of [0, 3]) { bank.initialize(index, 100000); bank.start(index, 1000); }
    bank.pause(0, 5000); // 0x440d70 at the finish.
    return bank;
  };
  const native = create();
  native.pauseGame(6000);
  native.resumeGame(9000);
  // The finish pause ends: timer0 continues from its frozen 4000 ms.
  assert.equal(native.read(0, 10000), 5000);
  assert.equal(native.get(0).pausedAtMs, 0);
  const host = create();
  const paused = host.pauseHost(6000);
  assert.deepEqual(paused, [3]);
  host.resumeTimers(paused, 9000);
  assert.equal(host.read(0, 10000), 4000);
  assert.equal(host.get(0).pausedAtMs, 5000);
  assert.equal(host.read(3, 10000), 6000);
});

test('576 complete original race timer initializations and green-light resets match at both precisions', () => {
  const config = JSON.parse(readFileSync(new URL('../public/assets/config.json', import.meta.url)));
  const tables = [0, 1, 2].map(index => parseRacerTable(readFileSync(
    new URL(`../public/assets/racer-tables/cars${index}.dat`, import.meta.url))));
  assert.equal(fixtures.setup.length, 576);
  for (const [i, c] of fixtures.setup.entries()) {
    const bank = nativeRaceTimerSetup({ ...c, config, playerRacer: tables[c.difficulty][c.character] });
    assert.deepEqual(bank.timers, c.initialized, `initialize ${i}`);
    bank.startRace(12345, c);
    assert.deepEqual(bank.timers, c.started, `green ${i}`);
  }
});
