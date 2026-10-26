/**
 * Sampler portion of HUD entry 462320 and exit 462610.
 *
 * The device filter cache (6a6274) is separate from its actual min/mag
 * states. HUD exit restores the states but leaves the cache changed.
 * Both entry GetRenderState calls request MIN, including the saved MAG.
 *
 * Call capture once per logical native render, for the entire overlay.
 * Reuse current while drawing additional browser frames or HUD layers.
 * The original constructors leave HUD byte+88 uninitialized. Zero is an
 * explicit host policy; both zero/nonzero have the same visible sequence
 * for active FILTER=0/2 startup states.
 */
export class NativeHudSamplerState {
  constructor({filter=2,hudFilterByte=0,cached,min,mag}={}) {
    const linear=Number(filter)===2;
    this.cached=cached??(linear?2:0);
    this.min=min??(linear?2:1);
    this.mag=mag??(linear?2:1);
    this.hudFilterByte=hudFilterByte;
    this.saved=null;
    this.frames=0;
    this.current=this.snapshot();
  }
  snapshot() {
    return {min:this.min,mag:this.mag,cached:this.cached};
  }
  enter() {
    if(this.saved!==null)throw new Error('Native HUD sampler entry is already active');
    // 462337 and 462349 both query D3DRENDERSTATE_TEXTUREMIN (17).
    this.saved={min:this.min,mag:this.min};
    const requested=this.hudFilterByte?2:1;
    if(this.cached!==requested) {
      this.cached=requested;
      this.min=this.mag=2;
    }
    return this.snapshot();
  }
  leave() {
    if(this.saved===null)throw new Error('Native HUD sampler exit has no matching entry');
    this.min=this.saved.min;
    this.mag=this.saved.mag;
    this.saved=null;
    return this.snapshot();
  }
  capture() {
    this.current=this.enter();
    this.leave();
    this.frames++;
    return this.current;
  }
}
