// Player stuck recovery: the JS reconstruction's port safeguard (its docs/player-stuck-recovery.md; source/simulation/
// player-stuck-recovery.js, player-recovery-position.js, rescue-safety.js, native-rescue.js:104-286 and
// source/race-simulation.js:347-379, 481-494, 582-587), put around the original's own rescue. Not original behaviour
// (docs/intentional-differences.md). Eight seconds of attempted driving within 60 units starts the original rescue
// (queue 0x48dce0, update 0x48ca60: shrink, DISAPP/REAPP, rings, grow) with the JS port's destination: a safe road pose
// the kart drove through on this lap, else an authored waypoint behind it.
//
// How it sits in the original (rcskspel.dat, export of the JS reconstruction's original-source/):
//   - beforePass() runs before every pass of WinMain's loop (race.js tick), so it sees the pose the last pass left, as
//     the JS port's step sees the pose of its previous integration (race-simulation.js:347-379).
//   - the rescue is queued with the original 0x48dce0 (thiscall on the manager 0x48da90, args body, flag; RET 8). Its
//     flag byte (entry +0x11ac, written only by 0x48c9a0 at 0x48ca4a and read only by 0x48ca60 at 0x48ccbd, where it
//     picks the destination branch) carries the marker 0x80 instead of the original's 0 or 1.
//   - hook!RescueUpdate wraps 0x48ca60 (thiscall, ECX = entry, called only from 0x48db00 at 0x48db19). For a marked
//     entry at grow frame 0 (+0x1198 = 0, +0x1194 = 0) this module runs that one call: the destination branch (the
//     original's 0x493430/0x48d930 or 0x48bf80/0x48c170) is replaced by the JS port's, the rest is the original's glue
//     (0x48ca60: velocities 0, the blocked branch, the grow table 0x67da70, frame + 1, the rings 0x48d610). Every other
//     call runs the original body; after it, a marked entry that finished gets forward speed 0 instead of 5.0
//     (0x48d2fb) and no rates, and is shrunk again when its place is taken (native-rescue.js:176-177, 274-286).
// Layout (asm of 0x48ca60, 0x48c9a0, 0x430ff0, 0x4325b0): body u32[0x67ee20] + i*0xd0 (+0xc render object, +0x1c sector,
// +0x20 previous sector, +0x24 waypoint, +0x9c/+0xa0/+0xa4 lateral/vertical/forward speed, +0xa8/+0xac/+0xb0 pitch/yaw/
// roll rate); render object u32[0x6a5c38] + i*0xa9 (+0x10 matrix, +0x50 position, +0x74 pitch, +0x78 yaw, +0x7c roll);
// rescue entry (0x11b0 bytes, vector at [[0x67e4d0]+4]+4): +0x1180 body, +0x1194 frame, +0x1198 shrinking, +0x11a0
// finished, +0x11ac flag.
//
// Differences from the JS port (docs/intentional-differences.md, Stuck recovery): the overlapping pickups are not
// excluded after the return (hook!BonusPickUp, 0x4514e0, is too late: 0x4540c0 plays the pickup sounds after it; the
// place that would skip them as the JS port's `continue` does, native-bonus.js:274, is the overlap test 0x44fc80
// (thiscall, RET 4) at its call 0x454160 in 0x4540c0's racer loop, answered "no" for the player: not wrapped yet, and
// 0x455a10 calls it too, at 0x455abf), and the
// wheels are seated anew by the original's own first-use code (0x416650 with 0x507f48 cleared) on the next pass, where
// the JS port puts them on the ground at once.

const f32 = Math.fround;
export const STUCK_SECONDS = 8;            // player-stuck-recovery.js:4
export const STUCK_RADIUS = 60;            // :5 (planar, :6)
export const RECOVERY_MIN_DISTANCE = 80;   // player-recovery-position.js:7
export const RECOVERY_EXITS = Object.freeze([0, 10, 20, 30]); // :8
export const MARKER = 0x80;                // entry +0x11ac for a rescue this module started
const ROAD = 1;                            // 0x495fe0's kind for its first face list: the JS port's 'road' (native-track.js:191)
const MARKER_DANGER = 50;                  // waypoint +4: 0x32, the environment rescue's marker (0x48c030)
const separation = (a, b) => Math.hypot(a[0] - b[0], a[2] - b[2]);

