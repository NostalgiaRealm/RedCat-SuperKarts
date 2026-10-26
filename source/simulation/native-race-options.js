/** Race.INI switches as loaded at 0x42b870, before player construction. */
export function nativeRacePlayerOptions(config) {
  const player = config['race.ini']?.player;
  if (!player) throw new TypeError('Original Race.INI PLAYER section required');
  // The shipped menu preserves these keys. The force table indexes require
  // 0/1; normalize the original integer switch semantics at the API boundary.
  const flag = key => Number.parseInt(player[key] ?? '0', 10) ? 1 : 0;
  return {
    motorUpgrade: flag('motor'),
    tireUpgrade: flag('banden'),
    gearboxUpgrade: flag('versnellingsbak'),
  };
}

/** 0x431ecd..0x431eeb clears all six loaded upgrade globals during player
 * construction. These three affect the active force/steering/timer paths.
 * The other cleared globals are legacy turbo/ABS/injection switches, not
 * the separately acquired race bonus. Preserve the raw INI loader result.
 */
export function initializeNativeRacePlayerOptions(loadedOptions) {
  return {...loadedOptions,motorUpgrade:0,tireUpgrade:0,gearboxUpgrade:0};
}

/** 0x42af70/0x42c170 load independent Race.INI ETAPPE integer settings.
 * GetPrivateProfileInt's missing-key default is zero. Track map field14
 * controls rendering/steering mirroring and is not the British lane flag.
 */
export function nativeRaceRouteOptions(config) {
  const stage=config['race.ini']?.etappe??{};
  const integer=key=>(Number.parseInt(stage[key]??'0',10)||0)|0;
  return {british:integer('british'),direction:integer('direction')};
}

/** rcskmenu table0x47bd10, selected by profile save0x45a5dc. */
export function nativeMenuOpponentCount(raceType) {
  if (![0, 1, 2, 3].includes(raceType)) throw new RangeError('Shipped menu race type must be 0..3');
  return [4, 3, 3, 1][raceType];
}
