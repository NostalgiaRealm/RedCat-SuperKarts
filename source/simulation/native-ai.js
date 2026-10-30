import { nativeTrigTable } from './native-integrator.js';
import { NATIVE_PRECISION } from './native-precision.js';
const f32 = Math.fround;

/** 0x40e030/0x40e070: reroll lane preferences using the shared CRT stream. */
export function updateNativeAIPriorities(state, efficiency, random) {
  if (random.next() % 100 < Math.max(0, efficiency - 1)) {
    state.priorities = [[2, 1, 0], [0, 1, 2], [1, 0, 2]][random.next() % 3];
  }
  return state.priorities;
}

/** 0x412fd0 then0x4130e0; two shared random draws per normal drive update. */
const WOBBLE_ROLL_PITCH = ['roll', 'pitch'];
export function updateNativeAIWobble(body, dt, random, { precision = NATIVE_PRECISION, order = WOBBLE_ROLL_PITCH } = {}) {
  const r = precision === 53 ? Number : f32;
  dt = f32(dt);
  for (let i = 0; i < 2; i++) {
    const roll = order[i] === 'roll';
    let rate = roll ? body.rollRate : body.pitchRate, angle = roll ? body.roll : body.pitch;
    const change = f32(r(r(rate * -3) - r(angle * 3)));
    rate = f32(r(r(dt * change) + rate));
    angle = f32(r(r(dt * rate) + angle));
    const impulse = r(r(dt * body.forwardSpeed) * 4);
    rate = f32(r(rate + (random.next() % 10 < 5 ? impulse : -impulse)));
    if (roll) { body.rollRate = rate; body.roll = angle; } else { body.pitchRate = rate; body.pitch = angle; }
  }
  return body;
}

/** 0x401570: the first-place racer reacts to a nearby player behind it. */
export function nativeAIPlayerBehind(body, state, player, rank, options = {}) {
  const r = (options.precision ?? NATIVE_PRECISION) === 53 ? Number : f32;
  if (state.chaseTime > 1) { state.chaseTime = 0; return false; }
  const dx = f32(r(body.x - player.x)), dz = f32(r(body.z - player.z));
  if (r(r(dx * dx) + r(dz * dz)) < 10000) {
    const bearing = nativeAIRelativeBearing(body, player.position ?? [player.x, player.y, player.z], options);
    if (bearing > 1500 && bearing < 2500 && rank === 0) { state.targetId = player.id; return true; }
  }
  return false;
}

/** 0x4016e0 consumes a random value only for rank0 at forward speed >=30. */
export function nativeAIStartChase(body, state, rank, dt, random, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 53 ? Number : f32;
  if (rank === 0 && body.forwardSpeed >= 30) {
    if (random.next() % 100 < f32(r(f32(dt) * 50)) && state.chaseTime < 1) return true;
    state.chaseTime = 0;
  }
  return false;
}

export function nativeAIStuck(state) { return !state.blockRecovery && state.sectorTime > 2; }

/** 0x413330 route-plane spring, used by recovery and some effect states. */
export function updateNativeAIVerticalSpring(body, dt, sampleRouteHeight, { precision = NATIVE_PRECISION } = {}) {
  if (typeof sampleRouteHeight !== 'function') throw new TypeError('Original route-plane sampler is required');
  const r = precision === 53 ? Number : f32;
  dt = f32(dt);
  const { sin, cos } = nativeTrigTable(precision), index = Math.trunc(body.yaw) & 4095;
  // Both velocity components are stored (FSTP float 0x4133c6/0x4133df).
  const vx = f32(r(r(cos[index] * body.lateralSpeed) - r(sin[index] * body.forwardSpeed)));
  const vz = f32(r(r(sin[index] * body.lateralSpeed) + r(cos[index] * body.forwardSpeed)));
  const x = f32(r(r(r(dt * vx) * 10) + body.x));
  const z = f32(r(r(r(dt * vz) * 10) + body.z));
  const height = f32(sampleRouteHeight(x, body.y, z));
  const damping = f32(r(r(body.verticalSpeed * -3) - r(r(body.y - height) * 3)));
  body.verticalSpeed = f32(r(r(dt * damping) + body.verticalSpeed));
  return { x, z, height };
}

