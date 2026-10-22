import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {nativeProjectileFacing} from '../src/simulation/native-projectile.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));
const track=JSON.parse(read('tracks/etappe3.json'));

test('authored France jump runs before player preparation, including inactive phase and absent weather',()=>{
  for(const countdown of [false,true]){
    const sim=new RaceSimulation({config,manifest,cars,track,random:new NativeRandom(0),countdown,
      difficulty:0,physicsBytes:read('physics/phys0.dat'),racerBytes:read('racer-tables/cars0.dat')});
    // A controlled original boundary state, not a control-only completion run.
    const body=sim.motion.body,waypoint=track.route[104].driveIndices[0];
    Object.assign(body,{sector:104,previousSector:103,waypoint,forwardSpeed:20,
      position:[...track.drive[waypoint].position]});
    const origin=track.drive[track.route[104].driveIndices[0]],
      next=track.drive[origin.links[0]];
    body.matrix=[1,0,0,0,1,0,next.position[0]-origin.position[0],0,next.position[2]-origin.position[2]];
    assert.equal(nativeProjectileFacing(track,body,{british:0,direction:0}),true);
    sim.weather=null;
    sim.motion.ground.wheels.forEach((wheel,i)=>{wheel.verticalSpeed=i-2;});
    let observed=false;
    sim.step({throttle:0,brake:0,steer:0,handbrake:0,bonus:0},.025,25,{
      beforePlayerPrepare:()=>{
        observed=true;
        assert.equal(body.forwardSpeed,20);
        assert.deepEqual(sim.motion.ground.wheels.map(wheel=>wheel.verticalSpeed),[273,274,275,276]);
      },
    });
    assert.equal(observed,true);
  }
});
