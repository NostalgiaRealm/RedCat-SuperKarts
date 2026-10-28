import { nativeAIRelativeBearing } from './native-ai.js';
// Retain the public AI import path without making menu score readers load AI.
export { recordNativeNPCFinish } from './native-results.js';

const f32 = Math.fround;
const rounding = precision => precision === 53 ? Number : f32;

/** Original 0x493a40 returns the unsigned shorter sector distance. */
export function nativeAIShortSectorDistance(a, b, count) {
  const distance = Math.abs(a - b);
  return distance > Math.trunc(count / 2) ? count - distance : distance;
}

/** 0x406320. Uses graph direction, rather than the kart's current yaw. */
export function nativeAIPositionBehind(track, body, position, { precision = 24, deadEndTarget } = {}) {
  const node = track.drive[body.waypoint];
  if (!node) throw new RangeError('Native AI requires its current waypoint');
  const next = node.links.find(index => index >= 0);
  if (next === undefined) {
    // The original passes an uninitialized stack vector at this dead-end branch.
    // All six shipped graphs have a link; synthetic callers must choose a policy.
    if (!deadEndTarget) throw new TypeError('Dead-end native bearing reads an uninitialized target');
    const angle = nativeAIRelativeBearing(body, deadEndTarget, { precision });
    return angle > 1024 && angle < 3072;
  }
  const r = rounding(precision), to = track.drive[next].position;
  const dx = f32(r(to[0] - node.position[0])), dz = f32(r(to[2] - node.position[2]));
  const px = f32(r(position[0] - body.x)), pz = f32(r(position[2] - body.z));
  const numerator = r(r(px * dx) + r(pz * dz));
  const denominator = r(Math.sqrt(r(r(dx * dx) + r(dz * dz)))
    + Math.sqrt(r(r(px * px) + r(pz * pz))));
  return r(numerator / denominator) < 0;
}

/** 0x410420: first closest racer ahead by graph direction, beyond two sectors. */
export function nativeAINearestShooterTarget(track, body, racers, options = {}) {
  const position = track.drive[body.waypoint].position;
  let target = null, distance = 100000;
  for (const other of racers) {
    if (other.id === body.id) continue;
    const candidate = nativeAIShortSectorDistance(body.sector, other.sector, track.route.length);
    if (nativeAIPositionBehind(track, other, position, options) && candidate < distance && candidate > 2) {
      target = other;
      distance = candidate;
    }
  }
  return { target, distance: target ? distance : 0 };
}

/** Embedded reaction controller, 0x40eb20. Deadline is an absolute clock time. */
export function setNativeAIReaction(state, mode, now, reactionMs, { precision = 24 } = {}) {
  if (state.mode !== mode) {
    const r = rounding(precision);
    state.reactionMode = mode;
    state.reactionDeadline = f32(r(r(reactionMs * 0.001) + f32(now)));
  }
}

/** 0x40eba0 checks a strict deadline and cancels a mismatched controller mode. */
export function nativeAIReactionReady(state, now) {
  if (state.mode === state.reactionMode && f32(now) > state.reactionDeadline) return true;
  if (state.mode !== state.reactionMode) state.reactionMode = -1;
  return false;
}

/** 0x40cde0. Geometry answers are produced by nativeAIItemGuard below. */
export function decideNativeAIItem(state, owned, {
  rank, now, playerId, playerProtected, targetId = -1, targetDistance = 0,
  playerBehind = false, playerDistance = 0, shared, reactionMs, precision = 24,
}) {
  if (!shared || !Number.isInteger(shared.dropperCounter)) throw new TypeError('Shared native dropper counter is required');
  const r = rounding(precision);
  const fire = () => {
    if (state.mode !== 9) {
      setNativeAIReaction(state, 26, now, reactionMs, { precision });
      state.mode = 26;
    }
    return true;
  };
  if (owned.state !== 2) return false;
  if (owned.type === 1 || owned.type === 2) {
    if (rank === 0 || targetId === -1) return false;
    if (targetId === playerId) {
      if (!playerProtected && (owned.type === 1 || targetDistance < 20)) return fire();
    } else if (r(f32(now) - state.lastBonusTime) > 10) return fire();
  } else if (owned.type === 3 || owned.type === 4) {
    if ((playerBehind && playerDistance < 4) || r(f32(now) - state.lastBonusTime) > 5) return fire();
    if (shared.dropperCounter >= 456789) { shared.dropperCounter = 0; return fire(); }
    shared.dropperCounter = (shared.dropperCounter + 1) | 0;
  } else if (owned.type === 5) return fire();
  return false;
}

/** Complete source-graph firing guard, with racers in native NPC/player order. */
export function nativeAIItemGuard(track, body, state, owned, context) {
  const { racers, player, ...options } = context;
  let targetId = -1, targetDistance = 0, playerBehind = false, playerDistance = 0;
  if (owned.state === 2 && [1, 2].includes(owned.type) && options.rank !== 0) {
    const query = nativeAINearestShooterTarget(track, body, racers, options);
    targetId = query.target?.id ?? -1;
    targetDistance = query.distance;
  } else if (owned.state === 2 && [3, 4].includes(owned.type)) {
    playerBehind = nativeAIPositionBehind(track, body, track.drive[player.waypoint].position, options);
    playerDistance = nativeAIShortSectorDistance(body.sector, player.sector, track.route.length);
  }
  return decideNativeAIItem(state, owned, {
    ...options, playerId: player.id, targetId, targetDistance, playerBehind, playerDistance,
  });
}