/** 0x40e4b0, preserving recovery's two distinct spring/wobble call orders. */
export function prepareNativeAIRecovery(body, controls, state, dt, random, {
  time, sampleRouteHeight, respawn, precision = NATIVE_PRECISION,
} = {}) {
  if (!Number.isFinite(time)) throw new TypeError('Native elapsed time is required for recovery');
  const r = precision === 53 ? Number : f32;
  const reset = () => {
    state.mode = 0;
    controls.steering = 0;
    state.recoveryTime = state.sectorTime = 0;
    state.priorities = [1, 0, 2];
    state.reactionMode = -1;
  };
  if (r(f32(time) - state.lastRecoveryTime) < 3) {
    if (typeof respawn !== 'function') throw new TypeError('Original NPC respawn adapter is required');
    respawn(body);
    reset();
  }
  if (state.sectorTime < 1.5) {
    state.recoveryTime = f32(r(f32(dt) + state.recoveryTime));
    updateNativeAIWobble(body, dt, random, { precision });
    updateNativeAIVerticalSpring(body, dt, sampleRouteHeight, { precision });
    if (state.recoveryTime > 1.5) {
      // 0x40d230 ultimately writes0 even after the preceding 0/27 selection.
      reset();
      state.lastRecoveryTime = f32(time);
    }
  } else {
    controls.steering = -100;
    body.forwardSpeed = -15;
    state.sectorTime = state.recoveryTime = 0;
    if (state.recoveryCounter !== 0) state.recoveryCounter--;
    updateNativeAIVerticalSpring(body, dt, sampleRouteHeight, { precision });
    updateNativeAIWobble(body, dt, random, { precision, order: ['pitch', 'roll'] });
  }
  return body;
}

/** 0x409ea0: finished racers disable driving and settle their body springs. */
export function prepareNativeAIFinished(body, controls, state, racer, playerRacer, dt, random, {
  sampleRouteHeight, precision = NATIVE_PRECISION, ...options
} = {}) {
  const r = precision === 53 ? Number : f32;
  state.disabled = true;
  controls.steering = f32(Math.min(100, r(r(f32(dt) * 75) + controls.steering)));
  controls.throttle = controls.brake = 0;
  updateNativeAISteering(body, controls, state, racer, playerRacer, dt, { precision, ...options });
  updateNativeAIVerticalSpring(body, dt, sampleRouteHeight, { precision });
  updateNativeAIWobble(body, dt, random, { precision, order: ['pitch', 'roll'] });
  return body;
}

/** Original 0x407150 table: slot, old state, new state, expected result, guard. */
export const NATIVE_AI_TRANSITIONS = Object.freeze([
  [3, 0, 10, 1, '402040'], [4, 0, 1, 1, '401570'], [5, 1, 2, 1, '4016e0'],
  [6, 2, 0, 0, '401570'], [7, 27, 10, 1, '402040'], [8, 27, 0, 1, '40ca90'],
  [9, 0, 25, 1, '40cd00'], [10, 24, 10, 1, '402040'], [13, 23, 25, 1, '40cd00'],
  [14, 0, 22, 1, '40cd30'], [15, 22, 10, 1, '402040'], [16, 23, 22, 1, '40cd30'],
  [17, 0, 26, 1, '40cde0'], [18, 26, 10, 1, '402040'], [19, 26, 25, 1, '40cd00'],
  [20, 23, 10, 1, '402040'], [21, 0, 28, 1, '40d070'], [22, 28, 10, 1, '402040'],
  [23, 1, 10, 1, '402040'], [24, 2, 10, 1, '402040'], [25, 10, 26, 1, '40cde0'],
  [26, 28, 26, 1, '40cde0'], [27, 23, 26, 1, '40cde0'],
].map(Object.freeze));

/** 0x4024d0: preserve ordered, potentially side-effecting condition calls. */
export function updateNativeAITransition(state, guards) {
  for (let i = 0; i < NATIVE_AI_TRANSITIONS.length; i++) {
    const row = NATIVE_AI_TRANSITIONS[i];
    if (state.mode !== row[1]) continue;
    const guard = guards[row[4]];
    if (typeof guard !== 'function') throw new Error(`Missing native NPC transition guard0x${row[4]}`);
    if (Number(guard()) === row[3]) { state.mode = row[2]; break; }
  }
  return state.mode;
}

