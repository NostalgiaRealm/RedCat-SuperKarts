/** "FPS weergeven": drawn frames per second over one-second windows, after a
 * short warm-up. Pauses and stalls longer than a second restart the sample. */
export class FpsCounter {
  constructor(){this.reset();}
  reset(){this.previous=null;this.elapsed=0;this.frames=0;this.warmup=2;this.fps=null;}
  frame(time){
    const dt=this.previous===null?0:(time-this.previous)/1000;
    this.previous=time;
    if(dt<=0)return;
    if(dt>1){this.elapsed=this.frames=0;this.warmup=2;this.fps=null;return;}
    if(this.warmup>0){this.warmup-=dt;return;}
    this.elapsed+=dt;this.frames++;
    if(this.elapsed<1)return;
    this.fps=this.frames/this.elapsed;this.elapsed=this.frames=0;
  }
  get label(){return this.fps===null?'FPS: …':`${Math.round(this.fps)} FPS`;}
}
