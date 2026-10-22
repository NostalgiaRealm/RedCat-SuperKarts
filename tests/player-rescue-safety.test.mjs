import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {nativeRescueDestination} from '../src/simulation/native-rescue.js';
import {rescuePlacementClear,rescueRectanglesOverlap} from '../src/simulation/rescue-safety.js';
import {nativeRectangleOverlap} from '../src/simulation/native-collision.js';
import {updateNativeGround} from '../src/simulation/native-ground.js';

const read=path=>fs.readFileSync(new URL('../'+path,import.meta.url));
const json=path=>JSON.parse(read(path));
const config=json('public/assets/config.json'),manifest=json('public/assets/manifest.json'),
  cars=json('public/assets/cars.json');
function create(trackIndex){
  return new RaceSimulation({config,manifest,cars,track:json(`public/assets/tracks/etappe${trackIndex}.json`),
    physicsBytes:read('public/assets/physics/phys0.dat'),racerBytes:read('public/assets/racer-tables/cars0.dat'),
    random:new NativeRandom(0),character:0,difficulty:0,raceMode:0});
}
function capturedItaly(){
  const sim=create(5),fixture=json('evidence/race-completion/italy-native-rescue.json');
  const sample=json('evidence/race-completion/italy-all-rescue-trace.json').runs[0].samples.at(-1);
  for(const actor of sample.allBodies){
    const body=sim.actors[actor.id].body;
    body.position.splice(0,3,...actor.position);
    body.sector=body.previousSector=actor.sector;
    body.waypoint=actor.waypoint;
  }
  sim.motion.body.waypoint=490;
  return {sim,fixture};
}
function completeRescue(sim){
  const body=sim.motion.body,entry=sim.rescue.enqueue(sim.motion,{environment:true});
  let relocatedAt=null;
  for(let tick=1;tick<=200&&!entry.finished;tick++){
    sim.rescue.step(.025);
    if(entry.relocated)relocatedAt=tick*.025;
    sim.rescue.finishRender();
  }
  return {entry,relocatedAt,body};
}

test('captured Italy occupancy recovers to supported clear road after a bounded wait',()=>{
  const {sim}=capturedItaly(),body=sim.motion.body;
  const actorsBefore=sim.opponents.map(actor=>structuredClone(actor.body.position));
  const raceBefore=sim.race.snapshot();
  assert.deepEqual(nativeRescueDestination(sim.race.track,sim.world,body,{
    environment:true,occupants:sim.actors.map(actor=>actor.body)}),{blocked:true});
  const {entry,relocatedAt}=completeRescue(sim);
  assert.ok(entry.finished&&entry.safetyFallback);
  assert.ok(relocatedAt>=2.5&&relocatedAt<4,'native shrink then two seconds blocked before alternative');
  assert.notEqual(entry.destination.waypoint,514);
  assert.equal(rescuePlacementClear(sim.motion.collision,body,entry.destination),true);
  assert.deepEqual(sim.opponents.map(actor=>actor.body.position),actorsBefore,'never move blocking opponents');
  assert.deepEqual(sim.race.snapshot(),raceBefore,'rescue does not award laps or change timers');
  assert.equal(sim.rescue.get(body),undefined);
  assert.equal(body.forwardSpeed,5);
});

test('captured France return is rejected despite passing the native distance rule',()=>{
  const sim=create(3),capture=json('evidence/race-completion/france-native-rescue-overlap.json');
  for(const actor of capture.input.actors){
    const body=sim.actors[actor.id].body;
    Object.assign(body,{sector:actor.sector,previousSector:actor.sector,yaw:actor.yaw});
    body.position.splice(0,3,...actor.position);
  }
  const body=sim.motion.body;
  body.waypoint=438;
  const native=nativeRescueDestination(sim.race.track,sim.world,body,{
    environment:true,occupants:sim.actors.map(actor=>actor.body)});
  assert.equal(native.waypoint,471);
  assert.equal(rescuePlacementClear(sim.motion.collision,body,native),false);
  const {entry}=completeRescue(sim);
  assert.ok(entry.finished&&entry.safetyFallback);
  assert.notEqual(entry.destination.waypoint,471);
  assert.equal(rescuePlacementClear(sim.motion.collision,body,entry.destination),true);
  assert.equal(body.pitchRate,0);
});