// 0x4ac410's 4096-entry table as the JS port builds it (native-integrator.js:7-12)
const TWO_PI = f32(2 * Math.PI);
export const SIN = Float32Array.from({ length: 4096 }, (_, i) => Math.sin((i / 4096) * TWO_PI));
export const COS = Float32Array.from({ length: 4096 }, (_, i) => Math.cos((i / 4096) * TWO_PI));
const awayFromZero = (yaw) => (yaw > 0 ? Math.ceil(yaw) : Math.floor(yaw));

/** player-stuck-recovery.js:8-66, unchanged: when attempted driving has gone 8 s within 60 units. */
export class StuckDetector {
  constructor() {
    this.anchors = []; this.lapCount = 0; this.lapStartDistance = 0;
    this.recoveries = 0; this.lastRecovery = null; this.reset();
  }
  reset() { this.origin = null; this.attemptSeconds = 0; this.idleSeconds = 0; }
  observeLap(race) {
    if (race.lapCount !== this.lapCount) {
      this.lapCount = race.lapCount; this.lapStartDistance = race.distance;
      this.anchors = []; this.reset();
    }
  }
  /** pose: { position, yaw, sector, waypoint }; race: { distance, lapCount, finishArmed } */
  remember(body, race, isSafe) {
    this.observeLap(race);
    const previous = this.anchors[0];
    // only travelled, separated road poses: a trapped pose cannot overwrite the history by lasting (:22-23)
    if (previous && separation(previous.position, body.position) < 100) return;
    const pose = { position: [...body.position], yaw: body.yaw, sector: body.sector, previousSector: body.sector,
      waypoint: body.waypoint, distance: race.distance, lapCount: race.lapCount, finishArmed: race.finishArmed };
    if (!isSafe(pose)) return;
    this.anchors.unshift(pose); this.anchors.length = Math.min(this.anchors.length, 32);
  }
  /** input: { throttle, brake, handbrake } (0..1, the analog's when a pad or the wheel drives: :33) */
  step(body, input, dt, { eligible = true } = {}) {
    const throttle = input.throttle ?? 0, brake = input.brake ?? 0;
    const driving = Math.abs(throttle - brake) >= 0.2 && !(throttle > 0.1 && brake > 0.1) && !input.handbrake;
    if (!eligible || !body.position.every(Number.isFinite) || !(dt > 0 && dt <= f32(0.1))) { this.reset(); return false; }
    if (!driving) {
      this.idleSeconds += dt;
      if (this.idleSeconds >= 0.75) this.reset();
      return false;
    }
    this.idleSeconds = 0;
    if (!this.origin || separation(this.origin, body.position) > STUCK_RADIUS) { this.origin = [...body.position]; this.attemptSeconds = 0; }
    this.attemptSeconds += dt;
    return this.attemptSeconds + 1e-9 >= STUCK_SECONDS;
  }
  request(body, race) {
    const reference = { position: [...body.position], yaw: body.yaw, sector: body.sector, waypoint: body.waypoint,
      distance: race.distance, lapCount: race.lapCount, lapStartDistance: this.lapStartDistance, finishArmed: race.finishArmed };
    return { anchors: this.anchors.map((pose) => ({ ...pose, position: [...pose.position] })), reference };
  }
  started(recovery) { this.recoveries++; this.lastRecovery = { reason: 'blocked-driving', reference: recovery.reference }; this.reset(); }
  // a temporarily occupied track is checked again once per second of attempted driving (:61-65)
  retryAfter() { this.attemptSeconds = STUCK_SECONDS - 1; }
}

/**
 * player-recovery-position.js:126-176 selectPlayerRecoveryDestination, unchanged, over `track` (GameTrack below, or a
 * stand-in in tests): a same-lap anchor that is not ahead and 80 units away, else an authored waypoint behind the kart.
 */
