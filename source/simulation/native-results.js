/** 0x417e30. Per-opponent timers use index9+rosterIndex, in milliseconds. */
export function recordNativeNPCFinish(objectId, opponents, readTimer, pauseTimer) {
  const finished = [];
  for (let index = 0; index < opponents.length; index++) {
    if (opponents[index].objectId !== objectId) continue;
    opponents[index].finishTimeMs = readTimer(index + 9) >>> 0;
    pauseTimer(index + 9);
    opponents[index].finished = true;
    finished.push(index);
  }
  return finished;
}

/**
 * 0x417d00. Finish pending NPC timers and estimate their remaining race time.
 * The signed integer quotient is truncated before multiplication. The final
 * duplicate check reads one record past the active NPC roster in the original.
 */
export function finalizeNativeOpponentResults(opponents, {
  playerDistance, sectorCount, lapCount, readTimer, pauseTimer, trailingRecordTimeMs,
}) {
  if (!Number.isInteger(trailingRecordTimeMs)) {
    throw new TypeError('The native trailing roster time must be supplied explicitly');
  }
  const totalSectors = Math.imul(sectorCount, lapCount);
  for (const opponent of opponents) {
    if (opponent.finished) continue;
    opponent.finished = true;
    recordNativeNPCFinish(opponent.objectId, opponents, readTimer, pauseTimer);
    const deficit = (playerDistance - opponent.distance) | 0;
    const denominator = (totalSectors - deficit) | 0;
    if (!denominator) throw new RangeError('Original result estimator divides by zero');
    const elapsed = opponent.finishTimeMs | 0;
    if (elapsed === -2147483648 && denominator === -1) throw new RangeError('Original signed division overflows');
    const perSector = Math.trunc(elapsed / denominator);
    opponent.finishTimeMs = (Math.imul(perSector, deficit) + elapsed) >>> 0;
  }
  if (opponents.length) {
    for (let i = 1; i <= opponents.length; i++) {
      const other = i < opponents.length ? opponents[i].finishTimeMs : trailingRecordTimeMs;
      if ((opponents[0].finishTimeMs | 0) === (other | 0)) {
        opponents[0].finishTimeMs = ((other | 0) + 1) >>> 0;
      }
    }
  }
  return opponents;
}

/** Original 0x42c4c0 writer order, represented as an INI patch. */
export function nativeRaceResultPatch({
  finished, player, opponents, trackIndex, bestLapRecordMs, raceRecordMs,
  timeCheckCount = 0, timeChecks = [],
}) {
  const patch = { PLAYER: { finished: Number(Boolean(finished)) } };
  if (!finished) return patch;
  Object.assign(patch.PLAYER, {
    damage: player.damage | 0,
    tracktime: player.finishTimeMs | 0,
    position: player.rank | 0,
    EUROSTARS: player.stars | 0,
    FASTEST_LAP: player.bestLapMs | 0,
  });
  const serialize = racer => `${racer.carIndex | 0},${racer.rank | 0},${racer.finishTimeMs | 0}`;
  patch.RACERS = { [opponents.length]: serialize(player) };
  opponents.forEach((opponent, i) => { patch.RACERS[i] = serialize(opponent); });
  const count = timeCheckCount < 0 || timeCheckCount > 9 ? 0 : timeCheckCount | 0;
  patch['BEST TIMES'] = {
    [`LAP_RECORD_E${trackIndex}`]: bestLapRecordMs | 0,
    [`RACE_RECORD_E${trackIndex}`]: raceRecordMs | 0,
    [`TIME_CHECK_COUNT_E${trackIndex}`]: count,
  };
  for (let i = 0; i < count; i++) patch['BEST TIMES'][`TIME_CHECK_E${trackIndex}_C${i}`] = timeChecks[i] | 0;
  return patch;
}

/** 0x458a00 in rcskmenu.dat: five best-lap scores, strict insertion after ties. */
export function nativeHighscoreIndex(entries, bestLapMs) {
  if (entries.length !== 5) throw new RangeError('The original high-score board contains five rows');
  const value = bestLapMs | 0;
  let sum = value, index = -1;
  for (let i = 0; i < 5; i++) {
    const time = entries[i].bestLapMs | 0;
    sum = (sum + time) | 0;
    if (!time) return i;
    if (time > value) { index = i; break; }
  }
  return sum === 0 ? 0 : index;
}

/** 0x458a40. Returns a copied board; empty/cancelled names are handled by the UI. */
export function insertNativeHighscore(entries, record, index = -1) {
  if (index === -1) index = nativeHighscoreIndex(entries, record.bestLapMs);
  const board = entries.map(entry => ({ ...entry }));
  if (index < 0 || index >= 5) return { index: -1, entries: board };
  for (let i = 4; i > index; i--) board[i] = { ...board[i - 1] };
  board[index] = {
    name: record.name, character: record.character & 255,
    totalRaceMs: record.totalRaceMs | 0, bestLapMs: record.bestLapMs | 0,
    difficulty: record.difficulty & 255,
  };
  return { index, entries: board };
}

/** 0x458838 serialization; per-country section is `${country}scores`. */
export function serializeNativeHighscore(record) {
  return `${record.name},${record.character & 255},${record.totalRaceMs | 0},${record.bestLapMs | 0},${record.difficulty & 255}`;
}

const roundEven = value => {
  const lo = Math.floor(value), fraction = value - lo;
  return fraction < 0.5 ? lo : fraction > 0.5 ? lo + 1 : lo % 2 === 0 ? lo : lo + 1;
};

/** Delphi 0x45cae8/0x45ca84/0x45cb3c, including its 60-second boundary quirk. */
export function nativeResultTimeParts(milliseconds, { precision = 53 } = {}) {
  if ((milliseconds | 0) <= 0) return { minutes: 0, seconds: 0, centiseconds: 0 };
  const r = precision === 24 ? Math.fround : Number;
  const totalSeconds = r((milliseconds | 0) / 1000);
  const minuteFraction = r(totalSeconds / 60);
  const minutes = Math.trunc(minuteFraction);
  const seconds = totalSeconds > 60
    ? Math.trunc(r(r(minuteFraction - Math.trunc(minuteFraction)) * 60))
    : Math.trunc(totalSeconds);
  const centiseconds = roundEven(r(r(totalSeconds - Math.trunc(totalSeconds)) * 100));
  return { minutes, seconds, centiseconds };
}

/** Original menu 0x45c910 uses colon separators and no carry after rounding. */
export function formatNativeResultTime(milliseconds, options) {
  const { minutes, seconds, centiseconds } = nativeResultTimeParts(milliseconds, options);
  return `${minutes}:${String(seconds).padStart(2, '0')}:${String(centiseconds).padStart(2, '0')}`;
}

/** 0x471bc0 / 0x471b8c and trans.dat PHASE_DEBRIEF; both process a score first. */
export function nativeQuickRaceDebriefAction(action) {
  if (action === 'retry') return { processHighscore: true, modalResult: 4, nextPhase: 'PHASE_RETRY' };
  if (action === 'main') return { processHighscore: true, modalResult: 8, nextPhase: 'PHASE_MAIN' };
  throw new RangeError('Unknown QuickRace debrief action');
}

