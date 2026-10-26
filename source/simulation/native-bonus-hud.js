const f32 = Math.fround;
export const NATIVE_BONUS_HUD_ORIGIN = Object.freeze([f32(.7), f32(.1), 2]);

/** 0x465c90, with the original moving-element callbacks and linear mode0. */
export function updateNativeBonusHud(state, owned, deltaSeconds, { precision = 24 } = {}) {
  if (![0, 1, 2].includes(state.phase)) throw new RangeError('Original bonus HUD phase must be0,1 or2');
  const r = precision === 53 ? Number : f32;
  const unchanged = state.cached.state === owned.state && state.cached.type === owned.type
    && state.cached.level === owned.level;
  const start = () => {
    state.origin = [...NATIVE_BONUS_HUD_ORIGIN];
    state.position = [...state.origin];
    state.phase = 1;
    state.elapsedMs = 0;
    state.visible = true;
  };
  if (state.phase === 0) {
    if (state.cached.state !== owned.state) start();
  } else if (!unchanged) {
    // 0x465fa0 clears phase/visibility before the immediate0x465f50 restart.
    state.phase = 0;
    state.visible = false;
    start();
  } else if (state.phase === 1) {
    const elapsed = r(r(f32(deltaSeconds) * 1000) + state.elapsedMs);
    state.elapsedMs = f32(elapsed);
    // The original compares the still-unspilled x87 value, not elapsedMs.
    if (elapsed >= 1000) {
      state.position = [...state.destination];
      state.phase = 2;
    } else {
      const fraction = f32(r(elapsed / 1000));
      const complement = r(1 - fraction);
      state.position = state.destination.map((target, axis) =>
        f32(r(r(complement * state.origin[axis]) + r(fraction * target))));
    }
  }
  // These final copies override even the visibility written by start/reset.
  state.angles = owned.angles.map(f32);
  state.visible = Boolean(owned.visible ?? owned.state === 2);
  state.cached = { state: owned.state, type: owned.type, level: owned.level };
  return state;
}

/**
 * Destination is the original BonusObject overlay-local position, supplied
 * after the overlay loader's conversion. Constructor caches the current held
 * item so merely opening the HUD does not trigger a collection transition.
 */
export class NativeBonusHud {
  constructor({ destination, owned, precision = 24 }) {
    if (!destination || destination.length !== 3 || !owned) {
      throw new TypeError('Original bonus HUD destination and initial owned item are required');
    }
    this.precision = precision;
    this.state = { phase: 0, origin: [0, 0, 0], destination: destination.map(f32),
      position: destination.map(f32), elapsedMs: 0, visible: false, angles: [0, 0, 0],
      cached: { state: owned.state, type: owned.type, level: owned.level } };
  }
  step(owned, deltaSeconds) {
    return updateNativeBonusHud(this.state, owned, deltaSeconds, this);
  }
}
