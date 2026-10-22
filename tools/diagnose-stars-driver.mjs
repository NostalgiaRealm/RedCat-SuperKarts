/**
 * Test automation only. This is not original opponent AI or gameplay code.
 * Reads original linked DMP road nodes and returns ordinary analog inputs.
 * It never changes a kart, race timer, trigger, pickup, or physics constant.
 */
import { NativeRailCollision } from '../src/simulation/native-collision.js';
import { StarApproachPlanner,preferredRoadNodes } from '../tests/helpers/star-approach-planner.mjs';
const clamp = (value, low, high) => Math.max(low, Math.min(high, value));
const distance = (a, b) => Math.hypot(a[0] - b[0], a[2] - b[2]);

export class RouteTestDriver {
  constructor(track, { speed = 30, lookAheadSeconds = .5, steeringGain = 1.5,
    dampingGain = .5, railBounds = null, obstacles = [] } = {}) {
    Object.assign(this, { track, speed, lookAheadSeconds, steeringGain, dampingGain });
    this.stationaryMs = 0;
    this.reverseUntil = 0;
    this.recoveries = 0;
    this.previousPosition = null;
    this.targetPaths = new Map();
    this.approachTarget = null;
    this.approachUntil = 0;
    this.approachCooldown = new Map();
    // NPC bodies use the shared kart bounds in the engine. Give read-only
    // planner views those bounds while retaining the live pose by inheritance.
    // These views are never inserted into the simulation or collision response.
    obstacles=obstacles.map(body=>body.bounds?body:Object.create(body,{bounds:{value:railBounds}}));
    this.starPlanner = railBounds ? new StarApproachPlanner(track,{obstacles,avoidEnvironment:true}) : null;
    this.narrowStarPlanner = railBounds ? new StarApproachPlanner(track,{clearance:38,obstacles,avoidEnvironment:true}) : null;
    this.reverseLinks = track.drive.map(() => []);
    this.links = track.drive.map(node => preferredRoadNodes(track,node.links.slice(0, 3).filter(index => index >= 0)));
    if (railBounds) {
      const collision = new NativeRailCollision(track, railBounds);
      this.testCollision=collision;
      const sectors = new Int32Array(track.drive.length);
      track.route.forEach((route, sector) => {
        for (const node of [...route.driveIndices, ...route.driveLeftIndices]) sectors[node] = sector;
      });
      this.links = this.links.map((links, index) => {
        const position = track.drive[index].position;
        const legal = links.filter(next => {
          const end = track.drive[next].position;
          const dx = end[0] - position[0], dz = end[2] - position[2];
          // A synthetic query against the unchanged original rail kernel.
          // This body is never registered in or written to the actual race.
          const query = { x: position[0], y: position[1], z: position[2], position,
            yaw: Math.atan2(-dx, dz) * 2048 / Math.PI, sector: sectors[index],
            forwardSpeed: Math.hypot(dx, dz) / 10, lateralSpeed: 0, verticalSpeed: 0, yawRate: 0 };
          return collision.sweep(query, 1).fraction >= 1;
        });
        return legal.length ? legal : links;
      });
      // A solid can be driven around without discarding its entire authored
      // road link (which can select the wrong branch at a divided road).
      collision.bodies=obstacles;
    }
    this.links.forEach((links, index) => links.forEach(next => {
      if (next >= 0) this.reverseLinks[next].push(index);
    }));
  }

  targetPath(target) {
    const key = target.position.join(',');
    if (!this.targetPaths.has(key)) {
      const goal = this.track.drive.reduce((best, node, index) =>
        distance(node.position, target.position) < distance(this.track.drive[best].position, target.position) ? index : best, 0);
      const steps = new Int32Array(this.track.drive.length).fill(-1), queue = [goal];
      steps[goal] = 0;
      for (let i = 0; i < queue.length; i++) {
        const node = queue[i];
        for (const previous of this.reverseLinks[node]) if (steps[previous] < 0) {
          steps[previous] = steps[node] + 1;
          queue.push(previous);
        }
      }
      this.targetPaths.set(key, { goal, steps });
    }
    return this.targetPaths.get(key);
  }

