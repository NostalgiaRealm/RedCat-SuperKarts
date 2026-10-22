import { NativeRandom } from './native-random.js';

/** Original 0x437ff0..0x438670 selectors. COMM ranges retain native names. */
export const NATIVE_VOICE_SELECTORS = Object.freeze({
  HIT: { address: 0x437ff0, prefix: 'HIT', count: 6, offset: 0 },
  AMHIT: { address: 0x438090, prefix: 'AMHIT', count: 4, offset: 0 },
  PASSING: { address: 0x438130, prefix: 'PASSING', count: 2, offset: 0 },
  PASSED: { address: 0x4381d0, prefix: 'PASSED', count: 2, offset: 0 },
  BONUS: { address: 0x438270, prefix: 'BONUS', count: 7, offset: 0 },
  TURBO: { address: 0x438310, prefix: 'TURBO', count: 2, offset: 0 },
  COMM0_3: { address: 0x438480, prefix: 'COMM', count: 4, offset: 0 },
  COMM4_6: { address: 0x438520, prefix: 'COMM', count: 3, offset: 4 },
  COMM7_8: { address: 0x4385c0, prefix: 'COMM', count: 2, offset: 7 },
  COMM9_20: { address: 0x438670, prefix: 'COMM', count: 12, offset: 9 },
});

export function selectNativeVoiceSample(kind, random) {
  const selector = NATIVE_VOICE_SELECTORS[kind];
  if (!selector) throw new RangeError(`Unknown native voice selector: ${kind}`);
  return selector.prefix + (random.next() % selector.count + selector.offset);
}

/** 0x437ea0: every racer outside [0,NPCcount) resolves to the player. */
export function nativeCharacterVoiceId(racer, racerAvailableIndices) {
  const count = racerAvailableIndices.length - 1;
  const available = racerAvailableIndices[racer >= 0 && racer < count ? racer : count];
  if (!Number.isInteger(available) || available < 0 || available > 9)
    throw new RangeError('Unknown original character voice');
  return available;
}

/**
 * Logical requests only. Invoke these at the native gameplay callback point:
 * sample/chance draws use the shared CRT stream even when audio is disabled.
 * Queue admission, replacement/stop and playback belong to CVoiceController.
 */
export class NativeCharacterVoices {
  constructor({ random, racerAvailableIndices }) {
    if (!(random instanceof NativeRandom)) throw new TypeError('Shared native RNG required');
    if (!racerAvailableIndices.length) throw new RangeError('Player voice is required');
    this.random = random;
    this.racerAvailableIndices = [...racerAvailableIndices];
    this.player = racerAvailableIndices.length - 1;
    this.commands = [];
  }

  voiceId(racer) { return nativeCharacterVoiceId(racer, this.racerAvailableIndices); }
  isPlayer(racer) { return racer < 0 || racer >= this.player; }
  submit(voiceId, sample, replace = false) {
    const command = { voiceId, sample, replace };
    this.commands.push(command);
    this.onRequest?.(command);
    return command;
  }
  drain() { return this.commands.splice(0); }
  chance() { return this.random.next() % 3 === 0; } // 0x438710/0x438730

  /** 0x4387a0 (and player wrapper0x438760): sample already selected. */
  replaceRacer(racer, sample) {
    if (!this.chance()) return false;
    this.submit(this.voiceId(racer), sample, true);
    return true;
  }
  replacePlayer(sample) { return this.replaceRacer(this.player, sample); }
  selected(kind, racer) {
    return this.replaceRacer(racer, selectNativeVoiceSample(kind, this.random));
  }

  /** 0x4387e0: first chance chooses the speaker, second chance may drop PASSED. */
  passing(behind, ahead) {
    if (this.chance()) {
      this.submit(this.voiceId(ahead), selectNativeVoiceSample('PASSING', this.random));
    } else {
      this.selected('PASSED', behind);
    }
  }

  /** Voice portion of 0x40d9c0. The AI driver owns its state28 transition. */
  npcCatchup({ racer, mode, activated, sector, playerSector, sectorCount }) {
    if (mode === 9 || !activated) return;
    let difference = Math.abs(playerSector - sector);
    if (difference > Math.trunc(sectorCount / 2)) difference = sectorCount - difference;
    if (Math.abs(difference) >= 2) return;
    if (this.chance()) {
      const voiceId = this.voiceId(racer);
      this.submit(voiceId, selectNativeVoiceSample('PASSING', this.random));
      this.submit(voiceId, 'CLAXON');
    } else {
      this.selected('PASSED', this.player);
    }
  }

  /** 0x4106b0, before random pickup type/level decisions in0x4514e0. */
  pickupBefore(racer) { this.selected('BONUS', racer); }
  /** 0x4540c0, after the player's GOT_* effects request: a second voice draw. */
  pickupAfter(racer) { if (this.isPlayer(racer)) this.selected('BONUS', this.player); }
  /** 0x4537f0: NPC turbo does not request this character line. */
  turbo(racer) { if (this.isPlayer(racer)) this.selected('TURBO', this.player); }

  /** 0x40d260, called before NPC effect initialization. Literal -1 is required. */
  npcHit(racer, shooter) { if (shooter === -1) this.selected('AMHIT', racer); }
  /** 0x435aa0, after player effect initialization and its random draw. */
  playerHit() { this.selected('AMHIT', this.player); }
  /** 0x437c40→0x438760, even when the NPC victim ignored the attack. */
  playerHitOther() { this.selected('HIT', this.player); }
  /** 0x40de60: successful NPC attacker, unless its mode is9. */
  npcHitPlayer(racer, mode) { if (mode !== 9) this.selected('HIT', racer); }

  /** 0x430610 event5/6; symbolic COMM names belong to effects voice10. */
  gameEvent(event) {
    const selector = event === 5 ? 'COMM4_6' : event === 6 ? 'COMM0_3' : null;
    if (selector) this.submit(10, selectNativeVoiceSample(selector, this.random));
  }
  /** 0x48ca60 at pre-update rescue frame3: fixed actor FIFO, no random draw. */
  rescue(racer, sample) {
    if (sample !== 'DISAPP' && sample !== 'REAPP') throw new RangeError('Unknown rescue sound');
    return this.submit(this.voiceId(racer), sample);
  }
  /** 0x440a90 marker53. Caller must apply its native trigger guard. */
  zipper() {
    this.submit(10, 'FIRE_TURBO');
    this.selected('TURBO', this.player);
  }
}

/** Player-only effects queue in 0x411830/0x411b40/0x411e50/0x412090.
 * Missing names stay missing; the audio bank decides whether they are admitted. */
export function nativePlayerHitSoundRequests(type, level, player = true) {
  if (!player) return [];
  const hit = [null, 'HIT_BY_ROCKET', 'HIT_BY_SOAP', 'HIT_BY_OIL', 'HIT_BY_GUM'][type];
  if (!hit) throw new RangeError('Unknown original hit effect');
  const result = [{ voiceId: 10, sample: hit, replace: true }];
  const tail = [null, 'IMR', 'SOAP_UP', 'IMO', null][type];
  if (tail) result.push({ voiceId: 10, sample: tail + level, replace: false });
  return result;
}
