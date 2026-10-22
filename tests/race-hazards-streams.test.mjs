import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {createNativeSceneryRotations} from '../src/simulation/native-scenery-hazards.js';
const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));
const make=(id,options={})=>new RaceSimulation({config,manifest,cars,track:JSON.parse(read(`tracks/etappe${id}.json`)),
  random:new NativeRandom(0),physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat'),...options});
const input={throttle:1,brake:0,steer:0,handbrake:0,bonus:0};

test('headless and browser-supplied construction rotations consume the same original random phases',()=>{
  const track=JSON.parse(read('tracks/etappe0.json')),random=new NativeRandom(0);
  const rotationStates=createNativeSceneryRotations(track,config,random);
  const browser=make(0,{random,rotationStates}),headless=make(0);
  assert.equal(browser.pickups.random.state,headless.pickups.random.state);
  assert.deepEqual([...browser.rotationStates],[...headless.rotationStates]);
  assert.equal(browser.sceneryHazards.byPlacement.get([...rotationStates.keys()].find(index=>
    track.placements[index].type===43)).angles,rotationStates.get([...rotationStates.keys()].find(index=>
    track.placements[index].type===43)).angles);
});

test('original hazard registration, cached-player prop callback and post-movement squash binding',()=>{
  const sim=make(0),hazard=sim.sceneryHazards.objects.find(object=>object.type===44);
  assert.deepEqual(sim.squash.entries.slice(0,sim.actors.length).map(entry=>entry.body),
    [sim.motion.body,...sim.opponents.map(actor=>actor.body)]);
  sim.playerHudPosition=[...hazard.position];
  sim.motion.body.sector=hazard.sector;
  const before=hazard.matrix[4];
  sim.step(input,.025,25,{afterSceneryPrepare:()=>{
    assert.equal(sim.squash.find(hazard).active,true);
    assert.equal(sim.squash.find(sim.motion.body).active,false,'type44 requests itself');
    assert.notEqual(hazard.matrix[4],before);
  }});
  assert.equal(sim.sceneryObjects.get(hazard.placementIndex),hazard);
  const player=sim.motion.body;
  sim.squash.trigger(player,sim.nativeTickMs);
  sim.step(input,.025,50,{beforeBonuses:()=>{
    assert.ok(player.forwardSpeed<=sim.squash.settings.speedLimit);
    assert.ok(player.matrix[4]<.5,'post-integration matrix retains source flattening');
  }});
});

test('turbo and rocket callbacks bind original streams and raw deadline restores baseline',()=>{
  const sim=make(0),player=sim.actors.length-1;
  assert.ok(sim.streams.ribbons.some(entry=>entry.body===sim.motion.body));
  sim.combat.onTurbo(player,3);
  assert.equal(sim.streamTurboTimes[player],60000);
  for(let tick=1;tick<=8;tick++)sim.step(input,.025,tick*25);
  assert.ok(sim.streamFrames.jets.length>0);assert.ok(sim.streamFrames.ribbons.length>0);
  const shot={type:1,level:1,position:[0,20,0],matrix:[1,0,0,0,1,0,0,0,1],yaw:0};
  sim.combat.onProjectileState(shot,2);
  assert.ok(sim.streams.ribbons.some(entry=>entry.body===shot));
  sim.combat.onProjectileState(shot,1);
  assert.ok(!sim.streams.ribbons.some(entry=>entry.body===shot));
  sim.step(input,.025,5000);assert.equal(sim.streamTurboTimes[player],60000);
  sim.step(input,.025,5025);assert.equal(sim.streamTurboTimes[player],0);
});
