// Private ordinary-input route target. Never writes a simulation body.
const clamp=(v,a,b)=>Math.max(a,Math.min(b,v));
export function authoredBranchGoal(track,body,nodes,lookAheadSeconds){
  const sectors=new Map();for(let i=0;i<track.route.length;i++)for(const node of [...track.route[i].driveIndices,...track.route[i].driveLeftIndices])sectors.set(node,i);
  let best=null;
  for(let i=0;i+1<nodes.length;i++){
    if(body.sector<sectors.get(nodes[i])-1||body.sector>sectors.get(nodes[i+1])+1)continue;
    const a=track.drive[nodes[i]].position,b=track.drive[nodes[i+1]].position,dx=b[0]-a[0],dz=b[2]-a[2];
    const fraction=clamp(((body.x-a[0])*dx+(body.z-a[2])*dz)/(dx*dx+dz*dz),0,1),d=Math.hypot(body.x-a[0]-fraction*dx,body.z-a[2]-fraction*dz);
    if(!best||d<best.d)best={i,fraction,d};
  }
  if(!best)return null;
  let remaining=50+Math.abs(body.forwardSpeed)*10*lookAheadSeconds;
  for(let i=best.i;i+1<nodes.length;i++){
    const a=track.drive[nodes[i]].position,b=track.drive[nodes[i+1]].position,dx=b[0]-a[0],dz=b[2]-a[2],len=Math.hypot(dx,dz),fraction=i===best.i?best.fraction:0;
    if(remaining<=len*(1-fraction)||i===nodes.length-2){const t=clamp(fraction+remaining/len,0,1);return[a[0]+t*dx,0,a[2]+t*dz];}
    remaining-=len*(1-fraction);
  }
  return null;
}