export function selectRecoveryDestination(track, recovery) {
  const reference = recovery?.reference;
  if (!track.validPose(reference) || !Number.isInteger(reference.lapCount) || reference.lapCount < 0
    || !Number.isFinite(reference.distance) || !Number.isFinite(reference.lapStartDistance)) return { blocked: true };
  const reversedBeforeStart = reference.distance < reference.lapStartDistance;
  const planar = (pose) => Math.hypot(pose.position[0] - reference.position[0], pose.position[2] - reference.position[2]);
  const safe = (pose) => planar(pose) >= RECOVERY_MIN_DISTANCE && track.isSafe(pose);
  const notAhead = (pose) => {
    if (pose.sector !== reference.sector) return true;
    const forward = track.forward(reference.sector);
    return (pose.position[0] - reference.position[0]) * forward[0] + (pose.position[2] - reference.position[2]) * forward[2] <= 0;
  };
  const result = (pose, distance, finishArmed) => ({ ...pose, position: [...pose.position], previousSector: pose.sector,
    safetyFallback: true, recoveryDistance: distance, recoveryFinishArmed: Boolean(finishArmed) });
  for (const anchor of recovery.anchors ?? []) {
    if (!track.validPose(anchor) || anchor.lapCount !== reference.lapCount || !Number.isFinite(anchor.distance)) continue;
    if (reversedBeforeStart) {
      // reversing past this lap's start can put every known pose ahead: a visited one, without progress or a finish
      if (safe(anchor)) {
        const ahead = anchor.distance > reference.distance || !notAhead(anchor);
        return result(anchor, Math.min(reference.distance, anchor.distance), !ahead && anchor.finishArmed);
      }
      continue;
    }
    if (anchor.distance < reference.lapStartDistance || anchor.distance > reference.distance) continue;
    if (notAhead(anchor) && safe(anchor)) return result(anchor, anchor.distance, anchor.finishArmed);
  }
  if (reversedBeforeStart) return { blocked: true };
  // the nearest sectors first, within this lap and below half a circuit (Italy 17/18 need more than twelve)
  const count = track.routeCount;
  const maxBehind = Math.min(Math.floor((count - 1) / 2), Math.floor(reference.distance - reference.lapStartDistance));
  const candidates = [];
  for (let waypoint = 0; waypoint < track.driveCount; waypoint++) {
    if (track.marker(waypoint) === MARKER_DANGER) continue;
    let pose;
    try { pose = track.destinationAtWaypoint(waypoint); } catch { continue; }
    const behind = (reference.sector - pose.sector + count) % count;
    if (behind > maxBehind || !track.validPose(pose)) continue;
    candidates.push({ pose, behind, distance: planar(pose) });
  }
  candidates.sort((a, b) => a.behind - b.behind || a.distance - b.distance || a.pose.waypoint - b.pose.waypoint);
  for (const { pose, behind } of candidates) if (notAhead(pose) && safe(pose)) return result(pose, reference.distance - behind, false);
  return { blocked: true };
}

/** rescue-safety.js:6-23: SAT of two yawed rectangles, the first grown by `margin`. */
function corners(rect, margin = 0) {
  const a = rect.angle & 4095, s = SIN[a], c = COS[a];
  return [[rect.minX - margin, rect.minZ - margin], [rect.maxX + margin, rect.minZ - margin],
    [rect.maxX + margin, rect.maxZ + margin], [rect.minX - margin, rect.maxZ + margin]]
    .map(([x, z]) => [rect.position[0] + c * x - s * z, rect.position[2] + s * x + c * z]);
}
export function rectanglesOverlap(first, second, margin = 3) {
  const a = corners(first, margin), b = corners(second);
  for (const polygon of [a, b]) for (let i = 0; i < 2; i++) {
    const p = polygon[i], q = polygon[i + 1], ax = p[1] - q[1], az = q[0] - p[0];
    let minA = Infinity, maxA = -Infinity, minB = Infinity, maxB = -Infinity;
    for (const [x, z] of a) { const v = x * ax + z * az; if (v < minA) minA = v; if (v > maxA) maxA = v; }
    for (const [x, z] of b) { const v = x * ax + z * az; if (v < minB) minB = v; if (v > maxB) maxB = v; }
    if (maxA < minB || maxB < minA) return false;
  }
  return true;
}

// Render objects have a stride of 0xa9 bytes: their fields are read and written through the DataView, never f32[a >> 2].
const getF = (m, a) => m.view.getFloat32(a, true);
const setF = (m, a, v) => m.view.setFloat32(a, v, true);
const bitsView = new DataView(new ArrayBuffer(4));
const bits = (x) => { bitsView.setFloat32(0, x, true); return bitsView.getUint32(0, true); };