const catchupThresholds = [[100, 25, 0], [5, 15, f32(.05)], [1, 6, f32(.08)]];
const slowdownThresholds = [[1, 11, f32(.055)], [5, 18, f32(.045)], [100, 25, 0]];
/** 0x4062b0/0x405fd0/0x406100. Difference is racer progress minus player progress. */
export function applyNativeAICatchup(body, state, difficulty, difference, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 53 ? Number : f32;
  const slow = slowdownThresholds[difficulty], fast = catchupThresholds[difficulty];
  if (!slow) throw new RangeError('Native difficulty must be 0, 1 or 2');
  state.special = false;
  if (difference > slow[0] && difficulty !== 2) {
    // Integer division is intentional: original behavior jumps at the threshold.
    const amount = difference < slow[0] + slow[1] ? r(Math.trunc((difference - slow[0]) / slow[1]) * slow[2]) : slow[2];
    const factor = f32(r(1 - amount));
    body.lateralSpeed = f32(r(body.lateralSpeed * factor));
    body.verticalSpeed = f32(r(body.verticalSpeed * factor));
    body.forwardSpeed = f32(r(body.forwardSpeed * factor));
  } else if (difference < -fast[0] && difficulty !== 0 && (body.lateralSpeed >= 30 || body.verticalSpeed >= 30 || body.forwardSpeed >= 30)) {
    state.specialTime = -difference < fast[0] + fast[1] ? Math.trunc((-difference - fast[0]) / fast[1]) : 1;
    const factor = r(1 + r(state.specialTime * fast[2]));
    body.lateralSpeed = f32(r(body.lateralSpeed * factor));
    body.verticalSpeed = f32(r(body.verticalSpeed * factor));
    body.forwardSpeed = f32(r(body.forwardSpeed * factor));
    body.forwardSpeed = Math.min(80, body.forwardSpeed);
    state.special = true;
  }
  return body;
}

/** 0x41c4b0 NPC wheels differ from the player's control-linked wheel routine. */
export function updateNativeAIWheels(body, state, dt, height, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 53 ? Number : f32;
  const radius = state.wheels[0].radius;
  const spin = f32(r(r(r(4096 / r(radius + radius)) * f32(dt)) * body.forwardSpeed));
  const steeringAngle = Math.max(-500, Math.min(500, f32(r(body.yawRate * 400))));
  // 0x41c737 tests the register difference against 0; otherwise 0x41c752
  // compares the stored float with -1.11f, which an unordered NaN also fails.
  const difference = r(height - body.y), stored = f32(difference);
  const suspension = difference > 0 ? 0 : stored >= f32(-1.11) ? stored : f32(-1.11);
  for (let index = 0; index < state.wheels.length; index++) {
    const wheel = state.wheels[index];
    wheel.spin = f32(r(wheel.spin - spin));
    if (index < 2) wheel.steeringAngle = steeringAngle;
    wheel.local[1] = f32(r(suspension + wheel.radius));
  }
  return state;
}

/** Integer target-heading error from original NPC 0x414360, in 4096-unit angles. */
export function nativeAIHeadingError(body, target, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 24 ? f32 : Number;
  let dx = r(f32(target[0]) - body.x);
  const dz = f32(r(f32(target[2]) - body.z));
  if (dx > 0 && dx < f32(.1)) dx = f32(.1);
  else if (dx < 0 && dx > f32(-.1)) dx = f32(-.1);
  const ratio = r(dz / dx);
  const angle = f32(r(r(Math.atan(ratio) * f32(1 / (2 * Math.PI))) * 4096));
  let error = r(r(angle + (dx > 0 ? 3072 : 1024)) - body.yaw);
  if (error > 2048) error = r(error - 4096);
  if (error < -2048) error = r(error + 4096);
  // 0x4be698 truncates to an x87 qword and the caller reads its low dword.
  // A coincident XZ target yields NaN -> integer indefinite 8000000000000000,
  // hence EAX=0 (not INT32_MIN). This occurs after native spawn relocation.
  return Number.isFinite(error) ? Math.trunc(error) | 0 : 0;
}

