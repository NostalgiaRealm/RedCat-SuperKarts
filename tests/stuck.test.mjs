// The stuck recovery's pure parts (source/host/stuck.js): the detector and the destination choice are the JS
// reconstruction's (its player-stuck-recovery.js, player-recovery-position.js); these are its rules, on a stand-in
// track. The game side is tools/check-safeguards.mjs.
import test from 'node:test';
import assert from 'node:assert/strict';
import { StuckDetector, selectRecoveryDestination, rectanglesOverlap, STUCK_SECONDS } from '../source/host/stuck.js';

const DT = 0.025;
const body = (x, z, extra = {}) => ({ position: [x, 0, z], yaw: 0, sector: 5, waypoint: 5, ...extra });
const race = (extra = {}) => ({ lapCount: 0, distance: 5, finishArmed: false, ...extra });
const GAS = { throttle: 1, brake: 0, handbrake: false };

test('8 s of attempted driving within 60 units fires, on the 320th pass', () => {
  const d = new StuckDetector();
  let fired = -1;
  for (let k = 0; k < 400 && fired < 0; k++) if (d.step(body(k % 2 ? 30 : 0, 0), GAS, DT)) fired = k;
  assert.equal(fired, STUCK_SECONDS / DT - 1);
});

test('moving more than 60 units, idling 0.75 s, the handbrake and both pedals start it again', () => {
  const run = (pose, input, n) => { const d = new StuckDetector(); let f = false; for (let k = 0; k < n; k++) f = d.step(pose(k), input(k), DT) || f; return f; };
  assert.equal(run((k) => body(k < 200 ? 0 : 61, 0), () => GAS, 500), false);          // re-anchored at pass 200
  assert.equal(run(() => body(0, 0), (k) => (k >= 150 && k < 180 ? { throttle: 0 } : GAS), 400), false);
  assert.equal(run(() => body(0, 0), (k) => (k >= 150 && k < 170 ? { throttle: 0 } : GAS), 400), true); // 0.5 s idle: kept
  assert.equal(run(() => body(0, 0), () => ({ ...GAS, handbrake: true }), 400), false);
  assert.equal(run(() => body(0, 0), () => ({ throttle: 1, brake: 1 }), 400), false);
  assert.equal(run(() => body(0, 0), () => ({ throttle: 0, brake: 1 }), 400), true);    // reversing into a wall counts
});

test('anchors: every 100 units, at most 32, dropped on a new lap; retryAfter waits a second', () => {
  const d = new StuckDetector();
  for (let k = 0; k < 50; k++) d.remember(body(0, k * 50), race({ distance: k }), () => true);
  assert.equal(d.anchors.length, 25);
  for (let k = 0; k < 100; k++) d.remember(body(0, 5000 + k * 100), race(), () => true);
  assert.equal(d.anchors.length, 32);
  d.remember(body(0, 0), race({ lapCount: 1, distance: 40 }), () => true);
  assert.deepEqual([d.anchors.length, d.lapStartDistance], [1, 40]);
  while (!d.step(body(0, 0), GAS, DT));                 // fired; no free place: once more a second later
  d.retryAfter();
  let k = 0; while (!d.step(body(0, 0), GAS, DT)) k++;
  assert.equal(k, 1 / DT - 1);
});

// a straight track along +z: 20 sectors of 100 units, waypoint w at z = 50 w (sector floor(w / 2))
const track = {
  routeCount: 20, driveCount: 40,
  validPose: (p) => !!p && p.position.every(Number.isFinite) && Number.isInteger(p.sector) && p.sector >= 0 && p.sector < 20,
  marker: (w) => (w === 6 ? 50 : 0),
  forward: () => [0, 0, 1],
  destinationAtWaypoint: (w) => ({ waypoint: w, sector: Math.floor(w / 2), previousSector: Math.floor(w / 2), position: [0, 0, w * 50], yaw: 0 }),
  isSafe: (p) => !track.blocked.has(p.waypoint),
  blocked: new Set(),
};
const request = (anchors, ref = {}) => ({ anchors, reference: { position: [0, 0, 1000], yaw: 0, sector: 10, waypoint: 20, distance: 10, lapCount: 0, lapStartDistance: 0, finishArmed: false, ...ref } });
const anchor = (z, distance, extra = {}) => ({ position: [0, 0, z], yaw: 0, sector: Math.floor(z / 100), waypoint: Math.floor(z / 50), distance, lapCount: 0, finishArmed: false, ...extra });

test('the newest same-lap anchor that is 80 units back and safe', () => {
  const d = selectRecoveryDestination(track, request([anchor(950, 9), anchor(850, 8, { finishArmed: true }), anchor(500, 5)]));
  assert.deepEqual([d.position[2], d.recoveryDistance, d.recoveryFinishArmed, d.previousSector, d.safetyFallback], [850, 8, true, 8, true]);
  track.blocked.add(17);
  assert.equal(selectRecoveryDestination(track, request([anchor(850, 8), anchor(500, 5)])).position[2], 500);
  track.blocked.clear();
  // ahead of the kart (a later distance), another lap, or before this lap's start: not taken
  assert.equal(selectRecoveryDestination(track, request([anchor(850, 11), anchor(800, 8, { lapCount: 1 }), anchor(700, -1)])).waypoint, 18);
});

test('else the nearest authored waypoint behind, never marker 50, within the lap and half a circuit', () => {
  const d = selectRecoveryDestination(track, request([]));
  // waypoint 19 (sector 9) is 50 units back, below 80: 18, one sector behind, 100 units back
  assert.deepEqual([d.waypoint, d.recoveryDistance, d.recoveryFinishArmed], [18, 10 - 1, false]);
  // 9 sectors back at most (half of 20, less one): sectors 1..9, waypoints 2..19; 6 (marker 50) never
  track.blocked = new Set([2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18]);
  assert.equal(selectRecoveryDestination(track, request([])).blocked, true);
  track.blocked = new Set([2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18]);
  assert.equal(selectRecoveryDestination(track, request([])).waypoint, 7);
  // one sector into the lap: one sector back at most; at its start none (never beyond the lap's start)
  track.blocked = new Set();
  assert.equal(selectRecoveryDestination(track, request([], { distance: 1 })).waypoint, 18);
  assert.equal(selectRecoveryDestination(track, request([], { distance: 0 })).blocked, true);
});

test('reversed past the lap start: a visited pose without progress or a finish, no invented fallback', () => {
  const d = selectRecoveryDestination(track, request([anchor(500, 5, { finishArmed: true })], { distance: -1, lapStartDistance: 0 }));
  assert.deepEqual([d.position[2], d.recoveryDistance, d.recoveryFinishArmed], [500, -1, false]);
  assert.equal(selectRecoveryDestination(track, request([], { distance: -1 })).blocked, true);
});

test('rectangles: SAT with the margin on the first', () => {
  const r = (x, z, angle = 0) => ({ minX: -10, maxX: 10, minZ: -10, maxZ: 10, position: [x, 0, z], angle });
  assert.equal(rectanglesOverlap(r(0, 0), r(19, 0)), true);
  assert.equal(rectanglesOverlap(r(0, 0), r(22, 0)), true);           // 3-unit margin
  assert.equal(rectanglesOverlap(r(0, 0), r(24, 0)), false);
  assert.equal(rectanglesOverlap(r(0, 0), r(26, 0, 512)), true);      // 45 degrees: the corner reaches
});
