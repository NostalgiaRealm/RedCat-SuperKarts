import { NATIVE_PRECISION } from './native-precision.js';
const f = Math.fround;

/** 4818c0 selects TRACK<race type><country>, not the difficulty preset. */
export function getNativeWeatherSpec(config, raceType, trackIndex, {hardware = true} = {}) {
  const settings = config['sndgfx.ini']?.['gfx options'] ?? {};
  const entry = config['track.ini']?.[`track${raceType}${trackIndex}`] ?? {};
  const type = Number(entry.type ?? 0);
  if (!hardware || Number(settings.particles ?? 0) === 0 || ![1, 2].includes(type)) return null;
  const kind = type === 1 ? 'rain' : 'snow';
  return {
    kind, count: Number(config['game.ini']?.[kind]?.maxparticles ?? 0),
    enabled: Number(entry.enable ?? 0) !== 0,
    percentages: Array.from({length: Number(entry.count ?? 0)}, (_, i) => Number(entry[i] ?? 0)),
    texture: 's_sfx', cameraSpace: true,
    material: {sourceBlend: 'src-alpha', destinationBlend: 'one', depthWrite: false},
  };
}

/** Original 481a80/481be0 + 483060/483280/483650/483740.
 * All particles are initialized even if the system starts paused. Their draws
 * must use the race construction RNG; subsequent recycling uses the shared RNG.
 */
