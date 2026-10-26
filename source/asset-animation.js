// Native references are rcskspel.dat virtual addresses. All coordinates remain native.
const lower = value => String(value || '').trim().toLowerCase();
const split = value => String(value || '').split(/[,;]/).map(s => s.trim());
const number = value => Number(String(value || '0').split(';')[0].trim());

export function resolveAsset(manifest, kind, name, extension) {
  let key = lower(name).replaceAll('\\', '/').split('/').pop();
  if (extension && !key.endsWith(extension)) key += extension;
  return manifest[kind]?.[key]?.file ?? null;
}

// SndGfx [SKY], 0042d480 selects mesh<track> and <mode><track>.
// 00422d50 scales 10,4,10; 00423010 copies active racer's XYZ and identity rotation.
export function getSkySpec(config, manifest, trackId, mode = 0) {
  const section = config['sndgfx.ini']?.sky || {};
  const meshName = section[`mesh${trackId}`];
  const textureName = section[`${mode}${trackId}`];
  if (!meshName || !textureName) return null;
  return {mesh: resolveAsset(manifest, 'meshes', meshName, '.d3d'),
    texture: resolveAsset(manifest, 'images', textureName, '.tga'),
    scale: [10, 4, 10], positionSource: 'active-racer', rotation: [0, 0, 0],
    nativeFunctions: ['0042d480', '00422d50', '00423010']};
}

// 0044e460 builds inclusive ascending/descending frame lists.
export function getSceneryAnimation(config, manifest, trackId, animationName) {
  const name = lower(animationName).replace(/_anim$/, '');
  const section = config[`animobj${trackId}.ini`]?.[name];
  if (!section) return null;
  const sequences = [];
  for (let i = 0; i < number(section.count); i++) {
    const sequenceName = lower(section[String(i)]);
    const [prefix, from, to, fps, loops] = split(section[sequenceName]);
    const first = Number(from), last = Number(to), step = first <= last ? 1 : -1;
    if (!prefix || !Number.isInteger(first) || !Number.isInteger(last)) continue;
    const frames = [];
    for (let frame = first; ; frame += step) {
      const source = `${lower(prefix)}${String(frame).padStart(4, '0')}.d3d`;
      frames.push({source, file: resolveAsset(manifest, 'meshes', source)});
      if (frame === last) break;
    }
    sequences.push({name: sequenceName, fps: Number(fps), loops: Number(loops), frames});
  }
  return {name, texture: resolveAsset(manifest, 'images', section.texture, '.tga'),
    sequences, nativeFunctions: ['0044e460', '0044e850']};
}

export function createNativeMeshAnimation(sequence, nowMs = 0) {
  return {sequence, frame: 0, forward: true, completedLoops: 0, lastTime: nowMs >>> 0};
}

// Literal 0044e850 behavior: strict threshold, one advance, discarded excess time.
// In particular loop=-2 reverses at count-1 and skips that endpoint.
// Finite-loop transitions belong to the caller, not this native mesh-clock function.
export function advanceNativeMeshAnimation(state, nowMs, speedPercent = 100) {
  const {sequence} = state, count = sequence.frames.length;
  if (!count || sequence.fps <= 0) return null;
  const threshold = Math.trunc(Math.trunc(speedPercent * 1000 / sequence.fps) / 100) >>> 0;
  const now = nowMs >>> 0;
  if (((now - state.lastTime) >>> 0) > threshold) {
    state.lastTime = now;
    const wasForward = state.forward;
    state.frame += wasForward ? 1 : -1;
    if (state.frame === count || count === 1) {
      state.frame = 0; state.completedLoops++;
    }
    if (sequence.loops === -2 && (state.frame === -1 || state.frame === count - 1)) {
      state.forward = !wasForward;
      state.frame = wasForward ? state.frame - 2 : 1;
      state.completedLoops++;
    }
  }
  return sequence.frames[state.frame] ?? null;
}

