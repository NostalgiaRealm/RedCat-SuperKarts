// Test-only visibility routing around CMP barriers and current scenery bounds. These
// points are steering targets, never writes to simulation position or pickups.
import { nativeTrigTable } from '../../src/simulation/native-integrator.js';
const distance=(a,b)=>Math.hypot(a[0]-b[0],a[2]-b[2]);
function pointSegment(p,a,b){
  const dx=b[0]-a[0],dz=b[2]-a[2],den=dx*dx+dz*dz;
  const t=den?Math.max(0,Math.min(1,((p[0]-a[0])*dx+(p[2]-a[2])*dz)/den)):0;
  return Math.hypot(p[0]-a[0]-t*dx,p[2]-a[2]-t*dz);
}
function intersects(a,b,c,d){
  const cross=(a,b,c)=>(b[0]-a[0])*(c[2]-a[2])-(b[2]-a[2])*(c[0]-a[0]);
  const x=cross(a,b,c),y=cross(a,b,d),z=cross(c,d,a),w=cross(c,d,b);
  return x*y<0&&z*w<0;
}
// Marker50 invokes the native environmental-rescue check only near the fallback
// plane. Prefer another authored lane where one exists (Italy's canal), but
// retain all50 sections such as the raised Germany/France bridge.
export function preferredRoadNodes(track,indices){
  const alternatives=indices.filter(index=>track.drive[index].unknown[1]!==50);
  return alternatives.length?alternatives:indices;
}
export class StarApproachPlanner{
  constructor(track,{clearance=53,obstacles=[],avoidEnvironment=false}={}){
    this.track=track;this.clearance=clearance;this.obstacles=obstacles;this.cache=new Map();
    this.avoidEnvironment=avoidEnvironment;
    this.avoidedRoadNodes=new Set();
    if(avoidEnvironment)for(const route of track.route){
      const indices=[...route.driveIndices,...route.driveLeftIndices];
      const preferred=new Set(preferredRoadNodes(track,indices));
      for(const index of indices)if(!preferred.has(index))this.avoidedRoadNodes.add(index);
    }
    this.lines=track.collision.map(({position:p,delta:d})=>
      [p,[p[0]+d[0],p[1]+d[1],p[2]+d[2]]]);
    const ends=this.lines.flat();
    this.tips=ends.filter((point,i)=>ends.every((other,j)=>i===j||distance(point,other)>2));
  }
  scenery(centre){
    const {sin,cos}=nativeTrigTable();
    return this.obstacles.filter(body=>body.active!==false&&!body.collisionDisabled&&body.bounds
      &&distance(body.position,centre)<2200).map(body=>{
      const b=body.bounds,angle=(body.yaw>0?Math.ceil(body.yaw):Math.floor(body.yaw))&4095;
      const points=[[b.minX,b.minZ],[b.maxX,b.minZ],[b.maxX,b.maxZ],[b.minX,b.maxZ]].map(([x,z])=>
        [body.x+cos[angle]*x-sin[angle]*z,body.y,body.z+sin[angle]*x+cos[angle]*z]);
      return {points,body};
    });
  }
  outside(point,polygons){
    return polygons.every(({points})=>{
      const signs=points.map((a,i)=>{
        const b=points[(i+1)%points.length];
        return (b[0]-a[0])*(point[2]-a[2])-(b[2]-a[2])*(point[0]-a[0]);
      });
      return !(signs.every(x=>x>=0)||signs.every(x=>x<=0));
    });
  }
  clear(a,b,lines,depart=false){
    return lines.every(([c,d])=>{
      const start=pointSegment(a,c,d),end=pointSegment(b,c,d);
      const margin=depart&&end>start+2?Math.min(this.clearance,start-.5):this.clearance;
      return !intersects(a,b,c,d)&&Math.min(start,end,pointSegment(c,a,b),pointSegment(d,a,b))>=margin;
    });
  }
  graph(target){
    const polygons=this.scenery(target.position);
    // Animated and movable original scenery keeps its current bounds. A route
    // graph built before one moves is not reused with an obsolete footprint.
    const key=JSON.stringify([target.position,target.goals,polygons.map(x=>x.points)]);
    if(this.cache.has(key))return this.cache.get(key);
    const centre=target.position;
    const lines=[...this.lines.filter(([a,b])=>pointSegment(centre,a,b)<2000),
      ...polygons.flatMap(({points})=>points.map((a,i)=>[a,points[(i+1)%points.length]]))];
    const allowed=point=>this.outside(point,polygons)
      &&lines.every(([a,b])=>pointSegment(point,a,b)>=this.clearance);
    // A collection needs contact with the original pickup radius, not exact
    // alignment with its centre. Some centres are too close to a curb for the
    // conservative circular clearance used by this test planner.
    const candidates=(target.goals??[centre,...Array.from({length:12},(_,i)=>{
      const angle=i*Math.PI/6;return [centre[0]+Math.cos(angle)*55,centre[1],centre[2]+Math.sin(angle)*55];
    })]).filter(allowed);
    const points=[...candidates,...this.track.drive.filter((node,index)=>!this.avoidedRoadNodes.has(index)).map(node=>node.position)
      .filter(point=>distance(point,centre)<1600)];
    for(const tip of this.tips)if(distance(tip,centre)<1500)
      for(let i=0;i<12;i++){
        const angle=i*Math.PI/6;
        points.push([tip[0]+Math.cos(angle)*80,0,tip[2]+Math.sin(angle)*80]);
      }
    for(const {points:corners}of polygons)for(const corner of corners)
      for(let i=0;i<12;i++){
        const angle=i*Math.PI/6,radius=this.clearance+18;
        points.push([corner[0]+Math.cos(angle)*radius,corner[1],corner[2]+Math.sin(angle)*radius]);
      }
    const vertices=points.filter(allowed);
    const edges=vertices.map(()=>[]);
    for(let i=0;i<vertices.length;i++)for(let j=0;j<i;j++){
      const length=distance(vertices[i],vertices[j]);
      if(length<600&&this.clear(vertices[i],vertices[j],lines)){
        edges[i].push([j,length]);edges[j].push([i,length]);
      }
    }
    const distances=vertices.map((_,i)=>i<candidates.length?0:Infinity),next=vertices.map(()=>-1),done=new Set();
    while(done.size<vertices.length){
      let index=-1,best=Infinity;
      for(let i=0;i<vertices.length;i++)if(!done.has(i)&&distances[i]<best){index=i;best=distances[i];}
      if(index<0)break;
      done.add(index);
      for(const [other,length]of edges[index])if(best+length<distances[other]){
        distances[other]=best+length;next[other]=index;
      }
    }
    const graph={vertices,distances,next,lines};this.cache.set(key,graph);
    if(this.cache.size>24)this.cache.delete(this.cache.keys().next().value);
    return graph;
  }
  plan(position,target){
    const graph=this.graph(target);
    let index=-1,best=Infinity;
    for(let i=0;i<graph.vertices.length;i++){
      const length=distance(position,graph.vertices[i]);
      if(length>650||length+graph.distances[i]>=best||!this.clear(position,graph.vertices[i],graph.lines,true))continue;
      best=length+graph.distances[i];index=i;
    }
    if(index<0||best>2200)return null;
    const points=[];
    while(index>=0){points.push(graph.vertices[index]);index=graph.next[index];}
    return {points,distance:best};
  }
  planToRoad(position,sector,directedGoals){
    const goals=directedGoals??[];
    if(!directedGoals)for(let offset=2;offset<=10;offset++){
      const route=this.track.route[(sector+offset)%this.track.route.length];
      const indices=[...route.driveIndices,...route.driveLeftIndices];
      for(const index of this.avoidEnvironment?preferredRoadNodes(this.track,indices):indices){
        const point=this.track.drive[index].position;
        if(distance(position,point)<1200)goals.push(point);
      }
    }
    return this.plan(position,{position,goals});
  }
}
