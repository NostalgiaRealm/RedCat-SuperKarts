import fs from 'node:fs/promises';
import crypto from 'node:crypto';
import assert from 'node:assert/strict';
import {RouteTestDriver as Base,minimumTurnLine} from '../tests/helpers/private-projected-line-driver.mjs';
import {RouteTestDriver as Candidate} from '../tests/helpers/private-france-authored-branches.mjs';
import {NativeRailCollision} from '../src/simulation/native-collision.js';
import {getPlayerVisualSpec} from '../src/player-assets.js';
const root=new URL('../',import.meta.url),sha=bytes=>crypto.createHash('sha256').update(bytes).digest('hex');
const read=async path=>fs.readFile(new URL(path,root)),json=async path=>JSON.parse(await read(path));
const [track,config,manifest,baseline]=await Promise.all(['public/assets/tracks/etappe3.json','public/assets/config.json','public/assets/manifest.json','evidence/full-race-matrix/timed-france-hard-reset-line1000-p3d06.json'].map(json));
const before=JSON.stringify(track),bounds=getPlayerVisualSpec(config,manifest,1,0).body.bounds;
const base=new Base(track,{railBounds:bounds});base.configureRacingLine(1000);
assert.deepEqual(base.racingLine,baseline.runs[0].racingLine);
const rawShortest=minimumTurnLine(track,track.drive.map(node=>node.links.slice(0,3).filter(i=>i>=0)),0).nodes;
const shortest=minimumTurnLine(track,base.links,0).nodes,candidate=new Candidate(track,{railBounds:bounds});candidate.configureRacingLine(1000);
const n=track.route.length,sectors=new Map();track.route.forEach((r,s)=>[...r.driveIndices,...r.driveLeftIndices].forEach(i=>sectors.set(i,s)));
const links=track.drive.flatMap((node,a)=>node.links.slice(0,3).flatMap((b,slot)=>b>=0?[{a,b,slot,from:sectors.get(a),to:sectors.get(b),advance:(sectors.get(b)-sectors.get(a)+n)%n}]:[]));
assert.equal(sectors.size,track.drive.length);assert.ok(links.every(link=>link.advance===1));
const distance=(a,b)=>Math.hypot(track.drive[a].position[0]-track.drive[b].position[0],track.drive[a].position[2]-track.drive[b].position[2]);
const length=line=>line.reduce((sum,a,i)=>sum+distance(a,line[(i+1)%n]),0);
const divergences=[];
for(let i=0;i<n;){if(base.racingLine[i]===shortest[i]){i++;continue;}const first=i;while(i<n&&base.racingLine[i]!==shortest[i])i++;const last=i-1;let oldLength=0,newLength=0;for(let j=first-1;j<=last;j++){oldLength+=distance(base.racingLine[(j+n)%n],base.racingLine[(j+1)%n]);newLength+=distance(shortest[(j+n)%n],shortest[(j+1)%n]);}divergences.push({first,last,oldLength,newLength,saving:oldLength-newLength,originalNodes:base.racingLine.slice(first,last+1),alternativeNodes:shortest.slice(first,last+1)});}
const query=new NativeRailCollision(track,bounds),edgeChecks=[];
for(let s=0;s<n;s++){
 const a=candidate.racingLine[s],b=candidate.racingLine[(s+1)%n];if(a===base.racingLine[s]&&b===base.racingLine[(s+1)%n])continue;
 const p=track.drive[a].position,q=track.drive[b].position,dx=q[0]-p[0],dz=q[2]-p[2];
 const fraction=query.sweep({position:p,x:p[0],y:p[1],z:p[2],yaw:Math.atan2(-dx,dz)*2048/Math.PI,sector:s,forwardSpeed:Math.hypot(dx,dz)/10,lateralSpeed:0,verticalSpeed:0,yawRate:0},1).fraction;
 assert.equal(fraction,1,`Original adjacent candidate edge ${a}->${b} has no rail clearance`);
 edgeChecks.push({sector:s,from:a,to:b,sourceLinkSlot:track.drive[a].links.slice(0,3).indexOf(b),railFraction:fraction});
}
assert.equal(JSON.stringify(track),before);
const sourceSha256=Object.fromEntries(await Promise.all(['public/assets/tracks/etappe3.json','public/assets/config.json','public/assets/manifest.json','tests/helpers/private-projected-line-driver.mjs','tests/helpers/private-france-authored-branches.mjs'].map(async p=>[p,sha(await read(p))])));
const report={format:'superkarts-france-authored-route-audit-v1',scope:'Read-only original DMP/PMP geometry and original rail-sweep queries; candidate changes ordinary controller goals only. Geometric distance is not a claim of a faster driven lap.',sourceSha256,originalDigests:track.source,nodeCount:track.drive.length,sectorCount:n,forwardLinks:links.length,allLinksAdvanceExactlyOneSector:true,baselineLength:length(base.racingLine),shortestAdjacentLength:length(shortest),rawSourceMinimumLength:length(rawShortest),rawSourceDistanceSaving:length(base.racingLine)-length(rawShortest),rawSourceRouteWarning:'Unfiltered original links; some straight kart sweeps intersect rails. This is a geometric lower bound, not a drivable-path proof.',maximumRailFilteredAdjacentDistanceSaving:length(base.racingLine)-length(shortest),divergences:divergences.sort((a,b)=>b.saving-a.saving),candidate:{...candidate.authoredBranches,edgeChecks},originalTrackUnchanged:true};
await fs.writeFile(new URL('evidence/full-race-matrix/france-authored-route-audit.json',root),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({nodes:report.nodeCount,links:report.forwardLinks,baselineLength:report.baselineLength,shortestAdjacentLength:report.shortestAdjacentLength,candidateLength:report.candidate.afterLength,candidateSavings:report.candidate.beforeLength-report.candidate.afterLength,changedEdges:edgeChecks.length,allLinksAdvanceExactlyOneSector:true},null,2));
