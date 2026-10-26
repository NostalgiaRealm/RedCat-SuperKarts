const f=Math.fround;

/** Original normalized-screen Y motion, 00464e90 / 00464f30. */
export function nativeCountdownY(elapsed,{exiting=false,precision=24}={}){
  const round=precision===24?f:value=>value;
  const amount=round(f(elapsed)/f(1.2));
  return f(round(round(round(1-amount)*(exiting?f(.4):f(1.25)))
    +round(amount*(exiting?f(1.25):f(.4)))));
}

/**
 * Original 321 player: 00464a70, 00464ff0 and 00464fc0.
 * The overlay renderer consumes these original frame/slide/sound commands.
 * Countdown overshoot is discarded at each transition, not carried forward.
 */
export class NativeStartCountdown {
  constructor({precision=24}={}){
    if(![24,53].includes(precision))throw new RangeError('Unsupported native precision');
    this.precision=precision;this.phase=0;this.elapsed=0;this.soundIndex=0;this.events=[];
  }
  step(delta){
    if(!Number.isFinite(delta))throw new RangeError('Countdown requires a finite delta');
    this.elapsed=f(this.elapsed+f(delta));this.events=[];
    const phase=this.phase,duration=phase===0||phase===5?f(1.2):f(.8);
    if(phase===0)this.events.push({type:'slide-in',elapsed:this.elapsed});
    else if(phase>=1&&phase<=3)this.events.push({type:'frame',element:phase-1,frame:1});
    else if(phase===4)for(let element=0;element<3;element++)this.events.push({type:'frame',element,frame:2});
    else if(phase===5)this.events.push({type:'slide-out',elapsed:this.elapsed});
    if(phase>=0&&phase<=3){
      const threshold=this.precision===24?f(duration-f(.1)):duration-f(.1);
      if(this.elapsed>=threshold&&(phase===0?this.soundIndex===0:this.soundIndex<phase+1)){
        this.events.push({type:'sound',name:`STARTSE${phase+1}`});this.soundIndex=phase+1;
      }
    }
    if(phase>=0&&phase<=5&&this.elapsed>=duration){this.phase++;this.elapsed=0;}
    return this.snapshot();
  }
  snapshot(){
    return {phase:this.phase,elapsed:this.elapsed,soundIndex:this.soundIndex,
      green:this.phase>3,done:this.phase===6,events:this.events.map(event=>({...event}))};
  }
}
