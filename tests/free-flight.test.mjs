import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../src/race-simulation.js';
import {NativeRandom} from '../src/simulation/native-random.js';
import {advanceFreeFlight,roadFlightPose} from '../src/simulation/free-flight.js';
import {InputState,InputController} from '../src/input.js';

const read=path=>fs.readFileSync(new URL('../'+path,import.meta.url));
const json=path=>JSON.parse(read(path));
const assets={config:json('public/assets/config.json'),manifest:json('public/assets/manifest.json'),
  cars:json('public/assets/cars.json'),physicsBytes:read('public/assets/physics/phys0.dat'),
  racerBytes:read('public/assets/racer-tables/cars0.dat'),difficulty:0};
const make=(track=0,extra={})=>{
  const random=new NativeRandom(0);
  return {random,sim:new RaceSimulation({...assets,track:json(`public/assets/tracks/etappe${track}.json`),random,...extra})};
};
const input={throttle:1,brake:0,steer:.3,handbrake:0,bonus:0};
const frozen=({sim,random})=>JSON.stringify({race:sim.race.snapshot(),timers:sim.timers.timers,
  random:random.state,opponents:sim.opponents.map(actor=>({pose:actor.body.position,state:actor.state})),
  pickups:sim.pickups.pickups,owned:sim.pickups.owned,stars:sim.pickups.stars,
  paths:[...sim.sceneryPaths.objects],rescue:sim.rescue.entries.length,
  rank:sim.rankStates,updates:sim.motion.updates});

test('free flight is opt-in and explicit false leaves native composed driving unchanged',()=>{
  const a=make(),b=make();b.sim.setFreeFlight(false);
  for(let tick=1;tick<=80;tick++){
    assert.deepEqual(a.sim.step(input,.025,tick*25),b.sim.step(input,.025,tick*25));
    assert.deepEqual(a.sim.motion.snapshot(),b.sim.motion.snapshot());
    assert.equal(frozen(a),frozen(b));
  }
  assert.equal(a.sim.freeFlightEnabled,false);assert.equal(a.sim.freeFlightActive,false);
});

test('flight bypasses terrain and contacts while freezing all race awards, actors, clocks and RNG',()=>{
  const state=make(3,{raceMode:1}),{sim}=state;
  sim.step({},.025,25);sim.setFreeFlight(true);sim.step({},.025,50);
  assert.equal(sim.freeFlightActive,true);
  const before=frozen(state),origin=[...sim.motion.body.position];
  for(let tick=3;tick<=603;tick++){
    assert.deepEqual(sim.step({...input,steer:0,lift:tick<300?-1:1,bonus:1},.025,tick*25),[]);
    assert.equal(frozen(state),before);
    assert.ok(sim.camera.position.every(Number.isFinite));
    assert.ok(sim.camera.target.every(Number.isFinite));
  }
  assert.ok(Math.hypot(...sim.motion.body.position.map((v,i)=>v-origin[i]))>1000);
  assert.equal(sim.rescue.entries.length,0);assert.equal(sim.race.finished,false);
});

test('all six tracks restore supported road and zero airborne energy without phantom crossings',()=>{
  for(let track=0;track<6;track++){
    const {sim}=make(track);sim.step({},.025,25);sim.setFreeFlight(true);sim.step({},.025,50);
    const anchor=structuredClone(sim.flightReturnPose),progress=sim.race.snapshot();
    for(let tick=3;tick<=43;tick++)sim.step({throttle:1,lift:1,steer:1},.025,tick*25);
    sim.setFreeFlight(false);
    assert.deepEqual(sim.motion.body.position,anchor.position);
    assert.equal(roadFlightPose(sim.motion,anchor,{clear:true}),true);
    for(const key of ['forwardSpeed','verticalSpeed','lateralSpeed','yawRate','pitchRate','rollRate'])
      assert.equal(sim.motion.body[key],0);
    assert.ok(sim.motion.ground.wheels.every(w=>w.verticalSpeed===0&&w.position.every(Number.isFinite)));
    const events=sim.step({},.025,1100);
    assert.equal(sim.race.elapsedMs,progress.elapsedMs+25);
    assert.equal(sim.race.distance,progress.distance);
    assert.equal(events.some(e=>['lap','time-gate','finished','pickup'].includes(e.type)),false);
  }
});

test('saved enabled flight waits for the original introduction and green',()=>{
  const {sim}=make(3,{countdown:true});sim.setFreeFlight(true);
  let green=null;
  for(let tick=1;tick<=600&&!sim.freeFlightActive;tick++){
    const events=sim.step({},.025,tick*25);
    if(events.some(event=>event.type==='green'))green=tick*25;
    if(green===null)assert.equal(sim.freeFlightActive,false);
  }
  assert.ok(green>1000);assert.equal(sim.freeFlightActive,true);
  assert.equal(sim.race.elapsedMs,0);assert.equal(sim.race.finished,false);
});

test('flight pause and disabling while paused preserve the native timer epoch',()=>{
  const {sim}=make();sim.step({},.025,25);sim.setFreeFlight(true);sim.step({},.025,50);
  sim.pause(50);sim.setFreeFlight(false);sim.resume(5050);sim.step({},.025,5075);
  assert.equal(sim.race.elapsedMs,50);
  sim.pause(5075);sim.resume(6075);sim.step({},.025,6100);
  assert.equal(sim.race.elapsedMs,75);
});

test('flight movement is frame-independent and keyboard, touch and pad lift do not change ordinary input',()=>{
  const flight=()=>({body:{position:[0,0,0],yaw:0},controls:{},mirrored:false});
  const a=flight(),b=flight();
  for(let i=0;i<40;i++)advanceFreeFlight(a,{throttle:1,steer:.4,lift:1},.025);
  for(let i=0;i<100;i++)advanceFreeFlight(b,{throttle:1,steer:.4,lift:1},.01);
  a.body.position.forEach((v,i)=>assert.ok(Math.abs(v-b.body.position[i])<1e-8));
  const state=new InputState();state.keys.add(32);assert.equal('lift'in state.snapshot(),false);
  state.freeFlightActive=true;assert.equal(state.snapshot().lift,1);
  state.keys.delete(32);state.set('pointer:1','flightDown');assert.equal(state.snapshot().lift,-1);
  state.clear();assert.equal(state.snapshot().lift,0);
  const win=new EventTarget();win.document=new EventTarget();
  const buttons=Array.from({length:16},()=>({value:0}));buttons[4].value=1;
  win.navigator={getGamepads:()=>[{id:'fixture',connected:true,mapping:'standard',buttons,axes:[0,0]}]};
  const controller=new InputController({window:win});controller.setMode('race');controller.state.freeFlightActive=true;
  controller.poll(0);assert.equal(controller.state.snapshot().lift,1);
  controller.state.keys.add(67);controller.setMode('menu');assert.equal(controller.state.snapshot().lift,0);
  controller.destroy();
});