/**
 * The track and the karts as the JS port's selection sees them (its track.route/drive, world.sectors,
 * sampleNativeTrack and NativeRailCollision.candidates), read from game memory and asked of the original's own
 * routines: the nearest sector 0x450500, the heading 0x493540, the sector search 0x4977d0, the face 0x495fe0 and its
 * height 0x496290 (as 0x430ff0 calls them, 0x431044-0x4310a1), the rails of 0x4997f0 and the bodies of 0x499630 in the
 * order 0x499b20 collects them. None of these writes game state but 0x493540 (the kart's yaw, put back at once).
 */
export class GameTrack {
  constructor(m, me, scratch) {
    this.m = m;
    this.me = me;
    this.scratch = scratch;                  // 32 bytes of host memory for the routines' arguments and results
    this.routeCount = m.i32[0x680b2c >> 2] + 1;   // records 0..[0x680b2c] (0x493540's range check)
    this.driveCount = m.i32[0x680ae4 >> 2];       // 0x48bf80 scans [0x680ae4] waypoints
    this.forwards = new Map();
    this.destinations = new Map();
    const body = this.body(me);
    this.bounds = this.boundsOf(body);
    this.ignoreRails = m.i32[(body + 0x48) >> 2] !== 0;   // 0x499b20 skips the rails for such a body
  }

  body(i) { return this.m.u32[0x67ee20 >> 2] + i * 0xd0; }
  ro(i) { const m = this.m; return m.u32[0x6a5c38 >> 2] + m.i32[(this.body(i) + 0xc) >> 2] * 0xa9; }
  record(sector) { return this.m.u32[0x680b28 >> 2] + sector * 0x984; }
  drive(wp) { return this.m.u32[0x680ae0 >> 2] + wp * 0x50; }
  marker(wp) { return this.m.i32[(this.drive(wp) + 4) >> 2]; }
  vec(p) { const m = this.m; return [getF(m, p), getF(m, p + 4), getF(m, p + 8)]; }

  validPose(pose) {
    return Array.isArray(pose?.position) && pose.position.length === 3 && pose.position.every(Number.isFinite)
      && Number.isFinite(pose.yaw) && Number.isInteger(pose.sector) && pose.sector >= 0 && pose.sector < this.routeCount
      && Number.isInteger(pose.waypoint) && pose.waypoint >= 0 && pose.waypoint < this.driveCount;
  }

  /** world.sectors[s].forward of the JS port (native-track.js:121): toward the next record; the last copies the one before. */
  forward(sector) {
    let f = this.forwards.get(sector);
    if (!f) {
      const n = this.routeCount, s = sector === n - 1 && n > 1 ? n - 2 : sector;
      const a = this.vec(this.record(s) + 0x24), b = this.vec(this.record((s + 1) % n) + 0x24);
      const d = [b[0] - a[0], b[1] - a[1], b[2] - a[2]], l = Math.hypot(d[0], d[1], d[2]) || 1;
      f = [d[0] / l, d[1] / l, d[2] / l];
      this.forwards.set(sector, f);
    }
    return f;
  }

  /** The ground under (x, z) from a sector hint, as 0x430ff0 finds it: { sector, kind, height }. */
  ground(hint, x, y, z) {
    const m = this.m, out = this.scratch;
    const sector = m.call(0x4977d0, [hint, bits(x), bits(y), bits(z)], 0x680218);
    const rec = this.record(sector);
    m.call(0x495fe0, [bits(x), bits(y), bits(z), out, out + 4, out + 8], rec);
    const kind = m.i32[(out + 4) >> 2], index = m.i32[(out + 8) >> 2];
    m.call(0x496290, [bits(x), bits(y), bits(z), kind >>> 0, index >>> 0], rec);
    return { sector, kind, height: m.gSt0.value };
  }

