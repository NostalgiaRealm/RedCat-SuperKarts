import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRescueController} from '../source/simulation/native-rescue.js';
import {createNativeTrack} from '../source/simulation/native-track.js';

// tools/native-rescue-queue-fixtures.py executes rcskspel.dat 0x48dce0/0x48dc30
// (cap, duplicate scan), 0x48de90 (insert at begin()), 0x48db00/0x48ca60 and
// 0x48db30 (stale-slot retirement). Every tick is replayed through the port.
const fixture = JSON.parse(fs.readFileSync(new URL('../evidence/native/rescue-queue-fixtures.json', import.meta.url)));
const track = JSON.parse(fs.readFileSync(new URL('../public/assets/tracks/etappe5.json', import.meta.url)));
const world = createNativeTrack(track);
// Etappe 5 has four return markers (marker 51) far apart; environment players
// scan to MARKERS[id % 4], and a blocker there fails 0x48c170's clearance.
const MARKERS = [514, 516, 606, 610];
const ENVIRONMENT = '0x48dce0';
const sorted = values => [...values].sort((a, b) => a - b);

function makeDriver(id, log) {
  const body = {id, position: [id * 100, 0, 0], matrix: [1, 0, 0, 0, 1, 0, 0, 0, 1], yaw: 0,
    verticalSpeed: 0, forwardSpeed: 0, yawRate: 0, pitchRate: 0, rollRate: 0,
    sector: 10 + 5 * id, previousSector: 10 + 5 * id, waypoint: MARKERS[id % 4] - 1};
  // updateNativeRescue's first write is stop(body); the retirement clears the
  // stuck flag. Both are logged to observe the port's actual order.
  let lateral = 0, blocked = false;
  Object.defineProperty(body, 'lateralSpeed', {enumerable: true, get: () => lateral,
    set: value => { if (log.phase === 'update') log.updates.push(id); lateral = value; }});
  const state = {};
  Object.defineProperty(state, 'blockRecovery', {enumerable: true, get: () => blocked,
    set: value => { if (log.phase === 'retire' && !value) log.retired.push(id); blocked = value; }});
  return {body, state};
}

function createReplay() {
  const log = {phase: null, updates: [], retired: [], clearance: []};
  const drivers = new Map(), blockers = [];
  const controller = new NativeRescueController({track, world, occupants: () => {
    // Called once per grow-frame-0 destination; record the environment ones.
    const id = log.updates.at(-1), entry = controller.entries.find(item => item.body.id === id);
    if (entry?.environment) log.clearance.push(id);
    return blockers;
  }});
  const driver = id => {
    if (!drivers.has(id)) drivers.set(id, makeDriver(id, log));
    return drivers.get(id);
  };
  const ids = () => controller.entries.map(entry => entry.body.id);
  return {controller, drivers, tick(spec) {
    const enqueue = (spec.enqueue ?? []).map(([id, entry]) => {
      const d = driver(id), existing = controller.get(d.body), full = controller.entries.length >= 10;
      const returned = controller.enqueue(d, {environment: entry === ENVIRONMENT});
      const inserted = Boolean(returned) && returned !== existing;
      // The cap is tested before the duplicate scan, so a full queue rejects.
      if (!inserted) assert.equal(returned, full ? null : existing ?? null);
      return {player: id, entry, environment: Number(entry === ENVIRONMENT),
        result: inserted ? 'inserted' : full ? 'full' : 'duplicate'};
    });
    for (const id of spec.finish ?? []) Object.assign(controller.get(driver(id).body), {frame: 19, shrinking: false});
    const queue = ids();
    blockers.length = 0;
    for (const id of spec.blocked ?? []) blockers.push({id: -1 - id, position: [...track.drive[MARKERS[id % 4]].position]});
    Object.assign(log, {phase: 'update', updates: [], clearance: []});
    controller.step(fixture.deltaSeconds);
    const updates = log.updates, clearance = log.clearance;
    const state = controller.entries.map(entry => [entry.body.id, entry.frame, Number(entry.shrinking), Number(entry.finished)]);
    Object.assign(log, {phase: 'retire', retired: []});
    controller.finishRender();
    log.phase = null;
    const flags = sorted([...drivers].filter(([, d]) => d.state.blockRecovery).map(([id]) => id));
    return {enqueue, queue, updates, clearance, state, retired: log.retired, after: ids(), flags};
  }};
}