/** 0x401320: unsigned relative bearing, with the native one-turn yaw repair. */
export function nativeAIRelativeBearing(body, target, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 53 ? Number : f32;
  if (body.yaw >= 4096) body.yaw = f32(r(body.yaw - 4096));
  if (body.yaw < 0) body.yaw = f32(r(body.yaw + 4096));
  let dx = f32(r(f32(target[0]) - body.x));
  const dz = f32(r(f32(target[2]) - body.z));
  if (dx === 0 || (dx > 0 && dx < f32(.1))) dx = f32(.1);
  else if (dx < 0 && dx > f32(-.1)) dx = f32(-.1);
  const angle = f32(r(r(Math.atan(r(dz / dx)) * f32(1 / (2 * Math.PI))) * 4096));
  let bearing = f32(r(r(angle + (dx > 0 ? 3072 : 1024)) - body.yaw));
  if (bearing > 4096) bearing = f32(r(bearing - 4096));
  if (bearing < 0) bearing = f32(r(bearing + 4096));
  return Math.trunc(bearing);
}

/** 0x409b30 checks only occupants of the nearest waypoint, in stored order. */
export function nativeAIObstructed(body, occupants, options = {}) {
  for (const other of occupants) {
    if (other === body || (body.id !== undefined && other.id === body.id)) continue;
    const bearing = nativeAIRelativeBearing(body, other.position ?? [other.x, other.y, other.z], options);
    if ((bearing < 1024 || bearing > 3072) && other.forwardSpeed < body.forwardSpeed) return true;
  }
  return false;
}

/**
 * 0x401030 and0x4010e0. Steering and throttle targets can differ: the native
 * path search supplies distinct look-ahead waypoints for each.
 */
export function updateNativeAIControls(body, controls, steeringTarget, speedTarget, dt, options = {}) {
  const r = (options.precision ?? NATIVE_PRECISION) === 53 ? Number : f32;
  dt = f32(dt);
  const heading = nativeAIHeadingError(body, steeringTarget, options);
  controls.steering = f32(Math.max(-100, Math.min(100, heading * .5)));
  const speedHeading = Math.min(500, Math.abs(nativeAIHeadingError(body, speedTarget, options)));
  const desiredSpeed = 70 - Math.trunc(speedHeading / 15);
  if (body.forwardSpeed < desiredSpeed) {
    controls.throttle = Math.min(100, f32(r(r(dt * 75) + controls.throttle)));
    controls.brake = 0;
  } else if (options.traffic) {
    body.forwardSpeed = desiredSpeed;
  } else {
    controls.brake = Math.min(100, f32(r(r(dt * 400) + controls.brake)));
  }
  return controls;
}

/** 0x414470 simplified NPC drive model, distinct from active player forces. */
export function updateNativeAISpeed(body, controls, state, racer, playerRacer, dt, { precision = NATIVE_PRECISION } = {}) {
  const r = precision === 24 ? f32 : Number;
  dt = f32(dt);
  if (controls.throttle === 0) {
    const old = body.forwardSpeed;
    const change = r(dt * racer.frictionPower);
    body.forwardSpeed = f32(r(old < 0 ? old + change : old - change));
    if ((old < 0 && body.forwardSpeed > 0) || (old >= 0 && body.forwardSpeed < 0)) body.forwardSpeed = 0;
  }
  if (controls.throttle > 0) state.reverseLatch = false;
  const oldSpeed = body.forwardSpeed;
  let drive = Math.max(0, r(r(1 - r(oldSpeed / racer.raw[18 + state.gear])) * racer.raw[6 + state.gear]));
  state.gear = 6;
  for (let gear = 0; gear < 6; gear++) {
    if (oldSpeed < r(racer.maxSpeed[gear] * racer.gearUpFraction)) {
      state.gear = gear;
      drive = Math.max(0, r(r(1 - r(oldSpeed / racer.raw[18 + gear])) * racer.raw[6 + gear]));
      break;
    }
  }
  let brake = -Math.abs(playerRacer.brakePower);
  if (state.disabled) drive = brake = 0;
  body.forwardSpeed = f32(r(r(r(r(drive * controls.throttle) + r(brake * controls.brake)) * dt) + oldSpeed));
  if (controls.brake > 0) {
    if (Math.abs(body.forwardSpeed) < f32(.4) && !state.reverseLatch) {
      body.forwardSpeed = 0;
      state.reverseLatch = true;
    }
    const tilt = Math.min(1000, f32(r(controls.brake * body.forwardSpeed)));
    body.pitchRate = f32(r(body.pitchRate - r(dt * tilt)));
  }
  body.forwardSpeed = Math.max(f32(-13.333), body.forwardSpeed);
  return body;
}

