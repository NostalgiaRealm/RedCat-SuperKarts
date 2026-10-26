/** Map emitted gameplay events to the original 00430610 HUD dispatcher.
 * Native IDs 0/8/9 address non-text controllers; preserve explicit IDs so the
 * downstream dispatcher can keep handling those separately. No new notice is
 * inferred from a pickup, rank change, finish or timed-gate sound.
 */
export function getNativeGameplayHudNotificationId(event, {playerIndex} = {}) {
  if (!event || typeof event !== 'object') return undefined;
  if (event.type === 'native-notification') {
    return Number.isInteger(event.id) && event.id >= 0 && event.id <= 11
      ? event.id : undefined;
  }
  // 00440c30: final-lap notice first, then a new best-lap notice.
  if (event.type === 'last-lap') return 5;
  if (event.type === 'lap-record') return 6;
  // 00420730 emits ID7 only for game-over mode1 (time expiry).
  if (event.type === 'time-expired') return 7;
  // 00455b00: an NPC victim and a player shooter. This follows the NPC hit
  // callback even if state9 caused that callback to reject the effect.
  if (event.type === 'hit' && Number.isInteger(playerIndex) && playerIndex > 0
      && event.shooter === playerIndex && Number.isInteger(event.racer)
      && event.racer >= 0 && event.racer < playerIndex) return 4;
  // 00441e70 (markers74..76) updates timer18 and plays CHECKPOINT only.
  // Text ID11 instead belongs to 004425f0's distinct Time_Check marker45.
  return undefined;
}
