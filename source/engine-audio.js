import {getSoundSpec} from './asset-animation.js';

const f = Math.fround;
const keys = ['geara', 'gearb', 'stat'];

/** Original Car_Snd.ini is loaded with car index 0 even for other kart models. */
export function getNativeEngineAudioSpec(config, manifest) {
  const section = config['car_snd.ini']?.car0;
  if (!section) throw new Error('Missing original Car_Snd.ini car0');
  const count = Number(section.nrgears);
  const sound = key => {
    const spec = getSoundSpec(config, manifest, section[key]);
    if (!spec?.file) throw new Error(`Missing original engine sample: ${section[key]}`);
    return spec;
  };
  return {gearCount: count, minimumRpm: Number(section.minrpm), maximumRpm: Number(section.maxrpm),
    start: sound('start'), switchGear: sound('switchgear'),
    layers: keys.map(key => ({sound: sound(key), gears: Array.from({length: count}, (_, i) =>
      section[`${key}${i}`].split(',').map(Number))})),
    // 0x418590 only loads cylinder rows if a Cylinders= sample list exists.
    cylinderSamples: section.cylinders ? section.cylinders.split(',').map(value => value.trim()) : [],
    nativeFunctions: ['004182d0', '00418780', '00418950', '00418c80', '004189d0', '00418980']};
}

export function createNativeEngineAudio(spec, {precision = 24} = {}) {
  if (spec.cylinderSamples.length) throw new Error('This source has cylinder samples requiring the native random scheduler');
  return {spec, precision, active: false, gear: -1,
    minimumRpm: Array.from({length: spec.gearCount}, (_, i) => i === 0 ? spec.minimumRpm : -1)};
}

/** 0x418950 is called by countdown START action 0x420d90 after the authored
 * camera pan completes. Loading/preparing samples must leave this inactive;
 * the green-light action is later and does not start the engine sound. */
export function startNativeEngineAudio(state) {
  state.active = true;
  return [{event: state.spec.start.event, op: 'play', loop: false}];
}

/** CarSound path 0x418980 stops the start/gear effects. Browser disposal must
 * also release loop voices owned by the view; do not confuse these operations. */
export function stopNativeEngineAudio(state) {
  if (!state.active) return [];
  state.active = false;
  return [state.spec.start, state.spec.switchGear].map(sound => ({event: sound.event, op: 'stop'}));
}

export function nativeEngineLayerParameters(row, rpm, minimumRpm, maximumRpm, {precision = 24} = {}) {
  const r = precision === 24 ? f : Number;
  let fraction = r(((rpm | 0) - minimumRpm) / (maximumRpm - minimumRpm));
  // x87's unordered comparison follows the below-zero branch too (0/0).
  if (!(fraction >= 0)) fraction = 0;
  else if (fraction > 1) fraction = 1;
  const pitchPercent = row[0] + Math.trunc(r((row[1] - row[0]) * fraction));
  const interpolatedVolume = row[2] + Math.trunc(r((row[3] - row[2]) * fraction));
  return {pitchPercent, volumePercent: Math.trunc(r(interpolatedVolume * .75))};
}

/** 0x418c80 waits for the original starter WAV, then starts three concurrent
 * loops. Each gear remembers RPM at its first entry for all later changes. */
export function updateNativeEngineAudio(state, {gear, rpm, startPlaying = false}) {
  if (!state.active || startPlaying) return [];
  if (!Number.isInteger(gear) || gear < 0 || gear >= state.spec.gearCount) throw new RangeError('Invalid native audio gear');
  rpm = Math.trunc(f(rpm));
  const commands = [];
  if (state.gear === -1) for (const layer of state.spec.layers) {
    commands.push({event: layer.sound.event, op: 'play', loop: true});
  }
  if (gear !== state.gear) {
    if (state.gear >= 0 && state.gear < state.spec.gearCount) {
      commands.push({event: state.spec.switchGear.event, op: 'play', loop: false});
    }
    if (state.minimumRpm[gear] === -1) state.minimumRpm[gear] = rpm;
  }
  for (const layer of state.spec.layers) {
    const parameters = nativeEngineLayerParameters(layer.gears[gear], rpm,
      Math.max(0, state.minimumRpm[gear]), state.spec.maximumRpm, state);
    commands.push({event: layer.sound.event, op: 'pitch', percent: parameters.pitchPercent},
      {event: layer.sound.event, op: 'volume', percent: parameters.volumePercent});
  }
  state.gear = gear;
  return commands;
}

/** 0x49d520, following integer group-volume multiplication in 0x49d570.
 * DirectSound consumes hundredths of a decibel, not a linear gain. */
export function nativeSoundVolume(volumePercent, groupPercent = 100) {
  const percent = Math.trunc((volumePercent | 0) * (groupPercent | 0) / 100);
  const hundredthDb = Math.trunc((percent - 100) * 3900 / 100) - 100;
  return {percent, hundredthDb, gain: 10 ** (hundredthDb / 2000)};
}

/** 0x49d5e0 adds an integer percentage of the original sample frequency. */
export function nativeSoundFrequency(originalSampleRate, pitchPercent = 0) {
  const frequency = Math.max(100, Math.min(100000,
    originalSampleRate + Math.trunc(originalSampleRate * (pitchPercent | 0) / 100)));
  return {frequency, playbackRate: frequency / originalSampleRate};
}

/** Source sample rate survives WebAudio's decode-time resampling. */
export function nativeWavSampleRate(arrayBuffer) {
  const view = new DataView(arrayBuffer);
  const text = offset => String.fromCharCode(...new Uint8Array(arrayBuffer, offset, 4));
  if (view.byteLength < 12 || text(0) !== 'RIFF' || text(8) !== 'WAVE') throw new Error('Not an original RIFF WAV');
  for (let offset = 12; offset + 8 <= view.byteLength;) {
    const size = view.getUint32(offset + 4, true);
    if (offset + 8 + size > view.byteLength) throw new Error('Truncated original WAV');
    if (text(offset) === 'fmt ') {
      if (size < 16) throw new Error('Invalid original WAV format');
      return view.getUint32(offset + 12, true);
    }
    offset += 8 + size + (size & 1);
  }
  throw new Error('Original WAV has no format chunk');
}
