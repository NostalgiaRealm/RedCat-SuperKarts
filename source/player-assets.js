import {resolveAsset, createNativeMeshAnimation, advanceNativeMeshAnimation} from './asset-animation.js';
import {NATIVE_PRECISION} from './simulation/native-precision.js';

const key = value => String(value ?? '').trim().toLowerCase();
const fields = value => String(value ?? '').split(/[,;]/).map(value => value.trim());

// 004765d0 constructs a .pcx name. In accelerated mode 0042ccf0 -> 004a2cc0(1)
// selects TGA; 004a3c50 removes the requested extension before appending .tga.
function texture(manifest, source) {
  return resolveAsset(manifest, 'images', key(source).replace(/\.[^.]+$/, '') + '.tga');
}

export function getDriverSequences(config, manifest, character) {
  const section = config['charanim.ini']?.[key(character)];
  if (!section) throw new Error(`Missing original character definition: ${character}`);
  const sequences = {};
  for (let i = 0; i < Number(section.count); i++) {
    const name = key(section[i]);
    const [prefix, from, to, fps, loops] = fields(section[name]);
    const first = Number(from), last = Number(to), step = first <= last ? 1 : -1;
    const frames = [];
    for (let frame = first; ; frame += step) {
      const source = `${key(prefix)}${String(frame).padStart(4, '0')}.d3d`;
      frames.push({source, file: resolveAsset(manifest, 'meshes', source)});
      if (frame === last) break;
    }
    sequences[name] = {name, fps: Number(fps), loops: Number(loops), frames};
  }
  return sequences;
}

// 0044a220 uses the character's four comma-separated fields. 0042df90 uses
// Race.INI [PLAYER] car for every contestant and its character color separately.
export function getPlayerVisualSpec(config, manifest, characterIndex, carIndex = 0) {
  const characters = config['game.ini']?.available_characters;
  const [name, character, intelligence, color] = fields(characters?.[characterIndex]);
  if (!character) throw new Error(`Unknown original character index: ${characterIndex}`);
  const cars = config['car_ssr.ini'];
  const [section, prefix] = fields(cars?.cars?.[carIndex]);
  const car = cars?.[key(section)];
  if (!car) throw new Error(`Unknown original car index: ${carIndex}`);
  const colors = Object.keys(cars.colors).filter(value => /^\d+$/.test(value)).length;
  const colorId = Math.max(0, Math.min(Number(color || 0), colors - 1));
  const colorCode = fields(cars.colors[colorId])[1];
  const wheelTexture = fields(config['gen_anim.ini'].racer_5[1])[1];
  const wheelPositions = fields(car.wheelpos).map(value => Math.fround(Number(value)));
  const offsets = [
    [-wheelPositions[0], ...wheelPositions.slice(1, 3)], wheelPositions.slice(0, 3),
    [-wheelPositions[3], ...wheelPositions.slice(4, 6)], wheelPositions.slice(3, 6),
  ];
  const meshInfo = source => manifest.meshes[key(source)];
  const wheels = offsets.map((offset, index) => {
    const source = index < 2 ? car.fwheels : car.bwheels;
    return {source: key(source), mesh: resolveAsset(manifest, 'meshes', source),
      texture: texture(manifest, wheelTexture), offset,
      radius: meshInfo(source)?.bounds ? Math.abs(meshInfo(source).bounds.minY) : null,
      nativeChildIndex: index, rotation: [0, 0, 0]};
  });
  const driver = config['charanim.ini'][key(character)];
  return {
    characterIndex, character: key(character), name, intelligence: Number(intelligence),
    carIndex, colorId,
    body: {source: key(car.mesh), mesh: resolveAsset(manifest, 'meshes', car.mesh),
      texture: texture(manifest, `${prefix}${colorCode}.pcx`),
      bounds: meshInfo(car.mesh)?.bounds ?? null,
      horizontalRadius: meshInfo(car.mesh)?.horizontalRadius ?? null, scale: [1, 1, 1]},
    wheels,
    driver: {texture: texture(manifest, `${driver.texture}.pcx`), offset: [0, 0, 0],
      rotation: [0, 0, 0], nativeChildIndex: 4, initialSequence: 'idle',
      sequences: getDriverSequences(config, manifest, character)},
    nativeFunctions: ['0042df90', '004765d0', '0044a220', '0044cd50', '0041bdd0', '0041ca00'],
  };
}

