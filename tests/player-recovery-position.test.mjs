import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {NativeRailCollision} from '../src/simulation/native-collision.js';
import {NativeRescueController,nativeRescueDestinationAtWaypoint} from '../src/simulation/native-rescue.js';
import {isSafePlayerRecoveryPose,selectPlayerRecoveryDestination} from '../src/simulation/player-recovery-position.js';
import {sampleNativeTrack} from '../src/simulation/native-track.js';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';

const bounds={minX:-10,maxX:10,minZ:-15,maxZ:15};
const road=width=>[
  [[-width,0,-1000],[width,0,-1000],[width,0,1000]],
  [[-width,0,-1000],[width,0,1000],[-width,0,1000]],
].map(vertices=>({vertices,normal:[0,1,0],distance:0}));
function fixture(){
  const track={sectorCount:6,collision:[],
    route:Array.from({length:6},(_,i)=>({position:[0,0,i*100],collisionIndices:[]})),
    drive:Array.from({length:5},(_,i)=>({position:[0,0,i*100+50],unknown:[0,0],links:[i+1,-1,-1,i-1]}))};
  const world={sectors:track.route.map(({position})=>({position,side:[1,0,0],forward:[0,0,1],
    fallback:{normal:[0,1,0],distance:0},triangles:{road:road(1000),land:[],extra:[]}}))};
  const collision=new NativeRailCollision(track,bounds),body={position:[0,0,450],sector:4,previousSector:4,
    waypoint:4,yaw:0,pitch:0,roll:0,bounds,matrix:[1,0,0,0,1,0,0,0,1],
    lateralSpeed:0,verticalSpeed:0,forwardSpeed:0,yawRate:0,pitchRate:0,rollRate:0};
  const motion={body,collision,ground:{wheels:[[-5,1,5],[5,1,5],[-5,1,-5],[5,1,-5]]
    .map(local=>({local,radius:1,position:[999,999,999],verticalSpeed:200,steeringAngle:400}))},
    controls:{throttle:100,brake:80,steering:50,handbrake:true},gear:3,rpm:9000,prepared:{},
    sampleGround:(x,y,z)=>sampleNativeTrack(world,body.sector,x,y,z).height};
  collision.bodies=[body];
  const pose=(index,extra={})=>({position:[0,0,index*100+50],sector:index,waypoint:index,yaw:0,
    distance:index,lapCount:0,finishArmed:false,...extra});
  const recovery={anchors:[pose(3),pose(2),pose(1)],reference:pose(4,{lapStartDistance:0})};
  return {track,world,motion,pose,recovery};
}
function block(state,pose,extra={}){
  const body={position:[...pose.position],sector:pose.sector,yaw:0,bounds,...extra};
  state.motion.collision.bodies.push(body);return body;
}

test('safe recovery requires full supported footprint and rejects invalid or environmental poses',()=>{
  const state=fixture(),pose=state.pose(2);
  assert.equal(isSafePlayerRecoveryPose(state,pose),true);
  for(const change of [{yaw:NaN},{sector:-1},{waypoint:999},{position:[0,Infinity,250]},
    {position:[0,25,250]},{sector:1}])assert.equal(isSafePlayerRecoveryPose(state,{...pose,...change}),false);
  state.track.drive[2].unknown[1]=50;
  assert.equal(isSafePlayerRecoveryPose(state,pose),false);
  state.track.drive[2].unknown[1]=0;
  for(const sector of state.world.sectors)sector.triangles.road=road(5);
  assert.equal(sampleNativeTrack(state.world,pose.sector,...pose.position).kind,'road');
  assert.equal(isSafePlayerRecoveryPose(state,pose),false,'center-only road must not admit unsupported corners');
});

test('clear current footprint is rejected when the short forward exit meets a live obstacle',()=>{
  const state=fixture(),pose=state.pose(1);
  block(state,{position:[0,0,190],sector:1},{bounds:{minX:-5,maxX:5,minZ:-5,maxZ:5}});
  assert.equal(isSafePlayerRecoveryPose(state,pose),false);
  state.motion.collision.bodies.pop();
  assert.equal(isSafePlayerRecoveryPose(state,pose),true);
});

