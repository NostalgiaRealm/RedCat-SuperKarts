import {nativePathDurationTicks, sampleNativeSceneryPath} from '../scenery-paths.js';
import {NATIVE_PRECISION} from './native-precision.js';

const f = Math.fround;
function transform(offset, body, round, retainX = false) {
  return [0, 1, 2].map(column => {
    let sum = 0;
    for (let row = 0; row < 3; row++) sum = round(sum + round(offset[row] * body.matrix[row * 3 + column]));
    const value = round(f(sum) + body.position[column]);
    return retainX && column === 0 ? value : f(value);
  });
}

/**
 * Original startup path controller: 420fb0, 443d20/443e80, 4441a0,
 * 443f10 and 443ff0. Its path updates run AFTER rendering. The camera remains
 * selected during the following countdown; green420f00 selects camera0.
 */
export class NativeStartCamera {
  constructor(track, body, deltaSeconds, nowMs, {precision = NATIVE_PRECISION} = {}) {
    const index = track.paths.findIndex(path => path.type === 1);
    if (index < 0) throw new RangeError('This track has no original startup camera path');
    this.pathIndex = index;
    this.path = {...track.paths[index], durationMs: track.paths[index].durationMs + 1000,
      closed: false, tension: .5};
    this.precision = precision;
    this.durationTicks = nativePathDurationTicks(this.path, deltaSeconds, precision);
    if (this.durationTicks < this.path.points.length - 1) throw new RangeError('Startup path requires a complete spline segment');
    this.startedMs = nowMs >>> 0;
    this.lastPathMs = 0;
    this.stage = 0;
    this.tick = 0;
    this.done = false;
    // 443db0's tick-zero sample is the first authored point.
    this.position = [...this.path.points[0].position];
    this.up = [0, 1, 0];
    this.step(body);
  }

  /** Active camera498c00 target update, after integration and before rendering. */
  step(body) {
    const r = this.precision === 24 ? f : Number;
    this.target = transform([0, 50, 0], body, r);
    return this;
  }

  /** Path manager4458c0, after render/bonuses and before game actions420cf0.
   * A newly true `done` schedules/starts321 in this same action stage. */
  advance(body, nowMs) {
    if (this.done) return true;
    const now = nowMs >>> 0, r = this.precision === 24 ? f : Number;
    if (this.stage === 0) {
      if (((now - this.startedMs) >>> 0) >= 1000) this.stage = 1;
    } else if (this.stage === 1) {
      // The source samples the OLD tick before advancing the wall-clock count.
      const position = sampleNativeSceneryPath(this.path, this.durationTicks,
        this.tick % this.durationTicks, this.precision);
      if (this.lastPathMs === 0) this.lastPathMs = now;
      else {
        const elapsedTicks = Math.trunc(((now - this.lastPathMs) | 0) / 25);
        if (elapsedTicks !== 0) {
          this.lastPathMs = now;
          this.tick = (this.tick + elapsedTicks) | 0;
        }
        if (this.tick >= this.durationTicks - 2) this.stage = 2;
        else this.position = position;
      }
    } else if (this.stage === 2) {
      const desired = transform([0, 50, -150], body, r, true);
      // x stays on the x87 stack; y/z are stored before the length comparison.
      const difference = desired.map((value, axis) => {
        const delta = r(value - this.position[axis]);
        return axis === 0 ? delta : f(delta);
      });
      const length = r(Math.sqrt(r(r(r(difference[2] * difference[2])
        + r(difference[1] * difference[1])) + r(difference[0] * difference[0]))));
      if (length <= 1) this.done = true;
      else this.position = difference.map((delta, axis) => {
        const scaled = r(delta * f(.1));
        return f(r((axis === 0 ? scaled : f(scaled)) + this.position[axis]));
      });
    }
    return this.done;
  }
}
