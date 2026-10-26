import { nativeTrigTable } from './native-integrator.js';

const f = Math.fround;
export const NATIVE_STREAM_COLORS = [
  [49, 255, 165], [49, 255, 248], [49, 78, 255],
  [255, 243, 49], [255, 49, 64], [255, 49, 243],
];
export const NATIVE_RACER_STREAM_OFFSET = [0, 10, -28]; // 0x489300
export const NATIVE_SHOT_STREAM_OFFSET = [0, 0, -15]; // 0x489350
const jetPoints = [[-.5, -.5, 0], [-.5, .5, 0], [.5, -.5, 0], [.5, .5, 0],
  [.5, -.5, 0], [-.5, .5, 0], [-.5, -.5, 0]];
const identity = () => [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
const translate = xyz => { const m = identity(); m.splice(12, 3, ...xyz); return m; };
const matrixOf = (body, renderPose) => {
  const pose = renderPose?.(body) ?? body;
  const matrix = pose.matrix ?? body.matrix;
  const position = pose.position ?? body.position;
  return matrix.length === 16 ? matrix : [
    ...matrix.slice(0, 3), 0, ...matrix.slice(3, 6), 0,
    ...matrix.slice(6, 9), 0, ...position, 1,
  ];
};
const packed = rgb => ((rgb[0] | 0xffffff00) << 16 | rgb[1] << 8 | rgb[2]) >>> 0;
const vertex = position => ({position, color: 0, specular: 0, uv: [0, 0]});

// Original 0x4a2560 reverses the arguments relative to row-matrix product.
function multiply(a, b, r) {
  return Array.from({length: 16}, (_, index) => {
    const row = Math.floor(index / 4), col = index % 4;
    let sum = 0;
    for (let k = 0; k < 4; k++) sum = r(r(a[k * 4 + col] * b[row * 4 + k]) + sum);
    return f(sum);
  });
}
const transform = (point, matrix, r) => [0, 1, 2].map(axis =>
  f(r(r(r(r(point[0] * matrix[axis]) + r(point[1] * matrix[4 + axis])) +
    r(point[2] * matrix[8 + axis])) + matrix[12 + axis])));
function rotation(angle, precision) {
  const {sin, cos} = nativeTrigTable(precision), index = Math.trunc(angle) & 4095;
  return [cos[index], -sin[index], 0, 0, sin[index], cos[index], 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
}

/** 0x488100/0x488210. Initial untouched vertex memory is explicitly zeroed. */
export function createNativeJetFlare(body, {offset = NATIVE_RACER_STREAM_OFFSET,
  clockwise = true, colorIndex = 0, rainbow = false, crossed = false, size = 20} = {}) {
  return {body, active: true, offset: offset.map(f), clockwise, colorIndex:
    colorIndex >= 0 && colorIndex < 6 ? colorIndex : 0, rainbow, crossed,
  size: f(size), angle: 0, vertices: Array.from({length: crossed ? 7 : 4}, () => vertex([0, 0, 0]))};
}

/** 0x488850 -> 0x4885c0/0x4884d0/0x488440, once per native update. */
export function updateNativeJetFlare(entry, {player = false, throttle = 0, precision = 24, renderPose} = {}) {
  if (!entry.active) return;
  const r = precision === 24 ? f : Number;
  const size = f(r(f(player ? r(f(throttle) * f(.2)) : 5) + entry.size));
  entry.angle += entry.clockwise ? 15 : -15;
  if (entry.angle > 4096) entry.angle -= 4096;
  if (entry.angle < 0) entry.angle += 4096;
  const scale = identity(); scale[0] = scale[5] = size;
  const matrix = multiply(matrixOf(entry.body, renderPose),
    multiply(multiply(translate(entry.offset), rotation(entry.angle, precision), r), scale, r), r);
  let color = NATIVE_STREAM_COLORS[entry.colorIndex];
  if (entry.rainbow) {
    const previous = entry.vertices[0].color;
    color = [(previous >>> 16) & 255, (previous >>> 8) & 255, previous & 255]
      .map((value, i) => value + [45, 65, 85][i] > 255 ? 0 : value + [45, 65, 85][i]);
  }
  const uv = [[.4921875, .984375], [.4921875, .4921875], [.984375, .984375],
    [.984375, .4921875], [.984375, .984375], [.4921875, .4921875], [.4921875, .984375]];
  entry.vertices.forEach((v, i) => {
    v.position = transform(jetPoints[i], matrix, r);
    v.color = packed(color); v.specular = 0; v.uv = [...uv[i]];
  });
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
  {player = false, speedKmh = 0, precision = 24, renderPose} = {}) {
  if (!entry.active || (player && speedKmh <= 0)) return;
  const r = precision === 24 ? f : Number;
  if (entry.vertices.length + 2 > 999) entry.vertices.splice(-2);
  let matrix = multiply(matrixOf(entry.body, renderPose), translate(entry.offset), r);
  let halfWidth = 10;
  if (entry.rotate) {
    const next = r(r(r(60 / r(1 / f(deltaSeconds))) * 100) + entry.angle);
    entry.angle = f(next > 4096 ? r(next - 4096) : next);
    matrix = multiply(matrixOf(entry.body, renderPose),
      multiply(translate(entry.offset), rotation(entry.angle, precision), r), r);
    halfWidth = f(r(entry.size * .5));
  }
  // Native always uses -10 for the second endpoint, even with rotating size!=20.
  const first = vertex(transform([-10, 0, 0], matrix, r));
  const second = vertex(transform([halfWidth, 0, 0], matrix, r));
  entry.vertices.unshift(first, second);
  let rgb = NATIVE_STREAM_COLORS[entry.colorIndex];
  if (entry.rainbow) {
    entry.colors = entry.colors.map((value, i) => value + [25, 75, 125][i] > 255
      ? 0 : value + [25, 75, 125][i]);
    rgb = entry.colors;
  }
  const v = entry.vertices.length % 2 ? .1640625 : .1484375;
  first.color = second.color = packed(rgb);
  first.uv = [f(.88), v]; second.uv = [.984375, v];
}

/** 0x489f50 runs inside DRAW 0x48a170, not the effect-update callback. */
export function shrinkNativeRibbon(entry, {precision = 24} = {}) {
  if (!entry.active) return;
  const r = precision === 24 ? f : Number, points = entry.vertices;
  const count = points.length;
  for (let i = 0; i < count - 1; i += 2) {
    const a = points[i].position, b = points[i + 1].position;
    let factor = i < 6 && count > 12 ? [.4, 1.8, 1.8, 1.2, 1, .8][i] : .7;
    factor = f(factor);
    if (entry.fastShrink) factor = r(factor * f(.7));
    const center = a.map((value, axis) => {
      const result = r(r(value + b[axis]) * .5);
      return axis === 0 ? result : f(result);
    });
    const delta = a.map((value, axis) => r(value - center[axis]));
    const distance = r(r(r(delta[0] * delta[0]) + r(delta[1] * delta[1])) + r(delta[2] * delta[2]));
    if (distance < .25) {
      points.splice(i);
      return;
    }
    points[i].position = delta.map((value, axis) =>
      f(r(r((axis === 2 ? value : f(value)) * factor) + center[axis])));
    points[i + 1].position = b.map((value, axis) => f(r(r(r(value - center[axis]) * factor) + center[axis])));
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
  constructor({playerBody, jetstreams = true, alphaBlending = true, paletted = false, precision = 24} = {}) {
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
    for (const entry of this.ribbons) updateNativeRibbon(entry, deltaSeconds, {
      player: entry.body === this.playerBody, speedKmh: playerSpeedKmh, precision: this.precision, renderPose,
    });
    for (const entry of this.jets) updateNativeJetFlare(entry, {
      player: entry.body === this.playerBody, throttle: playerThrottle, precision: this.precision, renderPose,
    });
  }

  /** Jet draw precedes ribbon draw; this mutates ribbon widths and retirement. */
  draw() {
    if (!this.jetstreams || this.paletted) return {jets: [], ribbons: []};
    const jets = this.jets.filter(entry => entry.active).map(entry => entry.vertices);
    const ribbons = this.ribbons.flatMap(entry => {
      shrinkNativeRibbon(entry, {precision: this.precision});
      return nativeRibbonDrawPackets(entry);
    });
    return {jets, ribbons};
  }
}
