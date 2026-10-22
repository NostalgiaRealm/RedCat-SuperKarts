import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {predictClosedLoop} from './helpers/private-closed-loop-offset-driving.mjs';
const root=new URL('../public/assets/',import.meta.url),read=p=>fs.readFile(new URL(p,root));
const json=async p=>JSON.parse(await read(p));
test('private closed-loop controller returns bounded ordinary input without mutating any racer or collision state',async()=>{
  const [config,manifest,cars,track,physicsBytes,racerBytes]=await Promise.all([
    json('config.json'),json('manifest.json'),json('cars.json'),json('tracks/etappe2.json'),read('physics/phys2.dat'),read('racer-tables/cars2.dat')]);
  const random=new NativeRandom(0),sim=new RaceSimulation({config,manifest,cars,track,physicsBytes,racerBytes,random,character:1,difficulty:2,raceMode:1});
  for(let now=25;now<=1500;now+=25)sim.step({analog:{throttle:1,brake:0,steer:0}},.025,now);
  const line=track.route.map((r,sector)=>({sector,node:r.driveIndices[Math.floor(r.driveIndices.length/2)]}));line.push({sector:track.route.length,node:line[0].node});
  const snapshot=()=>JSON.stringify({bodies:sim.actors.map(a=>({position:a.body.position,yaw:a.body.yaw,lateralSpeed:a.body.lateralSpeed,forwardSpeed:a.body.forwardSpeed,verticalSpeed:a.body.verticalSpeed,yawRate:a.body.yawRate})),random:random.state,contact:sim.contactState,race:sim.race.snapshot()});
  const before=snapshot();
  const result=predictClosedLoop(sim.motion,track,line,{frames:2,lookaheads:[.7],speeds:[75],offsets:[-30,0,30]});
  assert.equal(snapshot(),before);
  for(const key of ['throttle','brake','handbrake'])assert.ok(result.input[key]>=0&&result.input[key]<=1,key);
  assert.ok(Number.isFinite(result.input.steer)&&Math.abs(result.input.steer)<=1);
  assert.deepEqual(predictClosedLoop(sim.motion,track,line,{frames:2,lookaheads:[.7],speeds:[75],offsets:[-30,0,30]}),result);
  assert.equal(snapshot(),before);
});
