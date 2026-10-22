// Test controls only. Join retained routes at shared original DMP nodes;
// no geometry, game state, collision rules or timers are changed.
import assert from 'node:assert/strict';
import {RouteTestDriver as GroundDriver} from './private-ground-chord-driver.mjs';
import {RouteTestDriver as ProjectedDriver} from './private-projected-line-driver.mjs';

export function hybridFranceLine(ground,projected) {
  const count=projected.length;
  assert.equal(count,187,'This retained route is France only');
  for(const sector of [0,57,171])
    assert.equal(ground.find(point=>point.sector===sector)?.node,projected[sector],
      `Hybrid join at sector ${sector} must use the same original node`);
  assert.deepEqual(ground.at(-1),{sector:count,node:projected[0]});
  const line=[...ground.filter(point=>point.sector<=57),
    ...projected.flatMap((node,sector)=>sector>57&&sector<171?[{sector,node}]:[]),
    ...ground.filter(point=>point.sector>=171)].map(point=>({...point}));
  const groundEdges=new Set(ground.slice(0,-1).map((p,i)=>`${p.sector}:${p.node}>${ground[i+1].sector}:${ground[i+1].node}`));
  for(let i=0;i<line.length-1;i++) {
    const a=line[i],b=line[i+1];
    if(a.sector>=57&&a.sector<171) {
      assert.equal(b.sector,a.sector+1);
      assert.equal(a.node,projected[a.sector]);
      assert.equal(b.node,projected[b.sector]);
    } else assert.ok(groundEdges.has(`${a.sector}:${a.node}>${b.sector}:${b.node}`));
  }
  return line;
}

export class RouteTestDriver extends GroundDriver {
  configureHybridLine(ground,projected) {
    this.racingLine=hybridFranceLine(ground,projected);
    this.projectedLine=[...projected];
    this.projectedNext=new Map(projected.map((node,i)=>[node,projected[(i+1)%projected.length]]));
    this.racingLineCost=this.racingLine.slice(0,-1).reduce((total,p,i)=>{
      const a=this.track.drive[p.node].position,b=this.track.drive[this.racingLine[i+1].node].position;
      return total+Math.hypot(b[0]-a[0],b[2]-a[2]);
    },0);
  }
  input(body,now,dt,options) {
    if(body.sector<57||body.sector>=171)return super.input(body,now,dt,options);
    // Preserve the earlier successful projected-line controller exactly in
    // the middle section. Temporary fields belong only to this test driver.
    const line=this.racingLine,next=this.racingLineNext;
    this.racingLine=this.projectedLine;this.racingLineNext=this.projectedNext;
    try{return ProjectedDriver.prototype.input.call(this,body,now,dt,options);}
    finally{this.racingLine=line;this.racingLineNext=next;}
  }
}