/** Original 0x414750 lateral/yaw update, including its disabled/sliding branch. */
export function updateNativeAISteering(body, controls, state, racer, playerRacer, dt, options = {}) {
  const r = (options.precision ?? NATIVE_PRECISION) === 53 ? Number : f32;
  const tau = f32(2 * Math.PI), angleScale = 0.0015339807141572237;
  const steer = -controls.steering;
  dt = f32(dt);
  let lateralDamping = 0;
  if (!state.disabled) {
    body.yawRate = f32(r(body.yawRate - r(r(body.yawRate * 10) * dt)));
    state.turnIntegral = state.turnStartHeading = state.turnTime = 0;
    lateralDamping = f32(r(body.lateralSpeed * (options.tireUpgrade ? 10 : 5)));
    body.lateralSpeed = f32(r(body.lateralSpeed - r(lateralDamping * dt)));
  }
  const absoluteSpeed = Math.abs(body.forwardSpeed);
  let gain;
  if (absoluteSpeed >= 2 || Math.abs(body.lateralSpeed) >= 2) {
    gain = racer.steerSpeed;
    if (state.special) gain = r(gain * (state.specialTime <= f32(.05) ? 10 : 15));
  } else {
    gain = r(Math.sin(Math.abs(r(r(f32(Math.PI) * body.forwardSpeed) * .25))) * racer.steerSpeed);
  }
  let theta = r(r(r(steer * .5) * tau) * f32(1 / 360));
  if (theta > tau) theta = r(theta - tau);
  else if (theta < 0) theta = r(theta + tau);
  const speedTerm = r(r(r(body.forwardSpeed * 50) * r(Math.sin(theta) * angleScale)) * dt);
  const steerTerm = r(r(r(angleScale * steer) * gain) * dt);
  let turn = r(speedTerm + steerTerm);
  const storedTurn = f32(turn);
  if (turn > tau) turn = r(turn - tau);
  else if (turn < 0) turn = r(turn + tau);
  if (!state.disabled && state.turnTime === 0) {
    const factor = Math.max(2.5, f32(r(10 - r(absoluteSpeed * f32(.15)))));
    const inside = turn > 0 && turn < tau;
    const increment = inside || body.forwardSpeed >= 0 ? r(factor * storedTurn) : r(steer * f32(.004));
    body.yawRate = f32(r(body.yawRate + (body.forwardSpeed < 0 ? increment : -increment)));
    const tilt = r(r(dt * playerRacer.raw[29]) * steer);
    const plusTilt = !inside || (body.forwardSpeed < 10 && options.lowSpeedTurn);
    body.roll = f32(r(body.roll + (plusTilt ? tilt : -tilt)));
    if (!inside) body.forwardSpeed = f32(r(body.forwardSpeed - r(r(lateralDamping * dt) * .5)));
    const angle = r(body.yawRate * dt);
    const lateral = r(r(Math.cos(angle) * body.lateralSpeed) - r(Math.sin(angle) * body.forwardSpeed));
    body.lateralSpeed = f32(options.tireUpgrade ? lateral : r(lateral * f32(.8)));
  } else {
    if (state.turnStartHeading === 0) {
      state.turnStartHeading = f32(r(r((Math.trunc(body.yaw) & 4095) / 4096) * tau));
    }
    state.turnTime = Math.min(1, f32(r(state.turnTime + dt)));
    const speed = r(Math.sqrt(r(r(body.lateralSpeed * body.lateralSpeed) + r(body.forwardSpeed * body.forwardSpeed))));
    if (speed <= 1) {
      body.lateralSpeed = body.forwardSpeed = body.yawRate = 0;
    } else {
      const wave = Math.sin(r(r(speed * f32(Math.PI)) * f32(.004)));
      const angular = r(r(r(r(state.turnTime * steer) * f32(.17999999)) * wave) * (options.traffic ? 1.25 : .5));
      body.yawRate = f32(body.forwardSpeed >= 0 || !options.reverseTurn ? -angular : angular);
      state.turnIntegral = f32(r(r(dt * f32(angular)) + state.turnIntegral));
      for (let i = 0; i < 2; i++) {
        const speed = i === 0 ? body.lateralSpeed : body.forwardSpeed;
        const damp = options.traffic ? r(speed * 3) : steer === 0 ? r(speed + speed) : speed;
        const damped = f32(r(speed - r(damp * dt)));
        if (i === 0) body.lateralSpeed = damped; else body.forwardSpeed = damped;
      }
    }
  }
  return body;
}

