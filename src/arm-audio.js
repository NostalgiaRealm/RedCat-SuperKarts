const f = Math.fround;

/**486ea0 sound branch4873f8..4876fb. Caller supplies its actual squared
 * distance ratio. At most one beep is queued per callback, without RNG. */
export function advanceNativeArmAudio({timer, deltaSeconds, ratio, player = true, precision = 24}) {
  if (!player) return {timer: f(timer), sample: null};
  const r = precision === 24 ? f : Number;
  const accumulated = r(f(deltaSeconds) + f(timer));
  if (accumulated <= f(.1)) return {timer: f(accumulated), sample: null};
  return {
    timer: f(r(accumulated - f(.1))),
    sample: f(ratio) > f(.7) ? 'ARMBEEP3' : f(ratio) > f(.4) ? 'ARMBEEP2' : 'ARMBEEP1',
  };
}
