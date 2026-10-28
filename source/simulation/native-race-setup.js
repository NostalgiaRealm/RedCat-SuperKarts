import { nativePlayerStart } from './native-start.js';
import { nativeSectorDistance } from './native-race.js';
import { NATIVE_ANGLE_COUNT } from './native-integrator.js';
import { nativeRaceRouteOptions } from './native-race-options.js';
import { NATIVE_PRECISION } from './native-precision.js';
const f32 = Math.fround;

// rcskmenu.dat pointer tables 0x47bc80 and0x47bcd8, read from original PE.
export const NATIVE_COUNTRY_MESHES = Object.freeze(['NEDERLAND', 'DUITSLAND', 'ENGELAND', 'FRANKRIJK', 'SPANJE', 'ITALIE']);
export const NATIVE_PLAYER_NAMES = Object.freeze(['RedCat', 'WhizzKitty', 'Brutus', 'Max']);
export const NATIVE_MENU_OPPONENT_COUNTS = Object.freeze([4, 3, 3, 1]);

export function nativeAIProfile(config, aiId) {
  const ini = config['npc_ai.ini'], person = ini?.[`person_${aiId}`], global = ini?.rcr_global;
  if (!person || !global) throw new RangeError(`Missing original NPC profile ${aiId}`);
  const rate = key => {
    const level = Number(person[key]), value = Number(global[`${key}${level}`]);
    if (!Number.isInteger(level) || level < 1 || level > 5 || !Number.isFinite(value)) throw new RangeError(`Invalid native ${key} profile`);
    return value;
  };
  return {
    id: aiId, type: person.type, efficiency: rate('efficiency'), reaction: rate('reaction'),
    massSetting: rate('mass'), drivingStyle: Number(person.driving_style),
    // Raw level at profile +0x8 (0x40fe50); 0x40e000 reads it, not the rate.
    efficiencyLevel: Number(person.efficiency),
    bonusAwareness: Number(person.bonus_awareness), preferredBonus: person.pref_bonus,
    catchupMs: Number(global[`catchup${Number(person.driving_style)}`]),
    catchupDurationMs: Number(global[`catchup_dur${Number(person.driving_style)}`]),
  };
}

/** Menu0x46e9bc/0x46efa8: country guest, other core characters, player last. */
export function nativeRaceRoster(config, { selectedCharacter = 0, trackIndex = 0, opponentCount = 4 } = {}) {
  if (!Number.isInteger(selectedCharacter) || selectedCharacter < 0 || selectedCharacter > 3) throw new RangeError('Native player selection is 0..3');
  if (!Number.isInteger(trackIndex) || trackIndex < 0 || trackIndex > 5) throw new RangeError('Native country is 0..5');
  if (![0, 1, 2, 3, 4].includes(opponentCount)) throw new RangeError('Verified menu roster supports zero through four opponents');
  const data = config['game.ini'].available_characters;
  const available = Array.from({ length: Number(data.count) }, (_, i) => {
    const [name, mesh, ai, color] = data[i].split(',').map(value => value.trim());
    return { availableIndex: i, name, mesh, aiId: Number(ai), color: Number(color) };
  });
  const selected = available.find(character => character.name.toLowerCase() === NATIVE_PLAYER_NAMES[selectedCharacter].toLowerCase());
  if (!selected) throw new Error('Selected character is absent from original configuration');
  const opponents = [];
  if (opponentCount === 1 || opponentCount > 3) {
    const guest = available.find(character => character.mesh.toUpperCase() === NATIVE_COUNTRY_MESHES[trackIndex]);
    if (!guest) throw new Error('Country opponent is absent from original configuration');
    opponents.push(guest);
  }
  for (const character of available) {
    if (opponents.length >= opponentCount) break;
    if (NATIVE_PLAYER_NAMES.some(name => name.toLowerCase() === character.name.toLowerCase()) && character !== selected) opponents.push(character);
  }
  return {
    opponents: opponents.map((character, index) => ({
      ...character, index, racerRecord: character.aiId, carIndex: 1,
      profile: nativeAIProfile(config, character.aiId),
    })),
    player: { ...selected, aiId: -1, index: opponentCount,
      racerRecord: selected.availableIndex, carIndex: selected.availableIndex },
  };
}

/**
 * 0x493540 with direction 1, the value both placement callers pass to
 * 0x415f90 (player 0x431a46, NPC 0x417781); 0x415f90 calls it at 0x416184.
 * Same register/store pattern as nativePlayerStart: squares, sum and FSQRT in
 * ST0; X/len stored (0x4935e5); Z/len (FDIVR 0x4935e9) stays in ST0 for FPATAN;
 * FSUBP/FMUL stay in registers until FDIV and FSTP float (0x493686).
 */
