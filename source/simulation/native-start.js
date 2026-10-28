import { NATIVE_ANGLE_COUNT } from './native-ground.js';
import { NATIVE_PRECISION } from './native-precision.js';
const f32 = Math.fround;

/** Original 0x493a20 wraps by one course length (not arbitrary modulo). */
function wrapSector(index, count) {
  if (index >= count) index -= count;
  if (index < 0) index = count - Math.abs(index);
  return index;
}

/**
 * 0x415dd0 grid scan, 0x415f90 placement, 0x4319f0 player selection and
 * 0x493540 heading. The original DMP Y value is retained verbatim.
 */
export function nativePlayerStart(track, world, {
  opponentCount = 4, raceType = 0, previousFinishPosition = 0,
  startChunk = 0, british = 0, direction = 0, precision = NATIVE_PRECISION,
} = {}) {
  if (precision !== 24 && precision !== 53) throw new RangeError('Native x87 precision must be 24 or 53');
  // x87 register intermediates round to 24 bits only under PC=24.
  const r = precision === 24 ? f32 : Number;
  if (!Number.isInteger(opponentCount) || opponentCount < 0 || opponentCount > 9) {
    throw new RangeError('Native grid requires zero through nine opponents');
  }
  const grid = Array.from({ length: opponentCount + 1 }, () => []);
  let found = 0;
  scan: for (let sector = 0; sector < track.route.length; sector++) {
    for (const waypoint of track.route[sector].driveIndices) {
      const node = track.drive[waypoint];
      const slot = node.unknown[1] - 69;
      if (slot >= 0 && slot < grid.length) {
        grid[slot].push({ sector, waypoint, position: [...node.position] });
        found++;
        if (found === grid.length) break scan;
      }
    }
  }
  let chosen, source;
  if (grid.every(slot => slot.length === 1)) {
    chosen = grid[0][0];
    source = 'TRIGGER_POS_REDCAT';
  } else {
    const count = track.route.length;
    let start = startChunk;
    if (start === 0) {
      const trigger = track.route.findIndex(route => route.trigger === 13 || route.unknown === 13);
      start = trigger < 0 ? 0 : wrapSector(trigger - 1, count);
    }
    const position = [1, 3].includes(raceType) ? 0 : Math.min(previousFinishPosition, opponentCount);
    const sector = wrapSector(start - position, count);
    const side = (direction === 0 ? british === 1 : british !== 1) ? 0 : 1;
    const lanes = side === 0 ? track.route[sector].driveLeftIndices : track.route[sector].driveIndices;
    // 0x493430 returns waypoint zero if lane4 does not exist.
    const waypoint = lanes.length > 4 ? lanes[4] : 0;
    chosen = { sector, waypoint, position: [...track.drive[waypoint].position] };
    source = 'lane-fallback';
  }
  const forward = world.sectors[chosen.sector].forward;
  // 0x4935cb-0x4935e9: the squares, sum and FSQRT stay in registers; only X/len
  // is spilled with FSTP float, Z/len (FDIVR) stays in ST0 for FPATAN.
  const length = r(Math.sqrt(r(r(forward[0] * forward[0]) + r(forward[2] * forward[2]))));
  const x = f32(forward[0] / length), z = r(forward[2] / length);
  // Player constructor passes direction1 to 0x493540, even for mirrored tracks.
  // FPATAN is not precision-controlled; FSUBP/FMUL/FDIV round until FSTP float 0x493686.
  const yaw = f32(r(r(Math.atan2(z, x) - f32(Math.PI) * 0.5) * NATIVE_ANGLE_COUNT) / f32(2 * Math.PI));
  return { ...chosen, yaw, source };
}
