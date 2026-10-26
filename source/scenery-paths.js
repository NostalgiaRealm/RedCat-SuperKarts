const f = Math.fround;
const key = value => String(value).trim().toLowerCase().replace(/_anim$/, '');
const registeredTypes = new Set([3, 6, 9, 10, 12, 13, 46, 47]);

/** 00446710 splits PATH_OBJECTS flags: bit1 repeats, bit0 closes the curve.
 * 0043e140/0044f9c0 retains the last registered placement for each animation. */
export function getNativeSceneryPaths(track) {
  return track.paths.map((path, index) => {
    const name = track.pathTypes[String(path.type)], row = track.pathObjects[key(name)];
    if (!row) return null; // Built-in camera paths have their own controller.
    const [animation, flagsText = '0'] = row.split(',').map(value => value.trim()), flags = Number(flagsText);
    let placementIndex = -1;
    track.placements.forEach((placement, i) => {
      if (registeredTypes.has(placement.type) && key(placement.animation) === key(animation)) placementIndex = i;
    });
    if (placementIndex < 0) throw new Error(`Native path ${index}: registered object ${animation} is absent`);
    return {...path, index, name, animation: key(animation), placementIndex,
      repeat: !!(flags & 2), closed: !!(flags & 1), tension: .5};
  }).filter(Boolean);
}

/** 00445740 freezes a tick count using the delta at activation, then 004450c0
 * rounds it DOWN to a multiple of the number of curve segments. */
export function nativePathDurationTicks(path, deltaSeconds, precision = 24) {
  const r = precision === 24 ? f : Number;
  const ticks = Math.trunc(r(f(r(path.durationMs * f(.001))) / f(deltaSeconds)));
  const segments = path.points.length - (path.closed ? 0 : 1);
  return Math.trunc(ticks / segments) * segments;
}

/** Literal Hermite basis and reverse accumulation order of 00445530. */
export function nativePathHermite(values, tick, duration, precision = 24) {
  const r = precision === 24 ? f : Number, t = f(r(tick / duration));
  const t2 = r(t * t), t3 = r(t2 * t);
  const h00 = f(r(r(f(r(t3 + t3)) - r(t2 * 3)) + 1));
  const h01 = f(r(r(t2 * 3) + f(r(t3 * -2))));
  const h10 = f(r(r(f(t3) - r(t2 + t2)) + t));
  const h11 = r(f(t3) - t2);
  return f(r(r(r(r(h11 * values[3]) + r(h10 * values[2])) + r(h01 * values[1])) + r(h00 * values[0])));
}

/** 00445120 preserves source endpoint clamping, closed wrapping and the
 * late-sample duration extension. Coordinates stay in native XYZ units. */
export function sampleNativeSceneryPath(path, ticks, tick, precision = 24) {
  const points = path.points, count = points.length, r = precision === 24 ? f : Number;
  if (count === 1) return [...points[0].position];
  let duration = Math.trunc(ticks / (count - (path.closed ? 0 : 1)));
  if (duration < 1) throw new RangeError('Native path duration has no complete segment');
  let index = Math.min(Math.trunc(tick / duration), count - (path.closed ? 1 : 2));
  let within = Math.max(0, tick - index * duration);
  if (within >= duration) duration = within + 1;
  let before = index - 1, after = index + 1, following = index + 2;
  if (!path.closed) {
    before = Math.max(0, before); after = Math.min(count - 1, after); following = Math.min(count - 1, following);
  } else {
    if (before < 0) before = count - 1;
    if (after > count - 1) { after = 0; following = 1; }
    else if (following > count - 1) following = 0;
  }
  return [0, 1, 2].map(axis => nativePathHermite([
    points[index].position[axis], points[after].position[axis],
    f(r(r(points[after].position[axis] - points[before].position[axis]) * f(path.tension ?? .5))),
    f(r(r(points[following].position[axis] - points[index].position[axis]) * f(path.tension ?? .5))),
  ], within, duration, precision));
}

/** 00446dd0 advances one tick regardless of subsequent delta changes. */
export function advanceNativeSceneryPath(state, playerSector, precision = 24) {
  const r = precision === 24 ? f : Number, {path} = state;
  state.poseWritten = false;
  if (state.tick >= state.durationTicks - 2 && path.repeat) state.tick = 0;
  state.sector = playerSector;
  if (state.tick < state.durationTicks - 2) {
    const position = sampleNativeSceneryPath(path, state.durationTicks, state.tick, precision);
    const next = sampleNativeSceneryPath(path, state.durationTicks, state.tick + 1, precision);
    const angle = r(Math.atan2(r(next[2] - position[2]), r(next[0] - position[0])));
    state.yaw = f(r(r(r(angle - r(f(Math.PI) * f(.5))) * 4096) / f(2 * Math.PI)));
    state.position = position;
    state.poseWritten = true;
    state.tick++;
  }
  if (path.endSector !== 0 && path.endSector === playerSector) {
    state.active = false;
    state.visible = false;
  }
  return state;
}

/** 00445900/004458c0: sector changes trigger once per lap, then update ten
 * slots in allocation order. Movement is after the original render boundary. */
export class NativeSceneryPaths {
  constructor(track, {precision = 24} = {}) {
    this.track = track;
    this.paths = getNativeSceneryPaths(track);
    this.precision = precision;
    this.previousSector = -1;
    this.previousLap = 0;
    this.started = new Set();
    this.slots = Array(10).fill(null);
    this.objects = new Map(this.paths.map(path => {
      const placement = track.placements[path.placementIndex];
      return [path.placementIndex, {position: [...placement.position],
        yaw: f(placement.nativeRotationDegrees[1] * 4096 / 360), sector: placement.sector,
        visible: true, poseRevision: 0, stopRevision: 0, updateRevision: 0}];
    }));
  }

  step({playerSector, lapCount = 0, deltaSeconds}) {
    if (playerSector !== this.previousSector) {
      this.previousSector = playerSector;
      if (lapCount !== this.previousLap) { this.started.clear(); this.previousLap = lapCount; }
      for (const path of this.paths) {
        if (path.startSector === 0 || path.startSector !== playerSector || this.started.has(path.index)
          || (path.unknown !== 0 && path.unknown !== lapCount + 1)) continue;
        const object = this.objects.get(path.placementIndex);
        object.visible = true;
        const slot = this.slots.findIndex(entry => !entry);
        // 00446c00 reports success even if 00445740 cannot allocate a slot.
        if (slot >= 0) this.slots[slot] = {path, tick: 0,
          durationTicks: nativePathDurationTicks(path, deltaSeconds, this.precision),
          active: true, ...object};
        this.started.add(path.index);
      }
    }
    for (let i = 0; i < this.slots.length; i++) {
      const state = this.slots[i];
      if (!state) continue;
      advanceNativeSceneryPath(state, playerSector, this.precision);
      const object=this.objects.get(state.path.placementIndex);
      Object.assign(object,{sector:state.sector,visible:state.visible});
      object.updateRevision++;
      if(state.poseWritten){
        object.position=[...state.position];object.yaw=state.yaw;object.poseRevision++;
      }
      if(!state.active)object.stopRevision++;
      if (!state.active) this.slots[i] = null;
    }
    return this.objects;
  }
}
