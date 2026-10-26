import { nativeTrigTable } from './native-integrator.js';
import { advanceNativeArmAudio } from '../arm-audio.js';

const f = Math.fround;
const baseVertices = [[-.5, .5, 0], [.5, .5, 0], [0, 0, 0]];
const textureUV = [[.4296875, .1328125], [.453125, .1328125], [.453125, .15625]];
const identity = () => [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
const translate = ([x, y, z]) => {
  const result = identity();
  result.splice(12, 3, x, y, z);
  return result;
};
const matrixOf = body => body.matrix.length === 16 ? body.matrix : [
  ...body.matrix.slice(0, 3), 0, ...body.matrix.slice(3, 6), 0,
  ...body.matrix.slice(6, 9), 0, ...body.position, 1,
];

function planarDistanceSquared(a, b, r) {
  const x = r(a[0] - b[0]), z = r(a[2] - b[2]);
  return r(r(z * z) + r(x * x));
}

/** 0x486ac0/0x486b20. This effect is attached to the shot's TARGET body. */
export function createNativeHomingArm(body, shot, {precision = 24, offset = [0, 25, -33], size = 10} = {}) {
  const r = precision === 24 ? f : Number;
  return {body, shot, active: true, offset: offset.map(f), size: f(size),
    scale: f(1.5), count: 2, growthAngle: 0, angle: 0, timer: 0,
    initialDistanceSquared: f(planarDistanceSquared(body.position, shot.position, r)),
    colors: [0, 80, 160], ratio: 1,
    // The native constructor leaves these buffers uninitialized. Zero is an
    // explicit deterministic storage policy until each native vertex is written.
    vertices: Array.from({length: 48}, () => ({
      position: [0, 0, 0], color: 0, specular: 0, uv: [0, 0],
    }))};
}

/** Original0x4a2560 takes matrices in the reverse order to their row product. */
function multiply(a, b, r) {
  return Array.from({length: 16}, (_, index) => {
    const row = Math.floor(index / 4), col = index % 4;
    let sum = 0;
    for (let k = 0; k < 4; k++) sum = r(r(a[k * 4 + col] * b[row * 4 + k]) + sum);
    return f(sum);
  });
}

/** 0x487740→0x486ea0/0x486d50/0x486cc0, before rendering and shot motion. */
export function updateNativeHomingArm(entry, deltaSeconds, {precision = 24, player = true} = {}) {
  if (!entry.active) return null;
  const r = precision === 24 ? f : Number, dt = f(deltaSeconds);
  const velocity = entry.count === 8 ? 35 : 45;
  const increment = r(r(60 / r(1 / dt)) * velocity);
  const wrap = angle => {
    const next = r(increment + angle);
    return f(next > 4096 ? r(next - 4096) : next);
  };
  entry.angle = wrap(entry.angle);
  entry.growthAngle = wrap(entry.growthAngle);
  if (entry.count < 8 && entry.growthAngle > 512) {
    entry.count++;
    entry.growthAngle = f(r(entry.growthAngle - 512));
  }

  // Geometry uses the PREVIOUS callback's scale, before recalculating ratio.
  const bodyMatrix = matrixOf(entry.body), offset = translate(entry.offset);
  const scale = identity();
  scale[0] = scale[5] = entry.size;
  const lower = multiply(scale, translate([0, entry.scale, 0]), r);
  const upper = multiply(scale, translate([0, f(r(entry.scale + .5)), 0]), r);
  const {sin, cos} = nativeTrigTable(precision);
  for (let ring = 0; ring < entry.count; ring++) {
    let positive = r(r(ring * 512) + entry.angle);
    const negative = f(r(4096 - f(positive)));
    if (positive > 4096) positive = r(positive - 4096);
    if (positive < 0) positive = r(positive + 4096);
    const matrices = [upper, lower].map((translation, side) => {
      const index = Math.trunc(side === 0 ? negative : positive) & 4095;
      const c = cos[index], s = sin[index];
      const rotation = [c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
      const transformedOffset = multiply(offset, rotation, r);
      return multiply(bodyMatrix, multiply(transformedOffset, translation, r), r);
    });
    for (let side = 0; side < 2; side++) for (let v = 0; v < 3; v++) {
      const matrix = matrices[side], [x, y, z] = baseVertices[v];
      entry.vertices[side * 24 + ring * 3 + v].position = [0, 1, 2].map(axis =>
        f(r(r(r(r(x * matrix[axis]) + r(y * matrix[4 + axis])) +
          r(z * matrix[8 + axis])) + matrix[12 + axis])));
    }
  }

  const ratio = r(planarDistanceSquared(entry.body.position, entry.shot.position, r) / entry.initialDistanceSquared);
  entry.ratio = f(ratio);
  entry.scale = f(r(ratio * f(1.5)));
  const audio = advanceNativeArmAudio({timer: entry.timer, deltaSeconds: dt,
    ratio: entry.ratio, player, precision});
  entry.timer = audio.timer;
  // FCOMP tests C0, so an unordered (0/0) ratio also retires the effect.
  if (Number.isNaN(entry.scale) || entry.scale > r(f(1.5) + f(.01))) {
    entry.active = false;
    entry.scale = f(1.5);
  }

  // 0x486d50: unsigned color overflow is intentional.
  let tipColor = r(r(1 - r(entry.scale / f(1.5))) * 255);
  if (tipColor < 25) tipColor = 40;
  entry.colors = entry.colors.map(value => (value + 10) >>> 0);
  for (let ring = 0; ring < entry.count; ring++) for (let v = 0; v < 3; v++) {
    const color = entry.colors[v], channel = Math.imul(v + 1, color);
    const first = (((((Math.imul(ring + v, color) | 0xffffc800) << 8) |
      Math.imul(ring + 1, channel)) << 8) | channel) >>> 0;
    entry.vertices[ring * 3 + v].color = first;
    entry.vertices[24 + ring * 3 + v].color = v === 2
      ? ((Math.trunc(tipColor) | 0xffffc800) << 16) >>> 0 : 0xc8ff0000;
    entry.vertices[ring * 3 + v].specular = entry.vertices[24 + ring * 3 + v].specular = 0x64000000;
  }
  for (let side = 0; side < 2; side++) for (let vertex = 0; vertex < 24; vertex++)
    entry.vertices[side * 24 + vertex].uv = [...textureUV[vertex % 3]];
  return audio.sample;
}

/** 0x4879c0 preserves the original loop bound after shrinking its vector.
 * A stale trailing copy can still update/queue sound, while the copied live
 * record retains its pre-update fields. Body/shot are native external pointers. */
export function advanceNativeArmQueue(entries, update) {
  const storage = [...entries], count = storage.length;
  let remaining = count;
  for (let index = 0; index < count; index++) {
    if (!update(storage[index])) continue;
    const {body, shot, ...fields} = storage[--remaining];
    storage[index] = {...structuredClone(fields), ...(body ? {body} : {}), ...(shot ? {shot} : {})};
  }
  return storage.slice(0, remaining);
}

/** Original manager0x487af0/0x4879c0/0x487c00; one entry per target body. */
export class NativeHomingArms {
  constructor({actors, voices = null, jetstreams = true, alphaBlending = true,
    paletted = false, precision = 24}) {
    Object.assign(this, {actors, voices, jetstreams, alphaBlending, paletted, precision});
    this.entries = [];
  }
  get enabled() { return this.jetstreams && this.alphaBlending && !this.paletted; }
  targetRacer(shot) {
    return shot.target >= 0 && shot.target < this.actors.length - 1 ? shot.target : this.actors.length - 1;
  }
  create(shot) {
    if (!this.enabled || shot.type !== 1 || shot.level <= 1 || this.entries.length >= 20) return null;
    const racer = this.targetRacer(shot), body = this.actors[racer].body;
    if (this.entries.some(entry => entry.body === body)) return null;
    const entry = createNativeHomingArm(body, shot, {precision: this.precision});
    entry.racer = racer;
    this.entries.push(entry);
    return entry;
  }
  remove(shot) {
    if (!this.jetstreams) return;
    const body = this.actors[this.targetRacer(shot)].body;
    const index = this.entries.findIndex(entry => entry.body === body);
    if (index < 0) return;
    const last = this.entries.pop();
    if (index < this.entries.length) this.entries[index] = last;
  }
  step(deltaSeconds) {
    if (!this.enabled) return this.entries;
    this.entries = advanceNativeArmQueue(this.entries, entry => {
      // 487740 returns false for an already inactive entry.
      if (!entry.active) return false;
      const sample = updateNativeHomingArm(entry, deltaSeconds, {
        precision: this.precision, player: entry.racer === this.actors.length - 1,
      });
      if (sample && this.voices) this.voices.submit(this.voices.voiceId(entry.racer), sample);
      return !entry.active;
    });
    return this.entries;
  }
}
