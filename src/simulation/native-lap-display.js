const f=Math.fround;

/** CRcoStatistics lap-text hold: 0046e680, 0046f230 and 0046ecc0.
 * The native element retains its last rendered string, not a completed-lap
 * measurement. Supply the current timer-0 text and absolute engine seconds.
 * Paused/redraw-only frames do not call update; no race-time timeout is used.
 */
export class NativeLapDisplay {
  constructor({initialText='',precision=24}={}) {
    if(![24,53].includes(precision))throw new RangeError('Unsupported native precision');
    this.precision=precision;
    this.state={holdStampSeconds:-1,text:initialText};
  }
  notifyLap({lapCount,nowSeconds}) {
    if(lapCount>0)this.state.holdStampSeconds=Math.trunc(f(nowSeconds));
    return this.state.text;
  }
  update({lapText,nowSeconds}) {
    const state=this.state,r=this.precision===24?f:Number;
    if(state.holdStampSeconds===-1)state.text=lapText;
    else if(r(f(nowSeconds)-state.holdStampSeconds)>=3)state.holdStampSeconds=-1;
    // Native code leaves the element unchanged on the callback that clears
    // the stamp. The next callback enters the ordinary timer-format branch.
    return state.text;
  }
}
