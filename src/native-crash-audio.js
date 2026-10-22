import {NativeRandom} from './simulation/native-random.js';

export const NATIVE_CRASH_SOUNDS = Object.freeze([
  'SOFT_CAR_HIT1', 'SOFT_CAR_HIT2',
  'MID_CAR_HIT1', 'MID_CAR_HIT2',
  'HARD_CAR_HIT1', 'HARD_CAR_HIT2', 'SCHUUR',
]);

/** 434ea0/434f20. Call only from the original player contact callback.
 * Every call resets the wall-clock gate, even when playback is suppressed.
 * The RNG is shared with gameplay and advances only for enabled impact pairs. */
export class NativeCrashAudio {
  constructor({random, enabled = true, lastTimeMs = 0}) {
    if (!(random instanceof NativeRandom)) throw new TypeError('Shared native RNG required');
    this.random = random;
    this.enabled = enabled;
    this.lastTimeMs = lastTimeMs >>> 0;
  }

  contact({impulse, contactType, nowMs}) {
    const magnitude = Math.trunc(Math.fround(impulse));
    const elapsed = ((nowMs >>> 0) - this.lastTimeMs) >>> 0;
    this.lastTimeMs = nowMs >>> 0;
    if (!this.enabled) return null;
    if (elapsed < 300) {
      if (magnitude > 17999 || contactType !== 0) return null;
      return {event: 'SCHUUR', loop: false};
    }
    const pair = magnitude < 18000 ? 0 : magnitude < 25000 ? 2 : 4;
    return {event: NATIVE_CRASH_SOUNDS[pair + this.random.next() % 2], loop: false};
  }
}
