/** GetTickCount timers from 0x42a210..0x42a700; distinct from engine seconds. */
export const NATIVE_PAUSED_TIMER_IDS = Object.freeze([0, 3, 8, ...Array.from({ length: 19 }, (_, i) => i + 9)]);

export class NativeGameTimers {
  constructor() { this.timers = Array.from({ length: 28 }, () => null); }
  get(index, required = true) {
    if (!Number.isInteger(index) || index < 0 || index > 27) throw new RangeError('Native timer index must be 0..27');
    const timer = this.timers[index];
    if (required && !timer) throw new Error(`Native timer ${index} not initialized`);
    return timer;
  }
  initialize(index, limitMs, countdown = false) {
    this.get(index, false);
    if (!Number.isInteger(limitMs) || limitMs < 0 || limitMs > 0x7fffffff) throw new RangeError('Invalid native timer limit');
    return this.timers[index] = { limitMs, startMs: 0xffffffff, countdown: Boolean(countdown), pausedAtMs: 0 };
  }
  start(index, nowMs) {
    const timer = this.get(index);
    timer.startMs = nowMs >>> 0;
    timer.pausedAtMs = 0;
  }
  pause(index, nowMs, { required = true } = {}) {
    const timer = this.get(index, required);
    if (timer && timer.pausedAtMs === 0) timer.pausedAtMs = nowMs >>> 0;
  }
  resume(index, nowMs, { required = true } = {}) {
    const timer = this.get(index, required);
    if (!timer || timer.pausedAtMs === 0) return;
    if (timer.startMs !== 0xffffffff) timer.startMs = (timer.startMs + ((nowMs >>> 0) - timer.pausedAtMs)) >>> 0;
    timer.pausedAtMs = 0;
  }
  elapsed(index, nowMs) {
    const timer = this.get(index), now = nowMs >>> 0;
    if (timer.startMs === 0xffffffff) return 0;
    return (now - timer.startMs - (timer.pausedAtMs === 0 ? 0 : now - timer.pausedAtMs)) | 0;
  }
  read(index, nowMs) {
    const timer = this.get(index), elapsed = this.elapsed(index, nowMs);
    return timer.countdown ? Math.max(0, (timer.limitMs - elapsed) | 0) : Math.min(timer.limitMs, elapsed);
  }
  expired(index, nowMs) {
    const timer = this.get(index);
    return timer.startMs !== 0xffffffff && timer.limitMs <= this.elapsed(index, nowMs);
  }
  setLimit(index, limitMs, nowMs) {
    if (!Number.isInteger(limitMs) || limitMs < 0 || limitMs > 0x7fffffff) throw new RangeError('Invalid native timer limit');
    const timer = this.get(index);
    timer.limitMs = limitMs;
    if (timer.startMs !== 0xffffffff) timer.startMs = nowMs >>> 0;
  }
  pauseGame(nowMs) {
    for (const index of NATIVE_PAUSED_TIMER_IDS) this.pause(index, nowMs, { required: false });
  }
  resumeGame(nowMs) {
    for (const index of NATIVE_PAUSED_TIMER_IDS) this.resume(index, nowMs, { required: false });
  }
  /** 0x42f980, called when the post-render countdown action changes phase1 to0. */
  startRace(nowMs, { opponentCount, raceType }) {
    for (const index of [8, 0, 3]) this.start(index, nowMs);
    for (let index = 0; index < opponentCount; index++) this.start(index + 9, nowMs);
    if (raceType === 1) this.start(18, nowMs);
  }
}

/** 0x415cf0 +0x42d300. The unusual raw+0x40 field is read verbatim. */
export function nativeTrackCountdownLimit(trackIndex, difficulty, playerRacer, {
  motorUpgrade = false, gearboxUpgrade = false, precision = 24,
} = {}) {
  if (![0, 1, 2].includes(difficulty) || !Number.isInteger(trackIndex) || trackIndex < 0 || trackIndex > 6) {
    throw new RangeError('Original track/difficulty index required');
  }
  const f = Math.fround, r = precision === 53 ? Number : f;
  const sourceSpeed = playerRacer.raw[gearboxUpgrade ? 23 : 16];
  const speed = f(r(sourceSpeed + (motorUpgrade ? 4 : 0)));
  const distance = Math.trunc(r([0, 142, 0, 110, 0, 142, 0][trackIndex] * 10));
  const seconds = r(distance / r(speed * f(difficulty === 0 ? .4 : .65)));
  // Same CRT qword-low-word conversion as the steering target routine.
  return ((Number.isFinite(seconds) ? Math.trunc(seconds) : 0) * 1000) | 0;
}

/** 0x42d360,0x435670,0x417dd0. Returns initialized, not yet started timers. */
export function nativeRaceTimerSetup({ config, trackIndex, difficulty, raceType,
  opponentCount, playerRacer, motorUpgrade = false, gearboxUpgrade = false, precision = 24 }) {
  const bank = new NativeGameTimers();
  const record = config['track.ini'].maps[trackIndex].split(',').map(value => value.trim());
  const routeMs = nativeTrackCountdownLimit(trackIndex, difficulty, playerRacer,
    { motorUpgrade, gearboxUpgrade, precision });
  bank.initialize(0, Number(record[10]) * 1000);
  bank.initialize(8, routeMs, true);
  bank.initialize(3, 0xfffffff);
  for (let index = 0; index < opponentCount; index++) bank.initialize(index + 9, 0xfffffff);
  if (raceType === 1) {
    const gates = config['track.ini'].time_gates[trackIndex * 3 + difficulty].split(',').map(Number);
    bank.initialize(18, gates[1], true);
  }
  return bank;
}

/** Exact inactive player reset at 0x432b85..0x432c09; controls are retained. */
export function resetNativeInactivePlayer(motion) {
  motion.rpm = 0;
  motion.lowSpeedTurn = false;
  if ('slipMagnitude' in motion) motion.slipMagnitude = 0;
  for (const key of ['lateralSpeed', 'verticalSpeed', 'forwardSpeed', 'yawRate']) motion.body[key] = 0;
}
