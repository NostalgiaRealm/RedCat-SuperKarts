/** Original race phases and blocking keyboard loops represented as resumable state. */
const VK = Object.freeze({ Escape: 27, Enter: 13, Space: 32, P: 80, J: 74, N: 78, Y: 89, Shift: 16 });
function rawKey(keys, code) {
  if (keys instanceof Set) return keys.has(code) || Object.entries(VK).some(([name, value]) => value === code && keys.has(name));
  return Boolean(keys?.[code] || Object.entries(VK).some(([name, value]) => value === code && keys?.[name]));
}
/** 0x4b3830 rejects an unmodified virtual-key poll while Shift is held. */
export function nativeRaceKeyDown(keys, code) {
  return !rawKey(keys, 16) && rawKey(keys, typeof code === 'string' ? VK[code] : code);
}
const acceptKey = keys => [27, 13, 32].some(code => nativeRaceKeyDown(keys, code));

/** 0x41fd90 / 0x420850. Epoch begins on the FIRST update, not phase entry. */
export class NativeRaceResultGate {
  constructor(phase, { hardware = true, finishFlagRequested = false } = {}) {
    if (![3, 6].includes(phase)) throw new RangeError('Native result gate requires phase 3 or 6');
    this.phase = phase;
    this.startedMs = 0xffffffff;
    this.waitingForRelease = false;
    this.done = false;
    this.hardware = hardware;
    this.finishFlagRequested = finishFlagRequested;
  }
  update(nowMs, keys = {}) {
    if (this.done) return true;
    // This is a suspended native busy-wait: its timeout is no longer evaluated.
    if (this.waitingForRelease) {
      if (!acceptKey(keys)) { this.waitingForRelease = false; this.done = true; }
      return this.done;
    }
    if (this.startedMs === 0xffffffff) this.startedMs = nowMs >>> 0;
    const elapsed = ((nowMs >>> 0) - this.startedMs) >>> 0;
    if (elapsed < (this.phase === 3 ? 1500 : 1000)) return false;
    // 0x41fd90 requests the flag once, before both the timeout and release loop.
    if (this.phase === 3 && this.hardware) this.finishFlagRequested = true;
    if (this.phase === 3 && elapsed >= 8001) return this.done = true;
    if (!acceptKey(keys)) return false;
    if (this.phase === 6) return this.done = true;
    this.waitingForRelease = true;
    return false;
  }
}

/** 0x42f740. The renderer consumes camera/action events; no camera is invented. */
export class NativeRaceLifecycle {
  constructor({ phase = 1, movementActive = false, playerActive = false, running = true } = {}) {
    Object.assign(this, { phase, movementActive, playerActive, running, raceCompleted: false,
      presentation: false, gameOverMode: -1, lastTickSecond: 0, resultGate: null });
  }
  enter(phase, { startRace } = {}) {
    if (this.phase === phase) return [];
    this.phase = phase;
    if ([0, 1, 2].includes(phase)) this.presentation = false;
    if (phase === 0) {
      this.movementActive = this.playerActive = true;
      startRace?.();
      return [{ type: 'green' }];
    }
    if (phase === 4) {
      this.movementActive = this.playerActive = this.running = false;
      return [{ type: 'race-exit', completed: this.raceCompleted }];
    }
    if ([3, 6, 8].includes(phase)) this.presentation = true;
    if ([3, 6].includes(phase)) {
      this.resultGate = new NativeRaceResultGate(phase);
      return [{ type: 'native-action', action: phase === 3 ? 4 : 12,
        start: phase === 3 ? 0x41fc60 : 0x420730,
        update: phase === 3 ? 0x41fd90 : 0x420850,
        finish: phase === 3 ? 0x41fe50 : 0x420950 }];
    }
    if (phase === 1) return [{ type: 'native-action', action: 2, start: 0x420fe0, update: 0x420ff0, finish: 0x421000 }];
    if (phase === 8) return [{ type: 'native-action', action: 11, start: 0x41fac0, update: 0x41fb30, finish: 0x41fba0 }];
    return [];
  }
  /** Run at the post-render game-actions stage, before expiry checks. */
  updateResult(nowMs, keys = {}) {
    if (![3, 6].includes(this.phase)) return [];
    this.resultGate ??= new NativeRaceResultGate(this.phase);
    if (!this.resultGate.update(nowMs, keys)) return [];
    if (this.phase === 3) this.raceCompleted = true; // 0x41fe50 only.
    return this.enter(4);
  }
  /** 0x42f170 then 0x42f1f0; timer18 is the time-gate countdown. */
  checkExpiry({ raceType, timers, nowMs, damage = 0 }) {
    const events = [];
    if (raceType === 1 && this.phase === 0) {
      if (timers.expired(18, nowMs)) {
        this.gameOverMode = 1;
        events.push({ type: 'time-expired' }, ...this.enter(6));
      } else {
        const seconds = Math.trunc(timers.read(18, nowMs) / 1000);
        if (seconds < 6 && seconds !== this.lastTickSecond) {
          this.lastTickSecond = seconds;
          events.push({ type: 'time-tick', seconds, sound: 'TIME_TICK' });
        }
      }
    }
    if (damage > 98 && this.phase === 0) {
      this.gameOverMode = 0;
      events.push({ type: 'damage-expired' }, ...this.enter(6));
    }
    return events;
  }
}

