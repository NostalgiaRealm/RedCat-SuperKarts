import { RouteTestDriver as Base } from './private-projected-line-driver.mjs';
import { NativeRailCollision } from '../../src/simulation/native-collision.js';
import { createNativeTrack, sampleNativeTrack } from '../../src/simulation/native-track.js';

const distance = (a, b) => Math.hypot(a[0] - b[0], a[2] - b[2]);

/**
 * Test controls only: smooth steering goals on original road, land and extra triangles and
 * original rail clearance. The simulation's track, bodies and colliders never
 * receive these goal coordinates. All resulting inputs remain ordinary inputs.
 */
export class RouteTestDriver extends Base {
  constructor(track, options) {
    super(track, options);
    this.originalTrack = track;
    this.queryBounds = options.railBounds;
  }

  configureRacingLine(turnPenalty, { maximumOffset = 70, iterations = 30, weight = .35 } = {}) {
    super.configureRacingLine(turnPenalty);
    const track = this.originalTrack, world = createNativeTrack(track);
    const query = new NativeRailCollision(track, this.queryBounds);
    const nodes = this.racingLine;
    const authored = nodes.map(index => [...track.drive[index].position]);
    const points = authored.map(point => [...point]);
    let accepted = 0;
    const legal = (a, b, sector) => {
      const dx = b[0] - a[0], dz = b[2] - a[2], length = distance(a, b);
      if (length < 1) return false;
      query.candidates = () => query.rails.filter((rail, index) => {
        const { position: p, delta: d } = track.collision[index];
        return Math.max(p[0], p[0] + d[0]) >= Math.min(a[0], b[0]) - 80
          && Math.min(p[0], p[0] + d[0]) <= Math.max(a[0], b[0]) + 80
          && Math.max(p[2], p[2] + d[2]) >= Math.min(a[2], b[2]) - 80
          && Math.min(p[2], p[2] + d[2]) <= Math.max(a[2], b[2]) + 80;
      });
      const body = { position: a, x: a[0], y: a[1], z: a[2],
        yaw: Math.atan2(-dx, dz) * 2048 / Math.PI, sector,
        forwardSpeed: length / 10, lateralSpeed: 0, verticalSpeed: 0, yawRate: 0 };
      if (query.sweep(body, 1).fraction < 1) return false;
      const count = Math.max(1, Math.ceil(length / 20));
      for (let i = 0; i <= count; i++) {
        const t = i / count;
        if (sampleNativeTrack(world, sector, a[0] + dx * t,
          a[1] + (b[1] - a[1]) * t, a[2] + dz * t).kind === 'fallback') return false;
      }
      return true;
    };
    for (let pass = 0; pass < iterations; pass++) {
      for (let i = 0; i < points.length; i++) {
        const before = (i + points.length - 1) % points.length;
        const after = (i + 1) % points.length;
        const a = points[before], b = points[after], old = points[i], source = authored[i];
        const proposal = [
          old[0] + ((a[0] + b[0]) * .5 - old[0]) * weight,
          source[1],
          old[2] + ((a[2] + b[2]) * .5 - old[2]) * weight,
        ];
        const offset = distance(source, proposal);
        if (offset > maximumOffset) {
          const scale = maximumOffset / offset;
          proposal[0] = source[0] + (proposal[0] - source[0]) * scale;
          proposal[2] = source[2] + (proposal[2] - source[2]) * scale;
        }
        if (distance(old, proposal) < .01
          || !legal(a, proposal, before) || !legal(proposal, b, i)) continue;
        points[i] = proposal;
        accepted++;
      }
    }
    const goalByNode = new Map(nodes.map((node, index) => [node, points[index]]));
    this.track = { ...track, drive: track.drive.map((node, index) =>
      goalByNode.has(index) ? { ...node, position: goalByNode.get(index) } : node) };
    const length = list => list.reduce((sum, a, i) => sum + distance(a, list[(i + 1) % list.length]), 0);
    this.smoothedGoals = { maximumOffset, iterations, weight, accepted,
      authoredLength: length(authored), smoothedLength: length(points), nodes, points };
  }
}