  /** nativeRescueDestinationAtWaypoint (player-recovery-position.js:30-37): the original success branch's pose for wp. */
  destinationAtWaypoint(wp) {
    let d = this.destinations.get(wp);
    if (d) return d;
    const m = this.m, out = this.scratch + 16;
    const position = this.vec(this.drive(wp) + 8);
    m.f32[out >> 2] = position[0]; m.f32[(out + 4) >> 2] = position[1]; m.f32[(out + 8) >> 2] = position[2];
    const previousSector = m.call(0x450500, [out]);            // 0x450690's nearest sector
    const ground = this.ground(previousSector, ...position);   // 0x430ff0 from that hint
    // 0x493540(body, sector, 1) writes the heading into the kart's yaw: asked for, then put back
    const yawAt = this.ro(this.me) + 0x78, saved = m.view.getUint32(yawAt, true);
    m.call(0x493540, [this.me, previousSector, 1]);
    const yaw = getF(m, yawAt);
    m.view.setUint32(yawAt, saved, true);
    d = { waypoint: wp, sector: ground.sector, previousSector, position: [position[0], f32(ground.height), position[2]], yaw };
    this.destinations.set(wp, d);
    return d;
  }

  /** A body's rectangle from its mesh's box (0x490ce0, the box record u32[0x6a5ee0] + mesh*0xbc as 0x499630 reads it). */
  boundsOf(body) {
    const m = this.m, box = m.u32[0x6a5ee0 >> 2] + m.call(0x490ce0, [], body) * 0xbc;
    const xs = [], zs = [];
    for (const o of [0x10, 0x1c, 0x4c, 0x40]) { xs.push(getF(m, box + o)); zs.push(getF(m, box + o + 8)); }
    return { minX: Math.min(...xs), maxX: Math.max(...xs), minZ: Math.min(...zs), maxZ: Math.max(...zs) };
  }

  /** NativeRailCollision.candidates (native-collision.js:180-195) as 0x499b20 builds its list for the player. */
  candidates(sector) {
    const m = this.m, i32 = m.i32, out = [];
    const wrapN = i32[0x680b2c >> 2];                          // 0x493a20 wraps by [0x680b2c]
    const wrap = (s) => (s >= wrapN ? s - wrapN : s < 0 ? wrapN + s : s);
    if (!this.ignoreRails) {
      const rails = m.u32[0x6a5be8 >> 2];
      for (let d = -1; d <= 1; d++) {
        const rec = this.record(wrap(sector + d)), n = i32[(rec + 0xe0) >> 2];
        for (let k = 0; k < n; k++) {
          const rail = rails + i32[(rec + 0xf4 + k * 4) >> 2] * 0x60;   // 0x4997f0: (-10, -1)..(0, length + 1)
          out.push({ minX: -10, maxX: 0, minZ: -1, maxZ: f32(getF(m, rail + 0x5c) + 1), position: this.vec(rail), angle: awayFromZero(getF(m, rail + 0x18)) });
        }
      }
    }
    const me = this.me, myBody = this.body(me), n = this.routeCount;
    for (let p = 0x67ee78; p < 0x67fe1c; p += 8) {
      const b = i32[(p + 4) >> 2];
      if (!m.u32[p >> 2] || b === me || b === i32[(myBody + 0x2c) >> 2] || b === i32[(myBody + 0x30) >> 2]) continue;
      const body = this.body(b);
      if (m.u8[body + 4] & 8 || !i32[(body + 0x44) >> 2]) continue;
      const diff = Math.abs(sector - i32[(body + 0x1c) >> 2]);
      if (Math.min(diff, n - diff) >= 10) continue;
      const ro = this.ro(b);
      // 0x490ce0 stops the game on a render object of another type than 1 or 2 (0x4afee0): such a body is left out
      const type = m.view.getInt32(ro, true);
      if (type !== 1 && type !== 2) continue;
      out.push({ ...this.boundsOf(body), position: this.vec(ro + 0x50), angle: awayFromZero(getF(m, ro + 0x78)) });
    }
    return out;
  }

  /** rescuePlacementClear (rescue-safety.js:25-32): the kart's rectangle, 3 units larger, against rails and bodies. */
  placementClear(pose) {
    const moving = { ...this.bounds, position: pose.position, angle: awayFromZero(pose.yaw) };
    return this.candidates(pose.sector).every((obstacle) => !rectanglesOverlap(moving, obstacle));
  }

