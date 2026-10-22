// Test-only target selection. All goals and every edge remain original DMP data.
import {RouteTestDriver as Base,minimumTurnLine} from './private-projected-line-driver.mjs';
export const FRANCE_INNER_BRANCHES=[[39,53],[157,170]];
export class RouteTestDriver extends Base {
  configureRacingLine(turnPenalty){
    super.configureRacingLine(turnPenalty);
    const originalObjectiveCost=this.racingLineCost,original=[...this.racingLine],shortest=minimumTurnLine(this.track,this.links,0).nodes;
    this.racingLine=[...original];
    for(const[first,last]of FRANCE_INNER_BRANCHES)
      for(let sector=first;sector<=last;sector++)this.racingLine[sector]=shortest[sector];
    for(let i=0;i<this.racingLine.length;i++){
      const a=this.racingLine[i],b=this.racingLine[(i+1)%this.racingLine.length];
      if(!this.track.drive[a].links.slice(0,3).includes(b)||!this.links[a].includes(b))
        throw new Error(`Selected original branch has no permitted authored edge ${a}->${b}`);
    }
    this.racingLineNext=new Map(this.racingLine.map((node,i)=>[node,this.racingLine[(i+1)%this.racingLine.length]]));
    const length=line=>line.reduce((sum,a,i)=>{const p=this.track.drive[a].position,q=this.track.drive[line[(i+1)%line.length]].position;return sum+Math.hypot(p[0]-q[0],p[2]-q[2]);},0);
    this.racingLineCost=null; // The composite route is not a minimum of the previous weighted objective.
    this.authoredBranches={originalObjectiveCost,ranges:FRANCE_INNER_BRANCHES,before:original,after:[...this.racingLine],beforeLength:length(original),afterLength:length(this.racingLine)};
  }
}
