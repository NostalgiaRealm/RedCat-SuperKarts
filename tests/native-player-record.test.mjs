import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));
const create=(raceMode,countdown)=>new RaceSimulation({config,manifest,cars,raceMode,countdown,
  track:JSON.parse(read('tracks/etappe0.json')),random:new NativeRandom(0),
  physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat')});
function trace(sim){
  const log=[],random=sim.pickups.random,next=random.next.bind(random);
  let inRecord=false,inPickups=false;
  random.next=()=>{if(inRecord)log.push(inPickups?'pickups':'player');return next();};
  const create=sim.createPlayerRecord.bind(sim);
  sim.createPlayerRecord=()=>{inRecord=true;try{create();}finally{inRecord=false;}};
  const step=sim.pickups.step.bind(sim.pickups);
  sim.pickups.step=(...args)=>{inPickups=true;try{return step(...args);}finally{inPickups=false;}};
  const effect=sim.combat.prepareEffect.bind(sim.combat);
  sim.combat.prepareEffect=(...args)=>{log.push('effect');return effect(...args);};
  return log;
}
const input={throttle:1,brake:0,steer:0,handbrake:0,bonus:0};

test('0x435a30 draws once, from the first pickup check during the countdown in pickup races',()=>{
  for(const raceMode of [0,2,3]){
    const sim=create(raceMode,true),log=trace(sim);
    assert.equal(sim.playerRecordCreated,false);
    sim.step(input,.025,25);
    assert.equal(sim.movementActive,false,'still counting down');
    assert.equal(sim.playerRecordCreated,true,`race type ${raceMode}`);
    assert.deepEqual(log,['pickups']);
    for(let i=2;i<=40;i++)sim.step(input,.025,i*25);
    assert.equal(log.filter(entry=>entry!=='effect').length,1);
  }
});

test('time trials have no pickups, so 0x432f30 draws on the first active update before the hit effect',()=>{
  const waiting=create(1,true);trace(waiting);
  for(let i=1;i<=10;i++)waiting.step(input,.025,i*25);
  assert.equal(waiting.movementActive,false);
  assert.equal(waiting.playerRecordCreated,false);
  const sim=create(1,false),log=trace(sim);
  sim.step(input,.025,25);
  assert.deepEqual(log,['player','effect']);
  for(let i=2;i<=40;i++)sim.step(input,.025,i*25);
  assert.equal(log.filter(entry=>entry==='player').length,1);
});