// Reused capture storage, kept off the controller: only its live state is race state.
const weatherScratches = new WeakMap();
function weatherScratch(weather) {
  let scratch = weatherScratches.get(weather);
  if (!scratch) {
    const rain = weather.kind === 'rain', count = weather.particles.length, u0 = f(rain ? .56 : .35), u1 = f(rain ? .63 : .54), v0 = f(.05), v1 = f(rain ? .4 : .25);
    const uv = [u0, v0, u1, v0, u0, v1, u1, v0, u1, v1, u0, v1], noUV = new Array(12).fill(0);
    const argb = new Array(6).fill(rain ? 0x806060c0 : 0x80ffffff), rows = Math.ceil(count / 6);
    // Each frame's UV and colour are constant; only the positions change.
    scratch = {framePool: Array.from({length: count}, (_, index) => ({
      vertices: new Array(18).fill(0), uv: index < rows ? uv : noUV, argb})), frames: []};
    weatherScratches.set(weather, scratch);
  }
  return scratch;
}
export class NativeWeather {
  constructor({kind, count = 400, enabled = true, random, precision = NATIVE_PRECISION, percentages = []}) {
    if (!random?.next) throw new Error('Original shared random stream is required');
    if (!['rain', 'snow'].includes(kind)) throw new Error('Unknown original weather kind');
    Object.assign(this, {kind, count, activeCount: count, random, precision, percentages,
      percentageIndex: 0, paused: !enabled, texture: 's_sfx'});
    this.acceleration = kind === 'rain' ? [-8, -4, 1] : [-4, 0, 1];
    this.particles = Array.from({length: count}, () => ({
      active: false, age: 0, lifetime: 0, mass: kind === 'rain' ? 20 : .5,
      position: [0, 0, 0], previousPosition: [0, 0, 0], acceleration: [0, 0, 0],
      velocity: [0, 0, 0], width: kind === 'rain' ? .5 : 1.5,
      argb: kind === 'rain' ? 0x806060c0 : 0x80ffffff,
    }));
    for (const particle of this.particles) this.initialize(particle);
  }
  randomRange(min, max) {
    const r = this.precision === 24 ? f : Number;
    return r(r(r(this.random.next() * f(1 / 32767)) * r(max - min)) + min);
  }
  initialize(particle) {
    const r = this.precision === 24 ? f : Number, rain = this.kind === 'rain';
    const lifetime = f(r(this.randomRange(.5, 2) * 2));
    const range = rain ? 25 : 35;
    const x = f(this.randomRange(-range, range));
    const z = f(r((rain ? 35 : 50) + this.randomRange(-range, range)));
    const factor = this.randomRange(.75, 1.25);
    particle.active = true; particle.age = 0; particle.lifetime = lifetime;
    const p = particle.position, a = particle.acceleration, v = particle.velocity, source = this.acceleration;
    p[0] = x; p[1] = rain ? 25 : 35; p[2] = z;
    // 4824a0 deliberately retains previousPosition when reusing a slot.
    a[0] = source[0]; a[1] = source[1]; a[2] = source[2];
    v[0] = f(r((rain ? 15 : 10) * factor)); v[1] = f(r((rain ? -35 : -6) * factor)); v[2] = 0;
  }
  setFraction(value) {
    value = f(value);
    if (value >= 0 && value <= 1) {
      const r = this.precision === 24 ? f : Number;
      this.activeCount = Math.trunc(r(this.count * value));
    }
  }
  /** Callback table4ecd80: guarded79/80 and84/85; unconditional81/82,
   *86/87; intensity cycles83/88 use415be0 direction, including NPCs. */
  trigger(marker, {player = true, forward = true, waypointMarker = marker} = {}) {
    if (this.kind === 'rain') {
      if ((player && marker === 79 && waypointMarker === 79) || marker === 81) this.paused = false;
      if ((player && marker === 80 && waypointMarker === 80) || marker === 82) this.paused = true;
    } else {
      if ((player && marker === 84 && waypointMarker === 84) || marker === 86) this.paused = false;
      if ((player && marker === 85 && waypointMarker === 85) || marker === 87) this.paused = true;
    }
    if (marker === (this.kind === 'rain' ? 83 : 88) && this.percentages.length) {
      this.percentageIndex += forward ? 1 : -1;
      if (this.percentageIndex === this.percentages.length) this.percentageIndex = 0;
      else if (this.percentageIndex < 0) this.percentageIndex = this.percentages.length - 1;
      const r = this.precision === 24 ? f : Number;
      this.setFraction(f(r(r(this.percentages[this.percentageIndex]) * f(.01))));
    }
  }
  step(deltaSeconds, velocity) {
    if (this.paused) return;
    const r = this.precision === 24 ? f : Number, dt = f(deltaSeconds), particles = this.particles, active = this.activeCount;
    let survived = false;
    for (let i = 0; i < active; i++) {
      const particle = particles[i];
      if (!particle.active) continue;
      const age = r(dt + particle.age);
      particle.age = f(age);
      if (!(age < particle.lifetime)) {
        particle.active = false;
        this.initialize(particle);
        continue;
      }
      survived = true;
      const p = particle.position, q = particle.previousPosition, a = particle.acceleration, v = particle.velocity, mass = particle.mass;
      q[0] = p[0]; q[1] = p[1]; q[2] = p[2];
      const ay = f(r(a[1] - r(mass * f(9.81))));
      v[0] = f(r(r(r(a[0] / mass) * dt) + v[0]));
      v[1] = f(r(r(r(ay / mass) * dt) + v[1]));
      v[2] = f(r(r(r(a[2] / mass) * dt) + v[2]));
      p[0] = f(r(r(dt * v[0]) + p[0]));
      p[1] = f(r(r(dt * v[1]) + p[1]));
      p[2] = f(r(r(dt * v[2]) + p[2]));
    }
    // The weather-specific tail skips when every visited particle recycled.
    if (!survived) return;
    const x = f(velocity[0]), y = f(velocity[1]), z = f(velocity[2]);
    const speed = r(Math.sqrt(r(r(r(z * z) + r(y * y)) + r(x * x))));
    this.acceleration[1] = f(r(speed * (this.kind === 'rain' ? -2.5 : -1)));
    this.acceleration[2] = f(r(speed * (this.kind === 'rain' ? -4.5 : -1.5)));
    const drag = this.kind === 'rain' ? 3 : 2;
    for (let i = 0; i < active; i++) {
      const v = particles[i].velocity;
      v[2] = f(r(v[2] + drag));
      if (v[2] > 0) v[2] = 0;
    }
  }
  /**483350 uses identity view/world matrices. These vertices are camera-space.
   * Native482840 initializes only ceil(count/6) UV quads. Later UV memory is
   * unspecified; this port explicitly uses zero-filled allocation for it.
   */
  capture() {
    if (this.paused) return [];
    const r = this.precision === 24 ? f : Number, rain = this.kind === 'rain';
    const scratch = weatherScratch(this), frames = scratch.frames, particles = this.particles, active = this.activeCount;
    let count = 0;
    for (let i = 0; i < active; i++) {
      const particle = particles[i];
      if (!particle.active) continue;
      const p = particle.position, width = particle.width;
      let tx, ty, tz, bx, by, bz;
      if (rain) {
        const q = particle.previousPosition;
        if (q[1] < p[1]) {tx = p[0]; ty = p[1]; tz = p[2]; bx = q[0]; by = q[1]; bz = q[2];}
        else {tx = q[0]; ty = q[1]; tz = q[2]; bx = p[0]; by = p[1]; bz = p[2];}
      } else {
        tx = bx = p[0]; ty = p[1]; tz = bz = p[2];
        by = f(r(p[1] - width));
      }
      const brx = f(r(tx + width)), trx = f(r(bx + width));
      const frame = scratch.framePool[count], v = frame.vertices;
      v[0] = tx; v[1] = ty; v[2] = tz; v[3] = brx; v[4] = ty; v[5] = tz;
      v[6] = bx; v[7] = by; v[8] = bz; v[9] = brx; v[10] = ty; v[11] = tz;
      v[12] = trx; v[13] = by; v[14] = bz; v[15] = bx; v[16] = by; v[17] = bz;
      frames[count++] = frame;
    }
    frames.length = count;
    return frames;
  }
}
