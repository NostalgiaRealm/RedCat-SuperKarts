/** Player race progress and timers recovered from the shipped x86 program.
 * This module does not decide tournament qualification or implement item triggers.
 */
export function nativeSectorDistance(current, previous, count) {
  if (current === previous) return 0;
  const difference = Math.abs(current - previous);
  const magnitude = difference > Math.trunc(count / 2) ? count - difference : difference;
  const forward = (current > previous && current - previous < Math.trunc(count / 2))
    || (current < previous && previous - current > Math.trunc(count / 2));
  return forward ? magnitude : -magnitude;
}

/** 0x4938e0 dispatches only one boundary, even if several sectors were skipped. */
export function nativeCrossedTriggers(track, previous, current) {
  if (previous === current) return [];
  const last = track.route.length - 1;
  const sector = Math.min(previous, current) === 0 && Math.max(previous, current) === last
    ? 0 : Math.max(previous, current);
  const route = track.route[sector];
  return [route.trigger, route.unknown].filter(value => value !== 0);
}

export function nativeRaceSettings(config, trackIndex, difficulty = 1, raceType = 0) {
  const record = config['track.ini'].maps[trackIndex].split(',').map(value => value.trim());
  const saved = config['race.ini'].best_times ?? config['race.ini']['best times'] ?? {};
  const gateRecord = config['track.ini'].time_gates[trackIndex * 3 + difficulty].split(',').map(Number);
  const configuredLaps = Number(config['game.ini'].options.nrlaps);
  if (configuredLaps < 1 || configuredLaps > 999) throw new RangeError('Native lap count must be 1..999');
  return {
    raceType, lapLimit: Number(record[0]) === 0 ? 1 : configuredLaps,
    lapTimerLimitMs: Number(record[10]) * 1000,
    bestLapMs: Number(saved[`lap_record_e${trackIndex}`]) || 0xfffffff,
    bestRaceMs: Number(saved[`race_record_e${trackIndex}`]) || 0xfffffff,
    gateTimes: gateRecord.slice(1, gateRecord[0] + 2),
  };
}

/**
 * Time values are explicit active milliseconds since the green light.
 * Call beginUpdate with the sector from the PREVIOUS movement update, then move
 * the kart, then endUpdate: that is the native 0x4325b0/0x42f170 order.
 */
export class NativeRaceState {
  constructor({ track, startSector, raceType, lapLimit, lapTimerLimitMs,
    bestLapMs = 0xfffffff, bestRaceMs = 0xfffffff, gateTimes = [] }) {
    this.track = track;
    this.previousSector = startSector;
    this.raceType = raceType;
    this.lapLimit = lapLimit;
    this.lapTimerLimitMs = lapTimerLimitMs;
    this.bestLapMs = bestLapMs;
    this.bestRaceMs = bestRaceMs;
    this.gateTimes = [...gateTimes];
    if (raceType === 1 && gateTimes.length < 2) throw new RangeError('Original time gate values are required');
    this.phase = 0;
    this.gameOverMode = -1;
    this.finishArmed = false;
    this.lapCount = 0;
    this.lapTimes = [];
    this.sessionBestLapMs = 0;
    this.lapStartMs = 0;
    this.elapsedMs = 0;
    this.raceTimeMs = null;
    this.distance = 0;
    this.gateIndex = 0;
    this.gateDistance = 0;
    this.gateDeadlineMs = gateTimes[0] ?? 0;
    this.lastTickSecond = 0;
    this.zeroSectorPassed = false;
    this.finished = false;
    this.events = [];
  }

  setTime(activeMs) {
    if (!Number.isFinite(activeMs) || activeMs < this.elapsedMs) {
      throw new RangeError('Race time must be finite and monotonic');
    }
    this.elapsedMs = Math.trunc(activeMs);
  }

  beginUpdate(sector, activeMs, {previousSector = this.previousSector} = {}) {
    this.events = [];
    this.setTime(activeMs);
    // Player4325b0 reads engine+20, which rescue430ff0 can reset between
    // callbacks. NPC409530 deliberately uses its separate controller history.
    const previous = previousSector;
    this.distance += nativeSectorDistance(sector, previous, this.track.route.length);
    for (const trigger of nativeCrossedTriggers(this.track, previous, sector)) {
      this.trigger(trigger, { previous, current: sector, player: true });
    }
    this.previousSector = sector;
    return this.snapshot();
  }

