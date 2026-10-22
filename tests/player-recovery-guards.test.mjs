import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {nativeBonusOverlap} from '../src/simulation/native-bonus.js';
import {selectPlayerRecoveryDestination} from '../src/simulation/player-recovery-position.js';

const read=name=>fs.readFileSync(new URL('../public/assets/'+name,import.meta.url));
const json=name=>JSON.parse(read(name));
const config=json('config.json'),manifest=json('manifest.json'),cars=json('cars.json');
function create(raceMode=0){
  return new RaceSimulation({config,manifest,cars,track:json('tracks/etappe0.json'),
    physicsBytes:read('physics/phys0.dat'),racerBytes:read('racer-tables/cars0.dat'),
    random:new NativeRandom(0),raceMode});
}

// Synthetic boundary fixtures, not control-only driving or native physics proof:
// keep just the player's integration stationary while all surrounding production
// recovery/retirement/pickup composition runs normally.
function holdPlayer(sim){
  sim.motion.integrate=()=>{
    sim.motion.prepared=null;
    sim.motion.body.previousSector=sim.motion.body.sector;
    sim.motion.ground.groundCount=4;
    sim.motion.ground.playerContact=true;
  };
  sim.motion.ground.groundCount=4;
  let tick=0;
  return input=>{
    const events=sim.step(input,.025,++tick*25);
    for(const actor of sim.actors)if(actor.animationEvents)actor.animationEvents.length=0;
    return events;
  };
}

test('unavailable recovery destination leaves a trapped fixture visible and controllable through retries',()=>{
  const sim=create(),step=holdPlayer(sim),body=sim.motion.body;
  const before={position:[...body.position],yaw:body.yaw,matrix:[...body.matrix]};
  const recovery=sim.playerRecovery.request(body,sim.race);
  assert.deepEqual(selectPlayerRecoveryDestination({track:sim.race.track,world:sim.world,
    motion:sim.motion,recovery}),{blocked:true},'initial zero-progress fixture has no eligible return');
  for(let tick=0;tick<320;tick++)step({throttle:1,brake:0,steer:1});
  assert.equal(sim.playerRecovery.attemptSeconds,7,'failed preflight schedules a one-second retry');
  assert.equal(sim.playerRecovery.recoveries,0);
  assert.equal(sim.rescue.get(body),undefined);
  assert.ok(sim.motion.controls.throttle>0,'held controls continue to be processed');
  assert.notEqual(sim.motion.controls.steering,0);
  assert.deepEqual({position:body.position,yaw:body.yaw,matrix:body.matrix},before,
    'no rescue scale/pose or teleport is introduced');
  for(let tick=0;tick<40;tick++)step({throttle:1,brake:0,steer:1});
  assert.equal(sim.playerRecovery.attemptSeconds,7,'unavailable destination is retried, not enqueued');
  assert.equal(sim.rescue.get(body),undefined);
  assert.equal(sim.playerRecovery.recoveries,0);
});

test('returned pickup exclusions survive retirement and stationary updates, clearing only on exit',()=>{
  const sim=create(2),step=holdPlayer(sim),body=sim.motion.body,position=[...body.position];
  // Place an original-type star exactly at a synthetic return destination.
  const pickup={type:6,position:[...position],radius:10,state:2,level:1,ageSeconds:0,yaw:0};
  sim.pickups.pickups=[pickup];
  const entry=sim.rescue.enqueue(sim.motion,{softLock:sim.playerRecovery.request(body,sim.race)});
  sim.updateRecoveryPickupExclusions(true);
  assert.deepEqual([...sim.playerRecovery.excludedPickups],[0]);
  entry.finished=true;
  sim.rescue.finishRender();
  assert.equal(sim.rescue.get(body),undefined,'fixture now exercises the post-animation gap');
  for(let tick=0;tick<80;tick++)step({throttle:0,brake:0,steer:0});
  assert.equal(sim.pickups.stars,0,'retirement must not turn a teleport into a star award');
  assert.equal(pickup.state,2);
  assert.deepEqual([...sim.playerRecovery.excludedPickups],[0]);

  body.position[0]=position[0]+sim.motion.radius+pickup.radius+10;
  assert.equal(nativeBonusOverlap({position:body.position,radius:sim.motion.radius},pickup),false);
  step({});
  assert.equal(sim.playerRecovery.excludedPickups.size,0);
  assert.equal(sim.pickups.stars,0,'leaving the overlap itself awards nothing');
  body.position.splice(0,3,...position);
  step({});
  assert.equal(sim.pickups.stars,1,'a later normal overlap can collect the star');
  assert.notEqual(pickup.state,2);
});

