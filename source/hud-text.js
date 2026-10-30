import {nativeHudRootContext, nativeHudCompositeTransform, nativeHudElementTransform,
  nativeHudIniTransform, projectNativeHudPoint, getNativeHudCameraSpec} from './hud-mesh.js';
import {NATIVE_PRECISION} from './simulation/native-precision.js';

// Original HUD: 0045dca0/0045dde0 load fonts, 0045b140 aliases lowercase,
// 00461b50 chooses default alignment, 0045a6b0/004631d0/004632c0/00463400 lay out.
const f = Math.fround;
const key = value => String(value ?? '').toLowerCase();
const pair = (value, defaults) => {
  const values = String(value ?? '').split(';');
  return defaults.map((fallback, i) => values[i]?.trim() ? Number(values[i]) : fallback);
};
const HUD_TANGENT = Math.tan(getNativeHudCameraSpec().horizontalFov / 2);
const namedCharacters = {
  space: ' ', dot: '.', plus: '+', minus: '-', product: '*',
  div: ':', equals: '=', exclamation: '!', question: '?',
};

export function getHudFont(config, name) {
  const overlay = config['overlay.ini'] ?? config, section = overlay[key(name)];
  if (!section) throw new Error(`Missing original HUD font: ${name}`);
  const glyphs = {};
  const add = (character, value) => {
    const [texture, ...numbers] = value.split(';');
    const [x, y, width, height] = numbers.map(Number);
    glyphs[character] = {texture: `${key(texture)}.tga`, x, y, width, height};
  };
  for (const [name, value] of Object.entries(section)) {
    const character = /^[a-z0-9]$/.test(name) ? name.toUpperCase() : namedCharacters[name];
    if (character) add(character, value);
  }
  for (const [code, value] of Object.entries(overlay[`${key(name)}_ascii`] ?? {})) {
    add(String.fromCharCode(Number(code)), value);
  }
  for (let code = 65; code <= 90; code++) {
    const upper = String.fromCharCode(code), lower = upper.toLowerCase();
    if (!glyphs[lower] && glyphs[upper]) glyphs[lower] = glyphs[upper];
  }
  return {name: key(name), glyphs, distance: Number(section.distance ?? 0),
    maxWidth: Math.max(0, ...Object.values(glyphs).map(glyph => glyph.width))};
}

export function getHudStringSpec(config, id, {overrides = {}, precision = NATIVE_PRECISION, font: reusedFont} = {}) {
  const overlay = config['overlay.ini'] ?? config, section = overlay[key(id)];
  if (!section) throw new Error(`Missing original HUD string: ${id}`);
  const type = key(section.type), font = reusedFont ?? getHudFont(overlay, section.font);
  if (!['fixed', 'proportional'].includes(type)) throw new Error(`Unknown HUD string type: ${type}`);
  const options = {precision};
  const transform = name => {
    if (!name || key(name) === 'screen') return {context: nativeHudRootContext(), visible: true};
    const node = overlay[key(name)];
    if (!node) throw new Error(`Missing original HUD parent: ${name}`);
    const parent = transform(node.parent), override = overrides[key(name)] ?? {};
    return {context: nativeHudCompositeTransform({
      ...nativeHudIniTransform(node, {composite: true, ...options}), ...override,
    }, parent.context, options), visible: parent.visible && (override.visible ?? key(node.visible) !== 'false')};
  };
  const parent = transform(section.parent), override = overrides[key(id)] ?? {};
  // 45caa0 uses composite normalization, without its LEFT/TOP correction.
  const local = {...nativeHudIniTransform({...section, alignment: 'CENTER&CENTER'},
    {composite: true, ...options}), ...override};
  if (section.position !== undefined && override.position === undefined) {
    const r = precision === 24 ? f : value => value;
    const [x, y, z] = pair(section.position, [0, 0, 0]).map(f);
    const nx = r(x / 480), ny = r(y / 480);
    local.position = [f(r(r(nx + nx) - r(640 / 480))), f(r(1 - r(ny + ny))), f(z / 1000)];
  }
  // String::SetScale463c90 stores float[3] (458420) and also sets its horizontal
  // extent (458be0). Its overridden transform463bb0 uses parent[3], not
  // ordinary Composite's parent[4].
  local.scale = local.scale.map(f);
  const context = nativeHudCompositeTransform({...local, width: local.scale[0]}, parent.context, options);
  context[4] = f(local.scale[0] * parent.context[3]);
  const position = projectNativeHudPoint([context[0], context[1], f(context[2] + 1)]);
  return {id: key(id), type, font, length: Number(section.length), text: section.text ?? '',
    alignment: key(section.alignment || (type === 'fixed' ? 'RIGHT' : 'LEFT')),
    maxCharWidth: Number(section.maxcharwidth ?? font.maxWidth),
    cellWidth: override.cellWidth,
    position, scale: context.slice(6, 9), context, precision,
    // Native String fields +4/+0x10 and the parent context passed to 463bb0.
    local: {position: local.position, scale: local.scale}, parentContext: parent.context,
    visible: parent.visible && (override.visible ?? key(section.visible) !== 'false'),
    rgba: override.rgba ?? pair(section.rgba, [255, 255, 255, 255]),
    coordinateSpace: {width: 640, height: 480}};
}

