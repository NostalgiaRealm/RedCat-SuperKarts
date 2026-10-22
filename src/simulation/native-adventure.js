/** Original menu country/type enums and the rank table at 0x47bd24. */
export const NATIVE_ADVENTURE_COUNTRIES = Object.freeze(['nederland', 'duitsland', 'engeland', 'frankrijk', 'spanje', 'italie']);
export const NATIVE_ADVENTURE_TYPES = Object.freeze(['normalrace', 'timetrial', 'itemrace', 'duelrace', 'bonusrace']);
export const NATIVE_ADVENTURE_MAX_RANK = Object.freeze([4, 2, 0]);

/** 0x4582a0/0x457e84 load these original shellimg.dat sections. */
export function nativeAdventureConfiguration(config) {
  const ini = config['ini/shellimg.dat'];
  const sequence = [];
  for (let index = 0; index < 30; index++) {
    const value = ini.advsequence[index];
    if (!value) continue;
    const [country, raceType] = value.toLowerCase().split(',').map(part => part.trim());
    const entry = { index, country: NATIVE_ADVENTURE_COUNTRIES.indexOf(country), raceType: NATIVE_ADVENTURE_TYPES.indexOf(raceType) };
    if (entry.country < 0 || entry.raceType < 0) throw new RangeError(`Unknown original adventure entry ${value}`);
    sequence.push(entry);
  }
  return {
    sequence,
    locks: NATIVE_ADVENTURE_COUNTRIES.map((_, index) => Boolean(Number(ini.lockedstate[index] ?? 0))),
    requiredTypes: NATIVE_ADVENTURE_TYPES.map(type => Boolean(Number(ini.requiredtypes[type] ?? 0))),
    unlockCountries: NATIVE_ADVENTURE_TYPES.map(type => NATIVE_ADVENTURE_COUNTRIES.indexOf(ini.locks[type]?.toLowerCase())),
  };
}

/** 0x45aa5c resets the reusable profile; its raceType and slot are not cleared. */
export function resetNativeAdventureProfile(profile) {
  Object.assign(profile, {
    name: '', difficulty: 1, adventure: 0, character: 0, carType: 0, country: 0,
    completed: false, matrix: Array.from({ length: 6 }, () => Array(5).fill(0)),
  });
  return profile;
}

/** New-slot path 0x4760c0: reset first, then assign the accepted name. */
export function createNativeAdventureProfile(name, { slot = -1, raceType = 0 } = {}) {
  const profile = resetNativeAdventureProfile({ slot, raceType });
  profile.name = name;
  return profile;
}

/** 0x45a184: replaying a completed profile keeps identity and difficulty. */
export function restartNativeAdventureProfile(profile) {
  profile.matrix = Array.from({ length: 6 }, () => Array(5).fill(0));
  profile.adventure = 0;
  profile.completed = false;
  return profile;
}

/** 0x470c4c/0x471290 read WINMOVIES/STARMOVIES from settings.ini. */
export function nativeAdventureReward(config, kind, index) {
  const keys = kind === 'star' ? NATIVE_ADVENTURE_COUNTRIES
    : kind === 'win' ? ['redcat', 'whizzkitty', 'brutus', 'max'] : null;
  if (!keys?.[index]) throw new RangeError('Unknown native adventure reward');
  const source = config['ini/settings.ini'][kind === 'star' ? 'starmovies' : 'winmovies'][keys[index]];
  // The native code searches the uppercase filename for BMP, not its suffix.
  const image = source.toUpperCase().includes('BMP');
  return { source, image, durationMs: image ? 9000 : null, skippable: false,
    form: kind === 'star' ? 'TFRMSTARANIM' : 'TFRMADVENTWIN' };
}

/** 0x458468, including the 30-entry ceiling and completion sentinel999. */
export function nativeNextAdventureIndex(currentIndex, entryCount) {
  const next = (currentIndex + 1) | 0;
  return next < 30 && next < entryCount ? next : 999;
}

/** 0x4734b4 predicates after 0x472cfc checks the difficulty's rank threshold. */
export function nativeAdventureQualification({ difficulty, raceType }, { rank, finished, stars }) {
  const maximum = NATIVE_ADVENTURE_MAX_RANK[difficulty];
  if (maximum === undefined) throw new RangeError('Native difficulty must be 0, 1 or 2');
  if (rank < 0 || rank > maximum) return { qualified: false, reason: 'rank', maximumRank: maximum };
  if (raceType === 1 && !finished) return { qualified: false, reason: 'time', maximumRank: maximum };
  // 0x4733e5 uses SETZ; collecting more than twelve does not pass this check.
  if (raceType === 2 && stars !== 12) return { qualified: false, reason: 'stars', maximumRank: maximum };
  if (raceType === 3 && rank !== 0) return { qualified: false, reason: 'duel', maximumRank: maximum };
  return { qualified: true, reason: null, maximumRank: maximum };
}

