import {nativeCharacterVoiceId} from './simulation/native-character-voice.js';

/**42f9c0's hardwired Space key branch, outside the developer-key guard.
 * It passes available character ID to the racer-index mapper, an original
 * mismatch retained here. CLAXON is absent but replacement still clears FIFO. */
export class NativeKeyAudio {
  constructor({racerCharacters, sampleNumber = 4, repetitions = 3}) {
    this.racerCharacters = racerCharacters;
    this.sampleNumber = sampleNumber;
    this.repetitions = repetitions;
  }

  step(spacePressed) {
    if (!spacePressed) return [];
    const selectedCharacter = this.racerCharacters.at(-1);
    const voiceId = nativeCharacterVoiceId(selectedCharacter, this.racerCharacters);
    const result = [
      {kind: 'voice', request: {voiceId, sample: 'CLAXON', replace: true}},
      {kind: 'direct', event: `KT${this.sampleNumber}`},
    ];
    this.repetitions--;
    if (this.repetitions === 0) {
      this.repetitions = 3;
      if (this.sampleNumber === 12) this.sampleNumber = 1;
    }
    return result;
  }
}
