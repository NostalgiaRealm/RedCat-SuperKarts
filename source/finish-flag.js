import {nativeTrigTable} from './simulation/native-integrator.js';
import {resolveAsset} from './asset-animation.js';
const f = Math.fround;

/** Original423450 creates ten triangle strips,34vertices each, from S_SFX. */
export function getNativeFinishFlagSpec(manifest, {precision = 24} = {}) {
  const r = precision === 24 ? f : Number, position = [], uv = [], index = [];
  for (let row = 0; row < 10; row++) {
    for (let column = 0; column <= 16; column++) {
      const x = f(r(r(column * f(12.5)) - 100));
      const u = f(r(r(r(column * f(.06249997)) * f(.0625)) + f(.445313)));
      for (const yRow of [row, row + 1]) {
        position.push(x, f(r(r(yRow * 15) - 75)), 100);
        uv.push(u, f(r(f(.046875) - r(r(yRow * f(.046875)) * f(.1)))));
      }
    }
    for (let column = 0; column < 16; column++) {
      const base = row * 34 + column * 2;
      index.push(base, base + 1, base + 2, base + 2, base + 1, base + 3);
    }
  }
  return {texture: resolveAsset(manifest, 'images', 's_sfx.tga'), position, uv, index,
    blendMode: 1, depthTest: false, nativeFunctions: ['00423450', '00423280', '004233c0']};
}

/** 423230 freezes the two-second period in update ticks at activation. */
export class NativeFinishFlag {
  constructor({precision = 24} = {}) { this.precision = precision; this.tick = 0; this.period = 0; this.enabled = false; }
  setEnabled(enabled, deltaSeconds) {
    const r = this.precision === 24 ? f : Number;
    this.period = Math.trunc(r(2 / f(deltaSeconds)));
    if (this.tick >= this.period) this.tick = 0;
    this.enabled = enabled;
  }
  /** 423280 samples before4233c0 increments the counter, once per render. */
  capture() {
    if (!this.enabled) return null;
    if (!(this.period > 0)) throw new RangeError('Native finish flag requires a positive period');
    const r = this.precision === 24 ? f : Number, {sin} = nativeTrigTable(this.precision);
    const z = [], argb = [], rgba = [], phase = Math.trunc(4096 / this.period) * this.tick;
    for (let row = 0; row < 10; row++) for (let column = 0; column <= 16; column++)
      for (let edge = 0; edge < 2; edge++) {
        const wave = r(sin[(phase + row * 64 + column * 128 + edge * 64) & 4095] * 10);
        const shade = Math.max(128, Math.min(255, 256 - Math.trunc(r(r(wave + 10) * f(6.4)))));
        z.push(f(r(wave + 100)));
        rgba.push(shade, shade, shade, 100);
        argb.push(((100 << 24) | (shade << 16) | (shade << 8) | shade) >>> 0);
      }
    if (++this.tick >= this.period) this.tick = 0;
    return {z, argb, rgba};
  }
}
