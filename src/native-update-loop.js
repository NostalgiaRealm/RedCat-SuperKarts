/** Browser scheduling for the native minimum-interval update gate.
 * Display refreshes never call this loop. A late wake runs one measured update,
 * then schedules from that update's actual start, without replaying a backlog.
 */
export class NativeUpdateLoop {
  constructor({clock,now=()=>performance.now(),schedule=(fn,delay)=>setTimeout(fn,delay),
    cancel=handle=>clearTimeout(handle),beforeUpdate}={}){
    this.clock=clock;this.now=now;this.schedule=schedule;this.cancel=cancel;
    this.beforeUpdate=beforeUpdate;this.running=false;this.handle=null;this.generation=0;
  }
  start(timestamp=this.now()){
    if(this.running&&!this.clock.paused)return this.clock.snapshot(timestamp);
    if(this.handle!==null)this.cancel(this.handle);
    this.handle=null;
    this.running=true;const generation=++this.generation;
    const state=this.clock.resume(timestamp);
    this.arm(generation);return state;
  }
  stop(timestamp=this.now()){
    this.running=false;this.generation++;
    if(this.handle!==null)this.cancel(this.handle);
    this.handle=null;return this.clock.pause(timestamp);
  }
  arm(generation){
    if(!this.running||generation!==this.generation)return;
    if(this.clock.paused){this.running=false;return;}
    const delay=Math.max(0,Math.ceil(this.clock.snapshot(this.now()).nextUpdateInMs));
    this.handle=this.schedule(()=>{
      if(!this.running||generation!==this.generation)return;
      this.handle=null;
      const timestamp=this.now();
      try{
        this.beforeUpdate?.(timestamp);
        // Input polling may pause the race or replace the viewer.
        if(!this.running||generation!==this.generation)return;
        this.clock.advance(timestamp);
      }catch(error){this.stop(this.now());throw error;}
      // Update work counts toward the next 25 ms minimum, like 4432a0.
      this.arm(generation);
    },delay);
  }
}