/** 0x494000 selects the nearest waypoint from the current sector's right list. */
export function nearestNativeAIWaypoint(track, body, { precision = NATIVE_PRECISION, side = 1 } = {}) {
  if (side !== 0 && side !== 1 && side !== -1) throw new RangeError('Native waypoint side must be -1, 0 or 1');
  const r = precision === 53 ? Number : f32;
  let closest = -1, distance = f32(3.4e38);
  const position = body.position, x = position ? position[0] : body.x, y = position ? position[1] : body.y, z = position ? position[2] : body.z;
  const route = track.route[body.sector];
  for (let list = 0; list < 2; list++) {
    if (list === 0 ? side === 0 : side === 1) continue;
    const indices = list === 0 ? route.driveIndices : route.driveLeftIndices;
    for (let i = 0; i < indices.length; i++) {
      const index = indices[i], p = track.drive[index].position;
      const dx = f32(r(p[0] - x)), dy = f32(r(p[1] - y)), dz = f32(r(p[2] - z));
      const candidate = f32(Math.sqrt(r(r(r(dy * dy) + r(dx * dx)) + r(dz * dz))));
      if (candidate < distance) { closest = index; distance = candidate; }
    }
  }
  return closest;
}

/** DMP link order is native +14,+1c,+18,+20; direction selector 0 means +18. */
export function nativeAINextWaypoint(track, waypoint, direction) {
  return track.drive[waypoint]?.links[[2, 0, 1, 3][direction]] ?? -1;
}

/**
 * Racer DFS 0x40ed40: search five links ahead while excluding occupied nodes.
 * Returns node1 as current route choice, node2 for steering and node4 for speed.
 * getPriorities is the explicit state/personality hook 0x40f0b0.
 */
export function searchNativeAIPath(track, start, {
  depth = 5, occupied = new Set(), priorities = [0, 1, 2], getPriorities,
  initial = { steering: null, speed: null }, sector = 0, precision = NATIVE_PRECISION,
} = {}) {
  if (depth > 25) return { waypoint: -2, steering: initial.steering && [...initial.steering], speed: initial.speed && [...initial.speed] };
  if (depth < 5 || start < 0 || !track.drive[start]) throw new RangeError('Native racer path requires a valid start and at least five look-ahead steps');
  const path = [start], tried = [0], live = occupied instanceof Map, set = occupied instanceof Set;
  const result = { waypoint: -1, steering: initial.steering && [...initial.steering], speed: initial.speed && [...initial.speed] };
  let level = 0, current = start, order = priorities;
  while (true) {
    path[level] = current;
    order = getPriorities ? getPriorities(current) : priorities;
    let advanced = false;
    while (!advanced) {
      while ((tried[level] ?? 0) < 3) {
        const choice = (tried[level] ?? 0);
        tried[level] = choice + 1;
        const next = nativeAINextWaypoint(track, current, order[choice]);
        if (next < 0 || (live ? occupied.get(next)?.length > 0 : set ? occupied.has(next) : occupied[next])) continue;
        level++;
        path[level] = next;
        tried[level] = 0;
        current = next;
        advanced = true;
        break;
      }
      if (advanced) break;
      if (level === 0) {
        const first = order.map(direction => nativeAINextWaypoint(track, start, direction)).find(index => index >= 0);
        if (first === undefined) { result.steering = [...track.drive[start].position]; return result; }
        const second = order.map(direction => nativeAINextWaypoint(track, first, direction)).find(index => index >= 0);
        if (second === undefined || second === 0) { result.steering = [...track.drive[first].position]; return result; }
        result.waypoint = second;
        result.steering = [...track.drive[second].position];
        // Original fallback's one-waypoint sector special case uses cos/sin
        // of literal 1024 radians and its Y difference in the XZ adjustment.
        if (track.route[sector].driveIndices.length === 1) {
          const r = precision === 53 ? Number : f32;
          const firstPosition = track.drive[first].position;
          const dx = r(r(result.steering[0] - firstPosition[0]) * f32(.46511626));
          const dy = r(r(result.steering[1] - firstPosition[1]) * f32(.46511626));
          result.steering[0] = f32(r(r(r(dx * Math.cos(1024)) - r(dy * Math.sin(1024))) + result.steering[0]));
          result.steering[2] = f32(r(r(r(dy * Math.cos(1024)) + r(dx * Math.sin(1024))) + result.steering[2]));
          result.speed ??= [0, 0, 0];
          result.speed[0] = result.steering[0]; result.speed[2] = result.steering[2];
        }
        return result;
      }
      current = path[level - 1];
      level--;
    }
    if (level >= depth) return { waypoint: path[1], steering: [...track.drive[path[2]].position], speed: [...track.drive[path[4]].position] };
  }
}