  /** isSafePlayerRecoveryPose (player-recovery-position.js:55-82): road under a short exit and the whole footprint. */
  isSafe(pose) {
    if (!this.validPose(pose) || this.marker(pose.waypoint) === MARKER_DANGER) return false;
    const b = this.bounds, a = Math.floor(pose.yaw) & 4095, fa = awayFromZero(pose.yaw) & 4095;
    const supported = (g, y) => g.kind === ROAD && Number.isFinite(g.height) && Math.abs(g.height - y) < 25;
    for (const distance of RECOVERY_EXITS) {
      const position = [pose.position[0] - SIN[a] * distance, pose.position[1], pose.position[2] + COS[a] * distance];
      const ground = this.ground(pose.sector, ...position);
      if (!supported(ground, position[1])) return false;
      // the broad phase depends on the sector: never a stale hint, also when the exit crosses a boundary
      if (distance === 0 && ground.sector !== pose.sector) return false;
      if (!this.placementClear({ ...pose, position, sector: ground.sector })) return false;
      for (const [x, z] of [[b.minX, b.minZ], [b.maxX, b.minZ], [b.maxX, b.maxZ], [b.minX, b.maxZ]]) {
        const cx = position[0] + COS[fa] * x - SIN[fa] * z, cz = position[2] + SIN[fa] * x + COS[fa] * z;
        if (!supported(this.ground(ground.sector, cx, position[1], cz), position[1])) return false;
      }
    }
    return true;
  }
}

/**
 * Installs the recovery on a Race's machine. host.driveInput() gives the player's input for the pass ({ throttle,
 * brake, handbrake }; the game worker reads it from shared memory, tools/checks/full-race-gaps-lib.mjs from its keys);
 * without it the recovery stays off. host.flightActive: free flight flies (free-flight.js). Returns { beforePass(paused),
 * stats, detector }.
 */
