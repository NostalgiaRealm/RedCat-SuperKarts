// Copied unchanged from the JavaScript reconstruction: ../RedCat Superkarts/source/frame-limit.js at commit 5bfe0b62 (1.0.3).
// Change it there first and copy it again; the recomp's menu keeps the JS port's code as it is.
/** Host adaptation for phones and tablets: a 90 or 120 Hz display gets at most
 * about 60 drawn frames per second, which keeps the phone cooler. Updates and
 * input are not limited, and displays at 60 Hz or below never skip a frame. */
export class FrameLimiter {
  constructor(intervalMs=1000/60,toleranceMs=2){
    this.intervalMs=intervalMs;this.toleranceMs=toleranceMs;this.next=-Infinity;
  }
  due(time){
    if(time<this.next-this.toleranceMs)return false;
    this.next+=this.intervalMs;
    if(this.next<=time)this.next=time+this.intervalMs;
    return true;
  }
}