// 004325b0 requests, in original order, including inactive and winning branches.
// Lateral velocity (object+0x9c), rather than steering input, selects leaning.
export function getDrivingAnimationRequests(config, {
  lateralSpeed = 0, forwardSpeed = 0, brake = 0, handbrake = false, turboAgeMs = 0xffffffff,
  movementActive = true, legacyAutopilotActive = false, phase = 0, rank = 0, precision = NATIVE_PRECISION,
  lookRequests = getPlayerLookAnimationRequests(),
} = {}) {
  const requests = [], add = (name, from, to) => requests.push({name, from, to});
  const r = precision === 24 ? Math.fround : Number;
  const lateralKmh = Math.trunc(r(Math.fround(lateralSpeed) * Math.fround(3.6)));
  const threshold = Number(config['charanim.ini'].tweak.turn_speed);
  if (lateralKmh < -threshold) {
    add('idle_steer_right', 0, 4); add('steer_right', 4, 4); add('steer_right_idle', 4, 0);
  } else if (lateralKmh > threshold) {
    add('idle_steer_left', 0, 3); add('steer_left', 3, 3); add('steer_left_idle', 3, 0);
  }
  // 53be64 selects legacy404f00 AI, not the separate recovery crane. There
  // are no direct writes to this BSS-zero flag in the supplied executable.
  if(legacyAutopilotActive)return requests;
  if(!movementActive){add('cheer',0,0);return requests;}
  requests.push(...lookRequests);
  if(phase===3&&rank===0)add('cheer',0,0);
  if (forwardSpeed >= 0) {
    if (brake < 1 && !handbrake) {
      if ((turboAgeMs >>> 0) < 5000) {
        add('turbo', 6, 6); add('idle_turbo', 0, 6);
      } else add('turbo_idle', 6, 0);
      add('brake_idle', 5, 0);
    } else {
      add('brake', 5, 5); add('idle_brake', 0, 5);
    }
    add('back_idle', 1, 0); add('idle', 0, 0);
  } else {
    add('idle_back', 0, 1); add('back', 1, 1); add('brake_idle', 5, 0);
  }
  return requests;
}

/** 0x435c60→0x40ec30. The bearing is relative to the OTHER racer's yaw. */
export function getPlayerLookAnimationRequests({
  playerPosition = [0, 0, 0], opponents = [], precision = NATIVE_PRECISION,
} = {}) {
  const f = Math.fround, r = precision === 24 ? f : Number;
  let nearestDistance = f(9999999), bearing = null;
  for (const opponent of opponents) {
    const dx = r(f(opponent.position[0]) - f(playerPosition[0]));
    const dz = r(f(opponent.position[2]) - f(playerPosition[2]));
    const distance = r(r(dx * dx) + r(dz * dz));
    if (!(distance < 10000) || !(f(distance) < nearestDistance)) continue;
    nearestDistance = f(distance);
    let x = r(f(playerPosition[0]) - f(opponent.position[0]));
    const z = f(r(f(playerPosition[2]) - f(opponent.position[2])));
    if (x > 0 && x < f(.1)) x = f(.1);
    else if (x < 0 && x > f(-.1)) x = f(-.1);
    const angle = f(r(r(Math.atan(r(z / x)) * f(1 / (2 * Math.PI))) * 4096));
    let relative = r(r(angle + (x > 0 ? 3072 : 1024)) - f(opponent.yaw));
    if (relative > 2048) relative = r(relative - 4096);
    if (relative < -2048) relative = r(relative + 4096);
    // Original __ftol uses a 64-bit FISTP. Integer-indefinite's low32 is zero.
    bearing = Number.isFinite(relative) ? Math.trunc(relative) : 0;
  }
  if (bearing !== null && bearing < -400)
    return [{name: 'idle_left', from: 0, to: 3}, {name: 'left', from: 3, to: 3}];
  if (bearing !== null && bearing > 400)
    return [{name: 'idle_right', from: 0, to: 4}, {name: 'right', from: 4, to: 4}];
  return [{name: 'right_idle', from: 4, to: 0}, {name: 'left_idle', from: 3, to: 0}];
}

/** 0x4362f0, called by player non-star collection before render's next tick. */
export function getPlayerAnimationEventRequests({callback, completed = false}) {
  callback = typeof callback === 'number' ? callback : parseInt(callback, 16);
  if (callback === 0x4362f0) return completed ? [] : [{name: 'cheer', enqueue: true}];
  // Player435aa0 invokes the same four hit initializers as NPC40d310.
  if ([0x411830, 0x411b40, 0x411e50, 0x412090].includes(callback))
    return [{name: 'hit', enqueue: true}];
  throw new Error(`Unmapped native player animation callback: ${callback?.toString(16)}`);
}