// Type3 requires race mode1; type4 requires mode2 (0043e140).
// Other types may be hidden by their controllers after construction.
export function placementExistsInMode(placement, mode) {
  return placement.type === 3 ? mode === 1 : placement.type === 4 ? mode === 2 : true;
}

export function getRotationSpec(config, placement) {
  if (![7, 43].includes(placement.type)) return null;
  const row = config['rotobj.ini']?.[lower(placement.animation)];
  if (!row) return null;
  return {increment: ['x', 'y', 'z'].map(axis => Math.fround(number(row[`rotation${axis}`]) * 0.001)),
    randomize: ['x', 'y', 'z'].map(axis => number(row[`startrandom${axis}`]) === 1),
    nativeFunctions: ['0043e140', '0043f490']};
}

export function createNativeRotation(spec, degrees, randomInt, angleCount = 4096) {
  // 0043e140 only randomizes when the config equals 1. Value100 stays unrandomized.
  // 00442fc0 -> 004ac410 -> 004a1510 selects 4096 in active game initialization.
  const angles = degrees.map(value => Math.fround(value * angleCount / 360));
  for (let i = 0; i < 3; i++) {
    if (spec.randomize[i]) {
      if (!randomInt) throw new Error('Native random integer source required for rotation phase');
      angles[i] = randomInt() % 2000;
    }
  }
  return {spec, angles, angleCount};
}

export function advanceNativeRotation(state, deltaSeconds, {precision = state.precision ?? 24} = {}) {
  // 0043f490 x87 operations: 60 / (1 / (dt + 0.01)), then float32 store.
  const r = precision === 24 ? Math.fround : Number;
  const multiplier = r(60 / r(1 / r(Math.fround(deltaSeconds) + .01)));
  for (let i = 0; i < 3; i++) {
    state.angles[i] = Math.fround(r(state.angles[i] + r(state.spec.increment[i] * multiplier)));
    if (state.angles[i] > 4096) state.angles[i] = Math.fround(state.angles[i] - 4096);
  }
  return state.angles.map(value => value * Math.PI * 2 / (state.angleCount ?? 4096));
}

// eNN_anim is a list of mesh+texture pairs, not an FPS definition.
export function getOverlayAssets(config, manifest, trackId, name) {
  const section = config[`e${String(trackId).padStart(2, '0')}_anim.ini`]?.[lower(name)];
  if (!section) return [];
  return Array.from({length: number(section.count)}, (_, i) => {
    const [mesh, texture] = split(section[String(i)]);
    return {mesh: resolveAsset(manifest, 'meshes', mesh),
      texture: resolveAsset(manifest, 'images', texture.replace(/\.pcx$/i, '.tga')) ??
        resolveAsset(manifest, 'images', texture)};
  });
}

export function getTrackMusic(manifest, trackId) {
  // 0042d7d0 initialization formats rclemu%02d.dat using the track ID.
  return resolveAsset(manifest, 'audio', `rclemu${String(trackId).padStart(2, '0')}.dat`);
}

export function getSoundSpec(config, manifest, eventName) {
  for (const [index, value] of Object.entries(config['sound.ini']?.sndtypes || {})) {
    if (!/^\d+$/.test(index)) continue;
    // Native4b1f60's default delimiters are comma, equals and colon.
    // Sound.ini record404 uses CDT=cdt.wav, so comma-only parsing loses it.
    const fields = value.split(/[,=:]/).map(part => part.trim());
    if (lower(fields[0]) !== lower(eventName)) continue;
    return {index: Number(index), event: fields[0], source: fields[1],
      file: resolveAsset(manifest, 'audio', fields[1]), fields};
  }
  return null;
}

export function getMenuSample(config, manifest, index, character = null) {
  let section = config['ini/soundset.dat']?.generic_samples;
  if (character) {
    const bank = config['ini/soundset.dat']?.soundsets?.[lower(character)];
    if (!bank) return null;
    section = config[`ini/${lower(bank)}`]?.sample_set;
  }
  const name = section?.[String(index)];
  return name ? resolveAsset(manifest, 'audio', name) : null;
}
