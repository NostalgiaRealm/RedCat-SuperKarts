import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {SimulationClock,NativeDeltaFilter,NATIVE_REFERENCE_UPTIME_MS} from '../source/simulation/clock.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json')),cars=JSON.parse(read('cars.json'));
function create(id,difficulty,character=id%4,options={}) {
  const random=new NativeRandom(0);
  const simulation=new RaceSimulation({config,manifest,cars,physicsBytes:read(`physics/phys${difficulty}.dat`),
    racerBytes:read(`racer-tables/cars${difficulty}.dat`),track:JSON.parse(read(`tracks/etappe${id}.json`)),
    character,difficulty,random,...options});
  random.seed(0);
  return simulation;
}

test('authored start camera and countdown retain inactive motion and start race clocks after the green render',()=>{
  const sim=create(0,1,0,{countdown:true}),filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS});
  const initialControls={...sim.motion.controls};
  const initialProgress=sim.opponents.map(actor=>actor.progress.distance);
  let now=0,renderedPhase=null,greenAt=null,countdownAt=null;
  const input={throttle:1,brake:0,steer:0,handbrake:0,bonus:1};
  while(now<20000){
    now+=25;
    const active=sim.movementActive;
    const events=sim.step(input,filter.sample(.025),now,{
      beforeBonuses:()=>{
        renderedPhase=sim.race.phase;
        if(!active)assert.deepEqual(sim.motion.controls,initialControls);
      },
    });
    if(!active){
      assert.equal(sim.race.elapsedMs,0);
      assert.equal(sim.motion.body.forwardSpeed,0);
      assert.deepEqual(sim.opponents.map(actor=>actor.progress.distance),initialProgress);
    }
    if(events.some(event=>event.type==='green')){
      greenAt=now;
      assert.equal(renderedPhase,1);
      assert.equal(sim.race.phase,0);
      for(const id of [0,3,8,9,10,11,12])assert.equal(sim.timers.get(id).startMs,now);
    }
    if(sim.countdownStarted&&countdownAt===null){
      countdownAt=now;
      assert.equal(sim.startCamera.done,true);
      assert.equal(sim.countdown.elapsed,0);
    }
  }
  assert.ok(countdownAt>1000);
  assert.ok(greenAt-countdownAt>3000&&greenAt-countdownAt<4000);
  assert.equal(sim.race.elapsedMs,now-greenAt);
  assert.ok(sim.motion.body.forwardSpeed>0);
});

test('pause excludes wall-clock downtime from race clocks while absolute AI time ages',()=>{
  const sim=create(0,1),input={throttle:0,brake:0,steer:0,handbrake:0,bonus:0};
  sim.step(input,.025,1000,{wallMs:1000,engineMs:40000});
  sim.pause(1000);sim.resume(6000);
  sim.step(input,.025,1025,{wallMs:6025,engineMs:45025});
  assert.equal(sim.race.elapsedMs,1025);
  assert.equal(sim.timers.read(9,6025),1025);
  assert.equal(sim.opponents[0].animationTurbo.nowSeconds,Math.fround(45.025));
});

test('post-render Space audio follows the original Shift gate without consuming its repetition counter',()=>{
  const sim=create(0,1),input={throttle:0,brake:0,steer:0,handbrake:0,bonus:0},calls=[];
  sim.onDirectSound=event=>calls.push(event);
  sim.onVoiceRequest=request=>{if(request.sample==='CLAXON')calls.push(request);};
  sim.step(input,.025,25,{keys:new Set([16,32]),beforeBonuses:()=>calls.push('render')});
  assert.deepEqual(calls,['render']);
  assert.equal(sim.keyAudio.repetitions,3);
  calls.length=0;
  sim.step(input,.025,50,{keys:new Set([32]),beforeBonuses:()=>calls.push('render')});
  assert.equal(calls[0],'render');
  assert.equal(calls[1].sample,'CLAXON');
  assert.equal(calls[1].replace,true);
  assert.equal(calls[2],'KT4');
  assert.equal(sim.keyAudio.repetitions,2);
});