/**
 * 0x401200 for registered racers: native drive, steering, yaw dynamics and
 * body wobble. Traffic's extra vertical-height spring is a separate path.
 * This is the preparation phase; the engine integrates all actors afterward.
 */
export function updateNativeAIRacerMotion(body, controls, state, racer, playerRacer, target, dt, random, options = {}) {
  const r = (options.precision ?? NATIVE_PRECISION) === 53 ? Number : f32;
  if (body.yaw < 0) body.yaw = f32(r(body.yaw + 4096));
  if (body.yaw >= 4096) body.yaw = f32(r(body.yaw - 4096));
  updateNativeAISpeed(body, controls, state, racer, playerRacer, dt, options);
  controls.steering = f32(Math.max(-100, Math.min(100, nativeAIHeadingError(body, target, options) * .5)));
  updateNativeAISteering(body, controls, state, racer, playerRacer, dt, options);
  updateNativeAIWobble(body, dt, random, options);
  return body;
}

/**
 * 0x40e180 normal racer handler. Occupancy is a map of waypoint to actor arrays.
 * Item/recovery/chase state handlers are deliberately separate from this path.
 */
export function prepareNativeNormalAI(track, body, controls, state, racer, playerRacer, dt, random, {
  occupancy = new Map(), efficiency, pathScratch, ...options
} = {}) {
  if (!Number.isFinite(efficiency)) throw new TypeError('Original NPC efficiency setting is required');
  const nearest = nearestNativeAIWaypoint(track, body, options);
  if (nearest < 0) throw new RangeError('Native AI could not find a waypoint in the current sector');
  state.disabled = false;
  const path = searchNativeAIPath(track, nearest, {
    occupied: occupancy, sector: body.sector, precision: options.precision,
    initial: pathScratch ?? { steering: state.steeringTarget, speed: state.speedTarget },
    getPriorities: () => {
      const mode = state.mode ?? 0;
      if (mode !== 0 && mode !== 3 && mode !== 23 && mode !== 24 && mode !== 25 && mode !== 27) return [1, 2, 0];
      const result = state.priorities;
      if (mode === 0 || mode === 3) updateNativeAIPriorities(state, efficiency, random);
      return result;
    },
  });
  if (pathScratch) {
    pathScratch.steering = path.steering;
    pathScratch.speed = path.speed;
  }
  if (!path.steering) throw new Error('Native AI path left an uninitialized steering target');
  if (path.waypoint >= 0) {
    state.waypoint = path.waypoint;
    state.disabled = nativeAIObstructed(body, occupancy.get(nearest) ?? [], options);
    if (!state.disabled) {
      // Some occupied-path fallbacks leave the speed output untouched. Native
      // 0x40e180 never reads it when 0x409b30 blocks the current waypoint.
      if (!path.speed) throw new Error('Native AI path read an uninitialized speed target');
      updateNativeAIControls(body, controls, path.steering, path.speed, dt, options);
    }
  }
  state.steeringTarget = path.steering;
  state.speedTarget = path.speed;
  updateNativeAIRacerMotion(body, controls, state, racer, playerRacer, path.steering, dt, random, options);
  return { nearest, ...path };
}