export function nativeRaceHeading(world, sector, { precision = NATIVE_PRECISION } = {}) {
  if (precision !== 24 && precision !== 53) throw new RangeError('Native x87 precision must be 24 or 53');
  const r = precision === 24 ? f32 : Number;
  const forward = world.sectors[sector].forward;
  const length = r(Math.sqrt(r(r(forward[0] * forward[0]) + r(forward[2] * forward[2]))));
  const x = f32(forward[0] / length), z = r(forward[2] / length);
  return f32(r(r(Math.atan2(z, x) - f32(Math.PI) * .5) * NATIVE_ANGLE_COUNT) / f32(2 * Math.PI));
}

/** 0x415dd0/0x415f90/0x417640 with normal trigger numbering69+slot. */
export function nativeRaceGrid(track, world, {
  opponentCount = 4, previousFinishPosition = 0, startChunk = 0,
  british = 0, direction = 0, raceType = 0, precision = NATIVE_PRECISION,
} = {}) {
  if (!Number.isInteger(opponentCount) || opponentCount < 0 || opponentCount > 9) throw new RangeError('Native grid requires zero through nine opponents');
  if (precision !== 24 && precision !== 53) throw new RangeError('Native x87 precision must be 24 or 53');
  const wrap = value => value >= track.route.length ? value - track.route.length : value < 0 ? track.route.length - Math.abs(value) : value;
  const slots = Array.from({ length: opponentCount + 1 }, () => []);
  let found = 0;
  scan: for (let sector = 0; sector < track.route.length; sector++) {
    for (const waypoint of track.route[sector].driveIndices) {
      const node = track.drive[waypoint], slot = node.unknown[1] - 69;
      if (slot >= 0 && slot < slots.length) {
        slots[slot].push({ sector, waypoint, position: [...node.position] });
        if (++found === slots.length) break scan;
      }
    }
  }
  const player = nativePlayerStart(track, world, { opponentCount, previousFinishPosition, startChunk, british, direction, raceType, precision });
  const playerRank = [1, 3].includes(raceType) ? 0 : Math.min(previousFinishPosition, opponentCount);
  const ranks = Array.from({ length: opponentCount + 1 }, (_, i) => i).filter(i => i !== playerRank);
  const complete = slots.every(slot => slot.length === 1);
  let initialSector = startChunk, lane = 0;
  if (initialSector === 0) {
    const trigger = track.route.findIndex(route => route.trigger === 13 || route.unknown === 13);
    initialSector = trigger < 0 ? 0 : wrap(trigger - 1);
  }
  const side = (direction === 0 ? british === 1 : british !== 1) ? 0 : 1;
  const opponents = ranks.map((rank, index) => {
    const fallbackSector = wrap(initialSector - rank);
    const lanes = side === 0 ? track.route[fallbackSector].driveLeftIndices : track.route[fallbackSector].driveIndices;
    lane = Math.min(Math.max(0, lane + 1), lanes.length - 1); //0x493a70
    const waypoint = lanes[lane] ?? 0;
    const chosen = complete ? slots[index + 1][0] : { sector: fallbackSector, waypoint, position: [...track.drive[waypoint].position] };
    return { ...chosen, position: [...chosen.position], yaw: nativeRaceHeading(world, chosen.sector, { precision }), rank,
      source: complete ? `TRIGGER_POS_${70 + index}` : 'lane-fallback' };
  });
  // 0x42c680 stores the same clamped value in the live player rank 0x53be60.
  return { player: { ...player, rank: playerRank }, opponents };
}

/**
 * 0x403d90 starts at sector minus finish-marker sector;0x409530 adds signed
 * travel. The sector timer is one FADD/FSTP float (0x40968e/0x409694), so it is
 * precision-independent; distances are integers.
 */
export class NativeAIProgress {
  constructor(startSector, sectorCount, originSector = startSector) {
    this.previousSector = startSector; this.sectorCount = sectorCount;
    this.distance = startSector - originSector; this.sectorTime = 0;
  }
  update(sector, deltaSeconds) {
    if (sector === this.previousSector) this.sectorTime = f32(this.sectorTime + f32(deltaSeconds));
    else {
      this.distance += nativeSectorDistance(sector, this.previousSector, this.sectorCount);
      this.previousSector = sector; this.sectorTime = 0;
    }
    return this.distance;
  }
}

export function nativeRaceSetup(config, track, world, options = {}) {
  const roster = nativeRaceRoster(config, options),
    grid = nativeRaceGrid(track, world, {...nativeRaceRouteOptions(config),...options});
  const difficulty = options.difficulty ?? 1;
  if (![0, 1, 2].includes(difficulty)) throw new RangeError('Native difficulty is 0..2');
  const progressOriginSector = track.route.findIndex(route => route.trigger === 14 || route.unknown === 14);
  if (progressOriginSector < 0) throw new Error('Native racer progress requires the finish marker14');
  return {
    player: { ...roster.player, start: grid.player },
    opponents: roster.opponents.map((racer, i) => ({ ...racer, start: grid.opponents[i] })),
    racerTableFile: `assets/racer-tables/cars${difficulty}.dat`, difficulty,
    progressOriginSector,
  };
}