  exitApproach(body){
    const plan=this.starPlanner?.planToRoad(body.position,body.sector)
      ??this.narrowStarPlanner?.planToRoad(body.position,body.sector);
    this.egressPath=plan?.points??[...(this.approachFullPath??[])].reverse().slice(1);
  }

  clearSegment(body, target) {
    if (!this.testCollision) return false;
    const dx=target[0]-body.x,dz=target[2]-body.z;
    return this.testCollision.sweep({...body,sourceBody:body,
      yaw:Math.atan2(-dx,dz)*2048/Math.PI,
      forwardSpeed:Math.hypot(dx,dz)/10,lateralSpeed:0,verticalSpeed:0,yawRate:0},1).fraction>=1;
  }

  refreshStalledDetour(body, nowMs, roadTarget, roadPath) {
    if (!this.egressPath?.length) { this.detourProgress=null; return; }
    const point=this.egressPath[0],key=point.join(','),remaining=distance(body.position,point);
    if(this.detourProgress?.key!==key){
      this.detourProgress={key,bestDistance:remaining,lastProgressMs:nowMs};
      return;
    }
    const progress=this.detourProgress;
    if(remaining<progress.bestDistance-5){
      progress.bestDistance=remaining;progress.lastProgressMs=nowMs;
    }
    // A kart can keep moving around a missed corner forever, so displacement
    // alone is insufficient. Reconnect only after the target stops getting
    // closer, and query the unchanged collision kernel at the current pose.
    if(nowMs-progress.lastProgressMs<6000||nowMs<this.reverseUntil)return;
    progress.lastProgressMs=nowMs;
    let replacement=null;
    if(this.clearSegment(body,roadTarget))replacement=[];
    else{
      for(let i=this.egressPath.length-1;i>0;i--)
        if(this.clearSegment(body,this.egressPath[i])){
          replacement=this.egressPath.slice(i);break;
        }
      if(!replacement){
        const goals=roadPath.slice(2,8);
        const plan=this.starPlanner?.planToRoad(body.position,body.sector,goals)
          ??this.narrowStarPlanner?.planToRoad(body.position,body.sector,goals);
        if(plan)replacement=plan.points;
      }
    }
    if(replacement){
      this.egressPath=replacement;
      this.detourProgress=null;
      this.detourReplans=(this.detourReplans??0)+1;
      this.lastDetourRefresh={timeMs:nowMs,from:[...point],to:replacement[0]??roadTarget};
    }
  }