/** 0x409cc0/0x409dc0: approach/chase use fixed lane priorities, no lane RNG. */
export function prepareNativeChaseAI(track, body, controls, state, racer, playerRacer, dt, random, {
  occupancy = new Map(), player, pathScratch, precision = NATIVE_PRECISION, ...options
} = {}) {
  if (![1, 2, 3].includes(state.mode)) throw new RangeError('Approach/chase handler requires native state1,2 or3');
  const chase = state.mode === 2;
  if (chase && !player) throw new TypeError('Native chase requires the selected target body');
  const nearest = nearestNativeAIWaypoint(track, chase ? player : body, { precision });
  if (!chase) state.disabled = false;
  const path = searchNativeAIPath(track, nearest, {
    priorities: [1, 2, 0], occupied: occupancy, sector: body.sector, precision,
    initial: pathScratch ?? { steering: state.steeringTarget, speed: state.speedTarget },
  });
  if (pathScratch) Object.assign(pathScratch, { steering: path.steering, speed: path.speed });
  if (!path.steering) throw new Error('Native chase read an uninitialized steering target');
  if (path.waypoint >= 0) {
    state.waypoint = path.waypoint;
    const blocked = !chase && nativeAIObstructed(body, occupancy.get(nearest) ?? [], { precision });
    if (!blocked) {
      if (!path.speed) throw new Error('Native chase read an uninitialized speed target');
      updateNativeAIControls(body, controls, path.steering, path.speed, dt, { precision, ...options });
    }
  } else if (chase) controls.throttle = controls.brake = 0;
  state.steeringTarget = path.steering; state.speedTarget = path.speed;
  updateNativeAIRacerMotion(body, controls, state, racer, playerRacer, path.steering, dt, random, { precision, ...options });
  if (chase) state.chaseTime = f32((precision === 53 ? Number : f32)(state.chaseTime + f32(dt)));
  return { nearest, ...path };
}

/** 0x40e0c0: choose a neighbor of the forced route marker using efficiency. */
export function nativeAIForcedRouteChoice(track, waypoint, efficiency, random) {
  if (random.next() % 100 < Math.max(0, efficiency - 1)) {
    const links = track.drive[waypoint].links;
    const sides = random.next() % 2 === 0 ? [links[1], links[2], waypoint] : [links[2], links[1], waypoint];
    return sides.find(index => index !== -1);
  }
  return waypoint;
}

/** 0x40e270 state27 follows marker66 after the marker64 route trigger. */
export function prepareNativeForcedRouteAI(track, body, controls, state, racer, playerRacer, dt, random, {
  efficiency, precision = NATIVE_PRECISION, ...options
} = {}) {
  const nearest = nearestNativeAIWaypoint(track, body, { precision });
  const links = track.drive[nearest].links;
  const first = [links[0], links[1], links[2]].find(index => index !== -1) ?? nearest;
  const next = track.drive[first].links;
  const hasMarker = index => index >= 0 && track.drive[index].unknown[1] === 66;
  const target = [next[0], next[1], next[2]].find(hasMarker) ??
    track.route[(body.sector + 1) % track.route.length].driveIndices.find(hasMarker);
  if (target === undefined) throw new Error('Native forced route did not initialize marker66 target');
  const waypoint = nativeAIForcedRouteChoice(track, target, efficiency, random);
  const steering = [...track.drive[target].position], speed = [...track.drive[waypoint].position];
  state.disabled = false;
  if (waypoint >= 0) {
    state.waypoint = waypoint;
    updateNativeAIControls(body, controls, steering, speed, dt, { precision, ...options });
  }
  updateNativeAIRacerMotion(body, controls, state, racer, playerRacer, steering, dt, random, { precision, ...options });
  return { nearest, waypoint, steering, speed };
}