/** 0x42f9c0: P is processed after Escape, so it wins simultaneous presses. */
export function nativeRacePauseRequest(phase, keys) {
  let request = null;
  if (![1, 3, 6].includes(phase) && nativeRaceKeyDown(keys, 27)) request = 'quit';
  if (![3, 6].includes(phase) && nativeRaceKeyDown(keys, 80)) request = 'pause';
  return request;
}

/** 0x473f20: image8/3 are No, image5/1 Yes; keyboard maps into same codes. */
export function nativeQuitRequesterChoice(code) {
  if (code === 0 || code === 2) return true;
  if (code === 1 || code === 3 || code === 10000) return false;
  return null;
}

/**
 * 0x42f220/0x42f290/0x474040. The host suspends simulation while this is open,
 * pauses/resumes NativeGameTimers, and resets its delta filter on completion.
 * Input keys are Win32 VK codes or the named keys above. No invented prompt.
 */
export class NativeRacePauseGate {
  constructor(kind, { graphical = true } = {}) {
    if (!['pause', 'quit'].includes(kind)) throw new RangeError('Unknown native pause request');
    Object.assign(this, { kind, graphical, stage: 'initial-release', heldKey: null,
      scan: 0, sawKey: false, done: false, quit: false });
  }
  update(keys = {}, { requesterCode = -1 } = {}) {
    if (this.done) return this.snapshot();
    if (this.stage === 'initial-release') {
      if (nativeRaceKeyDown(keys, this.kind === 'pause' ? 80 : 27)) return this.snapshot();
      this.stage = 'input';
    }
    if (this.kind === 'pause') {
      // Native scans 0..255, waiting for EACH encountered key's release.
      for (; this.scan < 256; this.scan++) {
        if (nativeRaceKeyDown(keys, this.scan)) {
          this.sawKey = true;
          this.heldKey = this.scan;
          return this.snapshot();
        }
        this.heldKey = null;
      }
      if (this.sawKey) this.done = true;
      else this.scan = 0;
      return this.snapshot();
    }
    if (this.stage === 'key-release') {
      if (!nativeRaceKeyDown(keys, this.heldKey)) this.done = true;
      return this.snapshot();
    }
    if (this.graphical) {
      const key = [74, 78, 27].find(code => nativeRaceKeyDown(keys, code));
      if (key !== undefined) {
        this.quit = key === 74;
        this.heldKey = key;
        this.stage = 'key-release';
      } else {
        const choice = nativeQuitRequesterChoice(requesterCode);
        if (choice !== null) { this.quit = choice; this.done = true; }
      }
    } else {
      // The missing-art fallback accepts Y too. Yes is evaluated before No.
      this.quit ||= nativeRaceKeyDown(keys, 74) || nativeRaceKeyDown(keys, 89);
      if (nativeRaceKeyDown(keys, 27)) {
        this.heldKey = 27;
        this.stage = 'key-release';
      } else if (nativeRaceKeyDown(keys, 78) || this.quit) this.done = true;
    }
    return this.snapshot();
  }
  snapshot() { return { done: this.done, quit: this.quit, stage: this.stage, heldKey: this.heldKey }; }
}