  input(body, nowMs, dtMs, { targets = [] } = {}) {
    const { track } = this, route = track.route[body.sector];
    const candidates = preferredRoadNodes(track,[...route.driveIndices, ...route.driveLeftIndices]);
    if (!candidates.length) throw new Error(`No authored road nodes in sector ${body.sector}`);
    let node = candidates.reduce((best, next) =>
      distance(track.drive[next].position, body.position) < distance(track.drive[best].position, body.position)
        ? next : best, candidates[0]);
    // Optional star collection is a test-driver route choice, never an item
    // collection call. It follows authored links toward the still-active star.
    let chosen = null;
    for (const target of targets) {
      const graph = this.targetPath(target);
      let steps = graph.steps[node];
      const next = track.route[(body.sector + 1) % track.route.length].position;
      const ahead = (target.position[0] - body.x) * (next[0] - route.position[0])
        + (target.position[2] - body.z) * (next[2] - route.position[2]);
      const nearby=distance(body.position,target.position);
      if(this.starPlanner&&(steps<0||steps>6)&&nearby<900&&ahead>0)
        steps=nearby/200;
      if ((this.approachCooldown.get(target)??0)>nowMs
        ||steps < 0 || steps > 40 || (steps === 0 && ahead < 0)) continue;
      if (!chosen || steps < chosen.steps) chosen = { target, graph, steps };
    }
    // Continue an imminent pickup approach after its nearest road node falls
    // behind us. A road node is not the pickup position; dropping the target
    // there can make the test driver repeatedly miss off-centre stars.
    if(this.approachTarget&&!targets.includes(this.approachTarget)){
      this.exitApproach(body);
      this.approachTarget=null;
    }
    if(this.egressPath?.length){
      chosen=null;
      while(this.egressPath.length&&distance(body.position,this.egressPath[0])<35)
        this.egressPath.shift();
    }
    if(this.approachTarget&&targets.includes(this.approachTarget)&&nowMs<this.approachUntil){
      const graph=this.targetPath(this.approachTarget);
      chosen={target:this.approachTarget,graph,steps:graph.steps[node],approaching:true};
    }else{
      if(this.approachTarget&&targets.includes(this.approachTarget)){
        this.approachCooldown.set(this.approachTarget,nowMs+30000);
        this.exitApproach(body);
        chosen=null;
      }
      this.approachTarget=null;
      if(!this.egressPath?.length&&chosen&&chosen.steps<=6&&distance(body.position,chosen.target.position)<1000){
        const plan=this.starPlanner?.plan(body.position,chosen.target)
          ??this.narrowStarPlanner?.plan(body.position,chosen.target);
        if(plan){
          this.approachTarget=chosen.target;this.approachUntil=nowMs+40000;
          this.approachPath=plan.points;
          this.approachFullPath=[[...body.position],...plan.points];
          chosen.approaching=true;
        }else if(this.starPlanner){
          this.approachCooldown.set(chosen.target,nowMs+30000);
          chosen=null;
        }
      }
    }
    const path = [track.drive[node].position];
    for (let i = 0; i < 10; i++) {
      const current = track.drive[node];
      const choices = this.links[node];
      if (!choices.length) break;
      const directed = chosen && chosen.graph.steps[node] > 0
        ? choices.filter(index => chosen.graph.steps[index] >= 0 && chosen.graph.steps[index] < chosen.graph.steps[node]) : [];
      const available = directed.length ? directed : choices;
      node = available.reduce((best, next) =>
        distance(track.drive[next].position, current.position) < distance(track.drive[best].position, current.position)
          ? next : best, available[0]);
      path.push(chosen?.graph.goal === node ? chosen.target.position : track.drive[node].position);
    }
    if (path.length < 2) throw new Error(`Road node ${node} has no forward link`);
    // Sector centers can lie between two roads; connected road nodes cannot
    // be replaced by that center when planning the test driver's path.
    const next = track.route[(body.sector + 1) % track.route.length].position;
    const dx = next[0] - route.position[0], dz = next[2] - route.position[2];
    let fraction = clamp(((body.x - route.position[0]) * dx +
      (body.z - route.position[2]) * dz) / (dx * dx + dz * dz), 0, 1);
    const lookAhead = 50 + Math.abs(body.forwardSpeed) * 10 * this.lookAheadSeconds;
    let remaining = lookAhead, target = path.at(-1);
    for (let i = 0; i + 1 < path.length; i++) {
      const a = path[i], b = path[i + 1], length = distance(a, b);
      const available = length * (1 - fraction);
      if (remaining <= available && length > 0) {
        const t = fraction + remaining / length;
        target = [a[0] + t * (b[0] - a[0]), 0, a[2] + t * (b[2] - a[2])];
        break;
      }
      remaining -= available;
      fraction = 0;
    }
    const targetDistance = chosen ? distance(body.position, chosen.target.position) : Infinity;
    if (chosen && !chosen.approaching && targetDistance < Math.max(lookAhead * 1.5, chosen.steps <= 2 ? 500 : 0))
      target = chosen.target.position;
    if(chosen?.approaching){
      while(this.approachPath.length>1&&distance(body.position,this.approachPath[0])<35)
        this.approachPath.shift();
      target=this.approachPath[0];
    }
    this.refreshStalledDetour(body,nowMs,target,path);
    if(this.egressPath?.length)target=this.egressPath[0];
    if(this.testCollision&&!chosen?.approaching&&!this.egressPath?.length
      &&nowMs>=(this.nextAvoidanceCheck??0)){
      this.nextAvoidanceCheck=nowMs+250;
      const dx=target[0]-body.x,dz=target[2]-body.z;
      const query={...body,sourceBody:body,yaw:Math.atan2(-dx,dz)*2048/Math.PI,
        forwardSpeed:Math.hypot(dx,dz)/10,lateralSpeed:0,yawRate:0};
      if(this.testCollision.sweep(query,1).fraction<1){
        const goals=path.slice(2,8);
        const plan=this.starPlanner.planToRoad(body.position,body.sector,goals)
          ??this.narrowStarPlanner.planToRoad(body.position,body.sector,goals);
        if(plan){this.egressPath=plan.points;target=this.egressPath[0];}
      }
    }
    const desiredHeading = Math.atan2(-(target[0] - body.x), target[2] - body.z);
    const error = Math.atan2(Math.sin(desiredHeading - body.yaw * Math.PI / 2048),
      Math.cos(desiredHeading - body.yaw * Math.PI / 2048));
    const navigating=chosen?.approaching||this.egressPath?.length;
    const backing=navigating&&Math.abs(error)>Math.PI*.6;
    const steeringError=backing?Math.atan2(Math.sin(error-Math.PI),Math.cos(error-Math.PI)):error;
    const targetSpeed = (backing?-1:1)*Math.min(this.speed / (1 + Math.abs(steeringError) * 2),
      navigating ? (chosen?.approaching&&this.approachPath.length===1&&distance(body.position,target)<12?0:8) : Infinity);
    let steer = clamp(-error * this.steeringGain + body.yawRate * this.dampingGain, -1, 1);
    if(backing)steer=clamp(steeringError*this.steeringGain-body.yawRate*this.dampingGain,-1,1);
    let throttle = clamp((targetSpeed - body.forwardSpeed) * .2, 0, 1);
    let brake = body.forwardSpeed > targetSpeed + 2
      ? clamp((body.forwardSpeed - targetSpeed) * .1, 0, 1) : 0;
    if(nowMs<this.reverseUntil)this.stationaryMs=0;
    else if (this.previousPosition && distance(this.previousPosition, body.position) < .5) this.stationaryMs += dtMs;
    else this.stationaryMs = 0;
    this.previousPosition = [...body.position];
    if (this.stationaryMs >= 1500 && nowMs > this.reverseUntil) {
      this.reverseUntil = nowMs + 2500;
      this.recoveryDirection=backing?1:-1;
      // Test-only control policy: choose a clear straight escape before turning.
      if(this.testCollision){
        const clearance=direction=>this.testCollision.sweep({...body,sourceBody:body,
          forwardSpeed:direction*10,lateralSpeed:0,verticalSpeed:0,yawRate:0},.2).fraction;
        const forward=clearance(1),reverse=clearance(-1);
        if(forward!==reverse)this.recoveryDirection=forward>reverse?1:-1;
      }
      this.straightEscapeUntil=nowMs+1250;
      this.stationaryMs = 0;
      this.recoveries++;
      // Reconnect from the actual stopped pose, not a reverse copy of an
      // approach whose corners may have been missed while manoeuvring.
      if(this.egressPath?.length)this.exitApproach(body);
      else if(this.approachTarget){
        const plan=this.starPlanner?.plan(body.position,this.approachTarget)
          ??this.narrowStarPlanner?.plan(body.position,this.approachTarget);
        if(plan)this.approachPath=plan.points;
      }else if(this.starPlanner){
        const plan=this.starPlanner.planToRoad(body.position,body.sector)
          ??this.narrowStarPlanner.planToRoad(body.position,body.sector);
        if(plan)this.egressPath=plan.points;
      }
    }
    if (nowMs < this.reverseUntil) {
      throttle = this.recoveryDirection>0?1:0;
      brake = this.recoveryDirection>0?0:1;
      steer = nowMs<this.straightEscapeUntil?0:
        this.recoveryDirection>0?clamp(-steeringError,-1,1):clamp(error,-1,1);
    }
    this.telemetry = { target: [...target], headingError: error, targetSpeed, reversing: nowMs < this.reverseUntil,
      detourReplans:this.detourReplans??0,lastDetourRefresh:this.lastDetourRefresh,
      pickupTarget:chosen?{position:chosen.target.position,steps:chosen.steps,approaching:Boolean(chosen.approaching)}:null };
    return { throttle, brake, steer, handbrake: 0, bonus: 0,
      analog: { throttle, brake, steer } };
  }
}
