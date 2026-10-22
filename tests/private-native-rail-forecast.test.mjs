import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs/promises';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {nativeAnalogFromNormalized} from '../src/simulation/native-input.js';
import {copyPlayerForRailForecast,advancePrivateRailFrame} from './helpers/private-native-rail-forecast.mjs';
const root=new URL('../public/assets/',import.meta.url),read=p=>fs.readFile(new URL(p,root)),json=async p=>JSON.parse(await read(p));
test('private rail forecast matches original player step ordering through real rail contacts without mutating source',async()=>{
  const [config,manifest,cars,track,physicsBytes,racerBytes]=await Promise.all([
    json('config.json'),json('manifest.json'),json('cars.json'),json('tracks/etappe3.json'),read('physics/phys2.dat'),read('racer-tables/cars2.dat')]);
  const random=new NativeRandom(6),sim=new RaceSimulation({config,manifest,cars,track,physicsBytes,racerBytes,random,character:1,difficulty:2,raceMode:1});
  const motion=sim.motion;
  // Isolated real-track rail kernel: dynamic actors are outside this test.
  motion.collision.bodies=[];motion.mirrored=false;
  const snapshot=()=>JSON.stringify({motion:motion.snapshot(),ground:motion.ground,clock:motion.groundClock.delta,
    controls:motion.controls,contact:motion.collision.contactState,random:random.state});
  let contacts=0,contactFrames=0;
  for(let frame=0;frame<160;frame++){
    const before=snapshot(),forecast=copyPlayerForRailForecast(motion);
    const input={throttle:1,brake:0,steer:.6,handbrake:0};
    advancePrivateRailFrame(forecast,input);
    assert.equal(snapshot(),before,'forecast may not change actual body, wheels, clock, controls, impulse or RNG');
    motion.prepare({},.025,{analog:nativeAnalogFromNormalized(input)});motion.integrate();
    assert.deepEqual(forecast.snapshot(),motion.snapshot());
    assert.deepEqual(forecast.ground,motion.ground);
    assert.equal(forecast.groundClock.delta,motion.groundClock.delta);
    if(forecast.railContacts){contacts+=forecast.railContacts;contactFrames++;}
  }
  assert.ok(contacts>0,'the comparison must actually execute original rail responses');
  assert.ok(contactFrames>1,'the recurrence must continue after contact');
});

test('private dynamic contact aborts before any real opposing body or callback can be changed',()=>{
  const body={position:[0,0,0],matrix:[1,0,0,0,1,0,0,0,1]},other={position:[2,0,0],yaw:0,forwardSpeed:12};
  let callbacks=0;
  body.onCollision=other.onCollision=()=>callbacks++;
  const motion={body,controls:{},upgrades:{},ground:{wheels:[]},groundClock:{delta:.025},
    collision:{bodies:[body,other],sample(b){return{contact:{firstBody:b,secondBody:this.bodies[0]}}}}};
  const copy=copyPlayerForRailForecast(motion),before=JSON.stringify(other);
  assert.notEqual(copy.collision.bodies[0],other);
  assert.throws(()=>copy.collision.sample(copy.body,.025),/Private forecast reached another body/);
  assert.equal(JSON.stringify(other),before);
  assert.equal(callbacks,0);
});
