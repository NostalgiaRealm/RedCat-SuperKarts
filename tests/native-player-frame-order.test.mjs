import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {RaceSimulation} from '../source/race-simulation.js';
import {NativeRandom} from '../source/simulation/native-random.js';
import {updateNativeWheelPose} from '../source/simulation/native-ground.js';

const read=file=>fs.readFileSync(new URL('../public/assets/'+file,import.meta.url));
const config=JSON.parse(read('config.json')),manifest=JSON.parse(read('manifest.json'));
const cars=JSON.parse(read('cars.json'));
const native=JSON.parse(fs.readFileSync(new URL('../evidence/native/player-frame-order-fixtures.json',import.meta.url)));
function create({track=0,...options}={}){
  return new RaceSimulation({config,manifest,cars,random:new NativeRandom(0),
    track:JSON.parse(read(`tracks/etappe${track}.json`)),difficulty:1,
    physicsBytes:read('physics/phys1.dat'),racerBytes:read('racer-tables/cars1.dat'),...options});
}
const idle={throttle:0,brake:0,steer:0,handbrake:0,bonus:0};

test('original caller traces put audio before markers and the first wheels before every input mode',()=>{
  assert.equal(native.cases.length,24);
  for(const c of native.cases){
    assert.deepEqual(c.trace.slice(0,4).map(x=>x.stage),['engine','rank','triggers','first-wheels']);
    assert.equal(c.trace[0].forwardSpeed,20);
    assert.equal(c.trace[3].forwardSpeed,20+c.triggerBoost);
    const stages=c.trace.map(x=>x.stage);
    if(!c.active)assert.equal(stages.length,4,'inactive dispatch does not poll input or shoot');
    else if(c.buttons&16)assert.deepEqual(stages.slice(4),['fire','forces','second-wheels']);
    else assert.deepEqual(stages.slice(4),['forces','second-wheels']);
  }
});

test('keyboard and analog bonus boundaries retain original controls and pre-turbo first-wheel speed',()=>{
  // Mode2's legacy DirectInput digital joystick is retained in the native
  // evidence; browser pads/touch intentionally use mode3's analog controls.
  for(const c of native.cases.filter(x=>x.inputMode!==2)){
    const sim=create(),motion=sim.motion,dt=.025;
    motion.body.forwardSpeed=20+c.triggerBoost;
    const expectedGround=structuredClone(motion.ground);
    updateNativeWheelPose(motion.body,expectedGround,dt,motion.controls.steering,motion.sampleGround);
    const firstSpin=expectedGround.wheels.map(w=>w.spin);
    let fired=false;
    motion.prepare({accelerate:Boolean(c.buttons&4),handbrake:Boolean(c.buttons&32)},dt,{
      active:c.active,analog:c.inputMode===3?{x:75,y:100,buttonMask:c.buttons}:null,
      onBonus:()=>{
        assert.deepEqual(motion.ground.wheels.map(w=>w.spin),firstSpin,'first wheel pass sees speed before turbo');
        if(!(c.buttons&16))return;
        fired=true;
        const original=c.trace.find(x=>x.stage==='fire');
        assert.deepEqual({...motion.controls},Object.fromEntries(
          ['throttle','brake','steering','handbrake'].map(key=>[key,original[key]])));
        motion.body.forwardSpeed=Math.fround(motion.body.forwardSpeed*1.5);
      },
    });
    assert.equal(fired,c.active&&Boolean(c.buttons&16));
    if(c.active){
      updateNativeWheelPose(motion.body,expectedGround,dt,motion.controls.steering,motion.sampleGround);
      assert.deepEqual(motion.ground.wheels.map(w=>w.spin),expectedGround.wheels.map(w=>w.spin),
        'only the second wheel pass sees the turbo boost');
    }
  }
});

test('connected player turbo fires between wheel passes and updates its animation in the same callback',()=>{
  for(const analog of [undefined,{steer:0,throttle:1,brake:0,handbrake:false,bonus:true}]){
    const sim=create(),motion=sim.motion,dt=.025;
    motion.body.forwardSpeed=20;
    Object.assign(sim.pickups.owned.at(-1),{state:2,type:5,level:1});
    const expected=structuredClone(motion.ground);
    updateNativeWheelPose(motion.body,expected,dt,motion.controls.steering,motion.sampleGround);
    const firstSpin=expected.wheels.map(w=>w.spin),seen=[];
    const turbo=sim.combat.onTurbo;
    sim.combat.onTurbo=(...args)=>{
      seen.push('fire');
      assert.deepEqual(motion.ground.wheels.map(w=>w.spin),firstSpin);
      assert.equal(motion.body.forwardSpeed,30);
      turbo(...args);
    };
    const events=sim.step({...idle,throttle:1,bonus:1,analog},dt,25,{
      beforePlayerProgress:()=>{seen.push('engine');assert.equal(motion.body.forwardSpeed,20);},
      afterPlayerPrepare:state=>{
        seen.push('prepared');
        assert.equal(state.turboAgeMs,0);
        updateNativeWheelPose(motion.body,expected,dt,motion.controls.steering,motion.sampleGround);
        assert.deepEqual(motion.ground.wheels.map(w=>w.spin),expected.wheels.map(w=>w.spin));
      },
    });
    assert.deepEqual(seen,['engine','fire','prepared']);
    assert.equal(events.filter(e=>e.type==='turbo'&&e.shooter===sim.actors.length-1).length,1);
  }
});

test('engine sampling precedes the actual France jump callback while HUD preparation follows it',()=>{
  const sim=create({track:3}),track=sim.race.track,body=sim.motion.body;
  const waypoint=track.route[104].driveIndices[0],node=track.drive[waypoint],next=track.drive[node.links[0]];
  Object.assign(body,{sector:104,previousSector:103,waypoint,forwardSpeed:20,position:[...node.position],
    matrix:[1,0,0,0,1,0,next.position[0]-node.position[0],0,next.position[2]-node.position[2]]});
  sim.motion.ground.wheels.forEach((wheel,i)=>{wheel.verticalSpeed=i-2;});
  let before=false,after=false;
  sim.step(idle,.025,25,{
    beforePlayerProgress:()=>{
      before=true;assert.deepEqual(sim.motion.ground.wheels.map(w=>w.verticalSpeed),[-2,-1,0,1]);
    },
    beforePlayerPrepare:()=>{
      after=true;assert.deepEqual(sim.motion.ground.wheels.map(w=>w.verticalSpeed),[273,274,275,276]);
    },
  });
  assert.ok(before&&after);
});

test('inactive startup never fires; active timed input precedes the render and expiry gate',()=>{
  const startup=create({countdown:true});
  Object.assign(startup.pickups.owned.at(-1),{state:2,type:5,level:1});
  let calls=0;const poll=startup.combat.playerFire.bind(startup.combat);
  startup.combat.playerFire=(...args)=>{calls++;return poll(...args);};
  startup.step({...idle,bonus:1},.025,25);
  assert.equal(calls,0);assert.equal(startup.pickups.owned.at(-1).state,2);
  const timed=create({raceMode:1});
  Object.assign(timed.pickups.owned.at(-1),{state:2,type:5,level:1});
  timed.race.gateDeadlineMs=25;
  let renderedPhase;
  const events=timed.step({...idle,bonus:1},.025,25,{
    beforeBonuses:()=>{renderedPhase=timed.race.phase;assert.equal(timed.pickups.owned.at(-1).state,1);},
  });
  assert.equal(renderedPhase,0);assert.equal(timed.race.phase,6);
  assert.ok(events.findIndex(e=>e.type==='turbo')<events.findIndex(e=>e.type==='time-expired'));
});
