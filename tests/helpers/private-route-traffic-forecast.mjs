// Test-driver prediction, not an alternate native NPC implementation.
// Routes and every future pose are private copies; no AI decisions/RNG run here.
import {selectNativeSector} from '../../src/simulation/native-track.js';
const clamp=(v,a,b)=>Math.max(a,Math.min(b,v));
const wrap=v=>Math.atan2(Math.sin(v),Math.cos(v));

export function copiedNPCPath(track,actor) {
  const body=actor.body,nearest=body.waypoint;
  if(!Number.isInteger(nearest)||!track.drive[nearest]||body.forwardSpeed<0)return null;
  const nodes=[],back=track.drive[nearest].links[3];
  if(back>=0&&track.drive[back])nodes.push(back);
  nodes.push(nearest);
  const priorities=actor.state?.priorities??[0,1,2];
  let current=nearest;
  for(let step=0;step<32;step++){
    const links=track.drive[current].links.slice(0,3).filter(i=>i>=0&&track.drive[i]);
    if(!links.length)break;
    const selected=step===0&&links.includes(actor.state?.waypoint)?actor.state.waypoint:null;
    const lane=track.drive[current].unknown?.[0];
    const sameLane=links.find(i=>track.drive[i].unknown?.[0]===lane);
    const next=selected??sameLane??priorities.map(i=>track.drive[current].links[i]).find(i=>links.includes(i))??links[0];
    if(next===current)break;
    nodes.push(next);current=next;
  }
  if(nodes.length<2)return null;
  const points=nodes.map(i=>[...track.drive[i].position]);
  let best=null,offset=0;
  // NearestNativeAIWaypoint can be ahead of or behind the body, so project
  // onto its incoming and outgoing segment rather than treating it as a pose.
  for(let i=0;i<Math.min(2,points.length-1);i++){
    const a=points[i],b=points[i+1],dx=b[0]-a[0],dz=b[2]-a[2],length=Math.hypot(dx,dz);
    if(length===0)continue;
    const fraction=clamp(((body.x-a[0])*dx+(body.z-a[2])*dz)/(length*length),0,1);
    const x=a[0]+fraction*dx,z=a[2]+fraction*dz;
    const error=(body.x-x)**2+(body.z-z)**2;
    if(!best||error<best.error)best={error,progress:offset+fraction*length,
      tx:dx/length,tz:dz/length,x,z,
      height:a[1]+fraction*(b[1]-a[1])};
    offset+=length;
  }
  if(!best)return null;
  return {nodes,points,start:best.progress,initialPosition:[...body.position],initialYaw:body.yaw,
    // Both residual components preserve the exact initial pose, including
    // clamped endpoint cases; rotate these offsets with the authored tangent.
    cross:(body.x-best.x)*best.tz-(body.z-best.z)*best.tx,
    along:(body.x-best.x)*best.tx+(body.z-best.z)*best.tz,
    heightOffset:body.y-best.height,
    headingOffset:wrap(body.yaw*Math.PI/2048-Math.atan2(-best.tx,best.tz)),
    speed:Math.hypot(body.forwardSpeed,body.lateralSpeed)*10};
}

export function sampleCopiedNPCPath(path,seconds) {
  if(seconds===0)return {position:[...path.initialPosition],yaw:path.initialYaw};
  let remaining=path.start+path.speed*seconds;
  for(let i=0;i<path.points.length-1;i++){
    const a=path.points[i],b=path.points[i+1],dx=b[0]-a[0],dz=b[2]-a[2],length=Math.hypot(dx,dz);
    if(length===0)continue;
    if(remaining<=length||i===path.points.length-2){
      const fraction=clamp(remaining/length,0,1),tx=dx/length,tz=dz/length;
      return {position:[
        a[0]+fraction*dx+tz*path.cross+tx*path.along,
        a[1]+fraction*(b[1]-a[1])+path.heightOffset,
        a[2]+fraction*dz-tx*path.cross+tz*path.along,
      ],yaw:(Math.atan2(-tx,tz)+path.headingOffset)*2048/Math.PI};
    }
    remaining-=length;
  }
  throw new Error('Copied NPC route has no positive-length segment');
}

export function createRouteTrafficForecast(motion,track,opponents) {
  const source=motion.collision;
  const actors=new Map(opponents.map(actor=>[actor.body,actor]));
  const entries=source.bodies.filter(body=>body!==motion.body).map(body=>({
    original:body,copy:{...body,position:[...body.position],bounds:body.bounds?{...body.bounds}:undefined},
    path:actors.has(body)?copiedNPCPath(track,actors.get(body)):null,
  }));
  const collision=Object.assign(Object.create(Object.getPrototypeOf(source)),source,{
    bodies:entries.map(entry=>entry.copy),contactState:{impulse:0},
  });
  return {collision,advance(seconds){
    for(const entry of entries){
      if(!entry.path)continue;
      const pose=sampleCopiedNPCPath(entry.path,seconds);
      entry.copy.position=pose.position;entry.copy.yaw=pose.yaw;
      entry.copy.sector=selectNativeSector(motion.world,entry.original.sector,pose.position[0],pose.position[2]);
    }
  }};
}
