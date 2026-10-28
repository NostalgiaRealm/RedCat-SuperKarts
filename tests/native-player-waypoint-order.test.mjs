import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {nearestNativeAIWaypoint} from '../source/simulation/native-ai.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));

test('0x491d30 selects the player waypoint after the sector and before the ground callback',()=>{
  const sim=new RaceSimulation({config,manifest,cars,track:JSON.parse(read('tracks/etappe0.json')),
    random:new NativeRandom(0),physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat')});
  const motion=sim.motion,body=motion.body,order=[];
  let integrating=false,selected=null;
  const integrate=motion.integrate.bind(motion),sample=motion.sampleGround,insert=sim.occupancy.insert.bind(sim.occupancy);
  motion.integrate=()=>{integrating=true;try{return integrate();}finally{integrating=false;}};
  motion.sampleGround=(...args)=>{if(integrating&&order.at(-1)!=='ground')order.push('ground');return sample(...args);};
  sim.occupancy.insert=(target,options)=>{
    if(integrating&&target===body){
      order.push('insert');
      selected={sector:body.sector,position:[...body.position]};
    }
    return insert(target,options);
  };
  const input={throttle:1,brake:0,steer:0,handbrake:0,bonus:0};
  for(let i=1;i<=80;i++){
    order.length=0;sim.step(input,.025,i*25);
    assert.deepEqual(order,['insert','ground'],`update ${i}`);
    assert.equal(body.waypoint,nearestNativeAIWaypoint(sim.race.track,{sector:selected.sector,position:selected.position},{side:-1}));
  }
  assert.equal(sim.occupancy.membership.get(body),body.waypoint);
});
