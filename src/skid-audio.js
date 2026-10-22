/** 00432190: the original player tyre loop. The caller 0042f230 runs this
 * after particle and voice updates, before rendering, through 00432240.
 * Disabled global sound returns without stopping an already playing voice. */
export function getNativeSkidAudioCommands({
  slipMagnitude, playerContact, playing = false, soundEnabled = true, controllerEnabled = true,
}) {
  if (!soundEnabled) return [];
  if (!playerContact || slipMagnitude < 4) return playing ? [{event: 'SLIP', op: 'stop'}] : [];
  const pitch = {event: 'SLIP', op: 'pitch', percent: slipMagnitude * 4 - 16};
  if (playing) return [pitch];
  return controllerEnabled ? [{event: 'SLIP', op: 'play', loop: true}, pitch] : [];
}