/** 0x45a9f4: all six country rows, or an unrequired race type. */
export function nativeAdventureTypeComplete(profile, raceType, requiredTypes) {
  return !requiredTypes[raceType] || profile.matrix.every(row => Boolean(row[raceType]));
}

/**
 * 0x472cfc followed by 0x472fe0. Mutates profile and shared country locks.
 * The country/type still refer to the completed race until the next briefing.
 * Unlock checking also happens when qualification failed, matching native order.
 */
export function applyNativeAdventureResult(profile, result, {
  sequence, locks, requiredTypes, unlockCountries,
}) {
  const qualification = nativeAdventureQualification(profile, result);
  let campaignCompleted = false;
  if (qualification.qualified) {
    profile.matrix[profile.country][profile.raceType] = 1;
    const next = nativeNextAdventureIndex(profile.adventure, sequence.length);
    if (next === 999) {
      profile.adventure = 0;
      profile.completed = true;
      campaignCompleted = true;
    } else profile.adventure = next;
  }
  let unlockedCountry = null;
  if (nativeAdventureTypeComplete(profile, profile.raceType, requiredTypes)) {
    unlockedCountry = unlockCountries[profile.raceType];
    if (!Number.isInteger(unlockedCountry) || unlockedCountry < 0) throw new RangeError('Missing original country unlock');
    locks[unlockedCountry] = false;
  }
  return { ...qualification, advanced: qualification.qualified, campaignCompleted, unlockedCountry };
}

/** 0x45a5dc / 0x454818: native save profile sections, without unrelated settings. */
export function nativeAdventureProfilePatch(profile) {
  return {
    playerdata: {
      name: profile.name, character: profile.character, adventure: profile.adventure,
      cartype: profile.carType, racetype: profile.raceType, country: profile.country,
      completed: Number(Boolean(profile.completed)), difficulty: profile.difficulty,
    },
    advmatrix: Object.fromEntries(NATIVE_ADVENTURE_COUNTRIES.map((country, index) => [
      country, profile.matrix[index].map(value => value & 0x7f).join(','),
    ])),
  };
}

/** 0x4783b8 reads the event; 0x4786ec applies its country/type on race start. */
export function nativeAdventureBriefing(profile, { sequence }) {
  const event = sequence.find(entry => entry.index === profile.adventure);
  if (!event) throw new RangeError('The native adventure index has no configured event');
  return { ...event, difficulty: profile.difficulty };
}

export function beginNativeAdventureEvent(profile, configuration) {
  const event = nativeAdventureBriefing(profile, configuration);
  profile.country = event.country;
  profile.raceType = event.raceType;
  return event;
}

/** 0x457c50/0x457c88/0x457cac: thirty save slots, without wrapping. */
export function nativeAdventureSaveSlot(occupied, action, current = -1) {
  if (occupied.length !== 30) throw new RangeError('The native menu has thirty save slots');
  if (action === 'new') return occupied.findIndex(value => !value);
  if (action === 'next') {
    for (let i = current + 1; i < 30; i++) if (occupied[i] === true || occupied[i] === 1) return i;
    return -1;
  }
  if (action === 'previous') {
    for (let i = current - 1; i >= 0; i--) if (occupied[i] === true || occupied[i] === 1) return i;
    return -1;
  }
  throw new RangeError('Unknown native save-slot operation');
}

/** 0x457c6c reads byte31 as well; callers must supply it if all slots are empty. */
export function nativeFirstAdventureSaveSlot(occupied, trailingByte) {
  const first = occupied.findIndex(value => value === true || value === 1);
  if (first >= 0) return first;
  if (trailingByte === undefined) throw new TypeError('Native empty-bank lookup reads a trailing byte');
  return trailingByte === 1 ? 30 : -1;
}

/** Source0x457a30 uses players\\player{slot}.dat. */
export function nativeAdventureSavePath(slot) {
  if (!Number.isInteger(slot) || slot < 0 || slot >= 30) throw new RangeError('Invalid native save slot');
  return `players/player${slot}.dat`;
}

/** 0x45a3c8 +0x454968. Missing fields default zero, including difficulty. */
export function readNativeAdventureProfile(ini, { slot = -1 } = {}) {
  const data = ini.playerdata ?? {}, matrix = ini.advmatrix ?? {};
  const byte = key => Number(data[key] ?? 0) & 255;
  return {
    slot, name: data.name ?? '', character: byte('character'),
    adventure: Number(data.adventure ?? 0) | 0, carType: byte('cartype'),
    raceType: byte('racetype'), country: byte('country'), completed: Boolean(byte('completed')),
    difficulty: byte('difficulty'),
    matrix: NATIVE_ADVENTURE_COUNTRIES.map(country => {
      const values = (matrix[country] ?? '').split(',');
      return Array.from({ length: 5 }, (_, i) => Number(values[i] ?? 0) & 255);
    }),
  };
}
