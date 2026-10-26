import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {createTrafficForecast,predictClosedLoop} from './helpers/private-closed-loop-traffic-driving.mjs';

const root=new URL('../public/assets/',import.meta.url),read=p=>fs.readFile(new URL(p,root));
const json=async p=>JSON.parse(await read(p));
const assets=Promise.all([
  json('config.json'),json('manifest.json'),json('cars.json'),json('tracks/etappe3.json'),
  read('physics/phys2.dat'),read('racer-tables/cars2.dat'),
]);
const randoms=new WeakMap();
const create=async()=>{
  const [config,manifest,cars,track,physicsBytes,racerBytes]=await assets;
  const random=new NativeRandom(6);
  const sim=new RaceSimulation({config,manifest,cars,track,physicsBytes,racerBytes,
    random,character:1,difficulty:2,raceMode:1});
  randoms.set(sim,random);
  return sim;
};
const snapshot=sim=>JSON.stringify({
  bodies:sim.physicalBodies.map(body=>({position:body.position,yaw:body.yaw,sector:body.sector,
    forwardSpeed:body.forwardSpeed,lateralSpeed:body.lateralSpeed,yawRate:body.yawRate})),
  random:randoms.get(sim).state,contact:sim.contactState,race:sim.race.snapshot(),
});

test('private traffic prediction moves only its own copied obstacle poses',async()=>{
  const sim=await create(),other=sim.opponents[0].body;
  other.yaw=0;other.forwardSpeed=10;other.lateralSpeed=2;other.yawRate=.25;
  const before=snapshot(sim),position=[...other.position],index=sim.physicalBodies.filter(x=>x!==sim.motion.body).indexOf(other);
  const forecast=createTrafficForecast(sim.motion);
  assert.notEqual(forecast.collision.bodies,sim.motion.collision.bodies);
  forecast.advance(1);
  const copied=forecast.collision.bodies[index];
  assert.deepEqual(copied.position,[position[0]+20,position[1],position[2]+100]);
  assert.equal(copied.yaw,.25*2048/Math.PI);
  forecast.advance(0);
  assert.deepEqual(copied.position,position);
  assert.equal(snapshot(sim),before);
  assert.ok(!forecast.collision.bodies.includes(sim.motion.body));
});

test('moving-traffic forecast supplies deterministic bounded inputs without touching live race state',async()=>{
  const sim=await create();
  for(let now=25;now<=1000;now+=25)sim.step({analog:{throttle:1,brake:0,steer:0}},.025,now);
  const track=sim.motion.collision.track;
  const line=track.route.map((r,sector)=>({sector,node:r.driveIndices[Math.floor(r.driveIndices.length/2)]}));
  line.push({sector:track.route.length,node:line[0].node});
  const before=snapshot(sim),options={frames:3,lookaheads:[.7],speeds:[75],offsets:[-30,0,30]};
  const first=predictClosedLoop(sim.motion,track,line,options);
  assert.deepEqual(predictClosedLoop(sim.motion,track,line,options),first);
  assert.equal(snapshot(sim),before);
  for(const key of ['throttle','brake','handbrake'])assert.ok(first.input[key]>=0&&first.input[key]<=1);
  assert.ok(Number.isFinite(first.input.steer)&&Math.abs(first.input.steer)<=1);
});
