const f = Math.fround;
const loopDurations = [1000, 1000, 1000, 3000, 3000, 3000];
const eventTable = {
  1: [6, 0, 0, true], 3: [25, 1, 5000], 4: [23, 1, 4000],
  5: [22, 4, 5000], 6: [17, 5, 5000], 7: [28, 3, 0],
  10: [26, 1, 5000], 11: [31, 1, 5000],
};

/** Native430610 dispatcher. IDs0/8/9 target other HUD controllers. */
export function getNativeNotificationEvent(config, id) {
  if (id === 2) return {op: 'stop'};
  const entry = eventTable[id];
  if (!entry) return null;
  const [textId, mode, duration, interrupt = false] = entry;
  const language = config['language.ini'];
  const name = ['nederlands', 'engels', 'duits'][Number(language.settings.language)];
  const text = language[name]?.[textId];
  if (text === undefined) throw Error(`Missing original notification text ${textId}`);
  return {op: 'message', id, textId, text, mode, duration, interrupt};
}

export function createNativeHudNotifications({precision = 24} = {}) {
  if (![24, 53].includes(precision)) throw RangeError('Unsupported native precision');
  return {precision, state: 0, elapsedMove: 0, loopDuration: 1000, duration: 5000,
    elapsedTotal: 0, mode: 0, queue: [], visible: false, text: '', position: [0, 0, 0],
    scale: [2, 2, 2], cellWidth: f(2 / 30), rgbaPacked: 0xffffffff};
}
const round = state => state.precision === 24 ? f : value => value;
function alpha(state, value) {
  state.rgbaPacked = ((Math.trunc(round(state)(f(value) * 255)) << 24) | 0xffffff) >>> 0;
}
function scale(state, value) { state.scale = [f(value), f(value), f(value)]; }
function width(state, value) { state.cellWidth = f(round(state)(round(state)(f(value) * 2) / 30)); }

function start(state, elapsed = 0) {
  state.elapsedTotal = f(elapsed);
  state.visible = true;
  state.state = 1;
  state.elapsedMove = 0;
  updateNativeHudNotifications(state, 0); //431640 freezes native clock for this call.
}

/** 46c1e0 queues ordinary notices.46c180 interrupts, preserving an unfinished
 * timed notice at the front. It also advances once with the caller's delta. */
export function showNativeHudNotification(state, {text, mode, duration, interrupt = false},
  deltaSeconds = 0) {
  if (!Number.isInteger(mode) || mode < 0 || mode > 5) throw RangeError('Unknown native notification mode');
  const r = round(state), message = {text: String(text), mode, duration: duration | 0, elapsed: 0};
  if (state.state === 1 && !interrupt) {
    state.queue.push(message);
    if (state.duration <= .1) state.duration = f(Math.trunc(r(state.elapsedTotal + 1)));
    return state;
  }
  if (state.state === 1 && interrupt) {
    if (state.elapsedTotal < state.duration) state.queue.unshift({
      text: state.text, mode: state.mode, duration: Math.trunc(state.duration),
      elapsed: Math.trunc(state.elapsedTotal),
    });
    state.state = 0;
    state.visible = false;
  }
  state.text = message.text;
  state.mode = mode;
  state.position = [0, 0, 0];
  state.scale = [2, 2, 2];
  state.rgbaPacked = 0xffffffff;
  width(state, 1);
  state.loopDuration = loopDurations[mode];
  state.duration = f(message.duration);
  start(state);
  if (interrupt) updateNativeHudNotifications(state, deltaSeconds);
  return state;
}

/** 46cc70 intentionally retains the previous style and loop duration while
 * resuming queued text. Preserve this shipped behavior, including its quirks. */
export function stopNativeHudNotification(state) {
  if (state.state !== 1) return state;
  state.state = 0;
  const next = state.queue.shift();
  if (!next) { state.visible = false; return state; }
  state.text = next.text;
  state.mode = next.mode;
  state.duration = f(next.duration);
  start(state, next.elapsed);
  return state;
}

export function updateNativeHudNotifications(state, deltaSeconds) {
  if (state.state !== 1) return state;
  const r = round(state), dt = r(f(deltaSeconds) * 1000);
  state.elapsedMove = f(r(state.elapsedMove + dt));
  const total = r(state.elapsedTotal + dt);
  state.elapsedTotal = f(total);
  if (state.duration > .1 && total >= state.duration) return stopNativeHudNotification(state);
  if (state.elapsedMove >= state.loopDuration) state.elapsedMove = 0;
  const fraction = f(r(state.elapsedMove / state.loopDuration));
  const ramp = fraction < .25 ? f(r(fraction * 4))
    : fraction < .5 ? 1 : fraction < .75 ? f(r(r(.75 - fraction) * 4)) : 0;
  switch (state.mode) {
    case 0: break;
    case 1: alpha(state, ramp); break;
    case 2: scale(state, f(r(ramp + 1))); break;
    case 3: {
      const inverse = r(1 - ramp);
      scale(state, f(r(r(inverse + inverse) + 1)));
      alpha(state, ramp);
      break;
    }
    case 4: {
      const quotient = r(state.elapsedTotal / state.duration), fraction = f(quotient);
      if (quotient > .5) {
        const currentWidth = r(r(30 * state.cellWidth) * .5);
        width(state, f(r(currentWidth * f(1.1))));
        scale(state, f(r(state.scale[0] * f(1.1))));
        alpha(state, f(r(1 - r(r(fraction * f(1.333)) - f(.333)))));
      }
      break;
    }
    case 5: {
      const x = Math.abs(r(r(.5 - r(state.elapsedTotal / state.duration)) * f(2.9)));
      const squared = f(r(x * x));
      state.position[0] = r(state.elapsedTotal * 2) < state.duration ? -squared : squared;
      break;
    }
  }
  return state;
}

export function dispatchNativeHudNotification(state, config, id, deltaSeconds = 0) {
  const event = getNativeNotificationEvent(config, id);
  if (event?.op === 'stop') stopNativeHudNotification(state);
  else if (event) showNativeHudNotification(state, event, deltaSeconds);
  return event;
}

export function getNativeHudNotificationOverride(state) {
  return {position: [...state.position], scale: [...state.scale], cellWidth: state.cellWidth,
    rgba: [255, 255, 255, state.rgbaPacked >>> 24], visible: state.visible};
}
