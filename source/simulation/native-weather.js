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
export class NativeWeather {
  constructor({kind, count = 400, enabled = true, random, precision = 24, percentages = []}) {
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
    Object.assign(particle, {
      active: true, age: 0, lifetime,
      position: [x, rain ? 25 : 35, z],
      // 4824a0 deliberately retains previousPosition when reusing a slot.
      acceleration: [...this.acceleration],
      velocity: [f(r((rain ? 15 : 10) * factor)), f(r((rain ? -35 : -6) * factor)), 0],
    });
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
    const r = this.precision === 24 ? f : Number, dt = f(deltaSeconds);
    let survived = false;
    for (let i = 0; i < this.activeCount; i++) {
      const particle = this.particles[i];
      if (!particle.active) continue;
      const age = r(dt + particle.age);
      particle.age = f(age);
      if (!(age < particle.lifetime)) {
        particle.active = false;
        this.initialize(particle);
        continue;
      }
      survived = true;
      particle.previousPosition = [...particle.position];
      const a = [...particle.acceleration];
      a[1] = f(r(a[1] - r(particle.mass * f(9.81))));
      particle.velocity = particle.velocity.map((v, axis) =>
        f(r(r(r(a[axis] / particle.mass) * dt) + v)));
      particle.position = particle.position.map((v, axis) => f(r(r(dt * particle.velocity[axis]) + v)));
    }
    // The weather-specific tail skips when every visited particle recycled.
    if (!survived) return;
    const [x, y, z] = velocity.map(f);
    const speed = r(Math.sqrt(r(r(r(z * z) + r(y * y)) + r(x * x))));
    this.acceleration[1] = f(r(speed * (this.kind === 'rain' ? -2.5 : -1)));
    this.acceleration[2] = f(r(speed * (this.kind === 'rain' ? -4.5 : -1.5)));
    for (let i = 0; i < this.activeCount; i++) {
      const particle = this.particles[i];
      particle.velocity[2] = f(r(particle.velocity[2] + (this.kind === 'rain' ? 3 : 2)));
      if (particle.velocity[2] > 0) particle.velocity[2] = 0;
    }
  }
  /**483350 uses identity view/world matrices. These vertices are camera-space.
   * Native482840 initializes only ceil(count/6) UV quads. Later UV memory is
   * unspecified; this port explicitly uses zero-filled allocation for it.
   */
  capture() {
    if (this.paused) return [];
    const r = this.precision === 24 ? f : Number, rain = this.kind === 'rain';
    const u0 = f(rain ? .56 : .35), u1 = f(rain ? .63 : .54),
      v0 = f(.05), v1 = f(rain ? .4 : .25);
    return this.particles.slice(0, this.activeCount).filter(particle => particle.active).map((particle, index) => {
      let top = [...particle.previousPosition], bottom = [...particle.position];
      if (rain) {
        if (top[1] < bottom[1]) [top, bottom] = [bottom, top];
      } else {
        top = [...particle.position];
        bottom = [...particle.position];
        bottom[1] = f(r(bottom[1] - particle.width));
      }
      const br = [...top]; br[0] = f(r(br[0] + particle.width));
      const tr = [...bottom]; tr[0] = f(r(tr[0] + particle.width));
      return {
        vertices: [...top, ...br, ...bottom, ...br, ...tr, ...bottom],
        uv: index < Math.ceil(this.count / 6) ? [u0,v0,u1,v0,u0,v1,u1,v0,u1,v1,u0,v1] : Array(12).fill(0),
        argb: Array(6).fill(particle.argb),
      };
    });
  }
}
