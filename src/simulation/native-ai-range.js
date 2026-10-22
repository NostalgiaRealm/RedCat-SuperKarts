/** 0x497b30. The low-end wrap adds count-1, an original off-by-one retained here. */
export function nativeVisibleSectorRange(sector, radius, sectorCount) {
  let start = sector - radius, end = sector + radius;
  if (start < 0) {
    return { start: start + sectorCount - 1, end: sectorCount - 1,
      wrapStart: 0, wrapEnd: end % sectorCount, wrapped: true };
  }
  if (end > sectorCount - 1) {
    return { start, end: sectorCount - 1,
      wrapStart: 0, wrapEnd: end % sectorCount, wrapped: true };
  }
  return { start, end, wrapped: false };
}

/**
 * Complete 0x4107e0 selection before its legacy-traffic relocation callback.
 * The fixed registry has250 records {active,id,type,sector}. Original racers
 * are type3 (0x417640 ->0x415f90); types3/4 are explicitly excluded here.
 * The player is type1 but is skipped by object identity. No race opponent
 * should be teleported merely because it is outside the visible sector range.
 */
export function nativeTrafficRelocationRequests(player, registry, { sectorCount, viewDistance }) {
  const range = nativeVisibleSectorRange(player.sector, viewDistance - 1, sectorCount);
  const halfway = Math.trunc(sectorCount / 2), requests = [];
  for (const car of registry.slice(0, 250)) {
    if (!car.active || car.id === player.id) continue;
    let target;
    if (!range.wrapped) {
      if (car.sector < range.start) target = range.end;
      else if (car.sector > range.end) target = range.start;
    } else if (car.sector < halfway) {
      if (car.sector > range.wrapEnd) target = range.start;
    } else if (car.sector < range.start) target = range.wrapEnd;
    if (target !== undefined && car.type !== 3 && car.type !== 4) {
      requests.push({ id: car.id, sector: target, forced: false });
    }
  }
  return requests;
}
