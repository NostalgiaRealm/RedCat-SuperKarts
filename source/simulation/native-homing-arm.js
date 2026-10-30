import { nativeTrigTable } from './native-integrator.js';
import { advanceNativeArmAudio } from '../arm-audio.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f = Math.fround;
const baseVertices = [[-.5, .5, 0], [.5, .5, 0], [0, 0, 0]];
const textureUV = [[.4296875, .1328125], [.453125, .1328125], [.453125, .15625]];
const matrix4 = () => Float64Array.of(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
// Filled completely before each read and never retained: one native update at a time.
const poseScratch = matrix4(), offsetScratch = matrix4(), scaleScratch = matrix4(), lowerScratch = matrix4(), upperScratch = matrix4();
const shiftScratch = matrix4(), spinScratch = matrix4(), productA = matrix4(), productB = matrix4(), sideScratch = [matrix4(), matrix4()];
const translate = (out, x, y, z) => { out[12] = x; out[13] = y; out[14] = z; return out; };
// 0x486ec0 copies the render-object matrix, which a rescue scales in place.
const matrixOf = (body, renderPose) => {
  const pose = renderPose?.(body) ?? body;
  const matrix = pose.matrix ?? body.matrix, position = pose.position ?? body.position;
  if (matrix.length === 16) return matrix;
  const m = poseScratch;
  m[0] = matrix[0]; m[1] = matrix[1]; m[2] = matrix[2];
  m[4] = matrix[3]; m[5] = matrix[4]; m[6] = matrix[5];
  m[8] = matrix[6]; m[9] = matrix[7]; m[10] = matrix[8];
  m[12] = position[0]; m[13] = position[1]; m[14] = position[2];
  return m;
};

function planarDistanceSquared(a, b, r) {
  const x = r(a[0] - b[0]), z = r(a[2] - b[2]);
  return r(r(z * z) + r(x * x));
}

/** 0x486ac0/0x486b20. This effect is attached to the shot's TARGET body. */
export function createNativeHomingArm(body, shot, {precision = NATIVE_PRECISION, offset = [0, 25, -33], size = 10} = {}) {
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
function multiply(a, b, r, out) {
  for (let row = 0; row < 4; row++) for (let col = 0; col < 4; col++) {
    let sum = 0;
    for (let k = 0; k < 4; k++) sum = r(r(a[k * 4 + col] * b[row * 4 + k]) + sum);
    out[row * 4 + col] = f(sum);
  }
  return out;
}

/** 0x487740→0x486ea0/0x486d50/0x486cc0, before rendering and shot motion. */
export function updateNativeHomingArm(entry, deltaSeconds, {precision = NATIVE_PRECISION, player = true, renderPose} = {}) {
  if (!entry.active) return null;
  const r = precision === 24 ? f : Number, dt = f(deltaSeconds);
  const velocity = entry.count === 8 ? 35 : 45;
  const increment = r(r(60 / r(1 / dt)) * velocity);
  const nextAngle = r(increment + entry.angle), nextGrowth = r(increment + entry.growthAngle);
  entry.angle = f(nextAngle > 4096 ? r(nextAngle - 4096) : nextAngle);
  entry.growthAngle = f(nextGrowth > 4096 ? r(nextGrowth - 4096) : nextGrowth);
  if (entry.count < 8 && entry.growthAngle > 512) {
    entry.count++;
    entry.growthAngle = f(r(entry.growthAngle - 512));
  }

  // Geometry uses the PREVIOUS callback's scale, before recalculating ratio.
  const bodyMatrix = matrixOf(entry.body, renderPose), offset = translate(offsetScratch, entry.offset[0], entry.offset[1], entry.offset[2]);
  scaleScratch[0] = scaleScratch[5] = entry.size;
  const lower = multiply(scaleScratch, translate(shiftScratch, 0, entry.scale, 0), r, lowerScratch);
  const upper = multiply(scaleScratch, translate(shiftScratch, 0, f(r(entry.scale + .5)), 0), r, upperScratch);
  const {sin, cos} = nativeTrigTable(precision), vertices = entry.vertices;
  for (let ring = 0; ring < entry.count; ring++) {
    let positive = r(r(ring * 512) + entry.angle);
    const negative = f(r(4096 - f(positive)));
    if (positive > 4096) positive = r(positive - 4096);
    if (positive < 0) positive = r(positive + 4096);
    for (let side = 0; side < 2; side++) {
      const index = Math.trunc(side === 0 ? negative : positive) & 4095;
      spinScratch[0] = spinScratch[5] = cos[index]; spinScratch[1] = -sin[index]; spinScratch[4] = sin[index];
      const matrix = multiply(bodyMatrix, multiply(multiply(offset, spinScratch, r, productA), side === 0 ? upper : lower, r, productB), r, sideScratch[side]);
      for (let v = 0; v < 3; v++) {
        const base = baseVertices[v], x = base[0], y = base[1], z = base[2], position = vertices[side * 24 + ring * 3 + v].position;
        for (let axis = 0; axis < 3; axis++)
          position[axis] = f(r(r(r(r(x * matrix[axis]) + r(y * matrix[4 + axis])) +
            r(z * matrix[8 + axis])) + matrix[12 + axis]));
      }
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
  const colors = entry.colors;
  colors[0] = (colors[0] + 10) >>> 0; colors[1] = (colors[1] + 10) >>> 0; colors[2] = (colors[2] + 10) >>> 0;
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
    { const uv = entry.vertices[side * 24 + vertex].uv, source = textureUV[vertex % 3]; uv[0] = source[0]; uv[1] = source[1]; }
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
    paletted = false, precision = NATIVE_PRECISION}) {
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
  /** The rescue update 0x42f618 precedes this 0x42f648 arm update. */
  step(deltaSeconds, {renderPose} = {}) {
    if (!this.enabled || !this.entries.length) return this.entries;
    this.entries = advanceNativeArmQueue(this.entries, entry => {
      // 487740 returns false for an already inactive entry.
      if (!entry.active) return false;
      const sample = updateNativeHomingArm(entry, deltaSeconds, {
        precision: this.precision, player: entry.racer === this.actors.length - 1, renderPose,
      });
      if (sample && this.voices) this.voices.submit(this.voices.voiceId(entry.racer), sample);
      return !entry.active;
    });
    return this.entries;
  }
}