  /** 0x440dd0, 0x440e40, 0x441e70, and player's part of 0x442970. */
  trigger(id, { previous = this.previousSector, current = this.previousSector, player = true } = {}) {
    if (id === 9 && player) this.zeroSectorPassed = true;
    // 4ecd80[54] -> 4420f0 -> 430610(9): junction HUD, independent of race mode.
    if (id === 54 && player) this.events.push({type:'native-notification',id:9});
    if (id === 15) this.finishArmed = true;
    if (id === 14 && [0, 7, 8].includes(this.phase) && this.finishArmed) {
      if (previous < current) {
        this.completeLap();
        if (this.lapCount >= this.lapLimit) {
          this.raceTimeMs = this.elapsedMs;
          this.bestRaceMs = Math.min(this.raceTimeMs, this.bestRaceMs);
          this.phase = 3;
          this.finished = true;
          this.events.push({ type: 'finished', timeMs: this.raceTimeMs });
        }
      } else this.finishArmed = false;
      this.events.push({ type: 'native-notification', id: 8 });
    }
    if ([74, 75, 76].includes(id) && this.raceType === 1 && ![3, 6].includes(this.phase)
      && player && this.gateDistance < this.distance) {
      this.gateIndex = this.gateIndex === this.gateTimes.length - 1 ? 1 : this.gateIndex + 1;
      this.gateDistance = this.distance + 1;
      const additionalMs = this.gateTimes[this.gateIndex];
      this.gateDeadlineMs = this.elapsedMs + this.remainingMs + additionalMs;
      this.events.push({ type: 'time-gate', index: this.gateIndex, additionalMs, sound: 'CHECKPOINT' });
    }
  }

  /** 0x440c30 preserves the original positive-time session-best condition. */
  completeLap() {
    const timeMs = Math.min(this.lapTimerLimitMs, this.elapsedMs - this.lapStartMs);
    this.lapTimes[this.lapCount] = timeMs;
    if ((timeMs < this.sessionBestLapMs && timeMs > 0) || this.sessionBestLapMs === 0) {
      this.sessionBestLapMs = timeMs;
    }
    this.lapCount = Math.max(0, Math.min(this.lapLimit, this.lapCount + 1));
    this.events.push({ type: 'lap', lap: this.lapCount, timeMs });
    if (this.lapCount === this.lapLimit - 1) this.events.push({ type: 'last-lap' });
    if (timeMs < this.bestLapMs) {
      this.bestLapMs = timeMs;
      this.events.push({ type: 'lap-record', timeMs });
    }
    this.lapStartMs = this.elapsedMs;
  }

  /** 0x42f170 runs after movement, triggers and other game actions. */
  endUpdate(activeMs = this.elapsedMs, {damage = 0} = {}) {
    this.setTime(activeMs);
    if (this.raceType === 1 && this.phase === 0) {
      if (this.remainingMs === 0) {
        this.phase = 6;
        this.gameOverMode = 1;
        this.events.push({ type: 'time-expired' });
      } else {
        const seconds = Math.trunc(this.remainingMs / 1000);
        if (seconds < 6 && seconds !== this.lastTickSecond) {
          this.lastTickSecond = seconds;
          this.events.push({ type: 'time-tick', seconds, sound: 'TIME_TICK' });
        }
      }
    }
    // 42f1f0 follows the time-expiry check, and only changes active racing.
    if (damage > 98 && this.phase === 0) {
      this.phase = 6;
      this.gameOverMode = 0;
      this.events.push({type: 'damage-expired'});
    }
    return this.snapshot();
  }

  get remainingMs() { return Math.max(0, this.gateDeadlineMs - this.elapsedMs); }

  snapshot() {
    return {
      phase: this.phase, finishArmed: this.finishArmed, finished: this.finished,
      lapCount: this.lapCount, lapLimit: this.lapLimit, lapTimes: [...this.lapTimes],
      sessionBestLapMs: this.sessionBestLapMs, bestLapMs: this.bestLapMs, bestRaceMs: this.bestRaceMs,
      raceTimeMs: this.raceTimeMs, elapsedMs: this.elapsedMs,
      distance: this.distance, gateIndex: this.gateIndex, gateDistance: this.gateDistance,
      remainingMs: this.raceType === 1 ? this.remainingMs : null,
      zeroSectorPassed: this.zeroSectorPassed, events: this.events.map(event => ({ ...event })),
    };
  }
}