test('a blocker leaving during the grace period preserves the original return',()=>{
  const {sim}=capturedItaly(),body=sim.motion.body;
  const entry=sim.rescue.enqueue(sim.motion,{environment:true});
  for(let tick=0;tick<40;tick++)sim.rescue.step(.025);
  assert.equal(entry.safetyBlocked,true);
  for(const actor of sim.opponents)actor.body.position[0]+=10000;
  for(let tick=0;tick<60&&!entry.finished;tick++)sim.rescue.step(.025);
  assert.equal(entry.finished,true);
  assert.equal(entry.destination.waypoint,514);
  assert.equal(entry.safetyFallback,undefined);
});

test('the safety check catches crossing rectangles with no corner inside either one',()=>{
  const a={minX:-60,maxX:60,minZ:-10,maxZ:10,position:[0,0,0],angle:0};
  const b={...a,angle:1024};
  assert.equal(nativeRectangleOverlap(a,b)||nativeRectangleOverlap(b,a),false);
  assert.equal(rescueRectanglesOverlap(a,b),true);
});

test('an entirely obstructed search never forces an unsafe placement',()=>{
  const {sim}=capturedItaly(),body=sim.motion.body,position=[...body.position];
  sim.motion.collision.candidates=()=>[{
    minX:-100000,maxX:100000,minZ:-100000,maxZ:100000,position:[0,0,0],angle:0,
  }];
  const {entry}=completeRescue(sim);
  assert.equal(entry.finished,false);
  assert.equal(entry.safetyBlocked,true);
  assert.deepEqual(body.position,position);
});

test('fallback initializes wheel world heights so the next ground update retains the new road',()=>{
  const {sim}=capturedItaly();
  sim.motion.ground.wheels.forEach(wheel=>{
    wheel.position=[-9999,9999,-9999];wheel.verticalSpeed=275;
  });
  const {entry,body}=completeRescue(sim);
  assert.equal(entry.safetyFallback,true);
  for(const wheel of sim.motion.ground.wheels){
    assert.equal(wheel.verticalSpeed,0);
    assert.equal(wheel.position[1],Math.fround(sim.motion.sampleGround(...wheel.position)+wheel.radius));
  }
  const relocatedY=body.y;
  updateNativeGround(body,sim.motion.ground,.025,sim.motion.sampleGround,{clock:sim.motion.groundClock});
  assert.ok(Math.abs(body.y-relocatedY)<25,'old wheel altitude must not pull the kart back to its previous height');
});

test('a kart entering during growth prevents retirement into an overlap',()=>{
  const {sim}=capturedItaly(),body=sim.motion.body;
  for(const actor of sim.opponents)actor.body.position[0]+=10000;
  const entry=sim.rescue.enqueue(sim.motion,{environment:true});
  for(let tick=0;tick<60&&!entry.relocated;tick++)sim.rescue.step(.025);
  assert.equal(entry.relocated,true);
  const blocker=sim.opponents[0].body;
  blocker.position.splice(0,3,...body.position);blocker.sector=body.sector;
  for(let tick=0;tick<19;tick++)sim.rescue.step(.025);
  sim.rescue.finishRender();
  assert.equal(entry.finished,false);
  assert.equal(entry.safetyBlocked,true);
  assert.equal(sim.rescue.get(body),entry);
  assert.equal(body.forwardSpeed,0,'do not release the player into the entering kart');
  blocker.position[0]+=10000;
  for(let tick=0;tick<80&&!entry.finished;tick++)sim.rescue.step(.025);
  assert.equal(entry.finished,true);
});
