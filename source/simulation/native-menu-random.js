/** Delphi menu Random(upper), 0x402b74; separate from the game's CRT stream. */
export class NativeMenuRandom {
  constructor(seed = 0) { this.seed = seed >>> 0; }
  next(upper) {
    this.seed = (Math.imul(this.seed, 0x08088405) + 1) >>> 0;
    return Number((BigInt(upper >>> 0) * BigInt(this.seed)) >> 32n);
  }
}

/** 0x40293c, called when constructing TfrmDebrief: UTC milliseconds of day. */
export function nativeMenuRandomSeed(date) {
  return ((date.getUTCHours() * 60 + date.getUTCMinutes()) * 60 + date.getUTCSeconds()) * 1000 + date.getUTCMilliseconds();
}

/** 0x473204/0x473298 and byte tables 0x47c4f4/0x47c4fc. */
export function nativeAdventureOutcomeVoice(qualified, raceType, random) {
  if (!Number.isInteger(raceType) || raceType < 0 || raceType > 3) throw new RangeError('No shipped outcome-voice pair for this race type');
  return (qualified ? 55 : 47) + raceType * 2 + random.next(2);
}

/** 0x4731c8: result-screen greeting, before any qualification dialog. */
export function nativeDebriefRankVoice(rank, random) {
  if (!Number.isInteger(rank) || rank < 0 || rank > 4) throw new RangeError('Native result rank is outside the five greeting pairs');
  return 37 + rank * 2 + random.next(2);
}
