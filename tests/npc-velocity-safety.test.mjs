import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {captureNPCLinearVelocity,resetNewlyNonfiniteNPCVelocity} from '../source/simulation/npc-velocity-safety.js';
import {applyNativeAICatchup} from '../source/simulation/native-ai.js';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';

const read=path=>fs.readFileSync(new URL('../'+path,import.meta.url));
const json=path=>JSON.parse(read(path));
const failure=json('evidence/full-race-matrix/timed-england-nonfinite-deep.json').failure;
const finalFrame=failure.history.at(-1);
// The port recorded this history while it still ran gameplay at 24-bit.
const recorded={precision:24};

test('all119 captured finite catchup updates remain bit-identical without a safety intervention',()=>{
  for(let i=0;i<failure.history.length-1;i++){
    const body=structuredClone(failure.history[i].actors[0].body),before=captureNPCLinearVelocity(body);
    applyNativeAICatchup(body,{},2,-7,recorded);
    assert.equal(body.verticalSpeed,failure.history[i+1].actors[0].body.verticalSpeed);
    const nativeResult=structuredClone(body);
    assert.deepEqual(resetNewlyNonfiniteNPCVelocity(body,before),[]);
    assert.deepEqual(body,nativeResult);
  }
});

test('the actual valid-input overflow resets only its newly nonfinite vertical component',()=>{
  assert.ok(Object.values(finalFrame.input.analog).every(Number.isFinite));
  const body=structuredClone(finalFrame.actors[0].body),before=captureNPCLinearVelocity(body);
  const state=structuredClone(finalFrame.actors[0].state);
  applyNativeAICatchup(body,state,2,-7,recorded);
  assert.equal(body.verticalSpeed,Infinity,'the original callback itself still overflows');
  const nativeResult=structuredClone(body),stateBefore=structuredClone(state);
  assert.deepEqual(resetNewlyNonfiniteNPCVelocity(body,before),[{
    component:'verticalSpeed',previous:3.3529011546832445e38,rejected:'Infinity',replacement:0,
  }]);
  assert.deepEqual(body,{...nativeResult,verticalSpeed:0});
  assert.deepEqual(state,stateBefore,'the safety exception never alters AI state');
});

test('the guard preserves signed zero, every finite extreme, and already-invalid inputs',()=>{
  const body={lateralSpeed:-0,verticalSpeed:Math.fround(3.4028234663852886e38),forwardSpeed:-17,
    yawRate:Infinity,position:[1,2,3]};
  const before=captureNPCLinearVelocity(body),unchanged=structuredClone(body);
  assert.deepEqual(resetNewlyNonfiniteNPCVelocity(body,before),[]);
  assert.deepEqual(body,unchanged);
  const invalid={lateralSpeed:NaN,verticalSpeed:Infinity,forwardSpeed:-Infinity};
  assert.deepEqual(resetNewlyNonfiniteNPCVelocity(invalid,captureNPCLinearVelocity(invalid)),[]);
  assert.ok(Number.isNaN(invalid.lateralSpeed));
  assert.equal(invalid.verticalSpeed,Infinity);
  assert.equal(invalid.forwardSpeed,-Infinity);
});

test('composition exposes the correction before integration without changing race progress or AI state',()=>{
  const sim=new RaceSimulation({config:json('public/assets/config.json'),
    manifest:json('public/assets/manifest.json'),cars:json('public/assets/cars.json'),
    track:json('public/assets/tracks/etappe2.json'),physicsBytes:read('public/assets/physics/phys2.dat'),
    racerBytes:read('public/assets/racer-tables/cars2.dat'),random:new NativeRandom(0),
    character:1,difficulty:2,raceMode:1});
  const actor=sim.opponents[0],originalPrepare=actor.prepare.bind(actor);
  actor.body.verticalSpeed=finalFrame.actors[0].body.verticalSpeed;
  let nativeState,preparedPlanar;
  actor.prepare=(dt,options)=>{
    originalPrepare(dt,options);
    // Reproduce the captured native catchup boundary in a bounded full frame.
    // The full ordinary-control replay is retained separately in evidence.
    actor.body.verticalSpeed=finalFrame.actors[0].body.verticalSpeed;
    applyNativeAICatchup(actor.body,actor.state,2,-7);
    nativeState=structuredClone(actor.state);
    preparedPlanar=[actor.body.lateralSpeed,actor.body.forwardSpeed];
  };
  let observed=false;
  const events=sim.step(finalFrame.input,.025,25,{afterOpponentPrepare:(prepared,index)=>{
    if(index!==0)return;
    observed=true;
    assert.equal(prepared.body.verticalSpeed,0);
    assert.deepEqual([prepared.body.lateralSpeed,prepared.body.forwardSpeed],preparedPlanar);
    assert.deepEqual(prepared.state,nativeState);
  }});
  assert.equal(observed,true);
  assert.equal(sim.velocitySafetyCorrections,1);
  assert.equal(events.filter(event=>event.type==='npc-velocity-safety').length,1);
  assert.equal(sim.race.lapCount,0);
  assert.equal(actor.state.laps,0);
  assert.ok([...actor.body.position,actor.body.verticalSpeed].every(Number.isFinite));
});
