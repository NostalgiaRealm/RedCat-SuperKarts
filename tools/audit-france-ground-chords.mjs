import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {NativeRailCollision} from '../src/simulation/native-collision.js';
import {NativeSceneryBodies,nativeSceneryRectangle} from '../src/simulation/native-scenery-contact.js';
import {createNativeTrack,sampleNativeTrack} from '../src/simulation/native-track.js';
import {nativeSectorDistance} from '../src/simulation/native-race.js';
import {nativeYawTrig} from '../src/simulation/native-ground.js';
import {getPlayerVisualSpec} from '../src/player-assets.js';
import {validationSourceDependencies} from './validation-source-dependencies.mjs';
const root=new URL('../',import.meta.url),sha=b=>crypto.createHash('sha256').update(b).digest('hex');
const inputs={};
async function read(path){const bytes=await fs.readFile(new URL(path,root));inputs[path]=sha(bytes);return JSON.parse(bytes);}
const [track,config,manifest,baseReport,groundReport]=await Promise.all([
  'public/assets/tracks/etappe3.json','public/assets/config.json','public/assets/manifest.json',
  'evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json',
  'evidence/full-race-matrix/timed-france-hard-reset-ground0.json'].map(read));
const before=JSON.stringify(track),base=baseReport.runs[0].racingLine,ground=groundReport.runs[0].racingLine;
const n=track.route.length,world=createNativeTrack(track),visual=getPlayerVisualSpec(config,manifest,1,0);
const query=new NativeRailCollision(track,visual.body.bounds);
const scenery=new NativeSceneryBodies({track,config,manifest,world,collision:query});
const fixed=scenery.bodies.filter(body=>body.type===5).map(nativeSceneryRectangle);
const distance=(a,b)=>Math.hypot(a[0]-b[0],a[2]-b[2]);
const point=node=>track.drive[node].position;
const baseLength=(start,end)=>{let length=0;for(let i=start;i<end;i++)length+=distance(point(base[i%n]),point(base[(i+1)%n]));return length;};
const edges=[];
for(let index=0;index<ground.length-1;index++){
  const a=ground[index],b=ground[index+1],p=point(a.node),q=point(b.node);
  const dx=q[0]-p[0],dz=q[2]-p[2],length=distance(p,q),yaw=Math.atan2(-dx,dz)*2048/Math.PI;
  const body={position:[...p],x:p[0],y:p[1],z:p[2],yaw,sector:a.sector%n,
    forwardSpeed:length/10,lateralSpeed:0,verticalSpeed:0,yawRate:0};
  query.candidates=()=>query.rails;
  const rail=query.sweep(body,1);
  query.candidates=()=>[...query.rails,...fixed];
  const solid=query.sweep(body,1);
  const centerKinds={},wheelKinds={},sectors=[],unsupported=[];
  let hint=a.sector%n,previousHeight=null,maxHeightStep=0,maxSectorStep=0;
  const trig=nativeYawTrig(yaw);
  for(let step=0,count=Math.ceil(length/10);step<=count;step++){
    const t=step/count,x=p[0]+dx*t,y=p[1]+(q[1]-p[1])*t,z=p[2]+dz*t;
    const center=sampleNativeTrack(world,hint,x,y,z);
    maxSectorStep=Math.max(maxSectorStep,Math.abs(nativeSectorDistance(center.sector,hint,n)));
    hint=center.sector;
    if(sectors.at(-1)!==hint)sectors.push(hint);
    centerKinds[center.kind]=(centerKinds[center.kind]??0)+1;
    if(center.kind==='fallback')unsupported.push({step,part:'center',position:[x,y,z],sector:hint});
    if(previousHeight!==null)maxHeightStep=Math.max(maxHeightStep,Math.abs(center.height-previousHeight));
    previousHeight=center.height;
    for(let wheel=0;wheel<visual.wheels.length;wheel++){
      const [ox,,oz]=visual.wheels[wheel].offset;
      const wx=x+trig.cos*ox-trig.sin*oz,wz=z+trig.sin*ox+trig.cos*oz;
      const sample=sampleNativeTrack(world,hint,wx,center.height,wz);
      wheelKinds[sample.kind]=(wheelKinds[sample.kind]??0)+1;
      if(sample.kind==='fallback')unsupported.push({step,part:`wheel${wheel}`,position:[wx,sample.height,wz],sector:sample.sector});
    }
  }
  // Preserve the native fallback result. Probe either side only to distinguish
  // an exact triangle/sector seam from a broad unsupported cut; do not repair it.
  for(const item of unsupported){
    const [x,y,z]=item.position;
    item.nearbySupport=[-1,-.1,.1,1].map(offset=>({offset,
      kind:sampleNativeTrack(world,item.sector,x+dx/length*offset,y,z+dz/length*offset).kind}));
  }
  const sectorMetadata=[];
  for(let s=a.sector;s<=b.sector;s++){
    const route=track.route[s%n],markers=[...new Set([...route.driveIndices,...route.driveLeftIndices].map(i=>track.drive[i].unknown[1]))];
    if(markers.some(x=>x!==0)||route.trigger||route.unknown)sectorMetadata.push({sector:s%n,markers,
      pmpTrigger:route.trigger,pmpUnknown:route.unknown});
  }
  edges.push({index,from:a,to:b,length,baselineLength:baseLength(a.sector,b.sector),
    saving:baseLength(a.sector,b.sector)-length,originalAdjacent:b.sector-a.sector===1&&track.drive[a.node].links.slice(0,3).includes(b.node),
    railFraction:rail.fraction,railAndStaticFraction:solid.fraction,
    staticHit:solid.contact?.secondBody?.placementIndex??solid.contact?.firstBody?.placementIndex??null,
    centerKinds,wheelKinds,unsupported,sectors,maxSectorStep,maxHeightStep,sectorMetadata});
}
const common=ground.map((entry,index)=>entry.node===base[entry.sector%n]?index:null).filter(x=>x!==null);
const segments=[];
for(let k=0;k<common.length-1;k++){
  const first=common[k],last=common[k+1],items=edges.slice(first,last);
  const a=ground[first],b=ground[last],baselineLength=baseLength(a.sector,b.sector),length=items.reduce((sum,e)=>sum+e.length,0);
  segments.push({fromSector:a.sector,toSector:b.sector,nodes:ground.slice(first,last+1),baselineLength,
    length,saving:baselineLength-length,savingMetres:(baselineLength-length)/10,
    railClear:items.every(e=>e.railFraction===1),staticClear:items.every(e=>e.railAndStaticFraction===1),
    denseCenterAndWheelSupport:items.every(e=>!e.unsupported.length),
    supportGapsBoundedByOneUnit:items.every(e=>e.unsupported.every(item=>
      item.nearbySupport.filter(sample=>Math.abs(sample.offset)===1).every(sample=>sample.kind!=='fallback'))),
    supportGapCount:items.reduce((sum,e)=>sum+e.unsupported.length,0),
    maxSectorStep:Math.max(...items.map(e=>e.maxSectorStep)),
    metadata:items.flatMap(e=>e.sectorMetadata),edgeIndices:items.map(e=>e.index)});
}
const blocks=[[0,80],[80,129],[129,176],[176,187]].map(([start,end])=>{
  const clippedLength=edges.reduce((sum,e)=>sum+e.length*Math.max(0,Math.min(end,e.to.sector)-Math.max(start,e.from.sector))/(e.to.sector-e.from.sector),0);
  return {start,end,baselineLength:baseLength(start,end),groundLengthAllocatedBySector:clippedLength,
    approximateSaving:baseLength(start,end)-clippedLength};
});
assert.equal(JSON.stringify(track),before);
const result={format:'superkarts-france-ground-chord-audit-v1',generatedAt:new Date().toISOString(),
  scope:'Read-only geometry comparison of two retained original-node routes. Every ground chord is rechecked using all original rails and fixed type5 solids with original kart bounds; native terrain is sampled at most10units apart at center and four original wheel offsets. Geometry clearance is not a driven-lap proof: turning, tire slip, dynamic traffic/train and body pitch remain unvalidated. Original markers and PMP triggers are listed, never removed or modified.',
  inputs,sourceSha256:Object.fromEntries(await Promise.all((await validationSourceDependencies(new URL(import.meta.url),root))
    .map(async path=>[path,sha(await fs.readFile(new URL(path,root)))]))),
  originalDigests:track.source,baselineLength:baseLength(0,n),groundLength:edges.reduce((s,e)=>s+e.length,0),
  savingMetres:(baseLength(0,n)-edges.reduce((s,e)=>s+e.length,0))/10,
  wheelOffsets:visual.wheels.map(w=>w.offset),bounds:visual.body.bounds,
  staticBodyCount:fixed.length,omittedDynamicBodies:scenery.bodies.filter(b=>b.type!==5).map(b=>({placementIndex:b.placementIndex,mesh:b.mesh,type:b.type})),
  blocks,segments:segments.sort((a,b)=>b.saving-a.saving),edges,originalTrackUnchanged:true};
await fs.writeFile(new URL('evidence/full-race-matrix/france-ground-chord-audit.json',root),JSON.stringify(result,null,2)+'\n');
console.log(JSON.stringify({baselineLength:result.baselineLength,groundLength:result.groundLength,savingMetres:result.savingMetres,
  segments:result.segments.filter(s=>s.saving>5).map(({metadata,edgeIndices,...s})=>({...s,metadata})),
  failedEdges:edges.filter(e=>e.railFraction<1||e.railAndStaticFraction<1||e.unsupported.length).map(e=>({from:e.from,to:e.to,rail:e.railFraction,static:e.railAndStaticFraction,unsupported:e.unsupported.length,staticHit:e.staticHit}))},null,2));
