import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {copiedNPCPath,sampleCopiedNPCPath,createRouteTrafficForecast} from './helpers/private-route-traffic-forecast.mjs';
import {predictClosedLoop} from './helpers/private-closed-loop-route-traffic-driving.mjs';

test('copied NPC forecast follows authored corner and circuit wrap while retaining lateral offset',()=>{
  const positions=[[0,0,0],[0,0,100],[100,0,100],[100,0,0]];
  const track={drive:positions.map((position,i)=>({position,unknown:[0,0],links:[(i+1)%4,-1,-1,(i+3)%4]}))};
  const body={position:[10,5,50],x:10,y:5,z:50,yaw:4096,waypoint:0,forwardSpeed:10,lateralSpeed:0};
  const actor={body,state:{waypoint:1,priorities:[0,1,2]}},before=JSON.stringify({track,actor});
  const path=copiedNPCPath(track,actor);
  assert.deepEqual(sampleCopiedNPCPath(path,0),{position:[10,5,50],yaw:4096});
  const corner=sampleCopiedNPCPath(path,1);
  assert.deepEqual(corner.position,[50,5,90]);
  assert.ok(Math.abs(corner.yaw+1024)<1e-9);
  assert.deepEqual(sampleCopiedNPCPath(path,4).position,[10,5,50]);
  assert.equal(JSON.stringify({track,actor}),before);
});

test('route-aware collider prediction changes only copied NPC poses, leaves scenery and all live state intact',async()=>{
  const root=new URL('../public/assets/',import.meta.url),read=p=>fs.readFile(new URL(p,root)),json=async p=>JSON.parse(await read(p));
  const [config,manifest,cars,track,physicsBytes,racerBytes]=await Promise.all([
    json('config.json'),json('manifest.json'),json('cars.json'),json('tracks/etappe3.json'),read('physics/phys2.dat'),read('racer-tables/cars2.dat')]);
  const random=new NativeRandom(6),sim=new RaceSimulation({config,manifest,cars,track,physicsBytes,racerBytes,random,character:1,difficulty:2,raceMode:1});
  for(let now=25;now<=1500;now+=25)sim.step({analog:{throttle:1,brake:0,steer:0}},.025,now);
  const snapshot=()=>JSON.stringify({bodies:sim.physicalBodies.map(body=>({position:body.position,yaw:body.yaw,sector:body.sector,
    forwardSpeed:body.forwardSpeed,lateralSpeed:body.lateralSpeed,yawRate:body.yawRate})),states:sim.opponents.map(a=>a.state),
    random:random.state,contacts:sim.contactState,race:sim.race.snapshot()});
  const before=snapshot(),forecast=createRouteTrafficForecast(sim.motion,track,sim.opponents);
  const sceneryIndex=sim.physicalBodies.filter(x=>x!==sim.motion.body).findIndex(body=>body===sim.scenery.bodies[0]);
  const sceneryPose=[...forecast.collision.bodies[sceneryIndex].position];
  forecast.advance(1.2);
  assert.deepEqual(forecast.collision.bodies[sceneryIndex].position,sceneryPose);
  assert.equal(snapshot(),before);
  const line=track.route.map((r,sector)=>({sector,node:r.driveIndices[Math.floor(r.driveIndices.length/2)]}));
  line.push({sector:track.route.length,node:line[0].node});
  const options={frames:3,lookaheads:[.7],speeds:[75],offsets:[-30,0,30],opponents:sim.opponents};
  const result=predictClosedLoop(sim.motion,track,line,options);
  assert.deepEqual(predictClosedLoop(sim.motion,track,line,options),result);
  assert.equal(snapshot(),before);
  for(const key of ['throttle','brake','handbrake'])assert.ok(result.input[key]>=0&&result.input[key]<=1);
  assert.ok(Number.isFinite(result.input.steer)&&Math.abs(result.input.steer)<=1);
});
