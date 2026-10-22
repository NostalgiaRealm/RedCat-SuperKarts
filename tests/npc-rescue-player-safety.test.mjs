import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {nativeRescueDestination} from '../src/simulation/native-rescue.js';
import {rescuePlacementOverlapsPlayer} from '../src/simulation/rescue-safety.js';

const read=file=>fs.readFileSync(new URL('../'+file,import.meta.url));
const json=file=>JSON.parse(read(file));
const capture=json('evidence/full-race-matrix/normal-germany-native-rescue-overlap.json').input;
function setup(){
  const sim=new RaceSimulation({config:json('public/assets/config.json'),
    manifest:json('public/assets/manifest.json'),cars:json('public/assets/cars.json'),
    track:json('public/assets/tracks/etappe1.json'),physicsBytes:read('public/assets/physics/phys1.dat'),
    racerBytes:read('public/assets/racer-tables/cars1.dat'),random:new NativeRandom(0),character:0,difficulty:1});
  for(const actor of capture.actors){
    const body=sim.actors[actor.id].body;
    body.position.splice(0,3,...actor.position);
    Object.assign(body,{yaw:actor.yaw,sector:actor.sector,previousSector:actor.sector,waypoint:actor.waypoint});
  }
  const npc=sim.opponents[0],player=sim.motion.body;
  npc.body.waypoint=417;
  npc.body.position.splice(0,3,...sim.race.track.drive[417].position);
  const destination=nativeRescueDestination(sim.race.track,sim.world,npc.body,
    {environment:true,occupants:sim.actors.map(actor=>actor.body)});
  assert.equal(destination.waypoint,425,'original planar clearance permits the captured return');
  assert.equal(rescuePlacementOverlapsPlayer(sim.motion.collision,npc.body,destination,player),true);
  return {sim,npc,player,destination};
}
const tick=sim=>{sim.rescue.step(.025);sim.rescue.finishRender();};

test('captured Germany NPC waits instead of materializing inside the player, then keeps its native return',()=>{
  const {sim,npc,player,destination}=setup();
  const origin=[...npc.body.position],playerBefore=[...player.position],raceBefore=sim.race.snapshot();
  const entry=sim.rescue.enqueue(npc,{environment:true});
  for(let i=0;i<160;i++)tick(sim);
  assert.equal(entry.finished,false);
  assert.equal(entry.playerOverlapBlocked,true);
  assert.ok(sim.rescue.playerOverlapDeferrals>0);
  assert.deepEqual(npc.body.position,origin);
  assert.deepEqual(player.position,playerBefore);
  assert.deepEqual(sim.race.snapshot(),raceBefore,'waiting does not alter race results or clocks');
  player.position[0]+=1000;
  for(let i=0;i<80&&!entry.finished;i++)tick(sim);
  assert.equal(entry.finished,true);
  assert.equal(entry.destination.waypoint,425);
  assert.deepEqual(npc.body.position,destination.position);
  assert.equal(entry.safetyFallback,undefined);
  assert.equal(npc.state.blockRecovery,false);
});

test('NPC overlap with a different NPC retains original clearance when the player is absent',()=>{
  const {sim,npc,player,destination}=setup();
  const blocker=sim.opponents[1].body;
  blocker.position.splice(0,3,...player.position);blocker.yaw=player.yaw;
  player.position[0]+=1000;
  const entry=sim.rescue.enqueue(npc,{environment:true});
  for(let i=0;i<50&&!entry.finished;i++)tick(sim);
  assert.equal(entry.finished,true);
  assert.equal(sim.rescue.playerOverlapDeferrals,0);
  assert.deepEqual(npc.body.position,destination.position);
});

test('an incoming player during NPC growth prevents retirement until the original return is clear again',()=>{
  const {sim,npc,player}=setup(),overlapPosition=[...player.position];
  player.position[0]+=1000;
  const entry=sim.rescue.enqueue(npc,{environment:true});
  for(let i=0;i<21;i++)tick(sim);
  assert.equal(entry.relocated,true);
  player.position.splice(0,3,...overlapPosition);
  for(let i=0;i<20;i++)tick(sim);
  assert.equal(entry.finished,false);
  assert.equal(entry.playerOverlapBlocked,true);
  assert.ok(sim.rescue.get(npc.body));
  player.position[0]+=1000;
  for(let i=0;i<80&&!entry.finished;i++)tick(sim);
  assert.equal(entry.finished,true);
  assert.equal(entry.destination.waypoint,425);
});