/** 0x40d070/0x40d9c0/0x40dbd0. Integer millisecond division is intentional. */
export function nativeAICatchupGuard(state, { rank, playerRank, catchupMs, now, reactionMs, precision = 24 }) {
  if (state.mode === 28 || rank === 0 || state.lastRank !== rank
    || !(f32(Math.trunc(catchupMs / 1000)) < state.rankTime) || rank <= 0) return false;
  if (state.mode !== 9) {
    setNativeAIReaction(state, 28, now, reactionMs, { precision });
    state.mode = 28;
    state.chaseTime = 0;
  }
  return { announce: playerRank + 1 === rank };
}

/** 0x40c010: catch-up duration only advances after its reaction deadline. */
export function updateNativeAICatchupState(state, dt, { now, durationMs, precision = 24 }) {
  if (nativeAIReactionReady(state, now)) {
    if (f32(Math.trunc(durationMs / 1000)) <= state.chaseTime) return false;
    state.chaseTime = f32(rounding(precision)(f32(dt) + state.chaseTime));
  }
  return true;
}

/** 0x40d230. The shared reaction controller is cleared, not the target actor. */
export function resetNativeAIItemState(state) {
  state.priorities = [1, 0, 2];
  state.mode = 0;
  state.reactionMode = -1;
}

/** 0x40e690 calls fire, unconditionally resets, then runs ordinary movement. */
export function prepareNativeAIFireState(state, fire, normal) {
  const event = fire();
  resetNativeAIItemState(state);
  normal();
  return event;
}

/** 0x40e730 always runs movement, including the update that finishes state28. */
export function prepareNativeAICatchupState(state, dt, options, normal) {
  const active = updateNativeAICatchupState(state, dt, options);
  if (!active) resetNativeAIItemState(state);
  normal();
  return active;
}

/** 0x40d610 stores absolute seconds even for an already-finished opponent. */
export function nativeAIBonusCollected(state, now) {
  state.lastBonusTime = f32(now);
  return state.mode !== 9 ? { animation: 'CHEER' } : null;
}

/** 0x40ddd0 starts the one-second NPC hit marker only while it is clear. */
export function markNativeNPCWeaponHit(state, now) {
  if (state.mode === 9 || state.hitVisible) return;
  if (!Number.isFinite(now)) throw new TypeError('NPC hit marker requires the original seconds clock');
  state.hitTime = f32(now);
  state.hitVisible = true;
}

/** Native 0x42b060 speed-limit globals, kept distinct from racer physics. */
export function nativeAITriggerSpeedLimits(config) {
  const values = config['npc_ai.ini'].violations;
  return Object.fromEntries([[4, 'maxspeed60'], [5, 'maxspeed80'], [6, 'maxspeed120'], [8, 'nomaxspeed']]
    .map(([marker, key]) => [marker, f32(Number(values[key]) * .25)]));
}

/** 0x406470 NPC marker dispatcher. Finish timing/audio is returned to its owner. */
export function applyNativeAITrigger(body, state, marker, {
  now, circuit, lapCount, playerForwardSpeed, efficiencyLevel, speedLimits,
  previousEngineSector, precision = 24,
}) {
  const r = rounding(precision);
  if ([4, 5, 6, 8].includes(marker)) {
    if (!Number.isFinite(speedLimits?.[marker])) throw new TypeError('Original NPC marker speed limits required');
    state.speedLimit = speedLimits[marker];
  } else if (marker === 14) {
    let finish = !circuit;
    if (circuit && state.finishMarker === 15 && r(f32(now) - state.lastFinishTime) > 10) {
      state.laps++;
      state.lastFinishTime = f32(now);
      state.finishMarker = 14;
      finish = state.laps >= lapCount;
    }
    if (finish) { state.finished = true; state.mode = 9; return { type: 'finish' }; }
  } else if (marker === 15) state.finishMarker = 15;
  else if (marker === 53) {
    if ([body.lateralSpeed, body.verticalSpeed, body.forwardSpeed].every(speed => playerForwardSpeed < speed)) {
      body.forwardSpeed = playerForwardSpeed;
    }
    body.forwardSpeed = f32(r(body.forwardSpeed * f32(1.2)));
    if (state.mode !== 9) { state.turboVisible = true; state.turboTime = f32(now); }
    return { type: 'turbo' };
  } else if (marker === 64 && state.mode !== 9 && state.mode !== 27) {
    state.mode = 27;
    state.forcedRoute = true;
    // 0x40e000: 6 minus the profile's efficiency level (+0x8), not driving_style (+0x4).
    state.recoveryCounter = 6 - efficiencyLevel;
  } else if (marker === 65) state.forcedRoute = false;
  else if (marker === 67 && body.sector !== previousEngineSector) state.slippery = !state.slippery;
  // Marker68 calls an empty original function; unknown markers are ignored.
  return null;
}

/** 0x4067e0: both sector markers excluding53, then the current node marker. */
export function nativeAITrackMarkers(track, body) {
  const sector = track.route[body.sector];
  return [sector.trigger, sector.unknown].filter(marker => marker !== 53)
    .concat(track.drive[body.waypoint].unknown[1]);
}

export function applyNativeAITrackTriggers(track, body, state, options) {
  return nativeAITrackMarkers(track, body).flatMap(marker => {
    const event = applyNativeAITrigger(body, state, marker, options);
    return event ? [event] : [];
  });
}
