import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';

const read=path=>fs.readFileSync(new URL('../'+path,import.meta.url));
const json=path=>JSON.parse(read(path));
const config=json('public/assets/config.json'),manifest=json('public/assets/manifest.json'),
  cars=json('public/assets/cars.json');

test('the player callback reads the previous tick\'s scaled rescue matrix, and the last one once after retiring',()=>{
  const sim=new RaceSimulation({config,manifest,cars,track:json('public/assets/tracks/etappe0.json'),
    physicsBytes:read('public/assets/physics/phys0.dat'),racerBytes:read('public/assets/racer-tables/cars0.dat'),
    random:new NativeRandom(0),character:0,difficulty:0,raceMode:0});
  const body=sim.motion.body,input={throttle:1,brake:0,steer:0,handbrake:0,bonus:0};
  const prepare=sim.motion.prepare.bind(sim.motion);
  let received;
  sim.motion.prepare=(buttons,dt,options)=>{received=options.matrix;return prepare(buttons,dt,options);};
  let now=0;
  const step=()=>{now+=25;sim.step(input,.025,now);};
  for(let i=0;i<8;i++)step();
  assert.equal(received,undefined);
  const entry=sim.rescue.enqueue(sim.motion,{environment:true});
  let previous=[...entry.matrix],ticks=0;
  // 0x4325b0 runs before 0x491d30 rebuilds the body and 0x42f618 scales it
  // again, so each callback sees the matrix the previous tick scaled.
  while(sim.rescue.get(body)){
    step();ticks++;
    assert.deepEqual(received,previous,`tick ${ticks}`);
    previous=[...entry.matrix];
    assert.ok(ticks<200,'rescue finishes');
  }
  assert.equal(entry.finished,true);
  assert.equal(entry.scale,Math.fround(1.2));
  step();
  assert.deepEqual(received,previous,'last 1.2-scaled matrix lasts one more callback');
  step();
  assert.equal(received,undefined,'then the rebuilt body matrix');
});
