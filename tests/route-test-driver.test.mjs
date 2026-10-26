import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {StarApproachPlanner,preferredRoadNodes} from './helpers/star-approach-planner.mjs';
import {RouteTestDriver} from './helpers/route-test-driver.mjs';
import {NativeSceneryBodies} from '../source/simulation/native-scenery-contact.js';
import {nativeRectangleSweep} from '../source/simulation/native-collision.js';
import {nativeTrigTable} from '../source/simulation/native-integrator.js';
import {createNativeInputState,nativeAnalogFromNormalized,updateNativeAnalogInput} from '../source/simulation/native-input.js';

const read=name=>JSON.parse(fs.readFileSync(new URL(`../public/assets/${name}`,import.meta.url)));
const config=read('config.json'),manifest=read('manifest.json');
test('test driver routes around the real England collision dummy',()=>{
  const track=read('tracks/etappe2.json');
  const obstacles=new NativeSceneryBodies({track,config,manifest}).bodies;
  const obstacle=obstacles.find(body=>body.placementIndex===120);
  const start=[-4743,0,3145],target={position:[-4933.98876953125,30,3500.346923828125]};
  const planner=new StarApproachPlanner(track,{obstacles});
  const plan=planner.plan(start,target);
  assert.ok(plan&&plan.points.length>1);
  const angle=Math.ceil(obstacle.yaw),{sin,cos}=nativeTrigTable(),i=(-angle)&4095;
  const moving={minX:-38,maxX:38,minZ:-38,maxZ:38,position:start,angle:0};
  const rect={...obstacle.bounds,position:obstacle.position,angle};
  const sweep=(a,b)=>{
    const dx=b[0]-a[0],dz=b[2]-a[2];
    return nativeRectangleSweep(rect,{...moving,position:a},
      [cos[i]*dx-sin[i]*dz,0,sin[i]*dx+cos[i]*dz]).fraction;
  };
  assert.ok(sweep(start,target.position)<1,'direct route hits the original solid box');
  let previous=start;
  for(const point of plan.points){
    assert.equal(sweep(previous,point),1,'planned segment clears original directed sweep');
    previous=point;
  }
});
test('narrow test-planner fallback reaches the Netherlands star pocket',()=>{
  const track=read('tracks/etappe0.json'),obstacles=new NativeSceneryBodies({track,config,manifest}).bodies;
  const start=[-2700,0,8500],target={position:[-2548.27001953125,75,8122.15625]};
  assert.equal(new StarApproachPlanner(track,{obstacles}).plan(start,target),null);
  const plan=new StarApproachPlanner(track,{obstacles,clearance:38}).plan(start,target);
  assert.ok(plan&&plan.points.length>=3);
  assert.ok(Math.hypot(plan.points.at(-1)[0]-target.position[0],
    plan.points.at(-1)[2]-target.position[2])<=55);
});
test('a stationary test driver gives forward input time between recovery attempts',()=>{
  const track=read('tracks/etappe0.json'),driver=new RouteTestDriver(track);
  const position=[...track.route[4].position];
  const body={position,x:position[0],z:position[2],sector:4,yaw:0,yawRate:0,forwardSpeed:0};
  for(let now=25;now<=5000;now+=25)driver.input(body,now,25);
  assert.equal(driver.recoveries,1);
  assert.equal(driver.telemetry.reversing,false);
  assert.ok(driver.stationaryMs<1500);
});
test('recorded Germany orbit reconnects through a clear road segment instead of chasing its stale corner',()=>{
  const fixture=JSON.parse(fs.readFileSync(new URL('../evidence/race-completion/germany-orbit-fixture.json',import.meta.url)));
  const track=read(`tracks/etappe${fixture.track}.json`);
  const driver=new RouteTestDriver(track,{
    railBounds:read('cars.json').cars[0].bodyBounds,
    obstacles:new NativeSceneryBodies({track,config,manifest}).bodies,
  });
  driver.egressPath=structuredClone(fixture.egressPath);
  let refreshed=false;
  for(const sample of fixture.samples){
    const position=Object.freeze([...sample.position]);
    const body=Object.freeze({position,x:position[0],y:position[1],z:position[2],
      sector:sample.sector,yaw:sample.yaw,yawRate:sample.yawRate,
      forwardSpeed:sample.speed,lateralSpeed:0});
    const before=driver.detourReplans??0;
    const input=driver.input(body,sample.timeMs,25);
    assert.ok(Object.values(input.analog).every(Number.isFinite));
    if((driver.detourReplans??0)>before){
      refreshed=true;
      assert.notDeepEqual(driver.telemetry.target,fixture.egressPath[0]);
      assert.equal(driver.clearSegment(body,driver.telemetry.target),true,
        'reconnection passes the original rail/scenery collision query');
    }
    if(!refreshed)assert.deepEqual(driver.telemetry.target,fixture.egressPath[0]);
  }
  assert.equal(refreshed,true);
  assert.equal(driver.recoveries,0,'the recorded kart is moving, so stationary recovery cannot detect this orbit');
});
test('a detour which continues getting closer is not discarded by a duration timeout',()=>{
  const track=read('tracks/etappe1.json'),driver=new RouteTestDriver(track);
  const target=[0,0,0],roadTarget=[100,0,0];
  let reconnectQueries=0;
  driver.clearSegment=()=>{reconnectQueries++;return true;};
  driver.egressPath=[target];
  for(let now=0;now<=20000;now+=1000){
    const position=[500-now/100,0,0],body={position,x:position[0],z:0};
    driver.refreshStalledDetour(body,now,roadTarget,[target,roadTarget]);
  }
  assert.deepEqual(driver.egressPath,[target]);
  assert.equal(driver.detourReplans??0,0);
  assert.equal(reconnectQueries,0,'elapsed time alone must not initiate a reconnect');
});
test('the test route chooses authored lanes beside Italy water while retaining the Germany raised bridge',()=>{
  const italy=read('tracks/etappe5.json'),germany=read('tracks/etappe1.json');
  const laneIndices=route=>[...route.driveIndices,...route.driveLeftIndices];
  const italyChoices=preferredRoadNodes(italy,laneIndices(italy.route[94]));
  assert.equal(italy.drive[491].unknown[1],50,'captured Italy entry is an environmental marker');
  assert.equal(italyChoices.includes(491),false);
  assert.deepEqual(italyChoices,[489,490,492,493,494],'retain the original adjacent road nodes');
  const italyDriver=new RouteTestDriver(italy);
  for(const [index,node]of italy.drive.entries()){
    const original=node.links.slice(0,3).filter(index=>index>=0);
    if(original.some(index=>italy.drive[index].unknown[1]!==50))
      assert.ok(italyDriver.links[index].every(index=>italy.drive[index].unknown[1]!==50));
  }
  const planner=new StarApproachPlanner(italy,{avoidEnvironment:true});
  const graph=planner.graph({position:italy.drive[491].position,goals:[italy.drive[489].position]});
  assert.ok(!graph.vertices.includes(italy.drive[491].position),
    'detour planning must not reintroduce the deliberately avoided water lane');
  const germanyDriver=new RouteTestDriver(germany);
  for(let sector=105;sector<=108;sector++){
    const original=laneIndices(germany.route[sector]);
    assert.ok(original.every(index=>germany.drive[index].unknown[1]===50));
    assert.deepEqual(preferredRoadNodes(germany,original),original,
      'marker50 alone must not remove the only authored bridge route');
    for(const index of original)assert.ok(germanyDriver.links[index].length>0);
  }
});
test('mirrored ordinary joystick commands preserve native integer steering, including half-step rounding',()=>{
  const track=read('tracks/etappe3.json'),position=Object.freeze([...track.route[4].position]);
  const regular=new RouteTestDriver(track,{steeringGain:0,dampingGain:1});
  const mirrored=new RouteTestDriver(track,{steeringGain:0,dampingGain:1,mirrored:true});
  let now=0;
  for(const yawRate of[-1,...Array.from({length:100},(_,i)=>(i*2-99)/100),0,1]){
    now+=25;
    const body=Object.freeze({position,x:position[0],z:position[2],sector:4,
      yaw:0,yawRate,forwardSpeed:10});
    // Each sample is independent; these are steering-domain probes, not a
    // stationary race replay that should initiate an escape manoeuvre.
    regular.previousPosition=mirrored.previousPosition=null;
    const a=regular.input(body,now,25),b=mirrored.input(body,now,25);
    const nativeA=updateNativeAnalogInput(createNativeInputState(),nativeAnalogFromNormalized(a.analog),false);
    const nativeB=updateNativeAnalogInput(createNativeInputState(),nativeAnalogFromNormalized(b.analog),true);
    assert.deepEqual(nativeB,nativeA,`native controls differ for steer ${yawRate}`);
  }
});
test('optional obstacle-free test policy retains rail-prechecked links and omits live detours',()=>{
  const track=read('tracks/etappe2.json');
  const options={railBounds:read('cars.json').cars[0].bodyBounds,
    obstacles:new NativeSceneryBodies({track,config,manifest}).bodies};
  const regular=new RouteTestDriver(track,options);
  const direct=new RouteTestDriver(track,{...options,obstacleAvoidance:false});
  assert.deepEqual(direct.links,regular.links);
  assert.deepEqual(direct.reverseLinks,regular.reverseLinks);
  assert.equal(direct.testCollision,null);
  assert.equal(direct.starPlanner,null);
  assert.equal(direct.narrowStarPlanner,null);
  assert.ok(regular.testCollision&&regular.starPlanner&&regular.narrowStarPlanner);
});
test('captured Netherlands contact selects the clear straight reverse before turning',()=>{
  const capture=JSON.parse(fs.readFileSync(new URL('../evidence/full-race-matrix/stars-nederland-easy-contact.json',import.meta.url)));
  const track=read('tracks/etappe0.json');
  const driver=new RouteTestDriver(track,{railBounds:read('cars.json').cars[0].bodyBounds,
    obstacles:new NativeSceneryBodies({track,config,manifest}).bodies});
  const position=Object.freeze([...capture.position]);
  const body=Object.freeze({position,x:position[0],y:position[1],z:position[2],
    sector:capture.sector,yaw:capture.yaw,yawRate:0,forwardSpeed:0,lateralSpeed:0,verticalSpeed:0});
  const clearance=direction=>driver.testCollision.sweep({...body,sourceBody:body,
    forwardSpeed:direction*10,yawRate:0},.2).fraction;
  assert.equal(clearance(1),0,'the original collision dummy blocks forward movement');
  assert.equal(clearance(-1),1,'the original sweep permits straight reverse movement');
  driver.previousPosition=position;
  driver.stationaryMs=1500;
  const input=driver.input(body,2000,25);
  assert.equal(driver.recoveryDirection,-1);
  assert.equal(input.throttle,0);
  assert.equal(input.brake,1);
  assert.equal(input.analog.steer,0,'straight steering prevents the front-corner turning trap');
  assert.equal(driver.input(body,3225,25).analog.steer,0);
  assert.equal(driver.straightEscapeUntil,3250);
  assert.equal(driver.reverseUntil,4500,'the existing total recovery duration stays bounded');
  assert.notEqual(driver.input(body,3250,25).analog.steer,0,'turning resumes after the initial straight phase');
});