// These events are emitted by the NPC controller, not inferred from a driver's
// physical lateral speed. The two steering callbacks have different deadbands.
export function getNPCAnimationEventRequests({callback, argument = 0, fsmState = 0}) {
  callback = typeof callback === 'number' ? callback : parseInt(callback, 16);
  const requests = [], add = (name, from, to) => requests.push({name, from, to});
  if (callback === 0x40c0c0 || callback === 0x40c370) {
    argument |= 0;
    if (callback === 0x40c370 && argument >= -999 && argument <= 999) {
      add('right_idle', 4, 0); add('left_idle', 3, 0);
    } else if (argument < 0) {
      add('idle_right', 0, 4); add('right', 4, 4);
    } else {
      add('idle_left', 0, 3); add('left', 3, 3);
    }
  } else if (callback === 0x40dc10) {
    if (fsmState !== 9) { add('turbo', 6, 6); add('idle_turbo', 0, 6); }
  } else if (callback === 0x40de60 || callback === 0x40d610) {
    if (fsmState !== 9) requests.push({name: 'cheer', enqueue: true});
  } else if ([0x411830, 0x411b40, 0x411e50, 0x412090].includes(callback)) {
    requests.push({name: 'hit', enqueue: true});
  } else throw new Error(`Unmapped native NPC animation callback: ${callback?.toString(16)}`);
  return requests;
}

// 0040e760's clock is in seconds (0048f4d0), unlike player 004325b0.
// The simulation owns clearing its turbo flag on expiry; this helper is pure.
export function getNPCTurboAnimationRequests({
  turboActive = false, turboStartedSeconds = 0, nowSeconds = 0, precision = NATIVE_PRECISION,
} = {}) {
  if (!turboActive) return [];
  const difference = Math.fround(nowSeconds) - Math.fround(turboStartedSeconds);
  const age = precision === 24 ? Math.fround(difference) : difference;
  return age < 5
    ? [{name: 'turbo', from: 6, to: 6}, {name: 'idle_turbo', from: 0, to: 6}]
    : [{name: 'turbo_idle', from: 6, to: 0}, {name: 'idle', from: 0, to: 0}];
}

// 0040b0b0: the FSM submits events first, followed by turbo, finish and idle.
// Supply events once, in simulation order. For an isolated damage/event
// callback outside the normal update, use getNPCAnimationEventRequests.
export function getNPCDrivingAnimationRequests({
  events = [], racePhase = 0, rank = 1, ...turbo
} = {}) {
  const requests = events.flatMap(getNPCAnimationEventRequests);
  requests.push(...getNPCTurboAnimationRequests(turbo));
  if (racePhase === 3 && rank === 0) requests.push({name: 'cheer', from: 0, to: 0});
  requests.push({name: 'turbo_idle', from: 6, to: 0}, {name: 'right_idle', from: 4, to: 0},
    {name: 'left_idle', from: 3, to: 0}, {name: 'idle', from: 0, to: 0});
  return requests;
}

export function createDriverAnimation(driver) {
  const clocks = Object.fromEntries(Object.entries(driver.sequences).map(([name, sequence]) =>
    [name, createNativeMeshAnimation(sequence, 0)]));
  const initial = driver.initialSequence ?? 'idle';
  return {driver, clocks, queue: [initial], nativeState: 0,
    displayedFrame: driver.sequences[initial].frames[0], displayedSequence: initial};
}

// 0044ce90 only accepts a state-matching request with an empty queue.
// 0044f390/0044eb90 reset frame and completed loops, preserving the per-sequence
// timestamp and ping-pong direction. An accepted transition changes state now.
export function requestDriverAnimation(state, {name, from, to, enqueue = false}) {
  name = key(name);
  if (!enqueue && (state.nativeState !== from || state.queue.length)) return false;
  const clock = state.clocks[name];
  if (!clock) throw new Error(`Missing original driver sequence: ${name}`);
  if (!enqueue) state.nativeState = to;
  state.queue.push(name);
  // 0044f390 appends then restarts the existing queue HEAD, not the newly
  // appended clip. Hit/cheer requests use this unconditional entrypoint.
  const head = state.clocks[state.queue[0]];
  head.frame = 0;
  head.completedLoops = 0;
  return true;
}

// Call once per native simulation tick, after submitting gameplay requests.
// 0044f110 removes a completed sequence before 0044cac0 assigns its mesh:
// if the queue empties, the last displayed mesh remains until another request.
export function advanceDriverAnimation(state, nowMs, requests = []) {
  for (const request of requests) requestDriverAnimation(state, request);
  if (!state.queue.length) return state.displayedFrame;
  const name = state.queue[0], clock = state.clocks[name];
  const frame = advanceNativeMeshAnimation(clock, nowMs);
  if (clock.sequence.loops >= 0 && clock.completedLoops === clock.sequence.loops) {
    state.queue.shift();
    // 44f110 restarts the new head (or sequence0 when now empty), preserving
    // its timestamp/direction. 44cac0 then displays the new head this callback.
    const nextName = state.queue[0] ?? Object.keys(state.clocks)[0];
    const next = state.clocks[nextName];
    next.frame = 0;
    next.completedLoops = 0;
    if (state.queue.length) {
      state.displayedSequence = nextName;
      state.displayedFrame = next.sequence.frames[0];
    }
  } else {
    state.displayedSequence = name;
    state.displayedFrame = frame;
  }
  return state.displayedFrame;
}
