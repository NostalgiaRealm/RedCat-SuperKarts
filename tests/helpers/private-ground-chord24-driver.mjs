import {RouteTestDriver as Base} from './private-timed-lane-driver.mjs';
import {NativeRailCollision} from '../../src/simulation/native-collision.js';
import {createNativeTrack,sampleNativeTrack} from '../../src/simulation/native-track.js';
const distance=(a,b)=>Math.hypot(a[0]-b[0],a[2]-b[2]);
const clamp=(x,a,b)=>Math.max(a,Math.min(b,x));

// Private ground-cut test driver: accepts original road/land/extra support.
// Test driver only. Every hypothetical sweep uses a separate query collider;
// the actual race still performs all collisions and terrain/rescue rules.
export class RouteTestDriver extends Base {
  constructor(track,options){super(track,options);this.queryBounds=options.railBounds;}
  configureRacingLine(turnPenalty){
    const track=this.track,n=track.route.length,points=track.drive.map(d=>d.position);
    const sets=track.route.map(r=>[...new Set([...r.driveIndices,...r.driveLeftIndices])]);
    const world=createNativeTrack(track),query=new NativeRailCollision(track,this.queryBounds);
    const edges=Array.from({length:n},()=>new Map());
    for(let s=0;s<n;s++)for(const a of sets[s]){
      const next=[];edges[s].set(a,next);
      for(let span=1;span<=24;span++)for(const b of sets[(s+span)%n]){
        const p=points[a],q=points[b],dx=q[0]-p[0],dz=q[2]-p[2],length=Math.hypot(dx,dz);
        if(length<1)continue;
        query.candidates=()=>query.rails.filter((rail,k)=>{
          const r=track.collision[k].position,d=track.collision[k].delta;
          return Math.max(r[0],r[0]+d[0])>=Math.min(p[0],q[0])-80
            &&Math.min(r[0],r[0]+d[0])<=Math.max(p[0],q[0])+80
            &&Math.max(r[2],r[2]+d[2])>=Math.min(p[2],q[2])-80
            &&Math.min(r[2],r[2]+d[2])<=Math.max(p[2],q[2])+80;
        });
        const body={position:p,x:p[0],y:p[1]+8,z:p[2],yaw:Math.atan2(-dx,dz)*2048/Math.PI,
          sector:s,forwardSpeed:length/10,lateralSpeed:0,verticalSpeed:0,yawRate:0};
        const originalAdjacent=span===1&&this.links[a].includes(b);
        if(!originalAdjacent&&query.sweep(body,1).fraction<1)continue;
        let safe=true;
        for(let step=1,count=Math.ceil(length/50);step<count;step++){
          const t=step/count;
          if(sampleNativeTrack(world,s,p[0]+dx*t,p[1]+(q[1]-p[1])*t,p[2]+dz*t).kind==='fallback'){safe=false;break;}
        }
        if(!safe&&!originalAdjacent)continue;
        let penalty=0;
        for(const k of [s,(s+span)%n]){
          const r=track.route[k].position,z=track.route[(k+1)%n].position,ux=z[0]-r[0],uz=z[2]-r[2];
          penalty+=1-clamp((ux*dx+uz*dz)/(Math.hypot(ux,uz)*length),-1,1);
        }
        next.push({node:b,span,cost:length+turnPenalty*penalty});
      }
    }
    let best=null;
    for(const start of sets[0]){
      const states=Array.from({length:n+1},()=>new Map());
      states[0].set(start,{cost:0,path:[{sector:0,node:start}]});
      for(let s=0;s<n;s++)for(const [a,state] of states[s])
        for(const edge of edges[s].get(a)??[]){
          const end=s+edge.span;if(end>n||(end===n&&edge.node!==start))continue;
          const cost=state.cost+edge.cost,prev=states[end].get(edge.node);
          if(!prev||cost<prev.cost)states[end].set(edge.node,{cost,path:[...state.path,{sector:end,node:edge.node}]});
        }
      const last=states[n].get(start);
      if(last&&(!best||last.cost<best.cost))best=last;
    }
    if(!best)throw new Error('No closed collision-clear road chord path');
    this.racingLine=best.path;this.racingLineCost=best.cost;
  }
  input(body,now,dt,options){
    const input=super.input(body,now,dt,options);
    if(this.telemetry.reversing)return input;
    const track=this.track,n=track.route.length,points=this.racingLine;
    let best=null;
    for(let i=0;i+1<points.length;i++){
      const s=points[i].sector,e=points[i+1].sector;
      if(![body.sector,body.sector+n].some(k=>k>=s-1&&k<=e+1))continue;
      const a=track.drive[points[i].node].position,b=track.drive[points[i+1].node].position;
      const dx=b[0]-a[0],dz=b[2]-a[2],fraction=clamp(((body.x-a[0])*dx+(body.z-a[2])*dz)/(dx*dx+dz*dz),0,1);
      const d=distance(body.position,[a[0]+fraction*dx,0,a[2]+fraction*dz]);
      if(!best||d<best.d)best={i,fraction,d};
    }
    if(!best)return input;
    let remaining=50+Math.abs(body.forwardSpeed)*10*this.lookAheadSeconds,target;
    for(let k=0;k<points.length;k++){
      const i=(best.i+k)%(points.length-1),a=track.drive[points[i].node].position,b=track.drive[points[i+1].node].position;
      const fraction=k?0:best.fraction,length=distance(a,b),available=length*(1-fraction);
      if(remaining<=available){const t=fraction+remaining/length;target=[a[0]+t*(b[0]-a[0]),0,a[2]+t*(b[2]-a[2])];break;}
      remaining-=available;
    }
    if(!target)return input;
    const desired=Math.atan2(-(target[0]-body.x),target[2]-body.z);
    const error=Math.atan2(Math.sin(desired-body.yaw*Math.PI/2048),Math.cos(desired-body.yaw*Math.PI/2048));
    const speed=this.speed/(1+2*Math.abs(error));
    const throttle=clamp((speed-body.forwardSpeed)*.2,0,1),brake=body.forwardSpeed>speed+2?clamp((body.forwardSpeed-speed)*.1,0,1):0;
    const steer=clamp(-error*this.steeringGain+body.yawRate*this.dampingGain,-1,1);
    this.telemetry={...this.telemetry,target,headingError:error,targetSpeed:speed};
    return {...input,throttle,brake,steer,analog:{throttle,brake,steer}};
  }
}
