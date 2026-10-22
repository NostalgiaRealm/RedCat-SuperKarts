import {nativeTrigTable} from './simulation/native-integrator.js';
import {getSoundSpec} from './asset-animation.js';
import {nativeCameraMatrix} from './simulation/native-camera-matrix.js';
const f = Math.fround;

/** 491530: ranges are the CALLBACK window (twice the render distance).
 * Attached sound clones set alwaysUpdate=true in43f020, bypassing both ranges. */
export function nativeObjectCallbackCount({visible = true, alwaysUpdate = false, sector, ranges}) {
  if (!visible) return 0;
  const inRange = range => range && range[0] <= sector && sector <= range[1];
  return Number(alwaysUpdate || !!inRange(ranges?.[0])) + Number(!alwaysUpdate && !!inRange(ranges?.[1]));
}

/** 49da60. Original Sound.ini range/volume/doppler are integer fields. */
export function getNativeSpatialAudioCommands({position, velocity = [0, 0, 0],
  listenerPosition, listenerForward, listenerVelocity = [0, 0, 0],
  range, baseVolume, doppler, playing = false, loop = true, precision = 24}) {
  const r = precision === 24 ? f : Number;
  const delta = position.map((value, i) => f(r(value - listenerPosition[i])));
  const distance = f(r(Math.sqrt(r(r(r(delta[0] * delta[0]) + r(delta[1] * delta[1])) + r(delta[2] * delta[2])))));
  if (!(distance < range)) return playing ? [{op: 'stop'}] : [];
  const direction = distance === 0 ? [0, 1, 0] : delta.map(value => f(r(value / distance)));
  const volumePercent = Math.max(0, Math.min(100,
    Math.trunc((100 - Math.trunc(Math.trunc(distance) * 100 / range)) * baseVolume / 100)));
  const cross = f(r(r(direction[2] * listenerForward[0]) - r(listenerForward[2] * direction[0])));
  const exponent = r(r(2 * Math.abs(cross)) + 2);
  const pan = Math.max(-10000, Math.min(10000, Math.trunc((cross < 0 ? -1 : 1) * 10 ** exponent)));
  const relative = velocity.map((value, i) => r(value - listenerVelocity[i]));
  const dot = r(r(r(relative[2] * direction[2]) + r(relative[1] * direction[1])) + r(relative[0] * direction[0]));
  const pitchPercent = doppler === 0 ? 0 : Math.trunc(r(-r(dot / 340) * doppler));
  return [...(playing ? [] : [{op: 'play', loop}]), {op: 'volume', percent: volumePercent},
    {op: 'pan', hundredthDb: pan}, {op: 'pitch', percent: pitchPercent || 0}];
}

/** DirectSound SetPan attenuates just one channel in hundredths of dB. */
export function nativePanGains(hundredthDb) {
  return hundredthDb >= 0 ? [10 ** (-hundredthDb / 2000), 1] : [1, 10 ** (hundredthDb / 2000)];
}

/** 43b660 copies the camera's orientation matrix, negating its forward row.
 * 498c00 copies body translation only for POSITION_LOCK cameras (player/failure).
 * Free start/finish cameras retain zero translation. Pass the mode explicitly. */
export function getNativeSoundListener(camera, body, {precision = 24, matrixTranslation} = {}) {
  if (!matrixTranslation) throw new Error('Original camera matrix translation is required');
  const r = precision === 24 ? f : Number;
  const forward=nativeCameraMatrix(camera,{precision}).slice(6).map(value=>f(-value));
  const {sin, cos} = nativeTrigTable(precision), angle = Math.trunc(body.yaw) & 4095;
  const lateral = body.lateralSpeed, longitudinal = body.forwardSpeed;
  const velocity = [f(r(r(cos[angle] * lateral) - r(sin[angle] * longitudinal))), 0,
    f(r(r(cos[angle] * longitudinal) + r(sin[angle] * lateral)))];
  return {position: matrixTranslation.map(f), forward, velocity};
}

/** Factory43f020 clones the original event selected by final OMP integer.
 * Type5 has no sound attachment; its default source0 must not become KKT. */
export function getNativeScenerySounds(config, manifest, track) {
  const sounds = config[`etappe${track.id}.ini`]?.sounds;
  if (!sounds || Number(sounds.count) < 1) return [];
  const attachedTypes = new Set([1, 3, 6, 9, 10, 12, 13, 46, 47]);
  return track.placements.flatMap((placement, placementIndex) => {
    if (!attachedTypes.has(placement.type) || placement.value === -1) return [];
    const event = sounds[placement.value]?.split(',')[1]?.trim();
    if (!event || (track.id === 1 && event.toUpperCase() === 'KAKTUS')) return [];
    const sound = getSoundSpec(config, manifest, event);
    if (!sound || sound.index === 255) return [];
    if (!sound.file) throw new Error(`Missing scenery sound ${event}`);
    return [{placementIndex, voiceId: `scenery:${placementIndex}`, sound,
      position: [...placement.position], sector: placement.sector, alwaysUpdate: true, range: Number(sound.fields[4]),
      //43f020 clones immutable Sound.ini TYPE, after static-source overrides.
      baseVolume: Number(sound.fields[3]), doppler: Number(sound.fields[5])}];
  });
}

/**43e140 type2/26 attach a clone directly, outside etappe[SOUNDS].
 *43fe80 invokes its nonlooping spatial update only at impact. */
export function getNativeReactiveSounds(config, manifest, track) {
  const sound = getSoundSpec(config, manifest, 'PION_HIT_CAR');
  if (!sound?.file) throw new Error('Missing original PION_HIT_CAR sound');
  return track.placements.flatMap((placement, placementIndex) =>
    placement.type === 2 || placement.type === 26 ? [{
      placementIndex, voiceId: `impact:${placementIndex}`, sound,
      position: [...placement.position], sector: placement.sector,
      range: Number(sound.fields[4]), baseVolume: Number(sound.fields[3]),
      doppler: Number(sound.fields[5]),
    }] : []);
}