test('newest occupied anchor is reselected without mutating history or blocking actors',()=>{
  const state=fixture(),obstacle=block(state,state.pose(3));
  const before=structuredClone({recovery:state.recovery,obstacle});
  const destination=selectPlayerRecoveryDestination(state);
  assert.equal(destination.waypoint,2);assert.equal(destination.recoveryDistance,2);
  assert.equal(destination.previousSector,2);assert.equal(destination.safetyFallback,true);
  assert.deepEqual({recovery:state.recovery,obstacle},before);
  destination.position[0]=999;
  assert.equal(state.recovery.anchors[1].position[0],0,'output never aliases the saved anchor');
});

test('selection rejects future, earlier-lap and pre-lap-start anchors and never shortcuts the lap',()=>{
  const state=fixture();
  state.recovery.reference.lapStartDistance=2;
  state.recovery.anchors=[state.pose(3,{distance:5}),state.pose(3,{lapCount:1}),
    state.pose(1),state.pose(2,{finishArmed:true})];
  const selected=selectPlayerRecoveryDestination(state);
  assert.equal(selected.waypoint,2);assert.equal(selected.recoveryFinishArmed,true);
  state.recovery.anchors=[];
  state.recovery.reference.lapStartDistance=3;
  assert.equal(selectPlayerRecoveryDestination(state).recoveryDistance,3);
  state.track.drive[3].unknown[1]=50;
  assert.deepEqual(selectPlayerRecoveryDestination(state),{blocked:true},'cannot search behind the current lap start');
  state.recovery.reference.lapStartDistance=4;
  assert.deepEqual(selectPlayerRecoveryDestination(state),{blocked:true});
});

test('unsafe searches remain blocked rather than moving into scenery or the trapped reference',()=>{
  const state=fixture();state.recovery.anchors=[state.pose(4)];
  const obstacle=block(state,state.pose(2),{bounds:{minX:-10000,maxX:10000,minZ:-10000,maxZ:10000}});
  assert.deepEqual(selectPlayerRecoveryDestination(state),{blocked:true});
  assert.deepEqual(state.motion.body.position,[0,0,450]);
  assert.deepEqual(obstacle.position,[0,0,250]);
});

test('reversed travel may return to a visited same-lap pose without awarding progress or a finish',()=>{
  const state=fixture();
  state.recovery.reference=state.pose(2,{position:[0,0,205],distance:-1,lapStartDistance:0});
  const anchor=state.pose(2,{position:[0,0,295],distance:0,finishArmed:true});
  state.recovery.anchors=[{...anchor,lapCount:1},anchor];
  const before=structuredClone(state.recovery);
  const selected=selectPlayerRecoveryDestination(state);
  assert.deepEqual(selected.position,anchor.position,'previously visited same-sector pose may be ahead');
  assert.equal(selected.recoveryDistance,-1,'return does not restore the reversed sector credit');
  assert.equal(selected.recoveryFinishArmed,false);
  assert.deepEqual(state.recovery,before);
  state.recovery.anchors=[{...anchor,lapCount:1}];
  assert.deepEqual(selectPlayerRecoveryDestination(state),{blocked:true},'other laps cannot authorize a return');
  state.recovery.anchors=[anchor];
  block(state,anchor);
  assert.deepEqual(selectPlayerRecoveryDestination(state),{blocked:true},'occupied history never becomes a forced placement');
  state.recovery.anchors=[];
  assert.deepEqual(selectPlayerRecoveryDestination(state),{blocked:true},'no authored forward fallback without history');
});

