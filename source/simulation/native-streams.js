import { nativeTrigTable } from './native-integrator.js';
import { NATIVE_PRECISION } from './native-precision.js';

const f = Math.fround;
export const NATIVE_STREAM_COLORS = [
  [49, 255, 165], [49, 255, 248], [49, 78, 255],
  [255, 243, 49], [255, 49, 64], [255, 49, 243],
];
export const NATIVE_RACER_STREAM_OFFSET = [0, 10, -28]; // 0x489300
export const NATIVE_SHOT_STREAM_OFFSET = [0, 0, -15]; // 0x489350
const jetPoints = [[-.5, -.5, 0], [-.5, .5, 0], [.5, -.5, 0], [.5, .5, 0],
  [.5, -.5, 0], [-.5, .5, 0], [-.5, -.5, 0]];
const jetUV = [[.4921875, .984375], [.4921875, .4921875], [.984375, .984375],
  [.984375, .4921875], [.984375, .984375], [.4921875, .4921875], [.4921875, .984375]];
const shrinkFactors = [.4, 1.8, 1.8, 1.2, 1, .8];
const ribbonInnerU = f(.88);
const matrix4 = () => Float64Array.of(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
// Filled completely before each read and never retained: one native update at a time.
const poseScratch = matrix4(), translateScratch = matrix4(), rotateScratch = matrix4(), scaleScratch = matrix4();
const productA = matrix4(), productB = matrix4(), productC = matrix4();
const translate = xyz => {
  translateScratch[12] = xyz[0]; translateScratch[13] = xyz[1]; translateScratch[14] = xyz[2];
  return translateScratch;
};
const matrixOf = (body, renderPose) => {
  const pose = renderPose?.(body) ?? body;
  const matrix = pose.matrix ?? body.matrix;
  const position = pose.position ?? body.position;
  if (matrix.length === 16) return matrix;
  const m = poseScratch;
  m[0] = matrix[0]; m[1] = matrix[1]; m[2] = matrix[2];
  m[4] = matrix[3]; m[5] = matrix[4]; m[6] = matrix[5];
  m[8] = matrix[6]; m[9] = matrix[7]; m[10] = matrix[8];
  m[12] = position[0]; m[13] = position[1]; m[14] = position[2];
  return m;
};
const packed = rgb => ((rgb[0] | 0xffffff00) << 16 | rgb[1] << 8 | rgb[2]) >>> 0;
const vertex = position => ({position, color: 0, specular: 0, uv: [0, 0]});
// Retired ribbon vertices are reused by the next update; packets never outlive a tick.
const freeVertices = [];
const takeVertex = () => {
  const v = freeVertices.pop() ?? vertex([0, 0, 0]);
  v.specular = 0;
  return v;
};
const retire = (points, from) => {
  for (let i = from; i < points.length; i++) if (freeVertices.length < 512) freeVertices.push(points[i]);
  points.length = from;
};

// Original 0x4a2560 reverses the arguments relative to row-matrix product.
function multiply(a, b, r, out) {
  for (let row = 0; row < 4; row++) for (let col = 0; col < 4; col++) {
    let sum = 0;
    for (let k = 0; k < 4; k++) sum = r(r(a[k * 4 + col] * b[row * 4 + k]) + sum);
    out[row * 4 + col] = f(sum);
  }
  return out;
}
function transform(out, x, y, z, matrix, r) {
  for (let axis = 0; axis < 3; axis++)
    out[axis] = f(r(r(r(r(x * matrix[axis]) + r(y * matrix[4 + axis])) +
      r(z * matrix[8 + axis])) + matrix[12 + axis]));
  return out;
}
function rotation(angle, precision) {
  const {sin, cos} = nativeTrigTable(precision), index = Math.trunc(angle) & 4095, m = rotateScratch;
  m[0] = cos[index]; m[1] = -sin[index]; m[4] = sin[index]; m[5] = cos[index];
  return m;
}

/** 0x488100/0x488210. Initial untouched vertex memory is explicitly zeroed. */
export function createNativeJetFlare(body, {offset = NATIVE_RACER_STREAM_OFFSET,
  clockwise = true, colorIndex = 0, rainbow = false, crossed = false, size = 20} = {}) {
  return {body, active: true, offset: offset.map(f), clockwise, colorIndex:
    colorIndex >= 0 && colorIndex < 6 ? colorIndex : 0, rainbow, crossed,
  size: f(size), angle: 0, vertices: Array.from({length: crossed ? 7 : 4}, () => vertex([0, 0, 0]))};
}

/** 0x488850 -> 0x4885c0/0x4884d0/0x488440, once per native update. */
export function updateNativeJetFlare(entry, {player = false, throttle = 0, precision = NATIVE_PRECISION, renderPose} = {}) {
  if (!entry.active) return;
  const r = precision === 24 ? f : Number;
  const size = f(r(f(player ? r(f(throttle) * f(.2)) : 5) + entry.size));
  entry.angle += entry.clockwise ? 15 : -15;
  if (entry.angle > 4096) entry.angle -= 4096;
  if (entry.angle < 0) entry.angle += 4096;
  scaleScratch[0] = scaleScratch[5] = size;
  const pose = matrixOf(entry.body, renderPose);
  const matrix = multiply(pose, multiply(multiply(translate(entry.offset), rotation(entry.angle, precision), r, productA),
    scaleScratch, r, productB), r, productC);
  let color = NATIVE_STREAM_COLORS[entry.colorIndex];
  if (entry.rainbow) {
    const previous = entry.vertices[0].color;
    color = [(previous >>> 16) & 255, (previous >>> 8) & 255, previous & 255]
      .map((value, i) => value + [45, 65, 85][i] > 255 ? 0 : value + [45, 65, 85][i]);
  }
  const argb = packed(color), vertices = entry.vertices;
  for (let i = 0; i < vertices.length; i++) {
    const v = vertices[i], point = jetPoints[i], uv = jetUV[i];
    transform(v.position, point[0], point[1], point[2], matrix, r);
    v.color = argb; v.specular = 0; v.uv[0] = uv[0]; v.uv[1] = uv[1];
  }
}

/** 0x489400/0x4894c0. Rainbow channels left uninitialized by native constructor
 * use an explicit zero-storage policy; red starts200 as the constructor writes. */
export function createNativeRibbon(body, {offset = NATIVE_RACER_STREAM_OFFSET,
  rotate = false, colorIndex = 0, rainbow = false, doubleSided = false,
  size = 20, flare = true, fastShrink = true} = {}) {
  if (!rainbow) {
    if (colorIndex >= 6) colorIndex -= 6;
    if (colorIndex < 0 || colorIndex >= 6) colorIndex = 0;
  }
  return {body, active: true, offset: offset.map(f), rotate, colorIndex, rainbow,
    doubleSided: rotate || doubleSided, size: f(size), flare, fastShrink,
    angle: 0, colors: [200, 0, 0], vertices: []};
}

/** 0x489d20/0x489c70: prepend two points; player uses stored integer speed. */
export function updateNativeRibbon(entry, deltaSeconds,
  {player = false, speedKmh = 0, precision = NATIVE_PRECISION, renderPose} = {}) {
  if (!entry.active || (player && speedKmh <= 0)) return;
  const r = precision === 24 ? f : Number;
  const vertices = entry.vertices;
  if (vertices.length + 2 > 999) retire(vertices, vertices.length - 2);
  let matrix, halfWidth = 10;
  if (entry.rotate) {
    const next = r(r(r(60 / r(1 / f(deltaSeconds))) * 100) + entry.angle);
    entry.angle = f(next > 4096 ? r(next - 4096) : next);
    const pose = matrixOf(entry.body, renderPose);
    matrix = multiply(pose, multiply(translate(entry.offset), rotation(entry.angle, precision), r, productA), r, productB);
    halfWidth = f(r(entry.size * .5));
  } else matrix = multiply(matrixOf(entry.body, renderPose), translate(entry.offset), r, productB);
  // Native always uses -10 for the second endpoint, even with rotating size!=20.
  const first = takeVertex(), second = takeVertex();
  transform(first.position, -10, 0, 0, matrix, r);
  transform(second.position, halfWidth, 0, 0, matrix, r);
  vertices.unshift(first, second);
  let rgb = NATIVE_STREAM_COLORS[entry.colorIndex];
  if (entry.rainbow) {
    const c = entry.colors;
    c[0] = c[0] + 25 > 255 ? 0 : c[0] + 25;
    c[1] = c[1] + 75 > 255 ? 0 : c[1] + 75;
    c[2] = c[2] + 125 > 255 ? 0 : c[2] + 125;
    rgb = c;
  }
  const v = vertices.length % 2 ? .1640625 : .1484375;
  first.color = second.color = packed(rgb);
  first.uv[0] = ribbonInnerU; first.uv[1] = v; second.uv[0] = .984375; second.uv[1] = v;
}

/** 0x489f50 runs inside DRAW 0x48a170, not the effect-update callback. */
export function shrinkNativeRibbon(entry, {precision = NATIVE_PRECISION} = {}) {
  if (!entry.active) return;
  const r = precision === 24 ? f : Number, points = entry.vertices;
  const count = points.length;
  for (let i = 0; i < count - 1; i += 2) {
    const a = points[i].position, b = points[i + 1].position;
    let factor = f(i < 6 && count > 12 ? shrinkFactors[i] : .7);
    if (entry.fastShrink) factor = r(factor * f(.7));
    const cx = r(r(a[0] + b[0]) * .5), cy = f(r(r(a[1] + b[1]) * .5)), cz = f(r(r(a[2] + b[2]) * .5));
    const dx = r(a[0] - cx), dy = r(a[1] - cy), dz = r(a[2] - cz);
    const distance = r(r(r(dx * dx) + r(dy * dy)) + r(dz * dz));
    if (distance < .25) {
      retire(points, i);
      return;
    }
    a[0] = f(r(r(f(dx) * factor) + cx)); a[1] = f(r(r(f(dy) * factor) + cy)); a[2] = f(r(r(dz * factor) + cz));
    b[0] = f(r(r(r(b[0] - cx) * factor) + cx)); b[1] = f(r(r(r(b[1] - cy) * factor) + cy)); b[2] = f(r(r(r(b[2] - cz) * factor) + cz));
  }
}

/** 0x48a170 second strip excludes the last original vertex before reversing. */
export function nativeRibbonDrawPackets(entry) {
  if (!entry.active) return [];
  const packets = entry.vertices.length > 3 ? [entry.vertices] : [];
  if (entry.doubleSided && entry.vertices.length - 1 > 3)
    packets.push(entry.vertices.slice(0, -1).reverse());
  return packets;
}

/** Original42d7d0/428cc0 baseline and4537f0 turbo setup arguments. */
export function nativeRacerStreamOptions(racer, level = 0) {
  if (level === 3) return [-18, 18].map(x => ({
    offset: [x, 12, -12], rotate: true, colorIndex: 2, rainbow: true,
    doubleSided: true, size: 10, flare: true, fastShrink: false,
  }));
  return [{offset: [...NATIVE_RACER_STREAM_OFFSET], rotate: false,
    colorIndex: racer + (level === 1 ? 1 : level === 2 ? 2 : 0),
    rainbow: level === 2, doubleSided: false, size: 20, flare: true, fastShrink: level === 0}];
}

/** Original456440 state2 only adds streams for rockets (bonus type1). */
export function nativeProjectileStreamOptions(type, level) {
  if (type !== 1) return [];
  if (level === 2) return [[-6, 0, -15], [6, 10, -28]].map(offset => ({
    offset, rotate: false, colorIndex: 2, rainbow: false, doubleSided: false,
    size: 8, flare: true, fastShrink: false,
  }));
  return [{offset: [...NATIVE_SHOT_STREAM_OFFSET], rotate: false, colorIndex: 5,
    rainbow: false, doubleSided: true, size: 8, flare: true, fastShrink: false}];
}

/** 0x48a570/0x48a6d0 ribbon manager and0x488b80 jet manager. */
export class NativeStreams {
  constructor({playerBody, jetstreams = true, alphaBlending = true, paletted = false, precision = NATIVE_PRECISION} = {}) {
    Object.assign(this, {playerBody, jetstreams, alphaBlending, paletted, precision});
    this.ribbons = [];
    this.jets = [];
    // Native heap constructor does not write manager+0xc. Explicit zero policy.
    this.pairCount = 0;
  }

  add(body, options) {
    const pair = options.length === 2;
    if (!this.jetstreams || !this.alphaBlending || this.paletted ||
      this.ribbons.length >= (pair ? 29 : 30) || this.ribbons.some(entry => entry.body === body)) return false;
    for (const spec of options) {
      const entry = createNativeRibbon(body, spec);
      this.ribbons.unshift(entry);
      if (entry.flare && this.jets.length < 20 && this.jets.filter(jet => jet.body === body).length < 3) {
        this.jets.unshift(createNativeJetFlare(body, {offset: entry.offset, clockwise: true,
          colorIndex: entry.colorIndex + 1, rainbow: false, crossed: false,
          size: f(body === this.playerBody ? entry.size : entry.size * 2.5)}));
      }
    }
    if (pair) this.pairCount++;
    return options.length > 0;
  }

  remove(body) {
    if (!this.jetstreams) return;
    const removeOne = () => {
      const index = this.ribbons.findIndex(entry => entry.body === body);
      if (index < 0) return false;
      const entry = this.ribbons[index];
      if (entry.flare && !this.paletted) {
        for (let i = this.jets.length - 1; i >= 0; i--) {
          const jet = this.jets[i];
          if (jet.body === body && jet.offset.every((v, axis) => v === entry.offset[axis])) {
            this.jets[i] = this.jets.at(-1); this.jets.pop();
          }
        }
      }
      this.ribbons[index] = this.ribbons.at(-1); this.ribbons.pop();
      return true;
    };
    removeOne();
    if (this.pairCount > 0 && removeOne()) this.pairCount--;
  }

  racer(body, racer, level = 0) {
    this.remove(body);
    return this.add(body, nativeRacerStreamOptions(racer, level));
  }

  projectile(shot) {
    return this.add(shot, nativeProjectileStreamOptions(shot.type, shot.level));
  }

  /** After halos and before arms. Player speed is4325b0's PRE-update integer. */
  step(deltaSeconds, {playerSpeedKmh = 0, playerThrottle = 0, renderPose} = {}) {
    if (!this.jetstreams || this.paletted) return;
    const playerBody = this.playerBody, precision = this.precision;
    const ribbon = {player: false, speedKmh: playerSpeedKmh, precision, renderPose};
    const jet = {player: false, throttle: playerThrottle, precision, renderPose};
    for (let i = 0; i < this.ribbons.length; i++) {
      const entry = this.ribbons[i];
      ribbon.player = entry.body === playerBody;
      updateNativeRibbon(entry, deltaSeconds, ribbon);
    }
    for (let i = 0; i < this.jets.length; i++) {
      const entry = this.jets[i];
      jet.player = entry.body === playerBody;
      updateNativeJetFlare(entry, jet);
    }
  }

  /** Jet draw precedes ribbon draw; this mutates ribbon widths and retirement. */
  draw() {
    const jets = [], ribbons = [], options = {precision: this.precision};
    if (!this.jetstreams || this.paletted) return {jets, ribbons};
    for (let i = 0; i < this.jets.length; i++) if (this.jets[i].active) jets.push(this.jets[i].vertices);
    for (let i = 0; i < this.ribbons.length; i++) {
      const entry = this.ribbons[i];
      shrinkNativeRibbon(entry, options);
      if (!entry.active) continue;
      const vertices = entry.vertices;
      if (vertices.length > 3) ribbons.push(vertices);
      if (entry.doubleSided && vertices.length - 1 > 3) ribbons.push(vertices.slice(0, -1).reverse());
    }
    return {jets, ribbons};
  }
}
