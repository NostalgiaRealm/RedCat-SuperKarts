import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {copyPlayerForRailForecast,advancePrivateRailFrame} from './helpers/private-native-contact-forecast.mjs';
const root=new URL('../public/assets/',import.meta.url);
const read=path=>fs.readFile(new URL(path,root)),json=async path=>JSON.parse(await read(path));

test('private contact forecast resolves actual paired contacts without changing any source body, callbacks or race state',async()=>{
  const [config,manifest,cars,track,physicsBytes,racerBytes]=await Promise.all([
    json('config.json'),json('manifest.json'),json('cars.json'),json('tracks/etappe3.json'),
    read('physics/phys2.dat'),read('racer-tables/cars2.dat')]);
  const random=new NativeRandom(6);
  const sim=new RaceSimulation({config,manifest,cars,track,physicsBytes,racerBytes,
    random,character:1,difficulty:2,raceMode:1});
  const motion=sim.motion,opponent=sim.opponents[0].body;
  // Isolated unit fixture only: approach a slower body along a straight axis.
  // The full-race runner never sets a body pose or velocity.
  motion.body.yaw=0;motion.body.forwardSpeed=60;motion.body.ignoreRails=true;
  opponent.position=[motion.body.x,motion.body.y,motion.body.z+120];
  opponent.yaw=0;opponent.forwardSpeed=25;opponent.lateralSpeed=0;
  opponent.sector=motion.body.sector;
  motion.collision.bodies=[motion.body,opponent];
  let callbacks=0;
  motion.body.onCollision=opponent.onCollision=()=>callbacks++;
  const snapshot=()=>JSON.stringify({actors:sim.actors.map(actor=>({
    body:actor.body,snapshot:actor.snapshot(),ground:actor.ground,controls:actor.controls,events:actor.events,
  })),race:sim.race.snapshot(),random:random.state,contact:sim.contactState,sharedAI:sim.sharedAI});
  const before=snapshot(),forecast=copyPlayerForRailForecast(motion);
  assert.notEqual(forecast.body,motion.body);
  assert.notEqual(forecast.collision.bodies[1],opponent);
  for(let frame=0;frame<24;frame++)advancePrivateRailFrame(forecast,{throttle:1,brake:0,steer:0,handbrake:0});
  assert.ok(forecast.dynamicContacts>0,'fixture must execute paired native contact responses');
  assert.ok(forecast.dynamicImpulse>0,'fixture must apply a nonzero paired impulse');
  assert.notEqual(forecast.collision.bodies[1].forwardSpeed,opponent.forwardSpeed);
  assert.equal(snapshot(),before,'no live body, wheels, controls, events, timer, RNG or AI state may change');
  assert.equal(callbacks,0);
  assert.throws(()=>forecast.collision.resolve(forecast.body,{
    firstBody:forecast.body,secondBody:opponent,point:[0,0,0],normal:[0,0,-1],
  }),/never resolve against a source body/);
});