test('soft-lock rescue snapshots metadata, restores wheel state and rechecks an entering kart',()=>{
  const state=fixture(),{motion}=state,body=motion.body;
  const rescue=new NativeRescueController({...state,occupants:()=>motion.collision.bodies,
    playerSafety:{body,collision:motion.collision}});
  const entry=rescue.enqueue(motion,{softLock:state.recovery});
  state.recovery.anchors[0].position[0]=9000;
  assert.equal(entry.softLock.anchors[0].position[0],0);
  for(let tick=0;tick<21;tick++)rescue.step(.025);
  assert.equal(entry.relocated,true);assert.equal(body.waypoint,3);assert.equal(body.previousSector,body.sector);
  assert.equal(entry.destination.recoveryDistance,3);
  assert.deepEqual(motion.controls,{throttle:0,brake:0,steering:0,handbrake:false});
  assert.equal(motion.prepared,null);assert.equal(motion.rpm,0);assert.equal(motion.gear,0);
  for(const wheel of motion.ground.wheels){
    assert.equal(wheel.position[1],1);assert.equal(wheel.verticalSpeed,0);assert.equal(wheel.steeringAngle,0);
  }
  const intruder=block(state,{position:body.position,sector:body.sector});
  for(let tick=0;tick<19;tick++)rescue.step(.025);
  assert.equal(entry.finished,false);assert.equal(entry.safetyBlocked,true);
  for(let tick=0;tick<45&&!entry.finished;tick++)rescue.step(.025);
  assert.equal(entry.finished,true);assert.equal(entry.destination.waypoint,2);
  assert.equal(body.forwardSpeed,0);assert.equal(body.yawRate,0);
  assert.deepEqual(intruder.position,[0,0,350],'recovery never moves the blocking kart');
});

test('all six original tracks provide validated authored return roads with actual scenery and kart bounds',()=>{
  const read=name=>fs.readFileSync(new URL('../'+name,import.meta.url));
  const json=name=>JSON.parse(read(name));
  const config=json('public/assets/config.json'),manifest=json('public/assets/manifest.json'),cars=json('public/assets/cars.json');
  for(let index=0;index<6;index++){
    const track=json(`public/assets/tracks/etappe${index}.json`);
    const sim=new RaceSimulation({track,config,manifest,cars,random:new NativeRandom(0),
      physicsBytes:read('public/assets/physics/phys0.dat'),racerBytes:read('public/assets/racer-tables/cars0.dat')});
    const context={track,world:sim.world,motion:sim.motion};
    const safe=track.drive.map((_,waypoint)=>nativeRescueDestinationAtWaypoint(track,sim.world,waypoint))
      .filter(pose=>isSafePlayerRecoveryPose(context,pose));
    assert.ok(safe.length>20,`track ${index} must retain real safe roads, got ${safe.length}`);
    const reference=safe.at(-1),distance=1000;
    const anchors=safe.filter(pose=>pose.sector<reference.sector).reverse().map(pose=>({...pose,
      distance:distance-(reference.sector-pose.sector),lapCount:1,finishArmed:false}));
    const selected=selectPlayerRecoveryDestination({...context,recovery:{anchors,
      reference:{...reference,distance,lapCount:1,lapStartDistance:distance-track.route.length}}});
    assert.equal(selected.blocked,undefined,`track ${index}`);
    assert.equal(isSafePlayerRecoveryPose(context,selected),true);
    assert.ok(selected.recoveryDistance<=distance);
  }
});

test('Italy17/18 widen behind an empty twelve-sector window without crossing the lap start',()=>{
  const read=name=>fs.readFileSync(new URL('../'+name,import.meta.url));
  const json=name=>JSON.parse(read(name)),track=json('public/assets/tracks/etappe5.json');
  const sim=new RaceSimulation({track,config:json('public/assets/config.json'),manifest:json('public/assets/manifest.json'),
    cars:json('public/assets/cars.json'),character:2,difficulty:0,raceMode:0,random:new NativeRandom(0),
    physicsBytes:read('public/assets/physics/phys0.dat'),racerBytes:read('public/assets/racer-tables/cars0.dat')});
  const context={track,world:sim.world,motion:sim.motion};
  const poses=track.drive.map((_,index)=>nativeRescueDestinationAtWaypoint(track,sim.world,index));
  for(const sector of [17,18]){
    const pose=poses.find(pose=>pose.sector===sector);
    assert.ok(pose);
    const recovery={anchors:[],reference:{...pose,distance:40,lapCount:0,lapStartDistance:28}};
    assert.deepEqual(selectPlayerRecoveryDestination({...context,recovery}),{blocked:true});
    recovery.reference.lapStartDistance=0;
    const selected=selectPlayerRecoveryDestination({...context,recovery});
    assert.equal(selected.blocked,undefined);
    const behind=(sector-selected.sector+track.route.length)%track.route.length;
    assert.ok(behind>12&&behind<=40&&behind<track.route.length/2);
    assert.equal(selected.recoveryDistance,40-behind);
    assert.equal(isSafePlayerRecoveryPose(context,selected),true);
    assert.equal(selected.recoveryFinishArmed,false);
  }
});