test('camera key selection persists across startup and finish ticks until a scripted switch',()=>{
  const input={throttle:0,brake:0,steer:0,handbrake:0,bonus:0};
  const startup=create(0,1,0,{countdown:true});
  startup.step(input,.1,25,{keys:new Set([50])});
  assert.equal(startup.camera,startup.playerCamera);
  assert.equal(startup.playerCamera.bodyVisible,false);
  startup.step(input,.1,50);
  assert.equal(startup.camera,startup.playerCamera);
  const race=create(0,1);
  race.race.phase=3;
  race.step(input,.1,25);
  assert.equal(race.camera,race.finishCamera);
  race.step(input,.1,50,{keys:new Set([50])});
  assert.equal(race.camera,race.playerCamera);
  race.step(input,.1,75);
  assert.equal(race.camera,race.playerCamera);
  // Other mode keys are restricted to active racing, including release of3.
  race.step(input,.025,100,{keys:new Set([49])});
  assert.equal(race.playerCamera.mode,3);
});
function run(simulation,schedule,duration=5000) {
  const filter=new NativeDeltaFilter({uptimeMs:NATIVE_REFERENCE_UPTIME_MS}),history=[];
  const clock=new SimulationClock({intervalMs:25,update:(dt,now)=>{
    simulation.step({throttle:now<2500?1:0,brake:now>=2500?1:0,
      steer:now>=1000&&now<1250?-.5:0,handbrake:0,bonus:1},filter.sample(dt),now);
    if(now%250===0)history.push(simulation.actors.map(actor=>({
      position:[...actor.body.position],sector:actor.body.sector,yaw:actor.body.yaw,
      forwardSpeed:actor.body.forwardSpeed,lateralSpeed:actor.body.lateralSpeed,
      phase:actor.phase,
    })));
  }});
  let time=0,index=0;clock.frame(time);
  while(time<duration){time=Math.min(duration,time+schedule[index++%schedule.length]);clock.frame(time);}
  return {history,owned:simulation.pickups.owned,random:simulation.pickups.random.state,
    race:simulation.race.snapshot(),camera:{position:simulation.camera.position,
      target:simulation.camera.target,up:simulation.camera.up},
    scenery:simulation.scenery.bodies.map(body=>({
      position:[...body.position],sector:body.sector,yaw:body.yaw,mesh:body.mesh,
      active:body.active,forwardSpeed:body.forwardSpeed,lateralSpeed:body.lateralSpeed,
    }))};
}

test('scenery and camera stages precede their native racer and render boundaries',()=>{
  const sim=create(1,1),stages=[];
  const snowball=sim.scenery.bodies.find(body=>body.mesh==='dusb0000.d3d');
  sim.step({throttle:0,brake:0,steer:0,handbrake:0,bonus:0},.025,100,{
    afterSceneryPrepare:()=>{stages.push('scenery');assert.equal(snowball.mesh,'dusb0001.d3d');},
    beforePlayerPrepare:()=>stages.push('player'),
    afterCamera:()=>{stages.push('camera');assert.equal(sim.cameraMatrix.length,9);},
    beforeBonuses:()=>stages.push('render'),
    beforeGameActions:()=>stages.push('actions'),
  });
  assert.deepEqual(stages,['scenery','player','camera','render','actions']);
  assert.equal(sim.sceneryObjects.get(snowball.placementIndex),snowball);
  assert.deepEqual(sim.rescue.occupants(),[sim.motion.body,...sim.opponents.map(actor=>actor.body)]);
  assert.equal(sim.physicalBodies[0],sim.scenery.bodies[0]);
  assert.equal(sim.physicalBodies[sim.scenery.bodies.length],sim.motion.body);
});

test('original CLOUDS option controls the smoke pool without a renderer',()=>{
  const disabled=structuredClone(config);disabled['sndgfx.ini']['gfx options'].clouds='0';
  const sim=create(0,1,0,{config:disabled});
  assert.equal(sim.smoke.enabled,false);
  assert.equal(create(0,1).smoke.enabled,true);
});

for(let difficulty=0;difficulty<3;difficulty++) {
  test(`all six tracks assemble original opponents and character physics at difficulty ${difficulty}`,()=>{
    for(let id=0;id<6;id++){
      const sim=create(id,difficulty);
      assert.equal(sim.motion.physics.index,id%4);
      assert.equal(sim.opponents.length,4);
      assert.equal(sim.setup.racerTableFile,`assets/racer-tables/cars${difficulty}.dat`);
      sim.opponents.forEach((actor,index)=>{
        assert.equal(actor.racer.index,sim.setup.opponents[index].aiId);
        assert.equal(actor.playerRacer.index,id%4);
        assert.equal(actor.groundClock,sim.motion.groundClock);
        assert.equal(actor.random,sim.pickups.random);
        assert.deepEqual(actor.collision.bodies,[...sim.scenery.bodies,...[sim.motion,...sim.opponents].map(a=>a.body)]);
      });
      const result=run(sim,[1000/60],3000);
      for(const state of result.history.flat()){
        assert.ok(state.position.every(Number.isFinite));assert.ok(Number.isFinite(state.forwardSpeed));
      }
    }
  });
  test(`player, NPCs, dynamic contacts and bonuses are render-rate independent at difficulty ${difficulty}`,()=>{
    const baseline=run(create(difficulty,difficulty),[1000/31]);
    for(const schedule of [[1000/32],[1000/60],[1000/120],[1000/144],[1000/240],[7,30,4,60,450,16]])
      assert.deepEqual(run(create(difficulty,difficulty),schedule),baseline,`frame schedule ${schedule}`);
  });
}