export function installStuck(m, host, { dt = 0.025 } = {}) {
  const { u8, i32, u32, f32: F } = m;
  const scratch = m.lowAlloc(32);
  const detector = new StuckDetector();
  const requests = new Map();                 // body -> the request of the rescue this module queued for it
  const stats = { started: 0, relocated: 0, blocked: 0, recheck: 0, last: null };
  const me = () => i32[0x53be28 >> 2];
  const bodyOf = (i) => u32[0x67ee20 >> 2] + i * 0xd0;
  const roOf = (i) => u32[0x6a5c38 >> 2] + i32[(bodyOf(i) + 0xc) >> 2] * 0xa9;
  const stop = (body) => { F[(body + 0x9c) >> 2] = 0; F[(body + 0xa0) >> 2] = 0; F[(body + 0xa4) >> 2] = 0; };
  /** The rescue entries (0x48db00 walks begin..size()): the address of `who`'s, or 0. */
  const entryOf = (who) => {
    const mgr = u32[0x67e4d0 >> 2];
    if (!mgr) return 0;
    const vec = u32[(mgr + 4) >> 2], begin = u32[(vec + 4) >> 2], end = u32[(vec + 8) >> 2];
    for (let e = begin; e && e < end; e += 0x11b0) if (i32[(e + 0x1180) >> 2] === who) return e;
    return 0;
  };
  /** The player's pose and the race's lap state (JS body + race). */
  const read = (i) => {
    const body = bodyOf(i), ro = roOf(i);
    return {
      body: { position: [getF(m, ro + 0x50), getF(m, ro + 0x54), getF(m, ro + 0x58)], yaw: getF(m, ro + 0x78),
        sector: i32[(body + 0x1c) >> 2], waypoint: i32[(body + 0x24) >> 2] },
      // laps i32[0x53ba18] (0x440c30); distance i32[0x53be70], summed by 0x4325b0 as the JS race.distance; finish armed
      // i32[0x53d1d8] (trigger 15's 0x440e40 sets it, 0x440dd0 clears it)
      race: { lapCount: i32[0x53ba18 >> 2], distance: i32[0x53be70 >> 2], finishArmed: i32[0x53d1d8 >> 2] !== 0 },
    };
  };
  /** playerRecoveryEligible (race-simulation.js:582-587) on game state. */
  const eligible = (i) => {
    if (!u32[0x53b9e0 >> 2] || !u32[0x53be54 >> 2] || u32[0x53b9c0 >> 2] !== 0 || !u32[0x53b9bc >> 2]
      || i32[0x53be50 >> 2] !== 0 || host.flightActive || entryOf(i)) return false;
    const hit = u32[0x53bee8 >> 2];                       // +0x11c: set by 0x435aa0, cleared by 0x4359a0
    if (hit && u8[hit + 0x11c]) return false;
    const sq = u32[0x67e4d8 >> 2];                         // squash entries of 0x1c bytes, count [+0x380] (0x48e970)
    if (sq) for (let k = 0, n = i32[(sq + 0x380) >> 2]; k < n; k++) if (i32[(sq + k * 0x1c) >> 2] === i && u8[sq + k * 0x1c + 0x11]) return false;
    // 0x416650 counts the grounded wheels of the player's slot i32[0x508610] into 0x50815c
    return i32[(0x50815c + i32[0x508610 >> 2] * 4) >> 2] > 0 || Math.abs(F[(bodyOf(i) + 0xa0) >> 2]) < 1;
  };

  /** The JS port's relocation (native-rescue.js:136-166, race-simulation.js:481-494) on the original's fields. */
  const relocate = (i, d) => {
    const body = bodyOf(i), ro = roOf(i), slot = i32[0x508610 >> 2];
    setF(m, ro + 0x50, d.position[0]); setF(m, ro + 0x54, d.position[1]); setF(m, ro + 0x58, d.position[2]);
    i32[(body + 0x1c) >> 2] = d.sector; i32[(body + 0x20) >> 2] = d.sector; i32[(body + 0x24) >> 2] = d.waypoint;
    setF(m, ro + 0x78, d.yaw); setF(m, ro + 0x74, 0); setF(m, ro + 0x7c, 0);   // safetyFallback: level, no rates
    // body.matrix = nativeRotationMatrix([0, yaw, 0]) (native-rescue.js:149): the rows right, up and forward of +0x10
    // (free-flight.js write()); the translation row stays, so this pass still draws at the old place, as the JS port
    // draws the relocation frame at the rescue's renderPosition, and the next 0x491d30 rebuilds the matrix as ever
    const a = Math.trunc(d.yaw) & 4095, c = COS[a], sn = SIN[a];
    [c, 0, sn, 0, 0, 1, 0, 0, -sn, 0, c, 0].forEach((v, k) => setF(m, ro + 0x10 + 4 * k, v));
    F[(body + 0xa8) >> 2] = 0; F[(body + 0xac) >> 2] = 0; F[(body + 0xb0) >> 2] = 0;
    // what 0x48ca60's success branch writes for the player: the HUD's position and 0 km/h
    F[0x53be44 >> 2] = d.position[0]; F[0x53be48 >> 2] = d.position[1]; F[0x53be4c >> 2] = d.position[2];
    i32[0x53be34 >> 2] = 0;
    // wheels: a cleared 0x507f48[slot] makes the next 0x416650 seat them anew (0x4166ab-0x41672a), as the JS port
    // re-grounds them; its count 0x50815c (re-counted by that call) reads 4 until then, as the JS groundCount
    i32[(0x507f48 + slot * 4) >> 2] = 0; i32[(0x50815c + slot * 4) >> 2] = 4;
    // controls, gear and rpm (JS: controls 0, gear 0, rpm 0, slip 0): steer f32 0x53bd70 and throttle f32 0x53bd74
    // (0x4325b0 reads them at 0x432e85/0x432e7a), brake i32 0x53be04, handbrake i32 0x53bdf4, rpm f32 0x507290 and gear
    // i32 0x507298 as free-flight.js names them, and the slip latch u32 0x50728c (0x4325b0 writes it at 0x432b52/0x432b94)
    F[0x53bd70 >> 2] = 0; F[0x53bd74 >> 2] = 0; i32[0x53be04 >> 2] = 0; i32[0x53bdf4 >> 2] = 0;
    F[0x507290 >> 2] = 0; i32[0x507298 >> 2] = 0; u32[0x50728c >> 2] = 0;
    i32[0x53d1d8 >> 2] = i32[0x53d1d8 >> 2] && d.recoveryFinishArmed ? 1 : 0;
    i32[0x53be70 >> 2] = Math.min(i32[0x53be70 >> 2], d.recoveryDistance);
    m.call(0x41e0b0, [i]);                                  // the camera behind the kart (NativeCamera.reset)
  };

  // 0x48ca60 behind hook!RescueUpdate (ECX = the entry)
  m.wrap('RescueUpdate', (esp, entry, edx, eax, next) => {
    if (u8[entry + 0x11ac] !== MARKER) return next(esp, entry, edx, eax);
    const who = i32[(entry + 0x1180) >> 2], body = bodyOf(who), ro = roOf(who);
    const request = requests.get(who);
    if (!request) { u8[entry + 0x11ac] = 0; return next(esp, entry, edx, eax); }   // not ours any more: the original's
    if (!u8[entry + 0x1198] && i32[(entry + 0x1194) >> 2] === 0) {
      stop(body);
      const d = selectRecoveryDestination(new GameTrack(m, who, scratch), request);
      if (d.blocked) {
        // 0x48ccd5-0x48cd52: back to the last shrink frame, the table 0x67e430, no rings
        stats.blocked++;
        i32[(entry + 0x1194) >> 2] = 0x13; u8[entry + 0x1198] = 1;
        m.call(0x4a17c0, [ro + 0x10, 0x67e430, ro + 0x10]);
        stop(body);
        return 0;
      }
      relocate(who, d);
      stats.relocated++;
      stats.last = { ...stats.last, destination: { waypoint: d.waypoint, sector: d.sector, position: d.position, yaw: d.yaw, distance: d.recoveryDistance } };
      // 0x48ce72-0x48d329 at frame 0: velocities 0, the grow table 0x67da70[0], frame 1, the rings
      stop(body);
      m.call(0x4a17c0, [ro + 0x10, 0x67da70, ro + 0x10]);
      i32[(entry + 0x1194) >> 2] = 1;
      m.call(0x48d610, [], entry);
      return 0;
    }
    const r = next(esp, entry, edx, eax);
    if (u8[entry + 0x11a0]) {
      // finished (0x48d2db): standing, no 5.0 forward (0x48d2fb), no rates (native-rescue.js:176-177)
      F[(body + 0xa4) >> 2] = 0;
      F[(body + 0xa8) >> 2] = 0; F[(body + 0xac) >> 2] = 0; F[(body + 0xb0) >> 2] = 0;
      const track = new GameTrack(m, who, scratch), pose = read(who).body;
      if (!track.placementClear(pose)) {
        // another kart came in while it grew: shrink again and choose anew (native-rescue.js:274-286)
        stats.recheck++;
        u8[entry + 0x11a0] = 0; i32[(entry + 0x1194) >> 2] = 0; u8[entry + 0x1198] = 1;
        stop(body);
      } else requests.delete(who);
    }
    return r;
  });

  return {
    detector, stats,
    /** Before a pass. paused: the last pass waited in the game's pause or requester (JS pause()/resume() reset it). */
    beforePass(paused) {
      if (!u32[0x67ee20 >> 2] || !u32[0x6a5c38 >> 2]) return;
      const i = me(), { body, race } = read(i);
      detector.observeLap(race);
      const ok = eligible(i);
      // 0x416650's grounded wheel count for the player's slot (race-simulation.js:350)
      const grounded = i32[(0x50815c + i32[0x508610 >> 2] * 4) >> 2];
      let track = null;
      if (ok && grounded >= 2) detector.remember(body, race, (pose) => (track ||= new GameTrack(m, i, scratch)).isSafe(pose));
      if (paused) detector.reset();
      const input = host.driveInput ? host.driveInput() : null;
      if (!input) { detector.reset(); return; }
      if (!detector.step(body, input, dt, { eligible: ok })) return;
      const recovery = detector.request(body, race);
      const d = selectRecoveryDestination(track ||= new GameTrack(m, i, scratch), recovery);
      if (!d.blocked && enqueue(i, recovery)) {
        detector.started(recovery);
        stats.started++;
        stats.last = { reference: recovery.reference, anchors: recovery.anchors.length };
      } else detector.retryAfter();
    },
  };

  /** 0x48dce0 (thiscall on the manager 0x48da90; body, flag; RET 8): cap 10, no duplicate, inserted at begin(). */
  function enqueue(i, recovery) {
    const mgr = m.call(0x48da90);
    m.call(0x48dce0, [i, MARKER], mgr);
    const e = entryOf(i);
    if (!e || u8[e + 0x11ac] !== MARKER) return false;
    requests.set(i, recovery);
    return true;
  }
}
