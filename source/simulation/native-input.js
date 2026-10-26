/**
 * Recovered keyboard/gamepad-button input law, rcskspel.dat 0x433870/0x433cf0.
 * This is an isolated native subsystem, not a complete kart simulation.
 * Call on simulation updates, never once per browser render.
 */
export function createNativeInputState() {
  return { throttle: 0, brake: 0, steering: 0, handbrake: false };
}

export function updateNativeInput(state, buttons, deltaSeconds, mirrored = false, onBonus) {
  // 48f4e0 returns the float32 representation of .1, slightly above JS .1.
  if (!Number.isFinite(deltaSeconds) || deltaSeconds < 0 || deltaSeconds > Math.fround(0.1)) {
    throw new RangeError('Native input delta must be between 0 and 0.1 seconds');
  }
  // 433870 writes handbrake before firing, then updates throttle/brake/steer.
  state.handbrake = Boolean(buttons.handbrake);
  onBonus?.();
  state.throttle = buttons.accelerate ? Math.min(100, Math.fround(state.throttle + 70 * deltaSeconds)) : 0;
  // x87 -> __ftol truncates after EACH update (0x433a19..0x433a52).
  // Moving this routine into requestAnimationFrame would break braking at >40Hz.
  state.brake = buttons.brake ? Math.min(100, Math.trunc(state.brake + 40 * deltaSeconds)) : 0;

  const left = Boolean(mirrored ? buttons.right : buttons.left);
  const right = Boolean(mirrored ? buttons.left : buttons.right);
  const previous = state.steering;
  const gain = (1 - Math.abs(previous) * 0.01) * 400 * deltaSeconds;
  if (left) {
    state.steering = previous > 0 ? 0 : Math.max(-100, Math.fround((previous === 0 ? -15 : previous) - gain));
  } else if (right) {
    state.steering = previous < 0 ? 0 : Math.min(100, Math.fround((previous === 0 ? 15 : previous) + gain));
  } else {
    state.steering = Math.fround(Math.sign(previous) * Math.max(0, Math.abs(previous) - 400 * deltaSeconds));
  }
  return state;
}

/** 0x42ef90 clamp +0x4341d0 active-model analog path; no digital ramp. */
export function updateNativeAnalogInput(state, { x, y, buttonMask = 0 }, mirrored = false, onBonus) {
  if (!Number.isInteger(x) || !Number.isInteger(y)) throw new TypeError('Native analog axes must be integer positions');
  x = Math.max(0, Math.min(100, x));
  y = Math.max(0, Math.min(100, y));
  state.steering = mirrored ? (50 - x) * 2 : x * 2 - 100;
  state.throttle = y < 50 ? 0 : y * 2 - 100;
  state.brake = y < 50 ? (50 - y) * 2 : 0;
  state.handbrake = Boolean(buttonMask & 0x20);
  // 4341d0 fires after storing all analog controls, unlike keyboard433870.
  onBonus?.();
  return state;
}

/**
 * Browser adaptation: normalized pad axes/triggers become the native integer
 * 0..100 joystick positions. The original has one combined throttle/brake axis.
 * Deadzone configuration belongs to the host, before this conversion.
 */
export function nativeAnalogFromNormalized({ steer = 0, throttle = 0, brake = 0,
  handbrake = false, bonus = false } = {}) {
  const axis = value => Number.isFinite(value) ? Math.max(-1, Math.min(1, value)) : 0;
  return {
    x: Math.round((axis(steer) + 1) * 50),
    y: Math.round((axis(Math.max(0, throttle) - Math.max(0, brake)) + 1) * 50),
    buttonMask: (handbrake ? 0x20 : 0) | (bonus ? 0x10 : 0),
  };
}
