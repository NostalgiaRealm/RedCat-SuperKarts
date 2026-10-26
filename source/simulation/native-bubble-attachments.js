const identity = () => [1,0,0,0,1,0,0,0,1];

/** Original 457780/457ab0/457b60 bubble-shell manager.
 * Racers are in CHARDATA order (NPCs, player). This is a separate render object,
 * not a child of the kart: step runs before the actor callbacks/integration.
 */
export class NativeBubbleAttachments {
  constructor(bodies) {
    if(!Array.isArray(bodies)||bodies.length<1||bodies.length>10)
      throw new RangeError('Original bubble manager supports one to ten racers');
    this.bodies=bodies;
    this.entries=Array.from({length:bodies.length},()=>null);
    this.allocationCursor=0;
  }
  racerIndex(index) {
    return index>=0&&index<this.bodies.length-1?index:this.bodies.length-1;
  }
  find(index) {
    const body=this.bodies[this.racerIndex(index)];
    return this.entries.findIndex(entry=>entry?.body===body);
  }
  attach(index) {
    if(this.find(index)!==-1)return true;
    const slot=this.entries.findIndex(entry=>entry===null);
    if(slot===-1)throw new Error('Original bubble manager has no free slot');
    const racer=this.racerIndex(index),body=this.bodies[racer];
    //48fc70 searches forward from its last allocation. A released last slot
    // can be reused; earlier holes wait until the engine allocation wraps.
    // The port uses a relative order within these dynamic shell allocations.
    while(this.entries.some(entry=>entry?.objectOrder===this.allocationCursor))
      this.allocationCursor++;
    const entry={body,racer,objectOrder:this.allocationCursor,visible:true,
      blendMode:2,angles:[0,0,0],matrix:identity()};
    this.copyPose(entry);
    this.entries[slot]=entry;
    return true;
  }
  detach(index) {
    const slot=this.find(index);
    if(slot===-1)return false;
    this.entries[slot]=null;
    return true;
  }
  copyPose(entry) {
    entry.position=entry.body.position.map(Math.fround);
    entry.sector=entry.body.sector;
    entry.waypoint=entry.body.waypoint;
    entry.angles=[0,0,0];
    entry.matrix=identity();
  }
  step() {
    for(const entry of this.entries)if(entry)this.copyPose(entry);
  }
}
