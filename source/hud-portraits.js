import {nativeTrigTable} from './simulation/native-integrator.js';
import {nativeHudIniTransform} from './hud-mesh.js';

const f = Math.fround, rfor = precision => precision === 24 ? f : Number;
const names = ['redcat', 'whizzkitty', 'brutus', 'max'];
const labels = ['first', 'second', 'third', 'fourth', 'fifth'];

/** Original Moving.cpp 0x4676d0: rank changes follow a half-circle, whereas
 * changes in spacing after another racer moves use linear interpolation. */
export function nativeHudPortraitCurve(start, target, fraction, {curved = true, precision = 24} = {}) {
  const r = rfor(precision), t = f(fraction), inv = r(1 - t);
  const linear = i => f(r(r(t * target[i]) + r(inv * start[i])));
  if (!curved) return [0, 1, 2].map(linear);
  const dx = f(r(target[0] - start[0])), dy = r(target[1] - start[1]);
  const direction = r(Math.atan2(dy, dx) * r(4096 / r(f(Math.PI) * 2)));
  const sweep = Math.trunc(r(r(4096 * t) * -.5));
  const angle = Math.trunc(r(direction + (1024 - sweep))) & 4095;
  const radius = r(Math.sqrt(r(r(dy * dy) + r(dx * dx))) * .5);
  const {sin, cos} = nativeTrigTable(precision);
  const xMiddle = r(r(start[0] + target[0]) * .5);
  const yMiddle = f(r(f(r(start[1] + target[1])) * .5));
  return [f(r(r(sin[angle] * radius) + xMiddle)),
    f(r(r(cos[angle] * radius) + yMiddle)), linear(2)];
}

export function createNativeHudPortrait(charName = 'redcat') {
  const name = String(charName).toLowerCase();
  return {name: names.includes(name) ? name : 'cou', state: 2, start: [0, 1, 0],
    target: [0, 1, 0], position: [0, 1, 0], elapsedMs: 0, durationMs: 400,
    curved: true, rank: -1};
}

/** 0x467000/0x46a220 retain the start position until movement completes. */
export function updateNativeHudPortrait(portrait, deltaSeconds, {precision = 24} = {}) {
  if (portrait.state !== 1) return portrait;
  const r = rfor(precision), elapsed = r(r(f(deltaSeconds) * 1000) + portrait.elapsedMs);
  portrait.elapsedMs = f(elapsed);
  if (elapsed >= portrait.durationMs) {
    portrait.state = 2;
    if (!portrait.curved) { portrait.curved = true; portrait.durationMs = 400; }
    portrait.start = [...portrait.target];
    portrait.position = [...portrait.target];
  } else {
    portrait.position = nativeHudPortraitCurve(portrait.start, portrait.target,
      f(r(elapsed / portrait.durationMs)), {curved: portrait.curved, precision});
  }
  return portrait;
}

export function nativeHudPortraitRankLayout(rank, playerRank, {precision = 24} = {}) {
  const r = rfor(precision), small = f(.32), large = f(.4);
  const distance = f(rank < playerRank ? r(r(rank + .5) * small)
    : rank > playerRank ? r(r(r(rank - .5) * small) + large)
      : r(r(rank * small) + r(large * .5)));
  const offset = r((rank === playerRank ? f(.19) : f(.15)) * (rank === playerRank ? large : small));
  const labelDistance = f(r(offset + distance));
  return {portraitY: f(r(1 - distance)), labelY: f(r(1 - labelDistance)), distance};
}

/** Characters are in original Race.ini CHARDATA order, not finishing order. */
export function createNativeHudPortraits({characters, playerIndex, precision = 24}) {
  if (!Array.isArray(characters) || characters.length < 1 || characters.length > 5
    || playerIndex < 0 || playerIndex >= characters.length || ![24, 53].includes(precision)) {
    throw new RangeError('Original portrait controller requires 1–5 racers and a valid player index');
  }
  return {playerIndex, precision, portraits: characters.map(createNativeHudPortrait),
    labelY: new Array(characters.length).fill(null)};
}

/** 0x46b5e0 checks rank changes only while the preceding move has finished;
 * a newly started move is first advanced on the NEXT native update. */
export function updateNativeHudPortraits(state, deltaSeconds, ranks) {
  if (ranks.length !== state.portraits.length || ranks.some(rank =>
    !Number.isInteger(rank) || rank < 0 || rank >= ranks.length)) {
    throw new RangeError('Native HUD ranks must be zero-based racer ranks');
  }
  const r = rfor(state.precision), options = {precision: state.precision};
  for (const [index, portrait] of state.portraits.entries()) {
    const rank = ranks[index], layout = nativeHudPortraitRankLayout(rank, ranks[state.playerIndex], options);
    if (portrait.state === 1) updateNativeHudPortrait(portrait, deltaSeconds, options);
    else if (portrait.state === 2) {
      const changedRank = rank !== portrait.rank;
      const changedSpacing = Math.abs(r(r(portrait.target[1] - 1) + layout.distance)) > .01;
      if (changedRank || changedSpacing) {
        portrait.target[1] = layout.portraitY;
        if (changedRank) portrait.rank = rank;
        else { portrait.curved = false; portrait.durationMs = 100; }
        portrait.state = 1;
        portrait.elapsedMs = 0;
      }
    } else throw new Error('Invalid original portrait movement state');
    state.labelY[rank] = layout.labelY;
  }
  return state;
}

/** Original node IDs and native normalized overrides for getHudMeshSpec.
 * Retain the Overlay.ini RGBA: backgrounds are alpha64, frames/faces alpha255. */
export function getNativeHudPortraitCommands(state, config) {
  const overlay = config['overlay.ini'], commands = [];
  for (const [index, portrait] of state.portraits.entries()) {
    const player = index === state.playerIndex;
    for (const prefix of ['back', 'frame', 'portr']) {
      const id = `${prefix}${portrait.name}`;
      const scale = nativeHudIniTransform(overlay[id]).scale;
      if (player) {
        scale[0] = f(scale[0] * 1.25); scale[1] = f(scale[1] * 1.25); scale[2] = f(scale[2] * f(.001));
      }
      commands.push({id, overrides: {[id]: {position: [...portrait.position], scale, visible: true}}});
    }
  }
  for (let rank = 0; rank < state.portraits.length; rank++) {
    const id = labels[rank], position = nativeHudIniTransform(overlay[id]).position;
    if (state.labelY[rank] !== null) position[1] = state.labelY[rank];
    commands.push({id, overrides: {[id]: {position, visible: true}}});
  }
  // Elements are inserted by Overlay.ini's numbered list: all backgrounds,
  // then frames, faces and ordinal labels. Keep this order during overlap.
  const order = Object.entries(overlay.elements).filter(([key]) => /^\d+$/.test(key))
    .sort(([a], [b]) => Number(a) - Number(b)).map(([, value]) => value.toLowerCase());
  return commands.sort((a, b) => order.indexOf(a.id) - order.indexOf(b.id));
}