test('return exclusion also covers inactive pickups that respawn while the player stays there',()=>{
  const sim=create(2),step=holdPlayer(sim),body=sim.motion.body;
  const pickup={type:6,position:[...body.position],radius:10,state:1,level:1,ageSeconds:0,yaw:0};
  sim.pickups.pickups=[pickup];
  sim.updateRecoveryPickupExclusions(true);
  assert.deepEqual([...sim.playerRecovery.excludedPickups],[0]);
  pickup.state=2; // Synthetic respawn boundary; source contact logic is unchanged.
  for(let tick=0;tick<40;tick++)step({});
  assert.equal(sim.pickups.stars,0);
  assert.equal(pickup.state,2);
  assert.deepEqual([...sim.playerRecovery.excludedPickups],[0]);
});

test('composition eligibility excludes hit, squash, airborne, free-flight and inactive states; pause clears elapsed attempt',()=>{
  const sim=create(),body=sim.motion.body,detector=sim.playerRecovery;
  sim.motion.ground.groundCount=4;
  assert.equal(sim.playerRecoveryEligible(),true);
  const check=change=>{
    detector.attemptSeconds=7.99;
    const undo=change();
    assert.equal(sim.playerRecoveryEligible(),false);
    assert.equal(detector.step(body,{throttle:1},.025,{eligible:sim.playerRecoveryEligible()}),false);
    assert.equal(detector.attemptSeconds,0);
    undo();
  };
  check(()=>{sim.combat.effects[sim.actors.length-1]={active:true};return()=>{sim.combat.effects[sim.actors.length-1]=null;};});
  check(()=>{const effect=sim.squash.find(body);effect.active=true;return()=>{effect.active=false;};});
  check(()=>{sim.motion.ground.groundCount=0;body.verticalSpeed=20;return()=>{sim.motion.ground.groundCount=4;body.verticalSpeed=0;};});
  check(()=>{sim.freeFlightActive=true;return()=>{sim.freeFlightActive=false;};});
  check(()=>{sim.movementActive=false;return()=>{sim.movementActive=true;};});
  check(()=>{sim.race.phase=6;return()=>{sim.race.phase=0;};});
  detector.attemptSeconds=7.99;
  sim.pause(100);
  assert.equal(detector.attemptSeconds,0);
  sim.resume(1100);
  assert.equal(detector.attemptSeconds,0);
});

test('recovery observes consumed sector progress before the next movement boundary',()=>{
  const sim=create(),body=sim.motion.body,captured=[];
  // Synthetic one-sector moves expose the old ordering mismatch deterministically.
  sim.motion.integrate=()=>{
    sim.motion.prepared=null;
    body.previousSector=body.sector;
    body.sector=(body.sector+1)%sim.race.track.route.length;
    sim.motion.ground.groundCount=4;
  };
  sim.playerRecovery.step=b=>{
    assert.equal(b.sector,sim.race.previousSector,
      'recovery must not pair a newly integrated sector with stale progress');
    captured.push(sim.race.distance);
    return false;
  };
  for(let tick=1;tick<=4;tick++)sim.step({},.025,tick*25);
  assert.deepEqual(captured,[0,1,2,3]);
});
