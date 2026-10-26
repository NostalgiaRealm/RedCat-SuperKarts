import fs from 'node:fs';
import {NativeRailCollision} from '../source/simulation/native-collision.js';
import {createNativeTrack,selectNativeSector,sampleNativeTrack} from '../source/simulation/native-track.js';
const track=JSON.parse(fs.readFileSync('public/assets/tracks/etappe1.json'));
const cars=JSON.parse(fs.readFileSync('public/assets/cars.json'));
const world=createNativeTrack(track);
const collision=new NativeRailCollision(track,cars.cars[1].bodyBounds);
const sectors=new Map();track.route.forEach((r,s)=>r.driveIndices.forEach(i=>sectors.set(i,s)));
const found=[];
for(let s=0;s<track.route.length;s++)for(let span=4;span<=12;span++){
 const e=(s+span)%track.route.length;
 for(const i of track.route[s].driveIndices)for(const j of track.route[e].driveIndices){
 const a=track.drive[i].position,b=track.drive[j].position,dx=b[0]-a[0],dz=b[2]-a[2],len=Math.hypot(dx,dz);
 let road=0;for(let k=0;k<span;k++){const a=track.route[(s+k)%track.route.length].position,b=track.route[(s+k+1)%track.route.length].position;road+=Math.hypot(b[0]-a[0],b[2]-a[2]);}
 if(road-len<100)continue;
 const body={position:a,x:a[0],y:a[1]+8,z:a[2],yaw:Math.atan2(-dx,dz)*2048/Math.PI,sector:s,forwardSpeed:len/10,lateralSpeed:0,verticalSpeed:0,yawRate:0};
 const oldCandidates=collision.candidates;
 collision.candidates=()=>collision.rails.filter((rail,k)=>{const p=track.collision[k].position,d=track.collision[k].delta;const loX=Math.min(a[0],b[0])-80,hiX=Math.max(a[0],b[0])+80,loZ=Math.min(a[2],b[2])-80,hiZ=Math.max(a[2],b[2])+80;return Math.max(p[0],p[0]+d[0])>=loX&&Math.min(p[0],p[0]+d[0])<=hiX&&Math.max(p[2],p[2]+d[2])>=loZ&&Math.min(p[2],p[2]+d[2])<=hiZ;});
 const hit=collision.sweep(body,1);collision.candidates=oldCandidates;
 if(hit.fraction>=1)found.push({s,e,i,j,len,road,saved:road-len});
 }
}
found.sort((a,b)=>b.saved-a.saved);console.log(JSON.stringify(found.slice(0,80),null,2));