// Coordinates returned by the original layout routines before parent transforms.
// cellWidth may be pixels for isolated fixtures or normalized screen coordinates.
export function nativeGlyphCenters(font, type, alignment, length, cellWidth, input,
  precision = NATIVE_PRECISION) {
  const r = precision === 24 ? f : Number;
  const characters = Array.from(String(input)).slice(0, length);
  const ratio = f(f(cellWidth) / f(font.maxWidth));
  if (type === 'fixed') {
    // 45a6b0 stores ratio and scaled distance (FSTP), but keeps distance+cell
    // width and the cell product in ST until the final FSTP.
    const distance = f(f(font.distance) * ratio);
    const padding = length - characters.length;
    const start = alignment === 'right' ? padding : alignment === 'center' ? Math.trunc(padding / 2) : 0;
    const cells = Array(length).fill(' ');
    characters.forEach((character, index) => { cells[start + index] = character; });
    const pitch = r(distance + f(cellWidth));
    return cells.map((character, index) => ({
      character,
      center: f(r((alignment === 'left' ? index + .5
        : alignment === 'center' ? f(f(1 - length) * .5) + index : index - length + .5) * pitch)),
    }));
  }
  // 4631d0/4632c0/463400: width*ratio stays in ST for the half-width term and
  // is stored (FST) for the advance; distance*ratio is recomputed in ST.
  const width = character => r(f(font.glyphs[character]?.width ?? 0) * ratio);
  const distance = r(f(font.distance) * ratio);
  const result = Array(characters.length);
  let cursor = 0;
  if (alignment === 'center') {
    let total = f(r(r(f(font.distance) * (characters.length - 1)) * ratio));
    for (let i = characters.length - 1; i >= 0; i--) total = f(r(width(characters[i]) + total));
    cursor = f(total * -.5);
  }
  if (alignment === 'right') {
    for (let i = characters.length - 1; i >= 0; i--) {
      const w = width(characters[i]);
      result[i] = {character: characters[i], center: f(r(cursor - r(w * .5)))};
      cursor = f(r(cursor - r(distance + f(w))));
    }
  } else {
    characters.forEach((character, i) => {
      const w = width(character);
      result[i] = {character, center: f(r(r(w * .5) + cursor))};
      cursor = f(r(r(distance + f(w)) + cursor));
    });
  }
  return result;
}

// Source quads (0045ed60) are centered in both axes. Output destinations are
// top-left rectangles in the original 640x480 HUD coordinate system.
export function layoutHudText(spec, text = spec.text) {
  const cellWidth = spec.cellWidth ?? f(f(2 * spec.maxCharWidth) / spec.coordinateSpace.width);
  const centers = nativeGlyphCenters(spec.font, spec.type, spec.alignment, spec.length, cellWidth, text, spec.precision);
  const result = [], options = {precision: spec.precision};
  for (let cell = 0; cell < centers.length; cell++) {
    const {character, center} = centers[cell], source = spec.font.glyphs[character];
    if (!source) continue;
    const transform = nativeHudElementTransform({position: [center, 0, 0]}, spec.context, options);
    const [centerX, centerY] = projectNativeHudPoint(transform.position);
    const factor = 320 / (HUD_TANGENT * transform.position[2]);
    const width = source.width * transform.scale[0] * factor;
    const height = source.height * transform.scale[1] * factor;
    result.push({character, cell, source, centerX, centerY,
      x: centerX - width / 2, y: centerY - height / 2, width, height});
  }
  return result;
}

const signedDecimal = (value, width = 0) => {
  const number = Math.trunc(value);
  return number < 0 ? `-${String(-number).padStart(width - 1, '0')}` : String(number).padStart(width, '0');
};

// 0046f700 uses signed integer division; 0046f5f0 has an 11-character buffer.
export function formatRaceTime(milliseconds) {
  const time = milliseconds | 0;
  return [Math.trunc(time / 60000), Math.trunc(time % 60000 / 1000), Math.trunc(time % 1000 / 10)]
    .map(value => signedDecimal(value, 2)).join(':').slice(0, 11);
}

// 0046f770: seconds (not minutes), centiseconds, a seven-character buffer.
export function formatCountdownTime(milliseconds) {
  const time = milliseconds | 0;
  return `${signedDecimal(time / 1000)}:${signedDecimal(time % 1000 / 10, 2)}`.slice(0, 7);
}

// 0046e6a0/0046ecc0. The caller owns lap timing and the native three-second
// finished-lap hold; provide heldLapTimeMs only while that state is active.
export function getRaceHudText({lapCounter, totalLaps, lapTimeMs, bestLapTimeMs = 0x0fffffff,
  heldLapTimeMs = null, countdownTimeMs = null}) {
  const result = {
    string_lap_value: String(Math.max(0, Math.min(totalLaps, lapCounter + 1))),
    string_lapof_value: `/${totalLaps}`,
    string_laptime_value: formatRaceTime(heldLapTimeMs ?? lapTimeMs),
    string_bestlap_value: bestLapTimeMs === 0x0fffffff ? '--:--:--' : formatRaceTime(bestLapTimeMs),
  };
  if (countdownTimeMs !== null) result.string_countdown_value = formatCountdownTime(countdownTimeMs);
  return result;
}