/** Exact comparison, except the approved retirement exception on a drop tick. */
function compareTick(port, native, label) {
  assert.deepEqual(port.enqueue, native.enqueue, `${label} enqueue`);
  assert.deepEqual(port.queue, native.queue, `${label} queue order (insert at begin())`);
  assert.deepEqual(native.renders, native.state.map(([id]) => id), `${label} native render order`);
  assert.deepEqual(port.updates, native.updates, `${label} update order`);
  assert.deepEqual(port.clearance, native.clearance.map(([id]) => id), `${label} 0x48c170 order`);
  assert.deepEqual(port.state, native.state, `${label} per-entry frame/phase/finished`);
  assert.deepEqual(port.retired, native.retired, `${label} stuck-flag clear order`);
  assert.deepEqual(port.flags, native.flags, `${label} stuck flags`);
  if (!native.dropped.length) {
    assert.deepEqual(port.after, native.after, `${label} retired queue`);
    return false;
  }
  // 0x48db30 copied back() over a stale finished slot that held another entry
  // and popped it: the native drops that entry (its flag stays set) and keeps
  // the finished one a tick longer. The port retires the stale slot's own entry.
  const unfinished = new Set(native.state.filter(([, , , finished]) => !finished).map(([id]) => id));
  assert.deepEqual(sorted(port.after), sorted(unfinished), `${label} port keeps exactly the unfinished rescues`);
  for (const id of native.dropped.filter(id => unfinished.has(id))) assert.ok(port.after.includes(id), `${label} keeps ${id}`);
  assert.ok(native.after.some(id => !unfinished.has(id)), `${label} native kept a finished slot`);
  const kept = new Set(native.after.filter(id => unfinished.has(id)));
  assert.deepEqual(port.after.filter(id => kept.has(id)), native.after.filter(id => kept.has(id)), `${label} relative order`);
  return true;
}

function replay(sequence) {
  const run = createReplay();
  let dropTick = -1;
  sequence.ticks.forEach((spec, tick) => {
    const port = run.tick(spec);
    if (dropTick < 0 && compareTick(port, sequence.trace[tick], `${sequence.name} tick ${tick}`)) dropTick = tick;
  });
  return {dropTick, run};
}

test('fixture executed the queue at both x87 precisions with full coverage', () => {
  assert.deepEqual(fixture.precisions, [24, 53]);
  assert.equal(fixture.identicalAcrossPrecisions, true);
  const ticks = [...fixture.natural, ...fixture.retirementMatrix].flatMap(sequence => sequence.trace);
  const results = ticks.flatMap(tick => tick.enqueue.map(item => item.result));
  for (const result of ['inserted', 'duplicate', 'full']) assert.ok(results.includes(result), result);
  assert.ok(ticks.some(tick => tick.enqueue.filter(item => item.result === 'inserted').length > 0 &&
    tick.enqueue.length > 10), 'more than ten enqueues in one tick');
  assert.ok(ticks.some(tick => tick.retired.length >= 10), 'ten finishing on one tick');
  const natural = fixture.natural.flatMap(sequence => sequence.trace);
  const finishedAt = tick => tick.state.flatMap(([, , , finished], slot) => finished ? [slot] : []);
  assert.ok(natural.some(tick => finishedAt(tick)[0] === 0 && tick.state.length > 1), 'finished at front');
  assert.ok(natural.some(tick => finishedAt(tick).some(slot => slot > 0 && slot < tick.state.length - 1)), 'finished in middle');
  assert.ok(natural.some(tick => finishedAt(tick).includes(tick.state.length - 1)), 'finished at end');
  assert.ok(ticks.some(tick => tick.visits.some(([, , stale]) => stale)), 'stale slot retirement');
  assert.deepEqual(fixture.summary.naturalDrops, ['blocked-front-and-end-drop-live']);
  // Exhaustive finished patterns for queue sizes 1..10.
  assert.equal(fixture.retirementMatrix.length, Array.from({length: 10}, (_, n) => 2 ** (n + 1) - 1).reduce((a, b) => a + b));
});

test('natural native enqueue/update/retire sequences replay exactly through NativeRescueController', () => {
  for (const sequence of fixture.natural) {
    const {dropTick, run} = replay(sequence);
    if (sequence.name !== 'blocked-front-and-end-drop-live') {
      assert.equal(dropTick, -1, sequence.name);
      continue;
    }
    // Native: player 1 is dropped at tick 41 with its stuck flag left set
    // forever, and finished player 2 is updated once more (0x48ca60 does not
    // test +0x11a0) before retiring at tick 42.
    const native = sequence.trace;
    assert.equal(dropTick, 41);
    assert.deepEqual(native[41].dropped, [1]);
    assert.deepEqual(native[42].state, [[2, 1, 1, 1]]);
    assert.deepEqual(native.at(-1).flags, [1]);
    // Port: the unfinished rescue keeps running and retires with its flag cleared.
    assert.deepEqual(run.controller.entries, []);
    assert.equal(run.drivers.get(1).state.blockRecovery, false);
  }
});

test('all 2036 native retirement patterns (1..10 entries) match, except the approved drop exception', () => {
  let exact = 0, drops = 0;
  for (const sequence of fixture.retirementMatrix) {
    const {dropTick} = replay(sequence);
    if (dropTick < 0) exact++;
    else drops++;
  }
  assert.equal(exact + drops, fixture.retirementMatrix.length);
  assert.equal(drops, fixture.summary.sequencesWithDrops - fixture.summary.naturalDrops.length);
});
